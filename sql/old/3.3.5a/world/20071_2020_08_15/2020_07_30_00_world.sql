-- Creature Rhahk'Zor 644 SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 644 AND `source_type` = 0 AND `id` = 2;

-- Change door entries to correct ones
UPDATE `gameobject` SET `id` = 16400 WHERE `guid` = 26185 AND `id` = 17153;
UPDATE `gameobject` SET `id` = 16399 WHERE `guid` = 26182 AND `id` = 17153;

-- Update Door Lever's interaction SAI to the new doors
UPDATE `smart_scripts` SET `target_type` = 20, `target_param1` = 16400, `target_param2` = 30 WHERE `entryorguid` = 101832 AND `source_type` = 1 AND `id` = 0;
UPDATE `smart_scripts` SET `target_type` = 20, `target_param1` = 16399, `target_param2` = 30 WHERE `entryorguid` = 101834 AND `source_type` = 1 AND `id` = 0;
