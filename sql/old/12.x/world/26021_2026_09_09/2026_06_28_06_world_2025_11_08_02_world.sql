--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 5851;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,5851,0,0,0,47,0,925,10,0,0,0,0,'',"Group 0: Show Gossip Option 0 if player has taken quest 'Cairne's Hoofprint'");

DELETE FROM `creature_text` WHERE `CreatureID` = 3057;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3057,0,0,"The attackers have fled!  Strength and honor to the Horde!",14,0,100,0,0,0,10632,0,"Cairne Bloodhoof");
