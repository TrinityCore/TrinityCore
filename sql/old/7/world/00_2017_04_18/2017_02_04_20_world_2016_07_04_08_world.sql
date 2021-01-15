-- 
UPDATE `quest_template_addon` SET `PrevQuestId`=0 WHERE `Id`=11875;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry`=11875;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 11875, 0, 0, 25, 0, 29354, 0, 0, 0, 0, 0, "", "Quest Gaining the Advantage requires Master Mining learned OR"),
(20, 0, 11875, 0, 0, 25, 0, 29354, 0, 0, 0, 0, 0, "", "Quest Gaining the Advantage requires Master Mining learned OR"),

(19, 0, 11875, 0, 1, 25, 0, 32678, 0, 0, 0, 0, 0, "", "Quest Gaining the Advantage requires Master Skinning learned OR"),
(20, 0, 11875, 0, 1, 25, 0, 32678, 0, 0, 0, 0, 0, "", "Quest Gaining the Advantage requires Master Skinning learned OR"),

(19, 0, 11875, 0, 2, 25, 0, 28695, 0, 0, 0, 0, 0, "", "Quest Gaining the Advantage requires Master Herbalism learned"),
(20, 0, 11875, 0, 2, 25, 0, 28695, 0, 0, 0, 0, 0, "", "Quest Gaining the Advantage requires Master Herbalism learned");
