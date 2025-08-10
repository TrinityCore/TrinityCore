SET @CGUID := 1051032;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 165107, 2222, 10534, 11473, '0', 14083, 0, 0, 1, -4090.19091796875, -4635.34912109375, 6536.0849609375, 0.661615490913391113, 7200, 0, 0, 6100, 0, 0, 0, 0, 0, 43345); -- Kleia (Area: -Unknown- - Difficulty: 0)

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 11473 AND `PhaseId` = 14083;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(11473, 14083, 'Cosmetic: Kleia Spawn after Quest: 57677 is complete/rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` = 14083) AND (`SourceEntry` = 11473);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 14083, 11473, 0, 0, 47, 0, 57261, 66, 0, 0, 'Allow Phase 14083 if Quest (57261) is complete/rewarded');

DELETE FROM `phase_name` WHERE `ID` = 14083;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(14083, 'Kleia at Aspirants Rest');

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID`=57261;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(57261, 669, 0, 0, 0, 0, 0, 0, 0, 'Your journey is just beginning, $n. I hope you can help us, and I hope we can help you.', 43345); -- Walk the Path; Aspirant

DELETE FROM `quest_details` WHERE `ID`=57677;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(57677, 669, 669, 669, 0, 0, 0, 0, 0, 43345); -- A Soulbind In Need

DELETE FROM `creature_queststarter` WHERE (`id`=165107 AND `quest`=57677);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(165107, 57677); -- A Soulbind In Need offered Kleia

DELETE FROM `quest_template_addon` WHERE `ID` = 57677;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(57677, 0, 0, 0, 57261, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
