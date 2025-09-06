--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 43648;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_akilzon_electrical_storm';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43648, 'spell_akilzon_electrical_storm');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 43658;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_akilzon_electrical_overload';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43658, 'spell_akilzon_electrical_overload');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 45458;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_midsummer_stamp_out_bonfire_quest_complete', 'spell_midsummer_stamp_out_bonfire_event');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45458, 'spell_midsummer_stamp_out_bonfire_quest_complete'),
(45443, 'spell_midsummer_stamp_out_bonfire_event');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 46903;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46903,0,0,31,0,5,187564,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,1,31,0,5,187914,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,2,31,0,5,187916,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,3,31,0,5,187917,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,4,31,0,5,187919,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,5,31,0,5,187920,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,6,31,0,5,187921,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,7,31,0,5,187922,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,8,31,0,5,187923,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,9,31,0,5,187924,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,10,31,0,5,187925,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,11,31,0,5,187926,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,12,31,0,5,187927,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,13,31,0,5,187928,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,14,31,0,5,187929,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,15,31,0,5,187930,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,16,31,0,5,187931,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,17,31,0,5,187932,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,18,31,0,5,187933,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,19,31,0,5,187934,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,20,31,0,5,187935,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,21,31,0,5,187936,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,22,31,0,5,187937,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,23,31,0,5,187938,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,24,31,0,5,187939,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,25,31,0,5,187940,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,26,31,0,5,187941,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,27,31,0,5,187942,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,28,31,0,5,187943,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,29,31,0,5,187944,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,30,31,0,5,187945,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,31,31,0,5,187946,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,32,31,0,5,194032,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,33,31,0,5,194035,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,34,31,0,5,194036,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,35,31,0,5,194038,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,36,31,0,5,194040,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,37,31,0,5,194044,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,38,31,0,5,194045,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,39,31,0,5,194049,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Alliance Bonfire'"),
(13,1,46903,0,40,31,0,5,187559,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,41,31,0,5,187947,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,42,31,0,5,187948,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,43,31,0,5,187949,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,44,31,0,5,187950,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,45,31,0,5,187951,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,46,31,0,5,187952,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,47,31,0,5,187953,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,48,31,0,5,187954,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,49,31,0,5,187955,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,50,31,0,5,187956,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,51,31,0,5,187957,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,52,31,0,5,187958,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,53,31,0,5,187959,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,54,31,0,5,187960,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,55,31,0,5,187961,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,56,31,0,5,187962,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,57,31,0,5,187963,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,58,31,0,5,187964,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,59,31,0,5,187965,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,60,31,0,5,187966,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,61,31,0,5,187967,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,62,31,0,5,187968,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,63,31,0,5,187969,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,64,31,0,5,187970,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,65,31,0,5,187971,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,66,31,0,5,187972,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,67,31,0,5,187973,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,68,31,0,5,187974,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,69,31,0,5,187975,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,70,31,0,5,194033,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,71,31,0,5,194034,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,72,31,0,5,194037,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,73,31,0,5,194039,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,74,31,0,5,194042,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,75,31,0,5,194043,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,76,31,0,5,194046,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'"),
(13,1,46903,0,77,31,0,5,194048,0,0,0,'',"Spell 'Stamp Out Bonfire (Art Kit)' (Effect 0) targets object 'Horde Bonfire'");

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 45750;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_borean_tundra_land_mine_barrier';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45750, 'spell_borean_tundra_land_mine_barrier');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (51060,51068,51088,51094);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_have_ingredient';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51060, 'spell_zuldrak_have_ingredient'),
(51068, 'spell_zuldrak_have_ingredient'),
(51088, 'spell_zuldrak_have_ingredient'),
(51094, 'spell_zuldrak_have_ingredient');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 52839;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_summon_escort_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52839, 'spell_zuldrak_summon_escort_aura');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 52989;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_akalis_stun';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52989, 'spell_zuldrak_akalis_stun');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 53435;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_cos_teleport_to_cot_stratholme_phase_4';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(53435, 'spell_cos_teleport_to_cot_stratholme_phase_4');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -45992;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_borean_tundra_taxi_amber_ledge_to_beryl_point_platform';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45992, 'spell_borean_tundra_taxi_amber_ledge_to_beryl_point_platform');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -51221;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_fjord_taxi_to_explorers_league_outpost';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51221, 'spell_fjord_taxi_to_explorers_league_outpost');

-- Quest 12166
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 46770;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26616,26643) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26616,0,0,0,8,0,100,1,46770,0,0,0,0,33,27111,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Blighted Elk - On Spellhit 'Liquid Fire of Elune' - Quest Credit 'The Liquid Fire of Elune'"),
(26616,0,1,0,8,0,100,1,46770,0,0,0,0,11,47972,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blighted Elk - On Spellhit 'Liquid Fire of Elune' - Cast 'The Liquid Fire of Elune: Blue Fire'"),
(26616,0,2,0,8,0,100,1,46770,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Blighted Elk - On Spellhit 'Liquid Fire of Elune' - Despawn"),

(26643,0,0,0,8,0,100,0,46770,0,0,0,0,33,27112,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Rabid Grizzly - On Spellhit 'Liquid Fire of Elune' - Quest Credit 'The Liquid Fire of Elune'"),
(26643,0,1,0,8,0,100,0,46770,0,0,0,0,11,47972,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rabid Grizzly - On Spellhit 'Liquid Fire of Elune' - Cast 'The Liquid Fire of Elune: Blue Fire'"),
(26643,0,2,0,8,0,100,0,46770,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Rabid Grizzly - On Spellhit 'Liquid Fire of Elune' - Despawn");

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 47190;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dragonblight_toaluus_spiritual_incense';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47190, 'spell_dragonblight_toaluus_spiritual_incense');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 61122;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_storm_peaks_contact_brann';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61122, 'spell_storm_peaks_contact_brann');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 61121;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,61121,0,0,31,0,3,29579,0,0,0,0,"","Group 0: Spell 'Despawn Brann' targets creature 'Brann Bronzebeard'"),
(13,1,61121,0,0,33,0,1,3,0,0,0,0,"","Group 0: Spell 'Despawn Brann' targets creature 'Brann Bronzebeard' if owned by spell caster");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_despawn_target' AND `spell_id` = 61121;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61121, 'spell_gen_despawn_target');

-- Already scripted in SpellScript
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 66744;

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (31606,31746,-31773,-31774,-31775,-31776);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_zangarmarsh_stormcrow_amulet','spell_zangarmarsh_whisper_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31606, 'spell_zangarmarsh_stormcrow_amulet'),
(31773, 'spell_zangarmarsh_whisper_aura'),
(31774, 'spell_zangarmarsh_whisper_aura'),
(31775, 'spell_zangarmarsh_whisper_aura'),
(31776, 'spell_zangarmarsh_whisper_aura');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 19512;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1229600,1229800) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1229600,9,0,0,0,0,100,0,0,0,0,0,0,36,12297,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Gazelle - On Script - Update Template To 'Cured Gazelle'"),
(1229600,9,1,0,0,0,100,0,0,0,0,0,0,28,19502,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Gazelle - On Script - Remove Aura 'Sickly Critter Aura'"),
(1229600,9,2,0,0,0,100,0,0,0,0,0,0,33,12297,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sickly Gazelle - On Script - Quest Credit 'Curing the Sick'"),
(1229600,9,3,0,0,0,100,0,1500,1500,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,30,30,0,0,"Sickly Gazelle - On Script - Move Offset"),
(1229600,9,4,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Gazelle - On Script - Despawn"),

(1229800,9,0,0,0,0,100,0,0,0,0,0,0,36,12299,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Deer - On Script - Update Template To 'Cured Deer'"),
(1229800,9,1,0,0,0,100,0,0,0,0,0,0,28,19502,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Deer - On Script - Remove Aura 'Sickly Critter Aura'"),
(1229800,9,2,0,0,0,100,0,0,0,0,0,0,33,12299,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sickly Deer - On Script - Quest Credit 'Curing the Sick'"),
(1229800,9,3,0,0,0,100,0,1500,1500,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,30,30,0,0,"Sickly Deer - On Script - Move Offset"),
(1229800,9,4,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sickly Deer - On Script - Despawn");

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (43369,-43369,-68347);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_fjord_worg_disguise', 'spell_fjord_worg_disguise_dummy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43369, 'spell_fjord_worg_disguise'),
(68347, 'spell_fjord_worg_disguise_dummy');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 47435;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dragonblight_scrape_corrosive_spit';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47435, 'spell_dragonblight_scrape_corrosive_spit');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -46813;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_borean_tundra_taxi_coldarra_ledge_to_transitus_shield';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46813, 'spell_borean_tundra_taxi_coldarra_ledge_to_transitus_shield');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -42385;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dustwallow_marsh_alcaz_survey_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42385, 'spell_dustwallow_marsh_alcaz_survey_aura');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-40623,-40625,-40626);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_bem_apexis_swiftness';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40623, 'spell_bem_apexis_swiftness'),
(40625, 'spell_bem_apexis_swiftness'),
(40626, 'spell_bem_apexis_swiftness');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 24714;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hallow_end_trick_initial';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(24714, 'spell_hallow_end_trick_initial');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 36587;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_bem_vision_guide';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(36587, 'spell_bem_vision_guide');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 42144;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_hallow_end_create_water_bucket';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42144, 'spell_hallow_end_create_water_bucket');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -68839;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_bronjahm_corrupt_soul';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(68839, 'spell_bronjahm_corrupt_soul');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = -62320;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_thorim_aura_of_celerity';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62320, 'spell_thorim_aura_of_celerity');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-54361,-59743);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuramat_void_shift';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(54361, 'spell_zuramat_void_shift'),
(59743, 'spell_zuramat_void_shift');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-47744,61611);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_grizzly_hills_rage_of_jinarrak';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47744, 'spell_grizzly_hills_rage_of_jinarrak');

--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-30448,30447,30448);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_azuremyst_isle_shadow_of_the_forest_creature','spell_azuremyst_isle_shadow_of_the_forest_player');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(30447, 'spell_azuremyst_isle_shadow_of_the_forest_creature'),
(30448, 'spell_azuremyst_isle_shadow_of_the_forest_player');
