--
DELETE FROM `creature_text` WHERE `CreatureID` = 19218 AND `GroupID` = 4;
DELETE FROM `creature_text` WHERE `CreatureID` = 19710 AND `GroupID` = 5;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(19218,4,0,"You hear a faint unlocking sound...",16,0,100,0,0,0,19055,0,"Gatewatcher Gyro-Kill - On Death"),
(19710,5,0,"You hear a faint unlocking sound...",16,0,100,0,0,0,19055,0,"Gatewatcher Iron-Hand - On Death");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 35301;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,35301,0,0,31,0,3,21062,0,0,0,0,"","Group 0: Spell 'Suicide' (Effect 0) targets creature 'Nether Wraith'");
