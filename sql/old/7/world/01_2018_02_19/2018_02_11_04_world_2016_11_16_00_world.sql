-- Adds a reference to the spell_vael_burning_adrenaline script for Burning Adrenaline (Vael Fight)
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_vael_burning_adrenaline';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('18173', 'spell_vael_burning_adrenaline');
