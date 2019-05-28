-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (22022);
DELETE FROM `smart_scripts` WHERE `entryorguid`=22022 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(22022, 0, 0, 0, 0, 0, 100, 0, 2000, 4000, 4000, 7000, 11, 34517, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Arcane Burst - IC - Cast Arcane Explosion'),
(22022, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 30, 0, 0, 0, 0, 0, 0, 'Arcane Burst - On just summoned - Start Attack');
