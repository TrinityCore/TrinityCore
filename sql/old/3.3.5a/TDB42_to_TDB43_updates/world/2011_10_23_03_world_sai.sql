-- Shattered Rumbler SAI
SET @ENTRY := 17157;
SET @ENTRY_MINION := 18181; -- Minion of Gurok
SET @SPELL_EARTH_RUMBLE := 33840; -- Earth Rumble
SET @SPELL_THROW_GORDAWGS_BULDER := 32001; -- Throw Gordawgs Boulder
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`=''WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,8000,9000,11,@SPELL_EARTH_RUMBLE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Rumbler - In Combat - Cast Earth Rumble"),
(@ENTRY,0,1,0,8,0,100,1,@SPELL_THROW_GORDAWGS_BULDER,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Shattered Rumbler - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,12,@ENTRY_MINION,4,20000,0,0,0,1,0,0,0,0,0,0,0,"Shattered Rumbler - Script - Summon Minion of Gurok"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,12,@ENTRY_MINION,4,20000,0,0,0,1,0,0,0,0,0,0,0,"Shattered Rumbler - Script - Summon Minion of Gurok"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,12,@ENTRY_MINION,4,20000,0,0,0,1,0,0,0,0,0,0,0,"Shattered Rumbler - Script - Summon Minion of Gurok"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Rumbler - Script - Die");

-- Minion of Gurok SAI
SET @ENTRY := 18181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Minion of Gurok - Out of Combat - Set Random Movement");

-- Spell Throw Gordawgs Boulder can only be cast at Shattered Rumbler
DELETE FROM `conditions` WHERE `SourceEntry`=24501 AND `ConditionValue2`=17157;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,24501,0,24,1,17157,0,0,'',"Item Gordawgs Boulder can only be used if target is Shattered Rumbler");


-- Lump SAI
SET @ENTRY := 18351;
SET @QUEST := 9918;
SET @GOSSIP := 21289;
SET @SPELL_SLEEPING_SLEEP := 42648; -- Sleeping Sleep
SET @SPELL_SHOULDER_CHARGE := 31994; -- Shoulder Charge
SET @SPELL_SPEAR_THROW := 32248; -- Spear Throw
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='',`gossip_menu_id`=@GOSSIP+1,`faction_A`=1711,`faction_H`=1711,`unit_flags`=`unit_flags`|528 WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,@SPELL_SLEEPING_SLEEP,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lump - Out Of Combat - Cast Sleeping Sleep"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lump - On Aggro - Say Line (random)"),
(@ENTRY,0,2,0,62,0,100,0,@GOSSIP+4,0,0,0,33,18354,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lump - On Gossip Select - Give Quest Credit"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Lump - On 30% HP - Run Script"),
(@ENTRY*100,9,0,0,2,0,100,1,0,0,0,0,2,1080,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lump - On Script - Set Faction Friendly"),
(@ENTRY*100,9,1,0,2,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lump - On Script - Say Line 1"),
(@ENTRY*100,9,2,0,2,0,100,1,1000,1000,0,0,5,447,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lump - On Script - Emote ONESHOT_FLY_SIT_GROUND_DOWN"), -- He wont sit down, no matter which emote I use - probably due evading
(@ENTRY*100,9,3,0,2,0,100,1,0,0,0,0,20,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lump - On Script - Stop auto-attack"),
(@ENTRY*100,9,4,0,2,0,100,1,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lump - On Script - Evade"),
(@ENTRY*100,9,5,0,2,0,100,1,0,0,0,0,28,@SPELL_SLEEPING_SLEEP,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lump - On Script - Remove Aura Sleeping Sleep"), -- Prevent gaining it - were leaving combat!
(@ENTRY,0,4,0,9,0,100,0,8,25,1500,2000,11,@SPELL_SHOULDER_CHARGE,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lump - On Player Range - Cast Shoulder Charge"),
(@ENTRY,0,5,0,9,0,100,0,5,40,1500,2000,11,@SPELL_SPEAR_THROW,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lump - On Player Range - Cast Spear Throw");
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"In Nagrand, food hunt ogre!",12,0,100,0,0,0,"Lump"),
(@ENTRY,0,1,"You taste good with maybe a little salt and pepper.",12,0,100,0,0,0,"Lump"),
(@ENTRY,1,2,"OK, OK! Lump give up!",12,0,100,0,0,0,"Lump");

-- Actual story menu
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+1 AND `text_id`=9352;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+1,9352);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+2 AND `text_id`=9353;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+2,9353);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+3 AND `text_id`=9354;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+3,9354);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+4 AND `text_id`=9355;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+4,9355);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+5 AND `text_id`=9356;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+5,9356);

-- Insert option menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN @GOSSIP+1 AND @GOSSIP+4;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(@GOSSIP+1,0,0,"I need answers, ogre!",1,1,@GOSSIP+2),
(@GOSSIP+2,1,0,"Why are the Boulderfist out this far? You know that this is Kurenai territory.",1,1,@GOSSIP+3),
(@GOSSIP+3,2,0,"And you think you can just eat anything you want? You're obviously trying to eat the Broken of Telaar.",1,1,@GOSSIP+4),
(@GOSSIP+4,3,0,"This means war, Lump! War I say!",1,1,@GOSSIP+5);

-- Only show first gossip if player is on quest Not On My Watch!
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP+1 AND `ConditionValue1`=@QUEST AND `SourceTypeOrReferenceId`=15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP+1,0,0,9,@QUEST,0,0,0,'',"Only show first gossip if player is on quest Not On My Watch!");


-- Wild Sparrowhawk SAI
SET @ENTRY := 22979;
SET @SPELL_SPARROWHAWK_NET := 39810; -- Sparrowhawk Net
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='',`InhabitType`=4 WHERE `entry`=@ENTRY; -- Always in air
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,@SPELL_SPARROWHAWK_NET,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Wild Sparrowhawk - On Spellhit - Run Script"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,28,@SPELL_SPARROWHAWK_NET,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wild Sparrowhawk - On Death - Remove Aura Sparrowhawk Net"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,41,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wild Sparrowhawk - Force Despawn 8 Seconds After Death'),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wild Sparrowhawk - On Script - Flee For Assist"), -- This is how it should work - there is no flee function in event_scripts, so can't do it blizzlike (event_scripts 39812)
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,28,@SPELL_SPARROWHAWK_NET,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wild Sparrowhawk - On Script - Remove Aura Sparrowhawk Net"), -- Remove it and add it back later
(@ENTRY*100,9,2,0,0,0,100,0,11000,11000,0,0,56,32320,1,0,0,0,0,7,0,0,0,0,0,0,0,"Wild Sparrowhawk - On Script - Add Item Captured Sparrowhawk"),
(@ENTRY*100,9,3,0,0,0,100,0,11000,11000,0,0,37,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wild Sparrowhawk - On Script - Die");

-- Spell Sparrowhawk Net can only be cast at Wild Sparrowhawk
DELETE FROM `conditions` WHERE `SourceEntry`=32321 AND `ConditionValue2`=22979 AND `SourceTypeOrReferenceId`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,32321,0,24,1,22979,0,0,'',"Item Sparrowhawk Net can only be used if target is Wild Sparrowhawk");


-- [Q] Diplomatic Measures
SET @GOSSIP := 21295;
SET @QUEST_HORDE := 10107;
SET @QUEST_ALLIANCE := 10108;

-- Lantresor of the Blade SAI
SET @ENTRY := 18261;
SET @SPELL_BUNING_BLADE_BLADEMASTER := 32281; -- Burning Blade Blademaster
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP+0,`AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,@SPELL_BUNING_BLADE_BLADEMASTER,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lantrestor of the Blade - Out of Combat - Cast Burning Blade Blademaster"),
(@ENTRY,0,1,0,62,0,100,0,@GOSSIP+7,0,0,0,26,@QUEST_ALLIANCE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lantrestor of the Blade - On Gossip Select - Give Quest Credit"),
(@ENTRY,0,2,0,62,0,100,0,@GOSSIP+7,0,0,0,26,@QUEST_HORDE,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lantrestor of the Blade - On Gossip Select - Give Quest Credit");

-- Make the npc_text entries work properly
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+1 AND `text_id`=9362;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+1,9362);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+2 AND `text_id`=9363;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+2,9363);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+3 AND `text_id`=9364;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+3,9364);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+4 AND `text_id`=9365;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+4,9365);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+5 AND `text_id`=9366;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+5,9366);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+6 AND `text_id`=9367;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+6,9367);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+7 AND `text_id`=9368;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+7,9368);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+8 AND `text_id`=9369;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+8,9369);

-- Insert menu options
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN @GOSSIP+0 AND @GOSSIP+7;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(@GOSSIP+0,0,0,"I have killed many of your ogres, Lantresor. I have no fear.",1,1,@GOSSIP+1),
(@GOSSIP+1,1,0,"Should I know? You look like an orc to me.",1,1,@GOSSIP+2),
(@GOSSIP+2,2,0,"And the other half?",1,1,@GOSSIP+3),
(@GOSSIP+3,3,0,"I have heard of your kind, but I never thought to see the day when I would meet a half-breed.",1,1,@GOSSIP+4),
(@GOSSIP+4,4,0,"My apologies. I did not mean to offend. I am here on behalf of my people.",1,1,@GOSSIP+5),
(@GOSSIP+5,5,0,"My people ask that you pull back your Boulderfist ogres and cease all attacks on our territories. In return, we will also pull back our forces.",1,1,@GOSSIP+6),
(@GOSSIP+6,6,0,"We will fight you until the end,then, Lantresor. We will not stand idly by as you pillage our towns and kill our people.",1,1,@GOSSIP+7),
(@GOSSIP+7,7,0,"What do I need to do?",1,1,@GOSSIP+8);

-- Conditions for gossip menu of quest Diplomatic Measures, they are grouped and thus ONE of them must be met in order for the gossip to become visible
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP+0,0,0,9,@QUEST_ALLIANCE,0,0,0,'',"Only show first gossip if player is on quest Diplomatic Measures (alliance)"),
(15,@GOSSIP+0,0,1,9,@QUEST_HORDE,0,0,0,'',"Only show first gossip if player is on quest Diplomatic Measures (horde)");
