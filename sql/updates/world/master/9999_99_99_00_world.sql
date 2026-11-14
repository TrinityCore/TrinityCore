-- Demonic Gateway
UPDATE `creature_template` SET `npcflag` = `npcflag` | 16777216, `AIName` = '', `ScriptName` = 'npc_warl_demonic_gateway' WHERE `entry` IN (59262, 59271);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (59262, 59271);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(59262, 113902, 0, 0),
(59271, 113902, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` = 111771 AND `ScriptName` = 'spell_warl_demonic_gateway';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(111771, 'spell_warl_demonic_gateway');
