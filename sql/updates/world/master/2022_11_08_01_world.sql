SET @CGUID := 651477;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90578, 1220, 7334, 7354, '0', '0', 0, 0, 0, -725.29168701171875, 7310.9150390625, 20.20719146728515625, 1.988834619522094726, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46366), -- Stellagosa Chain Bunny - All Phases
(@CGUID+1, 90578, 1220, 7334, 7354, '0', '0', 0, 0, 0, -723.9444580078125, 7348.97998046875, 21.1371307373046875, 3.934170007705688476, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46366), -- Stellagosa Chain Bunny - All Phases
(@CGUID+2, 90578, 1220, 7334, 7354, '0', '0', 0, 0, 0, -758.12677001953125, 7326.33447265625, 20.18547248840332031, 0.428984791040420532, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46366), -- Stellagosa Chain Bunny - All Phases
(@CGUID+3, 90546, 1220, 7334, 7351, '0', '4483', 0, 0, 0, -736.529541015625, 7336.212890625, 26.212158203125, 5.567546844482421875, 120, 0, 0, 18828, 3801, 0, 0, 0, 0, 46366); -- Stellagosa

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 4, ''), -- Stellagosa Chain Bunny - All Phases
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, 4, ''), -- Stellagosa Chain Bunny - All Phases
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, 4, ''), -- Stellagosa Chain Bunny - All Phases
(@CGUID+3, 0, 0, 50331648, 1, 0, 0, 0, 0, 3, ''); -- Stellagosa

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45 WHERE `entry`=90578; -- Stellagosa Chain Bunny - All Phases
UPDATE `creature_template` SET `VerifiedBuild`=46366 WHERE `entry`=90578; -- Stellagosa Chain Bunny - All Phases

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `faction`=190, `speed_run`=2.857142925262451171, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2099200, `HoverHeight`=5.849999904632568359 WHERE `entry`=90546; -- Stellagosa
UPDATE `creature_template` SET `VerifiedBuild`=46366 WHERE `entry`=90546; -- Stellagosa

UPDATE `quest_template` SET `VerifiedBuild`=46366 WHERE `ID`=37450; -- Saving Stellagosa

UPDATE `quest_poi` SET `VerifiedBuild`=46366 WHERE (`QuestID`=37450 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=37450 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=37450 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37450 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37450 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46366 WHERE (`QuestID`=37450 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=37450 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=37450 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=37450 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37450 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37450 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37450 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=46366 WHERE `ID` = 37450;

DELETE FROM `creature_queststarter` WHERE `id`= 90474 AND `quest` = 37450;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(90474, 37450, 46366); -- Saving Stellagosa offered Demon Hunter

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (90546, 90578);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(90546, 0, 0, 1, 0, 0, 0, NULL), -- Stellagosa
(90578, 0, 0, 1, 0, 0, 0, NULL); -- Stellagosa Chain Bunny - All Phases

DELETE FROM `phase_name` WHERE `ID` = 4483;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4483, 'Cosmetic - Azsuna - See Stellagosa chained');

DELETE FROM `phase_area` WHERE `AreaId` = 7351 AND `PhaseId` = 4483;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7351, 4483, 'Cosmetic - Azsuna - See Stellagosa chained in Legion Camp: Ruin');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4483 AND `SourceEntry` = 7351);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4483, 7351, 0, 0, 47, 0, 37450, 8, 0, 0, 'Apply Phase 4483 if Quest 37450 is in progress');
