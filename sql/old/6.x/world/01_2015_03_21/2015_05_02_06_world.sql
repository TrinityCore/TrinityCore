ALTER TABLE `battleground_template`
  CHANGE `id` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  DROP COLUMN `AllianceStartO`,
  DROP COLUMN `HordeStartO`;

UPDATE `battleground_template` SET `AllianceStartLoc`=1299, `HordeStartLoc`=1245 WHERE `ID`=30;
