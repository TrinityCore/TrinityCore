// -*- C++ -*-
//
// $Id: Profile_Timer.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_sys_resource.h"
#include "ace/Global_Macros.h"

#if (defined (ACE_HAS_PRUSAGE_T) || defined (ACE_HAS_GETRUSAGE)) && !defined (ACE_WIN32)

#  if defined (ACE_HAS_PRUSAGE_T)
#    include "ace/OS_NS_stropts.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_Profile_Timer::start (void)
{
  ACE_TRACE ("ACE_Profile_Timer::start");
  return ACE_OS::ioctl (this->proc_handle_,
                        PIOCUSAGE,
                        &this->begin_usage_);
}

ACE_INLINE int
ACE_Profile_Timer::stop (void)
{
  ACE_TRACE ("ACE_Profile_Timer::stop");
  this->last_usage_ = this->end_usage_;
  return ACE_OS::ioctl (this->proc_handle_,
                    PIOCUSAGE,
                    &this->end_usage_);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#  elif defined (ACE_HAS_GETRUSAGE)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_Profile_Timer::start (void)
{
  ACE_TRACE ("ACE_Profile_Timer::start");
  this->begin_time_ = ACE_OS::gettimeofday ();
  ACE_OS::getrusage (RUSAGE_SELF,
                     &this->begin_usage_);
  return 0;
}

ACE_INLINE int
ACE_Profile_Timer::stop (void)
{
  ACE_TRACE ("ACE_Profile_Timer::stop");
  this->last_time_ = this->end_time_;
  this->end_time_ = ACE_OS::gettimeofday ();
  this->last_usage_ = this->end_usage_;
  ACE_OS::getrusage (RUSAGE_SELF,
                     &this->end_usage_);
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#  endif /* ACE_HAS_PRUSAGE_T */

#elif defined (ACE_WIN32)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Profile_Timer::~ACE_Profile_Timer (void)
{
}

ACE_INLINE int
ACE_Profile_Timer::start (void)
{
  ACE_TRACE ("ACE_Profile_Timer::start");
#  if defined (ACE_HAS_GETRUSAGE)
  ACE_OS::getrusage (RUSAGE_SELF,
                     &this->begin_usage_);
#  endif /* ACE_HAS_GETRUSAGE */
  this->timer_.start ();
  return 0;
}

ACE_INLINE int
ACE_Profile_Timer::stop (void)
{
  ACE_TRACE ("ACE_Profile_Timer::stop");
  this->timer_.stop ();
#  if defined (ACE_HAS_GETRUSAGE)
  this->last_usage_ = this->end_usage_;
  ACE_OS::getrusage (RUSAGE_SELF, &this->end_usage_);
#  endif /* ACE_HAS_GETRUSAGE */
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#else

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_Profile_Timer::start (void)
{
  ACE_TRACE ("ACE_Profile_Timer::start");
  this->timer_.start ();
  return 0;
}

ACE_INLINE int
ACE_Profile_Timer::stop (void)
{
  ACE_TRACE ("ACE_Profile_Timer::stop");
  this->timer_.stop ();
  return 0;
}

ACE_INLINE
ACE_Profile_Timer::~ACE_Profile_Timer (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (ACE_HAS_PRUSAGE_T) || defined (ACE_HAS_GETRUSAGE) */
