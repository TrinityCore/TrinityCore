-- Out of Body Experience (12327)
SET @CGUID                  = 419;   -- 5 required 4.x changed
SET @ARUGAL                 = 27620;    -- Shade of Arugal
SET @VALANAR                = 27619;    -- Valanar
SET @THERALDIS              = 27624;    -- Theraldis
SET @KELESETH               = 27618;    -- Keleseth
SET @ATHERANN               = 27616;    -- Atherann
SET @SPELL_OOBE             = 49097;    -- Out of Body Experience Invisibility + Detection + Teleport Silverpine
SET @SPELL_TELEPORT_BACK    = 49098;    -- Grizzly Hills - Quest - Arugal Teleport Back
SET @SPELL_EVENT_CHANNEL    = 49128;    -- Arugal Event Channel
SET @SPELL_CREDIT           = 49131;    -- Out of Body Experience Quest Credit
SET @TRIGGER                =  4990;    -- Areatrigger

DELETE FROM `creature` WHERE `id` IN (@ARUGAL,@VALANAR,@THERALDIS,@KELESETH,@ATHERANN);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`,  `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGUID+0,@ARUGAL,0,1,1,0,0,-463.526,1499.51,20.4721,1.55035,300,0,0,10635,0,0,0,0,0),
(@CGUID+1,@ATHERANN,0,1,1,0,0,-458.712,1504.8,16.9815,3.93558,300,0,0,29820,0,0,0,0,0),
(@CGUID+2,@KELESETH,0,1,1,0,0,-471.433,1500.51,18.4603,0.024287,300,0,0,28830,0,0,0,0,0),
(@CGUID+3,@VALANAR,0,1,1,0,0,-462.81,1491.7,17.2292,1.65734,300,0,0,96100,3309,0,0,0,0),
(@CGUID+4,@THERALDIS,0,1,1,0,0,-472.925,1495.71,18.3354,0.577431,300,0,0,28830,0,0,0,0,0);

-- Also serves as a fail safe, if you accidently remove the aura you will be prompted to a credit.
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= -@SPELL_OOBE;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-@SPELL_OOBE,@SPELL_TELEPORT_BACK,0,'When Out of Body Experience expires cast Arugal Teleport Back');

DELETE FROM `spell_target_position` WHERE `id` IN (@SPELL_OOBE,@SPELL_TELEPORT_BACK);
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(@SPELL_OOBE,1,0,-481.041992,1492.949951,19.932100,0), -- Silverpine Forrest
(@SPELL_TELEPORT_BACK,1,571,3842.16,-3428.43,293.105,1.8776);   -- Grizzly Hills

DELETE FROM `creature_text` WHERE `entry` IN (@VALANAR,@THERALDIS);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@VALANAR,0,0,'Rise, Arugal! The power of the Lich King commands you!',12,0,100,0,0,0,'Prince Valanar - Silverpine'),
(@THERALDIS,0,0,'Yes... he shall suit our needs perfectly. Have him sent to Solstice Village when you''re ready. Arthas will not be pleased if we fall behind schedule.',12,0,100,0,0,0,'Prince Theraldis - Silverpine');

-- Detection Auras
DELETE FROM `creature_template_addon` WHERE `entry` IN (@ARUGAL,@VALANAR,@THERALDIS,@KELESETH,@ATHERANN);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ARUGAL,0,0,0,0,0,'49130'),
(@ATHERANN,0,0,0,0,0,'49130'),
(@KELESETH,0,0,0,0,0,'49130'),
(@VALANAR,0,0,0,0,0,'49130'),
(@THERALDIS,0,10721,0,0,0,'49130');

DELETE FROM `areatrigger_scripts` WHERE `entry`=@TRIGGER;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (@TRIGGER,'SmartTrigger');

UPDATE `creature_template` SET `faction_A`=16, `faction_H`=16, `AIName`='SmartAI' ,`unit_flags`=`unit_flags`|2, `InhabitType` = IF (`entry` =@ARUGAL, 4, `InhabitType`) WHERE `entry` IN (@ARUGAL,@VALANAR,@THERALDIS,@KELESETH,@ATHERANN);

DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryorguid`= @TRIGGER;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (@ARUGAL,@VALANAR,@THERALDIS,@KELESETH,@ATHERANN);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryorguid` =@ARUGAL*100;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@TRIGGER,2,0,0,46,0,100,0,@TRIGGER,0,0,0,45,0,1,0,0,0,0,10,@CGUID+0,0,0,0,0,0,0,'On Trigger - Set data 0 1 Shade of Arugal'),
--
(@ARUGAL,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shade of Arugal - on Spawn - React State Passive'),
(@ARUGAL,0,1,0,38,0,100,0,0,1,0,0,80,@ARUGAL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shade of Arugal - on Data set 0 1 - Run script'),
--
(@VALANAR,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Valanar - on Spawn - react Passive'),
(@VALANAR,0,1,0,1,0,100,0,0,0,0,0,11,@SPELL_EVENT_CHANNEL,2,0,0,0,0,11,@ARUGAL,20,0,0,0,0,0,'Valanar - OOC - cast Arugal Event Channel'),
(@VALANAR,0,2,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Valanar - on Data set 0 1 - Say text'),
--
(@KELESETH,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Keleseth - on Spawn - react Passive'),
(@KELESETH,0,1,0,1,0,100,0,0,0,0,0,11,@SPELL_EVENT_CHANNEL,2,0,0,0,0,11,@ARUGAL,20,0,0,0,0,0,'Keleseth - OOC - cast Arugal Event Channel'),
--
(@ATHERANN,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Atherann - on Spawn - react Passive'),
(@ATHERANN,0,1,0,1,0,100,0,0,0,0,0,11,@SPELL_EVENT_CHANNEL,2,0,0,0,0,11,@ARUGAL,20,0,0,0,0,0,'Atherann - OOC - cast Arugal Event Channel'),
--
(@THERALDIS,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Theraldis - on Spawn - react Passive'),
(@THERALDIS,0,1,0,38,0,100,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Theraldis - on Data set 0 1 - Say text'),
--
(@ARUGAL*100,9,0,0,0,0,100,1,5000,5000,0,0,45,0,1,0,0,0,0,19,@VALANAR,20,0,0,0,0,0,'On script - set Data 0 1 Prince Valanar'), -- prevent multiple events during an event
(@ARUGAL*100,9,1,0,0,0,100,0,8000,8000,0,0,45,0,1,0,0,0,0,19,@THERALDIS,20,0,0,0,0,0,'On script - set Data 0 1 Prince Theraldis'),
(@ARUGAL*100,9,2,0,0,0,100,0,0,0,0,0,11,@SPELL_CREDIT,2,0,0,0,0,17,0,30,0,0,0,0,0,'On script - cast Out of Body Experience Quest Credit'),
(@ARUGAL*100,9,3,0,0,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On script - call script reset');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_EVENT_CHANNEL;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@TRIGGER;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,@SPELL_EVENT_CHANNEL,0,0,31,0,3,@ARUGAL,0,0,0,'','Arugal Event Channel targets Shade of Arugal'),
(22,1,@TRIGGER,2,0,1,0,@SPELL_OOBE,0,0,0,0,'','SAI areatrigger 4990 triggers only if player has aura Out of Body Experience'),
(22,1,@TRIGGER,2,0,9,0,12327,0,0,0,0,'','SAI areatrigger 4990 triggers only if player has taken Quest Out of Body Experience');
