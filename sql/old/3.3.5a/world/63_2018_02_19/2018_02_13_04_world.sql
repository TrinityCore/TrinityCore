-- SMART_ACTION_FLEE_FOR_ASSIST (25) does not need a target
UPDATE `smart_scripts` SET `target_type`=0 WHERE `action_type`=25;
