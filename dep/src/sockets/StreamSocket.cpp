#include "StreamSocket.h"
#include "ISocketHandler.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

StreamSocket::StreamSocket(ISocketHandler& h) : Socket(h)
,m_bConnecting(false)
,m_connect_timeout(5)
,m_flush_before_close(true)
,m_connection_retry(0)
,m_retries(0)
,m_call_on_connect(false)
,m_b_retry_connect(false)
,m_line_protocol(false)
,m_shutdown(0)
{
}

StreamSocket::~StreamSocket()
{
}

void StreamSocket::SetConnecting(bool x)
{
    if (x != m_bConnecting)
    {
        m_bConnecting = x;
        if (x)
        {
            SetTimeout( GetConnectTimeout() );
        }
        else
        {
            SetTimeout( 0 );
        }
    }
}

bool StreamSocket::Connecting()
{
    return m_bConnecting;
}

bool StreamSocket::Ready()
{
    if (GetSocket() != INVALID_SOCKET && !Connecting() && !CloseAndDelete())
        return true;
    return false;
}

void StreamSocket::SetConnectTimeout(int x)
{
    m_connect_timeout = x;
}

int StreamSocket::GetConnectTimeout()
{
    return m_connect_timeout;
}

void StreamSocket::SetFlushBeforeClose(bool x)
{
    m_flush_before_close = x;
}

bool StreamSocket::GetFlushBeforeClose()
{
    return m_flush_before_close;
}

int StreamSocket::GetConnectionRetry()
{
    return m_connection_retry;
}

void StreamSocket::SetConnectionRetry(int x)
{
    m_connection_retry = x;
}

int StreamSocket::GetConnectionRetries()
{
    return m_retries;
}

void StreamSocket::IncreaseConnectionRetries()
{
    m_retries++;
}

void StreamSocket::ResetConnectionRetries()
{
    m_retries = 0;
}

void StreamSocket::SetCallOnConnect(bool x)
{
    Handler().AddList(GetSocket(), LIST_CALLONCONNECT, x);
    m_call_on_connect = x;
}

bool StreamSocket::CallOnConnect()
{
    return m_call_on_connect;
}

void StreamSocket::SetRetryClientConnect(bool x)
{
    Handler().AddList(GetSocket(), LIST_RETRY, x);
    m_b_retry_connect = x;
}

bool StreamSocket::RetryClientConnect()
{
    return m_b_retry_connect;
}

void StreamSocket::SetLineProtocol(bool x)
{
    m_line_protocol = x;
}

bool StreamSocket::LineProtocol()
{
    return m_line_protocol;
}

void StreamSocket::SetShutdown(int x)
{
    m_shutdown = x;
}

int StreamSocket::GetShutdown()
{
    return m_shutdown;
}


#ifdef SOCKETS_NAMESPACE
} // namespace SOCKETS_NAMESPACE {
#endif


