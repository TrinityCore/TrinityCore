ALTER TABLE `characters`
DROP COLUMN `power6`,
DROP COLUMN `power7`,
DROP COLUMN `power8`,
DROP COLUMN `power9`,
DROP COLUMN `power10`,
DROP COLUMN `power11`,
DROP COLUMN `ammoId`,
ADD COLUMN `guildId` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `grantableLevels`;
