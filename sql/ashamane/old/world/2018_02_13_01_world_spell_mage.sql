DELETE FROM `spell_script_names` WHERE ScriptName IN (
'spell_mage_arcane_explosion',
'spell_mage_arcane_missiles',
'spell_mage_arcane_missiles_damage',
'spell_mage_arcane_missiles_proc',
'spell_mage_arcane_missiles_charges',
'spell_mage_arcane_barrage',
'spell_mage_arcane_blast',
'spell_mage_unstable_magic',
'spell_mage_chrono_shift'
);

INSERT INTO spell_script_names(`spell_id`, `ScriptName`) VALUES
(30451, 'spell_mage_arcane_blast'),
(44425, 'spell_mage_arcane_barrage'),
(30451, 'spell_mage_unstable_magic'),
(133, 'spell_mage_unstable_magic'),
(228597, 'spell_mage_unstable_magic'),
(79683, 'spell_mage_arcane_missiles_charges'),
(7268, 'spell_mage_arcane_missiles_damage'),
(79684, 'spell_mage_arcane_missiles_proc'),
(5143, 'spell_mage_arcane_missiles'),
(1449, 'spell_mage_arcane_explosion'),
(235711, 'spell_mage_chrono_shift');
