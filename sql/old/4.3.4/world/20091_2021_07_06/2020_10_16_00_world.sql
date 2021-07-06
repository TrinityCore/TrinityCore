DELETE FROM `spell_bonus_data` WHERE `entry` IN (59881, 24640, 80003, 2818, 61193, 66217, 56815, 62036, 79270, 80015, 95933, 58859, 79136, 59653);
INSERT INTO `spell_bonus_data` (`entry`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(59881, 0.0175, 0.0175, 'Hunter - Rake'),
(24640, 0, 0.014, 'Hunter - Scorpid Poison'),
(80003, 0, 0.023, 'Hunter - Black Arrow'),
(2818, 0, 0.035, 'Rogue - Deadly Poison'),
(61193, 0.04, 0.04, 'Hunter - Spirit Strike'),
(66217, 0.05, 0.05, 'Death Knight - Rune Strike Off-Hand'),
(56815, 0.1, 0, 'Death Knight - Rune Strike'),
(62036, 0.1, 0, 'Death Knight - Rune Strike'),
(79270, 0.1, 0, 'Warrior - Damage Shield'),
(80015, 0.1, 0, 'Generic - Steady Shot'),
(95933, 0.1115, 0, 'Hunter - Black Arrow'),
(58859, 0.15, 0, 'Shaman - Spirit Bite'),
(79136, 0.176, 0, 'Rogue - Venomous Wound'),
(59653, 0.2, 0, 'Warrior - Damage Shield');

UPDATE `spell_bonus_data` SET `direct_bonus`= 0, `ap_bonus`= 0.0732 WHERE `entry`= 20925; -- Holy Shield
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.0732 WHERE `entry`= 8680; -- Instant Poison
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.108 WHERE `entry`= 60089; -- Faerie Fire (Feral)
