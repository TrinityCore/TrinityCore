-- Better handled in Eredar Twins Script (with Dark Flame)DELETE FROM spell_linked_spell where spell_effect in (45347,45348,-45348,-45347);

-- Felmyst spawn

DELETE FROM `creature` WHERE `id`=25038;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) 
values('25038','580','1','1','0','0','1463.83','611.512','51.57','1.62316','604800','0','0','1000000','0','0');
