ALTER TABLE waypoint_data ADD COLUMN id_old int(10) unsigned NOT NULL default '0' COMMENT 'Creature GUID' AFTER wpguid;
UPDATE waypoint_data SET id_old=id;
UPDATE waypoint_data,creature_addon SET waypoint_data.id=creature_addon.guid*10 WHERE creature_addon.path_id > 0 AND creature_addon.path_id=waypoint_data.id_old;
UPDATE waypoint_data SET id = 1343801 WHERE id_old = 2084;
UPDATE waypoint_scripts SET datalong = 1343801 WHERE id = 515;
ALTER TABLE waypoint_data DROP COLUMN id_old;