-- 
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|617299839 WHERE `entry`=33995;
UPDATE `gameobject` SET `rotation2`=-0.571201 WHERE `guid`= 5255 AND `id`= 21148;
DELETE FROM `linked_respawn` WHERE `guid` IN (12605,12606) AND `linkedGuid`=12597;
