-- See You on the Other Side (12121)
-- Jin'arrak's End (12152)

SET @ENTRY1         := 27199; -- Warlord Jinarrak
SET @ENTRY2         := 27200; -- Offering Bunny - Drakil'jin Exterior
SET @ENTRY3         := 26902; -- Essence of Warlord Jin'arrak
SET @ENTRY4         := 32742; -- Your Corpse
SET @ENTRY5         := 27201; -- Offering Target Bunny - Drakil'jin Exterior
SET @RAGE           := 47744; -- Rage of Jin'arrak
SET @OTOS           := 61611; -- On the Other Side
SET @BODY           := 61612; -- Summon Your Corpse
SET @OFFER          := 48059; -- Place Offering
SET @FEED           := 48060; -- Jin'arrak Feeds
SET @CREDIT         := 48194; -- Jin'arrak Kill Credit

-- Warlord Jinarrak
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY1;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY1,0,0,0,0,'17327 31951');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY1,@ENTRY1*100,@ENTRY1*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY1,0,0,0,54,0,100,1,0,0,0,0,44,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Warlord Jin''Arrak - Just summoned - Set phasemask 3 - Self'),
(@ENTRY1,0,1,2,38,0,100,0,0,2,0,0,80,@ENTRY1*100+1,0,2,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Warlord Jin''Arrak - On dataset 0 2 - Run script - Self'),
(@ENTRY1,0,2,0,61,0,100,0,0,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Linked - Play emote roar'),
(@ENTRY1,0,3,4,38,0,100,0,0,1,0,0,80,@ENTRY1*100,0,2,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Warlord Jin''Arrak - On dataset 0 1 - Run script - Self'),
(@ENTRY1,0,4,0,61,0,100,0,0,0,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Linked - Play emote roar'),
-- Scr 1
(@ENTRY1*100,9,0,0,0,0,100,1,0,0,0,0,11,47730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Script -  Gong Effect - Self'),
(@ENTRY1*100,9,1,0,0,0,100,1,10000,10000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Script - Emote Text - Self'),
(@ENTRY1*100,9,2,0,0,0,100,1,0,0,0,0,11,@RAGE,0,0,0,0,0,18,20,0,0,0,0,0,0,'Warlord Jin''Arrak - Script - Cast Rage of Jin''arrak - Players in range'),
(@ENTRY1*100,9,3,0,0,0,100,1,10000,10000,0,0,33,@ENTRY3,0,0,0,0,0,18,20,0,0,0,0,0,0,'Warlord Jin''Arrak - Script- Kill credit - Players in range'),
-- Scr2
(@ENTRY1*100+1,9,0,0,0,0,100,0,1500,1500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Script - Say 0'),
(@ENTRY1*100+1,9,1,0,0,0,100,0,1000,1000,0,0,11,48060,0,0,0,0,0,19,@ENTRY5,0,0,0,0,0,0,'Warlord Jin''Arrak - Script - Cast feed'),
(@ENTRY1*100+1,9,2,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Script - Say 1'),
(@ENTRY1*100+1,9,3,0,0,0,100,0,3000,3000,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Script - emotestate stun'),
(@ENTRY1*100+1,9,4,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Script - emotestate none'),
(@ENTRY1*100+1,9,5,0,0,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Warlord Jin''Arrak - Script - Set field_byte_1 to 7'),
(@ENTRY1*100+1,9,6,0,0,0,100,0,2000,2000,0,0,11,@CREDIT,0,0,0,0,0,18,20,0,0,0,0,0,0,'OOC - Cast credit - Players in range'),
(@ENTRY1*100+1,9,7,0,0,0,100,0,10000,10000,0,0,41,0,0,0,0,0,0,0,1,0,0,0,0,0,0,'OOC - Cast credit - Players in range');


DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-@RAGE,@OTOS);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-@RAGE,@OTOS,0,'Cast other side when curse expires'),
(@OTOS,@BODY,1,'Summon body when going to other side');


DELETE FROM `creature_text` WHERE `entry`=@ENTRY1;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY1,0,0,'Finally, a worthy offering!',41,0,0,0,0,0,'Warlord Jinarrak - Say Text'),
(@ENTRY1,1,0,'Ahhh! What be happenin'' to me, mon?',41,0,0,0,0,0,'Warlord Jinarrak - Say Text'),
(@ENTRY1,2,0,'How dare you summon me without an offering!',41,0,0,0,0,0,'Warlord Jinarrak - Say Text');

-- Offering Bunny - Drakil'jin Exterior
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=128 WHERE `entry`=@ENTRY2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY2,0,0,1,54,0,100,1,0,0,0,0,12,@ENTRY1,3,180000,0,0,0,8,0,0,0,4678.47,-4859.35,35.48,3.11,'Just summoned - Temp summon Warlord Jinarrak - Position'),
(@ENTRY2,0,1,0,61,0,100,1,0,0,0,0,11,@OFFER,0,0,0,0,0,1,0,0,0,0,0,0,0,'Link - Cast Place Offering - Self'),
(@ENTRY2,0,2,0,1,0,100,1,1000,1000,0,0,45,0,2,0,0,0,0,11,@ENTRY1,50,0,0,0,0,0,'OOC 2 sec later - Set data 0 2 - Warlord Jinarrak');

-- Essence of Warlord Jin'arrak
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=128 WHERE `entry`=@ENTRY3;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY3,0,0,0,54,0,100,1,0,0,0,0,12,@ENTRY1,3,30000,0,0,0,8,0,0,0,4678.47,-4859.35,35.48,3.11,'Just summoned - Temp summon - Position'),
(@ENTRY3,0,1,0,1,0,100,1,1000,1000,0,0,45,0,1,0,0,0,0,11,@ENTRY1,50,0,0,0,0,0,'OOC 1 sec later - Set data 0 1 - Warlord Jinarrak');
UPDATE creature_template SET AIName = 'SmartAI' WHERE entry =@ENTRY1;
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=@ENTRY5;
-- Your Corpse
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY4,0,0,1,54,0,100,1,0,0,0,0,85,60352,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Just summoned - Invoker cast Mirror Image - Invoker'),
(@ENTRY4,0,1,2,61,0,100,1,0,0,0,0,44,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Link - Set phasemask 3 - Self'),
(@ENTRY4,0,2,0,61,0,100,1,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Link - Cast Permanent Feign Death - Self');
