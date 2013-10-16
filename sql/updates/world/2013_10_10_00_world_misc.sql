UPDATE `creature` SET `spawndist`=0 WHERE `guid`=142524;

UPDATE `smart_scripts` SET `event_param2`=100 WHERE `entryorguid`=16769 AND `source_type`=0 AND `id`=9;
UPDATE `smart_scripts` SET `action_param1`=55661 WHERE `entryorguid`=29872 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=55662 WHERE `entryorguid`=29895 AND `source_type`=0 AND `id`=3;

UPDATE `conditions` SET `SourceGroup`=10059 WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=10058 AND `SourceEntry`=51969;
UPDATE `conditions` SET `SourceGroup`=10058 WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=10059 AND `SourceEntry`=51961;
