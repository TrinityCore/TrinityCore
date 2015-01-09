DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `ConditionTypeOrReference` = 18 AND `SourceEntry` IN (65875,67303,67304,67305,65876,67306,67307,67308) ;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 65875, 0, 18, 1, 34497, 2, 0, '', 'Twins Pact - Dark'),
(13, 0, 67303, 0, 18, 1, 34497, 2, 0, '', 'Twins Pact - Dark'),
(13, 0, 67304, 0, 18, 1, 34497, 2, 0, '', 'Twins Pact - Dark'),
(13, 0, 67305, 0, 18, 1, 34497, 2, 0, '', 'Twins Pact - Dark'),
(13, 0, 65876, 0, 18, 1, 34496, 2, 0, '', 'Twins Pact - Light'),
(13, 0, 67306, 0, 18, 1, 34496, 2, 0, '', 'Twins Pact - Light'),
(13, 0, 67307, 0, 18, 1, 34496, 2, 0, '', 'Twins Pact - Light'),
(13, 0, 67308, 0, 18, 1, 34496, 2, 0, '', 'Twins Pact - Light');
