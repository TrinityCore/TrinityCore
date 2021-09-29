 -- Ahn'kahar Spell Flinger
SET @ENTRY := 30278;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1000, 2000, 23000, 27000, 11, 56698, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 23 - 27 seconds (1 - 2s initially) - Self: Cast spell Shadow Blast (56698) on Victim (flags: combat move)"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 5000, 8000, 13000, 16000, 11, 56702, 64, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 13 - 16 seconds (5 - 8s initially) - Self: Cast spell Shadow Sickle (56702) on Self (flags: combat move)");

DELETE FROM `spell_script_names` WHERE `spell_id` IN (56698, 59102, 56702, 59103);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(56698, 'spell_shadow_blast'),
(59102, 'spell_shadow_blast'),
(56702, 'spell_shadow_sickle'),
(59103, 'spell_shadow_sickle');

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (56698, 56701, 56702);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(56698, 56698, 59102),
(56701, 56701, 59104),
(56702, 56702, 59103);
