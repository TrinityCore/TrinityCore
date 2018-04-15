-- [Q] Leave Nothing to Chance

-- Lower Wintergarde Mine Shaft and Upper Wintergarde Mine Shaft
UPDATE `creature_template` SET `MovementType`=0,`flags_extra`=`flags_extra`|128 WHERE `entry`IN (27437,27436);
UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `id` IN (27437,27436);

-- Wintergarde Mine Bomb SAI
SET @ENTRY := 27435;
SET @SPELL_EXPLOSION := 48742;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,14000,14000,0,0,11,@SPELL_EXPLOSION,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - Out of Combat - Cast Wintergarde Mine Explosion"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wintergarde Mine Bomb - On Wintergarde Mine Explosion Cast - Forced Despawn");

-- Spawn missing spell focus object for upper mine
DELETE FROM `gameobject` WHERE `id`=188711 AND `guid`=370;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(370,188711,571,1,1,3898.18,-881.748,119.533,0.421023,0,0,0.20896,0.977924,300,0,1);

-- Spawn missing Upper Wintergarde Mine Shaft
DELETE FROM `creature` WHERE `id`=27436 AND `guid`=42576;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(42576,27436,571,1,1,0,0,3899.86,-883.613,119.536,0.0636665,300,0,0,42,0,0,0,0,0);

-- Spellscriptname
DELETE FROM `spell_script_names` WHERE `spell_id`=@SPELL_EXPLOSION;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(@SPELL_EXPLOSION,'spell_q12277_wintergarde_mine_explosion');

-- The conditions will make it works exactly like it should. Thanks a lot Josh.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_EXPLOSION;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_EXPLOSION,0,31,3,27437,0,0,'',"Wintergarde Mine Explosion - Lower Wintergarde Mine Shaft"), -- Effect 0 - SPELL_EFFECT_DUMMY
(13,1,@SPELL_EXPLOSION,1,31,3,27436,0,0,'',"Wintergarde Mine Explosion - Upper Wintergarde Mine Shaft"), -- Effect 0 - SPELL_EFFECT_DUMMY
(13,2,@SPELL_EXPLOSION,0,31,4,0,0,0,'',"Wintergarde Mine Explosion - Targets Players"),                          -- Effect 1 - SPELL_EFFECT_KNOCK_BACK
(13,4,@SPELL_EXPLOSION,0,31,5,188712,0,0,'',"Wintergarde Mine Explosion - Wintergarde Mine Cave In (2)");    -- Effect 2 - SPELL_EFFECT_ACTIVATE_OBJECT
