-- Trial of the Crusader Death knight Death grip scriptname
DELETE FROM `spell_script_names` WHERE `spell_id` IN (66017, 68753, 68754, 68755);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66017, 'spell_faction_champion_death_grip'),
(68753, 'spell_faction_champion_death_grip'),
(68754, 'spell_faction_champion_death_grip'),
(68755, 'spell_faction_champion_death_grip');

-- Trial of the Crusader shaman heroism/bloodlust
DELETE FROM `spell_script_names` WHERE `spell_id` IN (65983, 65980);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(65983, 'spell_toc_heroism'),
(65980, 'spell_toc_bloodlust');

-- impale scriptname
DELETE FROM `spell_script_names` WHERE `spell_id`=65919;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(65919, 'spell_impale');

-- firebomb scriptname and modelid (ToC Gormok encounter)
UPDATE `creature_template` SET `ScriptName`="npc_firebomb" WHERE `entry`=34854;

-- frost sphere corrections
UPDATE `creature_template` SET `minlevel`=80, `InhabitType`=4, `RegenHealth`=0 WHERE `entry` IN (34606, 34649);

-- Dark / Light essence removing
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-67222, -67223, -67224, -65686, -67176, -67177, -67178, -65684);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-67222, -67511, 0, 'Light Essence 25M'),
(-67223, -67512, 0, 'Light Essence 10M H'),
(-67224, -67513, 0, 'Light Essence 25M H'),
(-65686, -65811, 0, 'Light Essence 10M'),
(-67176, -67179, 0, 'Dark Essence 25M'),
(-67177, -67180, 0, 'Dark Essence 10M H'),
(-67178, -67181, 0, 'Dark Essence 25M H'),
(-65684, -65827, 0, 'Dark Essence 10M');

-- Gormoks Fire Bomb scriptname
DELETE FROM `spell_script_names` WHERE `spell_id`=66313;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66313, 'spell_gormok_fire_bomb');

-- correcting hitbox of Anub'Arak
UPDATE `creature_model_info` SET `bounding_radius`=1.085, `combat_reach`=10.5 WHERE `modelid`=29268;

-- correcting hitbox of Acidmaw
UPDATE `creature_model_info` SET `bounding_radius`=1.24, `combat_reach`=12 WHERE `modelid`=29815;

-- spawn the Anub'arak gate in all versions of the instance
UPDATE `gameobject` SET `spawnMask`=15 WHERE `guid`=151192;

-- adding ToC boss immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask` | 1 | 2 | 4 | 8 | 16 | 32 | 64 | 128 | 256 | 512 | 1024 | 2048 | 4096 | 8192 | 65536 | 131072 | 524288 | 4194304 | 8388608 | 67108864 | 536870912  WHERE `entry` IN (34796, 35438, 35439, 35440, 34799, 35514, 35515, 35516, 35144, 35511, 35512, 35513, 34797, 35447, 35448, 35449, 34780, 35216, 35268, 35269, 36066, 35347, 35348, 35349, 34497, 35350, 35351, 35352, 34564, 34566, 35615, 35616);

-- adding Teleport locations to Trial of the Crusader/champion for GMs
DELETE FROM `game_tele` WHERE `name` LIKE '%TrialOfTheCrusader%' OR `name` LIKE '%TrialOfTheChampion%';
INSERT INTO `game_tele` (`position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES
(8515.63, 714.174, 558.248, 1.57298, 571, 'TrialOfTheCrusader'),
(8588.42, 791.888, 558.236, 3.23819, 571, 'TrialOfTheChampion');

-- misc fixes for higher boss brackets
UPDATE `creature_template` SET `dmg_multiplier`=70 WHERE `entry` IN (35440, 35513, 35516, 35449, 35269, 35352, 35349, 35616, 35664, 35670, 35673, 35676, 35682, 35685, 35688, 35691, 35694, 35697, 35701, 35704, 35707, 35710, 35713, 35716, 35720, 35723, 35726, 35730, 35733, 35736, 35739, 35742, 35745, 35748, 35749);
UPDATE `creature_template` SET `flags_extra`=`flags_extra` | 1 WHERE `entry` IN (35438, 35439, 35440, 35511, 35512, 35513, 35514, 35515, 35516, 35662, 35663, 35664, 35665, 35666, 35667, 35668, 35669, 35670, 35671, 35672, 35673, 35674, 35675, 35676, 35680, 35681, 35682, 35683, 35684, 35685, 35686, 35687, 35688, 35689, 35690, 35691, 35692, 35693, 35694, 35695, 35696, 35697, 35699, 35700, 35701, 35702, 35703, 35704, 35705, 35706, 35707, 35708, 35709, 35710, 35711, 35712, 35713, 35714, 35715, 35716, 35718, 35719, 35720, 35721, 35722, 35723, 35724, 35725, 35726, 35728, 35729, 35730, 35731, 35732, 35733, 35734, 35735, 35736, 35737, 35738, 35739, 35740, 35741, 35742, 35743, 35744, 35745, 35746, 35747, 35748, 34442, 34443, 35749);
UPDATE `creature_template` SET `speed_walk`=2.8, `speed_run`=1.71429 WHERE `entry` IN (35350, 35351, 35352, 35347, 35348, 35349);
UPDATE `creature_template` SET `speed_walk`=2, `speed_run`=1.14286 WHERE `entry` IN (34566, 35615, 35616);
UPDATE `creature_template` SET `skinloot`=34797 WHERE `entry` IN (35447, 35448, 35449);
UPDATE `creature_template` SET `skinloot`=70214 WHERE `entry` IN (34566, 35615, 35616);
UPDATE `creature_template` SET `mindmg`=388, `maxdmg`=583, `attackpower`=146 WHERE `entry` IN (35711, 35712, 35713);
UPDATE `creature_template` SET `mindmg`=468, `maxdmg`=702, `attackpower`=175 WHERE `entry` IN (35699, 35700, 35701);
UPDATE `creature_template` SET `dmg_multiplier`=35 WHERE `entry` IN (34472, 34454);
UPDATE `creature_template` SET `unit_class`=1 WHERE `entry` IN (34461, 35743, 35744, 35745);

-- adding Jaraxxus add immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask` | 1024 | 2048 WHERE `entry` IN (34815, 35262, 35263, 35264, 34826, 35270, 35271, 35272);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask` | 262144 WHERE `entry` IN (35263, 35264);
-- adding Nether portal and Infernal volcano immunities to knockout/grip
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask` | 32 | 8192 WHERE `entry` IN (34825, 35278, 35279, 35280, 34813, 35265, 35266, 35267);

-- cast Forbearance together with Divine shield (ToC Faction Champions paladin)
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=66010;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(66010, 25771, 0, 'Divine Shield - Forbearance');

-- make all Diminishing returns rules apply in faction champions
UPDATE `creature_template` SET `flags_extra`=`flags_extra` | 1048576 WHERE `entry` IN
(34445,35705,35706,35707,
34459,35686,35687,35688,
34447,35683,35684,35685,
34455,35680,35681,35682,
34453,35718,35719,35720,
34458,35692,35693,35694,
34454,35711,35712,35713,
34448,35724,35725,35726,
34441,34442,34443,35749,
34450,35695,35696,35697,
35610,35774,35775,35776,
35465,36301,36302,36303,
34451,35671,35672,35673,
34449,35689,35690,35691,
34444,35740,35741,35742,
34456,35708,35709,35710,
34460,35702,35703,35704,
34461,35743,35744,35745,
34463,35734,35735,35736,
34465,35746,35747,35748,
34466,35665,35666,35667,
34467,35662,35663,35664,
34468,35721,35722,35723,
34469,35714,35715,35716,
34470,35728,35729,35730,
34473,35674,35675,35676,
34474,35731,35732,35733,
34475,35737,35738,35739,
34471,35668,35669,35670,
34472,35699,35700,35701);

-- correcting faction champions dmg multipliers
UPDATE `creature_template` SET `dmg_multiplier`=10.8 WHERE `entry` IN (34445,34459,34447,34455,34453,34458,34454,34448,34441,34450,35610,35465,34451,34449,34444,34456,34460,34461,34463,34465,34466,34467,34468,34469,34470,34473,34474,34475,34472, 34471);
UPDATE `creature_template` SET `dmg_multiplier`=16.1 WHERE `entry` IN (35705,35706,35686,35687,35683,35684,35680,35681,35718,35719,35692,35693,35711,35712,35724,35725,34442,34443,35695,35696,35774,35775,36301,36302,35671,35672,35689,35690,35740,35741,35708,35709,35702,35703,35743,35744,35734,35735,35746,35747,35665,35666,35662,35663,35721,35722,35714,35715,35728,35729,35674,35675,35731,35732,35737,35738,35699,35700, 35668, 35669);
UPDATE `creature_template` SET `dmg_multiplier`=21.5 WHERE `entry` IN (35707,35688,35685,35682,35720,35694,35713,35726,35749,35697,35776,36303,35673,35691,35742,35710,35704,35745,35736,35748,35667,35664,35723,35716,35730,35676,35733,35739,35701, 35670);

-- ToC warlock pet db corrections
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `exp`=2, `faction_A`=16, `faction_H`=16, `mindmg`=417, `maxdmg`=582, `attackpower`=608, `unit_class`=2, `dynamicflags`=8, `minrangedmg`=341, `maxrangedmg`=506, `rangedattackpower`=80 WHERE `entry` IN (36301, 36302, 36303);
UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16, `difficulty_entry_1`=36301, `difficulty_entry_2`=36302, `difficulty_entry_3`=36303 WHERE `entry`=35465;
UPDATE `creature_template` SET `name`="Zhaagrym (1)" WHERE `entry`=36301;

-- Jaraxxus Mistress Kiss
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mistress_kiss_area';
INSERT INTO `spell_script_names` (spell_id, `ScriptName`) VALUES
(66336, 'spell_mistress_kiss_area'),
(67076, 'spell_mistress_kiss_area'),
(67077, 'spell_mistress_kiss_area'),
(67078, 'spell_mistress_kiss_area');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_mistress_kiss';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66334, 'spell_mistress_kiss'),
(67905, 'spell_mistress_kiss'),
(67906, 'spell_mistress_kiss'),
(67907, 'spell_mistress_kiss');

-- Gormoks Rising anger targeting
DELETE FROM `conditions` WHERE `SourceEntry`=66636;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 66636, 31, 3, 34796, 'Rising Anger');

-- Twins loot correction
UPDATE `creature_loot_template` SET `maxcount`=1 WHERE `entry`=34497 AND `mincountOrRef` IN (-34296, -34302);
-- Anubarak loot correction
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=34564 AND `mincountOrRef` IN (-34298, -34304);
