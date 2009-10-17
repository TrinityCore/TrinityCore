/* -*- C++ -*- */
//=============================================================================
/**
 *  @file     Memory_Pool.h
 *
 *  $Id: Memory_Pool.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Dougls C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Prashant Jain <pjain@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_MEMORY_POOL_H
#define ACE_MEMORY_POOL_H
#include /**/ "ace/pre.h"
#include "ace/ACE.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Local_Memory_Pool.h"
#include "ace/MMAP_Memory_Pool.h"
#include "ace/Sbrk_Memory_Pool.h"
#include "ace/Shared_Memory_Pool.h"
#include "ace/Pagefile_Memory_Pool.h"
#include /**/ "ace/post.h"
#endif /* ACE_MEMORY_POOL_H */

