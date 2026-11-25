DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (43455,37121,37087,37115,37218,916,895,786,912,837,926);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(43455, 11831, 60192), -- Saripal Smolderbrew
(37121, 10878, 60192), -- Teegli Merrowith
(37087, 10892, 60192), -- Jona Ironstock
(37115, 10879, 60192), -- Teo Hammerstorm
(37218, 10899, 60192), -- Coldridge Citizen
(916, 4676, 60192), -- Solm Hargrin
(895, 4675, 60192), -- Thorgas Grimson
(786, 10893, 60192), -- Grelin Whitebeard
(912, 4684, 60192), -- Thran Khorman
(837, 4679, 60192), -- Branstock Khalder
(926, 4678, 60192); -- Bromos Grummner

DELETE FROM `gossip_menu` WHERE (`MenuID`=10878 AND `TextID`=558) 
OR (`MenuID`=10892 AND `TextID`=15131) 
OR (`MenuID`=10879 AND `TextID`=15110) 
OR (`MenuID`=10899 AND `TextID`=15140) 
OR (`MenuID`=10893 AND `TextID`=15132)
OR (`MenuID`=11831 AND `TextID`=16590);

INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(10878, 558, 60192), -- 37121 (Teegli Merrowith)
(10892, 15131, 60192), -- 37087 (Jona Ironstock)
(10879, 15110, 60192), -- 37115 (Teo Hammerstorm)
(10899, 15140, 60192), -- 37218 (Coldridge Citizen)
(10893, 15132, 60192), -- 786 (Grelin Whitebeard)
(11831, 16590, 15595); -- 43455 (Saripal Smolderbrew)

UPDATE `gossip_menu` SET `VerifiedBuild`=60192 WHERE (`MenuID`=4047 AND `TextID`=4937) OR (`MenuID`=4675 AND `TextID`=4999) OR (`MenuID`=4684 AND `TextID`=1215) OR (`MenuID`=4679 AND `TextID`=4436) OR (`MenuID`=4678 AND `TextID`=3974) OR (`MenuID`=10898 AND `TextID`=15139) OR (`MenuID`=1262 AND `TextID`=1914) OR (`MenuID`=10900 AND `TextID`=15145);
DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (10878,11831,10879));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(10878, 111892, 0, 3, 'Most definitely.  Might you mentor me?', 36936, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60192),
(11831, 112546, 0, 3, 'I am interested in warlock training.', 2544, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60192),
(10879, 111893, 0, 3, 'Teach me the ways of the spirits.', 7658, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60192);

UPDATE `gossip_menu_option` SET `GossipOptionID`=89758, `OptionBroadcastTextID`=7157, `VerifiedBuild`=60192 WHERE (`MenuID`=4679 AND `OptionID`=0); -- OptionBroadcastTextID: 7157 - 7160 - 7167 - 7168 - 7169
UPDATE `gossip_menu_option` SET `GossipOptionID`=89090, `VerifiedBuild`=60192 WHERE (`MenuID`=4684 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=89045, `VerifiedBuild`=60192 WHERE (`MenuID`=4675 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=90379, `OptionText`='I\'m lookin\' for rogue trainin\'.', `OptionBroadcastTextID`=7490, `VerifiedBuild`=60192 WHERE (`MenuID`=4676 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=91151, `VerifiedBuild`=60192 WHERE (`MenuID`=4678 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=111903, `Language`=7, `VerifiedBuild`=60192 WHERE (`MenuID`=10898 AND `OptionID`=0); -- OptionBroadcastTextID: 2823 - 7509 - 8097
UPDATE `gossip_menu_option` SET `GossipOptionID`=88556, `OptionBroadcastTextID`=2583, `VerifiedBuild`=60192 WHERE (`MenuID`=1262 AND `OptionID`=0); -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
