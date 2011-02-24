#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "Config.h"

class duel_reset : public PlayerScript
{
    public:
        duel_reset() : PlayerScript("duel_reset") {}

    void OnDuelEnd(Player *winner, Player *looser, DuelCompleteType type)
    {
        // reset cooldowns in elewynn forest and durotar
        if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN) && (winner->GetZoneId() == 14 || winner->GetZoneId() == 12))
        {
            if (type == DUEL_WON)
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

            winner->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
        }
    }
};

void AddSC_DuelReset()
{
    new duel_reset;
}
