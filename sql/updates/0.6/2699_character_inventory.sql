UPDATE character_inventory SET bag = 0 WHERE bag = 255;
CREATE TABLE character_bags SELECT guid, slot, item FROM character_inventory LEFT JOIN item_template ON character_inventory.item_template = item_template.entry WHERE ContainerSlots > 0 AND bag = 0;
CREATE INDEX idx_gs ON character_bags (`guid`,`slot`);
ALTER TABLE character_inventory CHANGE COLUMN `bag` `bag` bigint(20) unsigned NOT NULL default '0';
UPDATE character_inventory As ci SET bag = (SELECT item FROM character_bags As cb WHERE ci.guid = cb.guid AND cb.slot = ci.bag LIMIT 1) WHERE bag != 0;
DROP TABLE character_bags;
ALTER TABLE character_inventory DROP PRIMARY KEY;
ALTER TABLE character_inventory ADD PRIMARY KEY (`item`);
CREATE INDEX idx_gb ON character_inventory (`guid`,`bag`);