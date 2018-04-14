/*
-- Huntsman Leopold --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuID` IN (7112,7111);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7111,8369,0),
(7112,8370,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=7102 AND `OptionID`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuID`=7111;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7102,0,0,"What is Cryptstalker armor?",11978,1,1,7111,0,0,0,"",0,0),
(7111,0,0,"Continue please.",11980,1,1,7112,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID` IN (8369,8370);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`) VALUES
(8369,"The preternatural ability of the crypt fiend to hunt and kill its foe is one studied and vaunted by men in my profession. I, myself, have slain thousands of the beasts in my crusade to rid this world of Scourge.$B$BWhile I loathe the crypt fiend for its merciless nature, its abilities must be admired. It has a job and it does it - very well.","",11979,0,1,0,1,0,1,0,1),
(8370,"I have discovered a use for the carapace of the crypt fiend and its various body parts. I am able to fashion an extremely light and very deadly set of armor by combining the fragments with some of the desecrated magical armors lost in Naxxramas.","",11981,0,1,0,1,0,1,0,0);
*/
