-- The Admiral Revealed (12852) - http://www.wowhead.com/quest=12852
-- http://www.youtube.com/watch?v=I9doc1BVmA8
SET @WHIRLWIND       := 49807; -- Admiral's Whirlwind, AoE, used in phase 1
SET @STRIKE          := 57846; -- Admiral's Heroic Strike, cast on tank, used in phase 1
SET @CLEAVE          := 15284; -- Admiral's Cleave, cast in cone, used in phase 1
SET @TOUCH           := 60501; -- Selfcast on Mal'Ganis, heals him, used in phase 2
SET @SLEEP           := 53045; -- Mal'Ganis Sleep,Cast on random group member, used in phase 2
SET @BLAST           := 60500; -- Mal'Ganis Mind Blast, Cast on random group member, used in phase 2
SET @CARRION         := 60502; -- Mal'Ganis Carrion Swarm, Cast in cone, used in phase 2
SET @SHIELD          := 50161; -- Cast when Admiral on 50 %
SET @ITEMSPELL       := 31699; -- Spell to disable shield
SET @ADMIRAL         := 29621; -- Grand Admiral Westwind
SET @MALGANIS        := 29620; -- Dreadlord Mal'Ganis
SET @PORTAL          := 27731; -- Portal visual
SET @LEGION_TELEPORT := 35502; -- Mal'Ganis Legion Portal visual
SET @CREDIT_BUNNY    := 29627; -- Cute little flaming bunny
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@CREDIT_BUNNY);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CREDIT_BUNNY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`, `target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CREDIT_BUNNY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 75, @PORTAL, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Credit Bunny - Just Summoned - Cast Portal');
-- SAI for Grand Admiral Westwind
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@ADMIRAL,@MALGANIS,@ADMIRAL*100);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (@ADMIRAL,@ADMIRAL*100) AND `source_type` IN (0,9);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MALGANIS AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`, `target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ADMIRAL, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On aggro - Set invicibility at 1 HP'),
(@ADMIRAL, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Say line 0'),
(@ADMIRAL, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Set phase 1'),
(@ADMIRAL, 0, 3, 4, 2, 0, 100, 1, 0, 50, 0, 0, 11, @SHIELD, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - At 50% HP - Cast Protection Sphere'),
(@ADMIRAL, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - Link - Say line 1'),
(@ADMIRAL, 0, 5, 6, 8, 0, 100, 0, @ITEMSPELL, 0, 0, 0, 28, @SHIELD, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On spell hit - Remove aura'),
(@ADMIRAL, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - Link - Say line 2'),
(@ADMIRAL, 0, 7, 8, 2, 0, 100, 1, 0, 30, 0, 0, 3, @MALGANIS, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - At 30% HP - Morph to Dreadlord Mal''Ganis'),
(@ADMIRAL, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Set phase 2'),
(@ADMIRAL, 0, 9,10, 61, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - Link - Say line 3'),
(@ADMIRAL, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 40, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'Grand Admiral Westwind - Link - Sheath'),
(@ADMIRAL, 0, 11, 0, 2, 0, 100, 1, 0, 15, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - At 15% HP - Say line 4'),
(@ADMIRAL, 0, 12, 0, 1, 0, 100, 0, 0, 0, 0, 0, 3, @ADMIRAL, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On evade - Restore model'),
(@ADMIRAL, 0, 13, 14, 2, 0, 100, 1, 1, 1, 0, 0, 18, 33554434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On 1 hp - Set unit_flags'),
(@ADMIRAL, 0, 14, 15, 61, 0, 100, 1, 0, 0, 0, 0, 12, @CREDIT_BUNNY, 1, 19000, 0, 0, 0, 8, 0, 0, 0, 7494.893066, 4871.533203, -12.655286, 1.376, 'Grand Admiral Westwind - On Link - Summon Npc'),
(@ADMIRAL, 0, 15, 16, 61, 0, 100, 1, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Stop Combat/Attack Attack State'),
(@ADMIRAL, 0, 16, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @ADMIRAL*100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Link - Start timed script'),
(@ADMIRAL*100, 9, 0, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On script - Set phase 3'),
(@ADMIRAL*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 7494.788, 4872.567, -12.72154, 0, 'Grand Admiral Westwind - On Script - Move to Pos'),
(@ADMIRAL*100, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Script - Say line 6'),
(@ADMIRAL*100, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 11, @LEGION_TELEPORT, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Script - Cast spell on self'),
(@ADMIRAL*100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 33, @CREDIT_BUNNY, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Script - Give quest credit'),
(@ADMIRAL*100, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 3500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Script - Despawn'),
(@ADMIRAL, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 19, 33554434, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Respawn - Unset unit_flags'),
(@ADMIRAL, 0, 18, 0, 0, 1, 100, 0, 15000, 16000, 16000, 16000, 11, @WHIRLWIND, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 1 - Cast Whirlwind'),
(@ADMIRAL, 0, 19, 0, 0, 1, 100, 0, 6000, 7000, 6000, 7000, 11, @STRIKE, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 1 - Cast Heroic Strike'),
(@ADMIRAL, 0, 20, 0, 0, 2, 100, 0, 15000, 16000, 15000, 16000, 11, @SLEEP, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 2 - Cast Sleep'),
(@ADMIRAL, 0, 21, 0, 0, 2, 100, 0, 6000, 7000, 6000, 7000, 11, @TOUCH, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 2- Cast Vampiric Touch'),
(@ADMIRAL, 0, 22, 0, 0, 1, 100, 0, 13000, 13500, 13000, 13500, 11, @CLEAVE, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 1 - Cast Cleave'),
(@ADMIRAL, 0, 23, 0, 0, 2, 100, 0, 8000, 9000, 8000, 9000, 11, @CARRION, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 2 - Cast Carrion Swarm'),
(@ADMIRAL, 0, 24, 0, 0, 2, 100, 0, 18000, 19000, 18000, 19000, 11, @BLAST, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - In combat Phase 2 - Cast Mind Blast'),
(@ADMIRAL, 0, 25, 0, 25, 0, 100, 0, 0, 0, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Grand Admiral Westwind - On Reset - Allow Attack State');
/*
Sound ID's
14429 Final speech - When he uses portal
14428 2% HP - When he becomes immune
14427 15 % - When he rages
14426 30% HP - When he morphs
14207 Sphere removed - When Item spell is used on him
14205 Sphere cast - When he casts sphere on self
14201 Beginning of combat - When he aggros
*/
-- Sniffed text with sounds
DELETE FROM `creature_text` WHERE `entry` IN (@ADMIRAL,@MALGANIS);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ADMIRAL,0,0, 'How did you find me? Did Landgren tell?',12,0,100,0,0,14201, 'Grand Admiral Westwind'),
(@ADMIRAL,1,0, 'You thought I would just let you kill me?',12,0,100,0,0,14205, 'Grand Admiral Westwind'),
(@ADMIRAL,2,0, 'WHAT?! No matter. Even without my sphere, I will crush you! Behold my true identity and despair!',14,0,100,0,0,14207, 'Grand Admiral Westwind'),
(@ADMIRAL,3,0, 'Gah! I spent too much time in that weak little shell.',14,0,100,0,0,14426, 'Grand Admiral Westwind'),
(@ADMIRAL,4,0, 'Kirel narak! I am Mal''Ganis. I AM ETERNAL!',14,0,100,0,0,14427, 'Grand Admiral Westwind'),
(@ADMIRAL,5,0, 'ENOUGH! I waste my time here. I must gather my strength on the homeworld.',14,0,100,0,0,14428, 'Grand Admiral Westwind'),
(@ADMIRAL,6,0, 'You''ll never defeat the Lich King without my forces. I''ll have my revenge... on him AND you!',14,0,100,0,0,14429, 'Grand Admiral Westwind');
