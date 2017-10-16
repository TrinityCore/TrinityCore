/*
-- Remove wrong aggro text for Volcor and add the correct ones
DELETE FROM `creature_text` WHERE `CreatureID`=3692 AND `GroupID`=4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3692,4,0,"Here they come!",12,7,100,0,0,0,1250,0,"Volcor"),
(3692,4,1,"We can overcome these foul creatures!",12,7,100,0,0,0,1251,0,"Volcor"),
(3692,4,2,"We shall earn our deaths at the very least!",12,7,100,0,0,0,1252,0,"Volcor"),
(3692,4,3,"Don\'t give up! Fight to the death!",12,7,100,0,0,0,1253,0,"Volcor");
*/
