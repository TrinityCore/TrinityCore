--
UPDATE `creature_template` SET `unit_flags`=0, `flags_extra`=0, `npcflag`=0 WHERE  `entry`=17587;
-- Timberstrider Fledgling SAI
SET @ENTRY := 17372;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,17587,10,0,0,0,0,0,"Timberstrider Fledgling - On Just Died - Set Data 1 1");

-- Draenei Youngling SAI
SET @ENTRY := 17587;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,1,0,100,0,60000,60000,60000,60000,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - Out of Combat - Set Event Phase 0"),
(@ENTRY,0,1,0,8,0,100,0,28880,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,2,0,38,1,100,0,1,1,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Data Set 1 1 - Set Npc Flag Questgiver (Phase 1)"),
(@ENTRY,0,3,0,61,0,100,0,60000,60000,60000,60000,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - Out of Combat - Set Npc Flag "),
(@ENTRY,0,5,0,8,0,100,0,59547,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,6,0,8,0,100,0,59545,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,7,0,8,0,100,0,59544,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,8,0,8,0,100,0,59542,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,9,0,8,0,100,0,59548,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1"),
(@ENTRY,0,10,0,8,0,100,0,59543,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Youngling - On Spellhit 'Gift of the Naaru' - Set Event Phase 1");

DELETE FROM `creature_text` WHERE `entry`IN (17587);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(17587,0,0, 'Help! I think this creature might be too tough for me to handle alone.',12,35,100,0,0,0, '17587',14167), -- player IC_LOS
(17587,0,1, 'Can anyone hear me? I need help! This creature is going to kill me!',12,35,100,0,0,0, '17587',14168), -- player IC_LOS
(17587,0,2, 'I can''t hold it off any longer! Tell the exarch that I gave it my best.',12,35,100,0,0,0, '17587',14169), -- player IC_LOS
(17587,1,0, 'Thanks again!',12,35,100,0,0,0, '17587',14170), -- heal received
(17587,1,1, 'Thanks for the heal, $n!',12,35,100,0,0,0, '17587',14166), -- heal received
(17587,2,0, 'Another victory for the Draenei!',12,35,100,0,0,0, '17587',14171), -- target dies
(17587,2,1, 'Another infected beast destroyed!',12,35,100,0,0,0, '17587',14172), -- target dies
(17587,2,2, 'Hah! This is easy.',12,35,100,0,0,0, '17587',14174), -- target dies
(17587,2,3, 'How could you think yourself a match for the draenei champion!',12,35,100,0,0,0, '17587',14173), -- target dies
(17587,3,0, 'Kill as many infected nightstalkers as I can find... This should be easy.',12,35,100,0,0,0, '17587',14165), -- random ooc
(17587,3,1, 'I''m supposed to be hunting infected nightstalkers... This should be easy.',12,35,100,0,0,0, '17587',14175), -- random ooc
(17587,3,2, 'Where in the nether are these damnable lashers??',12,35,100,0,0,0, '17587',14176), -- random ooc
(17587,3,3, 'Hrm, azure snapdragons? Where do they come up with these names? Daedal has gone mad!',12,35,100,0,0,0, '17587',14177), -- random ooc
(17587,3,4, 'These stags look nothing like talbuks.',12,35,100,0,0,0, '17587',14178), -- random ooc
(17587,3,5, 'I wonder what that little purple creature at the village is... It''s certainly beautiful.',12,35,100,0,0,0, '17587',14179), -- random ooc
(17587,4,0, 'Time to meet your maker, $n!',12,35,100,0,0,0, '17587',14180); -- on aggro
