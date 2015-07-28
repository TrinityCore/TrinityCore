DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (69708,70194,69784,70224,70225,69768,69767);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 69708, 0, 0, 31, 0, 3, 36954, 0, 0, 0, 0, '', 'Spell Ice Prison only hits Lich King'),
(13, 3, 70194, 0, 0, 31, 0, 3, 36954, 0, 0, 0, 0, '', 'Spell Dark Binding only hits Lich King'),
(13, 1, 69784, 0, 0, 31, 0, 3, 37014, 0, 0, 0, 0, '', 'Spell Destroy Wall only hits Ice Wall Target'),
(13, 1, 70224, 0, 0, 31, 0, 3, 37014, 0, 0, 0, 0, '', 'Spell Destroy Wall only hits Ice Wall Target'),
(13, 1, 70225, 0, 0, 31, 0, 3, 37014, 0, 0, 0, 0, '', 'Spell Destroy Wall only hits Ice Wall Target'),
(13, 1, 69768, 0, 0, 31, 0, 3, 37014, 0, 0, 0, 0, '', 'Spell Summon Ice Wall only hits Ice Wall Target'),
(13, 5, 69767, 0, 0, 31, 0, 3, 37014, 0, 0, 0, 0, '', 'Spell Summon Ice Wall only hits Ice Wall Target');
