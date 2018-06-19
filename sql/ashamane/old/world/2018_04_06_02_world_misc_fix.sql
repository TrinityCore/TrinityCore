-- Orgrimmar

-- Delete Deprecated Spawns and Upgrading One --
UPDATE creature SET id = 72939 AND modelid = 51000 WHERE id = 3344;
UPDATE creature SET id = 72944 AND modelid = 51002 WHERE id = 986;
DELETE FROM creature WHERE id IN (16012,83863);

-- Delete Duplicated Spawns --
DELETE FROM creature WHERE guid IN (235668,194727,194986,10642708);

-- Make a Bunny Invisible --
UPDATE creature_template SET flags_extra = 128 WHERE entry = 52810;

-- Add missing Things (a Mailbox and a Guard) --
SET @OGUID := 20;
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0; 
insert into `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) values
(@OGUID+0,206725,1,0,0,1,0,0,0,-1,1730.54,-4498.27,30.9709,3.23758,-0,-0,-0.998848,0.0479773,300,255,1,0,"",0);

SET @CGUID := 46;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3; 
insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) values
(@CGUID+0,88543,1,1637,5356,1,0,0,0,-1,56698,0,1646.19,-4335.09,26.7623,0.552369,300,0,0,8314140,10,0,0,0,0,0,0,"",0),
(@CGUID+1,88543,1,1637,5356,1,0,0,0,-1,56698,0,1651.06,-4332.37,26.7627,3.76072,300,0,0,8314140,10,0,0,0,0,0,0,"",0),
(@CGUID+2,89175,1,1637,5166,1,0,0,0,-1,18678,0,1788.36,-4275.11,7.73986,5.07307,300,0,0,112150,2434,0,0,0,0,0,0,"",0),
(@CGUID+3,3296,1,1637,5170,1,0,0,0,-1,4260,1,1737.94,-4403.28,36.5723,5.12287,300,0,0,1558901,0,0,0,0,0,0,0,"",0);

-- Add High Overlord Saurfang Quest_Starter Missing Data --
DELETE FROM `creature_queststarter` WHERE id = 14720;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(14720,9627),
(14720,13842),
(14720,25275),
(14720,26293),
(14720,26324),
(14720,26830),
(14720,26840),
(14720,26865),
(14720,28909),
(14720,31034);

-- Change Nathanos Blightcaller Model to the New One --
UPDATE creature SET modelid = 66644 WHERE id = 50609;
UPDATE creature_template SET modelid1 = 66644 WHERE entry IN (95315,95852,93603,91158,96683,95309,94420);

-- Fixing a Dark Ranger Weird Movements --
UPDATE creature SET MovementType = 0 WHERE id = 23776;

-- Stormwind

-- Add creature_template_addon missing data --
DELETE FROM creature_template_addon WHERE entry IN (61837,73190,105333);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(61837,0,0,0,257,426,0,0,0,""),
(73190,0,51037,0,0,0,0,0,0,""),
(105333,0,0,0,1,461,0,0,0,"");

-- Blasted Lands 

-- Fix Protecting our Rear --
UPDATE creature SET modelid = 73332 WHERE id = 41166;

-- Fix Quest Item Data (Demoniac Vessel Quest Related) --
UPDATE creature_loot_template SET QuestRequired = 1 AND MaxCount = 3 WHERE Item = 57178;

-- Silvermoon City

-- Fix Lor'themar Theron Weapons --
DELETE FROM creature_equip_template WHERE CreatureID = 16802;
insert into `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) values
(16802,1,62232,0,0,0,0,0,0,0,0,18019);

-- Scarlet Enclave

-- Scarlet Cannons --
UPDATE creature_template SET InhabitType = 8 WHERE entry IN (28833,28887);

-- Make Dummies Invisible --
UPDATE creature_template SET flags_extra = 128 WHERE entry IN (28367,28481,28483,29521,29580,29581);

-- Delete Spawns of NPCs that only are Summoneable by certain Events --
DELETE FROM creature WHERE id IN (28846,29007,29001);

-- Fix Unclickable Enemies (Battle For Light's Hope) --
UPDATE creature_template SET unit_flags = 32768 WHERE entry IN (29174,29176,29178,29177,29181,29179,29180,29182);

-- Fix Dead Bodies Visual--
UPDATE creature_template_addon SET mount = 0 WHERE entry = 28898;
DELETE FROM creature_template_addon WHERE entry IN (28892,54386);
insert into `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) values
(54386,0,0,0,1,0,0,0,0,29266),
(28892,0,0,0,1,0,0,0,0,29266);

-- Ashenvale

-- Fix wrong data on Npc_spellclick_spells --
DELETE FROM npc_spellclick_spells WHERE npc_entry = 33348 AND spell_id = 81550;

-- Class Halls: Fel Hammer

-- Add Demyssia Gladestrider Equip Template --
DELETE FROM creature_equip_template WHERE CreatureID = 116621;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(116621,1,5597,0,0,0,0,0,5597,0,0,25596);

-- Demyssia Gladestrider Fix Z Cord and set equipment id to 1 --
UPDATE creature SET equipment_id = 1 AND position_z = 236.718994 WHERE id = 116621;

-- Remove Duplicate Tyranna's Body in Fel Hammer Class Hall Vers  --
DELETE FROM creature WHERE guid = 20547022;

-- Fixing duplicated Rares 
DELETE FROM creature WHERE guid IN (87290,94941,10656142,85540,92317,131430,131429,130866);

-- Deleting EXP potions
DELETE FROM creature_loot_template WHERE item = 86574;
DELETE FROM creature_loot_template WHERE item = 128312;
DELETE FROM gameobject_loot_template WHERE item = 86574;
DELETE FROM gameobject_loot_template WHERE item = 128312;
DELETE FROM item_loot_template WHERE item = 86574;
DELETE FROM item_loot_template where item = 128312;

-- Class Halls: Dreadscar Rift

-- Fix Teleport --
UPDATE spell_target_position SET PositionZ = 243.5 WHERE ID = 215793;

-- Fix Teleporter Name --
UPDATE gameobject_template SET name = "Portal to Dreadscar Rift" WHERE entry = 251302;

-- Fix HallRogue game_tele --
UPDATE game_tele SET position_z=700.75 WHERE NAME = "HallRogue";

-- Fixing Some Herbs: Add Missing Data
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (247865,248019,248020,248022,248029,247897,248028,247607,248027,248018,247388,248025,248026,248024,247606,248023,248032,247608,248031,248030);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(247865,135480,0,100,1,1,0,1,1,""),
(248019,140948,0,100,1,1,0,1,1,""),
(248020,140950,0,100,1,1,0,1,1,""),
(248022,140951,0,100,1,1,0,1,1,""),
(248029,140961,0,100,1,1,0,1,1,""),
(247897,135500,0,100,1,1,0,1,1,""),
(248028,140960,0,100,1,1,0,1,1,""),
(247607,140958,0,100,1,1,0,1,1,""),
(248027,140959,0,100,1,1,0,1,1,""),
(248018,140988,0,100,1,1,0,1,1,""),
(247388,140986,0,100,1,1,0,1,1,""),
(248025,140956,0,100,1,1,0,1,1,""),
(248026,140957,0,100,1,1,0,1,1,""),
(248024,140955,0,100,1,1,0,1,1,""),
(247606,140952,0,100,1,1,0,1,1,""),
(248023,140954,0,100,1,1,0,1,1,""),
(248032,140992,0,100,1,1,0,1,1,""),
(247608,140989,0,100,1,1,0,1,1,""),
(248031,140991,0,100,1,1,0,1,1,""),
(248030,140990,0,100,1,1,0,1,1,"");

-- Fixing Some Herbs: Apply Loot Data
UPDATE gameobject_template SET Data1 = 244775 WHERE entry = 244775;
UPDATE gameobject_template SET Data1 = 244776 WHERE entry = 244776;
UPDATE gameobject_template SET Data1 = 244777 WHERE entry = 244777;
UPDATE gameobject_template SET Data1 = 247865 WHERE entry = 247865;
UPDATE gameobject_template SET Data1 = 248019 WHERE entry = 248019;
UPDATE gameobject_template SET Data1 = 248020 WHERE entry = 248020;
UPDATE gameobject_template SET Data1 = 248022 WHERE entry = 248022;
UPDATE gameobject_template SET Data1 = 248029 WHERE entry = 248029;
UPDATE gameobject_template SET Data1 = 247897 WHERE entry = 247897;
UPDATE gameobject_template SET Data1 = 248028 WHERE entry = 248028;
UPDATE gameobject_template SET Data1 = 247607 WHERE entry = 247607;
UPDATE gameobject_template SET Data1 = 248027 WHERE entry = 248027;
UPDATE gameobject_template SET Data1 = 248018 WHERE entry = 248018;
UPDATE gameobject_template SET Data1 = 247388 WHERE entry = 247388;
UPDATE gameobject_template SET Data1 = 248025 WHERE entry = 248025;
UPDATE gameobject_template SET Data1 = 248026 WHERE entry = 248026;
UPDATE gameobject_template SET Data1 = 248024 WHERE entry = 248024;
UPDATE gameobject_template SET Data1 = 247606 WHERE entry = 247606;
UPDATE gameobject_template SET Data1 = 248023 WHERE entry = 248023;
UPDATE gameobject_template SET Data1 = 248032 WHERE entry = 248032;
UPDATE gameobject_template SET Data1 = 247608 WHERE entry = 247608;
UPDATE gameobject_template SET Data1 = 248031 WHERE entry = 248031;
UPDATE gameobject_template SET Data1 = 248030 WHERE entry = 248030;
