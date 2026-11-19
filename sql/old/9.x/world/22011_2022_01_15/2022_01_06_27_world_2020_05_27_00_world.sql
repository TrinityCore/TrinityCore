-- 
UPDATE `smart_scripts` SET `event_flags` = `event_flags` &~ 1 WHERE `source_type` = 9; -- SMART_EVENT_FLAG_NOT_REPEATABLE
UPDATE `smart_scripts` SET `event_flags` = `event_flags` &~ 2 WHERE `source_type` = 9; -- SMART_EVENT_FLAG_DIFFICULTY_0
UPDATE `smart_scripts` SET `event_flags` = `event_flags` &~ 4 WHERE `source_type` = 9; -- SMART_EVENT_FLAG_DIFFICULTY_1
