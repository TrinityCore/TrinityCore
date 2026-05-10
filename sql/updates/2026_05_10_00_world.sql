-- Jaedenar Hound dont cast on non manauser
UPDATE `smart_scripts` SET `target_type` = 5, `target_param1` = 0, `target_param2` = 0, `target_param3` = 1, `target_param4` = 0 WHERE `entryorguid` = 7125 AND `source_type` = 0 AND `action_type` = 11 AND `action_param1` = 13321;
