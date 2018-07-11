SET @PHASE_169  = 172329;
SET @PHASE_170  = 59073;
SET @PHASE_171  = 59074;

-- Sylvanas ( apparently it does not have the same spawn mask as proudmore it should ) --
UPDATE creature SET spawnMask = 6, spawntimesecs = 7200, PhaseId = 170, position_x = 4899.977, position_y = 2208.158, position_z = 638.8166, orientation = 0.3490658, VerifiedBuild = 26972 WHERE guid = 20548883;

-- Lady Proudmore --
UPDATE creature SET PhaseId = 171, position_x = 4901.254, position_y = 2206.861, position_z = 638.8166, orientation = 5.88176, VerifiedBuild = 26972 WHERE guid = 351792;

-- Phasing --
INSERT INTO spell_area (`spell`, `area`, `teamid`, `flags`) VALUES 
(@PHASE_170, 4809, 1, 3),
(@PHASE_169, 4809, 1, 3),
(@PHASE_171, 4809, 0, 3),
(@PHASE_169, 4809, 0, 3);

-- QuestLine Fixes --
DELETE FROM creature_queststarter WHERE id=37596 AND quest=24506; -- THIS NPC IS NOT SUPPOSED TO GIVE THIS QUEST

-- missing spawns --
SET @CGUID = 210219090;

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1, 37582, 632, 4809, 4809, 6, 171, 0, 0, 0, 4903.156, 2213.092, 638.8166, 0.1745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 37582
(@CGUID+2, 37583, 632, 4809, 4809, 6, 170, 0, 0, 0, 4902.829, 2212.832, 638.8166, 0.3490658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 37583
(@CGUID+3, 37779, 632, 4809, 4809, 6, 170, 0, 0, 0, 4899.854, 2205.901, 638.8166, 5.497787, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 37779
(@CGUID+4, 37774, 632, 4809, 4809, 6, 171, 0, 0, 0, 4899.706, 2205.898, 638.8166, 5.864306, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 37774
