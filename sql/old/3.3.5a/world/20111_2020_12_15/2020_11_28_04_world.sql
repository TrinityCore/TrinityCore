--
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (21233,22461,5202,28408,9496,16364,22331,19399,22451,30066);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(21233,1,1,0,1,0,0),
(22461,1,1,0,1,0,0),
(5202,1,1,0,1,0,0),
(28408,1,1,0,1,0,0),
(9496,1,1,0,1,0,0),
(16364,1,1,0,1,0,0),
(22331,1,1,0,1,0,0),
(19399,1,1,0,1,0,0),
(22451,1,1,0,1,0,0),
(30066,1,1,0,1,0,0);

-- Legion Fel Cannon
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21233 AND `source_type` = 0 AND `id` = 0;
-- Fel Cannon MKI
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22461 AND `source_type` = 0 AND `id` = 0;
-- Archery Target
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 5202;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 5202 AND `source_type` = 0 AND `id` = 0;
-- Primordial Drake Egg
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` = 28408;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28408 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28408 AND `source_type` = 0 AND `id` = 1;
UPDATE `smart_scripts` SET `target_type` = 1 WHERE `entryorguid` = 28408 AND `source_type` = 0 AND `id` = 2;

-- Clutchmother Zavas / Gorishi Egg - https://www.youtube.com/watch?v=7RBhciA_S1M https://youtu.be/EiQ4t_c7OvM?t=36
UPDATE `smart_scripts` SET `link` = 3, `event_param1` = 8000 WHERE `entryorguid` = 6582 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 6582 AND `source_type` = 0 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6582,0,3,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Clutchmother Zavas - On Link - Say Line 0"),
(6582,0,4,0,2,0,100,1,0,20,0,0,0,39,20,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Clutchmother Zavas - Between 0-20% Health - Call for Help (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = 6582;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(6582,0,0,"%s lays an egg!",16,0,100,0,0,0,1408,0,"Clutchmother Zavas");

-- Gorishi Egg SAI
SET @ID := 9496;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,949600,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gorishi Egg - On Just Summoned - Run Script"),

-- Besides root and prevent melee flag we also have to make him passive or he'll act like normal creature
-- There's no passive flag for him in CreatureDifficulty, unfortunately
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gorishi Egg - On Script - Set Reactstate Passive"),
(@ID*100+0,9,1,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gorishi Egg - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gorishi Egg - On Script - Say Line 1"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,11,14206,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gorishi Egg - On Script - Cast 'Summon Gorishi Grub'"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gorishi Egg - On Script - Cast 'Suicide'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s begins to crack and open...",16,0,100,0,0,0,1409,0,"Gorishi Egg"),
(@ID,1,0,"%s splits open!",16,0,100,0,0,0,1410,0,"Gorishi Egg");

-- Infused Crystal SAI (Source: Sniffs)
SET @ID := 16364;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ID*100+0,@ID*100+1,@ID*100+2) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,80,1636400,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infused Crystal - On Just Summoned - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infused Crystal - On Script - Set Reactstate Passive"),
(@ID*100+0,9,1,0,0,0,100,0,3000,3000,0,0,0,107,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infused Crystal - On Script - Summon Group 0"),
(@ID*100+0,9,2,0,0,0,100,0,30000,30000,0,0,0,107,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infused Crystal - On Script - Summon Group 1"),
(@ID*100+0,9,3,0,0,0,100,0,30000,30000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infused Crystal - On Script - Say Line 0"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,33,16364,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Infused Crystal - On Script - Quest Credit 'Powering our Defenses'"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infused Crystal - On Script - Despawn (1000)");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 16364 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(16364,0,0,17086,8250.8076171875,-7239.40380859375,139.6404571533203125,0.678725242614746093,4,60000,"Infused Crystal - Group 0 - Enraged Wraith"),
(16364,0,0,17086,8263.35546875,-7181.14501953125,139.39434814453125,5.212749481201171875,4,60000,"Infused Crystal - Group 0 - Enraged Wraith"),
(16364,0,0,17086,8317.5205078125,-7209.08251953125,140.08746337890625,2.422304868698120117,4,60000,"Infused Crystal - Group 0 - Enraged Wraith"),
(16364,0,1,17086,8294.1650390625,-7178.41748046875,138.3867340087890625,4.10486602783203125,4,60000,"Infused Crystal - Group 1 - Enraged Wraith"),
(16364,0,1,17086,8238.513671875,-7207.8955078125,139.0634613037109375,6.230448722839355468,4,60000,"Infused Crystal - Group 1 - Enraged Wraith"),
(16364,0,1,17086,8301.7294921875,-7248.2373046875,140.0468902587890625,1.828517556190490722,4,60000,"Infused Crystal - Group 1 - Enraged Wraith");

UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 0.85714285714, `BaseAttackTime` = 2000, `RegenHealth` = 0, `unit_flags2` = 0 WHERE `entry` = 16364;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 0.85714285714, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000 WHERE `entry` = 17086;
-- Using non-existing creature at the moment when the quest was created is always a bad idea
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23837 AND `source_type` = 0 AND `id` IN (3,4);

-- Dragonmaw Elite, remove flee too, rooted with that flag creatures probably never can unroot
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22331 AND `source_type` = 0 AND `id` IN (0,4);

-- Fel Cannon
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 19399;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19399 AND `source_type` = 0 AND `id` = 0;

-- Legion Fel Cannon MKII - unused
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 22451;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22451 AND `source_type` = 0;

-- Valkyrion Harpoon Gun
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30066 AND `source_type` = 0 AND `id` = 0;
