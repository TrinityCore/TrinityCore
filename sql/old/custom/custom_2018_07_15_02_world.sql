DELETE FROM `playercreateinfo_skills` WHERE `skill`= 54 AND `classMask` IN (8, 32);
UPDATE `playercreateinfo_skills` SET `classMask`= `classMask` | 8 | 32 WHERE `skill`= 54;
DELETE FROM `playercreateinfo_skills` WHERE `skill`= 473;
INSERT INTO `playercreateinfo_skills` (`classMask`, `raceMask`, `skill`, `comment`) VALUES
(1 | 4 | 8 | 64 | 1024, 0, 473, 'Fist Weapons');
