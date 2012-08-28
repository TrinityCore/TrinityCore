-- Frenzied geist
DELETE FROM `creature_loot_template` WHERE `entry`=31671;
-- Savage worg
DELETE FROM `creature_loot_template` WHERE `entry`=31678 AND `item` IN(39211,39212,33454);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `mincountOrRef`, `maxcount`) VALUES 
(31678,39211,70,3,5),
(31678,39212,16,2,4),
(31678,33454, 3,1,1);

-- Keleseth
UPDATE `creature_template` SET `mechanic_immune_mask`=617289692 WHERE `entry` IN(23953,30748);
-- Tunneling ghoul
DELETE FROM `creature_loot_template` WHERE `entry`=31681;
-- Dalronn heartsplitter
UPDATE `creature_template` SET `mindmg`=380,`maxdmg`=580,`attackpower`=0,`dmg_multiplier`=10 WHERE `entry`=31660;
-- Frenzied geist
UPDATE `creature_template` SET `lootid`=28419 WHERE `entry`=31671;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=28419;
-- Skarvald the constructor - On level 81 health fits/is blizzlike, depending on wowhead his level range is 72 - 81
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81 WHERE `entry`=31679;
-- Tunneling ghoul
UPDATE `creature_template` SET `lootid`=24084 WHERE `entry`=31681;
-- Dragonflayer runecaster
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=23960;
-- Dragonflayer strategist
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_flags`=`unit_flags`|131072 WHERE `entry`=32246;
-- Ingvar and undead Ingvar
UPDATE `creature_template` SET `mindmg`=650,`maxdmg`=900,`attackpower`=200, `dmg_multiplier`=10 WHERE `entry` IN(31673,31674);
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`|1  WHERE `entry` IN(23954,31673,23980,31674);
-- Throw axe dummy
UPDATE `creature_template` SET `unit_flags`=2|131072|33554432, `flags_extra`=`flags_extra`|2, `equipment_id`=720 WHERE `entry` IN(23997,31835);
-- Throw axe target
UPDATE `creature_template` SET `unit_flags`=2|4|256|512, `faction_A`=35, `faction_H`=35, `flags_extra`=`flags_extra`|128 WHERE `entry`=23996;

-- Dragonflayer runecaster
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=23960;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23960 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `id`, `event_type`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `target_type`, `target_param2`, `comment`) VALUES 
(23960,1,0,2,5000,7000,14000,17000,11,42740,11,30,'Dragonflayer Runecaster - In combat - Cast Njords Rune of Protection'),
(23960,2,0,4,5000,7000,14000,17000,11,59616,11,30,'Dragonflayer Runecaster - In combat - Cast Njords Rune of Protection'),
(23960,3,0,2,1000,2000,15000,18000,11,54965, 1, 0,'Dragonflayer Runecaster - In combat - Cast Bolthorns Rune of Flame'),
(23960,4,0,4,1000,2000,15000,18000,11,59617, 1, 0,'Dragonflayer Runecaster - In combat - Cast Bolthorns Rune of Flame');

-- Frenzied geist
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=28419;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28419 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`target_type`,`comment`) VALUES
(28419,0,5000,5000,30000,30000,11,40414,5,'Frenzied geist - In combat - Cast Fixate');

-- Difficulty data for spells used in utgarde keep
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN(42669,42708,42750,42723,42729,43667,42702) OR `spellid0` IN(42669,42708,42750,42723,42729,43667,42702);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(42669,42669,59706), -- Smash
(42708,42708,59708), -- Staggering Roar
(42750,42750,59719), -- Throw Axe
(42723,42723,59709), -- Dark Smash
(42729,42729,59734), -- Dreadful Roar
(43667,43667,59389), -- Shadow Bolt
(42702,42702,59397); -- Decrepify

-- Ticking Time Bomb, Fixate
DELETE FROM `spell_script_names` WHERE `spell_id` IN(59686,40414);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(59686,'spell_ticking_time_bomb'),
(40414,'spell_fixate');

-- Proto-drake striders
DELETE FROM `creature` WHERE `guid` IN(125940,125934,125915,125920,125914,125936,125937,125922);
INSERT INTO `creature`(`guid`,`id`,`map`,`spawnmask`,`modelid`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`curhealth`,`MovementType`) VALUES
(125914,24849,574,3,22287,212.429,-127.793,256.101,1.62166,3600,35928,2),
(125915,24849,574,3,22287,211.854,-112.602,262.188,1.61856,3600,35928,2),
(125920,24849,574,3,22287,211.024,-100.299,266.201,1.63628,3600,35928,2),
(125922,24849,574,3,22288,213.777,-140.709,251.048,1.72496,3600,35928,2),
(125934,24849,574,3,22287,252.247,-350.532,185.813,2.01344,3600,35928,2),
(125936,24849,574,3,22287,243.964,-194.833,227.126,2.88377,3600,35928,2),
(125937,24849,574,3,22288,221.534,-239.809,196.459,0.23628,3600,35928,2),
(125940,24849,574,3,22287,238.382,-353.086,188.785,1.29762,3600,35928,2);

-- Waypoint assignments
INSERT IGNORE INTO `creature_addon`(`guid`) VALUES
(125940),
(125934),
(125915),
(125920),
(125914),
(125936),
(125937),
(125922);

UPDATE `creature_addon` SET `path_id`=`guid`*10 WHERE `guid` IN(125940,125934,125915,125920,125914,125936,125937,125922);

-- Waypoint data
DELETE FROM `waypoint_data` WHERE `id` IN(1259400,1259340,1259150,1259200,1259140,1259360,1259370,1259220);
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES 
(1259400,1,211.864,-352.629,196.144),
(1259340,1,271.911,-318.506,185.049),
(1259150,1,265.478,-199.246,186.812),
(1259200,1,346.765,-99.2527,220.519),
(1259140,1,295.597,-181.162,207.374),
(1259360,1,271.68,-194.911,220.248),
(1259370,1,238.947,-255.704,191.639),
(1259220,1,149.42,-247.696,194.145);

INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`)
SELECT `guid`*10,2,`position_x`,`position_y`,`position_z` FROM `creature` WHERE `guid` IN(125940,125934,125915,125920,125914,125936,125937,125922);
