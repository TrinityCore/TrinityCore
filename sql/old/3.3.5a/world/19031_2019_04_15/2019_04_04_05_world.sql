-- 
DELETE FROM `creature_loot_template` WHERE `item`=16976;
UPDATE `smart_scripts` SET `action_param1`=12921 WHERE `entryorguid`=17820500 AND `source_type`=9 AND `id` BETWEEN 0 AND 16;
DELETE FROM `smart_scripts` WHERE `entryorguid`=12921 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=178205 AND `source_type`=1 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12921, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 11, 6821, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Enraged Foulweald - On Reset - Cast 'Corrupted Strength Passive'"),
(12921, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 10000, 10000, 0, 69, 1, 0, 0, 0, 0, 0, 20, 178205, 100, 0, 0, 0, 0, 0, 0, "Foulweald Foulweald - Out of Combat - Move To Closest Gameobject 'Karang's Banner'"),
(12921, 0, 2, 3, 34, 0, 100, 0, 8, 1, 0, 0, 0, 11, 20786, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Foulweald Foulweald - On Reached Point 1 - Cast 'Destroy Karang's Banner'"),
(12921, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Enraged Foulweald - link - Say Line 0"),
(178205, 1, 1, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, 11, 20746, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Karang's Banner - Just created - cast Summon Karangs Banner Aura");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` =20737;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,20737,0,0,30,0,178205,40,0,1,0,'','Summon Karangs Banner only if not present');
