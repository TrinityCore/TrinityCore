ALTER TABLE `areatrigger_teleport` DROP PRIMARY KEY;
ALTER TABLE `areatrigger_teleport` ADD COLUMN `IsCustom` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`;
ALTER TABLE `areatrigger_teleport` ADD PRIMARY KEY (`ID`, `IsCustom`);
