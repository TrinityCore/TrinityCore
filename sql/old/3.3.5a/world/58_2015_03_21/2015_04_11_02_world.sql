UPDATE `smart_scripts` SET `event_flags`=0 WHERE `entryorguid`=25310 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid` IN (24009, 24010) AND `source_type`=0 AND `id`=1;
