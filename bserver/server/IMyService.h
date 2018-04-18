#ifndef MY_SERVICE_DEMO
#define MY_SERVICE_DEMO

#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#define BINDER_SERVICE_NAME String16("demoService")
#define BINDER_SERVICE_INTERFACE_NAME String16("com.example.jnidemo")

using namespace android;
class IMyService : public IInterface
{
	public:
		DECLARE_META_INTERFACE(MyService);
		virtual void sayHello()=0;
		virtual int getVersion()=0;
};

enum
{
	HELLO = android::IBinder::FIRST_CALL_TRANSACTION,
	VERSION = HELLO+1
};

class BnMyService: public BnInterface<IMyService> {
	public:
		virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
		virtual void sayHello();
		virtual int getVersion();
};

#endif

