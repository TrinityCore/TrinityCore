-- Adding Recruiter Lee quest starter
 DELETE FROM `creature_queststarter` WHERE `id` = 107934;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(107934, 42782);

  -- Alliance Recruit smart ai
SET @ENTRY := 107826;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107826 AND `SourceId` = 0;

 -- Alliance Recruit smart ai
SET @ENTRY := 107823;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107823 AND `SourceId` = 0;

 -- Alliance Recruit smart ai
SET @ENTRY := 107841;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107841 AND `SourceId` = 0;

 -- Alliance Recruit smart ai
SET @ENTRY := 107829;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107829 AND `SourceId` = 0;

 -- Alliance Recruit smart ai
SET @ENTRY := 107839;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107839 AND `SourceId` = 0;

 -- Alliance Recruit smart ai
SET @ENTRY := 107835;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107835 AND `SourceId` = 0;


 -- Kiruud the Relentless smart ai
SET @ENTRY := 108767;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 10800, 10800, 0, 49, 0, 0, 0, 0, 0, 0, 0, 19, 108765, 0, 0, 0, 0, 0, 0, 'Every 10.8 seconds (0s initially) (OOC) - Self: Attack Closest alive creature Seona Fireweaver (108765) in 100 yards', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108767 AND `SourceId` = 0;


 -- Seona Fireweaver smart ai
SET @ENTRY := 108765;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 10800, 10800, 0, 49, 198623, 0, 0, 0, 0, 0, 0, 19, 108767, 0, 0, 0, 0, 0, 0, 'Every 10.8 seconds (0s initially) (OOC) - Self: Attack Closest alive creature Kiruud the Relentless (108767) in 100 yards', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108765 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Niall Frostdrift
DELETE FROM `creature_text` WHERE `CreatureID` = 108743;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108743, 0, 0, 0, 'Next time I won\'t be so easy on you!', 12, 0, 100, 0, 0, 0, 'Niall Frostdrift');

 -- Niall Frostdrift smart ai
SET @ENTRY := 108743;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171858, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171858 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108743 AND `SourceId` = 0;


 -- Warning!! This SQL will override current texts
 -- Ramall Trueoak
DELETE FROM `creature_text` WHERE `CreatureID` = 108722;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108722, 0, 0, 0, 'Fine duel.', 12, 0, 100, 0, 0, 0, 'Ramall Trueoak');

 -- Ramall Trueoak smart ai
SET @ENTRY := 108722;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171773, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171773 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108722 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Tessa Wybroff
DELETE FROM `creature_text` WHERE `CreatureID` = 108744;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108744, 0, 0, 0, 'You take this round.', 12, 0, 100, 0, 0, 0, 'Tessa Wybroff');

 -- Tessa Wybroff smart ai
SET @ENTRY := 108744;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171863, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171863 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108744 AND `SourceId` = 0;


 -- Warning!! This SQL will override current texts
 -- Zelena Moonbreak
DELETE FROM `creature_text` WHERE `CreatureID` = 108746;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108746, 0, 0, 0, 'Well struck.', 12, 0, 100, 0, 0, 0, 'Zelena Moonbreak');

 -- Zelena Moonbreak smart ai
SET @ENTRY := 108746;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 172028, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  172028 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108746 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Audra Stoneshield
DELETE FROM `creature_text` WHERE `CreatureID` = 108748;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108748, 0, 0, 0, 'You take this round.', 12, 0, 100, 0, 0, 0, 'Audra Stoneshield');

 -- Audra Stoneshield smart ai
SET @ENTRY := 108748;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 12000, 15000, 0, 11, 172772, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 12 - 15 seconds (0 - 0s initially) (IC) - Self: Cast spell  172772 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108748 AND `SourceId` = 0;


 -- Warning!! This SQL will override current texts
 -- Haagios
DELETE FROM `creature_text` WHERE `CreatureID` = 108757;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108757, 0, 0, 0, 'Well struck.', 12, 0, 100, 0, 0, 0, 'Haagios');

 -- Haagios smart ai
SET @ENTRY := 108757;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171884, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171884 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108757 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Ciarra Neil
DELETE FROM `creature_text` WHERE `CreatureID` = 108752;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108752, 0, 0, 0, 'You have won.', 12, 0, 100, 0, 0, 0, 'Ciarra Neil');

 -- Ciarra Neil smart ai
SET @ENTRY := 108752;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171884, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171884 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108752 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Arctic Whitemace
DELETE FROM `creature_text` WHERE `CreatureID` = 108751;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108751, 0, 0, 0, 'Next time I won\'t be so easy on you!', 12, 0, 100, 0, 0, 0, 'Arctic Whitemace');

 -- Warning!! This SQL will override current texts
 -- Kihra
DELETE FROM `creature_text` WHERE `CreatureID` = 108723;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108723, 0, 0, 0, 'Well struck.', 12, 0, 100, 5, 0, 0, 'Kihra');

 --
 --  [ Creature templates ]
 --
DELETE FROM `creature_template_gossip` WHERE `CreatureID` = 108723 AND `MenuID` = 19861;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`) VALUES (108723, 19861);

 -- Kihra smart ai
SET @ENTRY := 108723;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171777, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171777 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108723 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Stormsinger Taalos
DELETE FROM `creature_text` WHERE `CreatureID` = 108755;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108755, 0, 0, 0, 'You take this round.', 12, 0, 100, 0, 0, 0, 'Stormsinger Taalos');

 -- Stormsinger Taalos smart ai
SET @ENTRY := 108755;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 172677, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  172677 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108755 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Lightshielder Baetrix
DELETE FROM `creature_text` WHERE `CreatureID` = 108758;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108758, 0, 0, 0, 'Next time I won\'t be so easy on you!', 12, 0, 100, 15, 0, 0, 'Lightshielder Baetrix');

 -- Lightshielder Baetrix smart ai
SET @ENTRY := 108758;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171922, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171922 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108758 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Navea the Purifier
DELETE FROM `creature_text` WHERE `CreatureID` = 108756;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108756, 0, 0, 0, 'Well struck.', 12, 0, 100, 0, 0, 0, 'Navea the Purifier');

 -- Navea the Purifier smart ai
SET @ENTRY := 108756;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 172675, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  172675 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108756 AND `SourceId` = 0;


 -- Warning!! This SQL will override current texts
 -- Antone Sula
DELETE FROM `creature_text` WHERE `CreatureID` = 108745;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108745, 0, 0, 0, 'You have bested me.', 12, 0, 100, 0, 0, 0, 'Antone Sula');

 -- Antone Sula smart ai
SET @ENTRY := 108745;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 172029, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  172029 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108745 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Loranea
DELETE FROM `creature_text` WHERE `CreatureID` = 108759;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108759, 0, 0, 0, 'Well struck.', 12, 0, 100, 0, 0, 0, 'Loranea');

 -- Loranea smart ai
SET @ENTRY := 108759;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171919, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171919 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108759 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Rorin Rivershade
DELETE FROM `creature_text` WHERE `CreatureID` = 108753;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108753, 0, 0, 0, 'Well struck.', 12, 0, 100, 0, 0, 0, 'Rorin Rivershade');

 -- Rorin Rivershade smart ai
SET @ENTRY := 108753;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 172670, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  172670 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108753 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Bridgette Hicks
DELETE FROM `creature_text` WHERE `CreatureID` = 108749;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108749, 0, 0, 0, 'You take this round.', 12, 0, 100, 0, 0, 0, 'Bridgette Hicks');

 -- Bridgette Hicks smart ai
SET @ENTRY := 108749;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 172769, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  172769 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108749 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Kymba Quickwidget
DELETE FROM `creature_text` WHERE `CreatureID` = 108747;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108747, 0, 0, 0, 'Next time I won\'t be so easy on you!', 12, 0, 100, 0, 0, 0, 'Kymba Quickwidget'),
(108747, 1, 0, 0, 'You have bested me.', 12, 0, 100, 0, 0, 0, 'Kymba Quickwidget');

 -- Kymba Quickwidget smart ai
SET @ENTRY := 108747;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171957, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171957 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108747 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Fingall Flamehammer
DELETE FROM `creature_text` WHERE `CreatureID` = 108754;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108754, 0, 0, 0, 'Next time I won\'t be so easy on you!', 12, 0, 100, 0, 0, 0, 'Fingall Flamehammer');

 -- Fingall Flamehammer smart ai
SET @ENTRY := 108754;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 172779, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  172779 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108754 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Eunna Young
DELETE FROM `creature_text` WHERE `CreatureID` = 108750;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108750, 0, 0, 0, 'Well struck.', 12, 0, 100, 0, 0, 0, 'Eunna Young');

 -- Eunna Young smart ai
SET @ENTRY := 108750;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 172757, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  172757 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108750 AND `SourceId` = 0;

 -- Warning!! This SQL will override current texts
 -- Fen Cinderpaw
DELETE FROM `creature_text` WHERE `CreatureID` = 108742;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `BroadcastTextId`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`) VALUES
(108742, 0, 0, 0, 'Thank you for the duel.', 12, 0, 100, 0, 0, 0, 'Fen Cinderpaw'),
(108742, 1, 0, 0, 'Well struck.', 12, 0, 100, 0, 0, 0, 'Fen Cinderpaw');

 -- Fen Cinderpaw smart ai
SET @ENTRY := 108742;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Attack Gossip player', ''),
(@ENTRY, 0, 4, 5, 2, 0, 100, 0, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit Ramall Trueoak (108722)', ''),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 9, 0, 0, 0, 100, 0, 0, 0, 2000, 3000, 0, 11, 171764, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171764 on Victim', ''),
(@ENTRY, 0, 10, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 108742 AND `SourceId` = 0;















