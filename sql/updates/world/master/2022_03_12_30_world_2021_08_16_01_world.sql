-- Not even needed, set as typo and uses no type but only map param
UPDATE `smart_scripts` SET `event_param2` = 0 WHERE `entryorguid` = 23941 AND `source_type` = 0 AND `id` = 0;
-- They all are spawned in same map and type is again 0, it's not even called
-- Even if intention was to reset faction to default, it will never work like that
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23678 AND `source_type` = 0 AND `id` = 0;
-- This should be handled differently, instead of changing default faction in template and changing it back in script for all creatures
-- except one summoned(not even implemented), faction should be changed only in script of summoned creature
UPDATE `creature_template` SET `faction` = 17 WHERE `entry` = 1706;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1706 AND `source_type` = 0 AND `id` = 3;
