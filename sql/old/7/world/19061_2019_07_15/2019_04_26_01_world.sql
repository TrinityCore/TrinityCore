-- Dave's Industrial Light and Magic Bunny (Medium)(Sessile) SAI ***
-- Dave's Industrial Light and Magic Bunny (Small)(Sessile) SAI ***

UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=40139;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (38821,35845);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-385940,-386736,-384774,-384767,-384775,-384769,-384773,-384734,-384740,-384533) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (388210,388211,388212,388213,388214,388215,388216,388217) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-385940,0,0,0,10,0,100,0,1,2,1000,1000,1,11,75667,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Range - Cast 'Second Flamegate Entry'"),
(-386736,0,0,0,10,0,100,0,1,2,1000,1000,1,11,77815,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Small)(Sessile) - Range - Cast 'Second Flamegate Exit'"),
(-384774,0,0,0,1,0,100,0,5000,25000,30000,35000,0,80,388210,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - OOC - Run Script"),
(-384767,0,0,0,1,0,100,0,5000,25000,30000,35000,0,80,388211,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - OOC - Run Script"),
(-384775,0,0,0,1,0,100,0,5000,25000,30000,35000,0,80,388212,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - OOC - Run Script"),
(-384769,0,0,0,1,0,100,0,5000,25000,30000,35000,0,80,388213,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - OOC - Run Script"),
(-384773,0,0,0,1,0,100,0,5000,25000,30000,35000,0,80,388214,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - OOC - Run Script"),
(-384734,0,0,0,1,0,100,0,5000,25000,30000,35000,0,80,388215,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - OOC - Run Script"),
(-384740,0,0,0,1,0,100,0,5000,25000,30000,35000,0,80,388216,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - OOC - Run Script"),
(-384533,0,0,0,1,0,100,0,5000,25000,30000,35000,0,80,388217,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - OOC - Run Script"),
(388210,9,0,0,0,0,100,0,0,0,0,0,0,85,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Self Cast 'Cosmetic - Storm Cloud Base'"),
(388210,9,1,0,0,0,100,0,5000,5000,0,0,0,86,74425,0,11,39859,30,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Cross Cast to self 'Cosmetic - Lightning Strike'"),
(388210,9,2,0,0,0,100,0,5000,5000,0,0,0,28,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Remove aura 'Cosmetic - Storm Cloud Base'"),
(388211,9,0,0,0,0,100,0,0,0,0,0,0,85,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Self Cast 'Cosmetic - Storm Cloud Base'"),
(388211,9,1,0,0,0,100,0,5000,5000,0,0,0,86,74425,0,11,39859,30,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Cross Cast to self 'Cosmetic - Lightning Strike'"),
(388211,9,2,0,0,0,100,0,5000,5000,0,0,0,28,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Remove aura 'Cosmetic - Storm Cloud Base'"),
(388212,9,0,0,0,0,100,0,0,0,0,0,0,85,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Self Cast 'Cosmetic - Storm Cloud Base'"),
(388212,9,1,0,0,0,100,0,5000,5000,0,0,0,86,74425,0,11,39859,30,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Cross Cast to self 'Cosmetic - Lightning Strike'"),
(388212,9,2,0,0,0,100,0,5000,5000,0,0,0,28,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Remove aura 'Cosmetic - Storm Cloud Base'"),
(388213,9,0,0,0,0,100,0,0,0,0,0,0,85,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Self Cast 'Cosmetic - Storm Cloud Base'"),
(388213,9,1,0,0,0,100,0,5000,5000,0,0,0,86,74425,0,11,39859,30,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Cross Cast to self 'Cosmetic - Lightning Strike'"),
(388213,9,2,0,0,0,100,0,5000,5000,0,0,0,28,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Remove aura 'Cosmetic - Storm Cloud Base'"),
(388214,9,0,0,0,0,100,0,0,0,0,0,0,85,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Self Cast 'Cosmetic - Storm Cloud Base'"),
(388214,9,1,0,0,0,100,0,5000,5000,0,0,0,86,74425,0,11,39859,30,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Cross Cast to self 'Cosmetic - Lightning Strike'"),
(388214,9,2,0,0,0,100,0,5000,5000,0,0,0,28,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Remove aura 'Cosmetic - Storm Cloud Base'"),
(388215,9,0,0,0,0,100,0,0,0,0,0,0,85,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Self Cast 'Cosmetic - Storm Cloud Base'"),
(388215,9,1,0,0,0,100,0,5000,5000,0,0,0,86,74425,0,11,39859,30,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Cross Cast to self 'Cosmetic - Lightning Strike'"),
(388215,9,2,0,0,0,100,0,5000,5000,0,0,0,28,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Remove aura 'Cosmetic - Storm Cloud Base'"),
(388216,9,0,0,0,0,100,0,0,0,0,0,0,85,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Self Cast 'Cosmetic - Storm Cloud Base'"),
(388216,9,1,0,0,0,100,0,5000,5000,0,0,0,86,74425,0,11,39859,30,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Cross Cast to self 'Cosmetic - Lightning Strike'"),
(388216,9,2,0,0,0,100,0,5000,5000,0,0,0,28,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Remove aura 'Cosmetic - Storm Cloud Base'"),
(388217,9,0,0,0,0,100,0,0,0,0,0,0,85,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Self Cast 'Cosmetic - Storm Cloud Base'"),
(388217,9,1,0,0,0,100,0,5000,5000,0,0,0,86,74425,0,11,39859,30,0,1,0,0,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Cross Cast to self 'Cosmetic - Lightning Strike'"),
(388217,9,2,0,0,0,100,0,5000,5000,0,0,0,28,74419,0,0,0,0,0,11,39859,30,0,0,0,0,0,"Dave's Industrial Light and Magic Bunny (Medium)(Sessile) - Script - Target Remove aura 'Cosmetic - Storm Cloud Base'");
-- Remove aura from Dave's Industrial Light and Magic Bunny (Large)(Sessile)
UPDATE `creature_addon` SET `auras` = "" WHERE `guid` IN (384778,384770,384777,384766,384776,384735,384741,384535);

UPDATE `creature` SET `modelid`=31729 WHERE `id`=40190;
DELETE FROM `creature_addon` WHERE `guid`=386736;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (386736,0,0,0,1,0, '70696,74093,74094,74095,74096');
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry` IN (40834, 40837);
UPDATE `creature_template` SET `flags_extra`=128,`InhabitType`=4 WHERE `entry` IN (39600);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (40240,40650,40250);
UPDATE `creature_template` SET `npcflag`=16777216,`unit_flags`=512,`unit_flags2`=67110912,`InhabitType`=4 WHERE `entry` IN (40190);
UPDATE `vehicle_template_accessory` SET `seat_id`=4 WHERE `entry`=40190;
DELETE FROM `creature_template_addon` WHERE `entry`=39637;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (39637,0,0,0,257,0, '');
DELETE FROM `creature` WHERE `guid` IN (384781,385390,385339,385033,385478,385472,385791);
DELETE FROM `creature_addon` WHERE `guid` IN (384781,385390,385339,385033,385478,385472,385791);
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id`=39588;
DELETE FROM `creature_addon` WHERE `guid`=384892;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (384892,0,0,0,1,431, '');
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=40240;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES (40240,75140,3,0);

UPDATE `quest_template` SET `AllowableRaces`=1101 WHERE `ID` IN (25352,25268,27726,25273,25280,25278,25353,25618,25623,25611,27398);
UPDATE `quest_template` SET `AllowableRaces`=690 WHERE `ID` IN (25354,25269,27721,25272,25279,25277,25355,25617,25624,25612,27399);

DELETE FROM `spell_area` WHERE `spell`=74091;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(74091,4979,0,25272,0,0,2,3,64,11);

DELETE FROM `gameobject` WHERE `guid`=237982;

DELETE FROM `creature_questender` WHERE `id` IN (39622) AND `quest` IN (25273,25353);
INSERT INTO `creature_questender` (`id`,`quest`) VALUES
(39622,25273),(39622,25353);
UPDATE `creature_template` SET `unit_flags`=8,`VehicleId`=1227 WHERE `entry`=39622;


DELETE FROM `spell_target_position` WHERE `ID`=74077;

DELETE FROM `gameobject` WHERE `guid`=237985;
DELETE FROM `gameobject_addon` WHERE `guid`=237985;

DELETE FROM `spell_scripts` WHERE `id`=74083;
INSERT INTO `spell_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(74083,0,15,74077,1,0,0,0,0,0);

-- Fix Lycanthoth spawn location
UPDATE `event_scripts` SET `x`=5134.321,`y`=-2309.696,`z`=1279.615,`o`=0.6539252 WHERE `id`=24005;

-- Lycanthoth SAI
SET @ENTRY := 39446;
UPDATE `creature_template` SET `mingold`=0, `maxgold`=0,`AIName`="SmartAI" WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`='74060 74061' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,116,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lycanthoth - Just Summoned - Despawn after 3 sec"),
(@ENTRY,0,1,0,54,0,100,1,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lycanthoth - Just Summoned - Attack Summoner"),
(@ENTRY,0,2,0,54,0,100,1,0,0,0,0,50,202661,0,0,0,0,0,8,0,0,0,5140.518,-2305.198,1279.25,1.221729,"Lycanthoth - Just Summoned - Summon Gameobject"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lycanthoth - Aggro - Say 0"),
(@ENTRY,0,4,0,2,0,100,1,1,49,0,0,11,37776,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lycanthoth - Hp below 50% - Cast 'Blood Howl'"),
(@ENTRY,0,5,0,2,0,100,1,1,49,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lycanthoth - Hp below 50% - Say 1"),
(@ENTRY,0,6,0,6,0,100,1,0,0,0,0,11,74084,2,0,0,0,0,7,0,0,0,0,0,0,0,"Lycanthoth - Death - Cast 'Force Player to Summon Wolf God'"),
(@ENTRY,0,7,0,6,0,100,1,0,0,0,0,4,21902,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lycanthoth - Death - Play Sound");

DELETE FROM `creature_text` WHERE `CreatureID`=39446;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(39446, 0, 0, 'Log''loth og shandai, mortal. Only death is eternal. You will be undone.', 12, 0, 100, 0, 0, 21900, 39639, 'Lycanthoth Aggro'),
(39446, 1, 0, 'Fate subjugates faith, mortal. Your prayers are meaningless here.', 12, 0, 100, 0, 0, 21901, 39640, 'Lycanthoth 50% HP');

-- Captain Saynna Stormrunner SAI
SET @ENTRY := 40139;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,25325,0,0,0,11,74895,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captain Saynna Stormrunner - Quest accepted - Cast 'Forcecast Summon Fandral'");

UPDATE `creature` SET `PhaseId`=0, `PhaseGroup`=448 WHERE `guid`=384142;

-- Pathing for Goldrinn Defender Entry: 39637 'TDB FORMAT'
SET @NPC := 385246;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5029.46,`position_y`=-2057.81,`position_z`=1148.975 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5029.46,-2057.81,1148.975,0,0,0,0,100,0),
(@PATH,2,5024.99,-2060.07,1148.975,0,0,0,0,100,0),
(@PATH,3,5020.8,-2061.3,1148.975,0,0,0,0,100,0),
(@PATH,4,5024.99,-2060.07,1148.975,0,0,0,0,100,0),
(@PATH,5,5029.46,-2057.81,1148.975,0,0,0,0,100,0),
(@PATH,6,5033.73,-2055.75,1148.975,0,0,0,0,100,0),
(@PATH,7,5036.76,-2054.16,1148.975,0,0,0,0,100,0),
(@PATH,8,5033.73,-2055.75,1148.975,0,0,0,0,100,0);

-- Pathing for Goldrinn Defender Entry: 39637 'TDB FORMAT' 
SET @NPC := 385248;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5040.6,`position_y`=-2035.3,`position_z`=1148.975 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5040.6,-2035.3,1148.975,0,0,0,0,100,0),
(@PATH,2,5030.91,-2036.05,1148.975,0,0,0,0,100,0),
(@PATH,3,5021.19,-2040.07,1148.975,0,0,0,0,100,0),
(@PATH,4,5017.68,-2042.73,1148.975,0,0,0,0,100,0),
(@PATH,5,5025.12,-2038.51,1148.975,0,0,0,0,100,0),
(@PATH,6,5030.91,-2036.05,1148.975,0,0,0,0,100,0),
(@PATH,7,5036.69,-2034.98,1148.975,0,0,0,0,100,0);

-- Pathing for Goldrinn Defender Entry: 39637 'TDB FORMAT' 
SET @NPC := 384772;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5352.994,`position_y`=-2182.122,`position_z`=1281.864 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5352.994,-2182.122,1281.864,0,0,0,0,100,0),
(@PATH,2,5359.195,-2183.47,1286.33,0,0,0,0,100,0),
(@PATH,3,5363.801,-2182.422,1289.738,0,0,0,0,100,0),
(@PATH,4,5367.083,-2182.677,1291.274,0,21000,0,3847720,100,0),
(@PATH,5,5359.329,-2183.13,1286.5,0,0,0,0,100,0),
(@PATH,6,5356.353,-2182.75,1284.551,0,0,0,0,100,0),
(@PATH,7,5351.456,-2179.042,1280.659,0,0,0,0,100,0),
(@PATH,8,5350.095,-2172.814,1279.973,3.159046,28000,0,0,100,0);
DELETE FROM `waypoint_scripts` WHERE `id`=3847720;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES
(3847720,4,4,68,8,0,0,0,0,0,954),(3847720,15,5,68,8,0,0,0,0,0,955);

-- Pathing for Goldrinn Defender Entry: 39637 'TDB FORMAT' 
SET @NPC := 384894;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5338.754,`position_y`=-2125.771,`position_z`=1280.634 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5338.754,-2125.771,1280.634,0,0,0,0,100,0),
(@PATH,2,5338.994,-2131.273,1280.634,0,0,0,0,100,0),
(@PATH,3,5337.473,-2132.144,1280.634,0,20000,0,0,100,0),
(@PATH,4,5339.748,-2128.094,1280.634,0,0,0,0,100,0),
(@PATH,5,5339.636,-2122.615,1280.634,0,0,0,0,100,0),
(@PATH,6,5340.385,-2118.509,1280.634,0,0,0,0,100,0),
(@PATH,7,5338.963,-2116.507,1280.634,0,0,0,0,100,0),
(@PATH,8,5338.963,-2116.507,1280.634,3.124139,23000,0,0,100,0);

-- Pathing for Goldrinn Defender Entry: 39637 'TDB FORMAT' 
SET @NPC := 385248;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5349.028,`position_y`=-2159.953,`position_z`=1277.905 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5349.028,-2159.953,1277.905,0,0,0,0,100,0),
(@PATH,2,5353.612,-2153.771,1280.535,0,0,0,0,100,0),
(@PATH,3,5356.823,-2150.359,1280.82,0,0,0,0,100,0),
(@PATH,4,5356.823,-2150.359,1280.82,3.665191,30000,0,0,100,0),
(@PATH,5,5349.887,-2157.385,1278.499,0,0,0,0,100,0),
(@PATH,6,5346.077,-2159.991,1276.248,0,0,0,0,100,0),
(@PATH,7,5341.911,-2162.766,1273.801,0,0,0,0,100,0),
(@PATH,8,5336.247,-2167.521,1271.412,0,0,0,0,100,0),
(@PATH,9,5334,-2172.441,1271.104,0,18000,0,0,100,0),
(@PATH,10,5343.153,-2163.199,1274.301,0,0,0,0,100,0);

-- Pathing for Hovel Brute Entry: 39642 'TDB FORMAT' 
SET @NPC := 385371;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `equipment_id`=2,`spawndist`=0,`MovementType`=2,`position_x`=5166.781,`position_y`=-2143.323,`position_z`=1277.952 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5166.781,-2143.323,1277.952,0,0,0,0,100,0),
(@PATH,2,5160.98,-2141.422,1277.969,0,11000,0,3853710,100,0), -- wait 4 Emote ID: 381 (OneShotLoot) wait 4 Emote ID: 381 (OneShotLoot) wait 3
(@PATH,3,5172.483,-2144.684,1277.952,0,0,0,0,100,0),
(@PATH,4,5176.522,-2149.427,1277.952,0,0,0,0,100,0),
(@PATH,5,5177.647,-2153.807,1277.952,0,18000,0,3853711,100,0),
(@PATH,6,5172.174,-2146.021,1277.952,0,0,0,0,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (3853710,3853711);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES
(3853710,4,1,381,0,0,0,0,0,0,956),(3853710,8,1,381,0,0,0,0,0,0,957),
(3853711,3,2,117,1,0,0,0,0,0,958),(3853711,7,1,233,1,0,0,0,0,0,959),(3853711,13,1,0,1,0,0,0,0,0,960),(3853711,18,2,117,0,0,0,0,0,0,961);

-- Pathing for Hovel Brute Entry: 39642 'TDB FORMAT' 
SET @NPC := 384825; 
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5166.486,`position_y`=-2121.313,`position_z`=1277.969,`orientation`=2.565634 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5166.486,-2121.313,1277.969,2.443461,15000,0,3848250,100,0),
(@PATH,2,5165.997,-2128.097,1277.969,0,0,0,0,100,0),
(@PATH,3,5160.565,-2128.458,1277.969,0,15000,0,3848250,100,0),
(@PATH,4,5169.286,-2126.177,1277.884,0,0,0,0,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (3848250);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES
(3848250,5,1,54,0,0,0,0,0,0,962),(3848250,7,1,54,0,0,0,0,0,0,963),(3848250,9,1,54,0,0,0,0,0,0,964);

-- Pathing for Hovel Brute Entry: 39642 'TDB FORMAT' 
SET @NPC := 384832;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5194.97,`position_y`=-2136.91,`position_z`=1270.598 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5194.97,-2136.91,1270.598,0,0,0,0,100,0),
(@PATH,2,5196.738,-2141.149,1269.484,0,15000,0,0,100,0),
(@PATH,3,5200.823,-2149.858,1267.478,0,0,0,0,100,0),
(@PATH,4,5205.227,-2153.849,1265.438,0,0,0,0,100,0),
(@PATH,5,5209.253,-2156.948,1263.483,0,12000,0,0,100,0),
(@PATH,6,5199.896,-2147.983,1267.906,0,0,0,0,100,0),
(@PATH,7,5198.407,-2143.964,1268.746,0,0,0,0,100,0),
(@PATH,8,5195.907,-2132.566,1270.825,0,0,0,0,100,0),
(@PATH,9,5194.737,-2125.478,1272.296,0,16000,0,0,100,0);

-- Pathing for Twilight Stormcaller Entry: 39843 'TDB FORMAT' 
SET @NPC := 385286;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5213.397,`position_y`=-1968.066,`position_z`=1365.574 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5213.397,-1968.066,1365.574,0,0,0,0,100,0),
(@PATH,2,5208.937,-1977.262,1365.574,0,0,0,0,100,0),
(@PATH,3,5213.397,-1968.066,1365.574,0,0,0,0,100,0),
(@PATH,4,5213.714,-1958.587,1365.673,0,0,0,0,100,0),
(@PATH,5,5213.311,-1949.323,1365.506,0,0,0,0,100,0),
(@PATH,6,5213.684,-1940.509,1365.631,0,0,0,0,100,0),
(@PATH,7,5219.163,-1936.24,1365.733,0,0,0,0,100,0),
(@PATH,8,5227.706,-1933.649,1364.482,0,0,0,0,100,0),
(@PATH,9,5219.163,-1936.24,1365.733,0,0,0,0,100,0),
(@PATH,10,5213.684,-1940.509,1365.631,0,0,0,0,100,0),
(@PATH,11,5213.311,-1949.323,1365.506,0,0,0,0,100,0),
(@PATH,12,5213.714,-1958.587,1365.673,0,0,0,0,100,0);

-- Pathing for Twilight Stormcaller Entry: 39843 'TDB FORMAT' 
SET @NPC := 385086;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5186.012,`position_y`=-2002.101,`position_z`=1365.646 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5186.012,-2002.101,1365.646,0,0,0,0,100,0),
(@PATH,2,5178.724,-2009.715,1365.646,0,0,0,0,100,0),
(@PATH,3,5171.741,-2015.064,1365.646,0,0,0,0,100,0),
(@PATH,4,5164.22,-2018.594,1365.648,0,0,0,0,100,0),
(@PATH,5,5159.299,-2019.639,1365.648,0,0,0,0,100,0),
(@PATH,6,5164.22,-2018.594,1365.648,0,0,0,0,100,0),
(@PATH,7,5171.741,-2015.064,1365.646,0,0,0,0,100,0),
(@PATH,8,5178.724,-2009.715,1365.646,0,0,0,0,100,0),
(@PATH,9,5186.012,-2002.101,1365.646,0,0,0,0,100,0),
(@PATH,10,5192.807,-1994.3,1365.648,0,0,0,0,100,0),
(@PATH,11,5186.012,-2002.101,1365.646,0,0,0,0,100,0);

-- Pathing for Twilight Stormcaller Entry: 39843 'TDB FORMAT' 
SET @NPC := 386097;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=5083.972,`position_y`=-2175.635,`position_z`=1382.04 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,5083.972,-2175.635,1382.04,5.637414,12000,0,3860970,100,0),
(@PATH,2,5083.239,-2173.729,1382.011,0,0,0,0,100,0),
(@PATH,3,5085.739,-2171.979,1382.011,0,0,0,0,100,0),
(@PATH,4,5090.989,-2171.979,1381.761,0,0,0,0,100,0),
(@PATH,5,5094.239,-2174.229,1382.011,0,0,0,0,100,0),
(@PATH,6,5093.507,-2176.323,1381.982,3.124139,12000,0,3860971,100,0),
(@PATH,7,5094.489,-2173.979,1382.011,0,0,0,0,100,0),
(@PATH,8,5090.239,-2170.479,1381.761,0,0,0,0,100,0),
(@PATH,9,5085.239,-2170.979,1381.761,0,0,0,0,100,0),
(@PATH,10,5083.239,-2173.479,1382.011,0,0,0,0,100,0);
DELETE FROM `waypoint_scripts` WHERE `id` IN (3860970,3860971);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES
(3860970,4,4,68,8,0,0,0,0,0,966),(3860970,8,5,68,8,0,0,0,0,0,967),
(3860971,3,1,432,0,0,0,0,0,0,968),(3860971,6,1,60,0,0,0,0,0,0,969),(3860971,9,1,5,0,0,0,0,0,0,970);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386768;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4520.843,`position_y`=-2415.413,`position_z`=1136.632 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4520.843,-2415.413,1136.632,0,0,0,0,100,0),
(@PATH,2,4510.958,-2425.653,1134.929,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386581;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4527.24,`position_y`=-1933.665,`position_z`=1222.378 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4527.24,-1933.665,1222.378,0,0,0,0,100,0),
(@PATH,2,4519.055,-1927.365,1225.969,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386539;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4747.391,`position_y`=-1613.127,`position_z`=1301.171 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4747.391,-1613.127,1301.171,0,0,0,0,100,0),
(@PATH,2,4735.158,-1610.667,1301.631,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386658;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4682.988,`position_y`=-2330.377,`position_z`=1173.957 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4682.988,-2330.377,1173.957,0,0,0,0,100,0),
(@PATH,2,4690.177,-2342.637,1172.034,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386543;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4682.21,`position_y`=-1631.776,`position_z`=1290.973 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4682.21,-1631.776,1290.973,0,0,0,0,100,0),
(@PATH,2,4672.656,-1634.052,1290.015,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386674;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4656.105,`position_y`=-2392.976,`position_z`=1159.272 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4656.105,-2392.976,1159.272,0,0,0,0,100,0),
(@PATH,2,4669.66,-2398.333,1156.774,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386625;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4500.909,`position_y`=-2142.785,`position_z`=1184.245 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4500.909,-2142.785,1184.245,0,0,0,0,100,0),
(@PATH,2,4496.703,-2133.859,1186.32,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386554;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4595.052,`position_y`=-1731.286,`position_z`=1274.395 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4595.052,-1731.286,1274.395,0,0,0,0,100,0),
(@PATH,2,4590.37,-1731.879,1273.904,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386547;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4673.484,`position_y`=-1685.705,`position_z`=1279.83 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4673.484,-1685.705,1279.83,0,0,0,0,100,0),
(@PATH,2,4675.502,-1680.677,1280.695,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386587;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4457.581,`position_y`=-1936.37,`position_z`=1233.196 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4457.581,-1936.37,1233.196,0,0,0,0,100,0),
(@PATH,2,4449.836,-1942.502,1233.046,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386664;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4722.851,`position_y`=-2397.524,`position_z`=1172.824 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4722.851,-2397.524,1172.824,0,0,0,0,100,0),
(@PATH,2,4717.418,-2388.906,1172.696,0,0,0,0,100,0);

-- Pathing for Dave's Industrial Light and Magic Bunny (Small) Entry: 34527 'TDB FORMAT' 
SET @NPC := 386707;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=4720.998,`position_y`=-2560.922,`position_z`=1153.353 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '74096');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,4720.998,-2560.922,1153.353,0,0,0,0,100,0),
(@PATH,2,4710.188,-2555.892,1151.776,0,0,0,0,100,0);
