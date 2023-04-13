///*
//# SoloCraft #
//#### A module for AzerothCore by [StygianTheBest](https://github.com/StygianTheBest/AzerothCore-Content/tree/master/Modules)
//------------------------------------------------------------------------------------------------------------------
//### Description ###
//------------------------------------------------------------------------------------------------------------------
//These are my extensions to the TrinityCore WoW Server Emulator for WoW version 3.3.5a that are targetted toward
//soloing (or with a very small party) the group content in WoW like dungeons and raids at the level the content was
//meant for instead of having to come back and solo when you are 20 levels higher than the content.
//The goal is to automatically apply stat buffs, HP regeneration, procs like dispelling target regeneration buffs,
//and other things to the player based on the instance the player has entered and the size of the party they are in
//to make up the non-deal party makeup.
//## To-Do ###
//------------------------------------------------------------------------------------------------------------------
//- Verify player pets are buffed accordingly
//- Dispel target regeneration
//- Provide unlimited http://www.wowhead.com/item=17333/aqual-quintessence
//    - Not Needed (Sadly), the need to douse the runes with Aqual Quintessence was removed in 3.0.8
//## Data ###
//------------------------------------------------------------------------------------------------------------------
//- Type: Server/Player
//- Script: Solocraft
//- Config: Yes
//    - Enable Module
//    - Enable Module Announce
//    - Set Difficulty for Instance Types
//- SQL: No
//### Version ###
//------------------------------------------------------------------------------------------------------------------
//- v2017.09.04 - Add config options for difficulty levels
//- v2017.09.05 - Update strings, Add module announce
//- v2018.12.17 - Changed difficulty type from int to float, to allow for more nuanced difficulties ie. 1.5
//    Added difficulties for more raid sizes, and assign them based on the map's maximum players
//    Fixed issue where modifier was 1 + set value, so setting modifier to 2x was actually applying a 3x modifier.
//### Credits ###
//------------------------------------------------------------------------------------------------------------------
//- [David Macalaster](https://github.com/DavidMacalaster/Solocraft)
//- [Blizzard Entertainment](http://blizzard.com)
//- [TrinityCore](https://github.com/TrinityCore/TrinityCore/blob/3.3.5/THANKS)
//- [SunwellCore](http://www.azerothcore.org/pages/sunwell.pl/)
//- [AzerothCore](https://github.com/AzerothCore/azerothcore-wotlk/graphs/contributors)
//- [AzerothCore Discord](https://discord.gg/gkt4y2x)
//- [EMUDevs](https://youtube.com/user/EmuDevs)
//- [AC-Web](http://ac-web.org/)
//- [ModCraft.io](http://modcraft.io/)
//- [OwnedCore](http://ownedcore.com/)
//- [OregonCore](https://wiki.oregon-core.net/)
//- [Wowhead.com](http://wowhead.com)
//- [AoWoW](https://wotlk.evowow.com/)
//### License ###
//------------------------------------------------------------------------------------------------------------------
//- This code and content is released under the [GNU AGPL v3](https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3).
//*/
//
//#include <map>
//#include "Config.h"
//#include "Chat.h"
//#include "Log.h"
//#include "ScriptMgr.h"
//#include "Unit.h"
//#include "Player.h"
//#include "Pet.h"
//#include "Map.h"
//#include "Group.h"
//#include "InstanceScript.h"
//
//namespace {
//
//    class solocraft_player_instance_handler : public PlayerScript {
//
//    public:
//
//        solocraft_player_instance_handler() : PlayerScript("solocraft_player_instance_handler")
//        {
//            TC_LOG_INFO("scripts.solocraft.player.instance", "[Solocraft] solocraft_player_instance_handler Loaded");
//        }
//
//        void OnMapChanged(Player* player) override
//        {
//            if (sConfigMgr->GetBoolDefault("Solocraft.Enable", true))
//            {
//                Map* map = player->GetMap();
//                float difficulty = CalculateDifficulty(map, player);
//                int numInGroup = GetNumInGroup(player);
//                ApplyBuffs(player, map, difficulty, numInGroup);
//            }
//        }
//
//    private:
//        std::map<ObjectGuid, float> _unitDifficulty;
//
//        // Get difficulty values from config
//        const float D5 = sConfigMgr->GetFloatDefault("Solocraft.Dungeon", 5.0);
//        const float D5H = sConfigMgr->GetFloatDefault("Solocraft.Heroic", 10.0);
//        const float D5M = sConfigMgr->GetFloatDefault("Solocraft.Mythic", 15.0);
//        const float D10 = sConfigMgr->GetFloatDefault("Solocraft.Raid10", 10.0);
//        const float D25 = sConfigMgr->GetFloatDefault("Solocraft.Raid25", 25.0);
//        const float D30 = sConfigMgr->GetFloatDefault("Solocraft.Raid30", 30.0);
//        const float D40 = sConfigMgr->GetFloatDefault("Solocraft.Raid30", 40.0);
//
//        // Set the instance difficulty
//        float CalculateDifficulty(Map* map, Player* player) {
//            float difficulty = 1.0;
//            if (map) {
//                if (map->IsRaid())
//                {
//                    switch (map->GetMapDifficulty()->MaxPlayers)
//                    {
//                    case 10:
//                        difficulty = D10; break;
//                    case 25:
//                        difficulty = D25; break;
//                    case 30:
//                        difficulty = D30; break;
//                    case 40:
//                        difficulty = D40; break;
//                    default:
//                        TC_LOG_WARN("scripts.solocraft.player.instance", "[SoloCraft] Unrecognized max players %d, defaulting to 10 man difficulty",
//                            map->GetMapDifficulty()->MaxPlayers);
//                        difficulty = D10;
//                    }
//                }
//                else if (map->IsDungeon())
//                {
//                    if (map->IsMythic())
//                        difficulty = D5M;
//                    else if (map->IsHeroic())
//                        difficulty = D5H;
//                    else
//                        difficulty = D5;
//                }
//            }
//            return difficulty - 1.0; // HandleStatModifier treats 100 as +100%, so a difficulty of 1 ends up being applied as a 200% buff
//        }
//
//        // Get the groups size
//        int GetNumInGroup(Player* player) {
//            int numInGroup = 1;
//            Group* group = player->GetGroup();
//            if (group) {
//                Group::MemberSlotList const& groupMembers = group->GetMemberSlots();
//                numInGroup = groupMembers.size();
//            }
//            return numInGroup;
//        }
//
//        // Apply the player buffs
//        void ApplyBuffs(Player* player, Map* map, float difficulty, int numInGroup)
//        {
//            ClearBuffs(player, map);
//
//            if (difficulty != 0)
//            {
//                // InstanceMap *instanceMap = map->ToInstanceMap();
//                // InstanceScript *instanceScript = instanceMap->GetInstanceScript();
//
//                // Announce to player
//                std::ostringstream ss;
//                ss << "|cffFF0000[SoloCraft] |cffFF8000" << player->GetName() << " entered %s - # of Players: %d - Difficulty Offset: %0.2f.";
//                ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), numInGroup, difficulty + 1.0);
//
//                // Adjust player stats
//                _unitDifficulty[player->GetGUID()] = difficulty;
//                for (int32 i = STAT_STRENGTH; i < MAX_STATS; ++i)
//                {
//                    // Buff the player
//                    player->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + i), TOTAL_PCT, difficulty * 100.0, true);
//                }
//
//                // Set player health
//                player->SetFullHealth();
//                if (player->GetPowerType() == POWER_MANA)
//                {
//                    // Buff the player's health
//                    player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
//                }
//            }
//        }
//
//        void ClearBuffs(Player* player, Map* map)
//        {
//            std::map<ObjectGuid, float>::iterator unitDifficultyIterator = _unitDifficulty.find(player->GetGUID());
//            if (unitDifficultyIterator != _unitDifficulty.end())
//            {
//                float difficulty = unitDifficultyIterator->second;
//                _unitDifficulty.erase(unitDifficultyIterator);
//
//                // Inform the player
//                std::ostringstream ss;
//                ss << "|cffFF0000[SoloCraft] |cffFF8000" << player->GetName() << " exited to %s - Reverting Difficulty Offset: %0.2f.";
//                ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), difficulty + 1.0);
//
//                // Clear the buffs
//                for (int32 i = STAT_STRENGTH; i < MAX_STATS; ++i)
//                {
//                    player->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + i), TOTAL_PCT, difficulty * 100.0, false);
//                }
//            }
//        }
//    };
//}
//
//void AddSC_solocraft() {
//    new solocraft_player_instance_handler();
//}
