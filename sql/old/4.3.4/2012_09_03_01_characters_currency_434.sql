-- porting from characters table
INSERT INTO `character_currency` (`guid`, `currency`, `total_count`, `week_count`) SELECT `characters`.`guid`, 392, `characters`.`totalHonorPoints`, 0 FROM `characters` WHERE `characters`.`totalHonorPoints` > 0;
INSERT INTO `character_currency` (`guid`, `currency`, `total_count`, `week_count`) SELECT `characters`.`guid`, 390, `characters`.`conquestPoints`, 0 FROM `characters` WHERE `characters`.`conquestPoints` > 0;
