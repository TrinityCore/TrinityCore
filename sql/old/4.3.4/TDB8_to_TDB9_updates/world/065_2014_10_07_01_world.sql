-- Fix Quest 11501 "News From the East"

SET @WALT      := 24807;
SET @CONSTRUCT := 24852;

UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry`=@WALT;
UPDATE `creature_template` SET `speed_run`=4.285714, `VehicleId`=87, `InhabitType`=4 WHERE `entry`=@CONSTRUCT;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@WALT,@CONSTRUCT);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@WALT,@CONSTRUCT) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CONSTRUCT*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WALT,0,0,1,62,0,100,0,9022,0,0,0,11,49975,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Walt <Explorers'' League> - On gossip option select - Spellcast Iron Rune Construct Taxi'),
(@WALT,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Walt <Explorers'' League> - On gossip option select - Close gossip'),
(@CONSTRUCT,0,0,0,54,0,100,0,0,0,0,0,80,@CONSTRUCT*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Iron Rune Construct - Just summoned - Run script'),
(@CONSTRUCT,0,1,2,40,0,100,1,18,@CONSTRUCT,0,0,1,1,2000,0,0,0,0,1,0,0,0,0,0,0,0, 'Iron Rune Construct - On WP 18 reached - Say line'),
(@CONSTRUCT,0,2,0,61,0,100,0,0,0,0,0,28,44687,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Iron Rune Construct - On WP 18 reached - Remove aura Rocket Jump'),
(@CONSTRUCT,0,3,0,52,0,100,0,1,@CONSTRUCT,0,0,11,44688,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Iron Rune Construct - On text over - Spellcast System Failure'),

(@CONSTRUCT*100,9,0,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Iron Rune Construct script - Say line'),
(@CONSTRUCT*100,9,1,0,0,0,100,0,0,0,0,0,11,44687,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Iron Rune Construct script - Spellcast Rocket Jump'),
(@CONSTRUCT*100,9,2,0,0,0,100,0,2000,2000,0,0,53,1,@CONSTRUCT,0,0,0,0,1,0,0,0,0,0,0,0, 'Iron Rune Construct script - Start WP movement');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=9022 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9022,0,0,'I''m ready to go, Walt.',23929,1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9022;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9022,0,0,28,11501,0,0,0,'','Walt <Explorers'' League> - Show gossip option only if player has completed but not rewarded quest News From the East');

DELETE FROM `creature_text` WHERE `entry`=@CONSTRUCT;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`) VALUES
(@CONSTRUCT,0,0,'Launching.',12,0,100,0,0,0,'Iron Rune Construct',23860),
(@CONSTRUCT,1,0,'System failure in 3... 2...',12,0,100,0,0,0,'Iron Rune Construct',23930);

DELETE FROM `waypoints` WHERE `entry`=@CONSTRUCT;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@CONSTRUCT,1,479.0616,-5941.539,316.96,'Iron Rune Construct'),
(@CONSTRUCT,2,479.2529,-5941.489,365.9878,'Iron Rune Construct'),
(@CONSTRUCT,3,517.0134,-5825.359,365.9878,'Iron Rune Construct'),
(@CONSTRUCT,4,527.9034,-5659.926,365.9878,'Iron Rune Construct'),
(@CONSTRUCT,5,715.0627,-5351.074,365.9878,'Iron Rune Construct'),
(@CONSTRUCT,6,768.4551,-5018.862,365.9878,'Iron Rune Construct'),
(@CONSTRUCT,7,840.6277,-4827.729,365.9878,'Iron Rune Construct'),
(@CONSTRUCT,8,864.8306,-4741.804,365.9878,'Iron Rune Construct'),
(@CONSTRUCT,9,966.0306,-4488.406,365.9878,'Iron Rune Construct'),
(@CONSTRUCT,10,1030.845,-4374.208,346.4599,'Iron Rune Construct'),
(@CONSTRUCT,11,1063.375,-4205.252,346.4599,'Iron Rune Construct'),
(@CONSTRUCT,12,1066.279,-4072.605,289.821,'Iron Rune Construct'),
(@CONSTRUCT,13,1066.46,-3833.815,282.9599,'Iron Rune Construct'),
(@CONSTRUCT,14,1236.65,-3685.513,282.9599,'Iron Rune Construct'),
(@CONSTRUCT,15,1357.56,-3430.121,217.8767,'Iron Rune Construct'),
(@CONSTRUCT,16,1382.808,-3290.728,217.8767,'Iron Rune Construct'),
(@CONSTRUCT,17,1388.928,-3261.844,203.7378,'Iron Rune Construct'),
(@CONSTRUCT,18,1390.475,-3262.215,161.9602,'Iron Rune Construct');

DELETE FROM `spell_scripts` WHERE `id`=44688 AND `command`=14;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(44688,0,0,14,46598,0,0,0,0,0,0),
(44688,0,0,15,44741,1,0,0,0,0,0);
