-- Gate of the Setting Sun -- falta npc vicuous fluid
UPDATE instance_template SET script='instance_gate_setting_sun' WHERE map=962;
-- Rimok
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_commander_rimok' WHERE entry=56636;
UPDATE creature_template SET minlevel=89, maxlevel=90, faction=1791, ScriptName='npc_krikthik_swarmer' WHERE entry=59835;
UPDATE creature_template SET minlevel=89, maxlevel=90, faction=1791, ScriptName='npc_krikthik_saboteur' WHERE entry=60447;
UPDATE creature_template SET minlevel=89, maxlevel=90, faction=1791, ScriptName='npc_add_generator' WHERE entry=59834;
INSERT INTO spell_script_names (spell_id,ScriptName) values (120559,'spell_rimok_saboteur_bombard');
-- Raigonn
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_raigonn' WHERE entry=56877;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_raigonn_weak_spot' WHERE entry=56895;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_protectorat' WHERE entry=56929;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_engulfer' WHERE entry=56912;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_swarm_bringer' WHERE entry=56930;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='vehicle_artillery' WHERE entry=59819;
-- Kiptilak
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_saboteur_kiptilak' WHERE entry=56906;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_instable_munition' WHERE entry=56917;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=56911;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=56918;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=56919;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=56920;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=59205;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=59206;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=59207;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_munition_explosion_bunny' WHERE entry=59208;
INSERT INTO spell_script_names (spell_id,ScriptName) values (107268,'spell_kiptilak_sabotage');
-- Gadok
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_striker_gadok' WHERE entry=56589;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_striker' WHERE entry=59778;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_krikthik_disruptor' WHERE entry=59794;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='npc_flak_cannon' WHERE entry=60421;
INSERT INTO spell_script_names (spell_id,ScriptName) values (116298,'spell_gadok_strafing');
INSERT INTO spell_script_names (spell_id,ScriptName) values (106933,'spell_prey_time');

-- Heart of Fear
UPDATE instance_template SET script='instance_heart_of_fear' WHERE map=1009;
INSERT INTO instance_template (map,script) values (1009,'instance_heart_of_fear');
-- Blade Lord Tayak
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_blade_lord_tayak' WHERE entry=62543;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='mob_tempest_slash' WHERE entry=62908;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='mob_tayak_tornado_all' WHERE entry=63567;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='mob_tayak_tornado' WHERE entry=63299;
INSERT INTO spell_script_names (spell_id,ScriptName) values (122994,'spell_invisible_strike');
-- Garalon
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_garalon' WHERE entry=62164;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_garalon' WHERE entry=63053;
INSERT INTO spell_script_names (spell_id,ScriptName) values (122754,'spell_garalon_furious_swipe');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122774,'spell_garalon_crush_searcher');
INSERT INTO spell_script_names (spell_id,ScriptName) values (129815,'spell_garalon_pheromones_first_target_selector');
-- Vizier Zorlock
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='boss_vizier_zorlock' WHERE entry=62980;
UPDATE creature_template SET minlevel=91, maxlevel=92, faction=1791, ScriptName='mob_sonic_ring' WHERE entry=62727;
INSERT INTO spell_script_names (spell_id,ScriptName) values (122718,'spell_force_and_verve_damage');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122336,'spell_zorlock_sonic_ring');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122740,'spell_zorlock_convert');

-- MoguShan Palace
UPDATE instance_template SET script='instance_mogu_shan_palace' WHERE map=994;
INSERT INTO instance_template (map,script) values (994,'instance_mogu_shan_palace');
--UPDATE gameobject_template SET ScriptName='go_mogushan_palace_temp_portal' WHERE entry=;
-- Gekkan
UPDATE creature_template SET ScriptName='boss_gekkan' WHERE entry=61243;
UPDATE creature_template SET ScriptName='mob_glintrok_skulker' WHERE entry=61338;
UPDATE creature_template SET ScriptName='mob_glintrok_ironhide' WHERE entry=61337;
UPDATE creature_template SET ScriptName='mob_glintrok_oracle' WHERE entry=61339;
UPDATE creature_template SET ScriptName='mob_glintrok_hexxer' WHERE entry=61340;
-- Trial of the King
UPDATE creature_template SET ScriptName='mob_xian_the_weaponmaster_trigger' WHERE entry=61884;
UPDATE creature_template SET ScriptName='boss_ming_the_cunning' WHERE entry=61444;
UPDATE creature_template SET ScriptName='mob_whirling_dervish' WHERE entry=61626;
UPDATE creature_template SET ScriptName='mob_adepts' WHERE entry=61449;
UPDATE creature_template SET ScriptName='boss_kuai_the_brute' WHERE entry=61442;
UPDATE creature_template SET ScriptName='mob_mu_shiba' WHERE entry=61453;
UPDATE creature_template SET ScriptName='boss_haiyan_the_unstoppable' WHERE entry=61445;
-- Xin the Weaponmaster
UPDATE creature_template SET ScriptName='boss_xin_the_weaponmaster' WHERE entry=61398;
UPDATE creature_template SET ScriptName='mob_animated_staff' WHERE entry=61433;
INSERT INTO spell_script_names (spell_id,ScriptName) values (119311,'spell_dart');

-- MoguShan Vaults
UPDATE instance_template SET script='instance_mogu_shan_vault' WHERE map=1008;
INSERT INTO instance_template (map,script) values (1008,'instance_mogu_shan_vault');
-- Elegon
UPDATE creature_template SET ScriptName='boss_elegon' WHERE entry=60410;
UPDATE creature_template SET ScriptName='mob_empyreal_focus' WHERE entry=60776;
UPDATE creature_template SET ScriptName='mob_celestial_protector' WHERE entry=60793;
UPDATE creature_template SET ScriptName='mob_cosmic_spark' WHERE entry=62618;
UPDATE creature_template SET ScriptName='mob_energy_charge' WHERE entry=60913;
UPDATE creature_template SET ScriptName='mob_infinite_energy' WHERE entry=65293;
UPDATE gameobject_template SET ScriptName='go_celestial_control_console' WHERE entry=211650;
INSERT INTO spell_script_names (spell_id,ScriptName) values (127785,'spell_spawn_flash_1_periodic');
INSERT INTO spell_script_names (spell_id,ScriptName) values (127783,'spell_spawn_flash_2_periodic');
INSERT INTO spell_script_names (spell_id,ScriptName) values (127781,'spell_spawn_flash_3_periodic');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117874,'spell_touch_of_titans');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118313,'spell_radiating_energies');
INSERT INTO spell_script_names (spell_id,ScriptName) values (119360,'spell_draw_power');
INSERT INTO spell_script_names (spell_id,ScriptName) values (124967,'spell_draw_power');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118024,'spell_core_checker');
INSERT INTO spell_script_names (spell_id,ScriptName) values (127362,'spell_grasping_energy_tendrils');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116994,'spell_unstable_energy');
INSERT INTO spell_script_names (spell_id,ScriptName) values (129711,'spell_total_annihilation');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132222,'spell_destabilizing_energies');
-- Feng
UPDATE creature_template SET ScriptName='boss_feng' WHERE entry=60009;
--UPDATE creature_template SET ScriptName='mob_lightning_fist' WHERE entry=;
UPDATE creature_template SET ScriptName='mob_wild_spark' WHERE entry=60438;
UPDATE creature_template SET ScriptName='mob_feng_shield' WHERE entry=60627;
UPDATE creature_template SET ScriptName='mob_soul_fragment' WHERE entry=60781;
INSERT INTO spell_script_names (spell_id,ScriptName) values (116040,'spell_mogu_epicenter');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116583,'spell_mogu_wildfire_spark');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116821,'spell_wildfire_infusion_stacks');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116816,'spell_mogu_wildfire_infusion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116711,'spell_draw_flame');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116365,'spell_mogu_arcane_velocity');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116434,'spell_mogu_arcane_resonance');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118300,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118302,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118304,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118305,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118307,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118308,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132296,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132297,'spell_mogu_inversion');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132298,'spell_mogu_inversion');
UPDATE gameobject_template SET ScriptName='go_inversion' WHERE entry=211628;
UPDATE gameobject_template SET ScriptName='go_cancel' WHERE entry=211626;
-- Garajal
UPDATE creature_template SET ScriptName='boss_garajal' WHERE entry=60143;
UPDATE creature_template SET ScriptName='mob_garajal_ghost' WHERE entry=61172;
UPDATE creature_template SET ScriptName='mob_spirit_totem' WHERE entry=60240;
UPDATE creature_template SET ScriptName='mob_shadowy_minion' WHERE entry=60940;
UPDATE creature_template SET ScriptName='mob_soul_cutter' WHERE entry=62003;
UPDATE creature_template SET ScriptName='mob_spirit_totem_intro' WHERE entry=60512;
INSERT INTO spell_script_names (spell_id,ScriptName) values (120715,'spell_soul_back');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118469,'spell_final_destination');
-- Spirit Kings
UPDATE creature_template SET ScriptName='boss_spirit_kings_controler' WHERE entry=60984;
UPDATE creature_template SET ScriptName='boss_spirit_kings' WHERE entry=60701;
UPDATE creature_template SET ScriptName='boss_spirit_kings' WHERE entry=60708;
UPDATE creature_template SET ScriptName='boss_spirit_kings' WHERE entry=60709;
UPDATE creature_template SET ScriptName='boss_spirit_kings' WHERE entry=60710;
UPDATE creature_template SET ScriptName='mob_pinning_arrow' WHERE entry=60958;
UPDATE creature_template SET ScriptName='mob_undying_shadow' WHERE entry=60731;
INSERT INTO spell_script_names (spell_id,ScriptName) values (117921,'spell_massive_attacks');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118094,'spell_volley');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118105,'spell_volley');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118106,'spell_volley');
INSERT INTO spell_script_names (spell_id,ScriptName) values (118145,'spell_pinned_down');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117708,'spell_maddening_shout');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117756,'spell_crazed_cowardice');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117737,'spell_crazed_cowardice');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117833,'spell_crazy_thought');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117558,'spell_coalescing_shadow');
-- Stone Guard
UPDATE creature_template SET ScriptName='boss_stone_guard_controler' WHERE entry=60089;
UPDATE creature_template SET ScriptName='boss_generic_guardian' WHERE entry=59915;
UPDATE creature_template SET ScriptName='boss_generic_guardian' WHERE entry=60043;
UPDATE creature_template SET ScriptName='boss_generic_guardian' WHERE entry=60047;
UPDATE creature_template SET ScriptName='boss_generic_guardian' WHERE entry=60051;
UPDATE creature_template SET ScriptName='npc_stone_guard_crystal' WHERE entry=60304;
UPDATE creature_template SET ScriptName='npc_stone_guard_crystal' WHERE entry=60306;
UPDATE creature_template SET ScriptName='npc_stone_guard_crystal' WHERE entry=60307;
UPDATE creature_template SET ScriptName='npc_stone_guard_crystal' WHERE entry=60308;
UPDATE creature_template SET ScriptName='mob_cobalt_mine' WHERE entry=65803;
UPDATE creature_template SET ScriptName='mob_tile' WHERE entry=300000;
INSERT INTO spell_script_names (spell_id,ScriptName) values (115852,'spell_petrification');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116006,'spell_petrification');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116036,'spell_petrification');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116057,'spell_petrification');
INSERT INTO spell_script_names (spell_id,ScriptName) values (130404,'spell_jasper_chains_damage');
-- Will of Emperor
UPDATE creature_template SET ScriptName='boss_jin_qin_xi' WHERE entry=60399;
UPDATE creature_template SET ScriptName='mob_woe_add_generic' WHERE entry=60396;
UPDATE creature_template SET ScriptName='mob_woe_add_generic' WHERE entry=60397;
UPDATE creature_template SET ScriptName='mob_woe_add_generic' WHERE entry=60398;
UPDATE creature_template SET ScriptName='mob_woe_titan_spark' WHERE entry=60480;
UPDATE gameobject_template SET ScriptName='go_ancient_control_console' WHERE entry=211584;
INSERT INTO spell_script_names (spell_id,ScriptName) values (116818,'spell_will_of_emperor_magnetic_armor');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117195,'spell_will_of_emperor_magnetic_armor');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116815,'spell_will_of_emperor_magnetic_armor_grip');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117193,'spell_will_of_emperor_magnetic_armor_grip');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116550,'spell_energizing_smash');

-- Scarlet Halls
UPDATE creature_template SET ScriptName='boss_armsmaster_harlan' WHERE entry=58632;
UPDATE creature_template SET ScriptName='boss_flameweaver_koegler' WHERE entry=59150;
UPDATE creature_template SET ScriptName='boss_houndmaster_braun' WHERE entry=59303;

-- Scarlet Monastery
UPDATE creature_template SET ScriptName='boss_brother_korloff' WHERE entry=59223;
UPDATE creature_template SET ScriptName='boss_high_inquisitor_whitemane' WHERE entry=74366;
UPDATE creature_template SET ScriptName='boss_thalnos_the_soulrender' WHERE entry=59789;

-- Scholomance
UPDATE creature_template SET ScriptName='boss_darkmaster_gandling' WHERE entry=59080;
UPDATE creature_template SET ScriptName='boss_instructor_chillheart' WHERE entry=58633;
UPDATE creature_template SET ScriptName='boss_jandice_barov' WHERE entry=59184;
UPDATE creature_template SET ScriptName='boss_lilian_voss' WHERE entry=74366;
UPDATE creature_template SET ScriptName='boss_rattlegore' WHERE entry=59153;

-- ShadoPan Monastery
UPDATE instance_template SET script='instance_shadopan_monastery' WHERE map=959;
INSERT INTO instance_template (map,script) values (959,'instance_shadopan_monastery');
-- Gu CloudStrike
UPDATE creature_template SET ScriptName='boss_gu_cloudstrike' WHERE entry=56747;
UPDATE creature_template SET ScriptName='npc_azure_serpent' WHERE entry=56754;
UPDATE creature_template SET ScriptName='npc_azure_serpent' WHERE entry=56754;
--INSERT INTO areatrigger_scripts (entry,ScriptName) values (,'at_gu_intro');
INSERT INTO spell_script_names (spell_id,ScriptName) values (114927,'spell_kill_guardians');
INSERT INTO spell_script_names (spell_id,ScriptName) values (111129,'spell_overcharged_soul_damage');
INSERT INTO spell_script_names (spell_id,ScriptName) values (107140,'spell_magnetic_shroud');
-- Master Snowdrift
UPDATE creature_template SET ScriptName='boss_master_snowdrift' WHERE entry=56541;
UPDATE creature_template SET ScriptName='npc_snowdrift_novice' WHERE entry=56395;
UPDATE creature_template SET ScriptName='npc_snowdrift_clone' WHERE entry=56713;
UPDATE creature_template SET ScriptName='npc_snowdrift_miniboss' WHERE entry=56397;
--UPDATE creature_template SET ScriptName='npc_snowdrift_fireball' WHERE entry=;
-- Sha of Violence
UPDATE creature_template SET ScriptName='boss_sha_of_violence' WHERE entry=56719;
-- Taran Zhu
UPDATE creature_template SET ScriptName='boss_taran_zhu' WHERE entry=56884;
UPDATE creature_template SET ScriptName='npc_gripping_hatred' WHERE entry=59804;
--INSERT INTO spell_script_names (spell_id,ScriptName) values (107085,'spell_taran_zhu_hate');
--INSERT INTO spell_script_names (spell_id,ScriptName) values (107085,'spell_taran_zhu_meditation');
INSERT INTO spell_script_names (spell_id,ScriptName) values (107085,'spell_taran_zhu_grip_of_hate');
INSERT INTO spell_script_names (spell_id,ScriptName) values (131521,'spell_taran_zhu_ring_of_malice');

-- Siege of Niuzao Temple
UPDATE instance_template SET script='instance_siege_of_the_niuzoa_temple' WHERE map=1011;
-- Jin Bak
UPDATE creature_template SET ScriptName='boss_jinbak' WHERE entry=61567;
UPDATE creature_template SET ScriptName='npc_sap_puddle' WHERE entry=61613;

-- Stormstout Brewery
UPDATE instance_template SET script='instance_stormstout_brewery' WHERE map=961;
-- Hoptallus
UPDATE creature_template SET ScriptName='boss_hoptallus' WHERE entry=56717;
UPDATE creature_template SET ScriptName='mob_virmen' WHERE entry=59464;
UPDATE creature_template SET ScriptName='mob_virmen' WHERE entry=59551;
UPDATE creature_template SET ScriptName='stalker_carrot_breath' WHERE entry=200504;
INSERT INTO spell_script_names (spell_id,ScriptName) values (112944,'spell_hoptallus_carrot_breath');
INSERT INTO spell_script_names (spell_id,ScriptName) values (114291,'spell_hoptallus_explosive_brew_target_selector');
--Ook Ook
UPDATE creature_template SET ScriptName='boss_ook_ook' WHERE entry=56637;
INSERT INTO achievement_criteria_data (ScriptName) VALUES ('achievement_keep_rollin_rollin_rollin') WHERE criteria_id=6089;
-- Yan Zhu The Uncasked
UPDATE creature_template SET ScriptName='boss_yan_zhu_the_uncasked' WHERE entry=59479;
UPDATE creature_template SET ScriptName='mob_yeasty_brew_alamental_yan_zhu' WHERE entry=66413;
UPDATE creature_template SET ScriptName='npc_fizzy_bubble' WHERE entry=59799;
INSERT INTO spell_script_names (spell_id,ScriptName) values (114466,'spell_yanzhu_wall_of_suds');
INSERT INTO spell_script_names (spell_id,ScriptName) values (106851,'spell_yanzhu_blackout_brew');
INSERT INTO spell_script_names (spell_id,ScriptName) values (106546,'spell_yanzhu_bloat');
INSERT INTO spell_script_names (spell_id,ScriptName) values (106560,'spell_yanzhu_bloat_damage_target_selector');
INSERT INTO spell_script_names (spell_id,ScriptName) values (114451,'spell_yanzhu_ferment');
INSERT INTO spell_script_names (spell_id,ScriptName) values (106563,'spell_yanzhu_bubble_shield');
INSERT INTO spell_script_names (spell_id,ScriptName) values (114386,'spell_yanzhu_carbonation_target_selector');
INSERT INTO achievement_criteria_data (ScriptName) VALUES ('achievement_heroic_stormstout_brewery') WHERE criteria_id=6456;

-- Temple of the Jade Serpent
UPDATE instance_template SET script='instance_temple_of_jade_serpent' WHERE map=960;
-- Liu Flameheart
UPDATE creature_template SET ScriptName='boss_liu_flameheart' WHERE entry=56732;
UPDATE creature_template SET ScriptName='boss_yu_lon' WHERE entry=56762;
UPDATE creature_template SET ScriptName='mob_minion_of_doubt' WHERE entry=65362;
UPDATE creature_template SET ScriptName='mob_lesser_sha' WHERE entry=56439;
UPDATE creature_template SET ScriptName='mob_jade_fire' WHERE entry=56893;
-- Lorewalker Stonestep
UPDATE creature_template SET ScriptName='boss_lorewalker_stonestep' WHERE entry=56843;
UPDATE creature_template SET ScriptName='mob_lorewalker_scroll' WHERE entry=57080;
UPDATE creature_template SET ScriptName='mob_sun' WHERE entry=56915;
UPDATE creature_template SET ScriptName='mob_sunfire' WHERE entry=58815;
UPDATE creature_template SET ScriptName='mob_zao' WHERE entry=58826;
UPDATE creature_template SET ScriptName='mob_haunting_sha' WHERE entry=58865;
UPDATE creature_template SET ScriptName='mob_peril_and_strife' WHERE entry=59726;
UPDATE creature_template SET ScriptName='mob_peril_and_strife' WHERE entry=59051;
UPDATE creature_template SET ScriptName='mob_nodding_tiger' WHERE entry=59544;
UPDATE creature_template SET ScriptName='mob_golden_beetle' WHERE entry=59545;
UPDATE creature_template SET ScriptName='mob_jiang_xiang' WHERE entry=59547;
UPDATE creature_template SET ScriptName='mob_jiang_xiang' WHERE entry=65317;
UPDATE creature_template SET ScriptName='mob_songbird_queen' WHERE entry=59553;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=59149;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=56882;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=56871;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=56872;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=56873;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=56874;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=59545;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=59552;
UPDATE creature_template SET ScriptName='mob_sha_corrupted_generic' WHERE entry=59544;
UPDATE creature_template SET ScriptName='mob_talking_fish' WHERE entry=59546;
UPDATE creature_template SET ScriptName='mob_hunting_sha' WHERE entry=59555;
-- Sha of Doubt
UPDATE creature_template SET ScriptName='boss_sha_of_doubt' WHERE entry=56439;
UPDATE creature_template SET ScriptName='mob_figment_of_doubt' WHERE entry=56792;
-- Wise Mari
UPDATE creature_template SET ScriptName='boss_wase_mari' WHERE entry=56448;
UPDATE creature_template SET ScriptName='mob_corrupt_living_water' WHERE entry=59873;
INSERT INTO spell_script_names (spell_id,ScriptName) values (106334,'spell_wise_mari_wash_away');

-- Terrace Of Endless Spring
UPDATE instance_template SET script='instance_terrace_of_endless_spring' WHERE map=996;
-- Protectors of the Endless
UPDATE creature_template SET ScriptName='boss_protector_kaolan' WHERE entry=60583;
UPDATE creature_template SET ScriptName='boss_elder_regail' WHERE entry=60585;
UPDATE creature_template SET ScriptName='boss_elder_asani' WHERE entry=60586;
UPDATE creature_template SET ScriptName='npc_defiled_ground' WHERE entry=60906;
UPDATE creature_template SET ScriptName='npc_expelled_corruption' WHERE entry=60886;
UPDATE creature_template SET ScriptName='npc_cleansing_waters' WHERE entry=60646;
UPDATE creature_template SET ScriptName='npc_corrupted_waters' WHERE entry=60621;
INSERT INTO spell_script_names (spell_id,ScriptName) values (117955,'spell_expelled_corruption');
INSERT INTO spell_script_names (spell_id,ScriptName) values (111850,'spell_lightning_prison');

-- Throne Of Thunder
UPDATE instance_template SET script='instance_throne_of_thunder' WHERE map=1098;
-- Council of Elders
UPDATE creature_template SET ScriptName = 'npc_council_event_helper' WHERE entry = 662203;
UPDATE creature_template SET ScriptName = 'boss_frost_king_malakk' WHERE entry = 69131;
UPDATE creature_template SET ScriptName = 'boss_kazrajin' WHERE entry = 69134;
UPDATE creature_template SET ScriptName = 'boss_sul_the_sandcrawler' WHERE entry = 69078;
UPDATE creature_template SET ScriptName = 'boss_high_priestess_marli' WHERE entry = 69132;
UPDATE creature_template SET ScriptName = 'mob_garajals_soul' WHERE entry = 69182;
UPDATE creature_template SET ScriptName = 'mob_quicksand_stalker' WHERE entry = 662205;
UPDATE creature_template SET ScriptName = 'mob_living_sand' WHERE entry = 69153;
UPDATE creature_template SET ScriptName = 'mob_blessed_loa_spirit' WHERE entry = 69480;
UPDATE creature_template SET ScriptName = 'mob_shadowed_loa_spirit' WHERE entry = 69548;
UPDATE creature_template SET ScriptName = 'mob_twisted_fate_helper' WHERE entry = 662204;
UPDATE creature_template SET ScriptName = 'mob_twisted_fate' WHERE entry IN (69740, 69746);
INSERT INTO spell_script_names VALUES
    (136442, 'spell_garajal_possessed'),
    (136903, 'spell_malakk_frigid_assault'),
    (136917, 'spell_malakk_biting_cold'),
    (136922, 'spell_malakk_frostbite_periodic'),
    (136990, 'spell_malakk_frostbite'),
    (136937, 'spell_malakk_frostbite_allies'),
    (137084, 'spell_malakk_body_heat'),
    (137117, 'spell_kazrajin_reckless_charge'),
    (137149, 'spell_kazrajin_overload'),
    (137166, 'spell_kazrajin_discharge'),
    (136860, 'spell_quicksand_periodic'),
    (136857, 'spell_quicksand_entrapped'),
    (136894, 'spell_sul_sandstorm'),
    (137203, 'spell_marli_summon_blessed_loa_spirit'),
    (137350, 'spell_marli_summon_shadowed_loa_spirit'),
    (137891, 'spell_marli_twisted_fate_first'),
    (137962, 'spell_marli_twisted_fate_second'),
    (137986, 'spell_marli_twisted_fate_damages');
-- Boss Horrifon
UPDATE creature_template SET ScriptName='npc_horrion_event_helper' WHERE entry=662202;
UPDATE creature_template SET ScriptName='boss_horridon' WHERE entry=68476;
UPDATE creature_template SET ScriptName='mob_war_god_jalak' WHERE entry=69374;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69172;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69167;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69185;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69184;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69168;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69176;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69175;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69164;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69178;
UPDATE creature_template SET ScriptName='mob_horridon_trashs' WHERE entry=69177;
UPDATE creature_template SET ScriptName='mob_horridon_summons' WHERE entry=69346;
UPDATE creature_template SET ScriptName='mob_horridon_summons' WHERE entry=69314;
UPDATE creature_template SET ScriptName='mob_horridon_summons' WHERE entry=69268;
UPDATE creature_template SET ScriptName='mob_horridon_summons' WHERE entry=69215;
UPDATE creature_template SET ScriptName='mob_horridon_summons' WHERE entry=69313;
UPDATE creature_template SET ScriptName='mob_zandalari_dinomancer' WHERE entry=69221;
UPDATE creature_template SET ScriptName='mob_direhorn_spirit' WHERE entry=70688;
UPDATE gameobject_template SET ScriptName='gob_horridon_orb_of_control' WHERE entry=218193;
UPDATE gameobject_template SET ScriptName='gob_horridon_orb_of_control' WHERE entry=218374;
UPDATE gameobject_template SET ScriptName='gob_horridon_orb_of_control' WHERE entry=218375;
UPDATE gameobject_template SET ScriptName='gob_horridon_orb_of_control' WHERE entry=218376;
INSERT INTO spell_script_names (spell_id,ScriptName) values (136741,'spell_horridon_double_swipe');
INSERT INTO spell_script_names (spell_id,ScriptName) values (137433,'spell_control_horridon');
INSERT INTO spell_script_names (spell_id,ScriptName) values (137442,'spell_control_horridon');
INSERT INTO spell_script_names (spell_id,ScriptName) values (137443,'spell_control_horridon');
INSERT INTO spell_script_names (spell_id,ScriptName) values (137444,'spell_control_horridon');
INSERT INTO spell_script_names (spell_id,ScriptName) values (136723,'spell_horridon_sand_trap');
-- Jin Rokh
UPDATE creature_template SET ScriptName='boss_jin_rokh' WHERE entry=69465;
UPDATE creature_template SET ScriptName='npc_conductive_water' WHERE entry=69469;
UPDATE creature_template SET ScriptName='npc_orb_of_focused_lightning' WHERE entry=70174;
UPDATE creature_template SET ScriptName='npc_lightning_fissure' WHERE entry=69609;
UPDATE creature_template SET ScriptName='npc_lightning_strike' WHERE entry=69753;
UPDATE creature_template SET ScriptName='npc_lightning_strike_storm' WHERE entry=662201;
UPDATE creature_template SET ScriptName='npc_mogu_statue_stalker' WHERE entry=662200;
INSERT INTO spell_script_names (spell_id,ScriptName) values (140597,'spell_jinrokh_thundering_throw');
INSERT INTO spell_script_names (spell_id,ScriptName) values (137162,'spell_jinrokh_static_burst');
INSERT INTO spell_script_names (spell_id,ScriptName) values (138349,'spell_jinrokh_static_wound');
INSERT INTO spell_script_names (spell_id,ScriptName) values (137530,'spell_jinrokh_focused_lightning_conduction');
INSERT INTO spell_script_names (spell_id,ScriptName) values (137507,'spell_jinrokh_implosion_conduction');
INSERT INTO spell_script_names (spell_id,ScriptName) values (137313,'spell_jinrokh_lightning_storm');
INSERT INTO spell_script_names (spell_id,ScriptName) values (138732,'spell_jinrokh_ionization');
INSERT INTO spell_script_names (spell_id,ScriptName) values (138743,'spell_jinrokh_ionization_conduction');
INSERT INTO spell_script_names (spell_id,ScriptName) values (138743,'spell_jinrokh_ionization_conduction');
-- Tortos
UPDATE creature_template SET ScriptName='boss_tortos' WHERE entry=69465;
UPDATE creature_template SET ScriptName='npc_rockfall' WHERE entry=69465;
INSERT INTO spell_script_names (spell_id,ScriptName) values (140431,'spell_rockfall');

-- TimelessIsle
UPDATE creature_template SET ScriptName='boss_chi_ji_ti' WHERE entry=71952;
UPDATE creature_template SET ScriptName='npc_eternal_kiln' WHERE entry=72896;
UPDATE creature_template SET ScriptName='npc_flarecore_golem' WHERE entry=73527;
UPDATE gameobject_template SET ScriptName='go_time_lost_shrine_ti' WHERE entry=222776;
UPDATE gameobject_template SET ScriptName='go_gleaming_crane_statue_ti' WHERE entry=220903;
INSERT INTO spell_script_names (spell_id,ScriptName) values (144385,'spell_timeless_isle_crane_wings');
INSERT INTO spell_script_names (spell_id,ScriptName) values (147997,'spell_timeless_isle_cauterize');
INSERT INTO spell_script_names (spell_id,ScriptName) values (147703,'spell_timeless_isle_burning_fury');
UPDATE creature_template SET ScriptName='npc_cinderfall' WHERE entry=73175;
UPDATE creature_template SET ScriptName='npc_huolon' WHERE entry=73167;
UPDATE creature_template SET ScriptName='npc_imperial_python' WHERE entry=73163;
UPDATE creature_template SET ScriptName='npc_emerald_gander' WHERE entry=73158;
UPDATE creature_template SET ScriptName='npc_golganarr' WHERE entry=72970;
UPDATE creature_template SET ScriptName='npc_watcher_osu' WHERE entry=73170;
UPDATE creature_template SET ScriptName='npc_tsavoka' WHERE entry=72808;
UPDATE creature_template SET ScriptName='npc_spirit_of_jadefire' WHERE entry=72769;
UPDATE creature_template SET ScriptName='npc_monstrous_spineclaw' WHERE entry=73166;
UPDATE creature_template SET ScriptName='npc_great_turtle_furyshell' WHERE entry=73161;
UPDATE creature_template SET ScriptName='npc_ironfur_steelhorn' WHERE entry=73160;
UPDATE creature_template SET ScriptName='npc_champion_of_the_black_flame' WHERE entry=73171;
UPDATE creature_template SET ScriptName='npc_chelon' WHERE entry=72045;
UPDATE creature_template SET ScriptName='npc_cranegnasher' WHERE entry=72049;
UPDATE creature_template SET ScriptName='npc_jakur_of_ordon' WHERE entry=73169;
UPDATE creature_template SET ScriptName='npc_bufo' WHERE entry=72775;
UPDATE creature_template SET ScriptName='npc_evermaw' WHERE entry=73279;

-- Wandering Island
-- East
UPDATE creature_template SET ScriptName='mob_tushui_monk' WHERE entry=65550;
UPDATE creature_template SET ScriptName='mob_tushui_monk' WHERE entry=55019;
UPDATE creature_template SET ScriptName='mob_tushui_monk' WHERE entry=65468;
UPDATE creature_template SET ScriptName='mob_tushui_monk' WHERE entry=59649;
UPDATE creature_template SET ScriptName='mob_shu_water_spirit' WHERE entry=55556;
UPDATE creature_template SET ScriptName='mob_shu_water_spirit' WHERE entry=60918;
UPDATE creature_template SET ScriptName='mob_shu_water_spirit' WHERE entry=65493;
UPDATE creature_template SET ScriptName='mob_shu_water_spirit' WHERE entry=65105;
INSERT INTO spell_script_names (spell_id,ScriptName) values (103069,'spell_rock_jump');
INSERT INTO spell_script_names (spell_id,ScriptName) values (103070,'spell_rock_jump');
INSERT INTO spell_script_names (spell_id,ScriptName) values (103077,'spell_rock_jump');
INSERT INTO spell_script_names (spell_id,ScriptName) values (103245,'spell_shu_benediction');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115904,'spell_grab_carriage');
UPDATE creature_template SET ScriptName='npc_nourished_yak' WHERE entry=59499;
-- North
UPDATE creature_template SET ScriptName='mob_master_shang_xi' WHERE entry=54609;
UPDATE creature_template SET ScriptName='mob_master_shang_xi' WHERE entry=55586;
UPDATE creature_template SET ScriptName='mob_master_shang_xi' WHERE entry=55672;
UPDATE creature_template SET ScriptName='mob_master_shang_xi' WHERE entry=53566;
UPDATE creature_template SET ScriptName='mob_master_shang_xi' WHERE entry=54786;
UPDATE creature_template SET ScriptName='mob_master_shang_xi' WHERE entry=54608;
UPDATE gameobject_template SET ScriptName='go_wandering_weapon_rack' WHERE entry=210017;
UPDATE gameobject_template SET ScriptName='go_wandering_weapon_rack' WHERE entry=210016;
UPDATE gameobject_template SET ScriptName='go_wandering_weapon_rack' WHERE entry=210020;
UPDATE gameobject_template SET ScriptName='go_wandering_weapon_rack' WHERE entry=210018;
UPDATE gameobject_template SET ScriptName='go_wandering_weapon_rack' WHERE entry=210005;
UPDATE gameobject_template SET ScriptName='go_wandering_weapon_rack' WHERE entry=210015;
UPDATE gameobject_template SET ScriptName='go_wandering_weapon_rack' WHERE entry=210019;
UPDATE creature_template SET ScriptName='mob_tushui_trainee' WHERE entry=65471;
UPDATE creature_template SET ScriptName='mob_tushui_trainee' WHERE entry=54587;
UPDATE creature_template SET ScriptName='boss_jaomin_ro' WHERE entry=54611;
UPDATE creature_template SET ScriptName='mob_min_dimwind' WHERE entry=54855;
UPDATE creature_template SET ScriptName='mob_attacker_dimwind' WHERE entry=54785;
UPDATE creature_template SET ScriptName='mob_attacker_dimwind' WHERE entry=54785;





-- MONK SPELLS
INSERT INTO spell_script_names (spell_id,ScriptName) values (117952,'spell_monk_crackling_jade_lightning');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117959,'spell_monk_crackling_jade_lightning_aura');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115203,'spell_monk_fortifying_brew');
INSERT INTO spell_script_names (spell_id,ScriptName) values (123725,'spell_monk_breath_of_fire');
INSERT INTO spell_script_names (spell_id,ScriptName) values (123393,'spell_monk_breath_of_fire');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117666,'spell_monk_legacy_of_the_emperor');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117667,'spell_monk_legacy_of_the_emperor');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115129,'spell_monk_expel_harm');
INSERT INTO spell_script_names (spell_id,ScriptName) values (124490,'spell_monk_touch_of_death');
INSERT INTO spell_script_names (spell_id,ScriptName) values (109132,'spell_monk_roll');
INSERT INTO spell_script_names (spell_id,ScriptName) values (121827,'spell_monk_roll');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116095,'spell_monk_disable');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115078,'spell_monk_paralysis');
INSERT INTO spell_script_names (spell_id,ScriptName) values (107270,'spell_monk_spinning_crane_kick');
INSERT INTO spell_script_names (spell_id,ScriptName) values (123980,'spell_monk_brewing_tigereye_brew');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116740,'spell_monk_tigereye_brew');
INSERT INTO spell_script_names (spell_id,ScriptName) values (120273,'spell_monk_tiger_strikes');
INSERT INTO spell_script_names (spell_id,ScriptName) values (126892,'spell_monk_zen_pilgrimage');
INSERT INTO spell_script_names (spell_id,ScriptName) values (126895,'spell_monk_zen_pilgrimage_return');
INSERT INTO spell_script_names (spell_id,ScriptName) values (124682,'spell_monk_enveloping_mist');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116694,'spell_monk_surging_mist');
INSERT INTO spell_script_names (spell_id,ScriptName) values (119611,'spell_monk_renewing_mist');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115460,'spell_monk_healing_sphere');
UPDATE creature_template SET ScriptName='npc_transcendence_spirit' WHERE entry=54569;
INSERT INTO spell_script_names (spell_id,ScriptName) values (102141,'spell_monk_transcendence');
INSERT INTO spell_script_names (spell_id,ScriptName) values (119996,'spell_monk_transcendence_transfer');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122470,'spell_monk_touch_of_karma');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122783,'spell_monk_diffuse_magic');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115315,'spell_monk_black_ox_statue');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115295,'spell_monk_guard');
INSERT INTO spell_script_names (spell_id,ScriptName) values (125893,'spell_monk_glyph_of_zen_flight');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115313,'spell_monk_jade_serpent_statue');
INSERT INTO spell_script_names (spell_id,ScriptName) values (120086,'spell_monk_fists_of_fury_stun');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132467,'spell_monk_chi_wave_bolt');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132463,'spell_monk_chi_wave_bolt');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115098,'spell_monk_chi_wave');
INSERT INTO spell_script_names (spell_id,ScriptName) values (117368,'spell_monk_grapple_weapon');
INSERT INTO spell_script_names (spell_id,ScriptName) values (132464,'spell_monk_chi_wave_healing_bolt');
INSERT INTO spell_script_names (spell_id,ScriptName) values (127722,'spell_monk_serpents_zeal');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122278,'spell_monk_dampen_harm');
INSERT INTO spell_script_names (spell_id,ScriptName) values (127361,'spell_monk_bear_hug');
INSERT INTO spell_script_names (spell_id,ScriptName) values (125883,'spell_monk_zen_flight_check');
INSERT INTO spell_script_names (spell_id,ScriptName) values (121817,'spell_monk_power_strikes');
INSERT INTO spell_script_names (spell_id,ScriptName) values (123408,'spell_monk_spinning_fire_blossom_damage');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115073,'spell_monk_spinning_fire_blossom');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116680,'spell_monk_thunder_focus_tea');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116645,'spell_monk_teachings_of_the_monastery');
INSERT INTO spell_script_names (spell_id,ScriptName) values (123763,'spell_monk_glyph_of_mana_tea');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115294,'spell_monk_mana_tea');
INSERT INTO spell_script_names (spell_id,ScriptName) values (123766,'spell_monk_mana_tea_stacks');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122280,'spell_monk_healing_elixirs');
INSERT INTO spell_script_names (spell_id,ScriptName) values (124081,'spell_monk_zen_sphere');
INSERT INTO spell_script_names (spell_id,ScriptName) values (123986,'spell_monk_chi_burst');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115288,'spell_monk_energizing_brew');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116705,'spell_monk_spear_hand_strike');
INSERT INTO spell_script_names (spell_id,ScriptName) values (116841,'spell_monk_tigers_lust');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115057,'spell_monk_flying_serpent_kick');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115008,'spell_monk_chi_torpedo');
INSERT INTO spell_script_names (spell_id,ScriptName) values (121828,'spell_monk_chi_torpedo');
INSERT INTO spell_script_names (spell_id,ScriptName) values (119582,'spell_monk_purifying_brew');
INSERT INTO spell_script_names (spell_id,ScriptName) values (122057,'spell_monk_clash');
INSERT INTO spell_script_names (spell_id,ScriptName) values (126449,'spell_monk_clash');
INSERT INTO spell_script_names (spell_id,ScriptName) values (121253,'spell_monk_keg_smash');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115308,'spell_monk_elusive_brew');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115175,'spell_monk_soothing_mist');
INSERT INTO spell_script_names (spell_id,ScriptName) values (100784,'spell_monk_blackout_kick');
INSERT INTO spell_script_names (spell_id,ScriptName) values (115546,'spell_monk_provoke');
INSERT INTO spell_script_names (spell_id,ScriptName) values (123980,'spell_monk_tigereye_brew_stacks');
--INSERT INTO spell_script_names (spell_id,ScriptName) values (124081,'spell_monk_zen_sphere_hot');





























