REPLACE INTO `spell_bonus_data` (entry, direct_bonus, comments) VALUES
(30451, 1.045, 'Mage - Arcane Blast');
DELETE FROM spell_script_names WHERE ScriptName = 'spell_mage_arcane_blast';
INSERT INTO spell_script_names VALUES
(30451, 'spell_mage_arcane_blast');
