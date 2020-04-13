-- 
UPDATE `gameobject_template` SET `AIName`="" WHERE `entry`=375;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 375 AND `source_type`=1;
