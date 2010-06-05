// -*- C++ -*-
//
// $Id: Asynch_IO_Impl.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Asynch_Result_Impl::ACE_Asynch_Result_Impl (void)
{
}

ACE_INLINE
ACE_Asynch_Operation_Impl::ACE_Asynch_Operation_Impl (void)
{
}

ACE_INLINE
ACE_Asynch_Read_Stream_Impl::ACE_Asynch_Read_Stream_Impl (void)
  : ACE_Asynch_Operation_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Read_Stream_Result_Impl::ACE_Asynch_Read_Stream_Result_Impl (void)
  : ACE_Asynch_Result_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Write_Stream_Impl::ACE_Asynch_Write_Stream_Impl (void)
  : ACE_Asynch_Operation_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Write_Stream_Result_Impl::ACE_Asynch_Write_Stream_Result_Impl (void)
  : ACE_Asynch_Result_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Read_File_Impl::ACE_Asynch_Read_File_Impl (void)
  : ACE_Asynch_Operation_Impl (),
    ACE_Asynch_Read_Stream_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Read_File_Result_Impl::ACE_Asynch_Read_File_Result_Impl (void)
  : ACE_Asynch_Result_Impl (),
    ACE_Asynch_Read_Stream_Result_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Write_File_Impl::ACE_Asynch_Write_File_Impl (void)
  : ACE_Asynch_Operation_Impl (),
    ACE_Asynch_Write_Stream_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Write_File_Result_Impl::ACE_Asynch_Write_File_Result_Impl (void)
  : ACE_Asynch_Result_Impl (),
    ACE_Asynch_Write_Stream_Result_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Accept_Impl::ACE_Asynch_Accept_Impl (void)
  : ACE_Asynch_Operation_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Accept_Result_Impl::ACE_Asynch_Accept_Result_Impl (void)
  : ACE_Asynch_Result_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Connect_Impl::ACE_Asynch_Connect_Impl (void)
  : ACE_Asynch_Operation_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Connect_Result_Impl::ACE_Asynch_Connect_Result_Impl (void)
  : ACE_Asynch_Result_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Transmit_File_Impl::ACE_Asynch_Transmit_File_Impl (void)
  : ACE_Asynch_Operation_Impl ()
{
}

ACE_INLINE
ACE_Asynch_Transmit_File_Result_Impl::ACE_Asynch_Transmit_File_Result_Impl (void)
  : ACE_Asynch_Result_Impl ()
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
