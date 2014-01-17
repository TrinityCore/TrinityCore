DELETE FROM `spell_bonus_data` WHERE `entry` IN (54158, 20187, 31804);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(54158, 0.25, 0, 0.16, 0, 'Paladin - Judgement (Seal of Light, Seal of Wisdom, Seal of Justice)'),
(20187, 0.32, 0, 0.2, 0, 'Paladin - Judgement of Righteousness'),
(31804, 0.22, 0, 0.14, 0, 'Paladin - Judgement of Vengeance');