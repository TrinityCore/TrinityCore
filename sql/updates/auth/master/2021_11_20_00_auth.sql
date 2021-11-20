ALTER TABLE `battle_pets` ADD `nameTimestamp` bigint(20) NOT NULL DEFAULT '0' AFTER `name`;

UPDATE `battle_pets` SET `nameTimestamp`=UNIX_TIMESTAMP() WHERE LENGTH(`name`) > 0;
