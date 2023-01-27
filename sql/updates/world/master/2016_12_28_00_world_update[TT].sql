DELETE FROM `creature` WHERE `id` = '68192';
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`ScriptName`='npc_young_egg_of_jikun' WHERE `entry`='68194'; 
UPDATE `creature_template` SET `ScriptName`='npc_incubater' WHERE `entry`='69626';
DELETE FROM `gameobject` WHERE `id`='213168' AND `map` = '1098';
UPDATE `creature_template` SET `ScriptName`='npc_jump_to_boss_platform' WHERE `entry`='69885'; 
DELETE FROM `spell_target_position` WHERE `id` = '138359';
INSERT INTO `spell_target_position`(`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES ( '138359','1098','6110.18','4296.92','-31.8637','0.5542');
DELETE FROM `gameobject` WHERE `id`='218543';
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) values(NULL ,'218543','1098','6622','6622','248','1','6184.25','4340.52','-31.8624','3.73717','0','0','0.955987','-0.293409','-604800','0','1','0');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) values(NULL ,'218543','1098','6622','6622','248','1','6125.7','4355.96','-31.8624','5.35509','0','0','0.447572','-0.894248','-604800','0','1','0');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) values(NULL ,'218543','1098','6622','6622','248','1','6169.03','4281.31','-31.8633','2.17267','0','0','0.884926','0.465732','-604800','0','1','0');
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) values(NULL ,'218543','1098','6622','6622','248','1','6110.02','4296.62','-31.8632','0.568894','0','0','0.280627','0.959817','-604800','0','1','0');
DELETE FROM `areatrigger_actions` WHERE `entry` = '800';
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('800','0','1','0','8','138406','0','0','0','0','0','0','0','TT:Jump to Boss Platform Area Trigger');
UPDATE `areatrigger_data` SET `Radius`='20',`RadiusTarget`='20',`polygon`='0' WHERE `entry`='800'; 
  