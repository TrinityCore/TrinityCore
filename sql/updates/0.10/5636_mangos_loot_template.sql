ALTER TABLE `creature_loot_template` 
  ADD `ChanceOrQuestChance` FLOAT NOT NULL default '100' AFTER `ChanceOrRef`,
  ADD `group` tinyint unsigned NOT NULL default '0' AFTER `QuestChanceOrGroup`,
  ADD `mincountOrRef` mediumint NOT NULL default '1' AFTER `mincount`;

UPDATE `creature_loot_template` SET 
  `ChanceOrQuestChance` = if(`QuestChanceOrGroup` > 0, -`QuestChanceOrGroup`, if(`ChanceOrRef` < 0, 100, `ChanceOrRef`)),
  `group` = if(`QuestChanceOrGroup` > 0, 0, -`QuestChanceOrGroup`), 
  `mincountOrRef` = if(`ChanceOrRef` < 0, `ChanceOrRef`, `mincount`), 
  `maxcount` = if(`ChanceOrRef` < 0, 1, `maxcount`);

ALTER TABLE `creature_loot_template` 
  DROP `ChanceOrRef`, 
  DROP `QuestChanceOrGroup`, 
  DROP `mincount`;


ALTER TABLE `disenchant_loot_template` 
  ADD `ChanceOrQuestChance` FLOAT NOT NULL default '100' AFTER `ChanceOrRef`,
  ADD `group` tinyint unsigned NOT NULL default '0' AFTER `QuestChanceOrGroup`,
  ADD `mincountOrRef` mediumint NOT NULL default '1' AFTER `mincount`;

UPDATE `disenchant_loot_template` SET 
  `ChanceOrQuestChance` = if(`QuestChanceOrGroup` > 0, -`QuestChanceOrGroup`, if(`ChanceOrRef` < 0, 100, `ChanceOrRef`)),
  `group` = if(`QuestChanceOrGroup` > 0, 0, -`QuestChanceOrGroup`), 
  `mincountOrRef` = if(`ChanceOrRef` < 0, `ChanceOrRef`, `mincount`), 
  `maxcount` = if(`ChanceOrRef` < 0, 1, `maxcount`);

ALTER TABLE `disenchant_loot_template` 
  DROP `ChanceOrRef`, 
  DROP `QuestChanceOrGroup`, 
  DROP `mincount`;


ALTER TABLE `fishing_loot_template`
  ADD `ChanceOrQuestChance` FLOAT NOT NULL default '100' AFTER `ChanceOrRef`,
  ADD `group` tinyint unsigned NOT NULL default '0' AFTER `QuestChanceOrGroup`,
  ADD `mincountOrRef` mediumint NOT NULL default '1' AFTER `mincount`;

UPDATE `fishing_loot_template` SET 
  `ChanceOrQuestChance` = if(`QuestChanceOrGroup` > 0, -`QuestChanceOrGroup`, if(`ChanceOrRef` < 0, 100, `ChanceOrRef`)),
  `group` = if(`QuestChanceOrGroup` > 0, 0, -`QuestChanceOrGroup`), 
  `mincountOrRef` = if(`ChanceOrRef` < 0, `ChanceOrRef`, `mincount`), 
  `maxcount` = if(`ChanceOrRef` < 0, 1, `maxcount`);

ALTER TABLE `fishing_loot_template`
  DROP `ChanceOrRef`, 
  DROP `QuestChanceOrGroup`, 
  DROP `mincount`;


ALTER TABLE `gameobject_loot_template`
  ADD `ChanceOrQuestChance` FLOAT NOT NULL default '100' AFTER `ChanceOrRef`,
  ADD `group` tinyint unsigned NOT NULL default '0' AFTER `QuestChanceOrGroup`,
  ADD `mincountOrRef` mediumint NOT NULL default '1' AFTER `mincount`;

UPDATE `gameobject_loot_template` SET 
  `ChanceOrQuestChance` = if(`QuestChanceOrGroup` > 0, -`QuestChanceOrGroup`, if(`ChanceOrRef` < 0, 100, `ChanceOrRef`)),
  `group` = if(`QuestChanceOrGroup` > 0, 0, -`QuestChanceOrGroup`), 
  `mincountOrRef` = if(`ChanceOrRef` < 0, `ChanceOrRef`, `mincount`), 
  `maxcount` = if(`ChanceOrRef` < 0, 1, `maxcount`);

ALTER TABLE `gameobject_loot_template`
  DROP `ChanceOrRef`, 
  DROP `QuestChanceOrGroup`, 
  DROP `mincount`;


ALTER TABLE `item_loot_template`
  ADD `ChanceOrQuestChance` FLOAT NOT NULL default '100' AFTER `ChanceOrRef`,
  ADD `group` tinyint unsigned NOT NULL default '0' AFTER `QuestChanceOrGroup`,
  ADD `mincountOrRef` mediumint NOT NULL default '1' AFTER `mincount`;

UPDATE `item_loot_template` SET 
  `ChanceOrQuestChance` = if(`QuestChanceOrGroup` > 0, -`QuestChanceOrGroup`, if(`ChanceOrRef` < 0, 100, `ChanceOrRef`)),
  `group` = if(`QuestChanceOrGroup` > 0, 0, -`QuestChanceOrGroup`), 
  `mincountOrRef` = if(`ChanceOrRef` < 0, `ChanceOrRef`, `mincount`), 
  `maxcount` = if(`ChanceOrRef` < 0, 1, `maxcount`);

ALTER TABLE `item_loot_template`
  DROP `ChanceOrRef`, 
  DROP `QuestChanceOrGroup`, 
  DROP `mincount`;


ALTER TABLE `pickpocketing_loot_template`
  ADD `ChanceOrQuestChance` FLOAT NOT NULL default '100' AFTER `ChanceOrRef`,
  ADD `group` tinyint unsigned NOT NULL default '0' AFTER `QuestChanceOrGroup`,
  ADD `mincountOrRef` mediumint NOT NULL default '1' AFTER `mincount`;

UPDATE `pickpocketing_loot_template` SET 
  `ChanceOrQuestChance` = if(`QuestChanceOrGroup` > 0, -`QuestChanceOrGroup`, if(`ChanceOrRef` < 0, 100, `ChanceOrRef`)),
  `group` = if(`QuestChanceOrGroup` > 0, 0, -`QuestChanceOrGroup`), 
  `mincountOrRef` = if(`ChanceOrRef` < 0, `ChanceOrRef`, `mincount`), 
  `maxcount` = if(`ChanceOrRef` < 0, 1, `maxcount`);

ALTER TABLE `pickpocketing_loot_template` 
  DROP `ChanceOrRef`, 
  DROP `QuestChanceOrGroup`, 
  DROP `mincount`;


ALTER TABLE `prospecting_loot_template`
  ADD `ChanceOrQuestChance` FLOAT NOT NULL default '100' AFTER `ChanceOrRef`,
  ADD `group` tinyint unsigned NOT NULL default '0' AFTER `QuestChanceOrGroup`,
  ADD `mincountOrRef` mediumint NOT NULL default '1' AFTER `mincount`;

UPDATE `prospecting_loot_template`SET 
  `ChanceOrQuestChance` = if(`QuestChanceOrGroup` > 0, -`QuestChanceOrGroup`, if(`ChanceOrRef` < 0, 100, `ChanceOrRef`)),
  `group` = if(`QuestChanceOrGroup` > 0, 0, -`QuestChanceOrGroup`), 
  `mincountOrRef` = if(`ChanceOrRef` < 0, `ChanceOrRef`, `mincount`), 
  `maxcount` = if(`ChanceOrRef` < 0, 1, `maxcount`);

ALTER TABLE `prospecting_loot_template`
  DROP `ChanceOrRef`, 
  DROP `QuestChanceOrGroup`, 
  DROP `mincount`;


ALTER TABLE `skinning_loot_template` 
  ADD `ChanceOrQuestChance` FLOAT NOT NULL default '100' AFTER `ChanceOrRef`,
  ADD `group` tinyint unsigned NOT NULL default '0' AFTER `QuestChanceOrGroup`,
  ADD `mincountOrRef` mediumint NOT NULL default '1' AFTER `mincount`;

UPDATE `skinning_loot_template`  SET 
  `ChanceOrQuestChance` = if(`QuestChanceOrGroup` > 0, -`QuestChanceOrGroup`, if(`ChanceOrRef` < 0, 100, `ChanceOrRef`)),
  `group` = if(`QuestChanceOrGroup` > 0, 0, -`QuestChanceOrGroup`), 
  `mincountOrRef` = if(`ChanceOrRef` < 0, `ChanceOrRef`, `mincount`), 
  `maxcount` = if(`ChanceOrRef` < 0, 1, `maxcount`);

ALTER TABLE `skinning_loot_template` 
  DROP `ChanceOrRef`, 
  DROP `QuestChanceOrGroup`, 
  DROP `mincount`;
