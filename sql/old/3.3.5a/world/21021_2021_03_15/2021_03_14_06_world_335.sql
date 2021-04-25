-- All with Turtle Scale
DELETE FROM `creature_loot_template` WHERE `Item` = 8167 AND `Reference` = 0; -- Only skinned

UPDATE `creature_template` SET `skinloot` = 60022 WHERE `entry` IN (2505,5431,6369,13599);
UPDATE `creature_template` SET `skinloot` = 60023 WHERE `entry` IN (4396,4397,4398,14223); -- 14223 may use unique, we'll never know
UPDATE `creature_template` SET `skinloot` = 60024 WHERE `entry` IN (4399,4400,14123);
UPDATE `creature_template` SET `skinloot` = 60025 WHERE `entry` IN (7977);
UPDATE `creature_template` SET `skinloot` = 60026 WHERE `entry` IN (6352,8213);
UPDATE `creature_template` SET `skinloot` = 60027 WHERE `entry` IN (13896);

DELETE FROM `skinning_loot_template` WHERE `Entry` IN (2505,4396,4397,4398,4399,4400,14123,5431,6369,7977,13599,6352,8213,13896);
DELETE FROM `skinning_loot_template` WHERE `Entry` BETWEEN 60022 AND 60027;
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60022,4304,0,77,0,1,1,1,1,"Thick Leather"),
(60022,8167,0,50,0,1,0,1,2,"Turtle Scale"),
(60022,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60022,8170,0,20,0,1,1,1,1,"Rugged Leather"),
(60023,4235,0,3,0,1,1,1,1,"Heavy Hide"),
(60023,4304,0,20,0,1,1,1,1,"Thick Leather"),
(60023,8167,0,25,0,1,0,1,1,"Turtle Scale"),
(60023,4234,0,77,0,1,1,1,1,"Heavy Leather"),
(60024,4234,0,43,0,1,1,1,1,"Heavy Leather"),
(60024,4235,0,3,0,1,1,1,1,"Heavy Hide"),
(60024,4304,0,50,0,1,1,1,1,"Thick Leather"),
(60024,8167,0,50,0,1,0,1,1,"Turtle Scale"),
(60024,8169,0,4,0,1,1,1,1,"Thick Hide"),
(60025,4304,0,75,0,1,1,1,2,"Thick Leather"),
(60025,8167,0,50,0,1,0,2,4,"Turtle Scale"),
(60025,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60025,8170,0,22,0,1,1,1,2,"Rugged Leather"),
(60026,4304,0,43,0,1,1,1,1,"Thick Leather"),
(60026,8167,0,50,0,1,0,1,3,"Turtle Scale"),
(60026,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60026,8170,0,50,0,1,1,1,1,"Rugged Leather"),
(60026,8171,0,4,0,1,1,1,1,"Rugged Hide"),
(60027,4304,0,43,0,1,1,1,2,"Thick Leather"),
(60027,8167,0,50,0,1,0,1,3,"Turtle Scale"),
(60027,8169,0,3,0,1,1,1,1,"Thick Hide"),
(60027,8170,0,50,0,1,1,1,2,"Rugged Leather"),
(60027,8171,0,4,0,1,1,1,1,"Rugged Hide");
