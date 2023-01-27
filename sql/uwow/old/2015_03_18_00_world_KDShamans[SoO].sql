DELETE FROM `creature` WHERE `id` = '71801';
DELETE FROM `creature` WHERE `id` = '71817';
DELETE FROM `creature` WHERE `id` = '71858';
DELETE FROM `creature` WHERE `id` = '71859';
DELETE FROM `creature` WHERE `id` = '71923';
DELETE FROM `creature` WHERE `id` = '71921';
DELETE FROM `creature` WHERE `id` = '71827';
DELETE FROM `creature` WHERE `id` = '71825';
DELETE FROM `creature` WHERE `id` = '72562';
DELETE FROM `creature` WHERE `id` = '72643';
DELETE FROM `creature` WHERE `id` = '72644';
DELETE FROM `creature` WHERE `id` = '71915';
DELETE FROM `creature` WHERE `id` = '71916';
DELETE FROM `creature` WHERE `id` = '71917';
insert into `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) values
('71859','1136','6738','6738','16536','1','0','71859','1659.5','-4334.99','26.7679','4.51469','300','0','0','348909600','1000','0','0','0','0','0','0'),
('71858','1136','6738','6738','16536','1','0','71858','1669.13','-4355.66','26.7168','3.035','300','0','0','348909600','1000','0','0','0','0','0','0');
UPDATE `creature_template` SET `ScriptName`='npc_ash_elemental' WHERE `entry`='71827'; 
UPDATE `creature_template` SET `ScriptName`='npc_foul_slime' WHERE `entry`='71825'; 
UPDATE `creature_template` SET `ScriptName`='npc_toxic_storm' WHERE `entry`='71801'; 
UPDATE `creature_template` SET `ScriptName`='npc_toxic_tornado' WHERE `entry`='71817'; 
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`flags_extra`='1',`ScriptName`='boss_korkron_dark_shaman' WHERE `entry`='71858'; 
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`flags_extra`='1',`ScriptName`='boss_korkron_dark_shaman' WHERE `entry`='71859'; 
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`ScriptName`='npc_wolf_maunt' WHERE `entry`='71921'; 
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`ScriptName`='npc_wolf_maunt' WHERE `entry`='71923'; 
UPDATE `creature_template_addon` SET `auras`='144226' WHERE `entry`='71858'; 
UPDATE `creature_template_addon` SET `auras`='144227' WHERE `entry`='71859'; 
delete from creature_text where entry in (71858,71859);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
('71858','0','0','Покоритесь нам!','14','0','100','0','0','39013','Покорительница волн Кардрис'),
('71859','0','0','Покоритесь нам!','14','0','100','0','0','39013','Землелом Харомм'); 



