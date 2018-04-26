-- Druid
DELETE FROM `spell_bonus_data` WHERE `entry` IN (
50464, -- Nourish
5176, -- Wrath
8921, -- Moonfire
467, -- Thorns
2912, -- Starfire
5185, -- Healing Touch
42231, -- Hurricane
5570, -- Insect Swarm
33763, -- Lifebloom
8936, -- Regrowth
774, -- Rejuvenation
50288, -- Starfall
44203, -- Tranquility
61391, -- Typhoon
48438 -- Wild Growth
);

-- Priest
DELETE FROM `spell_bonus_data` WHERE `entry` IN (
32546, -- Blinding Heal
34861, -- Circle of Healing
19236, -- Desperate Prayer
2944, -- Devouring Plague
64844, -- Devine Hymn
2061, -- Flash Heal
2060, -- Greater Heal
14914, -- Holy Fire
15237, -- Holy Nova Damage
23455, -- Holy Nova Heal
8092, -- Mind Blast
49821, -- Mind Sear
47750, -- Penance Heal
47666, -- Penance Damage
17, -- Power World: Shield
596, -- Player of Healing
33110, -- Prayer of Mending
139, -- Renew
32379, -- Shadow Word: Death
589, -- Shadow Word: Pain
34433, -- Shadowfiend
585, -- Smite
34914, -- Vampiric Touch
64085 -- Vampiric Touch (Dispelled)
);

-- Warlock
DELETE FROM `spell_bonus_data` WHERE `entry` IN (
755, -- Health Funel
47960, -- Shadowflame
31117 -- Unstable Affliction (Dispel)
);

-- Re-used from previous coefficient correction
-- Shaman
DELETE FROM `spell_bonus_data` WHERE `entry` IN (26364, 403, 421, 8042, 8050, 8056, 3606, 8349, 8187, 51490, 51505, 8004, 331, 77472, 1064, 5672, 379, 61295, 73921, 32175, 73899, 60103, 77478, 73683, 73682, 73685, 45297, 77451, 45284, 974, 8188);

-- Warlock
DELETE FROM `spell_bonus_data` WHERE `entry` IN (172, 686, 6229, 980, 603, 6789, 689, 1120, 5676, 6353, 17877, 348, 1949, 5857, 42223, 30108, 27243, 27285, 30283, 29722, 47897, 48181, 50796, 50590, 54786, 3110, 54049, 7814, 86121, 71521, 77799);

-- Mage
DELETE FROM `spell_bonus_data` WHERE `entry` IN (7268, 30451, 1449, 44425, 1463, 543, 133, 2948, 2136, 44614, 11366, 92315, 2120, 11113, 31661, 44457, 11129, 82731, 116, 42208, 120, 122, 30455, 11426, 44572, 71757, 44461, 31707);
