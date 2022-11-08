SET @CGUID := 651475;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90255, 1220, 7334, 7356, '0', 4356, 0, 0, 1, -412.979156494140625, 7113.74755859375, 1.65625, 0.780660390853881835, 120, 0, 0, 39230, 0, 0, 0, 0, 0, 46366), -- Kor'vas Bloodthorn
(@CGUID+1, 89362, 1220, 7334, 7364, '0', 5696, 0, 0, 1, -103.434028625488281, 6961.33251953125, 12.546875, 2.022709131240844726, 120, 0, 0, 5099900, 0, 0, 0, 0, 0, 46366);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 8, 1, 0, 0, 0, 0, 3, '222589 42459'), -- Kor'vas Bloodthorn
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 3, '42459');

UPDATE `creature_template` SET `VerifiedBuild`=46366, `minlevel`=45, `maxlevel`=45 WHERE `entry` = 90255; -- Kor'vas Bloodthorn
UPDATE `creature_questender` SET `VerifiedBuild`=46366 WHERE (`id`=90255 AND `quest`=36920);

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=36920; -- From Within
UPDATE `quest_poi` SET `VerifiedBuild`=46366 WHERE (`QuestID`=36920 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=36920 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46366 WHERE (`QuestID`=36920 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=36920 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_template` SET `VerifiedBuild`=46366 WHERE `ID`=36920;

DELETE FROM `phase_name` WHERE `ID` = 4356;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4356, 'Cosmetic - See Kor\'vas Bloodthorn');

DELETE FROM `phase_area` WHERE `AreaId` IN (7349, 7356) AND `PhaseId` = 4356;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7349, 4356, 'Cosmetic - Azsuna - See Kor\'vas Bloodthorn in Faronaar'), -- Faronaar Area
(7356, 4356, 'Cosmetic - Azsuna - See Kor\'vas Bloodthorn in Faronaar'); -- Vanquish Point Area

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4356  AND `SourceEntry` IN (7349, 7356));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4356, 7349, 0, 0, 47, 0, 36920, 64, 0, 1, 'Apply Phase 4356 if Quest 36920 is not rewarded'),
(26, 4356, 7356, 0, 0, 47, 0, 36920, 64, 0, 1, 'Apply Phase 4356 if Quest 36920 is not rewarded');
