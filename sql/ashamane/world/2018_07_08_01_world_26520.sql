
-- Festival Scorchling Horde 26520
UPDATE creature SET position_x=142.811, position_y=-4719.850, position_z=17.8981, orientation=1.79698 WHERE id=26520 AND guid=353067;

--
UPDATE creature SET position_x = -277.701630, position_y = -2667.983398, position_z = 92.450859, orientation = 4.623815 WHERE id=26520 AND guid = 352853;

--
UPDATE creature SET position_x = -6995.182617, position_y = 921.804749, position_z = 9.230270, orientation = 1.111767 WHERE guid = 352966;

-- Sar'theris Strand
UPDATE creature SET position_x = -1857.531006, position_y = 3058.434326, position_z = 0.836879, orientation = 1.215616 WHERE guid = 352994;

-- Nagrand
UPDATE creature SET position_x = -1215.812622, position_y = 7478.835938, position_z = 22.179300, orientation = 3.233664 WHERE guid = 353645;

-- Ruins of Thaurissan 
UPDATE creature SET position_x = -7599.558594, position_y = -2080.920898, position_z = 126.041420, orientation = 3.169070 WHERE guid = 352702;

-- Sholazar Basin
UPDATE creature SET position_x = 5500.890625, position_y = 4877.314941, position_z = -197.747070, orientation = 3.175186 WHERE guid = 353362;

-- Shadowmoon Valley
UPDATE creature SET position_x = -3068.479492, position_y = 2390.841309, position_z = 61.989639, orientation = 3.618936 WHERE guid = 353542;

-- Netherstorm 
UPDATE creature SET position_x = 2915.812988, position_y = 3688.631104, position_z = 144.152512, orientation = 3.200477 WHERE guid = 353607;

-- Bilgewater Harbor
SET @CGUID=375150;
DELETE FROM creature WHERE guid=@CGUID;
INSERT INTO creature 
(guid, id, map, zoneId, areaId, spawnMask, phaseUseFlags, PhaseId, PhaseGroup, terrainSwapMap, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, MovementType, npcflag, unit_flags, unit_flags2, unit_flags3, dynamicflags, ScriptName, VerifiedBuild)
VALUES
(@CGUID, 26520, 1, 4709, 4853, 1, 0, 0, 0, -1, 0, 0, 3412.449219, -6726.726563, 52.698486, 1.805525, 300, 0.0, 0, 87, 0, 0, 0, 0, 0, 0, 0, "", 0);
DELETE FROM game_event_creature WHERE guid=@CGUID;
INSERT INTO game_event_creature VALUES (1, @CGUID); 
SET @CGUID=@CGUID+1;

-- Twilight Highlands
UPDATE creature SET position_x = -3775.733154, position_y = -5240.852539, position_z = 36.585831, orientation = 3.487612 WHERE guid = 352500;

-- Move NPC: 26520 Festival Scorchling
UPDATE creature SET position_x = 137.402786, position_y = -4722.752930, position_z = 17.616600, orientation = 5.064082 WHERE guid = 353067;


-- 26520 Festival Scorchling
DELETE FROM creature_text WHERE CreatureID=26520;
INSERT INTO creature_text 
(CreatureID, groupid, id, text, type, language, probability, emote, duration, sound, comment, BroadcastTextID)
VALUES
(26520, 1, 0, "Thank you again, $n, for this delectable incense.", 12, 0, 100.0, 0, 0, 0, "", 25699),
(26520, 2, 0, "%s devours the incense.  It\'s ravenous!", 42, 0, 100.0, 0, 0, 0, "", 25717),
(26520, 3, 0, "So good!  So packed with energy!", 12, 0, 100.0, 0, 0, 0, "", 25718),
(26520, 4, 0, "It has everything a growing scorchling needs!", 12, 0, 100.0, 0, 0, 0, "", 25719),
(26520, 5, 0, "I can feel the power SURGING within me!", 12, 0, 100.0, 0, 0, 0, "", 25730),
(26520, 6, 0, "%s bellows with laughter!", 42, 0, 100.0, 0, 0, 0, "", 25720),
(26520, 7, 0, "Now!  Finally!  Our plans can take effect!", 12, 0, 100.0, 0, 0, 0, "", 25721),
(26520, 8, 0, "KNEEL, LITTLE MORTAL!  KNEEL BEFORE THE MIGHT OF THE HERALD OF RAGNAROS!", 12, 0, 100.0, 0, 0, 0, "", 25722),
(26520, 9, 0, "YOU WILL ALL PERISH IN FLAMES!", 12, 0, 100.0, 0, 0, 0, "", 25723),
(26520, 10, 0, "%s blinks...", 42, 0, 100.0, 0, 0, 0, "", 25724),
(26520, 11, 0, "Ah.  I was merely jesting...", 12, 0, 100.0, 0, 0, 0, "", 25725);


delete from creature_text_locale where CreatureID=26520;

UPDATE creature_template SET AIName="", ScriptName="npc_festival_scorchling_26520" WHERE entry=26520;

DELETE FROM smart_scripts WHERE entryorguid=26520;
