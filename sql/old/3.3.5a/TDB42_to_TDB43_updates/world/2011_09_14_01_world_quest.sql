-- Quest 12983 "Last of Her Kind"

-- Add Injured Icemaw Matriarch
DELETE FROM `creature` WHERE `id`=29563;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(152124,29563,571,1,1,0,0,7335.381,-2055.097,764.3585,3.368485,120,0,0,1,0,0,0,0,0);
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry`=29563; -- Injured Icemaw Matriarch
-- SAI for Harnessed Icemaw Matriarch
SET @ENTRY := 30468;
UPDATE `creature_template` SET `AIName`='SmartAI', `faction_A`=35, `faction_H`=35 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,27,0,100,0,0,0,0,0,53,1,@ENTRY,0,12983,0,0,1,0,0,0,0,0,0,0, 'Harnessed Icemaw Matriarch - On Passenger - Start WP movement'),
(@ENTRY,0,1,0,40,0,100,0,1,@ENTRY,0,0,18,130,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harnessed Icemaw Matriarch - Reach Waypoint - Make Unatackable'),
(@ENTRY,0,2,0,40,0,100,0,50,@ENTRY,0,0,33,29563,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Harnessed Icemaw Matriarch - Reach Waypoint - Quest Credit'),
(@ENTRY,0,3,0,40,0,100,0,51,@ENTRY,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Harnessed Icemaw Matriarch - Reach Waypoint - Despawn');
-- Waypoints for Harnessed Icemaw Matriarch
DELETE FROM `waypoints` WHERE `entry`=30468;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(30468,1,7339.617,-2058.659,764.919,'Harnessed Icemaw Matriarch'),
(30468,2,7338.267,-2064.381,765.3577,'Harnessed Icemaw Matriarch'),
(30468,3,7335.772,-2073.805,767.4077,'Harnessed Icemaw Matriarch'),
(30468,4,7327.591,-2087.35,770.8978,'Harnessed Icemaw Matriarch'),
(30468,5,7319.448,-2095.41,773.6814,'Harnessed Icemaw Matriarch'),
(30468,6,7305.165,-2107.299,774.3261,'Harnessed Icemaw Matriarch'),
(30468,7,7275.178,-2114.627,775.6678,'Harnessed Icemaw Matriarch'),
(30468,8,7258.999,-2116.149,778.5131,'Harnessed Icemaw Matriarch'),
(30468,9,7241.648,-2119.356,777.7652,'Harnessed Icemaw Matriarch'),
(30468,10,7226.729,-2115.936,777.3341,'Harnessed Icemaw Matriarch'),
(30468,11,7208.441,-2115.223,770.9512,'Harnessed Icemaw Matriarch'),
(30468,12,7198.355,-2115.354,767.3314,'Harnessed Icemaw Matriarch'),
(30468,13,7193.219,-2115.251,765.6339,'Harnessed Icemaw Matriarch'),
(30468,14,7188.855,-2117.307,763.8766,'Harnessed Icemaw Matriarch'),
(30468,15,7177.065,-2123.511,762.9337,'Harnessed Icemaw Matriarch'),
(30468,16,7163.708,-2131.039,762.1168,'Harnessed Icemaw Matriarch'),
(30468,17,7146.599,-2130.739,762.0986,'Harnessed Icemaw Matriarch'),
(30468,18,7127.765,-2130.799,760.3064,'Harnessed Icemaw Matriarch'),
(30468,19,7130.188,-2108.955,761.6824,'Harnessed Icemaw Matriarch'),
(30468,20,7122.738,-2087.617,763.7275,'Harnessed Icemaw Matriarch'),
(30468,21,7114.396,-2070.318,765.9775,'Harnessed Icemaw Matriarch'),
(30468,22,7101.815,-2051.608,765.8251,'Harnessed Icemaw Matriarch'),
(30468,23,7091.483,-2031.099,765.8953,'Harnessed Icemaw Matriarch'),
(30468,24,7087.403,-2012.366,767.2703,'Harnessed Icemaw Matriarch'),
(30468,25,7081.406,-1985.07,767.9617,'Harnessed Icemaw Matriarch'),
(30468,26,7073.832,-1961.028,769.3597,'Harnessed Icemaw Matriarch'),
(30468,27,7068.839,-1934.135,775.7347,'Harnessed Icemaw Matriarch'),
(30468,28,7064.366,-1916.702,781.6978,'Harnessed Icemaw Matriarch'),
(30468,29,7070.385,-1906.559,785.4976,'Harnessed Icemaw Matriarch'),
(30468,30,7079.504,-1899.025,787.0339,'Harnessed Icemaw Matriarch'),
(30468,31,7085.339,-1887.627,788.9089,'Harnessed Icemaw Matriarch'),
(30468,32,7067.585,-1884.709,793.0339,'Harnessed Icemaw Matriarch'),
(30468,33,7041.699,-1884.614,797.4276,'Harnessed Icemaw Matriarch'),
(30468,34,7029.2,-1871.599,803.4189,'Harnessed Icemaw Matriarch'),
(30468,35,7025.071,-1858.876,811.2399,'Harnessed Icemaw Matriarch'),
(30468,36,7018.791,-1838.968,820.2399,'Harnessed Icemaw Matriarch'),
(30468,37,7011.697,-1814.383,820.7299,'Harnessed Icemaw Matriarch'),
(30468,38,7009.096,-1791.501,820.7303,'Harnessed Icemaw Matriarch'),
(30468,39,7017.041,-1758.968,819.6544,'Harnessed Icemaw Matriarch'),
(30468,40,7013.258,-1723.917,819.8597,'Harnessed Icemaw Matriarch'),
(30468,41,6995.103,-1720.753,820.1116,'Harnessed Icemaw Matriarch'),
(30468,42,6975.483,-1722.112,820.7366,'Harnessed Icemaw Matriarch'),
(30468,43,6959.883,-1724.389,820.5955,'Harnessed Icemaw Matriarch'),
(30468,44,6941.025,-1720.429,820.5955,'Harnessed Icemaw Matriarch'),
(30468,45,6920.026,-1709.558,820.7527,'Harnessed Icemaw Matriarch'),
(30468,46,6902.995,-1697.53,820.6683,'Harnessed Icemaw Matriarch'),
(30468,47,6886.746,-1682.953,820.2584,'Harnessed Icemaw Matriarch'),
(30468,48,6867.681,-1684.361,819.8834,'Harnessed Icemaw Matriarch'),
(30468,49,6847.065,-1695.642,819.9857,'Harnessed Icemaw Matriarch'),
(30468,50,6824.819,-1701.835,820.6398,'Harnessed Icemaw Matriarch'),
(30468,51,6824.819,-1701.835,820.5497,'Harnessed Icemaw Matriarch');

-- Phasing Spell
DELETE FROM `spell_area` WHERE `spell`=55857 AND `area`=4455;
INSERT INTO `spell_area`(`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(55857,4455,12983,1,12983,0,0,2,1);

-- From Nay:
-- TODO: Respawn the whole cave, lots of shit wrong (phasemasks etc)
UPDATE `creature` SET `phaseMask`=2 WHERE `id`=29563;
DELETE FROM `creature_template_addon` WHERE `entry`=30468;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30468,0,0,1,0, NULL); -- Harnessed Icemaw Matriarch
