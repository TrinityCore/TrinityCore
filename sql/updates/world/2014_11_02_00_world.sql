DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(10111,10028);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 10111, 0, 0, 0, 9, 0, 13145, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken The Vile Hold (13145)'),
(15, 10111, 0, 0, 1, 9, 0, 13146, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Generosity Abounds (13146)'),
(15, 10111, 0, 0, 2, 9, 0, 13147, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Matchmaker (13147)'),
(15, 10111, 0, 0, 3, 9, 0, 13147, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Stunning View (13160)'),
(15, 10028, 0, 0, 0, 9, 0, 13168, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Parting Gifts (13168)'),
(15, 10028, 0, 0, 1, 9, 0, 13169, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken An Undeads Best Friend (13169)'),
(15, 10028, 0, 0, 2, 9, 0, 13171, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken From Whence They Came (13171)'),
(15, 10028, 0, 0, 3, 9, 0, 13170, 0, 0, 0, 0, 0, '', 'Eye of Dominion - Show gossip option only if player has taken Honor is for the Weak (13170)');
