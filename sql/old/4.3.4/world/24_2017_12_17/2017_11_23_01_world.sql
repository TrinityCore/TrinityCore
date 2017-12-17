-- Set scriptname for instance
UPDATE `instance_template` SET `script`= 'instance_lost_city_of_the_tolvir' WHERE `map`= 755;

-- Correct wrong base level of non-heroic bosses
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86 WHERE `entry` IN (44577, 43612, 43614, 44819);

-- General Husam
UPDATE `creature_template` SET `difficulty_entry_1`= 48932, `mechanic_immune_mask`= 667893759, `scriptname`= 'boss_general_husam' WHERE `entry`= 44577;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `exp`= 3, `speed_walk`= 2.8, `speed_run`= 1.42857, `unit_flags`= 32832, `unit_flags2`= 67584, `VehicleId`= 1036, `movementId`= 154, `mechanic_immune_mask`= 667893759 WHERE `entry`= 48932;
-- Shockwave Stalker
UPDATE `creature_template` SET `minlevel`= 82, `maxlevel`= 82, `faction`= 35, `unit_flags`= 33554432, `unit_flags2`= 2048, `InhabitType`= 4, `flags_extra`= 131, `speed_run`= 1.14286 WHERE `entry`= 44711;
-- Shockwave Visual
UPDATE `creature_template` SET `minlevel`= 82, `maxlevel`= 82, `faction`= 14, `unit_flags`= 33554432, `unit_flags2`= 2048, `InhabitType`= 4, `flags_extra`= 131 WHERE `entry`= 44712;
-- Tol'Vir Land Mine
UPDATE `creature_template` SET `minlevel`= 82, `maxlevel`= 82, `faction`= 14, `unit_flags`= 33554432, `unit_flags2`= 2048, `InhabitType`= 1, `flags_extra`= 131, `scriptname`= 'npc_husam_tolvir_land_mine_trigger' WHERE `entry`= 44840;
-- Tol'Vir Land Mine Vehicle
UPDATE `creature_template` SET `minlevel`= 82, `maxlevel`= 82, `faction`= 14, `unit_flags`= 33554432, `unit_flags2`= 2048, `InhabitType`= 1, `flags_extra`= 131, `VehicleId`= 1050, `scriptname`= 'npc_husam_tolvir_land_mine_vehicle' WHERE `entry`= 44798;
-- Tol'Vir Land Mine 2 
UPDATE `creature_template` SET `minlevel`= 82, `maxlevel`= 82, `faction`= 14, `unit_flags`= 33554432, `unit_flags2`= 2048, `InhabitType`= 1, `flags_extra`= 131, `scriptname`= 'npc_husam_tolvir_land_mine' WHERE `entry`= 44796;
-- Bad Intentions Target
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 128 WHERE `entry`= 44586;

DELETE FROM `creature_text` WHERE `CreatureID`= 44577;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(44577, 0, 0, 'Invaders, you shall go no further!', 14, 0, 100, 0, 0, 0, 49310, 'General Husam to Player'),
(44577, 1, 0, 'Insolent rat!', 14, 0, 100, 0, 0, 0, 49311, 'General Husam to Player'),
(44577, 2, 0, 'Murkash!', 14, 0, 100, 0, 0, 0, 49313, 'General Husam'),
(44577, 3, 0, '|TInterface\\Icons\\spell_nature_earthquake.blp:20|t%s begins to cast |cFFFF0000|Hspell:83445|h[Shockwave]!|h|r', 41, 0, 100, 0, 0, 0, 44921, 'General Husam'),
(44577, 4, 0, 'Tread Lightly.', 14, 0, 100, 0, 0, 0, 49314, 'General Husam'),
(44577, 5, 0, 'Siamat must not be freed! Turn back before it is too late!', 14, 0, 100, 0, 0, 0, 49312, 'General Husam to Player');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_husam_hammer_fist', 
'spell_husam_hammer_fist',
'spell_husam_shockwave_summon_search',
'spell_husam_shockwave',
'spell_husam_shockwave',
'spell_husam_mystic_trap',
'spell_husam_mystic_trap',
'spell_husam_detonate_traps',
'spell_husam_bad_intentions',
'spell_husam_hurl',
'spell_husam_hurl_vehicle');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83654, 'spell_husam_hammer_fist'),
(91256, 'spell_husam_hammer_fist'),
(83466, 'spell_husam_shockwave_summon_search'),
(83445, 'spell_husam_shockwave'),
(91257, 'spell_husam_shockwave'),
(83644, 'spell_husam_mystic_trap'),
(91252, 'spell_husam_mystic_trap'),
(91263, 'spell_husam_detonate_traps'),
(83113, 'spell_husam_bad_intentions'),
(83236, 'spell_husam_hurl'),
(83235, 'spell_husam_hurl_vehicle');

DELETE FROM `creature_template_addon` WHERE `entry` IN (44711, 44712);
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(44711, '83129');

DELETE FROM conditions WHERE SourceEntry IN (83445, 91257, 83466, 81350, 91263, 91263, 83235);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ScriptName, Comment) VALUES
(13, 7, 83466, 0, 0, 31, 0, 3, 44712, 0, 0, 0, '', 'Shockwave Searcher - Target Shockwave Visual'),
(13, 7, 83445, 0, 0, 31, 0, 3, 44711, 0, 0, 0, '', 'Shockwave - Target Shockwave Stalker'),
(13, 7, 91257, 0, 0, 31, 0, 3, 44711, 0, 0, 0, '', 'Shockwave - Target Shockwave Stalker'),
(13, 7, 91263, 0, 0, 31, 0, 3, 44796, 0, 0, 0, '', 'Detonate Traps - Target Tolvir Land Mine');

-- Creature Shockwave Visual 44712 SAI
SET @ENTRY := 44712;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 11, 83127, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell 83127 on Self // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 5000, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 5000 - 5000 ms // "),
(@ENTRY, 0, 2, 3, 59, 0, 100, 1, 0, 0, 0, 0, 28, 83127, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Remove aura due to spell 83127 // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 83454, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 83454 on Self // ");

-- Creature Bad Intentions Target 44586 SAI
SET @ENTRY := 44586;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 27, 0, 100, 0, 0, 0, 0, 0, 67, 0, 1000, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On passenger boarded (vehicle) - Trigger timed event #0 in 1000 - 1000 ms // "),
(@ENTRY, 0, 1, 2, 59, 0, 100, 0, 0, 0, 0, 0, 11, 83339, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell 83339 on Action invoker // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 50630 on Self // ");
