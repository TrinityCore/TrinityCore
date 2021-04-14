-- Coin operated crowd pummeler
update creature_template set scriptname='bfa_boss_coin_operated_crowd_pummeler' where entry=129214;
update creature_template set scriptname='bfa_npc_azerite_bomb' where entry=129246;

replace into spell_script_names values (256163,'bfa_spell_blazing_azerite');
replace into spell_script_names values (269493,'bfa_spell_footbomb_launcher');
replace into spell_script_names values (271903,'bfa_spell_coin_magnet');

-- Azerokk
update creature_template set scriptname='bfa_boss_azerokk' where entry=129227;
update creature_template set scriptname='bfa_npc_earthrager' where entry=129802;
update creature_template set scriptname='bfa_npc_fracking_totem' where entry=136500;
update creature_template set scriptname='bfa_npc_fracking_totem_selector' where entry=129804;

replace into spell_script_names values (257480,'bfa_spell_fracking_totem_summon');

-- Rixxa
replace INTO areatrigger_template VALUES (12208, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);
replace INTO areatrigger_scripts VALUES (12208, '');
replace INTO spell_areatrigger VALUES (12208, 12208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- Mogul Razdunk
update creature_template set scriptname='bfa_boss_mogul_razdunk' where entry=129232;
update creature_template set scriptname='bfa_npc_boomba' where entry=141303;
update creature_template set scriptname='bfa_npc_homing_missile' where entry=132338;
update creature_template set scriptname='bfa_npc_venture_skyscorcher' where entry=133436;

replace into spell_script_names values (260280,'bfa_spell_gatling_gun');