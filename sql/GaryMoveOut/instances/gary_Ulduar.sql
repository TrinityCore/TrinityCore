###########
-- ULDUAR #
###########

-- CLEANUP

UPDATE `creature_template` SET `unit_flags`= 33554432 WHERE `entry`=33661;
UPDATE `creature_template` SET `speed_walk`= 1 WHERE `entry` IN (32865, 33147);
UPDATE `creature_template` SET `baseattacktime`= 2000 WHERE `entry`=33147;
UPDATE `creature_template` SET `modelid2`=16925 WHERE `entry`=32879;
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=32879;
UPDATE `creature_template` SET `unit_flags`=32768, `dynamicflags`=8 WHERE `entry` IN (32885,32883,32908,32907,32882,32886);
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=16925 WHERE `entry` IN (33378, 32892);
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry` IN (33725, 33054);
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry` IN (32872, 32873, 32874);
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=32879;
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=34143;
UPDATE `creature_template` SET `modelid1`= 1126 WHERE `entry` IN (33990,33991);
UPDATE `creature_template` SET `modelid2`= 1126 WHERE `entry` IN (33881,33882);
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=33990;
UPDATE `creature_template` SET `modelid1`= 169 WHERE `entry` IN (34188,34189, 33233, 34129, 34153);
UPDATE `creature_template` SET `unit_flags`=16384 WHERE `entry`=33264;
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=33233;
UPDATE `creature_template` SET `modelid1`= 169, `modelid2`=23258 WHERE `entry` IN (33050, 33395, 33170, 33402);
UPDATE `creature_template` SET `modelid1`= 19725, `modelid2`=28549 WHERE `entry`=33292;
UPDATE `creature_template` SET `modelid1`= 1126, `modelid2`=28549 WHERE `entry`=34194;
UPDATE `creature_template` SET `mindmg`= 356, `maxdmg`=503, `minlevel`=76, `maxlevel`=76 WHERE `entry`=32879;
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `faction_A`=35, `faction_H`=35, `mindmg`=2, `maxdmg`=2, `attackpower`=24, `dmg_multiplier`=1, `unit_flags`=0, `InhabitType`=3, `ScriptName`='npc_yogg_saron_encounter_controller' WHERE `entry`=29224;
UPDATE `creature` SET `spawndist`=0 WHERE `id`=32865;
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`=32865;
UPDATE `gameobject_template` SET `flags`=16 WHERE `entry`=194312;
UPDATE `gameobject_template` SET `type`=0, `faction`=0, `data1`=1845, `data4`=33914 WHERE `entry`=194264;
UPDATE `gameobject_template` SET `flags`=48 WHERE `entry` IN (194912, 194914);
UPDATE `gameobject` SET `rotation2`=0, `spawntimesecs`=180, `animprogress`=255 WHERE `id`=194264;
DELETE FROM `gameobject_template` WHERE `entry`=194438;
DELETE FROM `gameobject` WHERE `id`=194438;
DELETE FROM `waypoint_data` WHERE `id` IN (34496, 34497);
DELETE FROM `creature` WHERE `id`=33856;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `position_x`, `position_y`, `position_z`, `spawntimesecs`, `curhealth`) VALUES 
(137621,33856,603,3,1,16925,2703.93,2569.32,364.397,180,4120),
(137622,33856,603,3,1,16925,2715.33,2569.23,364.397,180,4120),
(137623,33856,603,3,1,16925,2726.85,2569.28,364.397,180,4120),
(137624,33856,603,3,1,16925,2765.24,2534.38,364.397,180,4120),
(137625,33856,603,3,1,16925,2759.54,2544.3,364.397,180,4120),
(137626,33856,603,3,1,16925,2753.82,2554.22,364.397,180,4120),
(137627,33856,603,3,1,16925,2764.95,2604.11,364.397,180,4120),
(137628,33856,603,3,1,16925,2759.19,2594.26,364.397,180,4120),
(137629,33856,603,3,1,16925,2753.56,2584.3,364.397,180,4120);

UPDATE `gameobject_template` SET `type`=0, `faction`=0, `data1`=1845, `data4`=33914 WHERE `entry`=194264;
-- DELETE FROM `gameobject_scripts` WHERE `id`=55194;
UPDATE `gameobject` SET `rotation2`=0, `spawntimesecs`=180, `animprogress`=255 WHERE `id`=194264;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (66336, 67076, 67077, 67078);

-- END OF CLEANUP

###########
-- ULDUAR #
###########

-- Saronite Vapors scriptname
DELETE FROM `spell_script_names` WHERE `spell_id`=63322;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63322, 'spell_saronite_vapors');

-- Leviathan tower buffs
DELETE FROM `spell_script_names` WHERE `spell_id` IN (64482, 65075, 65076, 65077);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(64482, 'spell_leviathan_tower_buff'),
(65075, 'spell_leviathan_tower_buff'),
(65076, 'spell_leviathan_tower_buff'),
(65077, 'spell_leviathan_tower_buff');

-- Thorim berserk
DELETE FROM `spell_script_names` WHERE `spell_id`=62560;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62560, 'spell_thorim_berserk');

-- Thorim Charge orb targeting
DELETE FROM `spell_script_names` WHERE `spell_id`=62016;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62016, 'spell_thorim_charge_orb_targeting');

-- Ignis Flame_Jets target filtering
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62680, 63472);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(62680, 'spell_ignis_flame_jets'),
(63472, 'spell_ignis_flame_jets');

-- Ignis Activate Construct targeting
DELETE FROM `spell_script_names` WHERE `spell_id`=62488;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62488, 'spell_ignis_activate_construct');

-- Sara Psychosis
DELETE FROM `spell_script_names` WHERE `spell_id`=65301;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(65301, 'spell_sara_psychosis');

-- Thorim Lightning Destruction
DELETE FROM `spell_script_names` WHERE `spell_id`=62392;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62392, 'spell_thorim_lightning_destruction');

-- Thorim Runic Fortification
DELETE FROM `spell_script_names` WHERE `spell_id`=62942;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62942, 'spell_thorim_runic_fortification');

-- Scriptnames for Leviathan and vehicles
DELETE FROM `spell_script_names` WHERE `spell_id` IN (64979, 65044, 62907, 63847, 64677);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(64979, 'spell_anti_air_rocket'),
(65044, 'spell_leviathan_blaze_flames_effect'),
(62907, 'spell_freyas_ward_summon'),
(63847, 'spell_leviathan_flame_vents'),
(64677, 'spell_shield_generator');

DELETE FROM `spell_script_names` WHERE `spell_id`=64623;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(64623, 'spell_frost_bomb');

-- Renamed - the resulting effect is called "Pursued", not "Pursue"
UPDATE `spell_script_names` SET `ScriptName`='spell_pursued' WHERE `spell_id`=62374;

-- Creatures. I've renamed them, since they are no bosses, as named before
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_seat' WHERE `entry`=33114;
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_defense_turret' WHERE `entry`=33142;
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_defense_cannon' WHERE `entry`=33139;
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_overload_device' WHERE `entry`=33143;
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_safety_container' WHERE `entry`=33218;
UPDATE `creature_template` SET `ScriptName`='npc_liquid_pyrite' WHERE `entry`=33189;
UPDATE `creature_template` SET `ScriptName`='npc_freya_ward_of_life' WHERE `entry`=34275;
UPDATE `creature_template` SET `ScriptName`='npc_runeforged_sentry' WHERE `entry`=34234;
UPDATE `creature_template` SET `ScriptName`='npc_algalon_asteroid_target' WHERE `entry`=33104;

-- Mimirons Inferno Bunny - it should walk around.
DELETE FROM `waypoints` WHERE `entry`=33370;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(33370, 1, 266.689, -33.391, 409.99, 'Mimirons Inferno - Waypoint of dummy'),
(33370, 2, 379.158, -33.318, 409.81, 'Mimirons Inferno - Waypoint of dummy 2'),
(33370, 3, 266.611, -133.387, 409.81, 'Mimirons Inferno - Waypoint of dummy 3'),
(33370, 4, 158.411, -33.311, 409.81, 'Mimirons Inferno - Waypoint of dummy 4'),
(33370, 5, 266.699, 66.632, 409.81, 'Mimirons Inferno - Waypoint of dummy 5');

-- Areatrigger. These are the triggers at the repair stations (194261,194262)
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5369, 5423);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5369, 'at_RX_214_repair_o_matic_station');
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5423, 'at_RX_214_repair_o_matic_station');

-- Updates for achievement criterias... to avoid DISTINCT-selection during load
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_unbroken_25' WHERE `criteria_id`=10045 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_shutout_25' WHERE `criteria_id`=10055 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_three_car_garage_chopper_25' WHERE `criteria_id`=10049 AND type=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_three_car_garage_siege_25' WHERE `criteria_id`=10050 AND type=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_three_car_garage_demolisher_25' WHERE `criteria_id`=10051 AND type=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_orbital_bombardment_25' WHERE `criteria_id`=10059 AND type=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_orbital_devastation_25' WHERE `criteria_id`=10060 AND type=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_nuked_from_orbit_25' WHERE `criteria_id`=10061 AND type=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_orbit_uary_25' WHERE `criteria_id`=10219 AND type=11;

-- Game-objects: Replaced them if position is incorrect
DELETE FROM `gameobject` WHERE `id` IN (194261, 194262);
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(194261, 603, 3, 1, 130.553, -128.063, 409.804, 2.87979, 0, 0, 0, 1, 180, 255, 1),
(194261, 603, 3, 1, 138.516, 56.1078, 409.804, 2.87979, 0, 0, 0, 1, 180, 255, 1),
(194262, 603, 3, 1, 131.895, -128.264, 409.804, 0, 0, 0, 0, 1, 180, 255, 1),
(194262, 603, 3, 1, 139.857, 55.9064, 409.804, 0, 0, 0, 0, 1, 180, 255, 1);

-- Leviathan vehicles should not regen hp
UPDATE `creature_addon` SET `auras`=52455 WHERE `guid` IN (136093, 136094, 136239, 136240, 136268, 136269);

-- adding the lightning door behind leviathan
-- delete only the lightning door behind leviathan, not all
DELETE FROM `gameobject` WHERE `id`=194905 AND `position_x` > 200;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(194905, 603, 3, 1, 401.308, -13.8236, 409.524, 3.14159, 0, 0, -1, 0, 25, 0, 0);

-- XT002
-- Add additional target selection script, i.e. a SpellScript that is used aside the AuraScript that already got attached to
-- these spells.
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_xt002_gravity_bomb_aura_target';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(63024, 'spell_xt002_gravity_bomb_aura_target'), 
(64234, 'spell_xt002_gravity_bomb_aura_target');

-- make XT Deconstructors heart not regen hp
UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry` IN (33329, 33995);
UPDATE `vehicle_template_accessory` SET `minion`=0 WHERE `entry`=33293;

-- removing spell_xt002_heart_overload_periodic
DELETE FROM `spell_script_names` WHERE `spell_id`=62791;

-- Kologarn
-- Add script to arms.
UPDATE `creature_template` SET `ScriptName`='npc_kologarn_arm' WHERE `entry` IN (32933,32934);

-- Add achievement scripts to corresponding criterias
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10284, 10722, 10285, 10095, 10290, 10133);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(10284, 11, 0, 0, 'achievement_disarmed'),
(10284, 12, 0, 0, ''),
(10722, 11, 0, 0, 'achievement_disarmed_25'),
(10722, 12, 1, 0, ''),
(10285, 11, 0, 0, 'achievement_with_open_arms'),
(10285, 12, 0, 0, ''),
(10095, 11, 0, 0, 'achievement_with_open_arms_25'),
(10095, 12, 1, 0, ''),
(10290, 11, 0, 0, 'achievement_rubble_and_roll'),
(10290, 12, 0, 0, ''),
(10133, 11, 0, 0, 'achievement_rubble_and_roll_25'),
(10133, 12, 1, 0, '');

-- Assembly of Iron
DELETE FROM `spell_script_names` WHERE `spell_id` IN (61902, 61911, 63495, 61920);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(61902, 'spell_steelbreaker_electrical_charge'),
(61911, 'spell_steelbreaker_static_disruption'),
(63495, 'spell_steelbreaker_static_disruption'),
(61920, 'spell_supercharge');

-- spawning Prospector Doren
DELETE FROM `creature` WHERE `id`=33956;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(33956, 603, 3, 1, 0, 0, 1438.6, 114.639, 423.642, 2.11325, 120, 0, 0, 75600, 0, 0, 0, 0, 0);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10084,10087,10088,10418,10419,10089,10420,10421,10090,10422,10423,10091,10424,10425);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(10084, 11, 0, 0, 'achievement_i_choose_you'), -- achievement 2941
(10084, 12, 0, 0, ''),
(10087, 11, 0, 0, 'achievement_i_choose_you_25'), -- achievement 2944
(10087, 12, 1, 0, ''),
-- Check if the following works: Due to AchievmentCriteria.dbc, there are three criterias, but... there's only one check.
(10088, 11, 0, 0, 'achievement_but_i_am_on_your_side'), -- achievement 2945
(10088, 12, 0, 0, ''),
(10418, 11, 0, 0, 'achievement_but_i_am_on_your_side'), -- achievement 2945
(10418, 12, 0, 0, ''),
(10419, 11, 0, 0, 'achievement_but_i_am_on_your_side'), -- achievement 2945
(10419, 12, 0, 0, ''),
(10089, 11, 0, 0, 'achievement_but_i_am_on_your_side_25'), -- achievement 2946
(10089, 12, 1, 0, ''),
(10420, 11, 0, 0, 'achievement_but_i_am_on_your_side_25'), -- achievement 2946
(10420, 12, 1, 0, ''),
(10421, 11, 0, 0, 'achievement_but_i_am_on_your_side_25'), -- achievement 2946
(10421, 12, 1, 0, ''),
(10090, 11, 0, 0, 'achievement_cant_do_that_while_stunned'), -- achievement 2947
(10090, 12, 0, 0, ''),
(10422, 11, 0, 0, 'achievement_cant_do_that_while_stunned'), -- achievement 2947
(10422, 12, 0, 0, ''),
(10423, 11, 0, 0, 'achievement_cant_do_that_while_stunned'), -- achievement 2947
(10423, 12, 0, 0, ''),
(10091, 11, 0, 0, 'achievement_cant_do_that_while_stunned_25'), -- achievement 2948
(10091, 12, 1, 0, ''),
(10424, 11, 0, 0, 'achievement_cant_do_that_while_stunned_25'), -- achievement 2948
(10424, 12, 1, 0, ''),
(10425, 11, 0, 0, 'achievement_cant_do_that_while_stunned_25'), -- achievement 2948
(10425, 12, 1, 0, '');

-- Hodir
-- Achievement: Stayin buffed all winter.
-- Moved check to script.
-- 10 man handling.
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10223, 10240, 10241);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(10223, 11, 0, 0, 'achievement_staying_buffed_all_winter'), 
(10223, 12, 0, 0, ''), 
(10240, 11, 0, 0, 'achievement_staying_buffed_all_winter'), 
(10240, 12, 0, 0, ''), 
(10241, 11, 0, 0, 'achievement_staying_buffed_all_winter'), 
(10241, 12, 0, 0, '');

-- 25 man handling.
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10229, 10238, 10239);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(10229, 12, 1, 0, ''), 
(10229, 11, 0, 0, 'achievement_staying_buffed_all_winter_25'), 
(10238, 12, 1, 0, ''), 
(10238, 11, 0, 0, 'achievement_staying_buffed_all_winter_25'), 
(10239, 12, 1, 0, ''), 
(10239, 11, 0, 0, 'achievement_staying_buffed_all_winter_25');

-- adding hodir a weapon in 25m mode
UPDATE `creature` SET `equipment_id`=1842 WHERE `id`=32845;

-- Thorim
UPDATE `creature_template` SET `ScriptName`='boss_thorim' WHERE `entry`=32865;
UPDATE `creature` SET `equipment_id`=1844 WHERE `id`=33147;
-- Thunder orbs are spawned via boss script
DELETE FROM `creature` WHERE `id`=33378;
-- Lightning orb scriptname and waypoints
UPDATE `creature_template` SET `ScriptName`='npc_lightning_orb' WHERE `entry`=33138;
DELETE FROM waypoint_data WHERE id = 33138;
INSERT INTO waypoint_data (id, point, position_x, position_y, position_z) VALUES
(33138, 1, 2227.6, -263.7, 412.2),
(33138, 2, 2227.6, -432.6, 412.2),
(33138, 3, 2199.3, -433.7, 420),
(33138, 4, 2167.5 ,-440.2, 438.5),
(33138, 5, 2134.8 ,-440.2, 438.5),
(33138, 6, 2134.8 ,-303.4, 438.5);

-- update faction of Dark Rune Acolyte so hes correctly affected by Berserk
UPDATE `creature_template` SET `faction_A`=1692, `faction_H`=1692 WHERE `entry` IN (32886, 33159);

-- Controller
UPDATE `creature_template` SET `ScriptName`='npc_thorim_controller' WHERE `entry`=32879;
DELETE FROM `creature` WHERE `id`=32879;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(32879, 603, 3, 1, 0, 0, 2134.77, -262.307, 420.694, 1.3439, 604800, 0, 0, 12600, 0, 0, 0, 0, 0);

-- Adds
-- Link spell "Stormhammer" to "Deafening Thunder"
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62042;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(62042, 62470, 1, 'Stormhammer => Deafening Thunder');

-- Register spell-script for target-selection.
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_stormhammer_targeting';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62042, 'spell_stormhammer_targeting');

-- Charge Orb - implicit targeting only a special npc.
DELETE FROM `conditions` WHERE `SourceEntry`=62016;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 62016, 31, 3, 33378, 'Lightning Shock');

-- Pre-phase adds: Register scripts.
UPDATE `creature_template` SET `ScriptName`='npc_thorim_pre_phase_add' WHERE `entry` IN (32885,32883,32908,32907,32882,32886);
UPDATE `creature` SET `equipment_id`=1847 WHERE `id`=33152;
UPDATE `creature` SET `equipment_id`=1849 WHERE `id` IN (32885,33153);
UPDATE `creature` SET `equipment_id`=1850 WHERE `id` IN (32908,33151);
UPDATE `creature` SET `equipment_id`=1852 WHERE `id`=33150;
DELETE FROM `creature` WHERE `id` IN (32882,32908,32885,32886,32907,32883); -- NPCs are spawned by script.

-- Thorim Mini bosses : Runic Colossus, Ancient Rune Giant, Sif
UPDATE `creature_template` SET `mechanic_immune_mask`=1|2|4|8|16|64|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912, `flags_extra`=1, `ScriptName`='npc_runic_colossus' WHERE `entry`=32872;
UPDATE `creature_template` SET `mechanic_immune_mask`= 1|2|4|8|16|64|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912, `flags_extra`=1, `ScriptName`='npc_ancient_rune_giant' WHERE `entry`=32873;
UPDATE `creature_template` SET `mechanic_immune_mask`= 1|2|4|8|16|64|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912, `flags_extra`=1, `ScriptName`='npc_sif' WHERE `entry`=33196;

-- updating giant and Sif immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=1|2|4|8|16|64|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN (33149, 33148, 33196);
UPDATE `creature_template` SET `ScriptName`='npc_thorim_arena_phase_add' WHERE `entry` IN (32876, 32904, 32878, 32877, 32874, 32875, 33110);

DELETE FROM `creature_addon` WHERE `guid` IN (136059, 136816);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(136059, 0, 0, 0, 1, 0, '40775'),
(136816, 0, 0, 0, 1, 0, '40775');
DELETE FROM `creature` WHERE `id` IN (33140, 33141); -- Left and right runic smash bunnies are spawned in scripts
UPDATE `creature_template` SET `ScriptName`='npc_runic_smash' WHERE `entry` IN (33140, 33141);

-- adding Thorim Lever ScriptName
-- TODO: find out why entry 194264 doesnt work
UPDATE `gameobject_template` SET `ScriptName`='go_thorim_lever' WHERE `entry`=194264;
UPDATE `gameobject_template` SET `size`=3, `data2`=6000, `flags`=16|32, `ScriptName`='go_thorim_lever' WHERE `entry`=179148;
UPDATE `gameobject` SET `id`=179148 WHERE `guid`=55194;

-- Freya
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62207, 63006);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62207, 'spell_elder_brightleaf_unstable_sun_beam'),
(63006, 'spell_aggregation_pheromones_targeting');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (62968, 65761, 62713);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62968, 'spell_elder_brightleaf_essence_targeting'),
(65761, 'spell_elder_brightleaf_essence_targeting'),
(62713, 'spell_elder_ironbranch_essence_targeting');

-- Achievement stuff - again: due to DISTINCT(ScriptName) in ObjectMgr
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_getting_back_to_nature_25' WHERE `criteria_id`=10758 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_knock_on_wood_25' WHERE `criteria_id`=10459 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_knock_knock_on_wood_25' WHERE `criteria_id`=10460 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_knock_knock_knock_on_wood_25' WHERE `criteria_id`=10461 AND `type`=11;

-- Update spawndist for Guardian Of Life.
UPDATE `creature` SET `spawndist`=50 WHERE `id` IN (33528, 33733);

-- Mimiron
-- @DorianGrey
-- SQL-updates related to Mimiron-encounter, Ulduar.
-- While I've changed many parts of their encounter-script, this SQL-update is almost completely (apart from the achievement-stuff) 
-- adopted from https://github.com/darkman1983/TrinityCore , so all credits should go to them.

-- First gameobject for the tram from inner sanctuary -> Mimiron.
UPDATE `gameobject_template` SET `flags`=32, `data2`=3000, `ScriptName`='go_call_tram' WHERE `entry` IN (194914, 194912, 194437);
DELETE FROM `gameobject` WHERE id=194437;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(194437, 603, 3, 1, 2306.87, 274.237, 424.288, 1.52255, 0, 0, 0.689847, 0.723956, 300, 0, 1);

-- Mimirion
UPDATE `creature_template` SET `ScriptName`='boss_mimiron' WHERE `entry`=33350;
-- Leviathan MKII
UPDATE `creature_template` SET `vehicleid`=370, `ScriptName`='boss_leviathan_mk' WHERE `entry`=33432;
UPDATE `creature_template` SET `vehicleid`=370, `flags_extra`=`flags_extra` |1 WHERE `entry`=34106;
UPDATE `creature` SET `spawntimesecs`=604800 WHERE `id`=33236;
-- Leviathan MKII Turret
UPDATE `creature_template` SET `ScriptName`='boss_leviathan_mk_turret' WHERE `entry`=34071;
DELETE FROM `vehicle_template_accessory` WHERE `entry`=33432;
INSERT INTO `vehicle_template_accessory` VALUES
(33432, 34071, 3, 1, 'Leviathan Mk II turret', 8, 0);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=33432;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(33432, 46598, 1, 0);
-- Leviathan skills and skill-helper
UPDATE `creature_template` SET `ScriptName`='npc_proximity_mine' WHERE `entry`=34362;
UPDATE `creature_model_info` SET `bounding_radius`=0.5, `combat_reach`=7 WHERE `modelid` IN (28831, 28841, 28979);

-- VX-001
UPDATE `creature_template` SET `flags_extra`=`flags_extra` |1, `vehicleid`=371, `ScriptName`='boss_vx_001' WHERE `entry`=33651;
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `flags_extra`=`flags_extra` |1 WHERE `entry`=34108;
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35 WHERE `entry`=34050;
UPDATE `creature_template` SET `unit_flags`=4|512|131072|33554432, `flags_extra`=`flags_extra` |2 WHERE `entry`=34211;
UPDATE `creature_template` SET `ScriptName`='npc_rocket_strike' WHERE `entry`=34047;

-- Aerial Command Unit
UPDATE `creature_template` SET `flags_extra`=`flags_extra` |1, `ScriptName`='boss_aerial_unit', `vehicleid`=372 WHERE `entry`=33670;
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `flags_extra`=1 WHERE `entry`=34109;
UPDATE `creature_template` SET `ScriptName`='npc_magnetic_core' WHERE `entry`=34068;
UPDATE `creature_template` SET `ScriptName`='npc_assault_bot' WHERE `entry`=34057;
UPDATE `creature_template` SET `difficulty_entry_1`=34148, `ScriptName`='npc_emergency_bot' WHERE `entry`=34147;

-- HardMode
UPDATE `gameobject_template` SET `flags`=`flags` &~16, `ScriptName`='go_mimiron_hard_mode_activator' WHERE `entry`=194739;
UPDATE `creature_template` SET `difficulty_entry_1`=34361, `ScriptName`='npc_frost_bomb' WHERE `entry`=34149;
UPDATE `creature_template` SET `speed_walk`=0.15, `speed_run`=0.15, `ScriptName`='npc_mimiron_flame_trigger' WHERE `entry` =34363;
UPDATE `creature_template` SET `ScriptName`='npc_mimiron_flame_spread' WHERE `entry`=34121;
UPDATE `creature_template` SET `ScriptName`='npc_mimiron_bomb_bot' WHERE `entry`=33836;
UPDATE `creature_template` SET `ScriptName`='npc_boomer_xp' WHERE `entry`=34192;

-- Cleaning up Leviathan Mk II
DELETE FROM `creature` WHERE `id`=34071;
UPDATE `creature_template` SET `unit_flags`=`unit_flags` |2|33554432 WHERE `entry`=34143;

-- Ignis Iron Construct are spawned via scripts
DELETE FROM `creature` WHERE `id`=33121;

-- Auriaya Sanctum Sentries are spawned via scripts
DELETE FROM `creature` WHERE `id`=34014;
-- correct damage of Sanctum sentries and Feral Defender
UPDATE `creature_template` SET `dmg_multiplier` = 7.5 WHERE `entry` IN (34035, 34014);
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` IN (34171, 34166);

-- Thorim tunnel adds are spawned via scripts
DELETE FROM `creature` WHERE `id` IN (33110, 32874, 32875);

-- Algalons Celestial Planetarium Access is spawned via core
DELETE FROM `gameobject` WHERE `id`=194752;

-- correcting quest chain leading to Algalon
UPDATE `quest_template` SET `PrevQuestId`=13607, `NextQuestId`=13614, `ExclusiveGroup`=-13609 WHERE `Id` IN (13606, 13609, 13610, 13611);

-- Achievement "Firefighter" (3180 / 3189)
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10450, 10463);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(10450, 12, 0, 0, ''), 
(10450, 11, 0, 0, 'achievement_firefighter'), 
(10463, 12, 1, 0, ''), 
(10463, 11, 0, 0, 'achievement_firefighter_25');

-- Spell stuff
DELETE FROM `spell_script_names` WHERE `spell_id` IN (63382, 63016, 63027);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63382, 'spell_rapid_burst');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63027, 'spell_proximity_mines');

-- General Vezax
-- Register spell-scripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62692, 63276, 63278);
INSERT INTO `spell_script_names` VALUES 
(62692,'spell_aura_of_despair_aura'),
(63276,'spell_mark_of_the_faceless'),
(63278,'spell_mark_of_the_faceless_drain');

-- Shadow crash auras
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=63277;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(63277, 65269, 2, 'Shadow Crash auras');

-- Update saronite animus entry.
UPDATE `creature_template` SET `flags_extra`=`flags_extra` |1 WHERE `entry`=33524;

-- Achievements "I love the smell of saronite in the morning" and "Shadowdodger"
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10451, 10462, 10173, 10306);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(10451, 11, 0, 0, 'achievement_i_love_the_smell_of_saronite_in_the_morning'), 
(10451, 12, 0, 0, ''), 
(10462, 11, 0, 0, 'achievement_i_love_the_smell_of_saronite_in_the_morning_25'), 
(10462, 12, 1, 0, ''),
(10173, 11, 0, 0, 'achievement_shadowdodger'), 
(10173, 12, 0, 0, ''), 
(10306, 11, 0, 0, 'achievement_shadowdodger_25'), 
(10306, 12, 1, 0, '');

-- YoggSaron
-- Updates for the various NPCs in Yogg-Saron encounter.
UPDATE `creature_template` SET `ScriptName`='npc_yogg_saron_encounter_controller' WHERE `entry`=29224;
DELETE FROM `creature` WHERE `id`=29224;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(29224, 603, 3, 1, 0, 0, 1980.28, -25.5868, 329.397, 2.91365, 300, 0, 0, 7841, 0, 0, 0, 0, 0);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=33134;
UPDATE `creature_template` SET `ScriptName`='npc_ominous_cloud' WHERE `entry`=33292;
UPDATE `creature_template` SET `ScriptName`='npc_guardian_of_yogg_saron' WHERE `entry`=33136;
UPDATE `creature_template` SET `ScriptName`='npc_yogg_saron_tentacle' WHERE `entry` IN (33966,33985,33983);
UPDATE `creature_template` SET `ScriptName`='npc_descend_into_madness' WHERE `entry`=34072;
UPDATE `creature_template` SET `ScriptName`='boss_brain_of_yogg_saron' WHERE `entry`=33890;
UPDATE `creature_template` SET `ScriptName`='boss_yogg_saron' WHERE `entry`=33288;
UPDATE `creature_template` SET `ScriptName`='npc_influence_tentacle' WHERE `entry` IN (33716,33720,33719,33717,33433,33567);
UPDATE `creature_template` SET `ScriptName`='boss_sara' WHERE `entry`=33134;
UPDATE `creature_template` SET `ScriptName`='npc_immortal_guardian' WHERE `entry`=33988;
UPDATE `creature_template` SET `ScriptName`='npc_support_keeper' WHERE `entry` IN (33410,33411,33412,33413);
UPDATE `creature_template` SET `ScriptName`='npc_sanity_well' WHERE `entry`=33991;
UPDATE `creature_template` SET `ScriptName`='npc_death_orb' WHERE `entry`=33882;
UPDATE `creature_template` SET `ScriptName`='npc_death_ray' WHERE `entry`=33881;
UPDATE `creature_template` SET `ScriptName`='npc_laughting_skull' WHERE entry=33990;

-- Keeper helpers
UPDATE `creature_template` SET `npcflag`=`npcflag`|1, `ScriptName`='npc_keeper_help' WHERE `entry` IN (33241,33244,33242,33213);
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `difficulty_entry_1` = 33959 WHERE `entry`=33943;
UPDATE `gameobject_template` SET `ScriptName`='go_flee_to_surface' WHERE `entry`=194625;
UPDATE `item_template` SET `ScriptName`='item_unbound_fragments_of_valanyr' WHERE `entry`=45896;
UPDATE `creature_template` SET `RegenHealth`=1 WHERE `entry` IN (33134, 34332, 33890, 33954); -- No health regeneration for Sara and Brain of Yogg-saron

DELETE FROM `gameobject` WHERE `id`=194625;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `spawntimesecs`, `animprogress`, `state`) VALUES 
(194625, 603, 3, 1, 2001.4, -59.66, 245.07, 60, 100, 1),
(194625, 603, 3, 1, 1941.61, -25.88, 244.98, 60, 100, 1),
(194625, 603, 3, 1, 2001.18, 9.409, 245.24, 60, 100, 1);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (64466,64139,64143,64133,63120,64174,64172,63802,64164,64168,62670,62671,62702,62650);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(64466,'spell_empowering_shadows'),    -- Heal Trigger for Empowering Shadows
(64139,'spell_summon_tentacle_position'),  -- Correct Summon Position of Tentacle
(64143,'spell_summon_tentacle_position'),
(64133,'spell_summon_tentacle_position'),
(63120,'spell_insane_death_effekt'),   -- Insane Death trigger on Remove
(64174,'spell_hodir_protective_gaze'),   -- Hodir Secound Aura Script
(64172,'spell_titanic_storm_targeting'),  -- Needed for Titanic Storm, Script for Target have Weakened Aura
(63802,'spell_brain_link_periodic_dummy'),  -- Trigger Effekt on Near Player with Brain Link
(64164,'spell_lunatic_gaze_targeting'),
(64168,'spell_lunatic_gaze_targeting'),   -- Script for Target Faces Caster
(62670,'spell_keeper_support_aura_targeting'), -- Auras shouldn't hit other friendly NPCs
(62671,'spell_keeper_support_aura_targeting'),
(62702,'spell_keeper_support_aura_targeting'),
(62650,'spell_keeper_support_aura_targeting');

DELETE FROM `conditions` WHERE `SourceEntry` IN (64184, 63882, 63886, 64172, 64465, 65719, 62714);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES 
(13, 0, 64184, 31, 3, 33288, 'Effect on YoggSaron'), -- Create Val'anyr on Yogg-Saron
(13, 0, 63882, 31, 3, 33882, 'Effect on Death Orb'), -- Deathray Effect on Death Orb
(13, 0, 63886, 31, 3, 33882, 'Effect on Death Orb'),
(13, 0, 64172, 31, 3, 33988, 'Effect only for Immortal Guardians'), -- Condition because NPCs need this else no hit
(13, 0, 64465, 31, 3, 33988, 'Effect only for Immortal Guardians'),
(13, 1, 65719, 31, 3, 33134, 'Spell should hit only Sara'),		-- Shadow Nova
(13, 1, 62714, 31, 3, 33136, 'Effect should hit only Guardians'),
(13, 2, 62714, 31, 4, 0, 'Effect should hit only Players');

-- Various things
-- Update mechanic immunity flags.
UPDATE `creature_template` SET `mechanic_immune_mask`=1|2|4|8|16|32|64|256|512|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912, `flags_extra`=1 WHERE `entry` IN (
33113, 34003, -- Flame Leviathan
33118, 33190, -- Ignis the Furnace Master
33186, 33724, -- Razorscale
33293, 33885, -- XT002
32867, 33693, -- Steelbreaker
32927, 33692, -- Runemaster Molgeim
32930, 33909, -- Kologarn
32906, 33360, -- Freya
32845, 32846, -- Hodir
33350,        -- Mimiron
33432, 34106, -- Leviathan MK II
34071,        -- Leviathan MK II turret
33651, 34108, -- VX-001
33670, 34109, -- Aerial Unit
32865, 33147, -- Thorim
33271, 33449, -- General Vezax
33524, 34152, -- Saronite Animus
33288, 33955, -- Yogg-Saron
33134, 34332, -- Sara
33890, 33954  -- Brain of Yogg-Saron
);

-- General Vezax shouldnt be immune to interrupt
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask` & ~33554432 WHERE `entry` IN (33271, 33449);

-- Stormcaller Brundir (stun and interrupt immunities are handled in scripts)
UPDATE `creature_template` SET `mechanic_immune_mask`=1|2|4|8|16|32|64|256|512|4096|8192|65536|131072|524288|4194304|8388608|67108864|536870912, `flags_extra`=1 WHERE `entry` IN (32857, 33694);

-- assigning 25m version of Brain of Yogg-Saron to the normal version
UPDATE `creature_template` SET `difficulty_entry_1`=33954 WHERE `entry`=33890;

-- Auriaya should be interruptible, due to Sentinel Blast
UPDATE `creature_template` SET `mechanic_immune_mask`=1|2|4|8|16|32|64|256|512|2048|4096|8192|65536|131072|524288|4194304|8388608|67108864|536870912 WHERE `entry` IN (33515, 34175);

-- Ulduar Trash
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_steelforged_defender' WHERE `entry`=33236;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_ironwork_cannon' WHERE `entry`=33264;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_corrupted_servitor' WHERE `entry`=33354;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_misguided_nymph' WHERE `entry`=33355;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_guardian_lasher' WHERE `entry`=33430;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_forest_swarmer' WHERE `entry`=33431;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_mangrove_ent' WHERE `entry`=33525;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_ironroot_lasher' WHERE `entry`=33526;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_natures_blade' WHERE `entry`=33527;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_guardian_of_life' WHERE `entry`=33528;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_storm_tempered_keeper' WHERE `entry` IN (33699, 33722);
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_charged_sphere' WHERE `entry`=33715;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_faceless_horror' WHERE `entry`=33772; 
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_twilight_adherent' WHERE `entry`=33818; 
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_twilight_frost_mage' WHERE `entry`=33819;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_twilight_pyromancer' WHERE `entry`=33820;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_enslaved_fire_elemental' WHERE `entry`=33838;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_twilight_guardian' WHERE `entry`=33822;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_twilight_slayer' WHERE `entry`=33823;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_twilight_shadowblade' WHERE `entry`=33824;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_molten_colossus' WHERE `entry`=34069;

DELETE FROM `spell_script_names` WHERE `spell_id`=63059;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63059, 'spell_pollinate');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62317 AND `spell_effect`=57807 AND `type`=1;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(62317, 57807, 1, 'Twilight Guardian - Link Devastate to Sunder Armor');

-- Clockwork mechanic
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~(262144|33554432) WHERE `entry`=34184;

-- Auriaya
DELETE FROM `spell_group` WHERE `id`=64381;
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=64381;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
(64381, 64381);
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(64381, 1);

-- CUSTOM
-- Superheated winds invisibility
UPDATE `creature_template` SET `flags_extra`=`flags_extra` |128 WHERE `entry`=34189;

-- Magma Rager
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34086;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34086;
INSERT INTO `smart_scripts` (`entryorguid`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `target_type`, `comment`) VALUES 
(34086, 6, 5000, 10000, 5000, 10000, 11, 5, 'Magma Rager - Cast Fire Blast');

-- Forge Construct
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34085;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34085;
INSERT INTO `smart_scripts` (`entryorguid`, `event_type`, `event_flags`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34085, 4, 6, 11, 64719, 2, 'Forge Construct - Cast Charge');
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34085, 1, 0, 2, 5000, 15000, 5000, 15000, 11, 64720, 2, 'Forge Construct - Cast Flame Emission'),
(34085, 2, 0, 4, 5000, 15000, 5000, 15000, 11, 64721, 2, 'Forge Construct - Cast Flame Emission');

-- making some objects be spawned in all versions of Ulduar
UPDATE `gameobject` SET `spawnMask`=3 WHERE `guid` IN (35446, 35393, 35413, 35417, 55630, 34041, 54961, 54971, 55043, 55194, 35381, 35462, 42047, 42076, 42520, 42543, 42649, 42868, 42916, 42918, 42919, 42958, 43112, 43115, 44885, 45021, 45090, 45094, 45096, 45097, 45116, 4784597, 4784598,
45175, 45209, 48905, 50363, 55002, 55692, 55702, 127, 55734, 55862, 55926, 55965, 34155, 281, 35467, 35497, 35516, 35517, 42960, 43113, 43114, 44883, 34057, 45225, 45229, 45230, 45500, 56130, 56244, 56245, 56295, 56296, 56301, 56312, 56351, 56359, 56372, 56411, 54995, 55078, 56422, 56424, 56426, 
289, 35524, 56107, 56125, 42867, 42879, 55974, 55647, 285) OR `id` IN (194569, 189973, 190170, 190171, 191019, 194905, 194907) AND `map`=603;

-- enlarging hitbox of bosses
UPDATE `creature_model_info` SET `bounding_radius`=1.085, `combat_reach`=10.5 WHERE `modelid` IN (28787, 29185, 28611, 28324, 28344, 28381, 28651, 28777, 28548, 28817);

-- adding weapons to Expedition Trappers and Expedition Engineers
UPDATE `creature` SET `equipment_id`=1762 WHERE `id`=34257;
UPDATE `creature` SET `equipment_id`=361 WHERE `id`=34256;

-- updating Razorscale Controller positions
DELETE FROM `creature` WHERE `guid` BETWEEN 48304 AND 48310;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`) VALUES
(48304, 33233, 603, 2, 560.133, -143.035, 393.823),
(48306, 33233, 603, 3, 588.673, -136.835, 391.517),
(48307, 33233, 603, 2, 603.931, -142.889, 391.517),
(48308, 33233, 603, 3, 572.654, -139.375, 391.517);

-- delete razorscale broken harpoons, they are spawned via scripts
DELETE FROM `gameobject` WHERE `id`=194565;

-- small Emote to Say correction
-- UPDATE `script_texts` SET `type`=3 WHERE `entry`=-1603266;

-- XD-175 Compactobot
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34271;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34271;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `target_param1`, `target_param2`, `comment`) VALUES
(34271, 0, 0, 2, 10000, 20000, 10000, 20000, 11, 65073, 17, 10, 40, 'XD-175 Compactobot - Cast Trash Compactor'),
(34271, 1, 0, 4, 10000, 20000, 10000, 20000, 11, 65106, 17, 10, 40, 'XD-175 Compactobot - Cast Trash Compactor');

-- Parts Recovery Technician
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34267;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34267;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34267, 0, 0, 6, 10000, 20000, 10000, 20000, 11, 65071, 2, 'Parts Recovery Technician - Cast Mechano Kick'),
(34267, 1, 0, 6, 5000, 10000, 20000, 25000, 11, 65070, 1, 'Parts Recovery Technician - Cast Defense Matrix');

-- XB-488 Disposalbot
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34273;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34273;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34273, 0, 0, 2, 2000, 5000, 5000, 7000, 11, 65080, 2, 'XB-488 Disposalbot - Cast Cut Scrap Metal'),
(34273, 1, 0, 4, 2000, 5000, 5000, 7000, 11, 65104, 2, 'XB-488 Disposalbot - Cast Cut Scrap Metal'),
(34273, 2, 2, 6, 1, 15, 0, 0, 11, 65084, 1, 'XB-488 Disposalbot - Cast Self Destruct');

-- TODO: XR-949 Salvagebot

-- Lightning Charged Iron Dwarf
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34199;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34199;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34199, 0, 4, 2, 11, 64889, 1, 'Lightning Charged Iron Dwarf - Cast Lightning Charged'),
(34199, 1, 4, 4, 11, 64975, 1, 'Lightning Charged Iron Dwarf - Cast Lightning Charged');

-- Hardened Iron Golem
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34190;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34190;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34190, 0, 0, 2, 5000, 10000, 15000, 20000, 11, 64874, 2, 'Hardened Iron Golem - Cast Rune Punch'),
(34190, 1, 0, 4, 5000, 10000, 15000, 20000, 11, 64967, 2, 'Hardened Iron Golem - Cast Rune Punch'),
(34190, 2, 0, 6, 5000, 10000, 15000, 20000, 11, 64877, 1, 'Hardened Iron Golem - Cast Harden Fists');

-- Iron Mender
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34198;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34198;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34198, 0, 0, 2, 5000, 10000, 10000, 20000, 11, 64918, 2, 'Iron Mender - Cast Electro Shock'),
(34198, 1, 0, 4, 5000, 10000, 10000, 20000, 11, 64971, 2, 'Iron Mender - Cast Electro Shock'),
(34198, 2, 0, 2, 5000, 10000, 20000, 25000, 11, 64903, 5, 'Iron Mender - Cast Fuse Lightning'),
(34198, 3, 0, 4, 5000, 10000, 20000, 25000, 11, 64970, 5, 'Iron Mender - Cast Fuse Lightning'),
(34198, 4, 14, 2, 20000, 40, 15000, 20000, 11, 64897, 7, 'Iron Mender - Cast Fuse Metal'),
(34198, 5, 14, 4, 50000, 40, 15000, 20000, 11, 64968, 7, 'Iron Mender - Cast Fuse Metal');

-- Rune Etched Sentry
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34196;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34196;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34196, 0, 0, 2, 5000, 7000, 10000, 20000, 11, 64852, 5, 'Rune Etched Sentry - Cast Flaming Rune'),
(34196, 1, 0, 2, 5000, 10000, 10000, 15000, 11, 64870, 2, 'Rune Etched Sentry - Cast Lava Burst'),
(34196, 2, 0, 4, 5000, 10000, 10000, 15000, 11, 64991, 2, 'Rune Etched Sentry - Cast Lava Burst'),
(34196, 3, 0, 2, 7000, 10000, 10000, 15000, 11, 64847, 2, 'Rune Etched Sentry - Cast Runed Flame Jets'),
(34196, 4, 0, 4, 7000, 10000, 10000, 15000, 11, 64988, 2, 'Rune Etched Sentry - Cast Runed Flame Jets');

-- Chamber Overseer (TODO: Displacement Device)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34197;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34197;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `target_param1`, `target_param2`, `comment`) VALUES
(34197, 0, 0, 2, 10000, 15000, 10000, 20000, 11, 64820, 17, 10, 80, 'Chamber Overseer - Cast Devastating Leap'),
(34197, 1, 0, 4, 10000, 15000, 10000, 15000, 11, 64943, 17, 10, 80, 'Chamber Overseer - Cast Devastating Leap'),
(34197, 2, 0, 2, 5000, 10000, 10000, 15000, 11, 64825, 2, 0, 0, 'Chamber Overseer - Cast Staggering Roar'),
(34197, 3, 0, 4, 5000, 10000, 10000, 15000, 11, 64944, 2, 0, 0, 'Chamber Overseer - Cast Staggering Roar');

-- Dark Rune Ravager
UPDATE `creature_template` SET `ScriptName`='', `AIName`='SmartAI' WHERE `entry`=33755;
DELETE FROM `smart_scripts` WHERE `entryorguid`=33755;
INSERT INTO `smart_scripts` (`entryorguid`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(33755, 0, 6, 2000, 2000, 2000, 2000, 11, 63615, 2, 'Dark Rune Ravager - Cast Ravage Armor');

-- Dark Rune Thunderer
UPDATE `creature_template` SET `ScriptName`='', `AIName`='SmartAI' WHERE `entry`=33754;
DELETE FROM `smart_scripts` WHERE `entryorguid`=33754;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(33754, 0, 0, 2, 3000, 3000, 2000, 3000, 11, 63612, 2, 'Dark Rune Thunderer - Cast Lightning Brand'),
(33754, 1, 0, 4, 3000, 3000, 2000, 3000, 11, 63673, 2, 'Dark Rune Thunderer - Cast Lightning Brand');

-- Arachnopod Destroyer
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34183;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34183;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34183, 0, 4, 6, 0, 0, 0, 0, 11, 64779, 2, 'Arachnopod Destroyer - Cast Charged Leap'),
(34183, 1, 0, 6, 5000, 10000, 10000, 15000, 11, 64717, 2, 'Arachnopod Destroyer - Cast Flame Spray'),
(34183, 2, 0, 6, 10000, 20000, 20000, 30000, 11, 64776, 2, 'Arachnopod Destroyer - Cast Machine Gun');

-- Clockwork Mechanic
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34184;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34184;
INSERT INTO `smart_scripts` (`entryorguid`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34184, 2, 6, 0, 50, 20000, 30000, 11, 64966, 1, 'Clockwork Mechanic - Cast Ice Turret');

-- Ice Turret (spawned by Clockwork Mechanics)
UPDATE `creature_template` SET `unit_flags`=`unit_flags` |4, `AIName`='SmartAI' WHERE `entry`=34224;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34224;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34224, 0, 0, 2, 2000, 5000, 15000, 30000, 11, 66346, 1, 'Ice Turret - Cast Ice Nova'),
(34224, 1, 0, 4, 2000, 5000, 15000, 30000, 11, 64919, 1, 'Ice Turret - Cast ce Nova');

-- Champion of Hodir
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34133;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34133;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34133, 0, 0, 2, 10000, 15000, 10000, 15000, 11, 64639, 1, 'Champion of Hodir - Cast Stomp'),
(34133, 1, 0, 4, 10000, 15000, 10000, 15000, 11, 64652, 1, 'Champion of Hodir - Cast Stomp'),
(34133, 2, 0, 6, 15000, 20000, 15000, 20000, 11, 64649, 2, 'Champion of Hodir - Cast Freezing Breath');

-- Winter Jormungar
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34137;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34137;
INSERT INTO `smart_scripts` (`entryorguid`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34137, 0, 6, 5000, 10000, 5000, 10000, 11, 64638, 2, 'Winter Jormungar - Cast Acidic Bite');

-- Winter Revenant
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34134;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34134;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34134, 0, 0, 2, 5000, 15000, 10000, 15000, 11, 64642, 1, 'Winter Revenant - Cast Blizzard'),
(34134, 1, 0, 4, 5000, 15000, 10000, 15000, 11, 64653, 1, 'Winter Revenant - Cast Blizzard'),
(34134, 2, 4, 6, 0, 0, 0, 0, 11, 64644, 1, 'Winter Revenant - Cast Shield of the Winter Revenant'),
(34134, 3, 0, 6, 15000, 20000, 15000, 20000, 11, 64643, 1, 'Winter Revenant - Cast Whirling Strike');

-- Winter Rumbler
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34135;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34135;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `comment`) VALUES
(34135, 0, 0, 2, 5000, 10000, 10000, 15000, 11, 64645, 2, 'Winter Rumbler - Cast Cone of Cold'),
(34135, 1, 0, 4, 5000, 10000, 10000, 15000, 11, 64655, 2, 'Winter Rumbler - Cast Cone of Cold'),
(34135, 2, 0, 2, 10000, 20000, 10000, 20000, 11, 64647, 6, 'Winter Rumbler - Cast Snow Blindness'),
(34135, 3, 0, 4, 10000, 20000, 10000, 20000, 11, 64654, 6, 'Winter Rumbler - Cast Snow Blindness');

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (34153, 33395);

-- Thorims trap bunny shouldnt be able to move
UPDATE `creature_template` SET `unit_flags`=`unit_flags` |4 WHERE `entry`=33054;

-- spawning Keeper images
DELETE FROM `creature` WHERE `id` IN (33241, 33242, 33244, 33213);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `curhealth`) VALUES
(33241, 603, 3, 1939.06, 42.3925, 411.356, 5.25215, 14433075),
(33213, 603, 3, 1939.64, -90.9194, 411.356, 0.940322, 14433075),
(33244, 603, 3, 2037.32, 25.9017, 411.358, 3.81488, 14433075),
(33242, 603, 3, 2037.03, -73.8742, 411.355, 2.35011, 14433075);

-- Enslaved Fire Elementals and Ominous clouds are spawned by scripts
DELETE FROM `creature` WHERE `id`=33838;

-- correcting Junk bot template
UPDATE `creature_template` SET `difficulty_entry_1`=34114 WHERE `entry`=33855;
UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16 WHERE `entry`=34114;

-- correcting Enslaved Fire Elemental versions
UPDATE `creature_template` SET `difficulty_entry_1`=33839 WHERE `entry`=33838;
UPDATE `creature_template` SET `minlevel`= 82, `maxlevel`=82, `faction_A`=16, `faction_H`=16 WHERE `entry`=33839;

-- correcting some Ulduar loot
UPDATE `creature_loot_template` SET `lootmode`=1 WHERE `entry` IN (33885, 33293, 33449, 33271) AND `lootmode`=3;

-- Ulduar Texts
-- Flame Leviathan
-- DELETE FROM `script_texts` WHERE `npc_entry`=33113;
DELETE FROM `creature_text` WHERE `entry`=33113;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33113, 0, 0, 'Hostile entities detected. Threat assessment protocol active. Primary target engaged. Time minus thirty seconds to re-evaluation.', 14, 0, 0, 0, 0, 15506, 'Flame Leviathan SAY_AGGRO'),
(33113, 1, 0, 'Threat assessment routine modified. Current target threat level: zero. Acquiring new target.', 14, 0, 0, 0, 0, 15521, 'Flame Leviathan SAY_SLAY'),
(33113, 2, 0, 'Total systems failure. Defense protocols breached. Leviathan Unit shutting down.', 14, 0, 0, 0, 0, 15520, 'Flame Leviathan SAY_DEATH'),
(33113, 3, 0, 'Threat re-evaluated. Target assessment complete. Changing course.', 14, 0, 0, 0, 0, 15507, 'Flame Leviathan SAY_TARGET_1'),
(33113, 3, 1, 'Pursuit objective modified. Changing course.', 14, 0, 0, 0, 0, 15508, 'Flame Leviathan SAY_TARGET_2'),
(33113, 3, 2, 'Hostile entity stratagem predicted. Rerouting battle function. Changing course.', 14, 0, 0, 0, 0, 15509, 'Flame Leviathan SAY_TARGET_3'),
(33113, 4, 0, 'Orbital countermeasures enabled.', 14, 0, 0, 0, 0, 15510, 'Flame Leviathan SAY_HARDMODE'),
(33113, 5, 0, 'Alert! Static defense system failure. Orbital countermeasures disabled.', 14, 0, 0, 0, 0, 15511, 'Flame Leviathan SAY_TOWER_NONE'),
(33113, 6, 0, '''Hodir''s Fury'' online. Acquiring target.', 14, 0, 0, 0, 0, 15512, 'Flame Leviathan SAY_TOWER_FROST'),
(33113, 7, 0, '''Mimiron''s Inferno'' online. Acquiring target.', 14, 0, 0, 0, 0, 15513, 'Flame Leviathan SAY_TOWER_FLAME'),
(33113, 8, 0, '''Freya''s Ward'' online. Acquiring target.', 14, 0, 0, 0, 0, 15514, 'Flame Leviathan SAY_TOWER_NATURE'),
(33113, 9, 0, '''Thorim''s Hammer'' online. Acquiring target.', 14, 0, 0, 0, 0, 15515, 'Flame Leviathan SAY_TOWER_STORM'),
(33113, 10, 0, 'Unauthorized entity attempting circuit overload. Activating anti-personnel countermeasures.', 14, 0, 0, 0, 0, 15516, 'Flame Leviathan SAY_PLAYER_RIDING'),
(33113, 11, 0, 'System malfunction. Diverting power to support systems.', 14, 0, 0, 0, 0, 15517, 'Flame Leviathan SAY_OVERLOAD_1'),
(33113, 11, 1, 'Combat matrix overload. Powering do-o-o-own...', 14, 0, 0, 0, 0, 15518, 'Flame Leviathan SAY_OVERLOAD_2'),
(33113, 11, 2, 'System restart required. Deactivating weapon systems.', 14, 0, 0, 0, 0, 15519, 'Flame Leviathan SAY_OVERLOAD_3'),
(33113, 12, 0, 'Flame Leviathan pursues $N', 41, 0, 0, 0, 0, 0, 'Flame Leviathan EMOTE_PURSUE'),
(33113, 13, 0, 'Flame Leviathan''s circuits overloaded.', 41, 0, 0, 0, 0, 0, 'Flame Leviathan EMOTE_OVERLOAD'),
(33113, 14, 0, 'Automatic repair sequence initiated.', 41, 0, 0, 0, 0, 0, 'Flame Leviathan EMOTE_REPAIR');

-- Ignis
-- DELETE FROM `script_texts` WHERE `npc_entry`=33118;
DELETE FROM `creature_text` WHERE `entry`=33118;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33118, 0, 0, 'Insolent whelps! Your blood will temper the weapons used to reclaim this world!', 14, 0, 100, 0, 0, 15564, 'Ignis SAY_AGGRO'),
(33118, 1, 0, 'More scraps for the scrapheap!', 14, 0, 100, 0, 0, 15569, 'Ignis SAY_SLAY_1'),
(33118, 1, 1, 'Your bones will serve as kindling!', 14, 0, 100, 0, 0, 15570, 'Ignis SAY_SLAY_2'),
(33118, 2, 0, 'I. Have. Failed.', 14, 0, 100, 0, 0, 15572, 'Ignis SAY_DEATH'),
(33118, 3, 0, 'Arise, soldiers of the Iron Crucible! The Makers'' will be done!', 14, 0, 100, 0, 0, 15565, 'Ignis SAY_SUMMON'),
(33118, 4, 0, 'I will burn away your impurities!', 14, 0, 100, 0, 0, 15566, 'Ignis SAY_SLAG_POT'),
(33118, 5, 0, 'Let the inferno consume you!', 14, 0, 100, 0, 0, 15567, 'Ignis SAY_SCORCH_1'),
(33118, 5, 1, 'BURN! Burn in the makers fire!', 14, 0, 100, 0, 0, 15568, 'Ignis SAY_SCORCH_2'),
(33118, 6, 0, 'Let it be finished!', 14, 0, 100, 0, 0, 15571, 'Ignis SAY_BERSERK'),
(33118, 7, 0, 'Ignis the Furnace Master begins to cast Flame Jets!', 41, 0, 100, 0, 0, 0, 'Ignis EMOTE_JETS');

-- Razorscale
-- DELETE FROM `script_texts` WHERE `npc_entry` IN (33186, 33210, 33287, 33233);
DELETE FROM `creature_text` WHERE `entry` IN (33186, 33210, 33287, 33233);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33186, 0, 0, 'Razorscale takes a deep breath...', 41, 0, 100, 0, 0, 0, 'Razorscale EMOTE_BREATH'),
(33186, 1, 0, 'Razorscale grounded permanently!', 41, 0, 100, 0, 0, 0, 'Razorscale EMOTE_PERMA'),
(33210, 0, 0, 'Welcome, champions! All of our attempts at grounding her have failed. We could use a hand in bring her down with these harpoon guns.', 14, 0, 100, 0, 0, 15647, 'Exp Commander SAY_GREET'),
(33210, 1, 0, 'Move! Quickly! She won''t remain grounded for long.', 14, 0, 100, 0, 0, 15648, 'Exp Commander SAY_GROUND_PHASE'),
(33287, 0, 0, 'Give us a moment to prepare to build the turrets.', 14, 0, 100, 0, 0, 0, 'Exp Engineer SAY_AGGRO_1'),
(33287, 0, 1, 'Be on the lookout! Mole machines will be surfacing soon with those nasty Iron dwarves aboard!', 14, 0, 100, 0, 0, 0, 'Exp Engineer SAY_AGGRO_2'),
(33287, 0, 2, 'Ready to move out, keep those dwarves off of our backs!', 14, 0, 100, 0, 0, 0, 'Exp Engineer SAY_AGGRO_3'),
(33287, 1, 0, 'Fires out! Let''s rebuild those turrets!', 14, 0, 100, 0, 0, 0, 'Exp Engineer SAY_TURRETS'),
(33233, 0, 0, 'Harpoon Turret is ready for use!', 41, 0, 100, 0, 0, 0, 'Razorscale Controller EMOTE_HARPOON');

-- XT-002 Deconstructor
-- DELETE FROM `script_texts` WHERE `npc_entry` IN (33293, 33343);
DELETE FROM `creature_text` WHERE `entry` IN (33293, 33343);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33293, 0, 0, 'New toys? For me? I promise I won''t break them this time!', 14, 0, 100, 0, 0, 15724, 'XT002 SAY_AGGRO'),
(33293, 1, 0, 'So tired. I will rest for just a moment!', 14, 0, 100, 0, 0, 15725, 'XT002 SAY_HEART_OPENED'),
(33293, 2, 0, 'I''m ready to play!', 14, 0, 100, 0, 0, 15726, 'XT002 SAY_HEART_CLOSED'),
(33293, 3, 0, 'NO! NO! NO! NO! NO!', 14, 0, 100, 0, 0, 15727, 'XT002 SAY_TYMPANIC_TANTRUM'),
(33293, 4, 0, 'I... I think I broke it.', 14, 0, 100, 0, 0, 15728, 'XT002 SAY_SLAY_1'),
(33293, 4, 1, 'I guess it doesn''t bend that way.', 14, 0, 100, 0, 0, 15729, 'XT002 SAY_SLAY_2'),
(33293, 5, 0, 'I''m tired of these toys. I don''t want to play anymore!', 14, 0, 100, 0, 0, 15730, 'XT002 SAY_BERSERK'),
(33293, 6, 0, 'You are bad... Toys... Very... Baaaaad!', 14, 0, 100, 0, 0, 15731, 'XT002 SAY_DEATH'),
(33293, 7, 0, 'Time for a new game! My old toys will fight my new toys!', 14, 0, 100, 0, 0, 15732, 'XT002 SAY_SUMMON'),
(33293, 8, 0, 'XT-002 Deconstructor begins to cause the earth to quake.', 41, 0, 100, 0, 0, 0, 'XT002 EMOTE_TYMPANIC'),
(33293, 9, 0, 'XT-002 Deconstructor''s heart is exposed and leaking energy.', 41, 0, 100, 0, 0, 0, 'XT002 EMOTE_HEART'),
(33343, 0, 0, 'XT-002 Deconstructor consumes a scrap bot to repair himself!', 41, 0, 100, 0, 0, 0, 'XS-013 Scrapbot EMOTE_REPAIR');

-- Assembly of Iron
-- DELETE FROM `script_texts` WHERE `npc_entry` IN (32867, 32927, 32857);
DELETE FROM `creature_text` WHERE `entry` IN (32867, 32927, 32857);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32867, 0, 0, 'You will not defeat the Assembly of Iron so easily, invaders!', 14, 0, 100, 0, 0, 15674, 'Steelbreaker SAY_AGGRO'),
(32867, 1, 0, 'So fragile and weak!', 14, 0, 100, 0, 0, 15675, 'Steelbreaker SAY_SLAY_1'),
(32867, 1, 1, 'Flesh... such a hindrance.', 14, 0, 100, 0, 0, 15676, 'Steelbreaker SAY_SLAY_2'),
(32867, 2, 0, 'You seek the secrets of Ulduar? Then take them!', 14, 0, 100, 0, 0, 15677, 'Steelbreaker SAY_POWER'),
(32867, 3, 0, 'My death only serves to hasten your demise.', 14, 0, 100, 0, 0, 15678, 'Steelbreaker SAY_DEATH_1'),
(32867, 3, 1, 'Impossible!', 14, 0, 100, 0, 0, 15679, 'Steelbreaker SAY_DEATH_2'),
(32867, 4, 0, 'This meeting of the Assembly of Iron is adjourned!', 14, 0, 100, 0, 0, 15680, 'Steelbreaker SAY_BERSERK'),
(32927, 0, 0, 'Nothing short of total decimation will suffice.', 14, 0, 100, 0, 0, 15657, 'Molgeim SAY_AGGRO'),
(32927, 1, 0, 'The world suffers yet another insignificant loss.', 14, 0, 100, 0, 0, 15658, 'Molgeim SAY_SLAY_1'),
(32927, 1, 1, 'Death is the price of your arrogance.', 14, 0, 100, 0, 0, 15659, 'Molgeim SAY_SLAY_2'),
(32927, 2, 0, 'Decipher this!', 14, 0, 100, 0, 0, 15660, 'Molgeim SAY_RUNE_DEATH'),
(32927, 3, 0, 'Face the lightning surge!', 14, 0, 100, 0, 0, 15661, 'Molgeim SAY_SUMMON'),
(32927, 4, 0, 'The legacy of storms shall not be undone.', 14, 0, 100, 0, 0, 15662, 'Molgeim SAY_DEATH_1'),
(32927, 4, 1, 'What have you gained from my defeat? You are no less doomed, mortals!', 14, 0, 100, 0, 0, 15663, 'Molgeim SAY_DEATH_2'),
(32927, 5, 0, 'This meeting of the Assembly of Iron is adjourned!', 14, 0, 100, 0, 0, 15664, 'Molgeim SAY_BERSERK'),
(32857, 0, 0, 'Whether the world''s greatest gnats or the world''s greatest heroes, you''re still only mortal!', 14, 0, 100, 0, 0, 15684, 'Brundir SAY_AGGRO'),
(32857, 1, 0, 'A merciful kill!', 14, 0, 100, 0, 0, 15685, 'Brundir SAY_SLAY_1'),
(32857, 1, 1, 'HAH!', 14, 0, 100, 0, 0, 15686, 'Brundir SAY_SLAY_2'),
(32857, 2, 0, 'Stand still and stare into the light!', 14, 0, 100, 0, 0, 15687, 'Brundir SAY_SPECIAL'),
(32857, 3, 0, 'Let the storm clouds rise and rain down death from above!', 14, 0, 100, 0, 0, 15688, 'Brundir SAY_FLIGHT'),
(32857, 4, 0, 'The power of the storm lives on...', 14, 0, 100, 0, 0, 15689, 'Brundir SAY_DEATH_1'),
(32857, 4, 1, 'You rush headlong into the maw of madness!', 14, 0, 100, 0, 0, 15690, 'Brundir SAY_DEATH_2'),
(32857, 5, 0, 'This meeting of the Assembly of Iron is adjourned!', 14, 0, 100, 0, 0, 15691, 'Brundir SAY_BERSERK'),
(32857, 6, 0, 'Stormcaller Brundir begins to Overload!', 41, 0, 100, 0, 0, 0, 'Brundir EMOTE_OVERLOAD');

-- Kologarn
-- DELETE FROM `script_texts` WHERE `npc_entry`=32930;
DELETE FROM `creature_text` WHERE `entry`=32930;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32930, 0, 0, 'None shall pass!', 14, 0, 100, 0, 0, 15586, 'Kologarn SAY_AGGRO'),
(32930, 1, 0, 'KOL-THARISH!', 14, 0, 100, 0, 0, 15587, 'Kologarn SAY_SLAY_1'),
(32930, 1, 1, 'YOU FAIL!', 14, 0, 100, 0, 0, 15588, 'Kologarn SAY_SLAY_2'),
(32930, 2, 0, 'Just a scratch!', 14, 0, 100, 0, 0, 15589, 'Kologarn SAY_LEFT_ARM_GONE'),
(32930, 3, 0, 'Only a flesh wound!', 14, 0, 100, 0, 0, 15590, 'Kologarn SAY_RIGHT_ARM_GONE'),
(32930, 4, 0, 'OBLIVION!', 14, 0, 100, 0, 0, 15591, 'Kologarn SAY_SHOCKWAVE'),
(32930, 5, 0, 'I will squeeze the life from you!', 14, 0, 100, 0, 0, 15592, 'Kologarn SAY_GRAB_PLAYER'),
(32930, 6, 0, 'Master, they come...', 14, 0, 100, 0, 0, 15593, 'Kologarn SAY_DEATH'),
(32930, 7, 0, 'I am invincible!', 14, 0, 100, 0, 0, 15594, 'Kologarn SAY_BERSERK'),
(32930, 8, 0, 'Kologarn is focussing you!', 42, 0, 100, 0, 0, 0, 'Kologarn WHISPER_EYEBEAM'),
(32930, 9, 0, 'The Left Arm has regrown!', 41, 0, 100, 0, 0, 0, 'Kologarn EMOTE_LEFT'),
(32930, 10, 0, 'The Right Arm has regrown!', 41, 0, 100, 0, 0, 0, 'Kologarn EMOTE_RIGHT'),
(32930, 11, 0, 'Kologarn casts Stone Grip!', 41, 0, 100, 0, 0, 0, 'Kologarn EMOTE_STONE');

-- Auriaya
-- DELETE FROM `script_texts` WHERE `npc_entry`=33515;
DELETE FROM `creature_text` WHERE `entry`=33515;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33515, 0, 0, 'Some things are better left alone!', 14, 0, 100, 0, 0, 15473, 'Auriaya SAY_AGGRO'),
(33515, 1, 0, 'The secret dies with you!', 14, 0, 100, 0, 0, 15474, 'Auriaya SAY_SLAY_1'),
(33515, 1, 1, 'There is no escape!', 14, 0, 100, 0, 0, 15475, 'Auriaya SAY_SLAY_2'),
(33515, 2, 0, 'Auriaya screams in agony.', 14, 0, 100, 0, 0, 15476, 'Auriaya SAY_DEATH'),
(33515, 3, 0, 'You waste my time!', 14, 0, 100, 0, 0, 15477, 'Auriaya SAY_BERSERK'),
(33515, 4, 0, 'Auriaya begins to cast Terrifying Screech.', 41, 0, 100, 0, 0, 0, 'Auriaya - EMOTE_FEAR'),
(33515, 5, 0, 'Auriaya begins to activate the Feral Defender!', 41, 0, 100, 0, 0, 0, 'Auriaya - EMOTE_DEFENDER');

-- Freya
-- DELETE FROM `script_texts` WHERE `npc_entry` IN (32906, 32913, 32914, 32915);
DELETE FROM `creature_text` WHERE `entry` IN (32906, 32913, 32914, 32915);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32906, 0, 0, 'The Conservatory must be protected!', 14, 0, 100, 0, 0, 15526, 'Freya SAY_AGGRO'),
(32906, 1, 0, 'Elders, grant me your strength!', 14, 0, 100, 0, 0, 15527, 'Freya SAY_AGGRO_WITH_ELDER'),
(32906, 2, 0, 'Forgive me.', 14, 0, 100, 0, 0, 15529, 'Freya SAY_SLAY_1'),
(32906, 2, 1, 'From your death springs life anew!', 14, 0, 100, 0, 0, 15530, 'Freya SAY_SLAY_2'),
(32906, 3, 0, 'His hold on me dissipates. I can see clearly once more. Thank you, heroes.', 14, 0, 100, 0, 0, 15531, 'Freya SAY_DEATH'),
(32906, 4, 0, 'You have strayed too far, wasted too much time!', 14, 0, 100, 0, 0, 15532, 'Freya SAY_BERSERK'),
(32906, 5, 0, 'Eonar, your servant requires aid!', 14, 0, 100, 0, 0, 15528, 'Freya SAY_SUMMON_CONSERVATOR'),
(32906, 6, 0, 'Children, assist me!', 14, 0, 100, 0, 0, 15533, 'Freya SAY_SUMMON_TRIO'),
(32906, 7, 0, 'The swarm of the elements shall overtake you!', 14, 0, 100, 0, 0, 15534, 'Freya SAY_SUMMON_LASHERS'),
(32915, 0, 0, 'Matron, the Conservatory has been breached!', 14, 0, 100, 0, 0, 15483, 'Elder Brightleaf SAY_AGGRO'),
(32915, 1, 0, 'Fertilizer.', 14, 0, 100, 0, 0, 15485, 'Elder Brightleaf SAY_SLAY_1'),
(32915, 1, 1, 'Your corpse will nourish the soil!', 14, 0, 100, 0, 0, 15486, 'Elder Brightleaf SAY_SLAY_2'),
(32915, 2, 0, 'Matron, one has fallen!', 14, 0, 100, 0, 0, 15487, 'Elder Brightleaf SAY_DEATH'),
(32913, 0, 0, 'Mortals have no place here!', 14, 0, 100, 0, 0, 15493, 'Elder Ironbranch SAY_AGGRO'),
(32913, 1, 0, 'I return you whence you came!', 14, 0, 100, 0, 0, 15494, 'Elder Ironbranch SAY_SLAY_1'),
(32913, 1, 1, 'BEGONE!', 14, 0, 100, 0, 0, 15495, 'Elder Ironbranch SAY_SLAY_2'),
(32913, 2, 0, 'Freya! They come for you.', 14, 0, 100, 0, 0, 15496, 'Elder Ironbranch SAY_DEATH'),
(32914, 0, 0, 'This place will serve as your graveyard.', 14, 0, 100, 0, 0, 15500, 'Elder Stonebark SAY_AGGRO'),
(32914, 1, 0, '<Angry roar>', 14, 0, 100, 0, 0, 15501, 'Elder Stonebark SAY_SLAY_1'),
(32914, 1, 1, 'Such a waste.', 14, 0, 100, 0, 0, 15502, 'Elder Stonebark SAY_SLAY_2'),
(32914, 2, 0, 'Matron, flee! They are ruthless....', 14, 0, 100, 0, 0, 15503, 'Elder Stonebark SAY_DEATH');

-- Hodir
-- DELETE FROM `script_texts` WHERE `npc_entry`=32845;
DELETE FROM `creature_text` WHERE `entry`=32845;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32845, 0, 0, 'You will suffer for this trespass!', 14, 0, 100, 0, 0, 15552, 'Hodir SAY_AGGRO'),
(32845, 1, 0, 'Tragic. To come so far, only to fail.', 14, 0, 100, 0, 0, 15553, 'Hodir SAY_SLAY_1'),
(32845, 1, 1, 'Welcome to the endless winter.', 14, 0, 100, 0, 0, 15554, 'Hodir SAY_SLAY_2'),
(32845, 2, 0, 'Winds of the north consume you!', 14, 0, 100, 0, 0, 15555, 'Hodir SAY_FLASH_FREEZE'),
(32845, 3, 0, 'Hodir roars furious.', 41, 0, 100, 0, 0, 15556, 'Hodir SAY_STALACTITE'),
(32845, 4, 0, 'I... I am released from his grasp... at last.', 14, 0, 100, 0, 0, 15557, 'Hodir SAY_DEATH'),
(32845, 5, 0, 'Enough! This ends now!', 14, 0, 100, 0, 0, 15558, 'Hodir SAY_BERSERK'),
(32845, 6, 0, 'Hodir shatters the Rare Cache of Hodir!', 41, 0, 100, 0, 0, 0, 'Hodir SAY_HARD_MODE_FAILED'),
(32845, 7, 0, 'Hodir begins to cast Flash Freeze!', 41, 0, 100, 0, 0, 0, 'Hodir - EMOTE_FREEZE'),
(32845, 8, 0, 'Hodir gains Frozen Blows!', 41, 0, 100, 0, 0, 0, 'Hodir - EMOTE_BLOW');

-- Mimiron
-- DELETE FROM `script_texts` WHERE `npc_entry`=33350;
DELETE FROM `creature_text` WHERE `entry`=33350;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33350, 0, 0, 'Oh, my! I wasn''t expecting company! The workshop is such a mess! How embarrassing!', 14, 0, 100, 0, 0, 15611, 'Mimiron SAY_AGGRO'),
(33350, 1, 0, 'Now why would you go and do something like that? Didn''t you see the sign that said ''DO NOT PUSH THIS BUTTON!''? How will we finish testing with the self-destruct mechanism active?', 14, 0, 100, 0, 0, 15629, 'Mimiron SAY_HARDMODE_ON'),
(33350, 2, 0, 'We haven''t much time, friends! You''re going to help me test out my latest and greatest creation. Now, before you change your minds, remember, that you kind of owe it to me after the mess you made with the XT-002.', 14, 0, 100, 0, 0, 15612, 'Mimiron SAY_MKII_ACTIVATE'),
(33350, 3, 0, 'MEDIC!', 14, 0, 100, 0, 0, 15613, 'Mimiron SAY_MKII_SLAY_1'),
(33350, 3, 1, 'I can fix that... or, maybe not! Sheesh, what a mess...', 14, 0, 100, 0, 0, 15614, 'Mimiron SAY_MKII_SLAY_2'),
(33350, 4, 0, 'WONDERFUL! Positively marvelous results! Hull integrity at 98.9 percent! Barely a dent! Moving right along.', 14, 0, 100, 0, 0, 15615, 'Mimiron SAY_MKII_DEATH'),
(33350, 5, 0, 'Behold the VX-001 Anti-personnel Assault Cannon! You might want to take cover.', 14, 0, 100, 0, 0, 15616, 'Mimiron SAY_VX001_ACTIVATE'),
(33350, 6, 0, 'Fascinating. I think they call that a "clean kill".', 14, 0, 100, 0, 0, 15617, 'Mimiron SAY_VX001_SLAY_1'),
(33350, 6, 1, 'Note to self: Cannon highly effective against flesh.', 14, 0, 100, 0, 0, 15618, 'Mimiron SAY_VX001_SLAY_2'),
(33350, 7, 0, 'Thank you, friends! Your efforts have yielded some fantastic data! Now, where did I put- oh, there it is!', 14, 0, 100, 0, 0, 15619, 'Mimiron SAY_VX001_DEATH'),
(33350, 8, 0, 'Isn''t it beautiful? I call it the magnificent aerial command unit!', 14, 0, 100, 0, 0, 15620, 'Mimiron SAY_AERIAL_ACTIVATE'),
(33350, 9, 0, 'Outplayed!', 14, 0, 100, 0, 0, 15621, 'Mimiron SAY_AERIAL_SLAY_1'),
(33350, 9, 1, 'You can do better than that!', 14, 0, 100, 0, 0, 15622, 'Mimiron SAY_AERIAL_SLAY_2'),
(33350, 10, 0, 'Preliminary testing phase complete. Now comes the true test!!', 14, 0, 100, 0, 0, 15623, 'Mimiron SAY_AERIAL_DEATH'),
(33350, 11, 0, 'Gaze upon its magnificence! Bask in its glorious, um, glory! I present you... V-07-TR-0N!', 14, 0, 100, 0, 0, 15624, 'Mimiron SAY_V07TRON_ACTIVATE'),
(33350, 12, 0, 'Prognosis: Negative!', 14, 0, 100, 0, 0, 15625, 'Mimiron SAY_V07TRON_SLAY_1'),
(33350, 12, 1, 'You''re not going to get up from that one, friend.', 14, 0, 100, 0, 0, 15626, 'Mimiron SAY_V07TRON_SLAY_2'),
(33350, 13, 0, 'It would appear that I''ve made a slight miscalculation. I allowed my mind to be corrupted by the fiend in the prison, overriding my primary directive. All systems seem to be functional now. Clear.', 14, 0, 100, 0, 0, 15627, 'Mimiron SAY_V07TRON_DEATH'),
(33350, 14, 0, 'Oh, my! It would seem that we are out of time, my friends!', 14, 0, 100, 0, 0, 15628, 'Mimiron SAY_BERSERK');

-- Thorim
-- DELETE FROM `script_texts` WHERE `npc_entry` IN (33413, 32865, 32872);
DELETE FROM `creature_text` WHERE `entry` IN (33413, 32865, 32872);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32865, 0, 0, 'Interlopers! You mortals who dare to interfere with my sport will pay... Wait--you...', 14, 0, 100, 0, 0, 15733, 'Thorim SAY_AGGRO_1'),
(32865, 1, 0, 'I remember you... In the mountains... But you... what is this? Where am\-\-', 14, 0, 100, 0, 0, 15734, 'Thorim SAY_AGGRO_2'),
(32865, 2, 0, 'Behold the power of the storms and despair!', 14, 0, 100, 0, 0, 15735, 'Thorim SAY_SPECIAL_1'),
(32865, 2, 1, 'Do not hold back! Destroy them!', 14, 0, 100, 0, 0, 15736, 'Thorim SAY_SPECIAL_2'),
(32865, 2, 2, 'Have you begun to regret your intrusion?', 14, 0, 100, 0, 0, 15737, 'Thorim SAY_SPECIAL_3'),
(32865, 3, 0, 'Impertinent whelps! You dare challenge me atop my pedestal! I will crush you myself!', 14, 0, 100, 0, 0, 15738, 'Thorim SAY_JUMPDOWN'),
(32865, 4, 0, 'Can''t you at least put up a fight!?', 14, 0, 100, 0, 0, 15739, 'Thorim SAY_SLAY_1'),
(32865, 4, 1, 'Pathetic!', 14, 0, 100, 0, 0, 15740, 'Thorim SAY_SLAY_2'),
(32865, 5, 0, 'My patience has reached its limit!', 14, 0, 100, 0, 0, 15741, 'Thorim SAY_BERSERK'),
(32865, 6, 0, 'Failures! Weaklings!', 14, 0, 100, 0, 0, 15742, 'Thorim SAY_WIPE'),
(32865, 7, 0, 'Stay your arms! I yield!', 14, 0, 100, 0, 0, 15743, 'Thorim SAY_DEATH'),
(32865, 8, 0, 'I feel as though I am awakening from a nightmare, but the shadows in this place yet linger.', 14, 0, 100, 0, 0, 15744, 'Thorim SAY_END_NORMAL_1'),
(32865, 8, 1, 'Sif... was Sif here? Impossible\-\-she died by my brother''s hand. A dark nightmare indeed....', 14, 0, 100, 0, 0, 15745, 'Thorim SAY_END_NORMAL_2'),
(32865, 8, 2, 'I need time to reflect.... I will aid your cause if you should require it. I owe you at least that much. Farewell.', 14, 0, 100, 0, 0, 15746, 'Thorim SAY_END_NORMAL_3'),
(32865, 9, 0, 'You! Fiend! You are not my beloved! Be gone!', 14, 0, 100, 0, 0, 15747, 'Thorim SAY_END_HARD_1'),
(32865, 9, 1, 'Behold the hand behind all the evil that has befallen Ulduar! Left my kingdom in ruins, corrupted my brother and slain my wife!', 14, 0, 100, 0, 0, 15748, 'Thorim SAY_END_HARD_2'),
(32865, 9, 2, 'And now it falls to you, champions, to avenge us all! The task before you is great, but I will lend you my aid as I am able. You must prevail!', 14, 0, 100, 0, 0, 15749, 'Thorim SAY_END_HARD_3'),
(32872, 0, 0, 'Runic Colossus surrounds itself with a crackling Runic Barrier!', 41, 0, 100, 0, 0, 0, 'Runic Colossus EMOTE_BARRIER');

-- General Vezax
-- DELETE FROM `script_texts` WHERE `npc_entry` IN (33271, 33488);
DELETE FROM `creature_text` WHERE `entry` IN (33271, 33488);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33271, 0, 0, 'Your destruction will herald a new age of suffering!', 14, 0, 100, 0, 0, 15542, 'General Vezax SAY_AGGRO'),
(33271, 1, 0, 'You thought to stand before the legions of death... and survive?', 14, 0, 100, 0, 0, 15543, 'General Vezax SAY_SLAY_1'),
(33271, 1, 1, 'Defiance... a flaw of mortality.', 14, 0, 100, 0, 0, 15544, 'General Vezax SAY_SLAY_2'),
(33271, 2, 0, 'The black blood of Yogg-Saron courses through me! I. AM. UNSTOPPABLE!', 14, 0, 100, 0, 0, 15545, 'General Vezax SAY_SURGE_DARKNESS'),
(33271, 3, 0, 'Oh, what horrors await....', 14, 0, 100, 0, 0, 15546, 'General Vezax SAY_DEATH'),
(33271, 4, 0, 'Your defeat was inevitable!', 14, 0, 100, 0, 0, 15547, 'General Vezax SAY_BERSERK'),
(33271, 5, 0, 'Behold, now! Terror, absolute!', 14, 0, 100, 0, 0, 15548, 'General Vezax SAY_HARDMODE_ON'),
(33271, 6, 0, 'The saronite vapors mass and swirl violently, merging into a monstrous form!', 41, 0, 100, 0, 0, 0, 'General Vezax - EMOTE_ANIMUS'),
(33271, 7, 0, 'A saronite barrier appears around General Vezax!', 41, 0, 100, 0, 0, 0, 'General Vezax - EMOTE_BARRIER'),
(33271, 8, 0, 'General Vezax roars and surges with dark might!', 41, 0, 100, 0, 0, 0, 'General Vezax - EMOTE_SURGE_OF_DARKNESS'),
(33488, 0, 0, 'A cloud of saronite vapors coalesces nearby!', 41, 0, 100, 0, 0, 0, 'Saronite Vapor - EMOTE_VAPOR');

-- Yogg-Saron
-- DELETE FROM `script_texts` WHERE `npc_entry` IN (33288, 33241, 33213, 33244, 33242, 33436, 33437, 33523, 33495, 33535, 33441, 33442, 33134);
DELETE FROM `creature_text` WHERE `entry` IN (33288, 33241, 33213, 33244, 33242, 33436, 33437, 33523, 33495, 33535, 33441, 33442, 33134);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(33288, 0, 0, 'BOW DOWN BEFORE THE GOD OF DEATH!', 14, 0, 100, 0, 0, 0, 'YoggSaron SAY_PHASE2'),
(33288, 1, 0, 'Look upon the true face of death and know that your end comes soon!', 14, 0, 100, 0, 0, 15755, 'YoggSaron SAY_PHASE3'),
(33288, 2, 0, 'MADNESS WILL CONSUME YOU!', 14, 0, 100, 0, 0, 15756, 'YoggSaron SAY_PORTAL'),
(33288, 3, 0, 'Hoohehehahahaha... AHAHAHAHAHAHA!', 14, 0, 100, 0, 0, 15757, 'YoggSaron SAY_SLAY_1'),
(33288, 4, 0, 'Eternal suffering awaits!', 14, 0, 100, 0, 0, 15758, 'YoggSaron SAY_DEAFENING_ROAR'),
(33288, 5, 0, 'Your will is no longer you own...', 42, 0, 100, 0, 0, 15759, 'YoggSaron WHISP_INSANITY_1'),
(33288, 5, 1, 'Destroy them minion, your master commands it!', 42, 0, 100, 0, 0, 15760, 'YoggSaron WHISP_INSANITY_2'),
(33288, 6, 0, 'Your fate is sealed. The end of days is finally upon you and ALL who inhabit this miserable little seedling. Uulwi ifis halahs gag erh''ongg w''ssh.', 14, 0, 100, 0, 0, 15761, 'YoggSaron SAY_DEATH'),

-- 3 Vision at brain phase
-- tibbi: These should not be yells (shouldnt be visible in chat), but with normal SAY players cant hear sound effects (low Say range?) so Ive set all to Yell
(33288, 7, 0, 'A thousand deaths...', 14, 0, 100, 0, 0, 15762, 'YoggSaron v1 1'),
(33288, 8, 0, 'or one murder.', 14, 0, 100, 0, 0, 15763, 'YoggSaron v1 2'),
(33288, 9, 0, 'Your petty quarrels only make me stronger!', 14, 0, 100, 0, 0, 15764, 'YoggSaron v1 3'),
(33436, 0, 0, 'Bad news sire.', 14, 0, 100, 0, 0, 15538, 'Garona v1 4'),
(33436, 1, 0, 'The clans are united under Blackhand in this assault. They will stand together until Stormwind has fallen.', 14, 0, 100, 0, 0, 15539, 'Garona v1 5'),
(33436, 2, 0, 'Gul''dan is bringing up his warlocks by nightfall. Until then, the Blackrock clan will be trying to take the Eastern Wall.', 14, 0, 100, 0, 0, 15540, 'Garona v1 6'),
(33437, 0, 0, 'We will hold until the reinforcements come. As long as men with stout hearts are manning the walls and throne Stormwind will hold.', 14, 0, 100, 0, 0, 15585, 'King Llane v1 7'),
(33436, 3, 0, 'The orc leaders agree with your assessment.', 14, 0, 100, 0, 0, 15541, 'Garona v1 8'),

(33523, 0, 0, 'It is done... All have been given that which must be given. I now seal the Dragon Soul forever...', 14, 0, 100, 0, 0, 15631, 'Neltharion v3 1'),
(33495, 0, 0, 'That terrible glow... should that be?', 14, 0, 100, 0, 0, 15784, 'Ysera v3 2'),
(33523, 1, 0, 'For it to be as it must, yes.', 14, 0, 100, 0, 0, 15632, 'Neltharion v3 3'),
(33535, 0, 0, 'It is a weapon like no other. It must be like no other.', 14, 0, 100, 0, 0, 15610, 'Malygos v3 4'),
(33288, 10, 0, 'His brood learned their lesson before too long, you shall soon learn yours!', 14, 0, 100, 0, 0, 15765, 'YoggSaron v3 5'),

(33442, 0, 0, 'Arrrrrrgh!', 14, 0, 100, 0, 0, 15470, 'Immolated Champion v2 1'),
(33441, 0, 0, 'Your resilience is admirable.', 14, 0, 100, 0, 0, 15598, 'Lich King v2 2'),
(33442, 1, 0, 'I''m not afraid of you!', 14, 0, 100, 0, 0, 15471, 'Immolated Champion v2 3'),
(33441, 1, 0, 'I will break you as I broke him.', 14, 0, 100, 0, 0, 15599, 'Lich King v2 4'),
(33288, 11, 0, 'Yrr n''lyeth... shuul anagg!', 14, 0, 100, 0, 0, 15766, 'YoggSaron v2 5'),
(33288, 12, 0, 'He will learn... no king rules forever; only death is eternal!', 14, 0, 100, 0, 0, 15767, 'YoggSaron v2 6'),

(33134, 0, 0, 'Help me! Please get them off me!', 14, 0, 100, 0, 0, 15771, 'Sara SAY_PREFIGHT_1'),
(33134, 0, 1, 'What do you want from me? Leave me alone!', 14, 0, 100, 0, 0, 15772, 'Sara SAY_PREFIGHT_2'),
(33134, 1, 0, 'The time to strike at the head of the beast will soon be upon us! Focus your anger and hatred on his minions!', 14, 0, 100, 457, 0, 15775, 'Sara SAY_AGGRO'),
(33134, 2, 0, 'Yes! YES! Show them no mercy! Give no pause to your attacks!', 14, 0, 100, 0, 0, 15773, 'Sara SAY_PHASE1_1'),
(33134, 2, 1, 'Let hatred and rage guide your blows!', 14, 0, 100, 0, 0, 15774, 'Sara SAY_PHASE1_2'),
(33134, 3, 0, 'Suffocate upon your own hate!', 14, 0, 100, 0, 0, 15776, 'Sara SAY_PHASE2_1'),
(33134, 3, 1, 'Tremble, mortals, before the coming of the end!', 14, 0, 100, 0, 0, 15777, 'Sara SAY_PHASE2_2'),
(33134, 4, 0, 'Powerless to act...', 14, 0, 100, 0, 0, 15778, 'Sara SAY_SLAY_1'),
(33134, 4, 1, 'Could they have been saved?', 14, 0, 100, 0, 0, 15779, 'Sara SAY_SLAY_2'),
(33134, 5, 0, 'I am the lucid dream.', 14, 0, 100, 0, 0, 15754, 'Sara SAY_PHASE2_1'),
(33134, 6, 0, 'The monster in your nightmares.', 14, 0, 100, 0, 0, 0, 'Sara SAY_PHASE2_2'),
(33134, 7, 0, 'The fiend of a thousand faces.', 14, 0, 100, 0, 0, 0, 'Sara SAY_PHASE2_3'),
(33134, 8, 0, 'Cower before my true form.', 14, 0, 100, 0, 0, 0, 'Sara SAY_PHASE2_4'),

-- chosing helping keepers
(33241, 0, 0, 'Eonar, your servant calls for your blessing!', 14, 0, 100, 0, 0, 15535, 'Freya SAY_YS_HELP'),
(33213, 0, 0, 'The veil of winter will protect you, champions!', 14, 0, 100, 0, 0, 15559, 'Hodir SAY_YS_HELP'),
(33244, 0, 0, 'Combat matrix enhanced. Behold wonderous rapidity!', 14, 0, 100, 0, 0, 15630, 'Mimiron SAY_YS_HELP'),
(33242, 0, 0, 'Golganneth, lend me your strengh! Grant my mortal allies the power of thunder!', 14, 0, 100, 0, 0, 15750, 'Thorim SAY_YS_HELP');

-- Ulduar loot corrections
-- XT002 Deconstructor
DELETE FROM `creature_loot_template` WHERE `item`>=45442 AND `item`<=45446 AND `entry`=33293;
DELETE FROM `reference_loot_template` WHERE `item`>=45867 AND `item`<=45871 AND `entry`=34357;
DELETE FROM `creature_loot_template` WHERE `item`>=45867 AND `item`<=45871 AND `entry`=33293;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`) VALUES
(33293, 45867, 0, 2, 1),
(33293, 45868, 0, 2, 1),
(33293, 45869, 0, 2, 1),
(33293, 45870, 0, 2, 1),
(33293, 45871, 0, 2, 1);

-- Assembly of Iron - Steelbreaker
UPDATE `creature_loot_template` SET `item`=45455 WHERE `item`=25455 AND `entry`=32867;
UPDATE `creature_loot_template` SET `lootmode`=2 WHERE `entry`=32867 AND `item` IN (45447, 45448, 45449, 45456, 45455);
UPDATE `creature_loot_template` SET `lootmode`=2 WHERE `entry`=33693 AND `item` IN (45241, 45242, 45243, 45244, 45245, 45607);

-- Hodir - spawning hardmode caches
DELETE FROM `gameobject` WHERE `id` IN (194200, 194201);
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(194200, 603, 1, 1, 2035.75, -195.046, 432.687, 3.68744, 0, 0, 0.962987, -0.269548, 604800, 255, 1),
(194201, 603, 2, 1, 2035.75, -195.046, 432.687, 3.68744, 0, 0, 0.962987, -0.269548, 604800, 255, 1);

-- Thorim (no need to add custom lootmode, hardmode cache is spawned only when it should)
UPDATE `gameobject_loot_template` SET `lootmode`=1 WHERE `entry` IN (26955, 26956, 27074);

-- Yogg-saron 10m loot
DELETE FROM `creature_loot_template` WHERE `entry`=33288;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(33288, 1, 100, 1, 0, -34375, 1),
(33288, 47241, 100, 1, 0, 1, 1),
(33288, 2, 100, 1, 0, -12034, 1),
(33288, 3, 100, 2, 0, -34349, 1),
(33288, 4, 100, 4, 0, -34350, 1),
(33288, 5, 10, 4, 0, -34154, 1),
(33288, 46097, 0, 8, 1, 1, 1),
(33288, 46096, 0, 8, 1, 1, 1),
(33288, 46095, 0, 8, 1, 1, 1),
(33288, 46068, 0, 8, 1, 1, 1),
(33288, 7, 100, 8, 0, -34154, 1),
(33288, 6, 100, 8, 0, -34349, 1),
(33288, 46067, 0, 8, 1, 1, 1),
(33288, 46312, 100, 16, 0, 1, 1);

-- Yogg-saron 25m loot
DELETE FROM `creature_loot_template` WHERE `entry`=33955;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(33955, 1, 100, 1, 0, -34376, 2),
(33955, 45897, 100, 1, 0, 1, 1),
(33955, 47241, 100, 1, 0, 1, 1),
(33955, 4, 10, 1, 0, -34154, 1),
(33955, 2, 100, 1, 0, -12035, 2),
(33955, 3, 10, 1, 0, -34350, 1),
(33955, 5, 100, 2, 0, -34349, 1),
(33955, 6, 100, 4, 0, -34350, 1),
(33955, 45537, 0, 8, 1, 1, 1),
(33955, 45536, 0, 8, 1, 1, 1),
(33955, 45535, 0, 8, 1, 1, 1),
(33955, 45534, 0, 8, 1, 1, 1),
(33955, 8, 100, 8, 0, -34154, 1),
(33955, 7, 100, 8, 0, -34349, 1),
(33955, 45533, 0, 8, 1, 1, 1),
(33955, 45693, 100, 16, 0, 1, 1);

-- Algalon's Sack of Ulduar Spoils (10m)
DELETE FROM `creature_loot_template` WHERE `entry`=45875;
DELETE FROM `item_loot_template` WHERE `entry`=45875;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(45875, 45087, 100, 1, 0, 1, 1),
(45875, 47241, 100, 1, 0, 5, 5);
