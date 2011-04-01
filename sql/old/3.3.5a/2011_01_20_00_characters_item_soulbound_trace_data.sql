ALTER TABLE `item_soulbound_trade_data`
ROW_FORMAT=DEFAULT,
CHANGE `itemGuid` `itemGuid` INT(10) UNSIGNED NOT NULL COMMENT 'Item GUID';