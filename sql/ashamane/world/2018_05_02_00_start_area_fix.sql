-- Tauren start area fix
DELETE FROM `creature_questender` WHERE `id` = '3059' AND `quest` = '3091'; 
DELETE FROM `creature_questender` WHERE `id` = '3059' AND `quest` = '27020'; 
DELETE FROM `creature_queststarter` WHERE `id` = '44927' AND `quest` = '3091'; 
DELETE FROM `creature_queststarter` WHERE `id` = '44927' AND `quest` = '3092'; 
DELETE FROM `creature_queststarter` WHERE `id` = '44927' AND `quest` = '3093'; 
DELETE FROM `creature_queststarter` WHERE `id` = '44927' AND `quest` = '3094'; 
DELETE FROM `creature_queststarter` WHERE `id` = '44927' AND `quest` = '27014'; 
DELETE FROM `creature_queststarter` WHERE `id` = '44927' AND `quest` = '27015'; 
DELETE FROM `creature_queststarter` WHERE `id` = '44927' AND `quest` = '31165'; 
DELETE FROM `creature_queststarter` WHERE `id` = '2980' AND `quest` = '3091'; 
DELETE FROM `creature_queststarter` WHERE `id` = '2980' AND `quest` = '3092'; 
DELETE FROM `creature_queststarter` WHERE `id` = '2980' AND `quest` = '3093'; 
DELETE FROM `creature_queststarter` WHERE `id` = '2980' AND `quest` = '3094'; 
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (38345,43599);