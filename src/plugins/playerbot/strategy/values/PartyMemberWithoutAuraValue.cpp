#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PartyMemberWithoutAuraValue.h"
#include "../../../Entities/Pet/Pet.h"

using namespace ai;

class PlayerWithoutAuraPredicate : public FindPlayerPredicate, public PlayerbotAIAware
{
public:
    PlayerWithoutAuraPredicate(PlayerbotAI* ai, string aura) :
        PlayerbotAIAware(ai), FindPlayerPredicate(), aura(aura) {}

public:
    virtual bool Check(Unit* unit)
    {
        if (unit->IsPet())
        {
            Pet* pet = unit->ToPet();
            if (pet && pet->getPetType() == SUMMON_PET)
                return false;
        }

        return unit->IsAlive() && !ai->HasAura(aura, unit);
    }

private:
    string aura;
};

Unit* PartyMemberWithoutAuraValue::Calculate()
{
	PlayerWithoutAuraPredicate predicate(ai, qualifier);
    return FindPartyMember(predicate);
}
