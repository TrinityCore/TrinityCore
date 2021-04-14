-- anubesset 
update creature_template set scriptname='boss_anubesset' where entry=102246;
update creature_template set scriptname='npc_anubesset_spitting_scarab' where entry=102271;
update creature_template set scriptname='npc_anubesset_blistering_beetle' where entry=102540;

replace into spell_script_names values (202353,'spell_anubesset_impale_filter');

-- blood princess
update creature_template set scriptname='boss_blood_princess_thalena' where entry=102431;
update creature_template set scriptname='npc_thalena_pool_of_blood' where entry=102659;
update creature_template set scriptname='npc_thalena_congealed_blood' where entry=102941;

replace into spell_script_names values (203035,'spell_thalena_shroud_of_sorrow');
replace into spell_script_names values (202805,'spell_thalena_vampiric_bite');
replace into spell_script_names values (202792,'spell_thalena_frenzied_bloodthirst');

-- fel lord betrug
update creature_template set scriptname='boss_fel_lord_betrug' where entry=102446;
update creature_template set scriptname='npc_betrug_stasis_crystal' where entry=103672;

replace into spell_script_names values (202328,'spell_betrug_mighty_smash');
replace into spell_script_names values (210879,'spell_betrug_seed_of_destruction');

-- festerface
update creature_template set scriptname='npc_festerface_congealed_goo' where entry=102158;
update creature_template set scriptname='boss_festerface' where entry=101995;

replace into spell_script_names values (201598,'spell_festerface_congealing_vomit');
replace into spell_script_names values (201495,'spell_festerface_recongealing');
replace into spell_script_names values (207677,'spell_festerface_energy_tracker');

-- millificient manastorm
update creature_template set scriptname='boss_millificent_manastorm' where entry=101976;
update creature_template set scriptname='npc_millificent_elementium_squirrel_bomb' where entry in (102136,102043);
update creature_template set scriptname='npc_millificent_thorium_rocket_chicken' where entry in (102139,102103);
update creature_template set scriptname='npc_millificent_mechanical_bomb_squirrel' where entry=102137;

-- mind flayer kaarshj
update creature_template set scriptname='boss_mindflayer_kaahrj' where entry=101950;
update creature_template set scriptname='npc_kaahrj_faceless_tendril' where entry=101994;

-- saelorn
update creature_template set scriptname='boss_saelorn' where entry=102387;
update creature_template set scriptname='npc_saelorn_phase_spider' where entry=102434;

-- shivermaw
update creature_template set scriptname='boss_shivermaw' where entry=101951;
update creature_template set scriptname='npc_shivermaw_ice_block' where entry=102301;