#include "ace/Remote_Name_Space.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/SString.h"
#include "ace/OS_NS_string.h"

ACE_RCSID (ace,
           Remote_Name_Space,
           "$Id: Remote_Name_Space.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int
ACE_Remote_Name_Space::open (const ACE_TCHAR *servername, u_short port)
{
  ACE_TRACE ("ACE_Remote_Name_Space::open");
  ACE_INET_Addr servaddr;

  // Initialize Addr
  if (servaddr.set (port, servername) == -1)
    return -1;

  // Connect to Name Server process.
  if (this->ns_proxy_.open (servaddr) == -1)
    return -1;

  return 0;
}

ACE_Remote_Name_Space::ACE_Remote_Name_Space (void)
{
  ACE_TRACE ("ACE_Remote_Name_Space::ACE_Remote_Name_Space");
}

ACE_Remote_Name_Space::ACE_Remote_Name_Space (const ACE_TCHAR *hostname,
                                              u_short port)
{
  ACE_TRACE ("ACE_Remote_Name_Space::ACE_Remote_Name_Space");
  if (this->open (hostname, port) == -1)
    ACE_ERROR ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("ACE_Remote_Name_Space::ACE_Remote_Name_Space")));
}

int
ACE_Remote_Name_Space::bind (const ACE_NS_WString &name,
                             const ACE_NS_WString &value,
                             const char *type)
{
  ACE_TRACE ("ACE_Remote_Name_Space::bind");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> name_urep (name.rep ());
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> value_urep (value.rep ());
  ACE_UINT32 name_len =
    static_cast<ACE_UINT32> (name.length () * sizeof (ACE_WCHAR_T));
  ACE_UINT32 value_len =
    static_cast<ACE_UINT32> (value.length () * sizeof (ACE_WCHAR_T));
  ACE_UINT32 type_len =
    static_cast<ACE_UINT32> (ACE_OS::strlen (type));
  ACE_Name_Request request (ACE_Name_Request::BIND,
                            name_urep.get (),
                            name_len,
                            value_urep.get (),
                            value_len,
                            type,
                            type_len);
  return this->ns_proxy_.request_reply (request);
}

int
ACE_Remote_Name_Space::rebind (const ACE_NS_WString &name,
                               const ACE_NS_WString &value,
                               const char *type)
{
  ACE_TRACE ("ACE_Remote_Name_Space::rebind");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> name_urep (name.rep ());
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> value_urep (value.rep ());
  ACE_UINT32 name_len =
    static_cast<ACE_UINT32> (name.length () * sizeof (ACE_WCHAR_T));
  ACE_UINT32 value_len =
    static_cast<ACE_UINT32> (value.length () * sizeof (ACE_WCHAR_T));
  ACE_UINT32 type_len =
    static_cast<ACE_UINT32> (ACE_OS::strlen (type));
  ACE_Name_Request request (ACE_Name_Request::REBIND,
                            name_urep.get (),
                            name_len,
                            value_urep.get (),
                            value_len,
                            type,
                            type_len);
  return this->ns_proxy_.request_reply (request);
}

int
ACE_Remote_Name_Space::resolve (const ACE_NS_WString &name,
                                ACE_NS_WString &value,
                                char *&type)
{
  ACE_TRACE ("ACE_Remote_Name_Space::resolve");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> name_urep (name.rep ());
  ACE_UINT32 name_len =
    static_cast<ACE_UINT32> (name.length () * sizeof (ACE_WCHAR_T));
  ACE_Name_Request request (ACE_Name_Request::RESOLVE,
                            name_urep.get (),
                            name_len,
                            0, 0, 0, 0);

  if (this->ns_proxy_.send_request (request) == -1)
    return -1;

  ACE_Name_Request reply;

  if (this->ns_proxy_.recv_reply (reply) == -1)
    return -1;

  ACE_NS_WString temp (reply.value (), reply.value_len () / sizeof (ACE_WCHAR_T));
  value = temp;
  ACE_NEW_RETURN (type,
                  char[reply.type_len () + 1],
                  -1);
  ACE_OS::strcpy (type, reply.type ());
  return 0;
}

int
ACE_Remote_Name_Space::unbind (const ACE_NS_WString &name)
{
  ACE_TRACE ("ACE_Remote_Name_Space::unbind");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> name_urep (name.rep ());
  ACE_UINT32 name_len =
    static_cast<ACE_UINT32> (name.length () * sizeof (ACE_WCHAR_T));
  ACE_Name_Request request (ACE_Name_Request::UNBIND,
                            name_urep.get (),
                            name_len,
                            0, 0, 0, 0);
  return this->ns_proxy_.request_reply (request);
}

int
ACE_Remote_Name_Space::list_names (ACE_WSTRING_SET &set,
                                   const ACE_NS_WString &pattern)
{
  ACE_TRACE ("ACE_Remote_Name_Space::list_names");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> pattern_urep (pattern.rep ());
  ACE_UINT32 pattern_len =
    static_cast<ACE_UINT32> (pattern.length () * sizeof (ACE_WCHAR_T));
  ACE_Name_Request request (ACE_Name_Request::LIST_NAMES,
                            pattern_urep.get (),
                            pattern_len,
                            0, 0, 0, 0);
  if (this->ns_proxy_.send_request (request) == -1)
    return -1;

  ACE_Name_Request reply (0, 0, 0, 0, 0, 0, 0, 0);

  while (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
    {
      if (this->ns_proxy_.recv_reply (reply) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("ACE_Remote_Name_Space::list_names")),
                           -1);
      if (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
        {
          ACE_NS_WString name (reply.name (),
                               reply.name_len () / sizeof (ACE_WCHAR_T));
          set.insert (name);
        }
    }
  return 0;
}

int
ACE_Remote_Name_Space::list_values (ACE_WSTRING_SET &set,
                                    const ACE_NS_WString &pattern)
{
  ACE_TRACE ("ACE_Remote_Name_Space::list_values");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> pattern_urep (pattern.rep ());
  ACE_UINT32 pattern_len =
    static_cast<ACE_UINT32> (pattern.length () * sizeof (ACE_WCHAR_T));
  ACE_Name_Request request (ACE_Name_Request::LIST_VALUES,
                            pattern_urep.get (),
                            pattern_len,
                            0, 0, 0, 0);
  if (this->ns_proxy_.send_request (request) == -1)
    return -1;

  ACE_Name_Request reply (0, 0, 0, 0, 0, 0, 0, 0);

  while (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
    {
      if (this->ns_proxy_.recv_reply (reply) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("ACE_Remote_Name_Space::list_values")),
                           -1);
      if (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
        {
          ACE_NS_WString value (reply.value (),
                                reply.value_len () / sizeof (ACE_WCHAR_T));
          set.insert (value);
        }
    }

  return 0;
}

int
ACE_Remote_Name_Space::list_types (ACE_WSTRING_SET &set,
                                   const ACE_NS_WString &pattern)
{
  ACE_TRACE ("ACE_Remote_Name_Space::list_types");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> pattern_urep (pattern.rep ());
  ACE_UINT32 pattern_len =
    static_cast<ACE_UINT32> (pattern.length () * sizeof (ACE_WCHAR_T));
  ACE_Name_Request request (ACE_Name_Request::LIST_TYPES,
                            pattern_urep.get (),
                            pattern_len,
                            0, 0, 0, 0);

  if (this->ns_proxy_.send_request (request) == -1)
    return -1;

  ACE_Name_Request reply (0, 0, 0, 0, 0, 0, 0, 0);

  while (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
    {
      if (this->ns_proxy_.recv_reply (reply) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("ACE_Remote_Name_Space::list_values")),
                           -1);
      if (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
        {
          ACE_NS_WString type (reply.type ());
          set.insert (type);
        }
    }

  return 0;
}

int
ACE_Remote_Name_Space::list_name_entries (ACE_BINDING_SET &set,
                                          const ACE_NS_WString &pattern)
{
  ACE_TRACE ("ACE_Remote_Name_Space::list_name_entries");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> pattern_urep (pattern.rep ());
  ACE_UINT32 pattern_len =
    static_cast<ACE_UINT32> (pattern.length () * sizeof (ACE_WCHAR_T));
  ACE_Name_Request request (ACE_Name_Request::LIST_NAME_ENTRIES,
                            pattern_urep.get (),
                            pattern_len,
                            0, 0, 0, 0);

  if (this->ns_proxy_.send_request (request) == -1)
    return -1;

  ACE_Name_Request reply (0, 0, 0, 0, 0, 0, 0, 0);

  while (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
    {
      if (this->ns_proxy_.recv_reply (reply) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("ACE_Remote_Name_Space::list_names")),
                           -1);
      if (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
        {
          ACE_NS_WString name (reply.name (),
                               reply.name_len () / sizeof (ACE_WCHAR_T));
          ACE_NS_WString value (reply.value (),
                                reply.value_len () / sizeof (ACE_WCHAR_T));
          ACE_Name_Binding entry (name,
                                  value,
                                  reply.type ());
          if (set.insert (entry) == -1)
            return -1;
        }
    }
  return 0;
}

int
ACE_Remote_Name_Space::list_value_entries (ACE_BINDING_SET &set,
                                           const ACE_NS_WString &pattern)
{
  ACE_TRACE ("ACE_Remote_Name_Space::list_value_entries");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> pattern_urep (pattern.rep ());
  ACE_UINT32 pattern_len =
    static_cast<ACE_UINT32> (pattern.length () * sizeof (ACE_WCHAR_T));
  ACE_Name_Request request (ACE_Name_Request::LIST_VALUE_ENTRIES,
                            pattern_urep.get (),
                            pattern_len,
                            0, 0, 0, 0);

  if (this->ns_proxy_.send_request (request) == -1)
    return -1;

  ACE_Name_Request reply (0, 0, 0, 0, 0, 0, 0, 0);

  while (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
    {
      if (this->ns_proxy_.recv_reply (reply) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("ACE_Remote_Name_Space::list_values")),
                           -1);
      if (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
        {
          ACE_NS_WString name (reply.name (),
                               reply.name_len () / sizeof (ACE_WCHAR_T));
          ACE_NS_WString value (reply.value (),
                                reply.value_len () / sizeof (ACE_WCHAR_T));
          ACE_Name_Binding entry (name,
                                  value,
                                  reply.type());
          if (set.insert (entry) == -1)
            return -1;
        }
    }
  return 0;
}

int
ACE_Remote_Name_Space::list_type_entries (ACE_BINDING_SET &set,
                                          const ACE_NS_WString &pattern)
{
  ACE_TRACE ("ACE_Remote_Name_Space::list_type_entries");
  ACE_Auto_Basic_Array_Ptr<ACE_WCHAR_T> pattern_urep (pattern.rep ());
  ACE_UINT32 pattern_len =
    static_cast<ACE_UINT32> (pattern.length () * sizeof (ACE_WCHAR_T));
  ACE_Name_Request request (ACE_Name_Request::LIST_TYPE_ENTRIES,
                            pattern_urep.get (),
                            pattern_len,
                            0, 0, 0, 0);

  if (this->ns_proxy_.send_request (request) == -1)
    return -1;

  ACE_Name_Request reply (0, 0, 0, 0, 0, 0, 0, 0);

  while (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
    {
      if (this->ns_proxy_.recv_reply (reply) == -1)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p\n"),
                           ACE_TEXT ("ACE_Remote_Name_Space::list_values")),
                          -1);
      if (reply.msg_type () != ACE_Name_Request::MAX_ENUM)
        {
          ACE_NS_WString name (reply.name (),
                               reply.name_len () / sizeof (ACE_WCHAR_T));
          ACE_NS_WString value (reply.value (),
                                reply.value_len () / sizeof (ACE_WCHAR_T));
          ACE_Name_Binding entry (name,
                                  value,
                                  reply.type ());
          if (set.insert (entry) == -1)
              return -1;
        }
    }
  return 0;
}

ACE_Remote_Name_Space::~ACE_Remote_Name_Space (void)
{
  ACE_TRACE ("ACE_Remote_Name_Space::~ACE_Remote_Name_Space");
}

void
ACE_Remote_Name_Space::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Remote_Name_Space::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->ns_proxy_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

