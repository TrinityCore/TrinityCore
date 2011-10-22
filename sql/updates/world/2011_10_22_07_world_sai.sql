-- Hooked Net SHOULD hit this hard, fyi!
-- Sunreaver Agent SAI
SET @ENTRY := 36776;
SET @SPELL_HOOKED_NET := 59260;
SET @SPELL_SINISTER_STRIKE := 60195;
SET @SPELL_VANISH := 71400; -- Why is this called Vanish?... It teleports caster behind target
SET @SPELL_EVISCERATE := 15691;
SET @SPELL_BACKSTAB := 71410;
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|2,`unit_class`=4 WHERE `entry`=@ENTRY; -- Civilian according to video
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunreaver Agent - On Aggro - Say Line 0 (random)"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL_HOOKED_NET,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Agent - On Aggro - Cast Hooked Net"),
(@ENTRY,0,2,0,67,0,100,0,1000,3000,0,0,11,@SPELL_BACKSTAB,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Agent - Behind Target - Cast Backstab"),
(@ENTRY,0,3,0,0,0,100,0,1000,1500,3000,3000,11,@SPELL_SINISTER_STRIKE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Agent - In Combat - Cast Sinister Strike"),
(@ENTRY,0,4,0,0,0,100,1,4000,6000,0,0,11,@SPELL_VANISH,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Agent - In Combat - Cast Vanish"),
(@ENTRY,0,5,0,0,0,100,0,9000,13000,20000,20000,11,@SPELL_EVISCERATE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunreaver Agent - In Combat - Cast Eviscerate");

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Did you think you would escape with your life?",12,0,100,1,0,0,"Sunreaver Agent"),
(@ENTRY,0,1,"You'll never run us out of the city, Silver Covenant thug!",12,0,100,1,0,0,"Sunreaver Agent");

-- Silver Covenant Agent SAI
SET @ENTRY := 36774;
SET @SPELL_HOOKED_NET := 59260;
SET @SPELL_SINISTER_STRIKE := 60195;
SET @SPELL_VANISH := 71400; -- Why is this called Vanish?... It teleports caster behind target
SET @SPELL_EVISCERATE := 15691;
SET @SPELL_BACKSTAB := 71410;
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|2,`unit_class`=4 WHERE `entry`=@ENTRY; -- Civilian according to video
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Agent - On Aggro - Say Line 0 (random)"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL_HOOKED_NET,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Agent - On Aggro - Cast Hooked Net"),
(@ENTRY,0,2,0,67,0,100,0,1000,3000,0,0,11,@SPELL_BACKSTAB,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Agent - Behind Target - Cast Backstab"),
(@ENTRY,0,3,0,0,0,100,0,1000,1500,3000,3000,11,@SPELL_SINISTER_STRIKE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Agent - In Combat - Cast Sinister Strike"),
(@ENTRY,0,4,0,0,0,100,1,4000,6000,0,0,11,@SPELL_VANISH,1,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Agent - In Combat - Cast Vanish"),
(@ENTRY,0,5,0,0,0,100,0,9000,13000,20000,20000,11,@SPELL_EVISCERATE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Covenant Agent - In Combat - Cast Eviscerate");

-- Texts by
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You Sunreaver lackeys are all the same.",12,0,100,1,0,0,"Silver Covenant Agent"),
(@ENTRY,0,1,"You won't escape from us so easily!",12,0,100,1,0,0,"Silver Covenant Agent");

UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=30438; -- Sunreaver Agent
UPDATE `creature_model_info` SET `bounding_radius`=0.383,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=30310; -- Silver Covenant Agent
