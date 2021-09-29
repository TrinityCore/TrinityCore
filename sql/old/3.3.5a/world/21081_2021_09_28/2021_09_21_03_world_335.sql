--
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 14272;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 14272;
