[33mcommit 2f2d98c7b086409f24490006a375ae8e5bfb0a02[m
Author: Saqirmdev <1king2@azet.sk>
Date:   Sun Nov 11 12:52:08 2012 +0100

    Fix Typo in .SQL
    DB/SAI: Fix some Howling Fjord gossips - By Pitcrawler
    DB/Quest: fix a wrong text - By Exodius
    DB/Gossip: Add gossip menus for Midsummer partial - By Malcrom

[1mdiff --git a/sql/nase/world/Exhausted_Vyrkul_Sai.sql b/sql/nase/world/Exhausted_Vyrkul_Sai.sql[m
[1mnew file mode 100644[m
[1mindex 0000000..0a44458[m
[1m--- /dev/null[m
[1m+++ b/sql/nase/world/Exhausted_Vyrkul_Sai.sql[m
[36m@@ -0,0 +1,18 @@[m
[32m+[m[32m-- Exhausted Vrykul SAI[m
[32m+[m[32mSET @ENTRY := 30146;[m
[32m+[m[32mSET @SPELL_DESPERATE_BLOW := 57395;[m
[32m+[m[32mSET @SPELL_DISCIPLINING_ROD := 56033;[m
[32m+[m[32mUPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;[m
[32m+[m[32mDELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;[m
[32m+[m[32mDELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100+0,@ENTRY*100+1);[m
[32m+[m[32mINSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES[m
[32m+[m[32m(@ENTRY,0,0,0,1,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - Out of Combat - Set Bytes1 Sit"), -- Not doing this in creature_addon(_template) so that we can cancel this in SAI[m
[32m+[m[32m(@ENTRY,0,1,2,8,0,100,0,@SPELL_DISCIPLINING_ROD,0,0,0,87,@ENTRY*100+0,@ENTRY*100+1,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - On Spellhit - Run Random Script"),[m
[32m+[m[32m(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - On Spellhit - Set Phase 1"), -- To prevent the same one to give more credits[m
[32m+[m[32m(@ENTRY*100+0,9,0,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Attack Player"),[m
[32m+[m[32m(@ENTRY*100+0,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Say Line 0 (random)"),[m
[32m+[m[32m(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Say Line 1 (random)"),[m
[32m+[m[32m(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,91,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Stand Up"),[m
[32m+[m[32m(@ENTRY*100+1,9,2,0,0,0,100,0,0,0,0,0,5,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Emote Work"),[m
[32m+[m[32m(@ENTRY*100+1,9,3,0,0,0,100,0,0,0,0,0,33,29886,0,0,0,0,0,7,0,0,0,0,0,0,0,"Exhausted Vrykul - On Script - Kill Credit"),[m
[32m+[m[32m(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,11,@SPELL_DESPERATE_BLOW,0,0,0,0,0,2,0,0,0,0,0,0,0,"Exhausted Vrykul - At 15% HP - Cast Desperate Blow");[m
\ No newline at end of file[m
[1mdiff --git a/sql/nase/world/Howling_Fjord_Gossips.sql b/sql/nase/world/Howling_Fjord_Gossips.sql[m
[1mnew file mode 100644[m
[1mindex 0000000..e2c086d[m
[1m--- /dev/null[m
[1m+++ b/sql/nase/world/Howling_Fjord_Gossips.sql[m
[36m@@ -0,0 +1,113 @@[m
[32m+[m[32m-- Update creature gossip_menu_option from sniff[m
[32m+[m[32mDELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8803,8808,8894,9045,9621,9879,9895,9987,10117,10218) AND `id`=0;[m
[32m+[m[32mDELETE FROM `gossip_menu_option` WHERE `menu_id`=9879 AND `id`=1;[m[41m                 [m
[32m+[m[32mINSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES[m
[32m+[m[32m(8803,0,1, 'I need some booze, Coot.',3,128,0,0,0,0, ''),[m
[32m+[m[32m(8808,0,1, 'I require some components, Sorely.',3,128,0,0,0,0, ''),[m
[32m+[m[32m(8894,0,0, 'I need to fly to the Windrunner Official business!',1,1,0,0,0,0, ''),[m
[32m+[m[32m(9045,0,0, 'I don''t have time for chit-chat, Lou. Take me to Scalawag Point.',1,1,0,0,0,0, ''),[m
[32m+[m[32m(9621,0,0, 'Harry said I could use his bomber to Bael''gun''s. I''m ready to go!',1,1,0,0,0,0, ''),[m
[32m+[m[32m(9879,0,3, 'Train me',5,16,0,0,0,0, ''),[m
[32m+[m[32m(9879,1,1, 'Let me browse your goods.',3,128,0,0,0,0, ''),[m
[32m+[m[32m(9895,0,3, 'Train me',5,16,0,0,0,0, ''),[m
[32m+[m[32m(9987,0,3, 'Train me',5,16,0,0,0,0, ''),[m
[32m+[m[32m(10117,0,3, 'Train me',5,16,0,0,0,0, ''),[m
[32m+[m[32m(10218,0,0, '<Get in the bomber and return to Scalawag Point.>',1,1,0,0,0,0, '');[m
[32m+[m[32m-- Insert gossip menu from sniff[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8803 AND `text_id`=11287;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8808 AND `text_id`=11297;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8820 AND `text_id`=11352;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8832 AND `text_id`=11418;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8839 AND `text_id`=11436;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8893 AND `text_id`=11655;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8900 AND `text_id`=11691;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8957 AND `text_id`=11746;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=8985 AND `text_id`=12130;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9008 AND `text_id`=12170;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9045 AND `text_id`=12222;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9346 AND `text_id`=12646;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9895 AND `text_id`=13738;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9987 AND `text_id`=13841;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10117 AND `text_id`=14043;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10218 AND `text_id`=14205;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES[m
[32m+[m[32m(8803,11287),[m
[32m+[m[32m(8808,11297),[m
[32m+[m[32m(8820,11352),[m
[32m+[m[32m(8832,11418),[m
[32m+[m[32m(8839,11436),[m
[32m+[m[32m(8893,11655),[m
[32m+[m[32m(8900,11691),[m
[32m+[m[32m(8957,11746),[m
[32m+[m[32m(8985,12130),[m
[32m+[m[32m(9008,12170),[m
[32m+[m[32m(9045,12222),[m
[32m+[m[32m(9346,12646),[m
[32m+[m[32m(9895,13738),[m
[32m+[m[32m(9987,13841),[m
[32m+[m[32m(10117,14043),[m
[32m+[m[32m(10218,14205);[m
[32m+[m[32m-- Insert creature gossip_menu_id Update from sniff[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8803 WHERE `entry`=23737; -- Coot "The Stranger" Albertson[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8808 WHERE `entry`=23732; -- Sorely Twitchblade[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8820 WHERE `entry`=23862; -- Finlay Fletcher[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8832 WHERE `entry`=23770; -- Cannoneer Ely[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8839 WHERE `entry`=23906; -- Scout Knowles[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8893 WHERE `entry`=24106; -- Scout Valory[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8900 WHERE `entry`=24135; -- Greatmother Ankha[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8957 WHERE `entry`=23833; -- Explorer Jaren[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=8985 WHERE `entry`=24544; -- Old Icefin[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9008, `npcflag`=`npcflag`|1 WHERE `entry`=24643; -- Grezzix Spindlesnap[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9045, `npcflag`=1, `AIName`='SmartAI' WHERE `entry`=24896; -- Lou the Cabin Boy[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9346 WHERE `entry`=26540; -- Drenk Spannerspark[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry` IN (24067,24154,24350); -- Mahana Frosthoof, Mary Darrow, Robert Clarke[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9879 WHERE `entry`=26959; -- Booker Kells[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9895 WHERE `entry`=26960; -- Carter Tiffens[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9987 WHERE `entry`=26953; -- Thomas Kolichio[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=10117 WHERE `entry`=26964; -- Alexandra McQueen[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=10218, `AIName`='SmartAI' WHERE `entry`=28277; -- Harry's Bomber[m
[32m+[m[32m-- Insert npc_text from sniff[m
[32m+[m[32mDELETE FROM `npc_text` WHERE `ID` IN (12130,13702);[m
[32m+[m[32mINSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES[m
[32m+[m[32m(12130,'<Old Icefin eyes you warily, his fishy eye blinking as he bobs his head up and down once in a curt dismissal.>','',0,1,0,396,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340),[m
[32m+[m[32m(13702,'How may I help you?','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,12340);[m
[32m+[m[32m-- Insert creature_text from sniff[m
[32m+[m[32mDELETE FROM `creature_text` WHERE `entry` IN (27923,27933);[m
[32m+[m[32mINSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES[m
[32m+[m[32m(27923,0,0,'Hang on to your hat, $N! To Scalawag we go!',12,0,100,0,0,0,'Lou the Cabin Boy'),[m
[32m+[m[32m(27923,1,0,'YAAARRRRR! Here we be, matey! Scalawag Point!',12,0,100,0,0,0,'Lou the Cabin Boy'),[m
[32m+[m[32m(27933,0,0,'Enjoy the ride! It''s a one way trip!',12,0,100,3,0,0,'Alanya');[m
[32m+[m[32m-- Conditions[m
[32m+[m[32mDELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8894,9045,9621,10218) AND `SourceEntry`=0;[m
[32m+[m[32mDELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (8894,9546) AND `SourceEntry`=1;[m
[32m+[m[32mINSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES[m
[32m+[m[32m(15,8894,0,0,0,9,0,11229,0,0,0,0,'','Bathandler Camille - Show gossip option only if player has taken quest 11229'),[m
[32m+[m[32m(15,8894,1,0,0,9,0,11170,0,0,0,0,'','Bathandler Camille - Show gossip option only if player has taken quest 11170'),[m
[32m+[m[32m(15,9045,0,0,0,9,0,11509,0,0,0,0,'','Lou the Cabin Boy - Show gossip option only if player has taken quest 11509'),[m
[32m+[m[32m(15,9546,1,0,0,9,0,12298,0,0,0,0,'','Greer Orehammer - Show gossip option only if player has taken quest 12298'),[m
[32m+[m[32m(15,9621,0,0,0,9,0,11567,0,0,0,0,'','Alanya - Show gossip option only if player has taken quest 11567'),[m
[32m+[m[32m(15,10218,0,0,0,9,0,11567,0,0,0,0,'','Harry''s Bomber - Show gossip option if player has taken quest 11567');[m
[32m+[m[32m-- SmartAIs[m
[32m+[m[32mUPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=27933;[m
[32m+[m[32mUPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=23816;[m
[32m+[m[32mDELETE FROM `smart_scripts` WHERE `entryorguid`=23859 AND `source_type`=0 AND `id` IN (3,4); -- this npc had already a SmartAI so deleting just the new lines[m
[32m+[m[32mDELETE FROM `smart_scripts` WHERE `entryorguid` IN (23816,24896,27933,28277) AND `source_type`=0;[m
[32m+[m[32mINSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES[m
[32m+[m[32m(23816,0,0,2,62,0,100,0,8894,0,0,0,85,43074,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bathandler Camille - On gossip select - Invoker spellcast'),[m
[32m+[m[32m(23816,0,1,2,62,0,100,0,8894,1,0,0,85,43136,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bathandler Camille - On gossip select - Invoker spellcast'),[m
[32m+[m[32m(23816,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bathandler Camille - On gossip select - Close gossip'),[m
[32m+[m[32m(23859,0,3,4,62,0,100,0,9546,1,0,0,11,48862,0,0,0,0,0,7,0,0,0,0,0,0,0,'Greer Orehammer - On gossip select - Invoker spellcast'),[m
[32m+[m[32m(23859,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Greer Orehammer - On gossip select - Close gossip'),[m
[32m+[m[32m(24896,0,0,1,62,0,100,0,9045,0,0,0,11,50004,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lou the Cabin Boy - On gossip select - Spellcast'),[m
[32m+[m[32m(24896,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lou the Cabin Boy - On gossip select - Close gossip'),[m
[32m+[m[32m(27933,0,0,1,62,0,100,0,9621,0,0,0,11,50038,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alanya - On gossip select - Spellcast'),[m
[32m+[m[32m(27933,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alanya - On gossip select - Close gossip'),[m
[32m+[m[32m(27933,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Alanya - On gossip select - Say line'),[m
[32m+[m[32m(28277,0,0,1,62,0,100,0,10218,0,0,0,11,61604,0,0,0,0,0,7,0,0,0,0,0,0,0,'Harry''s Bomber - On gossip select - Spellcast'),[m
[32m+[m[32m(28277,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Harry''s Bomber - On gossip select - Close gossip');[m
[32m+[m[32mDELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=24896; -- that was absolutely not correct[m
[32m+[m[32mDELETE FROM `spell_target_position` WHERE `id` IN (50005,50039,61605);[m
[32m+[m[32mINSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES[m
[32m+[m[32m(50005,571,595.208,-2796.47,-0.124098,3.66519), -- Summon Lou the Cabin Boy[m
[32m+[m[32m(50039,571,-170.469,-3588.19,-0.221146,4.2586), -- Summon Harry's Bomber[m
[32m+[m[32m(61605,571,89.7416,-6286.08,1.17903,1.58825); -- Summon Harry's Bomber[m
\ No newline at end of file[m
[1mdiff --git a/sql/nase/world/Update_Gossip_Menu_Midsummer_partial.sql b/sql/nase/world/Update_Gossip_Menu_Midsummer_partial.sql[m
[1mnew file mode 100644[m
[1mindex 0000000..bfa6a40[m
[1m--- /dev/null[m
[1m+++ b/sql/nase/world/Update_Gossip_Menu_Midsummer_partial.sql[m
[36m@@ -0,0 +1,109 @@[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9260 WHERE `entry`=25754;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9260 AND `text_id`=12572;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9260,12572);[m
[32m+[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=11417 WHERE `entry`=25697;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=11417 AND `text_id`=12390;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11417,12390);[m
[32m+[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9298 WHERE `entry`=16818;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9298 AND `text_id`=12609;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9298,12609);[m
[32m+[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9204 WHERE `entry`=26113;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9204 WHERE `entry`=25994;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9204 AND `text_id`=12506;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9204,12506);[m
[32m+[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9148 WHERE `entry`=16781;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9148 AND `text_id`=12376;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9148,12376);[m
[32m+[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9157 WHERE `entry`=26221;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9157 AND `text_id`=12390;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9157,12390);[m
[32m+[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25884;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25918;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25919;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25920;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25921;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25922;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25924;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25926;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25928;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25929;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25930;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25932;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25934;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25936;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25937;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25938;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25940;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25943;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=25947;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=32809;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=32810;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=32811;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=32812;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=32813;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=32814;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=32815;[m
[32m+[m[32mUPDATE `creature_template` SET `gossip_menu_id`=9278 WHERE `entry`=32816;[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9278 AND `text_id`=12582;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9278,12582);[m
[32m+[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9354 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9354,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9384 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9384,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9385 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9385,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9386 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9386,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9387 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9387,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9389 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9389,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9390 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9390,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9393 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9393,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9395 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9395,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9396 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9396,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9399 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9399,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9401 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9401,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9403 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9403,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9408 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9408,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9409 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9409,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9410 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9410,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9411 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9411,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9412 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9412,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=9413 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9413,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10230 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10230,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10232 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10232,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10233 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10233,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10234 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10234,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10237 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10237,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10238 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10238,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10240 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10240,12377);[m
[32m+[m[32mDELETE FROM `gossip_menu` WHERE `entry`=10243 AND `text_id`=12377;[m
[32m+[m[32mINSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (10243,12377);[m
\ No newline at end of file[m
[1mdiff --git a/sql/nase/world/Wrong_Text_Quest_template.sql b/sql/nase/world/Wrong_Text_Quest_template.sql[m
[1mnew file mode 100644[m
[1mindex 0000000..c02d3c7[m
[1m--- /dev/null[m
[1m+++ b/sql/nase/world/Wrong_Text_Quest_template.sql[m
[36m@@ -0,0 +1 @@[m
[32m+[m[32mUPDATE `quest_template` SET `OfferRewardText`="WOW, that was a real life ghost! That was so awesome - I can't wait to tell everyone back at the orphanage. Captain Grayson... he even looked like a pirate! When I grow up I wanna be a ghost pirate too!$B$BThanks for taking me to Westfall, $N. I know there are scary things out there in the wilds of Westfall, and I hope I wasn't too much of a pain. You're awesome!" WHERE `Id`=1687;[m
\ No newline at end of file[m
[1mdiff --git a/sql/nase/world/minioni_update.sql b/sql/nase/world/minioni_update.sql[m
[1mindex 5ba852f..1e2a9d4 100644[m
[1m--- a/sql/nase/world/minioni_update.sql[m
[1m+++ b/sql/nase/world/minioni_update.sql[m
[36m@@ -1,6 +1,6 @@[m
[31m-UPDATE `world`.`creature_template` SET `minrangedmg` = '7',`maxrangedmg` = '11',`Health_mod` = '0.04' WHERE `creature_template`.`entry` =12922;[m
[31m-UPDATE `world`.`creature_template` SET `Health_mod` = '0.4' WHERE `creature_template`.`entry` =8996;[m
[31m-UPDATE `world`.`creature_template` SET `mindmg` = '30',`maxdmg` = '45',`minrangedmg` = '40',`maxrangedmg` = '70',`Health_mod` = '0.4',`Mana_mod` = '0.4' WHERE `creature_template`.`entry` =10928;[m
[32m+[m[32mUPDATE `creature_template` SET `minrangedmg` = '7',`maxrangedmg` = '11',`Health_mod` = '0.04' WHERE `entry` =12922;[m
[32m+[m[32mUPDATE `creature_template` SET `Health_mod` = '0.4' WHERE `creature_template`.`entry` =8996;[m
[32m+[m[32mUPDATE `creature_template` SET `mindmg` = '30',`maxdmg` = '45',`minrangedmg` = '40',`maxrangedmg` = '70',`Health_mod` = '0.4',`Mana_mod` = '0.4' WHERE `entry` =10928;[m
 [m
 [m
 [m
[1mdiff --git a/sql/nase/world/nagrand_arena_last_boss_quest.sql b/sql/nase/world/nagrand_arena_last_boss_quest.sql[m
[1mindex 162d973..0c84004 100644[m
[1m--- a/sql/nase/world/nagrand_arena_last_boss_quest.sql[m
[1m+++ b/sql/nase/world/nagrand_arena_last_boss_quest.sql[m
[36m@@ -1,2 +1,2 @@[m
[31m-UPDATE `world`.`quest_template` SET `RequiredNpcOrGo1` = '18069',`RequiredNpcOrGoCount1` = '1' WHERE `quest_template`.`Id` =9977;[m
[31m-UPDATE `world`.`quest_template` SET `SpecialFlags` = '0' WHERE `quest_template`.`Id` =9977;[m
[32m+[m[32mUPDATE `quest_template` SET `RequiredNpcOrGo1` = '18069',`RequiredNpcOrGoCount1` = '1' WHERE `Id` =9977;[m
[32m+[m[32mUPDATE `quest_template` SET `SpecialFlags` = '0' WHERE `Id` =9977;[m
[1mdiff --git a/sql/nase/world/zuldrak_arena.sql b/sql/nase/world/zuldrak_arena.sql[m
[1mindex 34b7457..b9ae935 100644[m
[1m--- a/sql/nase/world/zuldrak_arena.sql[m
[1m+++ b/sql/nase/world/zuldrak_arena.sql[m
[36m@@ -1,6 +1,6 @@[m
[31m-UPDATE `world`.`creature_template` SET `faction_A` = '14',`faction_H` = '14' WHERE `creature_template`.`entry` =30093;[m
[32m+[m[32mUPDATE `creature_template` SET `faction_A` = '14',`faction_H` = '14' WHERE `entry` =30093;[m
 [m
[31m-UPDATE `world`.`creature_template` SET `faction_A` = '14',`faction_H` = '14' WHERE `creature_template`.`entry` =30110;[m
[32m+[m[32mUPDATE `creature_template` SET `faction_A` = '14',`faction_H` = '14' WHERE `entry` =30110;[m
 [m
 [m
 [m
[1mdiff --git a/src/server/game/Spells/SpellInfo.cpp b/src/server/game/Spells/SpellInfo.cpp[m
[1mindex 7c3ed1f..b8e25d3 100644[m
[1m--- a/src/server/game/Spells/SpellInfo.cpp[m
[1m+++ b/src/server/game/Spells/SpellInfo.cpp[m
[36m@@ -1164,7 +1164,8 @@[m [mbool SpellInfo::IsSingleTargetWith(SpellInfo const* spellInfo) const[m
     // TODO - need better check[m
     // Equal icon and spellfamily[m
     if (SpellFamilyName == spellInfo->SpellFamilyName &&[m
[31m-        SpellIconID == spellInfo->SpellIconID)[m
[32m+[m[32m        SpellIconID == spellInfo->SpellIconID &&[m
[32m+[m[32m        SpellVisual == spellInfo->SpellVisual)[m
         return true;[m
 [m
     SpellSpecificType spec = GetSpellSpecific();[m
[1mdiff --git a/src/server/scripts/World/npc_taxi.cpp b/src/server/scripts/World/npc_taxi.cpp[m
[1mindex efdd4da..18f776e 100644[m
[1m--- a/src/server/scripts/World/npc_taxi.cpp[m
[1m+++ b/src/server/scripts/World/npc_taxi.cpp[m
[36m@@ -51,8 +51,6 @@[m [mEndScriptData[m
 #define GOSSIP_TARIOLSTRASZ2    "Can you spare a drake to travel to Lord Of Afrasastrasz, in the middle of the temple?"[m
 #define GOSSIP_TORASTRASZA1     "I would like to see Lord Of Afrasastrasz, in the middle of the temple."[m
 #define GOSSIP_TORASTRASZA2     "Yes, Please. I would like to return to the ground floor of the temple."[m
[31m-#define GOSSIP_CAMILLE1         "I need to fly to the Windrunner Official business!"[m
[31m-#define GOSSIP_CAMILLE2         "<The riding bat for the special task is necessary to me.>"[m
 #define GOSSIP_CRIMSONWING      "<Ride the gryphons to Survey Alcaz Island>"[m
 #define GOSSIP_THRICESTAR1      "Do you think I could take a ride on one of those flying machines?"[m
 #define GOSSIP_THRICESTAR2      "Kara, I need to be flown out the Dens of Dying to find Bixie."[m
[36m@@ -159,12 +157,6 @@[m [mpublic:[m
             // top -> ground[m
             player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TORASTRASZA2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);[m
             break;[m
[31m-        case 23816: // Howling Fjord - Bat Handler Camille[m
[31m-            if (!player->GetQuestRewardStatus(11229))[m
[31m-                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CAMILLE1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);[m
[31m-            if (player->GetQuestStatus(11170) == QUEST_STATUS_INCOMPLETE)[m
[31m-                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CAMILLE2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);[m
[31m-            break;[m
         case 23704: // Dustwallow Marsh - Cassa Crimsonwing[m
             if (player->GetQuestStatus(11142) == QUEST_STATUS_INCOMPLETE)[m
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CRIMSONWING, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+25);[m
