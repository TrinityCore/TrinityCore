UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName` IN
('npc_dream_fog',
'npc_spirit_shade',
'boss_ysondre',
'boss_taerar',
'boss_emeriss',
'boss_lethon');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dream_fog_sleep',
'spell_mark_of_nature');
