-- The Sum is Greater than the Parts (13043)
-- http://www.youtube.com/watch?v=dg84C1d-sxw

SET @QUEST                := 13043; -- The quest...Duh!
SET @NPC_NERGELD          := 30403; -- Nergeld
SET @NPC_DR_TERRIBLE      := 30404; -- Dr. Terrible
SET @NPC_HOUND            := 30432; -- Grimmr Hound
SET @NPC_ASSAILANT        := 30471; -- Vargul Assailant
SET @AURA_ROOT            := 59037; -- The Sum is Greater than the Parts: Nergeld's Freeze Anim
SET @SPELL_DEATH_SIGNAL   := 32067; -- The Sum is Greater than the Parts: Dr. Terrible's Death Signal
SET @SPELL_MOUNT          := 56699; -- Controlling Nergeld

-- Remove random movement from Nergeld
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid`=124127;
DELETE FROM `creature_addon` WHERE `guid`=124127;

UPDATE `creature_model_info` SET `combat_reach`=4.05 WHERE `modelid`=27102;

UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=56746,`spell2`=56748,`spell3`=56747,`spell4`=60540,`speed_run`=0.992062866687775,`VehicleId`=236,`unit_flags`=256|32768/*256|512|32768*/,`npcflag`=0x1000000 WHERE `entry`=@NPC_NERGELD;
UPDATE `creature_template` SET `faction_A`=974,`faction_H`=974,`unit_flags`=32768,`AIName`='SmartAI' WHERE `entry`=@NPC_HOUND;
UPDATE `creature_template` SET `faction_A`=2116,`faction_H`=2116,`unit_flags`=32768,`AIName`='SmartAI' WHERE `entry`=@NPC_ASSAILANT;
UPDATE `creature_template` SET `faction_A`=974,`faction_H`=974,`unit_flags`=32832,`AIName`='SmartAI' WHERE `entry`=@NPC_DR_TERRIBLE;

DELETE FROM `creature_template_addon` WHERE `entry`=@NPC_NERGELD;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@NPC_NERGELD,0,0x0,0x1,''); -- 59037 The Sum is Greater than the Parts: Nergeld's Freeze Anim

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=16 AND `SourceEntry`=@NPC_NERGELD) OR (`SourceTypeOrReferenceId`=13 AND `SourceEntry`=56747) OR (`SourceTypeOrReferenceId`=13 AND `SourceEntry`=56746) OR (`SourceTypeOrReferenceId`=18 AND `SourceEntry`=@SPELL_MOUNT) OR(`SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_DEATH_SIGNAL);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16,0,@NPC_NERGELD,0,0,23,0,4595,0,0,0,0,0,'','Dismount player when not in intended zone'),
(13,1,56747,0,0,31,0,3,@NPC_ASSAILANT,0,0,0,0,'','Stomp can target Vargul Assailant'),
(13,1,56747,0,1,31,0,3,@NPC_HOUND,0,0,0,0,'','Stomp can target Grimmr Hound'),
(13,1,56747,0,2,31,0,3,@NPC_DR_TERRIBLE,0,0,0,0,'','Stomp can target Dr. Terrible'),
(13,1,56746,0,0,31,0,3,@NPC_ASSAILANT,0,0,0,0,'','Punch can target Vargul Assailant'),
(13,1,56746,0,1,31,0,3,@NPC_HOUND,0,0,0,0,'','Punch can target Grimmr Hound'),
(13,1,56746,0,2,31,0,3,@NPC_DR_TERRIBLE,0,0,0,0,'','Punch can target Dr. Terrible'),
(18,@NPC_NERGELD,@SPELL_MOUNT,0,0,28,0,@QUEST,0,0,1,0,0,'','Spellclick when quest not complete'),
(18,@NPC_NERGELD,@SPELL_MOUNT,0,0,9,0,@QUEST,0,0,0,0,0,'','Spellclick when quest taken'),
(13,2,@SPELL_DEATH_SIGNAL,0,1,31,0,3,@NPC_DR_TERRIBLE,0,0,0,0,'','Dr. Terrible''s Death Signal effect1 targets Dr. Terrible'),
(13,1,@SPELL_DEATH_SIGNAL,0,1,31,0,3,@NPC_NERGELD,0,0,0,0,'','Dr. Terrible''s Death Signal effect0 targets Nergeld');



DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_NERGELD,@NPC_DR_TERRIBLE,@NPC_HOUND,@NPC_ASSAILANT) OR (`source_type`=9 AND `entryorguid`=@NPC_NERGELD*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Nergeld
(@NPC_NERGELD,0,0,0,11,0,100,0,0,0,0,0,75,@AURA_ROOT,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Respawn add root aura'),
(@NPC_NERGELD,0,1,0,28,0,100,0,0,0,0,0,75,@AURA_ROOT,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Passenger Removed add root aura'),
(@NPC_NERGELD,0,2,3,27,0,100,0,0,0,0,0,28,@AURA_ROOT,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Passenger Boarded remove root aura'),
(@NPC_NERGELD,0,3,4,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Passenger Boarded Talk'),
(@NPC_NERGELD,0,4,5,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Passenger Boarded Set State Passive'),
(@NPC_NERGELD,0,5,0,61,0,100,0,0,0,0,0,80,@NPC_NERGELD*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'On Passenger Boarded Run SCript'),
(@NPC_NERGELD,0,6,7,8,0,100,0,@SPELL_DEATH_SIGNAL,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Spellhit Say'),
(@NPC_NERGELD,0,7,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Spellhit Die'),
-- Wave 1 05:22:46.000
(@NPC_NERGELD*100,9,0,0,0,0,100,0,5000,5000,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,7993.895,3336.905,632.3955,0.1457695,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,1,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8003.723,3323.562,632.3955,0.6487832,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,2,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8026.945,3307.581,632.3955,1.482069,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,3,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8001.774,3306.377,632.3955,0.8634474,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,4,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,7987.904,3308.895,632.3955,0.6805801,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,5,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8016.516,3318.92,632.3956,0.940311,'On Script - Spawn Vargul'),
-- Wave 2 05:23:06.000
(@NPC_NERGELD*100,9,6,0,0,0,100,0,30000,30000,0,0,12,@NPC_HOUND,2,300000,0,0,0,8,0,0,0,7996.656,3308.777,632.3955,0.7732307,'On Script - Spawn Grimmr Hound'),
(@NPC_NERGELD*100,9,7,0,0,0,100,0,0,0,0,0,12,@NPC_HOUND,2,300000,0,0,0,8,0,0,0,8011.714,3315.362,632.3955,0.9011694,'On Script - Spawn Grimmr Hound'),
(@NPC_NERGELD*100,9,8,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8000.665,3317.225,632.3955,0.7105912,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,9,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8025.243,3313.552,632.3955,1.286934,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,10,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8007.712,3337.127,632.3955,0.4072851,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,11,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8009.925,3319.814,632.3955,0.8048422,'On Script - Spawn Vargul'),
-- Wave 3 05:23:26.000
(@NPC_NERGELD*100,9,12,0,0,0,100,0,30000,30000,0,0,12,@NPC_HOUND,2,300000,0,0,0,8,0,0,0,8021.793,3312.446,632.3955,1.130859,'On Script - Spawn Grimmr Hound'),
(@NPC_NERGELD*100,9,13,0,0,0,100,0,0,0,0,0,12,@NPC_HOUND,2,300000,0,0,0,8,0,0,0,8001.362,3332.711,632.3955,0.4433513,'On Script - Spawn Grimmr Hound'),
(@NPC_NERGELD*100,9,14,0,0,0,100,0,0,0,0,0,12,@NPC_HOUND,2,300000,0,0,0,8,0,0,0,7999.219,3302.518,632.3955,0.8723419,'On Script - Spawn Grimmr Hound'),
(@NPC_NERGELD*100,9,15,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8000.495,3345.769,632.3955,5.823889,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,16,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8001.774,3311.945,632.3955,0.797157,'On Script - Spawn Vargul'),
(@NPC_NERGELD*100,9,17,0,0,0,100,0,0,0,0,0,12,@NPC_ASSAILANT,2,300000,0,0,0,8,0,0,0,8012.214,3325.824,632.3955,0.7376673,'On Script - Spawn Vargul'),
-- Wave 4 05:23:47.000
(@NPC_NERGELD*100,9,18,0,0,0,100,0,31000,31000,0,0,12,@NPC_DR_TERRIBLE,2,300000,0,1,0,8,0,0,0,7985.901,3296.679,632.4788,0.8377581,'On Script - Spawn Dr. Terrible'),
(@NPC_NERGELD*100,9,19,0,0,0,100,0,0,0,0,0,12,@NPC_HOUND,2,300000,0,0,0,8,0,0,0,7982.587,3301.807,632.4788,0.6981317,'On Script - Spawn Grimmr Hound'),
(@NPC_NERGELD*100,9,20,0,0,0,100,0,0,0,0,0,12,@NPC_HOUND,2,300000,0,0,0,8,0,0,0,7991.366,3293.512,632.4788,0.9075712,'On Script - Spawn Grimmr Hound'),
-- Dr. Terrible
(@NPC_DR_TERRIBLE,0,0,0,25,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,@NPC_NERGELD,0,0,0,0,0,0,'On spawn attack npc'),
(@NPC_DR_TERRIBLE,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say on Aggro'),
(@NPC_DR_TERRIBLE,0,2,0,0,0,100,0,8000,8000,15000,19000,11,61143,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crazed Chop'),
(@NPC_DR_TERRIBLE,0,3,0,0,0,100,0,10000,12000,28000,33000,11,61146,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Slime Stream'),
(@NPC_DR_TERRIBLE,0,4,5,2,0,100,1,0,45,0,0,11,31730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heal at 45% HP'),
(@NPC_DR_TERRIBLE,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text'),
(@NPC_DR_TERRIBLE,0,6,7,6,0,100,1,0,0,0,0,11,@SPELL_DEATH_SIGNAL,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast on Death'),
(@NPC_DR_TERRIBLE,0,7,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say on Death'),
-- Grimmr Hound
(@NPC_HOUND,0,0,0,25,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,@NPC_NERGELD,0,0,0,0,0,0,'On spawn attack npc'),
(@NPC_HOUND,0,1,0,8,0,100,0,@SPELL_DEATH_SIGNAL,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Spellhit Despawn'),
-- Vargul Assailant
(@NPC_ASSAILANT,0,0,0,25,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,@NPC_NERGELD,0,0,0,0,0,0,'On spawn attack npc'),
(@NPC_ASSAILANT,0,1,0,8,0,100,0,@SPELL_DEATH_SIGNAL,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Spellhit Despawn'),
(@NPC_ASSAILANT,0,2,0,0,0,100,0,4500,5599,13400,15600,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chop'),
(@NPC_ASSAILANT,0,3,0,0,0,100,0,8000,9000,35000,37000,11,23262,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralize');


-- NPC talk text insert
DELETE FROM `creature_text` WHERE `entry` IN (@NPC_DR_TERRIBLE,@NPC_NERGELD);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_DR_TERRIBLE,0,0,'WHO DARES?! I AM GOING TO FLAY THE FLESH FROM YOUR BONES EVEN IF I HAVE TO DESTROY NERGELD TO GET TO YOU!',14,0,100,0,0,0,'Dr. Terrible'),
(@NPC_DR_TERRIBLE,1,0,'Now the nightmare''s real.Now Dr. Terrible is here.To make you quake with fear.To make the whole world kneel.And I won''t feel ...a thing',12,0,100,0,0,0,'Dr. Terrible'),
(@NPC_DR_TERRIBLE,2,0,'I''LL RISE AGAIN AND WHEN I DO I WILL HAVE MY REVENGE!.',14,0,100,0,0,0,'Dr. Terrible to Nergeld'),
(@NPC_NERGELD,0,0,'As you jump into Nergeld, the rotting flesh of the construct comes to life.',16,0,100,0,0,0,'Nergeld'),
(@NPC_NERGELD,1,0,'%s falls to pieces.',16,0,100,0,0,0,'Nergeld to Dr. Terrible');
