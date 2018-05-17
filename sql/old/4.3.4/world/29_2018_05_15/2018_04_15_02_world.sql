-- 
DELETE FROM gameobject WHERE id=214611;
DELETE FROM gameobject WHERE guid IN (200631,200970,200971,200972);
INSERT INTO gameobject (guid, id, map, zoneId, areaId, spawnMask, phaseMask, PhaseId, PhaseGroup, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state, VerifiedBuild) VALUES
(200631, 203435, 671, 0, 0, 15, 0, 169, 0, -577.81, -531.414, 893.863, 0, 0, 0, 0, 1, 7200, 255, 1, 0),
(200970, 203436, 671, 0, 0, 15, 0, 169, 0, -577.81, -531.414, 893.863, 0, 0, 0, 0, 1, 7200, 255, 1, 0),
(200971, 203433, 671, 0, 0, 15, 0, 169, 0, -577.81, -531.414, 893.863, 0, 0, 0, 0, 1, 7200, 255, 1, 0),
(200972, 203434, 671, 0, 0, 15, 0, 169, 0, -577.81, -531.414, 893.863, 0, 0, 0, 0, 1, 7200, 255, 1, 0);
