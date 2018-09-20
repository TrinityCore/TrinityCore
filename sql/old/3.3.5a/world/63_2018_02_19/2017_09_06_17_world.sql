-- Garrick Padfoot
DELETE FROM `creature_text` WHERE `CreatureID`=103 AND `GroupID`=0 AND `ID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(103,0,1,"This land belongs to the Defias Brotherhood now!",12,7,100,0,0,0,7134,0,"Garrick Padfoot");
