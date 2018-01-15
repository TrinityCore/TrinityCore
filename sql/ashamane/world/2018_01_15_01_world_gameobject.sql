-- Quest Stop the Bombardment, id:38727 Add missing banner
DELETE FROM gameobject WHERE guid = 20375675;
INSERT INTO gameobject (guid, id, map, zoneId, areaId, spawnMask, PhaseId, PhaseGroup, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state, VerifiedBuild) VALUES
(20375675, 243965, 1481, 0, 0, 1, 0, 0, 1813.36, 1543.43, 88.3732, 5.74205, 0, 0, 0.267278, -0.963619, 7200, 255, 1, 22423);
