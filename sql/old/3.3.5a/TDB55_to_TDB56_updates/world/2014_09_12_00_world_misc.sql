UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` =3362;

DELETE FROM `creature_text` WHERE `entry` IN(18407,18166);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(18407, 0, 0, 'Damn those ogres. Damn them to the Nether. Won''t someone save us from these savages! This is the fifth kidnapping in as many days.', 12, 1, 100, 0, 0, 0, 'Warden Bullrok',15371),
(18407, 1, 0, 'That''s the best reward we''re going to be able to offer. Hopefully someone accepts the mission.', 12, 1, 100, 1, 0, 0, 'Warden Bullrok',15372),
(18166, 0, 0, 'Do not burden A''dal with mundane questions, $r.  This being''s will is all that keeps our enemies from crushing this city.', 12, 0, 100, 0, 0, 0, 'Khadgar',17238),
(18166, 1, 0, 'Show our guest around Shattrath, will you?  Keep an eye out for pickpockets in the Lower City.', 12, 0, 100, 0, 0, 0, 'Khadgar',17266);

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE  `entry`=18166;

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(18407,18166) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18481 AND `source_type`=0 AND `id`=2;

DELETE FROM `smart_scripts` WHERE `entryorguid`=1840700 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18407, 0, 0, 0, 1, 0, 100, 0, 60000, 60000, 120000, 240000, 80, 1840700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Bullrok - Out of Combat - Run Script'),
(18481, 0, 2, 0, 20, 0, 100, 0, 10210, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 18166, 0, 0, 0, 0, 0, 0, 'A\'dal - On Quest Reward (A''DAL) - Say line 0 on Khadgar'),
(18166, 0, 0, 0, 19, 0, 100, 0, 10211, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Khadgar - On Quest Accept (City of Lights) - Say Line 1'),
(1840700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 1903, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Bullrok - Script - Equip Virtual Item 1903 to Slot 1'),
(1840700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.96706, 'Warden Bullrok - Script - Set Orientation'),
(1840700, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Bullrok - Script - Play emote STATE_WORK_CHOPWOOD'),
(1840700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Bullrok - Script - Say Line 1'),
(1840700, 9, 4, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Bullrok - Script - Play emote ONESHOT_NONE'),
(1840700, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Bullrok - Script - Say Line 1'),
(1840700, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.6283185, 'Warden Bullrok - Script - Set Orientation'),
(1840700, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warden Bullrok - Script - Unequip Virtual Item');

UPDATE `gossip_menu` SET `text_id`=5841 WHERE  `entry`=3161 AND `text_id`=3841;
UPDATE `conditions` SET `SourceEntry`=5843 WHERE  `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4006 AND `SourceEntry`=4840 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=5 AND `ConditionTarget`=0 AND `ConditionValue1`=81 AND `ConditionValue2`=128 AND `ConditionValue3`=0;
UPDATE `conditions` SET `SourceEntry`=5843 WHERE  `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4006 AND `SourceEntry`=4840 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=16 AND `ConditionTarget`=0 AND `ConditionValue1`=32 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `SourceEntry`=5855 WHERE  `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4004 AND `SourceEntry`=4855 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=5 AND `ConditionTarget`=0 AND `ConditionValue1`=72 AND `ConditionValue2`=128 AND `ConditionValue3`=0;
UPDATE `conditions` SET `SourceEntry`=5855 WHERE  `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4004 AND `SourceEntry`=4855 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=16 AND `ConditionTarget`=0 AND `ConditionValue1`=1 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
