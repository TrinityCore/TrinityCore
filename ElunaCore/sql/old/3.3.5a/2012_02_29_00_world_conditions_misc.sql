DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN(34125,33796,33798,33799,33791,33792,33790,
33795,33793,33800,33794,33843,33842,26421,26477,28161,29856,32788,32790);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,
`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
-- Stabled Campagin Warhorse Requires Any of the Dailies
(18,34125,63215,1,9,0,13847,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,2,9,0,13851,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,3,9,0,13852,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,4,9,0,13854,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,5,9,0,13855,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,6,9,0,13856,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,7,9,0,13857,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,8,9,0,13858,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,9,9,0,13859,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,10,9,0,13860,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,11,9,0,13861,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,12,9,0,13862,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,13,9,0,13863,0,0,0,'Required quest active for spellclick'),
(18,34125,63215,14,9,0,13864,0,0,0,'Required quest active for spellclick'),
-- Raptor requires (A) Valiant of Sen'Jin
(18,33796,62784,1,8,0,13693,0,0,0,'Required quest rewarded for spellclick'),
(18,33796,62784,2,8,0,13708,0,0,0,'Required quest rewarded for spellclick'),
-- Forsaken Warhorse requires (A) Valiant of Undercity
(18,33798,62787,1,8,0,13695,0,0,0,'Required quest rewarded for spellclick'),
(18,33798,62787,2,8,0,13710,0,0,0,'Required quest rewarded for spellclick'),
-- Orgrimmar Wolf requires (A) Valiant of Orgrimmar
(18,33799,62783,1,8,0,13691,0,0,0,'Required quest rewarded for spellclick'),
(18,33799,62783,2,8,0,13707,0,0,0,'Required quest rewarded for spellclick'),
-- Silvermoon Hawkstrider requires (A) Valiant of Silvermoon
(18,33791,62786,1,8,0,13696,0,0,0,'Required quest rewarded for spellclick'),
(18,33791,62786,2,8,0,13711,0,0,0,'Required quest rewarded for spellclick'),
-- Thunder Bluff Kodo requires (A) Valiant of Thunder Bluff
(18,33792,62785,1,8,0,13694,0,0,0,'Required quest rewarded for spellclick'),
(18,33792,62785,2,8,0,13709,0,0,0,'Required quest rewarded for spellclick'),
-- Exodar Elekk requires (A) Valiant of the Exodar
(18,33790,62781,1,8,0,13690,0,0,0,'Required quest rewarded for spellclick'),
(18,33790,62781,2,8,0,13705,0,0,0,'Required quest rewarded for spellclick'),
-- Ironforge Ram requires (A) Valiant of Ironforge
(18,33795,62779,1,8,0,13685,0,0,0,'Required quest rewarded for spellclick'),
(18,33795,62779,2,8,0,13703,0,0,0,'Required quest rewarded for spellclick'),
-- Gnomeregan Mechanostrider requires (A) Valiant of Gnomeregan
(18,33793,62780,1,8,0,13688,0,0,0,'Required quest rewarded for spellclick'),
(18,33793,62780,2,8,0,13704,0,0,0,'Required quest rewarded for spellclick'),
-- Stormwind Steed requires (A) Valiant of Stormwind
(18,33800,62774,1,8,0,13593,0,0,0,'Required quest rewarded for spellclick'),
(18,33800,62774,2,8,0,13684,0,0,0,'Required quest rewarded for spellclick'),
-- Darnassian Nightsaber requires (A) Valiant of Darnassus
(18,33794,62782,1,8,0,13689,0,0,0,'Required quest rewarded for spellclick'),
(18,33794,62782,2,8,0,13706,0,0,0,'Required quest rewarded for spellclick'),
-- Stabled Quel'Dorei steeds requires The Argent Tournament rewarded
(18,33843,63792,0,8,0,13667,0,0,0,'Required quest rewarded for spellclick'),
-- Stabled Quel'Dorei steed forbids Alliance Eligibility Marker rewarded
(18,33843,63792,0,8,0,13686,0,0,1,'Forbidden rewarded quest for spellclick'),
-- Sunreaver Hawkstrider requires The Argent Tournament rewarded
(18,33842,63791,0,8,0,13668,0,0,0,'Required quest rewarded for spellclick'),
-- Sunreaver Hawkstrider forbids Horde Eligibility Marker rewarded
(18,33842,63791,0,8,0,13687,0,0,1,'Forbidden rewarded quest for spellclick'),
-- Misc
(18,26421,47575,0,8,0,12092,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26421,47575,0,8,0,12096,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26421,47575,1,9,0,12092,0,0,0,'Required quest active for spellclick'),
(18,26421,47575,2,9,0,12096,0,0,0,'Required quest active for spellclick'),
(18,26477,47096,0,8,0,11999,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,47096,0,8,0,12000,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61286,0,8,0,11999,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61286,0,8,0,12000,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61832,0,8,0,11999,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61832,0,8,0,12000,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,26477,61286,1,9,0,11999,0,0,0,'Required quest active for spellclick'),
(18,26477,61286,2,9,0,12000,0,0,0,'Required quest active for spellclick'),
(18,26477,47096,1,9,0,11999,0,0,0,'Required quest active for spellclick'),
(18,26477,47096,2,9,0,12000,0,0,0,'Required quest active for spellclick'),
(18,26477,61832,1,9,0,11999,0,0,0,'Required quest active for spellclick'),
(18,26477,61832,2,9,0,12000,0,0,0,'Required quest active for spellclick'),
(18,28161,39996,0,8,0,12532,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,39996,0,8,0,12702,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,39996,1,9,0,12532,0,0,0,'Required quest active for spellclick'),
(18,28161,39996,2,9,0,12702,0,0,0,'Required quest active for spellclick'),
(18,28161,51037,0,8,0,12532,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,51037,0,8,0,12702,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,51037,1,9,0,12532,0,0,0,'Required quest active for spellclick'),
(18,28161,51037,2,9,0,12702,0,0,0,'Required quest active for spellclick'),
(18,28161,51961,0,8,0,12532,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,51961,0,8,0,12702,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,28161,51961,1,9,0,12532,0,0,0,'Required quest active for spellclick'),
(18,28161,51961,2,9,0,12702,0,0,0,'Required quest active for spellclick'),
(18,29856,55363,0,8,0,12629,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,29856,55363,0,8,0,12643,0,0,1,'Forbidden rewarded quest for spellclick'),
(18,29856,55363,1,9,0,12629,0,0,0,'Required quest active for spellclick'),
(18,29856,55363,2,9,0,12643,0,0,0,'Required quest active for spellclick'),
(18,32788,57539,1,8,0,13075,0,0,0,'Required quest rewarded for spellclick'),
(18,32788,57539,2,9,0,13075,0,0,0,'Required quest active for spellclick'),
(18,32790,57654,1,8,0,13073,0,0,0,'Required quest rewarded for spellclick'),
(18,32790,57654,2,9,0,13073,0,0,0,'Required quest active for spellclick');

-- Remove duplicate entries in npc_spellclick_spells (leave 1)
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN(34125,26421,26477,28161,
31157,33790,33791,33792,33793,33794,33795,33796,33798,33799,33800,34944,29856,30564,29414,31269);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(26477,47096,2,0),
(26477,61286,2,0),
(26477,61832,0,0),
(29414,18277,1,0),
(29856,55363,2,0),
(31269,46598,1,0),
(33794,62782,1,0),
(28161,51037,2,0),
(28161,39996,1,0),
(30564,57401,1,0),
(34125,63215,1,0),
(34944,68458,1,0),
(33790,62781,1,0),
(33793,62780,1,0),
(33795,62779,1,0),
(33800,62774,1,0),
(33798,62787,1,0),
(31157,46598,1,0),
(26421,47575,1,0),
(28161,51961,1,0),
(33791,62786,1,0),
(33792,62785,1,0),
(33796,62784,1,0),
(33799,62783,1,0);

-- If this query fails, fix your custom content
ALTER TABLE `npc_spellclick_spells` ADD PRIMARY KEY(`npc_entry`,`spell_id`);