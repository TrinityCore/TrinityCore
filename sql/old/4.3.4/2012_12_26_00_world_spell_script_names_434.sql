-- Blast Wave
DELETE FROM `spell_script_names` WHERE `spell_id`=11113 OR `ScriptName`='spell_mage_blast_wave';
INSERT INTO `spell_script_names` VALUES
(11113,'spell_mage_blast_wave');

-- Blizzard
DELETE FROM `spell_script_names` WHERE `spell_id`=42208 OR `ScriptName`='spell_mage_blizzard';
INSERT INTO `spell_script_names` VALUES
(42208,'spell_mage_blizzard');

-- Frostbolt
DELETE FROM `spell_script_names` WHERE `spell_id`=116 OR `ScriptName`='spell_mage_frostbolt';
INSERT INTO `spell_script_names` VALUES
(116,'spell_mage_frostbolt');

-- Ice Barrier
DELETE FROM `spell_script_names` WHERE `spell_id`=11426 OR `ScriptName`='spell_mage_ice_barrier';
INSERT INTO `spell_script_names` VALUES
(11426,'spell_mage_ice_barrier');

-- Mana Shield
DELETE FROM `spell_script_names` WHERE `spell_id`=1463 OR `ScriptName`='spell_mage_mana_shield' OR `ScriptName`='spell_mage_incanters_absorbtion_manashield';
INSERT INTO `spell_script_names` VALUES
(1463,'spell_mage_mana_shield');

-- Mage Ward
DELETE FROM `spell_script_names` WHERE `spell_id`=543 OR `ScriptName`='spell_mage_mage_ward' OR `ScriptName`='spell_mage_incanters_absorbtion_absorb';
INSERT INTO `spell_script_names` VALUES
(543,'spell_mage_mage_ward');

-- Replenish Mana (Mana Gem)
DELETE FROM `spell_script_names` WHERE `spell_id`=5405 OR `ScriptName`='spell_mage_replenish_mana';
INSERT INTO `spell_script_names` VALUES
(5405,'spell_mage_replenish_mana');

-- Water Elemental's Freeze
DELETE FROM `spell_script_names` WHERE `spell_id`=33395 OR `ScriptName`='spell_mage_water_elemental_freeze';
INSERT INTO `spell_script_names` VALUES
(33395,'spell_mage_water_elemental_freeze');
