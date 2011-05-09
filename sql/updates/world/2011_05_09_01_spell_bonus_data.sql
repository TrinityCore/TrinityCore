DELETE FROM `spell_bonus_data` WHERE `entry` IN (34914,64085);
INSERT INTO `spell_bonus_data` (`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`)
VALUES
(34914,0,0.4,0,0,'Priest - Vampiric Touch'),
(64085,1.2,0,0,0,'Priest - Vampiric Touch');