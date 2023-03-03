IF COL_LENGTH('battlenet_account_toys`','hasFanfare`') IS NULL
BEGIN
ALTER TABLE `battlenet_account_toys` ADD `hasFanfare` tinyint(1) DEFAULT '0' AFTER `isFavourite`;
END;