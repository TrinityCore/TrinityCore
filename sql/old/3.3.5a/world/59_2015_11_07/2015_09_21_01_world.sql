-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=3518 AND `source_type`=0;
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=3518;
UPDATE `waypoint_scripts` SET `dataint`=1102 WHERE `id`=273 ;
