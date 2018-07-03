--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (13044, 13068, 13086, 13104, 13105, 13120, 13139, 13224, 13225, 13604, 13817);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 13044, 0, 0, 8, 0, 13008, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13044, 0, 0, 8, 0, 13039, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13044, 0, 0, 8, 0, 13040, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13068, 0, 0, 8, 0, 13139, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13086, 0, 0, 8, 0, 13070, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13104, 0, 0, 8, 0, 13086, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13104, 0, 1, 15, 0, 1503, 0, 0, 0, 0, 0, "", "Show quest 13104 if player is not a Death Knight"),
(19, 0, 13105, 0, 0, 8, 0, 13086, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13105, 0, 1, 15, 0, 32, 0, 0, 0, 0, 0, "", "Show quest 13105 if player is a Death Knight"),
(19, 0, 13120, 0, 0, 8, 0, 13105, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13120, 0, 1, 8, 0, 13104, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13139, 0, 0, 8, 0, 13125, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13139, 0, 0, 8, 0, 13130, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13139, 0, 0, 8, 0, 13135, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13224, 0, 0, 8, 0, 13157, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13225, 0, 0, 8, 0, 13157, 0, 0, 0, 0, 0, "", ""),
(19, 0, 13604, 0, 0, 19, 0, 1, 0, 0, 0, 0, 0, "", "Archivum Data Disc quest mark only shown in 10 man"),
(19, 0, 13817, 0, 0, 19, 0, 2, 0, 0, 0, 0, 0, "", "Heroic: Archivum Data Disc quest mark only shown in 25 man");
