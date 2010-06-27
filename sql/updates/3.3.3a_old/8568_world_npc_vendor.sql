ALTER TABLE npc_vendor CHANGE COLUMN `ExtendedCost` `ExtendedCost` mediumint(8) NOT NULL default '0' COMMENT 'negative if cost must exclude normal money cost';
