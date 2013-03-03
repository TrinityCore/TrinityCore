// $Id: XercesString.cpp 95760 2012-05-15 13:46:19Z msmit $

#include <ostream>
#include <algorithm>

#include "XercesString.h"
#include "xercesc/util/PlatformUtils.hpp"

using xercesc::XMLString;
using xercesc::XMLPlatformUtils;

namespace XML
{
// On unicode windows, ACE_TCHAR == XMLCh
#if !defined (_MSC_VER) || !defined (ACE_USES_WCHAR)
  XStr::XStr (const ACE_TCHAR* str)
    : _wstr(0)
  {
    _wstr = XMLString::transcode(ACE_TEXT_ALWAYS_CHAR (str));
  }
#endif

  XStr::XStr (XMLCh *wstr)
    : _wstr(wstr)
  {

  }

  XStr::XStr (const XMLCh* wstr)
    : _wstr(0)
  {
    _wstr = XMLString::replicate(wstr);
  }

  XStr::XStr (const XStr &right)
    : _wstr(0)
  {
    _wstr = XMLString::replicate(right._wstr);
  }

  XStr& XStr::operator= (const XStr& rhs)
  {
    if (&rhs == this)
      return *this;
    XStr temp (rhs);
    std::swap (this->_wstr, temp._wstr);
    return *this;
  }

  XStr::~XStr ()
  {
    this->reset ();
  }

  const XMLCh* XStr::begin () const
  {
    return _wstr;
  }

  const XMLCh* XStr::end () const
  {
    return _wstr + size();
  }

  bool XStr::append(const XMLCh *tail)
  {
    int iTailLen = XMLString::stringLen(tail);
    int iWorkLen = XMLString::stringLen(_wstr);

    XMLSize_t bytes = (iWorkLen + iTailLen + 1) * sizeof (XMLCh);
    void *tmp = XMLPlatformUtils::fgMemoryManager->allocate (bytes);
    XMLCh *result = reinterpret_cast<XMLCh *> (tmp);

    bool bOK = result != 0;
    if (bOK)
      {
        XMLCh *target = result;
        XMLString::moveChars(target, _wstr, iWorkLen);
        target += iWorkLen;
        XMLString::moveChars(target, tail, iTailLen);
        target += iTailLen;
        *target++ = 0;
        XMLString::release(&_wstr);
        _wstr = result;
      }
    return bOK;
  }

  bool XStr::erase(const XMLCh *head, const XMLCh *tail)
  {
    bool bOK = head <= tail && head >= begin() && tail <= end();
    if (bOK)
      {
        XMLSize_t bytes = (size() - (tail - head) + 1 ) * sizeof (XMLCh);
        void *tmp = XMLPlatformUtils::fgMemoryManager->allocate (bytes);
        XMLCh *result = reinterpret_cast<XMLCh *> (tmp);

        XMLCh *target = result;
        bOK = target != 0;
        if (bOK)
          {
            const XMLCh *cursor = begin();

            while (cursor != head) *target++ = *cursor++;
            cursor = tail;
            while ( cursor != end() ) *target++ = *cursor++;
            *target ++ = 0;
            XMLString::release(&_wstr);
            _wstr = result;
          }
      }
    return bOK;
  }

  int XStr::size () const
  {
    return XMLString::stringLen(_wstr);
  }

  XMLCh XStr::operator [] (const int i)
  {
    return _wstr[i];
  }

  XMLCh XStr::operator [] (const int i) const
  {
    return _wstr[i];
  }

  XMLCh * XStr::release (void)
  {
    XMLCh* tmp = _wstr;
    this->_wstr = 0;
    return tmp;
  }

  void
  XStr::reset (void)
  {
    if (_wstr)
      XMLString::release(&_wstr);
    _wstr = 0;
  }

  bool operator== (const XStr& lhs, const XStr& rhs)
  {
    return XMLString::compareIString (lhs,rhs) == 0;
  }

  bool operator!= (const XStr& lhs, const XStr& rhs)
  {
    return !operator==(lhs, rhs);
  }


  std::ostream&
  operator<< (std::ostream& o, XStr const& str)
  {
    char* s = XMLString::transcode (str);

    o << s;

    XMLString::release (&s); // idiots?
    return o;
  }

}
