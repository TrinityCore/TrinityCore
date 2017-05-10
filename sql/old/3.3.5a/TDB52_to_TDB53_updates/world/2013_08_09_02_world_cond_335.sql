UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `Id`=8280;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) and `SourceEntry`=8280;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(20, 0, 8280, 0, 0, 8, 0, 8275, 0, 0, 0, 0, 0, '', 'Securing the Supply Lines can be taken if Taking Back Silithus (Alliance) Complete'),
(19, 0, 8280, 0, 0, 8, 0, 8275, 0, 0, 0, 0, 0, '', 'Securing the Supply Lines can be taken if Taking Back Silithus (Alliance) Complete'),
(20, 0, 8280, 0, 1, 8, 0, 8276, 0, 0, 0, 0, 0, '', 'Securing the Supply Lines can be taken if Taking Back Silithus (Horde) Complete'),
(19, 0, 8280, 0, 1, 8, 0, 8276, 0, 0, 0, 0, 0, '', 'Securing the Supply Lines can be taken if Taking Back Silithus (Horde) Complete');
