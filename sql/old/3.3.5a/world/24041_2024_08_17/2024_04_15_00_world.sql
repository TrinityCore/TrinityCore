-- TODO: Check actionlist (missing emotes, summons and waypoints)

-- Gossips
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=11375 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(11375, 0, 0, 'Let us consult the omens.', 40385, 1, 1, 0, 0, 0, 0, NULL, 0, 53788);

-- Misc
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11375;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11375, 0, 0, 0, 47, 0, 25480, 10, 0, 0, 0, 0, '', 'Gossip menu option requires quest 25480 taken or completed');

-- Quests
DELETE FROM `quest_details` WHERE `ID`=25480;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25480, 1, 1, 0, 0, 0, 0, 0, 0, 53788); -- Dance Of De Spirits

DELETE FROM `quest_request_items` WHERE `ID`=25480;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(25480, 0, 1, 'Well, what do de omens tell us?', 53788); -- Dance Of De Spirits

UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=53788 WHERE `ID`=25480; -- Dance Of De Spirits

DELETE FROM `game_event_creature_quest` WHERE (`id`=40391 AND `quest`=25480);
DELETE FROM `creature_queststarter` WHERE (`id`=40391 AND `quest`=25480);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(40391, 25480); -- Dance Of De Spirits offered by Vol'jin

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=40352 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40352,0,0,1,62,0,100,0,11375,0,0,0,0,80,4035200,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Witch Doctor Hez''tok - On gossip option 0 selected - Call timed actionlist'),
(40352,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Witch Doctor Hez''tok - Event linked - Close gossip');
