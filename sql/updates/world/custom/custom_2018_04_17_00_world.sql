UPDATE `quest_template` SET `RewardCurrencyId1`= 395 WHERE `ID`= 30111;
UPDATE `lfg_dungeon_rewards` SET `firstQuestId`= 30110, `otherQuestId`= 30111 WHERE `dungeonId` IN (416, 417);
UPDATE `quest_template` SET `Flags`= 32768 WHERE `ID`= 30110;
