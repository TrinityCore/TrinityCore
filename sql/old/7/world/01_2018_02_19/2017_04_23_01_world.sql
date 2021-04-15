DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (15290);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 15290, 0, 0, 33, 0, 1, 0, 0, 1, 0, 0, '', 'Spell Vampiric Embrace (effect 0) will hit the potential target of the spell if target is not the same as condition target.');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceGroup`=0 AND `SourceEntry` IN (38164,70805);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(24, 0, 38164, 0, 0, 31, 1, 3, 19457, 0, 0, 0, 0, '', 'Spell Unyielding Knights can proc on actionTarget if target is unit Grillok "Darkeye".'),
(24, 0, 70805, 0, 0, 33, 1, 0,     0, 0, 1, 0, 0, '', 'Spell Item - Rogue T10 2P Bonus can proc on actionTarget if target is not the same as condition target.');

-- Remove renamed scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_dummy_trigger','spell_pri_item_greater_heal_refund');

-- Add spellscripts to spells previously on giant switches in Unit.cpp
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_savage_defense';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_rapid_recuperation';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_thrill_of_the_hunt';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_alchemist_stone';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_totem_of_flowing_water';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_arcane_potency';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_glyph_of_ice_block';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rog_cut_to_the_chase';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_rog_t10_2p_bonus';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_shadow_trance_proc';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_improved_spell_reflection';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_uk_second_wind_proc';

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_anetheron_vampiric_aura',
'spell_deathbringer_blood_beast_blood_link',
'spell_putricide_ooze_tank_protection',
'spell_xt002_321_boombot_aura',
'spell_mark_of_malice',
'spell_twisted_reflection',
'spell_dk_dancing_rune_weapon','spell_dk_mark_of_blood','spell_dk_necrosis','spell_dk_pvp_4p_bonus',
'spell_dru_omen_of_clarity','spell_dru_t3_6p_bonus','spell_dru_t3_8p_bonus','spell_dru_t4_2p_bonus','spell_dru_item_t6_trinket','spell_dru_t10_balance_4p_bonus','spell_dru_t10_restoration_4p_bonus_dummy',
'spell_gen_vampiric_touch',
'spell_hun_hunting_party',
'spell_item_alchemist_stone','spell_item_tiny_abomination_in_a_jar','spell_item_tiny_abomination_in_a_jar_hero','spell_item_aura_of_madness','spell_item_dementia','spell_item_deadly_precision','spell_item_deadly_precision_dummy','spell_item_deathbringers_will_normal','spell_item_deathbringers_will_heroic','spell_item_discerning_eye_beast_dummy','spell_item_frozen_shadoweave','spell_item_heartpierce','spell_item_heartpierce_hero','spell_item_crystal_spire_of_karabor','spell_item_mark_of_conquest','spell_item_pendant_of_the_violet_eye','spell_item_persistent_shield','spell_item_pet_healing','spell_item_swift_hand_justice_dummy','spell_item_purified_shard_of_the_scale','spell_item_shiny_shard_of_the_scale','spell_item_sunwell_exalted_caster_neck','spell_item_sunwell_exalted_melee_neck','spell_item_sunwell_exalted_tank_neck','spell_item_sunwell_exalted_healer_neck','spell_item_unstable_power','spell_item_restless_strength','spell_item_soul_harvesters_charm','spell_item_commendation_of_kaelthas','spell_item_corpse_tongue_coin','spell_item_corpse_tongue_coin_heroic','spell_item_petrified_twilight_scale','spell_item_petrified_twilight_scale_heroic',
'spell_mage_burning_determination','spell_mage_hot_streak','spell_mage_imp_mana_gems',
'spell_pal_item_t6_trinket','spell_pal_t3_6p_bonus','spell_pal_t8_2p_bonus',
'spell_pri_aq_3p_bonus','spell_pri_item_t6_trinket','spell_pri_t3_4p_bonus','spell_pri_t5_heal_2p_bonus','spell_pri_t10_heal_2p_bonus',
'spell_sha_item_t6_trinket','spell_sha_t3_6p_bonus','spell_sha_t8_elemental_4p_bonus','spell_sha_t9_elemental_4p_bonus','spell_sha_t10_elemental_4p_bonus','spell_sha_t10_restoration_4p_bonus',
'spell_warl_seed_of_corruption_dummy','spell_warl_seed_of_corruption_generic','spell_warl_t4_2p_bonus_shadow','spell_warl_t4_2p_bonus_fire',
'spell_warr_item_t10_prot_4p_bonus','spell_warr_t3_prot_8p_bonus',
'spell_uk_second_wind'
);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38196,  'spell_anetheron_vampiric_aura'),
(72176,  'spell_deathbringer_blood_beast_blood_link'),
(71770,  'spell_putricide_ooze_tank_protection'),
(65032,  'spell_xt002_321_boombot_aura'),
(33493,  'spell_mark_of_malice'),
(21063,  'spell_twisted_reflection'),

(49028,  'spell_dk_dancing_rune_weapon'),
(206940, 'spell_dk_mark_of_blood'),
(207346, 'spell_dk_necrosis'),
(61257,  'spell_dk_pvp_4p_bonus'),

(16864,  'spell_dru_omen_of_clarity'),
(28744,  'spell_dru_t3_6p_bonus'),
(28719,  'spell_dru_t3_8p_bonus'),
(37288,  'spell_dru_t4_2p_bonus'),
(40442,  'spell_dru_item_t6_trinket'),
(70723,  'spell_dru_t10_balance_4p_bonus'),
(70664,  'spell_dru_t10_restoration_4p_bonus_dummy'),

(52723,  'spell_gen_vampiric_touch'),
(60501,  'spell_gen_vampiric_touch'),

(212658, 'spell_hun_hunting_party'),

(17619,  'spell_item_alchemist_stone'),
(71406,  'spell_item_tiny_abomination_in_a_jar'),
(71545,  'spell_item_tiny_abomination_in_a_jar_hero'),
(39446,  'spell_item_aura_of_madness'),
(41404,  'spell_item_dementia'),
(71563,  'spell_item_deadly_precision_dummy'),
(71564,  'spell_item_deadly_precision'),
(71519,  'spell_item_deathbringers_will_normal'),
(71562,  'spell_item_deathbringers_will_heroic'),
(59915,  'spell_item_discerning_eye_beast_dummy'),
(39372,  'spell_item_frozen_shadoweave'),
(71880,  'spell_item_heartpierce'),
(71892,  'spell_item_heartpierce_hero'),
(40971,  'spell_item_crystal_spire_of_karabor'),
(33510,  'spell_item_mark_of_conquest'),
(29601,  'spell_item_pendant_of_the_violet_eye'),
(26467,  'spell_item_persistent_shield'),
(37381,  'spell_item_pet_healing'),
(59906,  'spell_item_swift_hand_justice_dummy'),
(69755,  'spell_item_purified_shard_of_the_scale'),
(69739,  'spell_item_shiny_shard_of_the_scale'),
(45481,  'spell_item_sunwell_exalted_caster_neck'),
(45482,  'spell_item_sunwell_exalted_melee_neck'),
(45483,  'spell_item_sunwell_exalted_tank_neck'),
(45484,  'spell_item_sunwell_exalted_healer_neck'),
(24658,  'spell_item_unstable_power'),
(24661,  'spell_item_restless_strength'),
(52420,  'spell_item_soul_harvesters_charm'),
(45057,  'spell_item_commendation_of_kaelthas'),
(71634,  'spell_item_corpse_tongue_coin'),
(71640,  'spell_item_corpse_tongue_coin_heroic'),
(75475,  'spell_item_petrified_twilight_scale'),
(75481,  'spell_item_petrified_twilight_scale_heroic'),

(198063, 'spell_mage_burning_determination'),
(195283, 'spell_mage_hot_streak'),
(37447,  'spell_mage_imp_mana_gems'),
(61062,  'spell_mage_imp_mana_gems'),

(40470,  'spell_pal_item_t6_trinket'),
(28789,  'spell_pal_t3_6p_bonus'),
(64890,  'spell_pal_t8_2p_bonus'),

(26169,  'spell_pri_aq_3p_bonus'),
(40438,  'spell_pri_item_t6_trinket'),
(28809,  'spell_pri_t3_4p_bonus'),
(37594,  'spell_pri_t5_heal_2p_bonus'),
(70770,  'spell_pri_t10_heal_2p_bonus'),

(40463,  'spell_sha_item_t6_trinket'),
(28823,  'spell_sha_t3_6p_bonus'),
(64928,  'spell_sha_t8_elemental_4p_bonus'),
(67228,  'spell_sha_t9_elemental_4p_bonus'),
(70817,  'spell_sha_t10_elemental_4p_bonus'),
(70808,  'spell_sha_t10_restoration_4p_bonus'),

(27243,  'spell_warl_seed_of_corruption_dummy'),
(32863,  'spell_warl_seed_of_corruption_generic'),
(36123,  'spell_warl_seed_of_corruption_generic'),
(38252,  'spell_warl_seed_of_corruption_generic'),
(39367,  'spell_warl_seed_of_corruption_generic'),
(44141,  'spell_warl_seed_of_corruption_generic'),
(70388,  'spell_warl_seed_of_corruption_generic'),
(37377,  'spell_warl_t4_2p_bonus_shadow'),
(39437,  'spell_warl_t4_2p_bonus_fire'),

(70844,  'spell_warr_item_t10_prot_4p_bonus'),
(28845,  'spell_warr_t3_prot_8p_bonus'),

(42770,  'spell_uk_second_wind');
