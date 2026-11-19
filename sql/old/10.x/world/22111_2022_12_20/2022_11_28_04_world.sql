SET @CGUID := 651839;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89007, 1220, 7334, 7344, '0', 4301, 0, 0, 0, -408.09375, 6590.205078125, 0.215781688690185546, 0.842128276824951171, 120, 0, 0, 43153, 0, 0, 0, 0, 0, 46549), -- Sleepy Dhow (Area: Shipwreck Arena - Difficulty: 0) (Auras: 32951 - Sleeping Sleep)
(@CGUID+1, 88873, 1220, 7334, 7344, '0', 4574, 0, 0, 0, -327.267364501953125, 6535.986328125, 1.743238687515258789, 0.553760647773742675, 120, 0, 0, 3923, 0, 0, 0, 0, 0, 46549); -- Okuna Longtusk (Area: Shipwreck Arena - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, 3, '32951'); -- Sleepy Dhow - 32951 - Sleeping Sleep

UPDATE `creature_template` SET `gossip_menu_id`=17259, `minlevel`=45, `maxlevel`=45,`VerifiedBuild`=46658 WHERE `entry`=88873; -- Okuna Longtusk

UPDATE `quest_details` SET `VerifiedBuild`=46689 WHERE `ID` IN (37510, 37542, 37528);

DELETE FROM `creature_queststarter` WHERE (`id`=88873 AND `quest` IN (37510,37542,37528));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(88873, 37510, 46689), -- Sternfathom's Champion offered Okuna Longtusk
(88873, 37542, 46689), -- No Time for Tryouts offered Okuna Longtusk
(88873, 37528, 46689); -- Let Sleeping Giants Lie offered Okuna Longtusk

UPDATE `creature_questender` SET `VerifiedBuild`=46689 WHERE (`id`=88873 AND `quest` IN (37542,37528,37507));

UPDATE `quest_template` SET `VerifiedBuild`=46689 WHERE `ID`=37510; -- Sternfathom's Champion
UPDATE `quest_template` SET `VerifiedBuild`=46689 WHERE `ID`=37542; -- No Time for Tryouts
UPDATE `quest_template` SET `VerifiedBuild`=46689 WHERE `ID`=37528; -- Let Sleeping Giants Lie

DELETE FROM `quest_poi` WHERE (`QuestID`=37542 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37542 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37542 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(37542, 0, 2, 32, 0, 0, 1220, 630, 0, 0, 0, 0, 0, 964697, 0, 46689), -- No Time for Tryouts
(37542, 0, 1, 0, 276420, 89082, 1220, 630, 0, 0, 0, 0, 0, 968248, 0, 46689), -- No Time for Tryouts
(37542, 0, 0, -1, 0, 0, 1220, 630, 0, 0, 0, 0, 0, 964697, 0, 46689); -- No Time for Tryouts

DELETE FROM `quest_poi_points` WHERE (`QuestID`=37542 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37542 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37542 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(37542, 2, 0, -327, 6536, 2, 46689), -- No Time for Tryouts
(37542, 1, 0, -242, 6588, 2, 46689), -- No Time for Tryouts
(37542, 0, 0, -327, 6536, 2, 46689); -- No Time for Tryouts

UPDATE `quest_poi` SET `VerifiedBuild`=46689 WHERE (`QuestID`=37510 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37510 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=37528 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37528 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37528 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=46689 WHERE (`QuestID`=37510 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37510 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=37528 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37528 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37528 AND `Idx1`=0 AND `Idx2`=0);

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (4301, 4574);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4301, 'Cosmetic - See Sleepy Dhow at Shipwreck Arena'),
(4574, 'Cosmetic - See Okuna Longtusk at Shipwreck Arena');

DELETE FROM `phase_area` WHERE `AreaId` = 7344 AND `PhaseId` IN (4301, 4574);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7344, 4301, 'See Sleepy Dhow at Shipwreck Arena'),
(7344, 4574, 'See Okuna Longtusk at Shipwreck Arena');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4574 AND `SourceEntry` = 7344;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4574, 7344, 0, 0, 47, 0, 37510, 8 | 2 | 64, 0, 1, 'Apply Phase 4574 if Quest 37510 is not in progress | completed | rewarded');
