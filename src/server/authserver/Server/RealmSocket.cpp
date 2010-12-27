/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
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

#include <ace/OS_NS_string.h>
#include <ace/INET_Addr.h>
#include <ace/SString.h>

#include "RealmSocket.h"
#include "Log.h"

#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 0
#endif

RealmSocket::Session::Session(void) {}

RealmSocket::Session::~Session(void) { }

RealmSocket::RealmSocket(void) : input_buffer_(4096), session_(NULL), remote_address_()
{
    reference_counting_policy().value(ACE_Event_Handler::Reference_Counting_Policy::ENABLED);

    msg_queue()->high_water_mark(8 * 1024 * 1024);
    msg_queue()->low_water_mark(8 * 1024 * 1024);
}

RealmSocket::~RealmSocket(void)
{
    if (msg_queue())
        msg_queue()->close();

    // delete RealmSocketObject must never be called from our code.
    closing_ = true;

    if (session_)
        delete session_;

    peer().close();
}

int RealmSocket::open(void * arg)
{
    ACE_INET_Addr addr;

    if (peer().get_remote_addr(addr) == -1)
    {
        sLog->outError("Error %s while opening realm socket!", ACE_OS::strerror(errno));
        return -1;
    }

    remote_address_ = addr.get_host_addr();

    // Register with ACE Reactor
    if (Base::open(arg) == -1)
        return -1;

    if (session_)
        session_->OnAccept();

    // reactor takes care of the socket from now on
    remove_reference();

    return 0;
}

int RealmSocket::close(int)
{
    shutdown();

    closing_ = true;

    remove_reference();

    return 0;
}

const std::string& RealmSocket::get_remote_address(void) const
{
    return remote_address_;
}

size_t RealmSocket::recv_len(void) const
{
    return input_buffer_.length();
}

bool RealmSocket::recv_soft(char *buf, size_t len)
{
    if (input_buffer_.length() < len)
        return false;

    ACE_OS::memcpy(buf, input_buffer_.rd_ptr(), len);

    return true;
}

bool RealmSocket::recv(char *buf, size_t len)
{
    bool ret = recv_soft(buf, len);

    if (ret)
        recv_skip(len);

    return ret;
}

void RealmSocket::recv_skip(size_t len)
{
    input_buffer_.rd_ptr(len);
}

ssize_t RealmSocket::noblk_send(ACE_Message_Block &message_block)
{
    const size_t len = message_block.length();

    if (len == 0)
        return -1;

    // Try to send the message directly.
    ssize_t n = peer().send(message_block.rd_ptr(), len, MSG_NOSIGNAL);

    if (n < 0)
    {
        if (errno == EWOULDBLOCK) // Blocking signal
            return 0;
        else // Error happened
            return -1;
    }
    else if (n == 0)
    {
        // Can this happen ?
        return -1;
    }

    // return bytes transmitted
    return n;
}

bool RealmSocket::send(const char *buf, size_t len)
{
    if (buf == NULL || len == 0)
        return true;

    ACE_Data_Block db(len, ACE_Message_Block::MB_DATA, (const char*)buf, 0, 0, ACE_Message_Block::DONT_DELETE, 0);
    ACE_Message_Block message_block(&db, ACE_Message_Block::DONT_DELETE, 0);

    message_block.wr_ptr(len);

    if (msg_queue()->is_empty())
    {
        // Try to send it directly.
        ssize_t n = noblk_send(message_block);

        if (n < 0)
            return false;

        size_t un = size_t(n);
        if (un == len)
            return true;

        // fall down
        message_block.rd_ptr(un);
    }

    ACE_Message_Block *mb = message_block.clone();

    if (msg_queue()->enqueue_tail(mb, (ACE_Time_Value *)(&ACE_Time_Value::zero)) == -1)
    {
        mb->release();
        return false;
    }

    if (reactor()->schedule_wakeup(this, ACE_Event_Handler::WRITE_MASK) == -1)
        return false;

    return true;
}

int RealmSocket::handle_output(ACE_HANDLE)
{
    if (closing_)
        return -1;

    ACE_Message_Block *mb = 0;

    if (msg_queue()->is_empty())
    {
        reactor()->cancel_wakeup(this, ACE_Event_Handler::WRITE_MASK);
        return 0;
    }

    if (msg_queue()->dequeue_head(mb, (ACE_Time_Value *)(&ACE_Time_Value::zero)) == -1)
        return -1;

    ssize_t n = noblk_send(*mb);

    if (n < 0)
    {
        mb->release();
        return -1;
    }
    else if (size_t(n) == mb->length())
    {
        mb->release();
        return 1;
    }
    else
    {
        mb->rd_ptr(n);

        if (msg_queue()->enqueue_head(mb, (ACE_Time_Value *) &ACE_Time_Value::zero) == -1)
        {
            mb->release();
            return -1;
        }

        return 0;
    }

    ACE_NOTREACHED(return -1);
}

int RealmSocket::handle_close(ACE_HANDLE h, ACE_Reactor_Mask)
{
    // As opposed to WorldSocket::handle_close, we don't need locks here.
    closing_ = true;

    if (h == ACE_INVALID_HANDLE)
        peer().close_writer();

    if (session_)
        session_->OnClose();

    return 0;
}

int RealmSocket::handle_input(ACE_HANDLE)
{
    if (closing_)
        return -1;

    const ssize_t space = input_buffer_.space();

    ssize_t n = peer().recv(input_buffer_.wr_ptr(), space);

    if (n < 0)
        return errno == EWOULDBLOCK ? 0 : -1;
    else if (n == 0) // EOF
        return -1;

    input_buffer_.wr_ptr((size_t)n);

    if (session_ != NULL)
    {
        session_->OnRead();
        input_buffer_.crunch();
    }

    // return 1 in case there is more data to read from OS
    return n == space ? 1 : 0;
}


void RealmSocket::set_session(Session* session)
{
    if (session_ != NULL)
        delete session_;

    session_ = session;
}
