--
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (33651, 33432); 
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`) VALUES 
(33651, 34050, 5, 1, 'VX-001 Rocket Seat 6', 8),
(33651, 34050, 6, 1, 'VX-001 Rocket Seat 7', 8),
(33432, 34071, 3, 1, 'MKII MKII turret Seat 1', 8); 

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (33651, 33432); 
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(33651, 46598, 1, 1),
(33432, 46598, 1, 1); 

DELETE FROM `spell_script_names` WHERE `spell_id` IN (63274, 63414, 63667, 63382, 64402, 65034, 63681, 64542, 65192, 64570, 63027, 65346, 66351, 65224, 63009, 64620, 63820, 64425, 64426, 64621, 64398, 64567, 64619, 64623, 64627, 65354, 64626, 64618, 65333, 64436, 63340, 64383, 63339, 64562, 63041, 63801, 64463);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63801, 'spell_mimiron_bomb_bot'),
(65192, 'spell_mimiron_clear_fires'),
(65224, 'spell_mimiron_clear_fires'), 
(64619, 'spell_mimiron_clear_fires'), 
(65354, 'spell_mimiron_clear_fires'), 
(64463, 'spell_mimiron_despawn_assault_bots'), 
(64618, 'spell_mimiron_fire_search'), 
(64570, 'spell_mimiron_flame_suppressant'),
(64626, 'spell_mimiron_frost_bomb_explosion'),
(65333, 'spell_mimiron_frost_bomb_explosion'),
(64436, 'spell_mimiron_magnetic_core'),
(63667, 'spell_mimiron_napalm_shell'),
(63274, 'spell_mimiron_p3wx2_laser_barrage'),
(64542, 'spell_mimiron_plasma_blast'),
(63027, 'spell_mimiron_proximity_mines'),
(66351, 'spell_mimiron_proximity_explosion'),
(63009, 'spell_mimiron_proximity_explosion'),
(65346, 'spell_mimiron_proximity_trigger'),
(63382, 'spell_mimiron_rapid_burst'),
(64402, 'spell_mimiron_rocket_strike'),
(65034, 'spell_mimiron_rocket_strike'),
(63041, 'spell_mimiron_rocket_strike_damage'),
(63681, 'spell_mimiron_rocket_strike_target_select'),
(64383, 'spell_mimiron_self_repair'),
(63414, 'spell_mimiron_spinning_up'),
(64426, 'spell_mimiron_summon_assault_bot'),
(64425, 'spell_mimiron_summon_assault_bot_target'),
(64621, 'spell_mimiron_summon_fire_bot'),
(64620, 'spell_mimiron_summon_fire_bot_target'),
(64567, 'spell_mimiron_summon_flames_initial'),
(64562, 'spell_mimiron_summon_flames_spread'),
(64627, 'spell_mimiron_summon_frost_bomb'),
(64623, 'spell_mimiron_summon_frost_bomb_target'),
(64398, 'spell_mimiron_summon_junk_bot'),
(63820, 'spell_mimiron_summon_junk_bot_target'),
(63339, 'spell_mimiron_weld');

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (66351, 64019, 63387, 62997, 64348, 64352, 63689, 65647, 63677, 63679, 64626); 
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES 
(64348, 64348, 64536),
(64352, 64352, 64537),
(66351, 66351, 63009),
(63387, 63387, 64531),
(64019, 64019, 64532),
(62997, 62997, 64529),
(63689, 63689, 64535),
(65647, 65647, 65648),
(63677, 63677, 64533),
(63679, 63679, 64534),
(64626, 64626, 65333);

DELETE FROM `conditions` WHERE `SourceEntry` IN (65192, 64570, 63274, 66490, 63300, 63414, 64539, 64402, 65034, 63041, 65224, 64620, 63820, 64425, 64619, 64626, 65333, 65354, 64618, 64623, 64436, 64444, 65101, 64463);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 65192, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Flame Suppressant VX EFFECT_0 can only hit NPC_FLAME'),
(13, 1, 65192, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Flame Suppressant VX EFFECT_0 can only hit NPC_FLAME_SPREAD'),
(13, 2, 64570, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Flame Suppressant MK EFFECT_1 can only hit NPC_FLAME'),
(13, 2, 64570, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Flame Suppressant MK EFFECT_1 can only hit NPC_FLAME_SPREAD'),
(13, 1, 64623, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Frost Bomb EFFECT_0 can only hit NPC_FLAME'),
(13, 1, 64623, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Frost Bomb EFFECT_0 can only hit NPC_FLAME_SPREAD'),
(13, 4, 64626, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Explosion EFFECT_2 can only hit NPC_FLAME'),
(13, 4, 64626, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Explosion EFFECT_2 can only hit NPC_FLAME_SPREAD'),
(13, 4, 65333, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Explosion EFFECT_2 can only hit NPC_FLAME'),
(13, 4, 65333, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Explosion EFFECT_2 can only hit NPC_FLAME_SPREAD'),
(13, 1, 65224, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Clear Fires EFFECT_0 can only hit NPC_FLAME'),
(13, 1, 65224, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Clear Fires EFFECT_0 can only hit NPC_FLAME_SPREAD'),
(13, 1, 65354, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Clear Fires EFFECT_0 can only hit NPC_FLAME'),
(13, 1, 65354, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Clear Fires EFFECT_0 can only hit NPC_FLAME_SPREAD'),
(13, 1, 64619, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Water Spray EFFECT_0 can only hit NPC_FLAME'),
(13, 1, 64619, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Water Spray EFFECT_0 can only hit NPC_FLAME_SPREAD'),
(13, 1, 64618, 0, 0, 31, 0, 3, 34363, 0, 0, 0, 0, '', 'Fire Search EFFECT_0 can only hit NPC_FLAME'),
(13, 1, 64618, 0, 1, 31, 0, 3, 34121, 0, 0, 0, 0, '', 'Fire Search EFFECT_0 can only hit NPC_FLAME_SPREAD'),
(13, 1, 64539, 0, 0, 31, 0, 3, 34071, 0, 0, 0, 0, '', 'Napalm Shell EFFECT_0 can only hit NPC_LEVIATHAN_MKII_TURRET'),
(13, 1, 63274, 0, 0, 31, 0, 3, 33576, 0, 0, 0, 0, '', 'P3Wx2 Laser Barrage EFFECT_0 can only hit NPC_DB_TARGET'),
(17, 0, 66490, 0, 0, 31, 0, 3, 33432, 0, 0, 0, 0, '', 'P3Wx2 Laser Barrage can only hit NPC_LEVIATHAN_MKII'),
(17, 0, 63300, 0, 0, 31, 0, 3, 33651, 0, 0, 0, 0, '', 'P3Wx2 Laser Barrage can only hit NPC_VX_001'),
(13, 1, 63414, 0, 0, 31, 0, 3, 33576, 0, 0, 0, 0, '', 'Spinning Up EFFECT_0 can only hit NPC_DB_TARGET'),
(13, 2, 63414, 0, 1, 31, 0, 3, 33432, 0, 0, 0, 0, '', 'Spinning Up EFFECT_1 can only hit NPC_LEVIATHAN_MKII'),
(13, 1, 64620, 0, 0, 31, 0, 3, 33856, 0, 0, 0, 0, '', 'Summon Fire Bot Trigger EFFECT_0 can only hit NPC_BOT_SUMMON_TRIGGER'),
(13, 1, 63820, 0, 0, 31, 0, 3, 33856, 0, 0, 0, 0, '', 'Summon Junk Bot Trigger EFFECT_0 can only hit NPC_BOT_SUMMON_TRIGGER'),
(13, 1, 64425, 0, 0, 31, 0, 3, 33856, 0, 0, 0, 0, '', 'Summon Assault Bot Trigger EFFECT_0 can only hit NPC_BOT_SUMMON_TRIGGER'),
(13, 1, 64402, 0, 0, 31, 0, 3, 34050, 0, 0, 0, 0, '', 'Rocket Strike EFFECT_0 can only hit NPC_ROCKET_MIMIRON_VISUAL'),
(13, 1, 65034, 0, 0, 31, 0, 3, 34050, 0, 0, 0, 0, '', 'Rocket Strike EFFECT_0 can only hit NPC_ROCKET_MIMIRON_VISUAL'),
(13, 2, 64436, 0, 0, 31, 0, 3, 33670, 0, 0, 0, 0, '', 'Magnetic Core EFFECT_1 can only hit NPC_AERIAL_COMMAND_UNIT'),
(13, 1, 64444, 0, 0, 31, 0, 3, 33670, 0, 0, 0, 0, '', 'Magnetic Core EFFECT_0 can only hit NPC_AERIAL_COMMAND_UNIT'),
(13, 1, 65101, 0, 0, 31, 0, 3, 34071, 0, 0, 0, 0, '', 'Emergency Mode EFFECT_0 can only hit NPC_LEVIATHAN_MKII_TURRET'),
(13, 1, 64463, 0, 0, 31, 0, 3, 34057, 0, 0, 0, 0, '', 'Despawn Assault Bots EFFECT_1 can only hit NPC_ASSAULT_BOT'),
(13, 2, 63041, 0, 0, 31, 0, 3, 34057, 0, 0, 0, 0, '', 'Rocket Strike EFFECT_1 can only hit NPC_ASSAULT_BOT'),
(13, 4, 63041, 0, 1, 31, 0, 3, 34137, 0, 0, 0, 0, '', 'Rocket Strike EFFECT_2 can only hit NPC_EMERGENCY_FIRE_BOT'),
(13, 4, 63041, 0, 2, 31, 0, 3, 33855, 0, 0, 0, 0, '', 'Rocket Strike EFFECT_2 can only hit NPC_JUNK_BOT'),
(13, 4, 63041, 0, 3, 31, 0, 3, 33836, 0, 0, 0, 0, '', 'Rocket Strike EFFECT_2 can only hit NPC_BOMB_BOT');

UPDATE `creature_template` SET `HoverHeight` = 15, `ScriptName` = 'boss_aerial_command_unit', `InhabitType` = 3, `mechanic_immune_mask` = 646135679 WHERE `entry` = 33670;
UPDATE `creature_template` SET `HoverHeight` = 15, `InhabitType` = 3, `mechanic_immune_mask` = 646135679 WHERE `entry` = 34109;
UPDATE `creature_template` SET `unit_flags` = 33554438, `ScriptName` = 'boss_vx_001', `mechanic_immune_mask` = 646135679 WHERE `entry` = 33651;
UPDATE `creature_template` SET `unit_flags` = 33554438, `mechanic_immune_mask` = 646135679 WHERE `entry` = 34108;
UPDATE `creature_template` SET `ScriptName` = 'boss_leviathan_mk_ii', `mechanic_immune_mask` = 646135679 WHERE `entry` = 33432;
UPDATE `creature_template` SET `mechanic_immune_mask` = 646135679 WHERE `entry` = 34106;
UPDATE `creature_template` SET `ScriptName` = 'boss_mimiron' WHERE `entry` = 33350;
UPDATE `creature_template` SET `unit_flags` = 131078, `ScriptName` = 'npc_mimiron_proximity_mine' WHERE `entry` = 34362;
UPDATE `creature_template` SET `unit_flags` = 33685510, `faction` = 14, `ScriptName` = 'npc_mimiron_frost_bomb' WHERE `entry` = 34149;
UPDATE `creature_template` SET `unit_flags` = 33685510  WHERE `entry` IN( 34047, 34110, 34050, 34071);
UPDATE `creature_template` SET `unit_flags` = 33685510, `ScriptName` = 'npc_magnetic_core' WHERE `entry` = 34068;
UPDATE `creature_template` SET `unit_flags` = 33554436, `ScriptName` = 'npc_mimiron_flames' WHERE `entry` IN (34363, 34121);
UPDATE `creature_template` SET `faction` = 14 , `ScriptName` = 'npc_mimiron_emergency_fire_bot' WHERE `entry` = 34147; 
UPDATE `creature_template` SET `faction` = 14 WHERE `entry` IN (34148, 34114, 33855);
UPDATE `creature_template` SET `dmg_multiplier` = 60, `ScriptName` = 'npc_mimiron_assault_bot' WHERE `entry` = 34057; 
UPDATE `creature_template` SET `dmg_multiplier` = 75 WHERE `entry` = 34115; 
UPDATE `creature_template` SET `ScriptName` = 'npc_mimiron_computer' WHERE `entry` = 34143;
UPDATE `creature_template` SET `speed_walk` = 2.5 , `speed_run` = 4.5 , `MovementType` = 2 , `InhabitType` = 7, `flags_extra` = 2 WHERE `entry` = 33576;

UPDATE `creature_model_info` SET `bounding_radius` = 0.31 , `combat_reach` = 5 WHERE `modelid` = 28979; 
UPDATE `creature_model_info` SET `bounding_radius` = 0.306 , `combat_reach` = 7 WHERE `modelid` = 28841; 
UPDATE `creature_model_info` SET `bounding_radius` = 0.31 , `combat_reach` = 7.7 WHERE `modelid` = 28831; 

UPDATE `gameobject_template` SET `flags` = 32, `ScriptName` = 'go_mimiron_hardmode_button' WHERE `entry` = 194739;

UPDATE `creature_addon` SET `path_id` = 1376200 WHERE `guid` = 137620;

UPDATE `creature` SET `position_x` = 2785.423 , `position_y` = 2673.119, `MovementType` = 2 WHERE `guid` = 137620;

DELETE FROM `creature_template_addon` WHERE `entry` IN (34047, 34148, 33836, 34149, 34147, 33670, 34363, 34121); 
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(33670, 50331648, 1, ''),
(34363, 0, 1, '64561'),
(34121, 0, 1, '64561'),
(34047, 0, 1, '64064'),
(34148, 0, 1, '64616 64617'),
(33836, 0, 1, '63767'),
(34149, 0, 1, '64624'),
(34147, 0, 1, '64617');

DELETE FROM `creature_text` WHERE `entry` = 34143;
INSERT INTO `creature_text` (`entry`, `groupid`, `text`, `type`, `probability`, `sound`, `BroadcastTextID`) VALUES 
(34143, 0, 'Self-destruct sequence initiated.', 14, 100, 15413, 34268),
(34143, 1, 'Self-destruct sequence terminated. Override code A905..', 14, 100, 15414, 34284),
(34143, 2, 'This area will self-destruct in ten minutes.', 14, 100, 15415, 34283),
(34143, 3, 'This area will self-destruct in nine minutes.', 14, 100, 15416, 34282),
(34143, 4, 'This area will self-destruct in eight minutes.', 14, 100, 15417, 34281),
(34143, 5, 'This area will self-destruct in seven minutes.', 14, 100, 15418, 34280),
(34143, 6, 'This area will self-destruct in six minutes.', 14, 100, 15419, 34273),
(34143, 7, 'This area will self-destruct in five minutes.', 14, 100, 15420, 34274),
(34143, 8, 'This area will self-destruct in four minutes.', 14, 100, 15421, 34275),
(34143, 9, 'This area will self-destruct in three minutes.', 14, 100, 15422, 34276),
(34143, 10, 'This area will self-destruct in two minutes.', 14, 100, 15423, 34277),
(34143, 11, 'This area will self-destruct in one minute.', 14, 100, 15424, 34278),
(34143, 12, 'Self-destruct sequence finalized. Have a nice day.', 14, 100, 15425, 34279);

DELETE FROM `waypoint_data` WHERE `id` = 1376200; 
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES 
(1376200, 0, 2785.423, 2673.119, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 1, 2823.024, 2649.059, 371.9791, 0, 0, 1, 0, 100, 0), 
(1376200, 2, 2854.097, 2590.826, 371.9791, 0, 0, 1, 0, 100, 0), 
(1376200, 3, 2852.951, 2547.112, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 4, 2822.796, 2489.515, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 5, 2784.964, 2465.247, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 6, 2741.24, 2456.771, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 7, 2701.036, 2464.319, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 8, 2660.476, 2489.578, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 9, 2636.893, 2525.687, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 10, 2631.294, 2547.831, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 11, 2631.437, 2591.752, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 12, 2637.362, 2613.7, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 13, 2650.221, 2636.163, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 14, 2661.572, 2649.715, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 15, 2696.595, 2672.664, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 16, 2711.099, 2677.791, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 17, 2740.676, 2683.12, 372.3605, 0, 0, 1, 0, 100, 0), 
(1376200, 18, 2771.834, 2677.767, 372.3605, 0, 0, 1, 0, 100, 0);

DELETE FROM `disables` WHERE `sourceType` = 4 AND `entry` IN (10544, 10547, 10543, 10546, 10548, 10545, 10450, 10463, 10406, 10405);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10406, 10405) AND `type` = 18; 
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10545,10548,10546,10543,10547,10544, 10450, 10463) AND `type` = 11; 
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10544, 11, 0, 0, 'achievement_setup_rocket'),
(10547, 11, 0, 0, 'achievement_setup_rocket'),
(10543, 11, 0, 0, 'achievement_setup_mine'),
(10546, 11, 0, 0, 'achievement_setup_mine'),
(10548, 11, 0, 0, 'achievement_setup_boom'),
(10545, 11, 0, 0, 'achievement_setup_boom'),
(10450, 11, 0, 0, 'achievement_firefighter'),
(10463, 11, 0, 0, 'achievement_firefighter');
--
