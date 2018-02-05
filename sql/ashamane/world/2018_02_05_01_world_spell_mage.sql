DELETE FROM `spell_script_names` WHERE ScriptName IN (
'spell_mage_frost_bomb_damage',
'spell_mage_pyroblast_clearcasting_driver',
'spell_mage_kindling',
'spell_mage_pyroblast',
'spell_mage_flamestrike',
'spell_mage_blazing_barrier',
'spell_mage_conflagration',
'spell_mage_frenetic_speed',
'spell_mage_enhanced_pyrotechnics',
'spell_mage_fire_blast'
);

INSERT INTO spell_script_names(`spell_id`, `ScriptName`) VALUES
(113092, 'spell_mage_frost_bomb_damage'),
(44448, 'spell_mage_pyroblast_clearcasting_driver'),
(155148, 'spell_mage_kindling'),
(11366, 'spell_mage_pyroblast'),
(2120, 'spell_mage_flamestrike'),
(235313, 'spell_mage_blazing_barrier'),
(205023, 'spell_mage_conflagration'),
(236058, 'spell_mage_frenetic_speed'),
(157642, 'spell_mage_enhanced_pyrotechnics'),
(108853, 'spell_mage_fire_blast');

DELETE FROM `spell_proc` WHERE SpellId IN ( 155148 );
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Chance`, `Cooldown`, `Charges`) VALUES
(155148, 0x0, 3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x2, 0x2, 0, 0, 0);