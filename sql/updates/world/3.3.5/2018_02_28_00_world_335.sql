-- Fix prerequisite for quests "Hallowed Scroll" & "Glyphic Scroll"
UPDATE `quest_template_addon` SET `PrevQuestID`=364 WHERE `ID` IN (3097,3098);
