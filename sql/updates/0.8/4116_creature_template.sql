ALTER TABLE `creature_template`
ADD COLUMN `RacialLeader` tinyint(1) unsigned NOT NULL default '0' AFTER `InhabitType`; 
