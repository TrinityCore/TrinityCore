// -*- C++ -*-

//==========================================================================
/**
 *  @file    ATM_Addr.h
 *
 *  $Id: ATM_Addr.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Joe Hoffert <joeh@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_ATM_ADDR_H
#define ACE_ATM_ADDR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_ATM)

#include /**/ "ace/ACE_export.h"
#include "ace/Addr.h"

#if defined (ACE_HAS_FORE_ATM_XTI)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef ATMSAPAddress ATM_Addr;
ACE_END_VERSIONED_NAMESPACE_DECL
#elif defined (ACE_HAS_FORE_ATM_WS2)
#define FORE_NAME_SPACE NS_ALL
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
typedef struct sockaddr_atm ATM_Addr;
ACE_END_VERSIONED_NAMESPACE_DECL
#elif defined (ACE_HAS_LINUX_ATM)

#include /**/ "atm.h"

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

//pbrandao:as Linux has this 2 structs separeted we "link it" here
typedef struct _linux_atm_addr
{
  struct sockaddr_atmsvc sockaddratmsvc;
  struct atm_sap atmsap;
} ATM_Addr;
#else
typedef int ATM_Addr;
#endif /* ACE_HAS_FORE_ATM_XTI/ACE_HAS_FORE_ATM_WS2/ACE_HAS_LINUX_ATM */

/**
 * @class ACE_ATM_Addr
 *
 * @brief Defines the ATM domain address family address format.
 */
class ACE_Export ACE_ATM_Addr : public ACE_Addr
{
public:
  // Constants used for ATM options
  static const long LINE_RATE;
  static const int OPT_FLAGS_CPID;
  static const int OPT_FLAGS_PMP;
  static const int DEFAULT_SELECTOR;

  // = Initialization methods.
  /// Default constructor.
  ACE_ATM_Addr (u_char selector = DEFAULT_SELECTOR);

  /// Copy constructor.
  ACE_ATM_Addr (const ACE_ATM_Addr &,
                u_char selector = DEFAULT_SELECTOR);

  /**
   * Creates an ACE_ATM_Addr from an ATMSAPAddress structure. This
   * is vendor specific (FORE systems). May need to change when other
   * vendors are supported.
   */
  ACE_ATM_Addr (const ATM_Addr *,
                u_char selector = DEFAULT_SELECTOR);

  /**
   * Initializes an ACE_ATM_Addr from the <sap> which can be
   * "atm-address" (e.g.,
   * "47.0005.80.ffe100.0000.f20f.2200.0020480694f9.00") or "hostname"
   * (e.g., "frisbee.cs.wustl.edu").
   */
  ACE_ATM_Addr (const ACE_TCHAR sap[],
                u_char selector = DEFAULT_SELECTOR);

  /// Default dtor.
  ~ACE_ATM_Addr (void);

  // = Initialization methods (useful after object construction).
  /// Default initialization for non-address values (e.g.,
  /// t_atm_sap_addr.SVE_tag_addr, t_atm_sap_addr.SVE_tag_selector)
  void init (u_char selector = DEFAULT_SELECTOR);

  /// Initializes from another ACE_ATM_Addr.
  int set (const ACE_ATM_Addr &,
           u_char selector = DEFAULT_SELECTOR);

  /**
   * Initializes an ACE_ATM_Addr from an ATMSAPAddress/sockaddr_atm
   * structure. This is vendor specific (FORE systems). May need to
   * change when other vendors are supported.
   */
  int set (const ATM_Addr *,
           u_char selector = DEFAULT_SELECTOR);

  /**
   * Initializes an ACE_ATM_Addr from the <sap> which can be
   * "atm-address" (e.g.,
   * "47.0005.80.ffe100.0000.f20f.2200.0020480694f9.00") or "hostname"
   * (e.g., "frisbee.cs.wustl.edu").
   */
  int set (const ACE_TCHAR sap[],
           u_char selector = DEFAULT_SELECTOR);

  /**
   * Initializes an ACE_ATM_Addr from the <sap> which can be
   * "atm-address" (e.g.,
   * "47.0005.80.ffe100.0000.f20f.2200.0020480694f9.00") or "hostname"
   * (e.g., "frisbee.cs.wustl.edu").
   */
  virtual int string_to_addr (const ACE_TCHAR sap[]);

  /**
   * Return the character representation of the ATM address (e.g.,
   * "47.0005.80.ffe100.0000.f20f.2200.0020480694f9.00") storing it in
   * the @a addr (which is assumed to be <addrlen> bytes long). This
   * version is reentrant.  Returns -1 if the <addrlen> of the @a addr
   * is too small, else 0.
   */
  virtual int addr_to_string (ACE_TCHAR addr[],
                              size_t addrlen) const;

  /**
   * Return the character representation of the ATM address (e.g.,
   * "47.0005.80.ffe100.0000.f20f.2200.0020480694f9.00"). Returns -1
   * if the <size> of the <buffer> is too small, else 0.(This version
   * is non-reentrant since it returns a pointer to a static data
   * area.)
   */
  const ACE_TCHAR *addr_to_string (void) const;

  /// Return a pointer to the underlying network address.
  virtual void *get_addr (void) const;

  /// Set a pointer to the address.
  virtual void set_addr (void *, int);

  /// Return the selector for network address.
  u_char get_selector (void) const;

  /// Set the selector for the network address.
  void set_selector (u_char selector);

  /**
   * Compare two addresses for equality.  The addresses are considered
   * equal if they contain the same ATM address.  Q: Is there any
   * other check for equality needed for ATM?
   */
  bool operator == (const ACE_ATM_Addr &SAP) const;

  /// Compare two addresses for inequality.
  bool operator != (const ACE_ATM_Addr &SAP) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

//   char *construct_options (ACE_HANDLE fd,
//                            int qos_kb,
//                            int flags,
//                            long *optsize);
//   // Construct options for ATM connections

private:
  ATM_Addr atm_addr_;
};

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "ace/ATM_Addr.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_ATM */
#include /**/ "ace/post.h"
#endif /* ACE_ATM_ADDR_H */
