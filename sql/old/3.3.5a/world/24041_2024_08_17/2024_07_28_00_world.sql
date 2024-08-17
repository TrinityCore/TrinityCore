-- Fix Mmm... Amberseeds! quest requirements
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID` IN (12222, 12223); 
