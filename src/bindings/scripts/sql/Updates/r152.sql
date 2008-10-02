UPDATE `creature_template` SET `ScriptName` = 'mob_syth_fire' WHERE `entry` = 19203;
UPDATE `creature_template` SET `ScriptName` = 'mob_syth_arcane' WHERE `entry` = 19205;
UPDATE `creature_template` SET `ScriptName` = 'mob_syth_frost' WHERE `entry` = 19204;
UPDATE `creature_template` SET `ScriptName` = 'mob_syth_shadow' WHERE `entry` = 19206;
 
UPDATE `creature_template` SET `ScriptName` = 'boss_tailonking_ikiss' WHERE `entry` = 18473;
UPDATE `creature_template` SET `ScriptName` = 'boss_darkweaver_syth' WHERE `entry` = 18472;

UPDATE creature_template SET ScriptName = 'npc_shattrathflaskvendors' WHERE entry = '23483';
UPDATE creature_template SET ScriptName = 'npc_shattrathflaskvendors' WHERE entry = '23484';

UPDATE `creature_template` SET ScriptName='innkeeper' WHERE `npcflag` & 128<>0;