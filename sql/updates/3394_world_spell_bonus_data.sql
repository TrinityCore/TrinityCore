DELETE FROM `spell_bonus_data` WHERE `entry` IN (48505,50288,50294,53191,53188,53194,53189,53195,53190);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `comments`) VALUES
(50288, 0.05, 0, 0, 'Druid - Starfall rank 1'),
(50294, 0.012, 0, 0, 'Druid - Starfall AOE rank 1'),
(53191, 0.05, 0, 0, 'Druid - Starfall rank 2'),
(53188, 0.012, 0, 0, 'Druid - Starfall AOE rank 2'),
(53194, 0.05, 0, 0, 'Druid - Starfall rank 3'),
(53189, 0.012, 0, 0, 'Druid - Starfall AOE rank 3'),
(53195, 0.05, 0, 0, 'Druid - Starfall rank 4'),
(53190, 0.012, 0, 0, 'Druid - Starfall AOE rank 4');
