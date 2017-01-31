DELETE FROM `player_factionchange_reputations` WHERE `alliance_id` IN (1134, 1174, 1242, 1353, 1376, 1387, 1419, 1682, 1691, 1710, 1731, 1733, 1738);
INSERT INTO `player_factionchange_reputations` (`alliance_id`, `horde_id`) VALUES
(1134, 1133), -- Gilneas <-> Bilgewater Cartel
(1174, 1172), -- Wildhammer Clan <-> Dragonmaw Clan
(1242, 1228), -- Pearlfin Jinyu <-> Forest Hozen
(1353, 1352), -- Tushui Pandaren <-> Huojin Pandaren
(1376, 1375), -- Operation: Shieldwall <-> Dominance Offensive
(1387, 1388), -- Kirin Tor Offensive <-> Sunreaver Onslaught
(1419, 1374), -- Bizmo's Brawlpub (Season 1) <-> Brawl'gar Arena (Season 1)
(1682, 1681), -- Wrynn's Vanguard <-> Vol'jin's Spear
(1691, 1690), -- Bizmo's Brawlpub <-> Brawl'gar Arena
(1710, 1708), -- Sha'tari Defense <-> Laughing Skull Orcs
(1731, 1445), -- Council of Exarchs <-> Frostwolf Orcs
(1733, 1739), -- Delvar Ironfist <-> Vivianne
(1738, 1740); -- Defender Illona <-> Aeda Brightdawn
