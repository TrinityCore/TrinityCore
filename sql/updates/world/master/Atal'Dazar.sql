-- Dazar'ai Augur
SET @ENTRY := 122972;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,253562,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wildfire'),
(@ENTRY,0,1,0,2,0,100,1,0,55,0,0,11,254974,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gathered Souls at 55% HP');

-- Dazar'ai Colossus
SET @ENTRY := 122984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,254959,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soulburn'),
(@ENTRY,0,1,0,2,0,100,1,0,55,0,0,11,254958,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Soulforged Construct at 55% HP');

-- Dazar'ai Confessor
SET @ENTRY := 122973;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,253526,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Dispel'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,253517,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mending Word at 40% HP'),
(@ENTRY,0,2,0,14,0,100,0,40000,40,15000,18000,11,253517,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Mending Word on Friendlies'),
(@ENTRY,0,3,0,2,0,100,1,0,55,0,0,11,254974,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gathered Souls at 55% HP');

-- Dazar'ai Honor Guard
SET @ENTRY := 127799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,256138,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fervent Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,55,0,0,11,254974,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gathered Souls at 55% HP');

-- Dazar'ai Juggernaut
SET @ENTRY := 122971;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,253239,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Merciless Assault'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,255824,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fanatic\'s Rage at 30% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,55,0,0,11,254974,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gathered Souls at 55% HP');

-- Dinomancer Kish'o
SET @ENTRY := 129553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,256846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadeye Aim'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP'),
(@ENTRY,0,2,0,14,0,100,0,50000,40,15000,18000,11,256849,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Dino Might on Friendlies'),
(@ENTRY,0,3,0,0,0,100,0,0,0,2000,2000,11,256864,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Quickshot');

-- Feasting Skyscreamer
SET @ENTRY := 128434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,255041,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrifying Screech'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP');

-- Gilded Priestess
SET @ENTRY := 132126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,260666,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Transfusion');

-- Monzumi
SET @ENTRY := 129552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,256882,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wild Thrash'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP');

-- Priestess Alun'za
SET @ENTRY := 122967;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,260666,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Transfusion'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,255579,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gilded Claws');

-- Reanimated Honor Guard
SET @ENTRY := 127757;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,272631,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Battering Maul'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,256959,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rotting Decay');

-- Reanimation Totem
SET @ENTRY := 127315;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,258653,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju');

-- Rezan
SET @ENTRY := 122963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,255434,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serrated Teeth'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,257407,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Pursuit'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,10000,11,255421,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devour'),
(@ENTRY,0,3,0,2,0,100,0,0,55,15000,15000,11,255373,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tail at 55% HP'),
(@ENTRY,0,4,0,2,0,100,0,0,40,22000,25000,11,255371,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrifying Visage at 40% HP');

-- Shadowblade Razi
SET @ENTRY := 130912;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,258978,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cruel Blade'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2500,3000,11,258979,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stink Bomb'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,259097,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vanish at 40% HP');

-- Shadowblade Stalker
SET @ENTRY := 122970;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,252661,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Venom-Tipped Blade on Spawn'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,252692,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Waylaying Jab');

-- Shadowblade Stalker
SET @ENTRY := 131089;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,11,0,100,1,0,0,0,0,11,207707,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,207707,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,252661,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Venom-Tipped Blade');

-- Shieldbearer of Zul
SET @ENTRY := 127879;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,273185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP');

-- Shieldbearer of Zul
SET @ENTRY := 135989;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,273185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP');

-- T'lonja
SET @ENTRY := 128455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,255567,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frenzied Charge'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP');

-- Toxic Saurid
SET @ENTRY := 128435;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,251187,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Thrash'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP');

-- Vol'kaal
SET @ENTRY := 122965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,250372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lingering Nausea'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,259572,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Noxious Stench'),
(@ENTRY,0,2,0,2,0,100,1,0,20,0,0,11,250241,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Decay at 20% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,20000,10000,20000,11,250258,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Toxic Leap');

-- Wild Skyscreamer
SET @ENTRY := 122986;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,255041,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrifying Screech');

-- Yazma
SET @ENTRY := 122968;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,249919,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skewer'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,256577,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Soulfeast'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,250050,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Echoes of Shadra at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,4000,15000,5000,20000,11,250096,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wracking Pain');

-- Zanchuli Witch-Doctor
SET @ENTRY := 252923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,252923,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Blast'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,18000,20000,11,279118,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Unstable Hex'),
(@ENTRY,0,2,0,2,0,100,1,0,20,0,0,11,258653,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark of Juju at 20% HP');