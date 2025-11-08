-- Waypoint fix for "Spirit of Sathrah" (7411)
UPDATE `waypoints` SET `position_x`=9627.15,`position_y`=2517.89,`position_z`=1331.76 WHERE `entry`=7411 AND `pointid`=5;

-- Set despawn time for "Spirit of Sathrah" to 0
UPDATE `smart_scripts` SET `action_param1`=0,`comment`="Spirit of Sathrah - On Waypoint 9 Reached - Despawn" WHERE `entryorguid`=7411 AND `id`=1;
