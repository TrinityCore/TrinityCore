/*######
## A Few Good Gnomes
######*/

DELETE FROM `spell_script_names` WHERE `spell_id` = '74035';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('74035', 'spell_motivate_a_tron');
UPDATE `creature_template` SET `ScriptName` = 'npc_gnome_citizen', `InhabitType` = '3', `flags_extra` = '2', `modelid1` = '2590', `modelid2` = '2581' WHERE `entry` IN ('39466', '39624');
UPDATE `creature` SET `spawntimesecs` = '30' WHERE `id` IN ('39253', '39623');

DELETE FROM `creature_text` WHERE `entry` IN ('39466', '39624');
INSERT INTO `creature_text` VALUES ('39466', '0', '0', 'Sign me up!', '12', '0', '100', '66', '0', '0', 'Gnome Citizen JustSpawned');
INSERT INTO `creature_text` VALUES ('39466', '0', '1', 'Anything for King Mekkatorque!', '12', '0', '100', '0', '0', '0', 'Gnome Citizen JustSpawned');
INSERT INTO `creature_text` VALUES ('39466', '0', '2', 'I\'d love to help.', '12', '0', '100', '273', '0', '0', 'Gnome Citizen JustSpawned');
INSERT INTO `creature_text` VALUES ('39466', '0', '3', 'Is this going to hurt?', '12', '0', '100', '66', '0', '0', 'Gnome Citizen JustSpawned');
INSERT INTO `creature_text` VALUES ('39466', '1', '0', 'Wow! We\'re taking back Gnomeregan? I\'m in!', '12', '0', '100', '66', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39466', '1', '1', 'My wrench of vengance awaits!', '12', '0', '100', '1', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39466', '1', '2', 'I want to drive a Spider Tank', '12', '0', '100', '66', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39466', '1', '3', 'This is going to be fascinating!', '12', '0', '100', '0', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39466', '1', '4', 'When does the training start?', '12', '0', '100', '6', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39624', '0', '0', 'Sign me up!', '12', '0', '100', '66', '0', '0', 'Gnome Citizen JustSpawned');
INSERT INTO `creature_text` VALUES ('39624', '0', '1', 'Anything for King Mekkatorque!', '12', '0', '100', '0', '0', '0', 'Gnome Citizen JustSpawned');
INSERT INTO `creature_text` VALUES ('39624', '0', '2', 'I\'d love to help.', '12', '0', '100', '273', '0', '0', 'Gnome Citizen JustSpawned');
INSERT INTO `creature_text` VALUES ('39624', '0', '3', 'Is this going to hurt?', '12', '0', '100', '66', '0', '0', 'Gnome Citizen JustSpawned');
INSERT INTO `creature_text` VALUES ('39624', '1', '0', 'Wow! We\'re taking back Gnomeregan? I\'m in!', '12', '0', '100', '66', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39624', '1', '1', 'My wrench of vengance awaits!', '12', '0', '100', '1', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39624', '1', '2', 'I want to drive a Spider Tank', '12', '0', '100', '66', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39624', '1', '3', 'This is going to be fascinating!', '12', '0', '100', '0', '0', '0', 'Gnome Citizen Quest Turn in');
INSERT INTO `creature_text` VALUES ('39624', '1', '4', 'When does the training start?', '12', '0', '100', '6', '0', '0', 'Gnome Citizen Quest Turn in');

DELETE FROM `smart_scripts` WHERE (`entryorguid` IN ('39253', '39623') AND `source_type` = '0');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
('39253', '0', '0', '0', '8', '0', '100', '0', '73943', '0', '0', '0', '41', '1000', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Operation Gnomeregan: On spellhit - force despawn'),
('39623', '0', '0', '0', '8', '0', '100', '0', '74080', '0', '0', '0', '41', '1000', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', 'Operation Gnomeregan: On spellhit - force despawn');

/*######
## Basic Orders
######*/

UPDATE `creature_template` SET `ScriptName` = 'npc_steamcrank' WHERE `entry` = '39368';

/*######
## In and Out
######*/

UPDATE `creature_template` SET `VehicleId` = '745', `spell6` = '74153' WHERE `entry` = '39682';

/*######
## One Step Forward...
######*/

UPDATE `creature_template` SET `spell1` = '74157', `spell2` = '74159', `spell3` = '74160', `spell4` = '74153' WHERE `entry` = '39713';

/*######
## Press Fire
######*/

UPDATE `creature_template` SET `spell4` = '74174', `spell6` = '74153' WHERE `entry` = '39714';
UPDATE `creature_template` SET `ScriptName` = 'npc_shoot_bunny' WHERE `entry` = '39707';
DELETE FROM `spell_scripts` WHERE `id` = '74182';
INSERT INTO `spell_scripts` (`id`, `command`, `datalong`, `datalong2`) VALUES ('74182', '15', '74179', '2');

/*######
## Vent Horizon
######*/

UPDATE `conditions` SET `ConditionValue1` = '25212' WHERE (`SourceTypeOrReferenceId`='15') AND (`SourceGroup`='11211') AND (`SourceEntry`='0') AND (`ElseGroup`='0') AND (`ConditionTypeOrReference`='9') AND (`ConditionValue1`='25283') AND (`ConditionValue2`='0') AND (`ConditionValue3`='0');
DELETE FROM `creature_template_addon` WHERE (`entry` = '39420');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('39420', '0', '0', '65536', '1', '0', '75779');
UPDATE `creature_template` SET `scale` = '2' WHERE `entry` = '39420';
DELETE FROM `conditions` WHERE `SourceEntry`=73082;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES 
('13', '1', '73082', '31', '3', '39420');

/*######
## Prepping the Speech
######*/

UPDATE `quest_template` SET `PrevQuestId` = '25283', `NextQuestId` = '25287' WHERE `Id` = '25286';
UPDATE `quest_template` SET `NextQuestId` = '25286' WHERE `Id` = '25283';
UPDATE `creature_template` SET `ScriptName` = 'npc_mekkatorque', `scale` = '0.6', `unit_flags` = '33554752' WHERE `entry` = '39712';
DELETE FROM `creature_template_addon` WHERE (`entry` = '39712');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('39712', '0', '0', '0', '0', '0', '8326');
-- Cleanup [delete unused quest]
DELETE FROM `quest_template` WHERE (`Id` = '25500');
DELETE FROM `creature_questrelation` WHERE (`quest` = '25500');
DELETE FROM `gameobject_questrelation` WHERE (`quest` = '25500');
DELETE FROM `creature_involvedrelation` WHERE (`quest` = '25500');
DELETE FROM `gameobject_involvedrelation` WHERE (`quest` = '25500');
DELETE FROM `areatrigger_involvedrelation` WHERE (`quest` = '25500');

/*######
## Operation 'Gnomeregan'
######*/

UPDATE `creature_template` SET `mechanic_immune_mask` = '12658704', `ScriptName` = 'npc_og_mekkatorque' WHERE `entry` = '39271';
UPDATE `creature_template` SET `unit_flags` = '393220', `ScriptName` = 'npc_og_rl' WHERE `entry` = '39820';
UPDATE `creature_template` SET `npcflag` = '0', `VehicleId` = '0', `ScriptName` = 'npc_og_tank' WHERE `entry` = '39860';
UPDATE `creature_template` SET `faction_A` = '1771', `faction_H` = '1771', `unit_flags` = '4', `ScriptName` = 'npc_og_cannon' WHERE `entry` = '39759';
UPDATE `creature_template` SET `ScriptName` = 'npc_og_bomber' WHERE `entry` = '39735';
UPDATE `creature_template` SET `ScriptName` = 'npc_og_infantry' WHERE `entry` = '39252';
UPDATE `creature_template` SET `spell1` = '74764', `ScriptName` = 'npc_og_i_infantry' WHERE `entry` = '39755';
UPDATE `creature_template` SET `ScriptName` = 'npc_og_suit' WHERE `entry` = '39902';
UPDATE `creature_template` SET `ScriptName` = 'npc_og_trogg' WHERE `entry` IN ('39826', '39799');
UPDATE `creature_template` SET `ScriptName` = 'npc_og_boltcog' WHERE `entry` = '39837';
UPDATE `creature_template` SET `ScriptName` = 'npc_og_assistants' WHERE `entry` IN ('39273', '39910');
UPDATE `creature_template` SET `ScriptName` = 'npc_og_i_tank' WHERE `entry` = '39819';
UPDATE `creature_template` SET `AIName` = 'AggresorAI' WHERE `entry` IN ('39755', '39836');
UPDATE `creature_template` SET `VehicleId` = '0', `ScriptName` = 'npc_og_camera_vehicle' WHERE `entry` = '40479';
UPDATE `creature_template` SET `mechanic_immune_mask` = '8192' WHERE `entry` IN ('39860', '39826', '39799', '39819', '39273', '39910', '39837');

DELETE FROM `creature` WHERE `id` IN ('39273', '39910');
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
('250249', '39273', '0', '1', '256', '0', '0', '-5423.01', '535.254', '386.516', '5.23555', '300', '0', '0', '630000', '0', '0', '0', '134217728', '0'),
('250248', '39910', '0', '1', '256', '0', '0', '-5427.93', '532.323', '386.85', '5.27046', '300', '0', '0', '630000', '0', '0', '0', '0', '0');
UPDATE `creature` SET `position_x` = '-5424.462891', `position_y` = '531.410095', `position_z` = '386.743347', `orientation` = '5.2' WHERE `id` = '39271';
UPDATE `creature` SET `phaseMask`= '1' WHERE `id` = '7937';

DELETE FROM `vehicle_template_accessory` WHERE `entry` = '39860';

DELETE FROM `creature_template_addon` WHERE `entry` IN ('39820', '39273', '39910');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
('39820', '0', '0', '0', '0', '0', '74311'),
('39273', '0', '9473', '0', '0', '0', ''),
('39910', '0', '6569', '0', '0', '0', '');

UPDATE `creature_template` SET `modelid2` = '0' WHERE `entry` = '39903';
-- UPDATE `creature_template` SET `equipment_id` = '39368' WHERE `entry` = '39271';
UPDATE `creature_template` SET `speed_run` = '1.25', `faction_A` = '1770', `faction_H` = '1770' WHERE `entry` = '39273';
UPDATE `creature_template` SET `speed_run` = '1.29', `faction_A` = '1770', `faction_H` = '1770' WHERE `entry` = '39910';

DELETE FROM `spell_area` WHERE (`spell` = '74310') AND (`area` IN ('1', '135', '721'));
INSERT INTO `spell_area` VALUES
('74310', '721', '25287', '1', '25393', '0', '0', '2', '1'),
('74310', '135', '25287', '1', '25393', '0', '0', '2', '1');

UPDATE `gameobject` SET `phaseMask` = '257' WHERE `id` = '194498';
UPDATE `gameobject` SET `phaseMask` = '256' WHERE `id` = '202922';
UPDATE `gameobject` SET `spawntimesecs` = '-1' WHERE `guid` NOT IN ('2482', '2469', '2461', '2458', '2454', '2453', '2466', '2475') and `id` = '194498';

DELETE FROM `spell_scripts` where `id` IN ('74412', '75510') AND `command` = '6';
INSERT INTO `spell_scripts` (`id`, `command`, `x`, `y`, `z`, `o`) VALUES
('74412', '6', '-4842.156738', '-1277.52771', '501.868256', '0.84'),
('75510', '6', '-5164.767578', '556.341125', '423.753784', '25.29');

DELETE FROM `spell_dbc` WHERE `id` = '75517';
INSERT INTO `spell_dbc` VALUES ('75517', '0', '0', '384', '1024', '4', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '21', '13', '0', '-1', '0', '0', '6', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '25', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '[DND] Bind Sight');

-- waypoints for the last battle --

DELETE FROM `script_waypoint` WHERE `entry` IN ('39271', '39273', '39910');
INSERT INTO `script_waypoint` VALUES ('39271', '0', '-5420.67', '528.775', '386.713', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '1', '-5409.16', '533.555', '386.748', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '2', '-5387.22', '542.998', '386.062', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '3', '-5387.22', '542.998', '386.062', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '4', '-5363.67', '555.368', '387.222', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '5', '-5352.78', '571.801', '386.329', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '6', '-5348.4', '554.581', '385.103', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '7', '-5334.2', '548.422', '384.389', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '8', '-5320.33', '589.94', '389.282', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '9', '-5304.74', '579.818', '389.878', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '10', '-5296.44', '574.425', '387.195', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '11', '-5284.05', '583.055', '386.916', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '12', '-5273.44', '562.343', '386.416', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '13', '-5234.36', '526.2', '386.764', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '14', '-5190.17', '519.923', '387.845', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '15', '-5182.69', '494.296', '387.976', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '16', '-5162.55', '476.988', '390.1', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '17', '-5133.19', '446.746', '395.009', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '18', '-5102.61', '459.28', '403.119', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '19', '-5083.89', '449.192', '410.409', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '20', '-5073.83', '441.95', '410.966', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '21', '-5083.89', '449.192', '410.409', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '22', '-5094.04', '461.049', '404.753', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '23', '-5099.45', '463.045', '403.707', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '24', '-5102.38', '461.128', '403.291', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '25', '-5111.06', '456.148', '400.845', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '26', '-5130.05', '448.678', '395.097', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '27', '-5142.41', '457.047', '393.074', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '28', '-5156.83', '472.722', '390.558', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '29', '-5162.18', '477.146', '390.118', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '30', '-5171.85', '482.398', '388.832', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '31', '-5184.8', '495.179', '387.975', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '32', '-5188.27', '511.978', '387.774', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '33', '-5188.67', '519.197', '387.827', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '34', '-5189.08', '532.199', '388.979', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '35', '-5188.2', '548.319', '393.302', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '36', '-5184.14', '581.337', '403.195', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '37', '-5183.25', '600.234', '409.013', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '38', '-5182.88', '611.582', '408.964', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '39', '-5181.33', '629.587', '398.547', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '40', '-5181.18', '633.698', '398.547', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '41', '-5179.62', '655.145', '388.96', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '42', '-5179.33', '658.935', '388.96', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '43', '-5177.68', '680.319', '379.373', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '44', '-5177.34', '684.68', '379.279', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '45', '-5175.27', '705.866', '369.766', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '46', '-5174.38', '714.979', '369.766', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '47', '-5159.94', '714.156', '369.766', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '48', '-5159.84', '705.217', '369.766', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '49', '-5162.77', '665.875', '348.932', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '50', '-5163.54', '655.233', '348.281', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '51', '-5164.36', '649.379', '348.531', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '52', '-5164.36', '649.379', '247.268', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '53', '-5160.58', '691.629', '247.369', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '54', '-5150.96', '724.722', '247.369', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '55', '-5143.21', '723.851', '247.369', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '56', '-5119.14', '721.632', '254.27', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '57', '-5115.13', '721.586', '254.307', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '58', '-5095.03', '720.342', '260.506', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '59', '-5078.62', '722.355', '260.543', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '60', '-5055.71', '729.623', '260.559', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '61', '-5053.57', '730.578', '261.236', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '62', '-5046.74', '733.553', '256.475', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '63', '-5032.67', '734.978', '256.475', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '64', '-4974.75', '730.193', '256.261', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '65', '-4948.22', '728.136', '260.438', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '66', '-4946.75', '728.089', '261.646', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '67', '-4937.45', '728.895', '261.646', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '68', '-4944.71', '728.062', '261.645', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '69', '-4946.95', '727.975', '261.646', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '70', '-4948.56', '728.227', '260.382', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '71', '-4981.64', '730.998', '256.327', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '72', '-4974.27', '730.200', '256.257', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '73', '-4948.23', '727.982', '260.438', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '74', '-4947.24', '727.969', '261.506', '0', '');
INSERT INTO `script_waypoint` VALUES ('39271', '75', '-4938.09', '728.934', '261.646', '0', '');

INSERT INTO `script_waypoint` VALUES ('39273', '0', '-5420.402832', '532.782776', '386.462921', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '1', '-5413.188477', '535.881653', '386.570923', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '2', '-5391.552246', '544.664673', '386.394592', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '3', '-5366.873535', '557.704712', '386.987396', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '4', '-5357.714355', '569.594055', '386.843536', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '5', '-5347.485840', '559.449036', '384.522247', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '6', '-5337.935547', '551.479126', '384.372162', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '7', '-5321.748047', '584.958923', '388.036346', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '8', '-5305.991211', '583.735352', '389.782196', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '9', '-5297.886719', '578.137695', '388.633179', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '10', '-5283.689941', '587.856506', '387.076050', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '11', '-5272.595703', '566.956177', '386.519623', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '12', '-5236.533203', '530.369751', '387.070984', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '13', '-5189.522461', '524.215027', '388.070892', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '14', '-5181.116211', '499.922943', '387.990204', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '15', '-5163.294434', '482.087555', '389.972443', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '16', '-5134.145020', '452.650818', '394.293671', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '17', '-5106.144043', '460.529114', '402.411102', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '18', '-5083.545410', '452.273163', '409.631439', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '19', '-5082.151855', '450.770660', '410.434784', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '20', '-5083.367188', '452.029633', '409.771332', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '21', '-5090.745605', '462.081818', '405.188080', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '22', '-5094.800781', '464.407684', '404.231567', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '23', '-5098.551270', '464.187897', '403.823486', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '24', '-5109.258789', '459.713531', '401.694031', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '25', '-5125.863770', '452.030670', '395.953247', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '26', '-5138.246582', '456.800995', '393.498688', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '27', '-5151.615723', '470.463165', '390.977905', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '28', '-5159.138184', '477.868378', '390.390503', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '29', '-5166.544434', '482.103271', '389.501068', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '30', '-5179.772949', '493.101166', '388.037781', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '31', '-5185.578613', '509.315033', '387.862335', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '32', '-5186.571289', '515.156555', '387.784119', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '33', '-5186.854980', '528.101440', '388.403992', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '34', '-5186.819336', '543.251831', '391.710083', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '35', '-5182.299805', '576.332642', '401.499268', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '36', '-5180.895508', '596.640320', '408.112335', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '37', '-5180.009766', '610.448669', '408.964294', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '38', '-5179.010254', '629.560303', '398.546448', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '39', '-5178.824219', '633.018311', '398.546082', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '40', '-5177.220703', '654.860657', '388.959839', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '41', '-5176.970215', '658.702515', '388.959839', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '42', '-5175.649902', '678.966553', '379.909698', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '43', '-5175.290527', '684.310486', '379.352386', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '44', '-5173.214355', '705.574524', '369.766937', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '45', '-5172.834473', '712.714966', '369.765472', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '46', '-5163.152344', '712.508667', '369.765472', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '47', '-5162.308594', '705.768188', '369.765472', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '48', '-5165.507324', '666.178040', '348.932495', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '49', '-5166.233887', '656.292297', '348.279694', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '50', '-5166.872070', '649.750427', '348.489136', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '51', '-5166.872070', '649.750427', '247.841827', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '52', '-5162.357910', '689.594788', '247.369598', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '53', '-5151.636230', '727.016418', '247.369598', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '54', '-5145.094727', '726.401733', '247.369598', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '55', '-5119.512207', '724.035522', '254.095673', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '56', '-5116.247070', '723.778198', '254.307098', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '57', '-5098.798828', '722.279053', '259.285217', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '58', '-5081.573730', '724.174316', '260.555847', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '59', '-5054.638184', '732.560059', '261.248962', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '60', '-5048.257813', '735.472778', '257.336182', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '61', '-5033.412109', '737.746399', '256.475433', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '62', '-4976.061035', '733.267578', '256.275848', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '63', '-4948.415527', '730.725708', '260.374939', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '64', '-4946.948730', '730.632813', '261.566132', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '65', '-4939.745117', '731.451355', '261.645691', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '66', '-4940.826660', '730.935669', '261.645691', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '67', '-4976.375000', '733.288513', '256.280151', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '68', '-4948.928223', '730.775269', '260.292114', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '69', '-4946.928711', '730.578186', '261.582672', '0', '');
INSERT INTO `script_waypoint` VALUES ('39273', '70', '-4941.870117', '731.079346', '261.645782', '0', '');

INSERT INTO `script_waypoint` VALUES ('39910', '0', '-5424.904785', '529.018250', '386.907135', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '1', '-5409.412598', '529.308472', '386.815735', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '2', '-5389.864258', '537.651489', '386.400970', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '3', '-5362.293945', '552.092041', '387.345825', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '4', '-5351.015625', '568.830688', '385.658569', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '5', '-5352.846680', '556.917725', '385.812195', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '6', '-5331.118652', '550.053711', '384.222687', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '7', '-5317.275879', '586.008179', '388.921997', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '8', '-5305.580078', '576.558838', '389.430603', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '9', '-5299.335449', '572.321472', '387.363373', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '10', '-5287.414063', '579.508423', '386.900696', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '11', '-5279.070801', '564.824463', '386.324402', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '12', '-5237.998047', '523.175537', '386.834412', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '13', '-5195.938477', '518.082886', '387.628754', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '14', '-5187.843750', '496.516663', '387.960724', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '15', '-5169.045898', '477.416107', '389.567505', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '16', '-5140.520020', '448.746094', '394.346405', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '17', '-5103.534668', '454.931732', '402.526276', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '18', '-5087.425293', '447.815735', '409.280487', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '19', '-5085.774414', '446.122864', '410.010529', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '20', '-5087.396973', '447.636505', '409.314209', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '21', '-5092.096191', '455.544373', '406.078674', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '22', '-5096.645508', '459.132782', '404.369598', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '23', '-5099.127441', '459.274902', '403.712097', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '24', '-5106.294922', '455.985779', '402.018951', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '25', '-5128.013672', '445.234467', '395.625244', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '26', '-5139.292969', '451.904663', '393.962158', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '27', '-5155.541992', '468.300476', '390.728790', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '28', '-5160.116699', '472.721527', '390.356110', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '29', '-5168.042480', '477.739838', '389.631897', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '30', '-5183.694336', '489.820190', '388.044525', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '31', '-5190.432129', '508.433350', '387.769104', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '32', '-5191.108398', '514.904297', '387.729156', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '33', '-5191.555176', '527.512756', '388.405853', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '34', '-5190.826172', '545.530029', '392.304321', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '35', '-5187.698730', '575.555298', '401.323792', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '36', '-5186.026855', '597.184814', '408.193695', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '37', '-5185.793457', '610.082031', '408.964874', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '38', '-5183.908691', '629.966553', '398.547729', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '39', '-5183.680664', '633.795776', '398.545227', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '40', '-5181.918945', '655.113708', '388.982178', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '41', '-5181.717285', '658.493713', '388.960114', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '42', '-5179.924316', '678.677795', '380.190948', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '43', '-5179.567383', '684.666199', '379.353027', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '44', '-5177.982910', '705.807007', '369.818054', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '45', '-5176.126953', '715.995422', '369.766388', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '46', '-5160.162598', '716.361267', '369.766388', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '47', '-5157.438965', '705.328491', '369.766388', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '48', '-5160.029297', '665.752869', '348.932465', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '49', '-5160.773926', '655.525208', '348.280701', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '50', '-5161.148926', '649.951538', '348.936096', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '51', '-5161.270996', '648.982727', '247.909073', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '52', '-5157.797363', '689.493164', '247.369415', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '53', '-5151.696289', '721.441223', '247.369415', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '54', '-5145.410156', '721.279846', '247.369415', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '55', '-5119.867676', '719.472656', '254.097168', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '56', '-5116.398926', '719.157898', '254.307388', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '57', '-5098.915527', '717.599792', '259.362640', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '58', '-5079.908203', '719.716125', '260.552216', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '59', '-5054.856445', '727.103699', '261.248871', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '60', '-5047.593750', '730.491272', '257.369171', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '61', '-5033.518555', '732.164917', '256.475372', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '62', '-4976.188477', '727.239563', '256.272461', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '63', '-4949.388184', '724.849670', '260.293152', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '64', '-4947.241211', '724.775208', '261.645844', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '65', '-4940.058105', '725.943787', '261.645844', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '66', '-4941.194336', '724.833923', '261.645844', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '67', '-4976.979492', '727.399170', '256.280396', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '68', '-4950.066406', '725.069885', '260.181854', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '69', '-4947.596191', '725.010742', '261.424683', '0', '');
INSERT INTO `script_waypoint` VALUES ('39910', '70', '-4941.947266', '726.680725', '261.646057', '0', '');
