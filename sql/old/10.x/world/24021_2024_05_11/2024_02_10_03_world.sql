-- Delete Empty Rows
DELETE FROM `quest_template_addon` WHERE `ID` IN (8325,9704);
-- Unnecessary SpecialFlags
UPDATE `quest_template_addon` SET `SpecialFlags`=0 WHERE `ID` IN (8326,8327,8334,8335,8347,8350);
-- Unfortunate Measures
UPDATE `quest_template_addon` SET `PrevQuestID`=8325 WHERE `ID`=8326;
