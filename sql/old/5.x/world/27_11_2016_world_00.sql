REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(110744, 'spell_priest_divine_star'),
(110745, 'spell_priest_divine_star_aoe'),
(122121, 'spell_priest_divine_star'),
(122128, 'spell_priest_divine_star_aoe');
UPDATE creature_template set ScriptName = 'boss_brother_korloff' where entry = 59223;
REPLACE INTO `spell_script_names` VALUES (2060, 'spell_pri_holy_spark');
REPLACE INTO `spell_script_names` VALUES (55453, 'spell_sha_glyph_of_telluric_currents');
REPLACE INTO `spell_script_names` VALUES (58070, 'spell_warl_glyph_of_soul_consumption');
REPLACE INTO `spell_script_names` VALUES (29722, 'spell_warl_incinerate');
REPLACE INTO spell_script_names VALUE (3411, 'spell_warr_intervene');
REPLACE INTO `spell_script_names` VALUES (100, 'spell_warr_checkway');
REPLACE INTO `spell_script_names` VALUES (3411, 'spell_warr_checkway');
REPLACE INTO `spell_script_names` VALUES (114029, 'spell_warr_checkway');
UPDATE creature_template set ScriptName = 'boss_commander_durand' where entry = 60040;
REPLACE INTO `spell_script_names` SET `spell_id`='119996',`ScriptName`='spell_monk_transcendence_transfer';
UPDATE creature_template set ScriptName = 'boss_inquisitor_whitemane' where entry = 3977; 
REPLACE INTO spell_script_names VALUE (77485, 'spell_mastery_echo_of_light');
UPDATE `creature_template` SET `ScriptName` = 'boss_thalnos_the_soulrender' WHERE `entry` = 59789;
UPDATE creature_template set ScriptName = 'boss_armsmaster_harlan' where entry = 58632;
UPDATE creature_template set ScriptName = 'boss_flameweaver_koegler' where entry = 59150;
UPDATE creature_template set ScriptName = 'boss_houndmaster_braun' where entry = 59303;
UPDATE creature_template set ScriptName = 'boss_lillian_voss' where entry = 67274;
REPLACE INTO `spell_script_names` VALUES (119980, 'spell_dk_conversion_heal_aura');
REPLACE INTO `spell_script_names` VALUES (112833, 'spell_pri_spectral_guise');
REPLACE INTO `spell_script_names` VALUES (58640, 'spell_dk_glyph_of_the_geist');
REPLACE INTO `spell_script_names` VALUES (48263, 'spell_dk_presences');
REPLACE INTO `spell_script_names` VALUES (48266, 'spell_dk_presences');
REPLACE INTO `spell_script_names` VALUES (48265, 'spell_dk_presences');
REPLACE INTO spell_script_names VALUE (114154, 'spell_pal_unbreakable_spirit');
REPLACE INTO spell_script_names VALUE (20167, 'spell_pal_seal_of_insight');
REPLACE INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(56374,'spell_mage_glyph_of_icy_veins');
UPDATE `creature_template` SET `ScriptName`= "mob_fl_teleport" WHERE `entry` =111222;
UPDATE creature_template SET ScriptName = 'boss_vordraka' WHERE entry = 56009;
REPLACE INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES 
(17450, 11, 0, 0, 'achievement_not_an_ambi_turner');
UPDATE `creature_template` SET `AIName`="", `scriptname`="boss_garrosh_hellscream" WHERE `entry`=39605;
UPDATE `creature_template` SET `ScriptName` = 'mob_jaomin_ro' WHERE `entry` = 54611;
REPLACE INTO `instance_template` (`map`, `parent`, `script`, `allowMount`) VALUES
(1136, 0, 'instance_siege_of_orgrimmar', 0);
UPDATE `creature_template` SET `ScriptName` = 'boss_horridon' WHERE `entry` = 68476;
UPDATE creature_template set ScriptName = 'boss_sha_of_fear' where entry = 60999;
UPDATE `creature_template` SET `ScriptName` = 'boss_tortos' WHERE `entry` = 67977;
UPDATE `creature_template` SET `scriptname`='npc_throneofthunder_teleporter' WHERE `entry`=74000;
UPDATE `creature_template` SET `scriptname`='mob_pure_light_terrace' WHERE `entry`=60788;
UPDATE creature_template set ScriptName = 'boss_yan_zhu' where entry = 59479;
UPDATE creature_template set ScriptName = 'boss_lei_shi' where entry = 62983;
UPDATE `creature_template` SET `ScriptName` = 'boss_exarch_maladaar' WHERE `entry` = 18373;
UPDATE `creature_template` SET `ScriptName`='boss_shirrak_the_dead_watcher' WHERE `entry`=18371;
UPDATE `creature_template` SET `ScriptName` = 'boss_nexusprince_shaffar' WHERE `entry` = 18344;
UPDATE `creature_template` SET `ScriptName` = 'boss_pandemonius' WHERE `entry` = 18341;
UPDATE `creature_template` SET `ScriptName` = 'boss_darkweaver_syth' WHERE `entry` = 18472;
UPDATE `creature_template` SET `ScriptName`='boss_talon_king_ikiss' WHERE `entry`=18473;
UPDATE creature_template SET ScriptName='boss_steelbreaker' WHERE entry=32867;
UPDATE `creature_template` SET `ScriptName` = 'boss_runemaster_molgeim' WHERE `entry` = '32927';
UPDATE creature_template SET AIName = '', ScriptName = 'boss_magus_telestra_arcane' WHERE entry = 26929;
UPDATE `creature_template` SET `ScriptName` = 'gatewatcher_gyro_kill' WHERE `entry` = 19218;
UPDATE `creature_template` SET `ScriptName` = 'boss_nethermancer_sepethrea' WHERE `entry` = 19221;
UPDATE `creature_template` SET `ScriptName`='boss_laj' WHERE `entry`=17980;
update `creature_template` set `scriptname` = 'boss_warchief_kargath_bladefist' where `entry` = '16808';
update `creature_template` set `scriptname` = 'boss_warchief_kargath_bladefist' where `entry` = '20597';
UPDATE `creature_template` SET `ScriptName` = 'boss_gatewatcher_iron_hand' WHERE `entry` = 19710;
UPDATE `creature_template` SET `ScriptName`='boss_warbringer_omrogg' WHERE `entry`=16809;
UPDATE `creature_template` SET `ScriptName` = 'boss_grand_warlock_nethekurse' WHERE `entry` = 16807;
UPDATE `creature_template`  SET `ScriptName` = 'boss_niuzao'  WHERE `entry` = 71954 ;
UPDATE `creature_template`  SET `ScriptName` = 'boss_xuen'  WHERE `entry` = 71953 ;
REPLACE INTO `spell_script_names` VALUES (111666, 'spell_hoptallus_hammer_smash');
REPLACE INTO `spell_script_names` VALUES (106784, 'spell_brew_explosion');
