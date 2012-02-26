-- Spawn missing gameobject in world
DELETE FROM `gameobject` WHERE `id`=202443;
INSERT INTO `gameobject`(`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(2713025,202443,571,1,1,5804.72,640.837,647.627,-0.680677,0,0,-0.333807,0.942641,180,100,1);

-- Add gameobject_template
UPDATE gameobject_template set ScriptName = 'go_memorial_plaque_play_movie' WHERE entry = 202443;