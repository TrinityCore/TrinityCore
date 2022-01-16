SET @CGUID := 1050433;

-- Creature (Both Creatures have the Wrong Phase!!!)
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 168011, 2222, 10565, 13499, '0', 0, 0, 0, 0, -1873.1754150390625, 1426.9896240234375, 5267.671875, 5.052110671997070312, 7200, 0, 0, 117910, 0, 0, 0, 0, 0, 41488), -- Zo'sorg (Area: -Unknown- - Difficulty: 0)
(@CGUID+1, 164100, 2222, 10565, 13499, '0', 0, 0, 0, 0, -1955.7899169921875, 1318.609375, 5266.95703125, 0.521554529666900634, 7200, 0, 0, 11791, 0, 0, 0, 0, 0, 41488); -- Emissary Ba'silk (Area: -Unknown- - Difficulty: 0)

UPDATE `creature_template` SET `gossip_menu_id`=25288 WHERE `entry`=164100; -- Emissary Ba'silk
UPDATE `creature_template` SET `gossip_menu_id`=25685 WHERE `entry`=168011; -- Zo'sorg

-- Queststarter & ender
DELETE FROM `creature_queststarter` WHERE `id` IN  (156688, 178908) AND `quest` IN (63976, 63977, 63979, 63980);
INSERT INTO `creature_queststarter`(`id`, `quest`) VALUES
(156688, 63976),
(178908, 63977),
(178908, 63979),
(178908, 63980);

DELETE FROM `creature_questender` WHERE `id` IN (178908, 160090) AND `quest` IN (63976, 63977, 63979, 63980);
INSERT INTO `creature_questender`(`id`, `quest`) VALUES
(178908, 63976),
(178908, 63977),
(178908, 63979),
(160090, 63980); -- Creature is not yet spawned (Revendreth)

-- Quest stuff
DELETE FROM `quest_template_addon` WHERE `ID` IN (63977, 63979);
INSERT INTO `quest_template_addon`(`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(63977, 0, 0, 0, 63976, 63980, -63977, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(63979, 0, 0, 0, 63976, 63980, -63977, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_offer_reward` WHERE `ID` IN (63976, 63979, 63977);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(63976, 0, 0, 0, 0, 0, 0, 0, 0, 'It is a pleasure to meet you.', 41488), -- The Al'ley Cat of Oribos
(63979, 1, 1, 0, 0, 0, 0, 0, 0, 'Tazavesh, the Veiled Market...\n\nAn interesting choice of locations.', 41488), -- Things Best Kept Dark
(63977, 1, 0, 0, 0, 0, 0, 0, 0, 'How rude! They should be aware of who they are talking to.\n\nI apologize for my kin, Maw Walker.', 41488); -- Insider Trading

DELETE FROM `quest_greeting` WHERE (`ID`=178908 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(178908, 0, 0, 0, 'The Shadowlands contain many secrets. Some should not be discovered.', 41488); -- 178908

DELETE FROM `quest_details` WHERE `ID` IN (63979, 63977, 63976, 60274, 63980);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(63979, 1, 0, 0, 0, 0, 0, 0, 0, 41488), -- Things Best Kept Dark
(63977, 1, 0, 0, 0, 0, 0, 0, 0, 41488), -- Insider Trading
(63976, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- The Al'ley Cat of Oribos
(60274, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Trading Favors
(63980, 1, 0, 0, 0, 0, 0, 0, 0, 41488); -- Seeking Smugglers

DELETE FROM `quest_request_items` WHERE `ID` IN (63979 /*Things Best Kept Dark*/, 63977 /*Insider Trading*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(63979, 0, 0, 0, 0, 'Have you found anything?', 0), -- Things Best Kept Dark
(63977, 0, 0, 0, 0, 'Have you had a chance to speak with the other cartels?', 41488); -- Insider Trading


-- Conversation stuff
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (17009, 17010, 17011)  AND `Idx`=0;
INSERT INTO `conversation_actors`(`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `VerifiedBuild`) VALUES
(17011, 81676, 1050144, 0, 0, 0, 41488),
(17009, 81676, 1050144, 0, 0, 0, 41488),
(17010, 81676, 1050144, 0, 0, 0, 41488);

DELETE FROM `conversation_line_template` WHERE `Id` IN (43060, 43057, 43058, 43059);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(43057, 0, 0, 0, 41488),
(43060, 0, 0, 0, 41488),
(43058, 0, 0, 0, 41488),
(43059, 0, 0, 0, 41488);

DELETE FROM `conversation_template` WHERE `Id` IN (17009, 17010, 17011);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(17009, 43060, 0, 41488),
(17011, 43057, 0, 41488),
(17010, 43059, 0, 41488);

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 10565 AND `PhaseId` =17339;
INSERT INTO `phase_area`(`AreaId`, `PhaseId`, `Comment`) VALUES
(10565, 17339, 'Oribos - Al\'dalil');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (22, 26, 15) AND `SourceGroup` IN (1, 17339, 25621, 25288, 25623, 25685) AND `SourceEntry` IN (178908, 10565, 0, 1, 2);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 17339, 10565, 0, 1, 47, 0, 63976, 66, 0, 0, 0, 0, '', 'Allow Phase 17339 if Quest 63976 IS complete/rewarded'),
(26, 17339, 10565, 0, 1, 8, 0, 63986, 0, 0, 1, 0, 0, '', 'Allow Phase 17339 if Quest 63986 IS NOT rewarded'),
(22, 1, 178908, 0, 0, 28, 0, 63976, 0, 0, 0, 0, 0, '', 'Al´dalil - Allow SAI Script Row 0 if Quest 63976 is complete'),
(15, 25621, 1, 0, 0, 47, 0, 63977, 10, 0, 0, 0, 0, '', 'Allow Gossip Menu if Quest 63977 is taken/complete'),
(15, 25288, 1, 0, 0, 47, 0, 63977, 10, 0, 0, 0, 0, '', 'Allow Gossip Menu if Quest 63977 is taken/complete'),
(15, 25623, 2, 0, 0, 47, 0, 63977, 10, 0, 0, 0, 0, '', 'Allow Gossip Menu if Quest 63977 is taken/complete'),
(15, 25685, 1, 0, 0, 47, 0, 63977, 10, 0, 0, 0, 0, '', 'Allow Gossip Menu if Quest 63977 is taken/complete');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (156768, 164100, 167738, 168011, 178997) AND `GroupID` = 0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(156768, 0, 0, 'Cartel Ta avoids meddling in the affairs of others. It is to protect business. I am sure you understand.', 12, 0, 100, 1, 0, 181675, 210211, 'Overseer Ta\'readon to Player'),
(164100, 0, 0, 'We have little to gain from lesser cartels. Whatever Cartel Al and Cartel So are bickering over, it is not our concern.', 12, 0, 100, 274, 0, 181674, 210218, 'Emissary Ba\'silk to Player'),
(167738, 0, 0, 'You have been seen with Al\'dalil. A word of caution: choose your friends carefully, and your enemies more so.', 12, 0, 100, 1, 0, 181673, 210216, 'Foreman Au\'brak to Player'),
(168011, 0, 0, 'Zo\'sorg waves off your question, shooing you away.', 16, 0, 100, 274, 0, 0, 0, 'Zo\'sorg to Player'),
(178997, 0, 0, 'You there! That is the property of Cartel So!', 12, 0, 100, 5, 0, 181676, 210230, 'So\'danah to Player');

UPDATE `creature_text` SET `TextRange`=5 WHERE `CreatureID` IN (156768, 164100, 167738, 168011, 178997) AND `GroupID` = 0;

-- NPC Text
DELETE FROM `npc_text` WHERE `ID` IN (39872, 39871, 40527);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(39872, 1, 0, 0, 0, 0, 0, 0, 0, 189340, 0, 0, 0, 0, 0, 0, 0, 41488), -- 39872
(39871, 1, 0, 0, 0, 0, 0, 0, 0, 189338, 0, 0, 0, 0, 0, 0, 0, 41488), -- 39871
(40527, 1, 0, 0, 0, 0, 0, 0, 0, 196603, 0, 0, 0, 0, 0, 0, 0, 41488); -- 40527

-- Gossips
DELETE FROM `gossip_menu` WHERE (`MenuId`=25676 AND `TextId`=40527) OR (`MenuId`=25685 AND `TextId`=40543) OR (`MenuId`=25288 AND `TextId`=39871) OR (`MenuId`=25287 AND `TextId`=39872);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(25676, 40527, 41488), -- 167738 (Foreman Au'brak)
(25685, 40543, 41488), -- 168011 (Zo'sorg)
(25288, 39871, 41488), -- 164100 (Emissary Ba'silk)
(25287, 39872, 41488); -- 164100 (Emissary Ba'silk)

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=25623 AND `OptionIndex`=1) OR (`MenuId`=25288 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(25623, 1, 25676, 0),
(25288, 0, 25287, 0);

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (25621, 25288, 25623, 25685) AND `OptionIndex` IN (0, 1, 2);
INSERT INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(25621, 1, 0, 'What can you tell me about Cartel So?', 0, 1, 1, 41488),
(25288, 0, 0, 'Your kind are guests here?', 0, 1, 1, 41488),
(25288, 1, 0, 'What can you tell me about Cartel So?', 0, 1, 1, 41488),
(25623, 1, 0, 'What are you offering here?', 0, 1, 1, 41488),
(25623, 2, 0, 'What can you tell me about Cartel So?', 0, 1, 1, 41488),
(25685, 0, 1, 'Show me your wares.', 58437, 3, 128, 41488),
(25685, 1, 0, 'What can you tell me about Cartel So?', 0, 1, 1, 41488);

-- SET SAI in Template
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (178908, 156768, 164100, 167738, 168011);

-- SAI Scripts
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (178908, 156768, 164100, 167738, 168011) AND `source_type` IN (0, 1);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(178908, 0, 0, 0, 10, 0, 100, 0, 1, 10, 20000, 20000, 0, '', 143, 17009, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Al´dalil - On OOC LOS (10y) - Start Conversation 17009 - To Invoker'),
(178908, 0, 1, 0, 20, 0, 100, 0, 63976, 0, 0, 0, 0, '', 143, 17011, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Al´dalil - On Quest reward 63976 - Start Conversation 17011 - To Invoker'),
(178908, 0, 2, 0, 19, 0, 100, 0, 63980, 0, 0, 0, 0, '', 143, 17010, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Al´dalil - On Quest accept 63990 - Start Conversation 17010 - To Invoker'),
(156768, 0, 0, 1, 62, 0, 100, 0, 25621, 1, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Overseer Ta´readon - On Gossip Select 1 - Say Text 1 0 - To Invoker'),
(156768, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, 178970, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Overseer Ta´readon - On On SAI Link 0 - grant Credit 178970 - To Invoker'),
(156768, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Overseer Ta´readon - On SAI Link 1 - Close Gossip - To Invoker'),
(164100, 0, 0, 1, 62, 0, 100, 0, 25288, 1, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Emissary Ba´silk - On Gossip Select 1 - Say Text 1 0 - To Invoker'),
(164100, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, 178969, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Emissary Ba´silk - On On SAI Link 0 - grant Credit 178969 - To Invoker'),
(164100, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Emissary Ba´silk - On SAI Link 1 - Close Gossip - To Invoker'),
(167738, 0, 0, 1, 62, 0, 100, 0, 25623, 2, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Foreman Au´brak - On Gossip Select 2 - Say Text 1 0 - To Invoker'),
(167738, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, 178971, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Foreman Au´brak - On On SAI Link 0 - grant Credit 178971 - To Invoker'),
(167738, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Foreman Au´brak - On SAI Link 1 - Close Gossip - To Invoker'),
(168011, 0, 0, 1, 62, 0, 100, 0, 25685, 1, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Zo´sorg - On Gossip Select 1 - Say Text 1 0 - To Invoker'),
(168011, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, 178972, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Zo´sorg - On On SAI Link 0 - grant Credit 178972 - To Invoker'),
(168011, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Zo´sorg - On SAI Link 1 - Close Gossip - To Invoker');
