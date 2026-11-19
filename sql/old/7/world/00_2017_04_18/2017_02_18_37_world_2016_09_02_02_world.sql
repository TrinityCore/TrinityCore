DELETE FROM `player_factionchange_spells` WHERE `horde_id` IN (23248,35018,35028);
INSERT INTO `player_factionchange_spells` (`horde_id`, `alliance_id`) VALUES
(23248, 17454), -- Great Gray Kodo <-> Unpainted Mechanostrider
(35018, 49908), -- Purple Hawkstrider <-> Pink Elekk
(35028, 48027); -- Swift Warstrider <-> Black War Elekk
