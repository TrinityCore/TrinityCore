-- Quest "Runewarden Deryan" should not be available until "Defending Fairbreeze Village" is rewarded
UPDATE `quest_template_addon` SET `PrevQuestID`=9252 WHERE `ID`=9253;
