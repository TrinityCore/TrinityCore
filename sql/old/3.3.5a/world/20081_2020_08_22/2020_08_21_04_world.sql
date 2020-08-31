-- Make Bonestripper Buzzard & Vulture move to invoker rather than random creature
UPDATE `smart_scripts` SET `target_type` = 7, `target_param1` = 0, `target_param2` = 0, `target_param3` = 0, `comment` = "Bonestripper Buzzard - On Data 1 1 Set - Move To Invoker" WHERE `entryorguid` = 16972 AND `source_type` = 0 AND `id` = 2;
UPDATE `smart_scripts` SET `target_type` = 7, `target_param1` = 0, `target_param2` = 0, `target_param3` = 0, `comment` = "Bonestripper Vulture - On Data 1 1 Set - Move To Invoker" WHERE `entryorguid` = 16973 AND `source_type` = 0 AND `id` = 2;
