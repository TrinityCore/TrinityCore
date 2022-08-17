#include "LoadDataQueries.h"
#include "Errors.h"
#include <vector>

static std::vector<LoadDataQuery*> asyncQueries;

LoadDataQuery::LoadDataQuery(std::string const& query)
    : m_query(query)
{}

QueryResult LoadDataQuery::GetOrQueryResults()
{
    WaitForAsyncQuery();
    if (m_asyncResult.has_value())
    {
        // async queries are only ever consumed once
        QueryResult res = m_asyncResult.value();
        m_asyncResult.reset();
        return res;
    }

    return WorldDatabase.Query(m_query.c_str());
}

void LoadDataQuery::StartAsyncQuery()
{
    ASSERT(!m_asyncQuery.has_value());
    m_asyncQuery.emplace(WorldDatabase.AsyncQuery(m_query.c_str())
        .WithCallback([this](QueryResult res) {
            m_asyncResult = res;
        }));
}

void LoadDataQuery::WaitForAsyncQuery()
{
    while (m_asyncQuery.has_value())
    {
        if (m_asyncQuery->InvokeIfReady())
        {
            m_asyncQuery.reset();
            break;
        }
        // todo: bad wait
        std::this_thread::sleep_for(5ms);
    }
}

void LoadDataQuery::WaitForAllAsyncQueries()
{
    for (LoadDataQuery* query : asyncQueries)
    {
        query->WaitForAsyncQuery();
    }
}

LoadDataQuery LoadCreatureLocaleQuery("SELECT entry, locale, Name, Title FROM creature_template_locale");

LoadDataQuery LoadGossipMenuItemsLocalesQuery(
    //      0       1         2       3           4
    "SELECT MenuID, OptionID, Locale, OptionText, BoxText FROM gossip_menu_option_locale"
);

LoadDataQuery LoadPointOfInterestLocalesQuery(
    //      0   1       2
    "SELECT ID, locale, Name FROM points_of_interest_locale"
);


// Steps to update the counter below without doing it 1 by 1 manually
// 1. Using Notepad++ copy the query from "SELECT" to last field
// 2. Run this regex
//  a.find     "\r\n[ ]+\/\/[ ]+[0-9]+
//  b.replace "\/\/
// 3. Alt + Left Click and vertical select all columns enough on the right of the file to be after // in all lines
// 4. Select "Edit" in the menu and then "Column Editor.."
// 5. Select "Number to Insert", Initial number 1, Increase by 1
// 6. Run this regex
//  a.find    "\/\/[ ]+
//  b.replace "\r\n\t\t\/\/ (not that there is a space at the end of the regex, it's needed)
LoadDataQuery LoadCreatureTemplatesQuery(
    //  0
    "SELECT entry,"
    //  1
    "difficulty_entry_1,"
    //  2
    "difficulty_entry_2,"
    //  3
    "difficulty_entry_3,"
    //  4
    "KillCredit1,"
    //  5
    "KillCredit2,"
    //  6
    "modelid1,"
    //  7
    "modelid2,"
    //  8
    "modelid3,"
    //  9
    "modelid4,"
    // 10
    "name,"
    // 11
    "subname,"
    // 12
    "IconName,"
    // 13
    "gossip_menu_id,"
    // 14
    "minlevel,"
    // 15
    "maxlevel,"
    // 16
    "exp,"
    // 17
    "faction,"
    // 18
    "npcflag,"
    // 19
    "speed_walk,"
    // 20
    "speed_run,"
    // 21
    "scale,"
    // 22
    "`rank`,"
    // 23
    "dmgschool,"
    // 24
    "BaseAttackTime,"
    // 25
    "RangeAttackTime,"
    // 26
    "BaseVariance,"
    // 27
    "RangeVariance,"
    // 28
    "unit_class,"
    // 29
    "unit_flags,"
    // 30
    "unit_flags2,"
    // 31
    "dynamicflags,"
    // 32
    "family,"
    // 33
    "type,"
    // 34
    "type_flags,"
    // 35
    "lootid,"
    // 36
    "pickpocketloot,"
    // 37
    "skinloot,"
    // 38
    "PetSpellDataId,"
    // 39
    "VehicleId,"
    // 40
    "mingold,"
    // 41
    "maxgold,"
    // 42
    "AIName,"
    // 43
    "MovementType,"
    // 44
    "ctm.Ground,"
    // 45
    "ctm.Swim,"
    // 46
    "ctm.Flight,"
    // 47
    "ctm.Rooted,"
    // 48
    "ctm.Chase,"
    // 49
    "ctm.Random,"
    // 50
    "ctm.InteractionPauseTimer,"
    // 51
    "HoverHeight,"
    // 52
    "HealthModifier,"
    // 53
    "ManaModifier,"
    // 54
    "ArmorModifier,"
    // 55
    "DamageModifier,"
    // 56
    "ExperienceModifier,"
    // 57
    "RacialLeader,"
    // 58
    "movementId,"
    // 59
    "RegenHealth,"
    // 60
    "mechanic_immune_mask,"
    // 61
    "spell_school_immune_mask,"
    // 62
    "flags_extra,"
    // 63
    "ScriptName"
    " FROM creature_template ct"
    " LEFT JOIN creature_template_movement ctm ON ct.entry = ctm.CreatureId");

LoadDataQuery LoadCreatureTemplateResistancesQuery(
    //      0           1       2
    "SELECT CreatureID, School, Resistance FROM creature_template_resistance"
);

LoadDataQuery LoadCreatureTemplateSpellsQuery(
    //      0           1        2
    "SELECT CreatureID, `Index`, Spell FROM creature_template_spell"
);

LoadDataQuery LoadCreatureTemplateAddonsQuery(
    //      0      1        2      3       4       5      6
    "SELECT entry, path_id, mount, bytes1, bytes2, emote, visibilityDistanceType, auras FROM creature_template_addon"
);

LoadDataQuery LoadCreatureAddonsQuery(
    //      0     1        2      3       4       5      6                       7
    "SELECT guid, path_id, mount, bytes1, bytes2, emote, visibilityDistanceType, auras FROM creature_addon"
);

LoadDataQuery LoadGameObjectAddonsQuery(
    "SELECT guid, parent_rotation0, parent_rotation1, parent_rotation2, parent_rotation3, invisibilityType, invisibilityValue FROM gameobject_addon"
);

LoadDataQuery LoadEquipmentTemplatesQuery(
    //      0           1   2        3        4
    "SELECT CreatureID, ID, ItemID1, ItemID2, ItemID3 FROM creature_equip_template"
);

LoadDataQuery LoadCreatureMovementOverridesQuery(
    "SELECT cmo.SpawnId,"
    "COALESCE(cmo.Ground, ctm.Ground),"
    "COALESCE(cmo.Swim, ctm.Swim),"
    "COALESCE(cmo.Flight, ctm.Flight),"
    "COALESCE(cmo.Rooted, ctm.Rooted),"
    "COALESCE(cmo.Chase, ctm.Chase),"
    "COALESCE(cmo.Random, ctm.Random),"
    "COALESCE(cmo.InteractionPauseTimer, ctm.InteractionPauseTimer) "
    "FROM creature_movement_override AS cmo "
    "LEFT JOIN creature AS c ON c.guid = cmo.SpawnId "
    "LEFT JOIN creature_template_movement AS ctm ON ctm.CreatureId = c.id"
);

LoadDataQuery LoadCreatureModelInfoQuery(
    //      0          1               2            3       4 
    "SELECT DisplayID, BoundingRadius, CombatReach, Gender, DisplayID_Other_Gender FROM creature_model_info"
);

LoadDataQuery LoadPlayerTotemModelsQuery(
    //      0          1       2
    "SELECT TotemSlot, RaceId, DisplayId from player_totem_model"
);

LoadDataQuery LoadLinkedRespawnQuery(
    //      0     1           2
    "SELECT guid, linkedGuid, linkType FROM linked_respawn ORDER BY guid ASC"
);

LoadDataQuery LoadTempSummonsQuery(
    //      0           1             2        3      4           5           6           7            8           9
    "SELECT summonerId, summonerType, groupId, entry, position_x, position_y, position_z, orientation, summonType, summonTime FROM creature_summon_groups"
);

LoadDataQuery LoadCreaturesQuery("SELECT creature.guid, id, map, position_x, position_y, position_z, orientation, modelid, equipment_id, spawntimesecs, wander_distance, "
    "currentwaypoint, curhealth, curmana, MovementType, spawnMask, phaseMask, eventEntry, poolSpawnId, creature.npcflag, creature.unit_flags, creature.dynamicflags, "
    "creature.ScriptName "
    "FROM creature "
    "LEFT OUTER JOIN game_event_creature ON creature.guid = game_event_creature.guid "
    "LEFT OUTER JOIN pool_members ON pool_members.type = 0 AND creature.guid = pool_members.spawnId");

LoadDataQuery LoadGameObjectsQuery("SELECT gameobject.guid, id, map, position_x, position_y, position_z, orientation, "
    //   7          8          9          10         11             12            13     14         15         16          17
    "rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state, spawnMask, phaseMask, eventEntry, poolSpawnId, "
    //   18
    "ScriptName "
    "FROM gameobject LEFT OUTER JOIN game_event_gameobject ON gameobject.guid = game_event_gameobject.guid "
    "LEFT OUTER JOIN pool_members ON pool_members.type = 1 AND gameobject.guid = pool_members.spawnId");

LoadDataQuery LoadSpawnGroupTemplatesQuery(
    //      0        1          2
    "SELECT groupId, groupName, groupFlags FROM spawn_group_template"
);

LoadDataQuery LoadSpawnGroupsQuery(
    //      0        1          2
    "SELECT groupId, spawnType, spawnId FROM spawn_group"
);

LoadDataQuery LoadInstanceSpawnGroupsQuery(
    //      0              1            2           3             4
    "SELECT instanceMapId, bossStateId, bossStates, spawnGroupId, flags FROM instance_spawn_groups"
);

LoadDataQuery LoadItemLocalesQuery(
    "SELECT ID, locale, Name, Description FROM item_template_locale"
);

LoadDataQuery LoadItemTemplatesQuery(
    "SELECT entry, class, subclass, SoundOverrideSubclass, name, displayid, Quality, Flags, FlagsExtra, BuyCount, BuyPrice, SellPrice, InventoryType, "
    "AllowableClass, AllowableRace, ItemLevel, RequiredLevel, RequiredSkill, RequiredSkillRank, requiredspell, requiredhonorrank, "
    "RequiredCityRank, RequiredReputationFaction, RequiredReputationRank, maxcount, stackable, ContainerSlots, StatsCount, stat_type1, "
    "stat_value1, stat_type2, stat_value2, stat_type3, stat_value3, stat_type4, stat_value4, stat_type5, stat_value5, stat_type6, "
    "stat_value6, stat_type7, stat_value7, stat_type8, stat_value8, stat_type9, stat_value9, stat_type10, stat_value10, "
    "ScalingStatDistribution, ScalingStatValue, dmg_min1, dmg_max1, dmg_type1, dmg_min2, dmg_max2, dmg_type2, armor, holy_res, fire_res, "
    "nature_res, frost_res, shadow_res, arcane_res, delay, ammo_type, RangedModRange, spellid_1, spelltrigger_1, spellcharges_1, "
    "spellppmRate_1, spellcooldown_1, spellcategory_1, spellcategorycooldown_1, spellid_2, spelltrigger_2, spellcharges_2, "
    "spellppmRate_2, spellcooldown_2, spellcategory_2, spellcategorycooldown_2, spellid_3, spelltrigger_3, spellcharges_3, "
    "spellppmRate_3, spellcooldown_3, spellcategory_3, spellcategorycooldown_3, spellid_4, spelltrigger_4, spellcharges_4, "
    "spellppmRate_4, spellcooldown_4, spellcategory_4, spellcategorycooldown_4, spellid_5, spelltrigger_5, spellcharges_5, "
    "spellppmRate_5, spellcooldown_5, spellcategory_5, spellcategorycooldown_5, bonding, description, PageText, LanguageID, PageMaterial, "
    "startquest, lockid, Material, sheath, RandomProperty, RandomSuffix, block, itemset, MaxDurability, area, Map, BagFamily, "
    "TotemCategory, socketColor_1, socketContent_1, socketColor_2, socketContent_2, socketColor_3, socketContent_3, socketBonus, "
    "GemProperties, RequiredDisenchantSkill, ArmorDamageModifier, duration, ItemLimitCategory, HolidayId, ScriptName, DisenchantID, "
    "FoodType, minMoneyLoot, maxMoneyLoot, flagsCustom FROM item_template");

LoadDataQuery LoadItemSetNameLocalesQuery(
    //      0   1       2
    "SELECT ID, locale, Name FROM item_set_names_locale"
);

LoadDataQuery LoadItemSetNamesQuery(
    //       0        1        2
    "SELECT `entry`, `name`, `InventoryType` FROM `item_set_names`"
);

LoadDataQuery LoadVehicleTemplateAccessoriesQuery(
    //       0        1                  2          3         4             5
    "SELECT `entry`, `accessory_entry`, `seat_id`, `minion`, `summontype`, `summontimer` FROM `vehicle_template_accessory`"
);

LoadDataQuery LoadVehicleTemplateQuery(
    //      0           1
    "SELECT creatureId, despawnDelayMs FROM vehicle_template"
);

LoadDataQuery LoadVehicleAccessoriesQuery(
    //       0       1                  2          3         4             5
    "SELECT `guid`, `accessory_entry`, `seat_id`, `minion`, `summontype`, `summontimer` FROM `vehicle_accessory`"
);

LoadDataQuery LoadVehicleSeatAddonQuery(
    //       0            1                  2             3             4             5             6
    "SELECT `SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue` FROM `vehicle_seat_addon`"
);

LoadDataQuery LoadPetLevelInfoQuery(
    //      0               1      2   3     4    5    6    7     8    9      10       11
    "SELECT creature_entry, level, hp, mana, str, agi, sta, inte, spi, armor, min_dmg, max_dmg FROM pet_levelstats"
);

LoadDataQuery LoadPlayerInfoQuery(
    //      0     1      2    3     4           5           6           7
    "SELECT race, class, map, zone, position_x, position_y, position_z, orientation FROM playercreateinfo"
);

LoadDataQuery LoadPlayerCreateInfoItemsQuery(
    //      0     1      2       3
    "SELECT race, class, itemid, amount FROM playercreateinfo_item"
);

LoadDataQuery LoadPlayerCreateInfoCreateSkillsQuery(
    //      0         1          2       3
    "SELECT raceMask, classMask, skill, `rank` FROM playercreateinfo_skills"
);

LoadDataQuery LoadPlayerCreateInfoSpellCustomQuery(
    //      0         1          2
    "SELECT racemask, classmask, Spell FROM playercreateinfo_spell_custom"
);

LoadDataQuery LoadPlayerCreateInfoCastSpellQuery(
    //      0         1          2
    "SELECT raceMask, classMask, spell FROM playercreateinfo_cast_spell"
);

LoadDataQuery LoadPlayerCreateInfoActionQuery(
    //      0     1      2       3
    "SELECT race, class, button, action, type FROM playercreateinfo_action"
);

LoadDataQuery LoadPlayerClassLevelStatsQuery(
    //      0      1      2       3
    "SELECT class, level, basehp, basemana FROM player_classlevelstats"
);

LoadDataQuery LoadPlayerLevelStatsQuery(
    //      0     1      2      3    4    5    6     7
    "SELECT race, class, level, str, agi, sta, inte, spi FROM player_levelstats"
);

LoadDataQuery LoadPlayerXPForLevelQuery(
    //      0      1
    "SELECT Level, Experience FROM player_xp_for_level"
);

LoadDataQuery LoadQuestsQuery(
    "SELECT "
    //0      1           2         3           4            5                6              7             8
    "ID, QuestType, QuestLevel, MinLevel, QuestSortID, QuestInfoID, SuggestedGroupNum, TimeAllowed, AllowableRaces,"
    //      9                     10                   11                    12
    "RequiredFactionId1, RequiredFactionId2, RequiredFactionValue1, RequiredFactionValue2, "
    //     13                 14               15             16                17               18            19            20
    "RewardNextQuest, RewardXPDifficulty, RewardMoney, RewardBonusMoney, RewardDisplaySpell, RewardSpell, RewardHonor, RewardKillHonor, "
    //   21       22        23              24                25               26
    "StartItem, Flags, RewardTitle, RequiredPlayerKills, RewardTalents, RewardArenaPoints, "
    //    27            28            29           30             31            32            33            34
    "RewardItem1, RewardAmount1, RewardItem2, RewardAmount2, RewardItem3, RewardAmount3, RewardItem4, RewardAmount4, "
    //        35                      36                      37                      38                      39                      40                      41                      42                      43                      44                     45                      46
    "RewardChoiceItemID1, RewardChoiceItemQuantity1, RewardChoiceItemID2, RewardChoiceItemQuantity2, RewardChoiceItemID3, RewardChoiceItemQuantity3, RewardChoiceItemID4, RewardChoiceItemQuantity4, RewardChoiceItemID5, RewardChoiceItemQuantity5, RewardChoiceItemID6, RewardChoiceItemQuantity6, "
    //       47                 48                     49                  50                  51                     52                 53                  54                     55                  56                  57                    58                   59                 60                      61
    "RewardFactionID1, RewardFactionValue1, RewardFactionOverride1, RewardFactionID2, RewardFactionValue2, RewardFactionOverride2, RewardFactionID3, RewardFactionValue3, RewardFactionOverride3, RewardFactionID4, RewardFactionValue4, RewardFactionOverride4, RewardFactionID5, RewardFactionValue5,  RewardFactionOverride5,"
    //    62        63    64       65
    "POIContinent, POIx, POIy, POIPriority, "
    //   66          67               68                69                70
    "LogTitle, LogDescription, QuestDescription, AreaDescription, QuestCompletionLog, "
    //      71                72                73                74                   75                     76                    77                      78
    "RequiredNpcOrGo1, RequiredNpcOrGo2, RequiredNpcOrGo3, RequiredNpcOrGo4, RequiredNpcOrGoCount1, RequiredNpcOrGoCount2, RequiredNpcOrGoCount3, RequiredNpcOrGoCount4, "
    //   79         80         81         82            83                 84                  85                86
    "ItemDrop1, ItemDrop2, ItemDrop3, ItemDrop4, ItemDropQuantity1, ItemDropQuantity2, ItemDropQuantity3, ItemDropQuantity4, "
    //      87               88               89               90               91               92                93                  94                  95                  96                  97                  98
    "RequiredItemId1, RequiredItemId2, RequiredItemId3, RequiredItemId4, RequiredItemId5, RequiredItemId6, RequiredItemCount1, RequiredItemCount2, RequiredItemCount3, RequiredItemCount4, RequiredItemCount5, RequiredItemCount6, "
    //  99          100             101             102             103
    "Unknown0, ObjectiveText1, ObjectiveText2, ObjectiveText3, ObjectiveText4"
    " FROM quest_template"
);

LoadDataQuery LoadQuestLocalesQuery(
    "SELECT ID, locale, Title, Details, Objectives, EndText, CompletedText, ObjectiveText1, ObjectiveText2, ObjectiveText3, ObjectiveText4 FROM quest_template_locale"
);

LoadDataQuery LoadSpellScriptNamesQuery(
    //      0         1
    "SELECT spell_id, ScriptName FROM spell_script_names"
);

LoadDataQuery LoadPageTextsQuery(
    "SELECT ID, `Text`, NextPageID FROM page_text"
);

LoadDataQuery LoadPageTextLocalesQuery(
    "SELECT ID, locale, `Text` FROM page_text_locale"
);

LoadDataQuery LoadInstanceTemplateQuery(
    "SELECT map, parent, script, allowMount FROM instance_template"
);

LoadDataQuery LoadInstanceEncountersQuery(
    "SELECT entry, creditType, creditEntry, lastEncounterDungeon FROM instance_encounters"
);

LoadDataQuery LoadGossipTextQuery(
    "SELECT ID, "
    "text0_0, text0_1, BroadcastTextID0, lang0, Probability0, EmoteDelay0_0, Emote0_0, EmoteDelay0_1, Emote0_1, EmoteDelay0_2, Emote0_2, "
    "text1_0, text1_1, BroadcastTextID1, lang1, Probability1, EmoteDelay1_0, Emote1_0, EmoteDelay1_1, Emote1_1, EmoteDelay1_2, Emote1_2, "
    "text2_0, text2_1, BroadcastTextID2, lang2, Probability2, EmoteDelay2_0, Emote2_0, EmoteDelay2_1, Emote2_1, EmoteDelay2_2, Emote2_2, "
    "text3_0, text3_1, BroadcastTextID3, lang3, Probability3, EmoteDelay3_0, Emote3_0, EmoteDelay3_1, Emote3_1, EmoteDelay3_2, Emote3_2, "
    "text4_0, text4_1, BroadcastTextID4, lang4, Probability4, EmoteDelay4_0, Emote4_0, EmoteDelay4_1, Emote4_1, EmoteDelay4_2, Emote4_2, "
    "text5_0, text5_1, BroadcastTextID5, lang5, Probability5, EmoteDelay5_0, Emote5_0, EmoteDelay5_1, Emote5_1, EmoteDelay5_2, Emote5_2, "
    "text6_0, text6_1, BroadcastTextID6, lang6, Probability6, EmoteDelay6_0, Emote6_0, EmoteDelay6_1, Emote6_1, EmoteDelay6_2, Emote6_2, "
    "text7_0, text7_1, BroadcastTextID7, lang7, Probability7, EmoteDelay7_0, Emote7_0, EmoteDelay7_1, Emote7_1, EmoteDelay7_2, Emote7_2 "
    "FROM npc_text"
);

LoadDataQuery LoadNpcTextLocalesQuery(
    "SELECT ID, Locale, "
    "Text0_0, Text0_1, Text1_0, Text1_1, Text2_0, Text2_1, Text3_0, Text3_1, Text4_0, Text4_1, Text5_0, Text5_1, Text6_0, Text6_1, Text7_0, Text7_1 "
    "FROM npc_text_locale"
);

LoadDataQuery LoadQuestAreaTriggersQuery(
    "SELECT id, quest FROM areatrigger_involvedrelation"
);

LoadDataQuery LoadQuestGreetingsQuery(
    "SELECT ID, Type, GreetEmoteType, GreetEmoteDelay, Greeting FROM quest_greeting"
);

LoadDataQuery LoadQuestGreetingLocalesQuery(
    "SELECT ID, Type, Locale, Greeting FROM quest_greeting_locale"
);

LoadDataQuery LoadQuestOfferRewardLocaleQuery(
    "SELECT Id, locale, RewardText FROM quest_offer_reward_locale"
);

LoadDataQuery LoadQuestRequestItemsLocaleQuery(
    "SELECT Id, locale, CompletionText FROM quest_request_items_locale"
);

LoadDataQuery LoadAreaTriggersQuery(
    "SELECT id FROM areatrigger_tavern"
);

LoadDataQuery LoadAreaTriggerScriptsQuery(
    "SELECT entry, ScriptName FROM areatrigger_scripts"
);

LoadDataQuery LoadGraveyardZonesQuery(
    "SELECT ID, GhostZone, Faction FROM graveyard_zone"
);

LoadDataQuery LoadAreaTriggerTeleportsQuery(
    "SELECT ID,  target_map, target_position_x, target_position_y, target_position_z, target_orientation FROM areatrigger_teleport"
);

LoadDataQuery LoadAccessRequirementsQuery(
    "SELECT mapid, difficulty, level_min, level_max, item_level, item, item2, quest_done_A, quest_done_H, completed_achievement, quest_failed_text FROM access_requirement"
);

LoadDataQuery LoadSelectmaxTransport(
    "SELECT MAX(guid) FROM transports"
);

LoadDataQuery LoadSelectMaxCreatures(
    "SELECT MAX(guid) FROM creature"
);

LoadDataQuery LoadSelectMaxGameObject(
    "SELECT MAX(guid) FROM gameobject"
);

LoadDataQuery LoadGameObjectLocaleQuery(
    "SELECT entry, locale, name, castBarCaption FROM gameobject_template_locale"
);

LoadDataQuery LoadGameObjectTemplateQuery(
    //          1      2     3          4     5         6               7     8
    "SELECT entry, type, displayId, name, IconName, castBarCaption, unk1, size, "
    //   8      9      10     11     12     13     14     15     16     17     18      19      20
    "Data0, Data1, Data2, Data3, Data4, Data5, Data6, Data7, Data8, Data9, Data10, Data11, Data12, "
    //   21      22      23      24      25      26      27      28      29      30      31      32      33
    "Data13, Data14, Data15, Data16, Data17, Data18, Data19, Data20, Data21, Data22, Data23, AIName, ScriptName "
    "FROM gameobject_template"

);

LoadDataQuery LoadGameObjectTemplateAddonsQuery(
    "SELECT entry, faction, flags, mingold, maxgold, artkit0, artkit1, artkit2, artkit3 FROM gameobject_template_addon"
);

LoadDataQuery LoadGameObjectOverridesQuery(
    "SELECT spawnId, faction, flags FROM gameobject_overrides"
);

LoadDataQuery LoadExplorationBaseXPQuery(
    "SELECT level, basexp FROM exploration_basexp"
);

LoadDataQuery LoadPetNamesQuery(
    "SELECT word, entry, half FROM pet_name_generation"
);

LoadDataQuery LoadReputationRewardRateQuery(
    "SELECT faction, quest_rate, quest_daily_rate, quest_weekly_rate, quest_monthly_rate, quest_repeatable_rate, creature_rate, spell_rate FROM reputation_reward_rate"
);

LoadDataQuery LoadReputationOnKillQuery(
    "SELECT creature_id, RewOnKillRepFaction1, RewOnKillRepFaction2, "
    "IsTeamAward1, MaxStanding1, RewOnKillRepValue1, IsTeamAward2, MaxStanding2, RewOnKillRepValue2, TeamDependent "
    "FROM creature_onkill_reputation"
);

LoadDataQuery LoadReputationSpilloverTemplateQuery(
    "SELECT faction, faction1, rate_1, rank_1, faction2, rate_2, rank_2, faction3, rate_3, rank_3, faction4, rate_4, rank_4 FROM reputation_spillover_template"
);

LoadDataQuery LoadPointsOfInterestQuery(
    "SELECT ID, PositionX, PositionY, Icon, Flags, Importance, Name FROM points_of_interest"
);

LoadDataQuery LoadQuestPOIQuery(
    "SELECT QuestID, id, ObjectiveIndex, MapID, WorldMapAreaId, Floor, Priority, Flags FROM quest_poi"
);

LoadDataQuery LoadQuestPOIPointsQuery(
    "SELECT QuestID, Idx1, X, Y FROM quest_poi_points ORDER BY QuestID DESC, Idx2"
);

LoadDataQuery LoadNPCSpellClickSpellsQuery(
    "SELECT npc_entry, spell_id, cast_flags, user_type FROM npc_spellclick_spells"
);

LoadDataQuery LoadTrinityStringsQuery(
    "SELECT entry, content_default, content_loc1, content_loc2, content_loc3, content_loc4, content_loc5, content_loc6, content_loc7, content_loc8 FROM trinity_string"
);

LoadDataQuery LoadFishingBaseSkillLevelQuery(
    "SELECT entry, skill FROM skill_fishing_base_level"
);

LoadDataQuery LoadGameTeleQuery(
    "SELECT id, position_x, position_y, position_z, orientation, map, name FROM game_tele"
);

LoadDataQuery LoadMailLevelRewardsQuery(
    "SELECT level, raceMask, mailTemplateId, senderEntry FROM mail_level_reward"
);

LoadDataQuery LoadTrainerSpellQuery(
    "SELECT TrainerId, SpellId, MoneyCost, ReqSkillLine, ReqSkillRank, ReqAbility1, ReqAbility2, ReqAbility3, ReqLevel FROM trainer_spell"
);

LoadDataQuery LoadTrainerQuery(
    "SELECT Id, Type, Requirement, Greeting FROM trainer"
);

LoadDataQuery LoadTrainerLocaleQuery(
    "SELECT Id, locale, Greeting_lang FROM trainer_locale"
);

LoadDataQuery LoadCreatureDefaultTrainersQuery(
    "SELECT CreatureId, TrainerId FROM creature_default_trainer"
);

LoadDataQuery LoadVendorsQuery(
    "SELECT entry, item, maxcount, incrtime, ExtendedCost FROM npc_vendor ORDER BY entry, slot ASC"
);

LoadDataQuery LoadGossipMenuQuery(
    "SELECT MenuID, TextID FROM gossip_menu"
);

LoadDataQuery LoadGossipMenuItemsQuery(
    "SELECT MenuID, OptionID, OptionIcon, OptionText, OptionBroadcastTextID, OptionType, OptionNpcFlag, ActionMenuID, ActionPoiID, BoxCoded, BoxMoney, BoxText, BoxBroadcastTextID "
    "FROM gossip_menu_option ORDER BY MenuID, OptionID"
);

LoadDataQuery LoadScriptNamesQuery(
    "SELECT DISTINCT(ScriptName) FROM achievement_criteria_data WHERE ScriptName <> '' AND type = 11 "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM battlefield_template WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM battleground_template WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM creature WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM creature_template WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM gameobject WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM gameobject_template WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM item_template WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM areatrigger_scripts WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM spell_script_names WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM transports WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM game_weather WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM conditions WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(ScriptName) FROM outdoorpvp_template WHERE ScriptName <> '' "
    "UNION "
    "SELECT DISTINCT(script) FROM instance_template WHERE script <> ''"
);

LoadDataQuery LoadBroadcastTextQuery("SELECT ID, LanguageID, `Text`, Text1, EmoteID1, EmoteID2, EmoteID3, EmoteDelay1, EmoteDelay2, EmoteDelay3, SoundEntriesID, EmotesID, Flags FROM broadcast_text");

LoadDataQuery LoadBroadcastTextsLocaleQuery("SELECT ID, locale, `Text`, Text1 FROM broadcast_text_locale");

LoadDataQuery LoadCreatureClassLevelStatsQuery(
    "SELECT level, class, basehp0, basehp1, basehp2, basemana, basearmor, attackpower, rangedattackpower, damage_base, damage_exp1, damage_exp2 FROM creature_classlevelstats"
);

LoadDataQuery LoadFactionChangeAchievementsQuery(
    "SELECT alliance_id, horde_id FROM player_factionchange_achievement"
);

LoadDataQuery LoadFactionChangeItemsQuery(
    "SELECT alliance_id, horde_id FROM player_factionchange_items"
);

LoadDataQuery LoadFactionChangeQuestsQuery(
    "SELECT alliance_id, horde_id FROM player_factionchange_quests"
);

LoadDataQuery LoadFactionChangeReputationsQuery(
    "SELECT alliance_id, horde_id FROM player_factionchange_reputations"
);

LoadDataQuery LoadFactionChangeSpellsQuery(
    "SELECT alliance_id, horde_id FROM player_factionchange_spells"
);

LoadDataQuery LoadFactionChangeTitlesQuery(
    "SELECT alliance_id, horde_id FROM player_factionchange_titles"
);

LoadDataQuery LoadGameObjectQuestItemsQuery(
    "SELECT GameObjectEntry, ItemId, Idx FROM gameobject_questitem ORDER BY Idx ASC"
);

LoadDataQuery LoadCreatureQuestItemsQuery(
    "SELECT CreatureEntry, ItemId, Idx FROM creature_questitem ORDER BY Idx ASC"
);


// AchievementMgr

LoadDataQuery LoadAchievementCriteriaDataQuery(
    "SELECT criteria_id, type, value1, value2, ScriptName FROM achievement_criteria_data"
);

LoadDataQuery LoadAchievementRewardsQuery(
    "SELECT ID, TitleA, TitleH, ItemID, Sender, Subject, Body, MailTemplateID FROM achievement_reward"
);

LoadDataQuery LoadAchievementRewardLocalesQuery(
    "SELECT ID, Locale, Subject, Body FROM achievement_reward_locale"
);


// BattlefieldMgr

LoadDataQuery LoadBattlefieldQuery(
    "SELECT TypeId, ScriptName FROM battlefield_template"
);

// BattlegroundMgr
LoadDataQuery LoadBattlegroundTemplateQuery(
    "SELECT ID, MinPlayersPerTeam, MaxPlayersPerTeam, MinLvl, MaxLvl, AllianceStartLoc, AllianceStartO, HordeStartLoc, HordeStartO, StartMaxDist, Weight, ScriptName FROM battleground_template"
);

LoadDataQuery LoadBattlemasterEntryQuery(
    "SELECT entry, bg_template FROM battlemaster_entry"
);

// Conditions
LoadDataQuery LoadConditionsQuery(
    "SELECT SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, "
    " ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName FROM conditions"
);

// DisablesMgr
LoadDataQuery LoadDisablesQueryQuery(
    "SELECT sourceType, entry, flags, params_0, params_1 FROM disables"
);

// LFGMgr
LoadDataQuery LFGLoadRewardsQuery(
    "SELECT dungeonId, maxLevel, firstQuestId, otherQuestId FROM lfg_dungeon_rewards ORDER BY dungeonId, maxLevel ASC"
);

LoadDataQuery LFGLoadDungeonTemplateQuery(
    "SELECT dungeonId, position_x, position_y, position_z, orientation FROM lfg_dungeon_template"
);

// CreatureGroups

LoadDataQuery LoadCreatureFormationsQuery(
    "SELECT leaderGUID, memberGUID, dist, angle, groupAI, point_1, point_2 FROM creature_formations ORDER BY leaderGUID"
);

// ItemEnchantmentMgr
LoadDataQuery LoadRandomEnchantmentsTableQuery(
    "SELECT entry, ench, chance FROM item_enchantment_template"
);

// GameEventMgr
LoadDataQuery LoadGameEventsQuery(
    "SELECT eventEntry, UNIX_TIMESTAMP(start_time), UNIX_TIMESTAMP(end_time), occurence, length, holiday, holidayStage, description, world_event, announce FROM game_event"
);

LoadDataQuery LoadGameEventPrerequisiteQuery(
    "SELECT eventEntry, prerequisite_event FROM game_event_prerequisite"
);

LoadDataQuery LoadGameEventCreaturesQuery(
    "SELECT guid, eventEntry FROM game_event_creature"
);

LoadDataQuery LoadGameEventGameObjectsQuery(
    "SELECT guid, eventEntry FROM game_event_gameobject"
);

LoadDataQuery LoadGameEventDisplayChangeQuery(
    "SELECT creature.guid, creature.id, game_event_model_equip.eventEntry, game_event_model_equip.modelid, game_event_model_equip.equipment_id "
    "FROM creature JOIN game_event_model_equip ON creature.guid = game_event_model_equip.guid"
);

LoadDataQuery LoadGameEventCreatureQuestQuery(
    "SELECT id, quest, eventEntry FROM game_event_creature_quest"
);

LoadDataQuery LoadGameEventGameObjectQuestQuery(
    "SELECT id, quest, eventEntry FROM game_event_gameobject_quest"
);

LoadDataQuery LoadGameObjectQuestConditionQuery(
    "SELECT quest, eventEntry, condition_id, num FROM game_event_quest_condition"
);

LoadDataQuery LoadGameEventConditionQuery(
    "SELECT eventEntry, condition_id, req_num, max_world_state_field, done_world_state_field FROM game_event_condition"
);

LoadDataQuery LoadGameEventNPCFlagQuery(
    "SELECT guid, eventEntry, npcflag FROM game_event_npcflag"
);

LoadDataQuery LoadGameEventSeasonalQuestRelationQuery(
    "SELECT questId, eventEntry FROM game_event_seasonal_questrelation"
);


LoadDataQuery LoadGameEventNPCVendorQuery(
    "SELECT eventEntry, guid, item, maxcount, incrtime, ExtendedCost FROM game_event_npc_vendor ORDER BY guid, slot ASC"
);

LoadDataQuery LoadGameEventBattlegroundHolidayQuery(
    "SELECT EventEntry, BattlegroundID FROM game_event_battleground_holiday"
);

LoadDataQuery LoadGameEventPoolsQuery(
    "SELECT pool_template.entry, game_event_pool.eventEntry FROM pool_template"
    " JOIN game_event_pool ON pool_template.entry = game_event_pool.pool_entry"
);

LoadDataQuery LoadHolidayDatesQuery(
    "SELECT id, date_id, date_value, holiday_duration FROM holiday_dates"
);

LoadDataQuery LoadGameEventMaxEntryQuery(
    "SELECT MAX(eventEntry) FROM game_event"
);

// TransportMgr

LoadDataQuery LoadTransportTemplatesQuery(
    "SELECT entry FROM gameobject_template WHERE type = 15 ORDER BY entry ASC"
);

LoadDataQuery LoadTransportsQuery(
    "SELECT guid, entry FROM transports"
);

// WaypointMgr

LoadDataQuery LoadWaypointsQuery(
    "SELECT id, point, position_x, position_y, position_z, orientation, move_type, delay, action, action_chance FROM waypoint_data ORDER BY id, point"
);

// OutdoorPvPMgr

LoadDataQuery LoadOutdoorPVPTemplatesQuery(
    "SELECT TypeId, ScriptName FROM outdoorpvp_template"
);

// PoolMgr
LoadDataQuery LoadPoolTemplatesQuery(
    "SELECT entry, max_limit FROM pool_template"
);

LoadDataQuery LoadPoolCreatureMembersQuery(
    "SELECT spawnId, poolSpawnId, chance FROM pool_members WHERE type = 0"
);

LoadDataQuery LoadPoolGameObjectMembersQuery(
    "SELECT spawnId, poolSpawnId, chance FROM pool_members WHERE type = 1"
);

LoadDataQuery LoadPoolMotherMembersQuery(
    "SELECT spawnId, poolSpawnId, chance FROM pool_members WHERE type = 2"
);

LoadDataQuery LoadPoolHandlingQuery(
    "SELECT DISTINCT pool_template.entry, pool_members.spawnId, pool_members.poolSpawnId FROM pool_template"
    " LEFT JOIN game_event_pool ON pool_template.entry = game_event_pool.pool_entry"
    " LEFT JOIN pool_members ON pool_members.type = 2 AND pool_template.entry = pool_members.spawnId WHERE game_event_pool.pool_entry IS NULL"
);

// QuestPoolsMgr
LoadDataQuery LoadQuestPoolsQuery(
    "SELECT qpm.questId, qpm.poolId, qpm.poolIndex, qpt.numActive FROM quest_pool_members qpm LEFT JOIN quest_pool_template qpt ON qpm.poolId = qpt.poolId"
);

// ScriptSystem
LoadDataQuery LoadScriptWaypointCountQuery(
    "SELECT COUNT(entry) FROM script_waypoint GROUP BY entry"
);

LoadDataQuery LoadScriptWaypointsQuery(
    "SELECT entry, pointid, location_x, location_y, location_z, waittime FROM script_waypoint ORDER BY pointid"
);

LoadDataQuery LoadScriptSplineChainMetaQuery(
    "SELECT entry, chainId, splineId, expectedDuration, msUntilNext, velocity FROM script_spline_chain_meta ORDER BY entry asc, chainId asc, splineId asc"
);

LoadDataQuery LoadScriptSplineChainWaypointsQuery(
    "SELECT entry, chainId, splineId, wpId, x, y, z FROM script_spline_chain_waypoints ORDER BY entry asc, chainId asc, splineId asc, wpId asc"
);

LoadDataQuery LoadSkillDiscoveryTemplateQuery(
    "SELECT spellId, reqSpell, reqSkillValue, chance FROM skill_discovery_template"
);

LoadDataQuery LoadSkillPerfectItemTemplateQuery(
    "SELECT spellId, requiredSpecialization, perfectCreateChance, perfectItemType FROM skill_perfect_item_template"
);

LoadDataQuery LoadSkillExtraItemTemplateQuery(
    "SELECT spellId, requiredSpecialization, additionalCreateChance, additionalMaxNum FROM skill_extra_item_template"
);

// SpellMgr

LoadDataQuery LoadSpellRanksQuery(
    "SELECT first_spell_id, spell_id, `rank` from spell_ranks ORDER BY first_spell_id, `rank`"
);

LoadDataQuery LoadSpellRequiredQuery(
    "SELECT spell_id, req_spell from spell_required"
);

LoadDataQuery LoadSpellLearnSpellsQuery(
    "SELECT entry, SpellID, Active FROM spell_learn_spell"
);

LoadDataQuery LoadSpellTargetPositionQuery(
    "SELECT ID, EffectIndex, MapID, PositionX, PositionY, PositionZ, Orientation FROM spell_target_position"
);

LoadDataQuery LoadSpellGroupsQuery(
    "SELECT id, spell_id FROM spell_group"
);

LoadDataQuery LoadSpellGroupStackRulesQuery(
    "SELECT group_id, stack_rule FROM spell_group_stack_rules"
);

LoadDataQuery LoadSpellProcsQuery(
    "SELECT SpellId, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, "
    "ProcFlags, SpellTypeMask, SpellPhaseMask, HitMask, AttributesMask, DisableEffectsMask, ProcsPerMinute, Chance, Cooldown, Charges FROM spell_proc"
);

LoadDataQuery LoadSpellBonusesQuery(
    "SELECT entry, direct_bonus, dot_bonus, ap_bonus, ap_dot_bonus FROM spell_bonus_data"
);

LoadDataQuery LoadSpellThreatsQuery(
    "SELECT entry, flatMod, pctMod, apPctMod FROM spell_threat"
);

LoadDataQuery LoadSpellPetAurasQuery(
    "SELECT spell, effectId, pet, aura FROM spell_pet_auras"
);

LoadDataQuery LoadSpellEnchantProcDataQuery(
    "SELECT EnchantID, Chance, ProcsPerMinute, HitMask, AttributesMask FROM spell_enchant_proc_data"
);

LoadDataQuery LoadSpellLinkedQuery(
    "SELECT spell_trigger, spell_effect, type FROM spell_linked_spell"
);

LoadDataQuery LoadSpellAreasQuery(
    "SELECT spell, area, quest_start, quest_start_status, quest_end_status, quest_end, aura_spell, racemask, gender, autocast FROM spell_area"
);

LoadDataQuery LoadSpellInfoCustomAttributesQuery(
    "SELECT entry, attributes FROM spell_custom_attr"
);

// CreatureTextMgr

LoadDataQuery LoadCreatureTextLocalesQuery(
    "SELECT CreatureID, GroupID, ID, Locale, Text FROM creature_text_locale"
);

LoadDataQuery LoadMaxWardenChecksQuery(
    "SELECT MAX(id) FROM warden_checks"
);

LoadDataQuery LoadWardenChecksQuery(
    "SELECT id, type, data, result, address, length, str, comment FROM warden_checks ORDER BY id ASC"
);

// WeatherMgr

LoadDataQuery LoadWeatherDataQuery(
    "SELECT "
    "zone, spring_rain_chance, spring_snow_chance, spring_storm_chance,"
    "summer_rain_chance, summer_snow_chance, summer_storm_chance,"
    "fall_rain_chance, fall_snow_chance, fall_storm_chance,"
    "winter_rain_chance, winter_snow_chance, winter_storm_chance,"
    "ScriptName FROM game_weather"
);

LoadDataQuery LoadSmartScriptsQuery(
    "SELECT entryorguid, source_type, id, link, event_type, event_phase_mask, event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, event_param5, action_type, action_param1, action_param2, action_param3, action_param4, action_param5, action_param6, target_type, target_param1, target_param2, target_param3, target_param4, target_x, target_y, target_z, target_o FROM smart_scripts ORDER BY entryorguid, source_type, id, link"
);

LoadDataQuery LoadCreatureTextQuery
(
    "SELECT CreatureID, GroupID, ID, Text, Type, Language, Probability, Emote, Duration, Sound, BroadcastTextId, TextRange FROM creature_text"
);

static LoadDataQuery LootTemplateQuery(std::string const& name)
{
    return LoadDataQuery("SELECT Entry, Item, Reference, Chance, QuestRequired, LootMode, GroupId, MinCount, MaxCount FROM " + name);
}

static LoadDataQuery LoadCreatureTemplateQuery = LootTemplateQuery("creature_loot_template");
static LoadDataQuery LoadFishingLootTemplate = LootTemplateQuery("fishing_loot_template");
static LoadDataQuery LoadGameObjectLootTemplate = LootTemplateQuery("gameobject_loot_template");
static LoadDataQuery LoadItemLootTemplate = LootTemplateQuery("item_loot_template");
static LoadDataQuery LoadMailLootTemplate = LootTemplateQuery("mail_loot_template");
static LoadDataQuery LoadMillingLootTemplate = LootTemplateQuery("milling_loot_template");
static LoadDataQuery LoadPickpocketingLootTemplate = LootTemplateQuery("pickpocketing_loot_template");
static LoadDataQuery LoadSkinningLootTemplate = LootTemplateQuery("skinning_loot_template");
static LoadDataQuery LoadDisenchantLootTemplate = LootTemplateQuery("disenchant_loot_template");
static LoadDataQuery LoadProspectingLootTemplate = LootTemplateQuery("prospecting_loot_template");
static LoadDataQuery LoadSpellLootTemplate = LootTemplateQuery("spell_loot_template");
static LoadDataQuery LoadReferenceLootTemplate = LootTemplateQuery("reference_loot_template");

std::unordered_map<std::string, LoadDataQuery*> LoadLootTemplateQueries = {
    {"creature_loot_template",&LoadCreatureTemplateQuery},
    {"fishing_loot_template",&LoadFishingLootTemplate},
    {"gameobject_loot_template",&LoadGameObjectLootTemplate},
    {"item_loot_template",&LoadItemLootTemplate},
    {"mail_loot_template",&LoadMailLootTemplate},
    {"milling_loot_template",&LoadMillingLootTemplate},
    {"pickpocketing_loot_template",&LoadPickpocketingLootTemplate},
    {"skinning_loot_template",&LoadSkinningLootTemplate},
    {"disenchant_loot_template",&LoadDisenchantLootTemplate},
    {"prospecting_loot_template",&LoadProspectingLootTemplate},
    {"spell_loot_template",&LoadSpellLootTemplate},
    {"reference_loot_template",&LoadReferenceLootTemplate},
};

void LoadDataQuery::StartAllAsyncQueries()
{
    ASSERT(asyncQueries.size() == 0);
    asyncQueries.push_back(&LoadCreatureTemplateQuery);
    asyncQueries.push_back(&LoadFishingLootTemplate);
    asyncQueries.push_back(&LoadGameObjectLootTemplate);
    asyncQueries.push_back(&LoadItemLootTemplate);
    asyncQueries.push_back(&LoadMailLootTemplate);
    asyncQueries.push_back(&LoadMillingLootTemplate);
    asyncQueries.push_back(&LoadPickpocketingLootTemplate);
    asyncQueries.push_back(&LoadSkinningLootTemplate);
    asyncQueries.push_back(&LoadDisenchantLootTemplate);
    asyncQueries.push_back(&LoadProspectingLootTemplate);
    asyncQueries.push_back(&LoadSpellLootTemplate);
    asyncQueries.push_back(&LoadReferenceLootTemplate);

    asyncQueries.push_back(&LoadCreatureLocaleQuery);
    asyncQueries.push_back(&LoadGossipMenuItemsLocalesQuery);
    asyncQueries.push_back(&LoadPointOfInterestLocalesQuery);
    asyncQueries.push_back(&LoadCreatureTemplatesQuery);
    asyncQueries.push_back(&LoadCreatureTemplateResistancesQuery);
    asyncQueries.push_back(&LoadCreatureTemplateSpellsQuery);
    asyncQueries.push_back(&LoadCreatureTemplateAddonsQuery);
    asyncQueries.push_back(&LoadCreatureAddonsQuery);
    asyncQueries.push_back(&LoadGameObjectAddonsQuery);
    asyncQueries.push_back(&LoadEquipmentTemplatesQuery);
    asyncQueries.push_back(&LoadCreatureMovementOverridesQuery);
    asyncQueries.push_back(&LoadCreatureModelInfoQuery);
    asyncQueries.push_back(&LoadPlayerTotemModelsQuery);
    asyncQueries.push_back(&LoadLinkedRespawnQuery);
    asyncQueries.push_back(&LoadTempSummonsQuery);
    asyncQueries.push_back(&LoadCreaturesQuery);
    asyncQueries.push_back(&LoadGameObjectsQuery);
    asyncQueries.push_back(&LoadSpawnGroupTemplatesQuery);
    asyncQueries.push_back(&LoadSpawnGroupsQuery);
    asyncQueries.push_back(&LoadInstanceSpawnGroupsQuery);
    asyncQueries.push_back(&LoadItemLocalesQuery);
    asyncQueries.push_back(&LoadItemTemplatesQuery);
    asyncQueries.push_back(&LoadItemSetNameLocalesQuery);
    asyncQueries.push_back(&LoadItemSetNamesQuery);
    asyncQueries.push_back(&LoadVehicleTemplateAccessoriesQuery);
    asyncQueries.push_back(&LoadVehicleTemplateQuery);
    asyncQueries.push_back(&LoadVehicleAccessoriesQuery);
    asyncQueries.push_back(&LoadVehicleSeatAddonQuery);
    asyncQueries.push_back(&LoadPetLevelInfoQuery);
    asyncQueries.push_back(&LoadPlayerInfoQuery);
    asyncQueries.push_back(&LoadPlayerCreateInfoItemsQuery);
    asyncQueries.push_back(&LoadPlayerCreateInfoCreateSkillsQuery);
    asyncQueries.push_back(&LoadPlayerCreateInfoSpellCustomQuery);
    asyncQueries.push_back(&LoadPlayerCreateInfoCastSpellQuery);
    asyncQueries.push_back(&LoadPlayerCreateInfoActionQuery);
    asyncQueries.push_back(&LoadPlayerClassLevelStatsQuery);
    asyncQueries.push_back(&LoadPlayerLevelStatsQuery);
    asyncQueries.push_back(&LoadPlayerXPForLevelQuery);
    asyncQueries.push_back(&LoadQuestsQuery);
    asyncQueries.push_back(&LoadQuestLocalesQuery);
    asyncQueries.push_back(&LoadSpellScriptNamesQuery);
    asyncQueries.push_back(&LoadPageTextsQuery);
    asyncQueries.push_back(&LoadPageTextLocalesQuery);
    asyncQueries.push_back(&LoadInstanceTemplateQuery);
    asyncQueries.push_back(&LoadInstanceEncountersQuery);
    asyncQueries.push_back(&LoadGossipTextQuery);
    asyncQueries.push_back(&LoadNpcTextLocalesQuery);
    asyncQueries.push_back(&LoadQuestAreaTriggersQuery);
    asyncQueries.push_back(&LoadQuestGreetingsQuery);
    asyncQueries.push_back(&LoadQuestGreetingLocalesQuery);
    asyncQueries.push_back(&LoadQuestOfferRewardLocaleQuery);
    asyncQueries.push_back(&LoadQuestRequestItemsLocaleQuery);
    asyncQueries.push_back(&LoadAreaTriggersQuery);
    asyncQueries.push_back(&LoadAreaTriggerScriptsQuery);
    asyncQueries.push_back(&LoadGraveyardZonesQuery);
    asyncQueries.push_back(&LoadAreaTriggerTeleportsQuery);
    asyncQueries.push_back(&LoadAccessRequirementsQuery);
    asyncQueries.push_back(&LoadSelectmaxTransport);
    asyncQueries.push_back(&LoadSelectMaxCreatures);
    asyncQueries.push_back(&LoadSelectMaxGameObject);
    asyncQueries.push_back(&LoadGameObjectLocaleQuery);
    asyncQueries.push_back(&LoadGameObjectTemplateQuery);
    asyncQueries.push_back(&LoadGameObjectTemplateAddonsQuery);
    asyncQueries.push_back(&LoadGameObjectOverridesQuery);
    asyncQueries.push_back(&LoadExplorationBaseXPQuery);
    asyncQueries.push_back(&LoadPetNamesQuery);
    asyncQueries.push_back(&LoadReputationRewardRateQuery);
    asyncQueries.push_back(&LoadReputationOnKillQuery);
    asyncQueries.push_back(&LoadReputationSpilloverTemplateQuery);
    asyncQueries.push_back(&LoadPointsOfInterestQuery);
    asyncQueries.push_back(&LoadQuestPOIQuery);
    asyncQueries.push_back(&LoadQuestPOIPointsQuery);
    asyncQueries.push_back(&LoadNPCSpellClickSpellsQuery);
    asyncQueries.push_back(&LoadTrinityStringsQuery);
    asyncQueries.push_back(&LoadFishingBaseSkillLevelQuery);
    asyncQueries.push_back(&LoadGameTeleQuery);
    asyncQueries.push_back(&LoadMailLevelRewardsQuery);
    asyncQueries.push_back(&LoadTrainerSpellQuery);
    asyncQueries.push_back(&LoadTrainerQuery);
    asyncQueries.push_back(&LoadTrainerLocaleQuery);
    asyncQueries.push_back(&LoadCreatureDefaultTrainersQuery);
    asyncQueries.push_back(&LoadVendorsQuery);
    asyncQueries.push_back(&LoadGossipMenuQuery);
    asyncQueries.push_back(&LoadGossipMenuItemsQuery);
    asyncQueries.push_back(&LoadScriptNamesQuery);
    asyncQueries.push_back(&LoadBroadcastTextQuery);
    asyncQueries.push_back(&LoadBroadcastTextsLocaleQuery);
    asyncQueries.push_back(&LoadCreatureClassLevelStatsQuery);
    asyncQueries.push_back(&LoadFactionChangeAchievementsQuery);
    asyncQueries.push_back(&LoadFactionChangeItemsQuery);
    asyncQueries.push_back(&LoadFactionChangeQuestsQuery);
    asyncQueries.push_back(&LoadFactionChangeReputationsQuery);
    asyncQueries.push_back(&LoadFactionChangeSpellsQuery);
    asyncQueries.push_back(&LoadFactionChangeTitlesQuery);
    asyncQueries.push_back(&LoadGameObjectQuestItemsQuery);
    asyncQueries.push_back(&LoadCreatureQuestItemsQuery);
    asyncQueries.push_back(&LoadAchievementCriteriaDataQuery);
    asyncQueries.push_back(&LoadAchievementRewardsQuery);
    asyncQueries.push_back(&LoadAchievementRewardLocalesQuery);
    asyncQueries.push_back(&LoadBattlefieldQuery);
    asyncQueries.push_back(&LoadBattlegroundTemplateQuery);
    asyncQueries.push_back(&LoadBattlemasterEntryQuery);
    asyncQueries.push_back(&LoadConditionsQuery);
    asyncQueries.push_back(&LoadDisablesQueryQuery);
    asyncQueries.push_back(&LFGLoadRewardsQuery);
    asyncQueries.push_back(&LFGLoadDungeonTemplateQuery);
    asyncQueries.push_back(&LoadCreatureFormationsQuery);
    asyncQueries.push_back(&LoadRandomEnchantmentsTableQuery);
    asyncQueries.push_back(&LoadGameEventsQuery);
    asyncQueries.push_back(&LoadGameEventPrerequisiteQuery);
    asyncQueries.push_back(&LoadGameEventCreaturesQuery);
    asyncQueries.push_back(&LoadGameEventGameObjectsQuery);
    asyncQueries.push_back(&LoadGameEventDisplayChangeQuery);
    asyncQueries.push_back(&LoadGameEventCreatureQuestQuery);
    asyncQueries.push_back(&LoadGameEventGameObjectQuestQuery);
    asyncQueries.push_back(&LoadGameObjectQuestConditionQuery);
    asyncQueries.push_back(&LoadGameEventConditionQuery);
    asyncQueries.push_back(&LoadGameEventNPCFlagQuery);
    asyncQueries.push_back(&LoadGameEventSeasonalQuestRelationQuery);
    asyncQueries.push_back(&LoadGameEventNPCVendorQuery);
    asyncQueries.push_back(&LoadGameEventBattlegroundHolidayQuery);
    asyncQueries.push_back(&LoadGameEventPoolsQuery);
    asyncQueries.push_back(&LoadHolidayDatesQuery);
    asyncQueries.push_back(&LoadGameEventMaxEntryQuery);
    asyncQueries.push_back(&LoadTransportTemplatesQuery);
    asyncQueries.push_back(&LoadTransportsQuery);
    asyncQueries.push_back(&LoadWaypointsQuery);
    asyncQueries.push_back(&LoadOutdoorPVPTemplatesQuery);
    asyncQueries.push_back(&LoadPoolTemplatesQuery);
    asyncQueries.push_back(&LoadPoolCreatureMembersQuery);
    asyncQueries.push_back(&LoadPoolGameObjectMembersQuery);
    asyncQueries.push_back(&LoadPoolMotherMembersQuery);
    asyncQueries.push_back(&LoadPoolHandlingQuery);
    asyncQueries.push_back(&LoadQuestPoolsQuery);
    asyncQueries.push_back(&LoadScriptWaypointCountQuery);
    asyncQueries.push_back(&LoadScriptWaypointsQuery);
    asyncQueries.push_back(&LoadScriptSplineChainMetaQuery);
    asyncQueries.push_back(&LoadScriptSplineChainWaypointsQuery);
    asyncQueries.push_back(&LoadSkillDiscoveryTemplateQuery);
    asyncQueries.push_back(&LoadSkillPerfectItemTemplateQuery);
    asyncQueries.push_back(&LoadSkillExtraItemTemplateQuery);
    asyncQueries.push_back(&LoadSpellRanksQuery);
    asyncQueries.push_back(&LoadSpellRequiredQuery);
    asyncQueries.push_back(&LoadSpellLearnSpellsQuery);
    asyncQueries.push_back(&LoadSpellTargetPositionQuery);
    asyncQueries.push_back(&LoadSpellGroupsQuery);
    asyncQueries.push_back(&LoadSpellGroupStackRulesQuery);
    asyncQueries.push_back(&LoadSpellProcsQuery);
    asyncQueries.push_back(&LoadSpellBonusesQuery);
    asyncQueries.push_back(&LoadSpellThreatsQuery);
    asyncQueries.push_back(&LoadSpellPetAurasQuery);
    asyncQueries.push_back(&LoadSpellEnchantProcDataQuery);
    asyncQueries.push_back(&LoadSpellLinkedQuery);
    asyncQueries.push_back(&LoadSpellAreasQuery);
    asyncQueries.push_back(&LoadSpellInfoCustomAttributesQuery);
    asyncQueries.push_back(&LoadCreatureTextLocalesQuery);
    asyncQueries.push_back(&LoadMaxWardenChecksQuery);
    asyncQueries.push_back(&LoadWardenChecksQuery);
    asyncQueries.push_back(&LoadWeatherDataQuery);
    asyncQueries.push_back(&LoadSmartScriptsQuery);
    asyncQueries.push_back(&LoadCreatureTextQuery);

    for (LoadDataQuery* query : asyncQueries)
    {
        query->StartAsyncQuery();
    }
}

