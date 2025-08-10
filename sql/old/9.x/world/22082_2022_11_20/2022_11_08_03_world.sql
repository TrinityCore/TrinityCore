SET @CGUID := 651482;

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 90423, 1220, 7334, 7359, '0', 4472, 0, 0, 0, 1123.6319580078125, 6576.79345703125, 142.3843231201171875, 0, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46455); -- Mana-Drained Whelpling

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 7, 1, 0, 0, 0, 0, 0, ''); -- Mana-Drained Whelpling

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `VerifiedBuild`=46455 WHERE `entry`=90423; -- Mana-Drained Whelpling

DELETE FROM `creature_queststarter` WHERE (`id`=90423 AND `quest`=37859);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(90423, 37859, 46455); -- The Consumed offered Mana-Drained Whelpling

UPDATE `quest_details` SET `VerifiedBuild`=46455 WHERE `ID`=37859;

UPDATE `quest_poi` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37859 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=37859 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=37859 AND `BlobIndex`=3 AND `Idx1`=4) OR (`QuestID`=37859 AND `BlobIndex`=2 AND `Idx1`=3) OR (`QuestID`=37859 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=37859 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37859 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37859 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=8) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=7) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=6) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=5) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=4) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=3) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=2) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=1) OR (`QuestID`=37859 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=37859 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=37859 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=37859 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37859 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37859 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_template` SET `VerifiedBuild`=46455 WHERE `ID`=37859; -- The Consumed

DELETE FROM `phase_name` WHERE `ID` = 4472;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4472, 'Cosmetic - See Mana-Drained Whelpling in Azurewing Whelplands');

DELETE FROM `phase_area` WHERE `AreaId` IN (7359, 7338) AND `PhaseId` = 4472;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7338, 4472, 'Cosmetic - See Mana-Drained Whelpling in Azurewing Whelplands'), -- Runas's Hovel
(7359, 4472, 'Cosmetic - See Mana-Drained Whelpling in Azurewing Whelplands'); -- Azurewing Whelplands Zone

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4472  AND `SourceEntry` IN (7359, 7338));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4472, 7359, 0, 0, 47, 0, 37855, 64, 0, 0, 'Apply Phase 4472 if Quest 37855 is rewarded'),
(26, 4472, 7359, 0, 0, 47, 0, 37859, 8 | 2 | 64, 0, 1, 'Apply Phase 4472 if Quest 37859 is not in progress | completed | rewarded'),
(26, 4472, 7338, 0, 0, 47, 0, 37855, 64, 0, 0, 'Apply Phase 4472 if Quest 37855 is rewarded'),
(26, 4472, 7338, 0, 0, 47, 0, 37859, 8 | 2 | 64, 0, 1, 'Apply Phase 4472 if Quest 37859 is not in progress | completed | rewarded');
