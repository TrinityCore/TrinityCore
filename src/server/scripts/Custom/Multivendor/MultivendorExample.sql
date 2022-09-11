SET @MENU_ID = 12345;

INSERT INTO `gossip_menu_option` (`menuid`, `optionid`, `OptionNpc`, `optiontext`, `OptionNpcFlag`, `actionmenuid`, `actionpoiid`, `boxcoded`, `boxmoney`, `boxtext`) VALUES
(@MENU_ID, 0, 1, 'VendorTest 465', 128, 465, 0, 0, 0, ''),
(@MENU_ID, 1, 1, 'VendorTest 54', 128, 54, 0, 0, 0, ''),
(@MENU_ID, 2, 1, 'VendorTest 35574', 128, 35574, 0, 0, 100, 'These goods are special, so pay up!');
