ALTER TABLE `characters_npcbot` MODIFY COLUMN `roles` int(10) unsigned NOT NULL COMMENT 'bitmask: tank(1),dps(2),heal(4),ranged(8)';
