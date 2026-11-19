-- [NPC][WotlK] Frostborn Scout and Frostfeather Witch/Frostfeather Screecher
DELETE FROM `creature` WHERE `guid` IN (73947,74030,74031,74032);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(73947, 29811, 571, 0, 0, '0', 0, 0, 0, 6726.224, -879.4117, 699.3712, 4.118977, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Frostborn Scout (Area: Sifreldar Village) (Auras: 51329 - Feign Death)
(74030, 29793, 571, 0, 0, '0', 0, 0, 0, 6727.663, -873.1896, 699.3716, 4.39823, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Frostfeather Witch (Area: Sifreldar Village)
(74031, 29811, 571, 0, 0, '0', 0, 0, 0, 6925.177, -887.6844, 919.1036, 2.86234, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360), -- Frostborn Scout (Area: Bor's Breath) (Auras: 51329 - Feign Death)
(74032, 29792, 571, 0, 0, '0', 0, 0, 0, 6926.426, -884.468, 919.2955, 4.537856, 300, 0, 0, 0, 0, 0, 0, 0, 0, 23360); -- Frostfeather Screecher (Area: Bor's Breath)

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (104625, 104510, 104634, 104506, 104627);
