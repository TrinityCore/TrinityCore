-- Chicken Escapee SAI
SET @ENTRY := 28161;
SET @SPELL_NET_CHICKEN := 51959;
SET @SPELL_INVIS_CHICKEN := 50734;
SET @SPELL_SCARED_CHICKEN := 51846;
SET @SPELL_CREATE_QUESTITEM := 51037;
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`spawntimesecs`=5 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI',`npcflag`=1 WHERE `entry`=@ENTRY;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,@SPELL_NET_CHICKEN,0,0,0,28,@SPELL_SCARED_CHICKEN,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chicken Escapee - On Spellhit - Remove Aura Scared Chicken"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chicken Escapee - On Spellhit - Forced Despawn"),
(@ENTRY,0,2,3,64,0,100,0,0,0,0,0,85,@SPELL_CREATE_QUESTITEM,2,0,0,0,0,7,0,0,0,0,0,0,0,"Chicken Escapee - On Gossip Hello - Invoker Cast Capture Chicken Escapee"), -- Triggered because of cast-time
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Chicken Escapee - On Gossip Hello - Close Gossip"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chicken Escapee - On Gossip Hello - Set Npcflag None"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,28,@SPELL_SCARED_CHICKEN,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chicken Escapee - On Gossip Hello - Remove Aura Scared Chicken"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chicken Escapee - On Gossip Hello - Forced Despawn"),
(@ENTRY,0,7,8,25,0,100,0,0,0,0,0,11,@SPELL_INVIS_CHICKEN,1,0,0,0,0,1,0,0,0,0,0,0,0,"Chicken Escapee - On Reset - Cast Frenzyheart Chicken: Invisibility"), -- Just in case
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,11,@SPELL_SCARED_CHICKEN,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chicken Escapee - On Reset - Cast Scared Chicken");
