UPDATE `creature_template` SET `ScriptName` = 'npc_lokhtos_darkbargainer' WHERE `entry` = 12944;

UPDATE creature_template SET ScriptName='npc_lady_jaina_proudmoore' WHERE entry=4968;

UPDATE `creature_template` SET `ScriptName` = 'mobs_spitelashes' WHERE entry IN (6190,6193,6194,6195,6196,7885,7886,12204,12205);

UPDATE creature_template SET npcflag=1, ScriptName='npc_beaten_corpse' WHERE entry=10668;
UPDATE quest_template  SET SpecialFlags=8, ReqCreatureOrGOId1=10668, ReqCreatureOrGOCount1=1  WHERE entry=4921;

UPDATE creature_template SET ScriptName='boss_rokmar_the_crackler' WHERE entry=17991;
UPDATE creature_template SET ScriptName='boss_warlord_kalithresh' WHERE entry=17798;

UPDATE `creature_template` SET `ScriptName` = 'boss_midnight' WHERE `entry` = 16151;
UPDATE `creature_template` SET `ScriptName` = 'boss_attumen' WHERE `entry` = 15550;
UPDATE `creature_template` SET `ScriptName` = 'boss_moroes' WHERE `entry` = 15687;
UPDATE `creature_template` SET `ScriptName` = 'boss_maiden_of_virtue' WHERE `entry` = 16457;
UPDATE `creature_template` SET `ScriptName` = 'boss_curator' WHERE `entry` = 15691;
UPDATE `creature_template` SET `ScriptName` = 'boss_big_bad_wolf' WHERE `entry` = 17521;
UPDATE `creature_template` SET `ScriptName` = 'boss_julianne' WHERE `entry` = 17534;
UPDATE `creature_template` SET `ScriptName` = 'boss_romulo' WHERE `entry` = 17533;
UPDATE `creature_template` SET `ScriptName` = 'boss_dorothee' WHERE `entry` = 17535;
UPDATE `creature_template` SET `ScriptName` = 'boss_strawman' WHERE `entry` = 17543;
UPDATE `creature_template` SET `ScriptName` = 'boss_tinhead' WHERE `entry` = 17547;
UPDATE `creature_template` SET `ScriptName` = 'boss_tito' WHERE `entry` = 17548;
UPDATE `creature_template` SET `ScriptName` = 'boss_roar' WHERE `entry` = 17546;
UPDATE `creature_template` SET `ScriptName` = 'boss_crone' WHERE `entry` = 18168;
UPDATE `creature_template` SET `ScriptName` = 'boss_terestian_illhoof' WHERE `entry` = 15688;
UPDATE `creature_template` SET `ScriptName` = 'boss_shade_of_aran' WHERE `entry` = 16524;
UPDATE `creature_template` SET `ScriptName` = 'boss_netherspite' WHERE `entry` = 15689;
UPDATE `creature_template` SET `ScriptName` = 'boss_malchezaar' WHERE `entry` = 15690;
UPDATE `creature_template` SET `ScriptName` = 'boss_nightbane' WHERE `entry` = 17225;

UPDATE `creature_template` SET `ScriptName` = 'mob_homunculus' WHERE `entry` = 16539;
UPDATE `creature_template` SET `ScriptName` = 'mob_kilrek' WHERE `entry` = 17229;
UPDATE `creature_template` SET `ScriptName` = 'netherspite_infernal' WHERE `entry` = 17646;