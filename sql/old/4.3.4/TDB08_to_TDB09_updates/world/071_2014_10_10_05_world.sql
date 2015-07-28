--
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (28677,28678);
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Chance`,`QuestRequired`) VALUES
(28677,49352,100,1),
(28678,49351,100,1);
