-- Fix SAI for Sunseeker Harvester
UPDATE `smart_scripts` SET `event_flags`=7 WHERE `entryorguid`=19509 AND `source_type`=0 AND `id`=2;
