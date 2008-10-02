ALTER TABLE creature_loot_template ADD COLUMN quest_freeforall int(1) unsigned NOT NULL default '1' AFTER `maxcount`;
ALTER TABLE gameobject_loot_template ADD COLUMN quest_freeforall int(1) unsigned NOT NULL default '1' AFTER `maxcount`;
ALTER TABLE fishing_loot_template ADD COLUMN quest_freeforall int(1) unsigned NOT NULL default '1' AFTER `maxcount`;
ALTER TABLE item_loot_template ADD COLUMN quest_freeforall int(1) unsigned NOT NULL default '1' AFTER `maxcount`;
ALTER TABLE pickpocketing_loot_template ADD COLUMN quest_freeforall int(1) unsigned NOT NULL default '1' AFTER `maxcount`;
ALTER TABLE skinning_loot_template ADD COLUMN quest_freeforall int(1) unsigned NOT NULL default '1' AFTER `maxcount`;