-- TODO: Fix core scripts (40301, 40312)
-- TODO: Fix invisibility detection issue (core)

-- Creature templates
UPDATE `creature_template_addon` SET `auras`='75165 75180 22650' WHERE `entry`=40305; -- 40305 (Spirit of the Tiger)

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuID`=11394);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11394, 15873, 53788), -- 40492 (Zild'jian)
(11394, 15872, 53788), -- 40492 (Zild'jian)
(11394, 15871, 53788); -- 40492 (Zild'jian)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=21257);
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=11341 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(11341, 0, 0, 'Would you call down the Spirit of the Tiger again, Vanira?', 40445, 1, 1, 0, 0, 0, 0, NULL, 0, 53788);

DELETE FROM `npc_text` WHERE `ID`=15872;
INSERT INTO `npc_text` (`ID`, `text0_0`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(15872, 'De Echo Isles attack be startin'' soon!$B$BSit back and relax, dis song will be over in anotha $5071W minutes and then we''d be going.', 1, 0, 0, 0, 0, 0, 0, 0, 40475, 0, 0, 0, 0, 0, 0, 0, 53788); -- 15872

UPDATE `npc_text` SET `VerifiedBuild`=53788 WHERE `ID` IN (15865, 15873, 15877, 15876);
UPDATE `npc_text` SET `VerifiedBuild`=53788 WHERE `ID` IN (15806, 15846, 15796);

-- Misc
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (74903, 74977);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (75159, 75160, 75161);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11341;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=21257;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 74903, 0, 0, 31, 0, 3, 40187, 0, 0, 0, 0, '', 'Spell "Attune" can only target Vanira''s Sentry Totem'),
(13, 1, 74977, 0, 0, 31, 0, 3, 40218, 0, 0, 0, 0, '', 'Spell "Frogs Away!" can only target Spy Frog Credit'),
(17, 0, 75159, 0, 0, 31, 1, 3, 40312, 0, 0, 12, 0, '', 'Spell "Claw" can only target Tiger Matriarch'),
(17, 0, 75160, 0, 0, 31, 1, 3, 40312, 0, 0, 12, 0, '', 'Spell "Bloody Rip" can only target Tiger Matriarch'),
(17, 0, 75161, 0, 0, 31, 1, 3, 40312, 0, 0, 12, 0, '', 'Spell "Spinning Rake" can only target Tiger Matriarch'),
(15, 11341, 0, 0, 0, 47, 0, 25470, 10, 0, 0, 0, 0, '', 'Gossip menu option requires quest 25470 taken or completed'),
(15, 11341, 0, 0, 0, 1, 0, 75166, 0, 0, 1, 0, 0, '', 'Gossip menu option requires aura 25470 not applied');

UPDATE `creature_addon` SET `auras`='75038' WHERE `guid`=213977;

-- Quests
DELETE FROM `quest_details` WHERE `ID`=25470;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25470, 1, 1, 1, 0, 0, 0, 0, 0, 53788); -- Lady Of Da Tigers

DELETE FROM `quest_request_items` WHERE `ID`=25470;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `CompletionText`, `VerifiedBuild`) VALUES
(25470, 0, 1, 'Did you find out anythin'' about that tiger?', 53788); -- Lady Of Da Tigers

UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `VerifiedBuild`=53788 WHERE `ID`=25470; -- Lady Of Da Tigers

DELETE FROM `game_event_creature_quest` WHERE (`id`=40184 AND `quest` IN (25470));
DELETE FROM `creature_queststarter` WHERE (`id`=40184 AND `quest`=25470);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(40184, 25470); -- Lady Of Da Tigers offered by Vanira

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (40305);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (40184, 40305) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4018400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40184,0,0,0,19,0,100,0,25470,0,0,0,0,80,4018400,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Vanira - On quest 25470 taken - Call timed actionlist'),
(40184,0,1,2,62,0,100,0,11341,0,0,0,0,11,75186,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Vanira - On gossip option 0 selected - Cast "Force Cast Spirit of the Tiger" on invoker'),
(40184,0,2,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Vanira - Event linked - Close gossip'),
(4018400,9,0,0,0,0,100,0,0,0,0,0,0,11,75186,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Actionlist - Vanira - Cast "Force Cast Spirit of the Tiger" on invoker'),
(4018400,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,'Actionlist - Vanira - Say line 1'),
(4018400,9,2,0,0,0,100,0,0,0,0,0,0,11,60957,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Vanira - Cast "Cosmetic Nature Cast"'),
(4018400,9,3,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Actionlist - Vanira - Face invoker'),
(4018400,9,4,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Actionlist - Vanira - Set original orientation'),

(40305,0,0,0,27,0,100,512,0,0,0,0,0,11,75166,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Spirit of the Tiger - On passenger boarded - Cast "Spirit of the Tiger Aura (Rider)"'),
(40305,0,1,0,28,0,100,512,0,0,0,0,0,11,75167,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Spirit of the Tiger - On passenger removed - Cast "Cancel Spirit of the Tiger"'),
(40305,0,2,0,6,0,100,512,0,0,0,0,0,11,50630,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Spirit of the Tiger - On death - Cast "Eject All Passengers"'),
(40305,0,3,4,60,0,100,512,500,500,3000,3000,0,1,0,0,1,0,0,0,23,0,0,0,0,0,0,0,0,'Spirit of the Tiger - On update (every 10s) - Say line 1'),
(40305,0,4,0,61,0,100,512,0,0,0,0,0,41,2500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Spirit of the Tiger - Event linked - Despawn');

DELETE FROM `creature_text` WHERE `CreatureID` IN (40305);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(40305, 0, 0, 'You must remain in the Echo Isles, Darkspear Strand, or Sen''jin Village.', 42, 0, 100, 0, 0, 0, 40345, 0, 'Spirit of the Tiger');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=40305;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=4 AND `SourceEntry`=40305 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 4, 40305, 0, 0, 23, 1, 367, 0, 0, 1, 0, 0, '', 'Smart event requires area not allowed'),
(22, 4, 40305, 0, 0, 23, 1, 368, 0, 0, 1, 0, 0, '', 'Smart event requires area not allowed'),
(22, 4, 40305, 0, 0, 23, 1, 393, 0, 0, 1, 0, 0, '', 'Smart event requires area not allowed');
