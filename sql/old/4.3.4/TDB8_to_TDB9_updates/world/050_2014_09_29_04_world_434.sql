DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceGroup` = 50047;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 50047, 93072, 0, 7, 9, 0, 28806, 0, 0, 0, 0, 0, '', 'Requires Fear No Evil quest active for spellclick'),
(18, 50047, 93072, 0, 5, 9, 0, 28808, 0, 0, 0, 0, 0, '', 'Requires Fear No Evil quest active for spellclick'),
(18, 50047, 93072, 0, 6, 9, 0, 28809, 0, 0, 0, 0, 0, '', 'Requires Fear No Evil quest active for spellclick'),
(18, 50047, 93072, 0, 4, 9, 0, 28810, 0, 0, 0, 0, 0, '', 'Requires Fear No Evil quest active for spellclick'),
(18, 50047, 93072, 0, 3, 9, 0, 28811, 0, 0, 0, 0, 0, '', 'Requires Fear No Evil quest active for spellclick'),
(18, 50047, 93072, 0, 0, 9, 0, 28812, 0, 0, 0, 0, 0, '', 'Requires Fear No Evil quest active for spellclick'),
(18, 50047, 93072, 0, 1, 9, 0, 28813, 0, 0, 0, 0, 0, '', 'Requires Fear No Evil quest active for spellclick'),
(18, 50047, 93072, 0, 2, 9, 0, 29082, 0, 0, 0, 0, 0, '', 'Requires Fear No Evil quest active for spellclick');

DELETE FROM `waypoints` WHERE `entry` = 50047;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(50047, 1, -8836.792, -154.6042, 80.29581, 'Injured Stormwind Infantry path (Fear No Evil quest)'),
(50047, 2, -8853.476, -147.5382, 81.02872, 'Injured Stormwind Infantry path (Fear No Evil quest)'),
(50047, 3, -8880.7, -134.434, 80.70754, 'Injured Stormwind Infantry path (Fear No Evil quest)'),
(50047, 4, -8899.063, -126.9965, 81.6905, 'Injured Stormwind Infantry path (Fear No Evil quest)'),
(50047, 5, -8911.901, -126.3507, 81.40427, 'Injured Stormwind Infantry path (Fear No Evil quest)'),
(50047, 6, -8911.997, -134.3038,  80.75057, 'Injured Stormwind Infantry path (Fear No Evil quest)'),
(50047, 7, -8909.181, -144.8264, 81.94923, 'Injured Stormwind Infantry path (Fear No Evil quest)'),
(50047, 8, -8904.669, -156.7083, 81.93999, 'Injured Stormwind Infantry path (Fear No Evil quest)'),
(50047, 9, -8901.264, -160.1858, 81.93899, 'Injured Stormwind Infantry path (Fear No Evil quest)');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 50047;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(50047, 93072, 1, 0);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 50047;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 50047 AND `source_type` = 0 OR `entryorguid` = 5004700 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(50047, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, 11, 53034, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - On Reset - Cast ''Set Health Random'' spell'),
(50047, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 82, 16777216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - On Reset - Add npc_spellclick_spells flag'),
(50047, 0, 2, 3, 8, 0, 100, 1, 93097, 0, 0, 0, 83, 16777216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - On Spellhit - Remove npc_spellclick_spells flag'),
(50047, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 33, 50047, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - On Spellhit - Give Quest Credit to player'),
(50047, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 5004700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - On Spellhit - Start timed event'),
(5004700, 9, 0, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Stand up'),
(5004700, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Face Player'),
(5004700, 9, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Say line 0 (random)'),
(5004700, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Set Run'),
(5004700, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 50047, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - Actionlist - Start WP movement'),
(50047, 0, 5, 0, 58, 0, 100, 0, 9, 50047, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Injured Stormwind Infantry - On WP end - Despawn');

DELETE FROM `spell_script_names` WHERE `spell_id` = 93072;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93072, 'spell_q28813_get_our_boys_back_dummy');
