UPDATE `pool_template` SET `description` = `comment` WHERE `comment` <> '' AND `comment` IS NOT NULL AND (`description` = '' OR `description` IS NULL);
ALTER TABLE `pool_template` DROP COLUMN `comment`;
