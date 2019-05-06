-- 
DELETE FROM `gossip_menu` WHERE `MenuID`=1043;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1043,1639,0),(1043,1640,0),(1043,1641,0);

DELETE FROM `npc_text` WHERE `ID`=1639;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`) VALUES
(1639,"","Yes? I have a breastplate to finish so this had better be good.",3985,1,1,0,0,0,0,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=1043;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,1043,1639,0,0,25,0,2018,0,0,1,0,0,"","Show gossip text 1639 if the spell 2018 is learned"),
(14,1043,1640,0,0,7,0,164,225,0,1,0,0,"","Show gossip text 1640 if Blacksmithing less than 225"),
(14,1043,1640,0,0,25,0,2018,0,0,0,0,0,"","Show gossip text 1640 if the spell 2018 is learned"),
(14,1043,1641,0,0,7,0,164,225,0,0,0,0,"","Show gossip text 1641 if Blacksmithing more than 225"),
(14,1043,1641,0,0,25,0,2018,0,0,0,0,0,"","Show gossip text 1641 if the spell 2018 is learned"),
(15,1043,0,0,0,25,0,2018,0,0,0,0,0,"","Show gossip option 1043 if the spell 2018 is learned"),
(15,1043,0,0,0,7,0,164,225,0,0,0,0,"","Show gossip option 1043 if  Blacksmithing more than 225");
