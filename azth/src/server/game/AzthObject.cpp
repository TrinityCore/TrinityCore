#include "AzthObject.h"
#include <string>

AzthObject::AzthObject() {
}

/**
 * Use this function to add extra checks to
 * IsWithinLOSInMap of WorldObject
 * @param that
 * @param obj
 * @return true/false to return from parent method too, -1 instead to continue parent processing 
 */
int AzthObject::IsWithinLOSInMap(const WorldObject* that,const WorldObject* obj) {
    
    /* 
     * hack for ice tomb's gameobject
     * This hack *should* be fixed instead calculating the 
     * perimeter of NPC area instead of its center during
     * LOS algorithm 
     * Now we just skip it
     */
    if (obj->GetTypeId() == TYPEID_UNIT)
        if (obj->GetEntry() == 36980 /* Ice Tomb */)
            return true;

    if (that->GetTypeId() == TYPEID_UNIT)
        if (that->GetEntry() == 36980 /* Ice Tomb */)
            return true;
    
    return -1; // continue condition
}