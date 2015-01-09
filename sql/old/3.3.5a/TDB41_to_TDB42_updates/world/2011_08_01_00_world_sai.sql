-- Gurubashi Blood Drinker SAI
SET @ENTRY := 11353;
SET @SPELL_BLOOD_LEECH := 24437; -- Blood Leech
SET @SPELL_DRAIN_LIFE := 24435; -- Drain Life
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=24437,`spell2`=24435,`spell3`=0,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,0,0,11,@SPELL_BLOOD_LEECH,1,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Blood Drinker - At 50% HP - Cast Blood Leech');
-- (@ENTRY,0,1,0,0,0,100,0,3000,5000,9000,11000,11,@SPELL_DRAIN_LIFE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Blood Drinker - In Combat - Cast Drain Life'); -- Need spellscript, right now it heals the player for 5000 every second

-- Hakkari Priest SAI
SET @ENTRY := 11830;
SET @SPELL_PSYCHIC_SCREAM := 13704; -- Psychic Scream
SET @SPELL_ANTI_MAGIC_SHIELD := 24021; -- Anti-Magic Shield
SET @SPELL_CLEANSE_NOVA := 24022; -- Cleanse Nova
SET @SPELL_HEAL := 22883; -- Heal
UPDATE `creature_template` SET `AIName`='SmartAI',`mechanic_immune_mask`=`mechanic_immune_mask`|1 WHERE `entry`=@ENTRY; -- Immune to charm effects (mind control)
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Hakkari Priest - On Aggro - Say Line 0 (random)'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,27000,27000,11,@SPELL_PSYCHIC_SCREAM,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Priest - In Combat - Cast Psychic Scream'),
(@ENTRY,0,2,0,0,0,100,0,1000,1000,22000,24000,11,@SPELL_ANTI_MAGIC_SHIELD,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Priest - In Combat - Cast Anti-Magic Shield'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,30000,30000,11,@SPELL_CLEANSE_NOVA,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Priest - In Combat - Cast Cleanse Nova'),
(@ENTRY,0,4,0,2,0,100,1,0,50,0,0,11,@SPELL_HEAL,1,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Priest - At 50% HP - Cast Heal');
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Killing you be easy!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,1,'Troll mojo da strongest mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,2,'Your skull gonna decorate our ritual altars!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,3,'I gonna make you into mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,4,'Feel da big bad voodoo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,5,'My weapon be thirsty!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,6,'You be dead soon!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines');

-- Gurubashi Axe Thrower SAI
SET @ENTRY := 11350;
SET @SPELL_RANGED_THROW := 22887; -- Ranged Throw
SET @SPELL_FRENZY := 8269; -- Frenzy
SET @SPELL_AXE_FLURRY := 24018; -- Axe Flurry
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=22887,`spell2`=24018,`spell3`=8269,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Gurubashi Axe Thrower - On Aggro - Say Line 1 (random)'),
(@ENTRY,0,1,0,9,0,100,1,5,30,1500,2000,11,@SPELL_RANGED_THROW,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Axe Thrower - On Range - Cast Ranged Throw'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,@SPELL_FRENZY,1,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Axe Thrower - At 30% HP - Cast Frenzy'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Gurubashi Axe Thrower - At 30% HP - Say Line 0'),
(@ENTRY,0,4,0,0,0,100,0,15000,15000,25000,28000,11,@SPELL_AXE_FLURRY,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Axe Thrower - In Combat - Cast Axe Flurry');
-- Axe Flurry whirldwind effect will now stun nearby players by throwing axes at them
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=24071 AND `spell_effect`=24020;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(24071,24020,1,'Axe Flurry will now throw axes at nearby players, stunning them');
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s goes into a frenzy!',16,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,1,0,'Killing you be easy!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,1,1,'Troll mojo da strongest mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,1,2,'Your skull gonna decorate our ritual altars!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,1,3,'I gonna make you into mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,1,4,'Feel da big bad voodoo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,1,5,'My weapon be thirsty!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,1,6,'You be dead soon!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines');

-- Portal of Madness SAI
SET @ENTRY := 15141;
SET @SPELL_SUMMON_MAD_VOIDWALKERS := 24622; -- Summon Mad Voidwalkers
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,6000,6000,6000,6000,11,@SPELL_SUMMON_MAD_VOIDWALKERS,0,0,0,0,0,1,0,0,0,0,0,0,0,'Portal of Madness - OCC - Cast Summon Mad Voidwalkers'),
(@ENTRY,0,1,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Portal of Madness - On Spawn - Set react state Passive');

-- Mad Voidwalker SAI
SET @ENTRY := 15146;
SET @SPELL_CONSUMING_SHADOW := 24614; -- Consuming Shadows
SET @SPELL_SHADOW_SHOCK := 24616; -- Shadow Shock
UPDATE `creature_template` SET `AIName`='SmartAI',`mechanic_immune_mask`=131073,`flags_extra`=64 WHERE `entry`=@ENTRY; -- Immune to Enslave and Banish and no experience gain
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mad Voidwalker - On spawn - Set random movement'),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,11000,13000,11,@SPELL_CONSUMING_SHADOW,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mad Voidwalker - In Combat - Cast Consuming Shadows'),
(@ENTRY,0,2,0,0,0,100,2,3000,4000,8000,8000,11,@SPELL_SHADOW_SHOCK,0,0,0,0,0,2,0,0,0,0,0,0,0,'Mad Voidwalker - In Combat - Cast Shadow Shock'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mad Voidwalker - Link - Despawn after 3 minutes');

-- Mad Servant SAI
SET @ENTRY := 15111;
SET @SPELL_PORTAL_OF_MADNESS := 24621; -- Portal of Madness
SET @SPELL_FIREBALL := 24611; -- Fireball
SET @SPELL_FLAMESTRIKE := 24612; -- Flamestrike
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,4000,5000,11,@SPELL_FIREBALL,0,0,0,0,0,5,0,0,0,0,0,0,0,'Mad Servant - In Combat - Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,9000,11000,11,@SPELL_FLAMESTRIKE,1,0,0,0,0,5,0,0,0,0,0,0,0,'Mad Servant - In Combat - Cast Flamestrike'),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,11,@SPELL_PORTAL_OF_MADNESS,2,0,0,0,0,1,0,0,0,0,0,0,0,'Mad Servant - On Death - Cast Portal of Madness');

-- Razzashi Adder SAI
SET @ENTRY := 11372;
SET @SPELL_VENOM_SPIT := 24011; -- Venom Spit
SET @SPELL_EXPLOIT_WEAKNESS := 24016; -- Exploit Weakness
SET @SPELL_TRASH := 3391; -- Trash
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,3000,3000,15000,18000,11,@SPELL_VENOM_SPIT,1,0,0,0,0,5,0,0,0,0,0,0,0,'Razzashi Adder - In Combat - Cast Venom Spit'),
(@ENTRY,0,1,0,0,0,100,0,10000,11000,20000,20000,11,@SPELL_EXPLOIT_WEAKNESS,1,0,0,0,0,2,0,0,0,0,0,0,0,'Razzashi Adder - In Combat - Cast Exploit Weakness'),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,11000,14000,11,@SPELL_TRASH,1,0,0,0,0,1,0,0,0,0,0,0,0,'Razzashi Adder - In Combat - Cast Trash');

-- Gurubashi Headhunter SAI
SET @ENTRY := 11351;
SET @SPELL_THROW := 22887; -- Throw
SET @SPELL_WHIRLING_TRIP := 24048; -- Whirling Trip
SET @SPELL_MORTAL_STRIKE := 15708; -- Mortal Strike
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=22887,`spell2`=15708,`spell3`=0,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Headhunter - On Aggro - Say Line 0'),
(@ENTRY,0,1,0,9,0,100,0,5,30,1500,2000,11,@SPELL_THROW,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Headhunter - On Range - Cast Throw'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,7000,8000,11,@SPELL_WHIRLING_TRIP,1,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Headhunter - In Combat - Cast Whirlwing Trip'),
(@ENTRY,0,3,0,0,0,100,1,7000,8000,15000,15000,11,@SPELL_MORTAL_STRIKE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Headhunter - In Combat - Cast Mortal Strike');
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Killing you be easy!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,1,'Troll mojo da strongest mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,2,'Your skull gonna decorate our ritual altars!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,3,'I gonna make you into mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,4,'Feel da big bad voodoo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,5,'My weapon be thirsty!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,6,'You be dead soon!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines');

-- Hakkari Witch Doctor SAI
SET @ENTRY := 11831;
SET @SPELL_HEX := 24053; -- Hex
SET @SPELL_RELEASE_TOADS := 24058; -- Release Toads - needs work
SET @SPELL_SHADOW_SHOCK := 17289; -- Shadow Shock
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=24053,`spell2`=17289,`spell3`=24054,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Witch Doctor - On Aggro - Say Line 0'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,15000,17000,11,@SPELL_HEX,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Witch Doctor - In Combat - Cast Hex'),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,12000,13000,11,@SPELL_SHADOW_SHOCK,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Witch Doctor - In Combat - Cast Shadow Shock');
-- (@ENTRY,0,2,0,0,0,100,0,15000,16000,20000,22000,11,@SPELL_RELEASE_TOADS,1,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Witch Doctor - Cast Release Toads'); -- Spell needs work
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Killing you be easy!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,1,'Troll mojo da strongest mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,2,'Your skull gonna decorate our ritual altars!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,3,'I gonna make you into mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,4,'Feel da big bad voodoo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,5,'My weapon be thirsty!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,6,'You be dead soon!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines');

-- Bloodseeker Bat SAI
SET @ENTRY := 11368;
SET @SPELL_CHARGE := 24023; -- Charge
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=512 WHERE `entry`=@ENTRY; -- Will now be attackable
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL_CHARGE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Bloodseeker Bat - On Aggro - Cast Charge');
-- Charge will now also trigger Fixate (cast on bat)
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=24023 AND `spell_effect`=12021;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(24023,12021,1,'Charge (24023) will now trigger Fixate'); -- Bloodseeker Bat's charge

-- Razzashi Venombrood SAI
SET @ENTRY := 14532;
SET @SPELL_INTOXICATING_VENOM := 24596; -- Intoxicating Venom
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,5000,7000,11000,13000,11,@SPELL_INTOXICATING_VENOM,1,0,0,0,0,2,0,0,0,0,0,0,0,'Razzashi Venombrood - In Combat - Cast Intoxicating Venom');

-- Razzashi Broodwidow SAI
SET @ENTRY := 11370;
SET @SPELL_WEB_SPIN := 24600; -- Web Spin
SET @SPELL_SUMMON_RAZZASHI_SKITTERER := 24598; -- Summon Razzashi Skitterer (x5)
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,10000,14000,15000,11,@SPELL_WEB_SPIN,1,0,0,0,0,2,0,0,0,0,0,0,0,'Razzashi Broodwidow - In Combat - Cast Web Spin'),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,11,@SPELL_SUMMON_RAZZASHI_SKITTERER,2,0,0,0,0,1,0,0,0,0,0,0,0,'Razzashi Broodwidow - On Death - Cast Summon Razzashi Skitterer');

-- Hakkari Shadowcaster SAI
SET @ENTRY := 11338;
SET @SPELL_MANA_BURN := 22947; -- Mana Burn
SET @SPELL_SHADOW_BOLT := 15232; -- Shadow Bolt
SET @SPELL_SHADOW_BOLT_VOLLEY := 20741; -- Shadow Bolt Volley
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=15232,`spell2`=20741,`spell3`=0,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,11000,13000,11,@SPELL_MANA_BURN,1,0,0,0,0,5,0,0,0,0,0,0,0,'Hakkari Shadowcaster - In Combat - Cast Mana Burn'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,12000,14000,11,@SPELL_SHADOW_BOLT,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Shadowcaster - In Combat - Cast Shadow Bolt'),
(@ENTRY,0,2,0,0,0,100,0,7000,9000,12000,14000,11,@SPELL_SHADOW_BOLT_VOLLEY,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Shadowcaster - In Combat - Cast Shadow Bolt Volley');

-- Razzashi Raptor SAI
SET @ENTRY := 14821;
SET @SPELL_ENRAGE := 8599; -- Enrage
SET @SPELL_INFECTED_BITE := 24339; -- Infected Bite
SET @SPELL_TRASH := 3391; -- Trash
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6500,6500,8000,8000,11,@SPELL_INFECTED_BITE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Razzashi Raptor - In Combat - Cast Infected Bite'),
(@ENTRY,0,1,0,0,0,100,0,7000,8000,9000,10000,11,@SPELL_TRASH,1,0,0,0,0,1,0,0,0,0,0,0,0,'Razzashi Raptor - In Combat - Cast Trash'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,@SPELL_ENRAGE,1,0,0,0,0,1,0,0,0,0,0,0,0,'Razzashi Raptor - At 30% HP - Cast Enrage'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Razzashi Raptor - At 30% HP - Say Line 0');
-- Enrage text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s becomes enraged!',16,0,100,0,0,0,'Razzashi Raptor - At 30% HP - Say Line 0');

-- Gurubashi Champion SAI
SET @ENTRY := 11356;
SET @SPELL_BATTLE_SHOUT := 24438; -- Battle Shout
SET @SPELL_CHARGE := 22886; -- Berserker Charge
SET @SPELL_STRIKE := 22591; -- Strike
SET @SPELL_SHIELD_SLAM := 15655; -- Shield Slam
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=22886,`spell2`=22591,`spell3`=15655,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Champion - On aggro - Say Line 0'),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL_BATTLE_SHOUT,1,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Champion - On Aggro - Cast Battle Shout'),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,9000,10000,11,@SPELL_STRIKE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Champion - In Combat - Cast Strike'),
(@ENTRY,0,3,0,0,0,100,0,11000,13000,20000,22000,11,@SPELL_CHARGE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Champion - In Combat - Cast Berserker Charge'),
(@ENTRY,0,4,0,0,0,100,0,6000,6000,9000,9000,11,@SPELL_SHIELD_SLAM,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Champion - In Combat - Cast Shield Shalm');
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Killing you be easy!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,1,'Troll mojo da strongest mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,2,'Your skull gonna decorate our ritual altars!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,3,'I gonna make you into mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,4,'Feel da big bad voodoo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,5,'My weapon be thirsty!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,6,'You be dead soon!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines');

-- Zulian Panther SAI
SET @ENTRY := 11365;
SET @SPELL_RAKE := 24332; -- Rake
SET @SPELL_RAVAGE := 24333; -- Ravage
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,11000,13000,11,@SPELL_RAKE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Zulian Panther - In Combat - Cast Rake'),
(@ENTRY,0,1,0,0,0,100,0,11000,12000,22000,23000,11,@SPELL_RAVAGE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Zulian Panther - In Combat - Cast Ravage');

-- Gurubashi SAI
-- This one needs some work. It's summoned when opening a Voodoo Pile (spawned all over the instance) and should mind control the player for some seconds, but SAI refuses to cast the spell
SET @ENTRY := 15047;
SET @SPELL_WILL_OF_HAKKAR := 24178; -- Will of Hakkar
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=33554434 WHERE `entry`=@ENTRY; -- Set unattackable, untargetable
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Portal of Madness - On Spawn - Set react state Passive'), -- Temporarily workaround. It shouldn't attack players, but need core support for creatures mind controlling players
(@ENTRY,0,1,0,0,0,100,0,5,5,5,5,11,@SPELL_WILL_OF_HAKKAR,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi - In Combat - Cast Will Of Hakkar');

-- Hakkari Shadow Hunter SAI
SET @ENTRY := 11339;
SET @SPELL_SHOOT := 16496; -- Shoot
SET @SPELL_MULTI_SHOT := 21390; -- Multi-shot
SET @SPELL_WYVERN_STING := 24335; -- Wyvern Sting
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Shadow Hunter - On aggro - Emote Line 0'),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL_SHOOT,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Shadow Hunter - On Aggro - Cast Shoot'),
(@ENTRY,0,2,0,0,0,100,0,1000,1000,2000,3000,11,@SPELL_SHOOT,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Shadow Hunter - In Combat - Cast Shoot'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,14000,16000,11,@SPELL_MULTI_SHOT,1,0,0,0,0,5,0,0,0,0,0,0,0,'Hakkari Shadow Hunter - In Combat - Cast Multi-Shot'),
(@ENTRY,0,4,0,0,0,100,0,12000,13000,17000,19000,11,@SPELL_WYVERN_STING,1,0,0,0,0,5,0,0,0,0,0,0,0,'Hakkari Shadow Hunter - In Combat - Cast Wyvern Sting');
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Killing you be easy!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,1,'Troll mojo da strongest mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,2,'Your skull gonna decorate our ritual altars!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,3,'I gonna make you into mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,4,'Feel da big bad voodoo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,5,'My weapon be thirsty!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,6,'You be dead soon!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines');

-- 24247, 24246, 24222
-- Zulian Prowler SAI
SET @ENTRY := 15101;
SET @SPELL_TRASH := 3391; -- Trash
SET @SPELL_STEALTH := 24246; -- Stealth
SET @SPELL_VANISH_VISUAL := 24222; -- Vanish Visual
SET @SPELL_XXXXXX := 24247; -- Need more information and DBC
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,9000,10000,11,@SPELL_TRASH,1,0,0,0,0,1,0,0,0,0,0,0,0,'Zulian Prowler - In Combat - Cast Trash');
-- (@ENTRY,0,1,0,11,0,100,0,0,0,0,0,11,@SPELL_STEALTH,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zulian Prowler - On Spawn - Cast Stealth'), -- Needs to be implented in DBCs, together with 24247
-- (@ENTRY,0,2,0,11,0,100,0,0,0,0,0,11,@SPELL_VANISH_VISUAL,0,0,0,0,0,1,0,0,0,0,0,0,0,'Zulian Prowler - On Spawn - Cast Vanish Visual');

-- Atal'ai Mistress SAI
SET @ENTRY := 14882;
SET @SPELL_TRASH := 3391; -- Trash
SET @SPELL_CURSE_OF_BLOOD := 24673; -- Curse of Blood
SET @SPELL_SNAP_KICK := 24671; -- Snap Kick
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=3391,`spell2`=24673,`spell3`=0,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,9000,10000,11,@SPELL_TRASH,1,0,0,0,0,1,0,0,0,0,0,0,0,'Atalai Mistress - In Combat - Cast Trash'),
(@ENTRY,0,1,0,0,0,100,0,11000,14000,22000,22000,11,@SPELL_CURSE_OF_BLOOD,1,0,0,0,0,2,0,0,0,0,0,0,0,'Atalai Mistress - In Combat - Cast Curse of Blood'),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,22000,22000,11,@SPELL_SNAP_KICK,1,0,0,0,0,2,0,0,0,0,0,0,0,'Atalai Mistress - In Combat - Cast Snap Kick');

-- Zulian Crocolisk SAI
SET @ENTRY := 15043;
SET @SPELL_REND := 13445; -- Rend
SET @SPELL_TENDON_RIP := 3604; -- Tendon Rip
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,9000,11000,12000,11,@SPELL_TENDON_RIP,1,0,0,0,0,2,0,0,0,0,0,0,0,'Zulian Crocolisk - In Combat - Cast Tendon Rip'),
(@ENTRY,0,1,0,0,0,100,0,17000,19000,22000,24000,11,@SPELL_REND,1,0,0,0,0,2,0,0,0,0,0,0,0,'Zulian Crocolisk - In Combat - Cast Rend');

-- Hooktooth Frenzy SAI
SET @ENTRY := 11374;
SET @SPELL_PIERCE_ARMOR := 12097; -- Pierce Armor
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `entry`=@ENTRY AND `item`=19221; -- Remove incorrect item from loot table (Darkmoon Special Reserve)
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,11000,11000,11,@SPELL_PIERCE_ARMOR,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hooktooth Frenzy - In Combat - Cast Pierce Armor');

-- Son of Hakkar SAI
SET @ENTRY := 11357;
SET @SPELL_TRASH := 3391; -- Trash
SET @SPELL_KNOCKDOWN := 16790; -- Knockdown
SET @SPELL_POISONOUS_BLOOD := 24320; -- Poisonous Blood
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,9000,10000,11,@SPELL_TRASH,1,0,0,0,0,1,0,0,0,0,0,0,0,'Son of Hakkar - In Combat - Cast Trash'),
(@ENTRY,0,1,0,0,0,100,0,11000,13000,19000,22000,11,@SPELL_KNOCKDOWN,1,0,0,0,0,2,0,0,0,0,0,0,0,'Son of Hakkar - In Combat - Cast Knockdown'),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,11,@SPELL_POISONOUS_BLOOD,2,0,0,0,0,1,0,0,0,0,0,0,0,'Mad Servant - In Combat - Cast Poisonous Blood'); -- Spell needs work

-- Soulflayer SAI
SET @ENTRY := 11359;
SET @SPELL_FEAR := 22678; -- Fear
SET @SPELL_FRENZY := 8269; -- Frenzy
SET @SPELL_SOUL_TAP := 24619; -- Soul Tap
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,16000,19000,2100,23000,11,@SPELL_FEAR,1,0,0,0,0,5,0,0,0,0,0,0,0,'Soulflayer - In Combat - Cast Fear'),
(@ENTRY,0,1,0,0,0,100,0,10000,14000,20000,22000,11,@SPELL_SOUL_TAP,0,0,0,0,0,2,0,0,0,0,0,0,0,'Soulflayer - In Combat - Cast Soul Tap'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,@SPELL_FRENZY,1,0,0,0,0,1,0,0,0,0,0,0,0,'Soulflayer - At 30% HP - Cast Frenzy'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Soulflayer - At 30% HP - Say Line 0');
-- Frenzy text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s goes into a frenzy!',16,0,100,0,0,0,'Soulflayer - At 30% HP - Say Line 0');

-- Razzashi Cobra SAI
SET @ENTRY := 11373;
SET @SPELL_POISON := 24097; -- Poison
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,9000,11000,13000,11,@SPELL_POISON,1,0,0,0,0,2,0,0,0,0,0,0,0,'Razzashi Cobra - In Combat - Cast Poison');

-- Hakkari Blood Priest SAI
SET @ENTRY := 11340;
SET @SPELL_DRAIN_LIFE := 24618; -- Drain Life
SET @SPELL_BLOOD_FUNNEL := 24617; -- Blood Funnel
SET @SPELL_DISPEL_MAGIC := 17201; -- Dispel Magic
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=24618,`spell2`=0,`spell3`=0,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Blood Priest - On Aggro - Emote Line'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,15000,11,@SPELL_DISPEL_MAGIC,1,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Blood Priest - In Combat - Cast Dispel Magic'),
(@ENTRY,0,2,0,2,0,100,0,0,30,0,0,11,@SPELL_DRAIN_LIFE,1,0,0,0,0,1,0,0,0,0,0,0,0,'Hakkari Blood Priest - At 30% HP - Cast Drain Life');
-- (@ENTRY,0,3,0,0,0,85,0,5000,5000,15000,18000,11,@SPELL_BLOOD_FUNNEL,1,0,0,0,0,2,0,0,0,0,0,0,0,'Hakkari Blood Priest - In Combat - Cast Blood Funnel'), -- Need spellscript, heals player (target)
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'Killing you be easy!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,1,'Troll mojo da strongest mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,2,'Your skull gonna decorate our ritual altars!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,3,'I gonna make you into mojo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,4,'Feel da big bad voodoo!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,5,'My weapon be thirsty!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines'),
(@ENTRY,0,6,'You be dead soon!',12,0,100,0,0,0,'Part of the ZulGurub on aggro lines');

-- Voodoo Slave SAI
SET @ENTRY := 14883;
SET @SPELL_LIGHTNING_BLAST := 43996; -- Lightning Blast
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,0,3000,3000,6000,9000,11,@SPELL_LIGHTNING_BLAST,1,0,0,0,0,2,0,0,0,0,0,0,0,'Voodoo Slave - In Combat - Cast Lightning Blast');

-- Withered Mistress SAI
SET @ENTRY := 14825;
SET @SPELL_CURSE := 24673; -- Curse of Blood
SET @SPELL_DISPEL := 17201; -- Dispel Magic
SET @SPELL_VEIL_OF_SHADOW := 24674; -- Veil of Shadow
SET @SPELL_UNHOLY_FRENZY := 24672; -- Unholy Frenzy
UPDATE `creature_template` SET `AIName`='SmartAI',`spell1`=3391,`spell2`=24673,`spell3`=0,`spell4`=0 WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11000,14000,22000,22000,11,@SPELL_CURSE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Withered Mistress - In Combat - Cast Curse of Blood'),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,23000,26000,11,@SPELL_DISPEL,0,0,0,0,0,1,0,0,0,0,0,0,0,'Withered Mistress - In Combat - Cast Dispel Magic'),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,@SPELL_UNHOLY_FRENZY,1,0,0,0,0,1,0,0,0,0,0,0,0,'Withered Mistress - At 50% HP - Cast Unholy Frenzy'),
(@ENTRY,0,3,0,2,0,100,1,0,20,0,0,11,@SPELL_UNHOLY_FRENZY,1,0,0,0,0,1,0,0,0,0,0,0,0,'Withered Mistress - At 20% HP - Cast Unholy Frenzy');

-- Zulian Cub SAI
SET @ENTRY := 11360;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Zulian Cub - At 15% HP - Flee'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Zulian Cub - At 15% HP - Emote line 0');
-- Insert emote
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s attempts to run away in fear!',16,0,100,0,0,0,'Zulian Cub - At 15% HP - Emote line 0');

-- Gurubashi Berserker SAI
SET @ENTRY := 11352;
SET @SPELL_THUNDERCLAP := 15588; -- Thunderclap
SET @SPELL_KNOCK_AWAY := 11130; -- Knock Away
SET @SPELL_INTIMIDATING_ROAR := 16508; -- Intimidating Roar
SET @SPELL_FRENZY := 8269; -- Frenzy
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,15000,15000,11,@SPELL_INTIMIDATING_ROAR,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Berserker - In Combat - Cast Intimidating Roar'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,12000,12000,11,@SPELL_KNOCK_AWAY,1,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Berserker - In Combat - Cast Knock Away'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,13000,18000,11,@SPELL_THUNDERCLAP,1,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Berserker - In Combat - Cast Thunderclap'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,@SPELL_FRENZY,1,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Berserker - At 30% HP - Cast Frenzy'),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Gurubashi Berserker - At 30% HP - Emote Line 0');
-- Frenzy text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s goes into a frenzy!',16,0,100,0,0,0,'Gurubashi Berserker - At 30% HP - Emote Line 0');

-- Razzashi Serpent SAI
SET @ENTRY := 11371;
SET @SPELL_FATAL_BITE := 20539; -- Fatal Bite
SET @SPELL_PIERCE_ARMOR := 12097; -- Pierce Armor
SET @SPELL_TRANQUILIZING_POISON := 24002; -- Tranquilizing Poison
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,9000,12000,15000,11,@SPELL_FATAL_BITE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Razzashi Serpent - In Combat - Cast Fatal Bite'),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,14000,17000,11,@SPELL_TRANQUILIZING_POISON,1,0,0,0,0,5,0,0,0,0,0,0,0,'Razzashi Serpent - In Combat - Cast Tranquilizing Poison'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,11000,11000,11,@SPELL_PIERCE_ARMOR,1,0,0,0,0,2,0,0,0,0,0,0,0,'Razzashi Serpent - In Combat - Cast Pierce Armor');

-- Skullspitter Speaker SAI
SET @ENTRY := 11390;
SET @SPELL_HEAD_CRACK := 16172; -- Head Crack
SET @SPELL_WHIRLING_TRIP := 24048; -- Whirling Trip
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,16000,19000,1100,13000,11,@SPELL_HEAD_CRACK,1,0,0,0,0,2,0,0,0,0,0,0,0,'Skullspitter Speaker - In Combat - Cast Head Crack'),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,7000,8000,11,@SPELL_WHIRLING_TRIP,1,0,0,0,0,2,0,0,0,0,0,0,0,'Skullspitter Speaker - In Combat - Cast Whirlwing Trip');
-- Remove old addon data
DELETE FROM `creature_addon` WHERE `guid`=49257;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,8,1,0,NULL); -- Make Skullspitter Speaker kneel

-- Bloodscalp Speaker SAI
SET @ENTRY := 11389;
SET @SPELL_DISARM := 6713; -- Disarm
SET @SPELL_REND := 16509; -- Rend
SET @SPELL_ENRAGE := 8599; -- Enrage
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,11000,13000,11,@SPELL_REND,1,0,0,0,0,2,0,0,0,0,0,0,0,'Bloodscalp Speaker - In Combat - Cast Rend'),
(@ENTRY,0,1,0,0,0,100,0,9000,10000,13000,16000,11,@SPELL_DISARM,1,0,0,0,0,2,0,0,0,0,0,0,0,'Bloodscalp Speaker - In Combat - Cast Disarm');
-- Remove old addon data
DELETE FROM `creature_addon` WHERE `guid`=49288;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,8,1,0,NULL); -- Make Bloodscalp Speaker kneel

-- Vilebranch Speaker SAI
SET @ENTRY := 11391;
SET @SPELL_CLEAVE := 15284; -- Cleave
SET @SPELL_DEMORALIZING_SHOUT := 13730; -- Demoralizing Shout
SET @SPELL_ENRAGE := 8599; -- Enrage
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL_DEMORALIZING_SHOUT,1,0,0,0,0,2,0,0,0,0,0,0,0,'Vilebranch Speaker - On Aggro - Cast Demoralizing Shout'),
(@ENTRY,0,1,0,0,0,100,0,9000,10000,1300,16000,11,@SPELL_CLEAVE,1,0,0,0,0,2,0,0,0,0,0,0,0,'Vilebranch Speaker - In Combat - Cast Cleave');
-- Remove old addon data
DELETE FROM `creature_addon` WHERE `guid`=49656;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,0,1,20,NULL); -- Make Vilebranch Speaker beg

-- Witherbark Speaker SAI
SET @ENTRY := 11388;
SET @SPELL_EARTH_SHOCK := 22885; -- Earth Shock
SET @SPELL_FROST_SHOCK := 21401; -- Frost Shock
SET @SPELL_LIGHTNING_BOLT := 15801; -- Lightning Bolt
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL_FROST_SHOCK,0,0,0,0,0,2,0,0,0,0,0,0,0,'Witherbark Speaker - On Aggro - Cast Frost Shock'),
(@ENTRY,0,1,0,0,0,100,0,9000,10000,13000,16000,11,@SPELL_LIGHTNING_BOLT,0,0,0,0,0,2,0,0,0,0,0,0,0,'Witherbark Speaker - In Combat - Cast Lightning Bolt'),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,10000,11000,11,@SPELL_EARTH_SHOCK,0,0,0,0,0,2,0,0,0,0,0,0,0,'Witherbark Speaker - In Combat - Cast Earth Shock');
-- Remove old addon data
DELETE FROM `creature_addon` WHERE `guid`=49657;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,0,1,20,NULL); -- Make Witherbark Speaker beg

-- Gurubashi Bat Rider SAI
SET @ENTRY := 14750;
SET @SPELL_DEMORALIZING_SHOUT := 23511; -- Demoralizing Shout
SET @SPELL_BATTLE_COMMAND := 5115; -- Battle Command
SET @SPELL_INFECTED_BITE := 16128; -- Infected Bite
SET @SPELL_TRASH := 3391; -- Trash
SET @SPELL_UNSTABLE_CONCOCTION := 24024; -- Unstable Concoction
SET @SPELL_THROW_LIQUID_FIRE := 23968; -- Throw Liquid Fire
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,@SPELL_DEMORALIZING_SHOUT,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Bat Rider - On Aggro - Cast Demoralizing Shout'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,25000,25000,11,@SPELL_BATTLE_COMMAND,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Bat Rider - On Combat - Cast Battle Command'),
(@ENTRY,0,2,0,0,0,100,0,6500,6500,8000,8000,11,@SPELL_INFECTED_BITE,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gurubashi Bat Rider - On Combat - Cast Infected Bite'),
(@ENTRY,0,3,0,0,0,100,0,6000,6000,6000,6000,11,@SPELL_TRASH,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Bat Rider - On Combat - Cast Trash'),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,@SPELL_UNSTABLE_CONCOCTION,4,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Bat Rider - At 30% HP - Cast Unstable Concoction'),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gurubashi Bat Rider - At 30% HP - Emote Line 0');
-- Insert emote
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s fully engulfs in flame and a maddened look appears in his eyes!',16,0,100,0,0,0,'Gurubashi Bat Rider - On Unstable Concoction cast - Emote Line 0');
