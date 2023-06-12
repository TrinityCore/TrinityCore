-- Shadowflame
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= 47897;
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warl_shadowflame';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47897, 'spell_warl_shadowflame');

-- Backdraft
UPDATE `spell_proc` SET `SpellPhaseMask`= 0x1, `SpellTypeMask`= 0x1 WHERE `SpellId`= -47258;

-- Bane of Havoc
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_warl_bane_of_havoc',
'spell_warl_bane_of_havoc_tracking_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80240, 'spell_warl_bane_of_havoc'),
(85466, 'spell_warl_bane_of_havoc_tracking_aura');

DELETE FROM `spell_proc` WHERE `SpellId`= 85466;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(85466, 0x1, 0x2);
