-- Corporal Keeshan correct respawn time
UPDATE `creature` SET `spawntimesecs`=15 WHERE `guid`=17874;

-- After Corporal Keeshan reash waypoint 70 he should run the rest of the way
UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=2793 AND `point` BETWEEN 70 AND 115;

-- Add missing WP pause
UPDATE `smart_scripts` SET `action_type`=54,`action_param1`=3000,`comment`='Corporal Keeshan - Action list - pause waypoint' WHERE `entryorguid`=34902 AND `id`=0;
