DELETE FROM `spell_area` WHERE `spell` IN (241211, 273380) AND `area` = 8499;
INSERT INTO `spell_area` (`spell`, `area`, `flags`) VALUES
(241211, 8499, 2),
(273380, 8499, 2);
