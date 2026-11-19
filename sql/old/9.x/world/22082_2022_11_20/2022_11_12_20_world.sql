SET @CGUID := 651525;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89023, 1220, 7334, 7357, '0', 4368, 0, 0, 1, 288.520843505859375, 6643.10400390625, 56.12480545043945312, 5.360180377960205078, 120, 0, 0, 15690, 3801, 0, 0, 0, 0, 46455); -- Nightwatcher Idri (Area: Drowned Gardens - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 333, 0, 0, 0, 3, ''); -- Nightwatcher Idri

DELETE FROM `creature_queststarter` WHERE (`id`=89023 AND `quest` IN (37733,37256));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(89023, 37733, 46455), -- Prince Farondis offered Nightwatcher Idri
(89023, 37256, 46455); -- They Came From the Sea offered Nightwatcher Idri

UPDATE `creature_questender` SET `VerifiedBuild`=46455 WHERE (`id`=89023 AND `quest` IN (37256,37690));

UPDATE `creature_template` SET `VerifiedBuild`=46455 WHERE `entry` = 89023;

UPDATE `quest_poi` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37733 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37733 AND `BlobIndex`=0 AND `Idx1`=0);
DELETE FROM `quest_poi_points` WHERE (`QuestID`=37256 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37256 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=37256 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=37256 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=37256 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=37256 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=37256 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=37256 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=37256 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37256 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37256 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(37256, 3, 0, 286, 6683, 56, 46455), -- They Came From the Sea
(37256, 2, 7, -24, 6647, 22, 46455), -- They Came From the Sea
(37256, 2, 6, -24, 6658, 51, 46455), -- They Came From the Sea
(37256, 2, 5, 32, 6784, 53, 46455), -- They Came From the Sea
(37256, 2, 4, 83, 6850, 69, 46455), -- They Came From the Sea
(37256, 2, 3, 200, 6842, 63, 46455), -- They Came From the Sea
(37256, 2, 2, 269, 6798, 90, 46455), -- They Came From the Sea
(37256, 2, 1, 290, 6775, 53, 46455), -- They Came From the Sea
(37256, 2, 0, 179, 6535, -15, 46455), -- They Came From the Sea
(37256, 1, 0, 185, 6866, 72, 46455), -- They Came From the Sea
(37256, 0, 0, 286, 6683, 56, 46455); -- They Came From the Sea

UPDATE `quest_poi_points` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37733 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37733 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=46455 WHERE `ID` IN (37733, 37256);
UPDATE `quest_request_items` SET `VerifiedBuild`=46455 WHERE `ID`=37256;
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46455 WHERE `ID`=37256;

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 4368;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4368, 'Cosmetic - See Nightwatcher Idri at Drowned Gardens');

DELETE FROM `phase_area` WHERE `AreaId` IN (7357, 7352) AND `PhaseId` = 4368;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7357, 4368, 'See Nightwatcher Idri at Drowned Gardens'),
(7352, 4368, 'See Nightwatcher Idri at Drowned Gardens');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4368 AND `SourceEntry`  IN (7357, 7352));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4368, 7357, 0, 0, 47, 0, 37733, 2 | 64, 0, 1, 'Apply Phase 4368 if Quest 37733 is not complete | rewarded'),
(26, 4368, 7352, 0, 0, 47, 0, 37733, 2 | 64, 0, 1, 'Apply Phase 4368 if Quest 37733 is not complete | rewarded');
