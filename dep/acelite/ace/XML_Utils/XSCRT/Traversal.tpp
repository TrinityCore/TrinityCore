// file      : XSCRT/Traversal.tpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: Traversal.tpp 95833 2012-06-06 14:53:45Z johnnyw $

namespace XSCRT
{
  namespace Traversal
  {
    // TraverserBase
    //
    //

    template<typename B>
    TraverserBase<B>::
    ~TraverserBase ()
    {
    }

    // DispatcherBase
    //
    //

    template <typename B>
    DispatcherBase<B>::
    ~DispatcherBase ()
    {
    }

    //@@ merge after dropping VC6
    //
    //
    template <typename B>
    void DispatcherBase<B>::
    dispatch (B& n)
    {
      LevelMap levels;

      //@@ VC6
      ExtendedTypeInfo const& ti = extended_type_info (n);

      unsigned long max = compute_levels (ti, 0, levels);


      //wcerr << "starting dispatch process for "
      //      << typeid (n).name () << " with "
      //      << max << " levels" << endl;

      for (unsigned long l = 0; l < max + 1; ++l)
      {
        TypeInfoSet dispatched;

        for (typename LevelMap::const_iterator
               i (levels.begin ()), e (levels.end ());
             i != e; ++i)
        {
          if (i->second == l)
          {
            typename TraversalMap::const_iterator v (
              traversal_map_.find (i->first.type_id ()));

            if (v != traversal_map_.end ())
            {
              //wcerr << "dispatching traversers for "
              //      << typeid (n).name () << " as "
              //      << i->first.type_id ().name () << endl;

              //@@ VC6
              Traversers const& traversers  = v->second;
              for (typename Traversers::const_iterator
                     ti (traversers.begin ()), te (traversers.end ());
                   ti != te; ++ti)
              {
                (*ti)->trampoline (n);
              }

              flatten_tree (i->first, dispatched);
            }
          }
        }

        // Remove traversed types from the level map.
        //
    //@@ VC6
        {
          for (typename TypeInfoSet::const_iterator i = dispatched.begin ();
               i != dispatched.end ();
               ++i)
          {
            levels.erase (*i);
          }
    }
      }
    }

    template <typename B>
    void DispatcherBase<B>::
    dispatch (B const& n)
    {
      LevelMap levels;

      //@@ VC6
      ExtendedTypeInfo const& ti = extended_type_info (n);

      unsigned long max = compute_levels (ti, 0, levels);


      //wcerr << "starting dispatch process for "
      //      << typeid (n).name () << " with "
      //      << max << " levels" << endl;

      //wcerr << "using " << &traversal_map_ << " traversal map" << endl;

      for (unsigned long l = 0; l < max + 1; ++l)
      {
        TypeInfoSet dispatched;

        for (typename LevelMap::const_iterator
               i (levels.begin ()), e (levels.end ());
             i != e; ++i)
        {
          if (i->second == l)
          {
            typename TraversalMap::const_iterator v (
              traversal_map_.find (i->first.type_id ()));

            if (v != traversal_map_.end ())
            {
              //wcerr << "dispatching traversers for "
              //      << typeid (n).name () << " as "
              //      << i->first.type_id ().name () << endl;

              //@@ VC6
              Traversers const& traversers  = v->second;
              for (typename Traversers::const_iterator
                     ti (traversers.begin ()), te (traversers.end ());
                   ti != te; ++ti)
              {
                (*ti)->trampoline (n);
              }

              flatten_tree (i->first, dispatched);
            }
          }
        }

        // Remove traversed types from the level map.
        //
    //@@ VC6
        {
          for (typename TypeInfoSet::const_iterator i = dispatched.begin ();
               i != dispatched.end ();
               ++i)
          {
            levels.erase (*i);
          }
    }
      }
    }

    template <typename B>
    unsigned long DispatcherBase<B>::
    compute_levels (ExtendedTypeInfo const& ti,
                    unsigned long cur,
                    LevelMap& map)
    {
      unsigned long ret = cur;

      if (map.find (ti) == map.end () || map[ti] < cur) map[ti] = cur;

      for (ExtendedTypeInfo::BaseIterator i = ti.begin_base ();
           i != ti.end_base ();
           i++)
      {
        unsigned long t = compute_levels (i->type_info (), cur + 1, map);
        if (t > ret) ret = t;
      }

      return ret;
    }

    template <typename B>
    void DispatcherBase<B>::
    flatten_tree (ExtendedTypeInfo const& ti, TypeInfoSet& set)
    {
      set.insert (ti);

      for (ExtendedTypeInfo::BaseIterator i = ti.begin_base ();
           i != ti.end_base ();
           i++)
      {
        flatten_tree (i->type_info (), set);
      }
    }
  }
}
