DELETE FROM `conditions` WHERE `SourceEntry` IN (21104, 21105) AND `SourceTypeOrReferenceId`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1, 8716, 21104, 0, 0, 9, 0, 8620, 0, 0, 0, 0, 0, "", "Item Draconic for Dummies (Chapter II) can be looted if quest 'The Only Prescription' is taken"),
(1, 8717, 21104, 0, 0, 9, 0, 8620, 0, 0, 0, 0, 0, "", "Item Draconic for Dummies (Chapter II) can be looted if quest 'The Only Prescription' is taken"),
(1, 12396, 21104, 0, 0, 9, 0, 8620, 0, 0, 0, 0, 0, "", "Item Draconic for Dummies (Chapter II) can be looted if quest 'The Only Prescription' is taken"),
(1, 7461, 21105, 0, 0, 9, 0, 8620, 0, 0, 0, 0, 0, "", "Item Draconic for Dummies (Chapter III) can be looted if quest 'The Only Prescription' is taken"),
(1, 7463, 21105, 0, 0, 9, 0, 8620, 0, 0, 0, 0, 0, "", "Item Draconic for Dummies (Chapter III) can be looted if quest 'The Only Prescription' is taken");
