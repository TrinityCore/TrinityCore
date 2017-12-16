-- Ol' Beasley --> Add more texts
DELETE FROM `creature_text` WHERE `CreatureID`=1395 AND `GroupID`=0 AND `ID`>2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1395,0,3,"Could ye spare some coin?",12,7,100,0,0,0,179,0,"Ol\' Beasley"),
(1395,0,4,"Help a poor bloke out?",12,7,100,0,0,0,183,0,"Ol\' Beasley"),
(1395,0,5,"Shine yer armor for a copper.",12,7,100,0,0,0,185,0,"Ol\' Beasley"),
(1395,0,6,"It\'s all their fault, stupid orcs. Had to burn my farm to the ground.",12,7,100,0,0,0,187,0,"Ol\' Beasley"),
(1395,0,7,"Alms for the poor?",12,7,100,0,0,0,181,0,"Ol\' Beasley");
