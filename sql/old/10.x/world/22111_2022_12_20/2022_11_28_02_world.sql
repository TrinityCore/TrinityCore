SET @CGUID := 651834;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 109334, 1220, 7334, 7348, '0', 6875, 0, 0, 1, -908.14581298828125, 6408.9521484375, 3.654376983642578125, 4.070976734161376953, 120, 0, 0, 33882, 0, 0, 0, 0, 0, 46702), -- Okuna Longtusk (Area: Oceanus Cove - Difficulty: Normal)
(@CGUID+1, 89051, 1220, 7334, 7348, '0', 4325, 0, 0, 0, -957.2117919921875, 6309.15283203125, 29.86275672912597656, 2.938225030899047851, 120, 0, 0, 33882, 0, 0, 0, 0, 0, 46702); -- Okuna Longtusk (Area: Oceanus Cove - Difficulty: Normal)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Okuna Longtusk

UPDATE `creature_template` SET `minlevel`=45, `maxlevel`=45, `unit_flags3`=1048576, `VerifiedBuild`=46702 WHERE `entry`=89051; -- Okuna Longtusk
UPDATE `creature_template` SET `gossip_menu_id`=19919, `minlevel`=45, `maxlevel`=45, `VerifiedBuild`=46702 WHERE `entry`=109334; -- Okuna Longtusk

UPDATE `creature_questender` SET `VerifiedBuild`=46702 WHERE (`id`=109334 AND `quest`=37566);

UPDATE `quest_template` SET `VerifiedBuild`=46702 WHERE `ID`=37566; -- The Prince is Going Down

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46702 WHERE `ID`=37566;

UPDATE `quest_poi` SET `VerifiedBuild`=46702 WHERE (`QuestID`=37566 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37566 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37566 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46702 WHERE (`QuestID`=37566 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37566 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37566 AND `Idx1`=0 AND `Idx2`=0);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (4325, 6875);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4325, 'Cosmetic - See Okuna Longtusk caged'),
(6875, 'Cosmetic - See Okuna Longtusk free');

DELETE FROM `phase_area` WHERE `AreaId` = 7348 AND `PhaseId` IN (4325, 6875);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7348, 4325, 'See Okuna Longtusk caged at Oceanus Cove'),
(7348, 6875, 'See Okuna Longtusk free at Oceanus Cove');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4325, 6875) AND `SourceEntry` = 7348;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4325, 7348, 0, 0, 47, 0, 37566, 64, 0, 1, 'Apply Phase 4325 if Quest 37566 is not rewarded'),
(26, 6875, 7348, 0, 0, 47, 0, 37566, 2 | 64, 0, 0, 'Apply Phase 6875 if Quest 37566 is completed | rewarded');
