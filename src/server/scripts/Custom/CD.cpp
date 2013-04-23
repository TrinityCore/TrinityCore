#include "ScriptPCH.h"
 
class Duel_Reset : public PlayerScript
{
        public:
                Duel_Reset() : PlayerScript("Duel_Reset"){}
 
                void OnDuelEnd(Player* pWinner, Player* pLoser, DuelCompleteType /*type*/)
                {
                        pWinner->RemoveAllSpellCooldown();
                        pLoser->RemoveAllSpellCooldown();
                        pWinner->SetHealth(pWinner->GetMaxHealth());
                        if ( pWinner->getPowerType() == POWER_MANA )
                                pWinner->SetPower(POWER_MANA, pWinner->GetMaxPower(POWER_MANA));
                        pLoser->SetHealth(pLoser->GetMaxHealth());
                        if ( pLoser->getPowerType() == POWER_MANA )
                                pLoser->SetPower(POWER_MANA,  pLoser->GetMaxPower(POWER_MANA));
                }
};
 
void AddSC_Duel_Reset()
{
        new Duel_Reset();
}
