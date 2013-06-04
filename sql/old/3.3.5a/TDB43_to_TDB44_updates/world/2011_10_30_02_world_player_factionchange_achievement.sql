-- World Event
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id` IN (2144,1707,2797,1038,1656,1684,1692) AND `horde_id` IN (2145,1693,2798,1039,1657,1683,1691);
INSERT INTO `player_factionchange_achievement` (`alliance_id`,`horde_id`) VALUES
(2144,2145),    -- What A Long, Strange Trip It's Been
(1707,1693),    -- Fool For Love
(2797,2798),    -- Noble Gardener
(1038,1039),    -- The Flame Warden / Keeper
(1656,1657),    -- Hallowed Be Thy Name
(1684,1683),    -- Brewmaster
(1692,1691);    -- Merrymaker

-- World Event: Hallow's End
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id` IN (963,966,969,970,1040) AND `horde_id` IN (971,967,965,968,1041);
INSERT INTO `player_factionchange_achievement` (`alliance_id`,`horde_id`) VALUES
(970,971),      -- Tricks and Treats of Azeroth
(966,967),      -- Tricks and Treats of Eastern Kingdoms
(963,965),      -- Tricks and Treats of Kalimdor
(969,968),      -- Tricks and Treats of Outland
(1040,1041);    -- Rotten Hallow

-- World Event: Love is in the Air
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id` IN (1280,1697) AND `horde_id` IN (1279,1698);
INSERT INTO `player_factionchange_achievement` (`alliance_id`,`horde_id`) VALUES
(1280,1279),    -- Flirt With Disaster
(1697,1698);    -- Nation of Adoration

-- World Event: Noblegarden
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id` IN (2421,2419) AND `horde_id` IN (2420,2497);
INSERT INTO `player_factionchange_achievement` (`alliance_id`,`horde_id`) VALUES
(2421,2420),    -- Noble Garden
(2419,2497);    -- Spring Fling

-- World Event: Midsummer Fire Festival
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id` IN (1035,1028,1029,1030,1022,1023,1024,1034) AND `horde_id` IN (1037,1031,1032,1033,1025,1026,1027,1036);
INSERT INTO `player_factionchange_achievement` (`alliance_id`,`horde_id`) VALUES
(1035,1037),    -- Desecration of the Alliance / Horde
(1028,1031),    -- Extinguishing Eastern Kingdoms
(1029,1032),    -- Extinguishing Kalimdor
(1030,1033),    -- Extinguishing Outland
(1022,1025),    -- Flame Warden / Keeper of Eastern Kingdoms
(1023,1026),    -- Flame Warden / Keeper of Kalimdor
(1024,1027),    -- Flame Warden / Keeper of Outland
(1034,1036);    -- The Fires of Azeroth

-- World Event: Brewfest
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id` IN (1184) AND `horde_id` IN (1203);
INSERT INTO `player_factionchange_achievement` (`alliance_id`,`horde_id`) VALUES
(1184,1203);    -- Strange Brew

-- World Event: Pilgrim's Bounty
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id` IN (3576,3556,3580,3596) AND `horde_id` IN (3577,3557,3581,3597);
INSERT INTO `player_factionchange_achievement` (`alliance_id`,`horde_id`) VALUES
(3576,3577),    -- Now We're Cookin'
(3556,3557),    -- Pilgrim's Paunch
(3580,3581),    -- Pilgrim's Peril
(3596,3597);    -- Pilgrim's Progress

-- World Event: Feast of Winter Veil
DELETE FROM `player_factionchange_achievement` WHERE `alliance_id` IN (4436,1686,1255) AND `horde_id` IN (4437,1685,259);
INSERT INTO `player_factionchange_achievement` (`alliance_id`,`horde_id`) VALUES
(4436,4437),    -- BB King
(1686,1685),    -- Bros. Before Ho Ho Ho's
(1255,259);     -- Scrooge
