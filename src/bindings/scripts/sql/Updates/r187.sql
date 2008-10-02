-- test of lore quest npcs
UPDATE `creature_template` SET `ScriptName` = 'npc_parqual_fintallas' WHERE `entry` = 4488;
UPDATE `creature_template` SET `ScriptName` = 'npc_braug_dimspirit' WHERE `entry` = 4489;
-- quest Scratches
UPDATE `creature_template` SET `ScriptName` = 'npc_daranelle' WHERE `entry` = 21469;

-- no comments of malfuntion, implementing mount vendors script
UPDATE `creature_template` SET `ScriptName` = 'npc_mount_vendor' WHERE `entry` IN (384, 1261, 1460, 2357, 3362, 3685, 4730, 4731, 4885, 7952, 7955, 16264, 17584);

-- one time update, this is database related sql and should be included in any database
UPDATE `creature_template` SET `npcflag` = `npcflag`|1 WHERE `entry` IN (4488, 4489, 21469);
INSERT IGNORE `spell_teleport` VALUES (6766, 1,-2354.03,-1902.07,95.78,4.6);
