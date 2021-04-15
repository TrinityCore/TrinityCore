-- [Q] A Meeting With The Magister
-- [Q] An Audience With The Arcanist
SET @ENTRY_HATHOREL := 36670;
SET @ENTRY_TYBALIN := 36669;
SET @QUEST_A := 20439;
SET @QUEST_H := 24451;
SET @GOSSIP_A := 10857;
SET @GOSSIP_H := 10858;
SET @SPELL_SUNREAVER_DISGUISE := 70973;
SET @SPELL_COVENANT_DISGUISE := 70971;
SET @SPELL_CREATE_BLADES := 69722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY_HATHOREL,@ENTRY_TYBALIN);
UPDATE `quest_template` SET `OfferRewardText`="Excellent work. Now that this is in our hands, we must get it to Caladis Brightspear as soon as possible. We can't risk the book falling back into Sunreaver hands.$BI'll ensure that Shandy Glossgleam gets his tabard back without incident, along with a healthy reward for his help",`RequestItemsText`="Have you recovered that book?" WHERE `entry`=@QUEST_A;
UPDATE `quest_template` SET `OfferRewardText`="Excellent work. Now that this is in our hands, we must get it to Myralion Sunblaze as soon as possible. We can't risk the Silver Covenant taking the book from us again.$BI'll get that tabard back to Shandy and see that he's well compensated for his assistance. Once the book is in Myralion's hands, the Silver Covenant won't be a threat anymore.",`RequestItemsText`="Have you recovered that book?" WHERE `entry`=@QUEST_H;
DELETE FROM `creature` WHERE `guid`=150186 AND `id`=@ENTRY_HATHOREL; -- Double-spawned Hathorel
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_HATHOREL,@ENTRY_HATHOREL*100,@ENTRY_TYBALIN,@ENTRY_TYBALIN*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY_TYBALIN,0,0,0,19,0,100,0,@QUEST_A,0,0,0,11,@SPELL_SUNREAVER_DISGUISE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Quest Accept - Cast Sunreaver Disguise"),
(@ENTRY_TYBALIN,0,1,0,20,0,100,0,@QUEST_A,0,0,0,28,@SPELL_SUNREAVER_DISGUISE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Quest Reward - Remove Aura Sunreaver Disguise"),
(@ENTRY_TYBALIN,0,2,3,62,0,100,0,@GOSSIP_A,1,0,0,11,@SPELL_SUNREAVER_DISGUISE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Quest Accept - Cast Sunreaver Disguise"),
(@ENTRY_TYBALIN,0,3,0,61,0,100,0,@GOSSIP_A,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Gossip Select - Close Gossip"),
(@ENTRY_TYBALIN,0,4,0,62,0,100,0,@GOSSIP_H,0,0,0,80,@ENTRY_TYBALIN*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Tybalin - On Gossip Select - Run Script"),
(@ENTRY_TYBALIN*100,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Script - Close Gossip"),
(@ENTRY_TYBALIN*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Script - Say text 0"),
(@ENTRY_TYBALIN*100,9,2,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Script - Say text 1"),
(@ENTRY_TYBALIN*100,9,3,0,0,0,100,0,0,0,0,0,11,@SPELL_CREATE_BLADES,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Script - Cast Create Ancient Dragonforged Blades"),
(@ENTRY_TYBALIN*100,9,4,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Tybalin - On Script - Say text 2"),

(@ENTRY_HATHOREL,0,0,0,19,0,100,0,@QUEST_H,0,0,0,11,@SPELL_COVENANT_DISGUISE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Quest Accept - Cast Covenant Disguise"),
(@ENTRY_HATHOREL,0,1,0,20,0,100,0,@QUEST_H,0,0,0,28,@SPELL_COVENANT_DISGUISE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Quest Reward - Remove Aura Covenant Disguise"),
(@ENTRY_HATHOREL,0,2,3,62,0,100,0,@GOSSIP_H,1,0,0,11,@SPELL_COVENANT_DISGUISE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Quest Accept - Cast Covenant Disguise"),
(@ENTRY_HATHOREL,0,3,0,61,0,100,0,@GOSSIP_H,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Gossip Select - Close Gossip"),
(@ENTRY_HATHOREL,0,4,0,62,0,100,0,@GOSSIP_A,0,0,0,80,@ENTRY_HATHOREL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Hathorel - On Gossip Select - Run Script"),
(@ENTRY_HATHOREL*100,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Script - Close Gossip"),
(@ENTRY_HATHOREL*100,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Script - Say text 0"),
(@ENTRY_HATHOREL*100,9,2,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Script - Say text 1"),
(@ENTRY_HATHOREL*100,9,3,0,0,0,100,0,0,0,0,0,11,@SPELL_CREATE_BLADES,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Script - Cast Create Ancient Dragonforged Blades"),
(@ENTRY_HATHOREL*100,9,4,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Magister Hathorel - On Script - Say text 2");

-- Actual gossip option
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@GOSSIP_A,@GOSSIP_H);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(@GOSSIP_A,0,0,"I'm ready to deliver the tome, Magister Hathorel.",1,1,0,0,0,0,NULL),
(@GOSSIP_A,1,0,"Would you renew my Sunreaver disguise?",1,1,0,0,0,0,NULL),
(@GOSSIP_H,0,0,"I'm ready to deliver the tome, Arcanist Tybalin.",1,1,0,0,0,0,NULL),
(@GOSSIP_H,1,0,"Would you renew my Covenant disguise?",1,1,0,0,0,0,NULL);

-- Magister Hathorel
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY_HATHOREL,@ENTRY_TYBALIN);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY_HATHOREL,0,0,"You're late, courier. No, I don't want any excuses; this errand is far too important.",12,0,100,1,0,0,"Magister Hathorel"),
(@ENTRY_HATHOREL,1,0,"Here's the tome our representative brought from Wyrmrest. Get this to Myralion Sunblaze immediately.",12,0,100,1,0,0,"Magister Hathorel"),
(@ENTRY_HATHOREL,2,0,"Watch your back, courier. I needn't remind you of the value of the book, nor the fact that the Silver Covenant will stop at nothing to take it from us.",12,0,100,1,0,0,"Magister Hathorel"),
-- Arcanist Tybalin
(@ENTRY_TYBALIN,0,0,"It's good to finally see you, courier. Krasus has entrusted us with one of the few remaining copies of Ancient Dragonforged Blades.",12,0,100,1,0,0,"Arcanist Tybalin"),
(@ENTRY_TYBALIN,1,0,"Here is the book. You must ensure it gets to Caladis Brightspear in Icecrown before the Sunreavers realize what is happening.",12,0,100,1,0,0,"Arcanist Tybalin"),
(@ENTRY_TYBALIN,2,0,"Travel quickly! The Sunreavers will not waste any time once they realize that we have the information they seek.",12,0,100,1,0,0,"Arcanist Tybalin");

-- Conditions for the gossip options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (@GOSSIP_A,@GOSSIP_H);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`) VALUES
(15,@GOSSIP_A,0,9,@QUEST_A),
(15,@GOSSIP_H,0,9,@QUEST_H),

(15,@GOSSIP_A,1,11,@SPELL_COVENANT_DISGUISE),
(15,@GOSSIP_H,1,11,@SPELL_SUNREAVER_DISGUISE),

(15,@GOSSIP_A,1,9,@QUEST_A),
(15,@GOSSIP_H,1,9,@QUEST_H);
