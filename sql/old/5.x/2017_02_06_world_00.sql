-- General Nazgrim Texts
DELETE FROM `creature_text` WHERE `entry` = 71515;
INSERT INTO `creature_text` VALUES
(71515, 0, 0, 'I am Nazgrim, fist of Warchief, and General of the Horde armies, if I must die today I will die with honor in battle. For the HORDE!', 14, 0, 0, 0, 100, 38191, 'GENERAL_NAZGRIM_ALLIANCE_AGGRO'),
(71515, 1, 0, 'It is and honor to finaly face you in combat. Lok\'tar Ogar, for honor, and for the Horde!', 14, 0, 0, 0, 100, 38192, 'GENERAL_NAZGRIM_HORDE_AGGRO'),
(71515, 2, 0, 'I die... With honor... Lok\'tar Ogar...', 14, 0, 0, 0, 100, 38193, 'GENERAL_NAZGRIM_DEATH_1'),
(71515, 2, 1, 'Gamon... You have finaly learned... I am proud... To have died... At your hands...', 14, 0, 0, 0, 100, 38194, 'GENERAL_NAZGRIM_DEATH_2'),
(71515, 2, 2, 'For the Horde...', 14, 0, 0, 0, 100, 38195, 'GENERAL_NAZGRIM_DEATH_3'),
(71515, 3, 0, 'You have learned much... And learned well... An honorable battle...', 14, 0, 0, 0, 100, 38196, 'GENERAL_NAZGRIM_DEATH_HORDE_1'),
(71515, 3, 1, 'In the end I stood by the Warchief because it was my duty, and I am glad that it was you who struck me down... strenght, lead the Horde into the new era... Of prosperity', 14, 0, 0, 0, 100, 38197, 'GENERAL_NAZGRIM_DEATH_HORDE_2'),
(71515, 4, 0, 'Kor\'kron, at my side!', 14, 0, 0, 0, 100, 38198, 'GENERAL_NAZGRIM_SUMMON_1'),
(71515, 4, 1, 'Warriors!', 14, 0, 0, 0, 100, 38199, 'GENERAL_NAZGRIM_SUMMON_2'),
(71515, 4, 2, 'Next squad, to the front!', 14, 0, 0, 0, 100, 38200, 'GENERAL_NAZGRIM_SUMMON_3'),
(71515, 4, 3, 'Defend the gate!', 14, 0, 0, 0, 100, 38201, 'GENERAL_NAZGRIM_SUMMON_4'),
(71515, 4, 4, 'Rally the forces!', 14, 0, 0, 0, 100, 38202, 'GENERAL_NAZGRIM_SUMMON_5'),
(71515, 4, 5, 'All Kor\'kron, under my command, kill them now!', 14, 0, 0, 0, 100, 38203, 'GENERAL_NAZGRIM_SUMMON_6'),
(71515, 5, 0, 'Hah, you should have trained harder!', 14, 0, 0, 0, 100, 38209, 'GENERAL_NAZGRIM_KILL');

-- General Nazgrim Script Names
UPDATE `creature_template` SET `ScriptName` = 'boss_general_nazgrim' WHERE `entry` = 71515;
UPDATE `creature_template` SET `ScriptName` = 'mob_orgrimmar_faithful' WHERE `entry` = 71715;
UPDATE `creature_template` SET `ScriptName` = 'mob_korkron_ironblade' WHERE `entry` = 71516;
UPDATE `creature_template` SET `ScriptName` = 'mob_korkron_arcweaver' WHERE `entry` = 71517;
UPDATE `creature_template` SET `ScriptName` = 'mob_korkron_warshaman' WHERE `entry` = 71519;
UPDATE `creature_template` SET `ScriptName` = 'mob_korkron_assassin' WHERE `entry` = 71518;
UPDATE `creature_template` SET `ScriptName` = 'mob_korkron_sniper' WHERE `entry` = 71656;
UPDATE `creature_template` SET `ScriptName` = 'mob_aftershock' WHERE `entry` = 71697;
UPDATE `creature_template` SET `ScriptName` = 'mob_korkron_banner' WHERE `entry` = 71626;
UPDATE `creature_template` SET `ScriptName` = 'mob_healing_tide_totem' WHERE `entry` = 71610;
UPDATE `creature_template` SET `ScriptName` = 'mob_ravager' WHERE `entry` = 71762;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_war_song';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sundering_blow';
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_korkron_banner_aura';

INSERT INTO `spell_script_names` VALUES (143503, 'spell_war_song');
INSERT INTO `spell_script_names` VALUES (143494, 'spell_sundering_blow');
INSERT INTO `spell_script_names` VALUES (143420, 'spell_korkron_banner_aura');
INSERT INTO `spell_script_names` VALUES (143432, 'spell_korkron_banner_aura');
INSERT INTO `spell_script_names` VALUES (143431, 'spell_korkron_banner_aura');
INSERT INTO `spell_script_names` VALUES (143481, 'spell_korkron_banner_aura');
INSERT INTO `spell_script_names` VALUES (143884, 'spell_korkron_banner_aura');
INSERT INTO `spell_script_names` VALUES (143887, 'spell_korkron_banner_aura');
