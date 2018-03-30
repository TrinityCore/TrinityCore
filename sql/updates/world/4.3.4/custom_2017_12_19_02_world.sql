-- Siamat
UPDATE `creature_template` SET `difficulty_entry_1`= 51088, `minlevel`= 86, `maxlevel`= 86, `mechanic_immune_mask`= 667893759, `flags_extra`= 536870912, `scriptname`= 'boss_siamat' WHERE `entry`= 44819;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 16, `exp`= 3, `mechanic_immune_mask`= 667893759, `flags_extra`= 536870912 WHERE `entry`= 51088;
-- Servant of Siamat
UPDATE `creature_template` SET `minlevel`= 84, `maxlevel`= 84, `scale`= 1, `mechanic_immune_mask`= 667893759, `flags_extra`= 536870912, `scriptname`= 'npc_siamat_servant_of_siamat' WHERE `entry` IN (45259, 45268, 45269);
UPDATE `creature_template` SET `difficulty_entry_1`= 49256 WHERE `entry`= 45259;
UPDATE `creature_template` SET `difficulty_entry_1`= 49257 WHERE `entry`= 45268;
UPDATE `creature_template` SET `difficulty_entry_1`= 49258 WHERE `entry`= 45269;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `scale`= 1, `exp`= 3, `faction`= 16, `mechanic_immune_mask`= 667893759, `movementId`= 130, `flags_extra`= 536870912 WHERE `entry` IN (49256, 49257, 49258);
-- Cloud Burst
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 14, `unit_flags`= 33554944, `flags_extra`= 131 WHERE `entry`= 44541;
-- Minion of Siamat
UPDATE `creature_template` SET `difficulty_entry_1`= 49260, `minlevel`= 82, `maxlevel`= 82, `flags_extra`= 536870912, `scriptname`= 'npc_siamat_minion_of_siamat' WHERE `entry`= 44704;
UPDATE `creature_template` SET `minlevel`= 83, `maxlevel`= 83, `exp`= 3, `faction`= 16 , `movementId`= 130, `flags_extra`= 536870912 WHERE `entry`= 49260;
-- Minion of Siamat (Tempest Storm trigger)
UPDATE `creature_template` SET `minlevel`= 83, `maxlevel`= 83, `faction`= 16 , `unit_flags`= 33554496, `flags_extra`= 128 | 536870912 WHERE `entry`= 44713;  

DELETE FROM `spell_dbc` WHERE `Id`= 59632;
INSERT INTO `spell_dbc` (`Id`, `DurationIndex`, `Comment`) VALUES
(59632, 21, "Serverside Spell: mod scale 0.1");

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160080;
INSERT INTO `spelleffect_dbc` (`Id`, `EffectSpellId`, `Effect`, `EffectApplyAuraName`, `EffectBasePoints`, `EffectIndex`, `Comment`) VALUES
(160080, 59632, 6, 61, -90, 0, '');

DELETE FROM `creature_template_addon` WHERE `entry` IN (45259, 45268, 45269, 49256, 49257, 49258, 44541, 44704, 49260, 44713);
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(45259, '59632'),
(45268, '59632'),
(45269, '59632'),
(49256, '59632'),
(49257, '59632'),
(49258, '59632'),
(44541, '83048'),
(44704, '59632'),
(49260, '59632'),
(44713, '84512');

DELETE FROM `creature_text` WHERE `CreatureID`= 44819;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(44819, 0, 0, 'I. AM. UNLEASHED!', 14, 0, 100, 0, 0, 20231, 45481, 'Siamat - Intro'),
(44819, 1, 0, 'Winds of the south, rise and come to your master''s aid!', 14, 0, 100, 0, 0, 20227, 45483, 'Siamat - Aggro 1'),
(44819, 1, 1, 'Your city will be buried, your lives forfeit to the elements!', 14, 0, 100, 0, 0, 20230, 45486, 'Siamat - Aggro 2'),
(44819, 2, 0, 'Cower before the tempest storm!', 14, 0, 100, 0, 0, 20228, 45487, 'Siamat - Wailing Winds 1'),
(44819, 2, 1, 'Suffer the storm!', 14, 0, 100, 0, 0, 20229, 45485, 'Siamat - Wailing Winds 2'),
(44819, 3, 0, 'Nothing more than dust in the wind.', 14, 0, 100, 0, 0, 20232, 45482, 'Siamat - Slay'),
(44819, 4, 0, 'The sky... Beckons...', 14, 0, 100, 0, 0, 20226, 45484, 'Siamat - Death');
UPDATE `creature_text` SET `TextRange`= 2 WHERE `CreatureID`= 44819 AND `GroupID`= 0;

-- Spell Script Names
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_siamat_thunder_crash',
'spell_siamat_wailing_winds',
'spell_siamat_cloud_burst',
'spell_siamat_wailing_winds_player',
'spell_siamat_wailing_winds_knockback',
'spell_siamat_gathered_storms',
'spell_siamat_absorb_storms');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84521, 'spell_siamat_thunder_crash'),
(83066, 'spell_siamat_wailing_winds'),
(83790, 'spell_siamat_cloud_burst'),
(83089, 'spell_siamat_wailing_winds_player'),
(83566, 'spell_siamat_wailing_winds_knockback'),
(84987, 'spell_siamat_gathered_storms'),
(83151, 'spell_siamat_absorb_storms');

DELETE FROM `conditions` WHERE `SourceEntry`= 83151 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 83151, 0, 0, 31, 0, 3, 44713, 0, 0, 0, '', 'Absorb Storms - Target Minion of Siamat');

-- Creature Cloud Burst 44541 SAI
SET @ENTRY := 44541;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 3000, 3000, 0, 0, 11, 83051, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 3000 and 3000 ms) - Self: Cast spell 83051 on Self // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 28, 83048, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Remove aura due to spell 83048 // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn in 5000 ms // ");

-- Creature Minion of Siamat 44713 SAI
SET @ENTRY := 44713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 1000, 1000, 0, 0, 11, 83406, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 1000 and 1000 ms) - Self: Cast spell 83406 on Self // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Move in radius 10 yards // ");
