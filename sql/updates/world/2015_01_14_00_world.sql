-- Pandaren Skills
DELETE FROM `playercreateinfo_skills` WHERE `raceMask` IN (8388608, 16777216, 33554432, 58720256);
INSERT INTO `playercreateinfo_skills` (`raceMask`, `classMask`, `skill`, `rank`, `comment`)
VALUES
	(8388608, 0, 905, 0, 'Language: Pandaren (Neutral)'),
	(16777216, 0, 905, 0, 'Language: Pandaren (Alliance)'),
	(33554432, 0, 905, 0, 'Language: Pandaren (Horde)'),
	(58720256, 0, 899, 0, 'Racial - Pandaren');

-- Language: Common (Alliance)
UPDATE `playercreateinfo_skills` SET `raceMask` = 18875469 WHERE `skill` = 98;

-- Language: Orcish (Horde)
UPDATE `playercreateinfo_skills` SET `raceMask` = 33555378 WHERE `skill` = 109;
