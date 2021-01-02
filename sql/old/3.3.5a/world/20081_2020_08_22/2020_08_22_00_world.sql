-- Remove SMARTCAST_INTERRUPT_PREVIOUS from Invoker Cast, Cross Cast and Self Cast actions
UPDATE `smart_scripts` SET `action_param2` = `action_param2` &~1 WHERE `action_type` IN (85,86,134) AND `action_param2` & 1;
