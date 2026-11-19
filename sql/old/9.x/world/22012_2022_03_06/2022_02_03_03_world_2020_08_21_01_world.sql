-- Remove SMARTCAST_INTERRUPT_PREVIOUS from more event types
UPDATE `smart_scripts` SET `action_param2` = `action_param2` &~1 WHERE `event_type` IN (6,8,38,40,60,75) AND `event_flags` & 1 = 0 AND `action_type` = 11 AND `source_type` = 0 AND `action_param2` & 1;
