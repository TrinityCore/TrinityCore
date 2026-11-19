-- Restore negative ExtendedCost, we now use FlagsExtra value instead
UPDATE `npc_vendor` SET `ExtendedCost`=-`ExtendedCost` WHERE `ExtendedCost`<0;

-- Set field type to unsigned
ALTER TABLE npc_vendor CHANGE COLUMN `ExtendedCost` `ExtendedCost` mediumint(8) UNSIGNED NOT NULL default '0' COMMENT '';
