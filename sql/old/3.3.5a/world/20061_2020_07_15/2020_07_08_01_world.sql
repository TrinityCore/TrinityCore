--
ALTER TABLE `spell_scripts` ADD COLUMN `Comment` varchar(255) NOT NULL DEFAULT '';
ALTER TABLE `event_scripts` ADD COLUMN `Comment` varchar(255) NOT NULL DEFAULT '';
ALTER TABLE `waypoint_scripts` ADD COLUMN `Comment` varchar(255) NOT NULL DEFAULT '';
