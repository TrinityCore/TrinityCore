DELETE FROM `spell_script_names` WHERE ScriptName IN ('spell_mage_ice_block','spell_mage_frost_armor','spell_mage_novas_talent','spell_mage_chilled','spell_arti_mage_ebonbolt','spell_mage_jouster','spell_mage_jouster_buff','spell_mage_chain_reaction','spell_mage_chilled_to_the_core','spell_mage_nova_talent','spell_mage_splitting_ice','spell_mage_cold_snap','spell_mage_ice_lance_damage','spell_mage_ice_lance','spell_mage_flurry','spell_mage_ice_barrier','spell_mage_cone_of_cold','spell_mage_frostbolt','spell_mage_frozen_veins','spell_mastery_icicles_proc','spell_mastery_icicles_periodic','spell_mastery_icicles_glacial_spike','spell_mastery_icicles_mod_aura','spell_mage_frozen_touch','spell_mage_frost_bomb_damage','spell_mage_unstable_magic');

INSERT INTO spell_script_names(`spell_id`, `ScriptName`) VALUES
(45438, 'spell_mage_ice_block'),
(205708, 'spell_mage_chilled'),
(214634, 'spell_arti_mage_ebonbolt'),
(214626, 'spell_mage_jouster'),
(195391, 'spell_mage_jouster_buff'),
(195419, 'spell_mage_chain_reaction'),
(195448, 'spell_mage_chilled_to_the_core'),
(157997, 'spell_mage_nova_talent'),
(157980, 'spell_mage_nova_talent'),
(56377, 'spell_mage_splitting_ice'),
(120, 'spell_mage_cone_of_cold'),
(30455, 'spell_mage_ice_lance'),
(44614, 'spell_mage_flurry'),
(11426, 'spell_mage_ice_barrier'),
(195345, 'spell_mage_frozen_veins'),
(228597, 'spell_mage_frostbolt'),
(76613, 'spell_mastery_icicles_proc'),
(148023, 'spell_mastery_icicles_periodic'),
(199786, 'spell_mastery_icicles_glacial_spike'),
(214124, 'spell_mastery_icicles_mod_aura'),
(214125, 'spell_mastery_icicles_mod_aura'),
(214126, 'spell_mastery_icicles_mod_aura'),
(214127, 'spell_mastery_icicles_mod_aura'),
(214130, 'spell_mastery_icicles_mod_aura'),
(30451, 'spell_mage_unstable_magic'),
(133, 'spell_mage_unstable_magic'),
(228597, 'spell_mage_unstable_magic'),
(113092, 'spell_mage_unstable_magic'),
(235219, 'spell_mage_cold_snap'),
(205021, "spell_mage_ray_of_frost");


DELETE FROM `spell_proc` WHERE SpellId IN ( 195419, 195345 );
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Chance`, `Cooldown`, `Charges`) VALUES
(195419, 0x0, 3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x2, 0x2, 0, 0, 0),
(195345, 0x0, 3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x2, 0x2, 0, 0, 0);
