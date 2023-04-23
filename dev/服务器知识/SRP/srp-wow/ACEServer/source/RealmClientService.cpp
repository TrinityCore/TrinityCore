
#include <ace/Message_Block.h>
#include <algorithm>

#include "RealmClientService.h"
#include "RealmService.h"
#include "RealmPacket.h"
#include "RealmServer.h"
#include "Utility/Sha1.h"
#include "Utility/ByteBuffer.h"

Realm_Client_Service::Realm_Client_Service( Realm_Service * network )
{
	this->network_service_ = network;

	N.SetHexStr( "894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7" );
	g.SetDword( 7 );
	s.SetRand( 32 * 8 );
}

Realm_Client_Service::~Realm_Client_Service()
{
	delete this->network_service_;
}

int Realm_Client_Service::process( ACE_Message_Block * message )
{
	unsigned char * command = reinterpret_cast<unsigned char *>( message->rd_ptr() );
	if( *command == AUTH_LOGON_REQUEST )
	{
		process_logon_request( *message );
	}
	else if( *command == AUTH_LOGON_CHECK )
	{
		process_logon_check( *message );
	}
	else if( *command == AUTH_REALM_LIST )
	{
		process_realm_list( *message );
	}
	else
	{
		ACE_ERROR ((LM_ERROR, ACE_TEXT("Client_Service::process got unknown packet %u\n"), *command));
	}

	return 0;
}

void Realm_Client_Service::process_logon_request( ACE_Message_Block & mb )
{
	stLogonRequest_C * logon_request = reinterpret_cast<stLogonRequest_C *>( mb.rd_ptr() );
	if( logon_request->size + 4 != mb.length() )
	{
		ACE_ERROR ((LM_ERROR, ACE_TEXT("Client_Service::process_logon_request logon request data length error. %d : %d\n"), logon_request->size, mb.length()));
		return;
	}

	char login_name[64];
	memset( login_name, 0, 64 );
	strncpy( login_name, (const char *)logon_request->I, logon_request->I_len );
	login_ = login_name;
	ACE_DEBUG ((LM_DEBUG, ACE_TEXT("[Auth] user %s request logon\n"), login_name));

	std::string password = "q123456";

	// º∆À„hash÷µ
	std::transform( password.begin(), password.end(), password.begin(), std::towupper );

	Sha1Hash I;
	std::string sI = login_ + ":" + password;
	I.UpdateData(sI);
	I.Finalize();

	Sha1Hash sha;
	sha.UpdateData(s.AsByteArray(), s.GetNumBytes());
	sha.UpdateData(I.GetDigest(), 20);
	sha.Finalize();

	BigNumber x;
	x.SetBinary(sha.GetDigest(), sha.GetLength());
	v = g.ModExp(x, N);
	b.SetRand(19 * 8);
	BigNumber gmod=g.ModExp(b, N);
	B = ((v * 3) + gmod) % N;
	assert(gmod.GetNumBytes() <= 32);

	BigNumber unk3;
	unk3.SetRand( 16 * 8 );

	// respond data
	stLogonRequest_S answer_data;
	answer_data.cmd = AUTH_LOGON_REQUEST;
	answer_data.error = 0x00;
	answer_data.unk2 = 0x00;
	memcpy( answer_data.B, B.AsByteArray(), 0x20 );
	answer_data.g_len = 0x01;
	memcpy( answer_data.g, g.AsByteArray(), 0x01 );
	answer_data.N_len = 0x20;
	memcpy( answer_data.N, N.AsByteArray(), 0x20 );
	memcpy( answer_data.s, s.AsByteArray(), 0x20 );
	memcpy( answer_data.unk3, unk3.AsByteArray(), 0x10 );

	this->network_service_->send_buffer( (const char *)&answer_data, sizeof(answer_data) );
}

void Realm_Client_Service::process_logon_check( ACE_Message_Block & mb )
{
	if( mb.length() != sizeof(stLogonCheck_C) )
	{
		ACE_ERROR ((LM_ERROR, ACE_TEXT("Client_Service::process_logon_check logon request data length error. %d : %d\n"), sizeof(stLogonCheck_C), mb.length()));
		return;
	}
	stLogonCheck_C * logon_check = reinterpret_cast<stLogonCheck_C *>( mb.rd_ptr() );

	BigNumber A;
	A.SetBinary( logon_check->A, 32 );

	Sha1Hash sha;
	sha.UpdateBigNumbers( &A, &B, NULL );
	sha.Finalize();

	BigNumber u;
	u.SetBinary( sha.GetDigest(), 20 );
	BigNumber S = (A * (v.ModExp(u, N))).ModExp(b, N);

	unsigned char t[32];
	unsigned char t1[16];
	unsigned char vK[40];
	memcpy( t, S.AsByteArray(), 32 );
	for (int i = 0; i < 16; i++)
	{
		t1[i] = t[i*2];
	}

	sha.Initialize();
	sha.UpdateData( t1, 16 );
	sha.Finalize();
	for (int i = 0; i < 20; i++)
	{
		vK[i*2] = sha.GetDigest()[i];
	}
	for (int i = 0; i < 16; i++)
	{
		t1[i] = t[i*2+1];
	}

	sha.Initialize();
	sha.UpdateData( t1, 16 );
	sha.Finalize();
	for (int i = 0; i < 20; i++)
	{
		vK[i*2+1] = sha.GetDigest()[i];
	}
	K.SetBinary(vK, 40);

	unsigned char hash[20];

	sha.Initialize();
	sha.UpdateBigNumbers(&N, NULL);
	sha.Finalize();
	memcpy(hash, sha.GetDigest(), 20);
	sha.Initialize();
	sha.UpdateBigNumbers(&g, NULL);
	sha.Finalize();
	for (int i = 0; i < 20; i++)
	{
		hash[i] ^= sha.GetDigest()[i];
	}
	BigNumber t3;
	t3.SetBinary(hash, 20);

	sha.Initialize();
	sha.UpdateData(login_);
	sha.Finalize();
	BigNumber t4;
	t4.SetBinary(sha.GetDigest(), 20);

	sha.Initialize();
	sha.UpdateBigNumbers(&t3, &t4, &s, &A, &B, &K, NULL);
	sha.Finalize();
	BigNumber M;
	M.SetBinary(sha.GetDigest(), 20);

	if (!memcmp(M.AsByteArray(), logon_check->M1, 20))
	{
		sha.Initialize();
		sha.UpdateBigNumbers(&A, &M, &K, NULL);
		sha.Finalize();

		stLogonCheck_S proof;
		memcpy(proof.M2, sha.GetDigest(), 20);
		proof.cmd = AUTH_LOGON_CHECK;
		proof.error = 0;
		proof.unk2 = 0;

		this->network_service_->send_buffer( (const char *)&proof, sizeof(proof) );
	}
	else
	{
		char data[2]={AUTH_LOGON_CHECK,4};
		this->network_service_->send_buffer( data, sizeof(data) );
	}
}

void Realm_Client_Service::process_realm_list( ACE_Message_Block & mb )
{
	if( mb.length() != 5 )
	{
		ACE_ERROR ((LM_ERROR, ACE_TEXT("Client_Service::process_realm_list realm list request data length error. %d\n"), mb.length()));
		return;
	}

	ByteBuffer pkt;
	pkt << (unsigned long) 0;
	pkt << (unsigned char) 1;

	pkt << (unsigned long) 1;
	pkt << (unsigned char) 0;
	pkt << "MyServer";
	char server_addr[32];
	sprintf( server_addr, "%s:%d", "127.0.0.1", 5223 );
	pkt << server_addr;
	pkt << (float) 1.6;
	pkt << (unsigned char) 0;
	pkt << (unsigned char) 1;
	pkt << (unsigned char) 0;

	pkt << (unsigned char) 0;                             
	pkt << (unsigned char) 0x2;                           

	ByteBuffer hdr;
	hdr << (unsigned char) AUTH_REALM_LIST;
	hdr << (unsigned short)pkt.size();
	hdr.append(pkt);

	this->network_service_->send_buffer( (const char *)hdr.contents(), hdr.size() );
}

