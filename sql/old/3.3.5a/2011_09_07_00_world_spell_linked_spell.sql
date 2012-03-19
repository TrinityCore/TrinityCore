DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=44572;
INSERT INTO `spell_linked_spell` VALUES
(44572,71757,0, 'Deep Freeze - Damage Proc');

DELETE FROM `spell_bonus_data` WHERE `entry`=71757;
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(71757,2.143,0,0,0, 'Mage - Deep Freeze');
