-- Bijou's Belongings fix
-- Closes https://github.com/TrinityCore/TrinityCore/issues/4121

DELETE FROM gameobject WHERE id=175334;
INSERT INTO gameobject (guid,id,map,spawnMask,phaseMask,position_x,position_y,position_z,orientation,rotation0,rotation1,rotation2,rotation3,spawntimesecs,animprogress,state) VALUES
(NULL, 175334, 229, 1, 1, -95.709, -457.935, -18.6968, 2.2666, 0, 0, 0, 0, 43200, 100, 1);