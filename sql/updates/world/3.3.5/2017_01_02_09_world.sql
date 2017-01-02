-- Coren Direbrew Implementation
SET @CGUID := 77805;
DELETE FROM `creature` WHERE `id`=23872 OR `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 23872, 230, 0, 0, 1, 1, 0, 1, 891.8394, -129.1829, -49.65985, 5.253441, 300, 0, 0, 0, 0, 2, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid`=@CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID,@CGUID*10,0,0,1,0,NULL);

DELETE FROM `game_event_creature` WHERE `eventEntry`=24 AND `guid`=@CGUID;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(24,@CGUID);

DELETE FROM `waypoint_data` WHERE `id` IN (@CGUID*10);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`action`,`action_chance`,`wpguid`) VALUES
(@CGUID*10,0,888.4606, -130.909, -49.7434,0,0,0,100,0),
(@CGUID*10,1,895.4048, -126.9586, -49.74198,0,0,0,100,0);

UPDATE `gameobject_template` SET `ScriptName`='go_direbrew_mole_machine' WHERE `entry`=188508;
UPDATE `gameobject_template` SET `displayId`=1287, `VerifiedBuild`=0 WHERE `entry`=188509;
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=23795;
UPDATE `creature_template` SET `ScriptName`='npc_direbrew_antagonist' WHERE `entry`=23795;
UPDATE `creature_template` SET `ScriptName`='npc_direbrew_minion' WHERE `entry`=26776;
UPDATE `creature_template` SET `ScriptName`='npc_coren_direbrew_sisters' WHERE `entry` IN(26764,26822);
UPDATE `creature_template` SET `unit_flags`=256, `MovementType`=2, `ScriptName`='boss_coren_direbrew' WHERE `entry`=23872;

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=50313;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,50313,64,0,0,'Disable LOS for Spell Mole Machine Emerge');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(47344,52850);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,47344,0,0,31,0,3,26764,0,0,0,0,'','Spell Request Second mug targets Ilsa Direbrew'),
(13,1,52850,0,0,31,0,3,23872,0,0,0,0,'','Spell Port to Coren target Coren Direbrew');

DELETE FROM `creature_text` WHERE `entry` IN(23872,23795);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23872, 0, 0, "This is an insult! An affront! They deny us participation in time-honored dwarven traditions!", 12, 0, 100, 15, 0, 0, 22376, 0, 'Coren Direbrew SAY_INTRO'),
(23872, 1, 0, "Are we going to hide in our mountain and let those swill-peddlers have their little shindig without us?!", 12, 0, 100, 15, 0, 0, 22388, 0, 'Coren Direbrew SAY_INTRO2'),
(23872, 2, 0, "DAMN RIGHT! We'll show 'em why you don't cross the Dark Iron dwarves!", 12, 0, 100, 15, 0, 0, 22389, 0, 'Coren Direbrew SAY_INTRO3'),
(23872, 3, 0, "You'll pay for this insult, $c!", 12, 0, 100, 15, 0, 0, 25921, 0, 'Coren Direbrew SAY_INSULT'),
(23795, 0, 0, "No way!", 12, 0, 100, 15, 0, 0, 22397, 0, 'Dark Iron Antagonist SAY_ANTAGONIST_1'),
(23795, 0, 1, "NO!", 12, 0, 100, 15, 0, 0, 22399, 0, 'Dark Iron Antagonist SAY_ANTAGONIST_1'),
(23795, 0, 2, "Not on your life", 12, 0, 100, 15, 0, 0, 22398, 0, 'Dark Iron Antagonist SAY_ANTAGONIST_1'),
(23795, 1, 0, "Yeah!", 12, 0, 100, 15, 0, 0, 22393, 0, 'Dark Iron Antagonist SAY_ANTAGONIST_2'),
(23795, 1, 1, "You said it!", 12, 0, 100, 15, 0, 0, 22395, 0, 'Dark Iron Antagonist SAY_ANTAGONIST_2'),
(23795, 1, 2, "Damn straight!", 12, 0, 100, 15, 0, 0, 22396, 0, 'Dark Iron Antagonist SAY_ANTAGONIST_2'),
(23795, 1, 3, "Right!", 12, 0, 100, 15, 0, 0, 22394, 0, 'Dark Iron Antagonist SAY_ANTAGONIST_2'),
(23795, 2, 0, 'Never cross a Dark Iron, $C.', 12, 0, 50, 0, 0, 0, 1934, 0, 'Dark Iron Antagonist to Player'),
(23795, 2, 1, 'Feel the power of the Dark Iron Dwarves!', 12, 0, 50, 0, 0, 0, 1936, 0, 'Dark Iron Antagonist to Player');

DELETE FROM `creature_template_addon` WHERE `entry` IN (26764,26822);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(26764, 0, 0, 0, 1, 0, '47759 47760'),
(26822, 0, 0, 0, 1, 0, '47759 47760');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_direbrew_summon_mole_machine_target_picker',
'spell_direbrew_disarm',
'spell_send_mug_control_aura',
'spell_send_mug_target_picker',
'spell_request_second_mug',
'spell_barreled_control_aura');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(47407,'spell_direbrew_disarm'),
(47691,'spell_direbrew_summon_mole_machine_target_picker'),
(47369,'spell_send_mug_control_aura'),
(47370,'spell_send_mug_target_picker'),
(47344,'spell_request_second_mug'),
(50278,'spell_barreled_control_aura');

DELETE FROM  `gossip_menu_option` WHERE `menu_id` IN(11387,11388);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(11387, 0, 0, "Insult Coren Direbrew's brew.", 40431, 1, 1, 11388, 0, 0, 0, '', 0, 0),
(11388, 0, 0, "Fight", 40433, 1, 1, 0, 0, 0, 0, '', 0, 0),
(11388, 1, 0, "Apologize", 40434, 1, 1, 0, 0, 0, 0, '', 0, 0);
