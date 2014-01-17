-- [Q] Help Tavara

-- Tavara SAI
SET @ENTRY := 17551;
SET @SPELL_GIFT_OF_THE_NAARU_PR := 59544; -- Gift of the Naaru - Priest
SET @SPELL_LESSER_HEAL_R1 := 2050; -- Lesser Heal R1
SET @SPELL_LESSER_HEAL_R2 := 2052; -- Lesser Heal R2
SET @SPELL_RENEW_R1 := 139; -- Renew R1 (they don't have R2 yet)
UPDATE `creature_template` SET `AIName`='SmartAI',`RegenHealth`=0 WHERE `entry`=@ENTRY;
UPDATE `quest_template` SET `ReqSpellCast1`=0 WHERE `entry`=9586;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_LESSER_HEAL_R1,0,0,0,33,17551,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tavara - On Spellhit - Give Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,@SPELL_LESSER_HEAL_R2,0,0,0,33,17551,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tavara - On Spellhit - Give Quest Credit"),
(@ENTRY,0,2,0,8,0,100,1,@SPELL_GIFT_OF_THE_NAARU_PR,0,0,0,33,17551,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tavara - On Spellhit - Give Quest Credit"),
(@ENTRY,0,3,0,8,0,100,1,@SPELL_RENEW_R1,0,0,0,33,17551,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tavara - On Spellhit - Give Quest Credit");

-- [Q] Weakness to Lightning

-- Scavenge-bot 004-A8 SAI
SET @ENTRY := 25752;
SET @SPELL_CUTING_LASER := 49945;
SET @SPELL_POWER_OF_THE_STORM := 46432;
UPDATE `creature_template` SET `AIName`='SmartAI',`mechanic_immune_mask`=`mechanic_immune_mask`|8 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,10000,15000,11,@SPELL_CUTING_LASER,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scavenge-bot 004-A8 - In Combat - Cast Cutting Laser"),
(@ENTRY,0,1,0,8,0,100,0,@SPELL_POWER_OF_THE_STORM,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scavenge-bot 004-A8 - On Spellhit - Set Phase 1"),
(@ENTRY,0,2,0,6,1,100,0,0,0,0,0,33,26082,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scavenge-bot 004-A8 - On Death - Quest Credit (Phase 1)");

-- Scavenge-bot 005-B6 SAI
SET @ENTRY := 25792;
SET @SPELL_CUTING_LASER := 49945;
SET @SPELL_POWER_OF_THE_STORM := 46432;
UPDATE `creature_template` SET `AIName`='SmartAI',`mechanic_immune_mask`=`mechanic_immune_mask`|8 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,10000,15000,11,@SPELL_CUTING_LASER,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scavenge-bot 005-B6 - In Combat - Cast Cutting Laser"),
(@ENTRY,0,1,0,8,0,100,0,@SPELL_POWER_OF_THE_STORM,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scavenge-bot 005-B6 - On Spellhit - Set Phase 1"),
(@ENTRY,0,2,0,6,1,100,0,0,0,0,0,33,26082,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scavenge-bot 005-B6 - On Death - Quest Credit (Phase 1)");

-- Defendo-tank 66D SAI
SET @ENTRY := 25758;
SET @SPELL_SHOOT := 49987;
SET @SPELL_MACHINE_GUN := 49981;
SET @SPELL_POWER_OF_THE_STORM := 46432;
UPDATE `creature_template` SET `AIName`='SmartAI',`mechanic_immune_mask`=`mechanic_immune_mask`|8 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Defendo-tank 66D - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,1100,3100,2300,13700,11,@SPELL_SHOOT,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defendo-tank 66D - In Combat - Cast Shoot"),
(@ENTRY,0,2,0,0,0,100,0,9800,13100,18300,19200,11,@SPELL_MACHINE_GUN,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defendo-tank 66D - In Combat - Cast Machine Gun"),
(@ENTRY,0,3,0,8,0,100,0,@SPELL_POWER_OF_THE_STORM,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defendo-tank 66D - On Spellhit - Set Phase 1"),
(@ENTRY,0,4,0,6,1,100,0,0,0,0,0,33,26082,0,0,0,0,0,7,0,0,0,0,0,0,0,"Defendo-tank 66D - On Death - Quest Credit (Phase 1)");

-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Incoming $r flier! Shoot $g him:her; down!",12,0,100,0,0,0,"Defendo-tank 66D");

-- Sentry-bot 57-K SAI
SET @ENTRY := 25753;
SET @SPELL_STUN := 46641;
SET @SPELL_FIREWORK := 6668;
SET @SPELL_POWER_OF_THE_STORM := 46432;
UPDATE `creature_template` SET `AIName`='SmartAI',`mechanic_immune_mask`=`mechanic_immune_mask`|8 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`, `event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`, `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,13000,13000,26000,11,@SPELL_FIREWORK,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentry-bot 57-K - Out of Combat - Cast Red Firework"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentry-bot 57-K - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,1100,3100,2300,13700,11,@SPELL_STUN,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentry-bot 57-K - In Combat - Cast Stun"),
(@ENTRY,0,3,0,8,0,100,0,@SPELL_POWER_OF_THE_STORM,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentry-bot 57-K - On Spellhit - Set Phase 1"),
(@ENTRY,0,4,0,6,1,100,0,0,0,0,0,33,26082,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sentry-bot 57-K - On Death - Quest Credit (Phase 1)");

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Warning! Warning! Intruder alert! Intruder alert!",12,0,100,0,0,0,"Sentry-bot 57-K"),
(@ENTRY,0,1,"You have been detected. You will be assimilated or eliminated.",12,0,100,0,0,0,"Sentry-bot 57-K"),
(@ENTRY,0,2,"Activate counter-measures. Repel intruder.",12,0,100,0,0,0,"Sentry-bot 57-K");

DELETE FROM `conditions` WHERE `SourceEntry` IN (35352) AND `ConditionValue2` IN (25752,25792,25758,25753);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,35352,0,24,1,25752,0,0,'',"Spell Power of the Storm can only be cast at Scavenge-bot 004-A8"),
(18,0,35352,0,24,1,25792,0,0,'',"Spell Power of the Storm can only be cast at Scavenge-bot 005-B6"),
(18,0,35352,0,24,1,25758,0,0,'',"Spell Power of the Storm can only be cast at Defendo-tank 66D"),
(18,0,35352,0,24,1,25753,0,0,'',"Spell Power of the Storm can only be cast at Sentry-bot 57-K");


-- Mammoth Calf SAI
SET @ENTRY := 24613;
SET @SPELL_ANIMAL_BLOOD := 46221;
SET @SPELL_TRAMPLE := 15550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Mammoth Calf - On Death - Cast Animal Blood"),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,9000,18000,11,@SPELL_TRAMPLE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mammoth Calf - In Combat - Cast Trample");

-- Wooly Mammoth SAI
SET @ENTRY := 24614;
SET @SPELL_ANIMAL_BLOOD := 46221;
SET @SPELL_TRAMPLE := 15550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Wooly Mammoth - On Death - Cast Animal Blood"),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,9000,18000,11,@SPELL_TRAMPLE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wooly Mammoth - In Combat - Cast Trample");

-- Wooly Rhino Bull SAI
SET @ENTRY := 25489;
SET @SPELL_ANIMAL_BLOOD := 46221;
SET @SPELL_RHINO_CHARE := 50500;
SET @SPELL_THICK_HIDE := 50502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Wooly Rhino Bull - On Death - Cast Animal Blood"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,@SPELL_RHINO_CHARE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wooly Rhino Bull - On Aggro - Cast Rhino Charge"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,@SPELL_THICK_HIDE,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wooly Rhino Bull - On Aggro - Cast Thick Hide");

-- Carrion Condor SAI
SET @ENTRY := 26174;
SET @SPELL_ANIMAL_BLOOD := 46221;
SET @SPELL_SWOOP := 5708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Carrion Condor - On Death - Cast Animal Blood"),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,9000,18000,11,@SPELL_SWOOP,0,0,0,0,0,2,0,0,0,0,0,0,0,"Carrion Condor - In Combat - Cast Swoop");

-- Marsh Caribou SAI
SET @ENTRY := 25680;
SET @SPELL_ANIMAL_BLOOD := 46221;
SET @SPELL_GORE := 32019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Marsh Caribou - On Death - Cast Animal Blood"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,8000,11000,11,@SPELL_GORE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marsh Caribou - In Combat - Cast Gore");

-- Marsh Fawn SAI
SET @ENTRY := 25829;
SET @SPELL_ANIMAL_BLOOD := 46221;
SET @SPELL_GORE := 32019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Marsh Fawn - On Death - Cast Animal Blood"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,8000,11000,11,@SPELL_GORE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marsh Fawn - In Combat - Cast Gore");

-- Sand Turtle SAI
SET @ENTRY := 25482;
SET @SPELL_ANIMAL_BLOOD := 46221;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Sand Turtle - On Death - Cast Animal Blood");

-- Tundra Wolf SAI
SET @ENTRY := 25675;
SET @SPELL_ANIMAL_BLOOD := 46221;
SET @SPELL_INFECTED_BITE := 7367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Tundra Wolf - On Death - Cast Animal Blood"),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,9000,18000,11,@SPELL_INFECTED_BITE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tundra Wolf - In Combat - Cast Infected Bite");

-- Wooly Mammoth Bull SAI
SET @ENTRY := 25743;
SET @SPELL_THUNDERING_ROAR := 46316;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Wooly Mammoth Bull - On Death - Cast Animal Blood"),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,9000,18000,11,@SPELL_THUNDERING_ROAR,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wooly Mammoth Bull - In Combat - Cast Thundering Roar"); -- It's a fear spell

-- Wooly Rhino Calf SAI
SET @ENTRY := 25488;
SET @SPELL_ANIMAL_BLOOD := 46221;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Wooly Rhino Calf - On Death - Cast Animal Blood");

-- Wooly Rhino Matriarch SAI
SET @ENTRY := 25487;
SET @SPELL_ANIMAL_BLOOD := 46221;
SET @SPELL_THICK_HIDE := 50502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,@SPELL_ANIMAL_BLOOD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Wooly Rhino Matriarch - On Death - Cast Animal Blood"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL_THICK_HIDE,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wooly Rhino Matriarch - On Aggro - Cast Thick Hide");
