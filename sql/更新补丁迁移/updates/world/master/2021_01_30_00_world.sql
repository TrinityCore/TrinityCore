DELETE FROM `player_racestats` WHERE `race` IN (31, 32, 35, 37);
INSERT INTO `player_racestats` (`race`, `str`, `agi`, `sta`, `inte`) VALUES
(31, 1, 2, 0, -3), -- Zandalari
(32, 1, -2, 2, -1), -- Kul Tiran
(35, -3, 3, -1, 1), -- Vulpera
(37, -2, 1, -1, 2); -- Mechagnome

UPDATE `player_racestats` SET `str`=2, `agi`=-2, `sta`=1, `inte`=-1 WHERE  `race`=34; -- DarkIron
UPDATE `player_racestats` SET `str`=3, `agi`=-3, `sta`=1, `inte`=-1 WHERE  `race`=36; -- Maghar
UPDATE `player_racestats` SET `str`=-2, `agi`=1, `sta`=-1, `inte`=2 WHERE  `race`=27; -- Nightborne
UPDATE `player_racestats` SET `str`=0, `agi`=-1, `sta`=1, `inte`=0 WHERE  `race`=30; -- Lightforged
