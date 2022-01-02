--
UPDATE `quest_template_addon` SET `PrevQuestID`=0, `ExclusiveGroup`=0 WHERE `ID` IN (9927, 9928, 9931, 9932);
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=9934;
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID` IN (10107, 10108);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (9927, 9928, 9931, 9932, 9933, 9934);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 9927, 0, 0, 8, 0, 10107, 0, 0, 0, 0, 0, "", "Quest Ruthless Cunning requires quest Diplomatic Measures (Horde) rewarded OR"),
(19, 0, 9927, 0, 1, 8, 0, 10108, 0, 0, 0, 0, 0, "", "Quest Ruthless Cunning requires quest Diplomatic Measures (Alliance) rewarded"),
(19, 0, 9928, 0, 0, 8, 0, 10107, 0, 0, 0, 0, 0, "", "Quest Armaments for Deception requires quest Diplomatic Measures (Horde) rewarded OR"),
(19, 0, 9928, 0, 1, 8, 0, 10108, 0, 0, 0, 0, 0, "", "Quest Armaments for Deception requires quest Diplomatic Measures (Alliance) rewarded"),
(19, 0, 9931, 0, 0, 8, 0, 9927, 0, 0, 0, 0, 0, "", "Quest Returning the Favor requires quest Ruthless Cunning rewarded AND"),
(19, 0, 9931, 0, 0, 8, 0, 9928, 0, 0, 0, 0, 0, "", "Quest Returning the Favor requires quest Armaments for Deception rewarded"),
(19, 0, 9932, 0, 0, 8, 0, 9927, 0, 0, 0, 0, 0, "", "Quest Body of Evidence requires quest Ruthless Cunning rewarded AND"),
(19, 0, 9932, 0, 0, 8, 0, 9928, 0, 0, 0, 0, 0, "", "Quest Body of Evidence requires quest Armaments for Deception rewarded"),
(19, 0, 9933, 0, 0, 8, 0, 9931, 0, 0, 0, 0, 0, "", "Quest Message to Telaar requires quest Returning the Favor rewarded AND"),
(19, 0, 9933, 0, 0, 8, 0, 9932, 0, 0, 0, 0, 0, "", "Quest Message to Telaar requires quest Body of Evidence rewarded"),
(19, 0, 9934, 0, 0, 8, 0, 9931, 0, 0, 0, 0, 0, "", "Quest Message to Garadar requires quest Returning the Favor rewarded AND"),
(19, 0, 9934, 0, 0, 8, 0, 9932, 0, 0, 0, 0, 0, "", "Quest Message to Garadar requires quest Body of Evidence rewarded");
