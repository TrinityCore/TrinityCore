DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=41058;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 0, 41058, 0, 24, 1, 29625, 0, 0, '', 'Hyldnir Harpoon target Hyldsmeet Proto-Drake'),
(18, 0, 41058, 0, 24, 1, 29754, 0, 0, '', 'Hyldnir Harpoon target Column Ornament');
