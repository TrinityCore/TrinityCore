-- Erich Lohan
DELETE FROM `creature_text` WHERE `CreatureID`=3627 AND `GroupID`=0 AND `ID`=7;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3627,0,7,'Ask me how to get a free drink at the Blue Recluse!',12,7,100,0,0,0,1192,0,'Erich Lohan');
