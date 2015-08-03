-- Fix quest: Convocation at Zol'Heb (12730)

SET @GUID := 45214;

SET @NPC_ELM_BUNNY_LARGE := 24021;
SET @NPC_AKALI_PROPHET   := 29028;
SET @NPC_HARKOA          := 29050;
SET @GO_SKULL_PILE       := 190594;
SET @GO_CIRCLE           := 191123;
SET @GO_TORCH            := 191365;
SET @GO_SPELLFOCUS       := 300221;

DELETE FROM `creature` WHERE `guid` IN (@GUID);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(@GUID,@NPC_ELM_BUNNY_LARGE,571,1,1,21999,6448.935,-4475.177,451.3292,0.8028514,300,0,0);

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_AKALI_PROPHET,@NPC_HARKOA);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_AKALI_PROPHET,0,0,'What is this? I recognize you from when I killed Akali. You must be this $N that everyone is dreading.',14,0,100,25,0,12009,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,1,0,'You don''t worry me, $g boy : girl;. Just the opposite - I look forward to killing you. Nothing will stand between me and Zim''Torga now!',14,0,100,15,0,6200,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,2,0,'How sad that only now do you grasp the truth - I wield the power of a god. You are a mere mortal. You cannot hope to defeat me!',14,0,100,11,0,0,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,3,0,'You''ve meddled in affairs that were none of your business. You are nothing but a foreign invader. Prepare to die!',14,0,100,15,0,0,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,4,0,'The prophet begins to cast a ritual of annihilation.',16,0,100,0,0,0,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,5,0,'What? HAR''KOA?!',14,0,100,0,0,0,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,6,0,'Very well, kitten. I see no need to delay your inevitable demise. I look forward to dealing with you just as soon as I finish off this fool!',14,0,100,0,0,0,'Prophet of Akali'),
(@NPC_AKALI_PROPHET,7,0,'NO! I will not be defeated!',14,0,100,0,0,0,'Prophet of Akali'),
(@NPC_HARKOA,0,0,'PROPHET!',14,0,100,0,0,643,'Har''koa'),
(@NPC_HARKOA,1,0,'YOU KEEP YOUR FILTHY DRAKKARI HANDS OFF OF THEM!',14,0,100,35,0,11887,'Har''koa'),
(@NPC_HARKOA,2,0,'I THINK NOT. YOU WILL DROP YOUR IMMUNITY, CEASE YOUR RITUAL NOW AND RELEASE THEM!',14,0,100,0,0,11883,'Har''koa'),
(@NPC_HARKOA,3,0,'Thank you. Once again you have saved us all. I will see you back at Zim''Torga.',14,0,100,0,0,0,'Har''koa');

UPDATE `creature_template` SET `speed_run`=3.5714286, `dmg_multiplier`=7.5 WHERE `entry`=@NPC_HARKOA;
UPDATE `creature_model_info` SET `bounding_radius`=2.17, `combat_reach`=7 WHERE `modelid`=28009;

DELETE FROM `creature_equip_template` WHERE `entry`=@NPC_AKALI_PROPHET;
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@NPC_AKALI_PROPHET,1,39892,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (52956,52989);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52956,0,0,31,0,3,@NPC_ELM_BUNNY_LARGE,0,0,0,'','Spell Prophet of Akali Convocation targets ELM General Purpose Bunny Large'),
(13,1,52989,0,0,31,0,4,0,0,0,0,'','Spell Akali''s Stun targets players');

DELETE FROM `spell_scripts` WHERE `id`=53010;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(53010,0,0,14,52989,0,0,0,0,0,0);

DELETE FROM `spell_script_names` WHERE `spell_id`=53350;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(53350,'spell_q12730_quenching_mist');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=52989;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(52989,-53504,1,'On spellhit Akali''s Stun - Remove aura Flickering Flames');

DELETE FROM `waypoints` WHERE `entry` IN (@NPC_HARKOA,@NPC_HARKOA*10);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@NPC_HARKOA,1,6369.87,-4507.906,458.1296,'Har''koa'),
(@NPC_HARKOA,2,6372.938,-4508.172,457.8796,'Har''koa'),
(@NPC_HARKOA,3,6377.188,-4508.172,457.8796,'Har''koa'),
(@NPC_HARKOA,4,6387.688,-4507.922,457.8796,'Har''koa'),
(@NPC_HARKOA,5,6403.007,-4521.438,458.1296,'Har''koa'),

(@NPC_HARKOA*10,1,6404.547,-4486.095,451.1878,'Har''koa'),
(@NPC_HARKOA*10,2,6395.547,-4486.345,451.1878,'Har''koa'),
(@NPC_HARKOA*10,3,6391.547,-4486.345,451.1878,'Har''koa'),
(@NPC_HARKOA*10,4,6390.047,-4486.595,451.1878,'Har''koa'),
(@NPC_HARKOA*10,5,6388.047,-4486.595,451.4378,'Har''koa'),
(@NPC_HARKOA*10,6,6367.047,-4487.345,455.9378,'Har''koa'),
(@NPC_HARKOA*10,7,6364.297,-4487.595,457.9378,'Har''koa'),
(@NPC_HARKOA*10,8,6348.413,-4488.189,458.1296,'Har''koa');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_AKALI_PROPHET,@NPC_HARKOA);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@GO_SKULL_PILE,@GO_CIRCLE,@GO_TORCH,@GO_SPELLFOCUS);
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@NPC_AKALI_PROPHET,@NPC_HARKOA);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_AKALI_PROPHET,@NPC_HARKOA) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GO_SKULL_PILE,@GO_CIRCLE,@GO_TORCH,@GO_SPELLFOCUS) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_AKALI_PROPHET*100+0,@NPC_AKALI_PROPHET*100+1,@NPC_AKALI_PROPHET*100+2,@NPC_HARKOA*100,@GO_CIRCLE*100,@GO_TORCH*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_AKALI_PROPHET,0,0,1,54,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - Just summoned - Set unit_flags IMMUNE_TO_PC'),
(@NPC_AKALI_PROPHET,0,1,2,61,0,100,0,0,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - Just summoned - Spellcast Ethereal Teleport'),
(@NPC_AKALI_PROPHET,0,2,3,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Prophet of Akali - Just summoned - Store targetlist'),
(@NPC_AKALI_PROPHET,0,3,0,61,0,100,0,0,0,0,0,80,@NPC_AKALI_PROPHET*100+0,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - Just summoned - Run script 0'),
(@NPC_AKALI_PROPHET,0,4,0,0,1,100,0,10000,12000,14000,16000,11,53496,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Prophet of Akali - On update IC (phase 1) - Spellcast Darting Flames'),
(@NPC_AKALI_PROPHET,0,5,0,0,1,100,0,16000,18000,12000,15000,11,53493,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Prophet of Akali - On update IC (phase 1) - Spellcast Incinerate'),
(@NPC_AKALI_PROPHET,0,6,7,2,0,100,1,0,70,0,0,11,52982,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On health below 70% - Spellcast Akali''s Immunity'),
(@NPC_AKALI_PROPHET,0,7,8,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On health below 70% - Disable autoattack'),
(@NPC_AKALI_PROPHET,0,8,9,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On health below 70% - Set event phase 2'),
(@NPC_AKALI_PROPHET,0,9,0,61,0,100,0,0,0,0,0,80,@NPC_AKALI_PROPHET*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On health below 70% - Run script 1'),
(@NPC_AKALI_PROPHET,0,10,11,34,4,100,0,0,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.8028514, 'Prophet of Akali - On movement inform (phase 3) - Set orientation'),
(@NPC_AKALI_PROPHET,0,11,12,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On movement inform (phase 3) - Set event phase 0'),
(@NPC_AKALI_PROPHET,0,12,0,61,0,100,0,0,0,0,0,80,@NPC_AKALI_PROPHET*100+2,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali - On movement inform (phase 3) - Run script 2'),

(@NPC_HARKOA,0,0,0,54,0,100,0,0,0,0,0,53,1,@NPC_HARKOA,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa - Just summoned - Start WP movement'),
(@NPC_HARKOA,0,1,0,40,0,100,0,5,@NPC_HARKOA,0,0,45,0,1,0,0,0,0,19,@NPC_AKALI_PROPHET,50,0,0,0,0,0, 'Har''koa - On WP 5 reached - Set data 0 1 Akali Prophet'),
(@NPC_HARKOA,0,2,0,38,0,100,0,0,1,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Har''koa - On data 0 1 set - Turn to'),
(@NPC_HARKOA,0,3,0,38,0,100,0,0,2,0,0,80,@NPC_HARKOA*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa - On data 0 2 set - Run script'),
(@NPC_HARKOA,0,4,5,7,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa - On Evade - Say line'),
(@NPC_HARKOA,0,5,0,61,0,100,0,0,0,0,0,53,1,@NPC_HARKOA*10,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa - On Evade - Start WP movement'),
(@NPC_HARKOA,0,6,0,0,0,100,0,15000,16000,9000,10000,11,53499,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Har''koa - On update IC - Spellcast Rake'),
(@NPC_HARKOA,0,7,0,0,0,100,0,16000,17000,10000,10000,11,53498,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Har''koa - On update IC - Spellcast Swipe'),
(@NPC_HARKOA,0,8,0,0,0,100,0,10000,12000,12000,15000,86,53350,0,19,@NPC_AKALI_PROPHET,30,0,1,0,0,0,0,0,0,0, 'Har''koa - On update IC - Spellcast Quenching Mist'),
(@NPC_HARKOA,0,9,0,40,0,100,0,8,@NPC_HARKOA*10,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa - On WP 8 reached - Despawn'),

(@GO_SKULL_PILE,1,0,1,38,0,100,0,0,1,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Zul''Drak Skull Pile 02 - On data 0 1 set - Set phasemask 2'),
(@GO_SKULL_PILE,1,1,0,61,0,100,0,0,0,0,0,80,@GO_TORCH*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Zul''Drak Skull Pile 02 - On data 0 1 set - Run script'),

(@GO_CIRCLE,1,0,1,38,0,100,0,0,1,0,0,9,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Convocation Summoning Circle - On data 0 1 set - Activate gameobject'),
(@GO_CIRCLE,1,1,0,61,0,100,0,0,0,0,0,80,@GO_CIRCLE*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Convocation Summoning Circle - On data 0 1 set - Run script'),

(@GO_TORCH,1,0,1,38,0,100,0,0,1,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadow Council Torch (x2.00) - On data 0 1 set - Set phasemask 2'),
(@GO_TORCH,1,1,0,61,0,100,0,0,0,0,0,80,@GO_TORCH*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadow Council Torch (x2.00) - On data 0 1 set - Run script'),

(@GO_SPELLFOCUS,1,0,1,38,0,100,0,0,1,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'TEMP Convocation Summoning Circle - On data 0 1 set - Set phasemask 2'),
(@GO_SPELLFOCUS,1,1,0,61,0,100,0,0,0,0,0,80,@GO_TORCH*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'TEMP Convocation Summoning Circle - On data 0 1 set - Run script'),

(@NPC_AKALI_PROPHET*100+0,9,0,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,13,@GO_SKULL_PILE,0,20,0,0,0,0, 'Prophet of Akali script 0 - Set data 0 1 Zul''Drak Skull Pile 02'),
(@NPC_AKALI_PROPHET*100+0,9,1,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,20,@GO_CIRCLE,20,0,0,0,0,0, 'Prophet of Akali script 0 - Set data 0 1 Convocation Summoning Circle'),
(@NPC_AKALI_PROPHET*100+0,9,2,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,13,@GO_TORCH,0,20,0,0,0,0, 'Prophet of Akali script 0 - Set data 0 1 Shadow Council Torch (x2.00)'),
(@NPC_AKALI_PROPHET*100+0,9,3,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,20,@GO_SPELLFOCUS,20,0,0,0,0,0, 'Prophet of Akali script 0 - Set data 0 1 TEMP Convocation Summoning Circle'),
(@NPC_AKALI_PROPHET*100+0,9,4,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Prophet of Akali script 0 - Turn to summoner'),
(@NPC_AKALI_PROPHET*100+0,9,5,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Prophet of Akali script 0 - Say line'),
(@NPC_AKALI_PROPHET*100+0,9,6,0,0,0,100,0,6000,6000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Prophet of Akali script 0 - Turn to summoner'), 
(@NPC_AKALI_PROPHET*100+0,9,7,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Prophet of Akali script 0 - Say line'),
(@NPC_AKALI_PROPHET*100+0,9,8,0,0,0,100,0,3600,3600,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 0 - Remove unit_flags IMMUNE_TO_PC'),
(@NPC_AKALI_PROPHET*100+0,9,9,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Prophet of Akali script 0 - Start attack'),
(@NPC_AKALI_PROPHET*100+0,9,10,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 0 - Set event phase 1'),

(@NPC_AKALI_PROPHET*100+1,9,0,0,0,0,100,0,2400,2400,0,0,11,52989,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 1 - Spellcast Akali''s Stun'),
(@NPC_AKALI_PROPHET*100+1,9,1,0,0,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,6448.36,-4475.49,451.0759,0, 'Prophet of Akali script 1 - Move to position'),
(@NPC_AKALI_PROPHET*100+1,9,2,0,0,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 1 - Set event phase 3'),

(@NPC_AKALI_PROPHET*100+2,9,0,0,0,0,100,0,800,800,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Say line'),
(@NPC_AKALI_PROPHET*100+2,9,1,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Say line'),
(@NPC_AKALI_PROPHET*100+2,9,2,0,0,0,100,0,2400,2400,0,0,11,52993,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Spellcast Akali''s Ritual of Annihilation'),
(@NPC_AKALI_PROPHET*100+2,9,3,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Say line'),
(@NPC_AKALI_PROPHET*100+2,9,4,0,0,0,100,0,2000,2000,0,0,12,@NPC_HARKOA,1,300000,0,0,0,8,0,0,0,6355.075,-4494.311,458.179,0, 'Prophet of Akali script 2 - Summon Har''koa'),
(@NPC_AKALI_PROPHET*100+2,9,5,0,0,0,100,0,4000,4000,0,0,45,0,1,0,0,0,0,19,@NPC_HARKOA,100,0,0,0,0,0, 'Prophet of Akali script 2 - Set data 0 1 Har''koa'),
(@NPC_AKALI_PROPHET*100+2,9,6,0,0,0,100,0,4600,4600,0,0,45,0,2,0,0,0,0,19,@NPC_HARKOA,100,0,0,0,0,0, 'Prophet of Akali script 2 - Set data 0 2 Har''koa'),
(@NPC_AKALI_PROPHET*100+2,9,7,0,0,0,100,0,1500,1500,0,0,66,0,0,0,0,0,0,19,@NPC_HARKOA,100,0,0,0,0,0, 'Prophet of Akali script 2 - Turn to Har''koa'),
(@NPC_AKALI_PROPHET*100+2,9,8,0,0,0,100,0,1300,1300,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Say line'),
(@NPC_AKALI_PROPHET*100+2,9,9,0,0,0,100,0,7100,7100,0,0,66,0,0,0,0,0,0,19,@NPC_HARKOA,100,0,0,0,0,0, 'Prophet of Akali script 2 - Turn to Har''koa'),
(@NPC_AKALI_PROPHET*100+2,9,10,0,0,0,100,0,100,100,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Say line'),
(@NPC_AKALI_PROPHET*100+2,9,11,0,0,0,100,0,9500,9500,0,0,92,0,52993,1,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Interrupt spellcast'),
(@NPC_AKALI_PROPHET*100+2,9,12,0,0,0,100,0,300,300,0,0,11,53010,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Spellcast Convocation at Zol''Heb: Removef Akali''s Stun'),
(@NPC_AKALI_PROPHET*100+2,9,13,0,0,0,100,0,0,0,0,0,28,52982,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Remove aura Akali''s Immunity'),
(@NPC_AKALI_PROPHET*100+2,9,14,0,0,0,100,0,100,100,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Say line'),
(@NPC_AKALI_PROPHET*100+2,9,15,0,0,0,100,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Remove unit_flags IMMUNE_TO_NPC'),
(@NPC_AKALI_PROPHET*100+2,9,16,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Set event phase 1'),
(@NPC_AKALI_PROPHET*100+2,9,17,0,0,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Enable combat movement'),
(@NPC_AKALI_PROPHET*100+2,9,18,0,0,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Prophet of Akali script 2 - Enable autoattack'),

(@NPC_HARKOA*100,9,0,0,0,0,100,0,1200,1200,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa script 0 - Say line'),
(@NPC_HARKOA*100,9,1,0,0,0,100,0,5100,5100,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa script 0 - Say line'),
(@NPC_HARKOA*100,9,2,0,0,0,100,0,11000,11000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa script 0 - Say line'),
(@NPC_HARKOA*100,9,3,0,0,0,100,0,0,0,0,0,11,53004,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa script 0 - Spellcast Har''koa''s Compulsion'),
(@NPC_HARKOA*100,9,4,0,0,0,100,0,400,400,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa script 0 - Remove unit_flags IMMUNE_TO_NPC'),
(@NPC_HARKOA*100,9,5,0,0,0,100,0,2700,2700,0,0,97,108.6365,0,0,0,0,0,1,0,0,0,6439.68,-4484.5,451.246,0, 'Har''koa script 0 - Jump to position'),
(@NPC_HARKOA*100,9,6,0,0,0,100,0,2000,2000,0,0,49,0,0,0,0,0,0,19,@NPC_AKALI_PROPHET,50,0,0,0,0,0, 'Har''koa script 0 - Start attack'),
(@NPC_HARKOA*100,9,7,0,0,0,100,0,0,0,0,0,11,53029,0,0,0,0,0,19,@NPC_AKALI_PROPHET,50,0,0,0,0,0, 'Har''koa script 0 - Spellcast Har''koa''s Challenge'),
(@NPC_HARKOA*100,9,8,0,0,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Har''koa script 0 - Set homeposition'),

(@GO_CIRCLE*100,9,0,0,0,0,100,0,1000,1000,0,0,44,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Convocation Summoning Circle script - Set phasemask 2'),
(@GO_CIRCLE*100,9,1,0,0,0,100,0,299000,299000,0,0,44,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Convocation Summoning Circle script - Set phasemask 1'),

(@GO_TORCH*100,9,0,0,0,0,100,0,300000,300000,0,0,44,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadow Council Torch (x2.00) script - Set phasemask 1');
