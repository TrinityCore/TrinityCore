SET @GUID := 62851;

SET @TRIGGER := 4951;
SET @ELM_BUNNY := 23837;
SET @ELM_BUNNY_LARGE := 24110;
SET @OACHANOA := 26648;
SET @PEARL := 188422;

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE `entry`=@PEARL;
UPDATE `creature_template` SET `speed_run`=2.14286, `faction_A`=190, `faction_H`=190, `unit_flags`=33536, `unit_flags2`=2080, `AIName`='SmartAI', `InhabitType`=4 WHERE `entry`=@OACHANOA;

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID+0 AND @GUID+3;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,@ELM_BUNNY,571,1,1,11686,0,2452.865,1722.222,61.8313,5.654867,300,0,0,42,0,0,0,0,0),
(@GUID+1,@ELM_BUNNY_LARGE,571,1,1,11686,0,2427.382,1680.861,-0.05963766,2.356194,300,0,0,42,0,0,0,0,0),
(@GUID+2,@ELM_BUNNY_LARGE,571,1,1,11686,0,2407.345,1733.472,7.560452,2.443461,300,0,0,42,0,0,0,0,0),
(@GUID+3,@ELM_BUNNY_LARGE,571,1,1,11686,0,2436.226,1710.697,-0.01387666,5.183628,300,0,0,42,0,0,0,0,0);

DELETE FROM `areatrigger_scripts` WHERE `entry`=@TRIGGER;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(@TRIGGER,'SmartTrigger');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@TRIGGER AND `SourceId`=2;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@PEARL AND `SourceId`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@PEARL,1,0,9,0,12032,0,0,0,0,'','SAI only activates if player is on quest Conversing With the Depths'),
(22,1,@TRIGGER,2,0,9,0,12032,0,0,0,0,'','SAI only activates if player is on quest Conversing With the Depths'),
(22,1,@TRIGGER,2,0,1,0,47098,0,0,0,0,'','SAI only activates if player has aura Oacha''noa''s Compulsion');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@GUID+0),-(@GUID+1),-(@GUID+2),-(@GUID+3),@OACHANOA) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PEARL AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TRIGGER AND `source_type`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@OACHANOA*100,@OACHANOA*100+1,@PEARL*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-(@GUID+0),0,0,0,38,0,100,0,0,1,0,0,11,38497,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 1 set - Spellcast Cyclone Water Visual'),
(-(@GUID+0),0,1,0,38,0,100,0,0,2,0,0,28,38497,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny - On data 0 2 set - Remove aura Cyclone Water Visual'),
(-(@GUID+1),0,0,0,38,0,100,0,0,1,0,0,11,47479,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On data 0 1 set - Spellcast Water Spout'),
(-(@GUID+2),0,0,0,38,0,100,0,0,1,0,0,11,45849,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On data 0 1 set - Spellcast Camera Shake - Tremor'),
(-(@GUID+3),0,0,0,38,0,100,0,0,1,0,0,11,47479,0,0,0,0,0,1,0,0,0,0,0,0,0, 'ELM General Purpose Bunny Large - On data 0 1 set - Spellcast Water Spout'),

(@OACHANOA,0,0,1,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On Spawn - Set event phase 1'),
(@OACHANOA,0,1,2,61,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On Spawn - Set run'),
(@OACHANOA,0,2,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,2367.975,1712.07,43.56623,0, 'Oacha''noa - On Spawn - Move to position'),
(@OACHANOA,0,3,0,34,1,100,0,0,1,0,0,80,@OACHANOA*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On movement inform (phase 1) - Run script 0'),
(@OACHANOA,0,4,0,52,1,100,0,3,@OACHANOA,0,0,1,4,10100,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On text 3 over (phase 1) - Say line'),
(@OACHANOA,0,5,6,52,1,100,0,4,@OACHANOA,0,0,1,9,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa - On text 4 over (phase 1) - Say line'),
(@OACHANOA,0,6,7,61,0,100,0,0,0,0,0,6,12032,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa - On text 4 over (phase 1) - Fail quest'),
(@OACHANOA,0,7,0,61,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On text 4 over (phase 1) - Despawn after 2 seconds'),
(@OACHANOA,0,8,9,38,1,100,0,0,1,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On data 0 1 set (phase 1) - Set event phase 0'),
(@OACHANOA,0,9,0,61,0,100,0,0,0,0,0,80,@OACHANOA*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa - On data 0 1 set (phase 1) - Run script 1'),

(@TRIGGER,2,0,0,46,0,100,0,0,0,0,0,45,0,1,0,0,0,0,14,21195,@PEARL,0,0,0,0,0, 'On trigger - Set data 0 1 Pearl of the Depths'),

(@PEARL,1,0,0,70,0,100,0,2,0,0,0,80,@PEARL*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Pearl of the Depths - On state changed - Run script'),
(@PEARL,1,1,0,38,0,100,0,0,1,0,0,45,0,1,0,0,0,0,19,@OACHANOA,100,0,0,0,0,0, 'Pearl of the Depths - On data 0 1 set - Set data 0 1 Oacha''noa'),

(@OACHANOA*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 0 - Turn to'),
(@OACHANOA*100,9,1,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,@GUID+1,@ELM_BUNNY_LARGE,0,0,0,0,0, 'Oacha''noa script 0 - Set data 0 1 ELM General Purpose Bunny Large'),
(@OACHANOA*100,9,2,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,@GUID+2,@ELM_BUNNY_LARGE,0,0,0,0,0, 'Oacha''noa script 0 - Set data 0 1 ELM General Purpose Bunny Large'),
(@OACHANOA*100,9,3,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,@GUID+3,@ELM_BUNNY_LARGE,0,0,0,0,0, 'Oacha''noa script 0 - Set data 0 1 ELM General Purpose Bunny Large'),
(@OACHANOA*100,9,4,0,0,0,100,0,1200,1200,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 0 - Say line'),
(@OACHANOA*100,9,5,0,0,0,100,0,8500,8500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 0 - Say line'),
(@OACHANOA*100,9,6,0,0,0,100,0,9700,9700,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 0 - Say line'),
(@OACHANOA*100,9,7,0,0,0,100,0,0,0,0,0,11,47098,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 0 - Spellcast Oacha''noa''s Compulsion'),
(@OACHANOA*100,9,8,0,0,0,100,0,10900,10900,0,0,1,3,10000,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 0 - Say line'),

(@OACHANOA*100+1,9,0,0,0,0,100,0,0,0,0,0,15,12032,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Complete quest'),
(@OACHANOA*100+1,9,1,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Say line'),
(@OACHANOA*100+1,9,2,0,0,0,100,0,10600,10600,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Say line'),
(@OACHANOA*100+1,9,3,0,0,0,100,0,10800,10800,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Say line'),
(@OACHANOA*100+1,9,4,0,0,0,100,0,10700,10700,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.281219, 'Oacha''noa script 1 - Turn to'),
(@OACHANOA*100+1,9,5,0,0,0,100,0,200,200,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Oacha''noa script 1 - Say line'),
(@OACHANOA*100+1,9,6,0,0,0,100,0,1000,1000,0,0,5,374,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 1 - Play emote'),
(@OACHANOA*100+1,9,7,0,0,0,100,0,0,0,0,0,4,11561,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 1 - Play sound'),
(@OACHANOA*100+1,9,8,0,0,0,100,0,2300,2300,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oacha''noa script 1 - Despawn'),

(@PEARL*100,9,0,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Pearl of the Depths script - Store targetlist'),
(@PEARL*100,9,1,0,0,0,100,0,0,0,0,0,99,0,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Pearl of the Depths script - Set state'),
(@PEARL*100,9,2,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,@GUID+0,@ELM_BUNNY,0,0,0,0,0, 'Pearl of the Depths script - Set data 0 1 ELM General Purpose Bunny'),
(@PEARL*100,9,3,0,0,0,100,0,20000,20000,0,0,45,0,2,0,0,0,0,10,@GUID+0,@ELM_BUNNY,0,0,0,0,0, 'Pearl of the Depths script - Set data 0 2 ELM General Purpose Bunny'),
(@PEARL*100,9,4,0,0,0,100,0,0,0,0,0,12,@OACHANOA,8,0,0,0,0,8,0,0,0,2367.975,1712.07,0.232847,0, 'Pearl of the Depths script - Summon Oacha''noa'),
(@PEARL*100,9,5,0,0,0,100,0,1000,1000,0,0,100,1,0,0,0,0,0,19,@OACHANOA,100,0,0,0,0,0, 'Pearl of the Depths script - Send targetlist'),
(@PEARL*100,9,6,0,0,0,100,0,74000,74000,0,0,99,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Pearl of the Depths script - Set state');

DELETE FROM `creature_text` WHERE `entry`=@OACHANOA;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@OACHANOA,0,0,'Little $N, why do you call me forth? Are you working with the trolls of this land? Have you come to kill me and take my power as your own?',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,1,0,'I sense uncertainty in you, and I do not trust it whether you are with them, or not. If you wish my augury for the Kalu''ak, you will have to prove yourself first.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,2,0,'I will lay a mild compulsion upon you. Jump into the depths before me so that you put yourself into my element and thereby display your submission.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,3,0,'Though you are compelled, the choice, and the last step before you leap, are yours. You have twenty more seconds to decide.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,4,0,'I''m rather curious as to what will happen, should you ignore this and NOT jump into the water.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,5,0,'Well done, $N. Your display of respect is duly noted. Now, I have information for you that you must convey to the Kalu''ak.',14,0,100,33,0,11557,'Oacha''noa'),
(@OACHANOA,6,0,'Simply put, you must tell the tuskarr that they cannot run. If they do so, their spirits will be destroyed by the evil rising within Northrend.',15,0,100,0,0,0,'Oacha''noa'),
(@OACHANOA,7,0,'Tell the mystic that his people are to stand and fight alongside the Horde and Alliance against the forces of Malygos and the Lich King.',15,0,100,0,0,0,'Oacha''noa'),
(@OACHANOA,8,0,'Now swim back with the knowledge I have granted you. Do what you can for them, $r.',15,0,100,0,0,0,'Oacha''noa'),
(@OACHANOA,9,0,'Very well, $N, you have failed to act. The prophecy is not yours to learn. Do not call upon me again until you have found your backbone.',14,0,100,33,0,11557,'Oacha''noa');
