-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9052 WHERE `entry`=24965; -- Vindicator Xayann
UPDATE `creature_template` SET `gossip_menu_id`=9050 WHERE `entry`=24975; -- Mar'nah
UPDATE `creature_template` SET `gossip_menu_id`=9126 WHERE `entry`=25032; -- Eldara Dawnrunner
UPDATE `creature_template` SET `gossip_menu_id`=9087 WHERE `entry`=25046; -- Smith Hauthaa
UPDATE `creature_template` SET `gossip_menu_id`=9064 WHERE `entry`=25057; -- Battlemage Arynna
UPDATE `creature_template` SET `gossip_menu_id`=9062, `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=25059; -- Ayren Cloudbreaker
UPDATE `creature_template` SET `gossip_menu_id`=9063 WHERE `entry`=25061; -- Harbinger Inuuro
UPDATE `creature_template` SET `gossip_menu_id`=9127 WHERE `entry`=25069; -- Magister Ilastar
UPDATE `creature_template` SET `gossip_menu_id`=9115 WHERE `entry`=25112; -- Anchorite Ayuri
UPDATE `creature_template` SET `gossip_menu_id`=9105 WHERE `entry`=25169; -- Archmage Ne'thul
UPDATE `creature_template` SET `gossip_menu_id`=9286 WHERE `entry`=25632; -- Vindicator Moorba
UPDATE `creature_template` SET `gossip_menu_id`=9285 WHERE `entry`=25638; -- Captain Selana
UPDATE `creature_template` SET `gossip_menu_id`=9198 WHERE `entry`=25950; -- Shaani

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9050 AND `text_id`=12237;
DELETE FROM `gossip_menu` WHERE `entry`=9052 AND `text_id`=12241;
DELETE FROM `gossip_menu` WHERE `entry`=9062 AND `text_id`=12252;
DELETE FROM `gossip_menu` WHERE `entry`=9063 AND `text_id`=12256;
DELETE FROM `gossip_menu` WHERE `entry`=9064 AND `text_id`=12258;
DELETE FROM `gossip_menu` WHERE `entry`=9087 AND `text_id`=12286;
DELETE FROM `gossip_menu` WHERE `entry`=9115 AND `text_id`=12323;
DELETE FROM `gossip_menu` WHERE `entry`=9126 AND `text_id`=12338;
DELETE FROM `gossip_menu` WHERE `entry`=9127 AND `text_id`=12340;
DELETE FROM `gossip_menu` WHERE `entry`=9198 AND `text_id`=12497;
DELETE FROM `gossip_menu` WHERE `entry`=9285 AND `text_id`=12596;
DELETE FROM `gossip_menu` WHERE `entry`=9286 AND `text_id`=12597;
DELETE FROM `gossip_menu` WHERE `entry`=9287 AND `text_id`=12598;
DELETE FROM `gossip_menu` WHERE `entry`=9288 AND `text_id`=12599;
DELETE FROM `gossip_menu` WHERE `entry`=9289 AND `text_id`=12600;
DELETE FROM `gossip_menu` WHERE `entry`=9290 AND `text_id`=12601;
DELETE FROM `gossip_menu` WHERE `entry`=9293 AND `text_id`=12604;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9050,12237),
(9052,12241),
(9062,12252),
(9063,12256),
(9064,12258),
(9087,12286),
(9115,12323),
(9126,12338),
(9127,12340),
(9198,12497),
(9285,12596),
(9286,12597),
(9287,12598),
(9288,12599),
(9289,12600),
(9290,12601),
(9293,12604);

-- Creature Gossip_menu_option insert from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9050,9087,9126,9198,9285,9287,9288,9289) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9062 AND `id` IN (0,1);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9286 AND `id`=2;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(9050,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(9062,0,0,'Speaking of action, I''ve been ordered to undertake an air strike.',1,1,0,0,0,0,''),
(9062,1,0,'I need to intercept the Dawnblade reinforcements.',1,1,0,0,0,0,''),
(9087,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(9126,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(9198,0,1,'Let me browse your goods.',3,128,0,0,0,0,''),
(9285,0,0,'Give me a situation report, Captain.',1,1,9287,0,0,0,''),
(9286,2,0,'What is the current state of the Sunwell''s Gates?',1,1,9293,0,0,0,''),
(9287,0,0,'What went wrong?',1,1,9288,0,0,0,''),
(9288,0,0,'Why did they stop?',1,1,9289,0,0,0,''),
(9289,0,0,'Your insight is appreciated.',1,1,9290,0,0,0,'');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9062 AND `SourceEntry` IN (0,1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9062,0,0,0,9,11532,0,0,0,0,'','Show gossip option only if player has taken quest 11532'),
(15,9062,0,0,1,9,11533,0,0,0,0,'','Show gossip option only if player has taken quest 11533'),
(15,9062,1,0,0,9,11542,0,0,0,0,'','Show gossip option only if player has taken quest 11542'),
(15,9062,1,0,1,9,11543,0,0,0,0,'','Show gossip option only if player has taken quest 11543');

-- SmartAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=25059 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25059,0,0,2,62,0,100,0,9062,0,0,0,11,45071,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ayren Cloudbreaker - On Gossip option select - Cast "Quest - Sunwell Daily - Dead Scar Bombing Run" on player'),
(25059,0,1,2,62,0,100,0,9062,1,0,0,11,45113,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ayren Cloudbreaker - On Gossip option select - Cast "Quest - Sunwell Daily - Ship Bombing Run" on player'),
(25059,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Ayren Cloudbreaker - On Gossip option select - Close Gossip');

-- Spell scripts from sniff
DELETE FROM `spell_scripts` WHERE `id`=45071;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(45071,2,0,16,12318,1,0,0,0,0,0); -- Play sound
