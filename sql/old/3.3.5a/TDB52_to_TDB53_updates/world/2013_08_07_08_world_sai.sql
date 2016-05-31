-- Fueling the Project (11715)
-- oh, and guess what! random comment
SET @NPC_OIL                := 25781; -- Oil Pool
SET @SPELL_OIL_COLLECTOR    := 45990; -- Collect Oil
SET @SPELL_SUMON_COLLECTOR  := 45991; -- Summon Oil Collector
SET @SPELL_OIL_COAT         := 46011; -- Oil Coat (small)
SET @SPELL_FD               := 35357; -- Spawn Feign Death

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_OIL;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@NPC_OIL;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_OIL;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_OIL,0,0,1,25,0,100,0,0,0,0,0,11,@SPELL_FD,0,0,0,0,0,1,0,0,0,0,0,0,0,'On reset - Cast Spawn Feign Death'),
(@NPC_OIL,0,1,0,61,0,100,0,0,0,0,0,11,@SPELL_OIL_COAT,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Cast Oil Coat (small)'),
--
(@NPC_OIL,0,2,3,8,0,100,0,@SPELL_OIL_COLLECTOR,0,0,0,11,@SPELL_SUMON_COLLECTOR,0,0,0,0,0,7,0,0,0,0,0,0,0,'On spellhit - Cast Summon Oil Collector'),
(@NPC_OIL,0,3,4,61,0,100,0,0,0,0,0,33,@NPC_OIL,0,0,0,0,0,7,0,0,0,0,0,0,0,'On spellhit - Give killcredit'),
(@NPC_OIL,0,4,0,61,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Despawn in 1 sec');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_OIL_COLLECTOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_OIL_COLLECTOR,0,0,31,0,3,@NPC_OIL,0,0,0,'','Collect Oil target Oil Pool');
