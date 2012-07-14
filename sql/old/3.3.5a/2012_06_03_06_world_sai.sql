-- Bron Goldhammer SAI
SET @ENTRY := 19395;
SET @SPELL := 33822;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature_template` SET `AIName`= '' WHERE `entry`=19394;
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@ENTRY,19394);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,30000,100000,100000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bron Goldhammer - OOC - Run Script'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,11,19394,15,0,0,0,0,0, 'Bron Goldhammer - Script - Barimoke Wildbeard Say 0'),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bron Goldhammer - Script - Bron Goldhammer Say 0'),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bron Goldhammer - Script - Bron Goldhammer Say 1'),
(@ENTRY*100,9,3,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,11,19394,15,0,0,0,0,0, 'Bron Goldhammer - Script - Barimoke Wildbeard Say 1'),
(@ENTRY*100,9,4,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bron Goldhammer - Script - Bron Goldhammer Say 2'),
(@ENTRY*100,9,5,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,11,19394,15,0,0,0,0,0, 'Bron Goldhammer - Script - Barimoke Wildbeard Say 2'),
(@ENTRY*100,9,6,0,0,0,100,0,2500,2500,0,0,11,@SPELL,3,0,0,0,0,11,19394,15,0,0,0,0,0, 'Bron Goldhammer - Script - cast spell'),
(@ENTRY*100,9,7,0,0,0,100,0,1000,1000,0,0,90,7,0,0,0,0,0,11,19394,15,0,0,0,0,0, 'Bron Goldhammer - Script - Barimoke Wildbeard set bytes 1'),
(@ENTRY*100,9,8,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Bron Goldhammer - Script - Bron Goldhammer Say 3'),
(@ENTRY*100,9,9,0,0,0,100,0,2000,2000,0,0,91,7,0,0,0,0,0,11,19394,15,0,0,0,0,0, 'Bron Goldhammer - Script - Barimoke Wildbeard remove bytes 1'),
(@ENTRY*100,9,10,0,0,0,100,0,500,500,0,0,1,3,0,0,0,0,0,11,19394,15,0,0,0,0,0, 'Bron Goldhammer - Script - Barimoke Wildbeard Say 3');
-- Bron Goldhammer text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-325,-326,-327,-328);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s blinks, a perplexed expression crossing his face.',16,0,100,0,0,0, 'Bron Goldhammer'),
(@ENTRY,1,0, 'What, with me fists?',12,0,100,6,0,0, 'Bron Goldhammer'),
(@ENTRY,2,0, 'I''m... not sure that''s a good idea, ''Moke. Ye might get hurt...',12,0,100,1,0,0, 'Bron Goldhammer'),
(@ENTRY,3,0, 'Er... ''Moke?',12,0,100,6,0,0, 'Bron Goldhammer');
-- Barimoke Wildbeard text
SET @ENTRY  := 19394;
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-329,-330,-331,-332);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Bron! ''Ey Bron! ''Ey Bron! Hit me!',12,0,100,1,0,0, 'Barimoke Wildbeard'),
(@ENTRY,1,0, 'Nae, that''s fer wimps. Hit me with yer hammer!',12,0,100,274,0,0, 'Barimoke Wildbeard'),
(@ENTRY,2,0, 'DO IT, YE PANSEY!',12,0,100,5,0,0, 'Barimoke Wildbeard'),
(@ENTRY,3,0, '...THAT WAS GREAT!',12,0,100,5,0,0, 'Barimoke Wildbeard');
