SET @ENTRY := 18716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,7759,0,0,0,11,47068,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Who Are They - Shadowy Initiate - On Gossip option - Cast spell 47068 on player'),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,58,1,9613,2400,3800,30,30,1,0,0,0,0,0,0,0, 'Shadowy Initiate - On spawn install caster template');

SET @ENTRY := 18719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,7760,0,0,0,11,47070,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Who Are They - Shadowy Advisor - On Gossip option - Cast spell 47070 on player'),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,58,1,9613,2400,3800,30,30,1,0,0,0,0,0,0,0, 'Shadowy Advisor - On spawn install caster template');

SET @ENTRY := 18930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,7938,1,0,0,11,34924,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Vlagga Freyfeather - On gossip option 1 select - Cast Stair of Destiny to Thrallmar'),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,12,9297,4,30000,0,0,0,1,0,0,0,0,0,0,0, 'Vlagga Freyfeather - Vlagga Freyfeather - Summon Enraged Wyverns on Aggro'),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,12,9297,4,30000,0,0,0,1,0,0,0,0,0,0,0, 'Vlagga Freyfeather - Vlagga Freyfeather - Summon Enraged Wyverns on Aggro'),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Vlagga Freyfeather - Say text on Aggro');

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Arrrhhh...Guards!',14,7,100,0,0,0, 'Common Horde Flight Master');

-- some cleanup
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (19534,26816,26820,28417);
DELETE FROM `creature_ai_texts` WHERE `entry`=-337;

-- incorrectly set AIName
UPDATE `creature_template` SET `AIName`='EventAI', `ScriptName`='' WHERE `entry` IN (24938,27570);

SET @ENTRY := 25596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,32423,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Infected Kodo Beast - Blue Radiation on spawn'),
(@ENTRY,0,1,0,27,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Infected Kodo Beast - remove death state on passager boarded'),
(@ENTRY,0,2,0,31,0,100,0,45877,0,0,0,41,0,0,0,0,0,0,22,0,0,0,0,0,0,0, 'Infected Kodo Beast - On Spell Hit despawn');

SET @ENTRY := 26257;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,58,1,51797,3400,4800,30,7,1,0,0,0,0,0,0,0, 'Surge Needle Sorcerer - On spawn install caster template');

SET @ENTRY := 26343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,32423,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Indu''le Fisherman - On spawn - Cast Blue Radiation on self'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,18000,11,11820,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Indu''le Fisherman -  Cast Electrified Net');

SET @ENTRY := 27842;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,12,9521,4,30000,0,0,0,1,0,0,0,0,0,0,0, 'Fenrick Barlowe - Summon Enraged Felbat on Aggro'),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,12,9521,4,30000,0,0,0,1,0,0,0,0,0,0,0, 'Fenrick Barlowe - Summon Enraged Felbat on Aggro'),
(@ENTRY,0,3,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fenrick Barlowe - Say text on Aggro'),
(@ENTRY,0,4,0,11,0,100,0,0,0,0,0,53,0,27842,1,0,0,0,1,0,0,0,0,0,0,0, 'Fenrick Barlowe - on spawn start path'),
(@ENTRY,0,5,0,40,0,100,0,5,27842,0,0,80,2784201,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fenrick Barlowe - at wp 5 run script1'),
(@ENTRY,0,6,0,40,0,100,0,8,27842,0,0,80,2784202,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Fenrick Barlowe - at wp 8 run script2');

DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'Bat gizzards again for the gnomes tonight...', 12, 0, 100, 1, 0, 0, 'Fenrick Barlowe text'),
(@ENTRY, 0, 1, 'What do they expect, making the bats come in at that angle? Broken necks and gamey bat stew, that''s what they get.', 12, 0, 100, 1, 0, 0, 'Fenrick Barlowe text'),
(@ENTRY, 0, 2, 'We like trees, Fenrick. They provide cover. They won''t let me chop them down, either.', 12, 0, 100, 1, 0, 0, 'Fenrick Barlowe text'),
(@ENTRY, 0, 3, 'I wonder how many reinforcements need to suffer injury before they allows us to chop down these idiotic trees. They''re costing us a fortune in bats. Maybe I''ll rig a harness or two...', 12, 0, 100, 1, 0, 0, 'Fenrick Barlowe text'),
(@ENTRY,1,0, 'Arrrhhh...Guards!',14,7,100,0,0,0, 'Common Horde Flight Master');
