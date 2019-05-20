-- Template Updates
-- Omnotron
UPDATE `creature_template` SET `flags_extra`= 130, `unit_flags`= 0x02000000, `ScriptName`= 'boss_omnotron_defense_system' WHERE `entry`= 42186;
-- Electron
UPDATE `creature_template` SET `ScriptName`= 'npc_omnotron_electron' WHERE `entry`= 42179;
UPDATE `creature_template` SET `unit_flags2`= 0, `unit_flags`= 0x02000000 | 0x80000000, `DamageModifier`= 120, `mechanic_immune_mask`= 650854271 WHERE `entry` IN (42179, 49047, 49048, 49049);
-- Magmatron
UPDATE `creature_template` SET `ScriptName`= 'npc_omnotron_magmatron' WHERE `entry`= 42178;
UPDATE `creature_template` SET `unit_flags2`= 0, `unit_flags`= 0x02000000 | 0x80000000, `DamageModifier`= 120, `mechanic_immune_mask`= 650854271 WHERE `entry` IN (42178, 49053, 49054, 49055);
-- Toxitron
UPDATE `creature_template` SET `ScriptName`= 'npc_omnotron_toxitron' WHERE `entry`= 42180;
UPDATE `creature_template` SET `unit_flags2`= 0, `unit_flags`= 0x02000000 | 0x80000000, `DamageModifier`= 120, `mechanic_immune_mask`= 650854271 WHERE `entry` IN (42180, 49050, 49051, 49052);
-- Arcanotron
UPDATE `creature_template` SET `ScriptName`= 'npc_omnotron_arcanotron' WHERE `entry`= 42166;
UPDATE `creature_template` SET `unit_flags2`= 0, `unit_flags`= 0x02000000 | 0x80000000, `DamageModifier`= 120, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (42166, 49056, 49057, 49058);
-- Chemical Cloud
UPDATE `creature_template` SET `difficulty_entry_1`= 49118, `difficulty_entry_2`= 49119, `difficulty_entry_3`= 49120 WHERE `entry`= 42934;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 14, `unit_flags` = 33554432, `flags_extra`= 130 WHERE `entry` IN (42934, 49118, 49119, 49120);
-- Poison Bomb
UPDATE `creature_template` SET `difficulty_entry_1`= 49121, `difficulty_entry_2`= 49122, `difficulty_entry_3`= 49123, `ScriptName`= 'npc_omnotron_poison_bomb' WHERE `entry`= 42897;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 14, `baseattacktime`= 1000, `speed_run`= 0.7142 WHERE `entry` IN (42897, 49121, 49122, 49123);
-- Poison Puddle
UPDATE `creature_template` SET `unit_flags` = 33554432, `flags_extra`= 130 WHERE `entry`= 42920;
-- Power Generator
UPDATE `creature_template` SET `unit_flags` = 33554432, `flags_extra`= 130 WHERE `entry`= 42733;
-- Lord Victor Nefarius
UPDATE `creature_template` SET `unit_flags`= 33554496, `flags_extra`= 2, `ScriptName`= 'npc_lord_victor_nefarius_omnotron' WHERE `entry`= 49226;

-- Model Info
UPDATE `creature_model_info` SET `BoundingRadius`= 3.56457, `CombatReach`= 3.45 WHERE `DisplayID`= 32684;
UPDATE `creature_model_info` SET `BoundingRadius`= 3.56457, `CombatReach`= 3.45 WHERE `DisplayID`= 32685;
UPDATE `creature_model_info` SET `BoundingRadius`= 3.56457, `CombatReach`= 3.45 WHERE `DisplayID`= 32688;
UPDATE `creature_model_info` SET `BoundingRadius`= 3.56457, `CombatReach`= 3.45 WHERE `DisplayID`= 32687;
UPDATE `creature_model_info` SET `BoundingRadius`= 0.3, `CombatReach`= 1.5 WHERE `DisplayID`= 37556;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (42166, 42178, 42179, 42180, 42186, 49226);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Omnotron
(42186, 0, 0, 'Electron unit activated.', 14, 0, 100, 0, 0, 21865, 47924, 'Omnotron - Activate Electron'),
(42186, 1, 0, 'Toxitron unit activated.', 14, 0, 100, 0, 0, 21867, 47926, 'Omnotron - Activate Toxitron'),
(42186, 2, 0, 'Magmatron unit activated.', 14, 0, 100, 0, 0, 21866, 47925, 'Omnotron - Activate Magmatron'),
(42186, 3, 0, 'Arcanotron unit activated.', 14, 0, 100, 0, 0, 23378, 47927, 'Omnotron - Activate Arcanotron'),
(42186, 4, 0, 'Electron unit shield systems online.', 14, 0, 100, 0, 0, 21869, 47928, 'Omnotron - Shield Electron'),
(42186, 5, 0, 'Toxitron unit shield systems online.', 14, 0, 100, 0, 0, 21871, 47956, 'Omnotron - Shield Toxitron'),
(42186, 6, 0, 'Arcanotron unit shield systems online.', 14, 0, 100, 0, 0, 21872, 47930, 'Omnotron - Shield Arcanotron'),
(42186, 7, 0, 'Magmatron unit shield systems online.', 14, 0, 100, 0, 0, 21870, 47929, 'Omnotron - Shield Magmatron'),
(42186, 8, 0, 'Rerouting excess energy to Magmatron unit. Engage flamethrower device.', 14, 0, 100, 0, 0, 21873, 47931, 'Omnotron - Magmatron Flamethrower'),
(42186, 9, 0, 'Defense systems obliterated. Powering down...', 14, 0, 100, 0, 0, 21864, 47934, 'Omnotron - Defeat'),
-- Arcanotron
(42166, 0, 0, '|TInterface\\Icons\\spell_arcane_arcaneresilience.blp:20|t%s begins to cast|cFFFE1CF7|Hspell:79729|h [Power Conversion]!|r', 41, 0, 100, 0, 0, 0, 46354, 'Arcanotron'),
-- Magmatron
(42178, 0, 0, '|TInterface\\Icons\\ability_hunter_mastermarksman.blp:20|t%s sets his eye on |cFFFF0000$n|r and begins to cast|cFFFF0000|Hspell:79501|h [Acquiring Target]!|r', 41, 0, 100, 0, 0, 0, 46359, 'Magmatron to Player'),
-- Electron
(42179, 0, 0, '|TInterface\\Icons\\spell_shaman_staticshock.blp:20|t%s casts|cFF1CF2FE|Hspell:79888|h [Lightning Conductor]|h|r at |cFF1CF2FE$n|r!', 41, 0, 100, 0, 0, 0, 47759, 'Electron to Player'),
(42179, 1, 0, '|TInterface\\Icons\\spell_nature_lightningshield.blp:20|t%s begins to cast|cFF1CF2FE|Hspell:79900|h [Unstable Shield]!|r', 41, 0, 100, 0, 0, 0, 46355, 'Electron'),
-- Toxitron
(42180, 0, 0, '|TInterface\\Icons\\spell_nature_nullifydisease.blp:20|t%s begins to cast|cFF1CFE1C|Hspell:79835|h [Poison Soaked Shell]!|r', 41, 0, 100, 0, 0, 0, 46356, 'Toxitron'),
-- Lord Victor Nefarius
(49226, 0, 0, 'Hmm... the Omnotron Defense System. Centuries ago these constructs were considered the Dwarves\' greatest technical achievements. With so many counters to each construct\'s attacks, I\'ll have to rectify these designs for them to provide me any entertainment.', 14, 0, 100, 0, 0, 23374, 49054, 'Lord Victor Nefarius to Player'),
(49226, 1, 0, 'Lightning Conductor works much better in a crowd, yes?', 14, 0, 100, 0, 0, 23377, 49057, 'Lord Victor Nefarius to Player'),
(49226, 2, 0, 'Were you planning on using Toxitron\'s chemicals to damage the other constructs? Clever plan, let me ruin that for you.', 14, 0, 100, 0, 0, 23378, 49058, 'Lord Victor Nefarius to Toxitron'),
(49226, 3, 0, 'You would like to move away from that, wouldn\'t you? Too bad.', 14, 0, 100, 0, 0, 23375, 49055, 'Lord Victor Nefarius to Toxitron'),
(49226, 4, 0, 'Stupid Dwarves and your fascination with runes! Why would you create something that would help your enemy?', 14, 0, 100, 0, 0, 23376, 49056, 'Lord Victor Nefarius to Toxitron');


-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_omnotron_controller_recharge',
'spell_omnotron_recharging',
'spell_omnotron_activated',
'spell_omnotron_inactive',
'spell_omnotron_electrical_discharge',
'spell_omnotron_electrical_discharge_trigger',
'spell_omnotron_unstable_shield',
'spell_omnotron_aquiring_target',
'spell_omnotron_acquiring_target_periodic',
'spell_omnotron_barrier',
'spell_omnotron_shadow_infusion',
'spell_omnotron_shadow_conductor',
'spell_omnotron_overcharge',
'spell_omnotron_overcharged_power_generator');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(78696, 'spell_omnotron_controller_recharge'),
(78697, 'spell_omnotron_recharging'),
(95019, 'spell_omnotron_recharging'),
(95020, 'spell_omnotron_recharging'),
(95021, 'spell_omnotron_recharging'),
(78698, 'spell_omnotron_recharging'),
(95025, 'spell_omnotron_recharging'),
(95026, 'spell_omnotron_recharging'),
(95027, 'spell_omnotron_recharging'),
(78700, 'spell_omnotron_recharging'),
(95022, 'spell_omnotron_recharging'),
(95023, 'spell_omnotron_recharging'),
(95024, 'spell_omnotron_recharging'),
(78699, 'spell_omnotron_recharging'),
(95028, 'spell_omnotron_recharging'),
(95029, 'spell_omnotron_recharging'),
(95030, 'spell_omnotron_recharging'),
(78740, 'spell_omnotron_activated'),
(95016, 'spell_omnotron_activated'),
(95017, 'spell_omnotron_activated'),
(95018, 'spell_omnotron_activated'),
(78726, 'spell_omnotron_inactive'),
(79879, 'spell_omnotron_electrical_discharge'),
(91465, 'spell_omnotron_electrical_discharge'),
(91466, 'spell_omnotron_electrical_discharge'),
(91467, 'spell_omnotron_electrical_discharge'),
(95499, 'spell_omnotron_electrical_discharge_trigger'),
(79900, 'spell_omnotron_unstable_shield'),
(91447, 'spell_omnotron_unstable_shield'),
(91448, 'spell_omnotron_unstable_shield'),
(91449, 'spell_omnotron_unstable_shield'),
(79499, 'spell_omnotron_aquiring_target'),
(79501, 'spell_omnotron_acquiring_target_periodic'),
(92035, 'spell_omnotron_acquiring_target_periodic'),
(92036, 'spell_omnotron_acquiring_target_periodic'),
(92037, 'spell_omnotron_acquiring_target_periodic'),
(79582, 'spell_omnotron_barrier'),
(91516, 'spell_omnotron_barrier'),
(91517, 'spell_omnotron_barrier'),
(91518, 'spell_omnotron_barrier'),
(92050, 'spell_omnotron_shadow_infusion'),
(92051, 'spell_omnotron_shadow_conductor'),
(92135, 'spell_omnotron_shadow_conductor'),
(91881, 'spell_omnotron_overcharge'),
(91857, 'spell_omnotron_overcharged_power_generator');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (79920, 78696, 78697, 95019, 95020, 95021, 78698, 95025, 95026, 95027, 78699, 78700, 95022, 95023, 95024, 95028, 95029, 95030, 80164, 91478, 91479, 91480, 91823, 91881) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 79920, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Shared Health - Target Electron'),
(13, 1, 79920, 0, 1, 31, 0, 3, 42178, 0, 0, 0, '', 'Shared Health - Target Magmatron'),
(13, 1, 79920, 0, 2, 31, 0, 3, 42180, 0, 0, 0, '', 'Shared Health - Target Toxitron'),
(13, 1, 79920, 0, 3, 31, 0, 3, 42166, 0, 0, 0, '', 'Shared Health - Target Arcanotron'),
(13, 1, 78696, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Controller Recharge - Target Electron'),
(13, 1, 78696, 0, 1, 31, 0, 3, 42178, 0, 0, 0, '', 'Controller Recharge - Target Magmatron'),
(13, 1, 78696, 0, 2, 31, 0, 3, 42180, 0, 0, 0, '', 'Controller Recharge - Target Toxitron'),
(13, 1, 78696, 0, 3, 31, 0, 3, 42166, 0, 0, 0, '', 'Controller Recharge - Target Arcanotron'),
(13, 1, 78697, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Recharging - Target Electron'),
(13, 1, 95019, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Recharging - Target Electron'),
(13, 1, 95020, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Recharging - Target Electron'),
(13, 1, 95021, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Recharging - Target Electron'),
(13, 1, 78698, 0, 0, 31, 0, 3, 42178, 0, 0, 0, '', 'Recharging - Target Magmatron'),
(13, 1, 95025, 0, 0, 31, 0, 3, 42178, 0, 0, 0, '', 'Recharging - Target Magmatron'),
(13, 1, 95026, 0, 0, 31, 0, 3, 42178, 0, 0, 0, '', 'Recharging - Target Magmatron'),
(13, 1, 95027, 0, 0, 31, 0, 3, 42178, 0, 0, 0, '', 'Recharging - Target Magmatron'),
(13, 1, 78700, 0, 0, 31, 0, 3, 42180, 0, 0, 0, '', 'Recharging - Target Toxitron'),
(13, 1, 95022, 0, 0, 31, 0, 3, 42180, 0, 0, 0, '', 'Recharging - Target Toxitron'),
(13, 1, 95023, 0, 0, 31, 0, 3, 42180, 0, 0, 0, '', 'Recharging - Target Toxitron'),
(13, 1, 95024, 0, 0, 31, 0, 3, 42180, 0, 0, 0, '', 'Recharging - Target Toxitron'),
(13, 1, 78699, 0, 0, 31, 0, 3, 42166, 0, 0, 0, '', 'Recharging - Target Arcanotron'),
(13, 1, 95028, 0, 0, 31, 0, 3, 42166, 0, 0, 0, '', 'Recharging - Target Arcanotron'),
(13, 1, 95029, 0, 0, 31, 0, 3, 42166, 0, 0, 0, '', 'Recharging - Target Arcanotron'),
(13, 1, 95030, 0, 0, 31, 0, 3, 42166, 0, 0, 0, '', 'Recharging - Target Arcanotron'),
(13, 1, 80164, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Chemical Cloud - Target Electron'),
(13, 1, 80164, 0, 1, 31, 0, 3, 42178, 0, 0, 0, '', 'Chemical Cloud - Target Magmatron'),
(13, 1, 80164, 0, 2, 31, 0, 3, 42180, 0, 0, 0, '', 'Chemical Cloud - Target Toxitron'),
(13, 1, 80164, 0, 3, 31, 0, 3, 42166, 0, 0, 0, '', 'Chemical Cloud - Target Arcanotron'),
(13, 1, 91478, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Chemical Cloud - Target Electron'),
(13, 1, 91478, 0, 1, 31, 0, 3, 42178, 0, 0, 0, '', 'Chemical Cloud - Target Magmatron'),
(13, 1, 91478, 0, 2, 31, 0, 3, 42180, 0, 0, 0, '', 'Chemical Cloud - Target Toxitron'),
(13, 1, 91478, 0, 3, 31, 0, 3, 42166, 0, 0, 0, '', 'Chemical Cloud - Target Arcanotron'),
(13, 1, 91479, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Chemical Cloud - Target Electron'),
(13, 1, 91479, 0, 1, 31, 0, 3, 42178, 0, 0, 0, '', 'Chemical Cloud - Target Magmatron'),
(13, 1, 91479, 0, 2, 31, 0, 3, 42180, 0, 0, 0, '', 'Chemical Cloud - Target Toxitron'),
(13, 1, 91479, 0, 3, 31, 0, 3, 42166, 0, 0, 0, '', 'Chemical Cloud - Target Arcanotron'),
(13, 1, 91480, 0, 0, 31, 0, 3, 42179, 0, 0, 0, '', 'Chemical Cloud - Target Electron'),
(13, 1, 91480, 0, 1, 31, 0, 3, 42178, 0, 0, 0, '', 'Chemical Cloud - Target Magmatron'),
(13, 1, 91480, 0, 2, 31, 0, 3, 42180, 0, 0, 0, '', 'Chemical Cloud - Target Toxitron'),
(13, 1, 91480, 0, 3, 31, 0, 3, 42166, 0, 0, 0, '', 'Chemical Cloud - Target Arcanotron'),
(13, 1, 91823, 0, 3, 31, 0, 3, 42934, 0, 0, 0, '', 'Shadow Teleport - Target Chemical Cloud'),
(13, 1, 91881, 0, 3, 31, 0, 3, 42733, 0, 0, 0, '', 'Overcharge - Target Power Generator');

-- Procs
DELETE FROM `spell_proc` WHERE `SpellId` IN (79900, 91447, 91448, 91449, 79835, 91501, 91502, 91503, 80086);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Chance`) VALUES
(79900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
(91447, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
(91448, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
(91449, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
(79835, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
(91501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
(91502, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
(91503, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0),
(80086, 0, 0, 0, 0, 0, 0, 0, 12287, 0, 0);

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 42186 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(42186, 0, 0, 42179, -342.519, -405.134, 214.0583, 0.9424778, 8, 0),
(42186, 0, 0, 42178, -308.807, -405.278, 214.0873, 2.111848, 8, 0),
(42186, 0, 0, 42180, -333.632, -411.866, 214.1353, 1.291544, 8, 0),
(42186, 0, 0, 42166, -315.415, -412.474, 214.0963, 1.832596, 8, 0);

-- Waypoints
DELETE FROM `waypoint_data` WHERE `id`= 4218600;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(4218600, 1, -309.7726, -392.9861, 213.9485),
(4218600, 2, -324.7795, -399.0781, 213.8248),
(4218600, 3, -342.2674, -392.6615, 213.9369),
(4218600, 4, -324.7795, -399.0781, 213.8248);

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (42179, 42178, 42180, 42166, 42934, 42920, 42897, 42733, 49047, 49048, 49053, 49054, 49050, 49051, 49052, 49055, 49056, 49057, 49058, 49049, 49118, 49119, 49120, 49121, 49122, 49123, 49226);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
-- Golems
(42179, 0, 1, '78726 82265 78725 73059'),
(42178, 0, 1, '78726 82265 78725 73059'),
(42180, 0, 1, '78726 82265 78725 73059'),
(42166, 0, 1, '78726 82265 78725 73059'),
(49047, 0, 1, '78726 82265 78725 73059'),
(49048, 0, 1, '78726 82265 78725 73059'),
(49049, 0, 1, '78726 82265 78725 73059'),
(49053, 0, 1, '78726 82265 78725 73059'),
(49054, 0, 1, '78726 82265 78725 73059'),
(49055, 0, 1, '78726 82265 78725 73059'),
(49050, 0, 1, '78726 82265 78725 73059'),
(49051, 0, 1, '78726 82265 78725 73059'),
(49052, 0, 1, '78726 82265 78725 73059'),
(49056, 0, 1, '78726 82265 78725 73059'),
(49057, 0, 1, '78726 82265 78725 73059'),
(49058, 0, 1, '78726 82265 78725 73059'),
-- Chemical Cloud
(42934, 0, 1, '80162 80163'),
(49118, 0, 1, '80162 80163'),
(49119, 0, 1, '80162 80163'),
(49120, 0, 1, '80162 80163'),
-- Poison Puddle
(42920, 0, 1, '80095'),
-- Poison Bomb
(42897, 0, 1, '80086'),
(49121, 0, 1, '80086'),
(49122, 0, 1, '80086'),
(49123, 0, 1, '80086'),
-- Power Generator
(42733, 0, 1, '79628'),
-- Lord Victor Nefarius
(49226, 0, 1, '78494');

-- Spell target positions
DELETE FROM `spell_target_position` WHERE `ID`= 91854;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(91854, 0, 669, -302.386,  -350.7, 220.482, 4.509913);

-- Delete encounter related creature
DELETE FROM `creature` WHERE `guid` IN (250043, 250044, 250045, 250046);
DELETE FROM `creature_addon` WHERE `guid` IN (250043, 250044, 250045, 250046);
