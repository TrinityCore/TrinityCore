ALTER TABLE `quest_template`
    ADD COLUMN `ReqItemId5` mediumint(8) UNSIGNED DEFAULT '0' NOT NULL AFTER `ReqItemId4`,
    ADD COLUMN `ReqItemId6` mediumint(8) UNSIGNED DEFAULT '0' NOT NULL AFTER `ReqItemId5`,
    ADD COLUMN `ReqItemCount5` smallint(5) UNSIGNED DEFAULT '0' NOT NULL AFTER `ReqItemCount4`,
    ADD COLUMN `ReqItemCount6` smallint(5) UNSIGNED DEFAULT '0' NOT NULL AFTER `ReqItemCount5`;