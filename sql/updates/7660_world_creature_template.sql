ALTER TABLE creature_template ADD COLUMN speed_run float NOT NULL default '1.14286' COMMENT 'Result of 8.0/7.0, most common value' AFTER speed;
UPDATE creature_template SET speed=1 WHERE speed IS NULL;
ALTER TABLE creature_template CHANGE COLUMN speed speed_walk FLOAT NOT NULL DEFAULT '1' COMMENT 'Result of 2.5/2.5, most common value';
