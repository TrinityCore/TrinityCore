SET @CGUID := 7003087;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 140052, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -998.39410400390625, 1759.467041015625, 126.4007492065429687, 4.206452369689941406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+1, 140052, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -1000.68402099609375, 1761.1614990234375, 126.1938629150390625, 4.206452369689941406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+2, 140053, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -999.63714599609375, 1744.6441650390625, 123.9647293090820312, 3.310779571533203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Druid (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+3, 129168, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -996.72052001953125, 1752.6649169921875, 124.7531890869140625, 3.167483806610107421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Buddy (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: 266099 - Cosmetic - Sleep Zzz)
(@CGUID+4, 140052, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -1002.3021240234375, 1742.3819580078125, 123.4198989868164062, 2.706475734710693359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+5, 129167, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -997.404541015625, 1750.751708984375, 124.5175094604492187, 3.892115116119384765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Muttley (Area: Gol Koval - Difficulty: 0) CreateObject1 (Auras: 266099 - Cosmetic - Sleep Zzz)
(@CGUID+6, 140052, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -999.39581298828125, 1739.217041015625, 123.4240188598632812, 4.128108978271484375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+7, 140052, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -1000.11627197265625, 1747.32470703125, 124.255859375, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+8, 140052, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -998.02606201171875, 1741.9722900390625, 123.96490478515625, 4.128108978271484375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+9, 140052, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -997.15625, 1747.1041259765625, 124.3420181274414062, 4.975757122039794921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+10, 140053, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -993.107666015625, 1736.18408203125, 123.3753585815429687, 2.477457284927368164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Druid (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+11, 140052, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -993.22222900390625, 1741.3125, 124.4580535888671875, 3.163805246353149414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Recovering Ranger (Area: Gol Koval - Difficulty: 0) CreateObject1
(@CGUID+12, 140053, 1643, 8721, 9134, '0', 11264, 0, 0, 0, -993.717041015625, 1733.8819580078125, 123.1188430786132812, 2.700223684310913085, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568); -- Recovering Druid (Area: Gol Koval - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Ranger
(@CGUID+1, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Ranger
(@CGUID+2, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Druid
(@CGUID+3, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '266099'), -- Buddy - 266099 - Cosmetic - Sleep Zzz
(@CGUID+4, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Ranger
(@CGUID+5, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '266099'), -- Muttley - 266099 - Cosmetic - Sleep Zzz
(@CGUID+6, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Ranger
(@CGUID+7, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Ranger
(@CGUID+8, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Ranger
(@CGUID+9, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Ranger
(@CGUID+10, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Druid
(@CGUID+11, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Recovering Ranger
(@CGUID+12, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Recovering Druid

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 11264;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(11264, 'Cosmetic - See Recovering Ranger and Druid');

DELETE FROM `phase_area` WHERE `PhaseId` = 11264;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9134, 11264, 'See See Recovering Ranger and Druid');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 11264 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 11264, 0, 0, 0, 47, 0, 48179, 2|64, 0, 0, 'Apply Phase 11264 if Quest 48179 is complete | rewarded');

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 291638;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(291638, NULL, NULL, NULL, 1, 0);
