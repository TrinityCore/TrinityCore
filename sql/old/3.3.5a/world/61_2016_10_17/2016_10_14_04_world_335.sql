--
-- True Believers and Still Believing
DELETE FROM `mail_loot_template` WHERE `Item`=20469;
INSERT INTO `mail_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(93, 20469, 0, 100, 0, 1, 0, 1, 1, ""),
(94, 20469, 0, 100, 0, 1, 0, 1, 1, "");

-- A Terrible Purpose.
UPDATE `quest_template_addon` SET `RewardMailTemplateId`=110, `RewardMailDelay`=7200 WHERE `Id`=8287;

DELETE FROM `mail_loot_template` WHERE `Entry`=110;
INSERT INTO `mail_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(110, 20645, 0, 100, 0, 1, 0, 1, 1, "");

-- Wrath of Neptulon
UPDATE `quest_template_addon` SET `RewardMailTemplateId`=123, `RewardMailDelay`=86400 WHERE `Id`=8729;

-- A Letter for Home (Alliance and Horde)
UPDATE `quest_template_addon` SET `RewardMailTemplateId`=193, `RewardMailDelay`=86400 WHERE `Id`=12067;
UPDATE `quest_template_addon` SET `RewardMailTemplateId`=194, `RewardMailDelay`=86400 WHERE `Id`=12085;

-- Tactical Clemency
UPDATE `quest_template_addon` SET `RewardMailTemplateId`=234 WHERE `Id`=12422;

-- Abandoned Mail
UPDATE `quest_template_addon` SET `RewardMailTemplateId`=236 WHERE `Id`=12711;

DELETE FROM `mail_loot_template` WHERE `Entry`=236;
INSERT INTO `mail_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(236, 39317, 0, 100, 0, 1, 0, 1, 1, "");

-- Hammershout the Elder
UPDATE `quest_template_addon` SET `RewardMailTemplateId`=92 WHERE `Id`=8646;

-- Various Lunar Festival quests
DELETE FROM `quest_template_addon` WHERE `Id` IN (13067, 13066, 13065, 13033, 13032, 13031, 13030, 13029, 13028, 13027, 13026, 13025, 13024, 13023, 13022, 13021, 13020, 13019, 13018, 13017, 13016, 13015, 13014, 13013, 13012);
INSERT INTO `quest_template_addon` (`Id`, `RewardMailTemplateId`, `RewardMailDelay`) VALUES
(13012, 237, 21600),
(13013, 238, 21600),
(13014, 239, 21600),
(13015, 240, 21600),
(13016, 241, 21600),
(13017, 242, 21600),
(13018, 243, 21600),
(13019, 244, 21600),
(13020, 245, 21600),
(13021, 246, 21600),
(13022, 247, 21600),
(13023, 248, 21600),
(13024, 249, 21600),
(13025, 250, 21600),
(13026, 251, 21600),
(13027, 252, 21600),
(13028, 253, 21600),
(13029, 254, 21600),
(13030, 255, 21600),
(13031, 256, 21600),
(13032, 257, 21600),
(13033, 258, 21600),
(13065, 259, 21600),
(13066, 260, 21600),
(13067, 261, 21600);

DELETE FROM `mail_loot_template` WHERE `Entry` BETWEEN 237 AND 261;
INSERT INTO `mail_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(237, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(238, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(239, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(240, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(241, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(242, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(243, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(244, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(245, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(246, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(247, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(248, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(249, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(250, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(251, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(252, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(253, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(254, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(255, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(256, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(257, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(258, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(259, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(260, 21746, 0, 100, 0, 1, 0, 1, 1, ""),
(261, 21746, 0, 100, 0, 1, 0, 1, 1, "");
