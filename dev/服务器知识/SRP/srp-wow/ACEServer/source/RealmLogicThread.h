
#ifndef __REALM_LOGIC_THREAD_H__
#define __REALM_LOGIC_THREAD_H__

#include <ace/Task.h>
#include <map>

class Realm_Client_Service;

class RealmLogic_Thread : public ACE_Task<ACE_MT_SYNCH>
{
public:
	RealmLogic_Thread();
	virtual ~RealmLogic_Thread();

	virtual int svc();

	int open();
	int close();

private:
	bool running_;

	typedef std::map<unsigned int, Realm_Client_Service *> ClientServiceMap;
	ClientServiceMap client_service_map_;
};

#endif // __REALM_LOGIC_THREAD_H__
