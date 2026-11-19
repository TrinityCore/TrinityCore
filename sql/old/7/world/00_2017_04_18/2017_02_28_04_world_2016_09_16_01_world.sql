--
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID` IN (11316, 11319);
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID` IN (11314, 11315);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19, 20) AND `SourceEntry` IN (11316, 11319);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 11316, 0, 0, 8, 0, 11314, 0, 0, 0, 0, 0, "", "Quest 'Spawn of the Twisted Glade' requires quest 'The Fallen Sisters' rewarded"),
(19, 0, 11316, 0, 0, 8, 0, 11315, 0, 0, 0, 0, 0, "", "Quest 'Spawn of the Twisted Glade' requires quest 'Wild Vines' rewarded"),
(19, 0, 11319, 0, 0, 8, 0, 11314, 0, 0, 0, 0, 0, "", "Quest 'Seeds of the Blacksouled Keepers' requires quest 'The Fallen Sisters' rewarded"),
(19, 0, 11319, 0, 0, 8, 0, 11315, 0, 0, 0, 0, 0, "", "Quest 'Seeds of the Blacksouled Keepers' requires quest 'Wild Vines' rewarded"),

(20, 0, 11316, 0, 0, 8, 0, 11314, 0, 0, 0, 0, 0, "", "Quest mark for 'Spawn of the Twisted Glade' requires quest 'The Fallen Sisters' rewarded"),
(20, 0, 11316, 0, 0, 8, 0, 11315, 0, 0, 0, 0, 0, "", "Quest mark for 'Spawn of the Twisted Glade' requires quest 'Wild Vines' rewarded"),
(20, 0, 11319, 0, 0, 8, 0, 11314, 0, 0, 0, 0, 0, "", "Quest mark for 'Seeds of the Blacksouled Keepers' requires quest 'The Fallen Sisters' rewarded"),
(20, 0, 11319, 0, 0, 8, 0, 11315, 0, 0, 0, 0, 0, "", "Quest mark for 'Seeds of the Blacksouled Keepers' requires quest 'Wild Vines' rewarded");
