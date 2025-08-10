SET @CGUID := 651504;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90383, 1220, 7334, 7361, '0', 7635, 0, 0, 0, 1067.9097900390625, 6287.228515625, 117.3315887451171875, 5.21183633804321289, 120, 0, 0, 23538, 0, 0, 0, 0, 0, 46455); -- Runas the Shamed

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '180864'); -- Runas the Shamed - 180864 - Hungering

DELETE FROM `creature_queststarter` WHERE (`id`=90383 AND `quest` IN (37860,37959));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(90383, 37860, 46455), -- You Scratch My Back... offered Runas the Shamed
(90383, 37959, 46455); -- The Hunger Returns offered Runas the Shamed

UPDATE `creature_queststarter` SET `VerifiedBuild`=46455 WHERE (`id`=90383 AND `quest`=37857);
UPDATE `creature_questender` SET `VerifiedBuild`=46455 WHERE (`id`=90383 AND `quest`=37959);

UPDATE `creature_template` SET `VerifiedBuild`=46455 WHERE `entry` = 90383;

UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37860; -- You Scratch My Back...
UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37959; -- The Hunger Returns
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46455 WHERE `ID` IN (37860, 37959);


UPDATE `quest_poi` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37860 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=37860 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=37860 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37860 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37860 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=37959 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37959 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37959 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37860 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=37860 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37860 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37860 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37860 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=37959 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=37959 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37959 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=46455 WHERE `ID` IN (37860, 37959);

DELETE FROM `phase_name` WHERE `ID` = 7635;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(7635, 'Cosmetic - See Runas the Shamed in Ley-Ruins of Zarkhenar');

DELETE FROM `phase_area` WHERE `AreaId` = 7361 AND `PhaseId` = 7635;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7361, 7635, 'Cosmetic - See Runas the Shamed in Ley-Ruins of Zarkhenar'); -- Ley-Ruins of Zarkhenar Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 7635 AND `SourceEntry` = 7361);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 7635, 7361, 0, 0, 47, 0, 37857, 2 | 64, 0, 0, 'Apply Phase 7635 if Quest 37857 is completed | rewarded'),
(26, 7635, 7361, 0, 0, 47, 0, 37860, 64, 0, 1, 'Apply Phase 7635 if Quest 37860 is not rewarded');
