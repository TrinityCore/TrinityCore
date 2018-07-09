UPDATE `gameobject_template_addon` SET `flags`=0 WHERE `entry` IN (210005, 210015, 210016, 210017, 210018, 210019, 210020);

DELETE FROM `gameobject_loot_template` WHERE Entry = 210005;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(210005, 77278, 0, 100, 0, 1, 0, 1, 1, ''),
(210005, 77279, 0, 100, 0, 1, 0, 1, 1, '');

UPDATE `creature_template` SET `unit_flags` = 33280 WHERE entry IN (65471, 65470);

UPDATE `creature_template` SET `flags_extra` = 128 WHERE (entry = 41200);
UPDATE `creature_template` SET `faction` = 7 WHERE entry IN (65468, 55019);
