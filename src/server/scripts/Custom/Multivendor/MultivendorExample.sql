SET @MENU_ID = 12345;

INSERT INTO `gossip_menu_option` (`menuid`, `optionid`, `optionicon`, `optiontext`, `optiontype`, `optionnpcflag`, `actionmenuid`, `actionpoiid`, `boxcoded`, `boxmoney`, `boxtext`) VALUES
(@MENU_ID, 0, 4, 'VendorTest 465', 3, 128, 465, 0, 0, 0, ''),
(@MENU_ID, 1, 9, 'VendorTest 54', 3, 128, 54, 0, 0, 0, ''),
(@MENU_ID, 2, 6, 'VendorTest 35574', 3, 128, 35574, 0, 0, 100, 'These goods are special, so pay up!');
