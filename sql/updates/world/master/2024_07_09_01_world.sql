SET @CGUID := 9004277;
SET @OGUID := 9003941;

SET @NPCTEXTID := 590122;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 216458, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1725.3941650390625, 6924.61376953125, 180.0595550537109375, 2.08168959617614746, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Sparring Dummy (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+1, 216675, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1695.3646240234375, 6932.78125, 188.2431182861328125, 1.522490859031677246, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Resting Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+2, 216274, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1733.5867919921875, 6936.7490234375, 179.9481658935546875, 3.26306462287902832, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Bel'ameth Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+3, 216676, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1754.205322265625, 6981.67431640625, 175.96343994140625, 5.145911216735839843, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Sparring Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 216274, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1729.1336669921875, 6956.45166015625, 179.5142974853515625, 3.26306462287902832, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Bel'ameth Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+5, 212497, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1759.1024169921875, 6902.376953125, 182.93621826171875, 4.270366668701171875, 120, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 55461), -- Bloompaw Rabbit (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+6, 216674, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1699.6024169921875, 6936.45068359375, 180.9408416748046875, 1.001022577285766601, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Sparring Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+7, 216674, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1698.157958984375, 6938.91162109375, 180.9408416748046875, 4.181617259979248046, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Sparring Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+8, 216274, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1754.8680419921875, 6865.83837890625, 184.611114501953125, 4.923063278198242187, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Bel'ameth Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+9, 212491, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1820.0870361328125, 6975.78955078125, 165.75775146484375, 2.994378328323364257, 120, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 55461), -- Coastglider Pup (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+10, 216675, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1744.1771240234375, 6980.75, 176.9769287109375, 3.301061630249023437, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Resting Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+11, 216675, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1692.001708984375, 6943.8212890625, 180.940765380859375, 3.141888141632080078, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Resting Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+12, 216270, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1712.6678466796875, 6963.5615234375, 179.4542999267578125, 4.924420833587646484, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Ravensmith Ta'lir (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: 421496 - Work)
(@CGUID+13, 216274, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1772.01220703125, 6852.884765625, 184.9517974853515625, 5.98280954360961914, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Bel'ameth Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+14, 216675, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1709.4410400390625, 6939.54150390625, 180.940765380859375, 1.312006354331970214, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Resting Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+15, 216674, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1726.6944580078125, 6924.90478515625, 180.081817626953125, 5.315811634063720703, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Sparring Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+16, 212497, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1753.6583251953125, 6859.71826171875, 182.809326171875, 3.524875640869140625, 120, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 55461), -- Bloompaw Rabbit (Area: -Unknown- - Difficulty: 0) CreateObject1
(@CGUID+17, 216676, 2444, 15115, 15115, '0', '0', 0, 0, 1, -1752.816650390625, 6978.67431640625, 176.314178466796875, 2.0043182373046875, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55461), -- Sparring Sentinel (Area: -Unknown- - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+18, 212497, 2444, 15115, 15115, '0', '0', 0, 0, 0, -1696.9293212890625, 6956.607421875, 180.1136016845703125, 5.708446979522705078, 120, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 55461); -- Bloompaw Rabbit (Area: -Unknown- - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Resting Sentinel
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Resting Sentinel
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 743, 0, 0, 0, 0, ''), -- Resting Sentinel
(@CGUID+14, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Resting Sentinel

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 421761, 2444, 15115, 15115, '0', '0', 0, -1684.2066650390625, 7124.2724609375, 202.23785400390625, 0.95120316743850708, 0, 0, 0.457873344421386718, 0.889017403125762939, 120, 255, 1, 55461), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+1, 421762, 2444, 15115, 15115, '0', '0', 0, -1673.0850830078125, 7134.0712890625, 202.157989501953125, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 55461), -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+2, 421766, 2444, 15115, 15115, '0', '0', 0, -1683.673583984375, 6947.2509765625, 188.221649169921875, 4.380779743194580078, 0, 0, -0.81411457061767578, 0.580704271793365478, 120, 255, 1, 55461); -- Bench (Area: -Unknown- - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=1971, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216273; -- Bel'ameth Huntress
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216759; -- Commander Mar'alith
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216748; -- Lysander Starshade
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=216792; -- Vannara
UPDATE `creature_template` SET `faction`=1971, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216724; -- Saddled Stagwing
UPDATE `creature_template` SET `faction`=1971, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216270; -- Ravensmith Ta'lir
UPDATE `creature_template` SET `faction`=1971, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry` IN (216674, 216676); -- Sparring Sentinel
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=212500; -- Dutiful Tender
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=216790; -- Alennah Starsong
UPDATE `creature_template` SET `faction`=1971, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=216675; -- Resting Sentinel
UPDATE `creature_template` SET `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=8388609 WHERE `entry`=216458; -- Sparring Dummy

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_training_dummy' WHERE `entry` = 216458; -- Sparring Dummy

DELETE FROM `gameobject_template` WHERE `entry` IN (421761 /*Bench*/, 421762 /*Bench*/, 421766 /*Bench*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(421761, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55461), -- Bench
(421762, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55461), -- Bench
(421766, 7, 85900, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55461); -- Bench

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (216675 /*216675 (Resting Sentinel)*/, 216270 /*216270 (Ravensmith Ta'lir) - Work*/, 216458 /*216458 (Sparring Dummy) - Training Dummy Marker, [DNT] No Parry*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(216675, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 216675 (Resting Sentinel)
(216270, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 216270 (Ravensmith Ta'lir) - Work 421496
(216458, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 349892'); -- 216458 (Sparring Dummy) - Training Dummy Marker; [DNT] No Parry

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (216270,216676));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(216270, 1, 182578, 0, 0, 0, 0, 0, 0, 0, 0, 55461), -- Ravensmith Ta'lir
(216676, 1, 208761, 0, 0, 165199, 0, 0, 0, 0, 0, 55461); -- Sparring Sentinel

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=216270 AND `MenuID`=32034);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(216270, 32034, 55461); -- Ravensmith Ta'lir

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 244975, 0, 0, 0, 0, 0, 0, 0, 55461); -- 216270 (Ravensmith Ta'lir)

DELETE FROM `gossip_menu` WHERE (`MenuID`=32034 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(32034, @NPCTEXTID+0, 55461); -- 216270 (Ravensmith Ta'lir)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=32034 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(32034, 110533, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55461);

-- Trainer
DELETE FROM `creature_trainer` WHERE (`CreatureID`=216270 AND `MenuID`=32034 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(216270, 1080, 32034, 0);

DELETE FROM `trainer` WHERE `Id`=1080;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(1080, 2, 'Greetings, friend.', 55461);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=1080 AND `SpellId` IN (396777,384314,382407,382346,382348,382387,389192,382402,382401,382330,382398,382397,382396,382395,382394,382393,382392,382391,382390,382389,382388,382386,382385,382384,382383,382380,382379,382378,382377,382376,382375,366244,264478));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(1080, 396777, 1600000, 2827, 40, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 384314, 1000000, 2827, 15, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382407, 1000000, 2827, 15, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382346, 1300000, 2827, 25, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382348, 1600000, 2827, 40, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382387, 1700000, 2827, 45, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 389192, 1000000, 2827, 15, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382402, 1400000, 2827, 30, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382401, 1000000, 2827, 25, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382330, 1300000, 2827, 25, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382398, 1300000, 2827, 25, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382397, 1100000, 2827, 20, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382396, 1300000, 2827, 25, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382395, 1100000, 2827, 20, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382394, 1500000, 2827, 35, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382393, 1000000, 2827, 20, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382392, 1100000, 2827, 20, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382391, 1800000, 2827, 50, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382390, 1800000, 2827, 50, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382389, 1800000, 2827, 50, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382388, 1800000, 2827, 50, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382386, 800000, 2827, 15, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382385, 800000, 2827, 15, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382384, 800000, 2827, 15, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382383, 800000, 2827, 15, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382380, 1000000, 2827, 20, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382379, 1100000, 2827, 20, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382378, 800000, 2827, 10, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382377, 1000000, 2827, 15, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382376, 600000, 2827, 5, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 382375, 500000, 2827, 1, 0, 0, 0, 0, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 366244, 1000000, 202, 1, 0, 0, 0, 58, 55461), -- No Faction found! MoneyCost not recalculated!
(1080, 264478, 10, 0, 0, 0, 0, 0, 5, 55461); -- No Faction found! MoneyCost not recalculated!

-- Difficulty
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=55461 WHERE (`DifficultyID`=0 AND `Entry` IN (143622,216512,212109,217143,217142,212491,216710,212497,216251,216539,216274,216778,214196,216707,216462));
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=883, `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=216273 AND `DifficultyID`=0); -- 216273 (Bel'ameth Huntress) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=216759 AND `DifficultyID`=0); -- 216759 (Commander Mar'alith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=55461 WHERE (`Entry`=216748 AND `DifficultyID`=0); -- 216748 (Lysander Starshade) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=805306368, `VerifiedBuild`=55461 WHERE (`Entry`=216792 AND `DifficultyID`=0); -- 216792 (Vannara) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2078, `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=216724 AND `DifficultyID`=0); -- 216724 (Saddled Stagwing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `StaticFlags3`=33554432, `VerifiedBuild`=55461 WHERE (`Entry`=216270 AND `DifficultyID`=0); -- 216270 (Ravensmith Ta'lir) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=883, `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=216674 AND `DifficultyID`=0); -- 216674 (Sparring Sentinel) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=883, `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=216676 AND `DifficultyID`=0); -- 216676 (Sparring Sentinel) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2078, `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=212500 AND `DifficultyID`=0); -- 212500 (Dutiful Tender) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=805306368, `VerifiedBuild`=55461 WHERE (`Entry`=216790 AND `DifficultyID`=0); -- 216790 (Alennah Starsong) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=883, `StaticFlags1`=268435456, `VerifiedBuild`=55461 WHERE (`Entry`=216675 AND `DifficultyID`=0); -- 216675 (Resting Sentinel) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=536871168, `VerifiedBuild`=55461 WHERE (`Entry`=216458 AND `DifficultyID`=0); -- 216458 (Sparring Dummy) - Sessile, Floating

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (117017, 114249, 116741, 116992, 116989, 114247, 116990, 116644);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(117017, 0.388999998569488525, 1.5, 0, 55461),
(114249, 0.388999998569488525, 1.5, 0, 55461),
(116741, 0.466800004243850708, 1.80000007152557373, 0, 55461),
(116992, 0.305999994277954101, 1.5, 0, 55461),
(116989, 0.305999994277954101, 1.5, 0, 55461),
(114247, 0.305999994277954101, 1.5, 0, 55461),
(116990, 0.305999994277954101, 1.5, 0, 55461),
(116644, 0.408392846584320068, 0, 0, 55461);

UPDATE `creature_model_info` SET `VerifiedBuild`=55461 WHERE `DisplayID` IN (116851, 102069, 116849, 100359, 116848, 116850);

-- Ravensmith Ta'lir smart ai
SET @ENTRY := 216270;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 34, 0, 100, 0, 2, 4, 0, 0, 80, 21627000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list id #Ravensmith Ta\'lir #0 (21627000) (update out of combat)'),
(@ENTRY, 0, 1, 0, '', 34, 0, 100, 0, 2, 9, 0, 0, 80, 21627001, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 9 - Self: Start timed action list id #Ravensmith Ta\'lir #1 (21627001) (update out of combat)'),
(@ENTRY, 0, 2, 0, '', 34, 0, 100, 0, 2, 10, 0, 0, 80, 21627002, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 10 - Self: Start timed action list id #Ravensmith Ta\'lir #2 (21627002) (update out of combat)');

-- Timed list 21627000 smart ai
SET @ENTRY := 21627000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set stand state to KNEEL'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Remove stand state KNEEL');

-- Timed list 21627001 smart ai
SET @ENTRY := 21627001;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 421496, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 421496 on self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 11000, 11000, 0, 0, 28, 421496, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Remove aura due to spell  421496');

-- Timed list 21627002 smart ai
SET @ENTRY := 21627002;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 421496, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 421496 on self'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 7000, 7000, 0, 0, 28, 421496, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7 seconds - Self: Remove aura due to spell  421496');

-- Path for Ravensmith Tal'ir
SET @ENTRY := 216270;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Ravensmith Ta''lir - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1713.354, 6964.286, 179.4502, NULL, 0),
(@PATH, 1, -1716.773, 6964.987, 179.4457, NULL, 0),
(@PATH, 2, -1719.96, 6965.412, 179.4667, NULL, 0),
(@PATH, 3, -1721.806, 6968.408, 179.4949, NULL, 0),
(@PATH, 4, -1721.875, 6970.304, 179.5261, NULL, 5332),
(@PATH, 5, -1723.677, 6966.156, 179.6047, NULL, 0),
(@PATH, 6, -1724.385, 6963.247, 179.498, NULL, 0),
(@PATH, 7, -1723.458, 6960.532, 179.4515, NULL, 0),
(@PATH, 8, -1721.84, 6959.065, 179.445, NULL, 0),
(@PATH, 9, -1719.469, 6959.993, 179.4458, NULL, 12971),
(@PATH, 10, -1713.368, 6961.27, 179.4545, NULL, 8644);

UPDATE `creature` SET `position_x`= -1713.354, `position_y`= 6964.286, `position_z`= 179.4502, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+12, @PATH, 1);
