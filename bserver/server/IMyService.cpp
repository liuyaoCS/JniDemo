#include "common.h"
#include "IMyService.h"

IMPLEMENT_META_INTERFACE(MyService, BINDER_SERVICE_INTERFACE_NAME); //ʹ�ú꣬���MyService����

//����˴��� IMPLEMENT_META_INTERFACE ������
BpMyService::BpMyService(const sp<IBinder>& impl) : BpInterface<IMyService>(impl) {
}
void BpMyService::sayHello() {
};
int BpMyService::getVersion(){
    return 0;
}

//����ˣ�����Զ����Ϣ������onTransact����
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
// ʵ�ַ����sayHello����
void BnMyService::sayHello() {
    LOGI("BnMyService::sayHello");
};
int BnMyService::getVersion(){
    return 1001;
}
