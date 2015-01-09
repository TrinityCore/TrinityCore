/* Few changed zones updates */

-- Teldrassil, Rut'theran Village GY
UPDATE `game_graveyard_zone` SET `faction`=469 WHERE `id`=129;

-- Stranglethorn Vale, Booty Bay GY, Stranglethorn Vale & Gurubashi Arena GY,
UPDATE `game_graveyard_zone` SET `ghost_zone`=5287 WHERE `id` IN (109, 1458);

-- The Barrens, South GY, The Barrens, Camp Taurajo GY, The Barrens, Raptor Grounds & The Barrens, Central GY
UPDATE `game_graveyard_zone` SET `ghost_zone`=4709 WHERE `id` IN (229, 1289, 1432, 1433);

-- 4.3 dungeons & raid
DELETE FROM `game_graveyard_zone` WHERE `id`=1249 AND `ghost_zone` IN (5788, 5789, 5844, 5892);

/* Old dungeons graveyards */

-- Uldaman
DELETE FROM `game_graveyard_zone` WHERE `id`=8 AND `ghost_zone`=1337;

-- Scarlet Monastery
DELETE FROM `game_graveyard_zone` WHERE `id`=429 AND `ghost_zone`=796;

-- Dire Maul
DELETE FROM `game_graveyard_zone` WHERE `id`=849 AND `ghost_zone`=2557;

-- Zul'Farrak
DELETE FROM `game_graveyard_zone` WHERE `id`=209 AND `ghost_zone`=1176;

-- Gnomeregan
DELETE FROM `game_graveyard_zone` WHERE `id`=101 AND `ghost_zone`=721;

-- Stormwind Stockade
DELETE FROM `game_graveyard_zone` WHERE `id`=106 AND `ghost_zone`=717;

-- Wailling Caverns
DELETE FROM `game_graveyard_zone` WHERE `id`=10 AND `ghost_zone`=718;

-- Ragefire
DELETE FROM `game_graveyard_zone` WHERE `id`=850 AND `ghost_zone`=2437;

-- Blackfathom
DELETE FROM `game_graveyard_zone` WHERE `id`=469 AND `ghost_zone`=719;

-- Sunken Temple
DELETE FROM `game_graveyard_zone` WHERE `id` IN (108, 309) AND `ghost_zone`=1477;

-- Deadmines
DELETE FROM `game_graveyard_zone` WHERE `id` IN (4, 389) AND `ghost_zone`=1581;

-- Shadowfan Keep
DELETE FROM `game_graveyard_zone` WHERE `id` IN (97, 149) AND `ghost_zone`=209;

-- Scholomance
DELETE FROM `game_graveyard_zone` WHERE `id` IN (429, 629, 869) AND `ghost_zone`=2057;

-- Blackrock Spire, Blackwind Lair & Blackrock Depths
DELETE FROM `game_graveyard_zone` WHERE `id`=1469 AND `ghost_zone` IN (1583, 1584, 2677);

DELETE FROM `game_graveyard_zone` WHERE `id` IN (39, 389, 1459, 1460, 1488, 1489, 1491, 1492, 1494, 1495, 1496, 1497, 1689, 1690, 1692, 1693, 1694, 1695, 1696, 1697, 1698, 1699, 1700, 1701, 1702, 1704, 1705, 1706, 1707, 1708, 1709, 1710, 1711, 1712, 1713, 1716, 1721, 1722, 1723, 1724, 1725, 1730, 1731, 1732, 1733, 1734, 1741, 1742, 1743, 1744, 1745, 1746, 1747, 1748, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759, 1761, 1762, 1763, 1764, 1765, 1766, 1767, 1768, 1769, 1770, 1771, 1772, 1773, 1774, 1775, 1777, 1778, 1783, 1784, 1785, 1786, 1787, 1788, 1789, 1790, 1791, 1792, 1793, 1794, 1795, 1796, 1797, 1800, 1801, 1802, 1803, 1804, 1805, 1806, 1807, 1808, 1809, 1810, 1811, 1812, 1813, 1814, 1815, 1816, 1817, 1818, 1819, 1820, 1821, 1822, 1823, 1824, 1844, 1845, 1846, 1847, 1848, 1849, 1850, 1852, 1853, 1854, 1855, 1856, 1857, 1858, 1859, 1860, 1861, 1866, 1868, 1869, 1870, 1871, 1872, 1873, 1874, 1875, 1876, 1877, 1878, 1880, 1881, 1886, 1889, 1961, 1962, 2807, 2808, 2809, 2816, 3212);
INSERT INTO `game_graveyard_zone` (`id`, `ghost_zone`, `faction`) VALUES
(389, 5339, 0), -- Stranglethorn Vale, Northern Stranglethorn GY
(389, 33, 0), -- Stranglethorn Vale, Northern Stranglethorn GY
(1249, 5892, 0), -- Tanaris, CoT GY
(1249, 5788, 0), -- Tanaris, CoT GY
(1249, 5844, 0), -- Tanaris, CoT GY
(1249, 5789, 0), -- Tanaris, CoT GY
(1459, 5339, 0), -- Stranglethorn Vale, Central GY
(1459, 33, 0), -- Stranglethorn Vale, Central GY
(1460, 33, 0), -- Stranglethorn Vale, Savage Coast GY
(1460, 5339, 0), -- Stranglethorn Vale, Savage Coast GY
(1488, 4720, 0), -- The Lost Isles - Shipwreck Shore GY
(1489, 4720, 0), -- The Lost Isles - Orc Camp GY
(1491, 4720, 0), -- The Lost Isles - Wild Overlook GY
(1492, 4720, 0), -- The Lost Isles - Alliance Beachhead GY
(1494, 4714, 0), -- Gilneas - Duskhaven
(1495, 4714, 0), -- Gilneas - Farmstead GY
(1496, 4720, 0), -- The Lost Isles - Vengeance Wake - Phase 3 GY
(1497, 4720, 0), -- The Lost Isles - Vengeance Wake - Phase 4 GY
(1689, 4737, 0), -- Kezan - KTC Headquarters GY
(1690, 4737, 0), -- Kezan - Bilgewater Port GY
(1692, 4755, 0), -- Gilneas City - Merchant Quarter Graveyard
(1693, 4755, 0), -- Gilneas City - Military District Graveyard
(1694, 4755, 0), -- Gilneas City - Greymane Square Graveyard
(1695, 4755, 0), -- Gilneas City - Cathedral Graveyard
(1696, 4714, 0), -- Gilneas - Stormglen Graveyard
(1697, 4714, 0), -- Gilneas - Blackwald Graveyard
(1698, 4714, 0), -- Gilneas - Tempest's Reach Graveyard 2
(1699, 4714, 0), -- Gilneas - Aderic's Repose Graveyard
(1700, 14, 0), -- Durotar, Echo Isles GY
(1701, 4755, 0), -- Gilneas - Market GY
(1702, 4720, 0), -- The Lost Isles - Town-In-A-Box Phase 5 6 7 GY
(1704, 4720, 0), -- The Lost Isles - Lost Peak - Phase 5 6 7 GY
(1705, 4720, 0), -- The Lost Isles - Lost Caldera - Phase 5 6 7 GY
(1706, 4709, 0), -- South Barrens 4.x - Overgrowth GY
(1707, 4709, 0), -- South Barrens 4.x - East Overgrowth
(1708, 4720, 0), -- The Lost Isles - Warchief's Lookout - Phase 5 6 7 8 9 10 GY
(1709, 4709, 0), -- South Barrens 4.x - Firestone Point Graveyard
(1710, 4709, 0), -- South Barrens 4.x - Camp Taurajo Graveyard
(1711, 4720, 0), -- The Lost Isles - Sky Falls - Phase 8 9 10 GY
(1712, 4720, 0), -- The Lost Isles - Verdant Highlands - Phase 8 9 10 GY
(1713, 4720, 0), -- The Lost Isles - Bilgewater Lumber Yard - Phase 5 6 7 8 9 10 GY
(1716, 4720, 0), -- The Lost Isles - Oomlot Village GY
(1721, 5146, 0), -- Vashj'ir, Central Ruins GY
(1722, 5144, 0), -- Vashj'ir, Silver Tide Trench GY
(1723, 4815, 0), -- Vashj'ir, Mid Kelp Shelf GY
(1724, 4815, 0), -- Vashj'ir, Early Kelp Shelf GY
(1725, 5144, 0), -- Vashj'ir, Vrykul Shelf GY
(1730, 361, 0), -- Felwood, Shatter Scar GY
(1731, 361, 0), -- Felwood, Felpaw Village GY
(1732, 11, 0), -- Wetlands, Near Dun Modr GY
(1733, 16, 0), -- Azshara, Orgrimmar Rear Gate GY
(1734, 16, 0), -- Azshara, Valormok GY
(1741, 616, 0), -- Mount Hyjal 4.x - Aessina GY
(1742, 616, 0), -- Mount Hyjal 4.x - Crater GY
(1743, 616, 0), -- Mount Hyjal 4.x - Darkwhisper Gorge GY
(1744, 616, 0), -- Mount Hyjal 4.x - Ascendant's Circle GY
(1744, 5723, 0), -- Mount Hyjal 4.x - Ascendant's Circle GY
(1745, 5145, 0), -- Vashj'ir, Marianas Face GY
(1746, 5145, 0), -- Vashj'ir, Korthun's End GY
(1747, 5145, 0), -- Vashj'ir, Deepfin Ridge GY
(1748, 1, 0), -- Dun Morogh, Ironforge Airfield
(1751, 357, 67), -- Feralas, Camp Ataya GY (H)
(1752, 357, 469), -- Feralas, Dreamer's Rest GY (A)
(1753, 25, 0), -- Burning Steppes, Forgewright's Tomb
(1753, 4926, 0), -- Burning Steppes, Forgewright's Tomb
(1754, 357, 0), -- Feralas, Ruins of Feathermoon GY
(1755, 616, 0), -- Mount Hyjal 4.x - Aviana GY
(1756, 5042, 0), -- Deepholm, Crimson Expanse GY
(1757, 5042, 0), -- Deepholm, Temple of Earth GY
(1757, 5088, 0), -- Deepholm, Temple of Earth GY
(1758, 5042, 0), -- Deepholm, Shuddering Spires GY
(1759, 16, 0), -- Azshara, Arcane Pinnacle GY
(1761, 331, 0), -- Ashenvale, Zoram Strand GY
(1762, 2100, 0), -- Desolace, Maraudon GY
(1763, 1519, 469), -- Stormwind Cemetery, GY
(1764, 400, 0), -- Thousand Needles, High Perch GY (NEW)
(1765, 400, 0), -- Thousand Needles, Twilight Hammer Base GY (NEW)
(1766, 400, 0), -- Thousand Needles, Razorfen Downs GY (NEW)
(1767, 400, 0), -- Thousand Needles, Southsea Holdfast GY (NEW)
(1768, 4709, 0), -- South Barrens 4.x - Western Overgrowth GY
(1769, 4709, 0), -- South Barrens 4.x - Fort Triumph GY
(1770, 406, 0), -- Stonetalon Mountains, Charred Vale Overlook GY
(1771, 406, 0), -- Stonetalon Mountains, Cave GY
(1772, 8, 0), -- Swamp of Sorrows, Pool of Tears GY
(1773, 4720, 0), -- The Lost Isles - Volcanoth's Lair - Phase 8 GY
(1774, 4, 0), -- Blasted Lands, Red Reaches GY
(1775, 4, 0), -- Blasted Lands, Tainted Forest GY
(1777, 148, 0), -- Darkshore, Gary's Rock
(1778, 5004, 0), -- Vashj'ir, The Abyssal Maw
(1778, 5145, 0), -- Vashj'ir, The Abyssal Maw
(1783, 5095, 0), -- Tol Barad - Graveyard, Ironclad Garrison
(1784, 5095, 0), -- Tol Barad - Graveyard, West Spire
(1785, 5095, 0), -- Tol Barad - Graveyard, Warden's Vigil
(1786, 5095, 0), -- Tol Barad - Graveyard, South Spire
(1787, 5095, 0), -- Tol Barad - Graveyard, Slagworks
(1788, 5095, 0), -- Tol Barad - Graveyard, East Spire
(1789, 5095, 0), -- Tol Barad - Graveyard, Baradin Hold
(1789, 5600, 0), -- Tol Barad - Graveyard, Baradin Hold
(1790, 5042, 0), -- Deepholm, Twilight Overlook GY
(1791, 5042, 0), -- Deepholm, Central East GY
(1792, 5042, 0), -- Deepholm, Fractured Battlefront GY
(1793, 5042, 0), -- Deepholm, Needlerock Chasm GY
(1794, 5042, 0), -- Deepholm, Shattered Field GY
(1795, 5042, 0), -- Deepholm, Twilight Terrace GY
(1796, 5042, 0), -- Deepholm, Stone Hearth GY
(1797, 400, 0), -- Thousand Needles, Darkcloud Pinnacle GY (NEW)
(1800, 4922, 0), -- Twilight Highlands, Vermillion Redoubt GY
(1801, 4922, 469), -- Twilight Highlands, Kirthaven GY
(1802, 4922, 67), -- Twilight Highlands, Krazzworks GY
(1803, 4922, 67), -- Twilight Highlands, Dragonmaw Port GY
(1804, 4922, 469), -- Twilight Highlands, Smoot's Patrol GY
(1805, 4922, 469), -- Twilight Highlands, Twilight Shore GY
(1806, 5416, 0), -- Maelstrom GY
(1807, 5389, 67), -- Tol Barad - Graveyard, Horde Daily
(1808, 5389, 469), -- Tol Barad - Graveyard, Alliance Daily
(1809, 28, 0), -- Western Plaguelands, Argent Areal GY
(1810, 4706, 0), -- Ruins of Gilneas, Forward Command GY
(1811, 4706, 0), -- Ruins of Gilneas, Emberstone Village GY
(1812, 4922, 0), -- Twilight Highlands, Grim Batol GY
(1812, 4950, 0), -- Twilight Highlands, Grim Batol GY
(1813, 5336, 67), -- Twilight Highlands, Dragonmaw Port Ship GY
(1814, 4922, 469), -- Twilight Highlands, Victory Point GY
(1815, 4922, 67), -- Twilight Highlands, Crushblow GY
(1816, 4922, 67), -- Twilight Highlands, Bloodgulch GY
(1817, 618, 0), -- Winterspring, Gorge Upper Ledge
(1818, 5034, 0), -- Uldum Graveyard 000
(1819, 5034, 0), -- Uldum Graveyard 001
(1820, 5034, 0), -- Uldum Graveyard 002
(1820, 5396, 0), -- Uldum Graveyard 002
(1821, 5034, 0), -- Uldum Graveyard 003
(1822, 5034, 0), -- Uldum Graveyard 004
(1823, 5034, 0), -- Uldum Graveyard 005
(1823, 4945, 0), -- Uldum Graveyard 005
(1824, 5034, 0), -- Uldum Graveyard 006
(1824, 5638, 0), -- Uldum Graveyard 006
(1844, 46, 0), -- Burning Steppes, Center East GY
(1845, 16, 0), -- Azshara, Gallywix Pleasure Palace GY
(1846, 4922, 0), -- Twilight Highlands, The Twilight Citadel GY
(1846, 5334, 0), -- Twilight Highlands, The Twilight Citadel GY
(1847, 51, 0), -- Searing Gorge, Dustfire GY
(1848, 51, 0), -- Searing Gorge, Sea of Cinders GY
(1848, 5094, 0), -- Searing Gorge, Sea of Cinders GY
(1849, 51, 0), -- Searing Gorge, Near Blackrock GY
(1850, 51, 0), -- Searing Gorge, Micro Entrance GY
(1852, 267, 0), -- Hillsbrad Foothills, Purgation Isle GY
(1853, 5695, 0), -- Ahn'Qiraj:TFK - Terrace GY
(1854, 1519, 469), -- Stormwind Stockade, GY
(1854, 717, 0), -- Stormwind Stockade, GY
(1855, 17, 0), -- Northern Barrens 4.x - Wailing Caverns GY
(1856, 5034, 0), -- Uldum - Vortex Pinnacle GY
(1856, 5035, 0), -- Uldum - Vortex Pinnacle GY
(1857, 1637, 67), -- Durotar, Orgrimmar - Ragefire GY
(1857, 2437, 0), -- Durotar, Orgrimmar - Ragefire GY
(1858, 1176, 0), -- Tanaris, Zul'Farrak GY
(1858, 440, 0), -- Tanaris, Zul'Farrak GY
(1859, 2557, 0), -- Feralas, Dire Maul Dungeon GY
(1859, 357, 0), -- Feralas, Dire Maul Dungeon GY
(1860, 40, 0), -- Westfall, Moonbrook GY
(1861, 440, 0), -- Tanaris, Southern End GY
(1866, 4714, 0), -- Gilneas - Stagecoach Graveyard
(1868, 1581, 0), -- Westfall, Deadmines (Micro) GY
(1869, 718, 0), -- Northern Barrens 4.x - Wailing Caverns (Micro) GY
(1870, 130, 0), -- Silverpine Forest, Shadowfang Keep GY
(1870, 209, 0), -- Silverpine Forest, Shadowfang Keep GY
(1871, 719, 0), -- Ashenvale, Blackfathom (Micro) GY
(1872, 4709, 0), -- South Barrens 4.x - Razorfen Kraul GY
(1872, 491, 0), -- South Barrens 4.x - Razorfen Kraul GY
(1873, 4709, 0), -- South Barrens 4.x - Razorfen Downs (Micro) GY
(1873, 722, 0), -- South Barrens 4.x - Razorfen Downs (Micro) GY
(1874, 796, 0), -- Tirisfal Glades, Scarlet Moastery GY
(1874, 85, 0), -- Tirisfal Glades, Scarlet Moastery GY
(1875, 1337, 0), -- Badlands, Uldaman GY
(1875, 3, 0), -- Badlands, Uldaman GY
(1876, 1477, 0), -- Swamp of Sorrows, Sunken Temple GY
(1877, 1584, 0), -- Burning Steppes, Blackrock Depths GY
(1877, 25, 0), -- Burning Steppes, Blackrock Depths GY
(1878, 2057, 0), -- Western Plaguelands, Scholo GY
(1878, 28, 0), -- Western Plaguelands, Scholo GY
(1880, 1583, 0), -- Burning Steppes, Blackrock Spire GY
(1880, 2677, 0), -- Burning Steppes, Blackrock Spire GY
(1881, 1, 0), -- Dun Morogh, Gnomeregan (Micro) GY
(1881, 721, 0), -- Dun Morogh, Gnomeregan (Micro) GY
(1886, 357, 0), -- The Steam Pools
(1889, 141, 67), -- Teldrassil, Rut'theran Village (Horde) GY
(1961, 308, 0), -- Twilight Highlands, Forbidding Sea (Obsidian Forest) GY
(1962, 308, 0), -- Badlands, Forbidding Sea GY
(2807, 5733, 0), -- Molten Front, Malfurion's Breach GY
(2808, 5733, 0), -- Molten Front, Portal GY
(2809, 5733, 0), -- Molten Front, Spider GY
(2816, 5733, 0), -- Molten Front, Roost GY
(3212, 5861, 0); -- Darkmoon Island, First Aid GY
