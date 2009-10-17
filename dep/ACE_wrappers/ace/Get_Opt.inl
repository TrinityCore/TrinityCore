// -*- C++ -*-
//
// $Id: Get_Opt.inl 81840 2008-06-05 13:46:45Z sma $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE bool
ACE_Get_Opt::ACE_Get_Opt_Long_Option::operator < (const ACE_Get_Opt_Long_Option &rhs)
{
  return this->name_ < rhs.name_;
}
ACE_INLINE int
ACE_Get_Opt::argc (void) const
{
  return this->argc_;
}
ACE_INLINE ACE_TCHAR **
ACE_Get_Opt::argv (void) const
{
  return this->argv_;
}
ACE_INLINE ACE_TCHAR*
ACE_Get_Opt::opt_arg (void) const
{
  return this->optarg;
}
ACE_INLINE int
ACE_Get_Opt::opt_opt (void)
{
  return this->optopt_;
}
ACE_INLINE int &
ACE_Get_Opt::opt_ind (void)
{
  return this->optind;
}
#ifdef ACE_USES_WCHAR
ACE_INLINE  ACE_Get_Opt::ACE_Get_Opt (int argc,
               ACE_TCHAR **argv,
               const ACE_TCHAR *optstring,
               int skip_args,
               int report_errors,
               int ordering,
               int long_only)
  : argc_ (argc),
    argv_ (argv),
    optind (skip_args),
    opterr (report_errors),
    optarg (0),
    optstring_ (0),
    long_only_ (long_only),
    has_colon_ (0),
    last_option_ (0),
    nextchar_ (0),
    optopt_ (0),
    ordering_ (ordering),
    nonopt_start_ (optind),
    nonopt_end_ (optind),
    long_option_ (0)
{
  ACE_Get_Opt_Init (optstring);
}
ACE_INLINE  ACE_Get_Opt::ACE_Get_Opt (int argc,
               ACE_TCHAR **argv,
               const char *optstring,
               int skip_args,
               int report_errors,
               int ordering,
               int long_only)
  : argc_ (argc),
    argv_ (argv),
    optind (skip_args),
    opterr (report_errors),
    optarg (0),
    optstring_ (),
    long_only_ (long_only),
    has_colon_ (0),
    last_option_ (0),
    nextchar_ (0),
    optopt_ (0),
    ordering_ (ordering),
    nonopt_start_ (optind),
    nonopt_end_ (optind),
    long_option_ (0)
{
  ACE_Get_Opt_Init (ACE_TEXT_CHAR_TO_TCHAR (optstring));
}
#endif
ACE_END_VERSIONED_NAMESPACE_DECL
