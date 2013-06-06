-- Fix for Quest 11317 & 11322 "The Cleansing"
-- Your Inner Turmoil SAI
SET @ENTRY  := 27959;
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|256,`AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,41408,2,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On Summon - Cast Shadowform on self'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,85,50218,2,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On Summon - Player Cast The Cleansing: Your Inner Turmoil''s Mirror Image Aura on npc'),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,85,41054,2,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On Summon - Player Cast Copy Weapon on npc'),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,85,41055,2,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On Summon - Player Cast Copy Weapon on npc'),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,85,45205,2,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On Summon - Player Cast Copy Offhand Weapon on npc'),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,85,45206,2,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On Summon - Player Cast Copy Offhand Weapon on npc'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On Summon - Run Script'),
(@ENTRY,0,7,0,2,0,100,1,0,50,0,0,1,2,2,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - @50%hp - Say 2'),
(@ENTRY,0,8,9,6,0,100,1,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On death - Say 3'),
(@ENTRY,0,9,0,61,0,100,1,0,0,0,0,3,0,11686,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - On death - set model'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Your Inner Turmoil - Script - Turn to invoker'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Your Inner Turmoil - Script - Say 0'),
(@ENTRY*100,9,2,0,0,0,100,0,6000,6000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Your Inner Turmoil - Script - Turn to invoker'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Your Inner Turmoil - Script - Say 1'),
(@ENTRY*100,9,4,0,0,0,100,0,7000,7000,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Your Inner Turmoil - Script - remove unit flags'),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Your Inner Turmoil - Script - Attack invoker');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'You think that you can get rid of me through meditation?',15,0,100,0,0,0,'Your Inner Turmoil text 0'),
(@ENTRY,1,0,'Fool! I will destroy you and finally become that which has been building inside of you all of these years!',15,0,100,0,0,0,'Your Inner Turmoil text 1'),
(@ENTRY,2,0,'You cannot defeat me. I''m an inseparable part of you!',15,0,100,0,0,0,'Your Inner Turmoil text 50%'),
(@ENTRY,3,0,'NOOOOOOOoooooooooo!',15,0,100,0,0,0,'Your Inner Turmoil text death');
-- Spell Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (50218,41054,41055,45205,45206);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,50218,0,31,3,27959,0,0,'','Spell 50218 can target Your Inner Turmoil'),
(13,1,41054,0,31,3,27959,0,0,'','Spell 41054 can target Your Inner Turmoil'),
(13,1,41055,0,31,3,27959,0,0,'','Spell 41055 can target Your Inner Turmoil'),
(13,1,45205,0,31,3,27959,0,0,'','Spell 45205 can target Your Inner Turmoil'),
(13,1,45206,0,31,3,27959,0,0,'','Spell 45206 can target Your Inner Turmoil');
-- Spell Linking
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-43351;
INSERT INTO spell_linked_spell VALUES
(-43351,50167,0, ''),
(-43351,61720,0, '');
