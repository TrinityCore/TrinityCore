-- Princess Moira Bronzebeard
DELETE FROM `creature_text` WHERE `CreatureID`=8929;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8929,0,0,"%s is visibly shaken by the death of Emperor Thaurissan.",16,0,100,18,0,0,5429,0,"Princess Moira Bronzebeard");
