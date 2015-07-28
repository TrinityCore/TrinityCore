--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=37056;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 37056, 0, 0, 31, 0, 3, 21316, 0, 0, 0, '','Kill Legion Hold Infernals Targets Deathforged Infernal');

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=21512;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21512 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(21512,0,0,1,8,0,100,0,37055,0,300000,300000,33,21512,0,0,0,0,0,7,0,0,0,0,0,0,0,'Invis Legion Hold Glyph - On Spellhit (Destroy Legion Hold Infernals) - Give Kill Credit'),
(21512,0,1,0,61,0,100,0,37055,0,0,0,11,37056,0,0,0,0,0,1,0,0,0,0,0,0,0,'Invis Legion Hold Glyph - Linked with Previous Event - Cast Kill Legion Hold Infernals');
