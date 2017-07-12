--
DELETE FROM `creature_loot_template` WHERE `item`= 58891 AND `entry`= 442;
DELETE FROM `creature_loot_template` WHERE `item`= 58892 AND `entry`= 428;
DELETE FROM `creature_loot_template` WHERE `item`= 58893 AND `entry`= 547;
INSERT INTO `creature_loot_template` (`entry`,`item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(442, 58891, 0, 72, 1, 1, 0, 1, 1, NULL), -- Tarantula Eyes (58891) / Tarantula (442)
(428, 58892, 0, 85, 1, 1, 0, 1, 1, NULL), -- Condor Giblets (58892) / Dire Condor (428)
(547, 58893, 0, 51, 1, 1, 0, 1, 1, NULL); -- Goretusk Kidney (58893) / Great Goretusk (547)
--
