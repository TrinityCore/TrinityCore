UPDATE `spell_proc` SET `AttributesMask`= `AttributesMask` | 8 WHERE `SpellId`= 47283;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (89753, 30213, 3110, 3716, 54049, 7814, 6360, 17253, 16827, 31707);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(89753, 0.231, 0, 0, 0, 'Warlock - Fel Storm'),
(30213, 0.264, 0, 0, 0, 'Warlock - Legion Strike'),
(3110, 0.3285, 0, 0, 0, 'Warlock - Firebolt'),
(3716, 0.256, 0, 0, 0, 'Warlock - Torment'),
(54049, 0.614, 0, 0, 0, 'Warlock - Shadow Bite'),
(7814, 0.256, 0, 0, 0, 'Warlock - Lash of Pain'),
(6360, 0.425, 0, 0, 0, 'Warlock - Whiplash'),
(31707, 0.333, 0, 0, 0, 'Mage - Waterbolt');
