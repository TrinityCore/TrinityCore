-- 
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry` IN (14862);
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid` IN (14862) AND `source_type`=0 AND `id`=5;
