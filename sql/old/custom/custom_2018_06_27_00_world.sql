-- Heroic Throw
UPDATE `spell_bonus_data` SET `ap_bonus`= 0.75 WHERE `entry`= 57755;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (12809, 46968, 6544);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(12809, 0, 0, -1, 0, 'Warrior - Concussion Blow'),
(46968, 0, 0, -1, 0, 'Warrior - Shockwave'),
(6544, 0, 0, 0.5, 0, 'Warrior - Heroic Leap');
