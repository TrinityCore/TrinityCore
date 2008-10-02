ALTER TABLE `realmd`.`account` 
    ADD COLUMN `mutetime` bigint(40) unsigned NOT NULL default '0' AFTER `tbc`;
