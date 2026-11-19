SET @CGUID := 460677;
SET @OGUID := 395671;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 79243, 1116, 7078, 7078, '0', 4318, 0, 0, 1, 1936.2691650390625, 322.3975830078125, 89.0596923828125, 1.638979077339172363, 7200, 0, 0, 2586, 0, 0, 0, 0, 0, 44232); -- Baros Alexston (Area: -Unknown- - Difficulty: 0)

DELETE FROM `creature_template_addon` WHERE `entry` = 79243;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(79243, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 79243 (Baros Alexston)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 230280, 1116, 7078, 7078, '0', 4318, 0, 1939.8350830078125, 322.234375, 88.96616363525390625, 2.045852184295654296, 0, 0, 0.853635787963867187, 0.520870327949523925, 7200, 255, 1, 44232); -- Alliance Banner (Area: -Unknown- - Difficulty: 0)

UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=44232 WHERE `entry`=230280; -- Alliance Banner

-- Condition for Visibility
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 32 AND `SourceGroup` = 5 AND `SourceEntry` = 79243) OR (`SourceTypeOrReferenceId` = 32 AND `SourceGroup` = 8 AND `SourceEntry` = 230280);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(32, 5, 79243, 0, 0, 47, 0, 34583, 66, 0, 0, 'Baros Alexston gets visible if Quest: 34583 is complete/rewarded'),
(32, 8, 230280, 0, 0, 9, 0, 34583, 0, 0, 0, 'Alliance Banner gets visible if Quest: 34583 is Taken'),
(32, 8, 230280, 0, 1, 47, 0, 34583, 66, 0, 0, 'OR: Alliance Banner gets visible if Quest: 34583 is complete/rewarded');

-- Questchain
DELETE FROM `quest_template_addon` WHERE `ID` IN (34584, 34616, 34586);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(34584, 0, 0, 0, 34583, 34585, -34584, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(34616, 0, 0, 0, 34583, 34585, -34584, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(34586, 0, 0, 0, 34585, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
