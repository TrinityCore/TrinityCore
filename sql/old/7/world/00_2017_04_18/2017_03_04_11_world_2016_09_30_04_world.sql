--
UPDATE quest_template_addon SET PrevQuestID=9671 WHERE ID=9751;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry` IN (9513, 9523);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 9513, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Quest Reclaiming the Ruins requires quest A Small Start rewarded OR"),
(19, 0, 9513, 0, 1, 8, 0, 9512, 0, 0, 0, 0, 0, "", "Quest Reclaiming the Ruins requires quest Cookie's Jumbo Gumbo rewarded"),
(20, 0, 9513, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Quest mark for Reclaiming the Ruins requires quest A Small Start rewarded OR"),
(20, 0, 9513, 0, 1, 8, 0, 9512, 0, 0, 0, 0, 0, "", "Quest mark for Reclaiming the Ruins requires quest Cookie's Jumbo Gumbo rewarded"),
(19, 0, 9523, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Quest Precious and Fragile Things Need Special Handling requires quest A Small Start rewarded OR"),
(19, 0, 9523, 0, 1, 8, 0, 9512, 0, 0, 0, 0, 0, "", "Quest Precious and Fragile Things Need Special Handling requires quest Cookie's Jumbo Gumbo rewarded"),
(20, 0, 9523, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Quest mark for Precious and Fragile Things Need Special Handling requires quest A Small Start rewarded OR"),
(20, 0, 9523, 0, 1, 8, 0, 9512, 0, 0, 0, 0, 0, "", "Quest mark for Precious and Fragile Things Need Special Handling requires quest Cookie's Jumbo Gumbo rewarded");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (7398, 7400);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7398, 8862, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Gossip text 8862 requires quest A Small Start rewarded OR"),
(14, 7398, 8862, 0, 1, 8, 0, 9512, 0, 0, 0, 0, 0, "", "Gossip text 8862 requires quest Cookie's Jumbo Gumbo rewarded"),
(14, 7400, 8868, 0, 0, 8, 0, 9506, 0, 0, 0, 0, 0, "", "Gossip text 8868 requires quest A Small Start rewarded OR"),
(14, 7400, 8868, 0, 1, 8, 0, 9512, 0, 0, 0, 0, 0, "", "Gossip text 8868 requires quest Cookie's Jumbo Gumbo rewarded");

UPDATE `conditions` SET `ConditionTypeOrReference`=8, `ConditionValue1`=9506, `Comment`="Item Rune Covered Tablet requires quest A Small Start rewarded in order to drop" WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=23759;
