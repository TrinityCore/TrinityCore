DELETE FROM `spell_bonus_data` WHERE `entry` IN (45284,45297);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES
(45284,0.357,-1,-1,-1,'Shaman - LO Lightning Bolt'),
(45297,0.285,-1,-1,-1,'Shaman - LO Chain Lightning');
