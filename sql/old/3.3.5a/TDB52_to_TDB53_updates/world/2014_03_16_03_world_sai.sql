--
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=28256 AND `source_type`=1;
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=2825600 AND `source_type`=9 AND `id` BETWEEN 0 AND 4;
UPDATE `smart_scripts` SET `target_type`=18, `target_param1`=30 WHERE `entryorguid`=2825600 AND `source_type`=9 AND `id`=5;
