-- Morris Lawry --> Add more texts
DELETE FROM `creature_text` WHERE `CreatureID`=1405 AND `GroupID`=0 AND `ID`>2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1405,0,3,"It\'s all their fault, stupid Alliance army. Just had to build their towers right behind my farm.",12,7,100,0,0,0,186,0,"Morris Lawry"),
(1405,0,4,"Spare some change for a poor blind man? ...What do you mean I\'m not blind? ...I\'M NOT BLIND! I CAN SEE!! It\'s a miracle!",12,7,100,0,0,0,184,0,"Morris Lawry"),
(1405,0,5,"I will gladly pay you Tuesday for a hamburger today.",12,7,100,0,0,0,182,0,"Morris Lawry"),
(1405,0,6,"It\'s all their fault, stupid orcs. Had to burn my farm to the ground.",12,7,100,0,0,0,187,0,"Morris Lawry"),
(1405,0,7,"Alms for the poor?",12,7,100,0,0,0,181,0,"Morris Lawry");
