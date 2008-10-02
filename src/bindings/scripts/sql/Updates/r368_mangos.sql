UPDATE `instance_template` SET `script` = 'instance_shadowfang_keep' WHERE `map` = 33;
UPDATE `creature_template` SET `ScriptName` = 'boss_fenrus' WHERE `entry` = 4274;
UPDATE `creature_template` SET `ScriptName` = 'boss_nandos' WHERE `entry` = 3927;
UPDATE `creature_template` SET `ScriptName` = 'boss_rethilgore' WHERE `entry` = 3914;
UPDATE `creature_template` SET `ScriptName` = 'npc_shadowfang_prisoner' WHERE `entry` IN (3849, 3850);
