-- Iruk
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=26219;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26219 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26219,0,0,1,62,0,100,0,9280,0,0,0,11,46816,1,0,0,0,0,7,0,0,0,0,0,0,0,"Iruk - On gossip select - Cast spell 'Create Totem of Issliruk'"),
(26219,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Iruk - Linked event - Close gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9280;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9280,0,0,9,11961,0,0,0,0,'','Show gossip option 0 only if player has quest 11961 active');

-- Elder Muahit
DELETE FROM `creature_text` WHERE `CreatureID`=26218;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26218,0,0,'The spirits have listened!  Can you feel it, $n?',12,0,100,0,0,0,25615,0,'Elder Muahit');

UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`="" WHERE `entry`=26218;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26218 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26218,0,0,0,20,0,100,0,11961,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Elder Muahit - On quest reward - Say line 0');
