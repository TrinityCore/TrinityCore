
#include <ace/os_include/os_stddef.h>
#include <ace/os.h>
#include <ace/Message_Block.h>
#include <ace/Proactor.h>
#include <ace/WIN32_Proactor.h>

#include "RealmService.h"
#include "RealmAcceptor.h"
#include "SystemConfig.h"
#include "RealmServer.h"

Realm_Service::Realm_Service( ACE_Proactor * proactor )
{
	this->proactor( proactor );
	this->server_closed_ = false;
}

Realm_Service::~Realm_Service()
{
	if( this->handle() != ACE_INVALID_HANDLE )
		this->close_socket();
	this->proactor()->cancel_timer( *this );
}

void Realm_Service::close_socket()
{
	ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("(%t) Realm_Service::close_socket. handle %d\n"), reinterpret_cast<int>(this->handle_)));

	this->writer_.cancel();
	this->reader_.cancel();

	// close packet
	ACE_Message_Block * close_packet;
	ACE_NEW_NORETURN (close_packet, ACE_Message_Block(4, MB_CLOSE_PACKET));
	if( !close_packet )
		ACE_ERROR ((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("Realm_Service::close_socket error. no more memory")));
	unsigned int handle_addr = reinterpret_cast<unsigned int>( this->handle_ );
	if( close_packet )
		close_packet->copy( reinterpret_cast<const char *>(&handle_addr), sizeof(handle_addr) );

	// close socket
	if( this->handle() != ACE_INVALID_HANDLE )
	{
		ACE_OS::closesocket( this->handle() );
		this->handle( ACE_INVALID_HANDLE );
	}

	// 这里先关闭socket再放消息队列的原因:
	// logic线程在处理该消息时会删除此Proactive_Service对象
	// 如果删除后再调用 closesocket() 会出现非法访问
	if( close_packet && REALM_SERVER->putq( close_packet->duplicate() ) == -1 )
		ACE_ERROR ((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("Realm_Service::close_socket put close packet error")));
	if( close_packet )
		close_packet->release();
}

void Realm_Service::addresses( const ACE_INET_Addr& peer, const ACE_INET_Addr& local )
{
	ACE_TCHAR str[256];

	if( 0 == peer.addr_to_string(str, sizeof (str) / sizeof(ACE_TCHAR)) )
		ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("(%t) Realm_Service connection from %s\n"), str));
	else
		ACE_ERROR ((LM_ERROR, ACE_TEXT ("(%t) Realm_Service %p\n"), ACE_TEXT ("addr_to_string")));

	return;
}

void Realm_Service::open( ACE_HANDLE handle, ACE_Message_Block & )
{
	this->handle( handle );

	int nodelay = 1;
	ACE_SOCK_Stream option_setter( handle );
	if( -1 == option_setter.set_option(ACE_IPPROTO_TCP, TCP_NODELAY, &nodelay, sizeof(nodelay)))
		ACE_ERROR ((LM_ERROR, "%p\n", "set_option"));

	if( this->writer_.open( *this, this->handle_, 0, proactor_ ) == -1 )
		ACE_ERROR ((LM_ERROR,
					ACE_TEXT ("(%t) %p\n"),
					ACE_TEXT ("Realm_Service::ACE_Asynch_Write_Stream::open")));
    else if( this->reader_.open( *this, this->handle_, 0, proactor_ ) == -1 )
		ACE_ERROR ((LM_ERROR,
					ACE_TEXT ("(%t) %p\n"),
					ACE_TEXT ("Realm_Service::ACE_Asynch_Read_Stream::open")));
    else
	{
		if( this->initiate_read_stream() == -1 )
			ACE_ERROR ((LM_ERROR,
						ACE_TEXT ("(%t) %p\n"),
						ACE_TEXT ("Realm_Service::ACE_Asynch_Read_Stream::open")));
		else
			ACE_DEBUG ((LM_DEBUG, ACE_TEXT("(%t) Realm_Service::open OK. handle %d\n"), reinterpret_cast<int>(this->handle_)));
	}

	// connect packet
	ACE_Message_Block * con_packet;
	ACE_NEW_NORETURN (con_packet, ACE_Message_Block(8, MB_CONNECT_PACKET));
	unsigned int handle_addr = reinterpret_cast<unsigned int>( this->handle_ );
	con_packet->copy( reinterpret_cast<const char *>(&handle_addr), sizeof(handle_addr) );
	unsigned int this_addr = reinterpret_cast<unsigned int>( this );
	con_packet->copy( reinterpret_cast<const char *>(&this_addr), sizeof(this_addr) );
	if( REALM_SERVER->putq( con_packet->duplicate() ) == -1 )
		ACE_ERROR ((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("Realm_Service::open put connect packet error")));
	con_packet->release();
}

int Realm_Service::initiate_read_stream (void)
{
	if (this->handle() == ACE_INVALID_HANDLE)
		return -1;

	ACE_Message_Block * mb = 0;
	ACE_NEW_RETURN (mb, ACE_Message_Block(128, MB_NORMAL_PACKET),  -1);
	unsigned int handle_addr = reinterpret_cast<unsigned int>( this->handle_ );
	mb->copy( reinterpret_cast<const char *>(&handle_addr), sizeof(handle_addr) );

	// Inititiate read
	if( this->reader_.read( *mb, mb->size() - 4 ) == -1 )
	{
		mb->release();
		ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("(%t) Realm_Service %p\n"), ACE_TEXT ("read")), -1);
	}

	return 0;
}

int Realm_Service::initiate_write_stream( ACE_Message_Block &mb, size_t nbytes )
{
	if (this->handle() == ACE_INVALID_HANDLE)
	{
		mb.release();
		return -1;
	}

	if( nbytes == 0 )
	{
		mb.release();
		ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("(%t) Realm_Service::ACE_Asynch_Write_Stream::write nbytes <0 ")), -1);
	}

	if( this->writer_.write(mb, nbytes) == -1 )
	{
		mb.release();
		ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("(%t) Realm_Service %p\n"), ACE_TEXT ("write")), -1);
	}

	return 0;
}

void Realm_Service::handle_read_stream( const ACE_Asynch_Read_Stream::Result &result )
{
	ACE_Message_Block &mb = result.message_block();
	if( this->server_closed_ ||
		!result.success() || result.bytes_transferred() == 0 )
	{
		mb.release();
		ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("(%t) Realm_Service::handle_read_stream Connection Closed\n")));

		// close socket
		if( this->handle() != ACE_INVALID_HANDLE )
			this->close_socket();
		return;
	}
	else
	{
		// data packet
		if( REALM_SERVER->putq( &mb ) == -1 )
			ACE_ERROR ((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("Realm_Service::handle_read_stream put normal packet error")));
	}

	this->initiate_read_stream();
	return;
}

void Realm_Service::handle_write_stream( const ACE_Asynch_Write_Stream::Result &result )
{
	result.message_block().release();

	ACE_DEBUG ((LM_DEBUG, ACE_TEXT("(%t) Realm_Service::handle_write_stream Write Data OK\n")));
	return;
}

void Realm_Service::send_buffer( const char * data, int len )
{
	ACE_Message_Block * mb;
	ACE_NEW_NORETURN (mb, ACE_Message_Block(len));
	mb->copy( data, len );
	this->initiate_write_stream( *mb, len );
}

void Realm_Service::server_close()
{
	this->server_closed_ = true;
}
