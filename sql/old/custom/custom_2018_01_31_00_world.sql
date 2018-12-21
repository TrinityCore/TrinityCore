DELETE FROM `lfg_dungeon_template` WHERE `dungeonId`= 262;
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `requiredItemLevel`) VALUES
(262, 180);

UPDATE `quest_template` SET `RewardCurrencyCount1`= 2300 WHERE `ID` IN (24788, 24789);
