#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "PartyMemberToHeal.h"
#include "../../PlayerbotAIConfig.h"
#include "../../../Entities/Pet/Pet.h"

using namespace ai;

class IsTargetOfHealingSpell : public SpellEntryPredicate
{
public:
    virtual bool Check(SpellInfo const* spell) {
        for (int i=0; i<3; i++) {
            if (spell->Effects[i].Effect == SPELL_EFFECT_HEAL ||
                spell->Effects[i].Effect == SPELL_EFFECT_HEAL_MAX_HEALTH ||
                spell->Effects[i].Effect == SPELL_EFFECT_HEAL_MECHANICAL ||
                spell->Effects[i].Effect == SPELL_EFFECT_HEAL_PCT)
                return true;
        }
        return false;
    }

};

Unit* PartyMemberToHeal::Calculate()
{

    IsTargetOfHealingSpell predicate;

    Group* group = bot->GetGroup();
    if (!group)
        return NULL;

    bool isRaid = bot->GetGroup()->isRaidGroup();
    MinValueCalculator calc(100);
    for (GroupReference *gref = group->GetFirstMember(); gref; gref = gref->next())
    {
        Player* player = gref->GetSource();
        if (!Check(player) || !player->IsAlive())
            continue;

        uint8 health = player->GetHealthPct();
        if (isRaid || health < sPlayerbotAIConfig.mediumHealth || !IsTargetOfSpellCast(player, predicate))
            calc.probe(health, player);

        Pet* pet = player->GetPet();
        if (pet && CanHealPet(pet))
        {
            health = ((Unit*)pet)->GetHealthPct();
            if (isRaid || health < sPlayerbotAIConfig.mediumHealth || !IsTargetOfSpellCast(player, predicate))
                calc.probe(health, player);
        }
    }
    return (Unit*)calc.param;
}

bool PartyMemberToHeal::CanHealPet(Pet* pet)
{
    return HUNTER_PET == pet->getPetType();
}
