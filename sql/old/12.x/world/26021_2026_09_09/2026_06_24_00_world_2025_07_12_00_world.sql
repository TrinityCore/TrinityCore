--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_scourging_crystal_controller' WHERE `ScriptName` = 'spell_q11396_11399_scourging_crystal_controller';
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_q11396_11399_scourging_crystal_controller_dummy','spell_q11396_11399_force_shield_arcane_purple_x3');

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24464 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24464,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourging Crystal - On AI Initialize - Set Reactstate Passive"),
(24464,0,1,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourging Crystal - On AI Initialize - Set Corpse Delay"),
(24464,0,2,0,8,0,100,0,43882,0,0,0,0,28,43874,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourging Crystal - On Spellhit 'Scourging Crystal Controller' - Remove Aura 'Scourge Mur'gul Camp: Force Shield Arcane Purple x3'"),
(24464,0,3,0,8,0,100,0,43882,0,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scourging Crystal - On Spellhit 'Scourging Crystal Controller' - Remove ImmunePC");

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_sholazar_despawn_fruit_tosser' WHERE `ScriptName` = 'spell_q12634_despawn_fruit_tosser';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_zuldrak_summon_stefan' WHERE `ScriptName` = 'spell_q12661_q12669_q12676_q12677_q12713_summon_stefan';

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q12659_ahunaes_knife';

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28465 AND `source_type` = 0 AND `id` IN (4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28600 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28600;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28465,0,4,0,8,0,100,0,52090,0,0,0,0,33,28622,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Heb'Drakkar Striker - On Spellhit 'Ahunae's Knife' - Quest Credit 'Scalps!'"),
(28465,0,5,0,8,0,100,0,52090,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Heb'Drakkar Striker - On Spellhit 'Ahunae's Knife' - Delayed Despawn"),

(28600,0,0,0,8,0,100,0,52090,0,0,0,0,33,28622,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Heb'Drakkar Headhunter - On Spellhit 'Ahunae's Knife' - Quest Credit 'Scalps!'"),
(28600,0,1,0,8,0,100,0,52090,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Heb'Drakkar Headhunter - On Spellhit 'Ahunae's Knife' - Delayed Despawn");

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_zuldrak_quenching_mist' WHERE `ScriptName` = 'spell_q12730_quenching_mist';

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q11515_fel_siphon_dummy';

DELETE FROM `smart_scripts` WHERE `entryorguid` = 24918 AND `source_type` = 0 AND `id` = 3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24918,0,3,0,8,0,100,0,44936,0,0,0,0,36,24955,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Felblood Initiate - On Spellhit 'Quest - Fel Siphon Dummy' - Update Template To 'Emaciated Felblood'");

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q10255_administer_antidote';

DELETE FROM `smart_scripts` WHERE `entryorguid` = 16880 AND `source_type` = 0 AND `id` = 4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16880,0,4,0,8,0,100,0,34665,0,0,0,0,36,16992,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hulking Helboar - On Spellhit 'Administer Antidote' - Update Template To 'Dreadtusk'");

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q55_sacred_cleansing';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_illidan_kill_credit_master' WHERE `ScriptName` = 'spell_q13400_illidan_kill_master';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_zuldrak_zuldrak_rat' WHERE `ScriptName` = 'spell_q12527_zuldrak_rat';

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q12066_bunny_kill_credit';

DELETE FROM `smart_scripts` WHERE `entryorguid` = 23837 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23837,0,2,0,8,0,100,0,50546,0,0,0,0,11,47390,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"ELM General Purpose Bunny - On Spellhit 'The Focus on the Beach: Ley Line Focus Control Ring Effect' - Cast 'The Focus on the Beach: Ley Line Focus Bunny Beam'");

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_plant_battle_standard' WHERE `ScriptName` = 'spell_q13280_13283_plant_battle_standard';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_jump_jets' WHERE `ScriptName` = 'spell_q13280_13283_jump_jets';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_grizzly_hills_escape_from_silverbrook' WHERE `ScriptName` = 'spell_q12308_escape_from_silverbrook';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_grizzly_hills_escape_from_silverbrook_summon_worgen' WHERE `ScriptName` = 'spell_q12308_escape_from_silverbrook_summon_worgen';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_grab_fake_soldier' WHERE `ScriptName` = 'spell_q13291_q13292_q13239_q13261_frostbrood_skytalon_grab_decoy';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_summon_frost_wyrm' WHERE `ScriptName` = 'spell_q13291_q13292_q13239_q13261_armored_decoy_summon_skytalon';

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25752 AND `source_type` = 0 AND `id` = 6;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25753 AND `source_type` = 0 AND `id` = 7;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25758 AND `source_type` = 0 AND `id` = 6;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25792 AND `source_type` = 0 AND `id` = 4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25752,0,6,0,7,0,100,0,0,0,0,0,0,11,46446,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scavenge-bot 004-A8 - On Evade - Cast 'Weakness to Lightning: Cancel Power of the Storm Aura'"),
(25753,0,7,0,7,0,100,0,0,0,0,0,0,11,46446,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry-bot 57-K - On Evade - Cast 'Weakness to Lightning: Cancel Power of the Storm Aura'"),
(25758,0,6,0,7,0,100,0,0,0,0,0,0,11,46446,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defendo-tank 66D - On Evade - Cast 'Weakness to Lightning: Cancel Power of the Storm Aura'"),
(25792,0,4,0,7,0,100,0,0,0,0,0,0,11,46446,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scavenge-bot 005-B6 - On Evade - Cast 'Weakness to Lightning: Cancel Power of the Storm Aura'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_borean_tundra_weakness_to_lightning_cancel_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46446, 'spell_borean_tundra_weakness_to_lightning_cancel_aura');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_borean_tundra_weakness_to_lightning_cast_on_master' WHERE `ScriptName` = 'spell_q11896_weakness_to_lightning_46444';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_sholazar_lifeblood_dummy' WHERE `ScriptName` = 'spell_q12805_lifeblood_dummy';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_storm_peaks_flaming_arrow_triggered_effect' WHERE `ScriptName` = 'spell_q12851_going_bearback';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_eastern_kingdoms_thaumaturgy_channel' WHERE `ScriptName` = 'spell_q2203_thaumaturgy_channel';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_summon_soul_moveto_bunny' WHERE `ScriptName` = 'spell_q12847_summon_soul_moveto_bunny';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_cannons_target' WHERE `ScriptName` = 'spell_q13086_cannons_target';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_mixing_blood' WHERE `ScriptName` = 'spell_q11306_mixing_blood';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_mixing_vrykul_blood' WHERE `ScriptName` = 'spell_q11306_mixing_vrykul_blood';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_failed_mix_concoction_1' WHERE `ScriptName` = 'spell_q11306_failed_mix_43376';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_failed_mix_concoction_2' WHERE `ScriptName` = 'spell_q11306_failed_mix_43378';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_grizzly_hills_hand_over_reins' WHERE `ScriptName` = 'spell_q12414_hand_over_reins';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_bested_trigger' WHERE `ScriptName` = 'spell_q13665_q13790_bested_trigger';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_chapter1_siphon_of_acherus' WHERE `ScriptName` = 'spell_q12641_death_comes_from_on_high';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_chapter1_recall_eye_of_acherus' WHERE `ScriptName` = 'spell_q12641_recall_eye_of_acherus';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_chapter1_emblazon_runeblade' WHERE `ScriptName` = 'spell_q12619_emblazon_runeblade';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_chapter1_emblazon_runeblade_effect' WHERE `ScriptName` = 'spell_q12619_emblazon_runeblade_effect';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_quest_make_player_destroy_totems' WHERE `ScriptName` = 'spell_q14100_q14111_make_player_destroy_totems';

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q12459_seeds_of_natures_wrath';

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26841 AND `source_type` = 0 AND `id` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27808 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27122 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26841,0,1,0,8,0,100,0,49587,0,0,0,0,36,27821,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Reanimated Frost Wyrm - On Spellhit 'Seeds of Nature's Wrath' - Update Template To 'Weakened Reanimated Frost Wyrm'"),
(27808,0,2,0,8,0,100,0,49587,0,0,0,0,36,27809,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Turgid the Vile - On Spellhit 'Seeds of Nature's Wrath' - Update Template To 'Weakened Turgid the Vile'"),
(27122,0,2,0,8,0,100,0,49587,0,0,0,0,36,27807,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Overseer Deathgaze - On Spellhit 'Seeds of Nature's Wrath' - Update Template To 'Weakened Overseer Deathgaze'");

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_dragonblight_defending_wyrmrest_temple_cast_from_gossip' WHERE `ScriptName` = 'spell_q12372_cast_from_gossip_trigger';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_dragonblight_defending_wyrmrest_temple_dummy' WHERE `ScriptName` = 'spell_q12372_destabilize_azure_dragonshrine_dummy';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_borean_tundra_ultrasonic_screwdriver' WHERE `ScriptName` = 'spell_q11730_ultrasonic_screwdriver';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_zuldrak_gymers_grab' WHERE `ScriptName` = 'spell_q12919_gymers_grab';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_zuldrak_gymers_throw' WHERE `ScriptName` = 'spell_q12919_gymers_throw';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_bem_aggro_check_aura' WHERE `ScriptName` = 'spell_q11010_q11102_q11023_aggro_check_aura';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_bem_aggro_check' WHERE `ScriptName` = 'spell_q11010_q11102_q11023_aggro_check';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_bem_aggro_burst' WHERE `ScriptName` = 'spell_q11010_q11102_q11023_aggro_burst';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_bem_choose_loc' WHERE `ScriptName` = 'spell_q11010_q11102_q11023_choose_loc';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_bem_check_fly_mount' WHERE `ScriptName` = 'spell_q11010_q11102_q11023_q11008_check_fly_mount';

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_burst_at_the_seams_59576' WHERE `ScriptName` = 'spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59576';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_burst_at_the_seams_59579' WHERE `ScriptName` = 'spell_q13264_q13276_q13288_q13289_burst_at_the_seams_59579';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_bloated_abom_feign_death' WHERE `ScriptName` = 'spell_q13264_q13276_q13288_q13289_bloated_abom_feign_death';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_area_restrict_abom' WHERE `ScriptName` = 'spell_q13264_q13276_q13288_q13289_area_restrict_abom';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_assign_credit_to_master' WHERE `ScriptName` = 'spell_q13264_q13276_q13288_q13289_assign_credit_to_master';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_icecrown_burst_at_the_seams_52510' WHERE `ScriptName` = 'spell_q12690_burst_at_the_seams_52510';

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_q6124_6129_apply_salve';

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (12296,12298);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (12296,12298) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1229600,1229800) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12296,0,0,0,8,0,100,0,19512,0,0,0,0,80,1229600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Gazelle - On Spellhit 'Apply Salve' - Run Action List"),
(12298,0,0,0,8,0,100,0,19512,0,0,0,0,80,1229800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Deer - On Spellhit 'Apply Salve' - Run Action List"),

(1229600,9,0,0,0,0,100,0,0,0,0,0,0,36,12297,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Gazelle - On Script - Update Template To 'Cured Gazelle'"),
(1229600,9,1,0,0,0,100,0,0,0,0,0,0,33,12297,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sickly Gazelle - On Script - Quest Credit 'Curing the Sick'"),
(1229600,9,2,0,0,0,100,0,1500,1500,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,30,30,0,0,"Sickly Gazelle - On Script - Move Offset"),
(1229600,9,3,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Gazelle - On Script - Despawn"),

(1229800,9,0,0,0,0,100,0,0,0,0,0,0,36,12299,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Deer - On Script - Update Template To 'Cured Deer'"),
(1229800,9,1,0,0,0,100,0,0,0,0,0,0,33,12299,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sickly Deer - On Script - Quest Credit 'Curing the Sick'"),
(1229800,9,2,0,0,0,100,0,1500,1500,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,30,30,0,0,"Sickly Deer - On Script - Move Offset"),
(1229800,9,3,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Deer - On Script - Despawn");

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_terokkar_fumping' WHERE `ScriptName` = 'spell_q10929_fumping';

DELETE FROM `spell_script_names` WHERE `spell_id` = 39246 AND `ScriptName` = 'spell_terokkar_fumping_the_big_bone_worm';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(39246,'spell_terokkar_fumping_the_big_bone_worm');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (39248,39250);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,39248,0,0,31,0,3,22105,0,0,0,0,"","Group 0: Spell 'Summon Hai'Shulud' (Effect 0) targets creature 'Decrepit Clefthoof'"),
(13,1,39250,0,0,31,0,3,22105,0,0,0,0,"","Group 0: Spell 'Despawn Clefthoof' (Effect 0) targets creature 'Decrepit Clefthoof'");

DELETE FROM `spell_script_names` WHERE `spell_id` = 39250 AND `ScriptName` = 'spell_gen_despawn_target';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(39250,'spell_gen_despawn_target');

UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1 WHERE `entry` = 22482;
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22483;

UPDATE `creature_text` SET `Language` = 0, `Emote` = 15 WHERE `CreatureID` = 22483;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 22483 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2248300 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22483,0,0,0,11,0,100,0,0,0,0,0,0,80,2248300,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sand Gnome - On Spawn - Run Script"),

(2248300,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sand Gnome - On Script - Set Reactstate Passive"),
(2248300,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sand Gnome - On Script - Say Line 0"),
(2248300,9,2,0,0,0,100,0,1500,1500,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sand Gnome - On Script - Set Reactstate Aggressive"),
(2248300,9,3,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Sand Gnome - On Script - Start Attack Owner");
