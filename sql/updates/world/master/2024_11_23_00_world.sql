-- Creature Text
DELETE FROM `creature_text` WHERE (`CreatureID` = 93127 AND `GroupID` = 1) OR (`CreatureID` IN (96420, 96655) AND `GroupID` = 0);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(93127, 1, 0, 'We will not last much longer if those devastators are not destroyed!', 12, 0, 100, 5, 0, 55260, 98956, 5, 'Kayn Sunfury to Player'),
(96420, 0, 0, 'They outnumber us by an order of magnitude. Can we defeat them?', 12, 0, 100, 6, 0, 55092, 99002, 5, 'Cyana Nightglaive to Player'),
(96655, 0, 0, 'Last I saw, Kor\'vas cut a swath of destruction on her way across the bridge.', 12, 0, 100, 1, 0, 55010, 98848, 5, 'Allari the Souleater to Player');

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=96655 AND `quest`=38725) OR (`id`=96420 AND `quest`=38819) OR (`id`=93127 AND `quest`=38727);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(96655, 38725, 57689), -- Into the Foul Creche offered by Allari the Souleater
(96420, 38819, 57689), -- Their Numbers Are Legion offered by Cyana Nightglaive
(93127, 38727, 57689); -- Stop the Bombardment offered by Kayn Sunfury

DELETE FROM `quest_details` WHERE `ID` IN (38725 /*Into the Foul Creche*/, 38819 /*Their Numbers Are Legion*/, 38727 /*Stop the Bombardment*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(38725, 1, 0, 0, 0, 0, 0, 0, 0, 57689), -- Into the Foul Creche
(38819, 1, 25, 0, 0, 0, 0, 0, 0, 57689), -- Their Numbers Are Legion
(38727, 274, 0, 0, 0, 0, 0, 0, 0, 57689); -- Stop the Bombardment

DELETE FROM `quest_offer_reward` WHERE `ID`=39495;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(39495, 25, 0, 0, 0, 0, 0, 0, 0, 'Excellent. You\'ve absorbed that fel lord\'s power and become more powerful in-turn.\n\nNow, we can fully concentrate on destroying the Legion and their Brood Queen.', 57689); -- Hidden No More

DELETE FROM `quest_template_addon` WHERE `ID` IN (38725, 38819, 38727);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(38725, 0, 0, 0, 39495, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Into the Foul Creche
(38819, 0, 0, 0, 39495, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Their Numbers Are Legion
(38727, 0, 0, 0, 39495, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Stop the Bombardment

-- Kayn Sunfury smart ai
SET @ENTRY := 93127;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 1000, 4000, 4000, 7000, 0, 10, 396, 273, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 7 seconds (1 - 4s initially) - Self: Play random emote: 396, 273, 6,', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 38813, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Orders for Your Captains (38813) - Player who accepted quest: Talk 0 to invoker', ''),
(@ENTRY, 0, 2, 0, 19, 0, 100, 0, 39262, 0, 0, 0, 0, 143, 486, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Give Me Sight Beyond Sight (39262) - Player who accepted quest: Start conversation (486) Actors<> (first line 1298)', ''),
(@ENTRY, 0, 3, 0, 19, 0, 100, 0, 39262, 0, 0, 0, 0, 85, 191203, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Give Me Sight Beyond Sight (39262) - Player who accepted quest: Cast spell 191203 on self', ''),
(@ENTRY, 0, 4, 0, 19, 0, 100, 0, 38727, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Stop the Bombardment (38727) - Player who accepted quest: Talk 1 to invoker', '');

-- Cyana Nightglaive smart ai
SET @ENTRY := 96420;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 1000, 5000, 5000, 8000, 0, 10, 5, 25, 273, 1, 274, 15, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 8 seconds (1 - 5s initially) - Self: Play random emote: 5, 25, 273, 1, 274, 15', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 38819, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Their Numbers Are Legion (38819) - Player who accepted quest: Talk 0 to invoker', '');

-- Allari the Souleater smart ai
SET @ENTRY := 96655;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 0, 1000, 6000, 5000, 7000, 0, 10, 6, 274, 273, 396, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 7 seconds (1 - 6s initially) - Self: Play random emote: 6, 274, 273, 396,', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 38725, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Into the Foul Creche (38725) - Player who accepted quest: Talk 0 to invoker', '');
