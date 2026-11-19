SET @CGUID := 395264;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 55789, 0, 1519, 0, '0', 1687, 0, 0, 0, -8458.5244140625, 352.993072509765625, 135.6565399169921875, 5.409669876098632812, 120, 0, 0, 1989, 0, 0, 0, 0, 0, 43345); -- Rell Nightwind (Area: 0 - Difficulty: 0)

UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=55789; -- Rell Nightwind

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 1519 AND `PhaseId` = 1687;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 1687, 'Cosmetic - See Rell Nightwind');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 1687 AND `SourceEntry` = 1519);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 1687, 1519, 0, 0, 47, 0, 60125, 66, 0, 0, 'Allow Phase 1687 if Quest (60125) IS completed or rewarded');

-- Quest
DELETE FROM `quest_template_addon` WHERE `ID` = 29548;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29548, 0, 0, 0, 60125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_offer_reward` WHERE `ID`=60125;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(60125, 396, 0, 0, 0, 0, 0, 0, 0, 'Greetings, $n.', 43345); -- Mists of Pandaria: To Pandaria!

DELETE FROM `creature_questender` WHERE (`id`=55789 AND `quest`=60125);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(55789, 60125); -- Mists of Pandaria: To Pandaria! ended by Rell Nightwind

UPDATE `creature_questender` SET `VerifiedBuild`=43345 WHERE (`id`=55789 AND `quest`=60125);
