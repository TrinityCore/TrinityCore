-- Run action list in Reth'hedron's script even in OOC to prevent potential script stuck
UPDATE `smart_scripts` SET `action_param2` = 2 WHERE `entryorguid` = 22357 AND `source_type` = 0 AND `id` = 13;
