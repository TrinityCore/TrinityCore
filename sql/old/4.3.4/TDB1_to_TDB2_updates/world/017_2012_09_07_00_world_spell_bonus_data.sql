SET @Spell := 28715; -- Flamecap Fire
DELETE FROM `spell_bonus_data` WHERE `entry`=@Spell;
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(@Spell,0,0,0,0, 'Flamecap Fire');
