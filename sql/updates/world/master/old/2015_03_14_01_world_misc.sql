delete from spell_script_names where spell_id = 114357;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(114357, 'spell_hopling_summoner');

update creature_template set ScriptName = 'npc_hopling' where entry = 59459;

update creature_template set AIName = 'SmartAI' where entry = 59426;
delete from smart_scripts where entryorguid = 59426;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(59426, 0, 0, 1, 6, 0, 100, 0, 0, 0, 0, 0, 11, 114531, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Death - Cast Drop Hammer Cosmetic'),
(59426, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link Death - Remove Aura'),
(59426, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 53, 0, 59426, 0, 0, 1000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'JustSummon - Wp Start');

delete from waypoints where entry = 59426;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(59426, 1, -706.347, 1298.22, 162.677, NULL),
(59426, 2, -724.658, 1307.84, 162.622, NULL),
(59426, 3, -746.791, 1313.01, 162.632, NULL),
(59426, 4, -758.212, 1303.01, 162.636, NULL),
(59426, 5, -768.76, 1280.64, 162.677, NULL),
(59426, 6, -766.922, 1267.53, 163.239, NULL),
(59426, 7, -761.961, 1251.22, 162.756, NULL);

delete from creature where id = 55091 and map = 961;
INSERT INTO `creature` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `isActive`) VALUES 
(55091, 961, 5963, 5963, 262, 1, 0, 0, -703.585, 1288.21, 164.239, 1.84489, 300, 0, 0, 84, 1000, 0, 0, 0, 0, 0, 0);