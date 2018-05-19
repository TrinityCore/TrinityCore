DELETE FROM spell_script_names WHERE scriptname IN ("spell_summon_blood_elves_script","spell_muru_darkness","spell_dark_fiend_skin","spell_transform_visual_missile_periodic","spell_summon_blood_elves_periodic","spell_council_glaciate","spell_council_thundershock","spell_council_quake","spell_council_rising_flames","spell_council_burning_blood","spell_council_heart_of_ice","spell_council_liquid_ice","spell_halfus_stone_touch","spell_halfus_stone_grip","spell_sinestra_wreck","spell_sinestra_wrack_jump","spell_sinestra_twilight_slicer","spell_sinestra_twilight_essence","spell_sinestra_phyrric_focus","spell_dazzling_destruction","spell_devouring_flame","spell_shifting_reality","spell_whorshipping","spell_depravity","spell_sprayed_corruption","spell_spilled_blood_of_the_old_god","spell_corrupting_crash","spell_corruption_of_the_old_god","spell_debilitating_beam","spell_corruption_accelerated","spell_corruption_sickness","spell_shadow_conductor","spell_magmaw_massive_crash","spell_finkles_mixture","spell_release_abberations","spell_release_all_abberations","spell_atramedes_sonic_breath","spell_nefarian_tail_lash","spell_onyxia_lightning_discharge","spell_captain_cookie_setiated","spell_captain_cookie_nauseated","spell_captain_cookie_throw_food_targeting","spell_bleeding_wound","spell_ground_siege","spell_shadow_gale_damage","spell_disoriented_roar","spell_ashbury_archangel","spell_ashbury_asphyxoate_periodic","spell_summon_worgen_spirits","spell_toxic_coagulant_red","spell_springvale_forsaken_ability","spell_toxic_coagulant_green","spell_pistol_barrage_trigger","spell_pistol_barrage","spell_godfrey_summon_ghouls","spell_ulthok_dark_fissure");
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES 
(46050, "spell_summon_blood_elves_script"),
(46269, "spell_muru_darkness"),
(45934, "spell_dark_fiend_skin"),
(46205, "spell_transform_visual_missile_periodic"),
(46041, "spell_summon_blood_elves_periodic"),
(82746, "spell_council_glaciate"),
(83067, "spell_council_thundershock"),
(83565, "spell_council_quake"),
(82636, "spell_council_rising_flames"),
(82660, "spell_council_burning_blood"),
(82665, "spell_council_heart_of_ice"),
(84914, "spell_council_liquid_ice"),
(83603, "spell_halfus_stone_touch"),
(84593, "spell_halfus_stone_grip"),
(89421, "spell_sinestra_wreck"),
(89435, "spell_sinestra_wrack_jump"),
(92851, "spell_sinestra_twilight_slicer"),
(89284, "spell_sinestra_twilight_essence"),
(87323, "spell_sinestra_phyrric_focus"),
(86408, "spell_dazzling_destruction"),
(86840, "spell_devouring_flame"),
(93055, "spell_shifting_reality"),
(91317, "spell_whorshipping"),
(81713, "spell_depravity"),
(82919, "spell_sprayed_corruption"),
(81757, "spell_spilled_blood_of_the_old_god"),
(81685, "spell_corrupting_crash"),
(82361, "spell_corruption_of_the_old_god"),
(82411, "spell_debilitating_beam"),
(81836, "spell_corruption_accelerated"),
(93202, "spell_corruption_sickness"),
(92053, "spell_shadow_conductor"),
(88287, "spell_magmaw_massive_crash"),
(82705, "spell_finkles_mixture"),
(77569, "spell_release_abberations"),
(77991, "spell_release_all_abberations"),
(78098, "spell_atramedes_sonic_breath"),
(77827, "spell_nefarian_tail_lash"),
(77944, "spell_onyxia_lightning_discharge"),
(89267, "spell_captain_cookie_setiated"),
(89732, "spell_captain_cookie_nauseated"),
(89268, "spell_captain_cookie_throw_food_targeting"),
(89740, "spell_captain_cookie_throw_food_targeting"),
(90561, "spell_captain_cookie_throw_food_targeting"),
(90582, "spell_captain_cookie_throw_food_targeting"),
(90562, "spell_captain_cookie_throw_food_targeting"),
(90583, "spell_captain_cookie_throw_food_targeting"),
(90563, "spell_captain_cookie_throw_food_targeting"),
(90584, "spell_captain_cookie_throw_food_targeting"),
(90564, "spell_captain_cookie_throw_food_targeting"),
(90585, "spell_captain_cookie_throw_food_targeting"),
(90565, "spell_captain_cookie_throw_food_targeting"),
(90586, "spell_captain_cookie_throw_food_targeting"),
(74846, "spell_bleeding_wound"),
(74634, "spell_ground_siege"),
(75664, "spell_shadow_gale_damage"),
(74976, "spell_disoriented_roar"),
(93757, "spell_ashbury_archangel"),
(93423, "spell_ashbury_asphyxoate_periodic"),
(93857, "spell_summon_worgen_spirits"),
(91436, "spell_springvale_forsaken_ability"),
(91442, "spell_springvale_forsaken_ability"),
(91444, "spell_springvale_forsaken_ability"),
(93573, "spell_toxic_coagulant_red"),
(93572, "spell_toxic_coagulant_green"),
(93520, "spell_pistol_barrage_trigger"),
(93564, "spell_pistol_barrage"),
(93707, "spell_godfrey_summon_ghouls"),
(76047, "spell_ulthok_dark_fissure");

UPDATE creature_template SET ScriptName="npc_defias_watcher" WHERE entry=48803;
UPDATE creature_template SET ScriptName="boss_foe_reaper_5000" WHERE entry=43778;
UPDATE creature_template SET ScriptName="npc_glubtok_main_platter" WHERE entry=48974;
UPDATE creature_template SET ScriptName="npc_glubtok_secondary_platter" WHERE entry=48975;
UPDATE creature_template SET ScriptName="npc_glubtok_secondary_platter" WHERE entry=48976;
UPDATE creature_template SET ScriptName="npc_glubtok_secondary_platter" WHERE entry=49039;
UPDATE creature_template SET ScriptName="npc_glubtok_secondary_platter" WHERE entry=49040;
UPDATE creature_template SET ScriptName="npc_glubtok_secondary_platter" WHERE entry=49041;
UPDATE creature_template SET ScriptName="npc_glubtok_secondary_platter" WHERE entry=49042;
UPDATE creature_template SET ScriptName="boss_vanessa_vancleef" WHERE entry=49541;
UPDATE creature_template SET ScriptName="npc_rope_ship" WHERE entry=49550;
UPDATE creature_template SET ScriptName="npc_vanessa_intro" WHERE entry=49429;
UPDATE creature_template SET ScriptName="npc_note" WHERE entry=49564;
UPDATE creature_template SET ScriptName="npc_vanessa_nightmare" WHERE entry=49671;
UPDATE creature_template SET ScriptName="npc_helix_dm" WHERE entry=49674;
UPDATE creature_template SET ScriptName="npc_glubtok_dm" WHERE entry=49670;
UPDATE creature_template SET ScriptName="npc_mechanical_dm" WHERE entry=49681;
UPDATE creature_template SET ScriptName="npc_enraged_worgen_dm" WHERE entry=49532;
UPDATE creature_template SET ScriptName="npc_james_dm" WHERE entry=49539;
UPDATE creature_template SET ScriptName="npc_defias_shadowguard" WHERE entry=48505;
UPDATE creature_template SET ScriptName="npc_defias_enforcer" WHERE entry=48502;
UPDATE creature_template SET ScriptName="npc_defias_bloodwizard" WHERE entry=48417;
UPDATE creature_template SET ScriptName="npc_oaf_lackey" WHERE entry=47297;
UPDATE creature_template SET ScriptName="npc_defias_cannon" WHERE entry=48266;
UPDATE creature_template SET ScriptName="npc_defias_cannon" WHERE entry=48913;
UPDATE creature_template SET ScriptName="npc_goblin_engineer" WHERE entry=48439;
UPDATE creature_template SET ScriptName="npc_mining_powder" WHERE entry=48284;
UPDATE creature_template SET ScriptName="npc_mining_powder" WHERE entry=48835;
UPDATE creature_template SET ScriptName="npc_malignant" WHERE entry=39984;
UPDATE creature_template SET ScriptName="mob_faceless" WHERE entry=40600;
UPDATE creature_template SET ScriptName="mob_alexstraszas_eggs" WHERE entry=40486;
UPDATE creature_template SET ScriptName="npc_battered_red_drake" WHERE entry=48523;
UPDATE creature_template SET ScriptName="npc_net_red_dragon" WHERE entry=42570;
UPDATE creature_template SET ScriptName="boss_lord_walden" WHERE entry=46963;
UPDATE creature_template SET ScriptName="npc_haunted_stable_hand" WHERE entry=51400;
UPDATE creature_template SET ScriptName="lady_nazjar_gauntlet" WHERE entry=39959;
UPDATE creature_template SET ScriptName="npc_tot_teleporter" WHERE entry=51391;
UPDATE creature_template SET ScriptName="npc_tot_teleporter" WHERE entry=51391;

UPDATE gameobject_template SET ScriptName="go_heavy_door" WHERE entry=17154;
UPDATE gameobject_template SET ScriptName="go_throne_of_tides_defence_system" WHERE entry=17154;