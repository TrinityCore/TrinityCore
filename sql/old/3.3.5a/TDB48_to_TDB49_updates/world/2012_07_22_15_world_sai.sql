-- SAI for quest 12150 "Reclusive Runemaster"
SET @Dregmar := 27003;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Dregmar;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@Dregmar;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Dregmar AND `source_type`=0 AND `id` BETWEEN 0 AND 2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Dregmar*100 AND `source_type`=9 AND `id` BETWEEN 0 AND 8;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Dregmar,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - on aggro - yell text 0'),
(@Dregmar,0,1,0,2,0,100,1,0,50,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - at 50% HP - yell text 1'),
(@Dregmar,0,2,0,2,0,100,0,0,20,0,0,80,@Dregmar*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - at 20% HP - run script'),
(@Dregmar*100,9,0,0,0,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - set phase 1'),
(@Dregmar*100,9,1,0,0,0,100,0,0,0,0,0,24,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - evade'),
(@Dregmar*100,9,2,0,0,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - Stop combat'),
(@Dregmar*100,9,3,0,0,0,100,0,0,0,0,0,18,33346,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - unitflags OutOfCombat'),
(@Dregmar*100,9,4,0,0,0,100,0,0,0,0,0,75,48325,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - apply aura RUNE SHIELD'),
(@Dregmar*100,9,5,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - yell text 2'),
(@Dregmar*100,9,6,0,0,0,100,0,0,14000,0,0,11,48028,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - Complete quest on player range'),
(@Dregmar*100,9,7,0,0,0,100,0,0,14000,0,0,19,514,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - unitflags reseted'),
(@Dregmar*100,9,8,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Dregmar Runebrand - force despawn');

-- creature_text
DELETE FROM `creature_ai_texts` WHERE `entry` BETWEEN -894 AND -892;
DELETE FROM `creature_text` WHERE `entry`=@Dregmar AND `groupid` BETWEEN 0 AND 2;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Dregmar,0,0, 'I know why you''ve come - one of those foolish Magnataur on the plains meddled and managed to get the dragons involved. Do you enjoy serving them like a dog?',14,0,100,0,0,0, 'Dregmar Runebrand - yell'),
(@Dregmar,1,0, 'You seek their leader... little thing, you wage war against the clans of Grom''thar the Thunderbringer himself. Don''t be so eager to rush to your death.',14,0,100,0,0,0, 'Dregmar Runebrand yell'),
(@Dregmar,2,0, 'Hah! So be it. Blow the horn of a magnataur leader at the ring of torches south of the Azure Dragonshrine. Make peace with your gods... Grom''thar will come.',14,0,100,0,0,0, 'Dregmar Runebrand yell');
