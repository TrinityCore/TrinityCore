--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (13418, 13419, 13386, 13258);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 13418, 0, 0, 25, 0, 54197, 0, 0, 0, 0, 0, "", "Quest 'Preparations for War (A)' requires spell 'Cold Weather Flying'"),
(19, 0, 13419, 0, 0, 25, 0, 54197, 0, 0, 0, 0, 0, "", "Quest 'Preparations for War (H)' requires spell 'Cold Weather Flying'"),
(19, 0, 13386, 0, 0,  8, 0, 13225, 0, 0, 0, 0, 0, "", "Quest 'Exploiting an Opening' requires quest 'The Skybreaker' to be rewarded AND"),
(19, 0, 13386, 0, 0,  8, 0, 12898, 0, 0, 0, 0, 0, "", "Quest 'Exploiting an Opening' requires quest 'The Shadow Vault (A)' to be rewarded"),
(19, 0, 13258, 0, 0,  8, 0, 13224, 0, 0, 0, 0, 0, "", "Quest 'Opportunity' requires quest 'Ogrim's Hammer' to be rewarded AND"),
(19, 0, 13258, 0, 0,  8, 0, 12899, 0, 0, 0, 0, 0, "", "Quest 'Opportunity' requires quest 'The Shadow Vault (H)' to be rewarded");

UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=13386;
DELETE FROM `quest_template_addon` WHERE `ID` IN (13278, 13404, 13382);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`) VALUES
(13278, 13277), -- Coprous the Defiled requires Against the Giants
(13404, 13380), -- Static Shock Troops: the Bombardment requires Leading the Charge
(13382, 13380); -- Putting the Hertz: The Valley of Lost Hope requires Leading the Charge

DELETE FROM `quest_template_addon` WHERE `ID` IN (13224, 13225);
INSERT INTO `quest_template_addon` (`ID`, `NextQuestID`, `ExclusiveGroup`) VALUES
(13224, 13308, 13224), -- Mind Tricks requires Ogrim's Hammer OR
(13225, 13308, 13224); -- Mind Tricks requires The Skybreaker

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=13381;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `comment`) VALUES
(1, 13381, 0, "Quest 'Watts My Target' is deprecated");
