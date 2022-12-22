SET @CGUID := 651493;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90065, 1220, 7334, 7359, '0', 4441, 0, 0, 0, 1111.717041015625, 6758.375, 167.418609619140625, 5.531472682952880859, 120, 0, 0, 9808, 0, 0, 0, 0, 0, 46455); -- Stellagosa

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 7750, 0, 0, 0, ''); -- Stellagosa

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=32768, `HoverHeight`=5.849999904632568359, `VerifiedBuild`=46455 WHERE `entry`=90065; -- Stellagosa

DELETE FROM `creature_queststarter` WHERE (`id`=90065 AND `quest`=37957);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(90065, 37957, 46455); -- Runas the Shamed offered Stellagosa

UPDATE `quest_details` SET `VerifiedBuild`=46455 WHERE `ID`=37957;

UPDATE `quest_poi` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37957 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=37957 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37957 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37957 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37957 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37957 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37957 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37957 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37957; -- Runas the Shamed

DELETE FROM `phase_name` WHERE `ID` = 4441;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4441, 'Cosmetic - See Stellagosa in Azurewing Whelplands');

DELETE FROM `phase_area` WHERE `AreaId` IN (7359, 7338) AND `PhaseId` = 4441;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7338, 4441, 'Cosmetic - See Stellagosa in Azurewing Whelplands'), -- Runas's Hovel
(7359, 4441, 'Cosmetic - See Stellagosa in Azurewing Whelplands'); -- Azurewing Whelplands Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4441 AND `SourceEntry` IN (7359, 7338));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4441, 7359, 0, 0, 47, 0, 37855, 64, 0, 0, 'Apply Phase 4441 if Quest 37855 is completed | rewarded'),
(26, 4441, 7359, 0, 0, 47, 0, 37957, 8 | 2 | 64, 0, 1, 'Apply Phase 4441 if Quest 37957 is not in progress | completed | rewarded'),
(26, 4441, 7338, 0, 0, 47, 0, 37855, 64, 0, 0, 'Apply Phase 4441 if Quest 37855 is rewarded'),
(26, 4441, 7338, 0, 0, 47, 0, 37957, 8 | 2 | 64, 0, 1, 'Apply Phase 4441 if Quest 37957 is not in progress | completed | rewarded');
