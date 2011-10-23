-- Ethereum Relay SAI
SET @ENTRY := 20619;
SET @SPELL_SHADOWFORM := 16592;
SET @SPELL_ETHEREUM_RELAY := 39596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,@SPELL_SHADOWFORM,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereum Relay - Out of Combat - Cast Shadowform"),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,11,@SPELL_ETHEREUM_RELAY,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereum Relay - Out of Combat - Cast Ethereum Relay");

-- Re-add what shouldn't be deleted
SET @Gossip = 21289;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@Gossip AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`) VALUES
(@Gossip, 0, 0, 'I believe in you.', 1, 1);
