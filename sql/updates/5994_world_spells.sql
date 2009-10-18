
DELETE FROM `spell_bonus_data` WHERE `entry` IN (20187,54158);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(20187, 0, 0, 0, 0, 'Paladin - Judgement of Righteousness'),
(54158, 0, 0, 0, 0, 'Paladin - Judgement (Seal of Light, Seal of Wisdom, Seal of Justice)');
