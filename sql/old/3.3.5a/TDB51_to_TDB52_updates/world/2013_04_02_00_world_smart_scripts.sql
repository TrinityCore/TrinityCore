DELETE FROM `smart_scripts` WHERE `entryorguid`=19456 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES 
(19456,0,0,54,0,0,0,0,0,42,0,25,1,'Whitebarks Spirit - On summon - Set invincibility HP at 25%'),
(19456,1,0,4,1,0,0,0,0,1,0,0,1,'Whitebarks Spirit - On aggro (not repeatable) - Say 0'),
(19456,2,3,2,0,24,26,120000,120000,102,0,0,1,'Whitebarks Spirit - 24-26% HP - Disable HP reg (video)'),
(19456,3,4,61,0,0,0,0,0,101,0,0,1,'Whitebarks Spirit - Linked - Set home position'),
(19456,4,5,61,0,0,0,0,0,2,35,0,1,'Whitebarks Spirit - Linked - Change faction to friendly'),
(19456,5,6,61,0,0,0,0,0,1,1,0,1,'Whitebarks Spirit - Linked - Say 1'),
(19456,6,0,61,0,0,0,0,0,24,0,0,1,'Whitebarks Spirit - Linked - evade'),
(19456,7,0,0,0,2500,5500,12000,14500,11,31287,0,2,'Whitebarks Spirit - IC - Casts Entangling Roots'),
(19456,8,0,0,0,7500,7500,9500,16000,11,11442,0,2,'Whitebarks Spirit - IC - Casts Withered Touch'),
(19456,9,0,1,0,60000,60000,60000,60000,41,0,0,1,'Whitebarks Spirit - After 60sec OOC - Despawn');
