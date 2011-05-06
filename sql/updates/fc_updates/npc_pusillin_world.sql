-- Pusillin script
DELETE FROM `script_texts` WHERE `npc_entry` = 14354;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES 
(14354, -1901000,'If your want the key, you\'ll have to catch me!',0,0,0,0,'Pusillin 1'),
(14354, -1901002,'Why would you ever want to harm me!? Come. Friends we can be!',0,0,0,0,'pusillin 3'),
(14354, -1901001,'Chase me if you dare! I run without a care',0,0,0,0,'pusillin 2'),
(14354, -1901003,'DIE?! You make Pusillin cry!',0,0,0,0,'pusillin 4'),
(14354, -1901004,'Say hello to my little friends!',0,0,0,0,'pusillin 5');

DELETE FROM `script_waypoint` WHERE `entry` = 14354;
INSERT INTO `script_waypoint` (`entry`,`pointid`,`location_x`,`location_y`,`location_z`,`waittime`,`point_comment`) VALUES
(14354,0,83.389,-198.429,-3.95,0,'pusillin 1'),
(14354,1,-161.875,-199.876,-4.159,0,'pusillin 2'),
(14354,2,-153.733,-271.985,-4.147,0,'pusillin 3'),
(14354,3,-133.801,-349.232,-4.067,0,'pusillin 4'),
(14354,4,110.114,-355.008,-4.115,0,'pusillin 5'),
(14354,5,111.454,-468.53,-2.71,0,'pusillin 6'),
(14354,6,112,-513.661,-6.91,0,'pusillin 7'),
(14354,7,110.34,-538.94,-11.07,0,'pusillin 8'),
(14354,8,68.37,-546.36,-15.24,0,'pusillin 9'),
(14354,9,49.46,-564.84,-19.41,0,'pusillin 10'),
(14354,10,50.29,-641.51,-25.14,0,'pusillin 11'),
(14354,11,31.16,-696.35,-25.16,0,'pusillin 12'),
(14354,12,2.65,-695.88,-25.16,0,'pusillin 13'),
(14354,13,3,-671.75,-12.64,0,'pusillin 14'),
(14354,14,10.38,-665.57,-12.64,0,'pusillin 15'),
(14354,15,8.11,-673.06,-12.64,0,'pusillin 16'),
(14354,16,11.46,-708.44,-12.64,0,'pusillin 17');

UPDATE `creature` SET `spawntimesecs` = 300 WHERE `guid` = 84377;

UPDATE `creature_template` SET `ScriptName` = 'npc_pusillin', `speed_run` = 2.14286 WHERE `entry` =14354;