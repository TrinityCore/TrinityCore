DELETE FROM `trinity_string` WHERE `entry` BETWEEN 12050 AND 12072;
DELETE FROM `creature_text` WHERE `entry`=15214 AND (`groupid`=0 OR `groupid` BETWEEN 27 AND 38);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15214, 27, 0, 'The Battle for Lake Wintergrasp is about to begin!', 41, 0, 100, 0, 0, 0, 30960, 2, 'Invisible Stalker'),
(15214, 28, 0, 'Let the battle begin!', 41, 0, 100, 0, 0, 0, 30961, 2, 'Invisible Stalker'),

(15214, 29, 0, 'The Alliance has defended Wintergrasp Fortress!', 41, 0, 100, 0, 0, 8455, 31403, 2, 'Invisible Stalker'),
(15214, 30, 0, 'The Alliance has captured Wintergrasp Fortress!', 41, 0, 100, 0, 0, 8455, 27817, 2, 'Invisible Stalker'),

(15214, 31, 0, 'The Horde has defended Wintergrasp Fortress!', 41, 0, 100, 0, 0, 8454, 31405, 2, 'Invisible Stalker'),
(15214, 32, 0, 'The Horde has captured Wintergrasp Fortress!', 41, 0, 100, 0, 0, 8454, 27816, 2, 'Invisible Stalker'),

(15214, 33, 0, 'The north-eastern keep tower has been damaged!', 41, 0, 100, 0, 0, 0, 31235, 2, 'Invisible Stalker'),
(15214, 34, 0, 'The north-eastern keep tower has been destroyed!', 41, 0, 100, 0, 0, 0, 31236, 2, 'Invisible Stalker'),

(15214, 35, 0, 'The south-western keep tower has been damaged!', 41, 0, 100, 0, 0, 0, 31233, 2, 'Invisible Stalker'),
(15214, 36, 0, 'The south-western keep tower has been destroyed!', 41, 0, 100, 0, 0, 0, 31238, 2, 'Invisible Stalker'),

(15214, 37, 0, 'You have reached Rank 1: Corporal', 42, 0, 100, 0, 0, 0, 30650, 0, 'Invisible Stalker - Player'),
(15214, 38, 0, 'You have reached Rank 2: First Lieutenant', 42, 0, 100, 0, 0, 0, 30651, 0, 'Invisible Stalker - Player');


/*
(15214, x, x, 'The Battle for Lake Wintergrasp is about to begin!', 41, 0, 100, 0, 0, 0, '30960', 'Invisible Stalker'),
(15214, x, x, 'Let the battle begin!', 41, 0, 100, 0, 0, 0, '30961', 'Invisible Stalker'),

(15214, x, x, 'The Eastspark siege workshop has been attacked by the Alliance!', 41, 0, 100, 0, 0, 0, '34408', 'Invisible Stalker'),
(15214, x, x, 'The Eastspark siege workshop has been captured by the Alliance!', 41, 0, 100, 0, 0, 0, '34404', 'Invisible Stalker'),
(15214, x, x, 'The Eastspark siege workshop has been attacked by the Horde!', 41, 0, 100, 0, 0, 0, '34409', 'Invisible Stalker'),
(15214, x, x, 'The Eastspark siege workshop has been captured by the Horde!', 41, 0, 100, 0, 0, 0, '34406', 'Invisible Stalker'),

(15214, x, x, 'The Westspark siege workshop has been attacked by the Alliance!', 41, 0, 100, 0, 0, 0, '34410', 'Invisible Stalker'),
(15214, x, x, 'The Westspark siege workshop has been captured by the Alliance!', 41, 0, 100, 0, 0, 0, '34405', 'Invisible Stalker'),
(15214, x, x, 'The Westspark siege workshop has been attacked by the Horde!', 41, 0, 100, 0, 0, 0, '34411', 'Invisible Stalker'),
(15214, x, x, 'The Westspark siege workshop has been captured by the Horde!', 41, 0, 100, 0, 0, 0, '34407', 'Invisible Stalker'),

(15214, x, x, 'The Sunken Ring siege workshop has been attacked by the Alliance!', 41, 0, 100, 0, 0, 0, '33059', 'Invisible Stalker'),
(15214, x, x, 'The Sunken Ring siege workshop has been captured by the Alliance!', 41, 0, 100, 0, 0, 0, '30938', 'Invisible Stalker'),
(15214, x, x, 'The Sunken Ring siege workshop has been attacked by the Horde!', 41, 0, 100, 0, 0, 0, '33060', 'Invisible Stalker'),
(15214, x, x, 'The Sunken Ring siege workshop has been captured by the Horde!', 41, 0, 100, 0, 0, 0, '30940', 'Invisible Stalker'),

(15214, x, x, 'The Broken Temple siege workshop has been attacked by the Alliance!', 41, 0, 100, 0, 0, 0, '33061', 'Invisible Stalker'),
(15214, x, x, 'The Broken Temple siege workshop has been captured by the Alliance!', 41, 0, 100, 0, 0, 0, '30939', 'Invisible Stalker'),
(15214, x, x, 'The Broken Temple siege workshop has been attacked by the Horde!', 41, 0, 100, 0, 0, 0, '33062', 'Invisible Stalker'),
(15214, x, x, 'The Broken Temple siege workshop has been captured by the Horde!', 41, 0, 100, 0, 0, 0, '30941', 'Invisible Stalker'),



(15214, x, x, 'The eastern tower has been damaged!', 41, 0, 100, 0, 0, 0, '31246', 'Invisible Stalker'),
(15214, x, x, 'The eastern tower has been destroyed!', 41, 0, 100, 0, 0, 0, '31251', 'Invisible Stalker'),

(15214, x, x, 'The southern tower has been damaged!', 41, 0, 100, 0, 0, 0, '31247', 'Invisible Stalker'),
(15214, x, x, 'The southern tower has been destroyed!', 41, 0, 100, 0, 0, 0, '31250', 'Invisible Stalker'),


(15214, x, x, 'The western tower has been damaged!', 41, 0, 100, 0, 0, 0, '31248', 'Invisible Stalker'),
(15214, x, x, 'The western tower has been destroyed!', 41, 0, 100, 0, 0, 0, '31249', 'Invisible Stalker'),



(15214, x, x, 'The north-western keep tower has been damaged!', 41, 0, 100, 0, 0, 0, '31232', 'Invisible Stalker'),
(15214, x, x, 'The north-western keep tower has been destroyed!', 41, 0, 100, 0, 0, 0, '31239', 'Invisible Stalker'),

(15214, x, x, 'The south-western keep tower has been damaged!', 41, 0, 100, 0, 0, 0, '31233', 'Invisible Stalker'),
(15214, x, x, 'The south-western keep tower has been destroyed!', 41, 0, 100, 0, 0, 0, '31238', 'Invisible Stalker'),

(15214, x, x, 'The north-eastern keep tower has been damaged!', 41, 0, 100, 0, 0, 0, '31235', 'Invisible Stalker'),
(15214, x, x, 'The north-eastern keep tower has been destroyed!', 41, 0, 100, 0, 0, 0, '31236', 'Invisible Stalker'),

(15214, x, x, 'The south-eastern keep tower has been damaged!', 41, 0, 100, 0, 0, 0, '31234', 'Invisible Stalker'),
(15214, x, x, 'The south-eastern keep tower has been destroyed!', 41, 0, 100, 0, 0, 0, '31237', 'Invisible Stalker'),


(15214, x, x, 'The Alliance has defended Wintergrasp Fortress!', 41, 0, 100, 0, 0, 8455, '31403', 'Invisible Stalker'),
(15214, x, x, 'The Alliance has captured Wintergrasp Fortress!', 41, 0, 100, 0, 0, 8455, '27817', 'Invisible Stalker'),

(15214, x, x, 'The Horde has defended Wintergrasp Fortress!', 41, 0, 100, 0, 0, 8454, '31405', 'Invisible Stalker'),
(15214, x, x, 'The Horde has captured Wintergrasp Fortress!', 41, 0, 100, 0, 0, 8454, '27816', 'Invisible Stalker'),

(0, x, x, 'You have reached Rank 1: Corporal', 42, 0, 100, 0, 0, 0, '30650', 'Cherber to 0'),
(0, x, x, 'You have reached Rank 2: First Lieutenant', 42, 0, 100, 0, 0, 0, '30651', 'Cherber to 0'),
*/
