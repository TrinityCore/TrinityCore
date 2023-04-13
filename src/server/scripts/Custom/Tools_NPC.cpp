////From:https://uiwow.com/forum.php?mod=viewthread&tid=1112&_dsign=656d8c4f
///*
//
//REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES('900000','0','0','0','0','0','26867','0','0','0','Tools NPC','- by mthsena -','Speak','0','80','80','0','35','35','1','1','1.14286','2','3','0','0','0','0','1','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','1','0','0','0','0','0','0','0','0','1','0','0','Tools_NPC','1');
//
//- Made by mthsena
//
//*/
//------------------------------------------------------------------------------------------------------------------------------
//
//
//#include "ScriptPCH.h"
//
//class Tools_NPC : public CreatureScript
//{
//public:
//    Tools_NPC() : CreatureScript("Tools_NPC") { }
//
//    bool OnGossipHello(Player *player, Creature *creature)
//    {
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Restore HP and MP", GOSSIP_SENDER_MAIN, 1);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Instances", GOSSIP_SENDER_MAIN, 2);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Cooldowns", GOSSIP_SENDER_MAIN, 3);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Combat", GOSSIP_SENDER_MAIN, 4);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Remove Sickness", GOSSIP_SENDER_MAIN, 5);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Repair Items", GOSSIP_SENDER_MAIN, 6);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Others...", GOSSIP_SENDER_MAIN, 7);
//        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Exit", GOSSIP_SENDER_MAIN, 8);
//        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        return true;
//    }
//    bool OnGossipSelect(Player *player, Creature *creature, uint32 sender, uint32 action)
//    {
//        player->PlayerTalkClass->ClearMenus();
//        switch(action)
//        {
//        case 1: // Restore HP and MP
//            if(player->IsInCombat())
//            {
//                creature->MonsterWhisper("You're in combat!", player->GetGUID(), false);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//            else if(player->getPowerType() == POWER_MANA)
//                player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
//
//            player->SetHealth(player->GetMaxHealth());
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 2: // Reset Instances
//            for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
//            {
//                Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
//                for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
//                {
//                    player->UnbindInstance(itr, Difficulty(i));
//                }
//            }
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 3: // Reset Cooldowns
//            if(player->IsInCombat())
//            {
//                creature->MonsterWhisper("You're in combat!", player->GetGUID(), false);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            player->RemoveAllSpellCooldown();
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 4: // Reset Combat
//            player->CombatStop();
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 5: // Remove Sickness
//            if(player->HasAura(15007))
//                player->RemoveAura(15007);
//
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 6: // Repair Items
//            player->DurabilityRepairAll(false, 0, false);
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 7: // Others
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Talents", GOSSIP_SENDER_MAIN, 71);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Spells", GOSSIP_SENDER_MAIN, 72);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "...Back", GOSSIP_SENDER_MAIN, 73);
//            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//            break;
//        case 8:
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 71: // Reset Talents
//            player->resetTalents(true);
//            player->SendTalentsInfoData(false);
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 72: // Reset Spells
//            player->resetSpells();
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        case 73: // ...Back
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Restore HP and MP", GOSSIP_SENDER_MAIN, 1);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Instances", GOSSIP_SENDER_MAIN, 2);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Cooldowns", GOSSIP_SENDER_MAIN, 3);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reset Combat", GOSSIP_SENDER_MAIN, 4);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Remove Sickness", GOSSIP_SENDER_MAIN, 5);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Repair Items", GOSSIP_SENDER_MAIN, 6);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Others...", GOSSIP_SENDER_MAIN, 7);
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Exit", GOSSIP_SENDER_MAIN, 8);
//            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//            break;
//        }
//        return true;
//    }
//};
//
//void AddSC_Tools_NPC()
//{
//    new Tools_NPC();
//}
