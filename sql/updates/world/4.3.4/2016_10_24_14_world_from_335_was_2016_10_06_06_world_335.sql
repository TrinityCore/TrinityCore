--
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID` IN (1079, 1080);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry` IN (1079, 1080);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 1079, 0, 0, 8, 0, 1074, 0, 0, 0, 0, 0, "", "Quest Covert Ops - Alpha requires quest Ineptitude + Chemicals = Fun rewarded AND"),
(19, 0, 1079, 0, 0, 8, 0, 1077, 0, 0, 0, 0, 0, "", "Quest Covert Ops - Alpha requires quest Special Delivery for Gaxim rewarded"),
(19, 0, 1080, 0, 0, 8, 0, 1074, 0, 0, 0, 0, 0, "", "Quest Covert Ops - Beta requires quest Ineptitude + Chemicals = Fun rewarded AND"),
(19, 0, 1080, 0, 0, 8, 0, 1077, 0, 0, 0, 0, 0, "", "Quest Covert Ops - Beta requires quest Special Delivery for Gaxim rewarded"),
(20, 0, 1079, 0, 0, 8, 0, 1074, 0, 0, 0, 0, 0, "", "Quest mark for Covert Ops - Alpha requires quest Ineptitude + Chemicals = Fun rewarded AND"),
(20, 0, 1079, 0, 0, 8, 0, 1077, 0, 0, 0, 0, 0, "", "Quest mark for Covert Ops - Alpha requires quest Special Delivery for Gaxim rewarded"),
(20, 0, 1080, 0, 0, 8, 0, 1074, 0, 0, 0, 0, 0, "", "Quest mark for Covert Ops - Beta requires quest Ineptitude + Chemicals = Fun rewarded AND"),
(20, 0, 1080, 0, 0, 8, 0, 1077, 0, 0, 0, 0, 0, "", "Quest mark for Covert Ops - Beta requires quest Special Delivery for Gaxim rewarded");
