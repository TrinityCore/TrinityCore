--
UPDATE `quest_template_addon` SET `PrevQuestId`=0 WHERE `id`=9409;
UPDATE `quest_template_addon` SET `PrevQuestId`=9409 WHERE `id`=9371;
UPDATE `quest_template_addon` SET `ExclusiveGroup`=9280 WHERE `ID` IN (9280, 9369);
UPDATE `quest_template` SET `RewardNextQuest`=9409 WHERE `ID`=9280;
