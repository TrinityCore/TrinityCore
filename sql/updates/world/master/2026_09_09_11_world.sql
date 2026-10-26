ALTER TABLE `areatrigger_create_properties` ADD `NewFlags` int unsigned NOT NULL DEFAULT 0 AFTER `Flags`;

UPDATE `areatrigger_create_properties` SET `NewFlags`=`NewFlags`|0x02 WHERE (`Flags`&0x0100)!=0;
UPDATE `areatrigger_create_properties` SET `NewFlags`=`NewFlags`|0x04 WHERE (`Flags`&0x0001)!=0;
UPDATE `areatrigger_create_properties` SET `NewFlags`=`NewFlags`|0x08 WHERE (`Flags`&0x0008)!=0;
UPDATE `areatrigger_create_properties` SET `NewFlags`=`NewFlags`|0x10 WHERE (`Flags`&0x0010)!=0;
UPDATE `areatrigger_create_properties` SET `NewFlags`=`NewFlags`|0x20 WHERE (`Flags`&0x0020)!=0;

ALTER TABLE `areatrigger_create_properties` DROP `Flags`;
ALTER TABLE `areatrigger_create_properties` CHANGE `NewFlags` `Flags` int unsigned NOT NULL DEFAULT 0 AFTER `IsAreatriggerCustom`;

ALTER TABLE `areatrigger_create_properties`
  ADD `Roll` float NOT NULL DEFAULT 0 AFTER `ShapeData7`,
  ADD `Pitch` float NOT NULL DEFAULT 0 AFTER `Roll`,
  ADD `Yaw` float NOT NULL DEFAULT 0 AFTER `Pitch`,
  ADD `TargetRoll` float NULL DEFAULT NULL AFTER `Yaw`,
  ADD `TargetPitch` float NULL DEFAULT NULL AFTER `TargetRoll`,
  ADD `TargetYaw` float NULL DEFAULT NULL AFTER `TargetPitch`;
