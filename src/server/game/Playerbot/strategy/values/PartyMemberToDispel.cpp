#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PartyMemberToDispel.h"
#include "../../../Entities/Pet/Pet.h"

using namespace ai;

class PartyMemberToDispelPredicate : public FindPlayerPredicate, public PlayerbotAIAware
{
public:
    PartyMemberToDispelPredicate(PlayerbotAI* ai, uint32 dispelType) :
        PlayerbotAIAware(ai), FindPlayerPredicate(), dispelType(dispelType) {}

public:
    virtual bool Check(Unit* unit)
    {
        if (unit->IsPet())
        {
            Pet* pet = unit->ToPet();
            if (pet && pet->getPetType() == SUMMON_PET)
                return false;
        }

        return unit->IsAlive() && ai->HasAuraToDispel(unit, dispelType);
    }

private:
    uint32 dispelType;
};

Unit* PartyMemberToDispel::Calculate()
{
    uint32 dispelType = atoi(qualifier.c_str());

    PartyMemberToDispelPredicate predicate(ai, dispelType);
    return FindPartyMember(predicate);
}
