-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=2546000 AND `source_type`=9 AND `id`=0 AND `action_type`=11;
UPDATE `smart_scripts` SET `id`=0 WHERE `entryorguid`=2546000 AND `source_type`=9 AND `id`=1 AND `action_type`=53;

DELETE FROM `creature_addon` WHERE `guid`=137997; -- fix a DB error
