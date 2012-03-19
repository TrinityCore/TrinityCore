-- Quest 9303 "Inoculation"
SET @OWL := 16518; -- Nestlewood Owlkin
SET @IOWL := 16534; -- Inoculated Nestlewood Owlkin
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@OWL;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@OWL;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND`entryorguid`=@OWL;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND`entryorguid`=@OWL*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OWL,0,0,0,8,0,100,0,29528,0,3000,3000,80,@OWL*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'on spellhit run script'),
(@OWL*100,9,0,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'face player'),
(@OWL*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'say random text from groupid 0'),
(@OWL*100,9,2,0,0,0,100,0,0,0,0,0,36,@IOWL,0,0,0,0,0,1,0,0,0,0,0,0,0,'morph to entry'),
(@OWL*100,9,3,0,0,0,100,0,0,0,0,0,18,33024,0,0,0,0,0,1,0,0,0,0,0,0,0,'change unitflags'),
(@OWL*100,9,4,0,0,0,100,0,300,300,0,0,33,@IOWL,0,0,0,0,0,7,0,0,0,0,0,0,0,'give quest credit'),
(@OWL*100,9,5,0,0,0,100,0,500,500,0,0,89,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'random movement'),
(@OWL*100,9,6,0,0,0,100,0,9000,9000,0,0,36,@OWL,0,0,0,0,0,1,0,0,0,0,0,0,0,'change entry back'),
(@OWL*100,9,7,0,0,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'change unitflags back'),
(@OWL*100,9,8,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'despawn');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=16518;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16518,0,0, 'The %s seems overjoyed.',2,0,100,0,0,0, 'Inoculated Nestlewood Owlkin'),
(16518,0,1, 'The %s seems disoriented.',2,0,100,0,0,0, 'Inoculated Nestlewood Owlkin'),
(16518,0,2, 'The %s doesn''t look like it minds the crystal''s effects.',2,0,100,0,0,0, 'Inoculated Nestlewood Owlkin'),
(16518,0,3, 'The %s didn''t like what just happened.',2,0,100,0,0,0, 'Inoculated Nestlewood Owlkin'),
(16518,0,4, 'The %s looks confused.',2,0,100,0,0,0, 'Inoculated Nestlewood Owlkin'),
(16518,0,5, 'The %s nods appreciatively.',2,0,100,0,0,0, 'Inoculated Nestlewood Owlkin');

-- spell does not target the innoculated owlkin and it is not spawned, so take spell requirement out of equation
UPDATE `quest_template` SET `ReqSpellCast1`=0 WHERE `entry`=9303;
