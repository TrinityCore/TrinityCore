-- 
UPDATE `gameobject_template` SET `AIName`='' WHERE `entry`=101812;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=101812;
