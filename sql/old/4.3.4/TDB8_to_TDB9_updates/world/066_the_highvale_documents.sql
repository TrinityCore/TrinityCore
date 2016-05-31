--
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (34754,34755,34756);
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Chance`,`QuestRequired`) VALUES
(34754,61972,100,1),
(34755,61973,100,1),
(34756,61974,100,1);
