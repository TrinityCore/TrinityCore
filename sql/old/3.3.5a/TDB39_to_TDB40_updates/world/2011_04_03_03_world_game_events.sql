SET @Event = 63;
SET @GUID = 209029;

-- Elder Clearwater
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|768,`equipment_id`=589 WHERE `entry`=38294; -- Elder Clearwater
UPDATE `creature_model_info` SET `bounding_radius`=0.6076385,`combat_reach`=2.625,`gender`=2 WHERE `modelid`=23657; -- Elder Clearwater
DELETE FROM `creature_template_addon` WHERE `entry`=38294;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(38294,0,0,1,0, NULL);

DELETE FROM `creature` WHERE `id`=38294;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(@GUID,38294,571,1,1,0,0,5699.039,617.319458,646.797363,0.8552113,120,0,0,1,0,0,0);

DELETE FROM `game_event` WHERE `eventEntry` IN (@Event,@Event+1);
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`) VALUES
(@Event+0, '2011-01-03 13:00:00', '2020-12-31 05:00:00',10080,3*60,0, 'Kalu''ak Fishing Derby Turn-ins',0),
(@Event+1, '2011-01-03 14:00:00', '2020-12-31 05:00:00',10080,1*60,0, 'Kalu''ak Fishing Derby Fishing Pools',0); -- to be used with conditions

DELETE FROM `game_event_creature` WHERE `guid`=@GUID;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(@Event,@GUID);

-- And I thought that these were wdb fields...
UPDATE `quest_template` SET `RequestItemsText`='I''m afraid we''ve already had a winner for today, young $N. However, if you bring a shark, I''ll see that it''s released back into the waters, and I might just have a little something for you...',
`OfferRewardText`='Well, it''s nice that you tried $R. I don''t want you to think your efforts were wasted, so I''ve got something for you.' WHERE `entry`=24806; -- Better Luck Next Time
UPDATE `quest_template` SET `RequestItemsText`='The Kalu''ak have a long tradition of honing our fishing skills by putting them to the the test every week.$B$BThe first person to catch and bring a blacktip shark to me will be rewarded handsomely, and be known as the greatest fisherman of the north... for a couple days at least.$B$BThe blacktip shark''s favorite food is the pygmy suckerfish. Try fishing for the blacktip wherever you would normally catch the suckerfish.',
`OfferRewardText`='Don''t just stand there! Give me the shark and I''ll declare you the winner!' WHERE `entry` =24803; -- Kalu'ak Fishing Derby
