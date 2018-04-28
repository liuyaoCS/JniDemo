//
// Created by liuyao-s on 2018/4/26.
//


#include "Test.h"
#include "../../../../../bserver/platform/include/libc/stdio.h"

void test_type(){
    double x = sqrt(6.25);
    LOGI("x = %2.1f",x);

    //struct
    Person person{23, "liuyao"};
    LOGI("%s is %d",person.name.c_str(),person.age);

    //union
    UTpye ut;
    ut.i = 1;
    LOGI("union int value =%d long value=%ld",ut.i,ut.l);

    //enum
    Color color =red;
    LOGI("color is %d",color);

    //vector
    vector<int> a ={1,2};
    a.push_back(3);
    for(auto i=a.begin();i!=a.end();i++){
        LOGI("vector item->%d",*i);
    }

    //array
    array<int,2> arr ={4,5};
    for(auto i=arr.begin();i!=arr.end();i++){
        LOGI("array item->%d",*i);
    }

    //set
    string str[]={"hi","liuyao"};
    set<string> sets(str,str+2);
    for(auto si=sets.begin();si!=sets.end();si++){
        string item = *si;
        LOGI("s=%s",item.c_str());
    }

    //multimap
    multimap<int,string> maps;
    maps.insert(pair<int,string>(1,"dm"));
    maps.insert(pair<int,string>(2,"zh"));
    for(auto mi=maps.begin();mi!=maps.end();mi++){
        int key=(*mi).first;
        string value=(*mi).second;
        LOGI("key=%d,value=%s",key,value.c_str());
    }

}
void test_string(){
    //char* <-> string
    const char * c_str ="i am c_str";
    LOGI("c_str = %s",c_str);

    string str = c_str;
    str += " origin is str";
    LOGI("str = %s",str.c_str());
}
void test_pointer() {
    //pointer
    int i = 2;
    LOGI("address is %p", &i);
    int *pi = &i;
    *pi = *pi + 1;
    LOGI("i is %d", i);

    int *n = new int;
    *n = 2;
    LOGI("n is %d", *n);
    delete n;

    double *d3 = new double[3];
    d3[0] = 1.0;
    delete[] d3;
}
void test_char(){
    //char <-> int
    char ch = 'a';
    int int_ch= static_cast<int>(ch);
    LOGI("c= %c int_ch = %d",ch,int_ch);

    //char lib
    char a ='a';
    if(isalpha(a)){
        LOGI("%c is alpha", a);
    }

}
/**
 * 二进制读写
 */
void test_file(){
    const char* TEST_LOG_FILE = "/data/data/com.example.jnidemo/test.txt";
    char arr[] ="hello file\n";
    const size_t LEN = strlen(arr)+1; //add \'0'
    char buff[LEN];

    FILE *file = fopen(TEST_LOG_FILE,"w+");
    if(file!=NULL){
        fwrite(arr, LEN, 1, file);
        fseek(file,SEEK_SET,0);
        fread(buff,LEN,1,file);
        LOGI("read file content %s",buff);
        fclose(file);
    }else{
        LOGI("can not write file");
    }

}
void change(int* p){
    *p = 2;
    LOGI("p=%d",*p);
}
void change2(int& p){
    p=3;
}
void test_function_paramter_transmit(){
    int *p = new int;
    *p=1;
    change(p);
    LOGI("p=%d",*p);

    change2(*p);
    LOGI("p=%d",*p);
}
void say(int a){
    LOGI("say: %d",a);
}
void foo(int a,void (*f)(int)){
    f(a+2);
    (*f)(a+2);
}

void test_function_pointer(){
    foo(2,say);
}
/**
 * required: small function body ; multi called ; not recurse ; compiler support
 */
inline double square(double x){return x*x;}
void test_inline_function(){
    LOGI("x*x=%2.1f",square(3));
}

template <typename T>
void Swap(T& a,T& b){
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void test_template(){
    int a = 1, b =2;
    Swap(a,b);
    LOGI("swap a=%d,b=%d",a,b);
}

Product::Product(int t, const char *d) {
    this->type = t;
    this->desc = d;
}
Product::~Product() {
    LOGI("%s is over",this->desc);
}
void Product::printInfo() {
    LOGI("product(%d):%s",this->type,this->desc);
}
Book::Book(const char *n, int t, const char *d):Product(t,d) {
    this->name = n;
}
Book::~Book() {
    LOGI("%s is over",this->name);
}
const char* Book::getName() {
    return this->name;
}
void test_class(){
    Product pd1 = Product(1,"a phone");//函数退出的时候会自动调用析构函数
    pd1.printInfo();

    Product* pd2 = new Product(2,"a cup");
    pd2->printInfo();
    delete pd2;

    Book* book = new Book("old and sea",3,"a parent book");
    book->printInfo();
    LOGI("name is %s",book->getName());
    delete book;
}
void check(int a){
    if(a==-1){
        throw "bad paramter !";
    }
}
void test_exception(){
    try {
        check(-1);
    }catch(const char * msg){
        LOGI("exception happens:%s",msg);
    }
}
void test_cast(){
    //dynamic_cast 运行期间
    Product* p = new Product(0,"");
    Book* b = new Book("",1,"");

    Product* b1=dynamic_cast<Product*>(b);
    if(b1){
        LOGI("cast ok");
    }else{
        LOGI("cast err");
    }
    //static_cast 编译期间 static_cast能避免编译错误并且返回，但是不安全！！
    //char c{97.2};   //编译错误 丢失精度的转换都会报错
    char c= static_cast<char>(97.2);
    LOGI("cast ok c= %c",c);

    char c2= static_cast<char>(1000);
    LOGI("cast ok c2= %c",c2);//超出范围（232）变成无效字符

}
void test_c11(){
    //{}初始化
    int x{1};
    double y={2};
    Person p{1,""};

    //防止缩窄：禁止将数值赋给无法存储它的变量
    char c=1.2; //c11以前的语法 缩窄只是warning
    //char c{1.2}; //c11以后语法 编译错误

    //nullptr
    int *a = nullptr;
    int *b = NULL;

}
/**
 * 在c中，联合体（共用体）的数据成员都是从低地址开始存放。
 若是小端模式，由低地址到高地址c.a存放为0x01 00 00 00，c.b被赋值为0x01；
  ————————————————————————————
   地址 0x00000000 0x00000001 0x00000002 0x00000003
   c.a  01         00         00         00
   c.b  01         00
  ————————————————————————————
3  若是大端模式，由低地址到高地址c.a存放为0x00 00 00 01，c.b被赋值为0x0；
  ————————————————————————————
   地址 0x00000000 0x00000001 0x00000002 0x00000003
   c.a  00         00         00         01
   c.b  00         00
  ————————————————————————————
 * @return
 */
bool test_is_big_endian(){
    union w
    {
        int a;  //4 bytes
        char b; //1 byte
    } c;
    c.a=1;
    if (c.b==1)
        return false;
    else
        return true;

}
void test_computer(){
    //storage 0 -1
    int i = 4294967296;
    LOGI("i=%d",i);
    i = 4294967295;
    LOGI("i=%d",i);

    //endian 0 1 0
    if(test_is_big_endian()){
        LOGI("big endian");
    }else{
        LOGI("little endian");
    }
    ///32位环境，cpu为小端模式，所有参数用栈传递
    long long a=1;
    long long b=2;
    long long c=3;
    LOGI("%d,%d,%d",a,b,c);
}

void test(){
    test_type();
    test_char();
    test_string();
    test_class();

    test_function_paramter_transmit();
    test_function_pointer();
    test_inline_function();

    test_pointer();

    test_template();
    test_exception();
    test_cast();
    test_file();

    test_c11();
    test_computer();
}