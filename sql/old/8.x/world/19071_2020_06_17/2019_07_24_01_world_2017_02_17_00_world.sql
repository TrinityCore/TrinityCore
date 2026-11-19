ALTER TABLE `smart_scripts` CHANGE `event_flags` `event_flags` smallint(5) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `smart_scripts` CHANGE `event_phase_mask` `event_phase_mask` smallint(5) unsigned NOT NULL DEFAULT '0';
