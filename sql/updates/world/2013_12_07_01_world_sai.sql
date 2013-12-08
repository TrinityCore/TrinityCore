-- Remove Springpaw Stalker & Elder Springpaw SAI
UPDATE `creature_template` SET `AIName`= '' WHERE `entry`IN (15651,15652);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY IN (15651,15652);
