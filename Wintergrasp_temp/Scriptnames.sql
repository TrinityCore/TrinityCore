-- Wintergrasp queue template NPCs
UPDATE `creature_template` SET `ScriptName`= 'npc_wg_dalaran_queue' WHERE `entry` IN (32169,32170,35599,35596,35600,35601,35598,35603,35602,35597,35612,35611);

-- Wintergrasp spiritguide NPC script
UPDATE `creature_template` SET `ScriptName`= 'npc_wg_spiritguide' WHERE `entry` IN (31841,31842);

-- Wintergrasp demolisher engineer NPC script
UPDATE `creature_template` SET `ScriptName`= 'npc_demolisher_engineerer' WHERE `entry` IN (30400,30499);

-- Wintergrasp vehicle teleport
UPDATE `gameobject_template` SET `ScriptName`= 'go_wintergrasp_teleporter' WHERE `entry`=192951;

-- Wintergrasp Questgiver NPCs - requires binding to Wintergrasp questgiver script
UPDATE `creature_template` SET `ScriptName`= 'npc_wintergrasp_quest_giver' WHERE `entry` IN (31054, 31052, 31091, 31036, 31101, 31107, 31053, 31051, 31153, 31151, 31102, 31106);
