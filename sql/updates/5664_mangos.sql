ALTER TABLE npc_vendor
    ADD ExtendedCost mediumint(8) unsigned NOT NULL default '0';
UPDATE npc_vendor,item_template SET npc_vendor.ExtendedCost = item_template.ExtendedCost WHERE npc_vendor.item = item_template.entry;
ALTER TABLE item_template
    DROP ExtendedCost,
    DROP CondExtendedCost;