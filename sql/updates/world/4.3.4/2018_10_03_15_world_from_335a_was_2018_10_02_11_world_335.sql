/*
-- Eitrigg
DELETE FROM `gossip_menu` WHERE `MenuID` IN (21313,21314,21315,21316,21317,21318,21319);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (2901,2902,2903,2904,2905,2906,2907,2908,21313,21314,21315,21316,21317,21318,21319);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2901,0,0,"Hello, Eitrigg. I bring news from Blackrock Spire.",5990,1,1,2902,0,0,0,"",0,0),
(2902,0,0,"There is only one Warchief, Eitrigg!",5992,1,1,2903,0,0,0,"",0,0),
(2903,0,0,"What do you mean?",5994,1,1,2904,0,0,0,"",0,0),
(2904,0,0,"Hearthglen?? But...",5996,1,1,2905,0,0,0,"",0,0),
(2905,0,0,"I will take you up on that offer, Eitrigg.",5998,1,1,2906,0,0,0,"",0,0),
(2906,0,0,"Ah, so that is how they pushed the Dark Iron to the lower parts of the Spire.",6000,1,1,2907,0,0,0,"",0,0),
(2907,0,0,"Perhaps there exists a way?",6002,1,1,2908,0,0,0,"",0,0),
(2908,0,0,"As you wish, Eitrigg.",6004,1,1,0,0,0,0,"",0,0);

UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=1 WHERE `ID`=3574;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=1 WHERE `ID`=3575;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=1 WHERE `ID`=3576;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=11, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=1 WHERE `ID`=3577;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=1 WHERE `ID`=3578;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=1, `em0_4`=0, `em0_5`=1 WHERE `ID`=3579;
UPDATE `npc_text` SET `em0_0`=0, `em0_1`=1, `em0_2`=0, `em0_3`=25 WHERE `ID`=3580;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=3144;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2901;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,2901,0,0,0,9,0,4941,0,0,0,0,0,"","Show gossip option if quest 'Eitrigg's Wisdom' is taken");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3144 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `event_param1`=2908 WHERE `entryorguid`=3144 AND `source_type`=0 AND `id`=0;
*/
