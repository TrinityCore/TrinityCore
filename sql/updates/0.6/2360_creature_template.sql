ALTER TABLE `creature_template` 
  ADD COLUMN `MovementType` int(11) unsigned NOT NULL default '0' AFTER `MoveName`;

UPDATE `creature_template`
  SET `MovementType` = '1' WHERE `MoveName` = 'Random';
UPDATE `creature_template`
  SET `MovementType` = '2' WHERE `MoveName` = 'Waypoint';

ALTER TABLE `creature_template` 
  DROP `MoveName`;

ALTER TABLE `creature` 
  ADD COLUMN `MovementType` int(11) unsigned NOT NULL default '0' AFTER `faction`;

UPDATE `creature`, `creature_template`
  SET `creature`.`MovementType` = `creature_template`.`MovementType` WHERE `creature`.`id` = `creature_template`.`entry`;
