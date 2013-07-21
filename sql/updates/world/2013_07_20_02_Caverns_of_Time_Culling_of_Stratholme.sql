update `creature_template` set ScriptName = 'npc_cos_zombie' where entry = 27737;
update `creature_template` set ScriptName = 'npc_chromie' where entry = 26527;
DELETE FROM `disables` WHERE  `sourceType`=2 AND `entry`=595;