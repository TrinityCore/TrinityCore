SET @OGUID := 400522;

DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 239120, 1220, 7334, 7348, '0', 4317, 0, -482.0625, 6676.9990234375, -2.05414509773254394, 3.468499183654785156, -0.06594800949096679, 0.2011566162109375, -0.96541213989257812, 0.15220479667186737, 120, 255, 1, 46702); -- Okuna Longtusk's Pack (Area: Oceanus Cove - Difficulty: Normal)

UPDATE `gameobject_template` SET `ContentTuningId`=331, `VerifiedBuild`=46702 WHERE `entry`=239120; -- Okuna Longtusk's Pack
UPDATE `gameobject_queststarter` SET `VerifiedBuild`=46702 WHERE (`id`=239120 AND `quest`=37565);
UPDATE `gameobject_questender` SET `VerifiedBuild`=46702 WHERE (`id`=239120 AND `quest`=37538);

UPDATE `quest_template` SET `VerifiedBuild`=46702 WHERE `ID`=37565; -- The Right Weapon for the Job
UPDATE `quest_poi` SET `VerifiedBuild`=46702 WHERE (`QuestID`=37565 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=37565 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=37565 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37565 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46702 WHERE (`QuestID`=37565 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=37565 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=37565 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37565 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=46702 WHERE `ID`=37565;

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 4317;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4317, 'Cosmetic - See Okuna Longtusk\'s Pack at Oceanus Cove');

DELETE FROM `phase_area` WHERE `AreaId` = 7348 AND `PhaseId` = 4317;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7348, 4317, 'See Okuna Longtusk\'s Pack at Oceanus Cove');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4317 AND `SourceEntry` = 7348;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4317, 7348, 0, 0, 47, 0, 37538, 2 | 64, 0, 0, 'Apply Phase 4317 if Quest 37538 is completed | rewarded');
