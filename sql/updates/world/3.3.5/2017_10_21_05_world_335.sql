-- 
-- Fix random movement of Lost Souls
UPDATE `creature` SET `spawndist`=6, `MovementType`=1 WHERE `guid` IN (44863, 44864);
-- Correct waypoints of Nissa Agamand
UPDATE `waypoint_data` SET `orientation`=0.7703, `delay`=45000 WHERE `id`=449900 AND `point`=1;
UPDATE `waypoint_data` SET `orientation`=1.3075, `delay`=25000 WHERE `id`=449900 AND `point`=14;
-- Reposition broken Scarlet Warrior
UPDATE `creature` SET `position_z`=37.2094 WHERE `guid`=38336;
