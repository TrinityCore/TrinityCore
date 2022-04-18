--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_shimmering_vessel', 'spell_gen_arcane_charge');
UPDATE `spell_script_names` SET `ScriptName` = 'spell_muru_negative_energy_periodic' WHERE `ScriptName` = 'spell_gen_negative_energy_periodic';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_reliquary_of_souls_aura_of_anger' WHERE `ScriptName` = 'spell_gen_aura_of_anger';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_brutallus_burn' WHERE `ScriptName` = 'spell_gen_burn_brutallus';
