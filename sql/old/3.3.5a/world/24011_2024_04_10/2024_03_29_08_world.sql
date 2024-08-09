-- Missing Gossip Otions for Jessera of Mac'Aree during quest "Mac'Aree Mushroom Menagerie"
-- Gossip option text
DELETE FROM `gossip_menu_option` WHERE `MenuID`=7452 AND `OptionID` IN (0,1,2,3);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7452,0,0,"Jessera, could you direct me towards the aquatic stinkhorn?",14284,1,1,7453,0,0,0,"",0,0),
(7452,1,0,"Jessera, could you direct me towards the ruinous polyspore?",14287,1,1,7454,0,0,0,"",0,0),
(7452,2,0,"Jessera, could you direct me towards the fel cone fungus?",14290,1,1,7456,0,0,0,"",0,0),
(7452,3,0,"Jessera, could you direct me towards the blood mushrooms?",14292,1,1,7457,0,0,0,"",0,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup`=7452 AND `SourceEntry` IN (0,1,2,3);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7452,0,0,0,47,0,9648,10,0,0,0,0,'',"Show gossip menu options only if Quest 9648 is taken (active)"),
(15,7452,1,0,0,47,0,9648,10,0,0,0,0,'',"Show gossip menu options only if Quest 9648 is taken (active)"),
(15,7452,2,0,0,47,0,9648,10,0,0,0,0,'',"Show gossip menu options only if Quest 9648 is taken (active)"),
(15,7452,3,0,0,47,0,9648,10,0,0,0,0,'',"Show gossip menu options only if Quest 9648 is taken (active)");
