    DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=26477;
    INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
    (18, 26477, 47096, 0, 0, 9, 0, 12000, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
    (18, 26477, 47096, 0, 1, 9, 0, 11999, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
    (18, 26477, 61286, 0, 0, 9, 0, 12000, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
    (18, 26477, 61286, 0, 1, 9, 0, 11999, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
    (18, 26477, 61832, 0, 0, 9, 0, 11999, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
(18, 26477, 61832, 0, 1, 9, 0, 12000, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick');
