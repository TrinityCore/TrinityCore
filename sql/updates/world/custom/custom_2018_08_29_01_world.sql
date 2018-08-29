UPDATE `creature_template` SET `InhabitType`= 1, `flags_extra`= `flags_extra` | 512 WHERE `entry` IN (43875, 43876);
UPDATE `creature_template` SET `ScriptName`= 'npc_asaad_storm_target' WHERE `ScriptName`= 'npc_storm_target';
UPDATE `creature_template` SET `ScriptName`= 'npc_asaad_unstable_grounding_field' WHERE `ScriptName`= 'npc_unstable_grounding_field';

UPDATE `spell_script_names` SET `ScriptName`= 'spell_asaad_sots_targeting' WHERE `ScriptName`= 'spell_sots_targeting';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_asaad_sots_trigger' WHERE `ScriptName`= 'spell_sots_trigger';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_asaad_storm_rune_beam' WHERE `ScriptName`= 'spell_storm_rune_beam';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_asaad_grounding_field_visual_beams' WHERE `ScriptName`= 'spell_grounding_field_visual_beams';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_asaad_supremacy_of_the_storm' WHERE `ScriptName`= 'spell_supremacy_of_the_storm';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_asaad_supremacy_of_the_storm_visual' WHERE `ScriptName`= 'spell_supremacy_of_the_storm_visual';
UPDATE `spell_script_names` SET `ScriptName`= 'spell_asaad_static_cling' WHERE `ScriptName`= 'spell_static_cling';

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_asaad_summon_skyfall_star');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(96260, 'spell_asaad_summon_skyfall_star');

