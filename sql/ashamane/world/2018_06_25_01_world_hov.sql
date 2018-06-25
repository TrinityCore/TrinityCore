SET @CGUID := 210119019;

UPDATE creature_template SET `ScriptName` = 'boss_king_ranulf' WHERE `entry` = 97083;
UPDATE creature_template SET `ScriptName` = 'boss_king_haldor' WHERE `entry` = 95843;
UPDATE creature_template SET `ScriptName` = 'boss_king_bjorn' WHERE `entry` = 97081;
UPDATE creature_template SET `ScriptName` = 'boss_king_tor' WHERE `entry` = 97084;
UPDATE creature_template SET `ScriptName` = 'boss_god_king_kovald' WHERE `entry` = 95675;
UPDATE creature_template SET `ScriptName` = 'npc_aegis_of_aggramar' WHERE `entry` = 98364;
UPDATE creature_template SET `ScriptName` = 'npc_flame_of_woe' WHERE `entry` = 104822;
UPDATE creature_template SET npcflag = npcflag | 1, `ScriptName` = 'npc_halls_of_valor' WHERE `entry` = 101712;
UPDATE creature_template SET npcflag = npcflag | 1, `ScriptName` = 'npc_field_of_eternal_hunt' WHERE `entry` = 101697;
UPDATE creature_template SET `ScriptName` = 'boss_fenryr' WHERE `entry` = 99868;
UPDATE creature_template SET `ScriptName` = 'boss_hymdall' WHERE `entry` = 94960;
UPDATE creature_template SET `ScriptName` = 'boss_hyrja' WHERE `entry` = 95833;
UPDATE creature_template SET `ScriptName` = 'npc_olmyr_the_enlightened' WHERE `entry` = 97202;
UPDATE creature_template SET `ScriptName` = 'npc_olmyr_ghost' WHERE `entry` = 102557;
UPDATE creature_template SET `ScriptName` = 'npc_solsten' WHERE `entry` = 97219;
UPDATE creature_template SET `ScriptName` = 'npc_solsten_ghost' WHERE `entry` = 102558;
UPDATE creature_template SET `ScriptName` = 'boss_odyn_hov' WHERE `entry` = 95676;

UPDATE creature_template SET unit_flags = 0 WHERE entry IN (95675, 95833);
UPDATE creature_template SET flags_extra = 128 WHERE entry = 97795;
UPDATE creature_template SET inhabitType = 4 WHERE entry IN (97068);

UPDATE creature_template SET modelid1 = 47641 WHERE entry IN (101712, 101697);

UPDATE areatrigger_template SET `ScriptName` = 'at_center_eye_of_the_storm' WHERE `ID` = 10675;
UPDATE areatrigger_template SET `ScriptName` = 'at_eye_of_the_storm' WHERE `ID` = 10374;
UPDATE areatrigger_template SET `ScriptName` = 'at_sanctify' WHERE `ID` = 9601;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_aegis_of_aggramar' WHERE `ID` = 9758;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_infernal_flames' WHERE `ID` = 9758;
-- UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_flame_of_woe' WHERE `ID` = ;
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_dancing_blade' WHERE `ID` = 9700;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_kovald_ragnarok';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_kovald_infernal_flames';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_ravenous_leap_jump';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_ravenous_leap';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_expel_light';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sanctify';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193828, 'spell_kovald_ragnarok'),
(193828, 'spell_kovald_infernal_flames'),
(196495, 'spell_ravenous_leap_jump'),
(197560, 'spell_ravenous_leap'),
(192048, 'spell_expel_light'),
(192307, 'spell_sanctify');

UPDATE `instance_template` SET `script` = 'instance_halls_of_valor' WHERE `map` = 1477;

DELETE FROM creature_template_addon WHERE entry IN (97960, 101712);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(97960, 0, 0, 0, 1, 0, 0, 0, 0, 193214),
(101712, 0, 0, 50331648, 1, 0, 0, 0, 0, 200611);

UPDATE `creature_template_addon` SET `auras` = '' WHERE (entry = 95676);

DELETE FROM creature WHERE guid BETWEEN @CGUID+0 AND @CGUID+3;
insert into `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) values
(@CGUID+0, 95833,  1477, 0, 0, 2, 0, 0, 0, -1, 0, 1, 3113.48, 288.964, 662.4,   0.768688, 300, 0, 0, 38927456, 1, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+1, 97202,  1477, 0, 0, 2, 0, 0, 0, -1, 0, 1, 3138.08, 366.848, 655.18,  4.54253,  300, 0, 0, 17201968, 1, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+2, 97219,  1477, 0, 0, 2, 0, 0, 0, -1, 0, 1, 3191.19, 313.781, 655.185, 3.29767,  300, 0, 0, 17201968, 1, 0, 0, 0, 0, 0, 0, '', 0),
(@CGUID+3, 101712, 1477, 0, 0, 2, 0, 0, 0, -1, 0, 0, 3211.49, 2901.56, 641.531, 2.88399,  300, 0, 0, 87,       0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE creature SET spawnmask = 8388870 WHERE map = 1477;
UPDATE gameobject SET spawnmask = 8388870 WHERE map = 1477;