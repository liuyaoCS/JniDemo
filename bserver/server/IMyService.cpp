#include "common.h"
#include "IMyService.h"

IMPLEMENT_META_INTERFACE(MyService, BINDER_SERVICE_INTERFACE_NAME); //使用宏，完成MyService定义

//服务端代理 IMPLEMENT_META_INTERFACE 里面用
BpMyService::BpMyService(const sp<IBinder>& impl) : BpInterface<IMyService>(impl) {
}
void BpMyService::sayHello() {
};
int BpMyService::getVersion(){
    return 0;
}

//服务端，接收远程消息，处理onTransact方法
status_t BnMyService::onTransact(uint_t code, const Parcel& data,
								 Parcel* reply, uint32_t flags) {
	printf("BnMyService:: onTransact code=%d\n",code);
	switch (code) {
		case HELLO:
			data.enforceInterface(BINDER_SERVICE_INTERFACE_NAME);
			sayHello();
			return NO_ERROR;
        case VERSION:
            data.enforceInterface(BINDER_SERVICE_INTERFACE_NAME);
            reply->writeInt32(getVersion());
            return  NO_ERROR;
		default:
			break;
	}
	return NO_ERROR;
}
// 实现服务端sayHello方法
void BnMyService::sayHello() {
    LOGI("BnMyService::sayHello");
};
int BnMyService::getVersion(){
    return 1001;
}
