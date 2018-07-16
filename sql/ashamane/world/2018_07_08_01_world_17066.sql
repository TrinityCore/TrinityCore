
-- 17066 Ribbon Pole Debug Target,   invisible bunny flying above sonnenbaum  z=+6.58
UPDATE creature SET MovementType=0, spawndist=0 WHERE id=17066;

-- double spawned creature
DELETE FROM creature WHERE id=17066 AND guid IN 
(370304, 370209, 370026, 370046, 370053, 370030, 370060, 370033, 369960, 370207, 370317, 
 369976, 369965, 370029, 370049, 370236, 370228, 370327, 370101, 370074, 370188, 370220, 
 370232, 370298, 370076, 370081, 370080, 370507, 370182, 370065, 370506, 370037, 369978,
 370133, 370279, 370018, 370175, 369950, 370071, 370161, 369952, 370016, 370306, 370307,
 370145, 370092, 370247, 370098, 370147, 370111, 370110, 370193);

DELETE FROM game_event_creature WHERE guid IN 
(370304, 370209, 370026, 370046, 370053, 370030, 370060, 370033, 369960, 370207, 370317, 
 369976, 369965, 370029, 370049, 370236, 370228, 370327, 370101, 370074, 370188, 370220, 
 370232, 370298, 370076, 370081, 370080, 370507, 370182, 370065, 370506, 370037, 369978,
 370133, 370279, 370018, 370175, 369950, 370071, 370161, 369952, 370016, 370306, 370307,
 370145, 370092, 370247, 370098, 370147, 370111, 370110, 370193);

DELETE FROM creature_addon WHERE guid IN 
(370304, 370209, 370026, 370046, 370053, 370030, 370060, 370033, 369960, 370207, 370317, 
 369976, 369965, 370029, 370049, 370236, 370228, 370327, 370101, 370074, 370188, 370220, 
 370232, 370298, 370076, 370081, 370080, 370507, 370182, 370065, 370506, 370037, 369978,
 370133, 370279, 370018, 370175, 369950, 370071, 370161, 369952, 370016, 370306, 370307,
 370145, 370092, 370247, 370098, 370147, 370111, 370110, 370193);
  
SET @CGUID=375110;  
-- dun morogh
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 0, 0, 1, 0, 0, 0, -1, 11686, 0, 146.6080, -4735.150, 21.5686, 5.0434, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- gadgetzan
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 440, 976, 1, 0, 0, 0, -1, 11686, 0, -7097.150, -3673.050, 17.8608, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Gold Road
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 440, 976, 1, 0, 0, 0, -1, 11686, 0, -307.5960, -2662.570, 99.7776, 1.7802, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- silithus
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 1377, 1377, 1, 0, 0, 0, -1, 11686, 0, -6977.80, 905.3590, 15.1267, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Dustwallow Marsh 
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 15, 496, 1, 0, 0, 0, -1, 11686, 0, -3109.660, -2751.570, 41.1917, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Sar'theris Strand
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 405, 598, 1, 0, 0, 0, -1, 11686, 0, -1845.720, 3037.150, 10.2341, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Sun Rock 
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 406, 460, 1, 0, 0, 0, -1, 11686, 0, 938.9120, 800.3670, 110.7590, -0.7854, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Silverwind Refuge
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 331, 420, 1, 0, 0, 0, -1, 11686, 0, 2132.750, -1289.040, 102.3397, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Everlook
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 618, 2255, 1, 0, 0, 0, -1, 11686, 0, 6838.460, -4579.630, 714.606, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Mulgore
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 215, 215, 1, 0, 0, 0, -1, 11686, 0, -2341.330, -609.3720, -1.2358, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Dragonblight 
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 571, 65, 65, 1, 0, 0, 0, -1, 11686, 0, 3765.480, 1499.230, 96.5409, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Borean Tundra
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 571, 3537, 4122, 1, 0, 0, 0, -1, 11686, 0, 4470.350, 5618.950, 64.7419, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Sholazar Basin
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 571, 3711, 4290, 1, 0, 0, 0, -1, 11686, 0, 5511.40, 4862.280, -191.72, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- The Storm Peaks 
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 571, 67, 4418, 1, 0, 0, 0, -1, 11686, 0, 6163.270, -1034.0, 415.8260, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Zul'Drak 
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 571, 66, 66, 1, 0, 0, 0, -1, 11686, 0, 5275.40, -2782.260, 298.6510, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Grizzly Hills
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 571, 394, 394, 1, 0, 0, 0, -1, 11686, 0, 3372.280, -2142.590, 131.0010, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Bilgewater Harbor 
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 16, 4821, 1, 0, 0, 0, -1, 11686, 0, 3414.210, -6718.10, 59.1703, 5.7770, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0); -- -271.092
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Un'Goro Crater 
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 490, 490, 1, 0, 0, 0, -1, 11686, 0, -7593.240, -1571.380, -264.5120, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0); -- -271.092
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Uldum
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 5034, 5715, 1, 0, 0, 0, -1, 11686, 0, -9475.340, -859.2830, 112.219, -0.5061, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Southern Barrens 
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 17066, 1, 4709, 4853, 1, 0, 0, 0, -1, 11686, 0, -3131.140, -1673.30, 99.2548, 5.7770, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- z=+ 6.58

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195541 Silithus
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, -6780.270, 555.1670, 10.2419, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195669 Feathermoon
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, -4399.50, 2171.790, 18.4012, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195351 Tanaris
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, -7243.90, -3843.010, 17.2497, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 196550 Winterspring
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, 6841.910, -4747.450, 704.5240, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195257 Dustwallow Marsh
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, -3479.460, -4206.160, 19.3071, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 196149 Ashenvale
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, 3064.250, -3279.830, 161.9430, 2.4086);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 196471 Darkshore
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, 7255.820, -135.1340, 22.1256, -1.1694);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195723 Desolace
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, -56.3741, 1236.720, 97.5307, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 196566 Teldrassil
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, 9781.940, 1034.60, 1305.40, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 197707 Crystalsong Forest
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 571, 11686, 5129.820, -697.730, 179.3580, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 197514 Dragonblight
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 571, 11686, 3945.280, -618.0920, 248.3370, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 197467 Borean Tundra
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 571, 11686, 4147.370, 5396.950, 32.9196, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 197518 Sholazar Basin
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 571, 11686, 5352.690, 4859.320, -184.6480, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 197802 The Storm Peaks
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 571, 11686, 6073.190, -1122.820, 427.2060, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 197688 Zul'Drak
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 571, 11686, 5612.380, -2623.0, 298.8870, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 197679 Grizzly Hills
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 571, 11686, 3416.270, -2886.620, 207.6470, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195793 Mirkfallon Lake
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, 1393.70, 969.5070, 157.7120, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195385 The Marsh
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, -7504.010, -1680.610, -273.7020, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195394 Uldum
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, -9344.330, -899.3540, 128.6240, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- NPC delete + insert: 17066 Ribbon Pole Debug Target: 195284 Southern Barrens
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature (guid, id, map, modelid, position_x, position_y, position_z, orientation) VALUES 
(@CGUID, 17066, 1, 11686, -3380.340, -2241.550, 98.4217, -0.5061);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;





