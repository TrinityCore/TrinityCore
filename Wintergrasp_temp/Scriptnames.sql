-- Wintergrasp queue template NPCs script
UPDATE `creature_template` SET `ScriptName`= 'npc_wg_queue' WHERE `entry` IN (32169,32170,35599,35596,35600,35601,35598,35603,35602,35597,35612,35611); -- <Wintergrasp Battle-Master>

-- Wintergrasp spirit guide NPCs script
UPDATE `creature_template` SET `ScriptName`= 'npc_wg_spirit_guide' WHERE `entry` IN (31841,31842); -- Taunka Spirit Guide, Dwarven Spirit Guide

-- Wintergrasp demolisher engineer NPCs script
UPDATE `creature_template` SET `ScriptName`= 'npc_wg_demolisher_engineer' WHERE `entry` IN (30400,30499); -- Goblin Mechanic, Gnomish Engineer

-- Wintergrasp Questgiver NPCs script
UPDATE `creature_template` SET `ScriptName`= 'npc_wg_quest_giver' WHERE `entry` IN (31054,31052,31091,31036,31101,31107,31053,31051,31153,31151,31102,31106);

-- Wintergrasp vehicle teleport GO script
UPDATE `gameobject_template` SET `ScriptName`= 'go_wg_vehicle_teleporter' WHERE `entry`=192951; -- Vehicle Teleporter

DELETE FROM `spell_script_names` WHERE `spell_id` IN (61409, 56662, 56664, 56659, 49899, 61178);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61409, 'spell_wintergrasp_force_building'),
(56659, 'spell_wintergrasp_force_building'),
(56662, 'spell_wintergrasp_force_building'),
(56664, 'spell_wintergrasp_force_building'),
(49899, 'spell_wintergrasp_force_building'),
(61178, 'spell_wintergrasp_grab_passenger');
