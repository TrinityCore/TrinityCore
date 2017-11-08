DELETE FROM `smart_scripts` WHERE `entryorguid`=-308973;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-308973,0,0,0,25,0,100,0,0,0,0,0,71,0,0,1814,0,2507,0,1,0,0,0,0,0,0,0,'Darkspear Watcher - Reset - Set Equipment'),
(-308973,0,1,0,4,0,100,0,0,0,0,0,71,0,0,28914,0,2507,0,1,0,0,0,0,0,0,0,'Darkspear Watcher - Aggro - Set Equipment'),
(-308973,0,2,0,1,0,100,0,3000,3000,3000,3000,5,37,0,0,0,0,0,1,0,0,0,0,0,0,0,'Darkspear Watcher - OOC - Emote "OneShotAttack2HTight"'),
(-308973,0,3,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,'Darkspear Watcher - In Combat - Cast "Shoot"');

DELETE FROM `creature_template_addon` WHERE `entry`=38217;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`auras`) VALUES
(38217,0,0,257,0,0,0,0, 0, '18950');
