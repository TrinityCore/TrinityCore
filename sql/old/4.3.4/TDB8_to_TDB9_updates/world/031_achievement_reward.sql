--
DELETE FROM `achievement_reward` WHERE `entry` IN (4855, 4856);
INSERT INTO `achievement_reward` (`entry`, `title_A`, `title_H`) VALUES
(4855, 149, 149),
(4856, 150, 150);
