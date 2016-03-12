/*
SET @Pool := 370;

UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE  `ID` IN(12604,12541,12502,12509,12519,12502,12509,12519,12588,12591,12594,12557,12597,12598,12599,12564,12568,12585);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND`SourceEntry` IN(12541,12604,12502,12509,12519,12502,12509,12519,12588,12591,12594,12557,12597,12598,12599,12564,12568,12585);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19, 0, 12604, 0, 0, 1, 0, 51573, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Congratulations!' if player has aura 51573 'On Patrol'."),
(20, 0, 12604, 0, 0, 1, 0, 51573, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Congratulations!' if player has aura 51573 'On Patrol'."),
(19, 0, 12604, 0, 0, 1, 0, 53707, 0, 0, 1, 0, 0, '', "Show quest mark 12604 'Congratulations!' if player has no aura 51573 'On Patrol Heartbeat Script'."),
(20, 0, 12604, 0, 0, 1, 0, 53707, 0, 0, 1, 0, 0, '', "Show quest mark 12604 'Congratulations!' if player has no aura 51573 'On Patrol Heartbeat Script'."),
(19, 0, 12541, 0, 0, 9, 0, 12501, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Troll Patrol: The Alchemists Apprentice' if player has quest Troll patrol'."),
(20, 0, 12541, 0, 0, 9, 0, 12501, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Troll Patrol: The Alchemists Apprentice' if player has quest Troll patrol'."),
(19, 0, 12541, 0, 1, 9, 0, 12563, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Troll Patrol: The Alchemists Apprentice' if player has quest Troll patrol'."),
(20, 0, 12541, 0, 1, 9, 0, 12563, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Troll Patrol: The Alchemists Apprentice' if player has quest Troll patrol'."),
(19, 0, 12541, 0, 2, 9, 0, 12587, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Troll Patrol: The Alchemists Apprentice' if player has quest Troll patrol'."),
(20, 0, 12541, 0, 2, 9, 0, 12587, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Troll Patrol: The Alchemists Apprentice' if player has quest Troll patrol'."),
(19, 0, 12509, 0, 0, 9, 0, 12501, 0, 0, 0, 0, 0, '', "Show quest mark 12509 'Troll Patrol: Intestinal Fortitude' if player has quest Troll patrol'."),
(20, 0, 12509, 0, 0, 9, 0, 12501, 0, 0, 0, 0, 0, '', "Show quest mark 12509 'Troll Patrol: Intestinal Fortitude' if player has quest Troll patrol'."),
(19, 0, 12519, 0, 0, 9, 0, 12501, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Troll Patrol: Whatdya Want, a Medal?' if player has quest Troll patrol'."),
(20, 0, 12519, 0, 0, 9, 0, 12501, 0, 0, 0, 0, 0, '', "Show quest mark 12604 'Troll Patrol: Whatdya Want, a Medal?' if player has quest Troll patrol'."),
(19, 0, 12502, 0, 0, 9, 0, 12501, 0, 0, 0, 0, 0, '', "Show quest mark 12502 'Troll Patrol: High Standards' if player has quest Troll patrol'."),
(20, 0, 12502, 0, 0, 9, 0, 12501, 0, 0, 0, 0, 0, '', "Show quest mark 12502 'Troll Patrol: High Standards' if player has quest Troll patrol'."),
(19, 0, 12564, 0, 0, 9, 0, 12563, 0, 0, 0, 0, 0, '', "Show quest mark 12564 'Troll Patrol: Something for the Pain' if player has quest Troll patrol'."),
(20, 0, 12564, 0, 0, 9, 0, 12563, 0, 0, 0, 0, 0, '', "Show quest mark 12564 'Troll Patrol: Something for the Pain' if player has quest Troll patrol'."),
(19, 0, 12568, 0, 0, 9, 0, 12563, 0, 0, 0, 0, 0, '', "Show quest mark 12568 'Troll Patrol: Done to Death' if player has quest Troll patrol'."),
(20, 0, 12568, 0, 0, 9, 0, 12563, 0, 0, 0, 0, 0, '', "Show quest mark 12558 'Troll Patrol: Done to Death' if player has quest Troll patrol'."),
(19, 0, 12585, 0, 0, 9, 0, 12563, 0, 0, 0, 0, 0, '', "Show quest mark 12585 'Troll Patrol: Creature Comforts' if player has quest Troll patrol'."),
(20, 0, 12585, 0, 0, 9, 0, 12563, 0, 0, 0, 0, 0, '', "Show quest mark 12585 'Troll Patrol: Creature Comforts' if player has quest Troll patrol'."),
(19, 0, 12588, 0, 0, 9, 0, 12587, 0, 0, 0, 0, 0, '', "Show quest mark 12588 'Troll Patrol: Can You Dig It?' if player has quest Troll patrol'."),
(20, 0, 12588, 0, 0, 9, 0, 12587, 0, 0, 0, 0, 0, '', "Show quest mark 12588 'Troll Patrol: Can You Dig It?' if player has quest Troll patrol'."),
(19, 0, 12591, 0, 0, 9, 0, 12587, 0, 0, 0, 0, 0, '', "Show quest mark 12591 'Troll Patrol: Throwing Down' if player has quest Troll patrol'."),
(20, 0, 12591, 0, 0, 9, 0, 12587, 0, 0, 0, 0, 0, '', "Show quest mark 12591 'Troll Patrol: Throwing Down' if player has quest Troll patrol'."),
(19, 0, 12594, 0, 0, 9, 0, 12587, 0, 0, 0, 0, 0, '', "Show quest mark 12594 'Troll Patrol: Couldn't Care Less' if player has quest Troll patrol'."),
(20, 0, 12594, 0, 0, 9, 0, 12587, 0, 0, 0, 0, 0, '', "Show quest mark 12594 'Troll Patrol: Couldn't Care Less' if player has quest Troll patrol'."),
(19, 0, 12557, 0, 0, 9, 0, 12596, 0, 0, 0, 0, 0, '', "Show quest mark 12557 'Lab Work' if player has quest Pa'Troll'."),
(20, 0, 12557, 0, 0, 9, 0, 12596, 0, 0, 0, 0, 0, '', "Show quest mark 12557 'Lab Work' if player has quest Pa'Troll'."),
(19, 0, 12597, 0, 0, 9, 0, 12596, 0, 0, 0, 0, 0, '', "Show quest mark 12597 'Something for the Pain' if player has quest Pa'Troll'."),
(20, 0, 12597, 0, 0, 9, 0, 12596, 0, 0, 0, 0, 0, '', "Show quest mark 12597 'Something for the Pain' if player has quest Pa'Troll'."),
(19, 0, 12598, 0, 0, 9, 0, 12596, 0, 0, 0, 0, 0, '', "Show quest mark 12598 'Throwing Down' if player has quest Pa'Troll'."),
(20, 0, 12598, 0, 0, 9, 0, 12596, 0, 0, 0, 0, 0, '', "Show quest mark 12598 'Throwing Down' if player has quest Pa'Troll'."),
(19, 0, 12599, 0, 0, 9, 0, 12596, 0, 0, 0, 0, 0, '', "Show quest mark 12599 'Creature Comforts' if player has quest Pa'Troll'."),
(20, 0, 12599, 0, 0, 9, 0, 12596, 0, 0, 0, 0, 0, '', "Show quest mark 12599 'Creature Comforts' if player has quest Pa'Troll'.");
 
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`=''  WHERE `entry` =28039;
DELETE FROM `smart_scripts` WHERE `entryorguid` =28039 AND `source_type`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(28039, 0, 0, 1, 19, 0, 100, 0, 12596, 0, 0, 0, 85, 51506, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Pa''Troll - Invoker Cast Clear Patrol Quests'),
(28039, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 51509, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Pa''Troll - Invoker Cast Clear Patrol Quests II'),
(28039, 0, 2, 5, 19, 0, 100, 0, 12587, 0, 0, 0, 85, 51573, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Troll Patrol - Invoker Cast On Patrol'),
(28039, 0, 3, 5, 19, 0, 100, 0, 12501, 0, 0, 0, 85, 51573, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Troll Patrol - Invoker Cast On Patrol'),
(28039, 0, 4, 5, 19, 0, 100, 0, 12563, 0, 0, 0, 85, 51573, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Troll Patrol - Invoker Cast On Patrol'),
(28039, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 85, 53712, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Troll Patrol - Invoker Cast Clear DAILY Patrol SUBQuests 00'),
(28039, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 85, 53713, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Troll Patrol - Invoker Cast Clear DAILY Patrol SUBQuests 01'),
(28039, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 85, 53715, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Troll Patrol - Invoker Cast Clear DAILY Patrol SUBQuests 02'),
(28039, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 85, 53716, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Troll Patrol - Invoker Cast Clear DAILY Patrol SUBQuests 03'),
(28039, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 85, 53707, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Accept Troll Patrol - Invoker Cast On Patrol Heartbeat Script'),
(28039, 0, 10, 0, 20, 0, 100, 0, 12587, 0, 0, 0, 28, 51573, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Reward Congratulations - Remove Aura On Patrol'),
(28039, 0, 11, 0, 20, 0, 100, 0, 12563, 0, 0, 0, 28, 53707, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Reward Troll Patrol - Remove Aura On Patrol Heartbeat Script'),
(28039, 0, 12, 0, 20, 0, 100, 0, 12501, 0, 0, 0, 28, 53707, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Reward Troll Patrol - Remove Aura On Patrol Heartbeat Script'),
(28039, 0, 13, 0, 20, 0, 100, 0, 12604, 0, 0, 0, 28, 53707, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Commander Kunz - On Quest Reward Troll Patrol - Remove Aura On Patrol Heartbeat Script');

UPDATE `quest_template_addon` SET `ExclusiveGroup`=12587 WHERE  `ID`  IN(12501,12563,12587);

DELETE FROM `pool_quest` WHERE `pool_entry` IN (@Pool);

INSERT INTO `pool_quest` (`entry`, `pool_entry`, `description`) VALUES
(12587, @Pool, 'Troll Patrol'),
(12501, @Pool, 'Troll Patrol'),
(12563, @Pool, 'Troll Patrol');
    
DELETE FROM `pool_template` WHERE `entry` IN (@Pool);

INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@Pool, 1, 'Troll Patrol Daily Quests');
*/
