-- 
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_zm_field_scout' WHERE `entry` IN (18581,18564);
UPDATE `gossip_menu_option` SET `OptionNpcFlag`=1 WHERE `MenuID`=7724 AND `OptionID`=0;

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=7722 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7722, 0, 0, 'Give me a battle standard. I will take control of Twin Spire Ruins.', 15537, 1, 1, 0, 0, 0, 0, 0, NULL, 0, 45114); -- OptionBroadcastTextID: 15537 - 15539

UPDATE `gossip_menu_option` SET `VerifiedBuild`=45114 WHERE (`MenuID`=7722 AND `OptionID`=1);
