-- Wild Mushroom
UPDATE `creature_template` SET `InhabitType`= 12, `unit_flags`= 520, `flags_extra`= 2 WHERE `entry`= 47649;
-- Fungal Growth I and Fungael Growth II
UPDATE `creature_template` SET `InhabitType`= 12, `unit_flags`= 33554440, `unit_flags2`= 32, `flags_extra`= 2 WHERE `entry` IN (43484, 43497);
-- Treant
UPDATE `creature_template` SET `ScriptName`= 'npc_druid_treant' WHERE `entry`= 1964;

DELETE FROM `creature_template_addon` WHERE `entry` IN (43484, 43497);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(43484, '81282'),
(43497, '81289');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dru_wild_mushroom',
'spell_dru_wild_mushroom_detonate');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88747, 'spell_dru_wild_mushroom'),
(88751, 'spell_dru_wild_mushroom_detonate');

-- Creature Fungal Growth II 43484 SAI
SET @ENTRY := 43484;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 94339, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell 94339 on Self // ");

-- Creature Fungal Growth I 43497 SAI
SET @ENTRY := 43497;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 94339, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell 94339 on Self // ");
