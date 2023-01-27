DELETE FROM `spell_script_names` WHERE `spell_id` =57099;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(57099,'spell_gen_landmine_knockback_achievement_aura');
REPLACE INTO spell_script_names VALUE (871, 'spell_warr_shield_wall');
REPLACE INTO spell_script_names VALUE (91023, 'spell_rog_find_weakness'); 
REPLACE INTO spell_script_names VALUE (114175, 'spell_warl_demonic_slash');  
REPLACE INTO spell_script_names VALUE (119839, 'spell_warl_fury_ward'); 
REPLACE INTO spell_script_names VALUE (114168, 'spell_warl_dark_apotheosis');  
REPLACE INTO spell_script_names VALUE (111570, 'spell_lillian_grip');
REPLACE INTO spell_script_names VALUE (144689, 'spell_ordos_burning_soul_aura');






REPLACE INTO `instance_template` VALUES (959, 870, 'instance_shadopan_monastery', 0);
UPDATE creature_template set ScriptName = 'boss_wing_leader_neronok' where entry = 62205;
REPLACE INTO spell_script_names VALUES (106548, 'spell_madness_of_deathwing_agonizing_pain');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (97158, 97152, 97597);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(97158, 'spell_jindo_shadow_spike_target'),
(97152, 'spell_jindo_summon_spirit_target'),
(97597, 'spell_jindo_spirit_warrior_gaze_target');
REPLACE INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(16081, 11, 0, 0, 'achievement_pardon_denied');
update creature_template set ScriptName = 'boss_ming_the_cunning' where entry = 61444;
update creature_template set ScriptName = 'mob_adepts' where entry = 61447;
update creature_template set ScriptName = 'mob_adepts' where entry = 61449;
UPDATE `creature_template` SET `ScriptName`='npc_yeasty_brew_alemental' WHERE `entry`=59494;
REPLACE INTO `instance_template` VALUES (994, 870, 'instance_mogu_shan_palace', 0);
UPDATE `creature_template` SET `ScriptName`='npc_ook_barrel' WHERE `entry`=56682;
UPDATE `instance_template` SET `script`='instance_temple_of_jade_serpent' WHERE (`map`='960');
DELETE FROM `spell_script_names` WHERE `spell_id` IN 
(99052, 98934, 100648, 100834, 100835,
98471, 100826, 100827, 100828);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(99052, 'spell_bethtilac_smoldering_devastation'),
(98934, 'spell_bethtilac_ember_flare'),
(100648, 'spell_bethtilac_ember_flare'),
(100834, 'spell_bethtilac_ember_flare'),
(100835, 'spell_bethtilac_ember_flare'),
(98471, 'spell_bethtilac_burning_acid'),
(100826, 'spell_bethtilac_burning_acid'),
(100827, 'spell_bethtilac_burning_acid'),
(100828, 'spell_bethtilac_burning_acid');
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (17542, 18096);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(17542, 11, 0, 0, 'achievement_death_from_above');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(101223, 'spell_alysrazor_fieroblast'),
(101294, 'spell_alysrazor_fieroblast'),
(101295, 'spell_alysrazor_fieroblast'),
(101296, 'spell_alysrazor_fieroblast'),
(100640, 'spell_alysrazor_harsh_winds'),
(97128, 'spell_alysrazor_molten_feather'),
(97734, 'spell_alysrazor_molten_feather_script'),
(102111, 'spell_alysrazor_cataclysm');
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (17538, 17536, 17535, 17533, 17448, 17449, 18098);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(17538, 11, 0, 0, 'achievement_do_a_barrel_roll'),
(17536, 11, 0, 0, 'achievement_do_a_barrel_roll'),
(17535, 11, 0, 0, 'achievement_do_a_barrel_roll'),
(17533, 11, 0, 0, 'achievement_do_a_barrel_roll');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (101111, 99837, 99838, 101208, 101209, 101210);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(101111, 'spell_shannox_riplimb_dogged_determination'),
(99837, 'spell_shannox_crystal_prison_trap'),
(99838, 'spell_shannox_immolation_trap'),
(101208, 'spell_shannox_immolation_trap'),
(101209, 'spell_shannox_immolation_trap'),
(101210, 'spell_shannox_immolation_trap');
UPDATE `creature_template` SET `ScriptName`= "mob_fl_teleport" WHERE `entry` =111222;
UPDATE `creature_template` SET `type_flags`=`type_flags`|4 WHERE `entry` IN (52409, 53797, 53798, 53799);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (17576, 17775, 17776, 17777, 17778, 17779);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(17576, 11, 0, 0, 'achievement_bucket_list'),
(17775, 11, 0, 0, 'achievement_bucket_list'),
(17776, 11, 0, 0, 'achievement_bucket_list'),
(17777, 11, 0, 0, 'achievement_bucket_list'),
(17778, 11, 0, 0, 'achievement_bucket_list'),
(17779, 11, 0, 0, 'achievement_bucket_list');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(101384, 'spell_firelands_siphon_essence');
update creature_template set ScriptName = 'mob_xian_the_weaponmaster_trigger' where entry = 61884;
UPDATE `creature_template` SET `ScriptName`='npc_ignacious_flame_strike' WHERE `entry`=41264;
DELETE FROM `conditions` WHERE `SourceEntry`=86840;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
('13', '1', '86840', '31', '3', '48798', 'Valiona - Devouring flames');
DELETE FROM `spell_script_names` WHERE `spell_id` IN
(86788, 92876, 92877, 92878, 86408, 88518, 86199, 92868, 92869, 92870, 86228,
92867, 86406, 92926, 92927, 92928, 93055, 93051, 86844, 92872, 92873, 92874);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(86788, 'spell_valiona_blackout'),
(92876, 'spell_valiona_blackout'),
(92877, 'spell_valiona_blackout'),
(92878, 'spell_valiona_blackout'),
(88518, 'spell_valiona_twilight_meteorite'),
(86408, 'spell_theralion_dazzling_destruction'),
(86199, 'spell_valiona_twilight_flame_dmg_1'),
(92868, 'spell_valiona_twilight_flame_dmg_1'),
(92869, 'spell_valiona_twilight_flame_dmg_1'),
(92870, 'spell_valiona_twilight_flame_dmg_1'),
(86228, 'spell_valiona_twilight_flame_dmg_2'),
(92867, 'spell_valiona_twilight_flame_dmg_2'),
(86406, 'spell_theralion_dazzling_destruction_dmg'),
(92926, 'spell_theralion_dazzling_destruction_dmg'),
(92927, 'spell_theralion_dazzling_destruction_dmg'),
(92928, 'spell_theralion_dazzling_destruction_dmg'),
(93055, 'spell_shifting_reality'),
(93051, 'spell_twilight_shift_stack'),
(86844, 'spell_valiona_devouring_flames_dmg'),
(92872, 'spell_valiona_devouring_flames_dmg'),
(92873, 'spell_valiona_devouring_flames_dmg'),
(92874, 'spell_valiona_devouring_flames_dmg');
UPDATE `creature_template` SET `ScriptName`='npc_collapsing_twilight_portal' WHERE `entry`=46301;
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
UPDATE `creature_template` SET `ScriptName`='npc_valiona_twilight_flames' WHERE `entry`=40718;
UPDATE `creature_template` SET `ScriptName`='boss_valiona' WHERE `entry`=45992;
UPDATE `creature_template` SET `ScriptName`='boss_theralion' WHERE `entry`=45993;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (83719, 83603);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(83603, 'spell_halfus_stone_grip'),
(83719, 'spell_halfus_fireball_barrage');
UPDATE `creature_template` SET `ScriptName`='npc_proto_behemoth' WHERE `entry`=44687;
UPDATE `gameobject_template` SET `ScriptName`='go_whelp_cage' WHERE `entry`=205087;
UPDATE `creature_template` SET `AIName` = '', `ScriptName`='boss_halfus_wyrmbreaker' WHERE `entry`=44600;
UPDATE creature_template set ScriptName = 'mob_bone_pile' where entry = 59304;
UPDATE creature_template set ScriptName = 'boss_rattlegore' where entry = 59153;
UPDATE `creature_template` SET `ScriptName` = 'boss_pyroguard_emberseer' WHERE `entry` = 9816;  
UPDATE creature_template set ScriptName = 'boss_lilian_voss' where entry = 58722;
UPDATE `creature_template` SET `ScriptName` = 'boss_lillian_voss_soul' WHERE `entry` = 58791;
DELETE FROM `spell_script_names` WHERE `spell_id` =120032;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(120032,'spell_gen_dancing_steel');
REPLACE INTO spell_script_names VALUE (85804, 'spell_pal_selfless_healer_spell');
REPLACE INTO spell_script_names VALUE (108853, 'spell_mage_inferno_blast');
REPLACE INTO spell_script_names VALUE (35395, 'spell_pal_crusader_strike');
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (-47540,'spell_pri_penance');
UPDATE `creature_template` SET `ScriptName`='npc_enslaved_rock_elemental' WHERE `entry`=39900;
UPDATE `creature_template` SET `ScriptName`='npc_ascended_flameseeker' WHERE `entry`=39415;
UPDATE `creature_template` SET `ScriptName`='npc_ascended_rockbreaker' WHERE `entry`=40272;
UPDATE `creature_template` SET `ScriptName`='npc_ascended_waterlasher' WHERE `entry`=40273;
UPDATE `creature_template` SET `ScriptName`='npc_ascended_windwalker' WHERE `entry`=39414;
UPDATE `creature_template` SET `ScriptName`='npc_azureborne_guardian' WHERE `entry`=39854;
UPDATE `creature_template` SET `ScriptName`='npc_azureborne_seer' WHERE `entry`=39855;
UPDATE `creature_template` SET `ScriptName`='npc_azureborne_seer' WHERE `entry`=40291;
UPDATE `creature_template` SET `ScriptName`='npc_azureborne_warlord' WHERE `entry`=39909;
UPDATE `creature_template` SET `ScriptName`='npc_crimsonborne_guardian' WHERE `entry`=39381;
UPDATE `creature_template` SET `ScriptName`='npc_crimsonborne_seer' WHERE `entry`=40290;
UPDATE `creature_template` SET `ScriptName`='npc_crimsonborne_seer' WHERE `entry`=39405;
UPDATE `creature_template` SET `ScriptName`='npc_crimsonborne_warlord' WHERE `entry`=39626;
UPDATE `creature_template` SET `ScriptName`='npc_enslaved_burning_ember' WHERE `entry`=39892;
UPDATE `creature_template` SET `ScriptName`='npc_enslaved_rock_elemental' WHERE `entry`=39900;
UPDATE `creature_template` SET `ScriptName`='npc_enslaved_gronn_brute' WHERE `entry`=40166;
UPDATE `creature_template` SET `ScriptName`='npc_faceless_corruptor' WHERE `entry`=39392;
UPDATE `creature_template` SET `ScriptName`='npc_trogg_dweller' WHERE `entry`=39450;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_armsmaster' WHERE `entry`=40306;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_armsmaster' WHERE `entry`=41073;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_beguiler' WHERE `entry`=40167;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_drake' WHERE `entry`=41095;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_earthshaper' WHERE `entry`=39890;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_enforcer' WHERE `entry`=40448;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_enforcer' WHERE `entry`=39956;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_firecatcher' WHERE `entry`=39870;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_shadow_weaver' WHERE `entry`=39954;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_stormbreaker' WHERE `entry`=39962;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_thundercaller' WHERE `entry`=40270;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_war_mage' WHERE `entry`=40268;
UPDATE `creature_template` SET `ScriptName`='npc_twilight_wyrmcaller' WHERE `entry`=39873;
UPDATE `creature_template` SET `ScriptName`='npc_ascended_rockbreaker_fissure' WHERE `entry`=41091;
UPDATE `creature_template` SET `ScriptName`='npc_crimsonborne_warlord_empowering_flames' WHERE `entry`=41045;
DELETE FROM `spell_script_names` WHERE `spell_id`=92712;
INSERT INTO `spell_script_names` VALUES (92712, 'spell_item_big_cauldron_of_battle');
REPLACE INTO `spell_script_names` VALUES (92649, 'spell_item_cauldron_of_battle');

REPLACE INTO spell_script_names VALUE (20711, 'spell_pri_spirit_of_redemption');
REPLACE INTO spell_script_names VALUES (585, 'spell_pri_train_of_thought'), (2060, 'spell_pri_train_of_thought');
REPLACE INTO spell_script_names VALUE (527, 'spell_pri_purify');
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (-32379,'spell_pri_shadow_word_death');
REPLACE INTO spell_script_names VALUE (104232, 'spell_warl_rain_of_fire');
REPLACE INTO spell_script_names VALUE (108501, 'spell_warl_grimoire_of_service');
REPLACE INTO spell_script_names VALUES (78, 'spell_warr_taste_for_blood_aura'), (845, 'spell_warr_taste_for_blood_aura');
REPLACE INTO spell_script_names (spell_id, ScriptName) VALUES (6552, 'spell_warr_glyph_of_gag_order'), (114028, 'spell_warr_glyph_of_gag_order');
REPLACE INTO spell_script_names VALUES (133, 'spell_mastery_ignite'), (2948, 'spell_mastery_ignite'), (11366, 'spell_mastery_ignite'), (44614,'spell_mastery_ignite'), (108853, 'spell_mastery_ignite');
REPLACE INTO spell_script_names VALUE (50662, 'spell_q12512_resuscitate');
REPLACE INTO spell_script_names VALUE (122816, 'spell_q31112_ping_bunny');
REPLACE INTO spell_script_names VALUE (69453, 'spell_q14491_soothe_earth_spirit');
REPLACE INTO spell_script_names VALUE (71898, 'spell_q24861_funeral_offering');
REPLACE INTO spell_script_names VALUE (62506, 'spell_q13595_bottle_of_wildfire');

REPLACE INTO spell_script_names VALUE (62517, 'spell_q13523_elune_s_presence_dummy');
REPLACE INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES (55516, 'spell_q12919_gymers_grab'),(55421, 'spell_q12919_gymers_throw');
REPLACE INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (78838,'spell_item_enohar_explosive_arrows');
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (44436, 'spell_tricky_treat');
UPDATE creature_template SET ScriptName = "npc_gilthares_firebough" WHERE entry = 3465;
UPDATE gameobject_template SET ScriptName='go_tele_to_violet_stand' WHERE entry=191229;
UPDATE gameobject_template SET ScriptName='npc_doom_guard_warlock' WHERE entry=11859;
UPDATE creature_template SET ScriptName='npc_air_force_bots' WHERE entry IN (2614, 2615, 21974, 21993, 21996, 21997, 21999, 22001, 22002, 22003, 22063, 22065, 22066, 22068, 22069, 22070, 22071, 22078, 22079, 22080, 22086, 22087, 22088, 22090, 22124, 22125, 22126);
UPDATE `creature_template` SET `unit_flags` = 0x4|0x40000, ScriptName = 'npc_fungal_growth' WHERE `entry` = 43484;
UPDATE `creature_template` SET `ScriptName` = 'npc_mini_tyrael' WHERE `entry` = 29089;
UPDATE `creature_template` SET `ScriptName` = 'npc_pengu' WHERE `entry` = 32595;
UPDATE `creature_template` SET `ScriptName`='npc_puzzle_box_of_yogg_saron' WHERE `entry`=49634;
UPDATE `creature_template` SET `ScriptName` = 'mob_fel_crystal' WHERE `entry` = 24722;
UPDATE creature_template SET ScriptName='npc_koltira_deathweaver' WHERE entry=28912;
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (114460, 'spell_scorched_earth');
UPDATE `creature_template` SET `ScriptName` = 'mob_book_case' WHERE `entry` = 59155;
UPDATE `creature_template` SET `ScriptName` = 'mob_obedient_hound' WHERE `entry` = 59309;

-- instance
REPLACE INTO `instance_template` VALUES (959, 0, 'instance_shadopan', 0);
REPLACE INTO `instance_template` VALUES (960, 0, 'instance_temple_of_jade', 0);
REPLACE INTO `instance_template` VALUES (961, 0, 'instance_stormstout_brewery', 0);
REPLACE INTO `instance_template` VALUES (962, 0, 'instance_gate_of_setting_sun', 0);
REPLACE INTO `instance_template` VALUES (994, 0, 'instance_mogushan_palace', 0);
REPLACE INTO `instance_template` VALUES (995, 0, 'instance_the_depths', 0);
REPLACE INTO `instance_template` VALUES (996, 0, 'instance_terrace_of_endless_spring', 0);
REPLACE INTO `instance_template` VALUES (999, 0, 'instance_battle_for_theramore_a', 0);
REPLACE INTO `instance_template` VALUES (1000, 0, 'instance_battle_for_theramore_h', 0);
REPLACE INTO `instance_template` VALUES (1001, 0, 'instance_scarlet_halls', 0);
REPLACE INTO `instance_template` VALUES (1004, 0, 'instance_scarlet_monastery', 0);
REPLACE INTO `instance_template` VALUES (1007, 0, 'instance_scholomance', 0);
REPLACE INTO `instance_template` VALUES (1008, 0, 'instance_mogushan_vaults', 0);
REPLACE INTO `instance_template` VALUES (1009, 0, 'instance_heart_of_fear', 0);
REPLACE INTO `instance_template` VALUES (1011, 0, 'instance_siege_of_niuzao_temple', 0);

UPDATE `creature_template` SET `ScriptName` = 'mob_chia_hui_autumnleaf' WHERE `entry` = 60248;
UPDATE `creature_template` SET `ScriptName` = 'mob_aspiring_trainee' WHERE `entry` = 53565;
UPDATE `creature_template` SET `ScriptName` = 'mob_ji_firepaw' WHERE `entry` = 56418;
UPDATE `creature_template` SET `ScriptName` = 'npc_merchant_lorvo' WHERE `entry` = 54943;
UPDATE `creature_template` SET `ScriptName` = 'mob_huojin_monk' WHERE `entry` = 60176;
UPDATE `creature_template` SET `ScriptName` = 'mob_brewer_lin' WHERE `entry` = 60253;
UPDATE `creature_template` SET `ScriptName` = 'mob_delivery_cart_tender' WHERE `entry` = 57712;
UPDATE `creature_template` SET `ScriptName` = 'mob_master_shang_xi_temple' WHERE `entry` = 54786;
UPDATE `creature_template` SET `ScriptName` = 'mob_instructors' WHERE `entry` = 65469;
UPDATE `creature_template` SET `ScriptName` = 'mob_jaomin_ro' WHERE `entry` = 54611;

UPDATE `creature_template` SET `ScriptName` = 'mob_huojin_trainee' WHERE `entry` = 54586;
UPDATE `creature_template` SET `ScriptName` = 'mob_huojin_trainee' WHERE `entry` = 65470;
UPDATE `creature_template` SET `ScriptName` = 'mob_master_shang_xi' WHERE `entry` = 53566;
UPDATE `creature_template` SET `ScriptName` = 'mob_big_bao' WHERE `entry` = 58508;
UPDATE `creature_template` SET `ScriptName` = 'mob_pandriarch_goldendraft' WHERE `entry` = 56210;
UPDATE `creature_template` SET `ScriptName` = 'mob_pandriarch_bramblestaff' WHERE `entry` = 56209;
UPDATE `creature_template` SET `ScriptName` = 'mob_pandriarch_windfur' WHERE `entry` = 56206;
UPDATE `creature_template` SET `ScriptName` = 'mob_go_kan' WHERE `entry` = 50331;
UPDATE `creature_template` SET `ScriptName` = 'mob_ik_thik_warrior' WHERE `entry` = 56722;
UPDATE `creature_template` SET `ScriptName`='mob_hisek_the_swarmkeeper' WHERE `entry`=71153;
UPDATE `creature_template` SET `ScriptName`='mob_restless_leng' WHERE `entry`=65698;
UPDATE `creature_template` SET `ScriptName` = 'npc_sikthik_soldier' WHERE `entry` = 62348;
UPDATE `creature_template` SET `ScriptName` = 'npc_siege_explosive' WHERE `entry` = 61452;
UPDATE `creature_template` SET `ScriptName`='mob_jiang_xiang' WHERE (`entry`='65317');
UPDATE `creature_template` SET `ScriptName`='mob_songbird_queen' WHERE (`entry`='59553');

UPDATE `creature_template` SET `ScriptName`='mob_peril' WHERE (`entry`='59726');
UPDATE `creature_template` SET `ScriptName`='mob_strife' WHERE (`entry`='59051');
UPDATE `creature_template` SET `ScriptName`='mob_nodding_tiger' WHERE (`entry`='59544');
UPDATE `creature_template` SET `ScriptName`='mob_golden_beetle' WHERE (`entry`='59545');
UPDATE `creature_template` SET `ScriptName`='mob_talking_fish' WHERE (`entry`='59546');
UPDATE `creature_template` SET `ScriptName` = 'mob_yeast_brew_elemental' WHERE `entry` = 59494;





