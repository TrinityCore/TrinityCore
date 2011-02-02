-- Some spell bonus data mostly for DK spells and trinket spells
DELETE FROM `spell_bonus_data` WHERE `entry` IN (63544,54181,55078,55095,50536,52212,51460,48721,45477,54757,45055,60203,60488,45429);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES 
(63544, 0, -1, -1, -1, 'Priest - Empowered Renew'),
(54181, 0, -1, -1, -1, 'Warlock - Fel Synergy'),
(55078, 0, 0, -1, 0.06325, 'Death Knight - Blood Plague'),
(55095, -1, 0, -1, 0.06325, 'Death Knight - Frost Fever'),
(50536, -1, 0, -1, -1, 'Death Knight - Unholy Blight (Rank 1)'),
(52212, 0, -1, 0.0475, -1, 'Death Knight - Death and Decay'),
(51460, 0, -1, -1, -1, 'Death Knight - Necrosis'),
(48721, 0, -1, 0.04, -1, 'Death Knight - Blood Boil'),
(45477, 0, -1, 0.1, -1, 'Death Knight - Icy Touch'),
(54757, 0, -1, -1, -1, 'Hand-Mounted Pyro Rocket - Pyro Rocket'),
(45055, 0, -1, -1, -1, 'Timbal\'s Focusing Crystal - Shadow Bolt'),
(60203, 0, -1, -1, -1, 'Darkmoon Card: Death'),
(60488, 0, -1, -1, -1, 'Extract of Necromatic Power'),
(45429, 0, -1, -1, -1, 'Shattered Sun Pendant of Acumen - Arcane Bolt');
