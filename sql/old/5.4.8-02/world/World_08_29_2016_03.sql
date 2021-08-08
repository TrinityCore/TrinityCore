UPDATE `creature_template` SET `ScriptName`="npc_train_wrecker" WHERE `entry`=33404;
UPDATE `creature_template` SET `ScriptName`="npc_transcendence_spirit" WHERE `entry`=54569;
UPDATE `creature_template` SET `ScriptName` = 'boss_pyroguard_emberseer' WHERE `entry` = 9816;
UPDATE creature_template set ScriptName = 'boss_brother_korloff' where entry = 59223; 
UPDATE creature_template set ScriptName = 'boss_commander_durand' where entry = 60040;
UPDATE creature_template set ScriptName = 'boss_inquisitor_whitemane' where entry = 3977;  
UPDATE creature_template set ScriptName = 'boss_flameweaver_koegler' where entry = 59150;
UPDATE creature_template set ScriptName = 'boss_houndmaster_braun' where entry = 59303;
UPDATE creature_template set ScriptName = 'boss_armsmaster_harlan' where entry = 58632;
UPDATE creature_template set ScriptName = 'boss_thalnos_the_soulrender' where entry = 59789;  
UPDATE creature_template SET ScriptName= 'boss_netherspite' WHERE entry=15689;
UPDATE creature_template set ScriptName = 'boss_madness_of_deathwing' where entry = 56173; 
UPDATE `creature_template` SET `ScriptName` = 'boss_exarch_maladaar' WHERE `entry` = 18373;
UPDATE `creature_template` SET `ScriptName`='boss_shirrak_the_dead_watcher' WHERE `entry`=18371;
UPDATE `creature_template` SET `ScriptName` = 'boss_nexusprince_shaffar' WHERE `entry` = 18344;
UPDATE `creature_template` SET `ScriptName` = 'boss_pandemonius' WHERE `entry` = 18341;
UPDATE `creature_template` SET `ScriptName` = 'boss_darkweaver_syth' WHERE `entry` = 18472;
UPDATE `creature_template` SET `ScriptName`='boss_talon_king_ikiss' WHERE `entry`=18473;
UPDATE `creature_template` SET `ScriptName`='boss_ambassador_hellmaw' WHERE `entry`=18731;
UPDATE `creature_template` SET `ScriptName` = 'boss_blackheart_the_inciter' WHERE `entry` = 18667;
UPDATE `creature_template` SET `ScriptName`='boss_mekgineer_steamrigger' WHERE `entry`=17796;
UPDATE `creature_template` SET `ScriptName` = 'boss_murmur' WHERE `entry` = 18708;
UPDATE `creature_template` SET `ScriptName` = 'boss_hydromancer_thespia' WHERE `entry` = 17797;
UPDATE `creature_template` SET `ScriptName` = 'mob_coilfang_waterelemental' WHERE `entry` = 17917;
UPDATE `creature_template` SET `ScriptName`='mob_naga_distiller' WHERE `entry`=17954;
UPDATE creature_template SET ScriptName='boss_warlord_kalithresh' WHERE entry=17798;
UPDATE `creature_template` SET `ScriptName` = 'boss_hungarfen' WHERE `entry` = 17770;
UPDATE `creature_template` SET `ScriptName`='boss_warbringer_omrogg' WHERE `entry`=16809;
UPDATE `creature_template` SET `ScriptName`='mob_omrogg_heads' WHERE `entry` IN (19523,19524);
UPDATE `creature_template` SET `ScriptName`='boss_warchief_kargath_bladefist' WHERE `entry`=16808;
UPDATE `creature_template` SET `ScriptName` = 'boss_gatewatcher_iron_hand' WHERE `entry` = 19710;
UPDATE `creature_template` SET `ScriptName` = 'boss_gatewatcher_iron_hand' WHERE `entry` = 19710;
UPDATE `creature_template` SET `ScriptName` = 'boss_nethermancer_sepethrea' WHERE `entry` = 19221;  
UPDATE `creature_template` SET `ScriptName` = 'gatewatcher_gyro_kill' WHERE `entry` = 19218; 
UPDATE `creature_template` SET `ScriptName`='mob_fel_orc_convert' WHERE `entry`=17083;
UPDATE `creature_template` SET `ScriptName`='boss_laj' WHERE `entry`=17980;
UPDATE `creature_template` SET `ScriptName` = 'boss_grand_warlock_nethekurse' WHERE `entry` = 16807;
UPDATE `creature_template` SET `ScriptName`='boss_the_black_stalker' WHERE `entry`='17882';
UPDATE `creature_template` SET `ScriptName`='mob_steamrigger_mechanic' WHERE `entry`=17951;
UPDATE `creature_template` SET `ScriptName` = 'boss_grandmaster_vorpil' WHERE `entry` = 18732; 
UPDATE `creature_template` SET `ScriptName` = 'boss_farseer_vicious_war_wolf' WHERE `entry` = 71994;
UPDATE creature_template SET ScriptName = 'boss_thaddius' WHERE entry = 15928;
UPDATE creature_template SET ScriptName = 'mob_feugen' WHERE entry = 15930;
UPDATE creature_template SET ScriptName = 'boss_magus_telestra_arcane' WHERE entry = 26929;
UPDATE `creature_template` SET `ScriptName`='boss_novos' WHERE `entry`=26631;
UPDATE `creature_template` SET `ScriptName`='boss_dred' WHERE `entry`=27483;
UPDATE `creature_template` SET `ScriptName`='boss_tharon_ja' WHERE `entry`=26632;   
UPDATE `creature_template` SET `ScriptName`='boss_yulon' WHERE `entry`=71955; 
UPDATE creature_template set ScriptName = 'boss_garalon' where entry = 62164;
UPDATE creature_template SET ScriptName = 'boss_vordraka' WHERE entry = 56009;
UPDATE `creature_template` SET `ScriptName`='npc_shang_xi_choose_faction' WHERE (`entry`='60566');
UPDATE `creature_template` SET `ScriptName`='npc_shang_xi_choose_faction' WHERE (`entry`='56013');   
UPDATE creature_template SET ScriptName = 'npc_ji_firepaw' WHERE entry = 60741;
UPDATE creature_template SET ScriptName = 'boss_vojak' WHERE entry = 61634;
UPDATE `creature_template` SET `ScriptName`='boss_trollgore' WHERE `entry`=26630;
UPDATE `creature_template` SET `ScriptName` = 'boss_runemaster_molgeim' WHERE `entry` = 32927;
UPDATE creature_template SET ScriptName='boss_steelbreaker' WHERE entry=32867;    
UPDATE creature_template SET ScriptName='Reisin_Boss_Traps' WHERE entry=67046; 
UPDATE `creature_template` SET `ScriptName` = 'windblade' WHERE `entry` = 8479;
 
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('123106', 'pheremone_trail');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('93812', 'spell_calamity');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143434', 'spell_shadow_word_bane');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('143879', 'spell_shadow_word_bane');
  
UPDATE `creature_template` SET `ScriptName` = 'immersus_trigger_sha_swirl_circular' WHERE `entry` = 254235;

REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('144745', 'spell_desecrate_dummy');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('144843', 'spell_overcome ');

UPDATE `creature_template` SET `ScriptName`='mob_frost_sphere' WHERE `entry`='34606';
UPDATE creature_template SET ScriptName = 'npc_anub_ar_skirmisher' WHERE entry = 28734;
UPDATE creature_template SET ScriptName = 'npc_anub_ar_shadowcaster' WHERE entry = 28733;
update creature_template set scriptName = 'npc_watcher_gashra' where entry = 28730;
update creature_template set scriptName = 'npc_watcher_silthik' where entry = 28731;
UPDATE creature_template SET ScriptName = 'npc_anub_ar_warrior' WHERE entry = 28732;
update creature_template set scriptName = 'npc_watcher_narjil' where entry = 28729;
UPDATE `creature_template` SET `ScriptName`='npc_anubar_crusher' WHERE `entry`=28922;

REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('82327', 'spell_pal_hit_holy_radiance');
REPLACE INTO spell_script_names VALUE (114154, 'spell_pal_unbreakable_spirit');
REPLACE INTO spell_script_names VALUE (29166, 'spell_dru_innervate');
REPLACE INTO spell_script_names VALUE (20167, 'spell_pal_seal_of_insight');
REPLACE INTO spell_script_names VALUE (87426, 'spell_pri_shadowy_apparition');

REPLACE INTO spell_script_names VALUE (54785, 'spell_warl_demonic_leap_jump');

REPLACE INTO spell_script_names VALUE (51505, 'sha_lava_burst');


