--
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 38374;
UPDATE `creature_template_addon` SET `SheathState` = 1 WHERE `entry` = 38374;

DELETE FROM `spell_scripts` WHERE `id` IN (71848,71874);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pet_gen_toxic_wasteling_find_target',
'spell_pet_gen_toxic_wasteling_devour');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(71848, 'spell_pet_gen_toxic_wasteling_find_target'),
(71874, 'spell_pet_gen_toxic_wasteling_devour');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 38374;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 38374 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3837400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(38374,0,0,0,31,0,100,0,71847,0,0,0,0,80,3837400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Toxic Wasteling - On Target Spellhit 'Toxic Wasteling Attack' - Run Script"),
-- After jumping default follow movement is launched, making it work not like on retail
(3837400,9,0,0,0,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Toxic Wasteling - On Script - Stop Follow"),
(3837400,9,1,0,0,0,100,0,1500,1500,0,0,0,11,71874,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Toxic Wasteling - On Script - Cast 'Toxic Wasteling Devour'"),
(3837400,9,3,0,0,0,100,0,1500,1500,0,0,0,11,71854,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Toxic Wasteling - On Script - Cast 'Toxic Wasteling Grow'"),
(3837400,9,4,0,0,0,100,0,2500,2500,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Toxic Wasteling - On Script - Follow Owner");

--
DELETE FROM `spell_scripts` WHERE `id` = 50499;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_item_disco_ball_listening_to_music_periodic',
'spell_item_disco_ball_listening_to_music_check',
'spell_item_disco_ball_listening_to_music_parent');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(50493, 'spell_item_disco_ball_listening_to_music_periodic'),
(50492, 'spell_item_disco_ball_listening_to_music_check'),
(50499, 'spell_item_disco_ball_listening_to_music_parent');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 50492;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,50492,0,0,31,0,3,27989,0,0,0,0,"","Group 0: Spell 'Listening to Music CHECK' (Effect 0) targets creature 'D.I.S.C.O.'");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (50493,50317,-50493,-50314);

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 27989;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27989 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27989,0,0,0,11,0,100,0,0,0,0,0,0,11,50314,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D.I.S.C.O. - On Spawn - Cast 'Disco Ball'"),
(27989,0,1,0,11,0,100,0,0,0,0,0,0,11,50487,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D.I.S.C.O. - On Spawn - Cast 'Create Disco Ball Visual Object'"),
(27989,0,2,0,11,0,100,0,0,0,0,0,0,11,50493,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D.I.S.C.O. - On Spawn - Cast 'Listening to Music'"),
(27989,0,3,0,11,0,100,0,0,0,0,0,0,11,28782,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"D.I.S.C.O. - On Spawn - Cast 'Stun Self + Immune'");

UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 27989;

--
DELETE FROM `spell_scripts` WHERE `id` = 49899;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_wintergrasp_activate_robotic_arms';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49899, 'spell_wintergrasp_activate_robotic_arms');

--
DELETE FROM `spell_scripts` WHERE `id` IN (49625,49634);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_fjord_braves_flare',
'spell_fjord_sergeants_flare');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49625, 'spell_fjord_braves_flare'),
(49634, 'spell_fjord_sergeants_flare');

--
DELETE FROM `spell_scripts` WHERE `id` = 44563;

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 24823;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24823 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24823,0,0,0,8,0,100,512,44563,0,0,0,0,11,44569,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Iron Rune Construct - On Spellhit 'Bluff Quest Credit' - Cast 'Bluff Quest Credit'");

--
DELETE FROM `spell_scripts` WHERE `id` = 51659;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28379 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28379,0,2,0,8,0,100,0,51659,0,0,0,0,11,51656,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Shattertusk Mammoth - On Spellhit 'Apply Harness' - Cast 'Mount Mammoth Cue'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sholazar_mount_mammoth_cue';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51656, 'spell_sholazar_mount_mammoth_cue');

--
DELETE FROM `spell_scripts` WHERE `id` = 21977;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_warriors_wrath';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(21977, 'spell_warr_warriors_wrath');

--
DELETE FROM `spell_scripts` WHERE `id` = 49203;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dk_hungering_cold_init';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49203, 'spell_dk_hungering_cold_init');

--
DELETE FROM `spell_scripts` WHERE `id` = 31231;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_rog_cheat_death_cooldown';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31231, 'spell_rog_cheat_death_cooldown');

--
DELETE FROM `spell_scripts` WHERE `id` = 51662;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_rog_hunger_for_blood';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51662, 'spell_rog_hunger_for_blood');

--
DELETE FROM `spell_scripts` WHERE `id` = 40109;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_bem_kfc_the_bolt';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40109, 'spell_bem_kfc_the_bolt');

--
DELETE FROM `spell_scripts` WHERE `id` = 38173;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_bem_summon_spirit';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38173, 'spell_bem_summon_spirit');

--
DELETE FROM `spell_scripts` WHERE `id` IN (45685,45691);

UPDATE `spell_script_names` SET `ScriptName` = 'spell_borean_tundra_shortening_blaster' WHERE `ScriptName` = 'spell_q11653_shortening_blaster';

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_borean_tundra_magnataur_on_death_1',
'spell_borean_tundra_magnataur_on_death_2');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45691, 'spell_borean_tundra_magnataur_on_death_1'),
(45685, 'spell_borean_tundra_magnataur_on_death_2');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (25432,25434) AND `SourceId` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25432,25434) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25432,0,0,0,2,0,100,1,0,30,0,0,0,11,50420,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mate of Magmothregar - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(25432,0,1,0,83,0,100,0,50420,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mate of Magmothregar - On Spell Cast 'Enrage' - Say Line 0"),
(25432,0,2,0,6,0,100,0,0,0,0,0,0,11,45691,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mate of Magmothregar - On Death - Cast 'Hah... : Magnataur On Death 1'"),

(25434,0,0,0,0,0,100,0,0,5000,10000,15000,0,11,50413,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Magmoth Crusher - In Combat - Cast 'Magnataur Charge'"),
(25434,0,1,0,0,0,100,0,5000,10000,10000,15000,0,11,50410,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Magmoth Crusher - In Combat - Cast 'Tusk Strike'"),
(25434,0,2,0,6,0,100,0,0,0,0,0,0,11,45691,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Magmoth Crusher - On Death - Cast 'Hah... : Magnataur On Death 1'");
