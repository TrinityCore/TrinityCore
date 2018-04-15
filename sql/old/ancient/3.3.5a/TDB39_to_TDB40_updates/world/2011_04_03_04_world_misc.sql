SET @GUID = 209030; -- Need 2 - creature.guid
SET @BotH = 35607; -- Reginald Arcfire
SET @BotA = 35594; -- Brassbolt Mechawrench

UPDATE `creature_template` SET `npcflag`=`npcflag`|1|2097152,`speed_run`=0.99206,`flags_extra`=`flags_extra`|2 WHERE `entry`=@BotA; -- Brassbolt Mechawrench
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=`npcflag`|1|2097152,`speed_run`=0.99206 WHERE `entry`=@BotH; -- Reginald Arcfire

UPDATE `creature_model_info` SET `bounding_radius`=0.465,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=28282;

DELETE FROM `creature_addon` WHERE `guid`=85057; -- old spawn
DELETE FROM `creature_template_addon` WHERE `entry` IN (@BotH,@BotA);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@BotH,0,65536,1,0, '60191 0'), -- Reginald Arcfire
(@BotA,0,65536,1,0, '60190 0'); -- Brassbolt Mechawrench

DELETE FROM `creature` WHERE `id` IN (@BotH,@BotA);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`) VALUES
(@GUID+0,@BotH,571,1,1,5927.63500,731.5764,643.253052,4.694936,120),
(@GUID+1,@BotA,571,1,1,5927.62939,731.5903,643.253052,4.764749,120);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10656;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10656,0,6,NULL,13,2097152,0,0,0,0,0,NULL);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10656;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(15,10656,0,7,202,350, 'Steam-Powered Auctioneer - Engineering 350');

DELETE FROM `spell_area` WHERE `spell` IN (60197,60194);
INSERT INTO `spell_area` (`spell`,`area`,`racemask`,`gender`,`autocast`) VALUES
(60197,4395,690,2,1), -- Reginald Arcfire
(60194,4395,1101,2,1); -- Brassbolt Mechawrench
