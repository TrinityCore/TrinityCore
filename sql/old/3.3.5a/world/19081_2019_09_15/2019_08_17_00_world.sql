-- Burn with fire spell_linked_spell hack
DELETE FROM spell_linked_spell WHERE `spell_trigger` IN (-19386, -24132, -24133, -27068, -49011, -49012);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_wyvern_sting';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-19386,'spell_hun_wyvern_sting');
