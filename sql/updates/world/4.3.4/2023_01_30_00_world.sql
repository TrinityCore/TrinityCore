DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_mage_fire_frost_ward',
'spell_mage_glyph_of_ice_block',
'spell_mage_ice_block',
'spell_mage_glyph_of_icy_veins',
'spell_mage_glyph_of_polymorph',
'spell_mage_icy_veins');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45438, 'spell_mage_ice_block'),
(12472, 'spell_mage_icy_veins');

DELETE FROM `spell_proc` WHERE `SpellId` IN (56372, 56374, 56375);
