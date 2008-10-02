/*delete redundant column from creature table*/
ALTER TABLE `creature` ADD COLUMN `spawntimesecs` int(11) unsigned NOT NULL default '120' AFTER `spawntimemin`;

UPDATE creature SET `spawntimesecs`= (spawntimemin + spawntimemax) /2;

ALTER TABLE creature DROP COLUMN spawntimemax;
ALTER TABLE creature DROP COLUMN spawntimemin;