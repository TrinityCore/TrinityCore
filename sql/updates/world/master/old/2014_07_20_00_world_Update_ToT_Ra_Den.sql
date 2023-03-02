DELETE FROM `creature` WHERE `id`='69081';
UPDATE `creature_template` SET `InhabitType`='5',`mechanic_immune_mask`='650854399',`ScriptName`='npc_corrupted_sphere' WHERE `entry`='69958'; 
UPDATE `creature_template` SET `InhabitType`='5',`mechanic_immune_mask`='650854399',`ScriptName`='npc_corrupted_sphere' WHERE `entry`='69957'; 
UPDATE `creature_template` SET `unit_class`='4',`unit_flags`='0',`unit_flags2`='2048',`VehicleId`='2114',`mechanic_immune_mask`='650854399',`flags_extra`='1',`ScriptName`='boss_ra_den' WHERE `entry`='69473';
UPDATE `creature_template` SET `mechanic_immune_mask`='1048584',`ScriptName`='npc_crackling_stalker' WHERE `entry`='69872'; 
UPDATE `creature_template` SET `faction_A`='14',`faction_H`='14',`minlevel`='92',`maxlevel`='92',`mechanic_immune_mask`='650854399',`ScriptName`='npc_sanguine_horror' WHERE `entry`='69871';
UPDATE `gameobject_template` SET `faction`='1375' WHERE `entry`='218555';  
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `isActive`) values(NULL ,'69473','1098','6622','6730','248','1','0','0','5383.56','4656.25','-1.14492','0.0111542','604800','0','0','491090262','0','0','0','0','0','0');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) values('69473','0','0','0','1','0','122452');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('138321','spell_material_of_creation');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('138334','spell_fatal_strike');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('138333','spell_murderous_strike');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('138329','spell_unleashed_anima');

