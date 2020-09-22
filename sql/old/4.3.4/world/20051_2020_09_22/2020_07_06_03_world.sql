DELETE FROM `reference_loot_template` WHERE `Entry` IN (34078, 34079, 34151, 34152, 34153);

DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=12192 AND `OptionIndex`=11);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(12192, 11, 80);
