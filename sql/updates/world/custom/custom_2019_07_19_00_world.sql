-- Template Updates
-- Atramedes
UPDATE `creature_template` SET `ScriptName`= 'boss_atramedes' WHERE `entry`= 41442;
UPDATE `creature_template` SET `speed_run`= 1.429, `VehicleId`= 891, `flags_extra`= 1 | 512, `DamageModifier`= 120, `BaseVariance`= 0.5, `mechanic_immune_mask`= 650854271 WHERE `entry` IN (41442, 49583, 49584, 49585);
-- Blind Dragon Tail
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130, `AIName`= 'NullCreatureAI' WHERE `entry`= 42356;
-- Sonar Pulse
UPDATE `creature_template` SET `speed_run`= 1, `unit_flags`= 34080768, `flags_extra`= 130, `AIName`= 'NullCreatureAI' WHERE `entry`= 41546;
-- Sonar Pulse Target
UPDATE `creature_template` SET `unit_flags`= 33554688, `flags_extra`= 128, `AIName`= 'NullCreatureAI' WHERE `entry`= 49679;
-- Roaring Flame
UPDATE `creature_template` SET `unit_flags`= 33554688, `flags_extra`= 130, `AIName`= 'NullCreatureAI' WHERE `entry`= 41807;
-- Tracking Flames
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130, `speed_run`= 0.714, `AIName`= 'NullCreatureAI' WHERE `entry`= 41879;
-- Sonar Pulse
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130, `AIName`= 'NullCreatureAI' WHERE `entry`= 49623;
-- Reverberating Flame
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130, `speed_run`= 0.714, `AIName`= 'NullCreatureAI' WHERE `entry`= 41962;
-- Reverberating Flame (Fire)
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 130, `speed_run`= 0.714, `AIName`= 'NullCreatureAI' WHERE `entry`= 42001;
-- Ancient Dwarven Shield
UPDATE `creature_template` SET `ScriptName`= 'npc_atramedes_ancient_dwarven_shield' WHERE `entry` IN (41445, 42947, 42949, 42951, 42954, 42956, 42958, 42960);
-- Lord Victor Nefarius
UPDATE `creature_template` SET `unit_flags`= 33554496, `ScriptName`= 'npc_atramedes_lord_victor_nefarius' WHERE `entry`= 49580;
-- Obnoxious Imp
UPDATE `creature_template` SET `ScriptName`= 'npc_atramedes_obnoxious_fiend', `difficulty_entry_3`= 49798 WHERE `entry`= 49740;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3, `speed_run`= 1.429, `mechanic_immune_mask`= 650854271 WHERE `entry` IN (49740, 49798);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (41442, 49580);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Atramedes
(41442, 0, 0, 'I have no need for eyes to see my enemies. Your clumsy footsteps and foul stench give you away!', 14, 0, 100, 0, 0, 20820, 48030, 'Atramedes - Aggro'),
(41442, 1, 0, '|TInterface\\Icons\\spell_fire_selfdestruct.blp:20|t%s rears back and casts |cFFFF0000|Hspell:77982|h[Searing Flame]|h|r!\n', 41, 0, 100, 0, 0, 0, 42180, 'Atramedes - Announce Searing Flame'),
(41442, 2, 0, 'You cannot hide from searing flame!', 14, 0, 100, 0, 0, 20826, 48036, 'Atramedes - Searing Flame'),
(41442, 3, 0, 'Yes, run! With every step your heart quickens. The beating, loud and thunderous... Almost deafening. You cannot escape!', 14, 0, 100, 0, 0, 20827, 48038, 'Atramedes - Roaring Flame Breath'),
(41442, 4, 0, 'Death waits in the darkness!', 14, 0, 100, 0, 0, 20822, 48033, 'Atramedes - Slay 1'),
(41442, 4, 1, 'Sighted, but blind to the truth. Embrace the finality of it all!', 14, 0, 100, 0, 0, 20821, 48031, 'Atramedes - Slay 2'),
(41442, 5, 0, 'This miserable existence finally ends.', 14, 0, 100, 0, 0, 20823, 48034, 'Atramedes - Death'),
-- Lord Victor Nefarius
(49580, 0, 0, 'Atramedes, are you going deaf as well as blind? Hurry up and kill them all.', 14, 0, 100, 0, 0, 23360, 49074, 'Lord Victor Nefarius'),
(49580, 1, 0, 'Atramedes, the heroes are right THERE!', 14, 0, 100, 0, 0, 23359, 49075, 'Lord Victor Nefarius'),
(49580, 2, 0, 'These shields are proving quite the nuisance.', 14, 0, 100, 0, 0, 23358, 49076, 'Lord Victor Nefarius');

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_atramedes_modulation',
'spell_atramedes_roaring_flame_breath_reverse_cast',
'spell_atramedes_roaring_flame_breath',
'spell_atramedes_roaring_flame_breath_fire_periodic',
'spell_atramedes_resonating_clash_ground',
'spell_atramedes_resonating_clash_air',
'spell_atramedes_resonating_clash',
'spell_atramedes_sound_bar',
'spell_atramedes_noisy',
'spell_atramedes_vertigo',
'spell_atramedes_sonic_flames',
'spell_atramedes_devastation_trigger',
'spell_atramedes_sonic_breath',
'spell_atramedes_destroy_shield',
'spell_atramedes_pestered');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(92452, 'spell_atramedes_modulation'),
(92453, 'spell_atramedes_modulation'),
(78230, 'spell_atramedes_roaring_flame_breath_reverse_cast'),
(78221, 'spell_atramedes_roaring_flame_breath'),
(78431, 'spell_atramedes_roaring_flame_breath_fire_periodic'),
(77611, 'spell_atramedes_resonating_clash_ground'),
(78168, 'spell_atramedes_resonating_clash_air'),
(77709, 'spell_atramedes_resonating_clash'),
(88824, 'spell_atramedes_sound_bar'),
(78897, 'spell_atramedes_noisy'),
(77717, 'spell_atramedes_vertigo'),
(92389, 'spell_atramedes_vertigo'),
(92390, 'spell_atramedes_vertigo'),
(92391, 'spell_atramedes_vertigo'),
(78864, 'spell_atramedes_sonic_flames'),
(78898, 'spell_atramedes_devastation_trigger'),
(78075, 'spell_atramedes_sonic_breath'),
(92607, 'spell_atramedes_destroy_shield'),
(92685, 'spell_atramedes_pestered');

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (41807, 42001, 41962, 49580);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(41807, 0, 1, '78024 78018'),
(42001, 0, 1, '78024 78018'),
(41962, 0, 1, '78354 78217'),
(49580, 0, 1, '78494');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (77673, 78098, 92403, 92404, 92405, 78230, 78431, 77611, 78168, 78945, 92607) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 77673, 0, 0, 31, 0, 3, 41442, 0, 0, 0, '', 'Sonar Pulse Summon - Target Atramedes'),
(13, 1, 78098, 0, 0, 31, 0, 3, 41879, 0, 0, 0, '', 'Sonic Breath - Target Tracking Flames'),
(13, 1, 92403, 0, 0, 31, 0, 3, 41879, 0, 0, 0, '', 'Sonic Breath - Target Tracking Flames'),
(13, 1, 92404, 0, 0, 31, 0, 3, 41879, 0, 0, 0, '', 'Sonic Breath - Target Tracking Flames'),
(13, 1, 92405, 0, 0, 31, 0, 3, 41879, 0, 0, 0, '', 'Sonic Breath - Target Tracking Flames'),
(13, 1, 78230, 0, 0, 31, 0, 3, 41442, 0, 0, 0, '', 'Roaring Flame Breath Reverse Cast - Target Atramedes'),
(13, 1, 78431, 0, 0, 31, 0, 3, 42001, 0, 0, 0, '', 'Roaring Flame Breath Fire Periodic - Target Reverberating Flame'),
(13, 3, 77611, 0, 0, 31, 0, 3, 41442, 0, 0, 0, '', 'Resonating Clash - Target Atramedes'),
(13, 1, 78168, 0, 0, 31, 0, 3, 41442, 0, 0, 0, '', 'Resonating Clash - Target Atramedes'),
(13, 1, 78945, 0, 0, 31, 0, 3, 42956, 0, 0, 0, '', 'Sonic Flames - Target Ancient Dwarven Shield'),
(13, 1, 78945, 0, 1, 31, 0, 3, 42954, 0, 0, 0, '', 'Sonic Flames - Target Ancient Dwarven Shield'),
(13, 1, 78945, 0, 2, 31, 0, 3, 42958, 0, 0, 0, '', 'Sonic Flames - Target Ancient Dwarven Shield'),
(13, 1, 78945, 0, 3, 31, 0, 3, 42949, 0, 0, 0, '', 'Sonic Flames - Target Ancient Dwarven Shield'),
(13, 1, 78945, 0, 4, 31, 0, 3, 41445, 0, 0, 0, '', 'Sonic Flames - Target Ancient Dwarven Shield'),
(13, 1, 78945, 0, 5, 31, 0, 3, 42960, 0, 0, 0, '', 'Sonic Flames - Target Ancient Dwarven Shield'),
(13, 1, 78945, 0, 6, 31, 0, 3, 42951, 0, 0, 0, '', 'Sonic Flames - Target Ancient Dwarven Shield'),
(13, 1, 92607, 0, 0, 31, 0, 3, 42956, 0, 0, 0, '', 'Destroy Shield - Target Ancient Dwarven Shield'),
(13, 1, 92607, 0, 1, 31, 0, 3, 42954, 0, 0, 0, '', 'Destroy Shield - Target Ancient Dwarven Shield'),
(13, 1, 92607, 0, 2, 31, 0, 3, 42958, 0, 0, 0, '', 'Destroy Shield - Target Ancient Dwarven Shield'),
(13, 1, 92607, 0, 3, 31, 0, 3, 42949, 0, 0, 0, '', 'Destroy Shield - Target Ancient Dwarven Shield'),
(13, 1, 92607, 0, 4, 31, 0, 3, 41445, 0, 0, 0, '', 'Destroy Shield - Target Ancient Dwarven Shield'),
(13, 1, 92607, 0, 5, 31, 0, 3, 42960, 0, 0, 0, '', 'Destroy Shield - Target Ancient Dwarven Shield'),
(13, 1, 92607, 0, 6, 31, 0, 3, 42951, 0, 0, 0, '', 'Destroy Shield - Target Ancient Dwarven Shield');

-- Vehicle Accessory
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (41442, 49583, 49584, 49585);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(41442, 42356, 0, 1, 'Atramedes - Blind Dragon Tail', 8, 0), -- Atramedes - Blind Dragon Tail
(49583, 42356, 0, 1, 'Atramedes - Blind Dragon Tail', 8, 0), -- Atramedes - Blind Dragon Tail
(49584, 42356, 0, 1, 'Atramedes - Blind Dragon Tail', 8, 0), -- Atramedes - Blind Dragon Tail
(49585, 42356, 0, 1, 'Atramedes - Blind Dragon Tail', 8, 0); -- Atramedes - Blind Dragon Tail

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (41442, 49583, 49584, 49585, 41445, 42947, 42949, 42951, 42954, 42956, 42958, 42960);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
-- Atramedes
(41442, 46598, 1, 1),
(49583, 46598, 1, 1),
(49584, 46598, 1, 1),
(49585, 46598, 1, 1),
-- Ancient Dwarven Shield
(41445, 77709, 0, 1),
(42947, 77709, 0, 1),
(42949, 77709, 0, 1),
(42951, 77709, 0, 1),
(42954, 77709, 0, 1),
(42956, 77709, 0, 1),
(42958, 77709, 0, 1),
(42960, 77709, 0, 1);
-- Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (41546, 41962, 42956, 49580, 49623);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(41546, 0, 1, 1, 0),
(41962, 0, 0, 2, 0),
(42956, 0, 0, 2, 1),
(49580, 2, 0, 1, 0),
(49623, 2, 0, 0, 0);

-- Correct Athenaeum Door Rotation
UPDATE `gameobject` SET `rotation2`= -1, `rotation3`= 0 WHERE `guid`= 235177;
UPDATE `gameobject_addon` SET `parent_rotation2`= 1, `parent_rotation3`= -0.00000004371139 WHERE `guid`= 235177;

-- Respawn Ancient Dwarven Shields
DELETE FROM `creature` WHERE `guid` IN (250122, 250123, 250124, 250125, 250126, 250127, 250128, 250129, 250130, 250131, 259719, 259721);
DELETE FROM `creature_addon` WHERE `guid` IN (250122, 250123, 250124, 250125, 250126, 250127, 250128, 250129, 250130, 250131, 259719, 259721);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(250122, 42956, 669, 5094, 5094, 15, 169, 0, 0, 0, 106.283, -276.9514, 76.72944, 1.012291, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250123, 42954, 669, 5094, 5094, 15, 169, 0, 0, 0, 108.625, -171.259, 76.72993, 5.026548, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250124, 42958, 669, 5094, 5094, 15, 169, 0, 0, 0, 152.0052, -173.8819, 76.7294, 4.29351, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250125, 42947, 669, 5094, 5094, 15, 169, 0, 0, 0, 130.481, -282.245, 76.72993, 1.466077, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250126, 42949, 669, 5094, 5094, 15, 169, 0, 0, 0, 153.931, -276.589, 76.72993, 1.884956, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250127, 41445, 669, 5094, 5094, 15, 169, 0, 0, 0, 129.5677, -167.4809, 76.72993, 4.852015, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250128, 42960, 669, 5094, 5094, 15, 169, 0, 0, 0, 169.575, -262.495, 76.72974, 2.426008, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250129, 42951, 669, 5094, 5094, 15, 169, 0, 0, 0, 169.7118, -186.1667, 76.72974, 3.892084, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250130, 42954, 669, 5094, 5094, 15, 169, 0, 0, 0, 181.7691, -253.0347, 76.72941, 2.687807, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365), -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)
(250131, 42956, 669, 5094, 5094, 15, 169, 0, 0, 0, 182.7344, -196.4653, 76.7294, 3.525565, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Ancient Dwarven Shield (Area: Blackwing Descent - Difficulty: 6)

DELETE FROM `spawn_group_template` WHERE `groupId`= 400;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(400, 'Blackwing Descent - Ancient Dwarven Shields', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 400;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(400, 0, 250122),
(400, 0, 250123),
(400, 0, 250124),
(400, 0, 250125),
(400, 0, 250126),
(400, 0, 250127),
(400, 0, 250128),
(400, 0, 250129),
(400, 0, 250130),
(400, 0, 250131);

DELETE FROM `spell_dbc` WHERE `Id`= 92647;
INSERT INTO `spell_dbc` (`Id`, `CastingTimeIndex`, `DurationIndex`, `Attributes`, `AttributesEx`, `AttributesEx3`, `AttributesEx6`, `AttributesEx7`, `Comment`) VALUES
(92647, 0, 21, 0x20000100, 0x10000400, 0x10070300, 0x00000400, 0x02000000, '(Serverside/Non-DB2) Apply Vehicle Periodic');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160097;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectApplyAuraName`, `EffectAmplitude`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(160097, 27, 296, 0, 443, 445, 0, 12, 22, 7, 92647, 0, '(Serverside/Non-DB2) Apply Vehicle Periodic - EFFECT_0');

-- Procs
DELETE FROM `spell_proc` WHERE `SpellId`= 92681;
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Charges`) VALUES
(92681, 0x00000004, 0, 0, 0x00002FFF,  1);

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15655;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15655, 11, 0, 0, 'achievement_silence_is_golden');

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (41442, 49583, 49584, 49585);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(41442, 396, 3500),
(49583, 396, 4500),
(49584, 396, 3500),
(49585, 396, 4500);
