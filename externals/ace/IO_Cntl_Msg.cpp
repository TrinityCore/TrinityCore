// $Id: IO_Cntl_Msg.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/IO_Cntl_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/IO_Cntl_Msg.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, IO_Cntl_Msg, "$Id: IO_Cntl_Msg.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if 0
// This is not meant to be used, it's just a place holder...

#if !defined (__ACE_INLINE__)
#include "ace/Intrusive_List.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decl
template <class SYNCH> class ACE_Module;

/**
 * @class ACE_Module_Link
 *
 * @brief Data structure used to link two modules together
 */
class ACE_Module_Link
{
public:
  ACE_Module_Link (ACE_Module *m1, ACE_Module *m2): mod_upper_ (m1), mod_lower_ (m2), count_ (0) {}

  ACE_Module *upper (void) { return this->mod_upper_; }
  void   upper (ACE_Module *u) { this->mod_upper_ = u; }

  ACE_Module *lower (void) { return this->mod_lower_; }
  void   lower (ACE_Module *l) { this->mod_lower_ = l; }

  int    count (void) const { return this->count_; }
  void   count (int c) { this->count_ = c; }

private:
  ACE_Module *mod_upper_;
  ACE_Module *mod_lower_;
  int    count_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif

