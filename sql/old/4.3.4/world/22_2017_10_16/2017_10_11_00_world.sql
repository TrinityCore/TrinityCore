DELETE FROM `quest_template` WHERE `Id` IN (30110, 30111);
INSERT INTO `quest_template` (`Id`,`QuestType`,`QuestLevel`,`MinLevel`, `RewardMoney`, `RewardBonusMoney`, `Flags`, `LogTitle`, `RewardCurrencyId1`, `RewardCurrencyCount1`) VALUES 
(30110, 2, 85, 85, 376000, 832800, 128, 'Raid Finder (1st)', 396, 250),
(30111, 2, 85, 85, 376000, 832800, 128, 'Raid Finder (Nth)', 395, 250);

DELETE FROM `quest_template_addon` WHERE `Id` IN (30110, 30111);
INSERT INTO `quest_template_addon` (`Id`, `SpecialFlags`) VALUES
(30110, 8),
(30111, 8);

DELETE FROM `lfg_dungeon_rewards` WHERE `dungeonId` IN (300, 301, 434, 416, 417);
INSERT INTO `lfg_dungeon_rewards` (`dungeonId`, `maxLevel`, `firstQuestId`, `otherQuestId`) VALUES
(300, 85, 28907, 28908), -- Random Cataclysm Normal
(301, 85, 28905, 28906), -- Random Cataclysm Heroic
(434, 85, 29185, 29183), -- Random Cataclysm Hour of Twilight
(416, 85, 30110, 30111), -- Siege of the Wyrmrest Temple
(417, 85, 30110, 30111); -- Fall of Deathwing

DELETE FROM `lfg_dungeon_template` WHERE `dungeonId` IN (285, 286, 287, 288, 301, 319, 320, 321, 322, 323, 324, 325, 326, 327, 334, 340, 434, 435, 437, 439, 302, 303, 304, 305, 307, 311, 312, 300, 416, 417);
INSERT INTO `lfg_dungeon_template` (`dungeonId`, `requiredItemLevel`, `name`) VALUES
(285,329,'The Headless Horseman'),
(286,329,'Frostlord Ahune'),
(287,329,'Coren Direbrew'),
(288,329,'The Crown Chemical Co.'),
(301,329,'Heroic Random (Cataclysm)'),
(319,329,'The Vortex Pinnacle Heroic'),
(320,329,'The Stonecore Heroic'),
(321,329,'Halls of Origination'),
(322,329,'Grim Batol Heroic'),
(323,329,'Blackrock Caverns Heroic'),
(324,329,'Throne of the Tides Heroic'),
(325,329,'The Lost City of the Tol\'Vir Heroic'),
(326,329,'Deadmines Heroic'),
(327,329,'Shadowfang Keep Heroic'),
(334,346,'Zul\'Gurub Heroic'),
(340,346,'Zul\'Aman Heroic'),
(434,353,'Heroic Random (Hour of Twlight)'),
(435,353,'End Time Heroic'),
(437,353,'Well of Eternity'),
(439,353,'Hour of Twilight'),
(302,226,'Throne of the Tides Normal'),
(303,226,'Blackrock Caverns Normal'),
(304,305,'Grim Batol Normal'),
(305,305,'Halls of Origination Normal'),
(307,272,'The Stonecore Normal'),
(311,272,'TheVortex Pinnacle Normal'),
(312,305,'The Lost City of the Tol\'Vir Normal'),
(300,226,'Random Dungeon - Cataclysm'),
(416,372,'Siege of the Wyrmrest Temple'),
(417,372,'Fall of Deathwing');

UPDATE `quest_template` SET `RewardCurrencyCount1`= 150, `RewardCurrencyId1`= 396 WHERE `id` IN (28905, 29185);
UPDATE `quest_template` SET `RewardCurrencyCount1`= 150, `RewardCurrencyId1`= 395 WHERE `id` IN (28906, 29183, 28907, 28908);
