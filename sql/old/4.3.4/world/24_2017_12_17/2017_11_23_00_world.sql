-- Rajh
UPDATE `creature_template` SET `difficulty_entry_1`= 48815, `mechanic_immune_mask`= 80297983, `scriptname`= 'boss_rajh' WHERE `entry`= 39378;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `speed_walk`= 2, `type_flags`= 104, `exp`= 3, `faction`= 14,
 `unit_flags`= 32832, `unit_flags2`= 0, `vehicleId`= 790, `movementId`= 151, `mechanic_immune_mask`= 80297983, `flags_extra`= 1, `unit_class`= 4 WHERE `entry`= 48815;

-- Solar Winds Dummy
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 35, `unit_flags`= 33554496, `flags_extra`= 128 WHERE `entry`= 39634;

-- Solar Winds
UPDATE `creature_template` SET `scale`= 0.1, `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `unit_flags`= 33554496, `flags_extra`= 128, `InhabitType`= 1, `scriptname`= 'npc_solar_winds' WHERE `entry`= 39635;

-- Solar Winds (Fire)
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `unit_flags`= 33554496, `flags_extra`= 128 WHERE `entry`= 47922;

-- Inferno Leap
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 14, `unit_flags`= 33587200, `unit_flags2`= 34816, `flags_extra`= 128, `VehicleId`= 1233 WHERE `entry`= 47040;

-- Orb of the Sun
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 14, `unit_flags`= 33587200, `unit_flags2`= 34816, `flags_extra`= 128, `vehicleId`= 787, `scale`= 0.1, `InhabitType`= 4, `scriptname`= 'npc_orb_of_the_sun' WHERE `entry`= 40835;

-- Blazing Inferno
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `unit_flags`= 33587200, `unit_flags2`= 34816, `flags_extra`= 128, `vehicleId`= 790 WHERE `entry`= 40927;

DELETE FROM `creature_text` WHERE `CreatureID`= 39378;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(39378, 0, 0, 'Defilers! Wretches! Fiends! Begone from here!', 14, 0, 100, 0, 0, 18911, 44757, 'Rajh'),
(39378, 1, 0, 'Can you feel it? The blessed warmth of the sun?', 14, 0, 100, 0, 0, 18912, 44761, 'Rajh'),
(39378, 2, 0, 'I send you to your deity.', 14, 0, 100, 0, 0, 18914, 44758, 'Rajh to Player'),
(39378, 2, 1, 'I will take this life as an offering!', 14, 0, 100, 0, 0, 18913, 44759, 'Rajh to Player'),
(39378, 3, 0, 'Blazing rays of light, take me!', 14, 0, 100, 0, 0, 18910, 44760, 'Rajh to Player');

DELETE FROM `creature_template_addon` WHERE `entry` IN (39635, 47922, 47040, 40835);
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(39635, '74109'),
(47922, '89131'),
(47040, '87645'),
(40835, '73658');

DELETE FROM `conditions` WHERE `SourceEntry`= 87653;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 87653, 0, 0, 31, 0, 3, 47040, 0, 0, 0, '', 'Inferno Leap - Target Inferno Leap');

-- Creature Inferno Leap 47040 SAI
SET @ENTRY := 47040;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 1, 87653, 0, 0, 0, 67, 0, 500, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell 87653 hit  - Trigger timed event #0 in 500 - 500 ms // "),
(@ENTRY, 0, 1, 0, 59, 0, 100, 0, 0, 0, 0, 0, 11, 87647, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 87647 on Self // ");

-- Creature Blazing Inferno 40927 SAI
SET @ENTRY := 40927;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 1, 43671, 0, 0, 0, 67, 0, 500, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On spell 43671 hit  - Trigger timed event #0 in 500 - 500 ms // "),
(@ENTRY, 0, 1, 0, 59, 0, 100, 1, 0, 0, 0, 0, 11, 89877, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 89877 on Action invoker // ");

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15990;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15990, 11, 0, 0, 'achievement_sun_of_a');

DELETE FROM `spell_dbc` WHERE `Id`= 76374;
INSERT INTO `spell_dbc` (`Id`, `CastingTimeIndex`, `DurationIndex`, `Comment`) VALUES
(76374, 0, 575, 'Summon Meteor');
DELETE FROM `spelleffect_dbc` WHERE `Id`= 155916;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`) VALUES
(155916, 28, 40927, 64, 12, 12, 18, 18, 76374, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_rajh_summon_meteor',
'spell_rajh_summon_sun_orb');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76375, 'spell_rajh_summon_meteor'),
(76338, 'spell_rajh_summon_sun_orb');
