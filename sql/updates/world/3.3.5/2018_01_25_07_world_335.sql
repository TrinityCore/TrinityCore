UPDATE `creature_template` SET `gossip_menu_id`=6522, `npcflag`=4227, `type_flags`=134217728 WHERE `entry`=15127; -- Samuel Hawke
UPDATE `creature_template` SET `gossip_menu_id`=6521, `npcflag`=4227, `type_flags`=134217728 WHERE `entry`=15126; -- Rutherford Twing
UPDATE `creature_template` SET `gossip_menu_id`=6142, `npcflag`=4227, `type_flags`=134217728 WHERE `entry`=14753; -- Illiyana Moonblaze
UPDATE `creature_template` SET `gossip_menu_id`=6141, `npcflag`=4227, `type_flags`=134217728 WHERE `entry`=14754; -- Kelm Hargunth

DELETE FROM `gossip_menu` WHERE `MenuID` IN (6521,6522,6141,6142);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6522,7724,0), -- Samuel Hawke
(6521,7723,0), -- Rutherford Twing
(6142,7295,0), -- Illiyana Moonblaze
(6141,7294,0); -- Kelm Hargunth

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6521,6522,6141,6142);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6522,0,1,"What goods have I earned the right to purchase from the League of Arathor?",10625,3,128,0,0,0,0,"",0,0), -- Samuel Hawke
(6521,0,1,"What goods have I earned the right to purchase from the Defilers?",10623,3,128,0,0,0,0,"",0,0), -- Rutherford Twing
(6142,0,1,"What goods have I earned the right to purchase for use in Warsong Gulch?",10021,3,128,0,0,0,0,"",0,0), -- Illiyana Moonblaze
(6141,0,1,"What goods have I earned the right to purchase for use in Warsong Gulch?",10019,3,128,0,0,0,0,"",0,0); -- Kelm Hargunth
