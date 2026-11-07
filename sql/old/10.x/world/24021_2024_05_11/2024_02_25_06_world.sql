 -- Gremlock Pilsnor smart ai
SET @ENTRY := 1699;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (169900);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 0, 0, 107000, 107000, 80, 169900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 107 seconds (0s initially) (OOC) - Self: Start timed action list id #Gremlock Pilsnor #0 (169900) (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set walk'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 14000, 14000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -5594.47, -545.82, 398.948, 0, 'After 14 seconds - Self: Move to position (-5594.47, -545.82, 398.948, 0)'),
(@ENTRY * 100, 9, 2, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.81514, 'After 1 seconds - Self: Set orientation to 1.81514'),
(@ENTRY * 100, 9, 3, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Take off all equipped items'),
(@ENTRY * 100, 9, 4, 0, '', 0, 0, 100, 0, 25000, 25000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -5600.58, -543.316, 399.097, 0, 'After 25 seconds - Self: Move to position (-5600.58, -543.316, 399.097, 0)'),
(@ENTRY * 100, 9, 5, 0, '', 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.7822, 'After 3 seconds - Self: Set orientation to 4.7822'),
(@ENTRY * 100, 9, 6, 0, '', 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 76334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Cast spell  Cooking - Cosmetic (76334) on Self'),
(@ENTRY * 100, 9, 7, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 76334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Cast spell  Cooking - Cosmetic (76334) on Self'),
(@ENTRY * 100, 9, 8, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 76334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Cast spell  Cooking - Cosmetic (76334) on Self'),
(@ENTRY * 100, 9, 9, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 76334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Cast spell  Cooking - Cosmetic (76334) on Self'),
(@ENTRY * 100, 9, 10, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 11, 76334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Cast spell  Cooking - Cosmetic (76334) on Self'),
(@ENTRY * 100, 9, 11, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 71, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Equip equipment set 1'),
(@ENTRY * 100, 9, 12, 0, '', 0, 0, 100, 0, 10000, 10000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -5593.66, -542.815, 398.948, 0, 'After 10 seconds - Self: Move to position (-5593.66, -542.815, 398.948, 0)'),
(@ENTRY * 100, 9, 13, 0, '', 0, 0, 100, 0, 12000, 12000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 12 seconds - Self: Set emote state to STATE_USESTANDING (69)'),
(@ENTRY * 100, 9, 14, 0, '', 0, 0, 100, 0, 20000, 20000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 20 seconds - Self: Set emote state to 0');
