SET @CGUID := 10006126;
SET @NPCTEXTID := 600096;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 238147, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2569.741455078125, -2666.140625, 182.435272216796875, 1.599919080734252929, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59538), -- Undermine Engineer (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 1219473 - Goblin Hold KajaCola [DNT])
(@CGUID+1, 238148, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2578.03466796875, -2640.604248046875, 183.3184967041015625, 3.033392667770385742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59538), -- Norb (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 465021 - Goblin Hold Clipboard/notes/paper + write [DNT])
(@CGUID+2, 238155, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2599.303955078125, -2633.62841796875, 182.237518310546875, 0.576675772666931152, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59538), -- Escaped Rat (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+3, 238149, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2576.4697265625, -2640.08154296875, 183.284210205078125, 6.039510250091552734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59538), -- Oathsworn Administrator (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+4, 238147, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2587.375, -2645.604248046875, 183.9819183349609375, 5.102212429046630859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59538), -- Undermine Engineer (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+5, 238147, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2572.533935546875, -2664.270751953125, 182.3651123046875, 2.744896650314331054, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59538), -- Undermine Engineer (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 1219473 - Goblin Hold KajaCola [DNT])
(@CGUID+6, 235403, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2589.3515625, -2638.6181640625, 182.245574951171875, 2.207452774047851562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59538), -- Kenzi (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+7, 238147, 2552, 14771, 15043, '0', 0, 0, 0, 0, 2576.8828125, -2652.239501953125, 184.7718048095703125, 0.272526592016220092, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59538); -- Undermine Engineer (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 1219534 - Hammer & Chisel)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 743, 0, 0, 0, 0, '1219473'), -- Undermine Engineer - 1219473 - Goblin Hold KajaCola [DNT]
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '465021'), -- Norb - 465021 - Goblin Hold Clipboard/notes/paper + write [DNT]
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 1044, 0, 0, 0, 0, ''), -- Undermine Engineer
(@CGUID+5, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1219473'), -- Undermine Engineer - 1219473 - Goblin Hold KajaCola [DNT]
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 728, 14323, 0, 0, 0, '1219534'); -- Undermine Engineer - 1219534 - Hammer & Chisel

-- Delete deprecated spawns
DELETE FROM `creature` WHERE `guid` IN (10002087, 10002096, 10002095);
DELETE FROM `creature_addon` WHERE `guid` IN (10002087, 10002096, 10002095);

-- Update positions
UPDATE `creature` SET `position_x`= 2560.950439453125, `position_y`= -2646.991455078125, `position_z`= 181.51141357421875, `orientation`= 0.542080581188201904 WHERE `guid` = 10002097;
UPDATE `creature` SET `position_x`= 2561.257080078125, `position_y`= -2648.59375, `position_z`= 181.493316650390625, `orientation`= 6.231285572052001953 WHERE `guid` = 10002098;
UPDATE `creature` SET `position_x`= 2547.741455078125, `position_y`= -2656.333251953125, `position_z`= 183.3506927490234375, `orientation`= 1.511825442314147949 WHERE `guid` = 10002090;
UPDATE `creature` SET `position_x`= 2556.053955078125, `position_y`= -2657.31591796875, `position_z`= 182.222930908203125, `orientation`= 3.646399974822998046 WHERE `guid` = 10002101;
UPDATE `creature` SET `position_x`= 2554.639892578125, `position_y`= -2644.6650390625, `position_z`= 181.483184814453125, `orientation`= 3.763212442398071289 WHERE `guid` = 10002105;

-- Template
UPDATE `creature_template` SET `faction`=3476, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=235403; -- Kenzi
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=238149; -- Oathsworn Administrator
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=238155; -- Escaped Rat
UPDATE `creature_template` SET `faction`=3476, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=238148; -- Norb
UPDATE `creature_template` SET `faction`=3476, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=238147; -- Undermine Engineer

DELETE FROM `gameobject_template` WHERE `entry`=495190;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(495190, 5, 77463, 'Bronze Dragon Banner', '', '', '', 0.349999994039535522, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59538); -- Bronze Dragon Banner

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59538 WHERE (`Entry`=235403 AND `DifficultyID`=0); -- 235403 (Kenzi) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=59538 WHERE (`Entry`=238149 AND `DifficultyID`=0); -- 238149 (Oathsworn Administrator) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=59538 WHERE (`Entry`=238155 AND `DifficultyID`=0); -- 238155 (Escaped Rat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59538 WHERE (`Entry`=238148 AND `DifficultyID`=0); -- 238148 (Norb) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2888, `StaticFlags1`=0x10000000, `VerifiedBuild`=59538 WHERE (`Entry`=238147 AND `DifficultyID`=0); -- 238147 (Undermine Engineer) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=238148 AND `MenuID`=38061) OR (`CreatureID`=238149 AND `MenuID`=38063);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(238148, 38061, 59538), -- Norb
(238149, 38063, 59538); -- Oathsworn Administrator

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 281437, 0, 0, 0, 0, 0, 0, 0, 59538), -- 238148 (Norb)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 281448, 0, 0, 0, 0, 0, 0, 0, 59538); -- 238149 (Oathsworn Administrator)

DELETE FROM `gossip_menu` WHERE (`MenuID`=38061 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=38063 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(38061, @NPCTEXTID+0, 59538), -- 238148 (Norb)
(38063, @NPCTEXTID+1, 59538); -- 238149 (Oathsworn Administrator)

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (125913, 125319, 125825, 120520, 126362, 125318);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(125913, 0.305999994277954101, 1.5, 0, 59538),
(125319, 0.305999994277954101, 1.5, 0, 59538),
(125825, 0.305999994277954101, 1.5, 0, 59538),
(120520, 0.158240109682083129, 0.300000011920928955, 0, 59538),
(126362, 0.305999994277954101, 1.5, 0, 59538),
(125318, 0.305999994277954101, 1.5, 0, 59538);

UPDATE `creature_model_info` SET `VerifiedBuild`=59538 WHERE `DisplayID`=118429;
