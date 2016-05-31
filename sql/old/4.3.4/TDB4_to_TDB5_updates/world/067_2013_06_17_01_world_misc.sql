SET @GUID := 21707;

SET @QUEST_INFILTRATING_VOLTARUS := 12661;
SET @QUEST_REUNITED              := 12663;
SET @QUEST_DARK_HORIZON          := 12664;
SET @NPC_DRAKURU                 := 28503;
SET @NPC_STEFAN                  := 28518;
SET @NPC_GOREBAG                 := 28666;
SET @NPC_FLYING_FIEND            := 28669;
SET @NPC_OVERLORD_DRAKURU        := 28717;
SET @NPC_PERSISTENCE             := 29863;

UPDATE `creature_template` SET `speed_walk`=2.4, `speed_run`=0.992063, `AIName`='SmartAI' WHERE `entry`=@NPC_GOREBAG;
UPDATE `creature_template` SET `speed_walk`=4.4, `speed_run`=1.375, `InhabitType`=4, `AIName`='SmartAI', `vehicleId`=127 WHERE `entry`=@NPC_FLYING_FIEND;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_OVERLORD_DRAKURU;
UPDATE `creature_template` SET `unit_flags`=0, `InhabitType`=4 WHERE `entry`=28759;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_DRAKURU;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=@NPC_PERSISTENCE;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_PERSISTENCE;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`) VALUES
(@NPC_PERSISTENCE,50331648,1);

UPDATE `creature` SET `spawndist`=0, `MovementType`=0, `unit_flags`=768 WHERE `guid` IN (103732,103734,103744,103751,103753,103755,103765,103766);

DELETE FROM `creature` WHERE `guid` IN (@GUID,111712);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,28717,571,1,1,0,0,5954.766,-3273.196,406.9324,5.445427,300,0,0,0,0,0,0,0,0);

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5056,5057,5058,5059,5060,5095,5096,5097,5098);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(5056,'SmartTrigger'),
(5057,'SmartTrigger'),
(5058,'SmartTrigger'),
(5059,'SmartTrigger'),
(5060,'SmartTrigger'),
(5095,'SmartTrigger'),
(5096,'SmartTrigger'),
(5097,'SmartTrigger'),
(5098,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@GUID,-100088,-100089,-100090,-100091,-100092,-100093,-100094,-100095,@NPC_DRAKURU,@NPC_GOREBAG,@NPC_FLYING_FIEND,@NPC_PERSISTENCE) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC_STEFAN AND `source_type`=0 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5056,5057,5058,5059,5060,5095,5096,5097,5098) AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_FLYING_FIEND*100,@NPC_OVERLORD_DRAKURU*100,@NPC_PERSISTENCE*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-100095,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-100095,0,1,2,38,1,100,0,0,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100095,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100092,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-100092,0,1,2,38,1,100,0,0,1,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100092,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100088,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-100088,0,1,2,38,1,100,0,0,1,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100088,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-@GUID,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-@GUID,0,1,2,38,1,100,0,0,1,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-@GUID,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100090,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-100090,0,1,2,38,1,100,0,0,1,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100090,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100094,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-100094,0,1,2,38,1,100,0,0,1,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100094,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100089,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-100089,0,1,2,38,1,100,0,0,1,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100089,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100091,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-100091,0,1,2,38,1,100,0,0,1,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100091,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100093,0,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On spawn - Set event phase 1'),
(-100093,0,1,2,38,1,100,0,0,1,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),
(-100093,0,2,0,61,1,100,0,0,0,0,0,80,@NPC_OVERLORD_DRAKURU*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru - On data 0 1 set - Say line'),

(@NPC_DRAKURU,0,0,0,62,0,100,0,9731,1,0,0,11,52224,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Drakuru - On gossip select - Spellcast Kill Credit'),
(@NPC_DRAKURU,0,1,0,62,0,100,0,9731,2,0,0,11,52253,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Drakuru - On gossip select - Spellcast Kill Credit'),
(@NPC_DRAKURU,0,2,0,62,0,100,0,9731,3,0,0,11,52355,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Drakuru - On gossip select - Spellcast Quest Complete Credit Credit'),
(@NPC_DRAKURU,0,3,0,62,0,100,0,9731,4,0,0,11,52680,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Drakuru - On gossip select - Spellcast Kill Credit'),
(@NPC_DRAKURU,0,4,0,62,0,100,0,9731,5,0,0,11,52675,0,0,0,0,0,7,0,0,0,0,0,0,0,'Overlord Drakuru - On gossip select - Spellcast Kill Credit'),

(@NPC_STEFAN,0,4,0,62,0,100,0,9709,1,0,0,11,53810,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stefan Vadu - On gossip select - Spellcast Push Ensorceled Choker'),

(@NPC_GOREBAG,0,0,1,62,0,100,0,9732,0,0,0,11,52194,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gorebag - On gossip select - Spellcast Force Cast Summon Gargoyle'),
(@NPC_GOREBAG,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gorebag - On gossip select - Close gossip'),

(@NPC_FLYING_FIEND,0,0,1,54,0,100,0,0,0,0,0,11,52191,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flying Fiend - Just summoned - Spellcast Scourge Disguise'),
(@NPC_FLYING_FIEND,0,1,0,61,0,100,0,0,0,0,0,80,@NPC_FLYING_FIEND*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Flying Fiend - Just summoned - Run script'),
(@NPC_FLYING_FIEND,0,2,0,40,0,100,0,62,@NPC_FLYING_FIEND,0,0,33,28663,0,0,0,0,0,23,0,0,0,0,0,0,0,'Flying Fiend - On WP 62 reached - Quest Credit'),
(@NPC_FLYING_FIEND,0,3,0,40,0,100,0,63,@NPC_FLYING_FIEND,0,0,11,50630,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flying Fiend - On WP 63 reached - Spellcast Eject All Passengers'),

(@NPC_PERSISTENCE,0,0,0,54,0,100,0,0,0,0,0,80,@NPC_PERSISTENCE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Persistence - Just summoned - Run script'),

(5056,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5056,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,100095,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5056,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,100095,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),
(5057,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5057,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,100092,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5057,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,100092,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),
(5058,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5058,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,100088,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5058,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,100088,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),
(5059,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5059,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,@GUID,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5059,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,@GUID,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),
(5060,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5060,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,100090,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5060,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,100090,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),
(5095,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5095,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,100094,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5095,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,100094,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),
(5096,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5096,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,100089,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5096,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,100089,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),
(5097,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5097,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,100091,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5097,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,100091,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),
(5098,2,0,1,46,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'On trigger - Store targetlist'),
(5098,2,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,100093,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Send targetlist'),
(5098,2,2,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,100093,@NPC_OVERLORD_DRAKURU,0,0,0,0,0,'On trigger - Set data 0 1 Overlord Drakuru'),

(@NPC_FLYING_FIEND*100,9,0,0,0,0,100,0,1700,1700,0,0,53,1,@NPC_FLYING_FIEND,0,0,0,0,1,0,0,0,0,0,0,0,'Flying Fiend script - Start WP movement'),

(@NPC_OVERLORD_DRAKURU*100,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru script - Set event phase 0'),
(@NPC_OVERLORD_DRAKURU*100,9,1,0,0,0,100,0,5000,5000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Overlord Drakuru script - Set event phase 1'),

(@NPC_PERSISTENCE*100,9,0,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Persistence script - Move to position');

DELETE FROM `creature_text` WHERE `entry`=@NPC_OVERLORD_DRAKURU;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_OVERLORD_DRAKURU,0,0,'A portion of this land already be mine, mon, but it only be da beginning!',15,0,100,0,0,0,''),
(@NPC_OVERLORD_DRAKURU,1,0,'Here, da self-righteous crusaders be standin'' in da way of our goal. Dey will fall!',15,0,100,0,0,0,''),
(@NPC_OVERLORD_DRAKURU,2,0,'Dis all soon gonna belong to da Lich King.',15,0,100,0,0,0,''),
(@NPC_OVERLORD_DRAKURU,3,0,'Da Drakkari be destroyin'' their lands! Dey gunna be losin'' dem... soon, mon.',15,0,100,0,0,0,''),
(@NPC_OVERLORD_DRAKURU,4,0,'Ahh, dere be our destiny... Gundrak!',15,0,100,0,0,0,''),
(@NPC_OVERLORD_DRAKURU,5,0,'Study dis place well, mon. Ya gonna be helpin'' me conquer it!',15,0,100,0,0,0,''),
(@NPC_OVERLORD_DRAKURU,6,0,'Ahh yeah, mon! Dere be great glory ta be had here!',15,0,100,0,0,0,''),
(@NPC_OVERLORD_DRAKURU,7,0,'Da Lich King be sharin'' his power wit dem who serve him well, mon.',15,0,100,0,0,0,''),
(@NPC_OVERLORD_DRAKURU,8,0,'Come to me now, $n. I must be speakin'' wit ya.',15,0,100,0,0,0,'');

DELETE FROM `spell_scripts` WHERE `id`=50630;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(50630,0,0,14,46598,0,0,0,0,0,0);

DELETE FROM `spell_script_names` WHERE `spell_id`=55368;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(55368,'spell_q12661_q12669_q12676_q12677_q12713_summon_stefan');

DELETE FROM `waypoints` WHERE `entry`=@NPC_FLYING_FIEND;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@NPC_FLYING_FIEND,1,6063.744,-2094.859,431.5205,''),
(@NPC_FLYING_FIEND,2,5967.444,-2165.715,422.854,''),
(@NPC_FLYING_FIEND,3,5865.666,-2174.974,393.3817,''),
(@NPC_FLYING_FIEND,4,5713.336,-2151.653,373.4649,''),
(@NPC_FLYING_FIEND,5,5558.722,-2128.131,366.1319,''),
(@NPC_FLYING_FIEND,6,5451.114,-2151.127,354.4373,''),
(@NPC_FLYING_FIEND,7,5377.812,-2219.117,359.1318,''),
(@NPC_FLYING_FIEND,8,5366.704,-2360.862,377.715,''),
(@NPC_FLYING_FIEND,9,5435.392,-2533.554,373.9926,''),
(@NPC_FLYING_FIEND,10,5620.228,-2725.159,344.5209,''),
(@NPC_FLYING_FIEND,11,5710.932,-2849.435,341.9651,''),
(@NPC_FLYING_FIEND,12,5793.25,-3015.15,364.3539,''),
(@NPC_FLYING_FIEND,13,5879.358,-3182.915,393.3817,''),
(@NPC_FLYING_FIEND,14,5964.949,-3300.001,393.3817,''),
(@NPC_FLYING_FIEND,15,6115.404,-3420.539,450.5761,''),
(@NPC_FLYING_FIEND,16,6211.264,-3582.169,481.242,''),
(@NPC_FLYING_FIEND,17,6279.312,-3777.027,504.3809,''),
(@NPC_FLYING_FIEND,18,6463.991,-3861.046,546.2137,''),
(@NPC_FLYING_FIEND,19,6575.966,-4030.918,546.2137,''),
(@NPC_FLYING_FIEND,20,6743.058,-4188.865,546.2137,''),
(@NPC_FLYING_FIEND,21,6896.725,-4247.418,577.3526,''),
(@NPC_FLYING_FIEND,22,6999.448,-4298.92,582.9353,''),
(@NPC_FLYING_FIEND,23,7100.701,-4416.983,611.0741,''),
(@NPC_FLYING_FIEND,24,7116.469,-4555.864,660.6572,''),
(@NPC_FLYING_FIEND,25,7057.505,-4669.796,675.6574,''),
(@NPC_FLYING_FIEND,26,6947.491,-4771.33,660.6572,''),
(@NPC_FLYING_FIEND,27,6758.396,-4783.884,626.5463,''),
(@NPC_FLYING_FIEND,28,6650.223,-4701.149,597.2407,''),
(@NPC_FLYING_FIEND,29,6627.306,-4597.556,586.0188,''),
(@NPC_FLYING_FIEND,30,6613.611,-4439.712,592.6573,''),
(@NPC_FLYING_FIEND,31,6526.06,-4289.037,568.1019,''),
(@NPC_FLYING_FIEND,32,6401.896,-4215.937,538.5742,''),
(@NPC_FLYING_FIEND,33,6286.808,-4191.781,518.3241,''),
(@NPC_FLYING_FIEND,34,6204.36,-4223.743,465.0742,''),
(@NPC_FLYING_FIEND,35,6134.582,-4239.067,386.1299,''),
(@NPC_FLYING_FIEND,36,5995.454,-4246.94,428.5185,''),
(@NPC_FLYING_FIEND,37,5909.651,-4251.924,428.5185,''),
(@NPC_FLYING_FIEND,38,5792.211,-4212.291,428.5185,''),
(@NPC_FLYING_FIEND,39,5656.491,-4115.374,428.5185,''),
(@NPC_FLYING_FIEND,40,5549.697,-3983.661,428.5185,''),
(@NPC_FLYING_FIEND,41,5495.661,-3853.954,428.5185,''),
(@NPC_FLYING_FIEND,42,5463.381,-3751.72,428.5185,''),
(@NPC_FLYING_FIEND,43,5430.445,-3669.375,428.5185,''),
(@NPC_FLYING_FIEND,44,5348.065,-3559.13,406.3796,''),
(@NPC_FLYING_FIEND,45,5240.038,-3418.709,381.4073,''),
(@NPC_FLYING_FIEND,46,5160.26,-3335.475,381.4073,''),
(@NPC_FLYING_FIEND,47,5044.02,-3214.565,381.4073,''),
(@NPC_FLYING_FIEND,48,4994.617,-3163.257,381.4073,''),
(@NPC_FLYING_FIEND,49,4929.424,-3062.172,381.4073,''),
(@NPC_FLYING_FIEND,50,4874.155,-2945.799,381.4073,''),
(@NPC_FLYING_FIEND,51,4892.917,-2768.813,381.4073,''),
(@NPC_FLYING_FIEND,52,5019.182,-2627.008,381.4073,''),
(@NPC_FLYING_FIEND,53,5067.444,-2519.115,381.4073,''),
(@NPC_FLYING_FIEND,54,5081.711,-2367.998,381.4073,''),
(@NPC_FLYING_FIEND,55,5152.338,-2120.359,419.4349,''),
(@NPC_FLYING_FIEND,56,5368.514,-1851.122,422.8514,''),
(@NPC_FLYING_FIEND,57,5660.992,-1784.473,360.5462,''),
(@NPC_FLYING_FIEND,58,5851.7,-1800.855,350.1305,''),
(@NPC_FLYING_FIEND,59,6030.714,-1863.997,348.1571,''),
(@NPC_FLYING_FIEND,60,6103.75,-1910.458,354.3242,''),
(@NPC_FLYING_FIEND,61,6163.79,-1944.525,374.379,''),
(@NPC_FLYING_FIEND,62,6183.492,-1976.164,410.129,''),
(@NPC_FLYING_FIEND,63,6184.051,-1991.26,417.3231,'');

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (@NPC_FLYING_FIEND,@NPC_PERSISTENCE);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(@NPC_FLYING_FIEND,@NPC_OVERLORD_DRAKURU,1,1,'Flying Fiend',8,0),
(@NPC_PERSISTENCE,@NPC_STEFAN,0,1,'Persistence',8,0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (@NPC_FLYING_FIEND,@NPC_PERSISTENCE);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@NPC_FLYING_FIEND,46598,0,1),
(@NPC_PERSISTENCE,46598,0,1);

UPDATE `quest_template` SET `PrevQuestId`=12649 WHERE `Id`=@QUEST_REUNITED;
UPDATE `quest_template` SET `PrevQuestId`=12648 WHERE `Id`=@QUEST_DARK_HORIZON;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9731 AND `SourceEntry`=13348;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19  AND `SourceEntry` IN (@QUEST_REUNITED,@QUEST_DARK_HORIZON);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=20  AND `SourceEntry` IN (@QUEST_REUNITED,@QUEST_DARK_HORIZON);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22  AND `SourceEntry` IN (5056,5057,5058,5059,5060,5095,5096,5097,5098);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9731,13348,0,0,8,12238,0,0,1,0,'','Overlord Drakuru - Show different gossip if player has not rewarded quest Cleansing Drak''Tharon'),
(14,9731,13348,0,0,8,12661,0,0,1,0,'','Overlord Drakuru - Show different gossip if player has not rewarded quest Infiltrating Voltarus'),
(19,0,@QUEST_REUNITED,0,0,9,@QUEST_INFILTRATING_VOLTARUS,0,0,0,0,'','Quest acceptable only if player has taken quest Infiltrating Voltarus'),
(19,0,@QUEST_DARK_HORIZON,0,0,9,@QUEST_INFILTRATING_VOLTARUS,0,0,0,0,'','Quest acceptable only if player has taken quest Infiltrating Voltarus'),
(20,0,@QUEST_REUNITED,0,0,9,@QUEST_INFILTRATING_VOLTARUS,0,0,0,0,'','Show quest mark only if player has taken quest Infiltrating Voltarus'),
(20,0,@QUEST_DARK_HORIZON,0,0,9,@QUEST_INFILTRATING_VOLTARUS,0,0,0,0,'','Show quest mark only if player has taken quest Infiltrating Voltarus'),
(22,1,5056,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5056,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon'),
(22,1,5057,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5057,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon'),
(22,1,5058,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5058,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon'),
(22,1,5059,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5059,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon'),
(22,1,5060,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5060,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon'),
(22,1,5095,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5095,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon'),
(22,1,5096,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5096,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon'),
(22,1,5097,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5097,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon'),
(22,1,5098,2,0,9,@QUEST_REUNITED,0,0,0,0,'','SAI triggers only if player has taken quest Reunited'),
(22,1,5098,2,1,9,@QUEST_DARK_HORIZON,0,0,0,0,'','SAI triggers only if player has taken quest Dark Horizon');
