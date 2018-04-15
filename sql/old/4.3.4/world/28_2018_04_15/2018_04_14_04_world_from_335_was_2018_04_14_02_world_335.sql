/*
-- Rimblat Earthshatter --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuID` IN (7113,7114,7115);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7113,8371,0),
(7114,8372,0),
(7115,8373,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (7103,7113,7114);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7103,0,0,"What brings a tauren to the Plaguelands?",11983,1,1,7113,0,0,0,"",0,0),
(7113,0,0,"Continue please.",11985,1,1,7114,0,0,0,"",0,0),
(7114,0,0,"Continue please.",11985,1,1,7115,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID` IN (8371,8372,8373);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`) VALUES
(8371,"In the last war, tauren fought. Shaman were sent in defense of this world against the Scourge invasion. Most lost their lives. Many were otherwise ripped asunder, their body parts used for foul experiments in that cursed citadel. I mourn their passing but my heart swells with pride at their courage.","",11984,0,1,0,1,0,1,0,1),
(8372,"I was a young tauren, barely having reached adolescence at the time, but I knew that those that would brave the battles for our freedom were well protected in my namesake's vestments.","",11986,0,1,0,1,0,1,0,0),
(8373,"The name of Earthshatter has been one held by my family for hundreds of years. And like my father and his father before him, I too have inherited the right to create the vestments of my namesake.","",11987,0,1,0,1,0,1,0,0);
*/
