-- 
UPDATE `creature_template` SET `MovementType`=0 WHERE `entry` IN (21315,4841,8666,23872,25964,25965,25966,27003,33576);
UPDATE `creature` SET `MovementType`=2 WHERE `id`=27003;
UPDATE `waypoint_data` SET `id`=1072390 WHERE `id`=270030;
UPDATE `creature_addon` SET `path_id`=1072390 WHERE `guid`=107239;
