-- Fix guid for Wonza error in a previous commit
UPDATE `conversation_actors` SET `ConversationActorGuid`=1051211 WHERE `ConversationId`=12058 AND `ConversationActorId`=76284; -- CONVERSATION_LINE_ESCORT_SURVIVOR_CAMP Wonza

-- Missing Conditions on conversation lines for "Finding the lost Expedition"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (29322,34645,36152,36153);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,29322,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29322 if team is Alliance'),
(29,0,34645,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34645 if team is Alliance'),
(29,0,36152,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36152 if team is horde'),
(29,0,36153,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36153 if team is horde');
