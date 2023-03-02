update creature_template set IconName = 'LootAll', InhabitType = 7, ScriptName = 'npc_jade_quilen' where entry = 63091;

delete from npc_spellclick_spells where npc_entry = 63091;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(63091, 123206, 1, 0);

delete from creature where id = 63091;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(63091, 994, 6182, 6470, 260, 1, 0, 0, -3961.66, -2702.2, 26.7736, 3.202, 28800, 0, 0, 204, 1000, 0, 0, 0, 0, 0, 0),
(63091, 994, 6182, 6476, 260, 1, 0, 0, -4509.78, -2741.01, 45.2347, 1.57, 28800, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
(63091, 994, 6182, 6473, 260, 1, 0, 0, -4456.88, -2609.6, -26.1988, 0.69, 28800, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
(63091, 994, 6182, 6476, 260, 1, 0, 0, -4235.28, -2506.21, -21.06, 4.85, 28800, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
