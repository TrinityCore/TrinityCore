-- Lord Ello Ebonlocke -- Add another line
DELETE FROM `creature_text` WHERE `CreatureID`=263 AND `GroupID`=0 AND `ID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(263,0,1,"The Night Watch alone cannot protect us forever.  We need the backing of the Stormwind Army.",12,7,100,0,0,0,64,0,"Lord Ello Ebonlocke");
