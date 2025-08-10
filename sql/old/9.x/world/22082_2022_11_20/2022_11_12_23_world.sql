SET @CGUID := 651528;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 88115, 1220, 7334, 7355, '0', 4270, 0, 0, 1, -10.8506946563720703, 6734.1162109375, 55.6704559326171875, 0.037813689559698104, 120, 0, 0, 3138, 3801, 0, 0, 0, 0, 46455), -- Prince Farondis (Area: Crumbled Palace - Difficulty: 0) (Auras: 177720 - Farondis Channeling)
(@CGUID+1, 88867, 1220, 7334, 7366, '0', 4290, 0, 0, 1, -139.94097900390625, 6418.81787109375, 27.48244285583496093, 4.33477020263671875, 120, 0, 0, 3138, 3801, 0, 0, 0, 0, 46455); -- Prince Farondis (Area: Ruins of Nar'thalas - Difficulty: 0) (Auras: 177720 - Farondis Channeling)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '177720'), -- Prince Farondis - 177720 - Farondis Channeling
(@CGUID+1, 0, 0, 8, 1, 0, 0, 0, 0, 0, '177720'); -- Prince Farondis - 177720 - Farondis Channeling

UPDATE `creature_template` SET `gossip_menu_id`=17377, `VerifiedBuild`=46455 WHERE `entry`=88115; -- Prince Farondis

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `VerifiedBuild`=46455 WHERE `entry`=88867; -- Prince Farondis

UPDATE `quest_poi` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37497 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=37497 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=37497 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37497 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37497 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37497 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37497 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37497 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37497; -- Trailing the Tidestone

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (4270, 4290);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4270, 'Cosmetic - See Prince Farondis at Crumbled Palace'),
(4290, 'Cosmetic - See Prince Farondis at Ruins of Nar\' thalas');

DELETE FROM `phase_area` WHERE `AreaId` = 7334 AND `PhaseId` IN (4270, 4290);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7334, 4270, 'See Prince Farondis at Crumbled Palace'),
(7334, 4290, 'See Prince Farondis at Ruins of Nar\' thalas');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4270, 4290)  AND `SourceEntry` = 7334);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4270, 7334, 0, 0, 47, 0, 37497, 8 | 2 | 64, 0, 1, 'Apply Phase 4270 if Quest 37497 is not in progress | completed | rewarded'),
(26, 4290, 7334, 0, 0, 47, 0, 37497, 2 | 64, 0, 0, 'Apply Phase 4290 if Quest 37497 is completed | rewarded'),
(26, 4290, 7334, 0, 0, 47, 0, 37467, 2 | 64, 0, 1, 'Apply Phase 4290 if Quest 37467 is not completed | rewarded');
