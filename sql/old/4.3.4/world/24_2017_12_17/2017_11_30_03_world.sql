DELETE FROM `spell_bonus_data` WHERE `entry` IN (7268, 30451, 1449, 44425, 1463, 543, 133, 2948, 2136, 44614, 11366, 92315, 2120, 11113, 31661, 44457, 11129, 82731, 116, 42208, 120, 122, 30455, 11426, 44572);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
-- Arcane
(7268, 0.834, 0, 0, 0, 'Mage - Arcane Missiles'),
(30451, 1, 0, 0, 0, 'Mage - Arcane Blast'),
(1449, 0.186, 0, 0, 0, 'Mage - Arcane Explosion'),
(44425, 0.907, 0, 0, 0, 'Mage - Arcane Barrage'),
(1463, 0.807, 0, 0, 0, 'Mage - Mana Shield'),
(543, 0.807, 0, 0, 0, 'Mage - Mage Ward'),
-- Fire
(133, 1.236, 0, 0, 0, 'Mage - Fireball'),
(2948, 0.512, 0, 0, 0, 'Mage - Scorch'),
(2136, 0.429, 0, 0, 0, 'Mage - Fire Blast'),
(44614, 0.977, 0, 0, 0, 'Mage - Frostfire Bolt'),
(11366, 0.175, 0.18, 0, 0, 'Mage - Pyroblast'),
(92315, 0.175, 0.18, 0, 0, 'Mage - Pyroblast!'),
(2120, 0.146, 0.061, 0, 0, 'Mage - Flamestrike'),
(11113, 0.143, 0, 0, 0, 'Mage - Blast Wave'),
(31661, 0.193, 0, 0, 0, 'Mage - Dragon''s Breath'),
(44457, 0.25, 0.258, 0, 0, 'Mage - Living Bomb'),
(11129, 0.429, 0, 0, 0, 'Mage - Combustion'), -- DoT Damage needs script
(82731, 2.01, 0, 0, 0, 'Mage - Flame Orb'),
-- Frost
(116, 0.943, 0, 0, 0, 'Mage - Frostbolt'),
(42208, 0.162, 0, 0, 0, 'Mage - Frostbolt'),
(120, 0.214, 0, 0, 0, 'Mage - Cone of Cold'),
(122, 0.193, 0, 0, 0, 'Mage - Frost Nova'),
(30455, 0.378, 0, 0, 0, 'Mage - Ice Lance'),
(11426, 0.87, 0, 0, 0, 'Mage - Ice Barrier'),
(44572, 2.058, 0, 0, 0, 'Mage - Deep Freeze');
