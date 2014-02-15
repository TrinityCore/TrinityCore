/*
<--------------------------------------------------------------------------->
 - Developer(s): Made by ??
 - Edited by - Ghostcrawler336 and SymbolixDEV
 - Complete: 100%
 - ScriptName: 'Duel Reset' 
 - Comment: Untested.
 - Updated - 8/7/2013 or 7/8/2013
<--------------------------------------------------------------------------->
*/
#include "ScriptPCH.h"

class Duel_Reset : public PlayerScript
{
	public:
		Duel_Reset() : PlayerScript("Duel_Reset"){}

		void OnDuelEnd(Player* Winner, Player* Loser, DuelCompleteType /*type*/)
		{
			Winner->RemoveAllSpellCooldown();
			Loser->RemoveAllSpellCooldown();
			Winner->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
			Loser->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
			Winner->CastStop();
			Loser->CastStop();
			Winner->AttackStop();
			Loser->AttackStop();
			Winner->SetHealth(Winner->GetMaxHealth());
			if ( Winner->getPowerType() == POWER_MANA )
				Winner->SetPower(POWER_MANA, Winner->GetMaxPower(POWER_MANA));
			Loser->SetHealth(Loser->GetMaxHealth());
			if ( Loser->getPowerType() == POWER_MANA )
				Loser->SetPower(POWER_MANA,  Loser->GetMaxPower(POWER_MANA));
		}
};

void AddSC_Duel_Reset()
{
	new Duel_Reset();
}