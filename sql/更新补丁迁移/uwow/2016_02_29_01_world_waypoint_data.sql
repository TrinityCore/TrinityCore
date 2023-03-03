ALTER TABLE waypoint_data ADD COLUMN `speed` float(0) unsigned NOT NULL DEFAULT '0' AFTER `move_flag`;

update waypoint_data set speed = 30 where id in (6099900,6099901,6099902,6099903);