SET @CGUID := 10002085;

SET @NPCTEXTID := 600034;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2602.377685546875, -2620.986083984375, 184.60491943359375, 0.280349910259246826, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+1, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2592.4384765625, -2564.15966796875, 188.1512451171875, 4.638363838195800781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+2, 217081, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2568.65185546875, -2631.376708984375, 181.430938720703125, 2.23150038719177246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Trader Harthan (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+3, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2586.032958984375, -2569.751708984375, 181.57073974609375, 0.400520235300064086, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+4, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2587.80908203125, -2599.439208984375, 181.5489044189453125, 0.419246524572372436, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+5, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2552.06591796875, -2650.7744140625, 183.010040283203125, 4.031461238861083984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+6, 223533, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2539.7890625, -2578.82470703125, 181.623321533203125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Custodian Khubon (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+7, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2580.71533203125, -2657.401123046875, 182.142822265625, 1.029805541038513183, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439144 - Earthen - Shovel)
(@CGUID+8, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2605.010498046875, -2598.223876953125, 188.626983642578125, 4.51446390151977539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+9, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2565.44873046875, -2655.001708984375, 181.493316650390625, 5.8368682861328125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439144 - Earthen - Shovel)
(@CGUID+10, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2584.987060546875, -2643.0712890625, 183.23626708984375, 5.143726348876953125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+11, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2577.428955078125, -2645.029541015625, 181.736785888671875, 3.740097284317016601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439144 - Earthen - Shovel)
(@CGUID+12, 219097, 2552, 14771, 15043, '0', 0, 0, 0, 1, 2564.475830078125, -2638.3681640625, 181.4305572509765625, 4.196681976318359375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Tarib (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+13, 219096, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2567.131103515625, -2649.286376953125, 181.373291015625, 2.284739255905151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Gareb (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+14, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2595.732666015625, -2609.04345703125, 183.290863037109375, 0.452523797750473022, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+15, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2596.94873046875, -2586.328125, 181.645721435546875, 5.355077266693115234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+16, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2573.416748046875, -2644.30908203125, 181.49725341796875, 5.567463874816894531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439146 - Earthen - Mining)
(@CGUID+17, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2522.260498046875, -2627.375, 181.624542236328125, 2.03418731689453125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439142 - Earthen - Smithing)
(@CGUID+18, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2586.974853515625, -2571.447998046875, 181.571197509765625, 0.889838814735412597, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+19, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2537.98779296875, -2607.7431640625, 181.49127197265625, 2.181432485580444335, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+20, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2561.484375, -2653.314208984375, 181.50732421875, 3.528609514236450195, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439144 - Earthen - Shovel)
(@CGUID+21, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2536.6416015625, -2608.661376953125, 181.4912872314453125, 1.121540188789367675, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+22, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2517.587646484375, -2628.65625, 181.49127197265625, 3.834343671798706054, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+23, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2592.04345703125, -2567.291748046875, 188.0040740966796875, 1.528787136077880859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+24, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2408.645751953125, -2625.958251953125, 181.49127197265625, 3.909601211547851562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439142 - Earthen - Smithing)
(@CGUID+25, 219391, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2410.2431640625, -2626.411376953125, 181.49127197265625, 0.382788926362991333, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+26, 219392, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2390.314208984375, -2611.798583984375, 181.697479248046875, 0.91472017765045166, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forgegrounds Worker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439142 - Earthen - Smithing)
(@CGUID+27, 226751, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2511.0947265625, -2556.185791015625, 181.49127197265625, 3.901669502258300781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Reginald Arcfire (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+28, 226752, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2510.49560546875, -2557.46533203125, 181.49127197265625, 1.070719599723815917, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Brassbolt Mechawrench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+29, 223650, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2421.703125, -2591.435791015625, 181.505401611328125, 0.847295343875885009, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Forge Hand (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+30, 219014, 2552, 14771, 15043, '0', 0, 0, 0, 1, 2482.69091796875, -2509.90283203125, 181.548797607421875, 2.226074457168579101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+31, 219014, 2552, 14771, 15043, '0', 0, 0, 0, 6, 2572.833251953125, -2560.248291015625, 181.5489654541015625, 4.194911479949951171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+32, 219014, 2552, 14771, 15043, '0', 0, 0, 0, 1, 2487.925537109375, -2517.967041015625, 181.4855804443359375, 3.45979475975036621, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+33, 219014, 2552, 14771, 15043, '0', 0, 0, 0, 1, 2390.327392578125, -2543.46142578125, 181.41314697265625, 3.966630220413208007, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56647); -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439144'), -- Forgegrounds Worker - 439144 - Earthen - Shovel
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439144'), -- Forgegrounds Worker - 439144 - Earthen - Shovel
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439144'), -- Forgegrounds Worker - 439144 - Earthen - Shovel
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439146'), -- Forgegrounds Worker - 439146 - Earthen - Mining
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439142'), -- Forgegrounds Worker - 439142 - Earthen - Smithing
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Forgegrounds Worker
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439144'), -- Forgegrounds Worker - 439144 - Earthen - Shovel
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Forgegrounds Worker
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 428, 0, 0, 0, 0, ''), -- Forgegrounds Worker
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439142'), -- Forgegrounds Worker - 439142 - Earthen - Smithing
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Forgegrounds Worker
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439142'); -- Forgegrounds Worker - 439142 - Earthen - Smithing

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (219391 /*219391 (Forgegrounds Worker) - Earthen - Shovel*/, 219392 /*219392 (Forgegrounds Worker) - Earthen - Mining*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(219391, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 219391 (Forgegrounds Worker)
(219392, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 219392 (Forgegrounds Worker)

-- Template
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217081; -- Trader Harthan

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `VerifiedBuild`=56647 WHERE (`Entry`=217081 AND `DifficultyID`=0); -- 217081 (Trader Harthan) - 

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=223533 AND `MenuID` = 34926) OR (`CreatureID`=219097 AND `MenuID`=36348) OR (`CreatureID`=217081 AND `MenuID`=34051);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(223533, 34926, 56647), -- Custodian Khubon
(219097, 36348, 56647), -- Tarib
(217081, 34051, 56647); -- Trader Harthan

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 267782, 0, 0, 0, 0, 0, 0, 0, 56647), -- 223533 (Custodian Khubon)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 259296, 0, 0, 0, 0, 0, 0, 0, 56647), -- 217081 (Trader Harthan)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 261036, 0, 0, 0, 0, 0, 0, 0, 56647); -- 223533 (Custodian Khubon)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35039 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=34051 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=34926 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35039, @NPCTEXTID+0, 56647), -- 223533 (Custodian Khubon)
(34051, @NPCTEXTID+1, 56647), -- 217081 (Trader Harthan)
(34926, @NPCTEXTID+2, 56647); -- 223533 (Custodian Khubon)

DELETE FROM `gossip_menu` WHERE (`MenuID`=36348 AND `TextID`=14126);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(36348, 14126, 56647); -- 219097 (Tarib)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (36348,34926));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(36348, 124235, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56647),
(34926, 122551, 0, 0, 'What does it do?', 0, 0, 0, 35039, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56647);

-- Trainer
DELETE FROM `trainer` WHERE `Id`=1124;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(1124, 2, 'Hello, friend!', 56647);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=1124 AND `SpellId` IN (423353,265838));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(1124, 423353, 950000, 186, 1, 0, 0, 0, 68, 56647), -- No Faction found! MoneyCost not recalculated!
(1124, 265838, 10, 0, 0, 0, 0, 0, 5, 56647); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `creature_trainer` WHERE (`CreatureID`=219097 AND `MenuID`=36348 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(219097, 1124, 36348, 0);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=219096 AND `item`=226202 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219096 AND `item`=212754 AND `ExtendedCost`=8502 AND `type`=1) OR (`entry`=219096 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219096 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219096, 4, 226202, 0, 0, 1, 0, 0, 56647), -- Echoing Flux
(219096, 3, 212754, 0, 8502, 1, 0, 0, 56647), -- Crystalforged Cauldron
(219096, 2, 2901, 0, 0, 1, 0, 0, 56647), -- Mining Pick
(219096, 1, 5956, 0, 0, 1, 0, 0, 56647); -- Blacksmith Hammer

-- Path for Oathsworn Peacekeeper
SET @MOVERGUID := @CGUID+32;
SET @ENTRY := 219014;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Peacekeeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2471.9011, -2526.9045, 181.46301, NULL, 0),
(@PATH, 1, 2453.962, -2527.316, 181.41336, NULL, 0),
(@PATH, 2, 2440.8665, -2512.073, 181.41336, NULL, 0),
(@PATH, 3, 2440.198, -2495.2483, 181.41336, NULL, 0),
(@PATH, 4, 2442.9966, -2479.8386, 181.4142, NULL, 0),
(@PATH, 5, 2456.5312, -2470.5503, 181.444, NULL, 0),
(@PATH, 6, 2472.7102, -2470.8315, 181.46553, NULL, 0),
(@PATH, 7, 2488.3264, -2479.7622, 181.46548, NULL, 0),
(@PATH, 8, 2487.5574, -2497.1165, 181.46547, NULL, 0),
(@PATH, 9, 2502.8264, -2513.3281, 181.52826, 2.2913, 25811),
(@PATH, 10, 2480.8733, -2520.29, 181.4655, NULL, 0);

UPDATE `creature` SET `position_x`=2471.9011, `position_y`=-2526.9045, `position_z`=181.46301, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');

-- Path for Oathsworn Peacekeeper
SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 219014;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Peacekeeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2370.5913, -2593.4724, 181.41333, NULL, 0),
(@PATH, 1, 2375.9102, -2621.8845, 181.41336, NULL, 0),
(@PATH, 2, 2381.3857, -2629.741, 181.42548, NULL, 0),
(@PATH, 3, 2401.98, -2615.71, 181.66687, 0.7795, 6354),
(@PATH, 4, 2383.34, -2632.267, 181.46329, NULL, 0),
(@PATH, 5, 2376.6213, -2640.5562, 181.44797, NULL, 0),
(@PATH, 6, 2363.077, -2655.6418, 190.2953, NULL, 0),
(@PATH, 7, 2353.0095, -2665.3606, 190.14212, NULL, 0),
(@PATH, 8, 2365.1482, -2677.629, 190.1421, NULL, 0),
(@PATH, 9, 2356.28, -2686.47, 190.1421, NULL, 0),
(@PATH, 10, 2365.4333, -2677.3447, 190.1421, NULL, 0),
(@PATH, 11, 2353.4001, -2665.365, 190.1421, NULL, 0),
(@PATH, 12, 2363.3572, -2655.9138, 190.28464, NULL, 0),
(@PATH, 13, 2376.979, -2640.7644, 181.45198, NULL, 0),
(@PATH, 14, 2376.2844, -2621.7878, 181.41335, NULL, 0),
(@PATH, 15, 2371.1309, -2593.4304, 181.4133, NULL, 0),
(@PATH, 16, 2371.7373, -2568.6733, 181.41336, NULL, 0),
(@PATH, 17, 2390.492, -2543.8577, 181.41315, NULL, 0),
(@PATH, 18, 2404.3704, -2528.5574, 181.41336, NULL, 0),
(@PATH, 19, 2419.951, -2523.733, 181.41336, NULL, 0),
(@PATH, 20, 2464.8542, -2523.702, 181.45354, NULL, 0),
(@PATH, 21, 2464.97, -2532.51, 181.41336, 4.7115, 6537),
(@PATH, 22, 2419.924, -2523.5552, 181.41336, NULL, 0),
(@PATH, 23, 2404.258, -2528.3801, 181.41336, NULL, 0),
(@PATH, 24, 2390.1921, -2543.6077, 181.41315, NULL, 0),
(@PATH, 25, 2371.2837, -2568.5142, 181.41335, NULL, 0);

UPDATE `creature` SET `position_x`=2370.5913, `position_y`=-2593.4724, `position_z`=181.41333, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');
