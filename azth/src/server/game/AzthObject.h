#ifndef AZTHOBJECT_H
#define	AZTHOBJECT_H

#include "Common.h"
#include "Object.h"
#include <string>

class AzthObject {
    public:
        explicit AzthObject();
        ~AzthObject();
        
        static int IsWithinLOSInMap(const WorldObject* that, WorldObject const* obj);
};

#endif	/* AZTHOBJECT_H */

