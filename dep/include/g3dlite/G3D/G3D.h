/**
 @file G3D.h

 This header includes all of the G3D libraries in
 appropriate namespaces.

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu

 @created 2001-08-25
 @edited  2010-01-30

 Copyright 2000-2010, Morgan McGuire.
 All rights reserved.
*/

#ifndef G3D_G3D_h
#define G3D_G3D_h

#define NOMINMAX 1
#ifdef min
    #undef min
#endif
#ifdef max
    #undef max
#endif

#include "G3D/platform.h"
#include "G3D/units.h"
#include "G3D/ParseError.h"
#include "G3D/Random.h"
#include "G3D/Array.h"
#include "G3D/SmallArray.h"
#include "G3D/Queue.h"
#include "G3D/Crypto.h"
#include "G3D/format.h"
#include "G3D/Vector2.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/Color1.h"
#include "G3D/Color3.h"
#include "G3D/Color4.h"
#include "G3D/Matrix2.h"
#include "G3D/Matrix3.h"
#include "G3D/Matrix4.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/PhysicsFrame.h"
#include "G3D/Plane.h"
#include "G3D/Line.h"
#include "G3D/Ray.h"
#include "G3D/Sphere.h"
#include "G3D/Box.h"
#include "G3D/Box2D.h"
#include "G3D/AABox.h"
#include "G3D/WrapMode.h"
#include "G3D/Cone.h"
#include "G3D/Quat.h"
#include "G3D/stringutils.h"
#include "G3D/prompt.h"
#include "G3D/Table.h"
#include "G3D/Set.h"
#include "G3D/GUniqueID.h"
#include "G3D/BinaryFormat.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/debug.h"
#include "G3D/g3dfnmatch.h"
#include "G3D/G3DGameUnits.h"
#include "G3D/g3dmath.h"
#include "G3D/uint128.h"
#include "G3D/fileutils.h"
#include "G3D/ReferenceCount.h"
#include "G3D/Welder.h"
#include "G3D/GMutex.h"
#include "G3D/PrecomputedRandom.h"
#include "G3D/MemoryManager.h"
#include "G3D/AreaMemoryManager.h"
#include "G3D/BumpMapPreprocess.h"

template<class T> struct HashTrait< G3D::ReferenceCountedPointer<T> > {
    static size_t hashCode(G3D::ReferenceCountedPointer<T> key) { return reinterpret_cast<size_t>( key.pointer() ); }
};

#include "G3D/GImage.h"
#include "G3D/CollisionDetection.h"
#include "G3D/Intersect.h"
#include "G3D/Log.h"
#include "G3D/serialize.h"
#include "G3D/TextInput.h"
#include "G3D/NetAddress.h"
#include "G3D/NetworkDevice.h"
#include "G3D/System.h"
#include "G3D/splinefunc.h"
#include "G3D/Spline.h"
#include "G3D/UprightFrame.h"
#include "G3D/LineSegment.h"
#include "G3D/Capsule.h"
#include "G3D/Cylinder.h"
#include "G3D/Triangle.h"
#include "G3D/Color3uint8.h"
#include "G3D/Color4uint8.h"
#include "G3D/Vector2int16.h"
#include "G3D/Vector3int16.h"
#include "G3D/Vector3int32.h"
#include "G3D/Vector4int8.h"
#include "G3D/ConvexPolyhedron.h"
#include "G3D/MeshAlg.h"
#include "G3D/vectorMath.h"
#include "G3D/Rect2D.h"
#include "G3D/GCamera.h"
#include "G3D/GLight.h"
#include "G3D/KDTree.h"
#include "G3D/PointKDTree.h"
#include "G3D/TextOutput.h"
#include "G3D/MeshBuilder.h"
#include "G3D/Stopwatch.h"
#include "G3D/AtomicInt32.h"
#include "G3D/GThread.h"
#include "G3D/ThreadSet.h"
#include "G3D/RegistryUtil.h"
#include "G3D/Any.h"
#include "G3D/PointHashGrid.h"
#include "G3D/Map2D.h"
#include "G3D/Image1.h"
#include "G3D/Image1uint8.h"
#include "G3D/Image3.h"
#include "G3D/Image3uint8.h"
#include "G3D/Image4.h"
#include "G3D/Image4uint8.h"
#include "G3D/filter.h"
#include "G3D/WeakCache.h"
#include "G3D/Pointer.h"
#include "G3D/Matrix.h"
#include "G3D/ImageFormat.h"

#ifdef _MSC_VER
#   pragma comment(lib, "zlib")
#   pragma comment(lib, "ws2_32")
#   pragma comment(lib, "winmm")
#   pragma comment(lib, "imagehlp")
#   pragma comment(lib, "gdi32")
#   pragma comment(lib, "user32")
#   pragma comment(lib, "kernel32")
#   pragma comment(lib, "version")
#   pragma comment(lib, "advapi32")
#   pragma comment(lib, "png")
#   pragma comment(lib, "jpeg")
#   pragma comment(lib, "zip")
#   ifdef _DEBUG
        // Don't link against G3D when building G3D itself.
#      ifndef G3D_BUILDING_LIBRARY_DLL
#         pragma comment(lib, "G3Dd.lib")
#      endif
#   else
        // Don't link against G3D when building G3D itself.
#      ifndef G3D_BUILDING_LIBRARY_DLL
#         pragma comment(lib, "G3D.lib")
#      endif
#   endif
#endif

#endif

