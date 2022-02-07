ALTER TABLE `character_pet` CHANGE `slot` `slot` smallint NOT NULL DEFAULT '-1';

UPDATE `character_pet` SET `slot` = -1 WHERE `slot` = 100;
