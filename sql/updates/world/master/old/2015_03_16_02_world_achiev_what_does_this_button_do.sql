delete from creature where id = 59481 and map = 994;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(59481, 994, 6182, 6474, 262, 1, 0, 0, -4653.8, -2572.87, 27.10, 1.48115, 300, 0, 0, 1422711, 62356, 0, 0, 0, 0, 0, 0),
(59481, 994, 6182, 6474, 262, 1, 0, 0, -4652.74, -2573.03, 27.10, 1.489, 300, 0, 0, 1422711, 62356, 0, 0, 0, 0, 0, 0),
(59481, 994, 6182, 6474, 262, 1, 0, 0, -4613.57, -2654.51, 27.10, 1.53612, 300, 0, 0, 1422711, 62356, 0, 0, 0, 0, 0, 0),
(59481, 994, 6182, 6474, 262, 1, 0, 0, -4611.7, -2654.54, 27.10, 4.65415, 300, 0, 0, 1422711, 62356, 0, 0, 0, 0, 0, 0);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry = 124531;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 124531, 0, 0, 31, 0, 3, 59481, 0, 0, 0, '', NULL);

update creature_template set unit_flags = 768, ScriptName = 'npc_faintly_glowing_gem' where entry = 63808;