ALTER TABLE `creature_loot_template`
  CHANGE `chance`      `ChanceOrRef` float NOT NULL default '100',
  CHANGE `questchance` `QuestChanceOrGroup` tinyint(3) NOT NULL default '0';

ALTER TABLE `fishing_loot_template`
  CHANGE `chance`      `ChanceOrRef` float NOT NULL default '100',
  CHANGE `questchance` `QuestChanceOrGroup` tinyint(3) NOT NULL default '0';

ALTER TABLE `gameobject_loot_template`
  CHANGE `chance`      `ChanceOrRef` float NOT NULL default '100',
  CHANGE `questchance` `QuestChanceOrGroup` tinyint(3) NOT NULL default '0';

ALTER TABLE `item_loot_template`
  CHANGE `chance`      `ChanceOrRef` float NOT NULL default '100',
  CHANGE `questchance` `QuestChanceOrGroup` tinyint(3) NOT NULL default '0';

ALTER TABLE `pickpocketing_loot_template`
  CHANGE `chance`      `ChanceOrRef` float NOT NULL default '100',
  CHANGE `questchance` `QuestChanceOrGroup` tinyint(3) NOT NULL default '0';

ALTER TABLE `skinning_loot_template`
  CHANGE `chance`      `ChanceOrRef` float NOT NULL default '100',
  CHANGE `questchance` `QuestChanceOrGroup` tinyint(3) NOT NULL default '0';

UPDATE `skinning_loot_template`,`skinning_loot_template_alternative` 
  SET `QuestChanceOrGroup` = '-1',`ChanceOrRef` = '80'
  WHERE `skinning_loot_template`.`item` = `skinning_loot_template_alternative`.`item`;

INSERT INTO `skinning_loot_template` 
  SELECT `skinning_loot_template`.`entry`, `skinning_loot_template_alternative`.`item2`, '20', '-1', `skinning_loot_template`.`maxcount`, '1'
  FROM `skinning_loot_template`,`skinning_loot_template_alternative` 
  WHERE `skinning_loot_template`.`item` = `skinning_loot_template_alternative`.`item`;

DROP TABLE `skinning_loot_template_alternative`;
