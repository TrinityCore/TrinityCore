-- Rohan the Assassin --> Add gossip option
DELETE FROM `gossip_menu` WHERE `MenuID` IN (7118,7119,7120,7121,7122);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7118,8380,0),
(7119,8381,0),
(7120,8382,0),
(7121,8383,0),
(7122,8384,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=7101 AND `OptionID`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (7118,7119,7120,7121);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7101,0,0,"What is it that you do exactly, Rohan?",12003,1,1,7118,0,0,0,"",0,0),
(7118,0,0,"So what brings you to Light's Hope?",12005,1,1,7119,0,0,0,"",0,0),
(7119,0,0,"What? Bonescythe?",12007,1,1,7120,0,0,0,"",0,0),
(7120,0,0,"Wow, you're insane, aren't you?",12009,1,1,7121,0,0,0,"",0,0),
(7121,0,0,"Hey wait, Gadgetzan has a disco?",12011,1,1,7122,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID` IN (8380,8381,8382,8383,8384);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`) VALUES
(8380,"Ah, as the title states I am an assassin for the Scarlet Crusade. I spend my days exterminating high priority targets and nights at the Gadgetzan discotheque. Dancing is my true calling. Assassination just pays the bills.","",12004,0,1,0,1,0,1,0,1),
(8381,"Good question, $r. In my younger days I was footloose and fancy free without a care in the world. In those days I would sing in a barber shop quartet out of Stormwind known as the Four Dons. That's where I learned how to craft the Bonescythe digs.","",12006,0,1,0,273,0,1,0,1),
(8382,"Yes, Bonescythe. You see, it was our tenor, an ornery fellow known as Don Julio, who got me started on the whole thing. In his travels throughout Lordaeron, Don Julio picked up many interesting skills, one of them being the ability to take the bones of fallen Scourge and fashion them into a lethal set of leather armor - perfectly suited for an assassin.","",12008,0,1,0,1,0,1,0,25),
(8383,"I'm as sane as the next guy, $g fella:lady;. Believe what you will, but I AM capable of fashioning this armor. If you're interested, maybe we can make a deal. The sooner I can get out of the assassination business, the better.","",12010,0,1,0,1,0,1,0,0),
(8384,"Members only, scrub!","",12012,0,1,0,273,0,25,0,0);
