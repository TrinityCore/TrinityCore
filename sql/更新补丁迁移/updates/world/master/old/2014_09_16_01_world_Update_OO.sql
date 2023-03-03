DELETE FROM `creature` WHERE `id` = '35642' AND `map` = '1136';
DELETE FROM `creature` WHERE `id` = '72872' AND `spawndist` = '7';
DELETE FROM `creature` WHERE `id` = '72565';
DELETE FROM `creature` WHERE `id` = '72550';
DELETE FROM `creature` WHERE `id` = '61348';
DELETE FROM `creature` WHERE `id` = '71965';
DELETE FROM `creature` WHERE `id` = '71976';
DELETE FROM `creature` WHERE `id` = '71977';
DELETE FROM `creature` WHERE `id` = '72263';
DELETE FROM `creature` WHERE `id` = '72264';
UPDATE `creature_template` SET `ScriptName`='boss_amalgam_of_corruption' WHERE `entry`='72276';
UPDATE `creature_template` SET `ScriptName`='npc_blind_hatred' WHERE `entry`='72565';
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) values(NULL ,'221446','1136','6738','6738','16632','1','761.74','1048.2','357.106','1.78023','0','0','-0.465614','0.884988','7200','255','0','0');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) values(NULL ,'221447','1136','6738','6738','16632','1','768.012','1018.88','357.151','4.92363','0','0','0.628621','-0.777712','7200','255','1','0');
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) values('90008','0','0','0','0','0','169','11686','11686','0','Blind Hatred Controller','','','0','93','93','4','1','14','14','0','0','1','1.14286','1.14286','1','1','628','942','0','236','2','2000','2000','1','33554432','4196352','0','0','0','0','0','0','502','754','189','10','40','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','1','1','0','0','0','0','0','0','0','0','1','0','0','0','npc_blind_hatred_controller','16357');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('145216','spell_unleashed_anger');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('145227','spell_blind_hatred');


 