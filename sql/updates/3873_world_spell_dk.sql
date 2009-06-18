
replace into creature_questrelation (id,quest) VALUES (28377,12701);
replace into creature_involvedrelation (id,quest) VALUES (28377,12701);
replace into creature_involvedrelation (id,quest) VALUES (28914,12723);
replace into creature_questrelation (id,quest) VALUES (28914,12724);
replace into creature_involvedrelation (id,quest) VALUES (28914,12724);
replace into creature_questrelation (id,quest) VALUES (28913,12725);
replace into creature_involvedrelation (id,quest) VALUES (28912,12725);
replace into creature_questrelation (id,quest) VALUES (28912,12727);
replace into creature_involvedrelation (id,quest) VALUES (28913,12727);


DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (28833,28887);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
(28833, 52447, 12701, 3, 3),
(28887, 52447, 12701, 3, 3);

UPDATE creature_template SET spell1=52435,spell2=52576,spell5=52588,VehicleId=68,speed=0 WHERE entry IN (28833,28887);
UPDATE creature_template SET spell1=52211 WHERE entry=28864;

DELETE FROM `spell_script_target` WHERE entry IN
(52576);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(52576,1,28834),
(52576,1,28886);
