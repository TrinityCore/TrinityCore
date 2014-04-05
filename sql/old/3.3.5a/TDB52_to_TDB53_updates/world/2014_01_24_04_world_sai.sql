--
UPDATE `creature_template` SET `AIName`= '' WHERE  `entry`=23450;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23450 AND  `source_type`=0;
UPDATE `creature_template` SET `AIName`= '' WHERE  `entry`=28674;
