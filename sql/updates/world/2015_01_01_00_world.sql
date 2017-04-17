-- Fix Karazhan opera event game objects 
--Interaction fix => Disable player interaction with Door and Curtain
--Stage Door Left
UPDATE `gameobject_template` SET `flags` = 16 WHERE  `entry` = 184278;
--Stage Right Door
UPDATE `gameobject_template` SET `flags` = 16 WHERE  `entry` = 184279;
--Stage Curtain
UPDATE `gameobject_template` SET `flags` = 16 WHERE  `entry` = 183932;