-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=8871 WHERE `entry`=4501; -- Draz'Zilb
UPDATE `creature_template` SET `gossip_menu_id`=4004 WHERE `entry`=4885; -- Gregor MacVince
UPDATE `creature_template` SET `gossip_menu_id`=541 WHERE `entry`=4895; -- Smiling Jim
UPDATE `creature_template` SET `gossip_menu_id`=4122 WHERE `entry`=4900; -- Alchemist Narett
UPDATE `creature_template` SET `gossip_menu_id`=8840 WHERE `entry`=4921; -- Guard Byron
UPDATE `creature_template` SET `gossip_menu_id`=1186 WHERE `entry`=4926; -- Krog
UPDATE `creature_template` SET `gossip_menu_id`=1161 WHERE `entry`=4944; -- Captain Garran Vimes
UPDATE `creature_template` SET `gossip_menu_id`=5301 WHERE `entry`=4967; -- Archmage Tervosh
UPDATE `creature_template` SET `gossip_menu_id`=2465 WHERE `entry`=4968; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `gossip_menu_id`=8793 WHERE `entry`=5086; -- Captain Wymor
UPDATE `creature_template` SET `gossip_menu_id`=2916 WHERE `entry`=6546; -- Tabetha
UPDATE `creature_template` SET `gossip_menu_id`=4091 WHERE `entry`=8141; -- Captain Evencane
UPDATE `creature_template` SET `gossip_menu_id`=4355 WHERE `entry`=11052; -- Timothy Worthington
UPDATE `creature_template` SET `gossip_menu_id`=5382 WHERE `entry`=12939; -- Doctor Gustaf VanHowzen
UPDATE `creature_template` SET `gossip_menu_id`=8761 WHERE `entry`=23567; -- Inspector Tarem
UPDATE `creature_template` SET `gossip_menu_id`=8788 WHERE `entry`=23568; -- Captain Darill
UPDATE `creature_template` SET `gossip_menu_id`=8837 WHERE `entry`=23569; -- Renn McGill
UPDATE `creature_template` SET `gossip_menu_id`=8801 WHERE `entry`=23579; -- Brogg
UPDATE `creature_template` SET `gossip_menu_id`=8811 WHERE `entry`=23600; -- Apprentice Morlann
UPDATE `creature_template` SET `gossip_menu_id`=8812 WHERE `entry`=23601; -- Apprentice Garion
UPDATE `creature_template` SET `gossip_menu_id`=8762 WHERE `entry`=23602; -- Deserter Agitator
UPDATE `creature_template` SET `gossip_menu_id`=8782 WHERE `entry`=23704; -- Cassa Crimsonwing
UPDATE `creature_template` SET `gossip_menu_id`=8787 WHERE `entry`=23723; -- Sergeant Lukas
UPDATE `creature_template` SET `gossip_menu_id`=8830 WHERE `entry`=23797; -- Moxie Steelgrille
UPDATE `creature_template` SET `gossip_menu_id`=8831 WHERE `entry`=23835; -- Sergeant Amelyn
UPDATE `creature_template` SET `gossip_menu_id`=8826 WHERE `entry`=23896; -- "Dirty" Michael Crowe
UPDATE `creature_template` SET `gossip_menu_id`=8835 WHERE `entry`=23949; -- Lieutenant Nath
UPDATE `creature_template` SET `gossip_menu_id`=8836 WHERE `entry`=23950; -- Lieutenant Khand
UPDATE `creature_template` SET `gossip_menu_id`=8912 WHERE `entry`=24208; -- "Little" Logok
UPDATE `creature_template` SET `gossip_menu_id`=9342 WHERE `entry`=26546; -- Ludin Farrow

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=541 AND `text_id`=1058;
DELETE FROM `gossip_menu` WHERE `entry`=1161 AND `text_id`=1793;
DELETE FROM `gossip_menu` WHERE `entry`=1162 AND `text_id`=1794;
DELETE FROM `gossip_menu` WHERE `entry`=1186 AND `text_id`=1818;
DELETE FROM `gossip_menu` WHERE `entry`=1187 AND `text_id`=1819;
DELETE FROM `gossip_menu` WHERE `entry`=1188 AND `text_id`=1820;
DELETE FROM `gossip_menu` WHERE `entry`=2465 AND `text_id`=3157;
DELETE FROM `gossip_menu` WHERE `entry`=2916 AND `text_id`=3590;
DELETE FROM `gossip_menu` WHERE `entry`=4004 AND `text_id`=5855;
DELETE FROM `gossip_menu` WHERE `entry`=4091 AND `text_id`=4991;
DELETE FROM `gossip_menu` WHERE `entry`=4122 AND `text_id`=5049;
DELETE FROM `gossip_menu` WHERE `entry`=4355 AND `text_id`=5571;
DELETE FROM `gossip_menu` WHERE `entry`=5301 AND `text_id`=6333;
DELETE FROM `gossip_menu` WHERE `entry`=5382 AND `text_id`=6414;
DELETE FROM `gossip_menu` WHERE `entry`=8761 AND `text_id`=11126;
DELETE FROM `gossip_menu` WHERE `entry`=8762 AND `text_id`=11136;
DELETE FROM `gossip_menu` WHERE `entry`=8782 AND `text_id`=11224;
DELETE FROM `gossip_menu` WHERE `entry`=8787 AND `text_id`=11243;
DELETE FROM `gossip_menu` WHERE `entry`=8788 AND `text_id`=11245;
DELETE FROM `gossip_menu` WHERE `entry`=8793 AND `text_id`=11264;
DELETE FROM `gossip_menu` WHERE `entry`=8801 AND `text_id`=11281;
DELETE FROM `gossip_menu` WHERE `entry`=8811 AND `text_id`=11309;
DELETE FROM `gossip_menu` WHERE `entry`=8812 AND `text_id`=11311;
DELETE FROM `gossip_menu` WHERE `entry`=8826 AND `text_id`=11376;
DELETE FROM `gossip_menu` WHERE `entry`=8830 AND `text_id`=11403;
DELETE FROM `gossip_menu` WHERE `entry`=8831 AND `text_id`=11406;
DELETE FROM `gossip_menu` WHERE `entry`=8835 AND `text_id`=11426;
DELETE FROM `gossip_menu` WHERE `entry`=8836 AND `text_id`=11428;
DELETE FROM `gossip_menu` WHERE `entry`=8837 AND `text_id`=11432;
DELETE FROM `gossip_menu` WHERE `entry`=8840 AND `text_id`=11457;
DELETE FROM `gossip_menu` WHERE `entry`=8871 AND `text_id`=11567;
DELETE FROM `gossip_menu` WHERE `entry`=8912 AND `text_id`=11797;
DELETE FROM `gossip_menu` WHERE `entry`=9342 AND `text_id`=12642;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(541,1058),
(1161,1793),
(1162,1794),
(1186,1818),
(1187,1819),
(1188,1820),
(2465,3157),
(2916,3590),
(4004,5855),
(4091,4991),
(4122,5049),
(4355,5571),
(5301,6333),
(5382,6414),
(8761,11126),
(8762,11136),
(8782,11224),
(8787,11243),
(8788,11245),
(8793,11264),
(8801,11281),
(8811,11309),
(8812,11311),
(8826,11376),
(8830,11403),
(8831,11406),
(8835,11426),
(8836,11428),
(8837,11432),
(8840,11457),
(8871,11567),
(8912,11797),
(9342,12642);

-- Creature Gossip_menu_option insert from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1161,4122,4355,5382,8761,8762) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1186,8826,8912) AND `id` IN (0,1);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(1161,0,0,'What have you heard of the Shady Rest Inn?',1,1,1162,0,0,0,''),
(1186,0,0,'The Burning Inn.',1,1,1187,0,0,0,''),
(1186,1,0,'Paval Reethe.',1,1,1188,0,0,0,''),
(4122,0,3,'Train me.',5,16,0,0,0,0,''),
(4355,0,3,'Train me.',5,16,0,0,0,0,''),
(5382,0,3,'Train me.',5,16,0,0,0,0,''),
(8761,0,0,'Can you spread the reflective dust again?',1,1,0,0,0,0,''),
(8762,0,0,'Your propaganda won''t work on me. Spout your treasonous filth elsewhere, traitor!',1,1,0,0,0,0,''),
(8826,0,3,'Train me.',5,16,0,0,0,0,''),
(8826,1,1,'Show me what you have for sale.',3,128,0,0,0,0,''),
(8912,0,5,'Make this inn your home.',8,65536,0,0,0,0,''),
(8912,1,1,'I want to browse your goods.',3,128,0,0,0,0,'');

SET @NPC_DESERTER := 23602;
SET @NPC_INSPECTOR := 23567;
SET @SPELL_DISCOVERED_SUB := 42219;

-- Insert creature_text from sniff
DELETE FROM `creature_text` WHERE `entry`=@NPC_DESERTER;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_DESERTER,0,0,'It''s good to see you defending Theramore with pride, friend.',12,7,100,25,0,0,'Deserter Agitator'),
(@NPC_DESERTER,0,1,'When you''re off duty, let''s go to the inn. I''ll buy a round and we can reminisce about the good old days.',12,7,100,1,0,0,'Deserter Agitator'),
(@NPC_DESERTER,0,2,'Wouldn''t you like to bring those days back? I have some friends who know just the way to do that...''',12,7,100,1,0,0,'Deserter Agitator'),
(@NPC_DESERTER,1,0,'These people will know Admiral Proudmoore for the true hero he was!',12,7,100,5,0,0,'Deserter Agitator'),
(@NPC_DESERTER,1,1,'You can''t stop us from exposing the truth about Jaina''s cowardice!',12,7,100,5,0,0,'Deserter Agitator'),
(@NPC_DESERTER,1,2,'If you think you can stop us, you''re mistaken, ''friend.''',12,7,100,5,0,0,'Deserter Agitator'),
(@NPC_DESERTER,1,3,'It''s people like you who weaken the Alliance and invite the Horde to take away all we''ve fought for!',12,7,100,5,0,0,'Deserter Agitator');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=@SPELL_DISCOVERED_SUB;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8762 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_DISCOVERED_SUB,0,0,31,0,3,23602,0,0,0,'','Spell Discovered (Sub) only targets Deserter Agitator'),
(15,8762,0,0,0,9,0,11126,0,0,0,0,'','Show gossip option only if player has taken quest 11126');

-- SmartAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_INSPECTOR,@NPC_DESERTER) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_DESERTER*100,@NPC_DESERTER*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_INSPECTOR,0,0,1,62,0,100,0,8761,0,0,0,11,42169,0,0,0,0,0,7,0,0,0,0,0,0,0,'Inspector Tarem - On Gossip option select - Cast Reflective Dust'),
(@NPC_INSPECTOR,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Inspector Tarem - On Gossip option select - Close Gossip'),

(@NPC_DESERTER,0,0,0,25,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deserter Agitator - On reset - Set faction default'),
(@NPC_DESERTER,0,1,0,1,0,100,0,0,1,30000,40000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deserter Agitator - On update OOC - Say line'),
(@NPC_DESERTER,0,2,3,62,0,100,0,8762,0,0,0,11,42203,0,0,0,0,0,7,0,0,0,0,0,0,0,'Deserter Agitator - On Gossip option select - Cast Discovered'),
(@NPC_DESERTER,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Deserter Agitator - On Gossip option select - Close Gossip'),
(@NPC_DESERTER,0,4,5,8,0,100,0,@SPELL_DISCOVERED_SUB,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Deserter Agitator - On spellhit Discovered (Sub) - Turn to invoker'),
(@NPC_DESERTER,0,5,6,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Deserter Agitator - On spellhit Discovered (Sub) - Say line'),
(@NPC_DESERTER,0,6,0,61,0,100,0,0,0,0,0,87,@NPC_DESERTER*100,@NPC_DESERTER*100+1,0,0,0,0,1,0,0,0,0,0,0,0,'Deserter Agitator - On spellhit Discovered (Sub) - Run script'),

(@NPC_DESERTER*100,9,0,0,0,0,100,0,2000,2000,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deserter Agitator''s script 0 - Set faction monster'),
(@NPC_DESERTER*100,9,1,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Deserter Agitator''s script 0 - Attack'),

(@NPC_DESERTER*100+1,9,0,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deserter Agitator''s script 1 - Remove npcflag gossip'),
(@NPC_DESERTER*100+1,9,1,0,0,0,100,0,0,0,0,0,33,@NPC_DESERTER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Deserter Agitator''s script 1 - Credit'),
(@NPC_DESERTER*100+1,9,2,0,0,0,100,0,30000,30000,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Deserter Agitator''s script 1 - Add npcflag gossip');
