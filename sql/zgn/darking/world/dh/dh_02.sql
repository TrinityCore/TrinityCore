-- Quest id: 38727 - "Stop the Bombardment" - Add missing banner
DELETE FROM `gameobject` WHERE `guid` = 20375675;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(20375675, 243965, 1481, 7705, 7747, 0, 0, 0, 1813.36, 1543.43, 88.3732, 5.74205, 0, 0, 0.267278, -0.963619, 7200, 255, 1, 22423);

DELETE FROM `creature_queststarter` WHERE `id` IN (92718, 92980, 92986, 92984, 97643, 96675, 97644, 97978, 97296, 114562, 116704, 99254, 99262, 103156, 102585, 107574);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES  
(92718, 38672), -- breaking out
(92980, 38690), -- rise of the illidari
(92986, 38689), -- fel infusion
(92718, 38723), -- stop guldan (Havoc) (https://www.wowhead.com/search?q=stop+gul%27dan)
(92718, 40253), -- stop guldan (Vengeance)
(92984, 39682), -- grand theft felbat
(97643, 39685), -- frozen in time
(97643, 39684), -- beam me up
(96675, 39683), -- forged in fire (Havoc)
(96675, 40254), -- forged in fire (Vengeance)
(96675, 39686), -- all the way up
(97644, 40373), -- -- a new direction (https://www.wowhead.com/search?q=A+New+Direction)
(97644, 39694), -- between us and freedom (havoc H)
(97644, 39688), -- between us and freedom (havoc A)
(97644, 40255), -- between us and freedom (vengeance A)
(97644, 40256), -- between us and freedom (vengeance H)
(97978, 39689), -- Illidari we are leaving (A)
(97978, 39690), -- Illidari we are leaving (H)
(97296, 40976), -- Audience with Warchief
(97296, 39691), -- The Call of War
(114562, 44663), -- Blink of an Eye
(116704, 39047), -- call of the Illidari
(99254, 40816), -- Power To Survive (Altruis)
(99254, 41120), -- Making Arrangements
(99254, 41803), -- Asking A Favor
(99254, 41863), -- Vengeance Will Be Ours
(99262, 41807), -- Establishing a Connection
(103156, 41121), -- By Any Means
(103156, 41119), -- The Hunt
(102585, 39691), -- The Call of War
(102585, 44471), -- Second Sight
(102585, 44463), -- Demons Among Them
(107574, 44473); -- A Weapon of the Alliance

DELETE FROM `creature_questender` WHERE `quest` IN (40253, 38723);
INSERT INTO `creature_questender` (`id`,`quest`) VALUES (92984, 40253), (92984, 38723);

UPDATE `creature_template` SET `ScriptName` = 'npc_kayn_3' WHERE `entry` = 96665;
UPDATE `creature_template` SET `ScriptName` = 'npc_altruis' WHERE `entry` = 92986;
UPDATE `creature_template` SET `ScriptName` = 'npc_fel_infusion' WHERE `entry` = 92776;
UPDATE `creature_template` SET `ScriptName` = 'npc_fel_infusion' WHERE `entry` = 92782;
UPDATE `creature_template` SET `ScriptName` = 'npc_kayn_cell' WHERE `entry` = 103658;
UPDATE `creature_template` SET `ScriptName` = 'npc_altruis_cell' WHERE `entry` = 103655;
UPDATE `creature_template` SET `ScriptName` = 'npc_korvas_bloodthorn' WHERE `entry` = 97644;
UPDATE `creature_template` SET `ScriptName` = 'npc_khadgar' WHERE `entry` = 97978;
UPDATE `creature_template` SET `ScriptName` = 'npc_maiev_shadowsong' WHERE `entry` = 92718;
UPDATE `creature_template` SET `ScriptName` = 'npc_sledge' WHERE `entry` = 92990;
UPDATE `creature_template` SET `ScriptName` = 'npc_crusher' WHERE `entry` = 97632;
UPDATE `creature_template` SET `ScriptName` = 'npc_immolanth' WHERE `entry` = 96682;
UPDATE `creature_template` SET `ScriptName` = 'npc_vow_ashgolm' WHERE `entry` = 96681;
UPDATE `creature_template` SET `ScriptName` = 'npc_bastillax' WHERE `entry` = 96783;
UPDATE `creature_template` SET `ScriptName` = 'npc_legion_portal' WHERE `entry` = 99501;
UPDATE `creature_template` SET `ScriptName` = 'npc_cyana_immolanth_fight' WHERE `entry` = 96672;
UPDATE `creature_template` SET `ScriptName` = 'npc_khadgars_upgraded_servant' WHERE `entry` = 114562;

UPDATE `creature` SET `ScriptName` = 'npc_kayn_sledge_fight' WHERE `guid` = 20542913;
UPDATE `creature` SET `ScriptName` = 'npc_altruis_crusher_fight' WHERE `guid` = 20542914;
 
UPDATE `gameobject_template` SET `ScriptName` = 'go_reflective_mirror' WHERE `entry` = 244449;
UPDATE `gameobject_template` SET `ScriptName` = 'go_pool_of_judgements' WHERE `entry` = 244455;
UPDATE `gameobject_template` SET `ScriptName` = 'go_warden_ascent' WHERE `entry` = 244644;

UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1 WHERE `entry` = 99632;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1 WHERE `entry` = 99631;
UPDATE `creature_template` SET `npcflag` = 3 WHERE `entry` IN (92980, 92984);
UPDATE `creature_template` SET `npcflag` = 1 WHERE `entry` IN (103658, 103655);
UPDATE `creature_template` SET `HealthModifier` = 20 WHERE `entry` = 96682;

UPDATE `quest_template_addon` SET `PrevQuestID` = 38672 WHERE `ID` = 38690; -- Rise of the Illidari
UPDATE `quest_template_addon` SET `PrevQuestID` = 38672, `ScriptName` = 'q_fel_infusion' WHERE `ID` = 38689; -- Fel Infusion
UPDATE `quest_template_addon` SET `ScriptName` = 'q_frozen_in_time' WHERE `ID` = 39685; -- Frozen In Time test script
UPDATE `quest_template_addon` SET `PrevQuestID` = 38690, `NextQuestID` = 39682, `ExclusiveGroup` = 38723 WHERE `ID` = 38723; -- Stop Guldan
UPDATE `quest_template_addon` SET `PrevQuestID` = 38690, `NextQuestID` = 39682, `ExclusiveGroup` = 38723 WHERE `ID` = 40253; -- Stop Guldan

UPDATE `quest_template_addon` SET `PrevQuestID` = 39682, `NextQuestID` = 39686, `ExclusiveGroup` = -39685 WHERE `ID` = 39685; -- Frozen In Time
UPDATE `quest_template_addon` SET `PrevQuestID` = 39682, `NextQuestID` = 39686, `ExclusiveGroup` = -39685 WHERE `ID` = 39684; -- Beam Me Up

UPDATE `quest_template_addon` SET `PrevQuestID` = 39682, `NextQuestID` = 39686, `ExclusiveGroup` = 39683 WHERE `ID` = 39683; -- Forged In Fire
UPDATE `quest_template_addon` SET `PrevQuestID` = 39682, `NextQuestID` = 39686, `ExclusiveGroup` = 39683 WHERE `ID` = 40254; -- Forged In Fire

UPDATE `quest_template_addon` SET `PrevQuestID` = 39686 WHERE `ID` = 40373; -- A New Direction

UPDATE `quest_template_addon` SET `PrevQuestID` = 40373, `NextQuestID` = 39690, `ExclusiveGroup` = 39694 WHERE `ID` = 39694; -- between us and freedom
UPDATE `quest_template_addon` SET `PrevQuestID` = 40373, `NextQuestID` = 39689, `ExclusiveGroup` = 39694 WHERE `ID` = 39688; -- between us and freedom
UPDATE `quest_template_addon` SET `PrevQuestID` = 40373, `NextQuestID` = 39689, `ExclusiveGroup` = 39694 WHERE `ID` = 40255; -- between us and freedom
UPDATE `quest_template_addon` SET `PrevQuestID` = 40373, `NextQuestID` = 39690, `ExclusiveGroup` = 39694 WHERE `ID` = 40256; -- between us and freedom

UPDATE `creature_loot_template` SET `Chance` = 82, `QuestRequired` = 0, `LootMode` = 1, `GroupId` = 0, `MinCount` = 1, `MaxCount` = 1 WHERE `Entry` = 97370 AND `Item` = 133313;

DELETE FROM `spell_script_names` WHERE `spell_id` = 204588; -- activate countermeasures
DELETE FROM `npc_spellclick_spells` WHERE `spell_id` = 204588;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (204588, 'spell_activate_countermeasure');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES (99709, 204588, 1, 0), (99731, 204588, 1, 0), (99732, 204588, 1, 0);

DELETE FROM `gameobject` WHERE `guid` = 210120188; -- Vault of Silence door
DELETE FROM `gameobject` WHERE `guid` = 20373116; -- small chest
DELETE FROM `gameobject` WHERE `guid` = 20373163; -- small chest
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(210120188, 244925, 1468, 7814, 7814, 0, 0, 0, 0, -1, 4325.66, -576.49, -281.783, 4.65537, -0, -0, -0.726975, 0.686664, 300, 255, 1, 0, '', 22423);
DELETE FROM `gameobject` WHERE `guid` IN (20373129, 20373134); -- Vault of Betrayer doors
UPDATE `gameobject` SET `state` = 1 WHERE `guid` IN (20373013, 20373001, 20373016, 20373071, 20373066, 20373082, 20372994, 20373064);
DELETE FROM `creature` WHERE `guid` IN (20542659, 20542665);

DELETE FROM `creature_text` WHERE `CreatureID` IN (92718, 99632, 99631, 96682);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(92718, 0, 0, 'I will need your help to stop Gul\'dan. Free the other Illidari, quickly!', 12, 0, 100, 0, 0, 57338, 0, 0, 'Maiev to Player'),
(99632, 0, 0, 'How many years were wasted in that cell?', 12, 0, 100, 0, 0, 57343, 0, 0, 'Altruis on freed'),
(99631, 0, 0, 'I am awake? How is this possible?', 12, 0, 100, 0, 0, 57294, 0, 0, 'Kayn on freed'),
(99631, 1, 0, 'Why did you let THAT one free? He opposed Lord Illidan!', 12, 0, 100, 0, 0, 57320, 0, 0, 'Kayn\'s response of Altruis freed'),
(99632, 1, 0, 'It has been a long time, Kayn. I still believe in the cause. But, I do not blindly follow anyone... even Illidan.', 12, 0, 100, 0, 0, 57285, 0, 0, 'Altruis to Kayn'),
(99631, 2, 0, 'Why would Maiev free us? There could only be one reason...', 12, 0, 100, 0, 0, 57387, 0, 0, 'Kayns to Player when quest rewarded'),
(96682, 0, 0, 'Join me, demon hunters. I will increase your power beyond imagining!', 12, 0, 100, 0, 0, 57358, 0, 0, 'Immolanth on 60 pct'),
(96682, 1, 0, 'The wardens would keep us rotting here forever. Why do you fight on their side?', 12, 0, 100, 0, 0, 57359, 0, 0, 'Immolanth on 20 pct');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=92718;
DELETE FROM `smart_scripts` WHERE `entryorguid`=92718 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(92718,0,0,0,19,0,100,0,38672,0,0,0,66,0,0,0,0,0,0,21,5,0,0,0,0,0,0,"Maiev - On Quest 'Breaking Out' Taken - Set Orientation Closest Player"),
(92718,0,1,0,19,0,100,0,38672,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Maiev - On Quest 'Breaking Out' Taken - Say Line 0");

UPDATE `quest_template_addon` SET `ScriptName`='q_breaking_out' WHERE `ID`=38672;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=92718;

-- Wrath Lord Lekos SAI
SET @LORD_LEKOS := 97069;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@LORD_LEKOS;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LORD_LEKOS AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@LORD_LEKOS,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath-Lord Lekos - In Combat - Say Line 0 (No Repeat)"),
(@LORD_LEKOS,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200918,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrath-Lord Lekos - In Combat - Cast 'Fel Shield Blast'"),
(@LORD_LEKOS,0,2,0,0,0,100,0,10000,10000,10000,25000,11,200929,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrath-Lord Lekos - In Combat - Cast 'Furious Roar'"),
(@LORD_LEKOS,0,3,0,2,0,100,0,0,40,22000,25000,11,200936,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath-Lord Lekos - Between 0-40% Health - Cast 'Spiked Bulwark'");

DELETE FROM `creature_text` WHERE `CreatureID` = 97069;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97069, 0, 0, 'Lord Gul\'dan will lead us to victory. You cannot stop us.', 12, 0, 100, 0, 0, 57312, 0, 0, 'Wrath Lord Lekos to Player'),
(97069, 0, 1, 'Your world is the last standing. It, too, will be purged.', 12, 0, 100, 0, 0, 57298, 0, 0, 'Wrath Lord Lekos to Player'),
(97069, 0, 2, 'All goes according to HIS plan.', 12, 0, 100, 0, 0, 57392, 0, 0, 'Wrath Lord on Death');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 19 AND `SourceGroup` =0 AND `SourceEntry` IN (38723, 40253, 39683, 40254, 39694, 39688, 40255, 40256) AND `ConditionValue1` IN (212612, 212613);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
('19', '0', '38723', '0', '0', '1', '0', '212612', '0', '0', '0', '0', '0', '', 'Allow Quest "Stop Guldan" 38723 only for Havoc DH'),
('19', '0', '40253', '0', '0', '1', '0', '212613', '0', '0', '0', '0', '0', '', 'Allow Quest "Stop Guldan" only for Vengeance DH'),
('19', '0', '39683', '0', '0', '1', '0', '212612', '0', '0', '0', '0', '0', '', 'Allow Quest "Forged In Fire" only for Havoc DH'),
('19', '0', '40254', '0', '0', '1', '0', '212613', '0', '0', '0', '0', '0', '', 'Allow Quest "Forged In Fire" only for Vengeance DH'),
('19', '0', '39694', '0', '0', '1', '0', '212612', '0', '0', '0', '0', '0', '', 'Allow Quest "Between Us And Freedom" only for Havoc DH'),
('19', '0', '39688', '0', '0', '1', '0', '212612', '0', '0', '0', '0', '0', '', 'Allow Quest "Between Us And Freedom" only for Havoc DH'),
('19', '0', '40255', '0', '0', '1', '0', '212613', '0', '0', '0', '0', '0', '', 'Allow Quest "Between Us And Freedom" only for Vengeance DH'),
('19', '0', '40256', '0', '0', '1', '0', '212613', '0', '0', '0', '0', '0', '', 'Allow Quest "Between Us And Freedom" only for Vengeance DH');

-- Kethrazor SAI
SET @KETHRAZOR := 96997;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@KETHRAZOR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@KETHRAZOR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KETHRAZOR,0,0,0,0,0,100,1,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kethrazor - In Combat - Say Line 0 (No Repeat)"),
(@KETHRAZOR,0,1,0,0,0,100,0,5000,5000,12000,15000,11,201038,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kethrazor - In Combat - Cast 'Mind Spike'"),
(@KETHRAZOR,0,2,0,0,0,100,0,10000,10000,18000,25000,11,201033,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kethrazor - In Combat - Cast 'Seeping Eyes of Kethrazor'"),
(@KETHRAZOR,0,3,0,0,0,100,0,20000,22000,30000,32000,11,200999,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kethrazor - In Combat - Cast 'Explosive Eyes of Kethrazor'"),
(@KETHRAZOR,0,4,0,6,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kethrazor - On Just Died - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 96997;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
('96997', '0', '0', 'Your efforts are fruitless, demon hunter. Lord Gul\'dan sees all.', '14', '0', '100', '0', '0', '57341', '0', '0', 'Kethrazor to Player'),
('96997', '1', '0', 'In the end, you will all succumb to the Legion...', '14', '0', '100', '0', '0', '57368', '0', '0', 'Kethrazor to Player');

-- Seeping Inquisitor Eye SAI
SET @SEEPING_EYE := 101907;
UPDATE `creature_template` SET `faction`=90, `AIName`="SmartAI" WHERE `entry`=@SEEPING_EYE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SEEPING_EYE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SEEPING_EYE,0,0,0,0,0,100,0,0,0,0,0,11,201035,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seeping Inquisitor Eye - In Combat - Cast 'Some Aura'");

-- Explosive Inquisitor Eye SAI
SET @EXPLOSIVE_EYE := 101901;
UPDATE `creature_template` SET `faction`=90, `AIName`="SmartAI" WHERE `entry`=@EXPLOSIVE_EYE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@EXPLOSIVE_EYE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@EXPLOSIVE_EYE,0,0,0,0,0,100,1,0,0,0,0,11,201028,0,0,0,0,0,1,0,0,0,0,0,0,0,"Explosive Inquisitor Eye - In Combat - Cast 'Explosive Shadows' (No Repeat)"),
(@EXPLOSIVE_EYE,0,1,0,0,0,100,1,0,0,0,0,11,201015,0,0,0,0,0,1,0,0,0,0,0,0,0,"Explosive Inquisitor Eye - In Combat - Cast 'Fixate' (No Repeat)");

-- Glazer SAI
SET @GLAZER := 96680;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@GLAZER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GLAZER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GLAZER,0,0,0,1,0,100,1,1000,1000,1000,1000,11,191915,2,0,0,0,0,1,0,0,0,0,0,0,0,"Glazer - Out of Combat - Cast 'Focusing' (No Repeat)"),
(@GLAZER,0,1,0,1,0,100,0,2000,2000,15000,17000,11,196460,2,0,0,0,0,1,0,0,0,0,0,0,0,"Glazer - Out of Combat - Cast 'Lingering Gaze' (No Repeat)"),
(@GLAZER,0,2,0,1,0,100,0,3000,4000,20000,21000,11,196462,2,0,0,0,0,1,0,0,0,0,0,0,0,"Glazer - Out of Combat - Cast 'Pulse'");

-- Altruis near Glazer SAI
SET @ALTRUIS := 102391;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ALTRUIS;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ALTRUIS AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ALTRUIS,0,0,0,10,0,100,1,1,30,0,0,1,0,10000,0,0,0,0,18,30,0,0,0,0,0,0,"Altruis - Within 1-30 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@ALTRUIS,0,1,0,20,0,100,0,39684,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Altruis - On Quest 'Beam Me Up' Completed - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @ALTRUIS;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@ALTRUIS,0,0,'$n, the creature\'s destructive beam is focused upon me. Redirect the final mirror to shatter its shield!',12,0,100,0,0,57332,0,0,'Altruis to Player'),
(@ALTRUIS,1,0,'The shield is broken! Quickly, everyone out while the creature is stunned!',12,0,100,0,0,57333,0,0,'Altruis to Player');

-- Mirana Starlight SAI
SET @MIRANA := 99451;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@MIRANA;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MIRANA AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MIRANA,0,0,0,0,0,100,0,0,0,3400,4700,11,195783,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mirana - In Combat - Cast 'Fan of Blades'"),
(@MIRANA,0,1,0,0,0,100,0,5000,8000,12000,15000,11,191026,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mirana - In Combat - Cast 'Throwing Blade'");

-- Drelanin Whisperwind SAI
SET @DRELANIN := 96847;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@DRELANIN;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DRELANIN AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DRELANIN,0,0,0,10,0,100,1,1,15,0,0,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Drelanin - Within 1-15 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@DRELANIN,0,1,0,0,0,100,0,5000,8000,18000,22000,11,189469,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drelanin - In Combat - Cast 'Turn Kick'"),
(@DRELANIN,0,2,0,0,0,100,0,2000,5000,12000,15000,11,195783,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drelanin - In Combat - Cast 'Fan of Blades'");

DELETE FROM `creature_text` WHERE `CreatureID` = @DRELANIN;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@DRELANIN,0,0,'I hope Maiev was right about freeing you, demon hunter. Go on - I will hold the line.',12,0,100,0,0,57291,0,0,'Drelanin to Player');

SET @JACE := 96653;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@JACE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@JACE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@JACE,0,0,0,10,0,100,1,1,30,0,0,1,0,10000,0,0,0,0,18,30,0,0,0,0,0,0,"Jace Darkweaver - Within 1-30 Range Out of Combat LoS - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID` = @JACE;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@JACE,0,0,'Kayn and Altruis have already gone ahead. Take this felbat and join them.',12,0,100,0,0,57299,0,0,'Jace Darkweaver to Player');

SET @KORVAS_1 := 97643;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@KORVAS_1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@KORVAS_1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KORVAS_1,0,0,0,10,0,100,1,1,15,0,0,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Korvas Bloodthorn - Within 1-15 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@KORVAS_1,0,1,0,19,0,100,0,39685,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Quest 'Frozen In Time' Taken - Say Line 1"),
(@KORVAS_1,0,2,1,52,0,100,0,1,@KORVAS_1,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Text 1 Over - Say Line 2");

DELETE FROM `creature_text` WHERE `CreatureID` = @KORVAS_1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@KORVAS_1,0,0,'This is sheer madness! The Wardens have lost control of their prison',12,0,100,0,0,57323,0,0,'Korvas Bloodthorn to Player'),
(@KORVAS_1,1,0,'Aside from us, the most powerful prisoners were sealed on this level. WERE being the operative word.',12,0,100,0,0,57324,0,0,'Korvas Bloodthorn to Player'),
(@KORVAS_1,2,0,'We cannot afford to lose Kayn and Altruis here. Waste no time and help them, quickly!',12,0,100,0,0,57397,0,0,'Korvas Bloodthorn to Player');

-- Cyana near Immolanth SAI
SET @CYANA := 96672;
DELETE FROM `creature_text` WHERE `CreatureID` = @CYANA;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@CYANA,0,0,'That was too close for my liking. $n, the demon\'s power is yours.',12,0,100,0,0,57357,0,0,'Cyana to Player');

-- Kayn near Ashgolm SAI
SET @KAYN_1 := 102393;
DELETE FROM `creature_text` WHERE `CreatureID` = @KAYN_1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@KAYN_1,0,0,'Well done! The monster is contained. Let\'s meet up with the others.',12,0,100,0,0,55229,0,0,'Kayn to Player');

SET @ALLARI_1 := 96675;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ALLARI_1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ALLARI_1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ALLARI_1,0,0,0,19,0,100,0,39686,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Allari the Souleater - On Quest 'All the way Up' Taken - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ALLARI_1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@ALLARI_1,0,0,'The elevator will be here shortly. The others are waiting for you above.',12,0,100,0,0,57356,0,0,'Allari the Souleater to Player');

SET @KORVAS_2 := 97644;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@KORVAS_2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@KORVAS_2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KORVAS_2,0,0,0,10,0,100,1,1,15,0,0,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Korvas Bloodthorn - Within 1-15 Range Out of Combat LoS - Say Line 0 (No Repeat)"),
(@KORVAS_2,0,1,0,19,0,100,0,39694,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Quest 'Between Us And Freedom - Say Line 1"),
(@KORVAS_2,0,2,0,19,0,100,0,39688,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Quest 'Between Us And Freedom - Say Line 1"),
(@KORVAS_2,0,3,0,19,0,100,0,40255,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Quest 'Between Us And Freedom - Say Line 1"),
(@KORVAS_2,0,4,0,19,0,100,0,40256,0,0,0,1,1,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Korvas Bloodthorn - On Quest 'Between Us And Freedom - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = @KORVAS_2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@KORVAS_2,0,0,'Stop this foolish bickering. We do not have time for this!',12,0,100,0,0,57295,0,0,'Korvas Bloodthorn to Player'),
(@KORVAS_2,1,0,'Let\'s keep moving. The others are in the chamber just ahead.',12,0,100,0,0,57361,0,0,'Korvas Bloodthorn to Player');

SET @KHADGAR_1 := 97978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@KHADGAR_1;
DELETE FROM `creature_text` WHERE `CreatureID` = @KHADGAR_1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(@KHADGAR_1,0,0,'I am Arhmage Khadgar, leader of the Kirin Tor.',12,0,100,0,0,57302,0,0,'Khadgar to Player'),
(@KHADGAR_1,1,0,'Demon Hunters, Azeroth needs your help.',12,0,100,0,0,57364,0,0,'Khadgar to Player');

-- Stop Guldan Scene
DELETE FROM `scene_template` WHERE `SceneId`=1016 AND `ScriptPackageID`=1423;
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`ScriptName`) VALUES
(1016,26,1423,'scene_guldan_stealing_illidan_corpse');

DELETE FROM `gameobject_template` WHERE `entry` IN (246559, 246560, 246562, 246561, 246557, 246556, 246555, 246558);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES
('246559','3','33263','Small Treasure Chest','','Opening','','1','57','246559','1','0','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','110','3','0','0','0','0','0','0','0','0','0','0','64310','0','0','98','','','22423'),
('246560','3','33263','Small Treasure Chest','','Opening','','1','57','246560','1','0','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','110','3','0','0','0','0','0','0','0','0','0','0','64311','0','0','98','','','22423'),
('246562','3','33263','Small Treasure Chest','','Opening','','1','57','246562','1','0','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','110','3','0','0','0','0','0','0','0','0','0','0','64313','0','0','98','','','22423'),
('246561','3','33263','Small Treasure Chest','','Opening','','1','57','246561','1','0','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','110','3','0','0','0','0','0','0','0','0','0','0','64312','0','0','98','','','22423'),
('246557','3','33263','Small Treasure Chest','','Opening','','1','57','246557','1','0','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','110','3','0','0','0','0','0','0','0','0','0','0','64308','0','0','98','','','22423'),
('246556','3','33263','Small Treasure Chest','','Opening','','1','57','246556','1','0','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','110','3','0','0','0','0','0','0','0','0','0','0','64307','0','0','98','','','22423'),
('246555','3','33263','Small Treasure Chest','','Opening','','1','57','246555','1','0','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','110','3','0','0','0','0','0','0','0','0','0','0','64306','0','0','98','','','22423'),
('246558','3','33263','Small Treasure Chest','','Opening','','1','57','246558','1','0','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','110','3','0','0','0','0','0','0','0','0','0','0','64309','0','0','98','','','22423');

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (246559, 246560, 246562, 246561, 246557, 246556, 246555, 246558);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `reference`, `chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
('246560', '129196', '0', '100', '0', '1', '1', '2', '3', 'Legion Heartstone'),
('246560', '129210', '0', '99', '0', '1', '0', '2', '2', 'Fel Crystal Fragments'),
('246562', '129210', '0', '100', '0', '1', '0', '2', '3', 'Fel Crystal Fragments'),
('246559', '129196', '0', '100', '0', '1', '0', '2', '4', 'Legion Heartstone'),
('246561', '129196', '0', '100', '0', '1', '1', '2', '3', 'Legion Heartstone'),
('246561', '129210', '0', '99', '0', '1', '0', '2', '2', 'Fel Crystal Fragments'),
('246557', '129196', '0', '100', '0', '1', '1', '2', '3', 'Legion Heartstone'),
('246557', '129210', '0', '99', '0', '1', '0', '2', '2', 'Fel Crystal Fragments'),
('246555', '129210', '0', '100', '0', '1', '0', '2', '3', 'Fel Crystal Fragments'),
('246558', '129196', '0', '100', '0', '1', '1', '2', '3', 'Legion Heartstone'),
('246558', '129210', '0', '99', '0', '1', '0', '2', '2', 'Fel Crystal Fragments'),
('246556', '129210', '0', '100', '0', '1', '0', '2', '3', 'Fel Crystal Fragments');

UPDATE `gameobject_template` SET `name`='Small Treasure Chest', `castBarCaption`='Opening' WHERE `entry` IN (244689, 246309, 246353);
UPDATE `creature` SET `spawntimesecs`=120 WHERE `id`=92776 AND `map`=1468;
UPDATE `creature` SET `spawntimesecs`=120 WHERE `id`=92782 AND `map`=1468;

DELETE FROM `graveyard_zone` WHERE `GhostZone` IN (7871, 7866, 7864, 7819, 7873);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(5135, 7871, 0, 'TombOfThePenitent'),
(5136, 7866, 0, 'TheDemonWard'),
(5137, 7864, 0, 'ChamberOfNight'),
(5344, 7819, 0, 'VaultOfTheBetrayer - Corpse Catcher 1'),
(5345, 7819, 0, 'VaultOfTheBetrayer - Corpse Catcher 2'),
(5346, 7819, 0, 'VaultOfTheBetrayer - Corpse Catcher 3'),
(5347, 7819, 0, 'VaultOfTheBetrayer - Corpse Catcher 4'),
(5348, 7819, 0, 'VaultOfTheBetrayer - Corpse Catcher 5'),
(5349, 7819, 0, 'VaultOfTheBetrayer - Corpse Catcher 6'),
(5350, 7819, 0, 'VaultOfTheBetrayer - Corpse Catcher 7'),
(5356, 7873, 0, 'VaultOfSilence');

SET @CGUID := 280000000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+250 AND @CGUID+260;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 39660, 1468, 7814, 7871, 0, 0, 0, 0, 0, 4330.025, -315.0139, -283.7572, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: TombOfThePenitent - Difficulty: 0)
(@CGUID+251, 39660, 1468, 7814, 7873, 0, 0, 0, 0, 0, 4326.024, -598.0903, -281.8333, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: VaultOfSilence - Difficulty: 0)
(@CGUID+252, 39660, 1468, 7814, 7866, 0, 0, 0, 0, 0, 4442.008, -392.8559, 125.8984, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: TheDemonWard - Difficulty: 0)
(@CGUID+253, 39660, 1468, 7814, 7864, 0, 0, 0, 0, 0, 4184.598, -442.408, 269.8069, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: ChamberOfNight - Difficulty: 0)
(@CGUID+254, 39660, 1468, 7814, 7819, 0, 0, 0, 0, 0, 4079.568, -326.8594, -281.1126, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: VaultOfTheBetrayer - Catcher1 - Difficulty: 0)
(@CGUID+255, 39660, 1468, 7814, 7819, 0, 0, 0, 0, 0, 4050.474, -328.2865, -281.46, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: VaultOfTheBetrayer - Catcher2 - Difficulty: 0)
(@CGUID+256, 39660, 1468, 7814, 7819, 0, 0, 0, 0, 0, 4021.382, -327.4861, -281.1126, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: VaultOfTheBetrayer - Catcher3 - Difficulty: 0)
(@CGUID+257, 39660, 1468, 7814, 7819, 0, 0, 0, 0, 0, 4020.778, -297.4115, -281.46, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: VaultOfTheBetrayer - Catcher4 - Difficulty: 0)
(@CGUID+258, 39660, 1468, 7814, 7819, 0, 0, 0, 0, 0, 4023.035, -270.283, -281.1126, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: VaultOfTheBetrayer - Catcher5 - Difficulty: 0)
(@CGUID+259, 39660, 1468, 7814, 7819, 0, 0, 0, 0, 0, 4050.985, -268.4618, -281.4599, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Spirit Healer (Area: VotW: VaultOfTheBetrayer - Catcher6 - Difficulty: 0)
(@CGUID+260, 39660, 1468, 7814, 7819, 0, 0, 0, 0, 0, 4079.085, -269.4063, -281.1126, 5.090357, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549); -- Spirit Healer (Area: VotW: VaultOfTheBetrayer - Catcher7 - Difficulty: 0)
UPDATE `creature` SET `npcflag`=16384 WHERE `guid` BETWEEN @CGUID+250 AND @CGUID+260;

UPDATE `creature` SET `npcflag`=0 WHERE `guid`=20542913;

-- Altruis the Sufferer 3 SAI
SET @ALRTUIS_FEL_INFUSION := 92986;
UPDATE `creature` SET `spawntimesecs`=15 WHERE `guid`=20542724 AND `id`=@ALRTUIS_FEL_INFUSION;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ALRTUIS_FEL_INFUSION;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ALRTUIS_FEL_INFUSION AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ALRTUIS_FEL_INFUSION,0,0,0,10,0,100,1,1,15,25000,25000,1,0,10000,0,0,0,0,18,15,0,0,0,0,0,0,"Altruis the Sufferer - Within 1-15 Range Out of Combat LoS - Say Line 1 (No Repeat)"),
(@ALRTUIS_FEL_INFUSION,0,1,0,19,0,100,0,38689,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Altruis the Sufferer - On Quest 'Fel Infusion' Taken - Say Line 0"),
(@ALRTUIS_FEL_INFUSION,0,2,2,52,0,100,0,0,@ALRTUIS_FEL_INFUSION,0,0,12,@ALRTUIS_FEL_INFUSION*100+00,6,0,0,0,0,8,0,0,0,4321.75,-547.861,-281.497,1.68118,"Altruis the Sufferer - On Text 0 Over - Summon Creature 'Altruis the Sufferer'"),
(@ALRTUIS_FEL_INFUSION,0,3,0,61,0,100,0,0,@ALRTUIS_FEL_INFUSION,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Altruis the Sufferer - On Text 0 Over - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` = 92986;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
('92986', '0', '0', 'Time for answers later. There are demons to kill', '12', '0', '100', '0', '0', '57339', '0', '0', 'Altruis the Sufferer to Player'),
('92986', '0', '1', 'The Legion is here.', '12', '0', '100', '0', '0', '57388', '0', '0', 'Altruis the Sufferer to Player');

-- Altruis the Sufferer Summon SAI
SET @ALTRUIS_2_SUMMON := 9298600; -- 909992
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ALTRUIS_2_SUMMON;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ALTRUIS_2_SUMMON AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ALTRUIS_2_SUMMON,0,0,0,61,0,100,0,0,0,0,0,53,1,9298600,0,0,0,0,1,0,0,0,0,0,0,0,'Altruis the Sufferer - On Reset - Start Waypoint'),
(@ALTRUIS_2_SUMMON,0,1,0,54,0,100,0,0,0,0,0,53,1,9298600,0,0,0,0,1,0,0,0,0,0,0,0,'Altruis the Sufferer - Just Spawned - Start WP'),
(@ALTRUIS_2_SUMMON,0,2,0,40,0,100,0,4,9298600,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Altruis the Sufferer - On Waypoint 4 Reached - Despawn Instant');

DELETE FROM `creature_template` WHERE `entry`=@ALTRUIS_2_SUMMON;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ALTRUIS_2_SUMMON,'0','0','0','0','0','63985','0','0','0','Altruis the Sufferer','','Illidari',NULL,NULL,'0','100','100','5','0','0','2839','2','1','1.14286','1','1','0','1000','2000','1','1','1','33536','2048','0','0','0','0','0','0','7','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','SmartAI','0','3','1','10','1','5','1','1','1','1','0','0','1','0','0','','25549');

DELETE FROM `creature_template_addon` WHERE `entry`=@ALTRUIS_2_SUMMON;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(@ALTRUIS_2_SUMMON, '0', '0', '0', '1', '0', '0', '0', '0', NULL);

DELETE FROM `creature_equip_template` WHERE `CreatureID`=@ALTRUIS_2_SUMMON;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES 
(@ALTRUIS_2_SUMMON, '1', '128360', '0', '0', '128370', '0', '0', '0', '0', '0', '0');

DELETE FROM `waypoints` WHERE `entry`=9298600;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(9298600, 1, 4323.121, -541.476, -282.968, 'Altruis move'),
(9298600, 2, 4323.689, -538.507, -283.827, 'Altruis move'),
(9298600, 3, 4323.789, -525.309, -287.583, 'Altruis move'),
(9298600, 4, 4322.914, -516.714, -287.720, 'Altruis Despawn');

-- Kayn Sunfury 3 SAI
SET @KAYN_RISE := 92980;
UPDATE `creature` SET `spawntimesecs`=15 WHERE `guid`=20542693 AND `id`=@KAYN_RISE;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@KAYN_RISE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@KAYN_RISE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KAYN_RISE,0,0,0,19,0,100,0,38690,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Quest 'Rise of Illidari' Taken - Say Line 0"),
(@KAYN_RISE,0,1,2,52,0,100,0,0,@KAYN_RISE,0,0,12,@KAYN_RISE*100+00,6,0,0,0,0,8,0,0,0,4330.08,-548.288,-281.751,1.67951,"Kayn Sunfury - On Text 0 Over - Summon Creature 'Kayn Sunfury'"),
(@KAYN_RISE,0,2,0,61,0,100,0,0,@KAYN_RISE,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayn Sunfury - On Text 0 Over - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` = 92980;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
('92980', '0', '0', 'The demons aim to destroy our world. We need to release our alies.', '12', '0', '100', '0', '0', '55352', '0', '0', 'Kayn Sunfury to Player');

-- Kayn Sunfury Summon SAI
SET @KAYN_2_SUMMON := 9298000;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@KAYN_2_SUMMON;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@KAYN_2_SUMMON AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KAYN_2_SUMMON,0,0,0,61,0,100,0,0,0,0,0,53,1,9298000,0,0,0,0,1,0,0,0,0,0,0,0,'Kayn Sunfury - On Reset - Start WP'),
(@KAYN_2_SUMMON,0,1,0,54,0,100,0,0,0,0,0,53,1,9298000,0,0,0,0,1,0,0,0,0,0,0,0,'Kayn Sunfury - Just Spawned - Start WP'),
(@KAYN_2_SUMMON,0,2,0,40,0,100,0,4,9298000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kayn Sunfury - On Waypoint 4 Reached - Despawn Instant');

DELETE FROM `creature_template` WHERE `entry`=@KAYN_2_SUMMON;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(@KAYN_2_SUMMON,'0','0','0','0','0','61698','0','0','0','Kayn Sunfury','','Illidari',NULL,NULL,'0','100','100','5','0','0','2839','3','1','1.14286','1','1','0','1000','2000','1','1','1','32832','2048','0','0','0','0','0','0','7','4096','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','SmartAI','0','3','1','10','1','5','1','1','1','1','0','0','1','0','0','','25549');

DELETE FROM `creature_template_addon` WHERE `entry`=@KAYN_2_SUMMON;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(@KAYN_2_SUMMON, '0', '0', '0', '1', '0', '0', '0', '0', NULL);

DELETE FROM `creature_equip_template` WHERE `CreatureID`=@KAYN_2_SUMMON;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES 
(@KAYN_2_SUMMON, '1', '128359', '0', '0', '128371', '0', '0', '0', '0', '0', '0');

DELETE FROM `waypoints` WHERE `entry`=9298000;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(9298000, 1, 4328.037, -540.687, -283.179, 'Kayn move'),
(9298000, 2, 4328.187, -529.856, -286.617, 'Kayn move'),
(9298000, 3, 4328.747, -518.079, -287.721, 'Kayn move'),
(9298000, 4, 4332.642, -506.923, -288.638, 'Kayn Despawn');

UPDATE `creature_template` SET `minlevel`=99, `maxlevel`=99, `faction`=2395, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587720, `unit_flags2`=2048, `VehicleId`=4197, `MovementId` = 150, `AIName`='SmartAI', `InhabitType`=4 WHERE `entry`=99443;
DELETE FROM `smart_scripts` WHERE `entryorguid`=99443 AND `source_type`=0;
-- INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- (99443, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 85, 46598, 2, 0, 0, 0, 0, 1, 0, 0, 0, 4063.51, -296.51, -281.58, 0, 'Vampiric Felbat - Just Spawned - Invoker Cast Ride Vehicle Hardcoded'),
-- (99443, 0, 1, 0, 27, 0, 100, 0, 0, 0, 0, 0, 53, 1, 99443, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vampiric Felbat - Passenger Boarded - Start WP'),
-- (99443, 0, 2, 3, 58, 0, 100, 0, 13, 99443, 0, 0, 11, 68576, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vampiric Felbat - WP Ended - Cast Eject All Passengers'),
-- (99443, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vampiric Felbat - WP Ended - Despawn');

DELETE FROM `waypoints` WHERE `entry`=99443;
-- INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
-- (99443, 1, 4435.54, -289.252, -247.127, 'Vampiric Felbat1'),
-- (99443, 2, 4445.98, -299.189, -234.631, 'Vampiric Felbat2'),
-- (99443, 3, 4450.8, -320.845, -223.82, 'Vampiric Felbat3'),
-- (99443, 4, 4450.8, -320.845, -171.81, 'Vampiric Felbat4'),
-- (99443, 5, 4451.2, -321.103, -101.486, 'Vampiric Felbat5'),
-- (99443, 6, 4451.2, -321.103, -30.4712, 'Vampiric Felbat6'),
-- (99443, 7, 4451.2, -321.103, 5.68376, 'Vampiric Felbat7'),
-- (99443, 8, 4451.2, -321.103, 42.8748, 'Vampiric Felbat8'),
-- (99443, 9, 4451.2, -321.103, 78.3228, 'Vampiric Felbat9'),
-- (99443, 10, 4451.2, -321.103, 129.983, 'Vampiric Felbat10'),
-- (99443, 11, 4447.17, -323.197, 140.234, 'Vampiric Felbat11'),
-- (99443, 12, 4449.52, -341.185, 129.249, 'Vampiric Felbat12'),
-- (99443, 13, 4451.74, -359.885, 130.354, 'Vampiric Felbat13 - Despawn');

UPDATE `creature_template` SET `unit_flags`=768, `npcflag`=1 WHERE `entry`=99501;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=99501;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(99501, 202064, 1, 0);

SET @CGUID := 280000000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+261 AND @CGUID+268;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+261,96656,1468,0,0,0,0,0,0,-1,0,1,4392.36,-513.713,-281.484,2.7597,300,0,0,1266732,0,0,0,0,0,0,0,'',25549),
(@CGUID+262,96656,1468,0,0,0,0,0,0,-1,0,1,4361.92,-529.656,-274.719,2.26568,300,0,0,1304724,0,0,0,0,0,0,0,'',25549),
(@CGUID+263,96656,1468,0,0,0,0,0,0,-1,0,1,4305.08,-559.763,-281.487,1.12057,300,0,0,1266732,0,0,0,0,0,0,0,'',25549),
(@CGUID+264,96656,1468,0,0,0,0,0,0,-1,0,1,4346.46,-427.373,-281.485,4.42082,300,0,0,1266732,0,0,0,0,0,0,0,'',25549),
(@CGUID+265,96656,1468,0,0,0,0,0,0,-1,0,1,4280.47,-457.641,-287.566,4.61166,300,0,0,1266732,0,0,0,0,0,0,0,'',25549),
(@CGUID+266,96656,1468,0,0,0,0,0,0,-1,0,1,4280.5,-528.708,-274.754,1.61223,300,0,0,1266732,0,0,0,0,0,0,0,'',25549),
(@CGUID+267,96656,1468,0,0,0,0,0,0,-1,0,1,4289.63,-457.4,-274.719,5.52037,300,0,0,1304724,0,0,0,0,0,0,0,'',25549),
(@CGUID+268,96656,1468,0,0,0,0,0,0,-1,0,1,4362.25,-457.504,-274.719,3.95586,300,0,0,1266732,0,0,0,0,0,0,0,'',25549);

UPDATE `creature` SET `spawntimesecs`=60 WHERE `guid` IN (20542822, 20542748, 20542855, 20542737);
UPDATE `creature` SET `spawntimesecs`=30 WHERE `guid` IN (20542615, 20542616);
UPDATE `creature_template` SET `unit_flags`=384 WHERE (entry = 100717);

UPDATE `creature_template_addon` SET `path_id`=99631 WHERE `entry`=99631;
UPDATE `creature_template` SET `MovementType`=2 WHERE `entry`=99631;
DELETE FROM `waypoints` WHERE `entry`=99631;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(99631,1,4334.12,-590.217,-281.922,''),
(99631,2,4331.97,-589.663,-281.922,''),
(99631,3,4331.98,-589.172,-281.922,''),
(99631,4,4332.24,-588.301,-281.922,''),
(99631,5,4332.14,-587.541,-281.922,''),
(99631,6,4331.09,-584.03,-281.925,''),
(99631,7,4330.39,-583.545,-281.924,''),
(99631,8,4328.46,-583.66,-281.841,'');
DELETE FROM `waypoint_data` WHERE `id`=99631;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(99631,1,4334.12,-590.217,-281.922,0,0,0,0,100,0),
(99631,2,4331.97,-589.663,-281.922,0,0,0,0,100,0),
(99631,3,4331.98,-589.172,-281.922,0,0,0,0,100,0),
(99631,4,4332.24,-588.301,-281.922,0,0,0,0,100,0),
(99631,5,4332.14,-587.541,-281.922,0,0,0,0,100,0),
(99631,6,4331.09,-584.03,-281.925,0,0,0,0,100,0),
(99631,7,4330.39,-583.545,-281.924,0,0,0,0,100,0),
(99631,8,4328.46,-583.66,-281.841,0,0,0,0,100,0);

UPDATE `creature` SET `PhaseId` = 993 WHERE `guid` = 20542908;
UPDATE `creature` SET `PhaseId` = 993 WHERE `guid` = 20542909;
UPDATE `creature` SET `PhaseId` = 543 WHERE `guid` = 20542912;
UPDATE `creature` SET `PhaseId` = 543 WHERE `guid` = 20542915;
UPDATE `creature` SET `PhaseId` = 543 WHERE `guid` = 20542913;
UPDATE `creature` SET `PhaseId` = 543 WHERE `guid` = 20542914;

DELETE FROM `creature_text` WHERE `CreatureID` = 92985;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(92985,0,0,'Just like old times, eh Kayn?',12,0,100,0,0,57329,0,0,'Altruis the Sufferer to Kayn Sunfury'),
(92985,1,0,'After ten-thousand years of imprisonment, Illidan succumbed to the fel energy within. When he was freed, he was not in his right mind.',12,0,100,0,0,57284,0,0,'Altruis the Sufferer to Kayn Sunfury'),
(92985,2,0,'You followed Illidan blindly, like a dog. Even when he lost his way.',12,0,100,0,0,57326,0,0,'Altruis the Sufferer to Kayn Sunfury'),
(92985,3,0,'I fought as hard as the rest of you! But I did not murder thousands of innocents.',12,0,100,0,0,57386,0,0,'Altruis the Sufferer to Kayn Sunfury'),
(92985,4,0,'Fool! You would trust the warden? She hates us almost as much as the Legion.',12,0,100,0,0,57389,0,0,'Altruis the Sufferer to Kayn Sunfury');

DELETE FROM `creature_text` WHERE `CreatureID` = 92984;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(92984,0,0,'Do not speak to me of old times, Altruis. You betrayed Illidan. You betrayed us all!',12,0,100,0,0,57345,0,0,'Kayn Sunfury to Altruis the Sufferer'),
(92984,1,0,'He was fighting it, as we all do. He needed us to have faith in him, Altruis.',12,0,100,0,0,57325,0,0,'Kayn Sunfury to Altruis the Sufferer'),
(92984,2,0,'He made the hard choices. He sacrificed EVERYTHING. What did you give?',12,0,100,0,0,57321,0,0,'Kayn Sunfury to Altruis the Sufferer'),
(92984,3,0,'You heard the Warden. We are the only ones who can defeat the Legion. We MUST survive this place.',12,0,100,0,0,57322,0,0,'Kayn Sunfury to Altruis the Sufferer'),
(92984,4,0,'You trust no one and believe in nothing, Altruis. You are a leader with no followers.',12,0,100,0,0,57390,0,0,'Kayn Sunfury to Altruis the Sufferer');

UPDATE `creature_template` SET `MovementType`=2 WHERE `entry`=92984;
UPDATE `creature_template` SET `MovementType`=2 WHERE `entry`=92985;

-- UPDATE `creature` SET `ScriptName`='npc_altruis_sufferer_4' WHERE `guid`=20542908;
-- Overlord Saurfang in Orgri
DELETE FROM `creature` WHERE `guid`=280000275;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000275,100636,1,1637,5170,0,0,1178,0,-1,0,1,1606.07,-4376.37,21.8468,3.63639,300,0,0,1305,0,0,1,0,0,0,0,'npc_lord_saurfang',25549);
-- khadgar in Orgri
DELETE FROM `creature` WHERE `guid`=280000276;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000276,97296,1,1637,5170,0,0,1178,0,-1,0,1,1465.72,-4419.58,25.45,0.172787,120,0,0,9145554,5,0,2,0,0,0,0,'',25549);

DELETE FROM `creature_text` WHERE `CreatureID`=100636;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(100636,0,0,'I don\'t like the looks of them, mage. They smell of demon filth.',12,0,100,0,0,57915,0,0,'Lord Saurfang to Player');

DELETE FROM `npc_text` WHERE `ID` IN (30560, 30561, 30562, 30563, 30564);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(30560,1,0,0,0,0,0,0,0,147324,0,0,0,0,0,0,0,25549),
(30561,1,0,0,0,0,0,0,0,147325,0,0,0,0,0,0,0,25549),
(30562,1,0,0,0,0,0,0,0,147326,0,0,0,0,0,0,0,25549),
(30563,1,0,0,0,0,0,0,0,147327,0,0,0,0,0,0,0,25549),
(30564,1,0,0,0,0,0,0,0,147328,0,0,0,0,0,0,0,25549);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (20460, 20461, 20462, 20463, 20464);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(20460, 30560),
(20461, 30561),
(20462, 30562),
(20463, 30563),
(20464, 30564);

UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=100, `gossip_menu_id`=20460 WHERE `entry`=100636;
UPDATE `creature_template` SET `gossip_menu_id`=20461 WHERE `entry`=101035;
-- Alari the Souleater in Durotar Funeral
DELETE FROM `creature` WHERE `guid`=280000277;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000277,100873,1,14,4982,0,0,1180,0,-1,0,0,1272.81,-4383.71,28.735,3.48624,120,0,0,870,0,0,3,0,0,0,0,'',25549);
-- Lady Sylvana Windrunner in Durotar Funeral
DELETE FROM `creature` WHERE `guid`=280000278;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000278,101035,1,14,4982,0,0,1180,0,-1,0,0,1244.27,-4381.93,28.2979,4.74574,120,0,0,1075122944,0,0,3,0,0,0,0,'npc_lady_sylvana_funeral',25549);
-- Faction Acquisition quests
UPDATE `quest_template_addon` SET `PrevQuestID`=40976 WHERE `ID`=40982; -- Second Sight
UPDATE `quest_template_addon` SET `PrevQuestID`=40982 WHERE `ID`=40983; -- Demons Among Them
UPDATE `quest_template_addon` SET `PrevQuestID`=40983 WHERE `ID`=41002; -- A Weapon of the Horde
-- other quests to not mess up with the DH chain
UPDATE `quest_template_addon` SET `PrevQuestID`=40522 WHERE `ID`=40607; -- Demons Among Us
UPDATE `quest_template_addon` SET `PrevQuestID`=40607 WHERE `ID`=40605; -- Keep Your Friends Close
-- Felblade Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 280000301 AND 280000320;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000301,101104,1,14,4982,0,0,1181,0,-1,0,0,1234.2,-4423.7,22.5085,1.24287,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000302,101104,1,14,4982,0,0,1181,0,-1,0,0,1266.75,-4428.12,26.6402,2.11152,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000303,101104,1,14,4982,0,0,1181,0,-1,0,0,1294,-4389.82,26.2693,3.29276,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000304,101104,1,14,4982,0,0,1181,0,-1,0,0,1208.96,-4404.49,23.1639,0.0105786,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000305,101104,1,14,4982,0,0,1181,0,-1,0,0,1308.13,-4427.31,24.7053,2.7202,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000306,102543,1,14,4982,0,0,1181,0,-1,0,1,1264.68,-4398.66,26.3237,2.01098,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000307,102543,1,14,4982,0,0,1181,0,-1,0,1,1258.96,-4401.78,25.8567,1.77694,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000308,102543,1,14,4982,0,0,1181,0,-1,0,1,1263.19,-4407.53,25.7372,1.65755,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000309,102543,1,14,4982,0,0,1181,0,-1,0,1,1249.8,-4409.17,24.6836,2.19241,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000310,102543,1,14,4982,0,0,1181,0,-1,0,1,1242.62,-4413.61,23.726,1.96779,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000311,102543,1,14,4982,0,0,1181,0,-1,0,1,1248.65,-4419.28,23.8528,2.08481,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000312,102543,1,14,4982,0,0,1181,0,-1,0,1,1226.22,-4414.39,22.6062,1.0363,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000313,102543,1,14,4982,0,0,1181,0,-1,0,1,1218.39,-4409.72,22.9143,0.719791,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000314,102543,1,14,4982,0,0,1181,0,-1,0,1,1216.52,-4417.56,22.0563,0.7677,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000315,102543,1,14,4982,0,0,1181,0,-1,0,1,1244.4,-4390.51,28.2295,2.15628,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000316,102543,1,14,4982,0,0,1181,0,-1,0,1,1296.29,-4410.06,26.5713,2.26624,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000317,102543,1,14,4982,0,0,1181,0,-1,0,1,1293.49,-4434.14,27.1493,1.90103,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000318,102543,1,14,4982,0,0,1181,0,-1,0,1,1258.61,-4437.65,26.8017,1.70625,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000319,102543,1,14,4982,0,0,1181,0,-1,0,1,1227.55,-4448.21,24.2946,1.55939,120,0,0,174,0,0,0,0,0,0,0,'',25549),
(280000320,102543,1,14,4982,0,0,1181,0,-1,0,1,1224.24,-4394.29,23.6983,0.350657,120,0,0,174,0,0,0,0,0,0,0,'',25549);
UPDATE `creature_template` SET `KillCredit1`=101105, `minlevel`=99, `maxlevel`=99, `faction`=954, `unit_flags`=32768, `unit_flags2`=0 WHERE `entry` IN (102543, 101104);
UPDATE `creature_template_addon` SET `bytes1` = '0' , `auras` = '' WHERE `entry` = '102543';
UPDATE `creature_template` SET `faction` = '1786' WHERE `entry` = '102543';
UPDATE `creature_template` SET `unit_flags2` = '35653632' WHERE `entry` = '102543';
UPDATE `creature_template` SET `HealthScalingExpansion` = '5' , `lootid` = '98486' , `HealthModifier` = '1' WHERE `entry` = '102543';
UPDATE `scene_template` SET `ScriptName`='scene_demons_among_them_horde' WHERE `SceneId`=1453;
UPDATE `creature_template` SET `npcflag` = 2 WHERE `entry`=114562;

DELETE FROM `creature_text` WHERE `CreatureID` = 116704;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(116704,0,0,'I need to speak with you.',12,0,100,0,0,57295,0,0,'Korvas Bloodthorn to Player'),
(116704,1,0,'Altruis and the others await you at Krasus\' Landing. I\'ll meet you there.',12,0,100,0,0,57295,0,0,'Korvas Bloodthorn to Player'),
(116704,2,0,'Kayn and the others await you at Krasus\' Landing. I\'ll meet you there.',12,0,100,0,0,57295,0,0,'Korvas Bloodthorn to Player'),
(116704,3,0,'Every moment we sit idle, the Legion gains strength.',12,0,100,0,0,57295,0,0,'Korvas Bloodthorn to Player'),
(116704,4,0,'In Lord Illidan\'s absence, you are the ranking member of our order. We can\'t make this decision without you.',12,0,100,0,0,57295,0,0,'Korvas Bloodthorn to Player'),
(116704,5,0,'Let me know when you\'re ready.',12,0,100,0,0,57295,0,0,'Korvas Bloodthorn to Player');

UPDATE `creature_template` SET `npcflag`=2, `AIName`="", `ScriptName`='npc_korvas_bloodthorn_summon', `VerifiedBuild`=25549 WHERE `entry`=116704;
DELETE FROM `creature_equip_template` WHERE `CreatureID`=116704;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES 
(116704,1,128359,0,0,128371,0,0,0,0,0,25549);

UPDATE `creature_template` SET `npcflag`=3, `gossip_menu_id`=20463, `ScriptName`='npc_altruis_sufferer_artifact', `VerifiedBuild`=25549 WHERE `entry`=99254;

UPDATE `quest_template_addon` SET `PrevQuestID`=39047 WHERE `ID`=40816; -- The Power To Survive (Altruis)
UPDATE `quest_template_addon` SET `PrevQuestID`=39261 WHERE `ID`=40814; -- The Power To Survive (Kayn)
UPDATE `quest_template_addon` SET `PrevQuestID`=41120 WHERE `ID`=41121; -- By Any Means
UPDATE `quest_template_addon` SET `PrevQuestID`=41121 WHERE `ID`=41119; -- The Hunt

UPDATE `quest_template_addon` SET `PrevQuestID`=39689 WHERE `ID`=39691; -- The Call Of War
UPDATE `quest_template_addon` SET `PrevQuestID`=39691 WHERE `ID`=44471; -- Second Sight
UPDATE `quest_template_addon` SET `PrevQuestID`=44471 WHERE `ID`=44463; -- Demons Among Them
UPDATE `quest_template_addon` SET `PrevQuestID`=44463 WHERE `ID`=44473; -- A Weapon of the Alliance
UPDATE `quest_template_addon` SET `PrevQuestID`=40593 WHERE `ID`=44120; -- Illidari Allies

UPDATE `quest_template_addon` SET `PrevQuestID`=41803 WHERE `ID`=41804; -- Ask And You Shall Receive
UPDATE `quest_template_addon` SET `PrevQuestID`=41804 WHERE `ID`=41806; -- Return To Jace
UPDATE `quest_template_addon` SET `PrevQuestID`=41806 WHERE `ID`=41807; -- Establishing a Connection
UPDATE `quest_template_addon` SET `PrevQuestID`=41807 WHERE `ID`=41863; -- Vengeance Will Be Ours

DELETE FROM `playerchoice_response` WHERE `ChoiceId`=255;
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Header`, `Answer`, `Description`, `Confirmation`, `QuestId`, `VerifiedBuild`) VALUES
(255, 640, 2, 0, 'Vengeance', 'Select', 'The mighty Aldrachi were one of the few to stand against the Burning Legion. It took Sargeras to fell their greatest champion, seizing his warblades in the process. Now the traitorous Illidari Carla, servant of Kil\'Jaeden, wields the infamous warblades. The more souls she claims, the more powerful she becomes.\n\n            |cFF000000|Hitem:128832|h[Aldrachi Warblades]|h|r', 'CONFIRM_ARTIFACT_CHOICE', 40818, 25549),
(255, 641, 1, 0, 'Havoc', 'Select', 'These glaives belong to the former demon hunter Varedis Felsoul, who was slain defending the Black Temple many years ago. The Burning Legion\'s master, Kil\'jaeden the Deceiver, raised Varedis in the Twisting Nether and imbued his glaives with a piece of the demon lord\'s chaotic power.\n\n            |cFF000000|Hitem:127829|h[Twinblades of the Deceiver]|h|r', 'CONFIRM_ARTIFACT_CHOICE', 40817, 25549);

DELETE FROM `spell_target_position` WHERE `ID`=192757;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(192757, 0, 0, -8544.392578, 462.887299, 104.472054, 22566);

-- Delete Reward From Artifact Quests (Temporarly, only for the implemented ones)
UPDATE `quest_template` SET `RewardAmount1` = 0 WHERE `ID` IN (40817, 40818);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (41120,41803);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,41120,0,0,14,0,40818,0,0,0,0,0,"","Quest 'Making Arrangements' can only be taken if quest 'Aldrachi Warblades Chosen' is not taken"),
(19,0,41803,0,0,14,0,40817,0,0,0,0,0,"","Quest 'Asking A Favor' can only be taken if quest 'Twinblades of the Deceiver Chosen' is not taken");

DELETE FROM `creature` WHERE `guid` BETWEEN 280000321 AND 280000353;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000321,97296,0,1519,5390,0,0,175,0,-1,0,1,-8540.17,462.07,104.71,5.338177,120,0,0,9145554,5,0,2,0,0,0,0,'',25549), -- Khadgar
(280000322,102585,0,1519,6292,0,0,175,0,-1,0,1,-8386.70,256.77,155.34,5.436349,120,0,0,9145554,5,0,2,0,0,0,0,'npc_stormwind_jace',25549), -- Jace
(280000323,100472,0,1519,6292,0,0,175,0,-1,0,1,-8381.91,244.14,155.34,0.280596,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Aysa
(280000324,100471,0,1519,6292,0,0,175,0,-1,0,1,-8379.27,242.71,155.34,0.622245,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Gelbin
(280000325,109486,0,1519,6292,0,0,175,0,-1,0,1,-8375.32,239.37,155.34,0.775397,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Tyrande
(280000326,100977,0,1519,6292,0,0,175,0,-1,0,1,-8377.92,239.36,155.34,0.912056,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Malfurion
(280000327,100981,0,1519,6292,0,0,175,0,-1,0,1,-8367.53,245.38,155.34,3.007499,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Velen
(280000328,100454,0,1519,6292,0,0,175,0,-1,0,1,-8367.77,248.74,155.34,3.545497,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Muradin
(280000329,100456,0,1519,6292,0,0,175,0,-1,0,1,-8370.12,252.73,155.34,3.973544,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Falstad
(280000330,100455,0,1519,6292,0,0,175,0,-1,0,1,-8369.41,251.05,155.34,3.863588,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Moira
(280000331,100973,0,1519,6292,0,0,175,0,-1,0,1,-8363.29,232.547,157.073,2.2498,120,0,0,0,0,0,3,0,0,0,0,'',25549), -- Anduinn
(280000332,1756,0,1519,6292,0,0,175,0,-1,0,1,-8378.942,245.530,155.346,0.296706,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000333,1756,0,1519,6292,0,0,175,0,-1,0,1,-8376.486,242.281,155.347,1.069136,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000334,1756,0,1519,6292,0,0,175,0,-1,0,1,-8372.619,250.486,155.347,4.322258,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000335,1756,0,1519,6292,0,0,175,0,-1,0,1,-8370.068,247.454,155.347,3.368001,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000336,1756,0,1519,6292,0,0,175,0,-1,0,1,-8376.370,227.001,155.346,1.480863,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000337,1756,0,1519,6292,0,0,175,0,-1,0,1,-8354.978,243.959,155.346,2.984727,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000338,1756,0,1519,6292,0,0,175,0,-1,0,1,-8351.978,263.628,155.346,3.785607,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000339,1756,0,1519,6292,0,0,175,0,-1,0,1,-8371.314,268.122,155.346,4.527806,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000340,1756,0,1519,6292,0,0,175,0,-1,0,1,-8391.776,260.688,155.346,0.644793,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000341,1756,0,1519,6292,0,0,175,0,-1,0,1,-8384.391,266.399,155.346,3.773996,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000342,1756,0,1519,6292,0,0,175,0,-1,0,1,-8389.442,275.248,153.785,3.776624,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000343,1756,0,1519,6292,0,0,175,0,-1,0,1,-8391.933,278.380,152.785,3.773483,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000344,1756,0,1519,6292,0,0,175,0,-1,0,1,-8399.149,267.668,153.758,0.647596,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000345,1756,0,1519,6292,0,0,175,0,-1,0,1,-8401.752,270.572,152.784,0.646025,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000346,1756,0,1519,6292,0,0,175,0,-1,0,1,-8399.689,288.385,149.621,3.792332,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000347,1756,0,1519,6292,0,0,175,0,-1,0,1,-8402.229,291.475,148.621,3.775838,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000348,1756,0,1519,6292,0,0,175,0,-1,0,1,-8409.517,280.654,149.604,0.663304,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000349,1756,0,1519,6292,0,0,175,0,-1,0,1,-8412.028,283.738,148.610,0.657021,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000350,1756,0,1519,6292,0,0,175,0,-1,0,1,-8419.933,293.710,147.014,0.631103,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000351,1756,0,1519,6292,0,0,175,0,-1,0,1,-8422.538,296.917,147.014,0.656236,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000352,1756,0,1519,6292,0,0,175,0,-1,0,1,-8412.601,304.631,147.013,3.801755,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000353,1756,0,1519,6292,0,0,175,0,-1,0,1,-8410.082,301.516,147.013,3.797828,120,0,0,0,0,0,0,0,0,0,0,'',25549); -- Guard

DELETE FROM `creature` WHERE `guid` BETWEEN 280000354 AND 280000398;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000354,100973,0,1519,6292,0,0,176,0,-1,0,1,-8363.29,232.547,157.073,2.2498,120,0,0,0,0,0,3,0,0,0,0,'',25549), -- Anduinn
(280000355,100472,0,1519,6292,0,0,176,0,-1,0,1,-8361.094,244.066,155.333,1.441499,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Aysa
(280000356,100471,0,1519,6292,0,0,176,0,-1,0,1,-8371.305,238.017,155.311,2.585824,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Gelbin
(280000357,109486,0,1519,6292,0,0,176,0,-1,0,1,-8369.053,232.939,156.167,2.713844,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Tyrande
(280000358,100977,0,1519,6292,0,0,176,0,-1,0,1,-8374.339,232.658,155.318,2.978523,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Malfurion
(280000359,100981,0,1519,6292,0,0,176,0,-1,0,1,-8360.274,234.283,156.990,2.273232,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Velen
(280000360,100454,0,1519,6292,0,0,176,0,-1,0,1,-8365.908,241.111,155.321,1.824773,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Muradin
(280000361,100456,0,1519,6292,0,0,176,0,-1,0,1,-8359.758,238.273,156.125,1.363741,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Falstad
(280000362,100455,0,1519,6292,0,0,176,0,-1,0,1,-8364.902,237.553,156.154,1.836554,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Moira
(280000363,102585,0,1519,6292,0,0,176,0,-1,0,1,-8369.968,240.397,155.311,2.208833,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Jace
(280000364,1756,0,1519,6292,0,0,176,0,-1,0,1,-8391.776,260.688,155.346,0.644793,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000365,1756,0,1519,6292,0,0,176,0,-1,0,1,-8384.391,266.399,155.346,3.773996,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000366,1756,0,1519,6292,0,0,176,0,-1,0,1,-8389.442,275.248,153.785,3.776624,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000367,1756,0,1519,6292,0,0,176,0,-1,0,1,-8391.933,278.380,152.785,3.773483,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000368,1756,0,1519,6292,0,0,176,0,-1,0,1,-8399.149,267.668,153.758,0.647596,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000369,1756,0,1519,6292,0,0,176,0,-1,0,1,-8401.752,270.572,152.784,0.646025,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000370,1756,0,1519,6292,0,0,176,0,-1,0,1,-8399.689,288.385,149.621,3.792332,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000371,1756,0,1519,6292,0,0,176,0,-1,0,1,-8402.229,291.475,148.621,3.775838,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000372,1756,0,1519,6292,0,0,176,0,-1,0,1,-8409.517,280.654,149.604,0.663304,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000373,1756,0,1519,6292,0,0,176,0,-1,0,1,-8412.028,283.738,148.610,0.657021,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000374,1756,0,1519,6292,0,0,176,0,-1,0,1,-8419.933,293.710,147.014,0.631103,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000375,1756,0,1519,6292,0,0,176,0,-1,0,1,-8422.538,296.917,147.014,0.656236,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000376,1756,0,1519,6292,0,0,176,0,-1,0,1,-8412.601,304.631,147.013,3.801755,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000377,1756,0,1519,6292,0,0,176,0,-1,0,1,-8410.082,301.516,147.013,3.797828,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Guard
(280000378,102543,0,1519,6292,0,0,176,0,-1,0,1,-8351.075,264.363,155.346,3.827532,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000379,102543,0,1519,6292,0,0,176,0,-1,0,1,-8340.072,265.599,155.346,3.687732,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000380,102543,0,1519,6292,0,0,176,0,-1,0,1,-8346.911,274.800,155.346,3.741139,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000381,102543,0,1519,6292,0,0,176,0,-1,0,1,-8336.067,276.607,156.832,3.876228,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000382,102543,0,1519,6292,0,0,176,0,-1,0,1,-8399.436,225.984,155.347,0.664735,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000383,102543,0,1519,6292,0,0,176,0,-1,0,1,-8391.369,261.094,155.347,0.644316,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000384,102543,0,1519,6292,0,0,176,0,-1,0,1,-8384.396,266.405,155.347,3.785910,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000385,102543,0,1519,6292,0,0,176,0,-1,0,1,-8410.036,303.340,147.014,3.797690,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000386,102543,0,1519,6292,0,0,176,0,-1,0,1,-8421.426,294.345,147.014,0.708721,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000387,102543,0,1519,6292,0,0,176,0,-1,0,1,-8410.985,281.752,149.161,0.721288,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000388,102543,0,1519,6292,0,0,176,0,-1,0,1,-8401.074,289.815,149.124,3.814184,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000389,102543,0,1519,6292,0,0,176,0,-1,0,1,-8400.776,269.493,153.145,0.630967,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000390,102543,0,1519,6292,0,0,176,0,-1,0,1,-8390.620,277.214,153.217,3.850315,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000391,102543,0,1519,6292,0,0,176,0,-1,0,1,-8405.039,214.168,155.346,0.718823,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000392,102543,0,1519,6292,0,0,176,0,-1,0,1,-8412.923,222.840,155.346,0.603369,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000393,102543,0,1519,6292,0,0,176,0,-1,0,1,-8423.000,215.158,155.346,0.683480,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000394,102543,0,1519,6292,0,0,176,0,-1,0,1,-8414.742,205.794,155.346,0.687407,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Felblade
(280000395,100993,0,1519,6292,0,0,176,0,-1,0,1,-8371.511,239.132,155.311,0.674953,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Dead Felblade
(280000396,100993,0,1519,6292,0,0,176,0,-1,0,1,-8356.389,244.339,155.345,4.298779,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Dead Felblade
(280000397,100993,0,1519,6292,0,0,176,0,-1,0,1,-8371.095,249.906,155.345,3.237705,120,0,0,0,0,0,0,0,0,0,0,'',25549), -- Dead Felblade
(280000398,100993,0,1519,6292,0,0,176,0,-1,0,1,-8379.079,247.806,155.347,3.123822,120,0,0,0,0,0,0,0,0,0,0,'',25549); -- Dead Felblade

DELETE FROM `creature_addon` WHERE `guid` BETWEEN 280000354 AND 280000363;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(280000354,0,0,0,1,27,0,0,0,''),
(280000355,0,0,0,1,27,0,0,0,''),
(280000356,0,0,0,1,27,0,0,0,''),
(280000357,0,0,0,1,27,0,0,0,''),
(280000358,0,0,0,1,27,0,0,0,''),
(280000359,0,0,0,1,27,0,0,0,''),
(280000360,0,0,0,1,27,0,0,0,''),
(280000361,0,0,0,1,27,0,0,0,''),
(280000362,0,0,0,1,27,0,0,0,''),
(280000363,0,0,0,1,27,0,0,0,'');

DELETE FROM `gameobject` WHERE `guid` BETWEEN 51014100 AND 51014300;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES
(51014100,245649,0,1519,6292,0,0,175,0,-1,-8424.86,319.094,145.584,5.60214,0,0,0.33398,-0.94258,120,255,1,0,'',22423),
(51014101,245649,0,1519,6292,0,0,175,0,-1,-8422.75,318.646,145.758,3.13535,0,0,0.999995,0.00312133,120,255,1,0,'',22423),
(51014102,245649,0,1519,6292,0,0,175,0,-1,-8434.14,310.514,145.682,4.39963,0,0,0.808605,-0.588352,120,255,1,0,'',22423),
(51014103,245649,0,1519,6292,0,0,175,0,-1,-8419.82,313.059,146.402,3.0435,0,0,0.998797,0.0490267,120,255,1,0,'',22423),
(51014104,245649,0,1519,6292,0,0,175,0,-1,-8424.81,316.856,145.77,3.89481,0,0,0.929917,-0.367769,120,255,1,0,'',22423),
(51014105,245649,0,1519,6292,0,0,175,0,-1,-8422.27,314.925,146.091,0.504482,0,0,0.249575,0.968356,120,255,1,0,'',22423),
(51014106,245649,0,1519,6292,0,0,175,0,-1,-8412.63,304.816,147.014,0.112494,0,0,0.0562173,0.998419,120,255,1,0,'',22423),
(51014107,245649,0,1519,6292,0,0,175,0,-1,-8428.9,304.474,146.513,0.97466,0,0,0.468268,0.883586,120,255,1,0,'',22423),
(51014108,245649,0,1519,6292,0,0,175,0,-1,-8431.24,309.21,145.975,4.2703,0,0,0.844935,-0.53487,120,255,1,0,'',22423),
(51014109,245649,0,1519,6292,0,0,175,0,-1,-8430.4,306.788,146.227,3.73291,0,0,0.95661,-0.29137,120,255,1,0,'',22423),
(51014110,245649,0,1519,6292,0,0,175,0,-1,-8432.66,309.764,145.839,2.48892,0,0,0.947223,0.320575,120,255,1,0,'',22423),
(51014111,245649,0,1519,6292,0,0,175,0,-1,-8422.14,298.417,147.014,5.30874,0,0,0.468173,-0.883637,120,255,1,0,'',22423),
(51014112,245649,0,1519,6292,0,0,175,0,-1,-8398.92,286.63,150.085,3.89481,0,0,0.929917,-0.367769,120,255,1,0,'',22423),
(51014113,245649,0,1519,6292,0,0,175,0,-1,-8420.58,292.592,147.014,1.8064,0,0,0.785312,0.6191,120,255,1,0,'',22423),
(51014114,245649,0,1519,6292,0,0,175,0,-1,-8401.63,290.179,148.969,0.504482,0,0,0.249575,0.968356,120,255,1,0,'',22423),
(51014115,245649,0,1519,6292,0,0,175,0,-1,-8392.84,278.464,152.628,2.48892,0,0,0.947223,0.320575,120,255,1,0,'',22423),
(51014116,245649,0,1519,6292,0,0,175,0,-1,-8408.86,279.29,149.973,3.0435,0,0,0.998797,0.0490267,120,255,1,0,'',22423),
(51014117,245649,0,1519,6292,0,0,175,0,-1,-8394.32,279.214,152.251,4.39963,0,0,0.808605,-0.588352,120,255,1,0,'',22423),
(51014118,245649,0,1519,6292,0,0,175,0,-1,-8411.31,281.156,149.228,0.504482,0,0,0.249575,0.968356,120,255,1,0,'',22423),
(51014119,245649,0,1519,6292,0,0,175,0,-1,-8404.05,292.118,148.212,3.13535,0,0,0.999995,0.00312133,120,255,1,0,'',22423),
(51014120,245649,0,1519,6292,0,0,175,0,-1,-8413.85,283.087,148.455,3.89481,0,0,0.929917,-0.367769,120,255,1,0,'',22423),
(51014121,245649,0,1519,6292,0,0,175,0,-1,-8411.79,284.877,148.426,3.13535,0,0,0.999995,0.00312133,120,255,1,0,'',22423),
(51014122,245649,0,1519,6292,0,0,175,0,-1,-8399.18,288.312,149.714,3.0435,0,0,0.998797,0.0490267,120,255,1,0,'',22423),
(51014123,245649,0,1519,6292,0,0,175,0,-1,-8410.51,300.832,147.014,2.31972,0,0,0.916747,0.399468,120,255,1,0,'',22423),
(51014124,245649,0,1519,6292,0,0,175,0,-1,-8390.58,275.488,153.561,3.73291,0,0,0.95661,-0.29137,120,255,1,0,'',22423),
(51014125,245649,0,1519,6292,0,0,175,0,-1,-8398.22,265.731,154.282,3.89481,0,0,0.929917,-0.367769,120,255,1,0,'',22423),
(51014126,245649,0,1519,6292,0,0,175,0,-1,-8389.08,273.174,154.248,0.97466,0,0,0.468268,0.883586,120,255,1,0,'',22423),
(51014127,245649,0,1519,6292,0,0,175,0,-1,-8391.42,277.91,152.957,4.2703,0,0,0.844935,-0.53487,120,255,1,0,'',22423),
(51014128,245649,0,1519,6292,0,0,175,0,-1,-8400.93,269.28,153.166,0.504482,0,0,0.249575,0.968356,120,255,1,0,'',22423),
(51014129,245649,0,1519,6292,0,0,175,0,-1,-8403.54,271.962,152.234,3.73291,0,0,0.95661,-0.29137,120,255,1,0,'',22423),
(51014130,245649,0,1519,6292,0,0,175,0,-1,-8402.04,269.648,152.921,0.97466,0,0,0.468268,0.883586,120,255,1,0,'',22423),
(51014131,245649,0,1519,6292,0,0,175,0,-1,-8398.49,267.413,153.911,3.0435,0,0,0.998797,0.0490267,120,255,1,0,'',22423),
(51014132,245649,0,1519,6292,0,0,175,0,-1,-8377.22,246.682,155.347,4.08617,0,0,0.890529,-0.454926,120,255,1,0,'',22423),
(51014133,245649,0,1519,6292,0,0,175,0,-1,-8376.58,247.361,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014134,245649,0,1519,6292,0,0,175,0,-1,-8374.09,249.707,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014135,245649,0,1519,6292,0,0,175,0,-1,-8375.21,249.154,155.347,1.31395,0,0,0.610724,0.791843,120,255,1,0,'',22423),
(51014136,245649,0,1519,6292,0,0,175,0,-1,-8375.06,248.809,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014137,245649,0,1519,6292,0,0,175,0,-1,-8376.9,247.771,155.347,4.59481,0,0,0.747432,-0.664339,120,255,1,0,'',22423),
(51014138,245649,0,1519,6292,0,0,175,0,-1,-8377.02,247.26,155.347,0.958326,0,0,0.461037,0.887381,120,255,1,0,'',22423),
(51014139,245649,0,1519,6292,0,0,175,0,-1,-8373.97,249.128,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014140,245649,0,1519,6292,0,0,175,0,-1,-8374.88,249.207,155.347,3.26766,0,0,0.998014,-0.0629919,120,255,1,0,'',22423),
(51014141,245649,0,1519,6292,0,0,175,0,-1,-8377.62,246.946,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014142,245649,0,1519,6292,0,0,175,0,-1,-8374.36,249.434,155.347,0.851876,0,0,0.413175,0.910652,120,255,1,0,'',22423),
(51014143,245649,0,1519,6292,0,0,175,0,-1,-8374.6,248.88,155.347,4.00723,0,0,0.907787,-0.419431,120,255,1,0,'',22423),
(51014144,245649,0,1519,6292,0,0,175,0,-1,-8373.9,249.865,155.347,4.03958,0,0,0.900884,-0.434059,120,255,1,0,'',22423),
(51014145,245649,0,1519,6292,0,0,175,0,-1,-8377.11,247.019,155.347,0.346144,0,0,0.172209,0.98506,120,255,1,0,'',22423),
(51014146,245649,0,1519,6292,0,0,175,0,-1,-8377.99,246.738,155.347,0.28436,0,0,0.141701,0.989909,120,255,1,0,'',22423),
(51014147,245649,0,1519,6292,0,0,175,0,-1,-8376.71,246.946,155.347,0.218751,0,0,0.109158,0.994024,120,255,1,0,'',22423),
(51014148,245649,0,1519,6292,0,0,175,0,-1,-8374.48,249.111,155.347,3.39506,0,0,0.99198,-0.126395,120,255,1,0,'',22423),
(51014149,245649,0,1519,6292,0,0,175,0,-1,-8375.53,248.597,155.347,3.62259,0,0,0.971219,-0.238187,120,255,1,0,'',22423),
(51014150,245649,0,1519,6292,0,0,175,0,-1,-8378.49,246.531,155.347,2.65719,0,0,0.970812,0.23984,120,255,1,0,'',22423),
(51014151,245649,0,1519,6292,0,0,175,0,-1,-8376.12,247.632,155.347,0.573691,0,0,0.282928,0.959141,120,255,1,0,'',22423),
(51014152,245649,0,1519,6292,0,0,175,0,-1,-8374.78,248.384,155.347,1.36051,0,0,0.628991,0.777412,120,255,1,0,'',22423),
(51014153,245649,0,1519,6292,0,0,175,0,-1,-8377.46,246.385,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014154,245649,0,1519,6292,0,0,175,0,-1,-8373.59,249.297,155.347,3.33327,0,0,0.995411,-0.0956921,120,255,1,0,'',22423),
(51014155,245649,0,1519,6292,0,0,175,0,-1,-8377.64,246.219,155.347,0.990678,0,0,0.47533,0.879808,120,255,1,0,'',22423),
(51014156,245649,0,1519,6292,0,0,175,0,-1,-8377.53,243.491,155.347,4.84877,0,0,0.657283,-0.753644,120,255,1,0,'',22423),
(51014157,245649,0,1519,6292,0,0,175,0,-1,-8371.71,249.082,155.347,6.08848,0,0,0.0971989,-0.995265,120,255,1,0,'',22423),
(51014158,245649,0,1519,6292,0,0,175,0,-1,-8370.88,249.205,155.347,1.71242,0,0,0.755364,0.655305,120,255,1,0,'',22423),
(51014159,245649,0,1519,6292,0,0,175,0,-1,-8370.97,248.814,155.347,1.83982,0,0,0.795547,0.605892,120,255,1,0,'',22423),
(51014160,245649,0,1519,6292,0,0,175,0,-1,-8377.19,243.767,155.347,5.58835,0,0,0.340471,-0.940255,120,255,1,0,'',22423),
(51014161,245649,0,1519,6292,0,0,175,0,-1,-8373.06,249.458,155.347,5.7061,0,0,0.284555,-0.95866,120,255,1,0,'',22423),
(51014162,245640,0,1519,6292,0,0,175,0,-1,-8374.69,246.219,155.347,3.83248,0,0,0.940925,-0.338614,120,255,1,0,'',22423),
(51014163,245649,0,1519,6292,0,0,175,0,-1,-8371.21,248.92,155.347,2.45199,0,0,0.941143,0.33801,120,255,1,0,'',22423),
(51014164,245649,0,1519,6292,0,0,175,0,-1,-8372.23,249.654,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014165,245649,0,1519,6292,0,0,175,0,-1,-8377.43,243.872,155.347,4.97616,0,0,0.607979,-0.793953,120,255,1,0,'',22423),
(51014166,245649,0,1519,6292,0,0,175,0,-1,-8377.64,244.783,155.347,4.91438,0,0,0.63221,-0.774797,120,255,1,0,'',22423),
(51014167,245649,0,1519,6292,0,0,175,0,-1,-8371.52,249.851,155.347,2.06736,0,0,0.859188,0.511661,120,255,1,0,'',22423),
(51014168,245649,0,1519,6292,0,0,175,0,-1,-8378.19,244.469,155.347,5.6207,0,0,0.325218,-0.945639,120,255,1,0,'',22423),
(51014169,245649,0,1519,6292,0,0,175,0,-1,-8375.35,247.859,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014170,245649,0,1519,6292,0,0,175,0,-1,-8370.65,248.674,155.347,5.57984,0,0,0.344468,-0.938798,120,255,1,0,'',22423),
(51014171,245649,0,1519,6292,0,0,175,0,-1,-8378.03,244.279,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014172,245649,0,1519,6292,0,0,175,0,-1,-8371.28,249.373,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014173,245649,0,1519,6292,0,0,175,0,-1,-8377.45,244.399,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014174,245649,0,1519,6292,0,0,175,0,-1,-8376.39,247.043,155.347,4.54825,0,0,0.762694,-0.64676,120,255,1,0,'',22423),
(51014175,245649,0,1519,6292,0,0,175,0,-1,-8377.75,244.012,155.347,2.43299,0,0,0.937889,0.346935,120,255,1,0,'',22423),
(51014176,245649,0,1519,6292,0,0,175,0,-1,-8377.79,245.295,155.347,1.00403,0,0,0.481193,0.876615,120,255,1,0,'',22423),
(51014177,245649,0,1519,6292,0,0,175,0,-1,-8370.94,249.533,155.347,6.04192,0,0,0.12034,-0.992733,120,255,1,0,'',22423),
(51014178,245649,0,1519,6292,0,0,175,0,-1,-8377.47,243.154,155.347,2.89507,0,0,0.992413,0.122949,120,255,1,0,'',22423),
(51014179,245649,0,1519,6292,0,0,175,0,-1,-8370.76,247.913,155.347,1.77803,0,0,0.776451,0.630177,120,255,1,0,'',22423),
(51014180,245649,0,1519,6292,0,0,175,0,-1,-8370.95,248.295,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014181,245649,0,1519,6292,0,0,175,0,-1,-8370.37,248.417,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014182,245649,0,1519,6292,0,0,175,0,-1,-8376.9,242.846,155.347,5.20371,0,0,0.513911,-0.857844,120,255,1,0,'',22423),
(51014183,245649,0,1519,6292,0,0,175,0,-1,-8377.13,243.311,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014184,245649,0,1519,6292,0,0,175,0,-1,-8376.69,243.604,155.347,2.94163,0,0,0.995006,0.0998149,120,255,1,0,'',22423),
(51014185,245649,0,1519,6292,0,0,175,0,-1,-8370.21,248.226,155.347,2.48435,0,0,0.946488,0.322738,120,255,1,0,'',22423),
(51014186,245649,0,1519,6292,0,0,175,0,-1,-8371.97,245.627,155.347,3.34924,0,0,0.994615,-0.103637,120,255,1,0,'',22423),
(51014187,245649,0,1519,6292,0,0,175,0,-1,-8374.09,243.729,155.347,0.854521,0,0,0.414379,0.910104,120,255,1,0,'',22423),
(51014188,245649,0,1519,6292,0,0,175,0,-1,-8370.59,247.389,155.347,4.15088,0,0,0.875347,-0.483496,120,255,1,0,'',22423),
(51014189,245649,0,1519,6292,0,0,175,0,-1,-8374.72,243.488,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014190,245649,0,1519,6292,0,0,175,0,-1,-8371.2,246.189,155.347,2.5589,0,0,0.957858,0.287242,120,255,1,0,'',22423),
(51014191,245649,0,1519,6292,0,0,175,0,-1,-8371.02,246.359,155.347,4.12117,0,0,0.882432,-0.470439,120,255,1,0,'',22423),
(51014192,245649,0,1519,6292,0,0,175,0,-1,-8375.64,243.16,155.347,2.55339,0,0,0.957063,0.28988,120,255,1,0,'',22423),
(51014193,245649,0,1519,6292,0,0,175,0,-1,-8374.2,243.5,155.347,0.242342,0,0,0.120875,0.992668,120,255,1,0,'',22423),
(51014194,245649,0,1519,6292,0,0,175,0,-1,-8372.1,245.224,155.347,2.5589,0,0,0.957858,0.287242,120,255,1,0,'',22423),
(51014195,245649,0,1519,6292,0,0,175,0,-1,-8371.65,245.319,155.347,4.08881,0,0,0.889928,-0.456101,120,255,1,0,'',22423),
(51014196,245649,0,1519,6292,0,0,175,0,-1,-8373.33,244.736,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014197,245649,0,1519,6292,0,0,175,0,-1,-8372.56,244.958,155.347,3.70418,0,0,0.960697,-0.277599,120,255,1,0,'',22423),
(51014198,245649,0,1519,6292,0,0,175,0,-1,-8373.64,243.795,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014199,245649,0,1519,6292,0,0,175,0,-1,-8373.91,244.229,155.347,4.491,0,0,0.780892,-0.624666,120,255,1,0,'',22423),
(51014200,245649,0,1519,6292,0,0,175,0,-1,-8371.45,245.892,155.347,0.933465,0,0,0.449971,0.893043,120,255,1,0,'',22423),
(51014201,245649,0,1519,6292,0,0,175,0,-1,-8371.56,245.571,155.347,3.47664,0,0,0.986001,-0.166741,120,255,1,0,'',22423),
(51014202,245649,0,1519,6292,0,0,175,0,-1,-8375.11,243.321,155.347,0.180558,0,0,0.0901564,0.995928,120,255,1,0,'',22423),
(51014203,245649,0,1519,6292,0,0,175,0,-1,-8372.29,245.547,155.347,1.39555,0,0,0.642514,0.766274,120,255,1,0,'',22423),
(51014204,245649,0,1519,6292,0,0,175,0,-1,-8376.18,243.04,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014205,245649,0,1519,6292,0,0,175,0,-1,-8374.34,243.177,155.347,3.98236,0,0,0.912932,-0.408111,120,255,1,0,'',22423),
(51014206,245649,0,1519,6292,0,0,175,0,-1,-8374.61,242.904,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014207,245649,0,1519,6292,0,0,175,0,-1,-8374.81,242.757,155.347,0.886873,0,0,0.429046,0.903283,120,255,1,0,'',22423),
(51014208,245649,0,1519,6292,0,0,175,0,-1,-8370.68,245.839,155.347,3.41486,0,0,0.99068,-0.136209,120,255,1,0,'',22423),
(51014209,245649,0,1519,6292,0,0,175,0,-1,-8372.31,244.247,155.347,2.5589,0,0,0.957858,0.287242,120,255,1,0,'',22423),
(51014210,245649,0,1519,6292,0,0,175,0,-1,-8373.82,243.394,155.347,0.114949,0,0,0.0574429,0.998349,120,255,1,0,'',22423),
(51014211,245649,0,1519,6292,0,0,175,0,-1,-8371.78,244.807,155.347,1.4421,0,0,0.660174,0.751113,120,255,1,0,'',22423),
(51014212,245649,0,1519,6292,0,0,175,0,-1,-8370.18,246.028,155.347,5.78769,0,0,0.245221,-0.969467,120,255,1,0,'',22423),
(51014213,245649,0,1519,6292,0,0,175,0,-1,-8371.05,245.627,155.347,2.5589,0,0,0.957858,0.287242,120,255,1,0,'',22423),
(51014214,245649,0,1519,6292,0,0,175,0,-1,-8373.15,244.009,155.347,0.469888,0,0,0.232789,0.972527,120,255,1,0,'',22423),
(51014215,245649,0,1519,6292,0,0,175,0,-1,-8373.48,243.444,155.347,4.44444,0,0,0.795221,-0.606319,120,255,1,0,'',22423),
(51014216,245649,0,1519,6292,0,0,175,0,-1,-8372.31,244.247,155.347,2.5589,0,0,0.957858,0.287242,120,255,1,0,'',22423),
(51014217,245649,0,1519,6292,0,0,175,0,-1,-8373.48,243.444,155.347,4.44444,0,0,0.795221,-0.606319,120,255,1,0,'',22423),
(51014218,245649,0,1519,6292,0,0,175,0,-1,-8372.1,245.224,155.347,2.5589,0,0,0.957858,0.287242,120,255,1,0,'',22423),
(51014219,245649,0,1519,6292,0,0,175,0,-1,-8371.56,245.571,155.347,3.47664,0,0,0.986001,-0.166741,120,255,1,0,'',22423),
(51014220,245649,0,1519,6292,0,0,175,0,-1,-8374.09,243.729,155.347,0.854521,0,0,0.414379,0.910104,120,255,1,0,'',22423),
(51014221,245649,0,1519,6292,0,0,175,0,-1,-8373.82,243.394,155.347,0.114949,0,0,0.0574429,0.998349,120,255,1,0,'',22423),
(51014222,245649,0,1519,6292,0,0,175,0,-1,-8373.33,244.736,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014223,245649,0,1519,6292,0,0,175,0,-1,-8371.2,246.189,155.347,2.5589,0,0,0.957858,0.287242,120,255,1,0,'',22423),
(51014224,245649,0,1519,6292,0,0,175,0,-1,-8372.56,244.958,155.347,3.70418,0,0,0.960697,-0.277599,120,255,1,0,'',22423),
(51014225,245649,0,1519,6292,0,0,175,0,-1,-8371.65,245.319,155.347,4.08881,0,0,0.889928,-0.456101,120,255,1,0,'',22423),
(51014226,245649,0,1519,6292,0,0,175,0,-1,-8371.78,244.807,155.347,1.4421,0,0,0.660174,0.751113,120,255,1,0,'',22423),
(51014227,245649,0,1519,6292,0,0,175,0,-1,-8375.11,243.321,155.347,0.180558,0,0,0.0901564,0.995928,120,255,1,0,'',22423),
(51014228,245649,0,1519,6292,0,0,175,0,-1,-8372.29,245.547,155.347,1.39555,0,0,0.642514,0.766274,120,255,1,0,'',22423),
(51014229,245649,0,1519,6292,0,0,175,0,-1,-8374.61,242.904,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014230,245649,0,1519,6292,0,0,175,0,-1,-8373.15,244.009,155.347,0.469888,0,0,0.232789,0.972527,120,255,1,0,'',22423),
(51014231,245649,0,1519,6292,0,0,175,0,-1,-8370.18,246.028,155.347,5.78769,0,0,0.245221,-0.969467,120,255,1,0,'',22423),
(51014232,245649,0,1519,6292,0,0,175,0,-1,-8374.72,243.488,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014233,245649,0,1519,6292,0,0,175,0,-1,-8371.05,245.627,155.347,2.5589,0,0,0.957858,0.287242,120,255,1,0,'',22423),
(51014234,245649,0,1519,6292,0,0,175,0,-1,-8373.91,244.229,155.347,4.491,0,0,0.780892,-0.624666,120,255,1,0,'',22423),
(51014235,245649,0,1519,6292,0,0,175,0,-1,-8371.97,245.627,155.347,3.34924,0,0,0.994615,-0.103637,120,255,1,0,'',22423),
(51014236,245649,0,1519,6292,0,0,175,0,-1,-8371.45,245.892,155.347,0.933465,0,0,0.449971,0.893043,120,255,1,0,'',22423),
(51014237,245649,0,1519,6292,0,0,175,0,-1,-8374.34,243.177,155.347,3.98236,0,0,0.912932,-0.408111,120,255,1,0,'',22423),
(51014238,245649,0,1519,6292,0,0,175,0,-1,-8373.64,243.795,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014239,245649,0,1519,6292,0,0,175,0,-1,-8370.68,245.839,155.347,3.41486,0,0,0.99068,-0.136209,120,255,1,0,'',22423),
(51014240,245649,0,1519,6292,0,0,175,0,-1,-8374.81,242.757,155.347,0.886873,0,0,0.429046,0.903283,120,255,1,0,'',22423),
(51014241,245649,0,1519,6292,0,0,175,0,-1,-8374.2,243.5,155.347,0.242342,0,0,0.120875,0.992668,120,255,1,0,'',22423),
(51014242,245649,0,1519,6292,0,0,175,0,-1,-8370.97,248.814,155.347,1.83982,0,0,0.795547,0.605892,120,255,1,0,'',22423),
(51014243,245649,0,1519,6292,0,0,175,0,-1,-8370.37,248.417,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014244,245649,0,1519,6292,0,0,175,0,-1,-8376.69,243.604,155.347,2.94163,0,0,0.995006,0.0998149,120,255,1,0,'',22423),
(51014245,245649,0,1519,6292,0,0,175,0,-1,-8376.18,243.04,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014246,245649,0,1519,6292,0,0,175,0,-1,-8377.53,243.491,155.347,4.84877,0,0,0.657283,-0.753644,120,255,1,0,'',22423),
(51014247,245649,0,1519,6292,0,0,175,0,-1,-8378.03,244.279,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014248,245649,0,1519,6292,0,0,175,0,-1,-8377.75,244.012,155.347,2.43299,0,0,0.937889,0.346935,120,255,1,0,'',22423),
(51014249,245649,0,1519,6292,0,0,175,0,-1,-8377.47,243.154,155.347,2.89507,0,0,0.992413,0.122949,120,255,1,0,'',22423),
(51014250,245649,0,1519,6292,0,0,175,0,-1,-8371.21,248.92,155.347,2.45199,0,0,0.941143,0.33801,120,255,1,0,'',22423),
(51014251,245649,0,1519,6292,0,0,175,0,-1,-8370.59,247.389,155.347,4.15088,0,0,0.875347,-0.483496,120,255,1,0,'',22423),
(51014252,245649,0,1519,6292,0,0,175,0,-1,-8377.13,243.311,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014253,245649,0,1519,6292,0,0,175,0,-1,-8370.76,247.913,155.347,1.77803,0,0,0.776451,0.630177,120,255,1,0,'',22423),
(51014254,245649,0,1519,6292,0,0,175,0,-1,-8376.9,242.846,155.347,5.20371,0,0,0.513911,-0.857844,120,255,1,0,'',22423),
(51014255,245649,0,1519,6292,0,0,175,0,-1,-8377.19,243.767,155.347,5.58835,0,0,0.340471,-0.940255,120,255,1,0,'',22423),
(51014256,245649,0,1519,6292,0,0,175,0,-1,-8370.88,249.205,155.347,1.71242,0,0,0.755364,0.655305,120,255,1,0,'',22423),
(51014257,245649,0,1519,6292,0,0,175,0,-1,-8377.45,244.399,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014258,245649,0,1519,6292,0,0,175,0,-1,-8370.65,248.674,155.347,5.57984,0,0,0.344468,-0.938798,120,255,1,0,'',22423),
(51014259,245649,0,1519,6292,0,0,175,0,-1,-8370.95,248.295,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014260,245649,0,1519,6292,0,0,175,0,-1,-8371.02,246.359,155.347,4.12117,0,0,0.882432,-0.470439,120,255,1,0,'',22423),
(51014261,245649,0,1519,6292,0,0,175,0,-1,-8375.64,243.16,155.347,2.55339,0,0,0.957063,0.28988,120,255,1,0,'',22423),
(51014262,245649,0,1519,6292,0,0,175,0,-1,-8377.43,243.872,155.347,4.97616,0,0,0.607979,-0.793953,120,255,1,0,'',22423),
(51014263,245649,0,1519,6292,0,0,175,0,-1,-8370.21,248.226,155.347,2.48435,0,0,0.946488,0.322738,120,255,1,0,'',22423),
(51014264,245640,0,1519,6292,0,0,175,0,-1,-8374.69,246.219,155.347,3.83248,0,0,0.940925,-0.338614,120,255,1,0,'',22423),
(51014265,245649,0,1519,6292,0,0,175,0,-1,-8377.46,246.385,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014266,245649,0,1519,6292,0,0,175,0,-1,-8374.48,249.111,155.347,3.39506,0,0,0.99198,-0.126395,120,255,1,0,'',22423),
(51014267,245649,0,1519,6292,0,0,175,0,-1,-8377.64,246.219,155.347,0.990678,0,0,0.47533,0.879808,120,255,1,0,'',22423),
(51014268,245649,0,1519,6292,0,0,175,0,-1,-8371.28,249.373,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014269,245649,0,1519,6292,0,0,175,0,-1,-8376.39,247.043,155.347,4.54825,0,0,0.762694,-0.64676,120,255,1,0,'',22423),
(51014270,245649,0,1519,6292,0,0,175,0,-1,-8376.58,247.361,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014271,245649,0,1519,6292,0,0,175,0,-1,-8374.78,248.384,155.347,1.36051,0,0,0.628991,0.777412,120,255,1,0,'',22423),
(51014272,245649,0,1519,6292,0,0,175,0,-1,-8373.06,249.458,155.347,5.7061,0,0,0.284555,-0.95866,120,255,1,0,'',22423),
(51014273,245649,0,1519,6292,0,0,175,0,-1,-8376.12,247.632,155.347,0.573691,0,0,0.282928,0.959141,120,255,1,0,'',22423),
(51014274,245649,0,1519,6292,0,0,175,0,-1,-8370.94,249.533,155.347,6.04192,0,0,0.12034,-0.992733,120,255,1,0,'',22423),
(51014275,245649,0,1519,6292,0,0,175,0,-1,-8371.71,249.082,155.347,6.08848,0,0,0.0971989,-0.995265,120,255,1,0,'',22423),
(51014276,245649,0,1519,6292,0,0,175,0,-1,-8372.23,249.654,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014277,245649,0,1519,6292,0,0,175,0,-1,-8377.11,247.019,155.347,0.346144,0,0,0.172209,0.98506,120,255,1,0,'',22423),
(51014278,245649,0,1519,6292,0,0,175,0,-1,-8373.59,249.297,155.347,3.33327,0,0,0.995411,-0.0956921,120,255,1,0,'',22423),
(51014279,245649,0,1519,6292,0,0,175,0,-1,-8375.35,247.859,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014280,245649,0,1519,6292,0,0,175,0,-1,-8374.6,248.88,155.347,4.00723,0,0,0.907787,-0.419431,120,255,1,0,'',22423),
(51014281,245649,0,1519,6292,0,0,175,0,-1,-8377.22,246.682,155.347,4.08617,0,0,0.890529,-0.454926,120,255,1,0,'',22423),
(51014282,245649,0,1519,6292,0,0,175,0,-1,-8378.19,244.469,155.347,5.6207,0,0,0.325218,-0.945639,120,255,1,0,'',22423),
(51014283,245649,0,1519,6292,0,0,175,0,-1,-8376.71,246.946,155.347,0.218751,0,0,0.109158,0.994024,120,255,1,0,'',22423),
(51014284,245649,0,1519,6292,0,0,175,0,-1,-8377.02,247.26,155.347,0.958326,0,0,0.461037,0.887381,120,255,1,0,'',22423),
(51014285,245649,0,1519,6292,0,0,175,0,-1,-8373.97,249.128,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014286,245649,0,1519,6292,0,0,175,0,-1,-8377.64,244.783,155.347,4.91438,0,0,0.63221,-0.774797,120,255,1,0,'',22423),
(51014287,245649,0,1519,6292,0,0,175,0,-1,-8371.52,249.851,155.347,2.06736,0,0,0.859188,0.511661,120,255,1,0,'',22423),
(51014288,245649,0,1519,6292,0,0,175,0,-1,-8377.79,245.295,155.347,1.00403,0,0,0.481193,0.876615,120,255,1,0,'',22423),
(51014289,245649,0,1519,6292,0,0,175,0,-1,-8375.06,248.809,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014290,245649,0,1519,6292,0,0,175,0,-1,-8375.21,249.154,155.347,1.31395,0,0,0.610724,0.791843,120,255,1,0,'',22423),
(51014291,245649,0,1519,6292,0,0,175,0,-1,-8373.9,249.865,155.347,4.03958,0,0,0.900884,-0.434059,120,255,1,0,'',22423),
(51014292,245649,0,1519,6292,0,0,175,0,-1,-8378.49,246.531,155.347,2.65719,0,0,0.970812,0.23984,120,255,1,0,'',22423),
(51014293,245649,0,1519,6292,0,0,175,0,-1,-8377.99,246.738,155.347,0.28436,0,0,0.141701,0.989909,120,255,1,0,'',22423),
(51014294,245649,0,1519,6292,0,0,175,0,-1,-8375.53,248.597,155.347,3.62259,0,0,0.971219,-0.238187,120,255,1,0,'',22423),
(51014295,245649,0,1519,6292,0,0,175,0,-1,-8377.62,246.946,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014296,245649,0,1519,6292,0,0,175,0,-1,-8376.38,248.344,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014297,245649,0,1519,6292,0,0,175,0,-1,-8374.09,249.707,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014298,245649,0,1519,6292,0,0,175,0,-1,-8376.9,247.771,155.347,4.59481,0,0,0.747432,-0.664339,120,255,1,0,'',22423),
(51014299,245649,0,1519,6292,0,0,175,0,-1,-8374.36,249.434,155.347,0.851876,0,0,0.413175,0.910652,120,255,1,0,'',22423),
(51014300,245649,0,1519,6292,0,0,175,0,-1,-8374.88,249.207,155.347,3.26766,0,0,0.998014,-0.0629919,120,255,1,0,'',22423);

DELETE FROM `gameobject` WHERE `guid` BETWEEN 51014301 AND 51014365;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES
(51014301,245640,0,1519,6292,0,0,176,0,-1,-8374.69,246.219,155.347,3.83248,0,0,0.940925,-0.338614,120,255,1,0,'',22423),
(51014302,245649,0,1519,6292,0,0,176,0,-1,-8377.46,246.385,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014303,245649,0,1519,6292,0,0,176,0,-1,-8374.48,249.111,155.347,3.39506,0,0,0.99198,-0.126395,120,255,1,0,'',22423),
(51014304,245649,0,1519,6292,0,0,176,0,-1,-8377.64,246.219,155.347,0.990678,0,0,0.47533,0.879808,120,255,1,0,'',22423),
(51014305,245649,0,1519,6292,0,0,176,0,-1,-8371.28,249.373,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014306,245649,0,1519,6292,0,0,176,0,-1,-8376.39,247.043,155.347,4.54825,0,0,0.762694,-0.64676,120,255,1,0,'',22423),
(51014307,245649,0,1519,6292,0,0,176,0,-1,-8376.58,247.361,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014308,245649,0,1519,6292,0,0,176,0,-1,-8374.78,248.384,155.347,1.36051,0,0,0.628991,0.777412,120,255,1,0,'',22423),
(51014309,245649,0,1519,6292,0,0,176,0,-1,-8373.06,249.458,155.347,5.7061,0,0,0.284555,-0.95866,120,255,1,0,'',22423),
(51014310,245649,0,1519,6292,0,0,176,0,-1,-8376.12,247.632,155.347,0.573691,0,0,0.282928,0.959141,120,255,1,0,'',22423),
(51014311,245649,0,1519,6292,0,0,176,0,-1,-8370.94,249.533,155.347,6.04192,0,0,0.12034,-0.992733,120,255,1,0,'',22423),
(51014312,245649,0,1519,6292,0,0,176,0,-1,-8371.71,249.082,155.347,6.08848,0,0,0.0971989,-0.995265,120,255,1,0,'',22423),
(51014313,245649,0,1519,6292,0,0,176,0,-1,-8372.23,249.654,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014314,245649,0,1519,6292,0,0,176,0,-1,-8377.11,247.019,155.347,0.346144,0,0,0.172209,0.98506,120,255,1,0,'',22423),
(51014315,245649,0,1519,6292,0,0,176,0,-1,-8373.59,249.297,155.347,3.33327,0,0,0.995411,-0.0956921,120,255,1,0,'',22423),
(51014316,245649,0,1519,6292,0,0,176,0,-1,-8375.35,247.859,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014317,245649,0,1519,6292,0,0,176,0,-1,-8374.6,248.88,155.347,4.00723,0,0,0.907787,-0.419431,120,255,1,0,'',22423),
(51014318,245649,0,1519,6292,0,0,176,0,-1,-8377.22,246.682,155.347,4.08617,0,0,0.890529,-0.454926,120,255,1,0,'',22423),
(51014319,245649,0,1519,6292,0,0,176,0,-1,-8378.19,244.469,155.347,5.6207,0,0,0.325218,-0.945639,120,255,1,0,'',22423),
(51014320,245649,0,1519,6292,0,0,176,0,-1,-8376.71,246.946,155.347,0.218751,0,0,0.109158,0.994024,120,255,1,0,'',22423),
(51014321,245649,0,1519,6292,0,0,176,0,-1,-8377.02,247.26,155.347,0.958326,0,0,0.461037,0.887381,120,255,1,0,'',22423),
(51014322,245649,0,1519,6292,0,0,176,0,-1,-8373.97,249.128,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014323,245649,0,1519,6292,0,0,176,0,-1,-8377.64,244.783,155.347,4.91438,0,0,0.63221,-0.774797,120,255,1,0,'',22423),
(51014324,245649,0,1519,6292,0,0,176,0,-1,-8371.52,249.851,155.347,2.06736,0,0,0.859188,0.511661,120,255,1,0,'',22423),
(51014325,245649,0,1519,6292,0,0,176,0,-1,-8377.79,245.295,155.347,1.00403,0,0,0.481193,0.876615,120,255,1,0,'',22423),
(51014326,245649,0,1519,6292,0,0,176,0,-1,-8375.06,248.809,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014327,245649,0,1519,6292,0,0,176,0,-1,-8375.21,249.154,155.347,1.31395,0,0,0.610724,0.791843,120,255,1,0,'',22423),
(51014328,245649,0,1519,6292,0,0,176,0,-1,-8373.9,249.865,155.347,4.03958,0,0,0.900884,-0.434059,120,255,1,0,'',22423),
(51014329,245649,0,1519,6292,0,0,176,0,-1,-8378.49,246.531,155.347,2.65719,0,0,0.970812,0.23984,120,255,1,0,'',22423),
(51014330,245649,0,1519,6292,0,0,176,0,-1,-8377.99,246.738,155.347,0.28436,0,0,0.141701,0.989909,120,255,1,0,'',22423),
(51014331,245649,0,1519,6292,0,0,176,0,-1,-8375.53,248.597,155.347,3.62259,0,0,0.971219,-0.238187,120,255,1,0,'',22423),
(51014332,245649,0,1519,6292,0,0,176,0,-1,-8377.62,246.946,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014333,245649,0,1519,6292,0,0,176,0,-1,-8376.38,248.344,155.347,5.71161,0,0,0.281913,-0.95944,120,255,1,0,'',22423),
(51014334,245649,0,1519,6292,0,0,176,0,-1,-8374.09,249.707,155.347,2.47731,0,0,0.945346,0.326068,120,255,1,0,'',22423),
(51014335,245649,0,1519,6292,0,0,176,0,-1,-8376.9,247.771,155.347,4.59481,0,0,0.747432,-0.664339,120,255,1,0,'',22423),
(51014336,245649,0,1519,6292,0,0,176,0,-1,-8374.36,249.434,155.347,0.851876,0,0,0.413175,0.910652,120,255,1,0,'',22423),
(51014337,245649,0,1519,6292,0,0,176,0,-1,-8374.88,249.207,155.347,3.26766,0,0,0.998014,-0.0629919,120,255,1,0,'',22423),
(51014338,245649,0,1519,6292,0,0,176,0,-1,-8375.64,243.16,155.347,2.55339,0,0,0.957063,0.28988,120,255,1,0,'',22423),
(51014339,245649,0,1519,6292,0,0,176,0,-1,-8377.43,243.872,155.347,4.97616,0,0,0.607979,-0.793953,120,255,1,0,'',22423),
(51014340,245649,0,1519,6292,0,0,176,0,-1,-8370.21,248.226,155.347,2.48435,0,0,0.946488,0.322738,120,255,1,0,'',22423),
(51014341,245649,0,1519,6292,0,0,176,0,-1,-8371.45,245.892,155.347,0.933465,0,0,0.449971,0.893043,120,255,1,0,'',22423),
(51014342,245649,0,1519,6292,0,0,176,0,-1,-8374.34,243.177,155.347,3.98236,0,0,0.912932,-0.408111,120,255,1,0,'',22423),
(51014343,245649,0,1519,6292,0,0,176,0,-1,-8373.64,243.795,155.347,5.6078,0,0,0.331311,-0.943522,120,255,1,0,'',22423),
(51014344,245649,0,1519,6292,0,0,176,0,-1,-8370.68,245.839,155.347,3.41486,0,0,0.99068,-0.136209,120,255,1,0,'',22423),
(51014345,245649,0,1519,6292,0,0,176,0,-1,-8374.81,242.757,155.347,0.886873,0,0,0.429046,0.903283,120,255,1,0,'',22423),
(51014346,245649,0,1519,6292,0,0,176,0,-1,-8374.2,243.5,155.347,0.242342,0,0,0.120875,0.992668,120,255,1,0,'',22423),
(51014347,245649,0,1519,6292,0,0,176,0,-1,-8370.97,248.814,155.347,1.83982,0,0,0.795547,0.605892,120,255,1,0,'',22423),
(51014348,245649,0,1519,6292,0,0,176,0,-1,-8370.37,248.417,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014349,245649,0,1519,6292,0,0,176,0,-1,-8376.69,243.604,155.347,2.94163,0,0,0.995006,0.0998149,120,255,1,0,'',22423),
(51014350,245649,0,1519,6292,0,0,176,0,-1,-8376.18,243.04,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014351,245649,0,1519,6292,0,0,176,0,-1,-8377.53,243.491,155.347,4.84877,0,0,0.657283,-0.753644,120,255,1,0,'',22423),
(51014352,245649,0,1519,6292,0,0,176,0,-1,-8378.03,244.279,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014353,245649,0,1519,6292,0,0,176,0,-1,-8377.75,244.012,155.347,2.43299,0,0,0.937889,0.346935,120,255,1,0,'',22423),
(51014354,245649,0,1519,6292,0,0,176,0,-1,-8377.47,243.154,155.347,2.89507,0,0,0.992413,0.122949,120,255,1,0,'',22423),
(51014355,245649,0,1519,6292,0,0,176,0,-1,-8371.21,248.92,155.347,2.45199,0,0,0.941143,0.33801,120,255,1,0,'',22423),
(51014356,245649,0,1519,6292,0,0,176,0,-1,-8370.59,247.389,155.347,4.15088,0,0,0.875347,-0.483496,120,255,1,0,'',22423),
(51014357,245649,0,1519,6292,0,0,176,0,-1,-8377.13,243.311,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014358,245649,0,1519,6292,0,0,176,0,-1,-8370.76,247.913,155.347,1.77803,0,0,0.776451,0.630177,120,255,1,0,'',22423),
(51014359,245649,0,1519,6292,0,0,176,0,-1,-8376.9,242.846,155.347,5.20371,0,0,0.513911,-0.857844,120,255,1,0,'',22423),
(51014360,245649,0,1519,6292,0,0,176,0,-1,-8377.19,243.767,155.347,5.58835,0,0,0.340471,-0.940255,120,255,1,0,'',22423),
(51014361,245649,0,1519,6292,0,0,176,0,-1,-8370.88,249.205,155.347,1.71242,0,0,0.755364,0.655305,120,255,1,0,'',22423),
(51014362,245649,0,1519,6292,0,0,176,0,-1,-8377.45,244.399,155.347,4.05844,0,0,0.896751,-0.442535,120,255,1,0,'',22423),
(51014363,245649,0,1519,6292,0,0,176,0,-1,-8370.65,248.674,155.347,5.57984,0,0,0.344468,-0.938798,120,255,1,0,'',22423),
(51014364,245649,0,1519,6292,0,0,176,0,-1,-8370.95,248.295,155.347,0.922094,0,0,0.444886,0.895587,120,255,1,0,'',22423),
(51014365,245649,0,1519,6292,0,0,176,0,-1,-8371.02,246.359,155.347,4.12117,0,0,0.882432,-0.470439,120,255,1,0,'',22423);

UPDATE `creature_template` SET `gossip_menu_id`=20464, `ScriptName`='npc_anduin_wrynn' WHERE `entry`=100973;
UPDATE `scene_template` SET `ScriptName`='scene_demons_among_them_alliance' WHERE `SceneId`=1456;
UPDATE `quest_template_addon` SET `ScriptName` = 'quest_demons_among_them' WHERE `ID` = 44463;
UPDATE `creature_template` SET `KillCredit2`= 100993 WHERE `entry` = 102543;

DELETE FROM `creature` WHERE `guid` IN (280000399 , 280000400);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000399,103156,1220,7502,7592,0,0,171,0,-1,0,0,-952.355,4333.064,740.184,4.087,120,0,0,800,0,0,2,0,0,0,0,'',25549), -- Altruis the Sufferer
(280000400,96313,1220,7502,7592,0,0,171,0,-1,0,0,-956.850,4329.416,740.170,0.853,120,0,0,0,0,0,1,0,0,0,0,'npc_warden_alturas',25549);

SET @QUEST_STATUS_NONE = 1;
SET @QUEST_STATUS_COMPLETE = 2;
SET @QUEST_STATUS_INCOMPLETE = 8;
SET @QUEST_STATUS_FAILED = 32;
SET @QUEST_STATUS_REWARDED = 64;

SET @QUEST_TAKEN = @QUEST_STATUS_INCOMPLETE | @QUEST_STATUS_FAILED | @QUEST_STATUS_COMPLETE | @QUEST_STATUS_REWARDED;
SET @QUEST_STATUS_NOT_COMPLETED = @QUEST_STATUS_NONE | @QUEST_STATUS_INCOMPLETE | @QUEST_STATUS_FAILED;
SET @QUEST_STATUS_NOT_IN_PROGRESS = @QUEST_STATUS_NONE | @QUEST_STATUS_FAILED | @QUEST_STATUS_COMPLETE | @QUEST_STATUS_REWARDED;
SET @QUEST_STATUS_COMPLETED_REWARDED = @QUEST_STATUS_COMPLETE | @QUEST_STATUS_REWARDED;

DELETE FROM `spell_area` WHERE `area` IN (5390, 6292);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `quest_start_status`, `quest_end_status`) VALUES
(57569, 5390, 39689, 39691, @QUEST_STATUS_REWARDED, @QUEST_STATUS_COMPLETED_REWARDED), -- Phase 175 on Stormwind Canals starting when quest 39689 rewarded until 39691 rewarded
(57569, 6292, 39689, 44471, @QUEST_STATUS_REWARDED, @QUEST_STATUS_REWARDED), -- Phase 175 on Stormwind Keep starting when quest 39691 rewarded until 44463 incompleted/taken
(57569, 6292, 44471, 44463, @QUEST_STATUS_REWARDED, @QUEST_STATUS_INCOMPLETE),
(74789, 6292, 44463, 44473, @QUEST_STATUS_COMPLETED_REWARDED, @QUEST_STATUS_COMPLETED_REWARDED), -- Phase 176 on Stormwind Keep starting when quest 44463 rewarded until 44473 rewarded
(172329, 6292, 44473, 0, @QUEST_STATUS_COMPLETED_REWARDED, 0);

DELETE FROM `spell_area` WHERE `area` = 7592 AND `spell` = 59074;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `quest_start_status`, `quest_end_status`) VALUES
(59074, 7592, 41120, 41121, @QUEST_TAKEN, @QUEST_STATUS_COMPLETED_REWARDED);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceEntry`=6292) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (175,176));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 175, 6292, 0, 0, 9, 0, 44463, 0, 0, 0, 0, 0, '', 'Stormwind Keep Phase 175 when Quest 44463 taken'),
(26, 175, 6292, 0, 0, 48, 0, 286650, 0, 0, 1, 0, 0, '', 'Stormwind Keep Set in Phase 175 from start to - Complete first objective of quest 44463'),
(26, 176, 6292, 0, 0, 48, 0, 286650, 0, 0, 0, 0, 0, '', 'Stormwind Keep Set in Phase 176 from Complete first objective of quest 44463'),
(26, 176, 6292, 0, 0, 8, 0, 44463, 0, 0, 1, 0, 0, '', 'Stormwind Keep Set in Phase 176 to reward 44463');

DELETE FROM `phase_area` WHERE `AreaId` = 6292 AND `PhaseId` IN (175, 176);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(6292, 175, 'Stormwind Keep - quest 44463 taken quest objective not complete'),
(6292, 176, 'Stormwind Keep - quest 44463 first objective complete');

-- Felblade Assassin SAI
SET @FELBLADE_ASSASSIN := 102543;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@FELBLADE_ASSASSIN;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@FELBLADE_ASSASSIN AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FELBLADE_ASSASSIN,0,0,0,0,0,100,1,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Felblade Assassin - In Combat - Say Line 0 (No Repeat)"),
(@FELBLADE_ASSASSIN,0,1,0,0,0,100,0,5000,8000,12000,15000,11,225207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felblade Assassin - In Combat - Cast 'Unwavering Assault'");

DELETE FROM `creature_text` WHERE `CreatureID` = 102543;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(102543, 0, 0, 'I live to serve.', 12, 0, 100, 0, 0, 55363, 0, 0, 'Felblade Assassin to Demon Hunter');

-- Mardum Scripts
UPDATE `creature_template` SET `ScriptName` = 'npc_brood_queen_tyranna' WHERE `entry` = 93802;
UPDATE `creature` SET `ScriptName` = 'npc_kayn_tyranna_fight' WHERE `guid` = 20542609;
UPDATE `creature` SET `ScriptName` = 'npc_allari_tyranna_fight' WHERE `guid` = 20542497;
UPDATE `creature` SET `ScriptName` = 'npc_jace_tyranna_fight' WHERE `guid` = 20542610;
UPDATE `creature` SET `ScriptName` = 'npc_korvas_tyranna_fight' WHERE `guid` = 20542498;
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `guid` = 20542608;

DELETE FROM `creature_text` WHERE `CreatureID` = 93802;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(93802, 0, 0, '$p, You and your demon hunters are nothing.', 12, 0, 100, 0, 3000, 55363, 0, 0, 'Brood Queen Tyranna to Demon Hunter'),
(93802, 1, 0, 'The keystone was entrusted to me by Sargeras himself. You will not have it!', 12, 0, 100, 0, 4000, 55065, 0, 0, 'Brood Queen Tyranna to Demon Hunter'),
(93802, 2, 0, 'None can resist my kiss.', 14, 0, 100, 0, 0, 55068, 0, 0, 'Brood Queen Tyranna to Demon Hunter'),
(93802, 3, 0, 'Come forth, my children. Feast upon our enemies.', 14, 0, 100, 0, 0, 55069, 0, 0, 'Brood Queen Tyranna to Demon Hunter'),
(93802, 4, 0, 'My Lord Sargeras, no!!!', 14, 0, 100, 0, 0, 55055, 0, 0, 'Brood Queen Tyranna to Demon Hunter');

DELETE FROM `creature_text` WHERE `CreatureID` = 97244;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97244, 0, 0, 'Grab the keystone! Let\'s get to the portal down below and back to the Black Temple!', 14, 0, 100, 0, 0, 55268, 0, 0, 'Kayn Sunfury yells to Player');

DELETE FROM `creature_text` WHERE `CreatureID` = 97297;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(97297, 0, 0, 'I\'ll secure the exit portal back to the Black Temple once the others fly up here.', 12, 0, 100, 0, 0, 55096, 0, 0, 'Cyana Nightglaive to Player'),
(97297, 1, 0, 'Hurry. Kayn has already launched the attack on Tyranna.', 12, 0, 100, 0, 0, 55095, 0, 0, 'Cyana Nightglaive to Player');

-- Cyana Nightglaive SAI
SET @CYANA_NIGHTGLAIVE := 97297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@CYANA_NIGHTGLAIVE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CYANA_NIGHTGLAIVE AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CYANA_NIGHTGLAIVE,0,0,0,19,0,100,0,38728,0,0,0,66,0,0,0,0,0,0,21,5,0,0,0,0,0,0,"Cyana Nightglaive - On Quest 'The Keystone' Taken - Set Orientation Closest Player"), 
(@CYANA_NIGHTGLAIVE,0,1,0,19,0,100,0,38728,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Cyana Nightglaive - On Quest 'The Keystone' Taken - Say Line 0"),
(@CYANA_NIGHTGLAIVE,0,2,0,52,0,100,0,0,97297,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Cyana Nightglaives - On Text 0 Over - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 96313;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(96313, 0, 0, 'If you don\'t have time to explain, then I don\'t have time to waste on you.', 12, 0, 100, 0, 0, 64624, 0, 0, 'Warden Alturas to Player'),
(96313, 1, 0, 'Fair enough. Let\'s get this over with, then.', 12, 0, 100, 0, 0, 64623, 0, 0, 'Warden Alturas to Player'),
(96313, 2, 0, 'You\'re fortunate that Khadgar trusts you. But make no mistake... I do not share his sentiment.', 12, 0, 100, 0, 0, 64622, 0, 0, 'Warden Alturas to Player'),
(96313, 3, 0, 'You may enter the hold, but I will not put the lives of my guards at risk for your mission. Is that clear?', 12, 0, 100, 0, 0, 64641, 0, 0, 'Warden Alturas to Player');

DELETE FROM `spell_area` WHERE `area` = 7873 AND `spell` = 59074;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `quest_start_status`, `quest_end_status`) VALUES
(59074, 7873, 38672, 38672, @QUEST_TAKEN, @QUEST_STATUS_COMPLETED_REWARDED);

-- 92718
DELETE FROM `creature` WHERE `guid`=280000401;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(280000401,92718,1468,7814,7873,0,0,171,0,-1,0,0,4325.95,-605.75,-281.759,4.69607,720,0,0,0,0,0,0,0,0,0,0,'',25549);

DELETE FROM `creature_text` WHERE `CreatureID` = 99473;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(99473, 0, 0, 'Lower the barrier and evacuate the hold. These Illidari wish to... exchange words... with the eredar.', 12, 0, 100, 0, 0, 64634, 0, 0, 'Warden Alturas to Player'),
(99473, 1, 0, 'Follow me. I shall open the cell for you.', 12, 0, 100, 0, 0, 64635, 0, 0, 'Warden Alturas to Player'),
(99473, 2, 0, 'Meet Taldath, one of the most powerful eredar we\'ve ever encountered. I\'m sure you two will be fast friends.', 12, 0, 100, 0, 0, 57564, 0, 0, 'Warden Alturas to Player'),
(99473, 3, 0, 'Remember, demon hunter... you were never here.', 12, 0, 100, 0, 0, 64638, 0, 0, 'Warden Alturas to Player');