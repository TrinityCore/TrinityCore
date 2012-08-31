-- hand of sacrifice scriptname
DELETE FROM spell_script_names WHERE spell_id = 6940;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(6940, 'spell_pal_hand_of_sacrifice');

-- divine sacrifice scriptname
DELETE FROM spell_script_names WHERE spell_id = 64205;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(64205, 'spell_pal_divine_sacrifice');

-- righteous defense scriptname
DELETE FROM spell_script_names WHERE spell_id = 31789;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(31789, 'spell_pal_righteous_defense');

-- impale scriptname
DELETE FROM spell_script_names WHERE spell_id = 65919;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(65919, 'spell_impale');

-- leviathan tower buffs
DELETE FROM spell_script_names WHERE spell_id IN (64482, 65075, 65076, 65077);
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(64482, 'spell_leviathan_tower_buff'),
(65075, 'spell_leviathan_tower_buff'),
(65076, 'spell_leviathan_tower_buff'),
(65077, 'spell_leviathan_tower_buff');

-- Mark of the faceless scriptname
DELETE FROM spell_script_names WHERE spell_id = 63276;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(63276, 'spell_mark_of_the_faceless');

-- Raise dead scriptname
DELETE FROM spell_script_names WHERE spell_id = 46584;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(46584, 'spell_dk_raise_dead');

-- thorim berserk
DELETE FROM spell_script_names WHERE spell_id = 62560;
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(62560, 'spell_thorim_berserk');

-- making the Four Horsemen chest lootable
UPDATE gameobject_template SET flags = flags & ~16 WHERE entry = 193426;

-- -------------------------
-- TRIAL OF THE CRUSADER --
-- -------------------------

-- firebomb scriptname and modelid (ToC Gormok encounter)
UPDATE creature_template SET ScriptName = "npc_firebomb" WHERE entry = 34854;
UPDATE creature_template SET modelid1 = 11686, modelid2 = 0 WHERE entry = 34854;

-- frost sphere corrections
UPDATE creature_template SET modelid1 = 11686, minlevel = 80, InhabitType = 4, RegenHealth = 0 WHERE entry IN (34606, 34649);

-- Twin waypoints
DELETE FROM waypoint_data WHERE id IN (34496, 34497);
INSERT INTO waypoint_data (id, point, position_x, position_y, position_z, move_flag) VALUES
(34496, 1, 553.5, 180.5, 395.14, 1),
(34496, 2, 545.5, 170, 395.14, 1),
(34496, 3, 546, 169, 395.14, 1),
(34497, 1, 573.5, 180.5, 395.14, 1),
(34497, 2, 585.5, 170, 395.14, 1),
(34497, 3, 585, 169, 395.14, 1);

-- Dark / Light essence removing
DELETE FROM spell_linked_spell WHERE spell_trigger IN (-67222, -67223, -67224, -65686, -67176, -67177, -67178, -65684);
INSERT INTO spell_linked_spell (spell_trigger, spell_effect, type, comment) VALUES
(-67222, -67511, 0, 'Light Essence 25M'),
(-67223, -67512, 0, 'Light Essence 10M H'),
(-67224, -67513, 0, 'Light Essence 25M H'),
(-65686, -65811, 0, 'Light Essence 10M'),
(-67176, -67179, 0, 'Dark Essence 25M'),
(-67177, -67180, 0, 'Dark Essence 10M H'),
(-67178, -67181, 0, 'Dark Essence 25M H'),
(-65684, -65827, 0, 'Dark Essence 10M');

-- Dark / Light Vortex scriptname
DELETE FROM spell_script_names WHERE spell_id IN (66059, 67155, 67156, 67157, 66048, 67203, 67204, 67205);
INSERT INTO spell_script_names VALUES
(66059, 'spell_twin_vortex'),
(67155, 'spell_twin_vortex'),
(67156, 'spell_twin_vortex'),
(67157, 'spell_twin_vortex'),
(66048, 'spell_twin_vortex'),
(67203, 'spell_twin_vortex'),
(67204, 'spell_twin_vortex'),
(67205, 'spell_twin_vortex');

-- removing infernal model of nerubian burrower
UPDATE creature_template SET modelid1 = 0 WHERE entry = 34862;

-- removing infernal model of submerged anub'arak
UPDATE creature_template SET modelid2 = 0 WHERE entry = 34660;

-- correcting hitbox of Anub'Arak
UPDATE creature_model_info SET bounding_radius = 1.085, combat_reach = 10.5 WHERE modelid = 29268;

-- correcting hitbox of Acidmaw
UPDATE creature_model_info SET bounding_radius = 1.24, combat_reach = 12 WHERE modelid = 29815;

-- spawn the Anub'arak gate in all versions of the instance
UPDATE gameobject SET spawnMask = 15 WHERE guid = 151192;

-- adding ToC boss immunities
UPDATE creature_template SET mechanic_immune_mask = mechanic_immune_mask | 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128 | 256 | 512 | 1024 | 2048 | 4096 | 8192 | 65536 | 131072 | 524288 | 4194304 | 8388608 | 67108864 | 536870912 
	WHERE entry IN (34796, 35438, 35439, 35440, 34799, 35514, 35515, 35516, 35144, 35511, 35512, 35513, 34797, 35447, 35448, 35449, 34780, 35216, 35268, 35269, 36066, 35347, 35348, 35349, 34497, 35350, 35351, 35352, 34564, 34566, 35615, 35616);

-- adding Teleport locations to Trial of the Crusader/champion for GMs
DELETE FROM game_tele WHERE name LIKE '%TrialOfTheCrusader%' OR name LIKE '%TrialOfTheChampion%';
INSERT INTO game_tele (position_x, position_y, position_z, orientation, map, name) VALUES
(8515.63, 714.174, 558.248, 1.57298, 571, 'TrialOfTheCrusader'),
(8588.42, 791.888, 558.236, 3.23819, 571, 'TrialOfTheChampion');

-- -------------------------
-- ULDUAR ------------------
-- -------------------------

-- {Flame Leviathan}
-- Scripts update/register for NPCs, areatriggers and spells.

-- Part 1: Creatures. I've renamed them, since they are no bosses, as named before.
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_seat' WHERE `entry`=33114;
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_defense_turret' WHERE `entry`=33142;
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_defense_cannon' WHERE `entry`=33139;
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_overload_device' WHERE `entry`=33143;
UPDATE `creature_template` SET `ScriptName`='npc_flame_leviathan_safety_container' WHERE `entry`=33218; 
UPDATE `creature_template` SET `ScriptName`='npc_liquid_pyrite' WHERE `entry`=33189;
UPDATE `creature_template` SET `ScriptName`='npc_freya_ward_of_life' WHERE `entry`=34275;
UPDATE `creature_template` SET `ScriptName`='npc_runeforged_sentry' WHERE `entry`=34234;
-- Part 1.1: Mimirons Inferno Bunny - it should walk around.
DELETE FROM `waypoints` WHERE `entry`=33370;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(33370, 1, 266.689, -33.391, 409.99, 'Mimirons Inferno - Waypoint of dummy'), 
(33370, 2, 379.158, -33.318, 409.81, 'Mimirons Inferno - Waypoint of dummy 2'), 
(33370, 3, 266.611, -133.387, 409.81, 'Mimirons Inferno - Waypoint of dummy 3'), 
(33370, 4, 158.411, -33.311, 409.81, 'Mimirons Inferno - Waypoint of dummy 4'), 
(33370, 5, 266.699, 66.632, 409.81, 'Mimirons Inferno - Waypoint of dummy 5');

-- Part 2: Areatrigger. These are the triggers at the repair stations (194261,194262).
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5369, 5423);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (5369, 'at_RX_214_repair_o_matic_station');
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (5423, 'at_RX_214_repair_o_matic_station');

-- Part 3: Updates for achievement criterias... to avoid DISTINCT-selection during load :s
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_unbroken_25' WHERE `criteria_id`=10045 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_shutout_25' WHERE  `criteria_id`=10055 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_three_car_garage_chopper_25' WHERE `criteria_id`=10049 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_three_car_garage_siege_25' WHERE `criteria_id`=10050 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_three_car_garage_demolisher_25' WHERE  `criteria_id`=10051 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_orbital_bombardment_25' WHERE `criteria_id`=10059 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_orbital_devastation_25' WHERE `criteria_id`=10060 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_nuked_from_orbit_25' WHERE `criteria_id`=10061 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_orbit_uary_25' WHERE `criteria_id`=10219 AND `type`=11;

-- Part 4: Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (64979, 65044, 62907, 63847, 64677);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(64979, 'spell_anti_air_rocket'),
(65044, 'spell_leviathan_blaze_flames_effect'),
(62907, 'spell_freyas_ward_summon'),
(63847, 'spell_leviathan_flame_vents'),
(64677, 'spell_shield_generator');
-- Part 4.1: Renamed - the resulting effect is called "Pursued", not "Pursue". Period.
UPDATE `spell_script_names` SET `ScriptName`='spell_pursued' WHERE `spell_id`=62374;

-- Part 5: Game-objects: Replaced them if position is incorrect.
DELETE FROM `gameobject` WHERE `id` IN (194261, 194262);
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES 
(194261, 603, 3, 1, 130.553, -128.063, 409.804, 2.87979, 0, 0, 0, 1, 180, 255, 1),
(194261, 603, 3, 1, 138.516, 56.1078, 409.804, 2.87979, 0, 0, 0, 1, 180, 255, 1),
(194262, 603, 3, 1, 131.895, -128.264, 409.804, 0, 0, 0, 0, 1, 180, 255, 1),
(194262, 603, 3, 1, 139.857, 55.9064, 409.804, 0, 0, 0, 0, 1, 180, 255, 1);

-- Ignis::Spell::Flame_Jets -> Target filtering.
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62680, 63472);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(62680, 'spell_ignis_flame_jets'),
(63472, 'spell_ignis_flame_jets');

-- XT002
-- Add additional target selection script, i.e. a SpellScript that is used aside the AuraScript that already got attached to
-- these spells.
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_xt002_gravity_bomb_aura_target';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(63024, 'spell_xt002_gravity_bomb_aura_target'), 
(64234, 'spell_xt002_gravity_bomb_aura_target');

-- Remove unnecessary flags.
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~32768,`dynamicflags`=0,`type_flags`=`type_flags`&~524288 WHERE `entry` IN (33329, 33995);

-- Kologarn
-- Add script to arms.
UPDATE `creature_template` SET `ScriptName`='npc_kologarn_arm' WHERE `entry` IN (32933,32934);
-- Prevent NPC_ARM_SWEEP_STALKER from attacking players.
UPDATE `creature_template` SET `unit_flags`=33554432|256 WHERE `entry`=33661;
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

-- Thorim
UPDATE `creature_template` SET `speed_walk` = 1.66667, `mechanic_immune_mask` = 650854239, `ScriptName` = 'boss_thorim' WHERE `entry` = 32865;
UPDATE `creature_template` SET `speed_walk` = 1.66667, `baseattacktime` = 1500, `equipment_id` = 1844, `mechanic_immune_mask` = 650854239 WHERE `entry` = 33147;
UPDATE `creature` SET `spawndist`=5 WHERE `id`=32865;
-- Controller
UPDATE `creature_template` SET `modelid2`=11686, `unit_flags`=33554432|4|2, `flags_extra`=0, `ScriptName`='npc_thorim_controller' WHERE `entry`=32879;
DELETE FROM `creature` WHERE `id`=32879;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (32879, 603, 3, 1, 0, 0, 2134.77, -262.307, 428.694, 1.3439, 604800, 0, 0, 12600, 0, 0, 0, 0, 0);

-- Adds
UPDATE `creature` SET `MovementType`=1 WHERE `id`=32865;

-- Link spell "Stormhammer" to "Deafening Thunder"
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62042;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(62042, 62470, 1, 'Stormhammer => Deafening Thunder');

-- Register spell-script for target-selection.
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_stormhammer_targeting';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (62042, 'spell_stormhammer_targeting');

-- Charge Orb - implicit targeting only a special npc.
DELETE FROM `conditions` WHERE SourceEntry = 62016;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 62016, 31, 3, 33378, 'Lightning Shock');

-- Pre-phase adds: Register scripts.
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~32768,`dynamicflags`=0,`ScriptName`='npc_thorim_pre_phase_add' WHERE `entry` IN (32885,32883,32908,32907,32882,32886);
UPDATE `creature_template` SET `equipment_id`=1847 WHERE `entry`=33152;
UPDATE `creature_template` SET `equipment_id`=1849 WHERE `entry` IN (32885,33153);
UPDATE `creature_template` SET `equipment_id`=1850 WHERE `entry` IN (32908,33151);
UPDATE `creature_template` SET `equipment_id`=1852 WHERE `entry`=33150;
UPDATE `creature_template` SET `modelid1`=16925, `modelid2`=0 WHERE `entry` IN (33378, 32892);
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|131072 WHERE `entry` IN (33054,33725);
DELETE FROM `creature` WHERE `id` IN (32882,32908,32885,32886,32907,32883); -- NPCs are spawned by script.

-- Thorim Mini bosses : Runic Colossus, Ancient Rune Giant, Sif
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~256, `mechanic_immune_mask`= 650854239, `flags_extra`=1, `ScriptName`='npc_runic_colossus' WHERE `entry`=32872;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~256, `mechanic_immune_mask`= 650854239, `flags_extra`=1, `ScriptName`='npc_ancient_rune_giant' WHERE `entry`=32873;
UPDATE `creature_template` SET `mechanic_immune_mask`= 650854239, `flags_extra`=1, `ScriptName`='npc_sif' WHERE `entry`=33196;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~256, `ScriptName`='npc_thorim_arena_phase_add' WHERE `entry` IN (32876, 32904, 32878, 32877, 32874, 32875, 33110);
DELETE FROM `creature_addon` WHERE `guid` IN (136059, 136816);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(136059, 0, 0, 0, 1, 0, '40775'),
(136816, 0, 0, 0, 1, 0, '40775');
DELETE FROM `creature` WHERE `id` IN (33140,33141); -- Left- and right-hands are used in RunicSmash().
UPDATE `creature_template` SET `ScriptName`='npc_runic_smash' WHERE `entry` IN (33140, 33141);
UPDATE creature_template SET unit_flags = unit_flags | 4 WHERE entry = 33725;

-- Caches.
UPDATE `gameobject_template` SET `flags`=`flags`&~16 WHERE `entry` IN (194312,194313,194314,194315);

-- "Lever" should open "Dark Iron Portcullis".
UPDATE `gameobject_template` SET `type`=1, `faction`=35, `data1`=0, `data4`=0 WHERE `entry`=194264;
DELETE FROM `gameobject_scripts` WHERE `id`=55194;
INSERT INTO `gameobject_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(55194, 0, 11, 34155, 15, 0, 0, 0, 0, 0);
UPDATE `gameobject` SET `rotation2`=1, `spawntimesecs`=7200, `animprogress`=100 WHERE `id`=194264;

-- GO-template.
-- INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES (194264, 0, 295, 'Lever', '', '', '', 0, 48, 3, 0, 0, 0, 0, 0, 0, 0, 1845, 6000, 0, 33914, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340);

-- Freya
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62207,63006, 63007, 62485, 65587, 62484, 65588, 62483, 65589);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (62207, 'spell_elder_brightleaf_unstable_sun_beam');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (63006, 'spell_aggregation_pheromones_targeting');

-- TODO: I'm not sure about these spells, i.e. if the IDs are correct (I've taken them from script).
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62485,65587,62484,65588,62483,65589,62968,65761,62713);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (62968, 'spell_elder_brightleaf_essence_targeting');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (65761, 'spell_elder_brightleaf_essence_targeting');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (62713, 'spell_elder_ironbranch_essence_targeting');

-- Achievement stuff - again: due to DISTINCT(ScriptName) in ObjectMgr
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_getting_back_to_nature_25' WHERE `criteria_id`=10758 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_knock_on_wood_25' WHERE `criteria_id`=10459 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_knock_knock_on_wood_25' WHERE `criteria_id`=10460 AND `type`=11;
UPDATE `achievement_criteria_data` SET `ScriptName`='achievement_knock_knock_knock_on_wood_25' WHERE `criteria_id`=10461 AND `type`=11;

-- Update movement-type and spawndist for Guardian Of Life.
UPDATE `creature_template` SET `MovementType`=1 WHERE `entry` IN (33528, 33733);
UPDATE `creature` SET `spawndist`=50 WHERE `id` in (33528,33733);

-- Mimiron
-- @DorianGrey
-- SQL-updates related to Mimiron-encounter, Ulduar.
-- While I've changed many parts of their encounter-script, this SQL-update is almost completely (apart from the achievement-stuff) 
-- adopted from https://github.com/darkman1983/TrinityCore , so all credits should go to them.

-- First gameobject for the tram from inner sanctuary -> Mimiron.
UPDATE `gameobject_template` SET `flags`=32, `data2`=3000, `ScriptName`='go_call_tram' WHERE `entry` IN (194914, 194912, 194437);
DELETE FROM `gameobject` WHERE id = 194437;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(194437,603,1,1,2306.87,274.237,424.288,1.52255,0,0,0.689847,0.723956,300,0,1);

-- Second gameobject for the tram from Mimiron -> inner sanctuary.
DELETE FROM `gameobject_template` WHERE `entry`=194438;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `ScriptName`, `WDBVerified`) VALUES
(194438,1,8504,'Activate Tram','' ,'' ,'',0,32,1,0,0,0,0,0,0,0,0,3000,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'go_call_tram',12340);
DELETE FROM `gameobject` WHERE id=194438;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(194438,603,1,1,2306.99,2589.35,424.382,4.71676,0,0,0.705559,-0.708651,300,0,1);

-- Mimirion
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235, `ScriptName`='boss_mimiron' WHERE `entry`=33350;
-- Leviathan MKII
UPDATE `creature_template` SET `vehicleid`=370, `mechanic_immune_mask`=650854235, `ScriptName`='boss_leviathan_mk' WHERE `entry`=33432;
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235, `flags_extra`=1 WHERE `entry`=34106;
-- Leviathan MKII Turret
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235, `ScriptName`='boss_leviathan_mk_turret' WHERE `entry`=34071;
DELETE FROM `vehicle_template_accessory` WHERE entry = 33432;
INSERT INTO `vehicle_template_accessory` VALUES (33432, 34071, 3, 1, 'Leviathan Mk II turret', 8, 0);
-- Leviathan skills and skill-helper
UPDATE `creature_template` SET ScriptName='npc_proximity_mine' WHERE entry=34362;
DELETE FROM `creature_model_info` WHERE `modelid`=28831;
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`, `modelid_other_gender`) VALUES
(28831, 0.5, 7, 2, 0);

-- VX-001
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235, `flags_extra`=1, `vehicleid`=371, `ScriptName`='boss_vx_001' WHERE `entry`=33651;
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `mechanic_immune_mask`=650854235, `flags_extra`=1 WHERE `entry`=34108;
UPDATE `creature_template` SET `faction_A`=35, `faction_H` = 35 WHERE `entry` = 34050;
UPDATE `creature_template` SET `unit_flags`=33686020, `flags_extra`=2 WHERE `entry`=34211;
UPDATE `creature_template` SET `ScriptName`='npc_rocket_strike' WHERE `entry`=34047;

-- Aerial Command Unit
UPDATE `creature_template` SET `mechanic_immune_mask`=650854235, `flags_extra`=1, `ScriptName`='boss_aerial_unit', `vehicleid`=372 WHERE `entry`=33670;
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `mechanic_immune_mask`=650854235, `flags_extra`=1 WHERE `entry`=34109;
UPDATE `creature_template` SET `ScriptName`='npc_magnetic_core' WHERE `entry`=34068;
UPDATE `creature_template` SET `ScriptName`='npc_assault_bot' WHERE `entry`=34057;
UPDATE `creature_template` SET `difficulty_entry_1`=34148, `ScriptName`='npc_emergency_bot' WHERE `entry`=34147;

-- HardMode
UPDATE `gameobject_template` SET `flags`=32, `ScriptName`='go_mimiron_hard_mode_activator' WHERE `entry`=194739;
UPDATE `creature_template` SET `difficulty_entry_1`=34361, `ScriptName`='npc_frost_bomb' WHERE `entry`=34149;
UPDATE `creature_template` SET `speed_walk`= 0.15, `speed_run`=0.15, `ScriptName`='npc_mimiron_flame_trigger' WHERE `entry`=34363;
UPDATE `creature_template` SET `ScriptName`='npc_mimiron_flame_spread' WHERE `entry`=34121;
UPDATE `creature_template` SET `ScriptName`='npc_mimiron_bomb_bot' WHERE `entry`=33836;

-- CleanUp
DELETE FROM creature WHERE id IN (34071, 33856);
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=34143;

-- Achievement "Firefighter" (3180 / 3189)
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10450, 10463);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(10450, 12, 0, 0, ''), 
(10450, 11, 0, 0, 'achievement_firefighter'), 
(10463, 12, 1, 0, ''), 
(10463, 11, 0, 0, 'achievement_firefighter_25');

-- Spell stuff
DELETE FROM `spell_script_names` WHERE `spell_id` IN (63382, 63016, 63027);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (63382, 'spell_rapid_burst');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (63027, 'spell_proximity_mines');

-- General Vezax
-- Register spell-scripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62692, 63276, 63278);
INSERT INTO `spell_script_names` VALUES 
(62692,'spell_aura_of_despair_aura'),
(63276,'spell_mark_of_the_faceless_aura'),
(63278,'spell_mark_of_the_faceless_drain');

-- Update saronite animus entry. TODO: Check if its health-modifier is ok.
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `mindmg`=480, `maxdmg`=700, `flags_extra`=1 WHERE `entry`=33524;

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
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction_A`=14, `faction_H`=14, `mindmg`=104, `maxdmg`=138, `attackpower`=252, `dmg_multiplier`=7.5, `unit_flags`=33554432|4|2, `InhabitType`=7, `ScriptName`='npc_yogg_saron_encounter_controller' WHERE `entry`=29224;
DELETE FROM `creature` WHERE `id`=29224;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (29224, 603, 1, 1, 0, 0, 1980.28, -25.5868, 329.397, 2.91365, 300, 0, 0, 7841, 0, 0, 0, 0, 0);
UPDATE `creature_template` SET `faction_A`=35, `faction_H`=35 WHERE `entry` IN (33134, 34332);
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry` IN (33288, 33955);
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
UPDATE `creature_template` SET `ScriptName`='npc_support_keeper' WHERE `entry` in (33410,33411,33412,33413);
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=11686, `ScriptName`='npc_sanity_well' WHERE `entry`=33991;
UPDATE `creature_template` SET `modelid1`=16946, `modelid2`=16946, `ScriptName`='npc_death_orb' WHERE `entry`=33882;
UPDATE `creature_template` SET `modelid1`=17612, `modelid2`=17612, `ScriptName`='npc_death_ray' WHERE `entry`=33881;
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `ScriptName`='npc_laughting_skull' WHERE entry=33990;
UPDATE `creature_template` SET `modelid1`=15880, `modelid2`=15880 WHERE `entry`=33990;
-- Keeper helpers
UPDATE `creature_template` SET `npcflag`=`npcflag`|1, `ScriptName`='npc_keeper_help' WHERE `entry` IN (33241,33244,33242,33213);
DELETE FROM `creature` WHERE `id` IN (33213,33241,33242,33244);
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(33213, 603, 2, 1, 0, 0, 1939.94, -90.49, 338.46, 1.04118, 300, 0, 0, 14433076, 0, 0, 0, 0, 0),
(33241, 603, 2, 1, 0, 0, 2037.31, 25.6417, 338.415, 3.90552, 300, 0, 0, 14433076, 0, 0, 0, 0, 0),
(33242, 603, 2, 1, 0, 0, 2037.27, -73.9782, 338.415, 2.45097, 300, 0, 0, 14433076, 0, 0, 0, 0, 0),
(33244, 603, 2, 1, 0, 0, 1938.16, 43.9725, 338.46, 5.30923, 300, 0, 0, 14433076, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80 WHERE `entry`=33943;
UPDATE `gameobject_template` SET `ScriptName`='go_flee_to_surface' WHERE `entry`=194625;
UPDATE `item_template` SET `ScriptName`='item_unbound_fragments_of_valanyr' WHERE `entry`=45896;
UPDATE `creature_template` SET `RegenHealth`=0 WHERE `entry` IN (33134,34332,33890,33954); -- No health regeneration - tentacles.

DELETE FROM `gameobject` WHERE `id`=194625;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES 
(194625, 603, 3, 1, 2001.4, -59.66, 245.07, 0, 0, 0, 0, 0, 60, 100, 1),
(194625, 603, 3, 1, 1941.61, -25.88, 244.98, 0, 0, 0, 0, 0, 60, 100, 1),
(194625, 603, 3, 1, 2001.18, 9.409, 245.24, 0, 0, 0, 0, 0, 60, 100, 1);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (64466,64139,64143,64133,63120,64174,64172,63802,64164,64168,62670,62671,62702,62650);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(64466,'spell_empowering_shadows'),             -- Heal Trigger for Empowering Shadows
(64139,'spell_summon_tentacle_position'),       -- Correct Summon Position of Tentacle
(64143,'spell_summon_tentacle_position'),
(64133,'spell_summon_tentacle_position'),
(63120,'spell_insane_death_effekt'),            -- Insane Death trigger on Remove
(64174,'spell_hodir_protective_gaze'),          -- Hodir Secound Aura Script
(64172,'spell_titanic_storm_targeting'),        -- Needed for Titanic Storm, Script for Target have Weakened Aura
(63802,'spell_brain_link_periodic_dummy'),      -- Trigger Effekt on Near Player with Brain Link
(64164,'spell_lunatic_gaze_targeting'),
(64168,'spell_lunatic_gaze_targeting'),         -- Script for Target Faces Caster
(62670,'spell_keeper_support_aura_targeting'),  -- Auras shouldn't hit other friendly NPCs
(62671,'spell_keeper_support_aura_targeting'),
(62702,'spell_keeper_support_aura_targeting'),
(62650,'spell_keeper_support_aura_targeting');

DELETE FROM `conditions` WHERE SourceEntry IN (64184, 63882, 63886, 64172, 64465, 65209);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 0, 64184, 0, 0, 18, 0, 1, 33288, 0, 0, 0, '', 'Effekt on YoggSaron'), -- Create Val'anyr on Yogg-Saron
(13, 0, 63882, 0, 0, 18, 0, 1, 33882, 0, 0, 0, '', 'Effekt on Death Orb'), -- Deathray Effekt on Death Orb
(13, 0, 63886, 0, 0, 18, 0, 1, 33882, 0, 0, 0, '', 'Effekt on Death Orb'),
(13, 0, 64172, 0, 0, 18, 0, 1, 33988, 0, 0, 0, '', 'Effekt only for Immortal Guardians'), -- Condition because NPCs need this else no hit
(13, 0, 64465, 0, 0, 18, 0, 1, 33988, 0, 0, 0, '', 'Effekt only for Immortal Guardians'),
(13, 0, 65209, 0, 0, 18, 0, 1, 33136, 0, 0, 0, '', 'Effekt only for Guardian of YoggSaron'), -- Second Damage Effekt of ShadowNova only on other Guardians or Sara
(13, 0, 65209, 0, 0, 18, 0, 1, 33134, 0, 0, 0, '', 'Effekt only for Sara');

-- Missing Says Vision
UPDATE `script_texts` SET `npc_entry`=33134 WHERE `npc_entry`=33288 AND `entry` IN (-1603330,-1603331,-1603332,-1603333);
UPDATE `script_texts` SET `content_default`='Help me! Please get them off me!' WHERE `npc_entry`=33134 AND `entry`=-1603310;
UPDATE `script_texts` SET `content_default`='What do you want from me? Leave me alone!' WHERE `npc_entry`=33134 AND `entry`=-1603311;
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1603360 AND -1603342;
INSERT INTO `script_texts` VALUES 
(33535, -1603359, 'It is a weapon like no other. It must be like no other.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15610, 0, 0, 0, 'Malygos DragonSoulVision_Say'),
(33523, -1603356, 'It is done... All have been given that which must be given. I now seal the Dragon Soul forever...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15631, 0, 0, 0, 'Neltharion DragonSoulVision_Say1'),
(33495, -1603357, 'That terrible glow... should that be?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15702, 0, 0, 0, 'Ysera DragonSoulVision_Say'),
(33523, -1603358, 'For it to be as it must, yes.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15632, 0, 0, 0, 'Neltharion DragonSoulVision_Say2'),
(33288, -1603355, 'He will learn... no king rules forever, only death is eternal!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15767, 0, 0, 0, 'YoggSaron LichKingVision_Say2'),
(33288, -1603354, 'Yrr n\'lyeth... shuul anagg!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15766, 0, 0, 0, 'YoggSaron LichKingVision_Say1'),
(33441, -1603353, 'I will break you as I broke him.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15599, 0, 0, 0, 'TheLichKing LichKingVision_Say2'),
(33442, -1603351, 'Arrrrrrgh!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15470, 1, 0, 0, 'ImmolatedChampion LichKingVision_Say1'),
(33442, -1603352, 'I\'m not afraid of you!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15471, 0, 0, 0, 'ImmolatedChampion LichKingVision_Say2'),
(33436, -1603348, 'The orc leaders agree with your assessment.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15541, 0, 0, 0, 'Garona KingLlaneVision_Say4'),
(33288, -1603349, 'Your petty quarrels only make me stronger!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15764, 0, 0, 0, 'YoggSaron KingLlaneVision_Say3'),
(33288, -1603360, 'His brood learned their lesson before too long, you shall soon learn yours!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15765, 0, 0, 0, 'YoggSaron DragonSoulVision_Say1'),
(33441, -1603350, 'Your resilience is admirable.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15598, 0, 0, 0, 'TheLichKing LichKingVision_Say1'),
(33288, -1603346, '', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15763, 0, 0, 0, 'YoggSaron KingLlianeVision_Say2'),
(33437, -1603347, 'We will hold until the reinforcements come. As long as men with stout hearts are manning the walls and throne Stormwind will hold.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15585, 0, 0, 0, 'KingLlane KingLlaneVision_Say'),
(33436, -1603344, 'Gul\'dan is bringing up his warlocks by nightfall. Until then, the Blackrock clan will be trying to take the Eastern Wall.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15540, 0, 0, 0, 'Garona KingLlaneVision_Say3'),
(33288, -1603345, 'A thousand deaths... or one murder.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15762, 0, 0, 0, 'YoggSaron KingLlaneVision_Say1'),
(33436, -1603342, 'Bad news sire.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15538, 0, 0, 0, 'Garona KingLlaneVision_Say1'),
(33436, -1603343, 'The clans are united under Blackhand in this assault. They will stand together until Stormwind has fallen.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 15539, 0, 0, 0, 'Garona KingLlaneVision_Say2');

-- Various things'
-- Update mechanic immunity flags.
UPDATE `creature_template` SET `mechanic_immune_mask`=650853247, `flags_extra`=1 WHERE `entry` IN 
(
33113, 34003,  -- Flame Leviathan
33118, 33190,  -- Ignis the Furnace Master
33186, 33724,  -- Razorscale
33293, 33885,  -- XT002
32867, 33693,  -- Steelbreaker
32927, 33692,  -- Runemaster Molgeim
32930, 33909,  -- Kologarn
32906, 33360,  -- Freya
32845, 32846,  -- Hodir
33350,         -- Mimiron
33432, 34106,  -- Leviathan MK II
33651, 34108,  -- VX-001
33670, 34109,  -- Aerial Unit
32865, 33147,  -- Thorim
33271, 33449,  -- General Vezax
33524, 34152,  -- Saronite Animus
33288, 33955,  -- Yogg-Saron
33134, 34332,  -- Sara
33890, 33954   -- Brain of Yogg-Saron
);

-- updating giant immunities
UPDATE creature_template SET mechanic_immune_mask = 650854239 WHERE entry IN (33149, 33148);

-- assigning 25m version of Brain of Yogg-Saron to the normal version
UPDATE creature_template SET difficulty_entry_1 = 33954 WHERE entry = 33890;

-- Auriaya should be interruptible, due to Sentinel Blast
UPDATE `creature_template` SET `mechanic_immune_mask`=617298815 WHERE `entry` IN (33515);
-- Stormcaller Brundir, immunities to stun and interrupt are gained infight.
UPDATE `creature_template` SET `mechanic_immune_mask`=617296767, `flags_extra`=1 WHERE `entry` IN (32857);   

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
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (63059, 'spell_pollinate');

DELETE FROM `spell_linked_spell` WHERE  `spell_trigger`=62317 AND `spell_effect`=57807 AND `type`=1;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (62317, 57807, 1, 'Twilight Guardian - Link Devastate to Sunder Armor');

-- Other stuff
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~(33554432|262144) WHERE `entry`=34184;

-- Auriaya
-- Yes, I know this is hack-like, but as long as it works.... :D
DELETE FROM `spell_group` WHERE `id`=64381;
DELETE FROM `spell_group_stack_rules` WHERE `group_id`=64381;
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES (64381, 64381);
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES (64381, 1);

-- CUSTOM
-- Superheated winds, Razorscale controller and Razorscale Devouring Flame Stalker invisibility
UPDATE creature_template SET modelid1 = 0 WHERE entry IN (34194, 34188, 34189, 33233);

-- Magma Rager
UPDATE creature_template SET AIName='SmartAI' WHERE entry = 34086;
DELETE FROM smart_scripts WHERE entryorguid = 34086;
INSERT INTO smart_scripts (entryorguid, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, target_type, comment) VALUES 
(34086, 6, 5000, 10000, 5000, 10000, 11, 5, 'Magma Rager - Cast Fire Blast');

-- Forge Construct
UPDATE creature_template SET AIName='SmartAI' WHERE entry = 34085;
DELETE FROM smart_scripts WHERE entryorguid = 34085;
INSERT INTO smart_scripts (entryorguid, event_type, event_flags, action_type, action_param1, target_type, comment) VALUES
(34085, 4, 6, 11, 64719, 2, 'Forge Construct - Cast Charge');
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34085, 1, 0, 2, 5000, 15000, 5000, 15000, 11, 64720, 2, 'Forge Construct - Cast Flame Emission'),
(34085, 2, 0, 4, 5000, 15000, 5000, 15000, 11, 64721, 2, 'Forge Construct - Cast Flame Emission');

-- making some objects be spawned in all versions of Ulduar
UPDATE gameobject SET spawnMask = 15 WHERE guid IN (35446, 35393, 35413, 35417, 55630, 34041, 54961, 54971, 55043, 55194, 35381, 35462, 42047, 42076, 42520, 42543, 42649, 42868, 42916, 42918, 42919, 42958, 43112, 43115, 44885, 45021, 45090, 45094, 45096, 45097, 45116, 4784597, 4784598,
45175, 45209, 48905, 50363, 55002, 55692, 55702, 127, 55734, 55862, 55926, 55965, 34155, 281, 35467, 35497, 35516, 35517, 42960, 43113, 43114, 44883, 34057, 45225, 45229, 45230, 45500, 56130, 56244, 56245, 56295, 56296, 56301, 56312, 56351, 56359, 56372, 56411, 54995, 55078, 56422, 56424, 56426, 
289, 35524, 56107, 56125, 42867, 42879, 55974, 55647, 285) OR id IN (194569, 189973, 190170, 190171, 191019, 194905, 194907) AND map = 603;

-- disabling movement of Ironwork Cannon
UPDATE creature_template SET unit_flags = unit_flags | 4 WHERE entry = 33264;

-- enlarging hitbox of bosses
UPDATE creature_model_info SET bounding_radius = 1.085, combat_reach = 10.5 WHERE modelid IN (28787, 29185, 28611, 28324, 28344, 28381, 28651, 28777, 28548, 28817);

-- adding weapons to Expedition Trappers and Expedition Engineers
UPDATE creature_template SET equipment_id = 1762 WHERE entry = 34257;
UPDATE creature_template SET equipment_id = 361 WHERE entry = 34256;

-- updating Razorscale Controller positions and making them not selectable
DELETE FROM creature WHERE guid BETWEEN 48304 AND 48310;
INSERT INTO creature (guid, id, map, spawnMask, position_x, position_y, position_z) VALUES
(48304, 33233, 603, 2, 560.133, -143.035, 393.823),
(48306, 33233, 603, 3, 588.673, -136.835, 391.517),
(48307, 33233, 603, 2, 603.931, -142.889, 391.517),
(48308, 33233, 603, 3, 572.654, -139.375, 391.517);
UPDATE creature_template SET unit_flags = unit_flags | 33554432 WHERE entry = 33233;

-- small Emote to Say correction
UPDATE script_texts SET type = 3 WHERE entry = -1603266;

-- XD-175 Compactobot
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34271;
DELETE FROM smart_scripts WHERE entryorguid = 34271;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, target_param1, target_param2, comment) VALUES
(34271, 0, 0, 2, 10000, 20000, 10000, 20000, 11, 65073, 17, 10, 40, 'XD-175 Compactobot - Cast Trash Compactor'),
(34271, 1, 0, 4, 10000, 20000, 10000, 20000, 11, 65106, 17, 10, 40, 'XD-175 Compactobot - Cast Trash Compactor');

-- Parts Recovery Technician
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34267;
DELETE FROM smart_scripts WHERE entryorguid = 34267;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34267, 0, 0, 6, 10000, 20000, 10000, 20000, 11, 65071, 2, 'Parts Recovery Technician - Cast Mechano Kick'),
(34267, 1, 0, 6, 5000, 10000, 20000, 25000, 11, 65070, 1, 'Parts Recovery Technician - Cast Defense Matrix');

-- XB-488 Disposalbot
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34273;
DELETE FROM smart_scripts WHERE entryorguid = 34273;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34273, 0, 0, 2, 2000, 5000, 5000, 7000, 11, 65080, 2, 'XB-488 Disposalbot - Cast Cut Scrap Metal'),
(34273, 1, 0, 4, 2000, 5000, 5000, 7000, 11, 65104, 2, 'XB-488 Disposalbot - Cast Cut Scrap Metal'),
(34273, 2, 2, 6, 1, 15, 0, 0, 11, 65084, 1, 'XB-488 Disposalbot - Cast Self Destruct');

-- TODO: XR-949 Salvagebot

-- Lightning Charged Iron Dwarf
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34199;
DELETE FROM smart_scripts WHERE entryorguid = 34199;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, action_type, action_param1, target_type, comment) VALUES
(34199, 0, 4, 2, 11, 64889, 1, 'Lightning Charged Iron Dwarf - Cast Lightning Charged'),
(34199, 1, 4, 4, 11, 64975, 1, 'Lightning Charged Iron Dwarf - Cast Lightning Charged');

-- Hardened Iron Golem
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34190;
DELETE FROM smart_scripts WHERE entryorguid = 34190;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34190, 0, 0, 2, 5000, 10000, 15000, 20000, 11, 64874, 2, 'Hardened Iron Golem - Cast Rune Punch'),
(34190, 1, 0, 4, 5000, 10000, 15000, 20000, 11, 64967, 2, 'Hardened Iron Golem - Cast Rune Punch'),
(34190, 2, 0, 6, 5000, 10000, 15000, 20000, 11, 64877, 1, 'Hardened Iron Golem - Cast Harden Fists');

-- Iron Mender
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34198;
DELETE FROM smart_scripts WHERE entryorguid = 34198;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34198, 0, 0, 2, 5000, 10000, 10000, 20000, 11, 64918, 2, 'Iron Mender - Cast Electro Shock'),
(34198, 1, 0, 4, 5000, 10000, 10000, 20000, 11, 64971, 2, 'Iron Mender - Cast Electro Shock'),
(34198, 2, 0, 2, 5000, 10000, 20000, 25000, 11, 64903, 5, 'Iron Mender - Cast Fuse Lightning'),
(34198, 3, 0, 4, 5000, 10000, 20000, 25000, 11, 64970, 5, 'Iron Mender - Cast Fuse Lightning'),
(34198, 4, 14, 2, 20000, 40, 15000, 20000, 11, 64897, 7, 'Iron Mender - Cast Fuse Metal'),
(34198, 5, 14, 4, 50000, 40, 15000, 20000, 11, 64968, 7, 'Iron Mender - Cast Fuse Metal');

-- Rune Etched Sentry
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34196;
DELETE FROM smart_scripts WHERE entryorguid = 34196;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34196, 0, 0, 2, 5000, 7000, 10000, 20000, 11, 64852, 5, 'Rune Etched Sentry - Cast Flaming Rune'),
(34196, 1, 0, 2, 5000, 10000, 10000, 15000, 11, 64870, 2, 'Rune Etched Sentry - Cast Lava Burst'),
(34196, 2, 0, 4, 5000, 10000, 10000, 15000, 11, 64991, 2, 'Rune Etched Sentry - Cast Lava Burst'),
(34196, 3, 0, 2, 7000, 10000, 10000, 15000, 11, 64847, 2, 'Rune Etched Sentry - Cast Runed Flame Jets'),
(34196, 4, 0, 4, 7000, 10000, 10000, 15000, 11, 64988, 2, 'Rune Etched Sentry - Cast Runed Flame Jets');

-- Chamber Overseer (TODO: Displacement Device)
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34197;
DELETE FROM smart_scripts WHERE entryorguid = 34197;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, target_param1, target_param2, comment) VALUES
(34197, 0, 0, 2, 10000, 15000, 10000, 20000, 11, 64820, 17, 10, 80, 'Chamber Overseer - Cast Devastating Leap'),
(34197, 1, 0, 4, 10000, 15000, 10000, 15000, 11, 64943, 17, 10, 80, 'Chamber Overseer - Cast Devastating Leap'),
(34197, 2, 0, 2, 5000, 10000, 10000, 15000, 11, 64825, 2, 0, 0, 'Chamber Overseer - Cast Staggering Roar'),
(34197, 3, 0, 4, 5000, 10000, 10000, 15000, 11, 64944, 2, 0, 0, 'Chamber Overseer - Cast Staggering Roar');

-- Dark Rune Ravager
UPDATE creature_template SET ScriptName = '', AIName = 'SmartAI' WHERE entry = 33755;
DELETE FROM smart_scripts WHERE entryorguid = 33755;
INSERT INTO smart_scripts (entryorguid, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(33755, 0, 6, 2000, 2000, 2000, 2000, 11, 63615, 2, 'Dark Rune Ravager - Cast Ravage Armor');

-- Dark Rune Thunderer
UPDATE creature_template SET ScriptName = '', AIName = 'SmartAI' WHERE entry = 33754;
DELETE FROM smart_scripts WHERE entryorguid = 33754;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(33754, 0, 0, 2, 3000, 3000, 2000, 3000, 11, 63612, 2, 'Dark Rune Thunderer - Cast Lightning Brand'),
(33754, 1, 0, 4, 3000, 3000, 2000, 3000, 11, 63673, 2, 'Dark Rune Thunderer - Cast Lightning Brand');

-- Arachnopod Destroyer
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34183;
DELETE FROM smart_scripts WHERE entryorguid = 34183;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34183, 0, 4, 6, 0, 0, 0, 0, 11, 64779, 2, 'Arachnopod Destroyer - Cast Charged Leap'),
(34183, 1, 0, 6, 5000, 10000, 10000, 15000, 11, 64717, 2, 'Arachnopod Destroyer - Cast Flame Spray'),
(34183, 2, 0, 6, 10000, 20000, 20000, 30000, 11, 64776, 2, 'Arachnopod Destroyer - Cast Machine Gun');

-- Clockwork Mechanic
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34184;
DELETE FROM smart_scripts WHERE entryorguid = 34184;
INSERT INTO smart_scripts (entryorguid, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34184, 2, 6, 0, 50, 20000, 30000, 11, 64966, 1, 'Clockwork Mechanic - Cast Ice Turret');

-- Ice Turret (spawned by Clockwork Mechanics)
UPDATE creature_template SET unit_flags = unit_flags | 4, AIName = 'SmartAI' WHERE entry = 34224;
DELETE FROM smart_scripts WHERE entryorguid = 34224;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34224, 0, 0, 2, 2000, 5000, 15000, 30000, 11, 66346, 1, 'Ice Turret - Cast Ice Nova'),
(34224, 1, 0, 4, 2000, 5000, 15000, 30000, 11, 64919, 1, 'Ice Turret - Cast ce Nova');

-- TODO: Boomer XP-500

-- Champion of Hodir
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34133;
DELETE FROM smart_scripts WHERE entryorguid = 34133;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34133, 0, 0, 2, 10000, 15000, 10000, 15000, 11, 64639, 1, 'Champion of Hodir - Cast Stomp'),
(34133, 1, 0, 4, 10000, 15000, 10000, 15000, 11, 64652, 1, 'Champion of Hodir - Cast Stomp'),
(34133, 2, 0, 6, 15000, 20000, 15000, 20000, 11, 64649, 2, 'Champion of Hodir - Cast Freezing Breath');

-- Winter Jormungar
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34137;
DELETE FROM smart_scripts WHERE entryorguid = 34137;
INSERT INTO smart_scripts (entryorguid, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34137, 0, 6, 5000, 10000, 5000, 10000, 11, 64638, 2, 'Winter Jormungar - Cast Acidic Bite');

-- Winter Revenant
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34134;
DELETE FROM smart_scripts WHERE entryorguid = 34134;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34134, 0, 0, 2, 5000, 15000, 10000, 15000, 11, 64642, 1, 'Winter Revenant - Cast Blizzard'),
(34134, 1, 0, 4, 5000, 15000, 10000, 15000, 11, 64653, 1, 'Winter Revenant - Cast Blizzard'),
(34134, 2, 4, 6, 0, 0, 0, 0, 11, 64644, 1, 'Winter Revenant - Cast Shield of the Winter Revenant'),
(34134, 3, 0, 6, 15000, 20000, 15000, 20000, 11, 64643, 1, 'Winter Revenant - Cast Whirling Strike');

-- Winter Rumbler
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry = 34135;
DELETE FROM smart_scripts WHERE entryorguid = 34135;
INSERT INTO smart_scripts (entryorguid, id, event_type, event_flags, event_param1, event_param2, event_param3, event_param4, action_type, action_param1, target_type, comment) VALUES
(34135, 0, 0, 2, 5000, 10000, 10000, 15000, 11, 64645, 2, 'Winter Rumbler - Cast Cone of Cold'),
(34135, 1, 0, 4, 5000, 10000, 10000, 15000, 11, 64655, 2, 'Winter Rumbler - Cast Cone of Cold'),
(34135, 2, 0, 2, 10000, 20000, 10000, 20000, 11, 64647, 6, 'Winter Rumbler - Cast Snow Blindness'),
(34135, 3, 0, 4, 10000, 20000, 10000, 20000, 11, 64654, 6, 'Winter Rumbler - Cast Snow Blindness');

-- Nature bomb, Unstable energy model correction
UPDATE creature_template SET modelid1 = 0 WHERE entry IN (34129, 34153, 33050, 33170, 33395, 33402);

-- Thorims trap bunny shouldnt be able to move
UPDATE creature_template SET unit_flags = unit_flags | 4 WHERE entry = 33054;

-- spawning Keeper images
DELETE FROM creature WHERE id IN (33241, 33242, 33244, 33213);
INSERT INTO creature (id, map, spawnMask, position_x, position_y, position_z, orientation, curhealth) VALUES
(33241, 603, 3, 1939.06, 42.3925, 411.356, 5.25215, 14433075),
(33213, 603, 3, 1939.64, -90.9194, 411.356, 0.940322, 14433075),
(33244, 603, 3, 2037.32, 25.9017, 411.358, 3.81488, 14433075),
(33242, 603, 3, 2037.03, -73.8742, 411.355, 2.35011, 14433075);

-- correcting respawn timer of Enslaved Fire Elemental
UPDATE creature SET spawntimesecs = 604800 WHERE id = 33838;
