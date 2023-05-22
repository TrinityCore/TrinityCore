SET @CGUID := 651355;

DELETE FROM `creature` WHERE `guid` = @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 106881, 1220, 7334, 7345, '0', '4765', 0, 0, 0, -660.37847900390625, 5596.91650390625, 2.861580610275268554, 4.837513923645019531, 7200, 0, 0, 3923, 100, 0, 0, 0, 0, 46313);

DELETE FROM `creature_addon` WHERE `guid` = @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID, 0, 0, 0, 0, 0, 0, 0, 0, 3, '114943');

DELETE FROM `phase_name` WHERE `ID` = 4765;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4765, 'Cosmetic - See Looper Allen');

DELETE FROM `phase_area` WHERE `AreaId` IN (7342, 7345) AND `PhaseId` = 4765;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7342, 4765, 'See Looper Allen in Queen\'s Reprisal'), -- Queen\'s Reprisal Zone
(7345, 4765, 'See Looper Allen in Queen\'s Reprisal'); -- Mak'rana Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4765  AND `SourceEntry` IN (7342, 7345));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4765, 7345, 0, 0, 47, 0, 37659, 2 | 8 | 64, 0, 1, 'Apply Phase 4765 if Quest 37659 is not in progress | complete | rewarded'),
(26, 4765, 7342, 0, 0, 47, 0, 37659, 2 | 8 | 64, 0, 1, 'Apply Phase 4765 if Quest 37659 is not in progress | complete | rewarded');

DELETE FROM `creature_queststarter` WHERE `id`=106881 AND `quest`=37659;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(106881, 37659, 46366);

DELETE FROM `creature_questender` WHERE `id`=106881 AND `quest`=37654;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(106881, 37654, 46366);

UPDATE `quest_template` SET `VerifiedBuild`=46366 WHERE `ID`=37659;
UPDATE `quest_poi` SET `VerifiedBuild`=46366 WHERE `QuestID`=37659 AND `BlobIndex`=0 AND `Idx1` IN (0, 1);
UPDATE `quest_details` SET `VerifiedBuild`=46366 WHERE `ID` =37659;
