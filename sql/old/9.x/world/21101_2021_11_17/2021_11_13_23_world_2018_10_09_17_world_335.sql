-- Earthcaller Franzahl
UPDATE `creature_template` SET `gossip_menu_id`=5812 WHERE `entry`=14348;

DELETE FROM `gossip_menu` WHERE `MenuID` IN (5812,5813,5814,5815,5816);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5812,6985,0),
(5813,6986,0),
(5814,6987,0),
(5815,6988,0),
(5816,6989,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5812,5813,5814,5815);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(5812,0,0,"Are you the Earthshaper capable of creating Elementium?",9576,1,1,0),
(5813,0,0,"What do you know of it, Franzahl?",9578,1,1,0),
(5814,0,0,"A fissure?",9580,1,1,0),
(5815,0,0,"So what happened?",9582,1,1,0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuID` IN (5812,5813,5814,5815);
INSERT INTO `gossip_menu_option_action` (`MenuID`, `OptionIndex`, `ActionMenuID`, `ActionPoiID`) VALUES
(5812,0,5813,0),
(5813,0,5814,0),
(5814,0,5815,0),
(5815,0,5816,0);

DELETE FROM `npc_text` WHERE `ID` IN (6986,6987,6988,6989);
INSERT INTO `npc_text` (`ID`, `BroadcastTextID0`, `Probability0`) VALUES
(6986,9577,1),
(6987,9579,1),
(6988,9581,1),
(6989,9583,1);
