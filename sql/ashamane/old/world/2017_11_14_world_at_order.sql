ALTER TABLE `areatrigger` CHANGE `map_id` `map_id` INT(11) UNSIGNED NOT NULL AFTER `id`; 
ALTER TABLE `areatrigger` CHANGE `spawn_mask` `spawn_mask` INT(11) UNSIGNED DEFAULT 1 NOT NULL AFTER `map_id`; 
