ALTER TABLE `creature_default_trainer` DROP PRIMARY KEY;
RENAME TABLE `creature_default_trainer` TO `creature_trainer`;
ALTER TABLE `creature_trainer`
  ADD `MenuId` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `TrainerId`,
  ADD `OptionIndex` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MenuId`,
  ADD PRIMARY KEY(`CreatureId`,`MenuId`,`OptionIndex`);

DROP TABLE `gossip_menu_option_trainer`;
