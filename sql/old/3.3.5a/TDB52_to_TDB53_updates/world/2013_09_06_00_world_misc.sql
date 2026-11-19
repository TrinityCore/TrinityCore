-- Fix few startup errors
UPDATE `smart_scripts` SET `event_param3`=12555 WHERE `entryorguid`=27727 AND `source_type`=0 AND `id`=2 AND `link`=0;
DELETE FROM `creature_addon` WHERE `guid`=66177;
DELETE FROM `waypoint_data` WHERE `id`=661770;
