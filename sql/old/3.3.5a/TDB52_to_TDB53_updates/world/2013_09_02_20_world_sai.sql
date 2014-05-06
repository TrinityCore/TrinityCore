-- Random comment
SET @QUEST              := 12470; -- Mystery of the Infinite (12470)
SET @NPC_HoE            := 27840; -- Hourglass of Eternity
SET @NPC_FU             := 27899; -- Future You
SET @NPC_ICM            := 27898; -- Infinite Chrono-Magus
SET @NPC_IA             := 27896; -- Infinite Assailant
SET @NPC_ID             := 27897; -- Infonite Destroyer
SET @NPC_IT             := 27900; -- Infinite Timerender
SET @SPELL_SUMMON_FU    := 49942; -- Mystery of the Infinite: Force Cast to Player of Summon Future You
SET @SPELL_CAST         := 49686; -- Mystery of the Infinite: Script Effect Player Cast Mirror Image
SET @SPELL_MIRROR       := 49889; -- Mystery of the Infinite: Future You's Mirror Image Aura
SET @SPELL_NEARBY       := 50867; -- Hourglass of Eternity Nearby
SET @AURA_VISUAL        := 50057; -- Mystery of the Infinite: Hourglass of Eternity Visual/Sound Aura
SET @AURA_CLASS         := 49925; -- Mystery of the Infinite: Future You's Mirror Class Aura
SET @FU_SAY_RAND        := 50037; -- Mystery of the Infinite: Future You's Whisper to Controller - Random
SET @FU_SAY_BYE         := 50023; -- Mystery of the Infinite: Future You's Whisper to Controller - Farewell
SET @FU_SAY_NOZD        := 50014; -- Mystery of the Infinite: Future You's Whisper to Controller - Nozdormu
SET @VIEW_INVISIBILITY  := 50020; -- Mystery of the Infinite: Hourglass cast See Invis on Master
SET @VIEW_INVISIBILITY1 := 50012; -- See Nozdormu Invisibility
SET @FU_DESPAWN_TIME    := 50022; -- Mystery of the Infinite: Future You's Despawn Timer
SET @SPELL_ASSAILANT    := 49900; -- Summon Infinite Assailant
SET @SPELL_DESTROYER    := 49901; -- Summon Infinite Destroyer
SET @SPELL_MAGUS        := 49902; -- Summon Infinite Chrono-Magus
SET @SPELL_TIMERENDER   := 49905; -- Summon Infinite Timerender

-- Hourglass of Eternity
UPDATE `creature` SET `orientation`=2.085232 WHERE `guid`=152260;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=27925;
UPDATE `creature_template` SET `AIName`='SmartAI',`RegenHealth`=0 WHERE `entry`=@NPC_HoE;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@NPC_HoE AND `source_type`=0) OR (`entryorguid`IN (@NPC_HoE*100,@NPC_HoE*100+1) AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_HoE,0,0,1,54,0,100,1,0,0,0,0,85,@SPELL_SUMMON_FU,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On spawn - Invoker Cast'),
(@NPC_HoE,0,1,2,61,0,100,0,0,0,0,0,11,@SPELL_NEARBY,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On link - Cast Spell'),
(@NPC_HoE,0,2,3,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - Set passive - Self'),
(@NPC_HoE,0,3,6,61,0,100,0,0,0,0,0,80,@NPC_HoE*100,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On link - Start timed script'),
(@NPC_HoE,0,4,0,6,0,100,0,0,0,0,0,6,@QUEST,0,0,0,0,0,16,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On Death - Fail Quest'),
(@NPC_HoE,0,5,0,38,0,100,0,2,1,0,0,80,@NPC_HoE*100+1,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On Data Set  - Start timed script two'),
(@NPC_HoE,0,6,0,61,0,100,0,0,0,0,0,11,@AURA_VISUAL,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On link - Cast Spell'),

-- Wave 1 + Random speech
(@NPC_HoE*100,9,0,0,0,0,100,1,5000,5000,0,0,45,1,1,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,1,0,0,0,100,1,5000,5000,0,0,45,1,2,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,2,0,0,0,100,1,5000,5000,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,3,0,0,0,100,1,0,0,0,0,11,@SPELL_ASSAILANT,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- Wave 2 + Random speech
(@NPC_HoE*100,9,4,0,0,0,100,1,5000,5000,0,0,45,1,3,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,5,0,0,0,100,1,6000,6000,0,0,45,1,4,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,6,0,0,0,100,1,19000,19000,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,7,0,0,0,100,1,0,0,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- Wave 3 + Random speech
(@NPC_HoE*100,9,8,0,0,0,100,1,5000,5000,0,0,45,1,5,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,9,0,0,0,100,1,6000,6000,0,0,45,1,6,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,10,0,0,0,100,1,5000,5000,0,0,45,1,7,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,11,0,0,0,100,1,14000,14000,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,12,0,0,0,100,1,0,0,0,0,11,@SPELL_ASSAILANT,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,13,0,0,0,100,1,0,0,0,0,11,@SPELL_DESTROYER,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- Wave 4 + Random speech 
(@NPC_HoE*100,9,14,0,0,0,100,1,5000,5000,0,0,45,1,8,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,15,0,0,0,100,1,9000,9000,0,0,45,1,9,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,16,0,0,0,100,1,7000,7000,0,0,45,1,10,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,17,0,0,0,100,1,9000,9000,0,0,11,@SPELL_MAGUS,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100,9,18,0,0,0,100,1,0,0,0,0,11,@SPELL_ASSAILANT,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'OHourglass of Eternity - On update - Cast Spell on self'),
(@NPC_HoE*100,9,19,0,0,0,100,1,0,0,0,0,11,@SPELL_DESTROYER,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- Wave 5 final + Random speech
(@NPC_HoE*100,9,20,0,0,0,100,1,23000,23000,0,0,11,@SPELL_TIMERENDER,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Cast Spell on self'),
-- End Text Script
(@NPC_HoE*100+1,9,0,0,0,0,100,1,4000,4000,0,0,45,2,1,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100+1,9,1,0,0,0,100,1,0,0,0,0,15,@QUEST,0,0,0,0,0,21,10,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Give Quest Credit'),
(@NPC_HoE*100+1,9,2,0,0,0,100,1,8000,8000,0,0,45,2,2,0,0,0,0,19,@NPC_FU,20,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update - Set Data on Future You'),
(@NPC_HoE*100+1,9,3,0,0,0,100,1,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Hourglass of Eternity - On update -Despawn after timer');

-- Future You
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_FU AND `source_type`=0;
UPDATE `creature_template` SET `faction_A`=2141,`faction_H`=2141,`AIName`='SmartAI',`unit_flags`=0,`RegenHealth`=0 WHERE `entry`=@NPC_FU;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_FU,0,0,1,54,0,100,1,0,0,0,0,85,@SPELL_MIRROR,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spawn - Invoker Cast Spell - Self'),
(@NPC_FU,0,1,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,11,@NPC_HoE,10,0,0.0,0.0,0.0,0.0,'Future You - On link - Set Orientation'),
(@NPC_FU,0,2,3,38,0,100,0,1,1,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 1'),
(@NPC_FU,0,4,5,38,0,100,0,1,2,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 2'),
(@NPC_FU,0,6,7,38,0,100,0,1,3,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,7,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 3'),
(@NPC_FU,0,8,9,38,0,100,0,1,4,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,9,0,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 4'),
(@NPC_FU,0,10,11,38,0,100,0,1,5,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,11,0,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 5'),
(@NPC_FU,0,12,13,38,0,100,0,1,6,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,13,0,61,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 6'),
(@NPC_FU,0,14,15,38,0,100,0,1,7,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,15,0,61,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 7'),
(@NPC_FU,0,16,17,38,0,100,0,1,8,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,17,0,61,0,100,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 8'),
(@NPC_FU,0,18,19,38,0,100,0,1,9,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,19,0,61,0,100,0,0,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 9'),
(@NPC_FU,0,20,21,38,0,100,0,1,10,0,0,11,@FU_SAY_RAND,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,21,0,61,0,100,0,0,0,0,0,1,10,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 10'),
(@NPC_FU,0,22,23,38,0,100,0,2,1,0,0,11,@FU_SAY_NOZD,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Cast spell'),
(@NPC_FU,0,23,0,61,0,100,0,0,0,0,0,1,11,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On spellhit - Whisper 11'),
(@NPC_FU,0,24,25,38,0,100,0,2,2,0,0,1,12,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Data Set - Whisper 12'),
(@NPC_FU,0,25,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,11,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Link - Despawn after timer'),
(@NPC_FU,0,26,27,7,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Evade - Despawn after timer'),
(@NPC_FU,0,27,0,61,0,100,0,0,0,0,0,85,@SPELL_SUMMON_FU,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Future You - On Link - Cast Summon Clone');

-- Clone invoker weapons
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SPELL_MIRROR;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_MIRROR,41055,1,'Copy main weapon'),
(@SPELL_MIRROR,45206,1,'Copy off weapon');

-- Spell Area to see Nozdormu invis
DELETE FROM `spell_area` WHERE spell = @VIEW_INVISIBILITY1;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(@VIEW_INVISIBILITY1, 4175, 12470, 0, 0, 0, 2, 1, 2, 11);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_MIRROR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,@SPELL_MIRROR,0,0,31,0,3,@NPC_FU,0,0,0,'','Spell target Future You');

DELETE FROM `creature_template_addon` WHERE `entry` IN (@NPC_HoE,@NPC_FU);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_HoE,0,0x0,0x1,''),
(@NPC_FU,0,0x0,0x1,'');

-- Future You's text
DELETE FROM `creature_text` WHERE `entry`=@NPC_FU;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_FU,1,0,'Hey there, $N, don''t be alarmed. It''s me... you... from the future. I''m here to help.',15,0,100,396,0,0,'Future You'),
(@NPC_FU,2,0,'Head''s up... here they come. I''ll help as much as I can. Let''s just keep them off the hourglass!',15,0,100,396,0,0,'Future You'),
(@NPC_FU,3,0,'No matter what, you can''t die, because that would mean that I would cease to exist, right? I was here before when i was you. I''m so confused!',15,0,100,0,0,0,'Future You'),
(@NPC_FU,4,0,'I can''t believe that I used to wear that.',15,0,100,0,0,0,'Future You'),
(@NPC_FU,5,0,'Sorry, but Chromie said that I couldn''t reveal anything about your future to you. She said that if I did, I would cease to exist.',15,0,100,0,0,0,'Future You'),
(@NPC_FU,6,0,'Wow, I''d forgotten how inexperienced I used to be.',15,0,100,0,0,0,'Future You'),
(@NPC_FU,7,0,'Look at you fight; no wonder I turned to drinking.',15,0,100,0,0,0,'Future You'),
(@NPC_FU,8,0,'What? Am I here alone. We both have a stake at this, you know!',15,0,100,0,0,0,'Future You'),
(@NPC_FU,9,0,'Listen. I''m not supposed to tell you this, but there''s going to be this party that you''re invited to. Whatever you do, DO NOT DRINK THE PUNCH!',15,0,100,0,0,0,'Future You'),
(@NPC_FU,10,0,'Wish I could remember how many of the Infinite Dragonflight were going to try to stop you. This fight was so long ago.',15,0,100,0,0,0,'Future You'),
(@NPC_FU,11,0,'Look, $N, the hourglass has revealed Nozdormu!',15,0,100,25,0,0,'Future You'),
(@NPC_FU,12,0,'Farewell, $N, Keep us alive and get some better equipment!',15,0,100,0,0,0,'Future You');

DELETE FROM `creature_ai_scripts` WHERE creature_id IN (27898,27900);
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=2111,`faction_H`=2111,`unit_flags`=559104 WHERE `entry` IN (@NPC_ICM,@NPC_IA,@NPC_ID,@NPC_IT);
-- Infinite Chrono-Magus
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_ICM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_ICM,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Set Phase 1 - On Aggro'),
(@NPC_ICM,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Stop Moving - On Aggro'),
(@NPC_ICM,0,2,0,4,1,100,1,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Cast bolt on Aggro'),
(@NPC_ICM,0,3,0,9,1,100,0,0,40,3400,4700,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,'Infinite Chrono-Magus -  Cast Bolt'),
(@NPC_ICM,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Start Moving - When not in bolt Range'),
(@NPC_ICM,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Stop Moving - 15 Yards'),
(@NPC_ICM,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Stop Moving - When in bolt Range'),
(@NPC_ICM,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Set Phase 2 - 15% Mana'),
(@NPC_ICM,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Start Moving - 15% Mana'),
(@NPC_ICM,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Infinite Chrono-Magus - Set Phase 1 - When Mana is above 30%'),
(@NPC_ICM,0,10,0,0,1,100,0,8000,8000,12000,14000,11,38085,0,0,0,0,0,2,0,0,0,0,0,0,0,'Infinite Chrono-Magus - IC -Cast Shadow Blast');

-- Infinite Timerender
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_IT;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_IT,0,0,0,0,0,100,0,5000,6000,12000,17000,11,51020,0,0,0,0,0,2,0,0,0,0,0,0,0,'Infinite Timerender - IC - Cast Time Lapse'),
(@NPC_IT,0,1,0,6,0,100,0,0,0,0,0,45,2,1,0,0,0,0,19,@NPC_HoE,20,0,0,0,0,0,'Infinite Timerender - On Death - Set Data on HoE');
