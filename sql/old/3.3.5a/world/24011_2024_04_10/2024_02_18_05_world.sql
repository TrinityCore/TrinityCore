-- Fix credit cmangos
UPDATE `quest_template_addon` SET `ExclusiveGroup`=0, `NextQuestId`=0 WHERE `ID`=12008;
