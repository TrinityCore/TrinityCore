DELETE FROM `spell_proc_event` WHERE `entry` IN (35100,35102,35103);
INSERT INTO `spell_proc_event` VALUES 
(35100,0,0,0,0,0,524288,0),
(35102,0,0,0,0,0,524288,0),
(35103,0,0,0,0,0,524288,0);


DELETE FROM `spell_proc_event` WHERE `entry` IN (33511);
INSERT INTO `spell_proc_event` VALUES 
(33511,0,0,0,0,0,131072,0);
