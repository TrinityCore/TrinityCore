DELETE FROM `player_xp_for_level` WHERE `Level` BETWEEN 1 AND 12;
INSERT INTO `player_xp_for_level` (`Level`, `Experience`) VALUES
(1, 400),
(2, 900),
(3, 1400),
(4, 2100),
(5, 2800),
(6, 3600),
(7, 4500),
(8, 5400),
(9, 6500),
-- Up until here everything was as before. From now on, Classic uses significantly reduced values compared to 4.3.4.15595
(10, 6700),
(11, 7000),
(12, 7700);
