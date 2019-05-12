DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_mage_impact',
'spell_mage_impact_triggered');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-11103, 'spell_mage_impact'),
(12355, 'spell_mage_impact_triggered');

UPDATE `spell_proc` SET `SpellTypeMask`= 1 WHERE `SpellId`= 64343;
