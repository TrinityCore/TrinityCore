-- Fix prerequisite for quest "Rot Hide Ichor"
UPDATE `quest_template_addon` SET `PrevQuestID`=439 WHERE `ID`=443;
