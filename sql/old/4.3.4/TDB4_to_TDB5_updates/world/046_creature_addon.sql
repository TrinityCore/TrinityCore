DELETE FROM `creature_addon` WHERE `guid` IN (223343, 223369, 223370, 223387, 223388, 223389);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(223343, 0, 0x0, 0x1, 0, '108781 101864 29266'), -- Time-Twisted Scourge Beast - Time-Twisted, Diseased, Permanent Feign Death
(223369, 0, 0x0, 0x1, 0, '101878'), -- Time-Twisted Shadowtalon - Shred
(223370, 0, 0x0, 0x1, 438, ''), -- Time-Twisted Shadowtalon
(223387, 0, 0x0, 0x1, 0, '101862'), -- Time-Twisted Geist - Cannibalize
(223388, 0, 0x0, 0x1, 0, '101862'), -- Time-Twisted Geist - Cannibalize
(223389, 0, 0x0, 0x1, 0, '101862'); -- Time-Twisted Geist - Cannibalize
