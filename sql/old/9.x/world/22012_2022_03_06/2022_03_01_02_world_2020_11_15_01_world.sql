-- The sleeping one
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7346;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,7346,8759,0,0,8,0,9067,0,0,1,0,0,"","Group 0: Show gossip text 8759 if quest 'The Party Never Ends' is not rewarded"),
(14,7346,8760,0,0,8,0,9067,0,0,0,0,0,"","Group 0: Show gossip text 8760 if quest 'The Party Never Ends' is rewarded");

DELETE FROM `gossip_menu` WHERE `MenuID` = 7346 AND `TextID` = 8761;
DELETE FROM `gossip_menu` WHERE `MenuID` = 7347 AND `TextID` = 8761;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7347, 8761, 14545); -- 17056

DELETE FROM `smart_scripts` WHERE `entryorguid` = -59434 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-59434,0,0,0,64,0,100,0,0,0,0,0,0,98,7347,8761,0,0,0,0,7,0,0,0,0,0,0,0,0,"Eversong Partygoer - On Gossip Hello - Send Gossip");

UPDATE `creature_addon` SET `auras` = "42386" WHERE `guid` = 59434;

-- Rest
-- Change orientation to default
UPDATE `creature` SET `orientation` = 2.14675 WHERE `guid` = 59449 AND `id` = 17056;
-- Firework Guys are summoned
DELETE FROM `creature` WHERE `id` IN (15882,15883);
-- Emotes are set in script
UPDATE `creature_addon` SET `emote` = 0 WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 17056);
