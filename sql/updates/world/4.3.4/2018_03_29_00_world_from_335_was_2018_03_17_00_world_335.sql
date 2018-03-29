/*
-- Vindicator Vedaar --> Fix Gossip Texts
DELETE FROM `gossip_menu` WHERE `MenuID`=7407 AND `TextID` IN (8878,8877);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7407,8878,0),
(7407,8877,0);

UPDATE `npc_text` SET `em0_1`=6, `em0_3`=274 WHERE `ID`=8876;
DELETE FROM `npc_text` WHERE `ID`=8877;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_1`) VALUES
(8877,"Now that the demons have been dealt with, we can proceed with the establishment of a new base here.","",13767,0,1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7407;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7407,8878,0,0,8,0,9516,0,0,0,0,0,"","Show gossip text 8878 if quest 'Destroy the Legion' is rewarded"),
(14,7407,8878,0,0,8,0,9522,0,0,1,0,0,"","Show gossip text 8878 if quest 'Never Again!' is NOT rewarded"),
(14,7407,8877,0,0,8,0,9516,0,0,0,0,0,"","Show gossip text 8877 if quest 'Destroy the Legion' is rewarded"),
(14,7407,8877,0,0,8,0,9522,0,0,0,0,0,"","Show gossip text 8877 if quest 'Never Again!' is rewarded");
*/
