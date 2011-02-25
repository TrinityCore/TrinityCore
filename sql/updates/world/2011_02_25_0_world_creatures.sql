-- Correct bounding radius and combat reach for Right Arm and Left Arm
UPDATE `creature_model_info` SET `bounding_radius`=0.31, `combat_reach`=25 WHERE `modelid` IN(28821,28822);

-- Remove static spawns that are spawned by the encounter script and vehicle_accessory table
DELETE FROM `creature` WHERE `id` IN(32933,32934);

-- Update spawn data
UPDATE `creature` SET `unit_flags`=33554432, `deathstate`= 1, `MovementType`=0 WHERE `id`=34297;