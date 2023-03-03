delete from creature where id = 61399;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(61399, 994, 6182, 6472, 262, 1, 0, 0, -4267.71, -2519.43, -39.0845, 6.24468, 7200, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);

update creature_template set ScriptName = 'npc_glintrok_scout' where entry = 61399;

delete from creature_text where id = 61399;
iNSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(61399, 0, 0, 'Глинтрок-разведчик предупреждает об опасности!', 41, 0, 100, 0, 0, 0, 'Глинтрок-разведчик');