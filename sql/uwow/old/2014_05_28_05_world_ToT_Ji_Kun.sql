DELETE FROM `gameobject` WHERE `id` = '218543';
DELETE FROM `creature` WHERE `id` = '64571' AND `map` = '1098';
DELETE FROM `creature` WHERE `id` = '69712';
DELETE FROM `creature` WHERE `id` = '68178';
DELETE FROM `creature` WHERE `id` = '68188';
UPDATE `creature_template` SET `unit_flags`='0',`unit_flags2`='2048',`mechanic_immune_mask`='650854399',`ScriptName`='boss_jikun' WHERE `entry`='69712'; 
UPDATE `gameobject_template` SET `data0`='0',`ScriptName`='go_ji_kun_feather' WHERE `entry`='218543'; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) values(NULL ,'69712','1098','6622','6622','248','1','0','0','6147.13','4318.88','-30.8689','4.21308','604800','0','0','195389376','0','0','0','0','0','0');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) values(NULL ,'218543','1098','6622','6622','248','1','6125.02','4356.26','-31.8636','5.25849','0','0','0.490225','-0.871596','300','0','1','0');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) values(NULL ,'218543','1098','6622','6622','248','1','6094.68','4227.67','-6.2534','1.03928','0','0','0.496569','0.867997','300','0','1','0');

