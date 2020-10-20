-- Councilman Millstipe -- Add another line
DELETE FROM `creature_text` WHERE `CreatureID`=270 AND `GroupID`=0 AND `ID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(270,0,1,"The forest is crawling with worgen and ghouls.  Something must be done!",12,7,100,0,0,0,66,0,"Councilman Millstipe");
