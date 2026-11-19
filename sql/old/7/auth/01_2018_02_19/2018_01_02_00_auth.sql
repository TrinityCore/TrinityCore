SET @sql_mode = @@session.sql_mode;
SET SESSION sql_mode = '';

ALTER TABLE `account`
  CHANGE `last_login` `last_login` TIMESTAMP NULL;

UPDATE `account` SET `last_login`=NULL WHERE `last_login`='0000-00-00 00:00:00';

ALTER TABLE `battlenet_accounts`
  CHANGE `last_login` `last_login` TIMESTAMP NULL;

UPDATE `battlenet_accounts` SET `last_login`=NULL WHERE `last_login`='0000-00-00 00:00:00';

SET SESSION sql_mode = @@sql_mode;
