--
UPDATE `creature` SET `MovementType`=1, `spawndist`=10  WHERE `id`IN (10956); 
UPDATE `creature_template` SET `InhabitType`=2 WHERE `entry`=10956;
