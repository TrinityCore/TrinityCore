UPDATE `creature_template` SET `InhabitType`= 12, `ScriptName`= 'boss_magmaw' WHERE `entry`= 41570;
UPDATE `creature_template` SET `InhabitType`= 12 WHERE `entry` IN (51101, 51102, 51103);

UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (41620, 41789);

DELETE FROM `vehicle_template_accessory` WHERE `entry`= 41570;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 41570;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(41570, 77901, 1, 1);

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_magmaw_magma_spit',
'spell_magmaw_mangle');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(95280, 'spell_magmaw_magma_spit'),
(92047, 'spell_magmaw_mangle');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (89743, 78360);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 89743, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Ride Vehicle - Target Magmaw'),
(13, 1, 78360, 0, 0, 31, 0, 3, 41570, 0, 0, 0, '', 'Ride Vehicle - Target Magmaw');

DELETE FROM `creature` WHERE `guid` IN (250054, 250053, 250052);
DELETE FROM `creature_addon` WHERE `guid` IN (250054, 250053, 250052);
