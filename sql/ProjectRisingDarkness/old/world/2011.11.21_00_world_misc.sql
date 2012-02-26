UPDATE `creature_template` SET `ScriptName`='npc_spring_rabbit' WHERE `entry`=32791;
UPDATE `achievement_criteria_data` SET `value1`=186 WHERE `criteria_id`=9199 AND `type`=6;
-- Fix Quest 'The Tome of Divinity' part 7 (1768)
-- Cleanup NPC
DELETE FROM `creature` WHERE `id` = 6172;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(81163, 6172, 0, 1, 1, 0, 0, -9129.59, -984.313, 76.1811, 2.05949, 180, 0, 0, 186, 191, 0, 0, 0, 0);
-- quest_template Changes 
UPDATE `quest_template` SET `ReqCreatureOrGOId1` = 6172, `ReqCreatureOrGOCount1` = 1, `ReqSpellCast1` = 8593 WHERE `entry` = 1786; 
-- creature_template - disable move
UPDATE `creature_template` SET `unit_flags` = `unit_flags` | 4 WHERE `entry` = 6172;
SET @GUID := 303000;
SET @GO_GUID := 400020;

-- torch toss target condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (46054,45732);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(13,45732,18,1,25535),
(13,46054,18,1,25535);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=45723;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(45723,43313,2, 'Torch Tossing - Target Indicator Visual');

UPDATE `creature_template` SET `ScriptName`='npc_torch_tossing_bunny' WHERE `entry`=25535;

UPDATE `quest_template` SET `RewOrReqMoney`=74000, `RewMoneyMaxLevel`=132300 WHERE `entry` IN (11731,11922);
UPDATE `quest_template` SET `PrevQuestId`=11731, `RewOrReqMoney`=74000, `RewMoneyMaxLevel`=132300 WHERE `entry`=11921;
UPDATE `quest_template` SET `PrevQuestId`=11922, `RewOrReqMoney`=74000, `RewMoneyMaxLevel`=132300 WHERE `entry`=11926;
UPDATE `quest_template` SET `StartScript`=11731 WHERE `entry` IN (11731,11922);
UPDATE `quest_template` SET `StartScript`=11921 WHERE `entry` IN (11921,11926);

-- add torch toss aura on quest accept
DELETE FROM `quest_start_scripts` WHERE `id` IN (11731,11921);
INSERT INTO `quest_start_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(11731,0,14,45724,0,0,0,0,0,0),
(11731,1,15,45716,0,0,0,0,0,0),
(11921,0,14,45724,0,0,0,0,0,0),
(11921,1,15,46630,0,0,0,0,0,0);

-- more objects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @GO_GUID AND @GO_GUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GO_GUID,'187708','0','1','1','-8822.4','846.766','99.0875','2.10363','0','0','0.868324','0.495997','300','0','1'),
(@GO_GUID+1,'187708','0','1','1','-8817.63','851.846','98.9217','2.93222','0','0','0.994525','0.104495','300','0','1'),
(@GO_GUID+2,'187708','0','1','1','-8816.68','854.946','98.9073','2.92043','0','0','0.993892','0.110354','300','0','1'),
(@GO_GUID+3,'187708','0','1','1','-8816.66','858.591','98.9913','3.1427','0','0','1','-0.000551387','300','0','1'),
(@GO_GUID+4,'300068','0','1','1','-8834.32','857.823','99.8395','6.0196','0','0','0.131411','-0.991328','300','0','1'),
(@GO_GUID+5,'187708','1','1','1','1913.57','-4315.85','23.1799','4.90635','0','0','0.635316','-0.772252','300','0','1'),
(@GO_GUID+6,'300068','1','1','1','1914.7','-4336.27','22.1744','1.01471','0','0','0.485865','0.874034','300','0','1');

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @GO_GUID AND @GO_GUID+6;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(1,@GO_GUID),
(1,@GO_GUID+1),
(1,@GO_GUID+2),
(1,@GO_GUID+3),
(1,@GO_GUID+4),
(1,@GO_GUID+5),
(1,@GO_GUID+6);

-- more bunnies
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID,'25535','0','1','1','0','0','-8825.75','845.668','100.848','2.15624','30','0','0','4120','0','0','0','0','0'),
(@GUID+1,'25535','0','1','1','0','0','-8822.48','846.841','100.883','2.2018','30','0','0','4120','0','0','0','0','0'),
(@GUID+2,'25535','0','1','1','0','0','-8819.42','848.453','100.745','2.70837','30','0','0','4120','0','0','0','0','0'),
(@GUID+3,'25535','0','1','1','0','0','-8817.56','851.801','100.717','2.7767','30','0','0','4120','0','0','0','0','0'),
(@GUID+4,'25535','0','1','1','0','0','-8816.67','854.896','100.703','2.9275','30','0','0','4120','0','0','0','0','0'),
(@GUID+5,'25535','0','1','1','0','0','-8816.57','858.57','100.787','3.28328','30','0','0','4120','0','0','0','0','0'),
(@GUID+6,'25535','1','1','1','0','0','1925.17','-4321.24','23.4473','4.69918','30','0','0','4120','0','0','0','0','0'),
(@GUID+7,'25535','1','1','1','0','0','1923.89','-4315.22','24.2852','4.59786','30','0','0','4120','0','0','0','0','0'),
(@GUID+8,'25535','1','1','1','0','0','1920.46','-4319.27','23.6163','5.01334','30','0','0','4120','0','0','0','0','0'),
(@GUID+9,'25535','1','1','1','0','0','1918.05','-4314.94','24.6482','5.04868','30','0','0','4120','0','0','0','0','0'),
(@GUID+10,'25535','1','1','1','0','0','1913.58','-4315.8','24.9737','5.22382','30','0','0','4120','0','0','0','0','0'),
(@GUID+11,'25535','1','1','1','0','0','1915.54','-4320.43','23.6154','5.09658','30','0','0','4120','0','0','0','0','0');

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @GUID AND @GUID+11;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(1,@GUID),
(1,@GUID+1),
(1,@GUID+2),
(1,@GUID+3),
(1,@GUID+4),
(1,@GUID+5),
(1,@GUID+6),
(1,@GUID+7),
(1,@GUID+8),
(1,@GUID+9),
(1,@GUID+10),
(1,@GUID+11);
-- apple trap workaround
UPDATE `creature_template` SET `modelid1`=11686, `minlevel`=30, `maxlevel`=30, `faction_A`=35, `faction_H`=35, `ScriptName`='npc_apple_trap_bunny' WHERE `entry`=24263;
-- bark quests credits
UPDATE `creature_template` SET `modelid1`=11686, `minlevel`=30, `maxlevel`=30, `ScriptName`='npc_bark_bunny' WHERE `entry` IN (24202,24203,24204,24205);
-- apply ram mount spell on quest accept
UPDATE `quest_template` SET `SrcSpell`=43883 WHERE `entry` IN (11409,11412,11318,11122,11293,11294,11407,11408);
-- temporary give more coins
UPDATE `quest_template` SET `RewItemCount1`=25 WHERE `entry` IN (11293,11294,11407,11408);
-- keg delivery npcs
UPDATE `creature_template` SET `ScriptName`='npc_keg_delivery' WHERE `entry` IN (24364,24527,24497,23558);
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry` IN (24497,23558);
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=24527;

-- threw keg (player) target condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=43662;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(13,43662,18,1,24468),
(13,43662,18,1,24510);

-- make quest 11122 completable
UPDATE `quest_template` SET `StartScript`=11122 WHERE `entry`=11122;

DELETE FROM `quest_start_scripts` WHERE `id`=11122;
INSERT INTO `quest_start_scripts` (`id`, `command`, `datalong`) VALUES
(11122,15,51798);

-- remove ram fatigue debuff
DELETE FROM `spell_linked_spell` WHERE `spell_effect`=-43052;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-43883,-43052,0, 'Remove Ram Fatigue with Rental Racing Ram');

-- some spawns
SET @guid := 303065;
SET @go_guid := 400045;

DELETE FROM `creature` WHERE `id` IN (24202,24203,24204,24205,24527,24263);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@guid,24202,1,1,1,0,0,1652.82,-4425.6,16.7553,1.94068,180,0,0,42,0,0,0,0,0),
(@guid+1,24202,0,1,1,0,0,-4919.44,-941.245,501.562,5.38547,180,0,0,42,0,0,0,0,0),
(@guid+2,24203,1,1,1,0,0,1933.84,-4676.55,27.6472,2.16765,180,0,0,42,0,0,0,0,0),
(@guid+3,24203,0,1,1,0,0,-4959.34,-1199.69,501.659,0.735904,180,0,0,42,0,0,0,0,0),
(@guid+4,24204,1,1,1,0,0,1927.43,-4298.46,25.3459,0.375365,180,0,0,42,0,0,0,0,0),
(@guid+5,24204,0,1,1,0,0,-4690.26,-1235.04,501.66,2.25665,180,0,0,42,0,0,0,0,0),
(@guid+6,24205,1,1,1,0,0,1573.16,-4202.9,43.1776,5.43725,180,0,0,42,0,0,0,0,0),
(@guid+7,24205,0,1,1,0,0,-4679.16,-968.932,501.658,3.88478,180,0,0,42,0,0,0,0,0),
(@guid+8,24527,1,1,1,22508,0,841.342,-4511.96,5.63413,0.134843,10,0,0,44,0,0,0,0,0),
(@guid+9,24263,1,1,1,0,0,1290.72,-4433.38,28.9128,2.38741,180,0,0,102,0,0,0,0,0),
(@guid+10,24263,1,1,1,0,0,1096.47,-4427.09,21.9768,0.600628,180,0,0,102,0,0,0,0,0),
(@guid+11,24263,1,1,1,0,0,1004.37,-4479.23,12.6481,1.44494,180,0,0,102,0,0,0,0,0),
(@guid+12,24263,1,1,1,0,0,813.71,-4550.15,6.76704,0.526026,180,0,0,102,0,0,0,0,0),
(@guid+13,24263,0,1,1,0,0,-5189.01,-482.731,389.012,3.23857,180,0,0,102,0,0,0,0,0),
(@guid+14,24263,0,1,1,0,0,-5355.19,-527.227,393.217,0.866664,180,0,0,102,0,0,0,0,0),
(@guid+15,24263,0,1,1,0,0,-5621.26,-477.593,398.716,6.23093,180,0,0,102,0,0,0,0,0),
(@guid+16,24263,0,1,1,0,0,-5492.14,-528.144,399.901,1.56881,180,0,0,102,0,0,0,0,0);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @go_guid AND @go_guid+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@go_guid,'186717','1','1','1','819.338','-4506.86','7.81105','5.85064','0','0','0.214592','-0.976704','300','0','1'),
(@go_guid+1,'186331','0','1','1','-5492.23','-528.114','398.163','1.502','0','0','0.68237','0.731007','300','0','1'),
(@go_guid+2,'186331','0','1','1','-5621.04','-477.656','396.981','6.13355','0','0','0.0747495','-0.997202','300','0','1'),
(@go_guid+3,'186331','1','1','1','813.684','-4550.35','4.98399','0.526033','0','0','0.259995','0.96561','300','0','1');
SET @guid := 303108;
SET @event := 85;

UPDATE `creature_template` SET `ScriptName`='npc_dark_iron_herald' WHERE `entry`=24536;
UPDATE `creature_template` SET `ScriptName`='npc_dark_iron_guzzler' WHERE `entry`=23709;
UPDATE `gameobject_questrelation` SET `id`=189989 WHERE `quest`=12020;
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `entry`=12020;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (3557,3558);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
('3557','0','0','0',''),
('3558','0','0','0','');

DELETE FROM `creature` WHERE `id`=24536;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@guid,'24536','1','1','1','0','0','1199.34','-4293.03','21.2255','2.15038','420','0','0','16026','0','0','0','0','0'),
(@guid+1,'24536','0','1','1','0','0','-5158.79','-604.12','398.199','5.00486','420','0','0','16026','0','0','0','0','0');

DELETE FROM `game_event_creature` WHERE `eventEntry`=@event;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@event,@guid),
(@event,@guid+1);

DELETE FROM `game_event` WHERE `eventEntry`=@event;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`) VALUES
(@event,'2010-09-20 00:00:00','2020-12-31 06:00:00','30','8','0','Braufest - Angriff der Dunkeleisenzwerge','0');

SET @entry := 86;
SET @guid := 303082;

-- add events
DELETE FROM `game_event` WHERE `eventEntry` BETWEEN @entry AND @entry+11;
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`) VALUES
(@entry,'2011-01-01 00:00:00','2020-12-31 06:00:00','525600','44640','0','Bier des Monats - Januar','0'),
(@entry+1,'2011-02-01 00:00:00','2020-12-31 06:00:00','525600','40320','0','Bier des Monats - Februar','0'),
(@entry+2,'2011-03-01 00:00:00','2020-12-31 06:00:00','525600','44640','0','Bier des Monats - Maerz','0'),
(@entry+3,'2011-04-01 00:00:00','2020-12-31 06:00:00','525600','43200','0','Bier des Monats - April','0'),
(@entry+4,'2011-05-01 00:00:00','2020-12-31 06:00:00','525600','44640','0','Bier des Monats - Mai','0'),
(@entry+5,'2011-06-01 00:00:00','2020-12-31 06:00:00','525600','43200','0','Bier des Monats - Juni','0'),
(@entry+6,'2011-07-01 00:00:00','2020-12-31 06:00:00','525600','44640','0','Bier des Monats - Juli','0'),
(@entry+7,'2011-08-01 00:00:00','2020-12-31 06:00:00','525600','44640','0','Bier des Monats - August','0'),
(@entry+8,'2011-09-01 00:00:00','2020-12-31 06:00:00','525600','43200','0','Bier des Monats - September','0'),
(@entry+9,'2011-10-01 00:00:00','2020-12-31 06:00:00','525600','44640','0','Bier des Monats - Oktober','0'),
(@entry+10,'2011-11-01 00:00:00','2020-12-31 06:00:00','525600','43200','0','Bier des Monats - November','0'),
(@entry+11,'2011-12-01 00:00:00','2020-12-31 06:00:00','525600','44640','0','Bier des Monats - Dezember','0');

-- npc corrections
UPDATE `creature_template` SET `gossip_menu_id`=9549, `minlevel`=50, `maxlevel`=50, `faction_A`=35, `faction_H`=35, `npcflag`=129,
       `unit_flags`=768, `equipment_id`=357, `ScriptName`='npc_brew_vendor' WHERE `name`='Brew Vendor';

-- spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @guid AND @guid+25;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@guid,'27478','0','1','1','0','356','-4849.93','-862.626','501.914','5.41091','10','0','0','2215','0','0','0','0','0'),
(@guid+1,'27489','1','1','1','22492','0','1490.75','-4221.22','43.1862','4.71535','10','0','0','2215','0','0','0','0','0'),
(@guid+2,'27806','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+3,'27806','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+4,'27810','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+5,'27810','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+6,'27811','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+7,'27811','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+8,'27812','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+9,'27812','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+10,'27813','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+11,'27813','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+12,'27814','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+13,'27814','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+14,'27815','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+15,'27815','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+16,'27816','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+17,'27816','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+18,'27817','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+19,'27817','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+20,'27818','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+21,'27818','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+22,'27819','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+23,'27819','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0'),
(@guid+24,'27820','0','1','1','0','357','-4845.5','-861.761','501.914','5.019','10','0','0','2215','0','0','0','0','0'),
(@guid+25,'27820','1','1','1','0','357','1491.61','-4227.44','43.1862','1.75085','10','0','0','2215','0','0','0','0','0');

-- creature event links
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @guid+2 AND @guid+25;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@entry,@guid+2),
(@entry,@guid+3),
(@entry+1,@guid+4),
(@entry+1,@guid+5),
(@entry+2,@guid+6),
(@entry+2,@guid+7),
(@entry+3,@guid+8),
(@entry+3,@guid+9),
(@entry+4,@guid+10),
(@entry+4,@guid+11),
(@entry+5,@guid+12),
(@entry+5,@guid+13),
(@entry+6,@guid+14),
(@entry+6,@guid+15),
(@entry+7,@guid+16),
(@entry+7,@guid+17),
(@entry+8,@guid+18),
(@entry+8,@guid+19),
(@entry+9,@guid+20),
(@entry+9,@guid+21),
(@entry+10,@guid+22),
(@entry+10,@guid+23),
(@entry+11,@guid+24),
(@entry+11,@guid+25);

-- missing brew vendor items
DELETE FROM `npc_vendor` WHERE `entry` IN (27806,27810,27811,27812,27815,27816,27817);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
('27806','0','37488','0','0','0'),
('27810','0','37489','0','0','0'),
('27811','0','37490','0','0','0'),
('27812','0','37491','0','0','0'),
('27815','0','37494','0','0','0'),
('27816','0','37495','0','0','0'),
('27817','0','37496','0','0','0');
