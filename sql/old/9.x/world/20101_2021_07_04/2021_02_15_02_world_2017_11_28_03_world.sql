-- "Stinky" Ignatz
DELETE FROM `creature_text` WHERE `CreatureID`=4880 AND `GroupID`=10 AND `ID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4880,10,2,"Look out!  The $n attacks!",12,0,100,0,0,0,1628,0,"\"Stinky\" Ignatz"),
(4880,10,3,"I'm glad you're here!  Because I need your help!!",12,0,100,0,0,0,1631,0,"\"Stinky\" Ignatz");
