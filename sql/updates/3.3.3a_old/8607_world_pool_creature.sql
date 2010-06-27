UPDATE `pool_creature` SET `description` = `comment` WHERE `comment` <> '' AND `comment` IS NOT NULL AND (`description` = '' OR `description` IS NULL);
ALTER TABLE `pool_creature` DROP COLUMN `comment`;
