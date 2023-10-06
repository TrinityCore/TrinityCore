-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 100982;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(100982, 0, 0, 'I will meet you down at the gateway on the Molten Shore.', 12, 0, 100, 0, 0, 53104, 103349, 5, 'Sevis Brightflame to Player');

-- Sevis Brightflame (cave)
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5595 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5595, 0, 0, 0, 47, 0, 40378, 2|64, 0, 0, 'Apply Phase 5595 if Quest 40378 is complete | rewarded'),
(26, 5595, 0, 0, 0, 47, 0, 40379, 2|8|64, 0, 1, 'Apply Phase 5595 if Quest 40378 is not in progress | complete | rewarded');

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=40379;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(40379, 1, 0, 0, 0, 0, 0, 0, 0, 51536); -- Enter the Illidari: Coilskar

DELETE FROM `creature_queststarter` WHERE (`id`=100982 AND `quest`=40379);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(100982, 40379, 51536); -- Enter the Illidari: Coilskar offered Sevis Brightflame

DELETE FROM `quest_template_addon` WHERE `ID` = 40379;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(40379, 0, 0, 0, 40378, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Path Sevis Brightflame
SET @ENTRY := 100982;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, 820.3646, 2771.537, -30.75556, NULL, 0, 1),
(@PATH, 1, 803.1771, 2772.341, -33.35608, NULL, 0, 1),
(@PATH, 2, 786.9636, 2761.554, -37.11161, NULL, 0, 1),
(@PATH, 3, 773.6198, 2747.844, -41.77515, NULL, 0, 1),
(@PATH, 4, 764.1945, 2733.08, -45.57618, NULL, 0, 1),
(@PATH, 5, 756.1962, 2716.664, -49.0556, NULL, 0, 1);

-- Sevis Brightflame
SET @ENTRY := 100982;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = (@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 40379, 0, 0, 0, 80, (@ENTRY*100), 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Quest Accept (40379) - run Actionlist - to Invoker'),
((@ENTRY * 100), 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0s - become Personal Clone - Invoker'),
((@ENTRY * 100), 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - selfcast: 82238 (PhaseShiftUpdate) - to Summoner/Owner'),
((@ENTRY * 100), 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 175799, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - cast: 175799 (Track Target in Channel (Not Unique)) - to Summoner/Owner'),
((@ENTRY * 100), 9, 3, 0, 0, 0, 100, 0, 500, 500, 0, 0, 128, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 500ms - PlayOneShotAnimKidId 8599 - to self'),
((@ENTRY * 100), 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Say text 0 - to Summoner/Owner'),
((@ENTRY * 100), 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 137, 36264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - PlayVisualKit 36264 - to self'),
((@ENTRY * 100), 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 43, 0, 64385, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Mount to DisplayID 64385 - to self'),
((@ENTRY * 100), 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 92, 0, 175799, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Mount to DisplayID 64385 - to self'),
((@ENTRY * 100), 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, (@PATH), 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Start Waypointpath - to self'),
((@ENTRY * 100), 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 12000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - force despawn after 12s - to self');
