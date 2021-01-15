--
UPDATE `smart_scripts` SET `event_type`=58 WHERE `entryorguid`=50414 AND `source_type`=0 AND `id`=1;
DELETE FROM `creature` WHERE `guid`=325132 AND `id` =50374;
UPDATE `creature_text` SET `BroadcastTextId`=50126 WHERE `entry`=1568 AND `groupid`=0 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=50127 WHERE `entry`=1568 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=50128 WHERE `entry`=50414 AND `groupid`=0 AND `id`=0;
