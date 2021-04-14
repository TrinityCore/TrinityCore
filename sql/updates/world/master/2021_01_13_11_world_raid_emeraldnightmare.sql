-- cenarius
update creature_template set scriptname='boss_cenarius' where entry=104636;
update creature_template set scriptname='npc_cenarius_force_summoner' where entry in (106427, 106895, 106898, 106899);
update creature_template set scriptname='npc_cenarius_forces_of_nightmare' where entry in (105468, 106304, 105494, 105495);
update creature_template set scriptname='npc_cenarius_allies_of_nature' where entry in (106667, 106659, 106809, 106831);
update creature_template set scriptname='npc_cenarius_malfurion_stormrage' where entry=106482;
update creature_template set scriptname='npc_cenarius_nightmare_brambles' where entry=106167;
update creature_template set scriptname='npc_cenarius_entangling_roots' where entry=108040;
update creature_template set scriptname='npc_cenarius_beast_of_nightmare' where entry=108208;

replace into spell_script_names values (212630,'spell_cenarius_cleansing_ground');
replace into spell_script_names values (212192,'spell_cenarius_sum_wisp');
replace into spell_script_names values (212188,'spell_cenarius_sum_wisp');
replace into spell_script_names values (211639,'spell_cenarius_allies_periodic_energize');
replace into spell_script_names values (211935,'spell_cenarius_ancient_dream_filter');
replace into spell_script_names values (211939,'spell_cenarius_ancient_dream');
replace into spell_script_names values (226821,'spell_cenarius_desiccating_stomp_filter');
replace into spell_script_names values (211073,'spell_cenarius_desiccating_stomp_filter');
replace into spell_script_names values (211462,'spell_cenarius_twisted_touch_of_life_filter');
replace into spell_script_names values (210340,'spell_cenarius_dread_thorns_reflects');
replace into spell_script_names values (214529,'spell_cenarius_spear_of_nightmares');


replace into spell_areatrigger values (7297, 7297, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (7297,'at_cenarius_nightmare_blast');
replace into areatrigger_template values (7297, 0, 0, 5, 5, 0, 0, 0, 0, 'at_cenarius_nightmare_blast', 0);

-- dragons of nightmare
update creature_template set scriptname='boss_dragon_ysondre' where entry=102679;
update creature_template set scriptname='boss_dragon_taerar' where entry=102681;
update creature_template set scriptname='boss_dragon_lethon' where entry=102682;
update creature_template set scriptname='boss_dragon_emeriss' where entry=102683;
update creature_template set scriptname='npc_ysondre_nightmare_bloom' where entry=102804;
update creature_template set scriptname='npc_ysondre_defiled_druid_spirit' where entry=103080;
update creature_template set scriptname='npc_ysondre_shade_of_taerar' where entry=103145;
update creature_template set scriptname='npc_ysondre_spirit_shade' where entry=103100;
update creature_template set scriptname='npc_ysondre_dread_horror' where entry=103044;
update creature_template set scriptname='npc_ysondre_corrupted_mushroom' where entry in (103095, 103096, 103097);
update creature_template set scriptname='npc_en_rothos' where entry=111852;

replace into spell_script_names values (204040,'spell_ysondre_shadow_burst');
replace into spell_script_names values (203102,'spell_ysondre_marks');
replace into spell_script_names values (203121,'spell_ysondre_marks');
replace into spell_script_names values (203124,'spell_ysondre_marks');
replace into spell_script_names values (203125,'spell_ysondre_marks');
replace into spell_script_names values (205281,'spell_ysondre_periodic_energize');
replace into spell_script_names values (205282,'spell_ysondre_periodic_energize');
replace into spell_script_names values (203686,'spell_ysondre_nightmare_bloom');
replace into spell_script_names values (205172,'spell_ysondre_bellowing_roar');
replace into spell_script_names values (203888,'spell_ysondre_siphon_spirit_filter');

-- elerethe renferal
update creature_template set scriptname='boss_elerethe_renferal' where entry=106087;
update creature_template set scriptname='npc_elerethe_venomous_spiderling' where entry=107459;
update creature_template set scriptname='npc_elerethe_surging_egg_sac' where entry=108540;
update creature_template set scriptname='npc_elerethe_twisting_shadows' where entry in (106350, 107767, 111439);
update creature_template set scriptname='npc_en_venomous_spider' where entry=112039;
update creature_template set scriptname='npc_en_nightmother' where entry=111980;
update creature_template set scriptname='npc_en_shadowfeather' where entry=111975;
update creature_template set scriptname='npc_en_venomous_spiderling' where entry=106311;

replace into spell_script_names values (225364,'spell_elerethe_energy_tracker_transform');
replace into spell_script_names values (215288,'spell_elerethe_web_of_pain_filter');
replace into spell_script_names values (215307,'spell_elerethe_web_of_pain');
replace into spell_script_names values (215300,'spell_elerethe_web_of_pain');
replace into spell_script_names values (214348,'spell_elerethe_vile_ambush');
replace into spell_script_names values (214311,'spell_elerethe_feeding_time_filter');
replace into spell_script_names values (215449,'spell_elerethe_necrotic_venom');
replace into spell_script_names values (212993,'spell_elerethe_shimmering_feather_proc');
replace into spell_script_names values (223029,'spell_en_wretched_ambush');

-- ilgynoth
update creature_template set scriptname='boss_ilgynoth' where entry=105393;
update creature_template set scriptname='npc_eye_of_ilgynoth' where entry=105906;
update creature_template set scriptname='npc_ilgynoth_tentacles' where entry in (105304, 105322, 105383, 108821);
update creature_template set scriptname='npc_ilgynoth_nightmare_horror' where entry=105591;
update creature_template set scriptname='npc_ilgynoth_nightmare_ichor' where entry=105721;

replace into spell_script_names values (218415,'spell_ilgynoth_death_blossom');
replace into spell_script_names values (215128,'spell_ilgynoth_cursed_blood');
replace into spell_script_names values (209471,'spell_ilgynoth_nightmare_explosion');
replace into spell_script_names values (210048,'spell_ilgynoth_nightmare_explosion_pct');

-- nythendra
update creature_template set scriptname='boss_nythendra' where entry=102672;
update creature_template set scriptname='npc_nythendra_gelatinized_decay' where entry=111004;
update creature_template set scriptname='npc_nythendra_corrupted_vermin' where entry in (102998, 111005);

replace into spell_script_names values (203096,'spell_nythendra_volatile_rot');
replace into spell_script_names values (204463,'spell_nythendra_volatile_rot');
replace into spell_script_names values (204470,'spell_nythendra_volatile_rot_dmg');
replace into spell_script_names values (203537,'spell_nythendra_infested_ground_rot');
replace into spell_script_names values (203536,'spell_nythendra_infested_ground_rot');
replace into spell_script_names values (203095,'spell_nythendra_rot');
replace into spell_script_names values (205070,'spell_nythendra_infested');
replace into spell_script_names values (203646,'spell_nythendra_infested');
replace into spell_script_names values (204470,'spell_nythendra_infested');
replace into spell_script_names values (203097,'spell_nythendra_infested');
replace into spell_script_names values (202978,'spell_nythendra_infested');
replace into spell_script_names values (203045,'spell_nythendra_infested');
replace into spell_script_names values (205043,'spell_nythendra_infested_mind');
replace into spell_script_names values (222760,'spell_en_befoulment');

-- ursoc
update creature_template set scriptname='boss_ursoc' where entry=100497;
update creature_template set scriptname='npc_ursoc_nightmare_image' where entry=100576;

replace into spell_script_names values (205272,'spell_ursoc_periodic_energize');
replace into spell_script_names values (199237,'spell_ursoc_trampling_slam');
replace into spell_script_names values (198109,'spell_ursoc_barreling_impact');
replace into spell_script_names values (198099,'spell_ursoc_momentum_filter');

-- xavius
update creature_template set scriptname='boss_xavius' where entry=103769;
update creature_template set scriptname='npc_xavius_sleeping_version' where entry=104096;
update creature_template set scriptname='npc_xavius_dread_abomination' where entry=105343;
update creature_template set scriptname='npc_xavius_lurking_terror' where entry=103694;
update creature_template set scriptname='npc_xavius_corruption_horror' where entry=103695;
update creature_template set scriptname='npc_xavius_nightmare_blades' where entry=104422;
update creature_template set scriptname='npc_xavius_inconceivable_horror' where entry=105611;
update creature_template set scriptname='npc_xavius_nightmare_tentacle' where entry=104592;
update creature_template set scriptname='npc_xavius_event_conroller' where entry=109847;

replace into spell_script_names values (226184,'spell_xavius_periodic_energize');
replace into spell_script_names values (206005,'spell_xavius_dream_simulacrum');
replace into spell_script_names values (189960,'spell_xavius_nightmare_torment_alt_power');
replace into spell_script_names values (208860,'spell_xavius_crushing_shadows');
replace into spell_script_names values (207160,'spell_xavius_unfathomable_reality');
replace into spell_script_names values (208431,'spell_xavius_descent_into_madness');
replace into spell_script_names values (206651,'spell_xavius_darkening_soul');
replace into spell_script_names values (209158,'spell_xavius_darkening_soul');
replace into spell_script_names values (211802,'spell_xavius_nightmare_blades');
replace into spell_script_names values (206656,'spell_xavius_nightmare_blades_dmg_filter');
replace into spell_script_names values (210451,'spell_xavius_bonds_of_terror');
replace into spell_script_names values (226194,'spell_xavius_writhing_deep');
replace into spell_script_names values (207830,'spell_xavius_corrupting_nova');
replace into spell_script_names values (207849,'spell_xavius_corruption_meteor');
replace into spell_script_names values (206369,'spell_xavius_corruption_meteor');
replace into spell_script_names values (223216,'spell_teleport_to_rift');