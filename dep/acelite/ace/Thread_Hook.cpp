// $Id: Thread_Hook.cpp 94054 2011-05-11 18:28:20Z johnnyw $

#include "ace/Thread_Hook.h"
#include "ace/Object_Manager_Base.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Thread_Hook::~ACE_Thread_Hook ()
{
}

ACE_THR_FUNC_RETURN
ACE_Thread_Hook::start (ACE_THR_FUNC func, void *arg)
{
  return (func) (arg);
}

ACE_Thread_Hook *
ACE_Thread_Hook::thread_hook (ACE_Thread_Hook *hook)
{
  return ACE_OS_Object_Manager::thread_hook (hook);
}

ACE_Thread_Hook *
ACE_Thread_Hook::thread_hook (void)
{
  return ACE_OS_Object_Manager::thread_hook ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
