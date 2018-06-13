DELETE FROM `spell_bonus_data` WHERE `entry` IN (379, 974, 52042);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(379, 0.4762, -1, -1, -1, 'Shaman - Earth Shield heal'),
(974, 0, 0, 0, 0, 'Shaman - Earth Shield'),
(52042, -1, 0, 0, 0, 'Shaman - Healing Stream Totem');
