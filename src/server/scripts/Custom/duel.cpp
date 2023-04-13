//
//#include "PrecompiledHeaders/ScriptPCH.h"
//#include "ScriptMgr.h"
//#include "Object.h"
//
//enum DuelSpectateMode
//{
//    SpectateDisabled = 0,
//    SpectateEnabled = 1,
//};
//
//enum DuelZonesAndAreas
//{
//    AllowedArea = 6908,
//    AllowedZone = 6908
//};
//
//class duel_zone : public PlayerScript
//{
//public:
//    duel_zone() : PlayerScript("duel_zone") {}
//
//    void OnDuelEnd(Player* winner, Player* looser, DuelCompleteType type)
//    {
//        if (winner->GetCurrentAreaID() != AllowedArea && winner->GetCurrentZoneID() != AllowedZone)
//            return;
//
//        if (type == DUEL_FINISHED)
//        {
//            winner->RemoveArenaSpellCooldowns();
//            looser->RemoveArenaSpellCooldowns();
//
//            winner->SetHealth(winner->GetMaxHealth());
//            looser->SetHealth(looser->GetMaxHealth());
//
//            if (winner->getPowerType() == POWER_MANA)
//                winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
//
//            if (looser->getPowerType() == POWER_MANA)
//                looser->SetPower(POWER_MANA, looser->GetMaxPower(POWER_MANA));
//        }
//
//        SwitchSpectateMode(winner, SpectateEnabled);
//        SwitchSpectateMode(looser, SpectateEnabled);
//    }
//
//    void OnDuelStart(Player* player1, Player* player2)
//    {
//        if (player1->GetCurrentAreaID() != AllowedArea && player1->GetCurrentZoneID() != AllowedZone)
//            return;
//
//        uint32 uniqValue = getMSTime();
//        SwitchSpectateMode(player1, uniqValue);
//        SwitchSpectateMode(player2, uniqValue);
//    }
//
//    void OnUpdateZone(Player* p_Player, uint32 p_NewZone, uint32 p_NewArea)
//    {
//        switch (p_NewArea)
//        {
//        case AllowedArea:
//            SwitchSpectateMode(p_Player, SpectateEnabled);
//            return;
//        default:
//            break;
//        }
//        switch (p_NewZone)
//        {
//        case AllowedZone:
//            SwitchSpectateMode(p_Player, SpectateEnabled);
//            return;
//        default:
//            break;
//        }
//        SwitchSpectateMode(p_Player, SpectateDisabled);
//    }
//
//    void SwitchSpectateMode(Player* player, uint32 value)
//    {
//        player->m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_DUEL, value);
//        // player->UpdateObjectVisibility();
//    }
//};
//
//class duel_reset : public PlayerScript
//{
//public:
//    duel_reset() : PlayerScript("duel_reset") {}
//
//    void OnDuelEnd(Player* winner, Player* looser, DuelCompleteType type)
//    {
//        if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_ON_FINISH))
//        {
//            if (winner->GetCurrentZoneID() == 14 || winner->GetCurrentZoneID() == 12)
//            {
//                if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_IN_ELWYNN_AND_DUROTAR))
//                {
//                    if (type == DUEL_FINISHED)
//                    {
//                        winner->RemoveArenaSpellCooldowns();
//                        looser->RemoveArenaSpellCooldowns();
//                        winner->SetHealth(winner->GetMaxHealth());
//                        looser->SetHealth(looser->GetMaxHealth());
//
//                        if (winner->getPowerType() == POWER_MANA)
//                            winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
//
//                        if (looser->getPowerType() == POWER_MANA)
//                            looser->SetPower(POWER_MANA, looser->GetMaxPower(POWER_MANA));
//                    }
//                }
//            }
//            else if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_IN_DUEL_ZONE))
//            {
//                if (type == DUEL_FINISHED)
//                {
//                    winner->RemoveArenaSpellCooldowns();
//                    looser->RemoveArenaSpellCooldowns();
//                    winner->SetHealth(winner->GetMaxHealth());
//                    looser->SetHealth(looser->GetMaxHealth());
//
//                    if (winner->getPowerType() == POWER_MANA)
//                        winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
//
//                    if (looser->getPowerType() == POWER_MANA)
//                        looser->SetPower(POWER_MANA, looser->GetMaxPower(POWER_MANA));
//                }
//
//            }
//            winner->HandleEmoteCommand(EMOTE_ONESHOT_CHEER);
//        }
//    }
//
//    void OnDuelStart(Player* player1, Player* player2)
//    {
//        if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_ON_START))
//        {
//            if (player1->GetCurrentZoneID() == 14 || player1->GetCurrentZoneID() == 12)
//            {
//                if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_IN_ELWYNN_AND_DUROTAR))
//                {
//                    player1->RemoveArenaSpellCooldowns();
//                    player2->RemoveArenaSpellCooldowns();
//                    player1->SetHealth(player1->GetMaxHealth());
//                    player2->SetHealth(player2->GetMaxHealth());
//
//                    if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_RESET_ENERGY_ON_START))
//                    {
//                        player1->ResetPowers(100.0f, true);
//                        player2->ResetPowers(100.0f, true);
//                    }
//
//                    if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_MAX_ENERGY_ON_START))
//                    {
//                        player1->ResetPowers(100.0f, true);
//                        player2->ResetPowers(100.0f, true);
//                    }
//                }
//            }
//            else if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_IN_DUEL_ZONE))
//            {
//                player1->RemoveArenaSpellCooldowns();
//                player2->RemoveArenaSpellCooldowns();
//                player1->SetHealth(player1->GetMaxHealth());
//                player2->SetHealth(player2->GetMaxHealth());
//
//                if (sWorld->getBoolConfig(CONFIG_DUEL_RESET_COOLDOWN_MAX_ENERGY_ON_START))
//                {
//                    player1->ResetPowers(100.0f, true);
//                    player2->ResetPowers(100.0f, true);
//                }
//            }
//        }
//    }
//};
//
//enum Borders
//{
//    MinHordeX = 824,
//    MaxHordeX = 1389,
//
//    MinAllianceX = 1269,
//    MaxAllianceX = 1844,
//
//    GeneralMinY = 147,
//    GeneralMaxY = 716
//
//};
//
//class duel_check_position : public PlayerScript
//{
//public:
//    duel_check_position() : PlayerScript("duel_check_position") {}
//
//    uint32 timer_for_check;
//
//    void OnLogin(Player* player, bool firstLogin) override
//    {
//        timer_for_check = 2000;
//    }
//
//    void OnUpdate(Player* player, uint32 diff)
//    {
//        if (!player || player->isGameMaster())
//            return;
//
//        if (timer_for_check <= diff)
//        {
//            if (player->GetCurrentAreaID() == AllowedArea || player->GetCurrentZoneID() == AllowedZone)
//            {
//                if (player->GetPositionX() <= (player->GetTeam() == HORDE ? MinHordeX : MinAllianceX) ||
//                    player->GetPositionX() >= (player->GetTeam() == HORDE ? MaxHordeX : MaxAllianceX) ||
//                    player->GetPositionY() <= GeneralMinY ||
//                    player->GetPositionY() >= GeneralMaxY)
//                {
//                    player->TeleportTo(player->GetMapId(), 1332.92f, 579.96f, 38.24f, 4.68f);
//                    player->CastSpell(player, 70618);
//                    ChatHandler(player).PSendSysMessage("You have gone beyond the boundaries of the zone available to you!");
//                }
//
//            }
//            timer_for_check = 2000;
//        }
//        else
//            timer_for_check -= diff;
//    }
//};
//
//void AddSC_Duel()
//{
//    new duel_zone();
//    new duel_reset();
//    new duel_check_position();
//}
