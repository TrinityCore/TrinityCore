/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __AUTHSESSION_H__
#define __AUTHSESSION_H__

#include <memory>
#include <boost/asio.hpp>

#include "Common.h"
#include "BigNumber.h"

using boost::asio::ip::tcp;

const size_t bufferSize = 4096;

#define BUFFER_SIZE 4096

class AuthSession : public std::enable_shared_from_this < AuthSession >
{
public:
	AuthSession(tcp::socket socket) : _socket(std::move(socket))
	{
		N.SetHexStr("894B645E89E1535BBDAD5B8B290650530801B18EBFBF5E8FAB3C82872A3E9BB7");
		g.SetDword(7);
	}

	void Start()
	{
		AsyncReadHeader();
	}

	bool _HandleLogonChallenge();
	bool _HandleLogonProof();
	bool _HandleReconnectChallenge();
	bool _HandleReconnectProof();
	bool _HandleRealmList();

	const std::string GetRemoteIpAddress() const { return _socket.remote_endpoint().address().to_string(); };
	unsigned short GetRemotePort() const { return _socket.remote_endpoint().port(); }

private:
	void AsyncReadHeader();
	void AsyncReadData(bool (AuthSession::*handler)(), size_t dataSize, size_t bufferOffset);
	void AsyncWrite(size_t length);


	void SetVSFields(const std::string& rI);

	BigNumber N, s, g, v;
	BigNumber b, B;
	BigNumber K;
	BigNumber _reconnectProof;

	tcp::socket _socket;
	char _readBuffer[BUFFER_SIZE];
	char _writeBuffer[BUFFER_SIZE];

	bool _isAuthenticated;
	std::string _tokenKey;
	std::string _login;
	std::string _localizationName;
	std::string _os;
	uint16 _build;
	uint8 _expversion;

	AccountTypes _accountSecurityLevel;
};

#endif