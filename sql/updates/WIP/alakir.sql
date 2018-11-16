-- Template Updates
-- Al'Akir
UPDATE `creature_template` SET `ScriptName`= 'boss_alakir', `InhabitType`= 12 WHERE `entry`= 46753;
-- Slipstream
UPDATE `creature_template` SET `InhabitType`= 4, `ScriptName`= 'npc_totfw_slipstream' WHERE `entry`= 47066;
-- Lightning Strike Trigger
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 48977;
-- Lightning Strike Trigger (Heroic Chain-Caster)
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 2048, `InhabitType`= 4, `flags_extra`= 128 WHERE `entry`= 50254;
-- Relentless Storm Initial Vehicle
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 48977;
-- Ice Storm
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `ScriptName`= 'npc_alakir_ice_storm' WHERE `entry`= 46734;
-- Ice Storm (Ice Patch Field)
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 46973;
-- Squall Line Vehicle SW
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `VehicleId`= 1358, `speed_walk`= 2.8 WHERE `entry`= 47034;
-- Squall Line Vehicle SE
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `VehicleId`= 1360, `speed_walk`= 2.8 WHERE `entry`= 48852;
-- Ice Storm Trigger
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 46766;
-- Stormling Pre-Effect
UPDATE `creature_template` SET `unit_flags`= 33555200, `flags_extra`= 2 WHERE `entry`= 47177;
-- Stormling
UPDATE `creature_template` SET `DamageModifier`= 30, `ScriptName`= 'npc_alakir_stormling' WHERE `entry`= 47175;
-- Relentless Storm Initial Vehicle
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 47806;

-- Model Info
UPDATE `creature_model_info` SET `CombatReach`= 400 WHERE `DisplayId`= 36062;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 46753;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(46753, 0, 0, 'The Conclave of Wind has dissipated. Your honorable conduct and determination have earned you the right to face me in battle, mortals. I await your assault on my platform! Come!', 14, 0, 100, 0, 0, 0, 50553, 3, 'Al''Akir - Conclave of Wind defeated'),
(46753, 1, 0, 'Your challenge is accepted, mortals! Know that you face Al''Akir, Elemental Lord of Air! You have no hope of defeating me!', 14, 0, 100, 0, 0, 0, 50565, 3, 'Al''Akir - Aggro'),
(46753, 2, 0, '|TINTERFACE\\ICONS\\Spell_Frost_WindWalkOn.blp:20|t%s begins to cast |cFFFF0000|Hspell:87770|h[Wind Burst]|h|r!', 41, 0, 100, 0, 0, 0, 49014, 3, 'Al''Akir - Announce Wind Burst'),
(46753, 3, 0, 'Winds! Obey my command!', 14, 0, 100, 0, 0, 0, 50586, 3, 'Al''Akir - Squall Line'),
(46753, 4, 0, 'Your futile persistance angers me!', 14, 0, 100, 0, 0, 0, 50584, 3, 'Al''Akir - Phase 2'),
(46753, 5, 0, 'Storms! I summon you to my side!', 14, 0, 100, 0, 0, 0, 50587, 3, 'Al''Akir - Stormling'),
(46753, 6, 0, 'Enough! I will no longer be contained!', 14, 0, 100, 0, 0, 0, 50585, 3, 'Al''Akir - Phase 3');
/*
(46753, @GROUP_ID+6, @ID+, 'Enough! I will no longer be contained!', 14, 0, 100, 0, 0, 0, UNKNOWN, 'Al''Akir'),
(46753, @GROUP_ID+7, @ID+, 'After every storm, comes the calm...', 14, 0, 100, 0, 0, 0, UNKNOWN, 'Al''Akir to Player');
*/

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_alakir_lightning_strike_script',
'spell_alakir_lightning_strike_periodic',
'spell_alakir_lightning_strike_damage',
'spell_alakir_electrocute',
'spell_alakir_squall_line_pre_aura',
'spell_alakir_squall_line_script',
'spell_alakir_relentless_storm_initial_vehicle_ride_trigger',
'spell_alakir_relentless_storm_initial_vehicle_ride',
'spell_alakir_eye_of_the_storm');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(91326, 'spell_alakir_lightning_strike_script'),
(88238, 'spell_alakir_lightning_strike_periodic'),
(93854, 'spell_alakir_lightning_strike_periodic'),
(93855, 'spell_alakir_lightning_strike_periodic'),
(93856, 'spell_alakir_lightning_strike_periodic'),
(88214, 'spell_alakir_lightning_strike_damage'),
(93255, 'spell_alakir_lightning_strike_damage'),
(88427, 'spell_alakir_electrocute'),
(87652, 'spell_alakir_squall_line_pre_aura'),
(87855, 'spell_alakir_squall_line_script'),
(89528, 'spell_alakir_relentless_storm_initial_vehicle_ride_trigger'),
(89527, 'spell_alakir_relentless_storm_initial_vehicle_ride'),
(82724, 'spell_alakir_eye_of_the_storm');

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (47066, 50254, 46734, 47175);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(47066, '87713'),
(50254, '93247'),
(46734, '87053'),
(47175, '87906 87905');

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`= 46753 AND `summonerType`= 0;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(46753, 0, 0, 47066, -51.0972, 576.807, 209.7063, 1.553343, 8, 0),
(46753, 0, 0, 47066, -287.604, 816.51,  209.7063, 0,        8, 0),
(46753, 0, 0, 47066, -47.9531, 1053.3,  209.7063, 4.694936, 8, 0),
(46753, 0, 0, 47066, 188.823,  813.54,  209.7063, 3.124139, 8, 0);

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (47066, 47034, 48852);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(47066, 87742, 1, 0),
(47034, 46598, 1, 1),
(48852, 46598, 1, 1);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (91326, 87406, 88779, 87652, 87904, 101458, 101459, 101460, 89527) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 91326, 0, 0, 31, 0, 3, 48977, 0, 0, 0, '', 'Lightning Strike - Target Lightning Strike Trigger'),
(13, 1, 87406, 0, 0, 31, 0, 3, 46766, 0, 0, 0, '', 'Ice Storm - Target Ice Storm Trigger'),
(13, 1, 88779, 0, 0, 31, 0, 3, 46753, 0, 0, 0, '', 'Squall Line - Target Al''akir'),
(13, 1, 87652, 0, 0, 31, 0, 3, 48854, 0, 0, 0, '', 'Squall Line - Target Squall Line SW'),
(13, 1, 87652, 0, 1, 31, 0, 3, 48855, 0, 0, 0, '', 'Squall Line - Target Squall Line SE'),
(13, 1, 87904, 0, 0, 31, 0, 3, 46753, 0, 0, 0, '', 'Feedback - Target Al''akir'),
(13, 1, 101458, 0, 0, 31, 0, 3, 46753, 0, 0, 0, '', 'Feedback - Target Al''akir'),
(13, 1, 101459, 0, 0, 31, 0, 3, 46753, 0, 0, 0, '', 'Feedback - Target Al''akir'),
(13, 1, 101460, 0, 0, 31, 0, 3, 46753, 0, 0, 0, '', 'Feedback - Target Al''akir'),
(13, 1, 89527, 0, 0, 31, 0, 3, 47806, 0, 0, 0, '', 'Relentless Storm Initial Vehicle Ride - Target Relentless Storm Initial Vehicle');

-- Vehicle Accessories
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (47034, 48852);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summonType`, `summontimer`) VALUES
-- Squall Line Vehicle SW
(47034, 48854, 0, 1, 'Squall Line SW', 5, 0),
(47034, 48854, 1, 1, 'Squall Line SW', 5, 0),
(47034, 48854, 2, 1, 'Squall Line SW', 5, 0),
(47034, 48854, 3, 1, 'Squall Line SW', 5, 0),
(47034, 48854, 4, 1, 'Squall Line SW', 5, 0),
(47034, 48854, 5, 1, 'Squall Line SW', 5, 0),
(47034, 48854, 6, 1, 'Squall Line SW', 5, 0),
(47034, 48854, 7, 1, 'Squall Line SW', 5, 0),
-- Squall Line Vehicle SE
(48852, 48855, 0, 1, 'Squall Line SE', 5, 0),
(48852, 48855, 1, 1, 'Squall Line SE', 5, 0),
(48852, 48855, 2, 1, 'Squall Line SE', 5, 0),
(48852, 48855, 3, 1, 'Squall Line SE', 5, 0),
(48852, 48855, 4, 1, 'Squall Line SE', 5, 0),
(48852, 48855, 5, 1, 'Squall Line SE', 5, 0),
(48852, 48855, 6, 1, 'Squall Line SE', 5, 0),
(48852, 48855, 7, 1, 'Squall Line SE', 5, 0);

-- Spawns
DELETE FROM `creature` WHERE `guid` IN (340413, 340414, 340415);
DELETE FROM `creature_addon` WHERE `guid` IN (340413, 340414, 340415);
SET @CGUID := 254727;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -50.7691, 864.094, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+1, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -95.9913, 814.078, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+2, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -26.2274, 860.302, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+3, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -24.9896, 772.418, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+4, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -52.5764, 766.026, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+5, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -92.0469, 791.96, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+6, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -73.5833, 855.875, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+7, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -88.4149, 839.203, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+8, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -77.276, 775.408, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+9, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -6.08681, 790.281, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+10, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, -6.0625, 842.55, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
(@CGUID+11, 46766, 754, 5638, 5638, 15, 169, 0, 0, 0, 0.385417, 816.236, 191.2083, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- Ice Storm Trigger (Area: Throne of the Four Winds - Difficulty: 6) (Auras: )
