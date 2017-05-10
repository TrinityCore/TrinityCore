-- Fix Startup Errors
DELETE FROM `creature_addon` WHERE `guid` IN (103589,104200);
DELETE FROM `waypoint_scripts` WHERE `id` IN (460,461);
