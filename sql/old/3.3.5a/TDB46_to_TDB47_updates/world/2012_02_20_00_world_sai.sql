UPDATE `smart_scripts` SET `event_param3`=2*60*60*1000, `event_param4`=2*60*60*1000 WHERE `entryorguid`=18481 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=`event_flags`|1 WHERE `entryorguid` IN (-85175,-85176) AND `source_type`=0 AND `id`=5 AND `link`=6;
UPDATE `smart_scripts` SET `event_flags`=`event_flags`|1 WHERE `entryorguid`=30146 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_flags`=`event_flags`|0x20 WHERE `entryorguid` IN (-85175,-85176) AND `source_type`=0 AND `id`=2 AND `link`=3;
