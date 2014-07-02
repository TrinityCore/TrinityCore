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

#include <memory>
#include <boost/asio/write.hpp>
#include "RASession.h"

using boost::asio::ip::tcp;

void RASession::AsyncRead()
{
    auto self(shared_from_this());

    _socket.async_read_some(boost::asio::buffer(_readBuffer, 1), [this, self](boost::system::error_code error, size_t transferedBytes)
    {
        if (!error && transferedBytes == 1)
        {
            // let the magic happen
        }
        else
        {
            _socket.close();
        }
    });
}

void RASession::AsyncWrite(std::size_t length)
{
    boost::asio::async_write(_socket, boost::asio::buffer(_writeBuffer, length), [this](boost::system::error_code error, std::size_t /*length*/)
    {
        if (error)
        {
            _socket.close();
        }
    });
}

