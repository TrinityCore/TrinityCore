DELETE FROM `spell_threat` WHERE `entry` IN (81297, 31935, 53595, 88263);
INSERT INTO `spell_threat` (`entry`, `pctMod`) VALUES
(81297, 2.5), -- Consecration
(31935, 1.5), -- Avenger's Shield
(53595, 2), -- Hammer of the Righteous
(88263, 2); -- Hammer of the Righteous
