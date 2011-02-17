UPDATE `creature_template` SET `ScriptName`='npc_captured_rageclaw' WHERE (`entry`='29686');
UPDATE `creature_template` SET `ScriptName`='npc_drakuru_shackles' WHERE (`entry`='29700');

DELETE FROM `spell_script_target` WHERE `entry` IN (55083,55223,59951,59952);
INSERT INTO `spell_script_target` VALUES (55083, 1, 29700),(55223, 1, 29686),(59951, 1, 29686),(59952, 1, 29686);
