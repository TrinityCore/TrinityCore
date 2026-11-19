SET @CGUID := 651527;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 89341, 1220, 7334, 7355, '0', 4732, 0, 0, 1, -12.9131946563720703, 6727.5234375, 55.7231292724609375, 1.28174591064453125, 120, 0, 0, 3138, 3801, 0, 0, 0, 0, 46455); -- Magister Garuhod (Area: Crumbled Palace - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 7702, 0, 0, 0, ''); -- Magister Garuhod

DELETE FROM `creature_queststarter` WHERE (`id`=88798 AND `quest`=37492) OR (`id`=89341 AND `quest` IN (37728,37727));
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(89341, 37728, 46455), -- Presentation is Everything offered Magister Garuhod
(89341, 37727, 46455); -- The Magister of Mixology offered Magister Garuhod

UPDATE `creature_questender` SET `VerifiedBuild`=46455 WHERE (`id`=89341 AND `quest` IN (37727,37728));

UPDATE `quest_offer_reward` SET `VerifiedBuild`=46455 WHERE `ID` IN (37727, 37728);

UPDATE `quest_poi` SET `VerifiedBuild`=46455 WHERE (`QuestID`=38407 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=37728 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37728 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37728 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=37727 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=37727 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=37727 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=46455 WHERE (`QuestID`=37728 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37728 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37728 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=37727 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=37727 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=37727 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=37727 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=37727 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=37727 AND `Idx1`=0 AND `Idx2`=0);

UPDATE `quest_details` SET `VerifiedBuild`=46455 WHERE `ID` IN (37728, 37727);

UPDATE `creature_template` SET `VerifiedBuild`=46455 WHERE `entry`  = 89341;

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 4732;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4732, 'Cosmetic - See Magister Garuhod at Crumbled Palace');

DELETE FROM `phase_area` WHERE `AreaId` = 7355 AND `PhaseId` = 4732;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7355, 4732, 'See Magister Garuhod at Crumbled Palace');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4732 AND `SourceEntry` = 7355;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4732, 7355, 0, 0, 47, 0, 37727, 64, 0, 1, 'Apply Phase 4732 if Quest 37727 is not rewarded'),
(26, 4732, 7355, 0, 1, 47, 0, 37728, 64, 0, 1, 'Apply Phase 4732 if Quest 37728 is not rewarded');
