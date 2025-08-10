-- Fel Moss Corruption and Demonic Thieves ExclusiveGroup
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-28714 WHERE `ID` IN (28714,28715);
-- Demonic Thieves
UPDATE `quest_template_addon` SET `PrevQuestID`=28713 WHERE `ID`=28715;
UPDATE `quest_template_addon` SET `NextQuestID`=28723 WHERE `ID`=28715;
-- A Favor for Melithar
UPDATE `quest_template_addon` SET `PrevQuestID`=28714 WHERE `ID`=28734;
UPDATE `quest_template_addon` SET `NextQuestID`=0 WHERE `ID`=28734;
UPDATE `quest_template_addon` SET `BreadcrumbForQuestId`=28715 WHERE `ID`=28734;
