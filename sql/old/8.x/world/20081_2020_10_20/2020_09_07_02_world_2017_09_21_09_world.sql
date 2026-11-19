-- Ore Cart
UPDATE `creature` SET `modelid`=0 WHERE `id`=25986;
UPDATE `smart_scripts` SET `action_param1`=2000, `comment`="Ore Cart - On Waypoint 15 Reached - Despawn In 2 Seconds" WHERE `entryorguid`=25986 AND `id`=2;
