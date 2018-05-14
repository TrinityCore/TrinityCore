-- 
-- Delete duplicate Armory and Cathedral doors
DELETE FROM `gameobject` WHERE `guid` IN (200966,203104,212814,216444,220549,200965,203103,212815,216443,220550);

-- UPDATE SAI target
UPDATE `smart_scripts` SET `target_param1`=200252 WHERE `entryorguid` IN (101852) AND `source_type`=1 AND `id`=0;
UPDATE `smart_scripts` SET `target_param1`=200251 WHERE `entryorguid` IN (101853) AND `source_type`=1 AND `id`=0;
