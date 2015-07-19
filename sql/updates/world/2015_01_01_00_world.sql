-- Fix Karazhan opera event game objects 
-- Interaction fix => Disable player interaction with Door and Curtain
UPDATE `gameobject_template` SET `flags` = 16 WHERE `entry` IN (184278,184279,183932);
