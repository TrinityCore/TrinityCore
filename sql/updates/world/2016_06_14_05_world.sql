-- Pathing for Ghostlands Guardian Entry: 16541 'TDB FORMAT' 
SET @NPC := 145414;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7150.675,`position_y`=-7072.731,`position_z`=55.28159 WHERE `guid`=@NPC;
