// $Id: Monitor_Base.inl 82328 2008-07-15 17:20:17Z parsons $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE
{
  namespace Monitor_Control
  {
    ACE_INLINE
    const char*
    Monitor_Base::name (void) const
    {
      return this->name_.c_str ();
    }
    ACE_INLINE
    void
    Monitor_Base::name (const char* new_name)
    {
      this->name_ = new_name;
    }
    ACE_INLINE
    Monitor_Base::CONSTRAINTS&
    Monitor_Base::constraints (void)
    {
      return this->constraints_;
    }
    ACE_INLINE
    void
    Monitor_Base::add_ref (void)
    {
      (void) this->increment ();
    }
    ACE_INLINE
    void
    Monitor_Base::remove_ref (void)
    {
      long const new_count = this->decrement ();
      if (new_count == 0)
        {
          delete this;
        }
    }
    ACE_INLINE
    Monitor_Control_Types::Information_Type
    Monitor_Base::type (void) const
    {
      return this->data_.type_;
    }
  }
}
ACE_END_VERSIONED_NAMESPACE_DECL

