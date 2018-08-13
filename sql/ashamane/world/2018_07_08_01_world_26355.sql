
-- 26355 [DND] Midsummer Bonfire Faction Bunny - H,   invisible bunny inside bonfire Horde
UPDATE creature SET MovementType=0, spawndist=0 WHERE id=26355;

-- double spawned creature
DELETE FROM creature WHERE id=26355 AND guid IN
(370222, 370295, 370004, 369997, 369704, 369964, 369720, 369762, 369840, 
 370062, 369800, 370300, 369808, 369796, 370078, 370130, 369522, 369750, 370118, 
 370510, 370042, 369511, 370281, 369805, 369958, 370137, 369531, 370164, 370113, 
 369954, 369773, 370248, 370322, 369557, 369780, 370180, 370277, 370151, 369859);

DELETE FROM game_event_creature WHERE guid IN 
(370222, 370295, 370004, 369997, 369704, 369964, 369720, 369762, 369840, 
 370062, 369800, 370300, 369808, 369796, 370078, 370130, 369522, 369750, 370118, 
 370510, 370042, 369511, 370281, 369805, 369958, 370137, 369531, 370164, 370113, 
 369954, 369773, 370248, 370322, 369557, 369780, 370180, 370277, 370151, 369859);

DELETE FROM creature_addon WHERE guid IN 
(370222, 370295, 370004, 369997, 369704, 369964, 369720, 369762, 369840, 
 370062, 369800, 370300, 369808, 369796, 370078, 370130, 369522, 369750, 370118, 
 370510, 370042, 369511, 370281, 369805, 369958, 370137, 369531, 370164, 370113, 
 369954, 369773, 370248, 370322, 369557, 369780, 370180, 370277, 370151, 369859);

-- gadgetzan
UPDATE creature SET zoneId=440, areaId=976, position_x=-7122.510, position_y=-3657.110, position_z=10.0054 WHERE id=26355 AND guid=352916;

-- hellfire-peninsula
UPDATE creature SET zoneId=3483, areaId=3483, position_x=41.2448, position_y=2587.440, position_z=68.420 WHERE id=26355 AND guid=353518;

-- silithus
UPDATE creature SET position_x = -7000.750, position_y=918.8510, position_z = 9.237890, orientation = 4.347609 WHERE guid = 352963;

-- Everlook 
UPDATE creature SET position_x = 6855.990, position_y = -4564.40, position_z = 708.510, orientation = 1.440338 WHERE guid = 353128;

-- Terokkar Forest
UPDATE creature SET position_x = -2554.090, position_y = 4278.380, position_z = 21.1441, orientation = 4.764741 WHERE guid = 353473;

-- Wild Shore
UPDATE creature SET position_x = -14376.70, position_y = 115.9210, position_z = 1.4532, orientation = 2.245359 WHERE guid = 352818;

-- Hammerfall
UPDATE creature SET position_x = -1134.840, position_y = -3531.810, position_z = 51.0719, orientation = 4.865980 WHERE guid = 352494;

-- Silverpine Forest
UPDATE creature SET position_x = 585.7880, position_y = 1366.310, position_z = 90.0885, orientation = 3.253723 WHERE guid = 352552;

-- Sungraze Peak 
UPDATE creature SET position_x = 7693.530, position_y = -6836.510, position_z = 77.7878, orientation = 2.332183 WHERE guid = 352632;

-- Tirisfal
UPDATE creature SET position_x = 2279.250, position_y = 456.0090, position_z = 33.8671, orientation = 5.298807 WHERE guid = 352546;

-- Eversong Woods
UPDATE creature SET position_x = 9386.860, position_y = -6772.240, position_z = 14.4125, orientation = 1.601356 WHERE guid = 353252;

-- Crystalsong Forest 
UPDATE creature SET position_x = 5545.460, position_y = -743.8790, position_z = 151.5790, orientation = 1.601356 WHERE guid = 370549;

-- Borean Tundra
UPDATE creature SET position_x = 4444.650, position_y = 5628.330, position_z = 56.8540, orientation = 1.601356 WHERE guid = 370662;

-- Netherstorm 
UPDATE creature SET position_x = 2919.220, position_y = 3683.220, position_z = 143.6510, orientation = 2.9845 WHERE guid = 353590;

-- Northern Stranglethorn 
UPDATE creature SET position_x = -12432.50, position_y = 75.4410, position_z = 5.1181, orientation = 2.1119 WHERE guid = 352764;

-- Western Plaguelands 
UPDATE creature SET position_x = 1744.260, position_y = -834.1960, position_z = 60.0525, orientation = 0.3665 WHERE guid = 352560;

-- Un'Goro Crater 
UPDATE creature SET position_x = -7591.250, position_y = -1557.310, position_z = -271.4640, orientation = 1.7453 WHERE guid = 352906;

-- Twilight Highlands
UPDATE creature SET position_x = -3785.710, position_y = -5244.960, position_z = 37.2427, orientation = -0.8203 WHERE guid = 352492;

-- Uldum
UPDATE creature SET position_x = -9456.889648, position_y = -840.307007, position_z = 107.467003, orientation = 0.379171 WHERE guid = 352931;

-- Bilgewater Harbor
UPDATE creature SET position_x = 3416.660, position_y = -6706.350, position_z = 52.6976, orientation = 0.8552 WHERE guid = 369537;
