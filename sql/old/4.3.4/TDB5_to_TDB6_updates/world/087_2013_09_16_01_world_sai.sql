DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=28739 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,28739,0,0,1,1,52231,0,0,1,0,0,'','Execute sai only if aura is not presented');
DELETE FROM `disables` WHERE `entry` IN (52227,52228) AND `sourcetype`=0;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,52227,64,'','','Disable LOS check for Dilute Blight Cauldron'),
(0,52228,64,'','','Disable LOS check for Kill Credit (quest 12669)');
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=28739;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28739 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28739,0,0,1,8,0,100,0,52227,0,0,0,11,52228,0,0,0,0,0,7,0,0,0,0,0,0,0,'Blight Cauldron Bunny 00 - On Spell Hit - Give Quest Credit'),
(28739,0,1,0,61,0,100,0,0,0,0,0,11,52231,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blight Cauldron Bunny 00 - Link With Previous Event - Cast Cauldron Diluted Effect'),
(28739,0,2,0,1,0,100,0,30000,30000,30000,30000,28,52231,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blight Cauldron Bunny 00 - OOC - Remove Aura From Cauldron Diluted Effect');
