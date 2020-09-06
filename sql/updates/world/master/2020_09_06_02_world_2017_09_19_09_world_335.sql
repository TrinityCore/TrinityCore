-- Bloodfeather Harpy --> Add more texts
DELETE FROM `creature_text` WHERE `CreatureID`=2015 AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2015,0,0,'You will be easy prey, $C.',14,0,100,0,0,0,2231,0,'Bloodfeather Harpy'),
(2015,0,1,'A fine trophy your head will make, $R.',12,0,100,0,0,0,2229,0,'Bloodfeather Harpy'),
(2015,0,2,'My talons will shred your puny body, $R.',12,0,100,0,0,0,2230,0,'Bloodfeather Harpy');
