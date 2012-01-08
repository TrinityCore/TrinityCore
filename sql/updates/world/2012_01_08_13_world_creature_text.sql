-- NPC talk text insert from sniff "Orgrimmar Zeppelin Masters"
DELETE FROM `creature_text` WHERE `entry` IN (12136,26537,9564,34765) AND `groupid` IN (0);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(12136,0,0, 'The zeppelin to Grom''gol has just arrived! All aboard for Stranglethorn!',14,0,100,0,0,0, 'Snurk Bucksquick'),
(26537,0,0, 'The zeppelin to Warsong Hold has just arrived! All aboard for Borean Tundra!',14,0,100,0,0,0, 'Greeb Ramrocket'),
(9564,0,0, 'The zeppelin to Undercity has just arrived! All aboard for Tirisfal Glades!',14,0,100,0,0,0, 'Frezza'),
(34765,0,0, 'The zeppelin to Thunder Bluff has arrived! All aboard for a smooth ride across the Barrens!',14,0,100,0,0,0, 'Zelli Hotnozzle');
