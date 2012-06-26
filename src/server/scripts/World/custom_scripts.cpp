#include "ScriptPCH.h"

class Reset_OnDuelEnd : public PlayerScript
{
    public:
        Reset_OnDuelEnd() : PlayerScript("Reset_OnDuelEnd") {}

    void OnDuelEnd(Player *winner, Player *looser, DuelCompleteType type)
    {
        // reset cooldowns in elwynn forest, durotar and dalaran
        if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN) && (winner->GetZoneId() == 14 || winner->GetZoneId() == 12 || winner->GetZoneId() == 4395))
        {
            winner->RemoveArenaSpellCooldowns();
            looser->RemoveArenaSpellCooldowns();
            winner->SetHealth(winner->GetMaxHealth());
            looser->SetHealth(looser->GetMaxHealth());
            if (winner->getPowerType() == POWER_MANA) 
                winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
            if (looser->getPowerType() == POWER_MANA) 
                looser->SetPower(POWER_MANA, looser->GetMaxPower(POWER_MANA));
        }
    }
};

void AddSC_DuelReset()
{
    new Reset_OnDuelEnd;
}