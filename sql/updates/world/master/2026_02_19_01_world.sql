SET @CGUID := 9004557;

SET @NPCTEXTID := 590123;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 209790, 0, 1519, 9171, '0', 23766, 0, 0, 1, -8176.8369140625, 804.3125, 74.38509368896484375, 4.432802200317382812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65940), -- Virtos (Area: Stormwind Embassy - Difficulty: 0) CreateObject1
(@CGUID+1, 209790, 0, 1519, 1519, '0', 21820, 0, 0, 1, -8427.71875, 368.541656494140625, 135.511993408203125, 2.98610234260559082, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65940); -- Virtos (Area: Stormwind City - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (209790);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(209790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 209790 (Virtos)

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=209790; -- Virtos

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=65940 WHERE (`Entry`=209790 AND `DifficultyID`=0); -- 209790 (Virtos) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (23766,21820);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23766, 'Cosmetic - See Virtos at Stormwind Embassy'),
(21820, 'Cosmetic - See Virtos at Stormwind Keep');

DELETE FROM `phase_area` WHERE `PhaseId` IN (23766,21820);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 23766, 'See Virtos at Stormwind Embassy'),
(1519, 21820, 'See Virtos at Stormwind Keep');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=209790 AND `MenuID`=32431);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(209790, 32431, 65940); -- Virtos

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 246121, 0, 0, 0, 0, 0, 0, 0, 65940); -- 209790 (Virtos)

DELETE FROM `gossip_menu` WHERE (`MenuID`=32431 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(32431, @NPCTEXTID+0, 65940); -- 209790 (Virtos)

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=209790 AND `quest`=77408);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(209790, 77408, 65940); -- Prophecy Stirs offered by Virtos

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (142161, 91002);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(142161, 0.60000002384185791, 1.20000004768371582, 0, 65940),
(91002, 0.347222000360488891, 1.5, 0, 65940);

UPDATE `creature_model_info` SET `VerifiedBuild`=65940 WHERE `DisplayID` IN (134, 42722, 42720, 72178, 83231, 115637, 82854, 83234, 82914, 257, 82899, 82842, 221, 82867, 113854, 83230, 41667, 44820, 82847, 19732, 121842, 82895, 100577, 93414, 5131, 82884, 88443, 21342, 99391, 104833, 107223, 93410, 81532, 71224, 79381, 60711, 118473, 44819, 121844, 83233, 121843, 82874, 82918, 115867, 18890, 87971, 107225, 68845, 93415, 24877, 100576, 71286, 82923, 107226, 111029, 93411, 328, 5446, 83108, 93409, 46929, 3167, 107470, 82928, 80978, 115695, 82875, 121841, 77656, 102040, 68729, 27823, 111025, 91005, 106564, 98008, 37884, 91006, 80349, 93413, 82897, 106563, 11686, 83236, 99389);
UPDATE `creature_model_info` SET `BoundingRadius`=1.777777910232543945, `VerifiedBuild`=65940 WHERE `DisplayID`=87972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955, `VerifiedBuild`=65940 WHERE `DisplayID`=70663;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `VerifiedBuild`=65940 WHERE `DisplayID`=79380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216235846281051635, `CombatReach`=0.779591858386993408, `VerifiedBuild`=65940 WHERE `DisplayID` IN (5585, 63716);
