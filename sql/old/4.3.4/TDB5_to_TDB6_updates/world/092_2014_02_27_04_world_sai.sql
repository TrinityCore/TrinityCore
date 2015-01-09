-- Captured Totem
/*
DELETE FROM `creature_template_addon` WHERE `entry`=23811;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23811, 0, 0, 0, 4097, 0, '42464');

-- Mottled Drywallow Crocolisk
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE  `entry`=4344;

DELETE FROM `smart_scripts` WHERE `entryorguid` =4344;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4344, 0, 0, 0, 6, 0,100,0, 0, 0, 0, 0, 11, 42455, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mottled Drywallow Crocolisk - On Death - Cast Captured Totem Test Credit'),
(4344, 0, 1, 0, 0, 0,100,0, 1000, 6000, 11000, 12000, 11, 3604, 1,0,0,0,0,5,0,0,0,0,0,0,0,'Mottled Drywallow Crocolisk - IC - Cast Tendon Rip');

-- Drywallow Daggermaw
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE  `entry`=4345;

DELETE FROM `smart_scripts` WHERE `entryorguid` =4345;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4345, 0, 0, 0, 6,  0, 100, 0, 0, 0, 0, 0, 11, 42455, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Drywallow Daggermaw - On Death - Cast Captured Totem Test Credit'),
(4345, 0, 1, 0, 9,  0, 100, 0, 0, 5, 10000, 10000, 11, 6016, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Drywallow Daggermaw - IC - Cast Pierce Armor');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (4344,4345);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4344,0,0,1,1,42454,0,0,0,0,'','Captured Totem Quest Credit only if Crocolisk has Captured Totem Aura at Death'),
(22,1,4345,0,0,1,1,42454,0,0,0,0,'','Captured Totem Quest Credit only if Crocolisk has Captured Totem Aura at Death');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42454;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,42454,0,0,31,0,3,4344,0,0,0,0,'','Captive Totem Aura targets only Mottled Drywallow Crocolisk'),
(13,1,42454,0,0,36,0,0,0,0,0,0,0,'','Captive Totem Aura targets only alive units'),
(13,1,42454,0,1,31,0,3,4345,0,0,0,0,'','Captive Totem Aura targets only Drywallow Daggermaw'),
(13,1,42454,0,1,36,0,0,0,0,0,0,0,'','Captive Totem Aura targets only alive units');
*/
