-- Speech by Martik Tor'seldoi, Thrallmar
SET @ENTRY := 16577;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,50000,360000,360000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Martik Tor''seldoi - OOC - Load script every 6 min ooc'),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,11,18100,32,0,0,0,0,1,0,0,0,0,0,0,0, 'Martik Tor''seldoi - Reset - Cast Frost Armor'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Martik Tor''seldoi Say text 0'),
(@ENTRY*100,9,1,0,0,0,100,0,3000,3000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Martik Tor''seldoi emote'),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,0,0,5,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Martik Tor''seldoi emote'),
(@ENTRY*100,9,3,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,10,57487,16578,0,0,0,0,0,'Blood Elf Pilgrim Say text 0'),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,5,6,0,0,0,0,0,10,57487,16578,0,0,0,0,0,'Blood Elf Pilgrim emote'),
(@ENTRY*100,9,5,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,10,57487,16578,0,0,0,0,0,'Martik Tor''seldoi turn to'),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Martik Tor''seldoi Say text 1'),
(@ENTRY*100,9,7,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,10,57487,16578,0,0,0,0,0,'Blood Elf Pilgrim Say text 1'),
(@ENTRY*100,9,8,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Martik Tor''seldoi Say text 2'),
(@ENTRY*100,9,9,0,0,0,100,0,3000,3000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Martik Tor''seldoi emote'),
(@ENTRY*100,9,10,0,0,0,100,0,3000,3000,0,0,5,273,0,0,0,0,0,1,0,0,0,0,0,0,0,'Martik Tor''seldoi emote'),
(@ENTRY*100,9,11,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,10,57487,16578,0,0,0,0,0,'Blood Elf Pilgrim Say text 2'),
(@ENTRY*100,9,12,0,0,0,100,0,1000,1000,0,0,5,15,0,0,0,0,0,9,16578,0,20,0,0,0,0,'Blood Elf Pilgrim emote'),
(@ENTRY*100,9,13,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Martik Tor''seldoi turn to');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (16577,16578);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16577,0,0, 'Brothers and sisters, I have been to the promised land. I have tasted in the sublim energy. I have felt bliss - bliss so engrossing and all encompassing that I was left wondering if I had stumbled upon the dreams of gods.!',12,0,100,5,0,0, 'Martik Tor''seldoi'),
(16577,1,0, 'In paradise, you merely reach out and take from the Nether.',12,0,100,1,0,0, 'Martik Tor''seldoi'),
(16577,2,0, 'From the very air! Tendrils of arcane energy light up the obsidian sky as plumes of raw magic rise up from fissures in the land. Kneel and drink from the fissure as you do from a stream or well. Pluck a tendril from the heavens as if it were an apple hanging from a branch.',12,0,100,5,0,0, 'Martik Tor''seldoi'),
(16578,0,0, 'Tell us more, Martik. What is it? What does it feel like?',12,0,100,1,0,0, 'Blood Elf Pilgrim'),
(16578,1,0, 'But how?',12,0,100,6,0,0, 'Blood Elf Pilgrim'),
(16578,2,0, '%s smiles/gasps.',16,0,100,0,0,0, 'Blood Elf Pilgrim');
