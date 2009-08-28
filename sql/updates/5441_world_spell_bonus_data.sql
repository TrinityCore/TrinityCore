DELETE FROM `spell_bonus_data` WHERE `entry` IN(53733, 31804);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(53733, 0.22, -1, 0.14, -1, 'Paladin - Judgement of Corruption'),
(31804, 0.22, -1, 0.14, -1, 'Paladin - Judgement of Vengeance');