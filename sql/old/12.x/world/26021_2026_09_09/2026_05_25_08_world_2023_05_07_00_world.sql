-- Val'kyr Battle-maiden
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 28487;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28487 AND `source_type` = 0;
