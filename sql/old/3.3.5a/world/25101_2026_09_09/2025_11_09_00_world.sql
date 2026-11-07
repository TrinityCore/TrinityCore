-- Ingvar
UPDATE `creature_template` SET `unit_flags` = 33555200, `AIName` = 'SmartAI' WHERE `entry` = 24012;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24012 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24012,0,0,0,11,0,100,0,0,0,0,0,0,11,42862,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ingvar Res Ground Visual - On Spawn - Cast 'Scourge Resurrection'"),
(24012,0,1,0,11,0,100,0,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ingvar Res Ground Visual - On Spawn - Delayed Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23954,23980) AND `GroupID` = 3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23954,3,0,"%s roars!",41,0,100,0,0,0,14029,0,"Ingvar the Plunderer - EMOTE_ROAR"),
(23980,3,0,"%s roars!",41,0,100,0,0,0,14029,0,"Ingvar the Plunderer - EMOTE_ROAR");

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 23954 AND `ID` = 2;
UPDATE `creature_equip_template` SET `ItemID1` = 33177 WHERE `CreatureID` = 23954 AND `ID` = 1;
UPDATE `creature` SET `equipment_id` = 1 WHERE `id` = 23954;

-- Keleseth
DELETE FROM `creature_summon_groups` WHERE `summonerId` = 23953 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(23953,0,0,23970,153.91295,260.99866,42.953950,5.777040004730224609,8,0,"Prince Keleseth - Group 0 - Vrykul Skeleton"),
(23953,0,0,23970,148.90604,260.21863,42.953945,5.899212837219238281,8,0,"Prince Keleseth - Group 0 - Vrykul Skeleton"),
(23953,0,0,23970,147.77333,266.23520,42.953945,5.759586334228515625,8,0,"Prince Keleseth - Group 0 - Vrykul Skeleton"),
(23953,0,0,23970,153.47198,266.16130,42.953945,5.619960308074951171,8,0,"Prince Keleseth - Group 0 - Vrykul Skeleton");

DELETE FROM `creature_text` WHERE `CreatureID` = 23953;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23953,0,0,"Your blood is mine!",14,0,0,0,0,13221,22736,0,"Prince Keleseth - SAY_AGGRO"),
(23953,1,0,"Not so fast.",14,0,0,0,0,13222,22734,0,"Prince Keleseth - SAY_FROST_TOMB"),
(23953,2,0,"Darkness waits.",14,0,0,0,0,13223,29591,0,"Prince Keleseth - SAY_SLAY"),
(23953,3,0,"Aranal, ledel! Their fate shall be yours!",14,0,0,0,0,13224,22729,0,"Prince Keleseth - SAY_SUMMON_SKELETONS"),
(23953,4,0,"I join... the night.",14,0,0,0,0,13225,29592,0,"Prince Keleseth - SAY_DEATH"),
(23953,5,0,"%s casts Frost Tomb on $n.",41,0,0,0,0,0,27152,0,"Prince Keleseth - EMOTE_FROST_TOMB");

UPDATE `spell_script_names` SET `ScriptName` = 'spell_keleseth_frost_tomb_channel' WHERE `ScriptName` = 'spell_frost_tomb';

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_keleseth_frost_tomb_periodic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(42672, 'spell_keleseth_frost_tomb_periodic');

DELETE FROM `creature_text` WHERE `CreatureID` = 23970;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23970,0,0,"%s rises from the floor!",16,0,100,0,0,0,26607,0,"Vrykul Skeleton - EMOTE_RISES");

-- Skarvald
DELETE FROM `creature_loot_template` WHERE `Entry` = 24201 AND `Reference` = 35045;
DELETE FROM `creature_loot_template` WHERE `Entry` = 31656 AND `Item` = 47241;
DELETE FROM `creature_loot_template` WHERE `Entry` = 31656 AND `Reference` = 35049;
