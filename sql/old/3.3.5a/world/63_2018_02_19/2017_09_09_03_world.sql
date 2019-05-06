-- Balgaras the --> Add More Texts
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=1364 AND `source_type`=0 AND `id`=1;
DELETE FROM `creature_text` WHERE `CreatureID`=1364 AND `GroupID`=0 AND `ID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1364,0,1,'$n!  Betrayer of Ragnaros!',12,6,100,0,0,0,449,0,'Balgaras the Foul'),
(1364,0,2,'The Dark Iron Dwarves shall reclaim their rightful lands!',12,6,100,0,0,0,450,0,'Balgaras the Foul'),
(1364,0,3,'Foolish $C!  You are no match for the minions of Ragnaros!',12,6,100,0,0,0,451,0,'Balgaras the Foul'),
(1364,0,4,'A worthless $R such as you, $n, has no right to walk these lands!',12,6,100,0,0,0,452,0,'Balgaras the Foul'),
(1364,0,5,'$n!  Prepare to meet your doom!',12,6,100,0,0,0,453,0,'Balgaras the Foul'),
(1364,0,6,'Who is this weak $C who challenges my might?  Die fool!',12,6,100,0,0,0,454,0,'Balgaras the Foul'),
(1364,0,7,'I am Balgaras the Foul.  And you, $n, are about to become nothing more than ash and dust.',12,6,100,0,0,0,456,0,'Balgaras the Foul');
