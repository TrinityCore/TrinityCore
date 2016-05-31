-- Previous quest should be The Defense of Warsong Hold not To Conquest Hold, But Be Careful!
UPDATE `quest_template` SET `PrevQuestId`=11596 WHERE  `Id`=12486;
-- Change grouping so Alliance and Horde quests are no longer in 1 group
UPDATE `quest_template` SET `ExclusiveGroup`=-12222 WHERE  `Id` IN(12222,12223);
-- Hellscreams Champion requires some conditions to start the quest
UPDATE `quest_template` SET `ExclusiveGroup`=0,`NextQuestId`=0 WHERE  `Id` IN(11652,11705,11722);
UPDATE `quest_template` SET `NextQuestId`=11709 WHERE `Id`=11705;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry`=11916;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(20,0,11916,0,0,8,0,11652,0,0,0,0, '', 'Player must have completed The Plains of Nasam before been able to accept Hellscream''s Champion'),
(19,0,11916,0,0,8,0,11652,0,0,0,0, '', 'Player must have completed The Plains of Nasam before been able to accept Hellscream''s Champion'),
(20,0,11916,0,0,8,0,11705,0,0,0,0, '', 'Player must have completed The Foolish Endeavors before been able to accept Hellscream''s Champion'),
(19,0,11916,0,0,8,0,11705,0,0,0,0, '', 'Player must have completed The Foolish Endeavors before been able to accept Hellscream''s Champion'),
(20,0,11916,0,0,8,0,11722,0,0,0,0, '', 'Player must have completed The Trophies of Gammoth before been able to accept Hellscream''s Champion'),
(19,0,11916,0,0,8,0,11722,0,0,0,0, '', 'Player must have completed The Trophies of Gammoth before been able to accept Hellscream''s Champion');
-- Fix SAI issue for Hugh Glass (wrong npcflag was set)
UPDATE `smart_scripts` SET `action_param1`=643 WHERE  `entryorguid`=2648400 AND `source_type`=9 AND `id`=6;
