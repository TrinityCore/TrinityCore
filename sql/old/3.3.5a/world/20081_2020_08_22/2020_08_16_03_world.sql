-- Remove SMARTCAST_INTERRUPT_PREVIOUS from nearly all scripts
UPDATE `smart_scripts` SET `action_param2` = `action_param2` &~1 WHERE `event_type` IN (0,2,3,4,9,11,12,13,14,15,16,19,22,23,25,62,63,74) AND `event_flags` & 1 = 0 AND `action_type` = 11 AND `source_type` = 0 AND `action_param2` & 1;
