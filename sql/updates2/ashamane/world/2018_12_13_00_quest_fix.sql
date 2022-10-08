-- Table `gameobject_template`
UPDATE `gameobject_template` SET `Data1` = 0 WHERE (entry = 276496);

DELETE FROM `gameobject_loot_template` WHERE `Entry` = '276496' AND `Item` = '152847'; 
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES('276496','152847','0','100','1','1','0','1','1',NULL);
