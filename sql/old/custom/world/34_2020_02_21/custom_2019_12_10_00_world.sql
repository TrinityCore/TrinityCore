DELETE FROM `spell_bonus_data` WHERE `entry` IN (89753, 30213, 3110, 3716, 54049, 7814, 6360, 31707);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(89753, 0.231, 0, 0, 0, 'Warlock - Fel Storm'),
(30213, 0.264, 0, 0, 0, 'Warlock - Legion Strike'),
(3110, 0.657, 0, 0, 0, 'Warlock - Firebolt'),
(3716, 0.512, 0, 0, 0, 'Warlock - Torment'),
(54049, 1.228, 0, 0, 0, 'Warlock - Shadow Bite'),
(7814, 0.612, 0, 0, 0, 'Warlock - Lash of Pain'),
(6360, 0.85, 0, 0, 0, 'Warlock - Whiplash'),
(31707, 0.833, 0, 0, 0, 'Mage - Waterbolt');
