--
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=25425;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25425;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25425,0,0,0,8,0,100,0,45607,0,0,0,33,25425,0,0,0,0,0,7,0,0,0,0,0,0,0,'On Spell Hit(Kaganishu''s Fetish Trigger) - Quest Credit');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=45607;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,45607,0,0,31,0,3,25425,0,0,0,0,'','Kaganishu''s Fetish Trigger hits Farseer Grimwalker''s Spirit');
