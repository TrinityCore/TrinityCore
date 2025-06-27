-- Lights Vengence

SET @QUEST := 24546;-- The Sacred and the Corrupt
SET @TRIGG := 5650;
SET @LIGHTSVENGENCE:= 49869;
SET @BUNNY		:= 37832;-- Lich King Stun Bunny
SET @BUNNY2		:= 37878;-- AoD Impact Bunny

SET @LICHKING 		:= 37857;-- The Lich King

SET @CGUID		:= 76000;

UPDATE `creature_template` SET `flags_extra`=130 WHERE  `entry`=37826;
UPDATE `creature_template` SET `unit_flags`=768, `unit_flags2`=2099200, `dynamicflags`=1613035584 WHERE  `entry`=37857;
UPDATE `creature_template` SET `unit_flags`=33554688, `unit_flags2`=2099200, `dynamicflags`=1613037824 WHERE  `entry`=37894;
UPDATE `creature_template` SET `unit_flags`=33554688, `unit_flags2`=2099200, `dynamicflags`=1613036800 WHERE  `entry`=37878;


DELETE FROM `areatrigger_scripts` WHERE `entry` = @TRIGG;
INSERT INTO `areatrigger_scripts`(`entry`, `ScriptName`) VALUES
(@TRIGG,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` =@TRIGG AND `source_type`=2;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRIGG,2,0,1,46,0,100,0,@TRIGG,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"On Trigger - Store Target List"),
(@TRIGG,2,1,2,61,0,100,0,@TRIGG,0,0,0,100,1,0,0,0,0,0,10,@CGUID,@BUNNY,0,0,0,0,0,"On Trigger - Send Target List to Lich King Stun Bunny"),
(@TRIGG,2,2,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,@CGUID,@BUNNY,0,0,0,0,0,"On Trigger - Set Data on Lich King Stun Bunny");

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE`entry`IN(@BUNNY,@LICHKING,37827,37832,@BUNNY2,37881,37894,37893,38001,37976,37826,37952);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@BUNNY,@LICHKING,37827,37832,@BUNNY2,37881,37894,37893,38001,37976,37826,37952) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@LICHKING*100,37893*100,37952*100,3795201) AND `source_type`=9;

INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BUNNY,0,0,1,38,0,100,0,1,1,300000,300000,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich King Stun Bunny - On Data Set - Set Data"),
(@BUNNY,0,1,2,61,0,100,0,0,0,0,0,11,70583,0,0,0,0,0,12,1,0,0,0, 0, 0, 0,"Lich King Stun Bunny - On Data Set - Cast Lich King Stun"),
(@BUNNY,0,2,0,61,0,100,0,0,0,0,0,12,@LICHKING,1,300000,0,0,0,8,0,0,0,4835.083, -586.7692, 162.0051, 2.804995,"Lich King Stun Bunny - On Data Set - Summon The Lich Kin"),
(@BUNNY,0,3,4,38,0,100,0,2,2,0,0,11,70571,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich King Stunn Bunny - On Data Set - Cast Holy Zone Visual"),
(@BUNNY,0,4,0,61,0,100,0,0,0,0,0,11,70603,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich King Stunn Bunny - On Data Set - Cast Summon Light's Vengeance"),
(@BUNNY,0,5,0,38,0,100,0,3,3,0,0,28,70571,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lich King Stunn Bunny - On Data Set - Remove Aura Holy Zone Visual"),
(@BUNNY2,0,0,0,8,0,100,0,70614,0,10000,15000,11,70617,0,0,0,0,0,1,0,0,0,0,0,0,0,"AOD Impact Bunny - On Spell Hit(AoD Special)- Cast Summon Ghoul"),
(@BUNNY2,0,1,0,8,0,100,0,70743,0,10000,15000,11,70617,0,0,0,0,0,1,0,0,0,0,0,0,0,"AOD Impact Bunny - On Spell Hit(AoD Special - Vegard)- Cast Summon Ghoul"),
(@LICHKING,0,0,0,54,0,100,0,0,0,0,0,53,0,@LICHKING,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - On Just Summoned - Start WP"),
(@LICHKING,0,1,0,40,0,100,0,11,@LICHKING,0,0,80,@LICHKING*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - On Reached WP11 - Run Script"),
(37826,0,0,1,11,0,100,0,0,0,0,0,12,37827,8,0,0,0,0,8,0,0,0,4812.009, -586.2327, 162.57,0,"Light's Vengeance - On Spawn - Spawn Light's Vengeance Vehicle Bunny"),
(37826,0,1,2,61,0,100,0,0,0,0,0,12,37952,8,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance - On Spawn - Spawn Light's Vengeance Vehicle Bunny 2"),
(37952,0,0,0,38,0,100,1,1,1,0,0,80,3795200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - On Data Set - Run Script"),
(37952,0,1,2,40,0,100,0,8,37952,0,0,80,3795201,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - On Reached WP8 - Run Script 2"),
(37826,0,2,0,61,0,100,0,0,0,0,0,11,46598,0,0,0,0,0,19,37952,0,0,0,0,0,0,"Light's Vengeance - On Spawn - Cast Ride Vehicle Hardcoded"),
(37827,0,0,1,38,0,100,0,1,1,0,0,11,50630,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny - On Data Set - Cast Eject All Passengers"),
(37827,0,1,2,61,0,100,0,0,0,0,0,11,70595,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny - On Data Set - Cast Light's Vengeance Throw"),
(37827,0,2,0,61,0,100,0,0,0,0,0,70,300,0,0,0,0,0,20,201937,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny - On Data Set - Despawn Light's Vengence"),
(37881,0,0,1,54,0,100,0,0,0,0,0,11,7398,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Just Summoned - Cast Rebirth"),
(37881,0,1,0,61,0,100,0,0,0,0,0,11,70782,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Just Summoned - Cast Ghoul's Touch"),
(37881,0,2,0,8,0,100,0,70790,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Ghoul - On Spellhit(Zap Ghouls) - Die"),
(37894,0,0,0,8,0,100,0,70643,0,0,0,11,70644,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard Bunny - On Spellhit(Zap Vegard Bunny) - Cast Summon Vegard"),
(37893,0,0,0,54,0,100,0,0,0,0,0,80,3789300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Just Summoned - Run Script"),
(37893,0,1,2,8,0,100,0,70792,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Spell Hit(Kill Vegard) - Die"),
(37893,0,2,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Spell Hit(Kill Vegard) - Despawn"),
(38001,0,0,0,38,0,100,0,4,4,0,0,11,70862,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set - Cast Summon Vegard Skeleton"),
(38001,0,1,2,38,0,100,0,1,1,0,0,11,70967,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set- Cast Summon Light's Vengeance III"),
(38001,0,2,0,61,0,100,0,0,0,0,0,11,70970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set- Cast Hammer Shield"),
(38001,0,3,0,38,0,100,0,2,2,0,0,28,70970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set- Remove Aura Hammer Shield"),
(38001,0,4,0,38,0,100,0,3,3,0,0,11,70894,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Bunny 2 - On Data Set- Cast Summon Light's Vengeance II"),
(37976,0,0,1,54,0,100,0,0,0,0,0,11,7398,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Just Summoned - Cast Rebirth"),
(37976,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Just Summoned - Say Line 0"),
(37976,0,2,3,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Death - Say Line 1"),
(37976,0,3,4,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,38001,0,0,0,0,0,0,"Vegard the Unforgiven - On Death - Say Line Set Data 2 2 on Light's Vengeance Bunny 2"),
(37976,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,201937,0,0,0,0,0,0,"Vegard the Unforgiven - On Death - Say Line Set Data 1 1 on Light's Vengeance"),
(37976,0,5,0,9,0,100,0,0,10,20000,35000,11,70866,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Range - Cast Shadow Blast"),
(37976,0,6,0,2,0,100,0,0,30,15000,25000,11,70886,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Less than 30% HP - Cast Vegard's Thirst"),
(37976,0,7,0,0,0,100,0,3000,7000,25000,35000,11,71003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vegard the Unforgiven - IC - Cast Vegard's Vegard's Touch"),
(37976,0,8,9,7,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Evade - Say Line 2"),
(37976,0,9,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - On Evade - Despawn"),
(@LICHKING*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 0"), -- 16:59:11.266
(@LICHKING*100,9,1,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 1"), -- 16:59:18.641
(@LICHKING*100,9,2,0,0,0,100,0,4000,4000,0,0,11,70590,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 1"), -- 16:59:22.156
(@LICHKING*100,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37827,0,0,0,0,0,0,"The Lich King - Script - Set Data on Light's Vengeance Vehicle Bunny"), -- 16:59:22.156
(@LICHKING*100,9,4,0,0,0,100,0,3000,3000,0,0,45,2,2,0,0,0,0,19,@BUNNY,0,0,0,0,0,0,"The Lich King - Script - Set Data on Light's Vengeance Vehicle Bunny"), -- 16:59:25.375
(@LICHKING*100,9,5,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 2"), -- 16:59:28.344
(@LICHKING*100,9,6,0,0,0,100,0,8000,8000,0,0,11,70612,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Cast Summon Ghouls"), -- 16:59:36.687
(@LICHKING*100,9,7,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 3"), -- 16:59:40.484
(@LICHKING*100,9,8,0,0,0,100,0,7000,7000,0,0,11,70643,0,0,0,0,0,19,37894,0,0,0,0,0,0,"The Lich King - Script - Cast Zap Vegard Bunny"), -- 16:59:47.672
(@LICHKING*100,9,9,0,0,0,100,0,7000,7000,0,0,5,397,0,0,0,0,0,21,100,0,0,0,0,0,0,"The Lich King - Script - Play Emote OneShotPointNoSheathe(397)"), -- 16:59:54.906
(@LICHKING*100,9,10,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Say Line 4"), -- 16:59:55.031
(@LICHKING*100,9,11,0,0,0,100,0,2000,2000,0,0,11,70653,0,0,0,0,0,21,50,0,0,0,0,0,0,"The Lich King - Script - Cast Lich King Zap Player"), -- 17:00:00.812
(@LICHKING*100,9,12,0,0,0,100,0,3000,3000,0,0,11,70673,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Cast Lich King Despawn"), -- 17:00:00.812
(@LICHKING*100,9,13,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Lich King - Script - Despawn"), -- 17:00:00.812
(37893*100,9,0,0,0,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Set Unit Flags"), 
(37893*100,9,1,0,0,0,100,0,0,0,0,0,11,70692,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Cast Shield of the Lich King"), 
(37893*100,9,2,0,0,0,100,0,3000,3000,0,0,11,70737,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Cast Vegard Summon Ghouls"), 
(37893*100,9,3,0,0,0,100,0,13000,13000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Say Line 0"), -- 17:00:15.609
(37893*100,9,4,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vegard the Unforgiven - Script - Say Line 1"), -- 17:00:15.609
(37952*100,9,0,0,0,0,100,0,0,0,0,0,11,70785,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script - Cast Holy Bomb Visual"), 
(37952*100,9,1,0,0,0,100,0,0,0,0,0,11,70789,2,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script - Cast Zap Ghouls Aura"), 
(37952*100,9,2,0,0,0,100,0,0,0,0,0,53,0,37952,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script - Start WP"),
(3795201,9,0,0,0,0,100,0,0,0,0,0,11,70792,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Cast Kill Vegard"),
(3795201,9,1,0,0,0,100,0,0,0,0,0,11,70786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Cast Holy Bomb Explosion"),
(3795201,9,2,0,0,0,100,0,0,0,0,0,12,38001,1,300000,0,0,0,8,0,0,0,4812.009, -586.2327, 162.57, 2.75762,'Lights Vengeance Vehicle Bunny 2 - Script 2 - Summon Lights Vengeance Bunny 2'),
(3795201,9,3,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,38001,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Set Data 3 3 on Light's Vengeance Bunny 2"),
(3795201,9,4,0,0,0,100,0,0,0,0,0,41,120000,0,0,0,0,0,19,37826,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Despawn Light's Vengeance"),
(3795201,9,5,0,0,0,100,0,0,0,0,0,41,120000,0,0,0,0,0,19,37827,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Despawn Light's Vengeance Vehicle Bunny"),
(3795201,9,6,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Light's Vengeance Vehicle Bunny 2 - Script 2 - Despawn");


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND`SourceEntry`=@TRIGG;

INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@TRIGG,2,0,9,0,@QUEST,0,0,0,0,'','Trigger only activates if player is on and has not completed The Sacred and the Corrupt'),
(22,1,@TRIGG,2,0,2,0,@LIGHTSVENGENCE,1,0,1,0,'','Trigger does not activate if player already has lights vengence');
	
DELETE FROM `creature` WHERE `id`IN(@BUNNY,@BUNNY2,37826,37894);

INSERT INTO `creature`(`guid`, `id`, `map`, `spawnMask`, `phaseMask`,`position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, @BUNNY, 571, 1, 1, 4798.7, -639.529, 160.5693, 4.34587, 120, 0, 0), 
(@CGUID+1, @BUNNY2, 571, 1, 1, 4848.793, -601.8837, 157.445, 4.258604, 120, 0, 0), 
(@CGUID+2, @BUNNY2, 571, 1, 1, 4845.159, -576.0278, 159.9401, 5.532694, 120, 0, 0), 
(@CGUID+3, @BUNNY2, 571, 1, 1, 4826.658, -555.1059, 161.3158, 4.625123, 120, 0, 0), 
(@CGUID+4, @BUNNY2, 571, 1, 1, 4829.419, -629.3629, 157.6456, 3.612832, 120, 0, 0), 
(@CGUID+5, @BUNNY2, 571, 1, 1, 4779.228, -587.1545, 162.1223, 4.537856, 120, 0, 0), 
(@CGUID+6, @BUNNY2, 571, 1, 1, 4782.333, -572.7118, 161.8683, 5.585053, 120, 0, 0), 
(@CGUID+7, @BUNNY2, 571, 1, 1, 4796.73, -622.5868, 159.9098, 2.356194, 120, 0, 0), 
(@CGUID+8, @BUNNY2, 571, 1, 1, 4815.688, -625.3021, 158.6156, 4.066617, 120, 0, 0), 
(@CGUID+9, @BUNNY2, 571, 1, 1, 4792.949, -603.3854, 160.3281, 2.740167, 120, 0, 0), 
(@CGUID+10, @BUNNY2, 571, 1, 1, 4795.549, -631.2952, 160.2526, 1.361357, 120, 0, 0), 
(@CGUID+11, @BUNNY2, 571, 1, 1, 4804.116, -640.8143, 160.1202, 2.373648, 120, 0, 0), 
(@CGUID+12, @BUNNY2, 571, 1, 1, 4843.747, -587.0625, 159.7272, 0.9250245, 120, 0, 0), 
(@CGUID+13, @BUNNY2, 571, 1, 1, 4789.024, -611.7726, 160.3697, 0, 120, 0, 0), 
(@CGUID+14, @BUNNY2, 571, 1, 1, 4806.465, -618.2396, 159.5483, 5.445427, 120, 0, 0), 
(@CGUID+15, @BUNNY2, 571, 1, 1, 4845.673, -593.6736, 159.1436, 3.874631, 120, 0, 0), 
(@CGUID+16, @BUNNY2, 571, 1, 1, 4788.442, -639.3229, 162.3155, 1.37881, 120, 0, 0), 
(@CGUID+17, @BUNNY2, 571, 1, 1, 4803.761, -610.7188, 159.545, 4.24115, 120, 0, 0), 
(@CGUID+18, @BUNNY2, 571, 1, 1, 4793.397, -570.8108, 160.8941, 3.682645, 120, 0, 0), 
(@CGUID+19, @BUNNY2, 571, 1, 1, 4809.697, -642.8246, 159.2958, 2.007129, 120, 0, 0), 
(@CGUID+20, @BUNNY2, 571, 1, 1, 4790.142, -624.1771, 159.6133, 0.9773844, 120, 0, 0), 
(@CGUID+21, @BUNNY2, 571, 1, 1, 4810.049, -609.3768, 159.4645, 0, 120, 0, 0), 
(@CGUID+22, @BUNNY2, 571, 1, 1, 4800.022, -618.3073, 159.7944, 3.508112, 120, 0, 0), 
(@CGUID+23, @BUNNY2, 571, 1, 1, 4854.851, -593.2795, 157.3008, 4.625123, 120, 0, 0), 
(@CGUID+24, @BUNNY2, 571, 1, 1, 4759.741, -587.8351, 164.6121, 0, 120, 0, 0), 
(@CGUID+25, @BUNNY2, 571, 1, 1, 4822.641, -641.3472, 157.8503, 3.944444, 120, 0, 0), 
(@CGUID+26, @BUNNY2, 571, 1, 1, 4825.955, -637.9774, 157.6442, 5.340707, 120, 0, 0), 
(@CGUID+27, @BUNNY2, 571, 1, 1, 4809.641, -555.4688, 162.6923, 0.715585, 120, 0, 0), 
(@CGUID+28, @BUNNY2, 571, 1, 1, 4837.163, -576.5104, 160.5024, 5.078908, 120, 0, 0), 
(@CGUID+29, @BUNNY2, 571, 1, 1, 4809.902, -635.441, 159.2038, 1.151917, 120, 0, 0), 
(@CGUID+30, @BUNNY2, 571, 1, 1, 4842.37, -621.6962, 157.5227, 2.879793, 120, 0, 0), 
(@CGUID+31, @BUNNY2, 571, 1, 1, 4817.919, -551.9774, 162.0828, 3.036873, 120, 0, 0), 
(@CGUID+32, @BUNNY2, 571, 1, 1, 4851.638, -585.6007, 158.117, 2.059489, 120, 0, 0), 
(@CGUID+33, @BUNNY2, 571, 1, 1, 4809.817, -614.8125, 159.2753, 2.199115, 120, 0, 0), 
(@CGUID+34, @BUNNY2, 571, 1, 1, 4778.958, -567.7934, 162.0411, 3.647738, 120, 0, 0), 
(@CGUID+35, @BUNNY2, 571, 1, 1, 4763.713, -569.2257, 163.7682, 3.839724, 120, 0, 0), 
(@CGUID+36, @BUNNY2, 571, 1, 1, 4833.483, -635.0799, 157.4865, 4.834562, 120, 0, 0), 
(@CGUID+37, @BUNNY2, 571, 1, 1, 4790.34, -607.0833, 160.2565, 3.525565, 120, 0, 0), 
(@CGUID+38, @BUNNY2, 571, 1, 1, 4814.297, -619.2708, 158.7552, 0.715585, 120, 0, 0), 
(@CGUID+39, @BUNNY2, 571, 1, 1, 4798.659, -602.0208, 159.8221, 2.565634, 120, 0, 0), 
(@CGUID+40, @BUNNY2, 571, 1, 1, 4792.533, -591.684, 160.2542, 4.206244, 120, 0, 0), 
(@CGUID+41, @BUNNY2, 571, 1, 1, 4789.622, -579.4358, 161.0213, 4.520403, 120, 0, 0), 
(@CGUID+42, @BUNNY2, 571, 1, 1, 4797.168, -577.1268, 160.2595, 2.478368, 120, 0, 0), 
(@CGUID+43, @BUNNY2, 571, 1, 1, 4800.604, -547.7327, 164.9199, 0.715585, 120, 0, 0), 
(@CGUID+44, @BUNNY2, 571, 1, 1, 4784.508, -609.382, 161.722, 0, 120, 0, 0), 
(@CGUID+45, @BUNNY2, 571, 1, 1, 4776.268, -596.5695, 162.6325, 2.059489, 120, 0, 0), 
(@CGUID+46, @BUNNY2, 571, 1, 1, 4804.434, -635.9236, 159.8547, 0, 120, 0, 0), 
(@CGUID+47, @BUNNY2, 571, 1, 1, 4772.837, -575.5347, 162.7558, 1.64061, 120, 0, 0), 
(@CGUID+48, @BUNNY2, 571, 1, 1, 4797.148, -583.2952, 159.8615, 3.595378, 120, 0, 0), 
(@CGUID+49, @BUNNY2, 571, 1, 1, 4806.011, -623.4809, 159.5464, 2.740167, 120, 0, 0), 
(@CGUID+50, @BUNNY2, 571, 1, 1, 4848.793, -601.8837, 157.445, 4.258604, 120, 0, 0),
(@CGUID+51, 37826, 571, 1, 1, 4798.7, -639.529, 160.5693, 4.34587, 120, 0, 0),
(@CGUID+52, 37894, 571, 1, 1, 4812.028, -586.2222, 162.5564, 2.6529, 120, 0, 0);

DELETE FROM `waypoints` WHERE `entry`IN(@LICHKING,37952);
INSERT INTO `waypoints`(`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@LICHKING, 1, 4836.363, -586.9203, 161.9295, 'The Lichking'),
(@LICHKING, 2, 4835.365, -586.868, 161.9295, 'The Lichking'),
(@LICHKING, 3, 4834.092, -586.4228, 162.2705, 'The Lichking'),
(@LICHKING, 4, 4828.495, -584.4644, 163.6633, 'The Lichking'),
(@LICHKING, 5, 4826.363, -583.7183, 164.6168, 'The Lichking'),
(@LICHKING, 6, 4825.221, -583.3187, 164.9072, 'The Lichking'),
(@LICHKING, 7, 4823.253, -582.6302, 164.3474, 'The Lichking'),
(@LICHKING, 8, 4821.647, -582.0682, 163.8447, 'The Lichking'),
(@LICHKING, 9, 4818.997, -581.1409, 163.5256, 'The Lichking'),
(@LICHKING, 10, 4814.02, -579.3994, 162.4412, 'The Lichking'),
(@LICHKING, 11, 4814.02, -579.3994, 162.4412, 'The Lichking'),
(37952, 1, 4798.7, -639.529, 160.5693, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 2, 4801.055, -634.4948, 166.6768, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 3, 4797, -618.7934, 171.4821, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 4, 4794.907, -597.2153, 175.0993, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 5, 4796.127, -576.5347, 175.0993, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 6, 4808.424, -570.3871, 175.0993, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 7, 4818.083, -578.1805, 175.0993, 'Lights Vengeance Vehicle Bunny 2'),
(37952, 8, 4812.49, -586.9028, 175.0993, 'Lights Vengeance Vehicle Bunny 2');

DELETE FROM `creature_text` WHERE `entry` IN(37976,37893,@LICHKING);
INSERT INTO `creature_text`(`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(37976, 0, 0, 'Fear not, master. I shall rend the flesh of your enemy!', 12, 0, 100, 0, 0, 17077, 37657, 'Vegard the Unforgiven'),
(37976, 1, 0, 'Master... I have... failed.', 12, 0, 100, 0, 0, 17076, 37656, 'Vegard the Unforgiven'),
(37976, 2, 0, 'It is done, master.', 12, 0, 100, 0, 0, 17075, 37655, 'Vegard the Unforgiven'),
(37893, 0, 0, 'I hear and obey, master...', 12, 0, 100, 0, 0, 17073, 0, 'Vegard the Unforgiven'),
(37893, 1, 0, 'The enemy shall suffer greatly, master!', 12, 0, 100, 0, 0, 17074, 37651, 'Vegard the Unforgiven'),
(@LICHKING, 0, 0, 'So predictable...', 12, 0, 100, 396, 0, 17252, 37506, 'The Lich King'),
(@LICHKING, 1, 0, 'Did you truly expect to fulfill Mograine''s task unopposed?', 12, 0, 100, 6, 0, 17253, 37507, 'The Lich King'),
(@LICHKING, 2, 0, 'You both shall suffer as his father does...', 12, 0, 100, 396, 0, 17254, 37508, 'The Lich King'),
(@LICHKING, 3, 0, '...in eternal unrest!', 12, 0, 100, 0, 0, 17255, 37509, 'The Lich King'),
(@LICHKING, 4, 0, 'Die well, fool.', 12, 0, 100, 397, 0, 17256, 37510, 'The Lich King');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(70590,70595,70614,70643,70612,70790,70792,70743);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 70590, 0, 0, 31, 0, 3, 37826, 0, 0, 0, 0, '', 'Lich King Repel Hammer targets Lights Vengence'),
(13, 1, 70590, 0, 1, 31, 0, 3, 37827, 0, 0, 0, 0, '', 'Lich King Repel Hammer targets Lights Vengeance Vehicle Bunny'),
(13, 1, 70595, 0, 1, 31, 0, 3, @BUNNY, 0, 0, 0, 0, '', 'Lich King Repel Hammer targets Lich King Stun Bunny'),
(13, 1, 70792, 0, 0, 31, 0, 3, 37893, 0, 0, 0, 0, '', 'Kill Vegard targets Vegard the Unforgiven'),
(13, 1, 70614, 0, 0, 31, 0, 3, @BUNNY2, 0, 0, 0, 0, '', 'AoD Special targets AoD Impact Bunny'),
(13, 1, 70790, 0, 0, 31, 0, 3, 37881, 0, 0, 0, 0, '', 'Zap Ghouls targets Wretched Ghoul'),
(13, 1, 70643, 0, 0, 31, 0, 3, 37894, 0, 0, 0, 0, '', 'Zap Vegard Bunny targets Vegard Bunny'),
(13, 1, 70743, 0, 0, 31, 0, 3, @BUNNY2, 0, 0, 0, 0, '', 'AoD Special - Vegard targets AoD Impact Bunny');

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE`entry` IN(201844,201922,201937);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(201844,201922,201937) AND `source_type`=1;

INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(201922,1,0,1,70,0,100,1,2,0,0,0,45,4,4,0,0,0,0,19,38001,0,0,0,0,0,0,"Lights Vengeance - On State Changed - Set Data 4 4 on Lights Vengeance Bunny 2"),
(201922,1,1,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,38001,0,0,0,0,0,0,"Lights Vengeance - On State Changed Set Data 1 1 on Light's Vengence Bunny 2"),
(201844,1,0,1,70,0,100,1,2,0,0,0,45,1,1,0,0,0,0,19,37952,0,0,0,0,0,0,"Lights Vengeance - On State Changed - Set Data on Lights Vengeance Vehicle Bunny 2"),
(201844,1,1,0,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,@BUNNY,0,0,0,0,0,0,"Lights Vengeance - On State Changed Set Data 3 3 on Lich King Stun Bunny"),
(201937,1,1,0,11,0,100,0,0,0,0,0,104,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lights Vengeance - On Spawn - Set Non Selectable"),
(201937,1,2,0,38,0,100,0,1,1,0,0,104,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lights Vengeance - On Data Set - Set Selectable");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=70653;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(70653, 70966, 1, 'Lich King Zap Player - Knockback 50 No Log');
