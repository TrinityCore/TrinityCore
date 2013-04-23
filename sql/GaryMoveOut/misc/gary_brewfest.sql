/*Dark Iron Attack

23808 - [DND] Brewfest Keg Move to Target
24766 - [DND] Brewfest Face Me Bunny
24109 - [DND] Brewfest Target Dummy Move To Target
23894 - [DND] Brewfest Dark Iron Spawn Bunny
23703 - [DND] Brewfest Dark Iron Event Generator

188508 - Dark Iron Mole Machine (Minion Summoner)

42676 - Holiday - Brewfest - Dark Iron Knockback Aura

Full horde video	http://www.wegame.com/watch/world-of-warcraft-brewfest-dailies-part-1-horde-dark-iron-attack-part-3/
Proof of despawn	http://www.wegame.com/watch/brewfest-after-a-dark-iron-dwarf-attack/

*/
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Misc.
DELETE FROM `gameobject` WHERE `id`=186881; -- Dark Iron Sabotage Plans were used for the event in 2007
DELETE FROM `game_event_gameobject` WHERE `guid` IN (11140,18015); -- Dark Iron Sabotage Plans
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|256 WHERE `entry`=23706; -- Gordok Festive Keg
UPDATE `creature_model_info` SET `bounding_radius`=0.9,`combat_reach`=1.8,`gender`=2 WHERE `modelid`=24860; -- Gordok Festive Keg
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=1,`mount`=0,`emote`=0,`auras`=NULL WHERE `entry` IN (23702,23700,23706,24373,24372); -- Festive Kegs

-- Brewfest - Attack Keg can only target kegs
DELETE FROM `conditions` WHERE `SourceEntry` IN (42393) AND `ConditionValue2` IN (23702,23700,23706,24373,24372);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,42393,0,18,1,23702,0,0,'',"Spell Brewfest - Attack Keg can only be cast at Thunderbrew Festive Keg"),
(13,0,42393,0,18,1,23700,0,0,'',"Spell Brewfest - Attack Keg can only be cast at Barleybrew Festive Keg"),
(13,0,42393,0,18,1,23706,0,0,'',"Spell Brewfest - Attack Keg can only be cast at Gordok Festive Keg"),
(13,0,42393,0,18,1,24373,0,0,'',"Spell Brewfest - Attack Keg can only be cast at T'chalis's Festive Keg"),
(13,0,42393,0,18,1,24372,0,0,'',"Spell Brewfest - Attack Keg can only be cast at Drohn's Festive Keg");

-- Holiday - Brewfest - Dark Iron Knockback Target Test
-- DELETE FROM `spell_script_names` WHERE `spell_id`=42674;
-- INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
-- (42674,'spell_gen_dark_iron_knockback_test');

-- Brewfest - Dark Iron Knockback
DELETE FROM `conditions` WHERE `SourceEntry`=42299 AND `ConditionValue2`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,42299,0,18,1,0,0,0,'',"Spell Brewfest - Dark Iron Knockback can only be cast at players");

SET @GUID := 240240;
-- Spawn [DND] Brewfest Dark Iron Event Generator and Dark Iron Herald
DELETE FROM `creature` WHERE `id` IN (23703,24536) AND `guid` IN (@GUID+0,@GUID+1,@GUID+2,@GUID+3);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,23703,0,1,1,0,0,-5152.3,-603.529,398.356,2.50732,300,0,0,37800,0,0,0,0,0),
(@GUID+2,24536,0,1,1,0,0,-5152.3,-603.529,398.356,2.50732,300,0,0,37800,0,0,0,0,0),
(@GUID+3,23703,1,1,1,0,0,1197.6,-4293.571,21.243,5.20232,300,0,0,37800,0,0,0,0,0),
(@GUID+1,24536,1,1,1,0,0,1197.6,-4293.571,21.243,5.20232,300,0,0,37800,0,0,0,0,0);

-- Fix the equipment templates of the brewers
DELETE FROM `creature_equip_template` WHERE `entry`=2478;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(2478,33161,33161,0);

-- Update the templates for the Brewmaidens (the golden mugs)
UPDATE `creature` SET `equipment_id`=2478 WHERE `id` IN (23684,23683,23685,24493,24492);

-- Make the Event Generator spawns only spawn if Brewfest is active
DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid` IN (@GUID+0,@GUID+1,@GUID+2,@GUID+3);
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(24,@GUID+0),(24,@GUID+2),(24,@GUID+1),(24,@GUID+3);

-- Make the Dark Iron Mole Machine Wreckage give the quests
DELETE FROM `gameobject_questrelation` WHERE `id` IN (189990,189989);
INSERT INTO `gameobject_questrelation` (`id`,`quest`) VALUES
(189990,12192), -- Horde
(189989,12020); -- Alliance

-- Add aura 'Brewfest - Dark Iron Attack - Keg Marker' to Thunderbrew/Barleybrew/Gordok/T'chalis's/Drohn's Festive Keg
DELETE FROM `creature_template_addon` WHERE `entry` IN (23702,23700,23706,24373,24372);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(23702,0,0,0,0,'42761'),(23700,0,0,0,0,'42761'),(23706,0,0,0,0,'42761'),
(24373,0,0,0,0,'42761'),(24372,0,0,0,0,'42761');

-- Brewfest Chick Chucks Mug should also add an Complimentary Brewfest Sampler
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=42535 AND `spell_effect`=42518;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(42535,42518,1,'Brewfest Chick Chucks Mug should also add an Complimentary Brewfest Sampler');

-- Add Dark Iron Guzzler's equipment template (taken from sniff)
DELETE FROM `creature_equip_template` WHERE `entry`=2477;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(2477,33125,0,0);

-- Add aura 'Holiday - Brewfest - Dark Iron Knockback Target Test' to Dark Iron Guzzler
DELETE FROM `creature_template_addon` WHERE `entry`=23709;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(23709,0,0,0,0,'42676');

-- Drunken Master & Dark Iron Retreat
DELETE FROM `conditions` WHERE `SourceEntry` IN (42695,42794,42341) AND `ConditionValue2` IN (23709);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,42695,0,18,1,23709,0,0,'',"Spell Holiday - Brewfest - Dark Iron Knock-down Power-up can only be cast at Dark Iron Guzzler"),
(13,0,42794,0,18,1,23709,0,0,'',"Spell Holiday - Brewfest - Random Mug Fling can only be cast at Dark Iron Guzzler"),
(13,0,42341,0,18,1,23709,0,0,'',"Spell Dark Iron Retreat can only be cast at Dark Iron Guzzler");

-- Insert missing object template for spell Drunken Master's - it's a trap and these do not come from sniffs, so WDBVerified on 1
DELETE FROM `gameobject_template` WHERE `entry`=186471;
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`IconName`,`castBarCaption`,`unk1`,`faction`,`flags`,`size`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`data0`,`data1`,`data2`,`data3`,`data4`,`data5`,`data6`,`data7`,`data8`,`data9`,`data10`,`data11`,`data12`,`data13`,`data14`,`data15`,`data16`,`data17`,`data18`,`data19`,`data20`,`data21`,`data22`,`data23`,`AIName`,`ScriptName`,`WDBVerified`) VALUES
(186471,6,6371,'Super Brew Stein','','','',35,0,3,0,0,0,0,0,0,0,0,8,42696,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','',1);

-- Insert missing triggered objectsummons - they dissapear through another object which makes the despawn animation
DELETE FROM `gameobject_template` WHERE `entry` IN (202401,186462);
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`IconName`,`castBarCaption`,`unk1`,`faction`,`flags`,`size`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`data0`,`data1`,`data2`,`data3`,`data4`,`data5`,`data6`,`data7`,`data8`,`data9`,`data10`,`data11`,`data12`,`data13`,`data14`,`data15`,`data16`,`data17`,`data18`,`data19`,`data20`,`data21`,`data22`,`data23`,`AIName`,`ScriptName`,`WDBVerified`) VALUES
(202401,1,7510,'Dark Iron Mole Machine','','','',0,0,1,0,0,0,0,0,0,1,95,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','',1), -- Retreat and big version
(186462,1,7510,'Dark Iron Mole Machine','','','',0,0,0.6,0,0,0,0,0,0,1,95,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','',1);

-- [Q] [A/H] This One Time, When I Was Drunk...
-- Shouldn't be related to Chug and Chuck! quest at all
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `id`=12020;

-- [DND] Brewfest Dark Iron Event Generator SAI
SET @ENTRY := 23703;
SET @SPELL_RETREAT := 42341;
SET @SPELL_MOLE_MACHINE_SPAWN := 73074;
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@GUID+0),-(@GUID+3),@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2,@ENTRY*100+3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- DUN MOROGH
(-(@GUID+0),0,0,1,1,0,100,0,1800000,1800000,1800000,1800000,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - Out of Combat - Run Script"),
(-(@GUID+0),0,1,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,24536,100,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - Out of Combat - Set Data Dark Iron Herald"),
(-(@GUID+0),0,2,0,38,0,100,0,5,5,0,0,80,@ENTRY*100+3,0,2,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Data Set - Run Script"),
(@ENTRY*100,9,1,0,0,0,100,0,10000,10000,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5168.79,-597.261,398.101,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"), -- Time this to give the Brewfest Revelers some time to run away
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5154.99,-589.22,397.346,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5168.34,-585.515,397.688,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5160.86,-606.37,398.063,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,5,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5163.08,-592.054,398.022,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,6,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5160.24,-579.148,397.18,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,7,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5172.88,-576.9,397.339,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,8,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5180.1,-583.465,397.775,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,9,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5176.84,-592.674,397.622,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,10,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5172.06,-606.161,397.352,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,11,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5162.5,-614.447,397.741,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,12,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5153.05,-618.085,398.125,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,13,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5148.92,-607.028,398.537,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,14,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5155.28,-598.89,398.092,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,15,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5146.97,-591.708,397.372,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,16,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5136.8,-598.046,397.426,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,17,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5162.125000,-599.126953,398.169250,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,18,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5155.227051,-611.064087,398.384796,5.58,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,19,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5172.685547,-617.705200,397.190582,0.80,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,20,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5165.557129,-602.531067,397.959229,2.48,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,21,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5162.540039,-596.897278,398.152252,5.58,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,22,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5171.027832,-590.153503,397.964874,0.80,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,23,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5177.630371,-600.892029,397.344421,2.48,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,24,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5175.105957,-585.409302,397.801575,5.58,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,25,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5160.901367,-585.973755,397.494049,0.80,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,26,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5149.727051,-598.186523,398.000702,2.48,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,27,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5140.413574,-606.157715,398.110840,0.80,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,28,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5148.443359,-613.181458,398.464478,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,29,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5139.434570,-612.224487,398.017578,5.58,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,30,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5160.227051,-622.226868,397.487183,2.53,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,31,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5165.484863,-608.644226,397.621552,3.85,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,32,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5154.422852,-605.168152,398.364655,1.23,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,33,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5156.091309,-594.039612,397.730194,0.32,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,34,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5151.526855,-593.310730,397.529968,0.32,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,35,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5143.669922,-603.026917,398.192719,0.80,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,36,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5142.348633,-595.296265,397.526245,3.32,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,37,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5154.107910,-582.890503,397.179108,6.32,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,38,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5166.127930,-578.236206,397.194489,4.12,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,39,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5182.114746,-589.290283,397.433838,3.21,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,40,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5173.672363,-598.698364,397.764160,5.21,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,41,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5170.576660,-612.272156,397.254028,1.12,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,42,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5157.810059,-615.534058,398.061340,3.21,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,43,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5170.45,-619.995,397.201,5.03293,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,44,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5178.76,-596.961,397.377,1.7539,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,45,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5156.98,-580.003,397.177,0.120272,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,46,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5179.38,-586.717,397.709,4.49259,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,47,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5165.36,-587.727,397.835,1.67301,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,48,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5153.73,-615.453,398.279,0.856196,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,49,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5152.15,-595.603,397.77,4.901,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,50,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5162.17,-574.909,397.177,5.99506,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,51,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5168.06,-574.334,397.179,4.72586,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,52,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5175.6,-580.338,397.672,1.99189,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,53,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5173.89,-589.037,397.868,2.61942,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,54,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5174.16,-610.4,397.19,1.88822,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,55,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5168.59,-608.303,397.421,3.79124,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,56,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5139.81,-601.143,397.845,5.16019,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,57,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5148.49,-602.523,398.322,5.16019,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,58,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5150.64,-587.595,397.217,5.8317,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,59,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5164.38,-582.486,397.347,5.68012,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,60,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5170.38,-581.177,397.41,1.41776,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,61,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,-5172.32,-594.611,397.974,1.78454,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100,9,62,0,0,0,100,0,0,0,0,0,12,23702,1,300000,0,0,0,8,0,0,0,-5159.85,-632.055,397.179,1.46772,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon Thunderbrew Festive Keg"),
(@ENTRY*100,9,63,0,0,0,100,0,0,0,0,0,12,23706,1,300000,0,0,0,8,0,0,0,-5146.283691,-576.265930,397.176514,0.09009,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon Gordok Festive Keg"),
(@ENTRY*100,9,64,0,0,0,100,0,0,0,0,0,12,23700,1,300000,0,0,0,8,0,0,0,-5186.539551,-599.753662,397.176453,0.024872,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon Barleybrew Festive Keg"),
(@ENTRY*100,9,66,0,0,0,100,0,59000,79000,90000,90000,45,2,2,0,0,0,0,11,23685,50,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Gordok Brew Barker"),
(@ENTRY*100,9,67,0,0,0,100,0,10000,29000,90000,90000,45,3,3,0,0,0,0,11,23683,50,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Maeve Barleybrew"),
(@ENTRY*100,9,68,0,0,0,100,0,3000,11000,90000,90000,45,4,4,0,0,0,0,11,23684,50,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Ita Thunderbrew"),

-- DUROTAR
(-(@GUID+3),0,0,1,1,0,100,0,1800000,1800000,1800000,1800000,80,@ENTRY*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - Out of Combat - Run Script"),
(-(@GUID+3),0,1,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,24536,100,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - Out of Combat - Set Data Dark Iron Herald"),
(-(@GUID+3),0,2,0,38,0,100,0,5,5,0,0,80,@ENTRY*100+2,0,2,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Data Set - Run Script"),
(@ENTRY*100+1,9,2,0,0,0,100,0,10000,10000,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1204.37,-4279.81,21.1922,3.84123,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,3,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1198.54,-4276.24,21.1922,0.617165,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,4,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1204.52,-4282.65,21.1922,3.73127,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,5,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1195.59,-4282.27,21.1928,0.42867,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,6,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1190.5,-4279.52,21.1916,5.64764,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,7,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1186.5,-4281.45,21.1916,0.526844,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,8,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1182.72,-4285.52,21.1916,0.994156,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,9,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1198.15,-4286.48,21.197,3.531,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,10,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1191.91,-4286.18,21.194,3.32287,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,11,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1188.62,-4289.83,21.1958,4.45777,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,12,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1182.62,-4292.68,21.1755,4.34388,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,13,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1185.53,-4297.08,21.2927,0.456159,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,14,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1189.84,-4296.02,21.3273,6.2524,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,15,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1194.04,-4291.03,21.2161,1.28475,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,16,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1196.33,-4295.06,21.2993,6.05997,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,17,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1200.13,-4290.59,21.2003,0.797805,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,18,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1203.6,-4287.35,21.1943,1.36329,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,19,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1199.9,-4281.51,21.1974,3.80588,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,20,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1187.18,-4285.77,21.1921,3.69592,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,21,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1185.34,-4289.22,21.1921,4.52844,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,22,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1190.7,-4293.48,21.258,6.11102,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,23,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1200.36,-4293.36,21.2189,0.322628,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,24,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1204.04,-4291.89,21.1951,0.683911,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,25,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1207.19,-4286.44,21.192,1.35935,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,26,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1210.33,-4284.73,21.192,5.65548,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,27,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1212.97,-4288.85,21.192,4.25748,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,28,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1208.33,-4291.2,21.192,3.49957,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,29,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1206.46,-4294.69,21.1925,4.63054,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,30,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1208.4,-4297.3,21.1929,0.915605,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,31,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1213.24,-4292.98,21.1929,0.518979,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,32,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1215.26,-4296.66,21.1929,4.1004,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,33,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1212.44,-4299.5,21.1929,3.6645,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,34,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1206.24,-4300.01,21.1978,2.72595,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,35,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1199.34,-4298.13,21.377,3.02047,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,36,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1197.71,-4300.08,21.4586,4.93684,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,37,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1203.39,-4297.49,21.2196,2.00338,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,38,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1201.1,-4301.55,21.3483,2.99691,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,39,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1196.24,-4303.98,21.2509,2.66311,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,40,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1193.57,-4298.09,21.4725,2.84768,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,41,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1189.9,-4300.33,21.3319,3.9708,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,42,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1192.37,-4303.41,21.2629,5.4395,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,43,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1207.39,-4303.19,21.3475,0.350117,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,44,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1213.96,-4302.97,21.192,5.67905,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,45,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1214.59,-4305.26,21.192,4.47739,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,46,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1210.72,-4304.51,21.3555,2.41179,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,47,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1209.12,-4308.69,21.243,2.71417,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,48,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1203.82,-4303.28,21.2771,2.12512,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,49,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1204.53,-4306.97,21.2342,3.62523,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,50,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1204.76,-4310.99,21.252,3.72341,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,51,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1201.8,-4309.15,21.2576,2.2233,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,52,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1200.39,-4305.57,21.2246,1.91307,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,53,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1197.17,-4310.19,21.292,3.37391,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,54,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1195.19,-4307.9,21.2921,1.79918,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,55,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1192.68,-4309.06,21.2945,2.078,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,56,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1189.37,-4304.97,21.2507,2.60422,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,57,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1185.69,-4301.03,21.2623,2.2233,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,58,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1194.77,-4300.84,21.3994,0.892044,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,59,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1197.76,-4291.57,21.213,1.19442,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,60,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1194.9,-4285.23,21.196,0.703549,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,61,0,0,0,100,0,0,0,0,0,12,23894,1,300000,0,0,0,8,0,0,0,1201.07,-4285.3,21.1986,6.13458,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon [DND] Brewfest Dark Iron Spawn Bunny"),
(@ENTRY*100+1,9,62,0,0,0,100,0,0,0,0,0,12,24373,1,300000,0,0,0,8,0,0,0,1182.845,-4273.276,21.27497,1.46772,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon T'chali's Voodoo Brew Festive Keg"),
(@ENTRY*100+1,9,63,0,0,0,100,0,0,0,0,0,12,23706,1,300000,0,0,0,8,0,0,0,1222.903,-4296.746,21.27534,0.09009,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon Gordok Festive Keg"),
(@ENTRY*100+1,9,64,0,0,0,100,0,0,0,0,0,12,24372,1,300000,0,0,0,8,0,0,0,1184.316,-4314.621,21.37921,0.024872,"[DND] Brewfest Dark Iron Event Generator - On Script - Summon Drohn's Distillery Festive Keg"),
(@ENTRY*100+1,9,66,0,0,0,100,0,59000,79000,90000,90000,45,2,2,0,0,0,0,11,23685,70,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Gordok Brew Barker"),
(@ENTRY*100+1,9,67,0,0,0,100,0,10000,29000,90000,90000,45,3,3,0,0,0,0,11,24492,70,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Drohn's Distillery Barker"),
(@ENTRY*100+1,9,68,0,0,0,100,0,3000,11000,90000,90000,45,4,4,0,0,0,0,11,24493,70,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data T'chalis's Voodoo Brewewry Barket"),

(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL_RETREAT,0,0,0,0,0,11,23709,100,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Cast Brewfest Retreat"),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,11,@SPELL_MOLE_MACHINE_SPAWN,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Cast Brewfest Retreat"),
(@ENTRY*100+2,9,2,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,11,24493,100,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data T'chali's Voodoo Brewery Barker"),
(@ENTRY*100+2,9,3,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,11,24492,100,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Drohn's Distillery Barker"),
(@ENTRY*100+2,9,4,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,10,88864,23685,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Gordok Brew Barker"),
(@ENTRY*100+2,9,5,0,0,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Despawn"),

(@ENTRY*100+3,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL_RETREAT,0,0,0,0,0,11,23709,100,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Cast Brewfest Retreat"),
(@ENTRY*100+3,9,1,0,0,0,100,0,0,0,0,0,11,@SPELL_MOLE_MACHINE_SPAWN,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Cast Brewfest Retreat"),
(@ENTRY*100+3,9,2,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,11,23683,100,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Maeve Barleybrew"),
(@ENTRY*100+3,9,3,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,11,23684,100,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Ita Thunderbrew"),
(@ENTRY*100+3,9,4,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,10,88955,23685,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Set Data Gordok Brew Barker"),
(@ENTRY*100+3,9,5,0,0,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Event Generator - On Script - Despawn");

-- [DND] Brewfest Dark Iron Spawn Bunny SAI
SET @ENTRY := 23894;
SET @SPELL_MOLE_MACHINE_SPAWN := 43563;
SET @SPELL_GROUND_SHAKE := 44210;
UPDATE `creature_template` SET `AIName`='SmartAI',`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,5000,275000,280000,280000,11,@SPELL_MOLE_MACHINE_SPAWN,2,0,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Spawn Bunny - Out of Combat - Cast Mole Machine Spawn"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Spawn Bunny - On Mole Machine Spawn - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,5000,5000,0,0,12,23709,1,300000,0,0,0,1,0,0,0,0,0,0,3.85,"[DND] Brewfest Dark Iron Spawn Bunny - On Script - Spawn Dark Iron Guzzler"),
(@ENTRY*100,9,1,0,0,0,100,0,4000,4000,0,0,12,23709,1,300000,0,0,0,1,0,0,0,0,0,0,5.58,"[DND] Brewfest Dark Iron Spawn Bunny - On Script - Spawn Dark Iron Guzzler"),
(@ENTRY*100,9,2,0,0,0,100,0,3000,3000,0,0,12,23709,1,300000,0,0,0,1,0,0,0,0,0,0,0.80,"[DND] Brewfest Dark Iron Spawn Bunny - On Script - Spawn Dark Iron Guzzler"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,12,23709,1,300000,0,0,0,1,0,0,0,0,0,0,2.48,"[DND] Brewfest Dark Iron Spawn Bunny - On Script - Spawn Dark Iron Guzzler"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"[DND] Brewfest Dark Iron Spawn Bunny - On Data Set - Despawn");

-- Dark Iron Herald SAI
-- We are making him invisible (model 16925) at all times because else we can not run the event properly (since we spawned it).
-- We are also setting phase so the yells and such will only happen during the event
SET @ENTRY := 24536;
SET @SPELL_PLANS_A := 48145;
SET @SPELL_PLANS_H := 49318;
UPDATE `creature_template` SET `AIName`='SmartAI',`modelid1`=16925,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@GUID+1),-(@GUID+2),@ENTRY*100,@ENTRY*100+1,@ENTRY*100+2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Durotar
(-(@GUID+1),0,0,1,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Herald - On Data Set - Yell Line 0"),
(-(@GUID+1),0,1,2,61,0,100,0,0,0,0,0,45,2,2,0,0,0,0,11,24484,100,0,0,0,0,0,"Dark Iron Herald - On Data Set - Set Data Brewfest Reveler"),
(-(@GUID+1),0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Data Set - Set Phase 1"),
(-(@GUID+1),0,3,0,1,1,100,0,25000,45000,60000,90000,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Herald - Out of Combat - Say Line 1 (random)"),
(-(@GUID+1),0,4,5,1,1,100,1,295000,295000,300000,300000,45,5,5,0,0,0,0,10,@GUID+0,23703,0,0,0,0,0,"Dark Iron Herald - Out of Combat - Set Data Dark Iron Event Generator"), -- Almost 5 minutes passed, retreat
(-(@GUID+1),0,5,0,61,1,100,0,0,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - Out of Combat - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Yell Line 3"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,11,23702,100,0,0,0,0,0,"Dark Iron Herald - On Script - Set Data Thunderbrew Festive Keg"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,11,23706,100,0,0,0,0,0,"Dark Iron Herald - On Script - Set Data Gordok Festive Keg"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,11,23700,100,0,0,0,0,0,"Dark Iron Herald - On Script - Set Data Barleybrew Festive Keg"),
(@ENTRY*100,9,4,0,0,0,100,0,6000,6000,0,0,11,@SPELL_PLANS_H,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Cast Players Won - H - Summon Dark Iron Dwarf Plans"),
(@ENTRY*100,9,5,0,0,0,100,0,3000,3000,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Despawn"),
(-(@GUID+1),0,6,0,38,1,100,0,20,20,0,0,80,@ENTRY*100+2,0,2,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Data Set - Run Script"), -- Runs same script the alliance version does
-- Dun Morogh
(-(@GUID+2),0,0,1,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Herald - On Data Set - Yell Line 0"),
(-(@GUID+2),0,1,2,61,0,100,0,0,0,0,0,45,3,3,0,0,0,0,11,24484,100,0,0,0,0,0,"Dark Iron Herald - On Data Set - Set Data Brewfest Reveler"),
(-(@GUID+2),0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Data Set - Set Phase 1"),
(-(@GUID+2),0,3,0,1,1,100,0,25000,45000,60000,90000,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Herald - Out of Combat - Say Line 1 (random)"),
(-(@GUID+2),0,4,5,1,1,100,1,295000,295000,300000,300000,45,5,5,0,0,0,0,10,@GUID+3,23703,0,0,0,0,0,"Dark Iron Herald - Out of Combat - Set Data Dark Iron Event Generator"), -- Almost 5 minutes passed, retreat
(-(@GUID+2),0,5,0,61,1,100,0,0,0,0,0,80,@ENTRY*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - Out of Combat - Run Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Yell Line 2"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,11,23702,100,0,0,0,0,0,"Dark Iron Herald - On Script - Set Data Thunderbrew Festive Keg"),
(@ENTRY*100+1,9,2,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,11,23706,100,0,0,0,0,0,"Dark Iron Herald - On Script - Set Data Gordok Festive Keg"),
(@ENTRY*100+1,9,3,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,11,23700,100,0,0,0,0,0,"Dark Iron Herald - On Script - Set Data Barleybrew Festive Keg"),
(@ENTRY*100+1,9,4,0,0,0,100,0,6000,6000,0,0,11,@SPELL_PLANS_A,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Cast Players Won - A - Summon Dark Iron Dwarf Plans"),
(@ENTRY*100+1,9,5,0,0,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Despawn"),
(-(@GUID+2),0,6,0,38,1,100,0,20,20,0,0,80,@ENTRY*100+2,0,2,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Data Set - Run Script"), -- Runs same script the horde version does

-- This script is used for both Durotar and Dun Morogh version
(@ENTRY*100+2,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Yell Line 3"),
(@ENTRY*100+2,9,1,0,0,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Call Script Reset"),
(@ENTRY*100+2,9,2,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Herald - On Script - Despawn"),
(@ENTRY*100+2,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,23894,100,0,0,0,0,0,"Dark Iron Herald - On Script - Set Data Brewfest Dark Iron Spawn Bunny"); -- Unsummon the spawn bunnies so they won't summon more dwarfs while we are retreating
/*(@GUID+2,24536,0,1,1,0,0,-5152.3,-603.529,398.356,2.50732,300,0,0,37800,0,0,0,0,0),
(@GUID+1,24536,1,1,1,0,0,1197.6,-4293.571,21.243,5.20232,300,0,0,37800,0,0,0,0,0);*/
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"No one expects the Dark Iron dwarves!",14,0,100,0,0,11832,"Dark Iron Herald"), -- This is where we play the sound

(@ENTRY,1,0,"We'll drink yer stout and lager,$BDrain all the pints and kegs!$BWe'll drink and brawl and brawl and drink,$B'til we can't feel our legs!",12,0,100,0,0,0,"Dark Iron Herald"),
(@ENTRY,1,1,"So lift a mug to Coren,$BAnd Hurley Blackbreath too!$BThis drink is weak, without much kick,$BBut oi! At least it's brew!",12,0,100,0,0,0,"Dark Iron Herald"),
(@ENTRY,1,2,"And when the brew's all missin'$BTa Shadowforge we'll hop,$BA bitter toast ta Ragnaros...$B... but bring him not a drop!",12,0,100,0,0,0,"Dark Iron Herald"),
(@ENTRY,1,3,"Oh, we're from Blackrock Mountain,$BWe've come ta drink yer brew!$BDark Iron dwarves, they do not lie,$BAnd so yeh know it's true!",12,0,100,0,0,0,"Dark Iron Herald"),
(@ENTRY,1,4,"Yeh will not try our bitter,$BYeh will not serve our ale!$BBut have Brewfest without our lot?$BJust try it, and ye'll fail!",12,0,100,0,0,0,"Dark Iron Herald"),

-- Shauren told me to use 0 for the counter because it is also bugged on retail
(@ENTRY,2,0,"RETREAT! We've taken a beating and had 0 casualties! We can't keep taking these losses! FALL BACK!!",14,0,100,0,0,0,"Dark Iron Herald"), -- Alliance
(@ENTRY,3,0,"We did it boys! Now back to the Grim Guzzler and we'll drink to the 0 that were injured!!",14,0,100,0,0,0,"Dark Iron Herald"); -- Horde

-- Dark Iron Guzzler
-- We are setting AIName because some people applied the SAI for this NPC
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_dark_iron_guzzler',`unit_flags`=33024 WHERE `entry`=23709;
UPDATE `creature` SET `equipment_id`=2477 WHERE `id`=23709;
-- Text
DELETE FROM `creature_text` WHERE `entry`=23709;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(23709,0,0,"Did someone say 'Free Brew'?",12,0,20,0,0,0,"Dark Iron Guzzler"),
(23709,0,1,"DRINK! BRAWL! DRINK! BRAWL!",12,0,100,0,0,0,"Dark Iron Guzzler"),
(23709,0,2,"Drink it all boys!",12,0,50,0,0,0,"Dark Iron Guzzler"),
(23709,0,3,"It's not a party without some crashers!",12,0,30,0,0,0,"Dark Iron Guzzler");

-- Festive Keg SAI (creatures)
-- The unit_flags are taken from sniffs - we are setting react state passive so it won't EVER fight back
SET @ENTRY1 := 23702; -- Thunderbrew Festive Keg
SET @ENTRY2 := 23700; -- Barleybrew Festive Keg
SET @ENTRY3 := 23706; -- Gordok Festive Keg
SET @ENTRY4 := 24373; -- T'chalis's Festive Keg
SET @ENTRY5 := 24372; -- Drohn's Festive Keg
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=`unit_flags`|256,`RegenHealth`=0 WHERE `entry` IN (@ENTRY1,@ENTRY2,@ENTRY3,@ENTRY4,@ENTRY5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY1,@ENTRY2,@ENTRY3,@ENTRY4,@ENTRY5);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Thunderbrew Festive Keg
(@ENTRY1,0,0,0,1,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderbrew Festive Keg - Out of Combat - Set React State Passive"),
(@ENTRY1,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,186184,0,0,0,0,0,0,"Thunderbrew Festive Keg - On Death - Set Data Thunderbrew Festive Keg (OBJECT)"),
(@ENTRY1,0,2,0,38,0,100,0,5,5,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderbrew Festive Keg - On Data Set - Forced Despawn"),
(@ENTRY1,0,3,0,6,0,100,0,0,0,0,0,45,10,10,0,0,0,0,11,23709,3,0,0,0,0,0,"Thunderbrew Festive Keg - On Death - Set Data Dark Iron Guzzler"),
-- Barleybrew Festive Keg
(@ENTRY2,0,0,0,1,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barleybrew Festive Keg - Out of Combat - Set React State Passive"),
(@ENTRY2,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,186189,0,0,0,0,0,0,"Barleybrew Festive Keg - On Death - Set Data Barleybrew Festive Keg (OBJECT)"),
(@ENTRY2,0,2,0,38,0,100,0,5,5,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barleybrew Festive Keg - On Data Set - Forced Despawn"),
(@ENTRY2,0,3,0,6,0,100,0,0,0,0,0,45,11,11,0,0,0,0,11,23709,3,0,0,0,0,0,"Barleybrew Festive Keg - On Death - Set Data Dark Iron Guzzler"),
-- Gordok Festive Keg
(@ENTRY3,0,0,0,1,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Festive Keg - Out of Combat - Set React State Passive"),
(@ENTRY3,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,186185,0,0,0,0,0,0,"Gordok Festive Keg - On Death - Set Data Gordok Festive Keg (OBJECT)"),
(@ENTRY3,0,2,0,38,0,100,0,5,5,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Festive Keg - On Data Set - Forced Despawn"),
(@ENTRY3,0,3,0,6,0,100,0,0,0,0,0,45,12,12,0,0,0,0,11,23709,3,0,0,0,0,0,"Gordok Festive Keg - On Death - Set Data Dark Iron Guzzler"),
-- T'chalis's Festive Keg
(@ENTRY4,0,0,0,1,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"T'chalis's Festive Keg - Out of Combat - Set React State Passive"),
(@ENTRY4,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,186187,0,0,0,0,0,0,"T'chalis's Festive Keg - On Death - Set Data T'chalis's Festive Keg (OBJECT)"),
(@ENTRY4,0,2,0,38,0,100,0,5,5,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"T'chalis's Festive Keg - On Data Set - Forced Despawn"),
(@ENTRY4,0,3,0,6,0,100,0,0,0,0,0,45,10,10,0,0,0,0,11,23709,3,0,0,0,0,0,"T'chalis's Festive Keg - On Death - Set Data Dark Iron Guzzler"),
-- Drohn's Festive Keg
(@ENTRY5,0,0,0,1,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drohn's Festive Keg - Out of Combat - Set React State Passive"),
(@ENTRY5,0,1,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,186186,0,0,0,0,0,0,"Drohn's Festive Keg - On Death - Set Data Drohn's Festive Keg (OBJECT)"),
(@ENTRY5,0,2,0,38,0,100,0,5,5,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drohn's Festive Keg - On Data Set - Forced Despawn"),
(@ENTRY5,0,3,0,6,0,100,0,0,0,0,0,45,10,10,0,0,0,0,11,23709,3,0,0,0,0,0,"Drohn's Festive Keg - On Death - Set Data Dark Iron Guzzler");

-- Festive Keg SAI (gameobjects)
-- Currently we can not despawn the objects through SAI because it misses proper support. I'm still adding it because it might be of use for when this gets fixed
SET @ENTRY1 := 186184;
SET @ENTRY2 := 186189;
SET @ENTRY3 := 186185;
SET @ENTRY4 := 186187;
SET @ENTRY5 := 186186;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@ENTRY1,@ENTRY2,@ENTRY3,@ENTRY4,@ENTRY5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY1,@ENTRY2,@ENTRY3,@ENTRY4,@ENTRY5);
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY1,1,0,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderbrew Festive Keg - On Data Set - Despawn"),
(@ENTRY2,1,0,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barleybrew Festive Keg - On Data Set - Despawn"),
(@ENTRY3,1,0,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Festive Keg - On Data Set - Despawn"),
(@ENTRY4,1,0,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"T'chalis's Festive Keg - On Data Set - Despawn"),
(@ENTRY5,1,0,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drohn's Festive Keg - On Data Set - Despawn");

-- Brewfest Reveler SAI
SET @ENTRY := 24484;
SET @SPELL_THROW_MUG := 50696;
SET @SPELL_CREATE_MUG := 42518;
SET @SPELL_TOAST := 41586;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1); -- We are adding new lines so don't remove complete SAI
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,101,5000,5000,0,11,@SPELL_CREATE_MUG,2,0,0,0,0,7,0,0,0,0,0,0,0,"Brewfest Reveler - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"),
(@ENTRY,0,1,0,22,0,100,0,34,5000,5000,0,11,@SPELL_TOAST,2,0,0,0,0,7,0,0,0,0,0,0,0,"Brewfest Reveler - Emote Receive 'Dance' - Cast Brewfest Toast"),
(@ENTRY,0,2,0,1,0,100,0,4000,11000,15000,20000,10,92,1,4,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - Out of Combat - Play Random Emote"),
-- Dun Morogh
(@ENTRY,0,3,0,38,0,100,0,2,2,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Data Set - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,53,1,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Start WP"),
(@ENTRY*100,9,1,0,0,0,100,0,1000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Say Line 0 (random)"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,11,@SPELL_THROW_MUG,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Cast Throw Mug"),
(@ENTRY,0,4,0,58,0,100,0,3,@ENTRY,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On WP 3 - Despawn"),
-- Durotar
(@ENTRY,0,5,0,38,0,100,0,3,3,0,0,80,@ENTRY*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Data Set - Run Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,0,0,0,0,53,1,@ENTRY*10,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Start WP"),
(@ENTRY*100+1,9,1,0,0,0,100,0,1000,5000,5000,5000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Say Line 0 (random)"),
(@ENTRY*100+1,9,2,0,0,0,100,0,1000,3000,3000,3000,11,@SPELL_THROW_MUG,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On Script - Cast Throw Mug"),
(@ENTRY,0,6,0,58,0,100,0,4,@ENTRY*10,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brewfest Reveler - On WP 4 - Despawn");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Dark Iron dwarves!",12,0,100,0,0,0,"Brewfest Reveler"),
(@ENTRY,0,1,"Run! It's the Dark Iron dwarves!",12,0,100,0,0,0,"Brewfest Reveler"),
(@ENTRY,0,2,"They're after the beer!",12,0,100,0,0,0,"Brewfest Reveler"),
(@ENTRY,0,3,"Someone has to save the beer!",12,0,100,0,0,0,"Brewfest Reveler"),
(@ENTRY,0,4,"If you value your beer, run for it!",12,0,100,0,0,0,"Brewfest Reveler");
-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (@ENTRY,@ENTRY*10);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
-- Dun Morogh
(@ENTRY,1,-5184.680176,-562.372009,397.260010,'Brewfest Reveler'),
(@ENTRY,2,-5192.152832,-547.358459,397.177094,'Brewfest Reveler'),
(@ENTRY,3,-5198.825684,-530.586243,392.940155,'Brewfest Reveler'),
-- Durotar
(@ENTRY*10,1,1209.775879,-4342.093750,21.295063,'Brewfest Reveler'),
(@ENTRY*10,2,1203.770874,-4356.925781,21.967909,'Brewfest Reveler'),
(@ENTRY*10,3,1202.042725,-4370.892578,24.852894,'Brewfest Reveler'),
(@ENTRY*10,4,1199.489868,-4389.286621,23.865566,'Brewfest Reveler');

-- Gordok Brew Barker SAI
SET @ENTRY := 23685;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-88864,-88955,@ENTRY);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Dun Morogh version
(-88864,0,0,0,22,0,100,0,101,5000,5000,0,11,@SPELL_DRINK,2,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Brew Barker - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"),
(-88864,0,1,0,1,0,100,0,30000,45000,180000,240000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gordok Brew Barker - Out of Combat - Yell Line 0 (random)"),
(-88864,0,2,0,38,0,100,0,3,3,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Brew Barker - On Data Set - Set Phase 1"),
(-88864,0,3,0,1,1,100,0,10000,35000,45000,50000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gordok Brew Barker - Out of Combat - Say Line 2 (random) (P1)"),
(-88864,0,4,0,1,1,100,1,3,3,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Brew Barker - Out of Combat - Yell Line 1 (P1)"),
(-88864,0,5,0,52,1,100,0,1,@ENTRY,0,0,50,186471,15000,0,0,0,0,8,0,0,0,-5149.791992,-590.198792,397.323730,4.39,"Gordok Brew Barker - On Text Over - Summon Super Brew Stein Trap (P1)"),
(-88864,0,6,0,38,0,100,0,4,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Brew Barker - On Data Set - Set Phase 0"), -- Event is over, so set phase 0

-- Durotar version
(-88955,0,0,0,22,0,100,0,101,5000,5000,0,11,@SPELL_DRINK,2,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Brew Barker - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"),
(-88955,0,1,0,1,0,100,0,30000,45000,180000,240000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gordok Brew Barker - Out of Combat - Yell Line 0 (random)"),
(-88955,0,2,0,38,0,100,0,3,3,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Brew Barker - On Data Set - Set Phase 1"),
(-88955,0,3,0,1,1,100,0,10000,35000,45000,50000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gordok Brew Barker - Out of Combat - Say Line 2 (random) (P1)"),
(-88955,0,4,0,1,1,100,1,3,3,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Brew Barker - Out of Combat - Yell Line 1 (P1)"),
(-88955,0,5,0,52,1,100,0,1,@ENTRY,0,0,50,186471,15000,0,0,0,0,8,0,0,0,1216.599976,-4284.270020,21.290300,3.787360,"Gordok Brew Barker - On Text Over - Summon Super Brew Stein Trap (P1)"),
(-88955,0,6,0,38,0,100,0,4,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Brew Barker - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `script_texts` WHERE `entry` BETWEEN -717 AND -719; -- Old entries used in EAI
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"YOU TRY DA' BEST, NOW TRY DA' REST! OGRE BREW!",14,0,100,0,0,0,"Gordok Brew Barker"),
(@ENTRY,0,1,"HEY YOU! DRINK OGRE BREWS! MAKE YOU BIG AND STRONG!",14,0,100,0,0,0,"Gordok Brew Barker"),
(@ENTRY,0,2,"YOU WANT DRINK? WE GOT DRINK!",14,0,100,0,0,0,"Gordok Brew Barker"),

(@ENTRY,1,0,"SOMEONE TRY THIS SUPER BREW!",14,0,100,0,0,0,"Gordok Brew Barker");

-- Maeve Barleybrew SAI
SET @ENTRY := 23683;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,101,5000,5000,0,11,@SPELL_DRINK,2,0,0,0,0,7,0,0,0,0,0,0,0,"Maeve Barleybrew - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"),
(@ENTRY,0,1,0,1,0,100,0,30000,45000,180000,240000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Maeve Barleybrew - Out of Combat - Yell Line 0 (random)"),

(@ENTRY,0,2,0,38,0,100,0,3,3,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maeve Barleybrew - On Data Set - Set Phase 1"),
(@ENTRY,0,3,0,1,1,100,0,10000,35000,45000,50000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Maeve Barleybrew - Out of Combat - Say Line 2 (random) (P1)"),
(@ENTRY,0,4,0,1,1,100,1,3,3,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maeve Barleybrew - Out of Combat - Yell Line 1 (P1)"),
(@ENTRY,0,5,0,52,1,100,0,1,@ENTRY,0,0,50,186471,15000,0,0,0,0,8,0,0,0,-5161.600586,-611.307861,397.917419,2.39,"Maeve Barleybrew - On Text Over - Summon Super Brew Stein Trap (P1)"),
(@ENTRY,0,6,0,38,0,100,0,4,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maeve Barleybrew - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Come try our Barleybrew Dark!",12,0,100,0,0,0,"Maeve Barleybrew"),
(@ENTRY,0,1,"Barleybrew, finest brewery in Azeroth!",12,0,100,0,0,0,"Maeve Barleybrew"),
(@ENTRY,0,2,"The Barleybrews have always been leaders in brewery innovation. Check out our newest creation, Barleybrew Clear!",12,0,100,0,0,0,"Maeve Barleybrew"),

(@ENTRY,1,0,"SOMEONE TRY THIS SUPER BREW!",14,0,100,0,0,0,"Maeve Barleybrew"),

(@ENTRY,2,0,"Chug and chuck! Chug and chuck!",12,0,100,0,0,0,"Maeve Barleybrew"),
(@ENTRY,2,1,"Down the free brew and pelt the Guzzlers with your mug!",12,0,100,0,0,0,"Maeve Barleybrew");

-- Ita Thunderbrew SAI
SET @ENTRY := 23684;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,101,5000,5000,0,11,@SPELL_DRINK,2,0,0,0,0,7,0,0,0,0,0,0,0,"Ita Thunderbrew - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"),
(@ENTRY,0,1,0,1,0,100,0,30000,45000,180000,240000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ita Thunderbrew - Out of Combat - Yell Line 0 (random)"),

(@ENTRY,0,2,0,38,0,100,0,3,3,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ita Thunderbrew - On Data Set - Set Phase 1"),
(@ENTRY,0,3,0,1,1,100,0,10000,35000,45000,50000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ita Thunderbrew - Out of Combat - Say Line 2 (random) (P1)"),
(@ENTRY,0,4,0,1,1,100,1,3,3,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ita Thunderbrew - Out of Combat - Yell Line 1 (P1)"),
(@ENTRY,0,5,0,52,1,100,0,1,@ENTRY,0,0,50,186471,15000,0,0,0,0,8,0,0,0,-5149.791992,-590.198792,397.323730,4.39,"Ita Thunderbrew - On Text Over - Summon Super Brew Stein Trap (P1)"),
(@ENTRY,0,6,0,38,0,100,0,4,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ita Thunderbrew - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Thunderbrew, finest brewery in all the realms.",12,0,100,0,0,0,"Ita Thunderbrew"),
(@ENTRY,0,1,"THUNDER! THUNDER! THUNDER! THUNDERBREW, HO!",12,0,100,0,0,0,"Ita Thunderbrew"),
(@ENTRY,0,2,"You look like you could use a cold one. Thunderbrew's got ya covered!",12,0,100,0,0,0,"Ita Thunderbrew"),

(@ENTRY,1,0,"SOMEONE TRY THIS SUPER BREW!",14,0,100,0,0,0,"Ita Thunderbrew"),

(@ENTRY,2,0,"Chug and chuck! Chug and chuck!",12,0,100,0,0,0,"Ita Thunderbrew"),
(@ENTRY,2,1,"Down the free brew and pelt the Guzzlers with your mug!",12,0,100,0,0,0,"Ita Thunderbrew");

-- Drohn's Distillery Barker SAI
SET @ENTRY := 24492;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,101,5000,5000,0,11,@SPELL_DRINK,2,0,0,0,0,7,0,0,0,0,0,0,0,"Drohn's Distillery Barker - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"),
(@ENTRY,0,1,0,1,0,100,0,30000,45000,180000,240000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Drohn's Distillery Barker - Out of Combat - Yell Line 0 (random)"),

(@ENTRY,0,2,0,38,0,100,0,3,3,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drohn's Distillery Barker - On Data Set - Set Phase 1"),
(@ENTRY,0,3,0,1,1,100,0,10000,35000,45000,50000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Drohn's Distillery Barker - Out of Combat - Say Line 2 (random) (P1)"),
(@ENTRY,0,4,0,1,1,100,1,3,3,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drohn's Distillery Barker - Out of Combat - Yell Line 1 (P1)"),
(@ENTRY,0,5,0,52,1,100,0,1,@ENTRY,0,0,50,186471,15000,0,0,0,0,8,0,0,0,1191.014404,-4299.663574,21.381546,4.39,"Drohn's Distillery Barker - On Text Over - Summon Super Brew Stein Trap (P1)"),
(@ENTRY,0,6,0,38,0,100,0,4,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drohn's Distillery Barker - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Drohn's brew is the stuff legends are made of! Come taste the legend!",12,0,100,0,0,0,"Drohn's Distillery Barker"),
(@ENTRY,0,1,"We drink for the Horde! Do you drink for the Horde? Come show us at Drohn's Distillery!",12,0,100,0,0,0,"Drohn's Distillery Barker"),
(@ENTRY,0,2,"Hey you, the tall one... Want to put some hair on your chest? Drohn's Distillery can help you out!",12,0,100,0,0,0,"Drohn's Distillery Barker"),
(@ENTRY,0,3,"Hey you! T'chali's Voodoo Brewers have got a brew that won't kill you! But they've also got a brew that might...",12,0,100,0,0,0,"Drohn's Distillery Barker"),

(@ENTRY,1,0,"SOMEONE TRY THIS SUPER BREW!",14,0,100,0,0,0,"Drohn's Distillery Barker"),

(@ENTRY,2,0,"Chug and chuck! Chug and chuck!",12,0,100,0,0,0,"Drohn's Distillery Barker"),
(@ENTRY,2,1,"Down the free brew and pelt the Guzzlers with your mug!",12,0,100,0,0,0,"Drohn's Distillery Barker");

-- T'chali's Voodoo Brewery Barker SAI
SET @ENTRY := 24493;
SET @SPELL_DRINK := 42518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,101,5000,5000,0,11,@SPELL_DRINK,2,0,0,0,0,7,0,0,0,0,0,0,0,"T'chali's Voodoo Brewery Barker - Emote Receive 'Wave' - Cast Create Complimentary Brewfest Sampler"),
(@ENTRY,0,1,0,1,0,100,0,30000,45000,180000,240000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T'chali's Voodoo Brewery Barker - Out of Combat - Yell Line 0 (random)"),

(@ENTRY,0,2,0,38,0,100,0,3,3,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"T'chali's Voodoo Brewery Barker - On Data Set - Set Phase 1"),
(@ENTRY,0,3,0,1,1,100,0,10000,35000,45000,50000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T'chali's Voodoo Brewery Barker - Out of Combat - Say Line 2 (random) (P1)"),
(@ENTRY,0,4,0,1,1,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"T'chali's Voodoo Brewery Barker - Out of Combat - Yell Line 1 (P1)"),
(@ENTRY,0,5,0,52,1,100,0,1,@ENTRY,0,0,50,186471,15000,0,0,0,0,8,0,0,0,1190.705688,-4285.604004,21.193674,4.39,"T'chali's Voodoo Brewery Barker - On Text Over - Summon Super Brew Stein Trap (P1)"),
(@ENTRY,0,6,0,38,0,100,0,4,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"T'chali's Voodoo Brewery Barker - On Data Set - Set Phase 0"); -- Event is over, so set phase 0
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"If you wanna live life to the fullest, you gotta try T'chali's Voodoo Brew!",12,0,100,0,0,0,"T'chali's Voodoo Brewery Barker"),
(@ENTRY,0,1,"T'chali's Voodoo Brews helps keep the party going! Check out the party at Brewfest!",12,0,100,0,0,0,"T'chali's Voodoo Brewery Barker"),
(@ENTRY,0,2,"Hey you! T'chali's Voodoo Brewers have got a brew that won't kill you! But they've also got a brew that might...",12,0,100,0,0,0,"T'chali's Voodoo Brewery Barker"),
(@ENTRY,0,3,"T'chali's Voodoo Brewery has the best brew you can find! They were voted 'Best Brew' by the Goblin Brew Weekly!",12,0,100,0,0,0,"T'chali's Voodoo Brewery Barker"),

(@ENTRY,1,0,"SOMEONE TRY THIS SUPER BREW!",14,0,100,0,0,0,"T'chali's Voodoo Brewery Barker"),

(@ENTRY,2,0,"Chug and chuck! Chug and chuck!",12,0,100,0,0,0,"T'chali's Voodoo Brewery Barker"),
(@ENTRY,2,1,"Down the free brew and pelt the Guzzlers with your mug!",12,0,100,0,0,0,"T'chali's Voodoo Brewery Barker");

-- Drunken Brewfest Reveler SAI
SET @ENTRY := 23698;
SET @SPELL_VOMIT := 67468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-88896,-88960);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Alliance
(-88896,0,0,0,1,0,100,0,10000,45000,180000,240000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drunken Brewfest Reveler - Out of Combat - Say Line 0 (random)"),
(-88896,0,1,0,1,0,100,0,10000,45000,180000,240000,11,@SPELL_VOMIT,2,0,0,0,0,1,0,0,0,0,0,0,0,"Drunken Brewfest Reveler - Out of Combat - Cast Drunken Vomit"),
-- Horde
(-88960,0,0,0,1,0,100,0,10000,45000,180000,240000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drunken Brewfest Reveler - Out of Combat - Say Line 1 (random)"),
(-88960,0,1,0,1,0,100,0,10000,45000,180000,240000,11,@SPELL_VOMIT,2,0,0,0,0,1,0,0,0,0,0,0,0,"Drunken Brewfest Reveler - Out of Combat - Cast Drunken Vomit");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- Alliance
(@ENTRY,0,0,"Uh oh...",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,0,1,"Good times! <hic>",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,0,2,"What's all the fuss about here?",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,0,3,"The besht part about drinking is pretending to be drunk... I'm jusht pretending guys.",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,0,4,"Hey fellas! How's it going?",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,0,5,"Hey! Anyone shee that cute blond dwarf? I shwear they were jusht here...",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,0,6,"Hey! Lishten up! I've got... I have something important to talk about! Shee... Wait... What wash I shaying? Something aboutsh boats and floating... Yeah! Sho don't float on a boat... Thank you...",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
-- Horde
(@ENTRY,1,0,"Uh oh...",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,1,1,"Good times! <hic>",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,1,2,"What's all the fuss about here?",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,1,3,"The besht part about drinking is pretending to be drunk... I'm jusht pretending guys.",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,1,4,"You guys have gotta try thish...",12,0,100,0,0,0,"Drunken Brewfest Reveler"),
(@ENTRY,1,5,"Hey! You for the Horde? <hic> I'm for the Horde!",12,0,100,0,0,0,"Drunken Brewfest Reveler");

-- [Q] [A/H] Catch the Wild Wolpertinger!

-- Wild Wolpertinger SAI
SET @ENTRY := 23487;
SET @SPELL_NET := 41621;
SET @SPELL_CREATE_ITEM := 41622;
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=`unit_flags`|512 WHERE `entry`=@ENTRY;
UPDATE `creature` SET `position_x`=24.539537 WHERE `guid`=207045 AND `id`=@ENTRY; -- For some reason this one was spawned in air
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,@SPELL_NET,0,0,0,11,@SPELL_CREATE_ITEM,2,0,0,0,0,7,0,0,0,0,0,0,0,"Wild Wolpertinger - On Spellhit - Cast Create Stunned Wolpertinger Item"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wild Wolpertinger - On Spellhit - Forced Despawn");

-- Condition for spell Wolpertinger Net
SET @Net          := 41621;
SET @Wolpertinger := 23487;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@Net;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@Net,0,0,31,1,3,@Wolpertinger,0,0,0,'','Net can only hit Wolpertingers');
-- Update Wolpetinger flags to remove immunity to players, was 768 before
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=@Wolpertinger;

-- A lot of missing spawns. Objects and creatures
SET @CGUID := 240200;
SET @OGUID := 231001;
SET @EVENT := 24;
-- Berfest Reveler
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- Barleybrew Apprentice <Barleybrew Brew Vendor>
(@CGUID+0,23482,530,1,1,22395,0,-4016.6,-11833,0.106771,4.04165,300,0,0,2215,0,0,0,0,0),
-- Brewfest Reveler - Exodar
(@CGUID+1,24484,530,1,1,21843,86,-4004.32,-11859.4,0.177081,0.860784,300,0,0,2215,0,0,0,0,0),
(@CGUID+2,24484,530,1,1,21844,86,-4001.38,-11855.2,0.211436,4.18773,300,0,0,2215,0,0,0,0,0),
(@CGUID+3,24484,530,1,1,21843,86,-4010.47,-11852.8,0.118782,4.25763,300,0,0,2215,0,0,0,0,0),
(@CGUID+4,24484,530,1,1,21842,86,-4009.89,-11854.7,0.121793,3.64502,300,0,0,2215,0,0,0,0,0),
(@CGUID+5,24484,530,1,1,21844,86,-4012.09,-11839.5,0.131949,0.507355,300,0,0,2215,0,0,0,0,0),
(@CGUID+6,24484,530,1,1,21845,86,-4005.04,-11840.8,0.203372,2.26665,300,0,0,2215,0,0,0,0,0),
(@CGUID+7,24484,530,1,1,21842,86,-4017.34,-11851.2,0.047381,1.00608,300,0,0,2215,0,0,0,0,0),
(@CGUID+8,24484,530,1,1,21845,86,-4013.17,-11842.1,0.114192,4.16731,300,0,0,2215,0,0,0,0,0),
(@CGUID+9,24484,530,1,1,21844,86,-4012.1,-11847.4,0.111304,2.65935,300,0,0,2215,0,0,0,0,0),
(@CGUID+10,24484,530,1,1,21843,86,-4017.5,-11845,0.0595054,5.9266,300,0,0,2215,0,0,0,0,0),
-- Brewfest Reveler - Eversong Woods
(@CGUID+11,24484,530,1,1,21841,86,9318.1,-7278.19,13.3383,0.709729,300,0,0,2215,0,0,0,0,0),
(@CGUID+12,24484,530,1,1,21838,86,9318.04,-7274.55,13.3571,5.13466,300,0,0,2215,0,0,0,0,0),
(@CGUID+13,24484,530,1,1,21840,86,9322.69,-7278.57,13.2085,3.03844,300,0,0,2215,0,0,0,0,0),
(@CGUID+14,24484,530,1,1,21839,86,9323.46,-7274.86,13.2653,3.31333,300,0,0,2215,0,0,0,0,0),
(@CGUID+15,24484,530,1,1,21840,86,9333.88,-7275.82,13.514,5.39384,300,0,0,2215,0,0,0,0,0),
(@CGUID+16,24484,530,1,1,21841,86,9335.93,-7281.15,13.695,2.03234,300,0,0,2215,0,0,0,0,0),
(@CGUID+17,24484,530,1,1,21838,86,9340.67,-7275.46,14.0555,4.97837,300,0,0,2215,0,0,0,0,0),
(@CGUID+18,24484,530,1,1,21839,86,9343.15,-7280.24,14.3778,2.35828,300,0,0,2215,0,0,0,0,0),
(@CGUID+19,24484,530,1,1,21840,86,9334.47,-7296.27,13.7759,3.58271,300,0,0,2215,0,0,0,0,0),
(@CGUID+20,24484,530,1,1,21839,86,9329.98,-7295.05,13.7486,5.6758,300,0,0,2215,0,0,0,0,0),
(@CGUID+21,24484,530,1,1,21841,86,9340.93,-7269.42,14.5058,0.837748,300,0,0,2215,0,0,0,0,0),
-- Troll Commoner
(@CGUID+22,19177,1,1,1,21876,0,1748.94,-4497.53,28.793,5.47104,300,0,0,42,0,0,0,0,0),
(@CGUID+23,19177,1,1,1,21877,0,1752.58,-4499.43,28.2911,2.89886,300,0,0,42,0,0,0,0,0),
-- Orc Commoner
(@CGUID+24,19175,1,1,1,21868,0,1609.47,-4323.21,2.33176,3.34811,300,0,0,42,0,0,0,0,0),
(@CGUID+25,19175,1,1,1,21869,0,1605.95,-4324.2,2.19915,0.0101724,300,0,0,42,0,0,0,0,0),
-- Gnome Commoner
(@CGUID+26,19172,0,1,1,21850,0,-4831.74,-1172.58,502.278,6.19592,2,0,0,42,0,0,3,0,0),
(@CGUID+27,19172,0,1,1,21853,0,-4829.88,-1173.25,502.277,2.49582,2,0,0,42,0,0,3,0,0),
-- Bok Dropcertain
(@CGUID+28,24527,1,1,1,0,0,795.14,-4522.59,6.31052,5.20636,300,0,0,1004,0,0,0,0,0),
-- Drohn's Distillery Apprentice
(@CGUID+29,24501,530,1,1,22491,0,9333.7,-7269.67,13.7715,4.52047,300,0,0,2215,0,0,0,0,0),
-- Gordok Brew Apprentice <Gordok Brew Vendor>
(@CGUID+30,23511,530,1,1,0,0,-4020.13,-11855.6,0.0061873,1.0273,300,0,0,2215,0,0,0,0,0),
(@CGUID+31,23511,530,1,1,0,0,9313.83,-7281.3,13.8523,0.903714,300,0,0,2215,0,0,0,0,0),
-- T'chali's Voodoo Brewery Apprentice <Voodoo Brew Vendor>
(@CGUID+32,23533,530,1,1,22493,0,9330.11,-7285.87,13.7137,1.37103,300,0,0,2215,0,0,0,0,0),
-- Thunderbrew Apprentice
(@CGUID+33,23510,530,1,1,0,0,-4021.3,-11842.9,0.0212859,5.9439,300,0,0,2215,0,0,0,0,0);

-- Make the above spawns only happen if Brewfest is active
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(@EVENT,@CGUID+0),(@EVENT,@CGUID+1),(@EVENT,@CGUID+2),(@EVENT,@CGUID+3),
(@EVENT,@CGUID+4),(@EVENT,@CGUID+5),(@EVENT,@CGUID+6),(@EVENT,@CGUID+7),
(@EVENT,@CGUID+8),(@EVENT,@CGUID+9),(@EVENT,@CGUID+10),(@EVENT,@CGUID+11),
(@EVENT,@CGUID+12),(@EVENT,@CGUID+13),(@EVENT,@CGUID+14),(@EVENT,@CGUID+15),
(@EVENT,@CGUID+16),(@EVENT,@CGUID+17),(@EVENT,@CGUID+18),(@EVENT,@CGUID+19),
(@EVENT,@CGUID+20),(@EVENT,@CGUID+21),(@EVENT,@CGUID+22),(@EVENT,@CGUID+23),
(@EVENT,@CGUID+24),(@EVENT,@CGUID+25),(@EVENT,@CGUID+26),(@EVENT,@CGUID+27),
(@EVENT,@CGUID+28),(@EVENT,@CGUID+29),(@EVENT,@CGUID+30),(@EVENT,@CGUID+31),
(@EVENT,@CGUID+32),(@EVENT,@CGUID+33);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- Exodar
(@OGUID+0,178666,530,1,1,-4015.97,-11829.2,0.146814,2.80549,0,0,0.985913,0.167262,300,0,1),
(@OGUID+1,178666,530,1,1,-4024.94,-11840.7,-0.0137537,4.17208,0,0,0.870173,-0.492747,300,0,1),
(@OGUID+2,186259,530,1,1,-4029.42,-11849.1,-0.0817791,3.05053,0,0,0.998964,0.0455147,300,0,1),
(@OGUID+3,186260,530,1,1,-4008.1,-11835.5,0.186614,1.27632,0,0,0.595718,0.803194,300,0,1),
(@OGUID+4,186257,530,1,1,-4016.1,-11859.2,0.0441619,4.26476,0,0,0.846413,-0.532527,300,0,1),
(@OGUID+5,186221,530,1,1,-4008.42,-11850.7,0.144533,2.04601,0,0,0.853677,0.520803,300,0,1),
(@OGUID+6,186717,530,1,1,-4008.29,-11857.1,0.135722,5.47893,0,0,0.391378,-0.92023,300,0,1),
(@OGUID+7,186717,530,1,1,-4002.56,-11851,0.205429,5.13728,0,0,0.542116,-0.840304,300,0,1),
-- Darnassus
(@OGUID+8,186717,1,1,1,9962.87,2218.32,1329.82,1.77101,0,0,0.774236,0.632897,300,0,1),
(@OGUID+9,186717,1,1,1,9963.64,2192.59,1328.52,4.74374,0,0,0.695937,-0.718103,300,0,1),
-- Eversong Woods
(@OGUID+10,178666,530,1,1,9333.24,-7265.71,13.7149,3.15074,0,0,0.99999,-0.00457361,300,0,1),
(@OGUID+11,178666,530,1,1,9330.88,-7289.79,13.7388,0.18586,0,0,0.0927961,0.995685,300,0,1),
(@OGUID+12,186717,530,1,1,9319.23,-7265.19,13.7578,2.02761,0,0,0.84885,0.528633,300,0,1),
(@OGUID+13,186717,530,1,1,9310.25,-7291.41,14.4908,2.53027,0,0,0.953648,0.300923,300,0,1),
(@OGUID+14,186221,530,1,1,9318.17,-7291.17,14.4236,0.649241,0,0,0.318949,0.947772,300,0,1),
(@OGUID+15,186257,530,1,1,9318.61,-7289.66,14.436,0.782759,0,0,0.381464,0.924384,300,0,1),
(@OGUID+16,186256,530,1,1,9341.19,-7288.21,14.3979,4.71368,0,0,0.70665,-0.707563,300,0,1),
(@OGUID+17,186255,530,1,1,9343.07,-7265.55,14.691,1.48569,0,0,0.676387,0.736546,300,0,1),
(@OGUID+18,180037,530,1,1,9316.77,-7283.36,13.7084,3.63768,0,0,0.969394,-0.24551,300,0,1),
(@OGUID+19,180037,530,1,1,9313.62,-7285.06,13.9541,3.38636,0,0,0.992521,-0.122077,300,0,1),
(@OGUID+20,180037,530,1,1,9308.97,-7280.39,14.447,5.40091,0,0,0.426971,-0.904265,300,0,1);

-- Make the above game objects only spawn if Brewfest is active
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+20;
INSERT INTO `game_event_gameobject` (`eventEntry`,`guid`) VALUES
(@EVENT,@OGUID+0),(@EVENT,@OGUID+1),(@EVENT,@OGUID+2),(@EVENT,@OGUID+3),
(@EVENT,@OGUID+4),(@EVENT,@OGUID+5),(@EVENT,@OGUID+6),(@EVENT,@OGUID+7),
(@EVENT,@OGUID+8),(@EVENT,@OGUID+9),(@EVENT,@OGUID+10),(@EVENT,@OGUID+11),
(@EVENT,@OGUID+12),(@EVENT,@OGUID+13),(@EVENT,@OGUID+14),(@EVENT,@OGUID+15),
(@EVENT,@OGUID+16),(@EVENT,@OGUID+17),(@EVENT,@OGUID+18),(@EVENT,@OGUID+19),
(@EVENT,@OGUID+20);

-- [Q] [H] Catch the Wild Wolpertinger!
-- Alliance version already had this
DELETE FROM `creature_involvedrelation` WHERE `id`=24657 AND `quest`=11431;
INSERT INTO `creature_involvedrelation` (`id`,`quest`) VALUES (24657,11431);
DELETE FROM `creature_questrelation` WHERE `id`=24657 AND `quest`=11431;
INSERT INTO `creature_questrelation` (`id`,`quest`) VALUES (24657,11431);

-- [Q] [A/H] Did Someone Say "Souvenir?" (removed in 2.4.3) & Say, There Wouldn't Happen to be a Souvenir This Year, Would There?
DELETE FROM `creature_questrelation` WHERE `quest` IN (11321,11413,12193,12194);
DELETE FROM `creature_involvedrelation` WHERE `quest` IN (11321,11413,12193,12194);

-- [Q] [A/H] Save Brewfest! should have pre-req Welcome to Brewfest!
UPDATE `quest_template` SET `PrevQuestId`=11442 WHERE `id`=12318;
-- [Q] [A/H] Save Brewfest! - removed in 2.4.3
DELETE FROM `creature_involvedrelation` WHERE `quest`=12318;
DELETE FROM `creature_questrelation` WHERE `quest`=12318;

-- [Q] [A/H] Another Year, Another Souvenir.
DELETE FROM `creature_involvedrelation` WHERE `id` IN (24495,23710) AND `quest` IN (13931,13932);
INSERT INTO `creature_involvedrelation` (`id`,`quest`) VALUES
(24495,13931), -- Horde
(23710,13932); -- Alliance
DELETE FROM `creature_questrelation` WHERE `id` IN (24510,24468) AND `quest` IN (13931,13932);
INSERT INTO `creature_questrelation` (`id`,`quest`) VALUES
(24510,13931), -- Horde
(24468,13932); -- Alliance

-- [Q] [A] Direbrew's Dire Brew - removed PrevQuestId in 2010
-- Horde version already had this
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `id`=12491;

-- Misc.
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=23698; -- Drunken Brewfest Reveler
UPDATE `creature_template_addon` SET `auras`='43905' WHERE `entry`=23698; -- Drunken Brewfest Reveler
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=23698; -- Drunken Brewfest Reveler
UPDATE `creature` SET `spawntimesecs`=450 WHERE `id`=24484; -- Brewfest Reveler had 12 hour respawntime ...

-- Send a mail on quest complete "Brew of the Month Club" - there is no wait time so we won't use RewMailDelaySecs
-- Alliance quest missed quest texts
SET @MAIL_A := 209;
SET @MAIL_H := 210;
UPDATE `quest_template` SET `RewardMailTemplateId`=@MAIL_A,`OfferRewardText`="Your paperwork looks to be in order. Welcome to the club, $N!$B$BYou can expect to get our mail at the start of every month. If you like what you got, stop by and we can sell you some more. This is the club that keeps on giving.",`RequestItemsText`="Do you have your membership forms filled out?" WHERE `id`=12420;
UPDATE `quest_template` SET `RewardMailTemplateId`=@MAIL_A WHERE `id`=12278;
UPDATE `quest_template` SET `RewardMailTemplateId`=@MAIL_H WHERE `id` IN (12306,12421);

-- Ray'ma and Larkin were also finishing quest no longer available within the game.
DELETE FROM `creature_involvedrelation` WHERE `quest` IN (12278,12306); -- old "Brew of the Month Club" quests
DELETE FROM `creature_involvedrelation` WHERE `id`=27489 AND `quest`=12421;
INSERT INTO `creature_involvedrelation` (`id`,`quest`) VALUES (27489,12421);

-- The alliance vendors were selling wrong item - Ray'ma already had one but Blix was missing
DELETE FROM `npc_vendor` WHERE `item` IN (37571,37736,37599,37737);
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(23710,0,37736,0,0,2276), -- Belbi Quikswitch
(27478,0,37736,0,0,2276), -- Larkin Thunderbrew
(27489,0,37737,0,0,2276), -- Ray'ma
(24495,0,37737,0,0,2276); -- Blix Fixwidget

-- Insert missing Pint-Sized Pink Pachyderm for 100 tokens
DELETE FROM `npc_vendor` WHERE `item`=46707;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(23710,0,46707,0,0,2275), -- Belbi Quikswitch
(27478,0,46707,0,0,2275), -- Larkin Thunderbrew
(24495,0,46707,0,0,2275), -- Blix Fixwidget
(27489,0,46707,0,0,2275); -- Ray'ma

-- Insert missing Brewfest Dress for 200 tokens
DELETE FROM `npc_vendor` WHERE `item`=33863;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(23710,0,33863,0,0,2276), -- Belbi Quikswitch
(27478,0,33863,0,0,2276), -- Larkin Thunderbrew
(24495,0,33863,0,0,2276), -- Blix Fixwidget
(27489,0,33863,0,0,2276); -- Ray'ma

-- Insert missing Brewfest Regalia for 200 tokens
DELETE FROM `npc_vendor` WHERE `item`=33862;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(23710,0,33862,0,0,2276), -- Belbi Quikswitch
(27478,0,33862,0,0,2276), -- Larkin Thunderbrew
(24495,0,33862,0,0,2276), -- Blix Fixwidget
(27489,0,33862,0,0,2276); -- Ray'ma

-- Insert missing Wolpertinger's Tankard
DELETE FROM `npc_vendor` WHERE `item`=32233;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(23710,0,32233,0,0,0), -- Belbi Quikswitch
(27478,0,32233,0,0,0), -- Larkin Thunderbrew
(24495,0,32233,0,0,0), -- Blix Fixwidget
(27489,0,32233,0,0,0); -- Ray'ma

-- Coren Direbrew Horde Loot fix by dele (closes #7297)
DELETE FROM `creature_loot_template` WHERE `entry`=23872 AND `item`=38281;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(23872, 38281, 100, 1, 2, 1, 1);

-- This One Time, When I Was Drunk... (12020) Alliance quest giver fix by nelegalno (closes #7823)
UPDATE `gameobject_questrelation` SET `id`=189989 WHERE `quest`=12020;

-- quest Bark for xyz Brewfest by LuckerNr1
-- Bark for Drohn's Distillery! 11407
-- Bark for T'chali's Voodoo Brewery! 11408
-- Bark for the Barleybrews! 11293
-- Bark for the Thunderbrews! 11294
UPDATE `quest_template` SET `SourceSpellId`=43883 WHERE `id` IN (11407,11408,11293,11294);
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4769,4772,4770,4774,4801,4802,4803,4804) AND `ScriptName`='SmartTrigger';
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4769,'SmartTrigger'),
(4772,'SmartTrigger'),
(4770,'SmartTrigger'),
(4774,'SmartTrigger'),
(4801,'SmartTrigger'),
(4802,'SmartTrigger'),
(4803,'SmartTrigger'),
(4804,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4769,4772,4770,4774,4801,4802,4803,4804) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4769,2,0,0,46,0,100,0,4769,0,0,0,33,24202,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Bank - on trigger - give killcredit'),
(4772,2,0,0,46,0,100,0,4772,0,0,0,33,24203,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Military Ward - on trigger - give killcredit'),
(4770,2,0,0,46,0,100,0,4770,0,0,0,33,24204,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Hall of Explorers - on trigger - give killcredit'),
(4774,2,0,0,46,0,100,0,4774,0,0,0,33,24205,0,0,0,0,0,7,0,0,0,0,0,0,0,'SW Mystic Ward - on trigger - give killcredit'),
(4801,2,0,0,46,0,100,0,4801,0,0,0,33,24202,0,0,0,0,0,7,0,0,0,0,0,0,0,'OG Auction House - on trigger - give killcredit'),
(4802,2,0,0,46,0,100,0,4802,0,0,0,33,24203,0,0,0,0,0,7,0,0,0,0,0,0,0,'OG Valley of Honor - on trigger - give killcredit'),
(4803,2,0,0,46,0,100,0,4803,0,0,0,33,24204,0,0,0,0,0,7,0,0,0,0,0,0,0,'OG Valley of Wisdom - on trigger - give killcredit'),
(4804,2,0,0,46,0,100,0,4804,0,0,0,33,24205,0,0,0,0,0,7,0,0,0,0,0,0,0,'OG Valley of Spirits - on trigger - give killcredit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (4769,4772,4770,4774,4801,4802,4803,4804) AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4769,2,0,1,0,43883,0,0,0,0,'',''),
(22,1,4772,2,0,1,0,43883,0,0,0,0,'',''),
(22,1,4770,2,0,1,0,43883,0,0,0,0,'',''),
(22,1,4774,2,0,1,0,43883,0,0,0,0,'',''),
(22,1,4801,2,0,1,0,43883,0,0,0,0,'',''),
(22,1,4802,2,0,1,0,43883,0,0,0,0,'',''),
(22,1,4803,2,0,1,0,43883,0,0,0,0,'',''),
(22,1,4804,2,0,1,0,43883,0,0,0,0,'','');
