-- Into The Wild Green Yonder (13045)
SET @NPC_CAPTURED           := 30407; -- Captured Crusader
SET @NPC_SKYTALON           := 30500; -- Argent Skytalon (not the mount)
SET @NPC_SKYTALON_MOUNT     := 30228; -- Argent Skytalon (mount)

UPDATE `creature_template` SET `faction_A`=2070,`faction_H`=2070 WHERE `entry`=@NPC_SKYTALON;
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=@NPC_SKYTALON_MOUNT;

-- Re-vamped SAI script
UPDATE `creature_template` SET `npcflag`=0,`AIName`='SmartAI' WHERE `entry`=@NPC_CAPTURED;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_CAPTURED;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_CAPTURED,0,0,1,25,0,100,0,0,0,0,0,75,56726,0,0,0,0,0,1,0,0,0,0,0,0,0,'Apply aura on reset, linking to id 1'),
(@NPC_CAPTURED,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'set phasemask to 1'),
(@NPC_CAPTURED,0,2,0,1,1,100,0,4000,4000,4000,4000,10,70,22,0,0,0,0,1,0,0,0,0,0,0,0,'play emote OOC in phase 1'),
(@NPC_CAPTURED,0,3,4,8,1,100,0,56683,0,0,0,11,56687,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mount proto drake on spell hit, linking to id 4'),
(@NPC_CAPTURED,0,4,5,61,1,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say text , linking to id 5'),
(@NPC_CAPTURED,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'set phasemask to 2'),
(@NPC_CAPTURED,0,6,0,1,2,100,0,8000,8000,8000,8000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say text OOC in phase 2, starting with 8sec delay, then repeat every 8 secs'),
(@NPC_CAPTURED,0,7,8,23,2,100,0,56687,0,1000,1000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'say text if does not have ride aura(check every 1 sec), linking to id 8'),
(@NPC_CAPTURED,0,8,9,61,2,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'set despawn timer for 5 secs, linking to id 9'),
(@NPC_CAPTURED,0,9,0,61,2,100,0,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'set phase to 4');
-- Re-vamped spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@NPC_SKYTALON;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
-- Proper value
(@NPC_SKYTALON,56922,2,0);
-- rRe-vamped condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=18 AND `SourceEntry`=56922) OR (`SourceTypeOrReferenceId`=17 AND `SourceEntry`=56684) OR (`SourceTypeOrReferenceId`=13 AND `SourceEntry`=56683);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,@NPC_SKYTALON,56922,0,0,8,0,13045,0,0,1,0,'','Forbidden rewarded quest for spellclick'),
(18,@NPC_SKYTALON,56922,0,0,9,0,13045,0,0,0,0,'','Required quest active for spellclick'),
(13,1,56683,0,0,31,0,3,@NPC_CAPTURED,0,0,0,'','Grab Captured Crusader targets Captured Crusader'),
(17,0,56684,0,0,30,0,192523,15,0,0,0,'','Spell focus for Drop Off Captured Crusader'),
(17,0,56684,0,0,29,0,@NPC_CAPTURED,10,0,0,0,'','Drop Off Captured Crusader requires a Captured Crusader');
