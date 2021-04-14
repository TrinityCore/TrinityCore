-- Bonesunder SAI (Converted from EAI)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=27006;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27006;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=27006;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27006,0,0,0,0,0,100,0,5000,11000,16000,25000,11,52080,1,0,0,0,0,2,0,0,0,0,0,0,0,'Bonesunder - Cast Bonecrack');

-- Surge Needle Sorcerer SAI
SET @ELMGUID := 113473;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=26257;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26257,-109558,-109559,-109560,-109561,-109563,-109564,-109565,-109569,-109570,-109571,-109572,-109578);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26257,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109558,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109558,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109558,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109559,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109559,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109559,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109560,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109560,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109560,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109561,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109561,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109561,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109563,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109563,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109563,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109564,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109564,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109564,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109565,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109565,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109565,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109569,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109569,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109569,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109570,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109570,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109570,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109571,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109571,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109571,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109572,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109572,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109572,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim'),
(-109578,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(-109578,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(-109578,0,2,0,0,0,100,0,3000,4000,3000,5000,11,51797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast on victim');

-- Goramosh SAI
SET @ELMGUID := 113473;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=26349;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26349);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26349,0,0,0,1,0,100,1,1000,1000,1000,1000,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when spawned'),
(26349,0,1,0,21,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,@ELMGUID,26298,0,0,0,0,0,'Cast Surge Needle Beam when reach home'),
(26349,0,2,0,2,0,100,1,0,50,0,0,11,20828,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold on victim at 50% health'),
(26349,0,3,0,0,0,100,0,3500,3500,3500,3500,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Bolt on victim');

-- Arcanimus SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=26370;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26370);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26370,0,0,0,1,0,100,1,2000,2000,2000,2000,45,0,1,0,0,0,0,10,113473,26298,0,0,0,0,0, 'Set data 0 = 1 on bunny 2 sec after reset'),
(26370,0,1,0,1,0,100,1,0,0,0,0,11,46934,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arcanimus - Add Cosmetic - Arcane Force Shield (Blue x2) Aura on spawn & reset'),
(26370,0,2,3,4,0,100,0,0,0,0,0,28,46934,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arcanimus - Remove Cosmetic - Arcane Force Shield (Blue x2) Aura on aggro'),
(26370,0,3,0,61,0,100,0,0,0,0,0,28,46906,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arcanimus - Remove Cosmetic - Surge Needle Beam on aggro'),
(26370,0,4,0,2,0,100,1,71,80,0,0,11,51820,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arcanimus - at 80% health cast Arcane Explosion on self'),
(26370,0,5,0,2,0,100,1,41,60,0,0,11,51820,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arcanimus - at 60% health cast Arcane Explosion on self'),
(26370,0,6,0,2,0,100,1,21,40,0,0,11,51820,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arcanimus - at 40% health cast Arcane Explosion on self'),
(26370,0,7,0,2,0,100,1,1,20,0,0,11,51820,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arcanimus - at 20% health cast Arcane Explosion on self');

-- ELM General Purpose Bunny (scale x0.01) Large SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=26298;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-113473);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-113473,0,0,0,11,0,100,0,0,0,0,0,11,32566,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Purple Banish State aura on self when spawned'),
(-113473,0,1,2,38,0,100,0,0,1,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'reset data 0 = 0'),
(-113473,0,2,0,61,0,100,0,0,0,0,0,11,46906,2,0,0,0,0,10,96298,26370,0,0,0,0,0, 'cast Surge Needle Beam on Arcanimus');
