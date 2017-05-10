-- Pandaren Skills
DELETE FROM `playercreateinfo_skills` WHERE `raceMask` IN (0x800000, 0x1000000, 0x2000000, 0x3800000);
INSERT INTO `playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`) VALUES
( 0x800000, 0, 905, 0, 'Language: Pandaren (Neutral)'),
(0x1000000, 0, 905, 0, 'Language: Pandaren (Alliance)'),
(0x2000000, 0, 905, 0, 'Language: Pandaren (Horde)'),
(0x3800000, 0, 899, 0, 'Racial - Pandaren');

-- Language: Common (Alliance)
UPDATE `playercreateinfo_skills` SET `raceMask`=`raceMask`|0x1000000 WHERE `skill` = 98;

-- Language: Orcish (Horde)
UPDATE `playercreateinfo_skills` SET `raceMask`=`raceMask`|0x2000000 WHERE `skill` = 109;
