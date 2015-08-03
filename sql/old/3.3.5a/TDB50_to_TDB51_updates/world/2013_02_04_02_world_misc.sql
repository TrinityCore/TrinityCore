-- Pilfering Perfume (A:24656 H:24541)

SET @QUEST_A           := 24656;
SET @QUEST_H           := 24541;

SET @SNIP              := 38066; -- Inspector Snip Snagglebolt
SET @SNAP              := 37172; -- Detective Snap Snagglebolt
SET @MENUID            := 10976;

SET @TRIGGER_SW_OUT    := 5703; -- outside
SET @TRIGGER_SW_IN     := 5704; -- inside
SET @TRIGGER_ORG_OUT   := 5705; -- outside
SET @TRIGGER_ORG_IN    := 5706; -- inside

SET @SPELL_UNIFORM     := 71450; -- Crown Parcel Service Uniform
SET @SPELL_CONTRABAND  := 71459; -- Crown Chemical Co. Contraband

SET @SPELL_CREDIT_A    := 71522; -- Crown Chemical Co. Supplies
SET @SPELL_CREDIT_H    := 71539; -- Crown Chemical Co. Supplies

SET @GUID              := 48571; -- set by TDB,need 3 (48571,48572,48573)
SET @EVENT             := 8; -- Love is in the Air
SET @NPC_GUARD         := 37671; -- Crown Supply Guard

-- missing npcs on horde side
DELETE FROM `creature` WHERE `id`=@NPC_GUARD;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,@NPC_GUARD,1,1,1,0,0,1391.2,-4486.23,31.4544,3.3355,300,0,0,42,0,0,0,0,0),
(@GUID+1,@NPC_GUARD,1,1,1,0,0,1392.66,-4481.87,31.3782,1.97284,300,0,0,42,0,0,0,0,0),
(@GUID+2,@NPC_GUARD,1,1,1,0,0,1393.92,-4489.57,31.4737,4.93701,300,0,0,42,0,0,0,0,0);

DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @GUID+0 AND @GUID+2;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(@EVENT,@GUID+0),
(@EVENT,@GUID+1),
(@EVENT,@GUID+2);

-- removing a wrong spawn
DELETE FROM `creature` WHERE `guid`=40507;
DELETE FROM `game_event_creature` WHERE `guid`=40507;

-- deleting wrong previous spawns and reusing some guids to spawn proper ones
DELETE FROM `gameobject` WHERE `guid` IN (24416,24417,24418,24419,24420,24421,24422,24423,24433,24434,24435,24436,24437,24438,24439,24440,24441);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(24416,181015,1,1,1,1392.938,-4485.202,31.41421,0,0,0,0,1,120,255,1),
(24417,201778,1,1,1,1393.677,-4486.033,32.67227,0,0,0,0,1,120,255,1),
(24418,201752,1,1,1,1394.184,-4484.108,31.24833,4.32842,0,0,0,1,120,255,1),
(24419,201778,1,1,1,1394.26,-4484.368,32.50796,5.148723,0,0,0,1,120,255,1),
(24420,201752,1,1,1,1393.319,-4486.797,31.42903,4.101525,0,0,0,1,120,255,1),
(24421,201752,1,1,1,1394.401,-4485.688,31.35416,5.916668,0,0,0,1,120,255,1),
(24422,201752,1,1,1,1394.042,-4488.397,31.4775,4.32842,0,0,0,1,120,255,1),
(24423,201752,1,1,1,1396.476,-4482.715,32.14788,4.32842,0,0,0,1,120,255,1),
(24433,181015,1,1,1,1395.002,-4487.113,31.37537,3.874631,0,0,0,1,120,255,1),
(24434,181015,1,1,1,1396.632,-4482.505,30.87226,5.166176,0,0,0,1,120,255,1),
(24435,201752,1,1,1,1395.813,-4486.439,32.56021,1.710422,0,0,0,1,120,255,1),
(24436,201752,1,1,1,1396.595,-4486.056,31.15484,4.32842,0,0,0,1,120,255,1),
(24437,201752,1,1,1,1397.377,-4488.021,33.71862,0.157079,0,0,0,1,120,255,1),
(24438,181015,1,1,1,1397.51,-4487.901,32.46279,3.68265,0,0,0,1,120,255,1),
(24439,201752,1,1,1,1397.571,-4487.939,31.21067,3.33359,0,0,0,1,120,255,1);
-- these guids will remain free
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` IN (24440,24441);

-- Snip & Snap sai
UPDATE `creature_template` SET `npcflag`=`npcflag`|1|2,`gossip_menu_id`=@MENUID,`AIName`='SmartAI' WHERE `entry` IN (@SNIP,@SNAP);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SNIP,@SNAP) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SNIP,0,0,0,19,0,100,0,@QUEST_A,0,0,0,11,@SPELL_UNIFORM,0,0,0,0,0,7,0,0,0,0,0,0,0,'Snip - On quest accept - Spellcast'),
(@SNIP,0,1,2,62,0,100,0,@MENUID,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Snip - On gossip option select - Close gossip'),
(@SNIP,0,2,0,61,0,100,0,0,0,0,0,11,@SPELL_UNIFORM,0,0,0,0,0,7,0,0,0,0,0,0,0,'Snip - On gossip option accept - Spellcast'),
--
(@SNAP,0,0,0,19,0,100,0,@QUEST_H,0,0,0,11,@SPELL_UNIFORM,0,0,0,0,0,7,0,0,0,0,0,0,0,'Snap - On quest accept - Spellcast'),
(@SNAP,0,1,2,62,0,100,0,@MENUID,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Snap - On gossip option select - Close gossip'),
(@SNAP,0,2,0,61,0,100,0,0,0,0,0,11,@SPELL_UNIFORM,0,0,0,0,0,7,0,0,0,0,0,0,0,'Snap - On gossip option accept - Spellcast');

DELETE FROM `areatrigger_involvedrelation` WHERE `id` IN (@TRIGGER_SW_OUT,@TRIGGER_SW_IN,@TRIGGER_ORG_OUT,@TRIGGER_ORG_IN);
INSERT INTO `areatrigger_involvedrelation` (`id`,`quest`) VALUES
(@TRIGGER_SW_OUT,@QUEST_A),
(@TRIGGER_SW_IN,@QUEST_A),
--
(@TRIGGER_ORG_OUT,@QUEST_H),
(@TRIGGER_ORG_IN,@QUEST_H);

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (@TRIGGER_SW_OUT,@TRIGGER_SW_IN,@TRIGGER_ORG_OUT,@TRIGGER_ORG_IN);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(@TRIGGER_SW_OUT,'SmartTrigger'),
(@TRIGGER_SW_IN,'SmartTrigger'),
--
(@TRIGGER_ORG_OUT,'SmartTrigger'),
(@TRIGGER_ORG_IN,'SmartTrigger');

-- usig invoker cast because normal cast doesn't want to work(LoS issue,i think)
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@TRIGGER_SW_OUT,@TRIGGER_SW_IN,@TRIGGER_ORG_OUT,@TRIGGER_ORG_IN) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TRIGGER_SW_OUT,2,0,0,46,0,100,0,@TRIGGER_SW_OUT,0,0,0,85,@SPELL_CONTRABAND,0,0,0,0,0,7,0,0,0,0,0,0,0,"On Trigger - Cast - Invoker"),
(@TRIGGER_SW_IN,2,0,0,46,0,100,0,@TRIGGER_SW_IN,0,0,0,85,@SPELL_CREDIT_A,0,0,0,0,0,7,0,0,0,0,0,0,0,"On Trigger - Cast - Invoker"),
--
(@TRIGGER_ORG_OUT,2,0,0,46,0,100,0,@TRIGGER_ORG_OUT,0,0,0,85,@SPELL_CONTRABAND,0,0,0,0,0,7,0,0,0,0,0,0,0,"On Trigger - Cast - Invoker"),
(@TRIGGER_ORG_IN,2,0,0,46,0,100,0,@TRIGGER_ORG_IN,0,0,0,85,@SPELL_CREDIT_H,0,0,0,0,0,7,0,0,0,0,0,0,0,"On Trigger - Cast - Invoker");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (@TRIGGER_SW_OUT,@TRIGGER_SW_IN,@TRIGGER_ORG_OUT,@TRIGGER_ORG_IN);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=@MENUID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@TRIGGER_SW_OUT,2,0,1,0,@SPELL_UNIFORM,0,0,0,0,0,'','execute sai only if player has aura'),
(22,1,@TRIGGER_SW_IN,2,0,1,0,@SPELL_CONTRABAND,0,0,0,0,0,'','execute sai only if player has aura'),
(15,@MENUID,0,0,0,9,0,@QUEST_A,0,0,0,0,0,'','show gossip option only if player has quest taken'),
--
(22,1,@TRIGGER_ORG_OUT,2,0,1,0,@SPELL_UNIFORM,0,0,0,0,0,'','execute sai only if player has aura'),
(22,1,@TRIGGER_ORG_IN,2,0,1,0,@SPELL_CONTRABAND,0,0,0,0,0,'','execute sai only if player has aura'),
(15,@MENUID,0,0,1,9,0,@QUEST_H,0,0,0,0,0,'','show gossip option only if player has quest taken');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (@SPELL_CREDIT_A,@SPELL_CREDIT_H,-@SPELL_UNIFORM);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_CREDIT_A,-@SPELL_UNIFORM,1,'Remove Crown Parcel Service Uniform on Crown Chemical Co. Supplies hit'),
(@SPELL_CREDIT_H,-@SPELL_UNIFORM,1,'Remove Crown Parcel Service Uniform on Crown Chemical Co. Supplies hit'),
(-@SPELL_UNIFORM,-@SPELL_CONTRABAND,0,'Remove Crown Chemical Co. Contraband when Crown Parcel Service Uniform is removed');

DELETE FROM `spell_script_names` WHERE `spell_id`=@SPELL_UNIFORM;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(@SPELL_UNIFORM,'spell_gen_aura_service_uniform');
