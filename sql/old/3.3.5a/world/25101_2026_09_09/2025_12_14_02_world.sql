-- Fix the prerequisite quest for "Sleeping Giants"
UPDATE `quest_template_addon` SET `PrevQuestID`=11231 WHERE `ID`=11432;
