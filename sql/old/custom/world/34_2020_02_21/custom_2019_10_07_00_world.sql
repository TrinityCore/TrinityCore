UPDATE `creature_template` SET `DamageModifier`= 25, `flags_extra`= `flags_extra` | 1 WHERE `entry`= 48940;

DELETE FROM `creature` WHERE `guid`= 375851;
DELETE FROM `creature_addon` WHERE `guid`= 375851;
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (47297, 48939);

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(375851, 47296, 36, 1581, 0, 3, 169, 0, 0, 0, -303.0248, -516.4625, 55.81993, 0.1745329, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Helix Gearbreaker

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_helix_explode',
'spell_helix_helix_ride',
'spell_helix_ride',
'spell_helix_ride_vehicle',
'spell_helix_ride_face_timer_aura',
'spell_helix_helix_ride_face_timer_aura');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88337, 'spell_helix_helix_ride'),
(88351, 'spell_helix_helix_ride_face_timer_aura');
