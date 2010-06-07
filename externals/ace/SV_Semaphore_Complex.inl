// -*- C++ -*-
//
// $Id: SV_Semaphore_Complex.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_SV_Semaphore_Complex::acquire (u_short n, short flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::acquire");
  return ACE_SV_Semaphore_Simple::acquire ((u_short) n + 2, flags);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::acquire_read (u_short n, short flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::acquire_read");
  return this->acquire (n, flags);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::acquire_write (u_short n, short flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::acquire_write");
  return this->acquire (n, flags);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::tryacquire (u_short n, short flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::tryacquire");
  return ACE_SV_Semaphore_Simple::tryacquire ((u_short) n + 2, flags);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::tryacquire_read (u_short n, short flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::tryacquire_read");
  return this->tryacquire (n, flags);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::tryacquire_write (u_short n, short flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::tryacquire_write");
  return this->tryacquire (n, flags);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::release (u_short n, short flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::release");
  return ACE_SV_Semaphore_Simple::release ((u_short) n + 2, flags);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::op (short val, u_short n, short flags) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::op");
  return ACE_SV_Semaphore_Simple::op (val, (u_short) n + 2, flags);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::op (sembuf op_vec[], u_short n) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::op");
  return ACE_SV_Semaphore_Simple::op (op_vec, (u_short) n + 2);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::control (int cmd, semun arg, u_short n) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::control");
  return ACE_SV_Semaphore_Simple::control (cmd, arg, (u_short) n + 2);
}

ACE_INLINE int
ACE_SV_Semaphore_Complex::control (int cmd, int value, u_short n) const
{
  ACE_TRACE ("ACE_SV_Semaphore_Complex::control");
  return ACE_SV_Semaphore_Simple::control (cmd, value, (u_short) n + 2);
}

ACE_END_VERSIONED_NAMESPACE_DECL
