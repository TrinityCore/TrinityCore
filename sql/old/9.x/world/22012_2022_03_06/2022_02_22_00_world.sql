ALTER TABLE `areatrigger_create_properties` 
  ADD `ShapeData6` float NOT NULL DEFAULT 0 AFTER `ShapeData5`,
  ADD `ShapeData7` float NOT NULL DEFAULT 0 AFTER `ShapeData6`;

ALTER TABLE `areatrigger_template` 
  ADD `Data6` float NOT NULL DEFAULT 0 AFTER `Data5`,
  ADD `Data7` float NOT NULL DEFAULT 0 AFTER `Data6`;

ALTER TABLE `gossip_menu_option` ADD `Language` int unsigned NOT NULL DEFAULT 0 AFTER `OptionNpcFlag`;

ALTER TABLE `playerchoice`
  ADD `CloseSoundKitId` int unsigned NOT NULL DEFAULT 0 AFTER `SoundKitId`,
  ADD `Duration` bigint NOT NULL DEFAULT 0 AFTER `CloseSoundKitId`,
  ADD `PendingChoiceText` VARCHAR(255) NOT NULL DEFAULT '' AFTER `Duration`;
