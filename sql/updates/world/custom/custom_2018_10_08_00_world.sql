DELETE FROM `pet_levelstats` WHERE `creature_entry`= 1 AND `level` BETWEEN 81 AND 85;
INSERT INTO `pet_levelstats` (`creature_entry`, `level`, `hp`, `mana`, `armor`, `str`, `agi`, `sta`, `inte`, `spi`) VALUES
(1, 81, 8519, 1,  10085, 410, 170, 371, 81, 127),
(1, 82, 12895, 1, 10385, 436, 183, 387, 92, 139),
(1, 83, 15290, 1, 10684, 462, 196, 403, 103, 151),
(1, 84, 18705, 1, 10984, 488, 209, 419, 115, 163),
(1, 85, 32474, 1, 11647, 516, 222, 435, 127, 175);
