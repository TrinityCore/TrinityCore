UPDATE `command` SET
`name`= "reload creature_onkill_reward",
`help`= "Syntax: .reload creature_onkill_reward \nReload creature_onkill_reward table." WHERE `permission`= 635;

ALTER TABLE `creature_onkill_reputation` ADD COLUMN `CurrencyId1` MEDIUMINT(8) DEFAULT 0 NULL AFTER `TeamDependent`,
ADD COLUMN `CurrencyId2` MEDIUMINT(8) DEFAULT 0 NULL AFTER `CurrencyId1`,
ADD COLUMN `CurrencyId3` MEDIUMINT(8) DEFAULT 0 NULL AFTER `CurrencyId2`,
ADD COLUMN `CurrencyCount1` MEDIUMINT(8) DEFAULT 0 NULL AFTER `CurrencyId3`,
ADD COLUMN `CurrencyCount2` MEDIUMINT(8) DEFAULT 0 NULL AFTER `CurrencyCount1`,
ADD COLUMN `CurrencyCount3` MEDIUMINT(8) DEFAULT 0 NULL AFTER `CurrencyCount2`; 
RENAME TABLE`creature_onkill_reputation` TO `creature_onkill_reward`;
