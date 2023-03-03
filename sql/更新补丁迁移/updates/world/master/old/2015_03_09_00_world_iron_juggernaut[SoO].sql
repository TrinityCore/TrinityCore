DELETE FROM `creature` WHERE `id` = '71484';
DELETE FROM `creature` WHERE `id` = '71469';
DELETE FROM `creature` WHERE `id` = '71468';
DELETE FROM `creature` WHERE `id` = '71913';
DELETE FROM `creature` WHERE `id` = '71914';
DELETE FROM `creature` WHERE `id` = '72050';
DELETE FROM `creature` WHERE `id` = '73962';
DELETE FROM `creature` WHERE `id` = '73963';
DELETE FROM `creature` WHERE `id` = '71906';
DELETE FROM `creature` WHERE `id` = '72026';
DELETE FROM `creature` WHERE `id` = '71950';
DELETE FROM `creature` WHERE `id` = '71466';
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ('146325','spell_cutter_laser_target');
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ('144483','spell_seismic_activity'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ('144498','spell_explosive_tar'); 
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES ('144918','spell_cutter_laser'); 
UPDATE `creature_template` SET `modelid2`='0',`modelid3`='0',`ScriptName`='npc_explosive_tar' WHERE `entry`='71950';  
UPDATE `creature_template` SET `modelid2`='0',`modelid3`='0',`ScriptName`='npc_cutter_laser' WHERE `entry`='72026';  
UPDATE `creature_template_addon` SET `auras`='122452' WHERE `entry`='71466'; 
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`ScriptName`='npc_crawler_mine' WHERE `entry`='72050'; 
insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) values(NULL ,'71466','1136','6738','6802','16536','1','0','0','1308.86','-4387.75','26.0309','3.40616','604800','0','0','451401792','1000','0','16777216','0','0','0','0');
UPDATE `creature_template` SET `flags_extra`='1',`ScriptName`='boss_iron_juggernaut' WHERE `entry`='71466';
UPDATE `creature_template` SET `ScriptName`='npc_generic_iron_juggernaut_passenger' WHERE `entry`='71484'; 
UPDATE `creature_template` SET `ScriptName`='npc_generic_iron_juggernaut_passenger' WHERE `entry`='71469';
UPDATE `creature_template` SET `ScriptName`='npc_generic_iron_juggernaut_passenger' WHERE `entry`='71468';
UPDATE `creature_template` SET `ScriptName`='npc_generic_iron_juggernaut_passenger' WHERE `entry`='71914';  
insert into `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) values('71466','65343','0','0');
insert into `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) values('71466','71484','0','1','','8','0');
insert into `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) values('71466','71469','1','1','','8','0');
insert into `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) values('71466','71468','2','1','','8','0');
insert into `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) values('71466','71468','3','1','','8','0');
insert into `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) values('71466','71914','4','1','','8','0');



