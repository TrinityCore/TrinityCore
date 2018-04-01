DELETE FROM spell_script_names WHERE scriptname IN ("spell_dru_efflorescence", "spell_dru_efflorescence_aura", "spell_dru_efflorescence_heal", "spell_dru_primal_fury", "spell_dru_predatory_swiftness", "spell_dru_predatory_swiftness_aura", "spell_dru_lifebloom", "spell_dru_berserk", "spell_dru_sunfire", "spell_dru_balance_affinity_dps", "spell_dru_balance_affinity_resto", "spell_dru_ferocious_bite", "spell_dru_dash", "spell_dru_savage_roar", "spell_dru_survival_instincts", "spell_dru_swift_flight_passive", "spell_dru_wild_growth", "spell_dru_incarnation_chosen_of_elune", "spell_dru_incarnation_king_of_the_jungle", "spell_dru_incarnation_guardian_of_ursoc", "spell_dru_wild_charge_moonkin", "spell_dru_moonfire", "spell_dru_omen_of_clarity", "spell_dru_cat_form", "spell_dru_bear_form", "spell_dru_skull_bash", "spell_dru_stampeding_roar", "spell_dru_activate_cat_form", "spell_dru_killer_instinct", "spell_dru_living_seed", "spell_dru_infected_wound", "spell_dru_ysera_gift", "spell_dru_rake", "spell_dru_maim", "spell_dru_rip", "spell_dru_bloodtalons", "spell_dru_travel_form", "spell_dru_travel_form_aura");

INSERT INTO spell_script_names VALUE (145205, "spell_dru_efflorescence");
INSERT INTO spell_script_names VALUE (81262, "spell_dru_efflorescence_aura");
INSERT INTO spell_script_names VALUE (81269, "spell_dru_efflorescence_heal");
INSERT INTO spell_script_names VALUE (159286, "spell_dru_primal_fury");
INSERT INTO spell_script_names VALUE (16974, "spell_dru_predatory_swiftness");
INSERT INTO spell_script_names VALUE (69369, "spell_dru_predatory_swiftness_aura");
INSERT INTO spell_script_names VALUE (33763, "spell_dru_lifebloom");
INSERT INTO spell_script_names VALUE (106951, "spell_dru_berserk");
INSERT INTO spell_script_names VALUE (93402, "spell_dru_sunfire");
INSERT INTO spell_script_names VALUE (197488, "spell_dru_balance_affinity_dps");
INSERT INTO spell_script_names VALUE (197632, "spell_dru_balance_affinity_resto");
INSERT INTO spell_script_names VALUE (22568, "spell_dru_ferocious_bite");
INSERT INTO spell_script_names VALUE (202031, "spell_dru_ferocious_bite");
INSERT INTO spell_script_names VALUE (1850, "spell_dru_dash");
INSERT INTO spell_script_names VALUE (52610, "spell_dru_savage_roar");
INSERT INTO spell_script_names VALUE (61336, "spell_dru_survival_instincts");
INSERT INTO spell_script_names VALUE (40121, "spell_dru_swift_flight_passive");
INSERT INTO spell_script_names VALUE (48438, "spell_dru_wild_growth");
INSERT INTO spell_script_names VALUE (102560, "spell_dru_incarnation_chosen_of_elune");
INSERT INTO spell_script_names VALUE (102543, "spell_dru_incarnation_king_of_the_jungle");
INSERT INTO spell_script_names VALUE (102558, "spell_dru_incarnation_guardian_of_ursoc");
INSERT INTO spell_script_names VALUE (102383, "spell_dru_wild_charge_moonkin");
INSERT INTO spell_script_names VALUE (8921, "spell_dru_moonfire");
INSERT INTO spell_script_names VALUE (113043, "spell_dru_omen_of_clarity");
INSERT INTO spell_script_names VALUE (768, "spell_dru_cat_form");
INSERT INTO spell_script_names VALUE (5487, "spell_dru_bear_form");
INSERT INTO spell_script_names VALUE (106839, "spell_dru_skull_bash");
INSERT INTO spell_script_names VALUE (106898, "spell_dru_stampeding_roar");
#INSERT INTO spell_script_names VALUE (, "spell_dru_activate_cat_form");
INSERT INTO spell_script_names VALUE (108299, "spell_dru_killer_instinct");
INSERT INTO spell_script_names VALUE (48500, "spell_dru_living_seed");
INSERT INTO spell_script_names VALUE (48484, "spell_dru_infected_wound");
INSERT INTO spell_script_names VALUE (145108, "spell_dru_ysera_gift");
INSERT INTO spell_script_names VALUE (1822, "spell_dru_rake");
INSERT INTO spell_script_names VALUE (22570, "spell_dru_maim");
INSERT INTO spell_script_names VALUE (1079, "spell_dru_rip");
INSERT INTO spell_script_names VALUE (155672, "spell_dru_bloodtalons");
INSERT INTO spell_script_names VALUE (783, "spell_dru_travel_form");
INSERT INTO spell_script_names VALUE (783, "spell_dru_travel_form_aura");

    // AreaTrigger Scripts
UPDATE `areatrigger_template` SET scriptname = "at_dru_solar_beam" WHERE id = 983;
UPDATE `areatrigger_template` SET scriptname = "at_dru_starfall" WHERE id = 4756;
UPDATE `areatrigger_template` SET scriptname = "at_dru_ursols_vortex" WHERE id = 314;

    // NPC Scripts
UPDATE creature_template SET scriptname = "npc_dru_efflorescence" WHERE entry = 47649;