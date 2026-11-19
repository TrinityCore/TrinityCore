-- A Race Against Time (11671)

SET @NPC_SALRAND                := 25584; -- Inquisitor Salrand
SET @NPC_BERYL_INVISMAN         := 25594; -- Beryl Point InvisMan
SET @GOB_BERYL_SHIELD           := 187773; -- Beryl Shield
SET @GOB_BERYL_SHIELD_FOCUS     := 300176; -- TEMP Beryl Force Shield
SET @SPELL_BEAM                 := 45777; -- Salrand's Beam
SET @SPELL_THROW_DETONATOR      := 45780; -- Throw Beryl Shield Detonator
SET @SPELL_SUMMON_DETONATOR     := 45791; -- Summon Beryl Detonator
SET @SPELL_EXPLOSION            := 45796; -- Beryl Shield Explosion
SET @SPELL_LOCKBOX              := 45809; -- Summon Salrand's Lockbox
SET @GUID                       := 60441; -- used for a wrong go spawn,will reuse

UPDATE `gameobject_template` SET `data1`=80 WHERE  `entry`=300176; -- spell focus radius
UPDATE `gameobject_template` SET `flags`=32 WHERE  `entry`=187773; -- shield:nodespawn flag

-- missing spell focus
DELETE FROM `gameobject` WHERE `guid`=@GUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,@GOB_BERYL_SHIELD_FOCUS,571,1,1,3392.85,6161.089,79.8313,0,0,0,0,0,300,0,1);

UPDATE `creature_template` SET `InhabitType`=0x4,`unit_flags`=0x100,`AIName`='SmartAI' WHERE `entry`=@NPC_SALRAND;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_BERYL_INVISMAN;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_SALRAND;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_SALRAND,0,0x0,0x1,'45775');

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@NPC_SALRAND;
DELETE FROM `smart_scripts` WHERE (`source_type`=0 AND `entryorguid` IN (@NPC_SALRAND,@NPC_BERYL_INVISMAN)) OR (`source_type`=9 AND `entryorguid` IN (@NPC_SALRAND*100,@NPC_BERYL_INVISMAN*100));
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_SALRAND,0,0,0,38,0,100,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On data 1 1 - Say'),
(@NPC_SALRAND,0,1,2,38,0,100,1,1,2,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On data 1 2 - Say'),
(@NPC_SALRAND,0,2,0,61,0,100,1,0,0,0,0,80,@NPC_SALRAND*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Run script'),
(@NPC_SALRAND,0,3,4,6,0,100,1,0,0,0,0,11,@SPELL_LOCKBOX,0,0,0,0,0,1,0,0,0,0,0,0,0,'On death - Cast spell'),
(@NPC_SALRAND,0,4,0,61,0,100,1,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'On death - Say'),
(@NPC_SALRAND,0,5,0,11,0,100,1,0,0,0,0,24,0,0,0,0,0,0,15,0,0,0,0,0,0,0,'On respawn - Evade'),
(@NPC_SALRAND*100,9,0,0,0,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On script - set fly off'),
(@NPC_SALRAND*100,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,3392.852,6161.092,79.83095,0,'On script - Move to pos'),
(@NPC_SALRAND*100,9,2,0,0,0,100,0,3000,3000,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'On script - Set unit flags'),
--
(@NPC_BERYL_INVISMAN,0,0,0,8,0,100,0,@SPELL_THROW_DETONATOR,0,0,0,80,@NPC_BERYL_INVISMAN*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'On spellhit - Run Script'),
(@NPC_BERYL_INVISMAN*100,9,0,0,0,0,100,0,0,0,0,0,11,@SPELL_SUMMON_DETONATOR,0,0,0,0,0,1,0,0,0,0,0,0,0,'On script - Cast Spell'),
(@NPC_BERYL_INVISMAN*100,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,@NPC_SALRAND,100,0,0,0,0,0,'On script - Set Data'),
(@NPC_BERYL_INVISMAN*100,9,2,0,0,0,100,0,8000,8000,0,0,45,1,2,0,0,0,0,19,@NPC_SALRAND,100,0,0,0,0,0,'On script - Set Data'),
(@NPC_BERYL_INVISMAN*100,9,3,0,0,0,100,0,2000,2000,0,0,11,@SPELL_EXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0,'On script - Cast Spell');

DELETE FROM `creature_text` WHERE `entry`=@NPC_SALRAND;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_SALRAND,0,0,'What is the meaning of this disturbance?!',14,0,100,0,0,0,'Inquisitor Salrand to Beryl Point InvisMan'),
(@NPC_SALRAND,1,0,'Who dares interrupt my work!? Show yourself, coward!',14,0,100,0,0,0,'Inquisitor Salrand to Beryl Point InvisMan'),
(@NPC_SALRAND,2,0,'I''ve destroyed the key! Your cherished archmage belongs to Malygos!',12,0,100,0,0,0,'Inquisitor Salrand');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_THROW_DETONATOR;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SPELL_THROW_DETONATOR,0,0,31,0,3,@NPC_BERYL_INVISMAN,0,0,0,'','Throw Beryl Shield Detonator target npc');
