--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=27353;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=27353;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27353, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 12, 27238, 2, 120000, 0, 0, 0, 8, 0, 0, 0, 2802.381836,-199.922272,139.160980,3.575861, 'Levine Family Termite Bunny - On Spawn - Summon Foreman Kaleiki');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` =27353;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,27353,0,0,29,1,27238,40,0,1,0,'',' Foreman Kaleiki only spawns if not present');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=27238;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=27238;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27238, 0, 0, 0, 9, 0, 100, 0, 0, 5, 14000, 18000, 11, 9080, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Foreman Kaleiki - On Range - Cast Hamstring'),
(27238, 0, 1, 0, 0, 0, 100, 0, 8000, 11000, 8000, 11000, 11, 43673, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Foreman Kaleiki - IC - Cast Mighty Blow'),
(27238, 0, 2, 3,11, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Foreman Kaleiki - On Spawn - Set Faction'),
(27238, 0, 3, 0,61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Foreman Kaleiki - Linked with Previous Event - Say');

DELETE FROM `creature_text` WHERE `entry` =27238;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(27238, 0, 0, 'My beautiful mill. You! You\'ll die for this!', 12, 0, 100, 0, 0, 0, 'Foreman Kaleiki', 26418);
