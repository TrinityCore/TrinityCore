-- Rayne --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuID` IN (7123,7124,7125);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7123,8385,0),
(7124,8386,0),
(7125,8387,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=7104 AND `OptionID`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (7123,7124);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7104,0,0,"Hello, Rayne. What brings the Cenarion Circle to the Plaguelands?",12015,1,1,7123,0,0,0,"",0,0),
(7123,0,0,"Are these lands not beyond healing? They look pretty beat up.",12017,1,1,7124,0,0,0,"",0,0),
(7124,0,0,"What kind of services?",12019,1,1,7125,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID` IN (8385,8386,8387);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`) VALUES
(8385,"We are all drawn here for different reasons, $c.$B$B<Rayne smiles.>$B$BI am here to meet with Rimblat of the Earthen Ring. He has some interesting theories on cleansing these lands.","",12016,0,1,0,1,0,1,0,0),
(8386,"I think not. Rimblat has already proven that new life can grow from the sundered earth. Now we must find a way to reproduce and, more importantly, sustain the growth.$B$BWhile I am here, I am also offering my services to adventurers entering Naxxramas.","",12018,0,1,0,1,0,1,0,0),
(8387,"I am a crafter of some renown, $c. With the proper materials, I am able to craft an armor known as Dreamwalker. Druids - and even some shaman - are drawn to this armor due to its magical properties. Are you interested?","",12020,0,1,0,1,0,1,0,6);
