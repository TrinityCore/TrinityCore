--
DELETE from `creature_text` WHERE `CreatureID`=46254;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46254, 0, 0, 'Forest just setback!', 14, 0, 100, 0, 0, 0, 46474, 3, 'Hogger - Stockades - SAY_PULL'),
(46254, 1, 0, '%s Enrages!', 41, 0, 100, 0, 0, 0, 46631, 3, 'Hogger - Stockades - SAY_ENRAGE'),
(46254, 2, 0, 'Yiiipe!', 14, 0, 100, 0, 0, 0, 46476, 3, 'Hogger - Stockades - SAY_DEATH');

