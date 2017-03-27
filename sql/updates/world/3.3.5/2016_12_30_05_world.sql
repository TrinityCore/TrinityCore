-- 1st Kvaldir Vessel (The Serpent's Maw) SAI
SET @ENTRY := 25510;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,45692,0,0,0,33,25510,0,0,0,0,0,7,0,0,0,0,0,0,0,"1st Kvaldir Vessel (The Serpent's Maw) - On Spellhit 'Use Tuskarr Torch' - Quest Credit 'Burn in Effigy'"),
(@ENTRY,0,1,2,61,0,100,0,45692,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"1st Kvaldir Vessel (The Serpent's Maw) - On Spellhit 'Use Tuskarr Torch' - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3043.885,6745.263,10.34062,6.143561,"1st Kvaldir Vessel (The Serpent's Maw) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,3,4,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3049.331,6757.823,5.417898,5.358162,"1st Kvaldir Vessel (The Serpent's Maw) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,4,5,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3054.117,6764.733,3.606305,1.500983,"1st Kvaldir Vessel (The Serpent's Maw) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,5,6,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3053.359,6773.643,3.813772,2.426008,"1st Kvaldir Vessel (The Serpent's Maw) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,6,0,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3064.19,6785.298,8.44076,4.049168,  "1st Kvaldir Vessel (The Serpent's Maw) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'");



-- 2nd Kvaldir Vessel (The Kur Drakkar) SAI
SET @ENTRY := 25511;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,45692,0,0,0,33,25511,0,0,0,0,0,7,0,0,0,0,0,0,0,"2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit 'Use Tuskarr Torch' - Quest Credit 'Burn in Effigy'"),
(@ENTRY,0,1,2,61,0,100,0,45692,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit 'Use Tuskarr Torch' - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3025.193,6784.228,8.375009,6.03884, "2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,3,4,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3035.19,6794.023,4.210261,3.839725, "2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,4,5,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3044.207,6799.383,3.345489,4.782203,"2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,5,6,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3056.192,6807.476,7.09576,0.8726639,"2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,6,0,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,3043.326,6791.393,3.042087,4.485497,"2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'");

-- 3rd Kvaldir Vessel (Bor's Hammer) SAI
SET @ENTRY := 25512;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,45692,0,0,0,33,25512,0,0,0,0,0,7,0,0,0,0,0,0,0,"3rd Kvaldir Vessel (Bor's Hammer) - On Spellhit 'Use Tuskarr Torch' - Quest Credit 'Burn in Effigy'"),
(@ENTRY,0,1,2,61,0,100,0,45692,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"3rd Kvaldir Vessel (Bor's Hammer) - On Spellhit 'Use Tuskarr Torch' - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,2877.174,6855.259,15.0139,4.363324,  "3rd Kvaldir Vessel (Bor's Hammer) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,3,4,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,2867.662,6862.611,3.956,3.263772,    "3rd Kvaldir Vessel (Bor's Hammer) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,4,5,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,2862.167,6871.526,2.134927,0.9773831,"3rd Kvaldir Vessel (Bor's Hammer) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,5,6,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,2866.583,6875.242,2.717505,4.694937, "3rd Kvaldir Vessel (Bor's Hammer) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,6,0,61,0,100,0,45692,0,0,0,50,187704,60,0,0,0,0,8,0,0,0,2852.196,6875.289,1.91545,4.084071,  "3rd Kvaldir Vessel (Bor's Hammer) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'");

-- 4th Kvaldir Vessel (Bor's Anvil) SAI
SET @ENTRY := 25513;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,45692,0,0,0,33,25513,0,0,0,0,0,7,0,0,0,0,0,0,0,"4th Kvaldir Vessel (Bor's Anvil) - On Spellhit 'Use Tuskarr Torch' - Quest Credit 'Burn in Effigy'"),
(@ENTRY,0,1,2,61,0,100,0,45692,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"4th Kvaldir Vessel (Bor's Anvil) - On Spellhit 'Use Tuskarr Torch' - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,45692,0,0,0,50,187703,60,0,0,0,0,8,0,0,0,2515.687,6852.452,3.775909,5.166176,"4th Kvaldir Vessel (Bor's Anvil) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,3,4,61,0,100,0,45692,0,0,0,50,187703,60,0,0,0,0,8,0,0,0,2524.152,6848.546,5.444669,1.937312,"4th Kvaldir Vessel (Bor's Anvil) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,4,5,61,0,100,0,45692,0,0,0,50,187703,60,0,0,0,0,8,0,0,0,2524.671,6853.061,4.362841,3.42085, "4th Kvaldir Vessel (Bor's Anvil) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,5,6,61,0,100,0,45692,0,0,0,50,187703,60,0,0,0,0,8,0,0,0,2522.521,6851.036,4.778915,3.769912,"4th Kvaldir Vessel (Bor's Anvil) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'"),
(@ENTRY,0,6,0,61,0,100,0,45692,0,0,0,50,187703,60,0,0,0,0,8,0,0,0,2520.258,6846.322,5.93863,1.570796, "4th Kvaldir Vessel (Bor's Anvil) - On Spellhit 'Use Tuskarr Torch' - Summon Gameobject 'Kvaldir Inferno'");
