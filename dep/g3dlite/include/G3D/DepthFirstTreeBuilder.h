/** 
  \file G3D/DepthFirstTree.h
 
  \maintainer Jamie Lesser, http://graphics.cs.williams.edu
 
  \created 2015-03-16
  \edited  2015-03-16

  Copyright 2015, Morgan McGuire.
  All rights reserved.
 */
#ifndef DepthFirstTreeBuilder_h
#define DepthFirstTreeBuilder_h

#include "G3D/platform.h"

namespace G3D {

/**
 Template class for a depth first tree traversal supporting
 methods enterChild and goToParent.
 */

template <class Node>
class DepthFirstTreeBuilder { 
public: 
    DepthFirstTreeBuilder() {};
    virtual ~DepthFirstTreeBuilder() {}; 

    /** Add child to current node and go down a level. */
    virtual void enterChild(const Node& node) = 0; 

    /** Go up a level, to parent of current node. */
    virtual void goToParent() = 0;
};

} // namespace

#endif