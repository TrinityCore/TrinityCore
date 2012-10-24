#include "ScriptPCH.h" 
#include "ScriptMgr.h" 
#include "Config.h" 
 
class duel_reset : public PlayerScript 
{ 
public: 
    duel_reset() : PlayerScript("duel_reset") {} 
 
    void OnDuelEnd(Player *winner, Player *looser, DuelCompleteType type) 
    { 
        if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_ON_FINISH)) 
        { 
            if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_ONLY_IN_ELWYNN_AND_DUROTAR)) 
            { 
                if(winner->GetZoneId() == 14 || winner->GetZoneId() == 12) 
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
 
            else 
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
 
    void OnDuelStart(Player *player1, Player *player2) 
    { 
        if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_ON_START)) 
        { 
            if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_ONLY_IN_ELWYNN_AND_DUROTAR)) 
            { 
                if(player1->GetZoneId() == 14 || player1->GetZoneId() == 12) 
                { 
                    player1->RemoveArenaSpellCooldowns(); 
                    player2->RemoveArenaSpellCooldowns(); 
                    player1->SetHealth(player1->GetMaxHealth()); 
                    player2->SetHealth(player2->GetMaxHealth()); 
 
                    if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_RESET_ENERGY_ON_START)) 
                    { 
                        switch (player1->getPowerType()) 
                        { 
                        case POWER_RAGE: 
                            player1->SetPower(POWER_RAGE, 0); 
                            break; 
                        case POWER_RUNIC_POWER: 
                            player1->SetPower(POWER_RUNIC_POWER, 0); 
                            break; 
                        default: 
                            break; 
                        } 
 
                        switch (player2->getPowerType()) 
                        { 
                        case POWER_RAGE: 
                            player2->SetPower(POWER_RAGE, 0); 
                            break; 
                        case POWER_RUNIC_POWER: 
                            player2->SetPower(POWER_RUNIC_POWER, 0); 
                            break; 
                        default: 
                            break; 
                        } 
                    } 
 
                    if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_MAX_ENERGY_ON_START)) 
                    { 
                        switch (player1->getPowerType()) 
                        { 
                        case POWER_MANA: 
                            player1->SetPower(POWER_MANA, player1->GetMaxPower(POWER_MANA)); 
                            break; 
                        case POWER_RAGE: 
                            player1->SetPower(POWER_RAGE, player1->GetMaxPower(POWER_RAGE)); 
                            break; 
                        case POWER_RUNIC_POWER: 
                            player1->SetPower(POWER_RUNIC_POWER, player1->GetMaxPower(POWER_RUNIC_POWER)); 
                            break; 
                        default: 
                            break; 
                        } 
 
                        switch (player2->getPowerType()) 
                        { 
                        case POWER_MANA: 
                            player2->SetPower(POWER_MANA, player2->GetMaxPower(POWER_MANA)); 
                           break; 
                       case POWER_RAGE: 
                           player2->SetPower(POWER_RAGE, player2->GetMaxPower(POWER_RAGE)); 
                            break; 
                        case POWER_RUNIC_POWER: 
                            player2->SetPower(POWER_RUNIC_POWER, player2->GetMaxPower(POWER_RUNIC_POWER)); 
                            break; 
                        default: 
                            break; 
                        } 
                    } 
                } 
            } 

            else 
            { 
                player1->RemoveArenaSpellCooldowns(); 
                player2->RemoveArenaSpellCooldowns(); 
                player1->SetHealth(player1->GetMaxHealth()); 
                player2->SetHealth(player2->GetMaxHealth()); 
 
                if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_MAX_ENERGY_ON_START)) 
                { 
                    switch (player1->getPowerType()) 
                    { 
                    case POWER_MANA: 
                        player1->SetPower(POWER_MANA, player1->GetMaxPower(POWER_MANA)); 
                        break; 
                    case POWER_RAGE: 
                        player1->SetPower(POWER_RAGE, player1->GetMaxPower(POWER_RAGE)); 
                        break; 
                    case POWER_RUNIC_POWER: 
                        player1->SetPower(POWER_RUNIC_POWER, player1->GetMaxPower(POWER_RUNIC_POWER)); 
                        break; 
                    default: 
                        break; 
                    } 
 
                    switch (player2->getPowerType()) 
                    { 
                    case POWER_MANA: 
                        player2->SetPower(POWER_MANA, player2->GetMaxPower(POWER_MANA)); 
                        break; 
                    case POWER_RAGE: 
                        player2->SetPower(POWER_RAGE, player2->GetMaxPower(POWER_RAGE)); 
                        break; 
                    case POWER_RUNIC_POWER: 
                        player2->SetPower(POWER_RUNIC_POWER, player2->GetMaxPower(POWER_RUNIC_POWER)); 
                        break; 
                    default: 
                        break; 
                    } 
                } 
            } 
        } 
    } 
}; 
 
void AddSC_DuelReset() 
{ 
    new duel_reset(); 
} 