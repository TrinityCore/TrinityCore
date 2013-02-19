DELETE FROM `spell_bonus_data` where `entry` IN(62124, 64382);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(62124, 0.085, -1, -1, -1, 'Paladin - Hand of Reckoning'),
(64382, -1, -1, 0.5, -1, 'Warrior - Shattering Throw');
