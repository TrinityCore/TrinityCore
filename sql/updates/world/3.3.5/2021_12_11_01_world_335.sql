--
DELETE FROM `gossip_menu_option_locale` WHERE `Locale` IN ('zhTW','zhCN') AND `MenuID`=6763 AND `OptionID`=0;
INSERT INTO `gossip_menu_option_locale`(`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`) VALUES
(6763, 0, 'zhTW', '將一些馴鹿粉撒在梅森身上。', NULL),
(6763, 0, 'zhCN', '将一些驯鹿粉撒在梅森身上。', NULL);
