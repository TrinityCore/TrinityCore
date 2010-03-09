/*
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
  \ingroup realmd
  */

#include "RealmSocket.h"

#include <ace/OS_NS_string.h>
#include <ace/INET_Addr.h>
#include <ace/SString.h>

#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 0
#endif

RealmSocket::Session::Session(void)
{
}

RealmSocket::Session::~Session(void)
{
}

RealmSocket::RealmSocket(void):
    input_buffer_(4096),
    session_(NULL),
    remote_address_()
{
    this->reference_counting_policy().value(
            ACE_Event_Handler::Reference_Counting_Policy::ENABLED);

    this->msg_queue()->high_water_mark(8*1024*1024);
    this->msg_queue()->low_water_mark(8*1024*1024);
}

/*virtual*/ RealmSocket::~RealmSocket(void)
{
    if(this->session_)
        delete this->session_;

    if(this->peer().get_handle() != ACE_INVALID_HANDLE)
        this->peer().close();
}

/*virtual*/ int RealmSocket::open(void * arg)
{
    if(Base::open(arg) == -1)
        return -1;

    ACE_INET_Addr addr;

    if(peer().get_remote_addr(addr) == -1)
        return -1;

    char address[1024];

    addr.get_host_addr(address, 1024);

    this->remote_address_ = address;

    if(this->session_ != NULL)
    {
        // Prepare for upcall
        this->add_reference();
        ACE_Event_Handler_var guard(this);

        this->session_->OnAccept();
    }

    this->remove_reference();

    return 0;
}

const ACE_CString& RealmSocket::get_remote_address(void) const
{
    return this->remote_address_;
}

size_t RealmSocket::recv_len(void) const
{
    return this->input_buffer_.length();
}

bool RealmSocket::recv_soft(char *buf, size_t len)
{
    if(this->input_buffer_.length() < len)
        return false;

    ACE_OS::memcpy(buf, this->input_buffer_.rd_ptr(), len);

    return true;
}

bool RealmSocket::recv(char *buf, size_t len)
{
    bool ret = this->recv_soft(buf, len);

    if(ret)
        this->recv_skip(len);

    return ret;
}

void RealmSocket::recv_skip(size_t len)
{
    this->input_buffer_.rd_ptr(len);
}

ssize_t RealmSocket::noblk_send(ACE_Message_Block &message_block)
{
    const size_t len = message_block.length();

    if(len == 0)
        return -1;

    // Try to send the message directly.
    ssize_t n = this->peer().send(message_block.rd_ptr(), len, MSG_NOSIGNAL);

    if(n < 0)
    {
        if(errno == EWOULDBLOCK)
            // Blocking signal
            return 0;
        else
            // Error happened
            return -1;
    }
    else if(n == 0)
    {
        // Can this happen ?
        return -1;
    }

    // return bytes transmitted
    return n;
}

bool RealmSocket::send(const char *buf, size_t len)
{
    if(buf == NULL || len == 0)
        return true;

    ACE_Data_Block db(
            len,
            ACE_Message_Block::MB_DATA,
            (const char*)buf,
            0,
            0,
            ACE_Message_Block::DONT_DELETE,
            0);

    ACE_Message_Block message_block(
            &db,
            ACE_Message_Block::DONT_DELETE,
            0);

    message_block.wr_ptr(len);

    if(this->msg_queue()->is_empty())
    {
        // Try to send it directly.
        ssize_t n = this->noblk_send(message_block);

        if(n < 0)
            return false;
        else if(n == len)
            return true;

        // fall down
        message_block.rd_ptr((size_t)n);
    }

    ACE_Message_Block *mb = message_block.clone();

    if(this->msg_queue()->enqueue_tail(mb, (ACE_Time_Value *) &ACE_Time_Value::zero) == -1)
    {
        mb->release();
        return false;
    }

    if(this->reactor()->schedule_wakeup(this, ACE_Event_Handler::WRITE_MASK) == -1)
        return false;

    return true;
}

/*virtual*/ int RealmSocket::handle_output(ACE_HANDLE /*= ACE_INVALID_HANDLE*/)
{
    ACE_Message_Block *mb = 0;

    if(this->msg_queue()->is_empty())
    {
        this->reactor()->cancel_wakeup(this, ACE_Event_Handler::WRITE_MASK);
        return 0;
    }

    if(this->msg_queue()->dequeue_head(mb, (ACE_Time_Value *) &ACE_Time_Value::zero) == -1)
        return -1;

    ssize_t n = this->noblk_send(*mb);

    if(n < 0)
    {
        mb->release();
        return -1;
    }
    else if(n == mb->length())
    {
        mb->release();
        return 1;
    }
    else
    {
        mb->rd_ptr(n);

        if(this->msg_queue()->enqueue_head(mb, (ACE_Time_Value *) &ACE_Time_Value::zero) == -1)
        {
            mb->release();
            return -1;
        }

        return 0;
    }

    ACE_NOTREACHED(return -1);
}

/*virtual*/ int RealmSocket::handle_input(ACE_HANDLE /*= ACE_INVALID_HANDLE*/)
{
    const ssize_t space = this->input_buffer_.space();

    ssize_t n = this->peer().recv(this->input_buffer_.wr_ptr(), space);

    if(n < 0)
    {
        return errno == EWOULDBLOCK ? 0 : -1;
    }
    else if(n == 0)
    {
        // EOF
        return -1;
    }

    this->input_buffer_.wr_ptr((size_t)n);

    if(this->session_ != NULL)
    {
        // Prepare for upcall
        this->add_reference();
        ACE_Event_Handler_var guard(this);

        this->session_->OnRead();

        this->input_buffer_.crunch();
    }

    // return 1 in case there is more data to read from OS
    return n == space ? 1 : 0;
}

/*virtual*/ int RealmSocket::handle_close(ACE_HANDLE h, ACE_Reactor_Mask m)
{
    if(this->session_ != NULL)
    {
        // Prepare for upcall
        this->add_reference();
        ACE_Event_Handler_var guard(this);

        this->session_->OnClose();
    }

    this->shutdown();

    return 0;
}

void RealmSocket::set_session(Session* session)
{
    if(this->session_ != NULL)
        delete this->session_;

    this->session_ = session;
}

int RealmSocket::close(int)
{
    this->shutdown();

    this->remove_reference();

    return 0;
}
