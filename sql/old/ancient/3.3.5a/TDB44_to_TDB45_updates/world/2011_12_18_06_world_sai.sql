SET @JEEVES := 35642;
SET @SPELL_GOODBYE := 68052;
DELETE FROM `spell_linked_spell` WHERE `spell_effect`=@SPELL_GOODBYE AND  `spell_trigger`=-68054 AND `type`=0;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-68054,@SPELL_GOODBYE,0, 'Jeeves - Say Goodbye');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@JEEVES;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@JEEVES AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@JEEVES,0,0,0,8,0,100,0,@SPELL_GOODBYE,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jeeves - On Spellhit - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=@JEEVES;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@JEEVES,0,0,"If you'll excuse me, I'm afraid I have other business I must attend to. Please call on me again in the future.",12,0,100,3,0,0, 'Jeeves');
