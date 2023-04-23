
#ifndef __REALM_NETWORK_THREAD_H__
#define __REALM_NETWORK_THREAD_H__

#include <ace/Task.h>

class ACE_Proactor;

class RealmNetwork_Thread : public ACE_Task_Base
{
public:
	RealmNetwork_Thread();
	virtual ~RealmNetwork_Thread();

	virtual int svc();

	int open();
	int close();

private:
	bool running_;
	ACE_Proactor * proactor_;
};

#endif // __REALM_NETWORK_THREAD_H__
