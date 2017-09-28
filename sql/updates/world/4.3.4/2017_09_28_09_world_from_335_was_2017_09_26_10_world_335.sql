/*
-- Remorseful Highborne --> Add gossip texts
UPDATE `creature_template` SET `gossip_menu_id`=3803 WHERE `entry`=10684;

DELETE FROM `gossip_menu` WHERE `MenuID`=3803;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(3803,4635,0),
(3803,4636,0);

DELETE FROM `npc_text` WHERE `ID`=4636;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`) VALUES
(4636,'',"I will not forrrget what you have done...$B$BPleassse, leave meee...",7309,0,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=3803;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,3803,4636,0,0,8,0,5248,0,0,0,0,0,'',"Remorseful Highborne - Show Gossip Menu Text 4636 if Quest 5248 is rewarded");

-- Remorseful Highborne --> Add texts on quest finished
DELETE FROM `creature_text` WHERE `CreatureID`=10684;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10684,0,0,"Highborne spirits! Be at peace! The Crystal of Zin-Malor is whole once again!",14,0,100,0,0,0,6505,0,"Remorseful Highborne"),
(10684,0,1,"Cursed spirits! Let go of the past! The Crystal of Zin-Malor no longer binds you!",14,0,100,0,0,0,6506,0,"Remorseful Highborne"),
(10684,0,2,"Spirits of the Highborne! You may now rest! The curse of the crystal releases you!",14,0,100,0,0,0,6507,0,"Remorseful Highborne");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10684;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10684 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10684,0,0,0,20,0,100,0,5248,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Remorseful Highborne - On Quest \'Tormented by the Past\' Finished - Say Line 0");
*/
