// @tswow-begin
#include "TotemCreature.h"
#include "TotemCreatureAI.h"
#include "MotionMaster.h"
#include <cstdlib>

int32 TotemCreatureAI::Permissible(Creature const* creature)
{
    if(creature->m_isTempCreature)
    {
        // TODO: Fix this instead of +1
        if (reinterpret_cast<TotemCreature const*>(creature)->GetOwner()->GetTypeId() == TYPEID_PLAYER) {
            return PERMIT_BASE_PROACTIVE+1;
        }
        return PERMIT_BASE_REACTIVE+1; 
    }
    return PERMIT_BASE_NO;
}

TotemCreatureAI::TotemCreatureAI(Creature* creature) : PetAI(creature)
{
}

void TotemCreatureAI::OwnerAttacked(Unit* target)
{
    PetAI::OwnerAttacked(target);
}
// @tswow-end