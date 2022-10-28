DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10638 AND `SourceEntry` IN (0, 1) AND `ConditionTypeOrReference` = 27;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(15, 10638, 0, 0, 0, 27, 0, 60, 3, 0, 1, 'Show gossip option if player is not level 60'),
(15, 10638, 1, 0, 0, 27, 0, 60, 3, 0, 1, 'Show gossip option if player is not level 60');
