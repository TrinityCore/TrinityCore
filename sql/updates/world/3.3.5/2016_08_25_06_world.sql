-- Skadi the ruthless
SET @PATH := 2689300; -- Do not change this value without updating the following values in boss_skadi.cpp: GRAUF_PATH_INITIAL,GRAUF_PATH_RIGHT,GRAUF_PATH_LEFT.
DELETE FROM `waypoint_data` WHERE `id` IN(@PATH, @PATH+1, @PATH+2);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 310.2165, -510.5302, 120.5487, 0, 0, 1, 0, 100, 0), -- Initial
(@PATH, 1, 300.8685, -520.3249, 133.3664, 0, 0, 1, 0, 100, 0),
(@PATH, 2, 298.3447, -529.4818, 137.2831, 0, 0, 1, 0, 100, 0),
(@PATH, 3, 309.0959, -540.3195, 134.9774, 0, 0, 1, 0, 100, 0),
(@PATH, 4, 323.6415, -547.9715, 130.3106, 0, 0, 1, 0, 100, 0),
(@PATH, 5, 357.078,  -549.1597, 116.3105, 0, 0, 1, 0, 100, 0),
(@PATH, 6, 401.2573, -550.2768, 114.9216, 0, 0, 1, 0, 100, 0),
(@PATH, 7, 464.5062, -555.9442, 114.4494, 0, 0, 1, 0, 100, 0),
(@PATH, 8, 496.192,  -556.9628, 114.8661, 0, 0, 1, 0, 100, 0),
(@PATH, 9, 523.2011, -548.9916, 114.8661, 0, 0, 1, 0, 100, 0),
(@PATH+1, 0, 453.1242, -517.17, 120.0273, 0, 0, 1, 0, 100, 0), -- Right
(@PATH+1, 1, 388.3312, -514.3768, 121.1193, 0, 0, 1, 0, 100, 0),
(@PATH+1, 2, 340.2752, -512.0926, 122.3138, 0, 0, 1, 0, 100, 0),
(@PATH+1, 3, 313.0756, -509.138,  125.175, 0, 0, 1, 0, 100, 0),
(@PATH+1, 4, 296.6964, -522.6705, 133.7026, 0, 0, 1, 0, 100, 0),
(@PATH+1, 5, 301.2957, -549.4583, 137.4249, 0, 0, 1, 0, 100, 0),
(@PATH+1, 6, 335.0746, -552.1211, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+1, 7, 397.6237, -553.9203, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+1, 8, 459.6321, -558.0078, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+1, 9, 505.5458, -568.7815, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+1, 10, 518.099,  -560.8499, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+1, 11, 520.4827, -541.5633, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+2, 0, 451.9824, -509.2508, 120.0273, 0, 0, 1, 0, 100, 0), -- Left
(@PATH+2, 1, 399.2607, -510.0719, 121.1193, 0, 0, 1, 0, 100, 0),
(@PATH+2, 2, 350.6099, -508.3901, 122.3138, 0, 0, 1, 0, 100, 0),
(@PATH+2, 3, 325.8217, -506.7769, 125.175, 0, 0, 1, 0, 100, 0),
(@PATH+2, 4, 301.2941, -516.6706, 133.7026, 0, 0, 1, 0, 100, 0),
(@PATH+2, 5, 301.2957, -549.4583, 137.4249, 0, 0, 1, 0, 100, 0),
(@PATH+2, 6, 335.0746, -552.1211, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+2, 7, 397.6237, -553.9203, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+2, 8, 459.6321, -558.0078, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+2, 9, 505.5458, -568.7815, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+2, 10, 518.099, -560.8499, 119.8416, 0, 0, 1, 0, 100, 0),
(@PATH+2, 11, 520.4827, -541.5633, 119.8416, 0, 0, 1, 0, 100, 0);

UPDATE `creature_template` SET `InhabitType`=4, `HoverHeight`='3.75' WHERE `entry` IN(26893,30775);
UPDATE `creature_template` SET `unit_flags`=320 WHERE `entry` IN(26693,30807);
UPDATE `creature_template` SET `ScriptName`='npc_grauf' WHERE  `entry`IN(26893);
UPDATE `creature_template` SET `unit_flags`=320 WHERE  `entry`IN(26893,30775);
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `guid` IN(126125,126126,126127);
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_ymirjar_warrior' WHERE  `entry`=26690;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_ymirjar_witch_doctor' WHERE  `entry`=26691;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_ymirjar_harpooner' WHERE  `entry`=26692;
UPDATE `gameobject_template` SET `ScriptName`='' WHERE `entry` IN (192175,192176,192177);

DELETE FROM `areatrigger_scripts` WHERE `ScriptName`='at_skadi_gaunlet';
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4991,'at_skadi_gaunlet');

DELETE FROM `creature_text` WHERE `entry` IN (26893);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `TextRange`, `BroadcastTextID`) VALUES
(26893, 0, 0, '%s takes a deep breath!', 41, 0, 100, 0, 0, 0, 'Grauf - Emote', 1, 20774),
(26893, 1, 0, 'Skadi the Ruthless is within range of the harpoon launchers!', 41, 0, 100, 0, 0, 0, 'Skadi Emote', 1, 27809);

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (49308);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,49308,64,0,0,'Disable LoS for spell Utgard Pinacle Reset Check');

-- Conditions
UPDATE `conditions` SET `ConditionValue2`=19871 WHERE `SourceTypeOrReferenceId`=13 and`SourceGroup`=1 and`SourceEntry`=48641;
DELETE FROM `conditions` WHERE `SourceEntry` IN (47593,47594,47563,48642,47547,49308) and `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 47593, 0, 0, 31, 0, 3, 28351, 0, 0, 0, 0, '', ''),
(13, 1, 47594, 0, 0, 31, 0, 3, 28351, 0, 0, 0, 0, '', ''),
(13, 1, 47563, 0, 0, 31, 0, 3, 28351, 0, 0, 0, 0, '', ''),
(13, 1, 48642, 0, 0, 31, 0, 3, 26893, 0, 0, 0, 0, '', ''),
(13, 1, 48642, 0, 1, 31, 0, 3, 22515, 0, 0, 0, 0, '', ''),
(13, 1, 47547, 0, 0, 31, 0, 3, 28351, 0, 0, 0, 0, '', ''),
(13, 1, 49308, 0, 0, 31, 0, 3, 28351, 0, 0, 0, 0, '', ''),
(13, 2, 49308, 0, 0, 31, 0, 3, 26693, 0, 0, 0, 0, '', '');

DELETE FROM `spell_area` WHERE `spell`=47546;
INSERT INTO `spell_area`(`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(47546,1196,0,0,0,0,0,1,64,11);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` IN(23472,19871,28351);
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=28351;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (28351,26690,26691,26692);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28351, 0, 0, 0, 8, 0, 100, 0, 47563, 0, 0, 0, 11, 47574, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Breath Trigger - Cast Freezing Trap AoE'),
(28351, 0, 1, 0, 8, 0, 100, 0, 47593, 0, 0, 0, 11, 47594, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Breath Trigger - Cast Freezing Trap AoE');

DELETE FROM `spelldifficulty_dbc` WHERE  `id` IN (50225,50255,50228,50258,59334,47579,49089,49084,49091);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(49084, 49084, 59246),
(49089, 49089, 59247),
(49091, 49091, 59249),
(50255, 50255, 59331),
(50258, 50258, 59334),
(50228, 50228, 59322),
(47579, 47579, 60020);

DELETE FROM `spell_custom_attr` WHERE `entry`=48642;
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(48642, 32768); -- SPELL_ATTR0_CU_IGNORE_ARMOR

DELETE FROM `spell_script_names` where `ScriptName` IN ('spell_skadi_poisoned_spear','spell_freezing_cloud_area_right','spell_freezing_cloud_area_left','spell_summon_gauntlet_mobs_periodic','spell_skadi_launch_harpoon','spell_skadi_reset_check','spell_freezing_cloud_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(50255, 'spell_skadi_poisoned_spear'),
(59331, 'spell_skadi_poisoned_spear'),
(47594, 'spell_freezing_cloud_area_right'),
(47574, 'spell_freezing_cloud_area_left'),
(47579, 'spell_freezing_cloud_damage'),
(60020, 'spell_freezing_cloud_damage'),
(59275, 'spell_summon_gauntlet_mobs_periodic'),
(48642, 'spell_skadi_launch_harpoon'),
(49308, 'spell_skadi_reset_check');

DELETE FROM `spell_target_position` where `id`=61790;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(61790, 0, 575, 476.799, -511.167, 104.723, 3.14159, 20779);

DELETE FROM `disables` WHERE  `sourceType`=4 AND `entry`=7595;
DELETE FROM `achievement_criteria_data` where `criteria_id` = 7595 and `type` = 11;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES
(7595, 11, 'achievement_girl_love_to_skadi');
