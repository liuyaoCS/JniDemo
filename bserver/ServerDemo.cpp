#include "IMyService.h"

int main() {
	sp < IServiceManager > sm = defaultServiceManager(); //��ȡservice manager����
	sm->addService(BINDER_SERVICE_NAME, new BnMyService()); //ע����ΪBINDER_SERVICE_NAME�ķ���service manager
	ProcessState::self()->startThreadPool(); //�����̳߳�
	IPCThreadState::self()->joinThreadPool(); //�����̼߳����̳߳�
	return 0;
}
