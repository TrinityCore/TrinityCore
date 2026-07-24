-- These quests should not be available until "Timberling Seeds" is rewarded
UPDATE `quest_template_addon` SET `PrevQuestID`=918 WHERE `ID` IN (930,931);
