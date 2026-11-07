SET @CGUID := 10006592;

SET @NPCTEXTID := 600106;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+19;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 217543, 2552, 14717, 14784, '0', 0, 0, 0, 0, 3513.189208984375, -3393.451416015625, 189.0128936767578125, 5.522217750549316406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tordrin (Area: Rambleshire - Difficulty: 0) CreateObject1 (Auras: 456876 - Hidden Fear Aura [DNT])
(@CGUID+1, 215563, 2601, 14795, 14796, '0', 0, 0, 0, 0, 2226.45654296875, -2731.439208984375, 427.31365966796875, 5.094774246215820312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Igram Underwing (Area: Gundargaz - Difficulty: 0) CreateObject1
(@CGUID+2, 218388, 2601, 14795, 14808, '0', 0, 0, 0, 0, 1524.90625, -3782.47216796875, 259.804718017578125, 6.028645515441894531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Milgrit Stonefeather (Area: The Rumbling Wastes - Difficulty: 0) CreateObject1
(@CGUID+3, 224940, 2601, 14795, 0, '0', 0, 0, 0, 0, 749.890625, -3546.482666015625, 175.1983489990234375, 4.299605369567871093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Kargen Ironbrow (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+4, 224884, 2601, 14795, 0, '0', 0, 0, 0, 0, 75.11284637451171875, -4018.541748046875, 128.93475341796875, 3.271137475967407226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Clixi Fastfare (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+5, 228137, 2601, 14795, 15528, '0', 0, 0, 0, 0, -178.265625, -4809.92529296875, -117.974143981933593, 4.746461868286132812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Jix (Area: Gutterville - Difficulty: 0) CreateObject1
(@CGUID+6, 218298, 2601, 14838, 14848, '0', 0, 0, 0, 0, 1813.3853759765625, -1525.4288330078125, -141.310440063476562, 0.729088306427001953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Vellas Tearen (Area: The Aegis Wall - Difficulty: 0) CreateObject1
(@CGUID+7, 217639, 2601, 14838, 0, '0', 0, 0, 0, 1, 2470.32470703125, -1202.8177490234375, -53.0380439758300781, 4.445613861083984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Auro Flitter (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+8, 206537, 2601, 14838, 0, '0', 0, 0, 0, 0, 3224.82470703125, -693.045166015625, 10.65821456909179687, 0.589797496795654296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Rubaen Hillhelm (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+9, 218295, 2601, 14838, 15107, '0', 0, 0, 0, 0, 2686.983642578125, 382.09375, 61.79377365112304687, 6.225689888000488281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Bastian Wynfall (Area: Lorel's Crossing - Difficulty: 0) CreateObject1
(@CGUID+10, 218323, 2601, 14838, 15337, '0', 0, 0, 0, 0, 3076.643310546875, 983.4617919921875, 515.4781494140625, 2.122202634811401367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tristan Lyte (Area: Priory of the Sacred Flame - Difficulty: 0) CreateObject1
(@CGUID+11, 218305, 2601, 14838, 14917, '0', 0, 0, 0, 0, 2029.828125, 947.75518798828125, 220.4992523193359375, 0.879575550556182861, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Anje Noon (Area: Mereldar - Difficulty: 0) CreateObject1
(@CGUID+12, 218300, 2601, 14838, 0, '0', 0, 0, 0, 1, 1546.045166015625, 10.80902767181396484, -47.3251228332519531, 6.087027549743652343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Gear Flamepierce (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 458825 - Visual: Unsheathe + Ready 2h)
(@CGUID+13, 218304, 2601, 14838, 14928, '0', 0, 0, 0, 0, 993.67535400390625, 1040.1197509765625, 45.1142425537109375, 6.05847787857055664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- 'Red' Fearon (Area: Light's Redoubt - Difficulty: 0) CreateObject1
(@CGUID+14, 208384, 2601, 14752, 14958, '0', 0, 0, 0, 0, -796.19097900390625, 880.19793701171875, -950.08648681640625, 5.179391384124755859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Courier Nailen (Area: Wildcamp Or'lay - Difficulty: 0) CreateObject1
(@CGUID+15, 216972, 2601, 14752, 14765, '0', 0, 0, 0, 0, -1545.4305419921875, -588.5086669921875, -1354.258056640625, 5.088594436645507812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Courier Lyan (Area: Twitching Gorge - Difficulty: 0) CreateObject1
(@CGUID+16, 209330, 2601, 14753, 14791, '0', 0, 0, 0, 0, -2142.635498046875, -978.86114501953125, -1325.3076171875, 4.994460105895996093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Tekazza of the Aimless Few (Area: Umbral Bazaar - Difficulty: 0) CreateObject1
(@CGUID+17, 216979, 2601, 14752, 0, '0', 0, 0, 0, 0, -1406.4566650390625, -2814.314208984375, -1180.927001953125, 4.782161712646484375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Roughrider Tany (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+18, 207470, 2601, 14752, 14761, '0', 0, 0, 0, 0, -607.859375, -1440.9427490234375, -1087.6953125, 5.772234439849853515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wings of the Widow (Area: Silken Ward - Difficulty: 0) CreateObject1
(@CGUID+19, 216973, 2601, 14752, 14952, '0', 0, 0, 0, 0, 692.0086669921875, -1655.5694580078125, -979.414306640625, 1.66081857681274414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568); -- Courier Aidal (Area: Crawling Chasm - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (217543,218300,206537,217639,209330);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(217543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '456876'), -- 217543 (Tordrin) - Hidden Fear Aura [DNT]
(218300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '458825'), -- 218300 (Gear Flamepierce) - Visual: Unsheathe + Ready 2h
(206537, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 206537 (Rubaen Hillhelm)
(217639, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 217639 (Auro Flitter)
(209330, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, ''); -- 209330 (Tekazza of the Aimless Few)

-- Template
UPDATE `creature_template` SET `faction`=3407, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=217543; -- Tordrin
UPDATE `creature_template` SET `faction`=3398, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=215563; -- Igram Underwing
UPDATE `creature_template` SET `faction`=3398, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=218388; -- Milgrit Stonefeather
UPDATE `creature_template` SET `faction`=35, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=224940; -- Kargen Ironbrow
UPDATE `creature_template` SET `faction`=35, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=224884; -- Clixi Fastfare
UPDATE `creature_template` SET `faction`=3483, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=228137; -- Jix
UPDATE `creature_template` SET `faction`=3395, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=218298; -- Vellas Tearen
UPDATE `creature_template` SET `faction`=3364, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=217639; -- Auro Flitter
UPDATE `creature_template` SET `faction`=3364, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=206537; -- Rubaen Hillhelm
UPDATE `creature_template` SET `faction`=3395, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=218295; -- Bastian Wynfall
UPDATE `creature_template` SET `faction`=3395, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=218323; -- Tristan Lyte
UPDATE `creature_template` SET `faction`=3395, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=218305; -- Anje Noon
UPDATE `creature_template` SET `faction`=3395, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=218300; -- Gear Flamepierce
UPDATE `creature_template` SET `faction`=3395, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=218304; -- 'Red' Fearon
UPDATE `creature_template` SET `faction`=35, `npcflag`=8192, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=208384; -- Courier Nailen
UPDATE `creature_template` SET `faction`=3364, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=216972; -- Courier Lyan
UPDATE `creature_template` SET `faction`=3403, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=209330; -- Tekazza of the Aimless Few
UPDATE `creature_template` SET `faction`=3475, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4800 WHERE `entry`=216979; -- Roughrider Tany
UPDATE `creature_template` SET `faction`=3475, `npcflag`=8192, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x4800 WHERE `entry`=207470; -- Wings of the Widow
UPDATE `creature_template` SET `faction`=3364, `npcflag`=8193, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=216973; -- Courier Aidal

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=217543 AND `DifficultyID`=0); -- 217543 (Tordrin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=215563 AND `DifficultyID`=0); -- 215563 (Igram Underwing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=218388 AND `DifficultyID`=0); -- 218388 (Milgrit Stonefeather) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=224940 AND `DifficultyID`=0); -- 224940 (Kargen Ironbrow) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=224884 AND `DifficultyID`=0); -- 224884 (Clixi Fastfare) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=228137 AND `DifficultyID`=0); -- 228137 (Jix) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=218298 AND `DifficultyID`=0); -- 218298 (Vellas Tearen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=217639 AND `DifficultyID`=0); -- 217639 (Auro Flitter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=206537 AND `DifficultyID`=0); -- 206537 (Rubaen Hillhelm) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=218295 AND `DifficultyID`=0); -- 218295 (Bastian Wynfall) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=218323 AND `DifficultyID`=0); -- 218323 (Tristan Lyte) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=218305 AND `DifficultyID`=0); -- 218305 (Anje Noon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=218300 AND `DifficultyID`=0); -- 218300 (Gear Flamepierce) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2799, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=218304 AND `DifficultyID`=0); -- 218304 ('Red' Fearon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=208384 AND `DifficultyID`=0); -- 208384 (Courier Nailen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=216972 AND `DifficultyID`=0); -- 216972 (Courier Lyan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=209330 AND `DifficultyID`=0); -- 209330 (Tekazza of the Aimless Few) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=216979 AND `DifficultyID`=0); -- 216979 (Roughrider Tany) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=207470 AND `DifficultyID`=0); -- 207470 (Wings of the Widow) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2462, `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=216973 AND `DifficultyID`=0); -- 216973 (Courier Aidal) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=217543 AND `MenuID`=6944) OR (`MenuID`=6944 AND `CreatureID` IN (228137,224940,218388)) OR (`MenuID`=35111 AND `CreatureID`=224884) OR (`MenuID`=34038 AND `CreatureID`=215563) OR (`MenuID`=6944 AND `CreatureID` IN (218304,218300,218305,218323,218295,206537,218298)) OR (`MenuID`=34809 AND `CreatureID`=217639) OR (`MenuID`=6944 AND `CreatureID` IN (216979,209330,216972));
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(217543, 6944, 60568), -- Tordrin
(228137, 6944, 60568), -- Jix
(224884, 35111, 60568), -- Clixi Fastfare
(224940, 6944, 60568), -- Kargen Ironbrow
(218388, 6944, 60568), -- Milgrit Stonefeather
(215563, 34038, 60568), -- Igram Underwing
(218304, 6944, 60568), -- 'Red' Fearon
(218300, 6944, 60568), -- Gear Flamepierce
(218305, 6944, 60568), -- Anje Noon
(218323, 6944, 60568), -- Tristan Lyte
(218295, 6944, 60568), -- Bastian Wynfall
(206537, 6944, 60568), -- Rubaen Hillhelm
(217639, 34809, 60568), -- Auro Flitter
(218298, 6944, 60568), -- Vellas Tearen
(216979, 6944, 60568), -- Roughrider Tany
(209330, 6944, 60568), -- Tekazza of the Aimless Few
(216972, 6944, 60568); -- Courier Lyan

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 265701, 0, 0, 0, 0, 0, 0, 0, 60568), -- 224884 (Clixi Fastfare)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 16775, 0, 0, 0, 0, 0, 0, 0, 60568), -- 215563 (Igram Underwing)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 265705, 0, 0, 0, 0, 0, 0, 0, 60568); -- 224884 (Clixi Fastfare)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34809 AND `TextID`=7778);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34809, 7778, 60568); -- 217639 (Auro Flitter)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35111 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=34038 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=35112 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35111, @NPCTEXTID+0, 60568), -- 224884 (Clixi Fastfare)
(34038, @NPCTEXTID+1, 60568), -- 215563 (Igram Underwing)
(35112, @NPCTEXTID+2, 60568); -- 224884 (Clixi Fastfare)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=35111 AND `OptionID` IN (1,0)) OR (`MenuID`=34038 AND `OptionID`=0) OR (`MenuID`=34809 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(35111, 122683, 1, 0, 'A goblin with a cloudrook?', 265703, 0, 0, 35112, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60568),
(34038, 121194, 0, 2, 'Show me where I can fly.', 12271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60568),
(35111, 122682, 0, 2, 'Show me where I can fly.', 12271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60568),
(34809, 122293, 0, 2, 'Show me where I can fly.', 12271, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60568);

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (125593, 126580, 125613, 125654, 125664, 127172, 126578, 125735, 125617, 126579, 123782, 125596, 125640, 126043, 126789, 126788, 120037, 126790, 126787, 122463, 115396, 115402, 125733, 125732, 125403, 123567, 123566, 125856, 112247);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(125593, 0.305999994277954101, 1.5, 0, 60568),
(126580, 0.305999994277954101, 1.5, 0, 60568),
(125613, 0.305999994277954101, 1.5, 0, 60568),
(125654, 0.305999994277954101, 1.5, 0, 60568),
(125664, 0.305999994277954101, 1.5, 0, 60568),
(127172, 0.305999994277954101, 1.5, 0, 60568),
(126578, 0.305999994277954101, 1.5, 0, 60568),
(125735, 0.305999994277954101, 1.5, 0, 60568),
(125617, 0.305999994277954101, 1.5, 0, 60568),
(126579, 0.305999994277954101, 1.5, 0, 60568),
(123782, 0.305999994277954101, 1.5, 0, 60568),
(125596, 0.305999994277954101, 1.5, 0, 60568),
(125640, 0.305999994277954101, 1.5, 0, 60568),
(126043, 0.305999994277954101, 1.5, 0, 60568),
(126789, 0.305999994277954101, 1.5, 0, 60568),
(126788, 0.305999994277954101, 1.5, 0, 60568),
(120037, 2.637041807174682617, 3, 0, 60568),
(126790, 0.305999994277954101, 1.5, 0, 60568),
(126787, 0.305999994277954101, 1.5, 0, 60568),
(122463, 2.928663253784179687, 3.75, 0, 60568),
(115396, 0.802829265594482421, 0.5, 0, 60568),
(115402, 0.802829265594482421, 0.5, 0, 60568),
(125733, 0.305999994277954101, 1.5, 0, 60568),
(125732, 0.305999994277954101, 1.5, 0, 60568),
(125403, 0.305999994277954101, 1.5, 0, 60568),
(123567, 0.305999994277954101, 1.5, 0, 60568),
(123566, 0.305999994277954101, 1.5, 0, 60568),
(125856, 0.372000008821487426, 1.20000004768371582, 0, 60568),
(112247, 2.334235191345214843, 1, 0, 60568);

UPDATE `creature_model_info` SET `VerifiedBuild`=60568 WHERE `DisplayID` IN (112385, 125738, 125739, 125736, 103326, 115009, 112410, 117450, 112395, 117451, 120369, 117116, 119349, 120203, 120461, 120790, 119345, 124547, 85709, 119302, 110132, 85707, 119372, 119299, 119352, 119295, 119346, 119296, 85708, 119298, 124548, 120154, 110134, 119350, 124551, 119300, 119347, 108077, 119357, 119297, 119344, 119363, 82892, 82891, 82890, 120315, 88201, 118847, 114622, 103338, 103811, 103340, 115404, 103831, 114837, 119009, 115252, 91864, 120684, 115405, 115250, 115257, 108830, 102523, 103499, 115406, 102512, 102375, 114919, 114920, 115407, 115403, 115253, 81234, 117085, 114365, 115962, 119234, 120186, 117068, 114619, 119235, 120245, 114779, 116567, 120326, 115409, 120223, 120029, 113982, 120322, 116586, 120587, 120166, 117067, 118395, 120248, 115375, 110445, 116506, 110446, 116434, 118417, 118420, 118421, 110444, 118598, 117971, 116450, 118416, 117462, 117460, 121738, 118087, 119522, 114361, 117440, 117441, 110447, 117443, 117442, 118545, 104521, 110442, 119696, 110448, 117461, 122419, 107720, 110431, 107719, 118147, 85199, 75596, 118548, 118547, 115372, 37604, 119707, 119708, 116509, 116451, 22452, 45879, 112722, 109507, 112391, 115377, 112723, 112388, 109510, 120999, 75598, 117198, 118231, 108832, 117558, 118229, 119694, 57548, 108831, 121153, 121154, 103342, 116218, 118892, 112397, 117939, 119704, 109505, 117940, 118379, 112398, 103500, 112413, 122664, 116635, 119703, 116677, 112446, 116634, 114701, 114691, 116631, 112414, 114697, 114712, 114087, 120415, 112411, 114696, 114703, 118223, 116541, 114694, 118894, 112457, 114968, 119969, 77406, 42720, 42722, 116633, 119072, 117687, 27823, 115719, 117199, 116632, 119705, 116650, 77405, 120551, 116959, 115505, 77407, 120553, 118575, 114618, 117459, 117203, 114158, 103501, 117831, 114714, 114756, 120416, 115254, 117196, 112387, 120345, 114713, 118072, 117201, 116913, 117207, 118619, 116689, 117195, 117194, 117456, 116911, 15880, 121224, 114855, 117458, 114716, 117127, 114088, 119955, 117200, 114526, 120504, 117519, 117193, 93574, 23767, 120555, 19283, 119550);
UPDATE `creature_model_info` SET `BoundingRadius`=0.919484734535217285, `VerifiedBuild`=60568 WHERE `DisplayID` IN (114556, 116614);
UPDATE `creature_model_info` SET `BoundingRadius`=1.83896946907043457, `CombatReach`=2, `VerifiedBuild`=60568 WHERE `DisplayID`=113941;
UPDATE `creature_model_info` SET `BoundingRadius`=0.504002809524536132, `VerifiedBuild`=60568 WHERE `DisplayID` IN (114832, 114833);
UPDATE `creature_model_info` SET `BoundingRadius`=0.433260679244995117, `VerifiedBuild`=60568 WHERE `DisplayID`=121049;
UPDATE `creature_model_info` SET `CombatReach`=1.049999952316284179, `VerifiedBuild`=60568 WHERE `DisplayID`=52957;
UPDATE `creature_model_info` SET `BoundingRadius`=0.459742367267608642, `VerifiedBuild`=60568 WHERE `DisplayID`=116616;
UPDATE `creature_model_info` SET `BoundingRadius`=1.733876705169677734, `CombatReach`=2.40000009536743164, `VerifiedBuild`=60568 WHERE `DisplayID`=72764;
UPDATE `creature_model_info` SET `BoundingRadius`=0.85656285285949707, `CombatReach`=0.75, `VerifiedBuild`=60568 WHERE `DisplayID` IN (15468, 15467);
UPDATE `creature_model_info` SET `BoundingRadius`=1.83896946907043457, `VerifiedBuild`=60568 WHERE `DisplayID`=116611;
