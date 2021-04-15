--
UPDATE `creature_template` SET `AIName` = 'SmartAI',`npcflag`=`npcflag`|1 WHERE `entry` =26809;

DELETE FROM `smart_scripts` WHERE `entryorguid`=26809 AND `event_type`IN (25,61,64);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26809, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 31261, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ravaged Crystalline Ice Giant - On Spawn - Cast Permanent Feign Death (Root) on self'),
(26809, 0, 1, 2, 64, 0, 100, 0, 0, 0, 0, 0, 56, 36765, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ravaged Crystalline Ice Giant - On Hello - Add Sample of Rockflesh'),
(26809, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ravaged Crystalline Ice Giant - Linked with Previous Event - Close Gossip'),
(26809, 0, 3, 0, 64, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ravaged Crystalline Ice Giant - Linked with Previous Event - Close Gossip - On No quest or complete');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =26809;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,26809,0,0,9,0,12075,0,0,0,0,'','Ravaged Crystalline Ice Giant - Add Sample of Rockflesh only if player is on and has not completed slim pickings');
