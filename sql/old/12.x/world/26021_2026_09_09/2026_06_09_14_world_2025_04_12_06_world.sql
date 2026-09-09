-- Arch Druid Fandral Staghelm, gossip menu option requires the quest "Un' Goro Soil" rewarded and player to have herbalism skill below 75
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1630;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1630,0,0,1,8,0,3764,0,0,0,0,0,"","Gossip option 0 requires players have quest Un'Goro Soil rewarded AND"),
(15,1630,0,0,1,7,0,182,75,0,1,0,0,"","Requires player skill in herbalism lower than 75");
