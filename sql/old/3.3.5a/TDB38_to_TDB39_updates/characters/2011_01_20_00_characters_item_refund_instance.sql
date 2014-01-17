ALTER TABLE `item_refund_instance`
ROW_FORMAT=DEFAULT,
CHANGE `item_guid` `item_guid` INT(10) UNSIGNED NOT NULL COMMENT 'Item GUID',
CHANGE `player_guid` `player_guid` INT(10) UNSIGNED NOT NULL COMMENT 'Player GUID',
CHANGE `paidMoney` `paidMoney` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `paidExtendedCost` `paidExtendedCost` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL;