-- Vindicator Boros gossip menu changes after turning in quest "I Shoot Magic Into the Darkness"
-- Gossip menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7465 AND `TextID`=9076;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7465,9076,0);

-- Missing Gossip Otions for Vindicator Boros during quest "I Shoot Magic Inte the Darkness"
-- Gossip menu option text
DELETE FROM `gossip_menu_option` WHERE `MenuID`=7465;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7465,0,0,"Where should I begin my search for the portal?",14503,1,1,7501,0,0,0,"",0,0);

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=7465;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7465,9076,0,0,8,0,9700,0,0,0,0,0,"","Gossip text 9076 requires quest 'I Shoot Magic Into the Darkness' rewarded"),
(15,7465,0,0,0,47,0,9700,10,0,0,0,0,'','Show gossip menu options only if Quest 9700 is taken (active)');
