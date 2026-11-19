-- [Q] See You on the Other Side

-- Gan'jo SAI
SET @ENTRY := 26924;
SET @QUEST := 12121;
SET @GOSSIP := 10220;
SET @SPELL_RESURRECT := 61613;
UPDATE `creature_template` SET `npcflag`=3,`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,11,@SPELL_RESURRECT,1,0,0,0,0,7,0,0,0,0,0,0,0,"Gan'jo - On Gossip Select - Cast Ganjo Resurrection"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gan'jo - On Gossip Select - Close Gossip");

-- Essence of Warlord Jin'arrak SAI
SET @ENTRY := 26902;
SET @SPELL_DIE_EFFECT := 61611;
SET @SPELL_CAMERA_SHAKE := 47533;
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100) AND `source_type` IN (0,9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Essence of Warlord Jin'arrak - On Just Summoned - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,85,@SPELL_CAMERA_SHAKE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Essence of Warlord Jin'arrak - On Script - Invoker Cast Camera Shake - Small"),
(@ENTRY*100,9,1,0,0,0,100,0,4000,4000,0,0,33,@ENTRY,0,0,0,0,0,7,0,0,0,0,0,0,0,"Essence of Warlord Jin'arrak - On Script - Killed Monster Credit"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Essence of Warlord Jin'arrak - On Script - Monster Whisper Line 0"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,85,@SPELL_CAMERA_SHAKE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Essence of Warlord Jin'arrak - On Script - Invoker Cast Camera Shake - Small"),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,85,@SPELL_DIE_EFFECT,0,0,0,0,0,7,0,0,0,0,0,0,0,"Essence of Warlord Jin'arrak - On Script - Invoker Cast On The Other Side");

-- Essence of Warlord Jin'arrak text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"How dare you summon me without an offering!",42,0,0,0,0,0,"Essence of Warlord Jin'arrak");

-- Ganjo's Resurrection removes On The Other Side
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SPELL_RESURRECT;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_RESURRECT,-@SPELL_DIE_EFFECT,1,"Ganjo's Resurrection removes On The Other Side");

-- Conditions for Gan'jo's gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTarget`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`comment`) VALUES
(15,@GOSSIP,0,0,0,1,@SPELL_DIE_EFFECT,0,"Ganjo's Gossip - requires aura See You On The Other Side"),
(15,@GOSSIP,0,0,1,9,@QUEST,0,"Ganjo's Gossip - requires quest See You On The Other Side to be rewarded");
