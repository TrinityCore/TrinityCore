-- zulaman
UPDATE `creature_template` SET `flags_extra` = 33 WHERE `entry` = 23576; /*zam bear boss no crush blow*/
UPDATE `creature_template` SET `faction_A` = '1890', `faction_H` = '1890' WHERE `entry` in ('24240', '24241', '24242', '24243', '24244', '24245', '24246', '24247');
UPDATE `creature_template` SET `minlevel` = '73', `maxlevel` = '73' WHERE `entry` IN (24187, 24136);

-- sunwell
REPLACE INTO `gameobject_template` VALUES (187366, 6, 4251, 'Blaze', '', 14, 0, 1, 0, 73, 2, 45246, 0, 1, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
UPDATE creature_template SET faction_H = 14, faction_A = 14, minlevel = 73, maxlevel = 73,rank = 3, flags = 33554434, flag1 = 0 WHERE entry = 25214;
UPDATE `creature_template` SET `minlevel` = '70', `maxlevel` = '70',`faction_A` = '14', `faction_H` = '14' WHERE `entry` in (25265,25267,25268);
UPDATE `creature_template` SET `mindmg` = '1500', `maxdmg` = '2500', `minhealth` = '40000', `maxhealth` = '40000', `baseattacktime` = '2000' WHERE `entry` = 25268;
UPDATE creature_template SET minhealth = 2018275, maxhealth = minhealth = 2018275 WHERE entry = 24892;
UPDATE creature_template SET minlevel = 73, maxlevel = 73, minhealth = 828555, maxhealth = 828555, armor = 5000, mindmg = 1000, maxdmg = 2000 WHERE entry = 24891;
INSERT INTO creature_template_addon (entry) SELECT 24891 FROM creature_template_addon WHERE NOT EXISTS(SELECT * FROM creature_template_addon WHERE entry = 24891) LIMIT 1; 
INSERT INTO creature_template_addon (entry) SELECT 24892 FROM creature_template_addon WHERE NOT EXISTS(SELECT * FROM creature_template_addon WHERE entry = 24892) LIMIT 1; 
UPDATE creature_template_addon SET auras = '45769 0 45769 1' WHERE entry = 24850;
UPDATE creature_template_addon SET auras = '45769 0 45769 1 44801 0 44801 1 44801 2' WHERE entry = 24891;
UPDATE creature_template_addon SET auras = '45769 0 45769 1 44801 0 44801 1 44801 2 44800 0' WHERE entry = 24892;

-- black temple
update creature_template set minlevel = 73, maxlevel = 73, minhealth = 500000, maxhealth = 500000, mindmg = 3000, maxdmg = 4000 where entry = 23197;

UPDATE `creature_template` SET`minlevel` = '60',`maxlevel` = '60',`minhealth` = '6900',`maxhealth` = '7200',`minmana` = '9476',`maxmana` = '9736',`armor` = '4000',speed` = '1.7',`rank` = '1',`mindmg` = '600',`maxdmg` = '1500',`attackpower` = '1200',`family` = '16',`minrangedmg` = '0',`maxrangedmg` = '0',`rangedattackpower` = '0',`resistance1` = '15',`resistance2` = '15',`resistance3` = '15',`resistance4` = '15',`resistance5` = '15',`resistance6` = '15',`ScriptName` = 'npc_kservant' WHERE `entry` = '19685';
DELETE FROM `quest_start_scripts` WHERE `id`='10211';
UPDATE `quest_template` SET `StartScript`='0' WHERE entry=10211;
UPDATE gameobject_template SET faction = 14 WHERE entry = 185134;

update quest_template SET StartScript=0 WHERE entry=11108;

DELETE FROM gameobject_template WHERE `entry` IN (187578, 188173);
INSERT INTO gameobject_template () VALUES (187578, 10, 4891, 'Scrying Orb', '', 0, 0, 2.16851, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'go_movie_orb');
INSERT INTO gameobject_template () VALUES (188173, 10, 7161, 'Escape to the Isle of Quel\'Danas', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'go_kael_orb');

UPDATE creature_template SET modelid_A = '17612', modelid_H = '17612'  WHERE entry = '24745';
UPDATE `creature_template` SET `minhealth` = '6900', `maxhealth` = '6900' WHERE `entry` = 24675;
UPDATE `creature_template` SET `minlevel` = '70', `maxlevel` = '70' WHERE `entry` = 24708;
UPDATE `creature_template` SET `minlevel` = '70', maxlevel` = '70' WHERE `entry` = 24666;
UPDATE `creature_template` SET `scale` = '0.5' WHERE `entry` = 24708;
update creature_template SET spell1=6474 WHERE entry=22487;
update creature_template SET spell1=3600 WHERE entry=22486;

update creature_template set flags_extra = 128 where entry = 12999;

-- serpent
UPDATE creature_template SET modelid_A = '11686', modelid_H = '11686', flags_extra = '128' WHERE entry = '22207';
UPDATE creature_model_info SET bounding_radius = '13', combat_reach = '20' WHERE modelid = '20216';
UPDATE creature_template SET InhabitType = '3' WHERE entry = '21217';

-- SELECT `gameobject_template` WHERE `entry` IN (186648, 187021, 186672, 186667);
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (22699, 22790, 22797, 22968);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33480, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33481, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33483, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33489, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33590, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33591, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33805, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33971, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33490, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33491, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33492, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33493, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33494, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33495, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33496, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33497, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33498, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33499, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33500, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22699, 33809, 100, 0, 13, 7, 4);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33480, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33481, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33483, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33489, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33590, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33591, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33805, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33971, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33490, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33491, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33492, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33493, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33494, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33495, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33496, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33497, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33498, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33499, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33500, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22790, 33809, 100, 0, 13, 7, 4);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33480, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33481, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33483, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33489, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33590, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33591, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33805, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33971, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33490, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33491, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33492, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33493, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33494, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33495, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33496, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33497, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33498, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33499, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33500, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22797, 33809, 100, 0, 13, 7, 4);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33480, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33481, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33483, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33489, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33590, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33591, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33805, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33971, 0, 1, 13, 7, 1);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33490, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33491, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33492, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33493, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33494, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33495, 0, 1, 13, 7, 2);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33496, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33497, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33498, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33499, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33500, 0, 1, 13, 7, 3);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `chanceorquestchance`, `groupid`, `lootcondition`, `condition_value1`, `condition_value2`) VALUES (22968, 33809, 100, 0, 13, 7, 4);
