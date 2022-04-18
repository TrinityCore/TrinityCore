-- Remove useless param inside SMART_ACTION_CALL_TIMED_ACTIONLIST for gameobject scripts
-- Gameobjects cannot be in combat so no reason to change timer update type to 2 (update always)
UPDATE `smart_scripts` SET `action_param2` = 0 WHERE `action_type` = 80 AND `source_type` = 1 AND `target_type` = 1;
