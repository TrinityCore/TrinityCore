-- 
UPDATE `creature` SET `equipment_id`=1 WHERE `guid` IN (120420,120423,120427,120421,120422,120426);
UPDATE `creature` SET `equipment_id`=2 WHERE `guid` IN (120419,120425);
UPDATE `waypoint_data` SET `position_x`=2558.624023, `position_y`=-4999.662109, `position_z`=291.09082, `orientation`=1.009225 WHERE `id` IN (1204260) AND `point`=1;
UPDATE `waypoint_data` SET `delay`=20000 WHERE `id` IN (1204260);
