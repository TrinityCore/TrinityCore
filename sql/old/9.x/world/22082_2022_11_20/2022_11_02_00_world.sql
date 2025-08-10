SET @CGUID := 651357;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 88863, 1220, 7334, 7348, '0', 4756, 0, 0, 1, -874.58856201171875, 6514.01416015625, 3.743641376495361328, 5.438827037811279296, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46340),
(@CGUID+1, 93475, 1220, 7334, 7348, '0', 4757, 0, 0, 0, -958.78472900390625, 6608.900390625, 0.481153845787048339, 6.001494407653808593, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46340),
(@CGUID+2, 93487, 1220, 7334, 7348, '0', 4761, 0, 0, 0, -787.28125, 6783.0146484375, 5.734499454498291015, 2.305305719375610351, 7200, 0, 0, 58845, 0, 0, 0, 0, 0, 46340),
(@CGUID+3, 93492, 1220, 7334, 7348, '0', 4763, 0, 0, 0, -873.904541015625, 6444.125, 2.796334505081176757, 3.858138561248779296, 7200, 0, 0, 3923, 0, 0, 0, 0, 0, 46340);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 233, 0, 0, 0, 3, '');

UPDATE `creature_template` SET `minlevel` = 45, `maxlevel` = 45 WHERE `entry` IN (88863, 93475, 93487, 93492);

DELETE FROM `creature_queststarter` WHERE (`id`=88863 AND `quest`=38857);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(88863, 38857, 46366);

DELETE FROM `phase_name` WHERE `ID` IN (4756, 4757, 4761, 4763);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4756, 'Cosmetic - See Seska Seafang slaved'),
(4757, 'Cosmetic - See Cleave Thunderhill slaved'),
(4761, 'Cosmetic - See Gentle Rosh slaved'),
(4763, 'Cosmetic - See Grace the Green slaved');

DELETE FROM `phase_area` WHERE `AreaId` = 7348 AND `PhaseId` IN (4756, 4757, 4761, 4763);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7348, 4756, 'See Seska Seafang slaved in Oceanus Cove'),
(7348, 4757, 'See Cleave Thunderhill slaved in Oceanus Cove'),
(7348, 4761, 'See Gentle Rosh slaved in Oceanus Cove'),
(7348, 4763, 'See Grace the Green slaved in Oceanus Cove');

DELETE FROM `creature_template_addon` WHERE `entry` IN (93475, 93487, 93492);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(93475, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(93487, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(93492, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4756, 4757, 4761, 4763)  AND `SourceEntry` = 7348);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4756, 7348, 0, 0, 47, 0, 38857, 8 | 2 | 64, 0, 1, 'Apply Phase 4756 if Quest 38857 is not in progress | complete | rewarded'),
(26, 4757, 7348, 0, 0, 47, 0, 38857, 64, 0, 1, 'Apply Phase 4757 if Quest 38857 is not rewarded'),
(26, 4757, 7348, 0, 0, 48, 0, 278523, 0, 1, 1, 'Apply Phase 4757 if player has not quest objective done: Cleave Thunderhill rescued'),
(26, 4761, 7348, 0, 0, 47, 0, 38857, 64, 0, 1, 'Apply Phase 4761 if Quest 38857 is not rewarded'),
(26, 4761, 7348, 0, 0, 48, 0, 278524, 0, 1, 1, 'Apply Phase 4761 if player has not quest objective done: Gentle Rosh rescued'),
(26, 4763, 7348, 0, 0, 47, 0, 38857, 64, 0, 1, 'Apply Phase 4763 if Quest 38857 is not rewarded'),
(26, 4763, 7348, 0, 0, 48, 0, 278525, 0, 1, 1, 'Apply Phase 4763 if player has not quest objective done: Grace the Green rescued');

UPDATE `quest_poi` SET `VerifiedBuild`=46340 WHERE (`QuestID`=38857 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=38857 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=38857 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=38857 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=38857 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46340 WHERE (`QuestID`=38857 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=38857 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=38857 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=38857 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=38857 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=46340 WHERE `ID`=38857;
UPDATE `quest_template` SET `VerifiedBuild`=46340 WHERE `ID`=38857;
