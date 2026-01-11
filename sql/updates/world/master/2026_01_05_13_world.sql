-- Aspectral Invitation (66577)

DELETE FROM `conversation_actors` WHERE (`ConversationId`=17844 AND `Idx`=1);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(17844, 64220, 1, 184650, 107146, 0, 0, 64978);

DELETE FROM `scene_template` WHERE `SceneId`=3017;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(3017, 27, 3511, 0);

UPDATE `quest_offer_reward` SET `RewardText`='I cannot wait to see the Dragon Isles with you, $p!\n\nNow then, I believe that diminutive ally of yours said something about putting together an expedition.', `VerifiedBuild`=64978 WHERE `ID`=66577; -- Aspectral Invitation
UPDATE `quest_offer_reward` SET `VerifiedBuild`=64978 WHERE `ID`=65436;

DELETE FROM `quest_objectives` WHERE `ID`=427235;
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `SecondaryAmount`, `Flags`, `Flags2`, `ProgressBarWeight`, `ParentObjectiveID`, `Visible`, `Description`, `VerifiedBuild`) VALUES
(427235, 66577, 0, 0, 0, 189569, 1, 0, 0, 0, 0, 0, 1, 'Speak with Wrathion', 64978); -- Aspectral Invitation - Speak with Wrathion

DELETE FROM `quest_offer_reward_conditional` WHERE (`QuestId`=66577 AND `PlayerConditionId`=99433 AND `QuestgiverCreatureId`=0 AND `locale`='enUS');
INSERT INTO `quest_offer_reward_conditional` (`QuestId`, `PlayerConditionId`, `QuestgiverCreatureId`, `locale`, `Text`, `OrderIndex`, `VerifiedBuild`) VALUES
(66577, 99433, 0, 'enUS', 'There is much more to the Dragon Isles beyond the Forbidden Reach. I cannot wait for you to see it!\n\nNow then, I believe that diminutive archaeologist said something about putting together an expedition.', 0, 64978); -- Aspectral Invitation

UPDATE `creature_template_gossip` SET `VerifiedBuild`=64978 WHERE (`CreatureID`=189569 AND `MenuID`=28666);
UPDATE `gossip_menu` SET `VerifiedBuild`=64978 WHERE (`MenuID`=28666 AND `TextID`=590013);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=64978 WHERE (`MenuID`=28666 AND `OptionID`=1);

 -- Wrathion smart ai
SET @ENTRY := 189569;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `id` IN (1, 2) AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 28666, 1, 0, 0, 0, 129, 3017, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 28666 selected - Gossip player: Starts playing scene with Id: 3017', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 33, 189569, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 1 from menu 28666 selected - Gossip player: Give kill credit Wrathion (189569)', '');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 189569 AND `SourceGroup` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 2, 189569, 0, 0, 9, 0, 66577, 0, 0, '', 0, 'Action invoker has quest Aspectral Invitation (66577) active');