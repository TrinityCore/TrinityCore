-- Thalorien Dawnseeker's Remains
SET @ENTRY := 37552;

DELETE FROM `creature_template_addon` WHERE (`entry`=@ENTRY);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(@ENTRY, 0, 0, 0, 0, 0, '25824 31261');

DELETE FROM `gossip_menu_option` WHERE `menu_id`= @ENTRY;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(@ENTRY,0,0,'Examine the remains.',37149,1,1,0,0,0,0,'',0);

UPDATE `creature_template` SET `ScriptName`="npc_thalorien_dawnseeker" WHERE `entry`=@ENTRY;

-- Phase
DELETE FROM `spell_area` WHERE `spell`=70193;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
('70193', '4075', '24535', '0', '0', '0', '2', '1', '8', '11'),
('70193', '4075', '24563', '0', '0', '0', '2', '1', '8', '11');

-- Thalorien Dawnseeker SAI
SET @ENTRY := 37205;
UPDATE `creature_template` SET `faction`=250 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,15000,15000,11,67541,3,0,0,0,0,2,0,0,0,0,0,0,0,"Thalorien Dawnseeker - In Combat - Cast 'Bladestorm' (Dungeon & Raid)"),
(@ENTRY,0,1,0,0,0,100,0,2000,2000,13000,13000,11,67542,2,0,0,0,0,2,0,0,0,0,0,0,0,"Thalorien Dawnseeker - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,2,0,0,0,100,0,19000,19000,19000,19000,11,67716,2,0,0,0,0,1,0,0,0,0,0,0,0,"Thalorien Dawnseeker - In Combat - Cast 'Whirlwind'"),
(@ENTRY,0,3,0,0,0,100,0,1000,1000,8000,8000,11,57846,2,0,0,0,0,2,0,0,0,0,0,0,0,"Thalorien Dawnseeker - In Combat - Cast 'Heroic Strike'");

-- Thalorien Dawnseeker Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`comment`) VALUES 
(@ENTRY, 0, 0, 'We must defend the Sunwell from the enemy at all costs.', 12, 0, 100, 0, 0, 16769, 37154, 'Thalorien Dawnseeker'),
(@ENTRY, 1, 0, 'I am ordering you to withdraw to the Sunwell proper to help prepare the defenses.', 12, 0, 100, 0, 0, 16770, 37155, 'Thalorien Dawnseeker'),
(@ENTRY, 2, 0, 'I will make my stand here and buy you as much time as I am able. Use it well and make our prince proud.', 12, 0, 100, 0, 0, 16771, 37156, 'Thalorien Dawnseeker'),
(@ENTRY, 3, 0, 'It has been a great honor to fight beside you in defense of our land and our people.', 12, 0, 100, 0, 0, 16772, 37157, 'Thalorien Dawnseeker'),
(@ENTRY, 4, 0, 'You, stranger... you are not one of my soldiers. Will you stay and stand with me to face the enemy?', 12, 0, 100, 0, 0, 16773, 37158, 'Thalorien Dawnseeker'),
(@ENTRY, 5, 0, 'Listen well, Scourge defilers. None of you will reach the Sunwell so long as I stand!', 14, 0, 100, 0, 0, 16774, 37159, 'Thalorien Dawnseeker'),
(@ENTRY, 6, 0, 'I... I wasn\'t meant to survive this attack.', 12, 0, 100, 0, 0, 16775, 37196, 'Thalorien Dawnseeker'),
(@ENTRY, 7, 0, 'Why has this happened? Why have you come here?', 12, 0, 100, 0, 0, 16776, 37197, 'Thalorien Dawnseeker'),
(@ENTRY, 8, 0, 'It\'s Quel\'Delar! You possess the sword!', 12, 0, 100, 0, 0, 16777, 37198, 'Thalorien Dawnseeker'),
(@ENTRY, 9, 0, 'I don\'t know how, but the blade has chosen you to be its new wielder. Take it with my blessing, and wield it against the Scourge as I once did.', 12, 0, 100, 0, 0, 16778, 37199, 'Thalorien Dawnseeker');

-- Morlen Coldgrip SAI
SET @ENTRY := 37542;
UPDATE `creature_template` SET `faction`=16 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,10000,11,50688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morlen Coldgrip - In Combat - Cast 'Plague Strike' (Dungeon & Raid)");

-- Morlen Coldgrip Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`comment`) VALUES 
(@ENTRY, 0, 0, 'You will fall as your lands and your city have before you. My lord will a great victory here, and none will remember you name!', 14, 0, 100, 0, 0, 0, 37160, 'Morlen Coldgrip'),
(@ENTRY, 1, 0, 'Forward!', 14, 0, 100, 0, 0, 0, 37162, 'Morlen Coldgrip'),
(@ENTRY, 2, 0, 'Ghouls, slay this patheric high elf!', 14, 0, 100, 0, 0, 0, 37301, 'Morlen Coldgrip'),
(@ENTRY, 3, 0, 'You will fall before the might of the Scourge. Crypt raiders, attack!', 14, 0, 100, 0, 0, 0, 37302, 'Morlen Coldgrip'),
(@ENTRY, 4, 0, 'I shall kill you myself!', 14, 0, 100, 0, 0, 0, 37167, 'Morlen Coldgrip');

-- Crypt Raider SAI
SET @ENTRY := 37541;
UPDATE `creature_template` SET `faction`=16 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,4000,5000,11,31600,2,0,0,0,0,6,0,0,0,0,0,0,0,"Crypt Raider - In Combat - Cast 'Crypt Scarabs' (Dungeon & Raid)");

-- Ghoul Invader SAI
SET @ENTRY := 37539;
UPDATE `creature_template` SET `faction`=16 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,9000,10000,11,38056,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghoul Invader - In Combat - Cast 'Flesh Rip' (Dungeon & Raid)");

-- Scourge Zombie SAI
SET @ENTRY := 37538;
UPDATE `creature_template` SET `faction`=16 WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,9000,10000,11,49861,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Zombie - In Combat - Cast 'Infected Bite' (Dungeon & Raid)");
