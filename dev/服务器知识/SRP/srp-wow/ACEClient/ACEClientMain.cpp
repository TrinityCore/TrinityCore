
#include <ace/os.h>
#include <ace/OS_main.h>
#include <ace/OS_Memory.h>
#include <ace/INET_Addr.h>
#include <ace/SOCK_Stream.h>
#include <ace/SOCK_Connector.h>
#include <ace/Log_Msg.h>
#include <ace/Message_Block.h>
#include <ace/Time_Value.h>
#include <assert.h>
#include <string>
#include "RealmPacket.h"
#include "Utility/ByteBuffer.h"
#include "Utility/BigNumber.h"
#include "Utility/Sha1.h"

int ACE_TMAIN (int, ACE_TCHAR *[])
{
	ACE_INET_Addr srvr (3724, "127.0.0.1");
	std::string username = "QINGLAN";
	std::string password = "123456";

//	ACE_INET_Addr srvr (3724, "61.135.176.111");
//	std::string username = "QINGLAN_1";
//	std::string password = "Q123456";
	ACE_SOCK_Connector connector;
	ACE_SOCK_Stream peer;

	if (-1 == connector.connect (peer, srvr))
		ACE_ERROR_RETURN ((LM_ERROR,
		ACE_TEXT ("%p\n"),
		ACE_TEXT ("connect")), 1);

	// 1. 发送用户名
	ACE_Message_Block * mb;
	ACE_NEW_RETURN (mb, ACE_Message_Block(1024), -1);
	stLogonRequest_C * logon_request = (stLogonRequest_C *)mb->wr_ptr();
	logon_request->cmd = AUTH_LOGON_REQUEST;
	logon_request->error = 3;
	strcpy( (char *)logon_request->gamename, "WoW" );
	char ttt[] = { 0x57, 0x6F, 0x57, 0x00 };
	memcpy( logon_request->gamename, ttt, 4 );
	logon_request->version1 = 1;
	logon_request->version2 = 11;
	logon_request->version3 = 2;
	logon_request->build = 5464;
	strcpy( (char *)logon_request->platform, "68x" );
	strcpy( (char *)logon_request->os, "niW" );
	strncpy( (char *)logon_request->country, "NChz", 4 );
	logon_request->timezone_bias = 480;
	logon_request->ip = htonl(16777343);
	char tt[] = { 0xc0, 0xa8, 0x00, 0x02 };
	memcpy( &logon_request->ip, tt, 4 );
	logon_request->I_len = username.length();
	strncpy( (char *)logon_request->I, username.c_str(), username.length() );
	mb->wr_ptr( sizeof(stLogonRequest_C) + username.length() - 1 );
	logon_request->size = mb->length() - 4;
	ssize_t send_len = peer.send_n( mb->rd_ptr(), mb->length() );
	assert( send_len == mb->length() );
	mb->release();

	// 2. 接收N g s B
	char buf[1024];
	int bc;

	bc = peer.recv (buf, sizeof(buf));
	if( bc == -1 )
	{
		printf( "%d", errno );
		return -1;
	}
	else if( bc == 0 )
	{
		printf( "connection closed.\n" );
		return -1;
	}
	assert( bc >= sizeof(stLogonRequest_S) );

	stLogonRequest_S * logon_request_s = (stLogonRequest_S *)buf;
	BigNumber N, g, s, B;
	N.SetBinary( logon_request_s->N, logon_request_s->N_len );
	g.SetBinary( logon_request_s->g, logon_request_s->g_len );
	s.SetBinary( logon_request_s->s, 0x20 );
	B.SetBinary( logon_request_s->B, 0x20 );

	// 3. 计算A
	// a = random() A = g^a % N
	BigNumber a, A;
	a.SetRand( 32 * 8 );
	A = g.ModExp(a, N);

	// 4. 计算x
	// x = SHA( s + SHA(username + ":" + raw password) )
	Sha1Hash I;
	std::string sI = username + ":" + password;
	I.UpdateData(sI);
	I.Finalize();

	Sha1Hash sha;
	sha.Initialize();
	sha.UpdateData(s.AsByteArray(), s.GetNumBytes());
	sha.UpdateData(I.GetDigest(), 20);
	sha.Finalize();

	BigNumber x;
	x.SetBinary( sha.GetDigest(), 20 );

	// 5. 计算u
	// u = SHA( A + B )
	sha.Initialize();
	sha.UpdateBigNumbers( &A, &B, NULL );
	sha.Finalize();

	BigNumber u;
	u.SetBinary( sha.GetDigest(), 20 );

	// 6. 计算S
	// S = ( B - g^x) ^(a + u*x) % N
	BigNumber v = g.ModExp(x, N);
	BigNumber S = (B - v * 3).ModExp(a + u*x, N);

	// 7. 计算K
	// K = SHA_Interleave( S )
	unsigned char t[32];
	unsigned char t1[16];
	unsigned char vK[40];
	memcpy( t, S.AsByteArray(), 32 );
	for (int i = 0; i < 16; i++)
		t1[i] = t[i*2];

	sha.Initialize();
	sha.UpdateData( t1, 16 );
	sha.Finalize();
	for (int i = 0; i < 20; i++)
		vK[i*2] = sha.GetDigest()[i];
	for (int i = 0; i < 16; i++)
		t1[i] = t[i*2+1];

	sha.Initialize();
	sha.UpdateData( t1, 16 );
	sha.Finalize();
	for (int i = 0; i < 20; i++)
	{
		vK[i*2+1] = sha.GetDigest()[i];
	}

	BigNumber K;
	K.SetBinary(vK, 40);

	// 8. 计算M
	// M = H(H(N) XOR H(g) + H(username) + s + A + B + K)
	unsigned char hash[20];

	sha.Initialize();
	sha.UpdateBigNumbers(&N, NULL);
	sha.Finalize();
	memcpy(hash, sha.GetDigest(), 20);
	sha.Initialize();
	sha.UpdateBigNumbers(&g, NULL);
	sha.Finalize();
	for (int i = 0; i < 20; i++)
		hash[i] ^= sha.GetDigest()[i];

	BigNumber t3;
	t3.SetBinary(hash, 20);

	sha.Initialize();
	sha.UpdateData(username);
	sha.Finalize();
	BigNumber t4;
	t4.SetBinary(sha.GetDigest(), 20);

	sha.Initialize();
	sha.UpdateBigNumbers(&t3, &t4, &s, &A, &B, &K, NULL);
	sha.Finalize();
	BigNumber M;
	M.SetBinary(sha.GetDigest(), 20);

	// 请求验证
	ACE_Message_Block * mb_2;
	ACE_NEW_RETURN (mb_2, ACE_Message_Block(1024), -1);
	stLogonCheck_C * logon_check = (stLogonCheck_C *)mb_2->wr_ptr();
	memset( logon_check, 0, sizeof(stLogonCheck_C) );
	logon_check->cmd = AUTH_LOGON_CHECK;
	memcpy( logon_check->A, A.AsByteArray(), 0x20 );
	memcpy( logon_check->M1, M.AsByteArray(), 20 );
	mb_2->wr_ptr( sizeof(stLogonCheck_C) );
	send_len  = peer.send_n( mb_2->rd_ptr(), mb_2->length() );
	assert( send_len == mb_2->length() );
	mb_2->release();

	// 验证结果
	bc = peer.recv (buf, sizeof(buf));
	if( bc == -1 )
	{
		printf( "%d", errno );
		return -1;
	}
	else if( bc == 0 )
	{
		printf( "connection closed.\n" );
		return -1;
	}
	//assert( bc == sizeof(stLogonCheck_S) );
	stLogonCheck_S * logon_check_s = (stLogonCheck_S *)buf;

	peer.close ();

	return (0);
}
