DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(13226,13227);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 13226, 0, 0, 8, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (A) Can only be taken if Honor Above All Else is not rewarded'),
(19, 0, 13226, 0, 0, 9, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (A) Can only be taken if Honor Above All Else is not taken'),
(19, 0, 13226, 0, 0, 28, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (A) Can only be taken if Honor Above All Else is not completed'),
(20, 0, 13226, 0, 0, 8, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (A) Can only be taken if Honor Above All Else is not rewarded'),
(20, 0, 13226, 0, 0, 9, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (A) Can only be taken if Honor Above All Else is not taken'),
(20, 0, 13226, 0, 0, 28, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (A) Can only be taken if Honor Above All Else is not completed'),

(19, 0, 13227, 0, 0, 8, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (H) Can only be taken if Honor Above All Else is not rewarded'),
(19, 0, 13227, 0, 0, 9, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (H) Can only be taken if Honor Above All Else is not taken'),
(19, 0, 13227, 0, 0, 28, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (H) Can only be taken if Honor Above All Else is not completed'),
(20, 0, 13227, 0, 0, 8, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (H) Can only be taken if Honor Above All Else is not rewarded'),
(20, 0, 13227, 0, 0, 9, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (H) Can only be taken if Honor Above All Else is not taken'),
(20, 0, 13227, 0, 0, 28, 0, 13036, 0, 0, 1, 0, 0, '', 'Judgment Day Comes! (H) Can only be taken if Honor Above All Else is not completed');
