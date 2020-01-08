UPDATE `smart_scripts` SET `target_o`= 2.44048 WHERE `entryorguid`= -395368 AND `source_type`= 0 AND `action_type`= 66 AND `id`= 1;
UPDATE `smart_scripts` SET `target_o`= 0.929677 WHERE `entryorguid`= -395339 AND `source_type`= 0 AND `action_type`= 66 AND `id`= 1;
UPDATE `smart_scripts` SET `target_o`= 1.04065 WHERE `entryorguid`= -395337 AND `source_type`= 0 AND `action_type`= 66 AND `id`= 1;
UPDATE `smart_scripts` SET `target_o`= 1.00445 WHERE `entryorguid`= -395336 AND `source_type`= 0 AND `action_type`= 66 AND `id`= 1;
UPDATE `smart_scripts` SET `target_o`= 1.21455 WHERE `entryorguid`= 4700600 AND `source_type`= 9 AND `action_type`= 66 AND `id`= 2;
UPDATE `smart_scripts` SET `target_o`= 2.72695 WHERE `entryorguid`= 4700600 AND `source_type`= 9 AND `action_type`= 66 AND `id`= 17;

SET @ENTRY := 4729300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 3600, 3600, 0, 0, 28, 58506, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3600 and 3600 ms (and later repeats every 0 and 0 ms) - Self: Remove aura due to spell Stealth (58506) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 0 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 200, 200, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 200 and 200 ms (and later repeats every 0 and 0 ms) - Self: Talk 4 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 3800, 3800, 0, 0, 12, 47294, 8, 0, 0, 0, 0, 8, 0, 0, 0, -269.828, 2293.46, 77.5684, 5.95157, "When in combat and timer at the begining between 3800 and 3800 ms (and later repeats every 0 and 0 ms) - Self: Summon creature High Warlord Cromush (47294) at (-269.828, 2293.46, 77.5684, 5.95157) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3500 and 3500 ms (and later repeats every 0 and 0 ms) - Self: Talk 5 // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 8400, 8400, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 8400 and 8400 ms (and later repeats every 0 and 0 ms) - Self: Talk 6 // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 0 and 0 ms) - None: Talk 7 // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 22800, 22800, 0, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 22800 and 22800 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_BOW (2) // ");
