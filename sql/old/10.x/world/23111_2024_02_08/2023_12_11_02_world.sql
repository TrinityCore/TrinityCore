SET @CGUID := 7000280;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 121239, 1643, 8717, 9802, '0', 9050, 0, 0, 1, 1067.8819580078125, -478.791656494140625, 9.783459663391113281, 4.977229595184326171, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52301); -- Flynn Fairwind (Area: Harbormaster's Office - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 13362, 0, 0, 0, ''); -- Flynn Fairwind

DELETE FROM `creature_queststarter` WHERE (`id`=122370 AND `quest`=47485) OR (`id`=121239 AND `quest`=47181);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(122370, 47485, 52301), -- The Ashvane Trading Company offered Cyrus Crestfall
(121239, 47181, 52301); -- The Smoking Gun offered Flynn Fairwind

DELETE FROM `creature_questender` WHERE (`id`=121239 AND `quest`=47181);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(121239, 47181, 52301); -- The Smoking Gun ended by Flynn Fairwind

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 9050;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9050, 'Cosmetic - See Flynn Fairwind at Harbormaster\'s Office');

DELETE FROM `phase_area` WHERE `PhaseId` = 9050 AND `AreaId` IN (8717, 8718, 9802);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9802, 9050, 'See Flynn Fairwind at Harbormaster\'s Office'),
(8718, 9050, 'See Flynn Fairwind at Harbormaster\'s Office'),
(8717, 9050, 'See Flynn Fairwind at Harbormaster\'s Office');

-- Quest
UPDATE `quest_poi` SET `VerifiedBuild`=52301 WHERE (`QuestID`=47485 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47485 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47485 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47181 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47181 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47181 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=52301 WHERE (`QuestID`=47485 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47485 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47485 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47181 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47181 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47181 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_template` SET `VerifiedBuild`=52301 WHERE `ID`=47485;

UPDATE `quest_details` SET `VerifiedBuild`=52301 WHERE `ID` IN (47485, 47181);

UPDATE `quest_offer_reward` SET `VerifiedBuild`=52301 WHERE `ID`=47181;
