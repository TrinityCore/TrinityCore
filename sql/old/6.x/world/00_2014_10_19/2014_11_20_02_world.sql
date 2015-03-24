ALTER TABLE `spell_target_position` CHANGE `id` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `spell_target_position` CHANGE `effIndex` `EffectIndex` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `spell_target_position` CHANGE `target_map` `MapID` SMALLINT(3) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `spell_target_position` CHANGE `target_position_x` `PositionX` FLOAT NOT NULL DEFAULT '0';
ALTER TABLE `spell_target_position` CHANGE `target_position_y` `PositionY` FLOAT NOT NULL DEFAULT '0';
ALTER TABLE `spell_target_position` CHANGE `target_position_z` `PositionZ` FLOAT NOT NULL DEFAULT '0';
ALTER TABLE `spell_target_position` DROP COLUMN `target_orientation`;
