UPDATE `creature_template` SET `gossip_menu_id`=5746, `npcflag`=1 WHERE  `entry`=11444;
UPDATE `gameobject_template` SET `faction`=114 ,`flags`=34 where  `entry`=177219;

DELETE FROM `smart_scripts` WHERE `entryorguid`=14323 AND `id`>6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(14323, 0, 7, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 14323, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Spawn - Start WP'),
(14323, 0, 8, 0, 38, 0, 100, 0, 1, 1, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Data Set 1 1 - Set Phase 2'),
(14323, 0, 9, 10, 40, 2, 100, 0, 19, 14323, 0, 0, 55, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Reached WP19 (Phase 2) - Stop WP'),
(14323, 0, 10, 11, 61, 2, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Reached WP19 (Phase 2) - Set Home Position'),
(14323, 0, 11, 12, 61, 2, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Reached WP19 (Phase 2) - Set Unit Flags'),
(14323, 0, 12, 0, 61, 2, 100, 0, 0, 0, 0, 0, 11, 22856, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Guard Slip\'kik - On Reached WP19 (Phase 2) - Cast Icelock');

DELETE FROM `waypoints` where `entry`=14323;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(14323, 1, 550.9423, 528.1198, -25.40169, 'Guard Slip kik'),
(14323, 2, 556.3312, 543.3906, -25.39986, 'Guard Slip kik'),
(14323, 3, 566.9871, 557.3884, -25.39788, 'Guard Slip kik'),
(14323, 4, 573.3212, 578.565, -25.40273, 'Guard Slip kik'),
(14323, 5, 532.9773, 586.9559, -25.40273, 'Guard Slip kik'),
(14323, 6, 515.2665, 599.5718, -25.40246, 'Guard Slip kik'),
(14323, 7, 494.9027, 606.5114, -25.40438, 'Guard Slip kik'),
(14323, 8, 480.8065, 598.4612, -25.40517, 'Guard Slip kik'),
(14323, 9, 477.7994, 587.293, -25.40587, 'Guard Slip kik'),
(14323, 10, 504.7797, 574.7651, -25.40086, 'Guard Slip kik'),
(14323, 11, 480.9391, 578.991, -25.40194, 'Guard Slip kik'),
(14323, 12, 477.7994, 587.293, -25.40587, 'Guard Slip kik'),
(14323, 13, 484.9685, 603.9871, -25.40483, 'Guard Slip kik'),
(14323, 14, 501.5791, 606.5353, -25.40406, 'Guard Slip kik'),
(14323, 15, 519.1758, 594.009, -25.403, 'Guard Slip kik'),
(14323, 16, 570.0894, 586.4958, -25.40273, 'Guard Slip kik'),
(14323, 17, 573.4045, 571.6358, -25.40239, 'Guard Slip kik'),
(14323, 18, 561.7436, 552.6977, -25.3998, 'Guard Slip kik'),
(14323, 19, 560.2891, 551.3965, -25.39884, 'Guard Slip kik');

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry` =179485;

DELETE FROM `smart_scripts` WHERE `entryorguid` =179485 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES

(179485,1,0,1,20,0,100,0,1193,0,0,0,45,1,1,0,0,0,0,19,14323,0,0,0,0,0,0,'Broken Trap - On Quest Reward (A Broken Trap) - Set Data on Guard Slip kik'),
(179485,1,1,2,61,0,100,0,0,0,0,0,70,7200,0,0,0,0,0,1,0,0,0,0,0,0,0,'Broken Trap - On Quest Reward (A Broken Trap) - Despawn GO'),
(179485,1,2,0,61,0,100,0,0,0,0,0,50,179512,300,0,0,0,0,8,0,0,0,558.806, 550.065, -25.4008, 3.14159,'Broken Trap - On Quest Reward (A Broken Trap) - Summon Fixed Trap');
