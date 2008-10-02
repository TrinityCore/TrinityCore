ALTER TABLE `item_template` 
  ADD COLUMN `spellppmRate_1` float NOT NULL default '0' AFTER `spellcharges_1`,
  ADD COLUMN `spellppmRate_2` float NOT NULL default '0' AFTER `spellcharges_2`,
  ADD COLUMN `spellppmRate_3` float NOT NULL default '0' AFTER `spellcharges_3`,
  ADD COLUMN `spellppmRate_4` float NOT NULL default '0' AFTER `spellcharges_4`,
  ADD COLUMN `spellppmRate_5` float NOT NULL default '0' AFTER `spellcharges_5`;
