-- Siphon Essence should not scale with spellpower
DELETE FROM `spell_bonus_data` WHERE `entry`=38395;
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(38395,0,0,0,0, 'Warlock - Siphon Essence T6 2P proc');
