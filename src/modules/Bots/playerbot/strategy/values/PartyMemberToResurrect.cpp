#include "botpch.h"
#include "../../playerbot.h"
#include "PartyMemberToResurrect.h"

#include "../../ServerFacade.h"
using namespace ai;

class IsTargetOfResurrectSpell : public SpellEntryPredicate
{
public:
    virtual bool Check(SpellEntry const* spell)
    {
        for (int i=0; i<3; i++)
        {
            if (spell->Effect[i] == SPELL_EFFECT_RESURRECT ||
                spell->Effect[i] == SPELL_EFFECT_RESURRECT_NEW ||
                spell->Effect[i] == SPELL_EFFECT_SELF_RESURRECT)
                return true;
        }
        return false;
    }

};

class FindDeadPlayer : public FindPlayerPredicate
{
public:
    FindDeadPlayer(PartyMemberValue* value) : value(value) {}

    virtual bool Check(Unit* unit)
    {
        Player* player = dynamic_cast<Player*>(unit);
        return player && sServerFacade.GetDeathState(player) == CORPSE && !value->IsTargetOfSpellCast(player, predicate);
    }

private:
    PartyMemberValue* value;
    IsTargetOfResurrectSpell predicate;
};

Unit* PartyMemberToResurrect::Calculate()
{
	FindDeadPlayer finder(this);
    return FindPartyMember(finder);
}
