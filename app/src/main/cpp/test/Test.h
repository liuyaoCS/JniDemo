//
// Created by liuyao-s on 2018/4/26.
//

#ifndef JNIDEMO_TEST_H
#define JNIDEMO_TEST_H

#include <string>
#include <math.h>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <fstream>

#include <android/log.h>

#define TAG "ly-s"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG, __VA_ARGS__)

using namespace std;

void test();
struct Person{
    int age;
    string name;
};
class Product{
    private:
        int type;
        const char* desc;
    public:
        Product(int t,const char* d);
        virtual ~Product();//虚函数是为了实现多态性。如果不指明virtual Product *p =new Book; delete p;就会发生内存泄露
        void printInfo();
};
class Book : public Product{
private:
    const char* name;
public:
    Book(const char * n,int t ,const char * d);
    ~Book();
    const char* getName();
};
union UTpye{
    int i;
    long l;
};
enum Color{
    red,
    yellow,
    blue
};//notice : do not define variable here


#endif //JNIDEMO_TEST_H
