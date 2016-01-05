-- Issue #16168
-- Orbaz Bloodbane: Fix incorrect creature texts
-- By: dr-j
UPDATE `creature_text` SET `BroadcastTextId`=31961 WHERE  `entry`=31283 AND `groupid`=1 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=31962 WHERE  `entry`=31283 AND `groupid`=2 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=31963 WHERE  `entry`=31283 AND `groupid`=3 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=31966 WHERE  `entry`=31283 AND `groupid`=4 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=31967 WHERE  `entry`=31283 AND `groupid`=5 AND `id`=0;
UPDATE `creature_text` SET `BroadcastTextId`=31964 WHERE  `entry`=31283 AND `groupid`=6 AND `id`=0;
