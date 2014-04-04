DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=57852;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,57852,0,0,31,0,3,30742,0,0,0,0,'','Destroy Altar can hit First Summoning Altar'),
(13,1,57852,0,1,31,0,3,30744,0,0,0,0,'','Destroy Altar can hit Second Summoning Altar'),
(13,1,57852,0,2,31,0,3,30745,0,0,0,0,'','Destroy Altar can hit Third Summoning Altar'),
(13,1,57852,0,3,31,0,3,30950,0,0,0,0,'','Destroy Altar can hit Fourth Summoning Altar');

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (30742,30744,30745,30950);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30742,30744,30745,30950) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(30742,0,0,0,8,0,100,0,57852,0,0,0,33,30742,0,0,0,0,0,7,0,0,0,0,0,0,0,'First Summoning Altar - On Spell Hit - Give Quest Credit'),
(30744,0,0,0,8,0,100,0,57852,0,0,0,33,30744,0,0,0,0,0,7,0,0,0,0,0,0,0,'Second Summoning Altar - On Spell Hit - Give Quest Credit'),
(30745,0,0,0,8,0,100,0,57852,0,0,0,33,30745,0,0,0,0,0,7,0,0,0,0,0,0,0,'Third Summoning Altar - On Spell Hit - Give Quest Credit'),
(30950,0,0,0,8,0,100,0,57852,0,0,0,33,30950,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fourth Summoning Altar - On Spell Hit - Give Quest Credit');
