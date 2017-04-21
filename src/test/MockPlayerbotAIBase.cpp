#include "pch.h"
#include "aitest.h"
#include "MockPlayerbotAIBase.h"
#include "MockedTargets.h"

using namespace std;
using namespace ai;

void MockPlayerbotAIBase::InterruptSpell()
{
}

void MockPlayerbotAIBase::RemoveAura(string name)
{
    Unit* target = MockedTargets::GetSelf();
    if (HasAura(name, target)) {
        auras[target].remove(name);
        buffer.append(">-");
        buffer.append(name);
    }
}

bool MockPlayerbotAIBase::CanCastSpell(string name, Unit* target)
{
    for (list<string >::iterator i = spellCooldowns.begin(); i != spellCooldowns.end(); i++)
    {
        string s = *i;
        if (s == name)
            return false;
    }
    return true;
}

bool MockPlayerbotAIBase::IsSpellCastUseful(string name, Unit* target)
{
    return true;
}

bool MockPlayerbotAIBase::CastSpell(string name, Unit* target)
{
    buffer.append(">");
    if (target == MockedTargets::GetPartyMember())
        buffer.append("P:");
    if (target == MockedTargets::GetCurrentTarget())
        buffer.append("T:");
    if (target == MockedTargets::GetSelf())
        buffer.append("S:");
    if (target == MockedTargets::GetPet())
        buffer.append("Pet:");
    if (target == MockedTargets::GetCc())
        buffer.append("Cc:");
    buffer.append(name);

    spellCooldowns.push_back(name);
    auras[target].push_back(name);

    return true;
}

bool MockPlayerbotAIBase::HasAura(string spellName, Unit* player)
{
    for (list<string >::iterator i = auras[player].begin(); i != auras[player].end(); i++)
    {
        string s = *i;
        if (s == spellName)
            return TRUE;
    }
    return false;

}
bool MockPlayerbotAIBase::IsInterruptableSpellCasting(Unit* player, string spell)
{
    return targetIsCastingNonMeleeSpell;
}

bool MockPlayerbotAIBase::HasAuraToDispel(Unit* player, uint32 dispelType)
{
    return dispels[player] == dispelType;
}
