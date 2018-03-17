UPDATE `creature_template` SET `difficulty_entry_1`= 49262, `mechanic_immune_mask`= 80297855 WHERE `entry`= 39425;

UPDATE `creature_template` SET `exp`= 3, `unit_class`= 2 WHERE `entry` IN (48902, 48710, 48776);
UPDATE `creature_template` SET `exp`= 3, `unit_class`= 4 WHERE `entry` IN (48715);
UPDATE `creature_template` SET `faction`= 17 WHERE `entry`= 49241;

DELETE FROM `creature_loot_template` WHERE `Entry`= 65168;
UPDATE `creature_loot_template` SET `Chance`= 100.0, `QuestRequired`= 1 WHERE `Item` IN
(60885, 60878, 60880, 60879, 60876, 60881, 60877, 60882);

UPDATE `spell_script_names` SET `spell_id`= 53290 WHERE `spell_id`= -53290;
UPDATE `spell_script_names` SET `spell_id`= 54747 WHERE `spell_id`= -54747;
UPDATE `spell_script_names` SET `spell_id`= 51627 WHERE `spell_id`= -51627;
UPDATE `spell_script_names` SET `spell_id`= 51474 WHERE `spell_id`= -51474;
UPDATE `spell_script_names` SET `spell_id`= 31876 WHERE `spell_id`= -31876;
UPDATE `spell_script_names` SET `spell_id`= 31661 WHERE `spell_id`= -31661;
UPDATE `spell_script_names` SET `spell_id`= 31656 WHERE `spell_id`= -31656;
UPDATE `spell_script_names` SET `spell_id`= 31244 WHERE `spell_id`= -31244;
UPDATE `spell_script_names` SET `spell_id`= 30675 WHERE `spell_id`= -30675;
UPDATE `spell_script_names` SET `spell_id`= 29441 WHERE `spell_id`= -29441;
UPDATE `spell_script_names` SET `spell_id`= 27243 WHERE `spell_id`= -27243;
UPDATE `spell_script_names` SET `spell_id`= 27243 WHERE `spell_id`= -27243;


DELETE FROM `spell_script_names` WHERE `spell_id` IN
(54748, 59088, 54639, 53501, 49467, 49217, 49208, 49015, 31871, 31785, 20335, 18213, 15337, 20185, 20186, 20375, 21084, 31892, 44401, 49005, 51209, 53601, 53720, 53736, 54748, 54909, 58914, 70827, 74396);

UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'boss_mr_smite';
UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'npc_shadowfang_prisoner';
UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'npc_lunaclaw_spirit';
UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'boss_archmage_arugal';
UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'npc_yenniku';
UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'npc_arugal_voidwalker';
UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'npcs_dithers_and_arbington';
UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName`= 'npc_lazy_peon';

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_sha_shamanistic_rage',
'spell_dk_rime',
'spell_warr_second_wind',
'spell_dru_glyph_of_rejuvenation',
'spell_dru_glyph_of_rake',
'spell_warr_item_t10_prot_4p_bonus',
'spell_dk_glyph_of_scourge_strike',
'spell_mage_magic_absorption',
'spell_sha_t3_6p_bonus',
'spell_dru_t10_balance_4p_bonus',
'spell_dru_t10_restoration_4p_bonus_dummy',
'spell_hun_glyph_of_mend_pet',
'spell_dk_unholy_blight',
'spell_pri_imp_shadowform',
'spell_dk_mark_of_blood',
'spell_pal_spiritual_attunement',
'spell_rog_turn_the_tables_proc',
'spell_pri_mana_burn',
'spell_dk_glyph_of_death_grip',
'spell_dru_item_t6_trinket',
'spell_dru_t3_6p_bonus',
'spell_dru_omen_of_clarity',
'spell_pri_t10_heal_2p_bonus',
'spell_sha_glyph_of_earth_shield',
'spell_pri_improved_spirit_tap',
'spell_pal_judgements_of_the_wise',
'spell_dk_hungering_cold',
'spell_dk_death_rune',
'spell_sha_t9_elemental_4p_bonus',
'spell_dru_leader_of_the_pack',
'spell_dk_vendetta',
'spell_pal_glyph_of_divinity',
'spell_sha_t10_restoration_4p_bonus',
'spell_warr_t3_prot_8p_bonus',
'spell_mage_burning_determination',
'spell_dk_blade_barrier',
'spell_pal_sacred_shield_dummy',
'spell_mage_imp_blizzard',
'spell_dru_t3_2p_bonus',
'spell_hun_rapid_recuperation_trigger',
'spell_dk_wandering_plague',
'spell_dru_t4_2p_bonus',
'spell_sha_frozen_power',
'spell_dru_glyph_of_shred',
'spell_warr_glyph_of_blocking',
'spell_dk_dancing_rune_weapon',
'spell_dk_necrosis',
'spell_dk_pvp_4p_bonus',
'spell_dk_scent_of_blood_trigger',
'spell_dk_sudden_doom',
'spell_dk_threat_of_thassarian',
'spell_wotf_shared_cd',
'spell_dru_glyph_of_starfire_dummy',
'spell_dru_revitalize',
'spell_mage_gen_extra_effects',
'spell_dru_t3_8p_bonus',
'spell_rog_setup',
'spell_warl_seed_of_corruption_generic',
'spell_warl_t4_2p_bonus_fire',
'spell_howling_gale',
'spell_hun_hunting_party',
'spell_hun_kill_command_pet',
'spell_hun_roar_of_sacrifice',
'spell_husam_hurl_vehicle',
'spell_pal_judgement_of_wisdom_mana',
'spell_warl_t4_2p_bonus_shadow',
'spell_rog_deadly_brew',
'spell_mage_combustion',
'spell_mage_empowered_fire',
'spell_mage_fingers_of_frost',
'spell_mage_imp_mana_gems',
'spell_mage_missile_barrage',
'spell_sha_imp_water_shield',
'spell_sha_spirit_hunt',
'spell_pal_item_t6_trinket',
'spell_pal_divine_purpose',
'spell_pal_glyph_of_holy_light_dummy',
'spell_pri_aq_3p_bonus',
'spell_pal_heart_of_the_crusader',
'spell_pal_improved_lay_of_hands',
'spell_pal_infusion_of_light',
'spell_pal_judgement_of_light_heal',
'spell_pal_judgements_of_the_just',
'spell_pal_righteous_vengeance',
'spell_pal_seal_of_corruption',
'spell_pal_seal_of_vengeance',
'spell_pal_seals',
'spell_pal_sheath_of_light',
'spell_pal_t3_6p_bonus',
'spell_pal_t8_2p_bonus',
'spell_sha_t10_elemental_4p_bonus',
'spell_pri_glyph_of_dispel_magic',
'spell_pri_item_t6_trinket',
'spell_pri_shadowfiend_death',
'spell_pri_t3_4p_bonus',
'spell_pri_t5_heal_2p_bonus',
'spell_sha_astral_shift_aura',
'spell_rog_glyph_of_backstab',
'spell_rog_quick_recovery',
'spell_rog_turn_the_tables',
'spell_sha_flametongue_weapon',
'spell_sha_glyph_of_totem_of_wrath',
'spell_sha_item_t6_trinket',
'spell_sha_lightning_overload',
'spell_sha_maelstrom_weapon',
'spell_sha_static_shock',
'spell_sha_t8_elemental_4p_bonus',
'spell_sha_tidal_force_dummy',
'spell_sha_windfury_weapon',
'spell_shadowfang_keep_haunting_spirits',
'spell_uk_second_wind_proc',
'spell_warl_decimation',
'spell_warl_demonic_pact',
'spell_warl_glyph_of_corruption_nightfall',
'spell_warl_glyph_of_life_tap',
'spell_warl_improved_drain_soul',
'spell_warl_seed_of_corruption_dummy',
'spell_warr_deep_wounds_aura',
'spell_warr_extra_proc',
'spell_warr_vigilance_redirect_threat');

