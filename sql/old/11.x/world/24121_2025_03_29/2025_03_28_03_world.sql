SET @CGUID := 7001617;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 124922, 1643, 8721, 9032, '0', 0, 0, 0, 0, 54.24826431274414062, 1832.21875, 47.50242233276367187, 6.079949855804443359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888); -- Helena Gentle (Area: Fallhaven - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=124922; -- Helena Gentle

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=124922 AND `DifficultyID`=0); -- 124922 (Helena Gentle) - CanSwim

-- Quest
DELETE FROM `quest_details` WHERE `ID`=47979;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47979, 6, 0, 0, 0, 0, 0, 0, 0, 59888); -- Witch Hunt

DELETE FROM `creature_queststarter` WHERE (`id`=124922 AND `quest`=47979);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(124922, 47979, 59888); -- Witch Hunt offered by Helena Gentle

DELETE FROM `creature_questender` WHERE (`id`=124922 AND `quest`=47978);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(124922, 47978, 59888); -- The Wayward Crone ended by Helena Gentle

DELETE FROM `quest_template_addon` WHERE `ID` = 47979;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(47979, 0, 0, 0, 47978, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Witch Hunt

-- Model
UPDATE `creature_model_info` SET `VerifiedBuild`=59888 WHERE `DisplayID` IN (81005, 52835, 81154, 78048, 64978, 78257, 79911, 81145, 78051, 63016, 62863, 62862, 78052, 8014, 80953);
UPDATE `creature_model_info` SET `BoundingRadius`=1.847484946250915527, `VerifiedBuild`=59888 WHERE `DisplayID`=80962;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382819831371307373, `CombatReach`=1 WHERE `DisplayID`=36357;
