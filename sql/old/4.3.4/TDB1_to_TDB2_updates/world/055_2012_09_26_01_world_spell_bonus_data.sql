DELETE FROM `spell_bonus_data` WHERE `entry` IN (6489,6789);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(6789,0.2143,0,0,0,'Spell Power Coeff for Death Coil');
