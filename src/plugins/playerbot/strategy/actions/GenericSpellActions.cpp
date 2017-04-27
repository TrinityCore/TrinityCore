#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GenericActions.h"

using namespace ai;

bool CastSpellAction::Execute(Event event)
{
	if (spell == "mount")
	{
		if (bot->InBattleground() && !bot->IsInCombat())
		{
			if (!bot->IsMounted())
			{
				//Mounts
				if (bot->getLevel() > 39 && bot->GetTeamId() == TeamId::TEAM_ALLIANCE)
				{
					return ai->CastSpell(23240, bot);
				}
				if (bot->getLevel() > 39 && bot->GetTeamId() == TeamId::TEAM_HORDE)
				{
					return ai->CastSpell(23242, bot);
				}
				if (bot->getLevel() > 19 && bot->GetTeamId() == TeamId::TEAM_ALLIANCE)
				{
					return ai->CastSpell(6899, bot);
				}
				if (bot->getLevel() > 19 && bot->GetTeamId() == TeamId::TEAM_HORDE)
				{
					return ai->CastSpell(8395, bot);
				}
			}
		}
		return false;
	}	
	return ai->CastSpell(spell, GetTarget());
}

bool CastSpellAction::isPossible()
{
	if (spell == "mount" && !bot->IsMounted() && !bot->IsInCombat())
		return true;
	if (spell == "mount" && bot->IsInCombat())
	{
		bot->Dismount();
		return false;
	}	
	return ai->CanCastSpell(spell, GetTarget());
}

bool CastSpellAction::isUseful()
{
	if (spell == "mount" && !bot->IsMounted() && !bot->IsInCombat())
		return true;
	if (spell == "mount" && bot->IsInCombat())
	{
		bot->Dismount();
		return false;
	}	
	return GetTarget() && AI_VALUE2(bool, "spell cast useful", spell);
}

bool CastAuraSpellAction::isUseful()
{
	return CastSpellAction::isUseful() && !ai->HasAura(spell, GetTarget());
}

bool CastEnchantItemAction::isUseful()
{
    if (!CastSpellAction::isUseful())
        return false;

    uint32 spellId = AI_VALUE2(uint32, "spell id", spell);
    return spellId && AI_VALUE2(Item*, "item for spell", spellId);
}

bool CastHealingSpellAction::isUseful()
{
	return CastAuraSpellAction::isUseful() && AI_VALUE2(uint8, "health", GetTargetName()) < (100 - estAmount);
}

bool CastAoeHealSpellAction::isUseful()
{
	return CastSpellAction::isUseful() && AI_VALUE2(uint8, "aoe heal", "medium") > 0;
}


Value<Unit*>* CurePartyMemberAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member to dispel", dispelType);
}

Value<Unit*>* BuffOnPartyAction::GetTargetValue()
{
    return context->GetValue<Unit*>("party member without aura", spell);
}
