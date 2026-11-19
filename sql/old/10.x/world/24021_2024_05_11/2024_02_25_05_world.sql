 -- Tognus Flintfire smart ai
SET @ENTRY := 1241;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (124100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 0, 0, 48000, 48000, 80, 124100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 48 seconds (0s initially) (OOC) - Self: Start timed action list id #Tognus Flintfire #0 (124100) (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -5581.89, -429.616, 397.568, 0, 'After 0 seconds - Self: Move to position (-5581.89, -429.616, 397.568, 0)'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 50, 386, 15, 0, 0, 0, 0, 8, 0, 0, 0, -5581.09, -429.379, 398.676, 2.02458, 'After 1 seconds - Self: Summon gameobject Metal Mace (386) at (-5581.09, -429.379, 398.676, 2.02458) and despawn in 15 s'),
(@ENTRY * 100, 9, 2, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to STATE_WORK_MINING (233)'),
(@ENTRY * 100, 9, 3, 0, '', 0, 0, 100, 0, 11000, 11000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Set emote state to 0'),
(@ENTRY * 100, 9, 4, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set walk'),
(@ENTRY * 100, 9, 5, 0, '', 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -5582.41, -430.97, 397.447, 0, 'After 2 seconds - Self: Move to position (-5582.41, -430.97, 397.447, 0)'),
(@ENTRY * 100, 9, 6, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.39307, 'After 1 seconds - Self: Set orientation to 5.39307'),
(@ENTRY * 100, 9, 7, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 50, 386, 29, 0, 0, 0, 0, 8, 0, 0, 0, -5581.48, -432.389, 397.881, 2.18166, 'After 1 seconds - Self: Summon gameobject Metal Mace (386) at (-5581.48, -432.389, 397.881, 2.18166) and despawn in 29 s'),
(@ENTRY * 100, 9, 8, 0, '', 0, 0, 100, 0, 30000, 30000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -5582.41, -430.97, 397.447, 0, 'After 30 seconds - Self: Move to position (-5582.41, -430.97, 397.447, 0)');

-- Delete 27 db Spawns that should be temp spawns
DELETE FROM `gameobject` WHERE `id`=386;
