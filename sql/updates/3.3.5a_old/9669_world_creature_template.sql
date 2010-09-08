-- Icecrown Citadel needed vehicleIds

-- Lord Marrowgar : Bone Spike vehicle
UPDATE `creature_template` SET `vehicleId`=533 WHERE `entry`=36619;
-- Deathbringer Saurfang
UPDATE `creature_template` SET `VehicleId`=591 WHERE `entry` IN (37813, 3781301, 3781302, 3781303);
 -- High Overlord Saurfang
UPDATE `creature_template` SET `VehicleId`=599 WHERE `entry` IN (37187, 38156, 38637, 38638);