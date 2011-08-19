-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7333 AND `text_id`=8717;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7333,8717);
DELETE FROM `gossip_menu` WHERE `entry`=7334 AND `text_id`=8718;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7334,8718);
DELETE FROM `gossip_menu` WHERE `entry`=7335 AND `text_id`=8719;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7335,8719);
DELETE FROM `gossip_menu` WHERE `entry`=7348 AND `text_id`=8767;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7348,8767);
DELETE FROM `gossip_menu` WHERE `entry`=7420 AND `text_id`=8962;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7420,8962);
DELETE FROM `gossip_menu` WHERE `entry`=7825 AND `text_id`=9574;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7825,9574);
DELETE FROM `gossip_menu` WHERE `entry`=7878 AND `text_id`=9642;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7878,9642);
DELETE FROM `gossip_menu` WHERE `entry`=7893 AND `text_id`=9657;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7893,9657);
DELETE FROM `gossip_menu` WHERE `entry`=7955 AND `text_id`=9771;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7955,9771);
DELETE FROM `gossip_menu` WHERE `entry`=7967 AND `text_id`=9801;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7967,9801);
DELETE FROM `gossip_menu` WHERE `entry`=7967 AND `text_id`=10027;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7967,10027);
DELETE FROM `gossip_menu` WHERE `entry`=8069 AND `text_id`=9969;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8069,9969);
DELETE FROM `gossip_menu` WHERE `entry`=8085 AND `text_id`=9995;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8085,9995);
DELETE FROM `gossip_menu` WHERE `entry`=8086 AND `text_id`=9996;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8086,9996);
DELETE FROM `gossip_menu` WHERE `entry`=8087 AND `text_id`=9997;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8087,9997);
DELETE FROM `gossip_menu` WHERE `entry`=8089 AND `text_id`=10004;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8089,10004);
DELETE FROM `gossip_menu` WHERE `entry`=8090 AND `text_id`=10003;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8090,10003);
DELETE FROM `gossip_menu` WHERE `entry`=8091 AND `text_id`=10005;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8091,10005);
DELETE FROM `gossip_menu` WHERE `entry`=8269 AND `text_id`=10293;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8269,10293);
DELETE FROM `gossip_menu` WHERE `entry`=8272 AND `text_id`=10301;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8272,10301);
DELETE FROM `gossip_menu` WHERE `entry`=8274 AND `text_id`=10306;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8274,10306);
DELETE FROM `gossip_menu` WHERE `entry`=8495 AND `text_id`=10610;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8495,10610);
DELETE FROM `gossip_menu` WHERE `entry`=8505 AND `text_id`=10636;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8505,10636);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=19558;
UPDATE `creature_template` SET `gossip_menu_id`=7333 WHERE `entry`=16584;
UPDATE `creature_template` SET `gossip_menu_id`=7334 WHERE `entry`=16574;
UPDATE `creature_template` SET `gossip_menu_id`=7335 WHERE `entry`=16576;
UPDATE `creature_template` SET `gossip_menu_id`=7348 WHERE `entry`=16858;
UPDATE `creature_template` SET `gossip_menu_id`=7420 WHERE `entry`=17493;
UPDATE `creature_template` SET `gossip_menu_id`=7691 WHERE `entry`=18748;
UPDATE `creature_template` SET `gossip_menu_id`=7810 WHERE `entry`=16588;
UPDATE `creature_template` SET `gossip_menu_id`=7816 WHERE `entry`=18754;
UPDATE `creature_template` SET `gossip_menu_id`=7825 WHERE `entry`=17558;
UPDATE `creature_template` SET `gossip_menu_id`=7878 WHERE `entry`=16915;
UPDATE `creature_template` SET `gossip_menu_id`=7893 WHERE `entry`=18267;
UPDATE `creature_template` SET `gossip_menu_id`=7955 WHERE `entry`=19273;
UPDATE `creature_template` SET `gossip_menu_id`=7957 WHERE `entry`=19315;
UPDATE `creature_template` SET `gossip_menu_id`=7960 WHERE `entry`=19344;
UPDATE `creature_template` SET `gossip_menu_id`=7965 WHERE `entry`=19367;
UPDATE `creature_template` SET `gossip_menu_id`=7967 WHERE `entry`=19401;
UPDATE `creature_template` SET `gossip_menu_id`=8069 WHERE `entry`=19254;
UPDATE `creature_template` SET `gossip_menu_id`=8085 WHERE `entry`=3230;
UPDATE `creature_template` SET `gossip_menu_id`=8086 WHERE `entry`=19253;
UPDATE `creature_template` SET `gossip_menu_id`=8087 WHERE `entry`=19255;
UPDATE `creature_template` SET `gossip_menu_id`=8091 WHERE `entry`=19256;
UPDATE `creature_template` SET `gossip_menu_id`=8269 WHERE `entry`=21257;
UPDATE `creature_template` SET `gossip_menu_id`=8272 WHERE `entry`=21279;
UPDATE `creature_template` SET `gossip_menu_id`=8274 WHERE `entry`=21283;
UPDATE `creature_template` SET `gossip_menu_id`=8495 WHERE `entry`=22107;
UPDATE `creature_template` SET `gossip_menu_id`=8505 WHERE `entry`=22231;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7938,7842,7450,7957,7967,7893,8085,8090,6944,7810,7691,6647) AND `id` IN (0);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7938,7816,7967,7810,6647) AND `id` IN (1);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7967) AND `id` IN (4,5);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(7938,0,2, 'Show me where I can fly.',4,8192,0,0,0,0,0, ''),
(7938,1,2, 'Send me to Thrallmar!',4,8192,0,0,0,0,0, ''),
(7842,0,3, 'Train me.',5,16,0,0,0,0,0, ''),
(7816,1,1, 'Let me browse your goods.',3,128,0,0,0,0,0, ''),
(7450,0,1, 'Show me what I''ve earned the right to purchase.',3,128,0,0,0,0,0, ''),
(7957,0,1, 'What do you have for sale?',3,128,0,0,0,0,0, ''),
(7967,4,0, 'Lend me a Windrider.  I''m going to Spinebreaker Post!',1,1,0,0,0,0,0, ''),
(7967,5,0, 'I''m on a bombing mission for Forward Commander To''arch.  I need a wyvern destroyer!',1,1,0,0,0,0,0, ''),
(7967,0,0, 'Send me to the Abyssal Shelf!',1,1,0,0,0,0,0, ''),
(7967,1,0, 'Send me to the Abyssal Shelf!',1,1,0,0,0,0,0, ''),
(7893,0,1, 'I have marks to redeem!',3,128,0,0,0,0,0, ''),
(8085,0,0, 'Tell me more of our mission here, Nazgrel.',1,1,8090,0,0,0,0, ''),
(8090,0,0, '<Keep Listening>',1,1,8089,0,0,0,0, ''),
(6944,0,2, 'Show me where I can fly.',4,8192,0,0,0,0,0, ''),
(7810,0,3, 'I would like to train.',5,16,0,0,0,0,0, ''),
(7810,1,1, 'Let me browse your goods.',3,128,0,0,0,0,0, ''),
(7691,0,3, 'Train me.',5,16,6647,0,0,0,0, ''),
(6647,0,3, 'I would like to train further in the ways of the Light.',5,16,7938,0,0,0,0, ''),
(6647,1,0, 'I wish to unlearn my talents.',16,16,0,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7348 AND `text_id`=9619;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7348,9619);
DELETE FROM `gossip_menu` WHERE `entry`=8524 AND `text_id`=10659;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8524,10659);
DELETE FROM `gossip_menu` WHERE `entry`=8510 AND `text_id`=10643;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8510,10643);
DELETE FROM `gossip_menu` WHERE `entry`=7375 AND `text_id`=8813;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7375,8813);
DELETE FROM `gossip_menu` WHERE `entry`=7372 AND `text_id`=8810;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7372,8810);
DELETE FROM `gossip_menu` WHERE `entry`=7373 AND `text_id`=8811;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7373,8811);
DELETE FROM `gossip_menu` WHERE `entry`=12594 AND `text_id`=17713;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (12594,17713);
DELETE FROM `gossip_menu` WHERE `entry`=7342 AND `text_id`=8751;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7342,8751);
DELETE FROM `gossip_menu` WHERE `entry`=7345 AND `text_id`=8756;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7345,8756);
DELETE FROM `gossip_menu` WHERE `entry`=7881 AND `text_id`=9644;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7881,9644);
DELETE FROM `gossip_menu` WHERE `entry`=7312 AND `text_id`=8680;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7312,8680);
DELETE FROM `gossip_menu` WHERE `entry`=7317 AND `text_id`=8685;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7317,8685);
DELETE FROM `gossip_menu` WHERE `entry`=7189 AND `text_id`=8469;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7189,8469);
DELETE FROM `gossip_menu` WHERE `entry`=7880 AND `text_id`=9643;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7880,9643);
DELETE FROM `gossip_menu` WHERE `entry`=7963 AND `text_id`=9788;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7963,9788);
DELETE FROM `gossip_menu` WHERE `entry`=8081 AND `text_id`=9988;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8081,9988);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8524 WHERE `entry`=22258;
UPDATE `creature_template` SET `gossip_menu_id`=7375 WHERE `entry`=16845;
UPDATE `creature_template` SET `gossip_menu_id`=7372 WHERE `entry`=17123;
UPDATE `creature_template` SET `gossip_menu_id`=7373 WHERE `entry`=16848;
UPDATE `creature_template` SET `gossip_menu_id`=7342 WHERE `entry`=17015;
UPDATE `creature_template` SET `gossip_menu_id`=7345 WHERE `entry`=17046;
UPDATE `creature_template` SET `gossip_menu_id`=7881 WHERE `entry`=18997;
UPDATE `creature_template` SET `gossip_menu_id`=7312 WHERE `entry`=16792;
UPDATE `creature_template` SET `gossip_menu_id`=7317 WHERE `entry`=16794;
UPDATE `creature_template` SET `gossip_menu_id`=7288 WHERE `entry`=18905;
UPDATE `creature_template` SET `gossip_menu_id`=7880 WHERE `entry`=17277;
UPDATE `creature_template` SET `gossip_menu_id`=8081 WHERE `entry`=20159;

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8510,7881,7880,7964,8081) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8510,0,0, 'Yes, Scryer.  You may possess me.',1,1,0,0,0,0,0, ''),
(7881,0,1, 'I want to browse your goods.',3,128,0,0,0,0,0, ''),
(7880,0,1, 'I want to browse your goods.',3,128,0,0,0,0,0, ''),
(7964,0,0, 'Why don''t you escape?',1,1,7963,0,0,0,0, ''),
(8081,0,0, 'Magistrix Carinda has sent me to ask you about Arelion''s secret.  Who was he seeing?',1,1,0,0,0,0,0, ''); -- http://old.wowhead.com/quest=10286 needs scripting http://old.wowhead.com/npc=20159

-- NPC talk text insert from sniff for http://old.wowhead.com/quest=10286
DELETE FROM `creature_text` WHERE `entry` IN (20159) AND `groupid` IN (0,1);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(20159,0,0, 'If you think I''ll betray my friend that easily, think again!  Face me, you scoundrel!',12,1,100,0,0,0, 'Magister Aledis'),
(20159,1,0, 'Spare my life!  I will tell you about Arelion''s secret.',12,1,100,0,0,0, 'Magister Aledis');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=7953 AND `text_id`=10109;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7953,10109);

-- SAI for Wing Commamder Brack
SET @ENTRY := 19401;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,7967,0,0,0,11,33825,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Wing Commamder Brack - On gossip option 0 select - Cast Aerial Assault Flight (Horde)'),
(@ENTRY,0,1,0,62,0,100,0,7967,1,0,0,11,33825,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Wing Commamder Brack - On gossip option 1 select - Cast Aerial Assault Flight (Horde)'),
(@ENTRY,0,2,0,62,0,100,0,7967,4,0,0,11,34578,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Wing Commamder Brack - On gossip option 4 select - Cast Taxi - Reaver''s Fall to Spinebreaker Ridge'),
(@ENTRY,0,3,0,62,0,100,0,7967,5,0,0,11,33659,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Wing Commamder Brack - On gossip option 5 select - Cast Gateways Murket and Shaadraz');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7967;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7967,0,0,9,10162,0,0,0,'','Show gossip option 0 if player has Quest 10162 "Mission: The Abyssal Shelf"'),
(15,7967,1,0,9,10347,0,0,0,'','Show gossip option 1 if player has Quest 10347 "Return to the Abyssal Shelf"'),
(15,7967,4,0,9,10242,0,0,0,'','Show gossip option 4 if player has Quest 10242 "Spinebreaker Post"'),
(15,7967,5,0,9,10129,0,0,0,'','Show gossip option 5 if player has Quest 10129 "Mission: Gateways Murketh and Shaadraz"'),
(15,8081,0,0,9,10286,0,0,0,'','Show gossip option 0 if player has Quest 10286 "Arelion''s Secret"'),
(15,7938,1,0,9,10289,0,0,0,'','Show gossip option 0 if player has Quest 10289 "Journey to Thrallmar"');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7953;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7953,10109,0,8,10162,0,0,0,'','Show gossip text 10109 if player has rewarded Quest 10349 "The Earthbinder"');

-- SAI for Vlagga Freyfeather <Wind Rider Master>
SET @ENTRY := 18930;
UPDATE `creature_template` SET `ScriptName`='',`AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,7938,1,0,0,11,34924,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Vlagga Freyfeather - On gossip option 1 select - Cast Stair of Destiny to Thrallmar');
