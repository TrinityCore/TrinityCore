// file      : XSCRT/Traversal.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: Traversal.hpp 95833 2012-06-06 14:53:45Z johnnyw $

#ifndef XSCRT_TRAVERSAL_HPP
#define XSCRT_TRAVERSAL_HPP

#include <map>
#include <set>
#include <vector>

#include "ace/XML_Utils/XSCRT/ExtendedTypeInfo.hpp"

namespace XSCRT
{
  namespace Traversal
  {
    //
    //
    //
    template<typename B>
    class TraverserBase
    {
    protected:
      virtual
      ~TraverserBase ();

      //@@ VC6
    public:
      virtual void
      trampoline (B& n) = 0;

      virtual void
      trampoline (B const& n) = 0;
    };


    //
    //
    //
    template <typename B>
    class DispatcherBase
    {
    public:
      virtual
      ~DispatcherBase ();

      virtual void
      dispatch (B& n);

      virtual void
      dispatch (B const& n);

      void
      map (TypeId id, TraverserBase<B>& t)
      {
        //wcerr << "map for " << id.name () << " to " << &t
    //      << " in " << &traversal_map_ << endl;

        //@@ VC6
        Traversers& traversers = traversal_map_[id];
        traversers.push_back (&t);
      }

    public:
      typedef
      std::vector<TraverserBase<B>*>
      Traversers;

      typedef
      std::map<TypeId, Traversers>
      TraversalMap;

      typedef
      typename TraversalMap::const_iterator
      Iterator;

      Iterator
      begin () const
      {
        return traversal_map_.begin ();
      }

      Iterator
      end () const
      {
        return traversal_map_.end ();
      }

    private:
      struct TypeInfoComparator
      {
        bool
        operator () (ExtendedTypeInfo const& x,
                     ExtendedTypeInfo const& y) const
        {
          return x.type_id () < y.type_id ();
        }
      };

      typedef
      std::map<ExtendedTypeInfo, unsigned long, TypeInfoComparator>
      LevelMap;

      typedef
      std::set<ExtendedTypeInfo, TypeInfoComparator>
      TypeInfoSet;

      static unsigned long
      compute_levels (ExtendedTypeInfo const& ti,
                      unsigned long cur,
                      LevelMap& map);

      static void
      flatten_tree (ExtendedTypeInfo const& ti, TypeInfoSet& set);

    private:
      TraversalMap traversal_map_;
    };


    //
    //
    //
    template <typename B>
    class Dispatcher : public virtual DispatcherBase<B>
    {
    public:
      Dispatcher ()
          : merge_ (true)
      {
      }

      void
      traverser (DispatcherBase<B>& d)
      {
        for (typename DispatcherBase<B>::Iterator
               i (d.begin ()), end (d.end ());
             i != end; ++i)
        {
          for (typename DispatcherBase<B>::Traversers::const_iterator
                 t (i->second.begin ()), end (i->second.end ());
               t != end; ++t)
          {
            dispatcher_.map (i->first, **t);
          }
        }
      }

    public:
      virtual void
      dispatch (B& n)
      {
        merge ();
        dispatcher_.dispatch (n);
      }

      virtual void
      dispatch (B const& n)
      {
        merge ();
        dispatcher_.dispatch (n);
      }

      using DispatcherBase<B>::begin;
      using DispatcherBase<B>::end;

    private:
      void
      merge ()
      {
        if (merge_)
        {
          for (typename DispatcherBase<B>::Iterator
                 i (begin ()), e (end ()); i != e; ++i)
          {
            for (typename DispatcherBase<B>::Traversers::const_iterator
                   t (i->second.begin ()), e (i->second.end ()); t != e; ++t)
            {
              dispatcher_.map (i->first, **t);
            }
          }

          merge_ = false;
        }
      }

    protected:
      // DispatcherBase<B>&
      // traverser ()
      // {
      //   return dispatcher_;
      // }

      template <typename X, typename A, typename I>
      void
      iterate_and_dispatch (I begin, I end, X& x, void (X::*next)(A&), A& a)
      {
        for (; begin != end;)
        {
          dispatch (*begin);

          if (++begin != end) (x.*next) (a);
        }
      }

    private:
      bool merge_;
      DispatcherBase<B> dispatcher_;
    };



    //
    //
    //
    template <typename T, typename B>
    struct Traverser : TraverserBase<B>, virtual Dispatcher<B>
    {
      typedef
      T
      Type;

      Traverser ()
      {
        DispatcherBase<B>::map (typeid (Type), *this);
      }

      virtual void
      traverse (Type&)
      {
        abort ();
      }

      virtual void
      traverse (Type const&)
      {
        abort ();
      }

    protected:
      virtual void
      trampoline (B& n)
      {
        //wcerr << "trampoline for " << &n << " to type "
        //      << typeid (Type).name () << endl;

        traverse (dynamic_cast<Type&> (n));
      }

      virtual void
      trampoline (B const& n)
      {
        //wcerr << "trampoline for " << &n << " to type "
        //      << typeid (Type).name () << endl;

        traverse (dynamic_cast<Type const&> (n));
      }
    };
  }
}

#include <ace/XML_Utils/XSCRT/Traversal.tpp>

#endif  // XSCRT_TRAVERSAL_HPP
