SET @BRANN  := 29579;
SET @SNOW_TARGET := 29599;
SET @QUEST  := 12920;
SET @GOSSIP := 9853;

UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP, `minlevel`=80,`maxlevel`=80,`npcflag`=`npcflag`|1,`unit_flags`=`unit_flags`|32776, `AIName` = 'SmartAI', `equipment_id`=2485 WHERE `entry`=@BRANN;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry`=@SNOW_TARGET;
UPDATE `creature_model_info` SET `bounding_radius`=0.347,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=26356;
DELETE FROM `creature_template_addon` WHERE `entry` IN (@BRANN,@SNOW_TARGET);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@BRANN,0,0,2,0, ''),
(@SNOW_TARGET,0,0,1,0, '54717');
DELETE FROM `creature_equip_template` WHERE `entry`=2485;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(2485,0,0,25972);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@BRANN;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@BRANN,46598,1,1);
DELETE FROM `vehicle_template_accessory` WHERE `entry`=@BRANN;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(@BRANN,@SNOW_TARGET,0,1,'Brann Snow Target',7,0);

DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=13641;
DELETE FROM `gossip_menu` WHERE `entry`=10145 AND `text_id`=14089;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(@GOSSIP,13641),(10145,14089);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP AND `id` IN (0,1);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(@GOSSIP,0,0,'Do you understand me? We should be able to understand each other now.',1,1,0,0,0,0,''),
(@GOSSIP,1,0,'What kind of help do you require?',1,1,10145,0,0,0,'');

DELETE FROM `creature_text` WHERE `entry`=@BRANN;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@BRANN,0,0,"I... I can understand you now! Well, now that we can talk to each other, you have some explaining to do!",12,0,100,5,0,0,'Brann Bronzebeard text0'),
(@BRANN,1,0,"How did you get my communicator from the Explorers League?",12,0,100,5,0,0,'Brann Bronzebeard text1'),
(@BRANN,2,0,"If the Explorers League sent men, I didn't see any trace of them. I found your note buried in a camp overrun by iron dwarves.",12,0,100,0,0,0,'Player text2'),
(@BRANN,3,0,"You have my thanks for dispatching the iron dwarves. But why would the Horde have an interest in me?",12,0,100,6,0,0,'Brann Bronzebeard text3'),
(@BRANN,4,0,"A scout found the remains of your journal in Thor Modan. We've been looking for you ever since.",12,0,100,0,0,0,'Player text4'),
(@BRANN,5,0,"That wouldn't be Scout Vor'takh, would it? Even I know of his reputation for ruthlessness. He means to abduct me, then?",12,0,100,5,0,0,'Brann Bronzebeard text5'),
(@BRANN,6,0,"If you've seen the journal, then you know what I've been discovering. The titans' own creations are at war with each other!",12,0,100,5,0,0,'Brann Bronzebeard text6'),
(@BRANN,7,0,"Loken and his iron dwarf minions have ousted the Earthen from Ulduar and taken over the city.",12,0,100,5,0,0,'Brann Bronzebeard text7'),
(@BRANN,8,0,"If we spend our time and strength fighting with each other, Loken will use Ulduar's resources to destroy both Horde and Alliance.",12,0,100,6,0,0,'Brann Bronzebeard text8'),
(@BRANN,9,0,"Speak to the commander at your post, lad, and persuade him to abandon Vor'takh's foolish plan.",12,0,100,6,0,0,'Brann Bronzebeard Text10');

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@BRANN,@SNOW_TARGET);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@BRANN*100;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@BRANN,0,0,1,62,0,100,0,@GOSSIP,0,0,0,11,55579,2,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard - On gossip select - Spellcast Trigger Brann Signal'),
(@BRANN,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard - On gossip select - Close gossip'),
(@BRANN,0,2,0,8,0,100,0,55578,0,0,0,80,@BRANN*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Brann Bronzebeard - On spellhit Brann Signal to Self - Start script'),
(@SNOW_TARGET,0,0,0,11,0,100,0,0,0,0,0,3,0,26241,0,0,0,0,1,0,0,0,0,0,0,0,'Brann Snow Target - On spawn - Morph to model'),
(@BRANN*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text0'),
(@BRANN*100,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text0'),
(@BRANN*100,9,2,0,0,0,100,0,3100,3100,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,'Brann Bronzebeard script - Play emote point'),
(@BRANN*100,9,3,0,0,0,100,0,3200,3200,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text1'),
(@BRANN*100,9,4,0,0,0,100,0,5600,5600,0,0,84,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Player say text2'),
(@BRANN*100,9,5,0,0,0,100,0,6300,6300,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text3'),
(@BRANN*100,9,6,0,0,0,100,0,7200,7200,0,0,84,4,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Player say text4'),
(@BRANN*100,9,7,0,0,0,100,0,6400,6400,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text5'),
(@BRANN*100,9,8,0,0,0,100,0,7200,7200,0,0,1,6,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text6'),
(@BRANN*100,9,9,0,0,0,100,0,7200,7200,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text7'),
(@BRANN*100,9,10,0,0,0,100,0,7200,7200,0,0,1,8,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text8'),
(@BRANN*100,9,11,0,0,0,100,0,7100,7100,0,0,1,9,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Say text9'),
(@BRANN*100,9,12,0,0,0,100,0,3000,3000,0,0,33,@BRANN,0,0,0,0,0,7,0,0,0,0,0,0,0,'Brann Bronzebeard script - Quest credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=55578;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,55578,0,31,3,@BRANN,0,0,'', 'Spell Brann Signal to Self targets Brann'),
(15,@GOSSIP,0,0,9,@QUEST,0,0,0,'', 'Show gossip menu option if player has quest 12920'),
(15,@GOSSIP,1,0,9,12926,0,0,0,'', 'Show gossip menu option if player has quest 12926');
