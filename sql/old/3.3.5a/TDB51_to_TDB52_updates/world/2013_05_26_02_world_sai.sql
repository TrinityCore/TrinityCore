-- Not-So-Honorable Combat (13137)
SET @GO_SIGNAL_FIRE             := 193024;  -- Battlescar Signal Fire
SET @EVENT_SCRIPT               := 20069;   -- Event Script
SET @NPC_POSSESSED_ISKALDER     := 30924;   -- Possessed Iskalder <The Ancient Hero>
SET @NPC_VARDMADRA              := 30945;   -- Vadmadra
SET @NPC_LADY_NIGHTSWOOD        := 30955;   -- Lady Nightswood
SET @MOVE_TARGET_BUNNY          := 25715;   -- Not-So-Honorable Combat: Summon Lady Nightswood's Moveto Target Bunny
SET @TARGET_BUNNY               := 30959;   -- Lady Nightswood's Moveto Target Bunny
SET @SUMMON_NIGHTSWOOD          := 25727;   -- Not-So-Honorable Combat: Summon Lady Nightswood
SET @POSSESS_VARDMADRA          := 25745;   -- Possession

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 13 AND `SourceEntry`IN (@SUMMON_NIGHTSWOOD,@MOVE_TARGET_BUNNY,@POSSESS_VARDMADRA);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13,1,@SUMMON_NIGHTSWOOD,0,0,31,0,3,@TARGET_BUNNY,0,0,0,'','Summon Nightswood only hits Target Bunny'),
(13,1,@MOVE_TARGET_BUNNY,0,0,31,0,3,@NPC_POSSESSED_ISKALDER,0,0,0,'','Move Target Bunny only hits Target Bunny'),
(13,1,@POSSESS_VARDMADRA,0,0,31,0,3,@NPC_VARDMADRA,0,0,0,'','Possess Vardmadra only hits Vardmadra');

UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=2116,`faction_H`=2116,`unit_flags`=33088,`mindmg`=422,`maxdmg`=586,`attackpower`=642,`minrangedmg`=345,`maxrangedmg`=509,`rangedattackpower`=103 WHERE `entry`=@NPC_POSSESSED_ISKALDER;
UPDATE `creature_template` SET `faction_A`=2116,`faction_H`=2116,`unit_flags`=33536,`AIName`='SmartAI',`minlevel`=80, `maxlevel`=80 WHERE `entry`=@NPC_VARDMADRA;
UPDATE `creature_template` SET `AIName`='SmartAI', `InhabitType`=7 WHERE  `entry` IN (@TARGET_BUNNY,@NPC_LADY_NIGHTSWOOD);
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=0 WHERE  `entry`=@TARGET_BUNNY;
DELETE FROM `creature_template_addon` WHERE `entry` IN (@NPC_POSSESSED_ISKALDER,@NPC_VARDMADRA);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_POSSESSED_ISKALDER,0,0x0,0x1,'58102'),
(@NPC_VARDMADRA,0,0x3000000,0x1,'');

DELETE FROM `creature_equip_template` WHERE `entry`=@NPC_POSSESSED_ISKALDER;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@NPC_POSSESSED_ISKALDER,43296,43295,0);

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_POSSESSED_ISKALDER,@NPC_VARDMADRA,@NPC_LADY_NIGHTSWOOD);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_POSSESSED_ISKALDER,0,0,'Now fight me, $N! Kill Iskalder!',14,0,100,0,0,1167,'Possessed Iskalder'),
(@NPC_VARDMADRA,0,0, 'Iskalder, there you are. What is this? Engaged in battle already?',14,0,100,457,0,13824,'Vardmadra'),
(@NPC_VARDMADRA,1,0, 'NO! How is this possible?',14,0,100,457,0,13825,'Vardmadra'),
(@NPC_VARDMADRA,2,0, 'I know not how this was possible, but you must still be judged Iskalder. Wait... what is this?',14,0,100,457,0,13824,'Vardmadra'),
(@NPC_VARDMADRA,3,0, 'Stay away from me creature! Do not touch me!',14,0,100,0,0,1168,'Vardmadra to Nightswood'),
(@NPC_VARDMADRA,4,0, 'Ahahahahahaha! It is done. Return to my cave. We have much to discuss!',14,0,100,457,0,1167,'Vardmadra to '),
(@NPC_LADY_NIGHTSWOOD,0,0, 'This? This is me taking control of you. This is me setting up my final revenge!',14,0,100,457,0,13824,'Lady Nightswood');

-- Possessed Iskalder <The Ancient Hero>
DELETE FROM `event_scripts` WHERE `id`=@EVENT_SCRIPT;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@EVENT_SCRIPT,5,10,@NPC_POSSESSED_ISKALDER,180000,0,7229.436,3642.27,809.0175,0);

DELETE FROM `smart_scripts` WHERE `source_type` IN (0,9) AND `entryorguid` IN (@NPC_POSSESSED_ISKALDER,@NPC_VARDMADRA,@NPC_LADY_NIGHTSWOOD,@TARGET_BUNNY,@TARGET_BUNNY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_POSSESSED_ISKALDER,0,0,1,54,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iskalder - On Summon - Remove unit flag'),
(@NPC_POSSESSED_ISKALDER,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iskalder - On Link - Talk'),
(@NPC_POSSESSED_ISKALDER,0,2,0,2,0,100,1,0,65,0,0,12,@NPC_VARDMADRA,3,180000,0,0,0,8,0,0,0,7182.766602,3661.931885, 826.149292, 5.838641, 'Possessed Iskalder - on 65% HP - Spawn Vardmara'),
(@NPC_POSSESSED_ISKALDER,0,3,0,4,0,100,1,0,0,0,0,11,60108,0,0,0,0,0,2,0,0,0,0,0,0,0,'Iskalder - On Aggro - Cast Heroic Leap'),
(@NPC_POSSESSED_ISKALDER,0,4,0,0,0,100,0,3500,3500,14500,16700,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Iskalder - In Combat - Cast Cleave'),
(@NPC_POSSESSED_ISKALDER,0,5,0,0,0,100,0,5000,6000,11200,15800,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Iskalder - In Combat - Cast Heroic Strike'),
(@NPC_POSSESSED_ISKALDER,0,6,0,0,0,100,0,9000,11000,25000,25000,11,60121,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iskalder - In Combat - Cast Ancient Curse'),
(@NPC_POSSESSED_ISKALDER,0,7,0,2,0,100,1,0,50,0,0,1,0,0,0,0,0,0,11,@NPC_VARDMADRA,200,0,0,0,0,0,'Iskalder - On HPC - Make Vardmadra Say'),
(@NPC_POSSESSED_ISKALDER,0,8,0,6,0,100,1,0,0,0,0,45,1,1,0,0,0,0,11,@NPC_VARDMADRA,200,0,0,0,0,0,' Iskalder - On event death - Send Data to Vardmadra'),
(@NPC_POSSESSED_ISKALDER,0,9,10,1,0,100,1,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iskalder - OOC - Remove unit flag'),
(@NPC_POSSESSED_ISKALDER,0,10,0,61,0,100,1,0,0,0,0,45,2,2,0,0,0,0,11,@NPC_VARDMADRA,300,0,0,0,0,0, 'Possessed Iskalder - On link - Set Data on Vardmara'),

(@NPC_VARDMADRA,0,0,1,38,0,100,0,1,1,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vardmadra - On Receive Data - Set Run'),
(@NPC_VARDMADRA,0,1,2,61,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,7234.742,3643.584,811.8065,5.507,'Vardmadra - Linked with Previous Event - Move to position'),
(@NPC_VARDMADRA,0,2,3,61,0,100,0,0,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,'Vardmadra - Linked with Previous Event - Say'),
(@NPC_VARDMADRA,0,3,4,61,0,100,1,0,0,0,0,11,@MOVE_TARGET_BUNNY,2,0,0,0,0,19,@NPC_POSSESSED_ISKALDER,200,1,0,0,0,0,'Vardmadra - Linked with Previous Event - Cast Not-So-Honorable Combat: Summon Lady Nightswood''s Moveto Target Bunny'),
(@NPC_VARDMADRA,0,4,5,52,0,100,0,1,@NPC_VARDMADRA,0,0,1,2,10000,0,0,0,0,1,0,0,0,0,0,0,0,'Vardmadra - On Text Over - Say'),
(@NPC_VARDMADRA,0,5,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_POSSESSED_ISKALDER,200,1,0,0,0,0,'Vardmadra - On Link - Turn to Iskalder'),
(@NPC_VARDMADRA,0,6,7,52,0,100,0,2,@NPC_VARDMADRA,0,0,1,0,10000,0,0,0,0,11,@NPC_LADY_NIGHTSWOOD,200,0,0,0,0,0,'Vardmadra - On Text Over - Say'),
(@NPC_VARDMADRA,0,7,8,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_LADY_NIGHTSWOOD,200,0,0,0,0,0,'Vardmadra - On Link - Turn to Lady Nightswood'),
(@NPC_VARDMADRA,0,8,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@NPC_LADY_NIGHTSWOOD,200,0,0,0,0,0,'Vardmadra - On link - Send Data to Lady Nightswood'),
(@NPC_VARDMADRA,0,9,0,52,0,100,0,0,@NPC_LADY_NIGHTSWOOD,0,0,1,3,10000,0,0,0,0,1,0,0,0,0,0,0,0,'Vardmadra - On Text Over - Say'),
(@NPC_VARDMADRA,0,10,0,52,0,100,0,3,@NPC_VARDMADRA,0,0,1,4,10000,0,0,0,0,1,0,0,0,0,0,0,0,'Vardmadra- On Text Over - Say'),
(@NPC_VARDMADRA,0,11,0,52,0,100,0,4,@NPC_VARDMADRA,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vardmadra - On Text Over - Despawn'),
(@NPC_VARDMADRA,0,12,0,38,0,100,0,2,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vardmadra - On Receive Data - Despawn'),

(@TARGET_BUNNY,0,0,0,54,0,100,0,0,0,0,0,80,@TARGET_BUNNY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Lady Nightswood Move-to-Bunny - On Summon - Start Timed Script'),
(@TARGET_BUNNY*100,9,0,0,0,0,100,0,7000,7000,7000,7000,69,0,0,0,0,0,0,8,0,0,0,7242.77,3631.67,814.0644,2.227,'Lady Nightswood Move-to-Bunny - On Script - Go to position'),
(@TARGET_BUNNY*100,9,1,0,0,0,100,0,8000,8000,8000,8000,11,@SUMMON_NIGHTSWOOD,2,0,0,0,0,1,0,0,0,0,0,0,0,'Lady Nightswood Move-to-Bunny - Linked with Previous Event - Cast Not-So-Honorable Combat: Summon Lady Nightswood''s Moveto Target Bunny'),

(@NPC_LADY_NIGHTSWOOD,0,0,0,54,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_VARDMADRA,200,0,0,0,0,0,'Lady Nightswood - On Summon - Turn to Vardmadra'),
(@NPC_LADY_NIGHTSWOOD,0,1,0,38,0,100,0,1,1,0,0,11,@POSSESS_VARDMADRA,0,0,0,0,0,19,@NPC_VARDMADRA,200,0,0,0,0,0,'Lady Nigtswood - On Receive Data - Possess Vardmadra');
