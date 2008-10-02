UPDATE `creature_template` SET `ScriptName` = 'mob_infested_root_walker' WHERE `entry` = 22095;
UPDATE `creature_template` SET `ScriptName` = 'mob_rotting_forest_rager' WHERE `entry` = 22307;
UPDATE `creature_template` SET `ScriptName` = 'mob_netherweb_victim' WHERE `entry` = 22355;

UPDATE `creature_template` SET `ScriptName` = 'mobs_shadow_council_covert' WHERE `entry` IN (18716, 18717, 18719);
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` IN (18716, 18717, 18719);

UPDATE `creature_template` SET `ScriptName` = 'mob_gurok_the_usurper' WHERE `entry` = 18182;
UPDATE `creature_template` SET `ScriptName` = 'mob_shattered_rumbler' WHERE `entry` = '17157';
UPDATE `creature_template` SET `ScriptName` = 'mobs_kilsorrow_agent' WHERE `entry` IN (17146, 17147, 17148, 18397, 18658);
UPDATE `creature_template` SET `ScriptName` = 'npc_altruis_the_sufferer' WHERE `entry` = 18417;

UPDATE `creature_template` SET `ScriptName` = 'npcs_ashyen_and_keleth' WHERE `entry` IN (17900, 17901);
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` IN (17900,17901);
UPDATE `creature_template` SET `ScriptName` = 'npc_elder_kuruti' WHERE `entry` = 18197;
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` = 18197;

UPDATE `creature_template` SET `ScriptName` = 'mob_lunaclaw' WHERE `entry` = 12138;

UPDATE `creature_template` SET `ScriptName` = 'npc_steward_of_time' WHERE `entry` = 20142;

UPDATE `creature_template` SET `ScriptName` = 'boss_death_knight_darkreaver' WHERE `entry` = 14516;

UPDATE `creature_template` SET `ScriptName` = 'mob_yenniku' WHERE `entry` = 2530;
