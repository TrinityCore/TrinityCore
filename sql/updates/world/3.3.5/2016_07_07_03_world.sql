--
DELETE FROM `creature_queststarter` WHERE `quest` IN (3763, 3789, 3790, 3803);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(6735, 3763),
(6740, 3789),
(5111, 3790),
(4217, 3803);
