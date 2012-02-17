-- Add spell Magma Totem TEST to disables table
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=61904;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `comment`) VALUES
(0, 61904, 8, 'Magma Totem TEST - can crash client by spawning too many totems');

-- Move a high guid to a lower one (Vyragosa)
SET @oldguid = 250006;
SET @newguid = 202602;
UPDATE `creature` SET `guid`=@newguid WHERE `guid`=@oldguid;
UPDATE `creature_addon` SET `guid`=@newguid, `path_id`=@newguid*100 WHERE `guid`=@oldguid;
UPDATE `waypoint_data` SET `id`=@newguid*100 WHERE `id`=@oldguid*100;

-- By Aokromes:
-- Orientation fix for portal from ghostlands to eastern plagelands.
UPDATE `areatrigger_teleport` SET `target_orientation`=2.255664 WHERE `id`=4386;
-- Spawn Arcane Container also on heroic mode SLab
UPDATE `gameobject` SET `spawnMask`=3 WHERE `guid`=22674;
