
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (123707, 'eye_of_the_empress');
UPDATE `gameobject_template` SET `ScriptName` = 'Sikthik_cage' WHERE `entry` = 214734;
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (123032, 'spell_carrying_caustic_tar');
UPDATE `creature_template` SET `ScriptName` = 'npc_puddle_summon_x' WHERE `entry` = 61579;
UPDATE `creature_template` SET `ScriptName` = 'npc_sap_puddle' WHERE `entry` IN (61613);
UPDATE `creature_template` SET `ScriptName` = 'Yang_Ironclaw_ending' WHERE `entry` = 61620;
UPDATE `creature_template` SET `ScriptName` = 'sticky_resin_trigger' WHERE `entry` = 63730;
UPDATE creature_template set ScriptName = 'boss_garalon' where entry = 62164;

UPDATE `creature_template` SET `ScriptName` = 'npc_sap_puddle_x' WHERE `entry` = 61965;
UPDATE `creature_template` SET `ScriptName` = 'npc_sap_puddle_x' WHERE `entry` = 61613;
UPDATE `creature_template` SET `ScriptName` = 'mob_millhouse_manastorm' WHERE `entry` = 43391;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (98451,98450);
INSERT INTO `spell_script_names` VALUES
(98451, 'spell_staghelm_burning_orbs'),
(98450, 'spell_staghelm_searing_seeds_aura');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(66118, 'spell_gen_leeching_swarm'),
(67630, 'spell_gen_leeching_swarm'),
(68646, 'spell_gen_leeching_swarm'),
(68647, 'spell_gen_leeching_swarm'),
(24750, 'spell_gen_trick'),
(24751, 'spell_gen_trick_or_treat'),
(82636, 'spell_ignis_rising_flames');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (98451,98450);
INSERT INTO `spell_script_names` VALUES
(98451, 'spell_staghelm_burning_orbs'),
(98450, 'spell_staghelm_searing_seeds_aura');
UPDATE  `creature_template` SET  `ScriptName` =  'npc_queen_azshara_hammer_of_divinity' WHERE `entry` = 54864;
UPDATE `creature_template` SET `ScriptName`='npc_feludius_water_bomb' WHERE `entry`=41264;
UPDATE `creature_template` SET `flags_extra`=128, `ScriptName`='npc_feludius_water_bomb ' WHERE `entry`=44201;
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (51505, 'spell_sha_lava_burst');
UPDATE `creature_template` SET `ScriptName` = 'boss_pyroguard_emberseer' WHERE `entry` = 9816;
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (79340, 'spell_high_priestess_azil_gravity_well_script');
UPDATE `creature_template` SET `ScriptName`='npc_silverlaine_worgen' WHERE `entry`=50834 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`='npc_silverlaine_worgen' WHERE `entry`=50851 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`='npc_silverlaine_worgen' WHERE `entry`=50857 LIMIT 1;

UPDATE `creature_template` SET `ScriptName` = 'npc_gilneas_city_guard_phase1' WHERE `creature_template`.`entry` =34864;
UPDATE creature_template SET ScriptName='npc_prince_liam_greymane_phase1' WHERE entry='34850';
UPDATE `creature_template` SET `ScriptName`='npc_gwen_armstead_p2' WHERE `entry`='35840';
UPDATE creature_template SET ScriptName = 'npc_westfall_stew' WHERE entry = 42617;
UPDATE creature_template SET unit_flags = 4 WHERE entry = 42617;
UPDATE `creature_template` SET `ScriptName` = 'mob_shield_orb',`minlevel` = 70, `maxlevel` = 70, `faction_A`=14, `faction_H`=14 WHERE entry =25502;
UPDATE `creature_template` SET `ScriptName` = 'mob_impp' WHERE `entry` = 43014;
UPDATE `creature_template` SET `ScriptName`='npc_springvale_tormented_officer' WHERE `entry`=50615 LIMIT 1;
UPDATE `creature_template` SET `ScriptName`='npc_springvale_wailing_guardsman' WHERE `entry`=50613 LIMIT 1;
UPDATE `creature_template` SET ScriptName='npc_doom_guard_warlock' WHERE entry=11859;

UPDATE `creature_template` SET ScriptName='spell_q24747_custom_kill_credit' WHERE entry=38250;
UPDATE creature_template SET AIName = "", scriptname = "npc_sean_dempsey" WHERE ENTRY = 35081;
UPDATE creature_template SET ScriptName = 'npc_bloodfang_worgen' WHERE entry = 35118;
UPDATE `creature_template` SET `ScriptName` = 'npc_josiah_avery_p2' WHERE `entry` IN (35369);
UPDATE `creature_template` SET `ScriptName` = 'npc_worgen_alpha_c2' WHERE `entry` IN (35167);
UPDATE `creature_template` SET `ScriptName` = 'npc_king_genn_greymane_p4' WHERE `entry` IN (35550);
UPDATE `creature_template` SET `ScriptName` = 'npc_gilneas_city_guard_p8' WHERE `entry` IN (50474);
UPDATE `creature_template` SET `ScriptName` = 'npc_afflicted_gilnean_p8' WHERE `entry` IN (50471);
DELETE FROM `spell_script_names` WHERE `spell_id` = '68555';
INSERT `spell_script_names` (`spell_id`,`ScriptName`) VALUES ('68555', 'spell_keg_placed');
UPDATE `creature_template` SET `speed_run`=1.28571426868439, `npcflag`=0, `VehicleId`=494, `minlevel`=4, `maxlevel`=4, `Faction_A`=2203, `Faction_H`=2203,`Unit_Flags`=8, `Modelid1`=236, `Resistance2`=90, `Resistance4`=1, `unit_class`=2, `scriptname`='npc_greymane_horse', `mechanic_immune_mask`=2147483647 WHERE `entry`=35905;
UPDATE creature_template SET ScriptName='npc_prospector_remtravel' WHERE entry=2917;
UPDATE creature_template SET ScriptName='npc_dalinda_malem' WHERE entry=5644;
UPDATE `creature_template` SET `ScriptName`='npc_kaya_flathoof' WHERE `entry`=11856;

UPDATE `creature_template` SET `ScriptName`='mob_sabersnout' WHERE `entry`=37513;
UPDATE `creature_template` SET `ScriptName`='npc_homing_robot_oox_22_fe' WHERE `entry`=7807;
UPDATE `gameobject_template` SET `ScriptName`='go_blackhoof_cage' WHERE `entry`='186287';
UPDATE `creature_template` SET `ScriptName`='npc_subjugator_devo' WHERE `entry`=42023;
UPDATE creature_template SET ScriptName='npc_lakota_windsong' WHERE entry=10646;
UPDATE `creature_template` SET `ScriptName`='npc_kanati_greycloud' WHERE `entry`=39895;
UPDATE `creature_template` SET `ScriptName`='npc_pao_ka_swiftmountain' WHERE `entry`=47471;
UPDATE `creature_template` SET `ScriptName`='npc_a_me_01' WHERE `entry`=9623;
REPLACE INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (6341, 'at_bt_entrance');
UPDATE `creature_template` SET `ScriptName`='npc_warlord_zonozz_tentacle' WHERE `entry` IN (55418, 55416, 55417);

UPDATE `creature_template` SET `ScriptName`='npc_madness_of_deathwing_mutated_corruption' WHERE `entry`=56471;
UPDATE `creature_template` SET `ScriptName`='npc_madness_of_deathwing_crush_target' WHERE `entry`=56581;
UPDATE `creature_template` SET `ScriptName`='npc_madness_of_deathwing_congealing_blood' WHERE `entry`=57798;
UPDATE `creature_template` SET `ScriptName`='npc_dragon_soul_alexstrasza_dragon' WHERE `entry`=58207;
UPDATE creature_template SET ScriptName = 'boss_thaddius' WHERE entry = 15928;
UPDATE creature_template SET ScriptName = 'mob_feugen' WHERE entry = 15930;
UPDATE `creature_template` SET `Scriptname`='mob_ymirjar_flamebearer' WHERE `entry`=36893;
UPDATE `creature_template` SET `Scriptname`='mob_ymirjar_deathbringer' WHERE `entry`=36892;
UPDATE `creature_template` SET `Scriptname`='mob_iceborn_protodrake' WHERE `entry`=36891;
UPDATE `creature_template` SET `Scriptname`='mob_geist_ambusher' WHERE `entry`=36886;
UPDATE `creature_template` SET `InhabitType`=4,`flags_extra`=128,`unit_flags`=0x2000000,`ScriptName`='npc_arthas_teleport_visual' WHERE `entry`=30298; 
UPDATE `creature_template` SET `ScriptName` = 'mob_ethereal_beacon' WHERE `entry` = 18431;
UPDATE `creature_template` SET `ScriptName` = 'immersus_creature_sha_pool_heroic' WHERE `entry` = 47705;
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(47731, 'spell_nexus_critter_targeting');
UPDATE creature_template SET ScriptName='mob_chaotic_rift' WHERE entry=26918;
UPDATE `creature_template` SET `ScriptName` = 'mob_crystal_spike' WHERE `entry` = '27099';
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(50341, 'spell_oculus_touch_the_nightmare'),
(50344, 'spell_oculus_dream_funnel');
UPDATE `creature_template` SET `ScriptName`='npc_spectator' WHERE `entry`=26667;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_scourge_hulk' WHERE `entry`=26555;
UPDATE `creature_template` SET `ScriptName`='npc_drakkari_gutripper' WHERE `entry`=26641;
UPDATE `creature_template` SET `ScriptName`='npc_drakkari_scytheclaw' WHERE `entry`=26628;
UPDATE `creature_template` SET `ScriptName`='npc_hira_snowdawn' WHERE `entry`=31238;

UPDATE `creature_template` SET `ScriptName`='npc_hakmund_of_argus' WHERE `entry`=32638;
UPDATE `creature_template` SET `ScriptName`='npc_thorim' WHERE `entry`=29445;
UPDATE `creature_template` SET `ScriptName`='npc_victorious_challenger' WHERE `entry`=30012;
UPDATE `creature_template` SET `ScriptName`='npc_loklira_crone' WHERE `entry`=29975;
UPDATE `creature_template` SET `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0, `ScriptName`='npc_storm_cloud' WHERE `entry`=29939;
UPDATE `instance_template` SET `script`='instance_temple_of_jade_serpent' WHERE (`map`='960');

REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (106851, 'spell_yan_zhu_blackout_brew');
UPDATE `creature_template` SET `ScriptName`='npc_yeasty_brew_alemental' WHERE `entry`=59494;
REPLACE INTO `instance_template` VALUES (994, 870, 'instance_mogu_shan_palace', 0);
UPDATE `creature_template` SET `ScriptName`='npc_globue' WHERE `entry`=55863;
update creature_template set ScriptName = 'mob_whirling_dervish' where entry = 61626;
REPLACE INTO spell_script_names VALUES (121114, 'spell_resin_weaving');
DELETE FROM `instance_template` WHERE `map`=962;
INSERT INTO `instance_template` VALUES (962, 870, 'instance_gate_setting_sun', 0);
REPLACE INTO `instance_template` VALUES (959, 870, 'instance_shadopan_monastery', 0);
REPLACE INTO `instance_template` VALUES (1008, 870, 'instance_mogu_shan_vault', 0); 

UPDATE `creature_template` SET `ScriptName`='mob_stone_quilen' WHERE `entry`=60576;
UPDATE `creature_template` SET `ScriptName`='mob_zandalari_skullcharger' WHERE `entry`=60375;
UPDATE `creature_template` SET `ScriptName`='npc_madness_of_deathwing_blistering_tentacle' WHERE `entry`=56188;
















