-- Hogan Ference -- Add more lines
DELETE FROM `creature_text` WHERE `CreatureID`=325 AND `GroupID`=0 AND `ID`>2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(325,0,3,"When will someone do something about the undead?",12,7,100,0,0,0,961,0,"Hogan Ference"),
(325,0,4,"Where is everyone?",12,7,100,0,0,0,962,0,"Hogan Ference"),
(325,0,5,"I can't even visit my father's grave in peace anymore.",12,7,100,0,0,0,963,0,"Hogan Ference");
