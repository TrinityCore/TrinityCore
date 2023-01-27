ALTER TABLE `characters` ADD `inventorySlots` tinyint(3) unsigned NOT NULL DEFAULT '16' AFTER `customDisplay3`;

UPDATE `character_inventory` SET `slot`=`slot`+8 WHERE `slot`>=39 AND `bag`=0 ORDER BY slot DESC;
