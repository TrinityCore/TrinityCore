-- Gnarlhide SAI
SET @ENTRY := 30003;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,38391,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gnarlhide - Combat CMC - Cast 'Scorch'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,20000,25000,11,60290,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gnarlhide - Combat - Cast 'Blast Wave'"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,19000,24000,11,35250,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gnarlhide - Combat - Cast 'Dragon's Breath'"),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,9000,12000,11,20832,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gnarlhide - Combat - Cast 'Fire Blast'");

-- Yulda the Stormspeaker SAI
SET @ENTRY := 30046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,32018,64,0,0,0,0,2,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Combat CMC - Cast 'Call Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,15000,18000,11,55087,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yulda the Stormspeaker - Combat - Cast 'Typhoon'");

-- Sigrid Iceborn SAI
SET @ENTRY := 30086;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,61168,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sigrid Iceborn - Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,13000,16700,11,61164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sigrid Iceborn - Combat - Cast 'Impale'"),
(@ENTRY,0,2,0,13,0,100,0,12000,18000,0,0,11,57635,0,0,0,0,0,6,1,0,0,0,0,0,0,"Sigrid Iceborn - Target Casting - Cast 'Disengage'"),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,61165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - Out of Combat - Cast 'Frostbite Weapon'"),
(@ENTRY,0,4,5,62,0,100,0,9870,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Set Invincibility Hp 1"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Remove Flags Immune To Players & Immune To NPC's"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - On Gossip Option 0 Selected - Say Line 0"),
(@ENTRY,0,9,10,2,0,100,0,0,1,0,0,33,30086,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sigrid Iceborn - Between 0-1% Health - Quest Credit 'Eliminate the Competition'"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - Between 0-1% Health - Set Faction 0"),
(@ENTRY,0,11,12,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - Between 0-1% Health - Say Line 1"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sigrid Iceborn - Between 0-1% Health - Evade");

-- Twilight Worshipper SAI
SET @ENTRY := 30111;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Worshipper - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,5000,8000,11,61567,64,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - Combat CMC - Cast 'Fireball' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,14000,17000,11,56858,1,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - Combat - Cast 'Flamestrike' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,14000,17000,11,61568,1,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Worshipper - Combat - Cast 'Flamestrike' (Heroic Dungeon)");

-- Onu'zun SAI
SET @ENTRY := 30180;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,15242,64,0,0,0,0,2,0,0,0,0,0,0,0,"Onu'zun - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,14500,17800,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onu'zun - Combat - Cast 'Cone of Cold'"),
(@ENTRY,0,3,0,13,0,100,0,12000,18000,0,0,11,15122,0,0,0,0,0,6,1,0,0,0,0,0,0,"Onu'zun - Target Casting - Cast 'Counterspell'"),
(@ENTRY,0,4,5,62,0,100,0,9878,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Set Invincibility Hp 1"),
(@ENTRY,0,6,7,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Remove Flags Immune To Players & Immune To NPC's"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Set Faction 14"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - On Gossip Option 0 Selected - Say Line 0"),
(@ENTRY,0,9,10,2,0,100,0,0,1,0,0,33,30180,0,0,0,0,0,7,0,0,0,0,0,0,0,"Onu'zun - Between 0-1% Health - Quest Credit 'Eliminate the Competition'"),
(@ENTRY,0,10,11,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - Between 0-1% Health - Set Faction 0"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onu'zun - Between 0-1% Health - Evade");

-- Sunreaver Scout SAI
SET @ENTRY := 30233;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Scout - Within 5-30 Range - Cast 'Multi-Shot'");

-- Silver Covenant Scout SAI
SET @ENTRY := 30238;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Scout - Within 5-30 Range - Cast 'Multi-Shot'");

-- Silver Covenant Horseman SAI
SET @ENTRY := 30263;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Horseman - Within 5-30 Range - Cast 'Multi-Shot'");

-- Sunreaver Hawkrider SAI
SET @ENTRY := 30265;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,8000,13000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,15000,25000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Hawkrider - Within 5-30 Range - Cast 'Multi-Shot'");

-- Ahn'kahar Spell Flinger SAI
SET @ENTRY := 30278;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,23000,27000,11,56698,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Combat CMC - Cast 'Shadow Blast' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,23000,27000,11,59102,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Combat CMC - Cast 'Shadow Blast' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,14000,13000,16000,11,56702,65,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Combat CMC - Cast 'Shadow Sickle' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,10000,14000,13000,16000,11,59103,65,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Spell Flinger - Combat CMC - Cast 'Shadow Sickle' (Heroic Dungeon)");

-- Eye of Taldaram SAI
SET @ENTRY := 30285;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,17439,64,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Combat CMC - Cast 'Shadow Shock' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,17289,64,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Combat CMC - Cast 'Shadow Shock' (Heroic Dungeon)"),
(@ENTRY,0,2,0,13,0,100,3,0,0,0,0,11,56730,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eye of Taldaram - Target Casting - Cast 'Dark Counterspell' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,3,0,13,0,100,5,0,0,0,0,11,59111,0,0,0,0,0,7,0,0,0,0,0,0,0,"Eye of Taldaram - Target Casting - Cast 'Dark Counterspell' (No Repeat) (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,15000,19000,23000,27000,11,56728,1,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Combat - Cast 'Eyes in the Dark' (Dungeon)"),
(@ENTRY,0,5,0,6,0,100,3,0,0,0,0,11,56733,7,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Just Died - Cast 'Shadowfury' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,0,6,0,100,5,0,0,0,0,11,61463,7,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Taldaram - Just Died - Cast 'Shadowfury' (No Repeat) (Heroic Dungeon)");

-- Frostbringer SAI
SET @ENTRY := 30286;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,57825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostbringer - Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,3400,4800,11,61461,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostbringer - Combat CMC - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,15000,18000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Combat - Cast 'Frost Nova' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,15000,18000,11,61462,1,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - Combat - Cast 'Frost Nova' (Heroic Dungeon)"),
(@ENTRY,0,4,0,2,0,100,6,0,30,120000,130000,11,56716,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostbringer - 0-30% Health - Cast 'Icy Winds' (Dungeon)");

-- Stormforged Amplifier SAI
SET @ENTRY := 30591;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Amplifier - Combat CMC - Cast 'Lightning Bolt'");

-- Veteran Mage Hunter SAI
SET @ENTRY := 30665;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Out of Combat - Cast 'Destroy Door Seal' (Dungeon)"),
(@ENTRY,0,1,0,4,0,100,6,0,0,0,0,30,1,2,3,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Aggro - Set Random Phase(1, 2, 3) (Dungeon)"),
(@ENTRY,0,2,0,0,1,100,2,0,0,2400,3800,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Frostbolt' (Phase 1) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,1,100,4,0,0,2400,3800,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Frostbolt' (Phase 1) (Heroic Dungeon)"),
(@ENTRY,0,4,0,9,2,100,2,0,0,2400,3800,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Fireball' (Phase 2) (Normal Dungeon)"),
(@ENTRY,0,5,0,9,2,100,4,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Fireball' (Phase 2) (Heroic Dungeon)"),
(@ENTRY,0,6,0,9,4,100,2,0,0,2400,3800,11,13748,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Arcane Bolt' (Phase 3) (Normal Dungeon)"),
(@ENTRY,0,7,0,9,4,100,4,0,0,2400,3800,11,20829,64,0,0,0,0,2,0,0,0,0,0,0,0,"Veteran Mage Hunter - Combat CMC - Cast 'Arcane Bolt' (Phase 3) (Heroic Dungeon)"),
(@ENTRY,0,8,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Veteran Mage Hunter - Between 0-15% Health - Flee For Assist (No Repeat) (Dungeon)");

-- Portal Keeper SAI
SET @ENTRY := 30695;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,6000,8000,11,58531,64,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - Combat CMC - Cast 'Arcane Missiles' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,0,6000,8000,11,61593,64,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - Combat CMC - Cast 'Arcane Missiles' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,0,8,13000,19000,11,58532,1,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - 0-8 Range - Cast 'Frostbolt Volley' (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,0,8,13000,19000,11,61594,1,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - 0-8 Range - Cast 'Frostbolt Volley' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,0,8,9000,14000,11,58534,1,0,0,0,0,6,0,0,0,0,0,0,0,"Portal Keeper - Combat - Cast 'Deep Freeze' (Dungeon)");

-- Nesingwary Game Warden SAI
SET @ENTRY := 30737;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nesingwary Game Warden - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,13000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nesingwary Game Warden - 0-20 Range - Cast 'Net'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,8000,10000,11,31942,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nesingwary Game Warden - 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,3,0,9,0,100,0,0,45,7000,9000,11,23337,1,0,0,0,0,6,0,0,0,0,0,0,0,"Nesingwary Game Warden - 0-45 Range - Cast 'Shoot'");

-- Unbound Dryad SAI
SET @ENTRY := 30860;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,55217,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Dryad - Combat CMC - Cast 'Throw Spear'"),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,9000,13000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Dryad - In Combat - Cast 'Strike'");

-- Shandaral Hunter Spirit SAI
SET @ENTRY := 30864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,9000,14000,11,54615,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Combat - Cast 'Aimed Shot'"),
(@ENTRY,0,2,0,0,0,100,0,9000,15000,15000,22000,11,47168,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shandaral Hunter Spirit - Combat - Cast 'Improved Wing Clip'");

-- Unbound Corrupter SAI
SET @ENTRY := 30868;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,5400,11,38204,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Corrupter - Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,20000,30000,45000,60000,11,58667,1,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Corrupter - Combat - Cast 'Ley Curse'"),
(@ENTRY,0,2,0,2,0,100,0,0,30,30000,35000,11,58270,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Corrupter - 0-30% Health - Cast 'Transferred Power'");

-- Portal Keeper SAI
SET @ENTRY := 30893;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,45,6000,8000,11,58536,64,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - Combat CMC - Cast 'Arcane Volley' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,0,45,6000,8000,11,61591,64,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - Combat CMC - Cast 'Arcane Volley' (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,0,45,13000,19000,11,58535,0,0,0,0,0,5,0,0,0,0,0,0,0,"Portal Keeper - 0-45 Range - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,0,45,13000,19000,11,61590,0,0,0,0,0,5,0,0,0,0,0,0,0,"Portal Keeper - 0-45 Range - Cast 'Frostbolt' (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,0,8,9000,14000,11,58537,1,0,0,0,0,6,0,0,0,0,0,0,0,"Portal Keeper - Combat - Cast 'Polymorph' (Dungeon)");

-- Azure Binder SAI
SET @ENTRY := 31007;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4800,11,58456,64,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Binder - Combat CMC - Cast 'Arcane Barrage' (Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,0,8,9000,15000,11,58455,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - 0-8 Range - Cast 'Arcane Explosion' (Normal Dungeon)"),
(@ENTRY,0,2,0,9,0,100,4,0,8,9000,15000,11,59257,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Binder - 0-8 Range - Cast 'Arcane Blast' (Heroic Dungeon)");
