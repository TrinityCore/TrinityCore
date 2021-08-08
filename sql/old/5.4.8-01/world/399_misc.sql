-- fix Warbringer slow effect
INSERT INTO `spell_linked_spell` VALUES (105771, 137637, 0, 'Warbringer slow effect');

-- fix Water Elemental Waterbolt damage
UPDATE `spell_bonus_data` SET `direct_bonus`='0.55' WHERE `entry`='31707';

-- fix Conversion heal with pvp-power
INSERT INTO `spell_script_names` VALUES (119980, 'spell_dk_conversion_heal_aura');
