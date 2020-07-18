-- 
UPDATE `smart_scripts` SET `event_param5`=1 WHERE event_type=10 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param2`=30, `event_param5`=1 WHERE `entryorguid`=24248 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_flags`=0 WHERE `entryorguid`=24938 AND event_type=10 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param1`=1 WHERE `entryorguid`in (27376,27378,27379,27381) AND event_type=10 AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param1`=1, `event_param2`=20, `event_param5`=0 WHERE `entryorguid`=30313 AND `event_type`=10 AND `source_type`=0;
UPDATE `creature_template` SET `AIName`=""  WHERE `entry`=32582;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32582) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_flags`=0, `event_param2`=10, `event_param3`=60000, `event_param4`=60000, `event_param5`=1 WHERE `entryorguid`=5917 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=0, `event_param1`=1, `event_param2`=20, `event_param3`=40000, `event_param4`=60000, `event_param5`=1 WHERE `entryorguid`=9021 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_param5`=0 WHERE `entryorguid` IN (27246,  2775, 23370, 23760, 24845, 23675, 23673, 23672, 24271, 24364, 24468, 24510, 24527, 24718, 24938,24979,25063,30313) AND event_type=10 AND `source_type`=0;
