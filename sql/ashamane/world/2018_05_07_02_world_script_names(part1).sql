UPDATE `areatrigger` SET `ScriptName`='' WHERE  `guid`=33;

UPDATE `areatrigger_scripts` SET `ScriptName`='' WHERE  `entry` IN (7998,8355,9998,9999,10276,10277,10094,6444,6625,6626,6627,6437,6312,6442,10158,10314,6955,7881,5628,5630,5623,4853,10154,10153,10165,5140,6613,6274,6275,6276,6277,6278,6279,6280,6290,5873,5834,6646,10280,522,8366);

UPDATE `areatrigger_template` SET `ScriptName`='' WHERE  `Id` IN (6022,7214,149959,150050,151582,167465);

UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry` IN (21727,21725,15170,15171,2058,19998,20334,21296,21975,8531,8532,10385,580875,2000000,83673,90283,85997,859977,84170,583578,89021,89022,99655,99654,99657,90282,99658,77947,277947,77950,277950,2870,73400,59390,200502,200501,81864,81819,49176,76266,56717,767977,62442,287218,87218,76197,75927,275927,275839,75839,76177,276177,277734,77734,79511,279511,279510,76260,79510,77905,279507,79507,76259,77134,277134,77042,277042,277133,77133,76263,277130,77130,77812,277812,277131,77131,77132,277132,325242,76572,76283,432626,76284,76296,77935,277935,277890,77890,77889,341634,76655,77810,277810,279248,79248,80816,60586,60585,9031,76141,876141,276141,43688,14515,76865,1678491,1578491,78491,79912,69427,81252,68036,42179,760410,760710,60410,43687,60009,24245,76814,81305,76809,76974,15114,60143,762164,662164,562164,462164,62164,60051,60047,60043,59915,9027,86231,9028,76877,14834,76973,76806,69132,769132,669132,569132,469132,876266,276266,7626656717,768476,68476,71543,1677428,1577428,77428,68078,14517,669712,569712,469712,69712,60400,60399,760399,660400,660399,560400,560399,760400,460400,460399,69465,769465,11380,86217,78714,1578714,1678714,69134,769134,669134,569134,469134,669131,569131,469131,69131,24247,1679015,1579015,79015,77692,18338,76021,62983,34071,24243,68905,80805,14510,68065,70252,70251,70250,70229,70248,70247,70235,70212,80808,276407,76407,75829,275829,76413,77182,79852,69017,60583,76585,275964,75964,83746,87493,76143,876143,276143,275509,60999,62837,662837,562837,462837,83612,760709,760708,760701,60710,60709,60708,60701,60984,60089,68904,69078,769078,669078,569078,469078,81535,62543,762543,662543,562543,462543,80557,80551,78948,1580557,1680557,1578948,1678948,1580551,1680551,43689,1677404,1577404,77404,14509,
32865,24241,67977,42180,762442,78237,1678237,1578237,1678238,1578238,78238,662511,562511,462511,62511,69374,77120,62397,762397,662397,562397,462397,59479,62980,65174,65173,762980,662980,562980,462890,19750,28965,28961,28585,20061,45979,25467);

UPDATE `criteria_data` SET `ScriptName`='' WHERE  `criteria_id` IN (10568,10570);

UPDATE `gameobject_template` SET `ScriptName`='' WHERE  `entry` IN (231736,231737,231739,231740,231741,231742,231743,130511,211584,218723,203133,203136,186287,194912,194914,194438,194437,211626,211650,211674,177243,177365,177366,177367,177368,177369,177397,177398,177399,177400,101833,164957,209318,184073,218543,179552,233757,233758,237308,231313,188141,236916,237720,237191,237722,237723,237724,236906,236911,236910,236912,236765,236774,236908,233172,233173,239314,230764,233832,235704,235773,235790,235885,235886,235892,235913,236403,236420,236639,236640,236642,236646,236648,236651,236685,237027,237063,237067,237068,237102,237103,237123,237133,237139,237181,237355,237913,238761,239237,239238,240601,240602,233900,234095,234146,235078,186491,186492,186493,186494,186495,186496,186497,186498,186499,186500,186501,186502,186503,186504,186505,186507,186508,186509,186510,186511,186512,186513,186514,186515,186516,186517,186518,186798,186883,186895,186907,186908,186909,186910,186911,186923,186924,186929,186930,180526,181606,204979,192175,192176,192177,203187,233098,231770,231776,218667,190767,211628,176581,188173,186490,216057,216058,183770,183956,184311,184312,176594,104593,232541,232542,232543,232544,232545,235376,235387,235388,235389,235390,235391,188498,187578,164955,176195,205273,209081,205272,209080,207690,186267,186269,182052,187359,207691,179148,194264,184729,227011,194398,194399,194400,194401,194402,194403,194404,194405,194406,194407,194408,194409,194410,194411,194412,194413,194414,194415,194506,164956,234186,201580,201581,201811,201812,194569);

UPDATE `instance_template` SET `script`='' WHERE  `map` IN (1182,1205,1158,1331,1159,1152,1330,1153,1009,1448,1228,1195,1008,1277,1136,1209,996,1098,1358);

UPDATE `quest_template_addon` SET `ScriptName`='' WHERE  `ID` IN (41217,31135);

UPDATE `scene_template` SET `ScriptName`='' WHERE  `SceneId` IN (1141,1116);

UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=61882 AND `ScriptName`='aura_sha_earthquake';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=88286 AND `ScriptName`='spell_altairus_downwind_of_altairus';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=88282 AND `ScriptName`='spell_altairus_upwind_of_altairus';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=76904 AND `ScriptName`='spell_anraphet_alpha_beams';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=77106 AND `ScriptName`='spell_anraphet_omega_stance_summon';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=200653 AND `ScriptName`='spell_arti_pal_tyr_deliverance';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=87553 AND `ScriptName`='spell_asaad_grounding_damage';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=87474 AND `ScriptName`='spell_asaad_grounding_field';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=87518 AND `ScriptName`='spell_asaad_supremacy_of_the_storm_summon';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43450 AND `ScriptName`='spell_brewfest_apple_trap';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43259 AND `ScriptName`='spell_brewfest_barker_bunny';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43260 AND `ScriptName`='spell_brewfest_barker_bunny';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43261 AND `ScriptName`='spell_brewfest_barker_bunny';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43262 AND `ScriptName`='spell_brewfest_barker_bunny';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43876 AND `ScriptName`='spell_brewfest_dismount_ram';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43332 AND `ScriptName`='spell_brewfest_exhausted_ram';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=42924 AND `ScriptName`='spell_brewfest_giddyup';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=42992 AND `ScriptName`='spell_brewfest_ram';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=42993 AND `ScriptName`='spell_brewfest_ram';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=42994 AND `ScriptName`='spell_brewfest_ram';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43310 AND `ScriptName`='spell_brewfest_ram';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43052 AND `ScriptName`='spell_brewfest_ram_fatigue';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=43714 AND `ScriptName`='spell_brewfest_relay_race_intro_force_player_to_throw';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=92067 AND `ScriptName`='spell_council_static_overload';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=70903 AND `ScriptName`='spell_cultist_dark_martyrdom';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=71236 AND `ScriptName`='spell_cultist_dark_martyrdom';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=201467 AND `ScriptName`='spell_dh_fury_of_the_illidari';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=37336 AND `ScriptName`='spell_dru_forms_trinket';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=783 AND `ScriptName`='spell_dru_travel_form_aura';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=86284 AND `ScriptName`='spell_ertan_storms_edge';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=86310 AND `ScriptName`='spell_ertan_storms_edge_knockback';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=86299 AND `ScriptName`='spell_ertan_storms_edge_triggered';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=86311 AND `ScriptName`='spell_ertan_storms_edge_triggered';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=91872 AND `ScriptName`='spell_gathered_storms_trigger_cast';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=91871 AND `ScriptName`='spell_gathered_storms_trigger_cast';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=105367 AND `ScriptName`='spell_hagara_the_stormbinder_crystal_conduit_target';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=105316 AND `ScriptName`='spell_hagara_the_stormbinder_ice_lance_dmg';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=105314 AND `ScriptName`='spell_hagara_the_stormbinder_icewave_dmg';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24930 AND `ScriptName`='spell_hallow_end_candy';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24926 AND `ScriptName`='spell_hallow_end_candy_pirate';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24750 AND `ScriptName`='spell_hallow_end_trick';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=44436 AND `ScriptName`='spell_hallow_end_tricky_treat';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24751 AND `ScriptName`='spell_hallow_end_trick_or_treat';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24717 AND `ScriptName`='spell_hallow_end_wand';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24718 AND `ScriptName`='spell_hallow_end_wand';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24719 AND `ScriptName`='spell_hallow_end_wand';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24720 AND `ScriptName`='spell_hallow_end_wand';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24724 AND `ScriptName`='spell_hallow_end_wand';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24733 AND `ScriptName`='spell_hallow_end_wand';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24737 AND `ScriptName`='spell_hallow_end_wand';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=24741 AND `ScriptName`='spell_hallow_end_wand';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=67151 AND `ScriptName`='spell_hun_t9_4p_bonus';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=29602 AND `ScriptName`='spell_item_jom_gabbar';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=108601 AND `ScriptName`='spell_madness_of_deathwing_corrupting_parasite_dmg';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=2120 AND `ScriptName`='spell_mage_flamestrike';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=118 AND `ScriptName`='spell_mage_polymorph';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=56377 AND `ScriptName`='spell_mage_splitting_ice';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=200255 AND `ScriptName`='spell_mardum_felsaber_gift';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=45724 AND `ScriptName`='spell_midsummer_braziers_hit';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=63274 AND `ScriptName`='spell_mimiron_p3wx2_laser_barrage';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=63414 AND `ScriptName`='spell_mimiron_spinning_up';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=77127 AND `ScriptName`='spell_omega_stance_spider_effect';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=72752 AND `ScriptName`='spell_pvp_trinket_wotf_shared_cd';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=72757 AND `ScriptName`='spell_pvp_trinket_wotf_shared_cd';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=70805 AND `ScriptName`='spell_rog_t10_2p_bonus';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=73920 AND `ScriptName`='spell_sha_healing_rain';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=215864 AND `ScriptName`='spell_sha_rainfall';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=7057 AND `ScriptName`='spell_shadowfang_keep_haunting_spirits';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=106108 AND `ScriptName`='spell_ultraxion_heroic_will';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=18499 AND `ScriptName`='spell_warr_berzerker_rage';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=12292 AND `ScriptName`='spell_warr_bloodbath';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=845 AND `ScriptName`='spell_warr_cleave';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=97462 AND `ScriptName`='spell_warr_commanding_shoot';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=184362 AND `ScriptName`='spell_warr_enrage_trigger';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=5308 AND `ScriptName`='spell_warr_execute_fury';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=100130 AND `ScriptName`='spell_warr_furious_slash';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=52174 AND `ScriptName`='spell_warr_heroic_leap_damage';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=215550 AND `ScriptName`='spell_warr_in_for_the_kill';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=203179 AND `ScriptName`='spell_warr_opportunity_strikes';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=29838 AND `ScriptName`='spell_warr_second_wind';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=32215 AND `ScriptName`='spell_warr_victorious_state';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=1680 AND `ScriptName`='spell_warr_whirlwind_arms';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=190411 AND `ScriptName`='spell_warr_whirlwind_fury';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=26275 AND `ScriptName`='spell_winter_veil_px_238_winter_wondervolt';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=109894 AND `ScriptName`='spell_yorsahj_the_unsleeping_whisper';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=109895 AND `ScriptName`='spell_yorsahj_the_unsleeping_whisper';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=109896 AND `ScriptName`='spell_yorsahj_the_unsleeping_whisper';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=109897 AND `ScriptName`='spell_yorsahj_the_unsleeping_whisper';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=109898 AND `ScriptName`='spell_yorsahj_the_unsleeping_whisper';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=106199 AND `ScriptName`='spine_of_deathwing_blood_corruption';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=106200 AND `ScriptName`='spine_of_deathwing_blood_corruption';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=105777 AND `ScriptName`='spine_of_deathwing_roll_control';
UPDATE `spell_script_names` SET `ScriptName`='' WHERE  `spell_id`=60503 AND `ScriptName`='spell_warrior_overpower_proc';

DELETE FROM `spell_script_names` WHERE  `spell_id`=18499 AND `ScriptName`='spell_warr_berserker_rage';

