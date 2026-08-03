 -- Ancient Drakkari Soothsayer smart ai
SET @ENTRY := 26812;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 0, 47778, 0, 0, 0, 11, 47795, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Blow Snow (47778) hit - Self: Cast spell  Cold Cleanse (47795) on Self'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Blow Snow (47778) hit - Set event phase to phase 1'),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 144, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Blow Snow (47778) hit - Self: Enable Immune to PC'),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 145, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Blow Snow (47778) hit - Self: Enable Immune to NPC'),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 146, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Blow Snow (47778) hit - Self: Set uninteractable'),
(@ENTRY, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Blow Snow (47778) hit - Self: Set run'),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 127, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Blow Snow (47778) hit - Self: Pause movement for 0sec on movement slot 0'),
(@ENTRY, 0, 7, 8, 23, 1, 100, 1, 47795, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 20, 188464, 40, 0, 0, 0, 0, 0, 'When creature has aura Cold Cleanse (47795) (once) - Self: Move to Closest gameobject Ancient Troll Mummy (188464) in 40 yards (point id 1)'),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When creature has aura Cold Cleanse (47795) (once) - Self: Talk 0 to invoker'),
(@ENTRY, 0, 9, 0, 34, 0, 100, 0, 8, 1, 0, 0, 80, 2681200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Ancient Drakkari Soothsayer #0 (2681200) (update always)'),
(@ENTRY, 0, 10, 0, 11, 0, 100, 0, 0, 0, 0, 0, 91, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Remove stand state SLEEP'),
(@ENTRY, 0, 11, 0, 0, 0, 100, 0, 0, 0, 3000, 5000, 11, 9734, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 5 seconds (0 - 0s initially) (IC) - Self: Cast spell  Holy Smite (9734) on Victim'),
(@ENTRY, 0, 12, 0, 8, 0, 100, 0, 47681, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  Aggro Ancient Drakkari (47681) hit - Caster: Talk 1 to invoker'),
(@ENTRY, 0, 13, 0, 8, 0, 100, 0, 47681, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  Aggro Ancient Drakkari (47681) hit - Self: Attack Caster');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26811 AND `source_type` = 0 AND `id` IN (6,9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26811, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 127, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  Blow Snow (47778) hit - Self: Pause movement for 0sec on movement slot 0'),
(26811, 0, 9, 0, 34, 0, 100, 0, 8, 1, 0, 0, 80, 2681200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Ancient Drakkari Soothsayer #0 (2681200) (update always)');
