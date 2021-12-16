--
DELETE FROM `waypoint_data` WHERE `id` = 740330;
DELETE FROM `creature_template_addon` WHERE `entry` = 10820;
DELETE FROM `creature` WHERE `id` = 10820;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10820 AND `source_type` = 0;
