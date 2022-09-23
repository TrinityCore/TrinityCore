DELETE FROM `creature_text` WHERE `CreatureID`= 28587 AND `GroupID`= 6;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(28587, 6, 0, 'The armies of iron will conquer all!', 14, 0, 100, 0, 0, 13965, 31420, 'Volkhan - Slay'),
(28587, 6, 1, 'Feh! Pathetic!', 14, 0, 100, 0, 0, 13966, 31421, 'Volkhan - Slay'),
(28587, 6, 2, 'You have cost me too much work!', 14, 0, 100, 0, 0, 13967, 31422, 'Volkhan - Slay');
