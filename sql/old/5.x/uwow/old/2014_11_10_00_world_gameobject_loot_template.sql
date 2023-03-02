update gameobject_template set data1 = 220832 where entry = 220832;
update gameobject_template set data1 = 220902 where entry = 220902;

delete from gameobject_loot_template where entry = 220832;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`, `shared`) VALUES 
(220832, -777, 0, 1, 1, 1, 50, 0),
(220832, -738, 0, 1, 1, 1, 20, 0),
(220832, 104038, 50, 1, 0, 1, 1, 0);