
#ifndef __REALM_SERVICE_H__
#define __REALM_SERVICE_H__

#include <ace/Asynch_IO.h>

class ACE_Proactor;

class Realm_Service : public ACE_Service_Handler
{
	friend class Realm_Acceptor;

public:
	Realm_Service( ACE_Proactor * proactor = 0 );
	virtual ~Realm_Service();

	virtual void open( ACE_HANDLE h, ACE_Message_Block & );
	virtual void addresses( const ACE_INET_Addr& peer,
							const ACE_INET_Addr& local );
	// send data
	void send_buffer( const char * data, int len );
	void server_close();

protected:
	virtual void handle_read_stream( const ACE_Asynch_Read_Stream::Result &result );
	virtual void handle_write_stream( const ACE_Asynch_Write_Stream::Result &result );

private:
	int initiate_read_stream();
	int initiate_write_stream( ACE_Message_Block &mb, size_t nbytes );
	void close_socket();

private:
	ACE_Asynch_Read_Stream reader_;
	ACE_Asynch_Write_Stream writer_;

	bool server_closed_;
};

#endif // __REALM_SERVICE_H__
