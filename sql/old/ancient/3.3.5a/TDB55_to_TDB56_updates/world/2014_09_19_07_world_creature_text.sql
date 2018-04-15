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
