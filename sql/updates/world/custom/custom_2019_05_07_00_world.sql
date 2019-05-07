-- Magmaw
UPDATE `creature_template` SET `ScriptName`= 'boss_magmaw' WHERE `entry`= 41570;
UPDATE `creature_template` SET `DamageModifier`= 120, `BaseVariance`= 0.5, `npcflag`= 0, `mechanic_immune_mask`= 650854271, `flags_extra`= 1 WHERE `entry` IN (41570, 51101, 51102, 51103);
-- Magmaw's Pincer
UPDATE `creature_template` SET `spell1`= 77917 WHERE `entry`= 41620;
UPDATE `creature_template` SET `spell1`= 77941 WHERE `entry`= 41789;
-- Pillar of Flame
UPDATE `creature_template` SET `unit_flags`= 33587264, `unit_flags2`= 34816, `flags_extra`= 2 WHERE `entry`= 41843;
-- Exposed Head of Magmaw
UPDATE `creature_template` SET `unit_flags`= 33554496 WHERE `entry` IN (42347, 51248, 51249, 51250);
-- Nefarian
UPDATE `creature_template` SET `speed_run`= 1.7142, `unit_flags`= 33587264, `ScriptName`= 'npc_magmaw_nefarian', `flags_extra`= 2 WHERE `entry`= 49427;
-- Lava Parasite
UPDATE `creature_template` SET `ScriptName`= 'npc_magmaw_lava_parasite' WHERE `entry` IN (41806, 42321);
UPDATE `creature_template` SET `difficulty_entry_1`= 51456, `difficulty_entry_2`= 51457, `difficulty_entry_3`= 51458 WHERE `entry`= 41806;
UPDATE `creature_template` SET `difficulty_entry_1`= 51459, `difficulty_entry_2`= 51460, `difficulty_entry_3`= 51461 WHERE `entry`= 42321;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 14, `speed_run`= 0.4286, `mechanic_immune_mask`= 634338303, `flags_extra`= 1073742080 WHERE `entry` IN (41806, 42321, 51456, 51457, 51458, 51459, 51460, 51461);
-- Blazing Bone Construct
UPDATE `creature_template` SET `difficulty_entry_1`= 49482, `difficulty_entry_2`= 49483, `difficulty_entry_3`= 49484, `ScriptName`= 'npc_magmaw_blazing_bone_construct' WHERE `entry`= 49416;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 14, `speed_run`= 1.14286, `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 634338303, `flags_extra`= 1073742080 WHERE `entry` IN (49416, 49482, 49483, 49484);
-- Ignition
UPDATE `creature_template` SET `unit_flags`= 33554496, `flags_extra`= 131, `speed_run`= 0.7142 WHERE `entry`= 49447;

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (41806, 42321, 51456, 51457, 51458, 51459, 51460, 51461, 49427, 49416, 49482, 49483, 49484, 49447);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(41806, 0, 1, '78019'),
(42321, 0, 1, '78019'),
(51456, 0, 1, '78019'),
(51457, 0, 1, '78019'),
(51458, 0, 1, '78019'),
(51459, 0, 1, '78019'),
(51460, 0, 1, '78019'),
(51461, 0, 1, '78019'),
(49427, 50331648, 1, ''),
(49416, 0, 1, '92128'),
(49482, 0, 1, '92128'),
(49483, 0, 1, '92128'),
(49484, 0, 1, '92128'),
(49447, 0, 1, '92131');

-- Vehicle accessory
DELETE FROM `vehicle_template_accessory` WHERE `entry`= 41570;

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (41570, 51101, 51102, 51103);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(41570, 77901, 1, 0),
(51101, 77901, 1, 0),
(51102, 77901, 1, 0),
(51103, 77901, 1, 0);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (41570, 51101, 51102, 51103, 41620, 41789, 42347, 51248, 51249, 51250, 49427);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
-- Magmaw
(41570, 1, 0, 1, 1),
(51101, 1, 0, 1, 1),
(51102, 1, 0, 1, 1),
(51103, 1, 0, 1, 1),
-- Magmaw's Pincer
(41620, 0, 0, 1, 0),
(41789, 0, 0, 1, 0),
-- Exposed Head of Magmaw
(42347, 0, 0, 1, 0),
(51248, 0, 0, 1, 0),
(51249, 0, 0, 1, 0),
(51250, 0, 0, 1, 0),
-- Nefarian
(49427, 0, 0, 2, 0);

-- Serverside Spells
UPDATE `spell_dbc` SET `DurationIndex`= 3, `AttributesEx3`= `AttributesEx3` | 0x00000100 WHERE `Id`= 77994;

DELETE FROM `spell_dbc` WHERE `Id`= 94317;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `Comment`) VALUES 
(94317, 0x20000100, 0, 0x00000004, 0x00020100, 0, 0, 0, 0, 0, 0, 0, 1, 0, 13, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Blazing Inferno');

DELETE FROM `spelleffect_dbc` WHERE `Id` IN (160093, 160094);
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectApplyAuraName`, `EffectMiscValue`, `EffectRadiusIndex`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectIndex`, `EffectSpellId`, `Comment`) VALUES
(160093, 6, 296, 843, 28, 22, 15, 0, 77994, 'Pillar of Flame'),
(160094, 77, 0, 0, 28, 22, 15, 0, 94317, 'Blazing Inferno');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_magmaw_magma_spit',
'spell_magmaw_mangle',
'spell_magmaw_pillar_of_flame_dummy',
'spell_magmaw_pillar_of_flame_forcecast',
'spell_magmaw_ride_vehicle',
'spell_magmaw_launch_hook',
'spell_magmaw_eject_passenger_1',
'spell_magmaw_eject_passenger_3',
'spell_magmaw_lava_parasite',
'spell_magmaw_blazing_inferno_targeting',
'spell_magmaw_shadow_breath_targeting');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_eject_passenger' AND `spell_id` IN (77946, 95204);
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_eject_passenger_1' AND `spell_id`= 77946;
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_eject_passenger_3' AND `spell_id`= 95204;

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(95280, 'spell_magmaw_magma_spit'),
(92047, 'spell_magmaw_mangle'),
(78017, 'spell_magmaw_pillar_of_flame_dummy'),
(77998, 'spell_magmaw_pillar_of_flame_forcecast'),
(77901, 'spell_magmaw_ride_vehicle'),
(77946, 'spell_magmaw_eject_passenger_1'),
(95204, 'spell_magmaw_eject_passenger_3'),
(77917, 'spell_magmaw_launch_hook'),
(77941, 'spell_magmaw_launch_hook'),
(78019, 'spell_magmaw_lava_parasite'),
(94317, 'spell_magmaw_blazing_inferno_targeting'),
(95536, 'spell_magmaw_shadow_breath_targeting');


-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (89743, 78360, 78017, 78010, 94996, 77917, 77941, 77940, 77929) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89743, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Ride Vehicle - Target Magmaw'),
(13, 1, 78360, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Ride Vehicle - Target Magmaw'),
(13, 2, 78017, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Pillar of Flame - Target Magmaw'),
(13, 1, 78010, 0, 0, 31, 0, 3, 41843, 0, 0, 0, '', 'Pillar of Flame - Target Pillar of Flame'),
(13, 1, 94996, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Ride Vehicle - Target Magmaw'),
(13, 1, 77917, 0, 0, 31, 0, 3, 41767, 0, 0, 0, '', 'Launch Hook - Target Magmaw Spike Stalker'),
(13, 1, 77941, 0, 0, 31, 0, 3, 41767, 0, 0, 0, '', 'Launch Hook - Target Magmaw Spike Stalker'),
(13, 1, 77940, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Chain Visual - Target Magmaw'),
(13, 1, 77929, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Chain Visual - Target Magmaw');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (41570, 49427);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Magmaw
(41570, 0, 0, '%s begins to erupt, spewing Lava Parasites onto the ground!', 41, 0, 100, 0, 0, 8717, 51464, 'Magmaw - Announce Lava Parasites'),
(41570, 1, 0, '%s slumps forward, exposing his pincers!', 41, 0, 100, 0, 0, 8717, 47603, 'Magmaw - Announce Exposing Pincers'),
(41570, 2, 0, '%s becomes impaled on the spike, exposing his head!', 41, 0, 100, 0, 0, 8717, 41614, 'Magmaw - Announce Exposed Head'),
-- Nefarian
(49427, 0, 0, 'I found this fascinating specimen in the lava underneath this very room. Magmaw should provide an adequate challenge for your pathetic little band.', 14, 0, 100, 0, 0, 23367, 49060, 'Nefarian - Intro 1'),
(49427, 1, 0, 'On second thought, what fun is an "adequate" challenge?', 14, 0, 100, 0, 0, 23369, 49061, 'Nefarian - Intro 2'),
(49427, 2, 0, 'Inconceivable! You may actually defeat my lava worm! Perhaps I can help... tip the scales.', 14, 0, 100, 0, 0, 23368, 49782, 'Nefarian - Low Health Heroic'),
(49427, 3, 0, 'You won? How... disappointing. I could have easily watched you all continue to stand in the fire.', 14, 0, 100, 0, 0, 23366, 49062, 'Nefarian - Death Heroic');

-- Spline Chains
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`= 49427;
INSERT INTO `script_spline_chain_waypoints` (`entry`, `chainId`, `splineId`, `wpId`, `x`, `y`, `z`) VALUES
(49427, 1, 0, 0, -391.9144, 40.52919, 207.3371),
(49427, 1, 0, 1, -413.9097, 36.13715, 200.5833),
(49427, 1, 0, 2, -392.2778, 40.4566, 207.2257),
(49427, 1, 0, 3, -370.6458, 44.77604, 213.8682),
(49427, 1, 0, 4, -352.0885, 48.22743, 221.4187),
(49427, 1, 0, 5, -329.6441, 42.55035, 228.185),
(49427, 1, 0, 6, -320.2205, 16.81944, 238.6828),
(49427, 1, 0, 7, -315.9445, -6.895833, 246.8446),
(49427, 1, 0, 8, -315.9445, -6.895833, 246.8446);

DELETE FROM `script_spline_chain_meta` WHERE `entry`= 49427;
INSERT INTO `script_spline_chain_meta` (`entry`, `chainId`, `splineId`, `expectedDuration`, `msUntilNext`) VALUES
(49427, 1, 0, 10192, 0);

-- Delete encounter related creatures
DELETE FROM `creature` WHERE `guid` IN (250054, 250053, 250052);
DELETE FROM `creature_addon` WHERE `guid` IN (250054, 250053, 250052);

-- Achievement Data
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15650;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15650, 11, 0, 0, 'achievement_parasite_evening');

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (41570, 51101, 51102, 51103);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(41570, 396, 3500),
(51101, 396, 3500),
(51102, 396, 3500),
(51103, 396, 3500);
