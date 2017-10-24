-- 
UPDATE `smart_scripts` SET `event_param3`=0, `event_param4`=0 WHERE `entryorguid`=2856601 AND `source_type`=9 AND `id`=2;
UPDATE `smart_scripts` SET `event_flags`=0, `event_param3`=8010, `event_param4`=8010 WHERE `entryorguid`=28566 AND `source_type`=0 AND `id`=6;
UPDATE `smart_scripts` SET `event_flags`=0, `event_param3`=8000, `event_param4`=8000 WHERE `entryorguid`=28566 AND `source_type`=0 AND `id`=5;
UPDATE `smart_scripts` SET `event_flags`=0, `event_param3`=2000, `event_param4`=2000 WHERE `entryorguid`=28566 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `action_param1`=1 WHERE `entryorguid` IN (28566) AND `source_type`=0 AND `id`=5;
