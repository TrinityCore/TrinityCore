-- Inspector Tarem
DELETE FROM `gossip_menu` WHERE `MenuID`=8761 AND `TextID`=11127;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8761,11127,0);

DELETE FROM `npc_text` WHERE `ID`=11127;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`) VALUES
(11127,"What are you doing here? Do you wish to defile the ashes of this slain family further? Leave this place. You are not welcome.","",22040,0,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8761;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,8761,11127,0,0,6,0,67,0,0,0,0,0,"","Show text 11127 if Player is Horde"),
(14,8761,11126,0,0,6,0,469,0,0,0,0,0,"","Show text 11126 if Player is Alliance");

UPDATE `smart_scripts` SET `target_type`=1, `target_param1`=0, `target_param2`=0 WHERE `entryorguid`=23567 AND `source_type`=0 AND `id`=2;
