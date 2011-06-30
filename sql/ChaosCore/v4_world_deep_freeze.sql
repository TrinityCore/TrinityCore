DELETE FROM `spell_linked_spell` WHERE spell_trigger = 44572;
INSERT INTO `spell_linked_spell` VALUES
(44572, 71757, 0, 'Deep Freeze - Damage Proc');

DELETE FROM `spell_script_names` WHERE `entry` IN (44572, 71757);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(71757, 'spell_mage_deep_freeze_dmg');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (71757);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(71757, 2.143, 0, 0, 0,'Mage - Deep Freeze');