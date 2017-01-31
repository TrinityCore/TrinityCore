-- Grark Lorkrub should be available only when Kill On Sight: High Ranking Dark Iron Officials is complete
UPDATE `quest_template` SET `NextQuestId`=4122 WHERE `Id`=4082;
UPDATE `quest_template` SET `PrevQuestId`=4082 WHERE `Id`=4122;
