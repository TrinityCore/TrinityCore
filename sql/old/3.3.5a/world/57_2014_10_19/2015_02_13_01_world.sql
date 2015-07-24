--
SET @KC_FIRST_PROPHECY                  := 22798;
SET @KC_SECOND_PROPHECY                 := 22799;
SET @KC_THIRD_PROPHECY                  := 22800;
SET @KC_FOURTH_PROPHECY                 := 22801;
SET @QUEST_WHISPERS_RAVEN_GOD           := 10607;
SET @NPC_VISION_RAVEN_GOD               := 21861;
SET @SPELL_UNDERSTANDING_RAVENSPEECH    := 37466;
SET @AURA_UNDERSTANDING_RAVENSPEECH     := 37642;
SET @Falconwing                         := 19988;
SET @Harbinger                          := 19989;
SET @Scorncrow                          := 19990;

UPDATE `creature_template` SET `exp`='1', `minlevel`='67', `maxlevel`='67', `unit_flags`='768', `type`='7' WHERE `entry`=@NPC_VISION_RAVEN_GOD;

DELETE FROM `creature_text` WHERE `entry`=@NPC_VISION_RAVEN_GOD;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(@NPC_VISION_RAVEN_GOD,0,0,'From the darkest night shall rise again the raven, shall take flight in the shadows, shall reveal the nature of its kind. Prepare yourself for its coming, for the faithful shall be elevated to take flight with the raven, the rest be forgotten to walk upon the ground, clipped wings and shame.',15,0,100,0,0,0,'The Voice of the Raven God - The First Prophecy', 19475),
(@NPC_VISION_RAVEN_GOD,1,0,'Steel your minds and guard your thoughts. The dark wings will cloud and consume the minds of the weak, a flock of thralls whose feet may never leave the ground.', 15,0,100,0,0,0,'The Voice of the Raven God - The Second Prophecy', 19476),
(@NPC_VISION_RAVEN_GOD,2,0,'The Old blood will flow once again with the coming of the raven, the return of the darkness in the skies. Scarlet night, and the rise of the old.', 15,0,100,0,0,0,'The Voice of the Raven God - The Third Prophecy', 19477),
(@NPC_VISION_RAVEN_GOD,3,0,'The raven was struck down once for flying too high, unready. The eons have prepared the Dark Watcher for its ascent, to draw the dark cloak across the horizon.', 15,0,100,0,0,0,'The Voice of the Raven God - The Fourth Prophecy', 19478);

UPDATE creature_template SET AIName="SmartAI" WHERE entry IN (@Falconwing, @Harbinger, @Scorncrow,@NPC_VISION_RAVEN_GOD);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (184950,184967,184968,184969);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Falconwing, @Harbinger, @Scorncrow,@NPC_VISION_RAVEN_GOD) AND `source_type`=0; -- Npcs
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (184950,184967,184968,184969) AND `source_type`=1; -- Gameobjects (totems)
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
-- Npcs a matar para que te den el buff
(@Falconwing,0,0,0,0,0,100,0,2500,5500,10000,11000,11,37587,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grishna Falconwing - In Combat - Cast Bestial Wrath"),
(@Falconwing,0,1,0,6,0,35,0,0,0,0,0,85,@SPELL_UNDERSTANDING_RAVENSPEECH,2,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Grishna Falconwing - On Death - Cast Understanding Ravenspeech"),
(@Harbinger,0,0,0,0,0,100,0,2500,5500,20000,21000,11,37589,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grishna Harbinger - In Combat - Cast Shriveling Gaze"),
(@Harbinger,0,1,0,0,0,100,0,1000,6000,10000,15000,11,9532,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grishna Harbinger - In Combat - Cast Lightning Bolt"),
(@Harbinger,0,2,0,6,0,35,0,0,0,0,0,85,@SPELL_UNDERSTANDING_RAVENSPEECH,2,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Grishna Harbringer - On Death - Cast Understanding Ravenspeech"),
(@Scorncrow,0,0,0,0,0,100,0,2500,5500,10000,11000,11,35321,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Grishna Scorncrow - In Combat - Cast Gushing Wound"),
(@Scorncrow,0,1,0,6,0,35,0,0,0,0,0,85,@SPELL_UNDERSTANDING_RAVENSPEECH,2,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Grishna Scorncrow - On Death - Cast Understanding Ravenspeech"),
-- Vision Of Raven God
(@NPC_VISION_RAVEN_GOD,0,0,1,38,0,100,0,1,1,0,0,33,@KC_FIRST_PROPHECY,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Call Killedmonster"),
(@NPC_VISION_RAVEN_GOD,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 0"),
(@NPC_VISION_RAVEN_GOD,0,2,3,38,0,100,0,1,2,0,0,33,@KC_SECOND_PROPHECY,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Call Killedmonster"),
(@NPC_VISION_RAVEN_GOD,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 1"),
(@NPC_VISION_RAVEN_GOD,0,4,5,38,0,100,0,1,3,0,0,33,@KC_THIRD_PROPHECY ,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Call Killedmonster"),
(@NPC_VISION_RAVEN_GOD,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 2"),
(@NPC_VISION_RAVEN_GOD,0,6,7,38,0,100,0,1,4,0,0,33,@KC_FOURTH_PROPHECY,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Call Killedmonster"),
(@NPC_VISION_RAVEN_GOD,0,7,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 3"),
-- GOB Totems
(184950,1,0,1,64,0,100,0,0,0,0,0,12,@NPC_VISION_RAVEN_GOD,3,6000,0,0,0,8,0,0,0,3779.987061,6729.603027,180.498413,5.71490,"First Prophecy - On Gossip Hello - Summon Whisper Raven God"),
(184950,1,1,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@NPC_VISION_RAVEN_GOD,20,0,0,0,0,0,"First Prophecy - Link - Set Data 1 to Raven God"),
(184967,1,0,1,64,0,100,0,0,0,0,0,12,@NPC_VISION_RAVEN_GOD,3,6000,0,0,0,8,0,0,0,3629.285889,6542.140137,155.004669,2.56267,"Second Prophecy - On Gossip Hello - Summon Whisper Raven God"),
(184967,1,1,0,61,0,100,0,0,0,0,0,45,1,2,0,0,0,0,11,@NPC_VISION_RAVEN_GOD,20,0,0,0,0,0,"Second Prophecy - Link - Set Data 2 to Raven God"),
(184968,1,0,1,64,0,100,0,0,0,0,0,12,@NPC_VISION_RAVEN_GOD,3,6000,0,0,0,8,0,0,0,3736.950439,6640.749023,133.674530,3.33629,"Third Prophecy - On Gossip Hello - Summon Whisper Raven God"),
(184968,1,1,0,61,0,100,0,0,0,0,0,45,1,3,0,0,0,0,11,@NPC_VISION_RAVEN_GOD,20,0,0,0,0,0,"Third Prophecy - Link - Set Data 3 to Raven God"),
(184969,1,0,1,64,0,100,0,0,0,0,0,12,@NPC_VISION_RAVEN_GOD,3,6000,0,0,0,8,0,0,0,3572.574219,6669.196289,128.455444,5.62290,"Four Prophecy - On Gossip Hello - Summon Whisper Raven God"),
(184969,1,1,0,61,0,100,0,0,0,0,0,45,1,4,0,0,0,0,11,@NPC_VISION_RAVEN_GOD,20,0,0,0,0,0,"Fourth Prophecy - Link - Set Data 4 to Raven God");

DELETE FROM `conditions` WHERE `ConditionValue1`=@AURA_UNDERSTANDING_RAVENSPEECH AND `sourcetypeorreferenceid`=22;
DELETE FROM `conditions` WHERE `ConditionValue1`=@NPC_VISION_RAVEN_GOD AND `sourcetypeorreferenceid`=22;
DELETE FROM `conditions` WHERE `SourceEntry`=@NPC_VISION_RAVEN_GOD AND `sourcetypeorreferenceid`=22;
INSERT INTO `conditions` (SourceTypeOrReferenceId,SourceGroup,SourceEntry,SourceId,ElseGroup,ConditionTypeOrReference,ConditionTarget,ConditionValue1,ConditionValue2,ConditionValue3,NegativeCondition,ErrorType,ErrorTextId,ScriptName,`Comment`) VALUES
(22,1,184950,1,0,1 ,0,@AURA_UNDERSTANDING_RAVENSPEECH,0,0,0,0,0,'','GOb First Prophecy - SAI 1, only if player has aura Understanding Ravenspeech'),
(22,1,184950,1,0,29,0,@NPC_VISION_RAVEN_GOD,20,0,1,0,0,'','GOb First Prophecy - SAI 1, only if Raven God is not near'),
(22,1,184967,1,0,1 ,0,@AURA_UNDERSTANDING_RAVENSPEECH,0,0,0,0,0,'','GOb Second Prophecy - SAI 1, only if player has aura Understanding Ravenspeech'),
(22,1,184967,1,0,29,0,@NPC_VISION_RAVEN_GOD,20,0,1,0,0,'','GOb Second Prophecy - SAI 1, only if Raven God is not near'),
(22,1,184968,1,0,1 ,0,@AURA_UNDERSTANDING_RAVENSPEECH,0,0,0,0,0,'','GOb Third Prophecy - SAI 1, only if player has aura Understanding Ravenspeech'),
(22,1,184968,1,0,29,0,@NPC_VISION_RAVEN_GOD,20,0,1,0,0,'','GOb Third Prophecy - SAI 1, only if Raven God is not near'),
(22,1,184969,1,0,1 ,0,@AURA_UNDERSTANDING_RAVENSPEECH,0,0,0,0,0,'','GOb Fourth Prophecy - SAI 1, only if player has aura Understanding Ravenspeech'),
(22,1,184969,1,0,29,0,@NPC_VISION_RAVEN_GOD,20,0,1,0,0,'','GOb Fourth Prophecy - SAI 1, only if Raven God is not near');
