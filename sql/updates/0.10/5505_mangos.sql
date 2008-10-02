-- Then update all tables
ALTER TABLE `areatrigger_involvedrelation`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Identifier',
    CHANGE COLUMN `quest` `quest` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier';
ALTER TABLE `areatrigger_tavern`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Identifier';
ALTER TABLE `areatrigger_teleport`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Identifier',
    CHANGE COLUMN `required_level` `required_level` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `required_item` `required_item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `target_map` `target_map` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `battleground_template`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL,
    CHANGE COLUMN `MinPlayersPerTeam` `MinPlayersPerTeam` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `MaxPlayersPerTeam` `MaxPlayersPerTeam` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `MinLvl` `MinLvl` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `MaxLvl` `MaxLvl` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `AllianceStartLoc` `AllianceStartLoc` mediumint unsigned NOT NULL,
    CHANGE COLUMN `HordeStartLoc` `HordeStartLoc` mediumint unsigned NOT NULL;
ALTER TABLE `battlemaster_entry`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Entry of a creature',
    CHANGE COLUMN `bg_template` `bg_template` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Battleground template id';
ALTER TABLE `command`
    CHANGE COLUMN `security` `security` tinyint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `creature`
    CHANGE COLUMN `guid` `guid` integer unsigned NOT NULL auto_increment COMMENT 'Global Unique Identifier',
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Creature Identifier',
    CHANGE COLUMN `map` `map` smallint unsigned NOT NULL DEFAULT 0 COMMENT 'Map Identifier',
    CHANGE COLUMN `modelid` `modelid` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipment_id` `equipment_id` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `spawntimesecs` `spawntimesecs` integer unsigned NOT NULL DEFAULT 120,
    CHANGE COLUMN `currentwaypoint` `currentwaypoint` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `curhealth` `curhealth` integer unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `curmana` `curmana` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `DeathState` `DeathState` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `MovementType` `MovementType` tinyint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `creature_addon`
    CHANGE COLUMN `guid` `guid` integer NOT NULL DEFAULT 0,
    CHANGE COLUMN `mount` `mount` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `bytes0` `bytes0` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `bytes1` `bytes1` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `bytes2` `bytes2` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `emote` `emote` integer unsigned NOT NULL DEFAULT 0;
ALTER TABLE `creature_equip_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Unique entry',
    CHANGE COLUMN `equipmodel1` `equipmodel1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipmodel2` `equipmodel2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipmodel3` `equipmodel3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipinfo1` `equipinfo1` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipinfo2` `equipinfo2` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipinfo3` `equipinfo3` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipslot1` `equipslot1` integer NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipslot2` `equipslot2` integer NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipslot3` `equipslot3` integer NOT NULL DEFAULT 0;
ALTER TABLE `creature_involvedrelation`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Identifier',
    CHANGE COLUMN `quest` `quest` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier';
ALTER TABLE `creature_loot_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestChanceOrGroup` `QuestChanceOrGroup` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `mincount` `mincount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxcount` `maxcount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `freeforall` `freeforall` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootcondition` `lootcondition` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value1` `condition_value1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value2` `condition_value2` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `creature_model_info`
    CHANGE COLUMN `modelid` `modelid` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `gender` `gender` tinyint unsigned NOT NULL DEFAULT 2,
    CHANGE COLUMN `modelid_other_gender` `modelid_other_gender` mediumint unsigned NOT NULL DEFAULT 0;
UPDATE `creature_movement` SET `orientation`=0 WHERE `orientation` IS NULL;
UPDATE `creature_movement` SET `model1`=0 WHERE `model1` IS NULL;
UPDATE `creature_movement` SET `model2`=0 WHERE `model2` IS NULL;
ALTER TABLE `creature_movement`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Identifier',
    CHANGE COLUMN `point` `point` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `waittime` `waittime` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `aiscript` `aiscript` varchar(128),
    CHANGE COLUMN `emote` `emote` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spell` `spell` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `wpguid` `wpguid` integer NOT NULL DEFAULT 0,
    CHANGE COLUMN `orientation` `orientation` float NOT NULL DEFAULT 0,
    CHANGE COLUMN `model1` `model1` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `model2` `model2` mediumint NOT NULL DEFAULT 0;
ALTER TABLE `creature_onkill_reputation`
    CHANGE COLUMN `creature_id` `creature_id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Creature Identifier',
    CHANGE COLUMN `RewOnKillRepFaction1` `RewOnKillRepFaction1` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewOnKillRepFaction2` `RewOnKillRepFaction2` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `MaxStanding1` `MaxStanding1` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `IsTeamAward1` `IsTeamAward1` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewOnKillRepValue1` `RewOnKillRepValue1` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `MaxStanding2` `MaxStanding2` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `IsTeamAward2` `IsTeamAward2` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewOnKillRepValue2` `RewOnKillRepValue2` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `TeamDependent` `TeamDependent` tinyint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `creature_questrelation`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Identifier',
    CHANGE COLUMN `quest` `quest` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier';
ALTER TABLE `creature_respawn`
    CHANGE COLUMN `guid` `guid` integer unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
    CHANGE COLUMN `respawntime` `respawntime` bigint NOT NULL DEFAULT 0,
    CHANGE COLUMN `instance` `instance` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `creature_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `modelid_A` `modelid_A` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `modelid_A2` `modelid_A2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `modelid_H` `modelid_H` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `modelid_H2` `modelid_H2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `minlevel` `minlevel` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxlevel` `maxlevel` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `minhealth` `minhealth` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxhealth` `maxhealth` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `minmana` `minmana` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxmana` `maxmana` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `armor` `armor` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `faction_A` `faction_A` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `faction_H` `faction_H` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `npcflag` `npcflag` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `speed` `speed` float NOT NULL DEFAULT 1.0,
    CHANGE COLUMN `scale` `scale` float NOT NULL DEFAULT 0,
    CHANGE COLUMN `rank` `rank` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `mindmg` `mindmg` float NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxdmg` `maxdmg` float NOT NULL DEFAULT 0,
    CHANGE COLUMN `dmgschool` `dmgschool` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `attackpower` `attackpower` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `baseattacktime` `baseattacktime` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `rangeattacktime` `rangeattacktime` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `flags` `flags` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `dynamicflags` `dynamicflags` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `family` `family` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `trainer_type` `trainer_type` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `trainer_spell` `trainer_spell` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `class` `class` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `race` `race` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `rangedattackpower` `rangedattackpower` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `type` `type` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `civilian` `civilian` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `flag1` `flag1` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootid` `lootid` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `pickpocketloot` `pickpocketloot` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `skinloot` `skinloot` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `resistance1` `resistance1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `resistance2` `resistance2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `resistance3` `resistance3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `resistance4` `resistance4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `resistance5` `resistance5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `resistance6` `resistance6` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spell1` `spell1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spell2` `spell2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spell3` `spell3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spell4` `spell4` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `mingold` `mingold` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxgold` `maxgold` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `AIName` `AIName` char(64) NOT NULL DEFAULT '',
    CHANGE COLUMN `MovementType` `MovementType` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `InhabitType` `InhabitType` tinyint unsigned NOT NULL DEFAULT 3,
    CHANGE COLUMN `RacialLeader` `RacialLeader` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RegenHealth` `RegenHealth` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `equipment_id` `equipment_id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `mechanic_immune_mask` `mechanic_immune_mask` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ScriptName` `ScriptName` char(64) NOT NULL DEFAULT '';
ALTER TABLE `creature_template_addon`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `mount` `mount` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `bytes0` `bytes0` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `bytes1` `bytes1` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `bytes2` `bytes2` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `emote` `emote` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `disenchant_loot_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Recommended id selection: item_level*100 + item_quality',
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestChanceOrGroup` `QuestChanceOrGroup` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `mincount` `mincount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxcount` `maxcount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `freeforall` `freeforall` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootcondition` `lootcondition` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value1` `condition_value1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value2` `condition_value2` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `event_scripts`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `delay` `delay` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `command` `command` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong` `datalong` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong2` `datalong2` integer unsigned NOT NULL DEFAULT 0;
ALTER TABLE `exploration_basexp`
    CHANGE COLUMN `level` `level` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `basexp` `basexp` mediumint NOT NULL DEFAULT 0;
ALTER TABLE `fishing_loot_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestChanceOrGroup` `QuestChanceOrGroup` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `mincount` `mincount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxcount` `maxcount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `freeforall` `freeforall` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootcondition` `lootcondition` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value1` `condition_value1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value2` `condition_value2` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `game_event_creature`
    CHANGE COLUMN `guid` `guid` integer unsigned NOT NULL,
    CHANGE COLUMN `event` `event` smallint NOT NULL DEFAULT 0 COMMENT 'Put negatives values to remove during event';
ALTER TABLE `game_event_creature_quest`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `quest` `quest` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `event` `event` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `game_event_gameobject`
    CHANGE COLUMN `guid` `guid` integer unsigned NOT NULL,
    CHANGE COLUMN `event` `event` smallint NOT NULL DEFAULT 0 COMMENT 'Put negatives values to remove during event';
ALTER TABLE `game_event_model_equip`
    CHANGE COLUMN `guid` `guid` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `modelid` `modelid` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `equipment_id` `equipment_id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `event` `event` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `game_graveyard_zone`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ghost_zone` `ghost_zone` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `faction` `faction` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `game_tele`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL auto_increment,
    CHANGE COLUMN `map` `map` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `game_weather`
    CHANGE COLUMN `zone` `zone` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spring_rain_chance` `spring_rain_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `spring_snow_chance` `spring_snow_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `spring_storm_chance` `spring_storm_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `summer_rain_chance` `summer_rain_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `summer_snow_chance` `summer_snow_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `summer_storm_chance` `summer_storm_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `fall_rain_chance` `fall_rain_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `fall_snow_chance` `fall_snow_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `fall_storm_chance` `fall_storm_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `winter_rain_chance` `winter_rain_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `winter_snow_chance` `winter_snow_chance` tinyint unsigned NOT NULL DEFAULT 25,
    CHANGE COLUMN `winter_storm_chance` `winter_storm_chance` tinyint unsigned NOT NULL DEFAULT 25;
ALTER TABLE `gameobject`
    CHANGE COLUMN `guid` `guid` integer unsigned NOT NULL auto_increment COMMENT 'Global Unique Identifier',
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Gameobject Identifier',
    CHANGE COLUMN `map` `map` smallint unsigned NOT NULL DEFAULT 0 COMMENT 'Map Identifier',
    CHANGE COLUMN `spawntimesecs` `spawntimesecs` integer NOT NULL DEFAULT 0,
    CHANGE COLUMN `animprogress` `animprogress` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `state` `state` tinyint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_involvedrelation`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `quest` `quest` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier';
ALTER TABLE `gameobject_loot_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestChanceOrGroup` `QuestChanceOrGroup` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `mincount` `mincount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxcount` `maxcount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `freeforall` `freeforall` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootcondition` `lootcondition` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value1` `condition_value1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value2` `condition_value2` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_questrelation`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `quest` `quest` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier';
ALTER TABLE `gameobject_respawn`
    CHANGE COLUMN `guid` `guid` integer unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
    CHANGE COLUMN `respawntime` `respawntime` bigint NOT NULL DEFAULT 0,
    CHANGE COLUMN `instance` `instance` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_scripts`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `delay` `delay` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `command` `command` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong` `datalong` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong2` `datalong2` integer unsigned NOT NULL DEFAULT 0;
ALTER TABLE `gameobject_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `type` `type` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `displayId` `displayId` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `name` `name` varchar(100) NOT NULL DEFAULT '',
    CHANGE COLUMN `faction` `faction` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `flags` `flags` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data0` `data0` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data1` `data1` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data2` `data2` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data3` `data3` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data4` `data4` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data5` `data5` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data6` `data6` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data7` `data7` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data8` `data8` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data9` `data9` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data10` `data10` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data11` `data11` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data12` `data12` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data13` `data13` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data14` `data14` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data15` `data15` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data16` `data16` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data17` `data17` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data18` `data18` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data19` `data19` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data20` `data20` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data21` `data21` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data22` `data22` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `data23` `data23` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ScriptName` `ScriptName` varchar(64) NOT NULL DEFAULT '';
ALTER TABLE `instance_template`
    CHANGE COLUMN `map` `map` smallint unsigned NOT NULL,
    CHANGE COLUMN `parent` `parent` integer unsigned NOT NULL,
    CHANGE COLUMN `levelMin` `levelMin` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `levelMax` `levelMax` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxPlayers` `maxPlayers` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `reset_delay` `reset_delay` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `script` `script` varchar(128) NOT NULL DEFAULT '';
ALTER TABLE `item_enchantment_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ench` `ench` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `item_loot_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestChanceOrGroup` `QuestChanceOrGroup` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `mincount` `mincount` smallint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxcount` `maxcount` smallint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `freeforall` `freeforall` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootcondition` `lootcondition` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value1` `condition_value1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value2` `condition_value2` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `item_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `class` `class` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `subclass` `subclass` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `unk0` `unk0` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `name` `name` varchar(255) NOT NULL DEFAULT '',
    CHANGE COLUMN `displayid` `displayid` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Quality` `Quality` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Flags` `Flags` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `BuyCount` `BuyCount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `BuyPrice` `BuyPrice` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SellPrice` `SellPrice` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `InventoryType` `InventoryType` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `AllowableClass` `AllowableClass` mediumint NOT NULL DEFAULT -1,
    CHANGE COLUMN `AllowableRace` `AllowableRace` mediumint NOT NULL DEFAULT -1,
    CHANGE COLUMN `ItemLevel` `ItemLevel` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredLevel` `RequiredLevel` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredSkill` `RequiredSkill` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredSkillRank` `RequiredSkillRank` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `requiredspell` `requiredspell` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `requiredhonorrank` `requiredhonorrank` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredCityRank` `RequiredCityRank` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredReputationFaction` `RequiredReputationFaction` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredReputationRank` `RequiredReputationRank` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxcount` `maxcount` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stackable` `stackable` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ContainerSlots` `ContainerSlots` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type1` `stat_type1` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value1` `stat_value1` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type2` `stat_type2` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value2` `stat_value2` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type3` `stat_type3` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value3` `stat_value3` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type4` `stat_type4` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value4` `stat_value4` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type5` `stat_type5` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value5` `stat_value5` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type6` `stat_type6` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value6` `stat_value6` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type7` `stat_type7` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value7` `stat_value7` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type8` `stat_type8` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value8` `stat_value8` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type9` `stat_type9` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value9` `stat_value9` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_type10` `stat_type10` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `stat_value10` `stat_value10` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `dmg_type1` `dmg_type1` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `dmg_type2` `dmg_type2` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `dmg_type3` `dmg_type3` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `dmg_type4` `dmg_type4` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `dmg_type5` `dmg_type5` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `armor` `armor` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `holy_res` `holy_res` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `fire_res` `fire_res` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `nature_res` `nature_res` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `frost_res` `frost_res` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `shadow_res` `shadow_res` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `arcane_res` `arcane_res` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `delay` `delay` smallint unsigned NOT NULL DEFAULT 1000,
    CHANGE COLUMN `ammo_type` `ammo_type` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellid_1` `spellid_1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spelltrigger_1` `spelltrigger_1` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcharges_1` `spellcharges_1` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcooldown_1` `spellcooldown_1` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellcategory_1` `spellcategory_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcategorycooldown_1` `spellcategorycooldown_1` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellid_2` `spellid_2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spelltrigger_2` `spelltrigger_2` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcharges_2` `spellcharges_2` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcooldown_2` `spellcooldown_2` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellcategory_2` `spellcategory_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcategorycooldown_2` `spellcategorycooldown_2` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellid_3` `spellid_3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spelltrigger_3` `spelltrigger_3` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcharges_3` `spellcharges_3` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcooldown_3` `spellcooldown_3` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellcategory_3` `spellcategory_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcategorycooldown_3` `spellcategorycooldown_3` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellid_4` `spellid_4` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spelltrigger_4` `spelltrigger_4` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcharges_4` `spellcharges_4` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcooldown_4` `spellcooldown_4` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellcategory_4` `spellcategory_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcategorycooldown_4` `spellcategorycooldown_4` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellid_5` `spellid_5` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spelltrigger_5` `spelltrigger_5` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcharges_5` `spellcharges_5` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcooldown_5` `spellcooldown_5` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `spellcategory_5` `spellcategory_5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcategorycooldown_5` `spellcategorycooldown_5` integer NOT NULL DEFAULT -1,
    CHANGE COLUMN `bonding` `bonding` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `PageText` `PageText` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `LanguageID` `LanguageID` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `PageMaterial` `PageMaterial` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `startquest` `startquest` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lockid` `lockid` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Material` `Material` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `sheath` `sheath` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RandomProperty` `RandomProperty` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RandomSuffix` `RandomSuffix` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `block` `block` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `itemset` `itemset` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `MaxDurability` `MaxDurability` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `area` `area` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Map` `Map` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `BagFamily` `BagFamily` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `TotemCategory` `TotemCategory` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `socketColor_1` `socketColor_1` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `socketContent_1` `socketContent_1` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `socketColor_2` `socketColor_2` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `socketContent_2` `socketContent_2` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `socketColor_3` `socketColor_3` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `socketContent_3` `socketContent_3` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `socketBonus` `socketBonus` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `GemProperties` `GemProperties` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `ExtendedCost` `ExtendedCost` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `CondExtendedCost` `CondExtendedCost` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredDisenchantSkill` `RequiredDisenchantSkill` smallint NOT NULL DEFAULT -1,
    CHANGE COLUMN `ScriptName` `ScriptName` varchar(64) NOT NULL DEFAULT '',
    CHANGE COLUMN `DisenchantID` `DisenchantID` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `FoodType` `FoodType` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `minMoneyLoot` `minMoneyLoot` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxMoneyLoot` `maxMoneyLoot` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Duration` `Duration` integer NOT NULL DEFAULT 0 COMMENT 'Duration in seconds. Negative value means realtime, postive value ingame time';
ALTER TABLE `locales_creature`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `locales_gameobject`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `locales_item`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `locales_npc_text`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `locales_page_text`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `locales_quest`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `mangos_string`
    CHANGE COLUMN `content_default` `content_default` text NOT NULL,
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `npc_gossip`   
    CHANGE COLUMN `npc_guid` `npc_guid` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `textid` `textid` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `npc_gossip_textid`
    CHANGE COLUMN `zoneid` `zoneid` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `action` `action` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `textid` `textid` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `npc_option`
    CHANGE COLUMN `id` `id` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `gossip_id` `gossip_id` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `npcflag` `npcflag` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `icon` `icon` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `action` `action` tinyint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `npc_text`
    CHANGE COLUMN `ID` `ID` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lang0` `lang0` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em0_0` `em0_0` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em0_1` `em0_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em0_2` `em0_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em0_3` `em0_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em0_4` `em0_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em0_5` `em0_5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lang1` `lang1` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em1_0` `em1_0` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em1_1` `em1_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em1_2` `em1_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em1_3` `em1_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em1_4` `em1_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em1_5` `em1_5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lang2` `lang2` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em2_0` `em2_0` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em2_1` `em2_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em2_2` `em2_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em2_3` `em2_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em2_4` `em2_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em2_5` `em2_5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lang3` `lang3` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em3_0` `em3_0` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em3_1` `em3_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em3_2` `em3_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em3_3` `em3_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em3_4` `em3_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em3_5` `em3_5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lang4` `lang4` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em4_0` `em4_0` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em4_1` `em4_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em4_2` `em4_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em4_3` `em4_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em4_4` `em4_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em4_5` `em4_5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lang5` `lang5` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em5_0` `em5_0` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em5_1` `em5_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em5_2` `em5_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em5_3` `em5_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em5_4` `em5_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em5_5` `em5_5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lang6` `lang6` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em6_0` `em6_0` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em6_1` `em6_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em6_2` `em6_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em6_3` `em6_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em6_4` `em6_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em6_5` `em6_5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lang7` `lang7` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em7_0` `em7_0` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em7_1` `em7_1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em7_2` `em7_2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em7_3` `em7_3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em7_4` `em7_4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `em7_5` `em7_5` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `npc_trainer`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spell` `spell` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `spellcost` `spellcost` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `reqskill` `reqskill` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `reqskillvalue` `reqskillvalue` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `reqlevel` `reqlevel` tinyint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `npc_vendor`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxcount` `maxcount` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `incrtime` `incrtime` integer unsigned NOT NULL DEFAULT 0;
ALTER TABLE `page_text`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `text` `text` longtext NOT NULL,
    CHANGE COLUMN `next_page` `next_page` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `pet_levelstats`
    CHANGE COLUMN `creature_entry` `creature_entry` mediumint unsigned NOT NULL,
    CHANGE COLUMN `level` `level` tinyint unsigned NOT NULL,
    CHANGE COLUMN `hp` `hp` smallint unsigned NOT NULL,
    CHANGE COLUMN `mana` `mana` smallint unsigned NOT NULL,
    CHANGE COLUMN `armor` `armor` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `str` `str` smallint unsigned NOT NULL,
    CHANGE COLUMN `agi` `agi` smallint unsigned NOT NULL,
    CHANGE COLUMN `sta` `sta` smallint unsigned NOT NULL,
    CHANGE COLUMN `inte` `inte` smallint unsigned NOT NULL,
    CHANGE COLUMN `spi` `spi` smallint unsigned NOT NULL;
ALTER TABLE `pet_name_generation`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL auto_increment,
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `half` `half` tinyint NOT NULL DEFAULT 0;
ALTER TABLE `petcreateinfo_spell`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Spell1` `Spell1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Spell2` `Spell2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Spell3` `Spell3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Spell4` `Spell4` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `FamilyPassive` `FamilyPassive` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `pickpocketing_loot_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestChanceOrGroup` `QuestChanceOrGroup` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `mincount` `mincount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxcount` `maxcount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `freeforall` `freeforall` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootcondition` `lootcondition` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value1` `condition_value1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value2` `condition_value2` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `playercreateinfo`
    CHANGE COLUMN `race` `race` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `class` `class` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `map` `map` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `zone` `zone` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `playercreateinfo_action`
    CHANGE COLUMN `race` `race` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `class` `class` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `button` `button` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `action` `action` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `type` `type` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `misc` `misc` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `playercreateinfo_item`
    CHANGE COLUMN `race` `race` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `class` `class` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `itemid` `itemid` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `amount` `amount` tinyint unsigned NOT NULL DEFAULT 1;
ALTER TABLE `playercreateinfo_skill`
    CHANGE COLUMN `race` `race` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `class` `class` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Skill` `Skill` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `playercreateinfo_spell`
    CHANGE COLUMN `race` `race` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `class` `class` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Spell` `Spell` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Active` `Active` tinyint unsigned NOT NULL DEFAULT 1;
-- here posted
ALTER TABLE `prospecting_loot_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestChanceOrGroup` `QuestChanceOrGroup` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `mincount` `mincount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxcount` `maxcount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `freeforall` `freeforall` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootcondition` `lootcondition` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value1` `condition_value1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value2` `condition_value2` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `quest_end_scripts`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `delay` `delay` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `command` `command` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong` `datalong` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong2` `datalong2` integer unsigned NOT NULL DEFAULT 0;
ALTER TABLE `quest_start_scripts`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `delay` `delay` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `command` `command` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong` `datalong` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong2` `datalong2` integer unsigned NOT NULL DEFAULT 0;
ALTER TABLE `quest_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ZoneOrSort` `ZoneOrSort` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `MinLevel` `MinLevel` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestLevel` `QuestLevel` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Type` `Type` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredRaces` `RequiredRaces` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredSkillValue` `RequiredSkillValue` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RepObjectiveFaction` `RepObjectiveFaction` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RepObjectiveValue` `RepObjectiveValue` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredMinRepFaction` `RequiredMinRepFaction` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredMinRepValue` `RequiredMinRepValue` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredMaxRepFaction` `RequiredMaxRepFaction` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RequiredMaxRepValue` `RequiredMaxRepValue` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `SuggestedPlayers` `SuggestedPlayers` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `LimitTime` `LimitTime` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestFlags` `QuestFlags` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SpecialFlags` `SpecialFlags` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `PrevQuestId` `PrevQuestId` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `NextQuestId` `NextQuestId` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `ExclusiveGroup` `ExclusiveGroup` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `NextQuestInChain` `NextQuestInChain` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SrcItemId` `SrcItemId` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SrcItemCount` `SrcItemCount` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SrcSpell` `SrcSpell` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqItemId1` `ReqItemId1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqItemId2` `ReqItemId2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqItemId3` `ReqItemId3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqItemId4` `ReqItemId4` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqItemCount1` `ReqItemCount1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqItemCount2` `ReqItemCount2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqItemCount3` `ReqItemCount3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqItemCount4` `ReqItemCount4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceId1` `ReqSourceId1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceId2` `ReqSourceId2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceId3` `ReqSourceId3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceId4` `ReqSourceId4` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceCount1` `ReqSourceCount1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceCount2` `ReqSourceCount2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceCount3` `ReqSourceCount3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceCount4` `ReqSourceCount4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceRef1` `ReqSourceRef1` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceRef2` `ReqSourceRef2` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceRef3` `ReqSourceRef3` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSourceRef4` `ReqSourceRef4` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqCreatureOrGOId1` `ReqCreatureOrGOId1` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqCreatureOrGOId2` `ReqCreatureOrGOId2` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqCreatureOrGOId3` `ReqCreatureOrGOId3` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqCreatureOrGOId4` `ReqCreatureOrGOId4` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqCreatureOrGOCount1` `ReqCreatureOrGOCount1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqCreatureOrGOCount2` `ReqCreatureOrGOCount2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqCreatureOrGOCount3` `ReqCreatureOrGOCount3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqCreatureOrGOCount4` `ReqCreatureOrGOCount4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSpellCast1` `ReqSpellCast1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSpellCast2` `ReqSpellCast2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSpellCast3` `ReqSpellCast3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `ReqSpellCast4` `ReqSpellCast4` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemId1` `RewChoiceItemId1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemId2` `RewChoiceItemId2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemId3` `RewChoiceItemId3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemId4` `RewChoiceItemId4` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemId5` `RewChoiceItemId5` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemId6` `RewChoiceItemId6` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemCount1` `RewChoiceItemCount1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemCount2` `RewChoiceItemCount2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemCount3` `RewChoiceItemCount3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemCount4` `RewChoiceItemCount4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemCount5` `RewChoiceItemCount5` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewChoiceItemCount6` `RewChoiceItemCount6` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewItemId1` `RewItemId1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewItemId2` `RewItemId2` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewItemId3` `RewItemId3` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewItemId4` `RewItemId4` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewItemCount1` `RewItemCount1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewItemCount2` `RewItemCount2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewItemCount3` `RewItemCount3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewItemCount4` `RewItemCount4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewRepFaction1` `RewRepFaction1` smallint unsigned NOT NULL DEFAULT 0 COMMENT 'faction id from Faction.dbc in this case',
    CHANGE COLUMN `RewRepFaction2` `RewRepFaction2` smallint unsigned NOT NULL DEFAULT 0 COMMENT 'faction id from Faction.dbc in this case',
    CHANGE COLUMN `RewRepFaction3` `RewRepFaction3` smallint unsigned NOT NULL DEFAULT 0 COMMENT 'faction id from Faction.dbc in this case',
    CHANGE COLUMN `RewRepFaction4` `RewRepFaction4` smallint unsigned NOT NULL DEFAULT 0 COMMENT 'faction id from Faction.dbc in this case',
    CHANGE COLUMN `RewRepFaction5` `RewRepFaction5` smallint unsigned NOT NULL DEFAULT 0 COMMENT 'faction id from Faction.dbc in this case',
    CHANGE COLUMN `RewRepValue1` `RewRepValue1` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewRepValue2` `RewRepValue2` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewRepValue3` `RewRepValue3` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewRepValue4` `RewRepValue4` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewRepValue5` `RewRepValue5` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewOrReqMoney` `RewOrReqMoney` integer NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewMoneyMaxLevel` `RewMoneyMaxLevel` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `RewSpell` `RewSpell` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `PointMapId` `PointMapId` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `PointOpt` `PointOpt` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `DetailsEmote1` `DetailsEmote1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `DetailsEmote2` `DetailsEmote2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `DetailsEmote3` `DetailsEmote3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `DetailsEmote4` `DetailsEmote4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `IncompleteEmote` `IncompleteEmote` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `CompleteEmote` `CompleteEmote` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `OfferRewardEmote1` `OfferRewardEmote1` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `OfferRewardEmote2` `OfferRewardEmote2` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `OfferRewardEmote3` `OfferRewardEmote3` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `OfferRewardEmote4` `OfferRewardEmote4` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `StartScript` `StartScript` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `CompleteScript` `CompleteScript` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `skill_discovery_template`
    CHANGE COLUMN `spellId` `spellId` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'SpellId of the discoverable spell',
    CHANGE COLUMN `reqSpell` `reqSpell` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'spell requirement';
ALTER TABLE `skill_extra_item_template`
    CHANGE COLUMN `spellId` `spellId` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'SpellId of the item creation spell',
    CHANGE COLUMN `requiredSpecialization` `requiredSpecialization` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Specialization spell id',
    CHANGE COLUMN `additionalMaxNum` `additionalMaxNum` tinyint unsigned NOT NULL DEFAULT 0 COMMENT 'max num of adds';
ALTER TABLE `skinning_loot_template`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `item` `item` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `QuestChanceOrGroup` `QuestChanceOrGroup` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `mincount` `mincount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `maxcount` `maxcount` tinyint unsigned NOT NULL DEFAULT 1,
    CHANGE COLUMN `freeforall` `freeforall` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `lootcondition` `lootcondition` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value1` `condition_value1` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `condition_value2` `condition_value2` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `spell_affect`
    CHANGE COLUMN `entry` `entry` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `effectId` `effectId` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SpellFamily` `SpellFamily` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SpellFamilyMask` `SpellFamilyMask` bigint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `Charges` `Charges` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `spell_chain`
    CHANGE COLUMN `spell_id` `spell_id` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `prev_spell` `prev_spell` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `first_spell` `first_spell` mediumint NOT NULL DEFAULT 0,
    CHANGE COLUMN `rank` `rank` tinyint NOT NULL DEFAULT 0;
ALTER TABLE `spell_learn_skill`
    CHANGE COLUMN `entry` `entry` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SkillID` `SkillID` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `Value` `Value` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `MaxValue` `MaxValue` smallint NOT NULL DEFAULT 0;
ALTER TABLE `spell_learn_spell`
    CHANGE COLUMN `entry` `entry` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SpellID` `SpellID` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `IfNoSpell` `IfNoSpell` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `spell_proc_event`
    CHANGE COLUMN `entry` `entry` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SchoolMask` `SchoolMask` tinyint NOT NULL DEFAULT 0,
    CHANGE COLUMN `Category` `Category` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `SkillID` `SkillID` smallint NOT NULL DEFAULT 0,
    CHANGE COLUMN `SpellFamilyName` `SpellFamilyName` smallint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `SpellFamilyMask` `SpellFamilyMask` bigint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `procFlags` `procFlags` integer unsigned NOT NULL DEFAULT 0;
ALTER TABLE `spell_script_target`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL,
    CHANGE COLUMN `type` `type` tinyint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `targetEntry` `targetEntry` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `spell_scripts`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `delay` `delay` integer unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `command` `command` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong` `datalong` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `datalong2` `datalong2` integer unsigned NOT NULL DEFAULT 0;
ALTER TABLE `spell_teleport`
    CHANGE COLUMN `id` `id` mediumint unsigned NOT NULL DEFAULT 0 COMMENT 'Identifier',
    CHANGE COLUMN `target_map` `target_map` smallint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `spell_threat`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL,
    CHANGE COLUMN `Threat` `Threat` smallint NOT NULL;
ALTER TABLE `transports`
    CHANGE COLUMN `entry` `entry` mediumint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `period` `period` mediumint unsigned NOT NULL DEFAULT 0;
ALTER TABLE `uptime`
    CHANGE COLUMN `starttime` `starttime` bigint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `startstring` `startstring` varchar(64) NOT NULL DEFAULT '',
    CHANGE COLUMN `uptime` `uptime` bigint unsigned NOT NULL DEFAULT 0,
    CHANGE COLUMN `maxplayers` `maxplayers` smallint unsigned NOT NULL DEFAULT 0;
