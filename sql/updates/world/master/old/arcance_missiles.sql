DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_mage_arcane_missiles';
DELETE FROM `spell_linked_spell` WHERE `spell_effect` IN (36032, -36032);