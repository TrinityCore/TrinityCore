-- Delete static spawns
DELETE FROM `creature` WHERE `guid`=275910;
DELETE FROM `creature` WHERE `guid`=275911;
DELETE FROM `creature` WHERE `guid`=275915;
DELETE FROM `creature` WHERE `guid`=275916;

-- Areatrigger Scripts
DELETE FROM `areatrigger_scripts` WHERE `entry`=5988;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5988, 'at_westfall_two_shoed_lou_thugs');

DELETE FROM `areatrigger_scripts` WHERE `entry`=5987;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5987, 'at_westfall_small_time_hustler');

DELETE FROM `areatrigger_scripts` WHERE `entry` = 5989;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5989, 'SmartTrigger');

-- Template
UPDATE `creature_template` SET `ScriptName`='npc_westfall_small_time_hustler' WHERE  `entry`=42390;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_thug' WHERE `entry`=42387;
UPDATE `creature_template` SET `ScriptName`='npc_westfall_lous_parting_thoughts_trigger' WHERE `entry`=42562;

-- SpellArea
DELETE FROM `spell_area` WHERE (`spell`=79346 AND `area`=40) OR (`spell`=79229 AND `area`=40);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(79346, 40, 26232, 0, 0, 0, 2, 3, 66, 11),
(79229, 40, 0, 26232, 0, 0, 2, 3, 64, 9);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (42387, 42562);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42387, 0, 0, 'Did you... Did you meet her?', 12, 7, 100, 6, 0, 0, 42439, 'Thug to Player'),
(42387, 1, 0, 'Yep. She\'s for real.', 12, 7, 100, 396, 0, 0, 42440, 'Thug to Player'),
(42387, 2, 0, 'She wanted me to tell you lugs that she appreciates the job that we did for her on the Furlbrows. Gave me a pile o\' gold to split with you all.', 12, 7, 100, 396, 0, 0, 42441, 'Thug to Player'),
(42387, 3, 0, 'See her face? Is it really...', 12, 0, 100, 6, 0, 0, 42442, 'Thug to Player'),
(42387, 4, 0, 'Whoa, what do we have here? Looks like we have ourselves an eavesdropper, boys.', 12, 0, 100, 5, 0, 0, 42443, 'Thug to Player'),
(42387, 5, 0, 'Only one thing to do with a lousy, good-for-nothin eavesdropper.', 12, 0, 100, 397, 0, 0, 42444, 'Thug to Player'),
(42387, 6, 0, 'DIE!', 12, 0, 100, 53, 0, 0, 28793, 'Thug to Player'), -- BroadcastTextID: 1694 - 9359 - 14091 - 28793 - 42445 - 51125 - 69531
(42562, 0, 0, 'Hurry back to the Furlbrow\'s Cottage!', 42, 0, 100, 0, 0, 0, 42446, 'Lou\'s Parting Thoughts Trigger to Player');

DELETE FROM `creature_text` WHERE `CreatureID` = 42390;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42390, 0, 0, 'Pssst...', 12, 0, 100, 0, 0, 0, 42306, 'Small-Time Hustler to Player'),
(42390, 1, 0, 'What\'re you doin\' out here? Slummin\'?', 12, 7, 100, 25, 0, 0, 42310, 'Small-Time Hustler to Player'),
(42390, 1, 1, 'I think we can do business.', 12, 7, 100, 25, 0, 0, 42313, 'Small-Time Hustler to Player'),
(42390, 1, 2, 'You need something, $g mack:lady;?', 12, 7, 100, 25, 0, 0, 42307, 'Small-Time Hustler to Player'),
(42390, 1, 3, 'You lookin\' for somethin\' a little more... exotic?', 12, 7, 100, 25, 0, 0, 42312, 'Small-Time Hustler to Player'),
(42390, 1, 4, 'Whaddya need? Information? I got that too!', 12, 7, 100, 25, 0, 0, 42311, 'Small-Time Hustler to Player'),
(42390, 1, 5, 'Keep your head low, $g buddy:lady;.', 12, 7, 100, 25, 0, 0, 42314, 'Small-Time Hustler to Player');

DELETE FROM `creature_text` WHERE `CreatureID` = 42559;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42559, 0, 0, 'You were standing right here! What the hell did you see? Speak up!', 12, 7, 100, 0, 0, 0, 42456, 'Stormwind Investigator to Player'),
(42559, 1, 0, 'Natural causes? Two bullets in the chest and his shoes are on his head. What kind of natural death would that be?', 12, 7, 100, 0, 0, 0, 42458, 'Stormwind Investigator to Player');

DELETE FROM `creature_text` WHERE `CreatureID` = 42384 AND `GroupID` = 11;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42384, 11, 0, 'I... I didn\'t see nothin\'! He... he died of natural causes.', 12, 7, 100, 0, 0, 0, 42457, 'Homeless Stormwind Citizen to Player');

DELETE FROM `creature_text` WHERE `CreatureID` = 42558;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(42558, 0, 0, 'Doesn\'t look good, rookie.', 12, 7, 100, 1, 0, 0, 42447, 'Lieutenant Horatio Laine to Player'),
(42558, 1, 0, 'This was an execution. Whoever did this was sending a message...', 12, 7, 100, 0, 0, 0, 42449, 'Lieutenant Horatio Laine to Player'),
(42558, 2, 0, 'A message for anyone that would dare snitch on these criminals.', 12, 7, 100, 0, 0, 0, 42450, 'Lieutenant Horatio Laine to Player'),
(42558, 3, 0, 'It would appear that poor Lou really put his foot...', 12, 7, 100, 0, 0, 0, 42451, 'Lieutenant Horatio Laine to Player'),
(42558, 4, 0, 'In his mouth.', 12, 7, 100, 0, 0, 0, 42452, 'Lieutenant Horatio Laine to Player');

-- Clientside area trigger 5989 smart ai
SET @ENTRY := 5989;
DELETE FROM `areatrigger_scripts` WHERE `entry` = @ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (@ENTRY, 'SmartTrigger');
DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 0, 10, 251575, 42558, 0, 0, 0, 0, 0, 'On trigger - Creature Lieutenant Horatio Laine (42558) with guid 251575 (fetching): Set creature data #1 to 1', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 5989 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 5989, 2, 0, 28, 0, 26232, 0, 0, '', 0, 'Action invoker has completed quest quest Lou\'s Parting Thoughts (26232) (but not yet rewarded)');

-- Lieutenant Horatio Laine smart ai
SET @ENTRY := 42558;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 80, 4255800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Start timed action list id #Lieutenant Horatio Laine #0 (4255800) (update out of combat)', '');

-- Timed list 4255800 smart ai
SET @ENTRY := 4255800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 10, 251574, 42559, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Stormwind Investigator (42559) with guid 251574 (fetching): Talk 0 to invoker', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 0, 1, 11, 0, 0, 0, 0, 0, 0, 10, 251572, 42384, 0, 0, 0, 0, 0, 'After 4.5 seconds - Creature Homeless Stormwind Citizen (42384) with guid 251572 (fetching): Talk 11 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 10, 251574, 42559, 0, 0, 0, 0, 0, 'After 4 seconds - Creature Stormwind Investigator (42559) with guid 251574 (fetching): Talk 1 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Talk 2 to invoker', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Talk 3 to invoker', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.5 seconds - Self: Talk 4 to invoker', '');
