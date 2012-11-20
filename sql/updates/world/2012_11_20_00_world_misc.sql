-- Mark of the Wild
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=1126;
DELETE FROM `spell_script_names` WHERE `spell_id`=1126 OR `ScriptName`='spell_dru_mark_of_the_wild';
INSERT INTO `spell_script_names` VALUES
(1126,'spell_dru_mark_of_the_wild');

-- Arcane Brilliance
DELETE FROM `spell_script_names` WHERE `spell_id`=1459 OR `ScriptName`='spell_mage_arcane_brilliance';
INSERT INTO `spell_script_names` VALUES
(1459,'spell_mage_arcane_brilliance');

-- Dalaran Brilliance
DELETE FROM `spell_script_names` WHERE `spell_id`=61316 OR `ScriptName`='spell_mage_dalaran_brilliance';
INSERT INTO `spell_script_names` VALUES
(61316,'spell_mage_dalaran_brilliance');

-- Blessing of Kings
DELETE FROM `spell_script_names` WHERE `spell_id`=20217 OR `ScriptName`='spell_pal_blessing_of_kings';
INSERT INTO `spell_script_names` VALUES
(20217,'spell_pal_blessing_of_kings');

-- Blessing of Might
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=19740;
DELETE FROM `spell_script_names` WHERE `spell_id`=19740 OR `ScriptName`='spell_pal_blessing_of_might';
INSERT INTO `spell_script_names` VALUES
(19740,'spell_pal_blessing_of_might');

-- Power Word: Fortitude
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=21562;
DELETE FROM `spell_script_names` WHERE `spell_id`=21562 OR `ScriptName`='spell_pri_power_word_fortitude';
INSERT INTO `spell_script_names` VALUES
(21562,'spell_pri_power_word_fortitude');

-- Shadow Protection
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=27683;
DELETE FROM `spell_scripts` WHERE `id`=27683;
DELETE FROM `spell_script_names` WHERE `spell_id`=27683 OR `ScriptName`='spell_pri_shadow_protection';
INSERT INTO `spell_script_names` VALUES
(27683,'spell_pri_shadow_protection');
