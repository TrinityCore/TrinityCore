-- SAI for Prince Valanar
SET @ENTRY := 28907;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `creature_ai_texts` WHERE `entry` BETWEEN -781 AND -795;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- AI
(@ENTRY,0,0,0,1,0,100,0,10000,20000,145000,145000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - OOC - run script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - Emote'),
(@ENTRY*100,9,1,0,0,0,100,0,3000,3000,3000,3000,69,0,0,0,0,0,0,8,0,0,0,2311.38,-5740.136,155.9813,0,'Prince Valanar - Script - moveto'),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,3000,3000,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - Emote'),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,2000,2000,69,0,0,0,0,0,0,8,0,0,0,2316.76,-5738.414,155.9813,0,'Prince Valanar - Script - moveto'),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 0'),
(@ENTRY*100,9,5,0,0,0,100,0,5000,5000,5000,5000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 1'),
(@ENTRY*100,9,6,0,0,0,100,0,4500,4500,4500,4500,69,0,0,0,0,0,0,8,0,0,0,2314.704,-5736.364,155.9813,0,'Prince Valanar - Script - moveto'),
(@ENTRY*100,9,7,0,0,0,100,0,1500,1500,1500,1500,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.308997,'Prince Valanar - Script - turnto'),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 2'),
(@ENTRY*100,9,9,0,0,0,100,0,4000,4000,4000,4000,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - Emote'),
(@ENTRY*100,9,10,0,0,0,100,0,2000,2000,2000,2000,69,0,0,0,0,0,0,8,0,0,0,2316.619,-5742.296,155.9813,0,'Prince Valanar - Script - moveto'),
(@ENTRY*100,9,11,0,0,0,100,0,2000,2000,2000,2000,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.590216,'Prince Valanar - Script - turnto'),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 3'),
(@ENTRY*100,9,13,0,0,0,100,0,3000,3000,3000,3000,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - Emote'),
(@ENTRY*100,9,14,0,0,0,100,0,3000,3000,3000,3000,69,0,0,0,0,0,0,8,0,0,0,2316.648,-5738.609,155.9813,0,'Prince Valanar - Script - moveto'),
(@ENTRY*100,9,15,0,0,0,100,0,1500,1500,1500,1500,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.7330383,'Prince Valanar - Script - turnto'),
(@ENTRY*100,9,16,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 4'),
(@ENTRY*100,9,17,0,0,0,100,0,3000,3000,3000,3000,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - Emote'),
(@ENTRY*100,9,18,0,0,0,100,0,4000,4000,4000,4000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 5'),
(@ENTRY*100,9,19,0,0,0,100,0,3000,3000,3000,3000,5,273,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - Emote'),
(@ENTRY*100,9,20,0,0,0,100,0,2000,2000,2000,2000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 6'),
(@ENTRY*100,9,21,0,0,0,100,0,5000,5000,5000,5000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 7'),
(@ENTRY*100,9,22,0,0,0,100,0,4000,4000,4000,4000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 8'),
(@ENTRY*100,9,23,0,0,0,100,0,4000,4000,4000,4000,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 9'),
(@ENTRY*100,9,24,0,0,0,100,0,1000,1000,1000,1000,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 10'),
(@ENTRY*100,9,25,0,0,0,100,0,1000,1000,1000,1000,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 11'),
(@ENTRY*100,9,26,0,0,0,100,0,4000,4000,4000,4000,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 12'),
(@ENTRY*100,9,27,0,0,0,100,0,4000,4000,4000,4000,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - Emote'),
(@ENTRY*100,9,28,0,0,0,100,0,4000,4000,4000,4000,5,22,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - Emote'),
(@ENTRY*100,9,29,0,0,0,100,0,4000,4000,4000,4000,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Valanar - Script - say 13'),
(@ENTRY*100,9,30,0,0,0,100,0,0,0,0,0,5,66,0,0,0,0,0,11,28933,25,0,0,0,0,0,'Prince Valanar - Script - Emote');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (28907);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28907,0,0, 'The sky itself feeds upon the suffering of the conquered!',12,7,100,5,0,0, 'Prince Valanar'),
(28907,1,0, 'The Scarlet Crusade is powerless to stop us!',12,7,100,5,0,0, 'Prince Valanar'),
(28907,2,0, 'The corpses of those that try only serve to feed our expanding host!',12,7,100,1,0,0, 'Prince Valanar'),
(28907,3,0, 'The Scarlet fleet lies in ruin upon the sundered coast!',12,7,100,25,0,0, 'Prince Valanar'),
(28907,4,0, 'With each enemy slain, our strength grows! We mustn''t relent!',12,7,100,5,0,0, 'Prince Valanar'),
(28907,5,0, 'The Lich King has spoken to each of you! Let his words resonate among you once more!',12,7,100,25,0,0, 'Prince Valanar'),
(28907,6,0, 'ALL. MUST. DIE.',12,7,100,22,0,0, 'Prince Valanar'),
(28907,7,0, 'Leave no survivors in your wake, brothers and sisters!',12,7,100,274,0,0, 'Prince Valanar'),
(28907,8,0, 'No mercy for the weak!',12,7,100,15,0,0, 'Prince Valanar'),
(28907,9,0, 'TERROR!',12,7,100,5,0,0, 'Prince Valanar'),
(28907,10,0, 'CHAOS!',12,7,100,22,0,0, 'Prince Valanar'),
(28907,11,0, 'DESTRUCTION!',12,7,100,15,0,0, 'Prince Valanar'),
(28907,12,0, 'With the approaching darkness comes the end of the Scarlet Crusade. You will battle once more! For the Scourge! For the Lich King!',12,7,100,5,0,0, 'Prince Valanar'),
(28907,13,0, 'SUFFER WELL, DEATH KNIGHTS!',12,7,100,71,0,9006, 'Prince Valanar');

DELETE FROM creature_ai_texts WHERE entry BETWEEN -712 AND -708; -- 26630
DELETE FROM creature_ai_texts WHERE entry BETWEEN -707 AND -698; -- 29305
DELETE FROM creature_ai_texts WHERE entry BETWEEN -575 AND -570; -- 17888
DELETE FROM creature_ai_texts WHERE entry BETWEEN -653 AND -644; -- 29120
DELETE FROM creature_ai_texts WHERE entry BETWEEN -695 AND -688; -- 26632

DELETE FROM `creature_text` WHERE `entry`=29305 AND `groupid`=1 AND `id`=2;
DELETE FROM `creature_text` WHERE `entry`=29305 AND `groupid`=6;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(29305, 1, 2, 'I crush you, cockroaches!',   14, 0, 100, 0, 0, 14725, 'moorabi - SAY_SLAY_3'),
(29305, 6, 0, '%s transforms into mammoth!', 16, 0, 100, 0, 0, 0,     'moorabi - EMOTE TRANSFORMED');
