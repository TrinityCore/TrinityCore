-- 
UPDATE `smart_scripts` SET `target_type`=24 WHERE `target_type`=16 AND `event_type`=2  AND `action_type` IN (33,15,11);
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=13197 AND `source_type`=0  AND `id`=11;
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=16977 AND `source_type`=0  AND `id`=14;
UPDATE `smart_scripts` SET `target_type`=18, `target_param1`=25 WHERE `target_type`=7 AND `event_type`=7  AND `action_type` IN (6);
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=25773 AND `source_type`=0  AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=19480 AND `source_type`=0  AND `id`=2;
UPDATE `smart_scripts` SET `event_type`=4 WHERE `entryorguid`=18400 AND `source_type`=0  AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=28444 AND `source_type`=0  AND `id`=1;
UPDATE `smart_scripts` SET `event_type`=10, `event_param1`=1, `event_param1`=20 WHERE `entryorguid`=19283 AND `source_type`=0  AND `id`=3;
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=27202 AND `source_type`=0  AND `id`=6;
