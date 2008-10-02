DELETE FROM `spell_proc_event` WHERE `entry` IN ( 11255, 12598 );
INSERT INTO `spell_proc_event` VALUES 
(11255,0,0,0,3,16384,16384,0),
(12598,0,0,0,3,16384,16384,0); 

DELETE FROM `spell_proc_event` WHERE `entry` IN ( 17793, 17796, 17801, 17802, 17803 );
INSERT INTO `spell_proc_event` VALUES 
(17793,0,0,593,5,1,65536,0),
(17796,0,0,593,5,1,65536,0),
(17801,0,0,593,5,1,65536,0),
(17802,0,0,593,5,1,65536,0),
(17803,0,0,593,5,1,65536,0);


DELETE FROM `spell_proc_event` WHERE `entry` IN ( 18094, 18095 );
INSERT INTO `spell_proc_event` VALUES 
(18094,0,0,0,5,10,131072,0),
(18095,0,0,0,5,10,131072,0);


DELETE FROM `spell_proc_event` WHERE `entry` IN ( 37443 );
INSERT INTO `spell_proc_event` VALUES 
(37443,0,0,0,0,0,65536,0); 
