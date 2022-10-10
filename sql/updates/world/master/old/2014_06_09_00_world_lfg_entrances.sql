REPLACE INTO `lfg_entrances` (dungeonId, name, position_x, position_y, position_z, orientation) VALUES
(542, 'Theramore''s Fall - lvl 85', -3813.674, -4790.984, 10.53071, 0.8520145),
(567, 'Theramore''s Fall - lvl 90', -3813.674, -4790.984, 10.53071, 0.8520145),
(517, 'A Brewing Storm - Normal', 2249.792, -1124.648, 485.5298, 4.632702),
(639, 'A Brewing Storm - Heroic', 2249.792, -1124.648, 485.5298, 4.632702),
(492, 'Greenstone Village', 2009.54, -2040.325, 221.0688, 1.536579),
(499, 'Unga Ingoo', -3101.01, 729.672, 0.747235, 0),
(537, 'Assault on Zan''vess - Horde', -1437.23, 3934.49, 6.51026, 0.01811268), -- check faction
(593, 'Assault on Zan''vess - Alliance', -1437.23, 3934.49, 6.51026, 0.01811268), -- check faction
(539, 'Brewmoon Festival', 1736.451, 302.5903, 475.8858, 1.138288),
(586, 'Dagger in the Dark - Horde', 778.3403, -191.1806, 402.4454, 6.221129), -- check faction
(616, 'Dagger in the Dark - Alliance', 778.3403, -191.1806, 402.4454, 6.221129), -- check faction
(595, 'Domination Point', -1751.345, 2488.858, 33.95753, 3.188432), -- not valid coords
(637, 'Blood in the Snow - Heroic', -5251.29, -426.649, 388.467, 2.041704),
(646, 'Blood in the Snow - Normal', -5251.29, -426.649, 388.467, 2.041704),
(625, 'The Secrets of Ragefire - Heroic', 1396.58, 802.536, 38.8645, 1.921415),
(649, 'The Secrets of Ragefire - Normal', 1396.58, 802.536, 38.8645, 1.921415),
(624, 'Dark Heart of Pandaria - Heroic', 1127.2, 905.2379, 404.1013, 3.650223),
(647, 'Dark Heart of Pandaria - Normal', 1127.2, 905.2379, 404.1013, 3.650223),
--
(527, 'Mogu''shan Vaults - Guardians of Mogu''shan', 3861.08, 1044.91, 490.073, 0), -- checked
(528, 'Mogu''shan Vaults - The Vault of Mysteries', 4276.98, 1462.39, 445.461, 1.570796), -- checked
(529, 'Heart of Fear - The Dread Approach', -2351.16, 459.964, 422.341, 0), -- checked
(610, 'Throne of Thunder - Last Stand of the Zandalari', 5892.094, 6615.736, 106.1092, 4.712389), -- checked
(611, 'Throne of Thunder - Forgotten Depths', 6043.058, 5072.52, -45.37531, 4.752635), -- checked
(612, 'Throne of Thunder - Halls of Flesh-Shaping', 6081.015, 4433.471, -13.14653, 2.174639), -- checked
(613, 'Throne of Thunder - Pinnacle of Storms', 5915.455566, 4115.099609, 202.296967, 3.914904), -- custom coords
(716, 'Siege of Orgrimmar - Vale of Eternal Sorrows - RF', 1441.052490, 250.507233, 283.558044, 1.578357), -- checked
(726, 'Siege of Orgrimmar - Vale of Eternal Sorrows - Flex', 1441.052490, 250.507233, 283.558044, 1.578357), -- checked
(717, 'Siege of Orgrimmar - Gates of Retribution - RF', 1440.256226, -5016.055664, 12.089993, 1.684395), -- custom coords
(728, 'Siege of Orgrimmar - Gates of Retribution - Flex', 1440.256226, -5016.055664, 12.089993, 1.684395), -- custom coords
(724, 'Siege of Orgrimmar - The Underhold - RF', 1672.121582, -4722.635254, -240.562347, 5.308998), -- custom coords
(729, 'Siege of Orgrimmar - The Underhold - Flex', 1672.121582, -4722.635254, -240.562347, 5.308998), -- custom coords
(725, 'Siege of Orgrimmar - Downfall - RF', 1970.512451, -5186.089844, -272.251709, 3.738217), -- custom coords
(730, 'Siege of Orgrimmar - Downfall - Flex', 1970.512451, -5186.089844, -272.251709, 3.738217); -- custom coords

REPLACE INTO `areatrigger_teleport` (id, name, target_map, target_position_x, target_position_y, target_position_z, target_orientation) VALUES
(614, 'Scarlet Halls - Entrance', 1001, 820.743, 607.8125, 13.63888, 0), -- checked
(7801, 'Scarlet Halls - Exit', 0, 2869.072021, -820.845337, 160.331528, 0.411862), -- checked
(4261, 'Scarlet Monastery - Entrance', 1004, 1124.565430, 511.299072, 0.989200, 1.538889), -- checked
(7802, 'Scarlet Monastery - Exit', 0, 2916.097656, -801.541565, 160.331528, 3.506339); -- checked