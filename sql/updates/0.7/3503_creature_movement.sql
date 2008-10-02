--
-- Enhancements to the waypoint system
--
-- Sorry for having forgotten to add this to the svn.
ALTER TABLE `creature_movement` ADD COLUMN `orientation` float default 0 AFTER `wpguid`;
ALTER TABLE `creature_movement` ADD COLUMN `model1` int (11) default 0 AFTER `orientation`;
ALTER TABLE `creature_movement` ADD COLUMN `model2` int (11) default 0 AFTER `model1`;
