ALTER TABLE `guild` DROP COLUMN `experience`, DROP COLUMN `todayExperience`;

ALTER TABLE `guild_bank_right` MODIFY COLUMN `gbright` mediumint(3) NOT NULL DEFAULT 0; -- temp type, can hold all values
UPDATE `guild_bank_right` SET `gbright` = -1 WHERE `gbright` = 255;
ALTER TABLE `guild_bank_right` MODIFY COLUMN `gbright` tinyint(3) NOT NULL DEFAULT 0;

ALTER TABLE `guild_bank_right` MODIFY COLUMN `SlotPerDay` bigint(10) NOT NULL DEFAULT 0; -- temp type, can hold all values
UPDATE `guild_bank_right` SET `SlotPerDay` = -1 WHERE `SlotPerDay` = 4294967295;
ALTER TABLE `guild_bank_right` MODIFY COLUMN `SlotPerDay` int(10) NOT NULL DEFAULT 0;
