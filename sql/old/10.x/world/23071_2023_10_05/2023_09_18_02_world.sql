SET @CGUID := 5000088;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 81763, 1265, 7025, 7041, '0', 3627, 0, 0, 0, 3991.33154296875, -2552.413330078125, 66.01389312744140625, 4.519192695617675781, 120, 0, 0, 4000, 0, 0, 0, 0, 50791), -- Rephuura (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+1, 81761, 1265, 7025, 7041, '0', 3626, 0, 0, 0, 3991.5087890625, -2552.361083984375, 66.00347900390625, 4.376849651336669921, 120, 0, 0, 4000, 0, 0, 0, 0, 50791); -- Ashka (Area: Heartblood - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Rephuura
(@CGUID+1, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Ashka

-- Phases
DELETE FROM `phase_name` WHERE `ID` IN (3627, 3626);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3626, 'Cosmetic - Ashka (H)'),
(3627, 'Cosmetic - Rephuura (A)');

DELETE FROM `phase_area` WHERE `AreaId` IN (7041, 7039) AND `PhaseId` IN (3626, 3627);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7041, 3626, 'See Ashka at Heartblood (Only Horde)'),
(7041, 3627, 'See Rephuura at Heartblood (Only Alliance)'),
(7039, 3626, 'See Ashka at Heartblood (Only Horde)'),
(7039, 3627, 'See Rephuura at Heartblood (Only Alliance)');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3626 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3626, 0, 0, 0, 6, 0, 67, 0, 0, 0, 'Apply phase 3626 if Team Horde');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3627 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3627, 0, 0, 0, 6, 0, 469, 0, 0, 0, 'Apply phase 3627 if Team Alliance');

-- Quest
UPDATE `quest_details` SET `VerifiedBuild`=50791 WHERE `ID` IN (35242, 35241);
UPDATE `creature_queststarter` SET `VerifiedBuild`=50791 WHERE (`id`=81763 AND `quest`=35242) OR (`id`=81761 AND `quest`=35241);
UPDATE `quest_poi` SET `VerifiedBuild`=50791 WHERE (`QuestID`=35242 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=35242 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=35242 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=35242 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=35242 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=50791 WHERE (`QuestID`=35242 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=35242 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=35242 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=35242 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=35242 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=51130 WHERE (`QuestID`=35241 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=35241 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=35241 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=35241 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=35241 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=51130 WHERE (`QuestID`=35241 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=35241 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=35241 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=35241 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=35241 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_template_addon` WHERE `ID` IN (35241, 35242);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(35241, 0, 0, 0, 34420, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''),
(35242, 0, 0, 0, 34420, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');
