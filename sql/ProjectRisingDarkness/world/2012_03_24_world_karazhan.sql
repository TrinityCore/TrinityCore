UPDATE `gameobject_template` SET `flags`= 16 WHERE `entry` IN (183932, 184278, 184279);
UPDATE `creature_template` SET `ScriptName`= 'npc_hastings',`flags_extra` = 1  WHERE `entry` = 16169;
UPDATE `creature_template` SET `ScriptName`= 'npc_rokad_the_ravager',`flags_extra` = 1  WHERE `entry` = 16181;
UPDATE `creature_template` SET `ScriptName`= 'npc_shadikith_the_glider',`flags_extra` = 1  WHERE `entry` = 16180;
UPDATE `creature_template` SET `ScriptName`= 'npc_hyakiss_the_lurker',`flags_extra` = 1  WHERE `entry` = 16179;
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1880000 AND -1880002;
INSERT INTO `script_texts` (entry, content_default) VALUES
(-1880000, 'Rokad the Ravager howls through the halls...!'),
(-1880001, 'Hyakiss the Lurker skitters out from the shadows...!'),
(-1880002, 'Shadikith the Glider flaps down from the ceiling...!');