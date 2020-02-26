-- 
UPDATE `creature_template` SET AIName="" WHERE `entry` IN (24151);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24151) AND `source_type`=0;
