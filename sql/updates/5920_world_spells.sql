
-- Lifebloom Spell Bonus Data
DELETE FROM `spell_bonus_data` WHERE `entry` IN (33763,33778,48450,48451);

INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(33778, 0.516, 0, 0, 0, 'Druid - Lifebloom final heal'),
(33763, 0, 0.09518, 0, 0, 'Druid - Lifebloom HoT(rank 1)'),
(48450, 0, 0.09518, 0, 0, 'Druid - Lifebloom HoT(rank 2)'),
(48451, 0, 0.09518, 0, 0, 'Druid - Lifebloom HoT(rank 3)');
