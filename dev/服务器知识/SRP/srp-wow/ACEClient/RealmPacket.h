
#ifndef __REALM_PACKET_H__
#define __REALM_PACKET_H__

// opcodes
#define AUTH_LOGON_REQUEST		0x00
#define AUTH_LOGON_CHECK		0x01
#define AUTH_REALM_LIST			0x10

// error code
enum E_AUTH_ERROR_CODE
{
	CE_SUCCESS			= 0x00,		// ≥…π¶
	CE_IPBAN			= 0x01,		// ¡¨Ω” ß∞‹
	CE_ACCOUNT_CLOSED	= 0x03,		// ∑‚∫≈
	CE_NO_ACCOUNT		= 0x04,		// √‹¬Î¥ÌŒÛ
	CE_ACCOUNT_IN_USE	= 0x06		// ’ ∫≈“—µ«¬º
};

#pragma pack(push, 1)

struct stLogonRequest_C
{
	unsigned char   cmd;
	unsigned char   error;
	unsigned short  size;
	unsigned char   gamename[4];
	unsigned char   version1;
	unsigned char   version2;
	unsigned char   version3;
	unsigned short  build;
	unsigned char   platform[4];
	unsigned char   os[4];
	unsigned char   country[4];
	unsigned int	timezone_bias;
	unsigned int	ip;
	unsigned char   I_len;
	unsigned char   I[1];
};

struct stLogonRequest_S
{
	unsigned char   cmd;
	unsigned char   error;
	unsigned char   unk2;
	unsigned char   B[32];
	unsigned char   g_len;
	unsigned char   g[1];
	unsigned char   N_len;
	unsigned char   N[32];
	unsigned char   s[32];
	unsigned char   unk3[16];
};

struct stLogonCheck_C
{
	unsigned char   cmd;
	unsigned char   A[32];
	unsigned char   M1[20];
	unsigned char   crc_hash[20];
	unsigned char   number_of_keys;
};

struct stLogonCheck_S
{
	unsigned char   cmd;
	unsigned char   error;
	unsigned char   M2[20];
	unsigned int	unk2;
};

struct stRealmList_S
{
	unsigned int	icon;		// 1
	unsigned char	color;		// 0
	char			name[1];
	char			address[1];
	float			unknown1;	// 1.6
	unsigned char	chars;		// 0
	unsigned char	timezone;	// 1
	unsigned char	unknown2;	// 0
};

#pragma pack(pop)

#endif // __REALM_PACKET_H__
