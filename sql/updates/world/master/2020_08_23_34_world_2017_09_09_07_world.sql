-- Professor Phizzlethorpe --> Add another text
DELETE FROM `creature_text` WHERE `CreatureID`=2768 AND `GroupID`=4 AND `ID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2768,4,1,"Help!! I told you this place was cursed!",12,0,100,0,0,0,858,0,"Professor Phizzlethorpe");
