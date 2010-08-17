// $Id: ATM_Addr.cpp 84565 2009-02-23 08:20:39Z johnnyw $

// Defines the Internet domain address family address format.

#include "ace/ATM_Addr.h"
#if defined (ACE_HAS_ATM)

#include "ace/Log_Msg.h"

#if defined (ACE_HAS_FORE_ATM_WS2)
#include /**/ "forews2.h"
#endif /* ACE_HAS_FORE_ATM_WS2 */

#if !defined (__ACE_INLINE__)
#include "ace/ATM_Addr.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, ATM_Addr, "$Id: ATM_Addr.cpp 84565 2009-02-23 08:20:39Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_ATM_Addr)

#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
#define BHLI_MAGIC "FORE_ATM"
// This is line rate in cells/s for an OC-3 MM interface.
const long ACE_ATM_Addr::LINE_RATE = 353207;
const int ACE_ATM_Addr::OPT_FLAGS_CPID = 0x1;
const int ACE_ATM_Addr::OPT_FLAGS_PMP = 0x2;
const int ACE_ATM_Addr::DEFAULT_SELECTOR = 0x99;
#elif defined (ACE_HAS_LINUX_ATM)
//pbrandao:for Linux:
//pbrandao:for now stick with current definitions
//pbrandao:see if later need to change
const long ACE_ATM_Addr::LINE_RATE = 353207;
const int ACE_ATM_Addr::OPT_FLAGS_CPID = 0;
const int ACE_ATM_Addr::OPT_FLAGS_PMP = 0;
const int ACE_ATM_Addr::DEFAULT_SELECTOR = 0x99;
#else
const long ACE_ATM_Addr::LINE_RATE = 0L;
const int ACE_ATM_Addr::OPT_FLAGS_CPID = 0;
const int ACE_ATM_Addr::OPT_FLAGS_PMP = 0;
const int ACE_ATM_Addr::DEFAULT_SELECTOR = 0x0;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */

// Default constructor

ACE_ATM_Addr::ACE_ATM_Addr (u_char selector)
#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  : ACE_Addr (AF_ATM,
#elif defined (ACE_HAS_LINUX_ATM)
  : ACE_Addr (PF_ATMSVC,
#else
  : ACE_Addr (AF_UNSPEC,
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
              sizeof this->atm_addr_)
{
  // ACE_TRACE ("ACE_ATM_Addr::ACE_ATM_Addr");
 (void) ACE_OS::memset ((void *) &this->atm_addr_,
                         0,
                         sizeof this->atm_addr_);
  this->init (selector);
}

// Copy constructor.

ACE_ATM_Addr::ACE_ATM_Addr (const ACE_ATM_Addr &sap,
                            u_char selector)
#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  : ACE_Addr (AF_ATM,
#elif defined (ACE_HAS_LINUX_ATM)
  : ACE_Addr (PF_ATMSVC,
#else
  : ACE_Addr (AF_UNSPEC,
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
              sizeof this->atm_addr_)
{
  ACE_TRACE ("ACE_ATM_Addr::ACE_ATM_Addr");
  this->set (sap, selector);
#if defined (ACE_HAS_LINUX_ATM)
  this->atm_addr_.sockaddratmsvc.sas_family = PF_ATMSVC;
  this->atm_addr_.atmsap.blli[0].l3_proto = ATM_L3_NONE;
  this->atm_addr_.atmsap.blli[0].l2_proto = ATM_L2_NONE;
  this->atm_addr_.atmsap.bhli.hl_type = ATM_HL_NONE;
#endif /* ACE_HAS_LINUX_ATM */
}

ACE_ATM_Addr::ACE_ATM_Addr (const ATM_Addr *sap,
                            u_char selector)
#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  : ACE_Addr (AF_ATM,
#elif defined (ACE_HAS_LINUX_ATM)
  : ACE_Addr (PF_ATMSVC,
#else
  : ACE_Addr (AF_UNSPEC,
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
              sizeof this->atm_addr_)
{
  ACE_TRACE ("ACE_ATM_Addr::ACE_ATM_Addr");
  this->set (sap, selector);
}


ACE_ATM_Addr::ACE_ATM_Addr (const ACE_TCHAR sap[],
                            u_char selector)
#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  : ACE_Addr (AF_ATM,
#elif defined (ACE_HAS_LINUX_ATM)
  : ACE_Addr (PF_ATMSVC,
#else
  : ACE_Addr (AF_UNSPEC,
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
              sizeof this->atm_addr_)
{
  ACE_TRACE ("ACE_ATM_Addr::ACE_ATM_Addr");
  this->set (sap, selector);
}

ACE_ATM_Addr::~ACE_ATM_Addr (void)
{
}

// Return the address.

void *
ACE_ATM_Addr::get_addr (void) const
{
  ACE_TRACE ("ACE_ATM_Addr::get_addr");
  return (void *) &this->atm_addr_;
}

void
ACE_ATM_Addr::init (u_char selector)
{
#if defined (ACE_HAS_FORE_ATM_XTI)
  // Note: this approach may be FORE implementation-specific.  When we
  // bind with tag_addr ABSENT and tag_selector PRESENT, only the
  // selector (i.e. address[19]) is used by the TP.  The rest of the
  // local address is filled in by the TP and can be obtained via the
  // 'ret' parameter or with t_getname ()/t_getprotaddr ().

  atm_addr_.addressType = (u_int16_t) AF_ATM;

  atm_addr_.sap.t_atm_sap_addr.SVE_tag_addr = (int8_t) T_ATM_ABSENT;
  atm_addr_.sap.t_atm_sap_addr.SVE_tag_selector = (int8_t) T_ATM_PRESENT;

  atm_addr_.sap.t_atm_sap_addr.address_format = (u_int8_t) T_ATM_ENDSYS_ADDR;
  atm_addr_.sap.t_atm_sap_addr.address_length = ATMNSAP_ADDR_LEN;
  atm_addr_.sap.t_atm_sap_addr.address[ATMNSAP_ADDR_LEN - 1] = selector;

  atm_addr_.sap.t_atm_sap_layer2.SVE_tag = (int8_t) T_ATM_ABSENT;
  atm_addr_.sap.t_atm_sap_layer3.SVE_tag = (int8_t) T_ATM_ABSENT;

  atm_addr_.sap.t_atm_sap_appl.SVE_tag = (int8_t) T_ATM_PRESENT;
  atm_addr_.sap.t_atm_sap_appl.ID_type = (u_int8_t) T_ATM_USER_APP_ID;

  ACE_OS::memcpy (atm_addr_.sap.t_atm_sap_appl.ID.user_defined_ID,
                  BHLI_MAGIC,
                  sizeof atm_addr_.sap.t_atm_sap_appl.ID);
#elif defined (ACE_HAS_FORE_ATM_WS2)
  ACE_OS::memset ((void *)&atm_addr_, 0, sizeof atm_addr_);
  atm_addr_.satm_number.Addr[ ATM_ADDR_SIZE - 1 ] = (char)selector;
  atm_addr_.satm_family = AF_ATM;
  atm_addr_.satm_number.AddressType = ATM_NSAP;
  atm_addr_.satm_number.NumofDigits = ATM_ADDR_SIZE;
  atm_addr_.satm_blli.Layer2Protocol = SAP_FIELD_ABSENT;
  atm_addr_.satm_blli.Layer3Protocol = SAP_FIELD_ABSENT;
  atm_addr_.satm_bhli.HighLayerInfoType = SAP_FIELD_ABSENT;

  // Need to know the correspondence.
  //atm_addr_.sap.t_atm_sap_appl.SVE_tag = (int8_t) T_ATM_PRESENT;
  //atm_addr_.sap.t_atm_sap_appl.ID_type = (u_int8_t) T_ATM_USER_APP_ID;
  //ACE_OS::memcpy (atm_addr_.sap.t_atm_sap_appl.ID.user_defined_ID,
  //                BHLI_MAGIC,
  //                sizeof atm_addr_.sap.t_atm_sap_appl.ID);
#elif defined (ACE_HAS_LINUX_ATM)
  atm_addr_.sockaddratmsvc.sas_family = AF_ATMSVC;
  atm_addr_.sockaddratmsvc.sas_addr.prv[ATM_ESA_LEN - 1] = (char)selector;
  atm_addr_.atmsap.blli[0].l3_proto = ATM_L3_NONE;
  atm_addr_.atmsap.blli[0].l2_proto = ATM_L2_NONE;
  atm_addr_.atmsap.bhli.hl_type = ATM_HL_NONE;
#else
  ACE_UNUSED_ARG (selector);
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
}

int
ACE_ATM_Addr::set (const ACE_ATM_Addr &sap,
                   u_char selector)
{
  ACE_TRACE ("ACE_ATM_Addr::set");

  this->init (selector);

  this->ACE_Addr::base_set (sap.get_type (),
                            sap.get_size ());

#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  ACE_ASSERT (sap.get_type () == AF_ATM);
#elif defined (ACE_HAS_LINUX_ATM)
  ACE_ASSERT (sap.get_type () == PF_ATMSVC);
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 */

 (void) ACE_OS::memcpy ((void *) &this->atm_addr_,
 (void *) &sap.atm_addr_,
                         sizeof this->atm_addr_);
  return 0;
}

int
ACE_ATM_Addr::set (const ATM_Addr *sap,
                   u_char selector)
{
  ACE_TRACE ("ACE_ATM_Addr::set");

  this->init (selector);

#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  this->ACE_Addr::base_set (AF_ATM,
#elif defined (ACE_HAS_LINUX_ATM)
  this->ACE_Addr::base_set (PF_ATMSVC,
#else
  this->ACE_Addr::base_set (AF_UNSPEC,
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 */
                            sizeof (*sap));

 (void) ACE_OS::memcpy ((void *) &this->atm_addr_,
 (void *) sap,
                         sizeof this->atm_addr_);
  return 0;
}

int
ACE_ATM_Addr::set (const ACE_TCHAR address[],
                   u_char selector)
{
  ACE_TRACE ("ACE_ATM_Addr::set");
  int ret;

  this->init (selector);

#if defined (ACE_HAS_FORE_ATM_XTI)
  atm_addr_.sap.t_atm_sap_addr.SVE_tag_addr =
 (int8_t) T_ATM_PRESENT;
#endif /* ACE_HAS_FORE_ATM_XTI */

  ret = this -> string_to_addr (address);
  this -> set_selector (selector);
  return ret;
}

// Transform the string into the current addressing format.

int
ACE_ATM_Addr::string_to_addr (const ACE_TCHAR sap[])
{
  ACE_TRACE ("ACE_ATM_Addr::string_to_addr");

#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  this->ACE_Addr::base_set (AF_ATM,
#elif defined (ACE_HAS_LINUX_ATM)
  this->ACE_Addr::base_set (PF_ATMSVC,
#else
  this->ACE_Addr::base_set (AF_UNSPEC,
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
                            sizeof this->atm_addr_);
#if defined (ACE_HAS_FORE_ATM_XTI)
  struct hostent *entry;
  struct atmnsap_addr *nsap;

  // Yow, someone gave us a NULL ATM address!
  if (sap == 0)
    {
      errno = EINVAL;
      return -1;
    }
  else if ((entry = gethostbyname_atmnsap ((ACE_TCHAR *)sap)) != 0)
    {
      ACE_OS::memcpy (atm_addr_.sap.t_atm_sap_addr.address,
                      entry->h_addr_list[0],
                      ATMNSAP_ADDR_LEN - 1);
    }
  else if ((nsap = atmnsap_addr (sap)) != 0)
    {
      ACE_OS::memcpy (atm_addr_.sap.t_atm_sap_addr.address,
                      nsap->atmnsap,
                      ATMNSAP_ADDR_LEN);
    }
  else {
      errno = EINVAL;
      return -1;
    }
#elif defined (ACE_HAS_FORE_ATM_WS2)
   DWORD dwValue;
   HANDLE hLookup;
   WSAQUERYSETW qsRestrictions;
   CSADDR_INFO  csaBuffer;
   WCHAR  tmpWStr[100];

   MultiByteToWideChar (CP_ACP, MB_PRECOMPOSED, sap, -1, tmpWStr, 100);

   csaBuffer.LocalAddr.iSockaddrLength = sizeof (struct sockaddr_atm);
   csaBuffer.LocalAddr.lpSockaddr = (struct sockaddr *)&atm_addr_;
   csaBuffer.RemoteAddr.iSockaddrLength = sizeof (struct sockaddr_atm);
   csaBuffer.RemoteAddr.lpSockaddr = (struct sockaddr *)&atm_addr_;

   qsRestrictions.dwSize                  = sizeof (WSAQUERYSETW);
   qsRestrictions.lpszServiceInstanceName = 0;
   qsRestrictions.lpServiceClassId        = &FORE_NAME_CLASS;
   qsRestrictions.lpVersion               = 0;
   qsRestrictions.lpszComment             = 0;
   qsRestrictions.dwNameSpace             = FORE_NAME_SPACE;
   qsRestrictions.lpNSProviderId          = 0;
   qsRestrictions.lpszContext             = L"";
   qsRestrictions.dwNumberOfProtocols     = 0;
   qsRestrictions.lpafpProtocols          = 0;
   qsRestrictions.lpszQueryString         = tmpWStr;
   qsRestrictions.dwNumberOfCsAddrs       = 1;
   qsRestrictions.lpcsaBuffer             = &csaBuffer;
   qsRestrictions.lpBlob                  = 0; //&blob;

   if (::WSALookupServiceBeginW (&qsRestrictions, LUP_RETURN_ALL, &hLookup)
        == SOCKET_ERROR) {
     ACE_OS::printf ("Error: WSALookupServiceBeginW failed! %d\n",
                     ::WSAGetLastError ());
           return -1;
   }

   dwValue = sizeof (WSAQUERYSETW);

   if (::WSALookupServiceNextW (hLookup, 0, &dwValue, &qsRestrictions)
        == SOCKET_ERROR) {
     if (WSAGetLastError () != WSA_E_NO_MORE) {
       ACE_OS::printf ("Error: WSALookupServiceNextW failed! %d\n",
                       ::WSAGetLastError ());
             return -1;
     }
   }

   if (WSALookupServiceEnd (hLookup) == SOCKET_ERROR) {
     ACE_OS::printf ("Error : WSALookupServiceEnd failed! %d\n",
                     ::WSAGetLastError ());
      errno = EINVAL;
      return -1;
   }
#elif defined (ACE_HAS_LINUX_ATM)
   if (sap == 0 || !ACE_OS::strcmp (sap,"")) {
     errno = EINVAL;
     return -1;
   }

   if (text2atm ((ACE_TCHAR *)sap,
 (struct sockaddr *)& (atm_addr_.sockaddratmsvc),
                 sizeof (atm_addr_.sockaddratmsvc),
                 T2A_SVC | T2A_NAME) < 0) {
     ACE_DEBUG (LM_DEBUG,
               "Error : text2atm failed!\n");
     errno = EINVAL;
     return -1;
   }
#else
  ACE_UNUSED_ARG (sap);

  return 0;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */

#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2) || defined (ACE_HAS_LINUX_ATM)
  return 0;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 */
}

// Transform the current address into string format.

int
ACE_ATM_Addr::addr_to_string (ACE_TCHAR addr[],
                              size_t addrlen) const
{
  ACE_TRACE ("ACE_ATM_Addr::addr_to_string");

#if defined (ACE_HAS_FORE_ATM_XTI)
  ACE_TCHAR buffer[MAXNAMELEN + 1];
  struct atmnsap_addr nsap;
  ACE_OS::memcpy (nsap.atmnsap,
                  atm_addr_.sap.t_atm_sap_addr.address,
                  ATMNSAP_ADDR_LEN);
  ACE_OS::sprintf (buffer,
                   ACE_TEXT ("%s"),
                   atmnsap_ntoa (nsap));

  size_t total_len = ACE_OS::strlen (buffer) + sizeof ('\0');

  if (addrlen < total_len)
    return -1;
  else
    ACE_OS::strcpy (addr, buffer);

  return 0;
#elif defined (ACE_HAS_FORE_ATM_WS2)
  ACE_TCHAR buffer[MAXNAMELEN + 1];
  int i;

  if (addrlen < ATM_ADDR_SIZE + 1)
          return -1;

  for (i = 0; i < ATM_ADDR_SIZE; i++) {
    buffer[ i * 3 ] = '\0';
          ACE_OS::sprintf (buffer, ACE_TEXT ("%s%02x."),
                     buffer,
                     atm_addr_.satm_number.Addr[ i ]);
  }

  buffer[ ATM_ADDR_SIZE * 3 - 1 ] = '\0';
  ACE_OS::strcpy (addr, buffer);

  return 0;
#elif defined (ACE_HAS_LINUX_ATM)
  ACE_TCHAR buffer[MAX_ATM_ADDR_LEN + 1];
  int total_len;
  if ((total_len = atm2text (buffer,
                            sizeof buffer,
 (struct sockaddr *)& (atm_addr_.sockaddratmsvc),
                            A2T_PRETTY)) < 0) {
    ACE_DEBUG ((LM_DEBUG,"ACE_ATM_Addr (addr_to_string): atm2text failed\n"));
    return -1;
  }
  if (addrlen < (size_t)total_len)
    return -1;
  else
    ACE_OS::strcpy (addr,
                   buffer);

  return 0;
#else
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (addrlen);
  return -1;
#endif /* ACE_HAS_FORE_ATM_XTI && ACE_HAS_FORE_ATM_WS2 */
}

const ACE_TCHAR *
ACE_ATM_Addr::addr_to_string (void) const
{
  ACE_TRACE ("ACE_ATM_Addr::addr_to_string");

  static ACE_TCHAR addr[MAXHOSTNAMELEN + 1];
  if (this->addr_to_string (addr,
                            MAXHOSTNAMELEN + 1) < 0)
    return 0;

  return addr;
}

// Set a pointer to the address.
void
ACE_ATM_Addr::set_addr (void *addr, int len)
{
  ACE_TRACE ("ACE_ATM_Addr::set_addr");

#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
  this->ACE_Addr::base_set (AF_ATM,
#elif defined (ACE_HAS_LINUX_ATM)
  this->ACE_Addr::base_set (PF_ATMSVC,
#else
  this->ACE_Addr::base_set (AF_UNSPEC,
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_WS2 */
                            len);
  ACE_OS::memcpy ((void *) &this->atm_addr_,
 (void *) addr, len);
}

// Compare two addresses for inequality.

bool
ACE_ATM_Addr::operator != (const ACE_ATM_Addr &sap) const
{
  ACE_TRACE ("ACE_ATM_Addr::operator !=");
  return ! ((*this) == sap);
}

// Compare two addresses for equality.

bool
ACE_ATM_Addr::operator == (const ACE_ATM_Addr &sap) const
{
  ACE_TRACE ("ACE_ATM_Addr::operator ==");

#if defined (ACE_HAS_LINUX_ATM)
  return (atm_equal ((const struct sockaddr *)& (this->atm_addr_.sockaddratmsvc),
 (const struct sockaddr *)& (sap.atm_addr_.sockaddratmsvc),
                    0,
                    0)
          &&
          sap_equal (& (this->atm_addr_.atmsap),
                    & (sap.atm_addr_.atmsap),
                    0));
#else
  return ACE_OS::memcmp (&atm_addr_,
                         &sap.atm_addr_,
                         sizeof (ATM_Addr)) == 0;
#endif /*  ACE_HAS_LINUX_ATM */
}

void
ACE_ATM_Addr::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_ATM_Addr::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_TCHAR s[ACE_MAX_FULLY_QUALIFIED_NAME_LEN + 16];
  ACE_OS::sprintf (s,
                   ACE_TEXT ("%s"),
                   this->addr_to_string ());
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("%s"), s));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_ATM */
