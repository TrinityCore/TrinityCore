DELETE FROM `creature` WHERE `id` IN (36610,36731,36477,36658,31260); -- Delete Temp Trigger Spawns

-- DB Data (souce: SNIFF)
UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80,`unit_flags`=0x02008000,`faction_A`=14,`faction_H`=14,`flags_extra`=`flags_extra`|0x80 WHERE `entry`=37670; -- Frostblade
UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80,`flags_extra`=`flags_extra`|0x80 WHERE `entry`=36610; -- Exploding Orb
UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80,`scale`=1.1,`flags_extra`=`flags_extra`|0x80 WHERE `entry`=36731; -- Icy Blast
UPDATE `creature_template` SET `speed_run`=1.857143,`speed_walk`=3.2,`unit_flags`=0x00000040,`faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`equipment_id`=1872 WHERE `entry` IN (36658,36938); -- Scourgelord Tyrannus
UPDATE `creature_template` SET `speed_run`=1.5873,`speed_walk`=2,`unit_flags`=0x00000040 WHERE `entry`=36661; -- Rimefang
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x80 WHERE `entry`=36495; -- Forgemaster Putridus Invisible Stalker
UPDATE `creature_template` SET `VehicleId`=560 WHERE `entry`=37626; -- Iceborn Protodrake (1)

-- SAI for Plagueborn Horror
SET @ENTRY := 36879;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,10000,10000,11,69581,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Pustulant Flesh on Random Target (Non-Heroic)'),
(@ENTRY,0,1,0,0,0,100,4,5000,5000,10000,10000,11,70273,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Pustulant Flesh on Random Target (Heroic)'),
(@ENTRY,0,2,0,0,0,100,6,8000,8000,8000,8000,11,70274,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Toxic Waste on Random Target'),
(@ENTRY,0,3,0,2,0,100,6,15,15,0,0,11,69582,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cast Blight Bomb self at 15pct Health');

-- SAI for Hungering Ghoul
SET @ENTRY := 37711;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,6000,8000,12000,11,70393,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Devour Flesh on current Target');

-- SAI for Deathwhisper Shadowcaster
SET @ENTRY := 37712;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,100,100,3000,3000,11,70386,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Shadow Bolt on current Target (Non-Heroic)'),
(@ENTRY,0,1,0,0,0,100,4,100,100,3000,3000,11,70387,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Shadow Bolt on current Target (Heroic)');

-- SAI for Deathwhisper Torturer
SET @ENTRY := 37713;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,10000,10000,10000,11,70392,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Black Brand on current Target'),
(@ENTRY,0,1,0,0,0,100,6,6000,6000,13000,13000,11,70391,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Curse of Agony on Random Target');

-- SAI for Ymirjar Wrathbringer
SET @ENTRY := 36840;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,7000,8000,8000,11,69603,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Blight on Random Target (Non-Heroic)'),
(@ENTRY,0,1,0,0,0,100,4,7000,7000,8000,8000,11,70285,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Blight on Random Target (Heroic)');

-- SAI for Stonespine Gargoyle
SET @ENTRY := 36896;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,5000,5000,11,69520,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Gargoyle Strike on current Target (Non-Heroic)'),
(@ENTRY,0,1,0,0,0,100,4,1000,1000,5000,5000,11,70275,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Gargoyle Strike on current Target (Heroic)'),
(@ENTRY,0,2,0,2,0,100,6,10,10,0,0,11,69575,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cast Stoneform self at 10pct Health');

-- SAI for Wrathbone Sorcerer
SET @ENTRY := 37728;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,8000,8000,11,75330,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Shadow Bolt on current Target (Non-Heroic)'),
(@ENTRY,0,1,0,0,0,100,4,3000,3000,8000,8000,11,75331,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Shadow Bolt on current Target (Heroic)');

-- SAI for Wrathbone Coldwraith
SET @ENTRY := 36842;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,100,100,3000,3000,11,69573,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Frostbolt on current Target (Non-Heroic)'),
(@ENTRY,0,1,0,0,0,100,4,100,100,3000,3000,11,70277,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Frostbolt on current Target (Heroic)'),
(@ENTRY,0,2,0,0,0,100,2,9000,9000,15000,15000,11,69574,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Freezing Circle on current Target (Non-Heroic)'),
(@ENTRY,0,3,0,0,0,100,4,9000,9000,15000,15000,11,70276,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Freezing Circle on current Target (Heroic)');

-- SAI for Deathwhisper Necrolyte
SET @ENTRY := 36788;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,100,100,3000,3000,11,69577,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Shadow Bolt on current Target (Non-Heroic)'),
(@ENTRY,0,1,0,0,0,100,4,100,100,3000,3000,11,70270,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Shadow Bolt on current Target (Heroic)'),
(@ENTRY,0,2,0,0,0,100,2,9000,9000,24000,24000,11,69578,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Conversion Beam on Random Target (Non-Heroic)'),
(@ENTRY,0,3,0,0,0,100,4,9000,9000,24000,24000,11,70269,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Conversion Beam on Random Target (Heroic)');

-- SAI for Fallen Warrior
SET @ENTRY := 36841;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,7000,8000,11,69579,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Arcing Slice to current Target'),
(@ENTRY,0,1,0,0,0,100,6,15000,15000,22000,22000,11,61044,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cast Demoralizing Shout'),
(@ENTRY,0,2,0,0,0,100,6,22000,22000,25000,25000,11,69580,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cast Shield Block');

-- SAI for Fallen Warrior 2
SET @ENTRY := 38487;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,7000,8000,11,69579,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Arcing Slice to current Target'),
(@ENTRY,0,1,0,0,0,100,6,15000,15000,22000,22000,11,61044,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cast Demoralizing Shout'),
(@ENTRY,0,2,0,0,0,100,6,22000,22000,25000,25000,11,69580,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cast Shield Block');

-- SAI for Ymirjar Skycaller
SET @ENTRY := 31260;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4000,8000,8000,11,70292,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Glacial Strike on current Target'),
(@ENTRY,0,1,0,2,0,100,6,50,50,0,0,11,70291,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Frostblade on Random Target at 50pct Health');

-- SAI for Frostblade
SET @ENTRY := 37670;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,0,0,11,70306,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Cast Frostblade self');

-- SAI for Ymirjar Deathbringer
SET @ENTRY := 36892;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,8000,8000,11,69528,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Empowered Shadow Bolt on Random Target (Non-Heroic)'),
(@ENTRY,0,1,0,0,0,100,4,4000,4000,8000,8000,11,70281,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Cast Empowered Shadow Bolt on Random Target (Heroic)');
