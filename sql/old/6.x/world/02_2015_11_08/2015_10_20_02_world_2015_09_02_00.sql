-- Waypoint fix for quest "Escape from the Winterfin Caverns" (11570)
UPDATE `script_waypoint` SET `location_x`=4279.54, `location_y`=6187.932, `location_z`=0.294670 WHERE `entry`=25208 AND `pointid`=41;

-- Swap 1st and 2nd text
UPDATE `creature_text` SET `groupid` = 99 WHERE `entry` = 25208 AND `groupid` = 0  AND `id` = 0;
UPDATE `creature_text` SET `groupid` = 0  WHERE `entry` = 25208 AND `groupid` = 1  AND `id` = 0;
UPDATE `creature_text` SET `groupid` = 1  WHERE `entry` = 25208 AND `groupid` = 99 AND `id` = 0;
