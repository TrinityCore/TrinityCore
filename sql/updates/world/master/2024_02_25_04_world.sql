-- Kogan Forgestone SAI
SET @ENTRY := 1245;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (124500);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 1, 0, 100, 0, 0, 0, 59000, 59000, 80, 124500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 59 seconds (0s initially) (OOC) - Self: Start timed action list id #Kogan Forgestone #0 (124500) (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.9147, 'After 1 seconds - Self: Set orientation to 2.9147'),
(@ENTRY * 100, 9, 1, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 50, 372, 15, 0, 0, 0, 0, 8, 0, 0, 0, -5577.55, -429.308, 398.608, 0.733038, 'After 0 seconds - Self: Summon gameobject Battleground Shield (372) at (-5577.55, -429.308, 398.608, 0.733038) and despawn in 15 s'),
(@ENTRY * 100, 9, 2, 0, '', 0, 0, 100, 0, 4000, 4000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to STATE_WORK_MINING (233)'),
(@ENTRY * 100, 9, 3, 0, '', 0, 0, 100, 0, 15000, 15000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15 seconds - Self: Set emote state to 0'),
(@ENTRY * 100, 9, 4, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set walk'),
(@ENTRY * 100, 9, 5, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -5575.67, -430.965, 397.466, 0, 'After 0 seconds - Self: Move to position (-5575.67, -430.965, 397.466, 0)'),
(@ENTRY * 100, 9, 6, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.89208, 'After 1 seconds - Self: Set orientation to 3.89208'),
(@ENTRY * 100, 9, 7, 0, '', 0, 0, 100, 0, 0, 0, 0, 0, 50, 372, 15, 0, 0, 0, 0, 8, 0, 0, 0, -5577.32, -432.01, 397.881, 0.226892, 'After 0 seconds - Self: Summon gameobject Battleground Shield (372) at (-5577.32, -432.01, 397.881, 0.226892) and despawn in 15 s'),
(@ENTRY * 100, 9, 8, 0, '', 0, 0, 100, 0, 38000, 38000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -5576.37, -429.771, 397.484, 0, 'After 38 seconds - Self: Move to position (-5576.37, -429.771, 397.484, 0)');
-- Delete 22 db Spawns that should be temp spawns
DELETE FROM `gameobject` WHERE `id`=372;
