--
UPDATE `smart_scripts` SET `event_param1` = 3681 WHERE `entryorguid` = 1855 AND `source_type` = 0 AND `id` = 0;

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (3502,3683,3682,3681);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3502,0,0,"I am ready to hear your tale, Tirion.",7219,1,1,3683,0,0,0,'',0,0),
(3683,0,0,"Thank you, Tirion. What of your identity?",7221,1,1,3682,0,0,0,'',0,0),
(3682,0,0,"That is terrible.",7223,1,1,3681,0,0,0,'',0,0),
(3681,0,0,"I will, Tirion.",7225,1,1,0,0,0,0,'',0,0);
