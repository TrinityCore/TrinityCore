-- remove aura_required for clickspells on tournament mounts and add more cases (Thanks to @Tassader)
DELETE FROM `npc_spellclick_spells` WHERE npc_entry IN (33842,33796,33798,33791,33792,33799,33843,33800,33795,33790,33793,33794);
INSERT INTO `npc_spellclick_spells`(`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(33842,63791,13668,0,13687,1,0,0,0),-- Aspirant
(33799,62783,13691,0,0,1,0,0,0),-- A Valiant Of Orgrimmar
(33799,62783,13707,0,0,1,0,0,0),-- Valiant Of Orgrimmar
(33796,62784,13693,0,0,1,0,0,0),-- A Valiant Of Sen'jin
(33796,62784,13708,0,0,1,0,0,0),-- Valiant Of Sen'jin
(33792,62785,13694,0,0,1,0,0,0),-- A Valiant Of Thunder Bluff
(33792,62785,13709,0,0,1,0,0,0),-- Valiant Of Thunder Bluff
(33791,62786,13696,0,0,1,0,0,0),-- A Valiant Of Silvermoon
(33791,62786,13711,0,0,1,0,0,0),-- Valiant Of Silvermoon
(33798,62787,13695,0,0,1,0,0,0),-- A Valiant Of Undercity
(33798,62787,13710,0,0,1,0,0,0), -- Valiant Of Undercity
(33843,63792,13667,0,13686,1,0,0,0),-- Aspirant
(33800,62774,13593,0,0,1,0,0,0),-- A Valiant Of Stormwind
(33800,62774,13684,0,0,1,0,0,0),-- Valiant Of Stormwind
(33795,62779,13685,0,0,1,0,0,0),-- A Valiant Of Ironforge
(33795,62779,13703,0,0,1,0,0,0),-- Valiant Of Ironforge
(33793,62780,13688,0,0,1,0,0,0),-- A Valiant Of Gnomregan
(33793,62780,13704,0,0,1,0,0,0),-- Valiant Of Gnomregan
(33790,62781,13690,0,0,1,0,0,0),-- A Valiant Of Exodar
(33790,62781,13705,0,0,1,0,0,0),-- Valiant Of Exodar
(33794,62782,13689,0,0,1,0,0,0),-- A Valiant Of Darnassus
(33794,62782,13706,0,0,1,0,0,0); -- Valiant Of Darnassus
UPDATE `npc_spellclick_spells` SET `aura_required`=0 WHERE `aura_required`=62853;

-- Break-Shield spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62575,62626,64342,64507,64590,64595,64686,65147,66480,68504);
-- Charge spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62874,62960,63661,62563,63003,63010,64591,66481,68282,68284,68321,68498,68501);
-- Defend spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62552,62719,66482);
-- Pennant and summon spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62863,63034,62774,62779,62780,62781,62782,62783,62784,62785,62786,62787,63663,63791,63792,62595,62596,62594,63394,63395,63396,63397,63398,63401,63402,63403,63404,63405,63406,63421,63422,63423,63425,63426,63427,63428,63429,63430,63431,63432,63433,63434,63435,63436,63606,63500,63501,63607,63608,63609);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(62575,'spell_gen_break_shield'),
(62626,'spell_gen_break_shield'),
(64342,'spell_gen_break_shield'),
(64507,'spell_gen_break_shield'),
(64590,'spell_gen_break_shield'),
(64595,'spell_gen_break_shield'),
(64686,'spell_gen_break_shield'),
(65147,'spell_gen_break_shield'),
(66480,'spell_gen_break_shield'),
(68504,'spell_gen_break_shield'),
(62874,'spell_gen_mounted_charge'),
(62960,'spell_gen_mounted_charge'),
(63661,'spell_gen_mounted_charge'),
(62563,'spell_gen_mounted_charge'),
(63003,'spell_gen_mounted_charge'),
(63010,'spell_gen_mounted_charge'),
(64591,'spell_gen_mounted_charge'),
(66481,'spell_gen_mounted_charge'),
(68282,'spell_gen_mounted_charge'),
(68284,'spell_gen_mounted_charge'),
(68321,'spell_gen_mounted_charge'),
(68498,'spell_gen_mounted_charge'),
(68501,'spell_gen_mounted_charge'),
(62552,'spell_gen_defend'),
(62719,'spell_gen_defend'),
(66482,'spell_gen_defend'),
(62863 ,'spell_gen_tournament_duel'),
(63034,'spell_gen_on_tournament_mount'),
(62595,'spell_gen_tournament_pennant'),
(62596,'spell_gen_tournament_pennant'),
(62594,'spell_gen_tournament_pennant'),
(63394,'spell_gen_tournament_pennant'),
(63395,'spell_gen_tournament_pennant'),
(63396,'spell_gen_tournament_pennant'),
(63397,'spell_gen_tournament_pennant'),
(63398,'spell_gen_tournament_pennant'),
(63401,'spell_gen_tournament_pennant'),
(63402,'spell_gen_tournament_pennant'),
(63403,'spell_gen_tournament_pennant'),
(63404,'spell_gen_tournament_pennant'),
(63405,'spell_gen_tournament_pennant'),
(63406,'spell_gen_tournament_pennant'),
(63421,'spell_gen_tournament_pennant'),
(63422,'spell_gen_tournament_pennant'),
(63423,'spell_gen_tournament_pennant'),
(63425,'spell_gen_tournament_pennant'),
(63426,'spell_gen_tournament_pennant'),
(63427,'spell_gen_tournament_pennant'),
(63428,'spell_gen_tournament_pennant'),
(63429,'spell_gen_tournament_pennant'),
(63430,'spell_gen_tournament_pennant'),
(63431,'spell_gen_tournament_pennant'),
(63432,'spell_gen_tournament_pennant'),
(63433,'spell_gen_tournament_pennant'),
(63434,'spell_gen_tournament_pennant'),
(63435,'spell_gen_tournament_pennant'),
(63436,'spell_gen_tournament_pennant'),
(63606,'spell_gen_tournament_pennant'),
(63500,'spell_gen_tournament_pennant'),
(63501,'spell_gen_tournament_pennant'),
(63607,'spell_gen_tournament_pennant'),
(63608,'spell_gen_tournament_pennant'),
(63609,'spell_gen_tournament_pennant'),
(62774,'spell_gen_summon_tournament_mount'),
(62779,'spell_gen_summon_tournament_mount'),
(62780,'spell_gen_summon_tournament_mount'),
(62781,'spell_gen_summon_tournament_mount'),
(62782,'spell_gen_summon_tournament_mount'),
(62783,'spell_gen_summon_tournament_mount'),
(62784,'spell_gen_summon_tournament_mount'),
(62785,'spell_gen_summon_tournament_mount'),
(62786,'spell_gen_summon_tournament_mount'),
(62787,'spell_gen_summon_tournament_mount'),
(63663,'spell_gen_summon_tournament_mount'),
(63791,'spell_gen_summon_tournament_mount'),
(63792,'spell_gen_summon_tournament_mount');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=9798 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(9798,11,0,0, 'achievement_tilted');
