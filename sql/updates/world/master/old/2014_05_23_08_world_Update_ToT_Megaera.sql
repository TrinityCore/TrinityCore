DELETE FROM `creature` WHERE `id` = '68136';
DELETE FROM `creature` WHERE `id` = '70435';
DELETE FROM `creature` WHERE `id` = '63420';
DELETE FROM `creature` WHERE `id` = '70235';
DELETE FROM `creature` WHERE `id` = '70247';
DELETE FROM `creature` WHERE `id` = '70212';
DELETE FROM `creature` WHERE `id` = '70229';
DELETE FROM `creature` WHERE `id` = '70251';
DELETE FROM `creature` WHERE `id` = '70432';
DELETE FROM `creature` WHERE `id` = '58542' AND `map` = '1098';
UPDATE `creature_template` SET `modelid2`='0',`modelid3`='0',`modelid4`='0',`unit_flags`='0',`unit_flags2`='2048',`InhabitType` = '5',`mechanic_immune_mask`='650854399',`ScriptName`='npc_megaera_head' WHERE `entry`='70212'; 
UPDATE `creature_template` SET `modelid2`='0',`modelid3`='0',`modelid4`='0',`unit_flags`='0',`unit_flags2`='2048',`InhabitType` = '5',`mechanic_immune_mask`='650854399',`ScriptName`='npc_megaera_head' WHERE `entry`='70235'; 
UPDATE `creature_template` SET `modelid2`='0',`modelid3`='0',`modelid4`='0',`unit_flags`='0',`unit_flags2`='2048',`InhabitType` = '5',`mechanic_immune_mask`='650854399',`ScriptName`='npc_megaera_head' WHERE `entry`='70247'; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) values(NULL ,'70212','1098','6622','6706','248','1','0','0','6469.97','4483.59','-209.609','2.4602','604800','0','0','30093452','0','0','0','0','0','0');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) values(NULL ,'70235','1098','6622','6706','248','1','0','0','6419.33','4504.38','-209.609','2.3032','604800','0','0','30093452','0','0','0','0','0','0');
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) values(NULL ,'70247','1098','6622','6706','248','1','0','0','6438.71','4533.36','-209.609','2.7672','604800','0','0','30093452','0','0','0','0','0','0');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('139822','spell_cinders');
UPDATE `creature_template` SET `ScriptName`='npc_cinders' WHERE `entry`='70432'; 




