-- Broken Silithid Chitin can be only skinned
DELETE FROM `creature_loot_template` WHERE `Item` = 20499 AND `Reference` = 0;
UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` = 15286;

UPDATE `creature_template` SET `skinloot` = 60000 WHERE `entry` IN (11721,11722,11725,11726,11729,11731,11733,14475,15290,15319,15336);
UPDATE `creature_template` SET `skinloot` = 60001 WHERE `entry` IN (11698,11724,11727,11732,13136,13301,14474,15325,15327,15288);
UPDATE `creature_template` SET `skinloot` = 60002 WHERE `entry` IN (11723,11728,11734,11730,14473,15320,15323,15286);

-- This also fixes maxcount and adds missing items
DELETE FROM `skinning_loot_template` WHERE `Item` BETWEEN 20498 AND 20501 AND `Reference` = 0;
INSERT INTO `skinning_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(60000,20498,0,40,0,1,1,1,2,"Silithid Chitin"),
(60000,20499,0,60,0,1,1,1,2,"Broken Silithid Chitin"),
(60001,20498,0,30,0,1,1,1,2,"Silithid Chitin"),
(60001,20499,0,60,0,1,1,1,2,"Broken Silithid Chitin"),
(60001,20500,0,10,0,1,1,1,1,"Light Silithid Carapace"),
(60002,20498,0,30,0,1,1,1,2,"Silithid Chitin"),
(60002,20499,0,60,0,1,1,1,2,"Broken Silithid Chitin"),
(60002,20501,0,10,0,1,1,1,1,"Heavy Silithid Carapace");
