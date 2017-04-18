-- remove old (never used) param values from _CAST and _INVOKER_CAST
UPDATE `smart_scripts` SET `action_param3`=0,`action_param4`=0,`action_param5`=0,`action_param6`=0 WHERE `action_type` IN (11,85);
