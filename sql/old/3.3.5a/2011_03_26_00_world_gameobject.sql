-- Spawning Focusing Iris
DELETE FROM `gameobject` WHERE `id`=193958;
INSERT INTO `gameobject` (guid,id,map,spawnMask,phaseMask,position_x,position_y,position_z,orientation,rotation0,rotation1,rotation2,rotation3,spawntimesecs,animprogress,state) VALUES 
(151791,193958,616,1,1,754.2546,1301.71973,266.170319,-1.60570168,0,0,0,0,120,0,1);
-- Spawning chests
DELETE FROM `gameobject` WHERE `id` IN (193967,193905);
INSERT INTO `gameobject` (guid,id,map,spawnMask,phaseMask,position_x,position_y,position_z,orientation,spawntimesecs,animprogress,state) VALUES
(151792,193905,616,1,1,764.56,1284.63,269,1.82,-604800,100,1), 
(151793,193967,616,2,1,764.56,1284.63,269,1.82,-604800,100,1);