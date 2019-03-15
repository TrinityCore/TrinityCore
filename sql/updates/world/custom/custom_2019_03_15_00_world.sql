UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName` IN 
('boss_alyson_antille',
'boss_gazakroth',
'boss_darkheart',
'boss_slither',
'npc_halazzi_lynx',
'npc_akilzon_eagle',
'npc_janalai_firebomb',
'npc_janalai_hatcher',
'npc_janalai_hatchling',
'npc_janalai_egg');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_hexlord_unstable_affliction');

UPDATE `creature_template` SET `ScriptName` = 'npc_zulaman_voljin' WHERE `entry`= 52924;
