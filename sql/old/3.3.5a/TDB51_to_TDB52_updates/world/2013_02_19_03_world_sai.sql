-- Fix quest: Gather the Orbs http://www.wowhead.com/quest=10859
-- ID indexes
-- Almost all is based on Untaught script, just corrected some stuff with sniff
SET @OrbCollectingTotem := 22333;
SET @LightOrb           := 20635;
SET @Script :=   @LightOrb * 100;
SET @BanishedState :=      32566;
SET @ArcaneExplosion :=    35426; -- such spells need delay to execute properly, that is why I made actionlist
-- Update templates
UPDATE `creature_template` SET `unit_flags`=unit_flags|0x02000000 WHERE `entry`=@LightOrb; -- sniff
-- Add SAI support for Light Orbs and Totem
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@LightOrb;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@LightOrb,@OrbCollectingTotem);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@LightOrb,@OrbCollectingTotem) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Script AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OrbCollectingTotem,0,0,1,54,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@LightOrb,20,0,0,0,0,0, 'Orb collecting totem - On spawned - Set Data 0 1'),
(@OrbCollectingTotem,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Orb collecting totem - Linked with previous event - Store invoker'),
(@OrbCollectingTotem,0,2,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@LightOrb,20,0,0,0,0,0, 'Orb collecting totem - Linked with previous event - Send stored target list 1'),
(@LightOrb,0,0,0,25,0,100,1,0,0,0,0,11,@BanishedState,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spawn/reset - Cast Purple Banish State'),
(@LightOrb,0,1,0,38,0,100,0,0,1,30000,30000,69,1,0,0,0,0,0,19,@OrbCollectingTotem,20,0,0,0,0,0, 'Light Orb - On Data Set 0 1 - Move to totem'),
(@LightOrb,0,2,3,34,0,100,1,8,1,0,0,11,@ArcaneExplosion,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - On point 1 reached - Cast arcane explosion'),
(@LightOrb,0,3,4,61,0,100,0,0,0,0,0,33,21929,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Light Orb - Linkedw with previous event - Call kill credit'),
(@LightOrb,0,4,0,61,0,100,0,0,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Linkedw with previous event - Start action list to display arcase explosion'),
(@Script,9,0,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Action 0 - Set unseen'),
(@Script,9,1,0,0,0,100,0,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Light Orb - Action 1 - Despawn in 100 ms');
-- Remove deprecated required spell cast that was blocking the credit, on top of that it had some nosense spell that has nothing to do with quest?!
UPDATE `quest_template` SET `requiredspellcast1`=0 WHERE `id`=10859;
