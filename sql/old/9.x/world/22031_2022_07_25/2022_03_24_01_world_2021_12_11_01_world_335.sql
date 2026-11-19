--
DELETE FROM `gossip_menu_option_locale` WHERE `Locale` IN ('zhTW','zhCN') AND `MenuID`=6763 AND `OptionID`=0;
INSERT INTO `gossip_menu_option_locale`(`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`) VALUES
(6763, 0, 'zhTW', '你自由了，梅特森。那個壞格林奇不會再傷害你了。', NULL),
(6763, 0, 'zhCN', '你自由了，梅森。坏格林奇再也不能伤害你了。', NULL);
