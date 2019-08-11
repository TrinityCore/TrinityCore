UPDATE `quest_poi` SET `ObjectiveIndex`= 1 WHERE `id`= 1 AND `ObjectiveIndex`= 0 AND `QuestID` IN (SELECT `ID` FROM `quest_template` WHERE `RequiredNpcOrGo2` != 0);
UPDATE `quest_poi` SET `ObjectiveIndex`= 2 WHERE `id`= 2 AND `ObjectiveIndex`= 0 AND `QuestID` IN (SELECT `ID` FROM `quest_template` WHERE `RequiredNpcOrGo3` != 0);
UPDATE `quest_poi` SET `ObjectiveIndex`= 3 WHERE `id`= 3 AND `ObjectiveIndex`= 0 AND `QuestID` IN (SELECT `ID` FROM `quest_template` WHERE `RequiredNpcOrGo4` != 0);
