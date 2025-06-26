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
