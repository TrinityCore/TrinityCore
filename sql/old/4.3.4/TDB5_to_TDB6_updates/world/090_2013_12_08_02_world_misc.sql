-- Condition for spells Mind Trick: Chains
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (5432);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `ElseGroup`=1 AND `SourceEntry` IN (59951,59952); 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 5432,  0, 0, 31, 0, 3, 31892, 0, 0, 0, 0, '', 'Mind Trick: Chains - Torso Blood Back targets Darkspeaker R''khem'),
(13, 1, 59951, 0, 1, 31, 0, 3, 31892, 0, 0, 0, 0, '', 'Mind Trick: Chains - Left Hand targets Darkspeaker R''khem'),
(13, 1, 59952, 0, 1, 31, 0, 3, 31892, 0, 0, 0, 0, '', 'Mind Trick: Chains - Right Hand targets Darkspeaker R''khem');

-- Update ELM General Purpose Bunny Large
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=24110;
UPDATE `creature` SET `modelid`=0, `spawndist`=0, `curhealth`=1, `MovementType`=0 WHERE `id`=24110;

-- ELM General Purpose Bunny Large SAI
SET @ENTRY := 24110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` BETWEEN -121628 AND -121615;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-121615,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59952,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121616,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59952,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121617,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59952,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121618,0,0,0,1,0,100,1,1000,1000,1000,1000,11,5432,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121619,0,0,0,1,0,100,1,1000,1000,1000,1000,11,5432,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121620,0,0,0,1,0,100,1,1000,1000,1000,1000,11,5432,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121621,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59951,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121622,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59951,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121623,0,0,0,1,0,100,1,1000,1000,1000,1000,11,5432,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121624,0,0,0,1,0,100,1,1000,1000,1000,1000,11,5432,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121625,0,0,0,1,0,100,1,1000,1000,1000,1000,11,5432,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121626,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59951,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121627,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59951,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem"),
(-121628,0,0,0,1,0,100,1,1000,1000,1000,1000,11,59952,0,0,0,0,0,1,0,0,0,0,0,0,0,"ELM General Purpose Bunny Large - OCC Once - Cast chains on Darkspeaker R'khem");
