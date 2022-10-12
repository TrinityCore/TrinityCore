delete from creature where id = 40242;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(40242, 1, 616, 5016, 1, 1, 31379, 0, 5254.46, -1505.63, 1364.67, 2.68781, 300, 0, 0, 30951, 0, 0, 0, 0, 0, 0, 0);

update creature_template set ScriptName = 'npc_hyjal_soft_target', flags_extra = 130 where entry = 40242;

delete from spell_linked_spell where spell_trigger in (79040, 79044); 
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(79040, 95531, 0, 'Trampoline Bounce1 - Achiev Credit'),
(79044, 95531, 0, 'Trampoline Bounce2 - Achiev Credit');

delete from spell_script_names where spell_id = 95529;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(95529, 'spell_gen_bounce_achievement');
