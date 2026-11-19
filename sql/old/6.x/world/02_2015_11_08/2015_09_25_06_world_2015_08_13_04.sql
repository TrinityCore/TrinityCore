-- 
SET @QUEST              := 13343; -- Mystery of the Infinite 2 (13343)
SET @NPC_HoE            := 32327; -- Hourglass of Eternity
SET @NPC_PU             := 32331; -- Past You
SET @SPELL_SUMMON_PU    := 60790; -- Mystery of the Infinite: Force Cast to Player of Summon Past You
SET @SPELL_MIRROR       := 49889; -- Mystery of the Infinite: Future You's Mirror Image Aura
SET @SPELL_NEARBY       := 50867; -- Hourglass of Eternity Nearby
SET @AURA_VISUAL        := 50057; -- Mystery of the Infinite: Hourglass of Eternity Visual/Sound Aura
SET @SPELL_ASSAILANT    := 49900; -- Summon Infinite Assailant
SET @SPELL_DESTROYER    := 49901; -- Summon Infinite Destroyer
SET @SPELL_MAGUS        := 49902; -- Summon Infinite Chrono-Magus
SET @SPELL_TIMERENDER   := 60887; -- Summon Infinite Timerender
SET @NPC_IT             := 32352; -- Infinite Timerender

-- Infinite Timerender
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_IT;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_IT;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_IT,0,0,0,0,0,100,0,5000,6000,12000,17000,11,51020,0,0,0,0,0,2,0,0,0,0,0,0,0,'Infinite Timerender - IC - Cast Time Lapse'),
(@NPC_IT,0,1,0,6,0,100,0,0,0,0,0,45,2,1,0,0,0,0,19,@NPC_HoE,20,0,0,0,0,0,'Infinite Timerender - On Death - Set Data on HoE');

UPDATE `spell_area` SET `quest_start_status`=66, `quest_end_status`=0 WHERE `spell`=50012 AND `area`=4175;

-- Hourglass of Eternity
UPDATE `creature_template` SET `AIName`='SmartAI',`RegenHealth`=0 WHERE `entry`=@NPC_HoE;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@NPC_HoE AND `source_type`=0) OR (`entryorguid`IN (@NPC_HoE*100,@NPC_HoE*100+1) AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_HoE,0,0,1,54,0,100,1,0,0,0,0,85,@SPELL_SUMMON_PU,0,0,0,0,0,7,0,0,0,0,0,0,0,'Hourglass of Eternity - On spawn - Invoker Cast'),
(@NPC_HoE,0,1,2,61,0,100,0,0,0,0,0,11,@SPELL_NEARBY,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On link - Cast Spell'),
(@NPC_HoE,0,2,3,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - Set passive - Self'),
(@NPC_HoE,0,3,6,61,0,100,0,0,0,0,0,80,@NPC_HoE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On link - Start timed script'),
(@NPC_HoE,0,4,0,6,0,100,0,0,0,0,0,6,@QUEST,0,0,0,0,0,16,0,0,0,0,0,0,0,'Hourglass of Eternity - On Death - Fail Quest'),
(@NPC_HoE,0,5,0,38,0,100,0,2,1,0,0,80,@NPC_HoE*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On Data Set  - Start timed script two'),
(@NPC_HoE,0,6,0,61,0,100,0,0,0,0,0,11,@AURA_VISUAL,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On link - Cast Spell'),
(@NPC_HoE,0,7,0,54,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Hourglass of Eternity - On spawn - Store target'),

-- Wave 1 
(@NPC_HoE*100,9,0,0,0,0,100,1,3000,3000,0,0,45,1,1,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,1,0,0,0,100,1,5000,5000,0,0,45,1,2,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,2,0,0,0,100,1,5000,5000,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,3,0,0,0,100,1,0,0,0,0,11,@SPELL_ASSAILANT,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- Wave 2 
(@NPC_HoE*100,9,4,0,0,0,100,1,5000,5000,0,0,45,1,3,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,5,0,0,0,100,1,6000,6000,0,0,45,1,4,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,6,0,0,0,100,1,19000,19000,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,7,0,0,0,100,1,0,0,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- Wave 3 
(@NPC_HoE*100,9,8,0,0,0,100,1,5000,5000,0,0,45,1,5,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,9,0,0,0,100,1,6000,6000,0,0,45,1,6,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,10,0,0,0,100,1,5000,5000,0,0,45,1,7,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,11,0,0,0,100,1,14000,14000,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,12,0,0,0,100,1,0,0,0,0,11,@SPELL_ASSAILANT,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,13,0,0,0,100,1,0,0,0,0,11,@SPELL_DESTROYER,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- Wave 4 
(@NPC_HoE*100,9,14,0,0,0,100,1,5000,5000,0,0,45,1,8,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,15,0,0,0,100,1,9000,9000,0,0,45,1,9,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,16,0,0,0,100,1,7000,7000,0,0,45,1,10,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,17,0,0,0,100,1,9000,9000,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100,9,18,0,0,0,100,1,0,0,0,0,11,@SPELL_ASSAILANT,0,0,0,0,0,1,0,0,0,0,0,0,0,'OHourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,19,0,0,0,100,1,0,0,0,0,11,@SPELL_DESTROYER,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- Wave 5 final 
(@NPC_HoE*100,9,20,0,0,0,100,1,23000,23000,0,0,11,@SPELL_TIMERENDER,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- End Text Script
(@NPC_HoE*100+1,9,0,0,0,0,100,1,4000,4000,0,0,45,2,1,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100+1,9,1,0,0,0,100,1,0,0,0,0,15,@QUEST,0,0,0,0,0,12,1,0,0,0,0,0,0,'Hourglass of Eternity - On update - Give Quest Credit'),
(@NPC_HoE*100+1,9,2,0,0,0,100,1,8000,8000,0,0,45,2,2,0,0,0,0,19,@NPC_PU,20,0,0,0,0,0,'Hourglass of Eternity - On update - Set Data on Past You'),
(@NPC_HoE*100+1,9,3,0,0,0,100,1,4000,4000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hourglass of Eternity - On update -Despawn after timer');

-- Past You
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_PU AND `source_type`=0;
UPDATE `creature_template` SET `faction`=2141,`AIName`='SmartAI',`unit_flags`=0,`RegenHealth`=0, `minlevel`=75, `maxlevel`=75 WHERE `entry`=@NPC_PU;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_PU,0,0,1,54,0,100,1,0,0,0,0,85,@SPELL_MIRROR,2,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On spawn - Invoker Cast Spell - Self'),
(@NPC_PU,0,1,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,11,@NPC_HoE,10,0,0,0,0,0,'Past You - On link - Set Orientation'),
(@NPC_PU,0,2,0,38,0,100,0,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 1'),
(@NPC_PU,0,3,0,38,0,100,0,1,2,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 2'),
(@NPC_PU,0,4,0,38,0,100,0,1,3,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 3'),
(@NPC_PU,0,5,0,38,0,100,0,1,4,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 4'),
(@NPC_PU,0,6,0,38,0,100,0,1,5,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 5'),
(@NPC_PU,0,7,0,38,0,100,0,1,6,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 6'),
(@NPC_PU,0,8,0,38,0,100,0,1,7,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 7'),
(@NPC_PU,0,9,0,38,0,100,0,1,8,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 8'),
(@NPC_PU,0,10,0,38,0,100,0,1,9,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 9'),
(@NPC_PU,0,11,0,38,0,100,0,1,10,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 10'),
(@NPC_PU,0,12,0,38,0,100,0,2,1,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Data set - Whisper 11'),
(@NPC_PU,0,13,14,38,0,100,0,2,2,0,0,1,12,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Whisper 12'),
(@NPC_PU,0,14,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Link - Despawn after timer'),
(@NPC_PU,0,15,16,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Past You - On Evade - Despawn after timer'),
(@NPC_PU,0,16,0,61,0,100,0,0,0,0,0,85,@SPELL_SUMMON_PU,0,0,0,0,0,7,0,0,0,0,0,0,0,'Past You - On Link - Cast Summon Clone');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_MIRROR AND `ConditionValue2`=@NPC_PU;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,@SPELL_MIRROR,0,1,31,0,3,@NPC_PU,0,0,0,'','Spell target Past You');

DELETE FROM `creature_template_addon` WHERE `entry` IN (@NPC_PU);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_PU,0,0x0,0x1,'');

-- Past You's text
DELETE FROM `creature_text` WHERE `entry`=@NPC_PU;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@NPC_PU,1,0,'Whoa! You''re me, but from the future! Hey, my equipment got an upgrade! Cool!',15,0,100,396,0,0,'Past You', 32764), 
(@NPC_PU,2,0,'Here come the Infinites! I''ve got to keep the hourglass safe. Can you help?',15,0,100,396,0,0,'Past You', 32769), 
(@NPC_PU,3,0,'This equipment looks cool and all, but couldn''t we have done a little better? Are you even raiding?',15,0,100,396,0,0,'Past You', 32770), 
(@NPC_PU,4,0,'So, how does it all turn out in Icecrown?',15,0,100,396,0,0,'Past You', 32771),
(@NPC_PU,5,0,'It might help if you could tell me how many of these guys we''re going to fight.  You can remember that, right, grandpa?',15,0,100,396,0,0,'Past You', 32775),
(@NPC_PU,6,0,'Chromie said that if I don''t do this just right, I might wink out of existence. If I go, then you go!',15,0,100,396,0,0,'Past You', 32772), 
(@NPC_PU,7,0,'I just want you to know that if we get through this alive, I''m making sure that we turn out better than you. No offense.',15,0,100,396,0,0,'Past You', 32776), 
(@NPC_PU,8,0,'Looks like I''m an underachiever.',15,0,100,396,0,0,'Past You', 32773), 
(@NPC_PU,9,0,'Wait a minute! If you''re here, then that means that in the not-so-distant future I''m going to be you helping me? Are we stuck in a time loop?!',15,0,100,396,0,0,'Past You', 32777), 
(@NPC_PU,10,0,'I think I''m going to turn to drinking after this.',15,0,100,396,0,0,'Past You', 32774), 
(@NPC_PU,11,0,'What the heck? Nozdormu is up there!',15,0,100,396,0,0,'Past You', 32781), 
(@NPC_PU,12,0,'I feel like I''m being pulled away through time. Thanks for the help....',15,0,100,396,0,0,'Past You', 32782);
