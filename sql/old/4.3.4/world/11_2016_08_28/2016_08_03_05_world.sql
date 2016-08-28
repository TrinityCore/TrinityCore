--
DELETE FROM `pet_levelstats` WHERE `creature_entry` = 26125 AND `level` IN (81,82,83,84,85);
INSERT INTO `pet_levelstats` (`creature_entry`, `level`, `hp`, `mana`, `armor`, `str`, `agi`, `sta`, `inte`, `spi`) VALUES
(26125, 81, 4608, 2160, 4570, 333, 96, 93, 100, 88),
(26125, 82, 4665, 2186, 4627, 335, 97, 94, 101, 89),
(26125, 83, 4722, 2212, 4684, 337, 98, 95, 102, 90),
(26125, 84, 4779, 2238, 4741, 339, 99, 96, 103, 91),
(26125, 85, 4836, 2264, 4798, 341, 100, 97, 104, 92);
