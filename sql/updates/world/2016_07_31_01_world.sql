-- Anraphet loot -- Normal/Heroic

UPDATE `creature_template` SET `lootid`= 39788 where `entry`= 39788;
UPDATE `creature_template` SET `lootid`= 48902 where `entry`= 48902;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (39788, 48902);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`,`Comment`) VALUES
(39788,1,39788,100,0,1,0,1,1,'Anraphet N - Reference Loot'),
(48902,1,48902,100,0,1,0,1,1,'Anraphet H - Reference Loot');

DELETE FROM `reference_loot_template` where `entry` IN (39788,48902);
INSERT INTO `reference_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(39788,57855,0,0,0,1,1,1,1),
(39788,57857,0,0,0,1,1,1,1),
(39788,57860,0,0,0,1,1,1,1),
(39788,57856,0,0,0,1,1,1,1),
(39788,57858,0,0,0,1,1,1,1),
(48902,57870,0,0,0,1,1,1,1),
(48902,57868,0,0,0,1,1,1,1),
(48902,57867,0,0,0,1,1,1,1),
(48902,57866,0,0,0,1,1,1,1),
(48902,57869,0,0,0,1,1,1,1);

-- Isiset loot -- Normal/Heroic 

UPDATE `creature_template` SET `lootid`= 39587 where `entry`= 39587;
UPDATE `creature_template` SET `lootid`= 48710 where `entry`= 48710;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (39587, 48710);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`,`Comment`) VALUES
(39587,1,39587,100,0,1,0,1,1,'Isiset N - Reference Loot'),
(48710,1,48710,100,0,1,0,1,1,'Isiset H - Reference Loot');

DELETE FROM `reference_loot_template` where `entry` IN (39587,48710);
INSERT INTO `reference_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(39587,55994,0,0,0,1,1,1,1),
(39587,55996,0,0,0,1,1,1,1),
(39587,55995,0,0,0,1,1,1,1),
(39587,55993,0,0,0,1,1,1,1),
(39587,55992,0,0,0,1,1,1,1),
(48710,56414,0,0,0,1,1,1,1),
(48710,56416,0,0,0,1,1,1,1),
(48710,56413,0,0,0,1,1,1,1),
(48710,56415,0,0,0,1,1,1,1),
(48710,56412,0,0,0,1,1,1,1);

-- Ammunae loot -- Normal/heroic

UPDATE `creature_template` SET `lootid`= 39731 where `entry`= 39731;
UPDATE `creature_template` SET `lootid`= 48715 where `entry`= 48715;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (39731, 48715);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`,`Comment`) VALUES
(39731,1,39731,100,0,1,0,1,1,'Ammunae N - Reference Loot'),
(48715,1,48715,100,0,1,0,1,1,'Ammunae H - Reference Loot');

DELETE FROM `reference_loot_template` where `entry` IN (39731,48715);
INSERT INTO `reference_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(39731,56000,0,0,0,1,1,1,1),
(39731,55997,0,0,0,1,1,1,1),
(39731,55998,0,0,0,1,1,1,1),
(39731,55999,0,0,0,1,1,1,1),
(39731,56001,0,0,0,1,1,1,1),
(48715,56418,0,0,0,1,1,1,1),
(48715,56419,0,0,0,1,1,1,1),
(48715,56417,0,0,0,1,1,1,1),
(48715,56421,0,0,0,1,1,1,1),
(48715,56420,0,0,0,1,1,1,1);

-- Setesh loot -- Normal/heroic

UPDATE `creature_template` SET `lootid`= 39732 where `entry`= 39732;
UPDATE `creature_template` SET `lootid`= 48776 where `entry`= 48776;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (39732, 48776);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`,`Comment`) VALUES
(39732,1,39732,100,0,1,0,1,1,'Setesh N - Reference Loot'),
(48776,1,48776,100,0,1,0,1,1,'Setesh H - Reference Loot');

DELETE FROM `reference_loot_template` where `entry` IN (39732,48776);
INSERT INTO `reference_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(39732,57861,0,0,0,1,1,1,1),
(39732,57862,0,0,0,1,1,1,1),
(39732,57863,0,0,0,1,1,1,1),
(39732,57864,0,0,0,1,1,1,1),
(39732,57865,0,0,0,1,1,1,1),
(48776,57872,0,0,0,1,1,1,1),
(48776,57875,0,0,0,1,1,1,1),
(48776,57871,0,0,0,1,1,1,1),
(48776,57873,0,0,0,1,1,1,1),
(48776,57874,0,0,0,1,1,1,1);

-- Rajh loot -- Normal/heroic

UPDATE `creature_template` SET `lootid`= 39378 where `entry`= 39378;
UPDATE `creature_template` SET `lootid`= 48815 where `entry`= 48815;

DELETE FROM `creature_loot_template` WHERE `Entry` IN (39378, 48815);
INSERT INTO `creature_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`,`Comment`) VALUES
(39378,1,39378,100,0,1,0,1,1,'Rajh N - Reference Loot'),
(48815,1,48815,100,0,1,0,1,1,'Rajh H - Reference Loot'),
(48815,52078,0,100,0,1,0,1,1,'Rajh H - Chaos Orb');

DELETE FROM `reference_loot_template` where `entry` IN (39378,48815);
INSERT INTO `reference_loot_template` (`entry`, `item`, `Reference`, `Chance`, `QuestRequired`, `Lootmode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(39378,56099,0,0,0,1,1,1,1),
(39378,56100,0,0,0,1,1,1,1),
(39378,56101,0,0,0,1,1,1,1),
(39378,56102,0,0,0,1,1,1,1),
(39378,56098,0,0,0,1,1,1,1),
(39378,56104,0,0,0,1,1,1,1),
(39378,56105,0,0,0,1,1,1,1),
(39378,56106,0,0,0,1,1,1,1),
(39378,56107,0,0,0,1,1,1,1),
(39378,56108,0,0,0,1,1,1,1),
(48815,56430,0,0,0,1,1,1,1),
(48815,56431,0,0,0,1,1,1,1),
(48815,56432,0,0,0,1,1,1,1),
(48815,56433,0,0,0,1,1,1,1),
(48815,56427,0,0,0,1,1,1,1),
(48815,56428,0,0,0,1,1,1,1),
(48815,56429,0,0,0,1,1,1,1),
(48815,56434,0,0,0,1,1,1,1),
(48815,56435,0,0,0,1,1,1,1),
(48815,56436,0,0,0,1,1,1,1);
