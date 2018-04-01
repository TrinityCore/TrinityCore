DELETE FROM `spell_script_names` WHERE ScriptName IN (
'spell_mage_nether_tempest'
);

INSERT INTO spell_script_names(`spell_id`, `ScriptName`) VALUES
(114923, 'spell_mage_nether_tempest');
