-- Ossirian the Unscarred
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1509027 AND -1509018;
DELETE FROM `creature_text` WHERE `entry`=15339;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15339, 0, 0, 'I am rejuvinated!', 14, 0, 100, 0, 0, 8593, 'SAY_SUPREME_1'),
(15339, 0, 1, 'My powers are renewed!', 14, 0, 100, 0, 0, 8595, 'SAY_SUPREME_2'),
(15339, 0, 2, 'My powers return!', 14, 0, 100, 0, 0, 8596, 'SAY_SUPREME_3'),
(15339, 1, 0, 'Protect the city at all costs!', 14, 0, 100, 0, 0, 8597, 'SAY_INTRO_1'),
(15339, 1, 1, 'To your posts. Defend the city.', 14, 0, 100, 0, 0, 8600, 'SAY_INTRO_2'),
(15339, 1, 2, 'Tresspassers will be terminated.', 14, 0, 100, 0, 0, 8601, 'SAY_INTRO_3'),
(15339, 2, 0, 'Sands of the desert rise and block out the sun!', 14, 0, 100, 0, 0, 8598, 'SAY_AGGRO'),
(15339, 3, 0, 'You are terminated.', 14, 0, 100, 0, 0, 8602, 'SAY_SLAY'),
(15339, 4, 0, 'I...have...failed.', 14, 0, 100, 0, 0, 8594, 'SAY_DEATH'),
(15339, 5, 0, 'The walls have been breached!', 14, 0, 100, 0, 0, 8599, 'SAY_KURINAXX_DEATH');

