#include "IMyService.h"

int main() {
	sp < IServiceManager > sm = defaultServiceManager(); //获取service manager引用
	sm->addService(BINDER_SERVICE_NAME, new BnMyService()); //注册名为BINDER_SERVICE_NAME的服务到service manager
	ProcessState::self()->startThreadPool(); //启动线程池
	IPCThreadState::self()->joinThreadPool(); //把主线程加入线程池
	return 0;
}
