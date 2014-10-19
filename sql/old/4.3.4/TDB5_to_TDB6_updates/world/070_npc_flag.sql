-- Fix for Quest 6342  npcflag change NPC 40552 - Leora 
UPDATE `creature_template` SET `npcflag` = 8195 WHERE `entry` = 40552;

-- spawn correction by Exodius
UPDATE `creature` SET `position_x`=9973.317, `position_y`=2623.924, `position_z`=1316.682, `orientation`=3.787364 WHERE `guid`=139430;
