-- Quest: Bring 'Em Back Alive (11690)
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=45877,`unit_flags`=`unit_flags`|512,`speed_run`=2  WHERE `entry`=25596; -- Infected Kodo Beast
UPDATE `creature_template_addon` SET `bytes1`=7,`bytes2`=1,`mount`=0,`emote`=0,`auras`=45771 WHERE `entry`=25596; -- Aura: Scourge Infection
DELETE FROM `smart_scripts` WHERE `entryorguid`=25596 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25596,0,0,0,27,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Infected Kodo Beast - remove death state on passager boarded'),
(25596,0,1,0,31,0,100,0,45877,0,0,0,41,0,0,0,0,0,0,22,0,0,0,0,0,0,0, 'Infected Kodo Beast - On Spell Hit despawn');

DELETE FROM `npc_spellclick_spells` where `npc_entry`=25596;
INSERT INTO `npc_spellclick_spells`(`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) values 
(25596,45875,11690,1,11690,0,0,0,0);
