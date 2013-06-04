UPDATE `conditions` SET `ConditionValue2`=27827,`Comment`='Dispelling Illusions: Crate Dummy target' WHERE `SourceEntry`=49590;
DELETE FROM `creature` WHERE `id`=30996;
UPDATE `creature` SET `modelId`=0,`spawndist`=0,`MovementType`=0 WHERE `id` IN (27827,28960);
UPDATE `creature_template` SET `modelid1`=22712,`modelid2`=17200,`flags_extra`=`flags_extra`|128 WHERE `entry`=27827; -- reverse models (parsers fault)
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=28960; -- reverse models (parsers fault)

DELETE FROM `creature_text` WHERE `entry`=27915;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27915,0,0, 'Good work with the crates! Come talk to me in front of Stratholme for your next assignment!',4,0,0,0,0,0, 'Chromie - SAY_EVENT_START');
