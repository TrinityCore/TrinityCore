--
DELETE FROM `conditions` WHERE `SourceEntry` IN (35813, 33612) AND `SourceTypeOrReferenceId`=23;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23, 24539, 35813, 0, 0, 9, 0, 11476, 0, 0, 0, 0, 0, "", "Shiny Knife can be bought only if on quest 'A Carver and a Croaker'"),
(23, 24291, 33612, 0, 0, 9, 0, 11309, 0, 0, 0, 0, 0, "", "Fresh Pound of Flesh can be bought only if on quest 'Parts for the Job'");
