-- gilneas npc scripts

UPDATE `creature_template` SET `ScriptName` = 'npc_frightened_citizen' WHERE `entry` IN (34981, 35836);
UPDATE `creature_template` SET `ScriptName` = 'npc_worgen_runt' WHERE `entry` IN (35188, 35456);
UPDATE `creature_template` SET `ScriptName` = 'npc_josiah_avery' WHERE `entry` = 35370;
UPDATE `creature_template` SET `ScriptName` = 'npc_greymanes_horse' WHERE `entry` = 35905;
UPDATE `creature_template` SET `ScriptName` = 'npc_crowleys_horse' WHERE `entry` IN (35231, 44428);

UPDATE `creature_queststarter` SET `id` = 34850 WHERE `quest` = 14091;

