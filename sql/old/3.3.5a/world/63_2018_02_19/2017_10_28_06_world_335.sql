-- Marshal Gryan Stoutmantle
UPDATE `creature_text` SET `Type`=14 WHERE `CreatureID`=234 AND `GroupID`=0 AND `ID`=0;
DELETE FROM `creature_text` WHERE `CreatureID`=234 AND `GroupID`=0 AND `ID` IN (1,2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(234,0,1,"All hail, $n! Defender of The People!",14,7,100,0,0,0,197,0,"Marshal Gryan Stoutmantle"),
(234,0,2,"Three cheers for $n!  This land shall be ours once again!",14,7,100,0,0,0,199,0,"Marshal Gryan Stoutmantle");
