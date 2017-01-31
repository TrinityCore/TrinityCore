-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4149: Not on my watch / [NPC] Lump
UPDATE `smart_scripts` SET `event_param2`=3 WHERE `entryorguid`=18351 AND `event_type`=62;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=18351 AND `id`=0;
UPDATE `creature_template` SET `unit_flags`=528 WHERE `entry`=18351;
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4206: Eliminate the Competition
SET @NPC_SIGRID        := 30086; -- Sigrid Iceborn
SET @MENUID_SIGRID     := 9870;
SET @NPC_EFREM         := 30081; -- Efrem the Faithful
SET @MENUID_EFREM      := 9869;
SET @NPC_ONUZUN        := 30180; -- Onu'zun
SET @MENUID_ONUZUN     := 9878;
SET @NPC_TINKY         := 30162; -- Tinky Wickwhistle
SET @MENUID_TINKY      := 9875;
UPDATE `creature_template` SET `npcflag`=1,`unit_flags`=33024,`AIName`='SmartAI' WHERE `entry` IN (@NPC_SIGRID,@NPC_EFREM,@NPC_ONUZUN,@NPC_TINKY);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@NPC_SIGRID,@NPC_EFREM,@NPC_ONUZUN,@NPC_TINKY);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Sigrid Iceborn
(@NPC_SIGRID,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@NPC_SIGRID,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@NPC_SIGRID,0,2,0,4,1,100,1,0,0,0,0,11,61168,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw on Aggro'),
(@NPC_SIGRID,0,3,0,9,1,100,0,5,30,3500,4100,11,61168,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@NPC_SIGRID,0,4,0,9,1,100,0,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@NPC_SIGRID,0,5,0,9,1,100,0,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@NPC_SIGRID,0,6,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@NPC_SIGRID,0,7,0,9,1,100,0,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in Throw Range'),
(@NPC_SIGRID,0,8,0,0,1,100,0,3000,7000,13000,16700,11,61164,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@NPC_SIGRID,0,9,0,13,1,100,0,12000,18000,0,0,11,57635,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Disengage on Target Spellcast'),
(@NPC_SIGRID,0,10,0,1,0,100,0,500,1000,600000,600000,11,61165,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frostbite Weapon on Spawn'),
(@NPC_SIGRID,0,11,12,62,0,100,0,@MENUID_SIGRID,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Close gossip'),
(@NPC_SIGRID,0,12,13,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set invincible'),
(@NPC_SIGRID,0,13,14,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Remove flags 256+512'),
(@NPC_SIGRID,0,14,15,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set faction hostile'),
(@NPC_SIGRID,0,15,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_SIGRID,0,16,17,2,0,100,0,0,1,0,0,33,@NPC_SIGRID,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 1 hp - Give killcredit'),
(@NPC_SIGRID,0,17,18,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Restore faction'),
(@NPC_SIGRID,0,18,19,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_SIGRID,0,19,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Evade'),
-- Efrem the Faithful
(@NPC_EFREM,0,0,0,1,0,100,0,500,1000,600000,600000,11,17232,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Spawn'),
(@NPC_EFREM,0,1,0,2,0,100,1,0,50,0,0,11,17233,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lay on Hands at 50% HP'),
(@NPC_EFREM,0,2,0,0,0,100,0,3300,5500,16000,17600,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crusader Strike'),
(@NPC_EFREM,0,3,0,0,0,80,0,9900,9900,21000,32000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice'),
(@NPC_EFREM,0,4,5,62,0,100,0,@MENUID_EFREM,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Close gossip'),
(@NPC_EFREM,0,5,6,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set invincible'),
(@NPC_EFREM,0,6,7,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Remove flags 256+512'),
(@NPC_EFREM,0,7,8,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set faction hostile'),
(@NPC_EFREM,0,8,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_EFREM,0,9,10,2,0,100,0,0,1,0,0,33,@NPC_EFREM,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 1 hp - Give killcredit'),
(@NPC_EFREM,0,10,11,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Restore faction'),
(@NPC_EFREM,0,11,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Evade'),
-- Onu'zun
(@NPC_ONUZUN,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@NPC_ONUZUN,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@NPC_ONUZUN,0,2,0,4,1,100,1,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@NPC_ONUZUN,0,3,0,9,1,100,0,0,40,3400,4700,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@NPC_ONUZUN,0,4,0,9,1,100,0,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@NPC_ONUZUN,0,5,0,9,1,100,0,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@NPC_ONUZUN,0,6,0,9,1,100,0,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@NPC_ONUZUN,0,7,0,3,1,100,0,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@NPC_ONUZUN,0,8,0,3,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@NPC_ONUZUN,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@NPC_ONUZUN,0,10,0,1,0,100,0,500,1000,600000,600000,11,18100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@NPC_ONUZUN,0,11,0,13,0,100,0,12000,18000,0,0,11,15122,0,0,0,0,0,6,1,0,0,0,0,0,0,'Cast Counterspell on Target Spellcast'),
(@NPC_ONUZUN,0,12,0,0,1,100,0,5000,5000,14500,17800,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cone of Cold'),
(@NPC_ONUZUN,0,13,14,62,0,100,0,@MENUID_ONUZUN,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Close gossip'),
(@NPC_ONUZUN,0,14,15,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set invincible'),
(@NPC_ONUZUN,0,15,16,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Remove flags 256+512'),
(@NPC_ONUZUN,0,16,17,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set faction hostile'),
(@NPC_ONUZUN,0,17,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_ONUZUN,0,18,19,2,0,100,0,0,1,0,0,33,@NPC_ONUZUN,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 1 hp - Give killcredit'),
(@NPC_ONUZUN,0,19,20,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Restore faction'),
(@NPC_ONUZUN,0,20,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Evade'),
-- Tinky Wickwhistle
(@NPC_TINKY,0,0,0,0,0,100,0,7000,8000,15600,17800,11,61552,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrench Strike'),
(@NPC_TINKY,0,1,0,0,0,100,0,13000,14000,21300,23400,11,37666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Heavy Dynamite'),
(@NPC_TINKY,0,2,3,62,0,100,0,@MENUID_TINKY,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On gossip select - Close gossip'),
(@NPC_TINKY,0,3,4,61,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set invincible'),
(@NPC_TINKY,0,4,5,61,0,100,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Remove flags 256+512'),
(@NPC_TINKY,0,5,6,61,0,100,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Set faction hostile'),
(@NPC_TINKY,0,6,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_TINKY,0,7,8,2,0,100,0,0,1,0,0,33,@NPC_TINKY,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 1 hp - Give killcredit'),
(@NPC_TINKY,0,8,9,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Restore faction'),
(@NPC_TINKY,0,9,10,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Talk'),
(@NPC_TINKY,0,10,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Evade');
DELETE FROM `creature_text` WHERE `entry` IN (@NPC_SIGRID,@NPC_EFREM,@NPC_ONUZUN,@NPC_TINKY);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_SIGRID,0,0,'Taste my steel, little $g boy : girl;!',12,0,100,0,0,0,'say'),
(@NPC_SIGRID,1,0,'You fight well, little one. I am bested for now. We will meet again I assure you. When we do I will be better prepared!',12,0,100,66,0,0,'say'),
(@NPC_EFREM,0,0,'You dare to touch ME?! You won''t keep me from proving myself to the Lich King!',12,0,100,0,0,0,'say'),
(@NPC_ONUZUN,0,0,'Onu''zun gonna kill you dead!',12,0,100,0,0,0,'say'),
(@NPC_TINKY,0,0,'Grrrrrrrr! I''ll kneecap ya!',12,0,100,0,0,0,'say'),
(@NPC_TINKY,1,0,'WHEE!!!',12,0,100,0,0,0,'say');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4252: Bringing Down the Iron Thane
SET @Thane :=    26405;
SET @Anvil :=    26406;
SET @Guid :=     426; -- 4.x guid
SET @Script := 2640600;
SET @Golem :=    29005;
-- Add missing spawns
DELETE FROM `creature` WHERE `id`=@Thane;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)  VALUES
(@Guid,@Thane ,571,1,1,0,1419,3317.76,-5112.08,300.462,1.78269,300,0,0,12762,3561,0,0,0,0); -- spawn NPC if there isn't, GUID is random
-- SAI for Thane
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Thane;
UPDATE `creature_template` SET `AIName`='SmartAI',`faction_A`=1954,`faction_H`=1954 WHERE `entry`=@Thane ;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Thane,@Script);
INSERT INTO `smart_scripts` VALUES
(@Thane,0,0,0,38,0,100,0,0,1,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - On data set 0 1 - Run timed action list'),
(@Thane,0,1,0,1,0,100,0,0,0,20000,20000,75,47922,0,0,0,0,0,1,0,0,0,0,0,0,0,'Iron Thane - OOC - Add Aura'),
(@Thane,0,2,0,0,0,100,0,5000,9000,10000,14000,11,61575,0,0,0,0,0,2,0,0,0,0,0,0,0,'Iron Thane - IC - Cast Furyhammer'),
(@Thane,0,3,0,6,0,100,0,0,0,0,0,28,47923,0,0,0,0,0,19,@Anvil,30,0,0,0,0,0,'Thane - Script action 3 - Remove stun aura from Avil'),
-- Script 0 for Thane
(@Script,9,0,0,0,0,100,0,0,0,0,0,75,47923,0,0,0,0,0,19,@Anvil,30,0,0,0,0,0,'Thane - Script action 0 - Add aura stunned to Anvil'),
(@Script,9,1,0,0,0,100,0,500,500,0,0,28,47922,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - Script action 1 - Remove inurnable aura from self'),
(@Script,9,2,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thane - Script action 2 - Data set 0 0'),
(@Script,9,3,0,0,0,100,0,14500,14500,0,0,28,47923,0,0,0,0,0,19,@Anvil,30,0,0,0,0,0,'Thane - Script action 3 - Remove stun aura from Avil');
-- Add SAI for Anvil
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Anvil;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Anvil;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Anvil;
INSERT INTO `smart_scripts` VALUES
(@Anvil,0,0,0,8,0,100,0,47911,0,0,0,45,0,1,0,0,0,0,19,@Thane,30,0,0,0,0,0,'Anvil - on Spell hit - Data set 0 1 on Thane'),
(@Anvil,0,1,0,0,0,100,0,5000,7500,1200,14500,11,61577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Anvil - IC - Cast Molten Blast');
-- Add npc_spellclick_spells
UPDATE `creature_template` SET `VehicleId`=149,`spell1`=61380,`spell2`=47911 WHERE `entry`=@Golem;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@Golem;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@Golem,60944,1,0);
-- Add conditions for npc_spellclick_spells
DELETE FROM `conditions` WHERE `SourceGroup`=@Golem AND `SourceTypeOrReferenceId`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(18,@Golem,60944,0,1,9,0,12199,0,0,0,0,'', 'Player must be on quest 12199'),
(18,@Golem,60944,0,2,9,0,12153,0,0,0,0,'', 'Player must be on quest 12153');
-- Add conditions EMP to hit Anvil /for new condition system/
DELETE FROM `conditions` WHERE `SourceEntry`=47911 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(13,1,47911,0,0,31,0,3,@Anvil,0,0,0,'', 'EMP can hit only Anvil /rewritten condition/');
-- Add conditions EMP to cast only, if in 10 yards to anvil
DELETE FROM `conditions` WHERE `SourceEntry`=47911 AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(17,0,47911,0,0,29,0,@Anvil,10,0,0,0,'', 'EMP can cast, if in 10 yards of Anvil');
-- -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4888: Event after finishing The Dragonforged Hilt quest chain
SET @NPC_MYRALION_SUNBLAZE := 36642;
SET @NPC_CALADIS_BRIGHTSPEAR := 36624;
SET @NPC_SUNREAVER_WAR_MAGE := 36657;
SET @NPC_SILVER_COVENANT_SENTINEL := 36656;
SET @NPC_IMAGE_OF_ALEXTRASZA := 37829;
SET @NPC_IMAGE_OF_ANASTERIAN := 37844;
SET @NPC_IMAGE_OF_THALORIEN := 37828;
SET @NPC_IMAGE_OF_MORLEN := 37845;
SET @NPC_BLOOD_QUEEN_LANA_THEL := 37846;
SET @NPC_QUELDELAR_DUMMY := 37852;
SET @SPELL_FREEZE_GUARDS := 71365;
SET @SPELL_ICY_TOUCH_TRIGGER := 70589;
SET @SPELL_ICY_TOUCH_EFFECT := 70592;
SET @SPELL_THROW_SWORD := 70586;
SET @SPELL_EXPLOSION_DUMMY := 70000; -- Not OK!!
SET @EMOTE_TALK := 1;
SET @EMOTE_BOW := 2;
SET @EMOTE_QUESTION := 6;
SET @EMOTE_KNEE := 16;
SET @EMOTE_POINT := 25;
SET @EMOTE_STAND := 26;
SET @EMOTE_YES := 273;
SET @EMOTE_1H := 375;
SET @EMOTE_2H := 425;
SET @ITEM_QUELDELAR := 49767;
SET @DATA_CUSTOM_ACTION := 50;
SET @DATA_DESPAWN_ACTION := 41;
SET @WP_MYRALION := @NPC_MYRALION_SUNBLAZE;
SET @WP_CALADIS := @NPC_CALADIS_BRIGHTSPEAR;
SET @WP_THALORIEN := @NPC_IMAGE_OF_THALORIEN;
SET @WP_MORLEN := @NPC_IMAGE_OF_MORLEN;
SET @WP_BLOOD_QUEEN_1 := @NPC_BLOOD_QUEEN_LANA_THEL*100;
SET @WP_BLOOD_QUEEN_2 := @NPC_BLOOD_QUEEN_LANA_THEL*100+1;
SET @WP_GUARD_A_1 := @NPC_SILVER_COVENANT_SENTINEL*100;
SET @WP_GUARD_A_2 := @NPC_SILVER_COVENANT_SENTINEL*100+1;
SET @WP_GUARD_H_1 := @NPC_SUNREAVER_WAR_MAGE*100;
SET @WP_GUARD_H_2 := @NPC_SUNREAVER_WAR_MAGE*100+1;
SET @QUEST_RETURN_CALADIS_BRIGHTSPEAR := 24454;
SET @QUEST_RETURN_MYRALION_SUNBLAZE := 24558;
-- Set images as non-selectables
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432 WHERE `entry` IN (@NPC_IMAGE_OF_ALEXTRASZA,@NPC_IMAGE_OF_ANASTERIAN,@NPC_IMAGE_OF_THALORIEN,@NPC_IMAGE_OF_MORLEN);
-- Set Lana'thel as enemy and set OOC_NON_ATTACKABLE
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|256 WHERE `entry`=@NPC_BLOOD_QUEEN_LANA_THEL;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_THROW_SWORD;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL_THROW_SWORD,0,18,1,@NPC_QUELDELAR_DUMMY,0,0,'', "Throw Quel'delar on Quel'delar skull");
-- Set Morlen Coldgrip mount
DELETE FROM `creature_template_addon` WHERE (`entry`=@NPC_IMAGE_OF_MORLEN);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC_IMAGE_OF_MORLEN,0,25280,0,0,0,"");
-- Set AInames
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@NPC_CALADIS_BRIGHTSPEAR,@NPC_MYRALION_SUNBLAZE,@NPC_SILVER_COVENANT_SENTINEL,@NPC_SUNREAVER_WAR_MAGE,@NPC_IMAGE_OF_ALEXTRASZA,@NPC_IMAGE_OF_ANASTERIAN,@NPC_IMAGE_OF_THALORIEN,@NPC_IMAGE_OF_MORLEN,@NPC_BLOOD_QUEEN_LANA_THEL,@NPC_QUELDELAR_DUMMY);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_MYRALION_SUNBLAZE,@NPC_CALADIS_BRIGHTSPEAR,@NPC_IMAGE_OF_ALEXTRASZA,@NPC_IMAGE_OF_ANASTERIAN,@NPC_IMAGE_OF_THALORIEN,@NPC_IMAGE_OF_MORLEN,@NPC_BLOOD_QUEEN_LANA_THEL,@NPC_QUELDELAR_DUMMY) AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (@NPC_MYRALION_SUNBLAZE*100,@NPC_SILVER_COVENANT_SENTINEL*100,@NPC_BLOOD_QUEEN_LANA_THEL*100,@NPC_BLOOD_QUEEN_LANA_THEL*100+1) AND `source_type`=9);
DELETE FROM `smart_scripts` WHERE (`entryorguid` IN (-202775,-202776,-202777,-202778) AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Image of Alextrasza
(@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,38,0,100,0,@EMOTE_TALK,0,0,0,5,@EMOTE_TALK,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Alexstrasza (at Quel'delar rest) - Emote Talk on Data Set"),
(@NPC_IMAGE_OF_ALEXTRASZA,0,1,0,38,0,100,0,@EMOTE_POINT,0,0,0,5,@EMOTE_POINT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Alexstrasza (at Quel'delar rest) - Emote Point on Data Set"),
(@NPC_IMAGE_OF_ALEXTRASZA,0,2,0,38,0,100,0,@DATA_CUSTOM_ACTION ,0,0,0,66,0,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Image of Alexstrasza (at Quel'delar rest) - Set Orientation on Data Set"),
(@NPC_IMAGE_OF_ALEXTRASZA,0,3,0,38,0,100,0,@DATA_DESPAWN_ACTION,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Alexstrasza (at Quel'delar rest) - Despawn on Data Set"),
-- Image of Anasterian
(@NPC_IMAGE_OF_ANASTERIAN,0,0,0,38,0,100,0,@EMOTE_TALK,0,0,0,5,@EMOTE_TALK,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Emote talk on Data Set"),
(@NPC_IMAGE_OF_ANASTERIAN,0,1,0,38,0,100,0,@EMOTE_BOW,0,0,0,5,@EMOTE_BOW,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Emote bow on Data Set"),
(@NPC_IMAGE_OF_ANASTERIAN,0,2,0,38,0,100,0,@EMOTE_POINT,0,0,0,5,@EMOTE_POINT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Emote point on Data Set"),
(@NPC_IMAGE_OF_ANASTERIAN,0,3,0,38,0,100,0,@EMOTE_YES,0,0,0,5,@EMOTE_YES,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Emote yes on Data Set"),
(@NPC_IMAGE_OF_ANASTERIAN,0,4,0,38,0,100,0,@DATA_CUSTOM_ACTION ,0,0,0,66,0,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Set Orientation"),
(@NPC_IMAGE_OF_ANASTERIAN,0,5,0,38,0,100,0,@DATA_DESPAWN_ACTION,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Anasterian (at Quel'delar rest) - Despawn on data set"),
-- Image of Thalorien Dawnseeker
(@NPC_IMAGE_OF_THALORIEN,0,0,0,38,0,100,1,@DATA_CUSTOM_ACTION,0,0,0,53,0,@WP_THALORIEN,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Move to position on Data set"),
(@NPC_IMAGE_OF_THALORIEN,0,1,0,38,0,100,1,@EMOTE_BOW,0,0,0,5,@EMOTE_BOW,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Emote Bow on Data Set"),
(@NPC_IMAGE_OF_THALORIEN,0,2,0,38,0,100,1,@EMOTE_KNEE,0,0,0,5,@EMOTE_KNEE,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Emote Knee on Data Set"),
(@NPC_IMAGE_OF_THALORIEN,0,3,4,38,0,100,1,@EMOTE_1H,0,0,0,71,0,0,@ITEM_QUELDELAR,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Equip Sword Data Set"),
(@NPC_IMAGE_OF_THALORIEN,0,4,0,61,0,100,1,0,0,0,0,17,@EMOTE_1H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - EmoteState 2H on Data Set"),
(@NPC_IMAGE_OF_THALORIEN,0,5,0,38,0,100,1,@DATA_DESPAWN_ACTION,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Desapwn at data set"),
(@NPC_IMAGE_OF_THALORIEN,0,6,0,38,0,100,1,@DATA_CUSTOM_ACTION+1,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Thalorien Dawnseeker (at Quel'Delar rest) - Show now weapon"),
-- Image of Morlen Coldgrip
(@NPC_IMAGE_OF_MORLEN,0,0,0,34,0,100,1,0,1,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Morlen Coldgrip - Pause WP on 1st point"),
(@NPC_IMAGE_OF_MORLEN,0,1,0,34,0,100,1,0,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Morlen Coldgrip - Despawn on last WP"),
(@NPC_IMAGE_OF_MORLEN,0,2,0,54,0,100,1,0,2,0,0,53,0,@WP_MORLEN,0,0,0,0,1,0,0,0,0,0,0,0,"Image of Morlen Coldgrip - Start WP on spawn"),
-- Blood-Queen Lana'thel
(@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,54,0,100,1,0,0,0,0,53,0,@WP_BLOOD_QUEEN_1,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Quen Lana'thel (at Quel'delar rest) - Start WP on spawn"),
(@NPC_BLOOD_QUEEN_LANA_THEL,0,1,2,40,0,100,1,1,@WP_BLOOD_QUEEN_1,0,0,80,@NPC_BLOOD_QUEEN_LANA_THEL*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Quen Lana'thel (at Quel'delar rest) - Start first part of timed event when reached first point"),
(@NPC_BLOOD_QUEEN_LANA_THEL,0,2,0,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_QUELDELAR_DUMMY,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Face to invisible dummy"),
(@NPC_BLOOD_QUEEN_LANA_THEL,0,3,0,40,0,100,1,2,@WP_BLOOD_QUEEN_2,0,0,80,@NPC_BLOOD_QUEEN_LANA_THEL*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Quen Lana'thel (at Quel'delar rest) - Start second timed event when reached second point"),
(@NPC_QUELDELAR_DUMMY,0,1,0,8,0,100,0,@SPELL_THROW_SWORD,0,0,0,11,@SPELL_EXPLOSION_DUMMY,1,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'delar dummy (at Quel'delar rest) - Cast shadow explosion when hitten by sword"),
-- Blood-Queen Lana'thel 1st action list
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,0,0,0,0,100,1,3000,3000,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,9,@NPC_SILVER_COVENANT_SENTINEL,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Make guards attack her"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,1,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,9,@NPC_SUNREAVER_WAR_MAGE,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Make guards attack her"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,2,0,0,0,100,1,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Say 1"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,3,0,0,0,100,1,3000,3000,0,0,11,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Cast Freeze Guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,4,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION+1,0,0,0,0,0,9,@NPC_SILVER_COVENANT_SENTINEL,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Freeze guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,5,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION+1,0,0,0,0,0,9,@NPC_SUNREAVER_WAR_MAGE,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Freeze guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,6,0,0,0,100,1,500,500,0,0,1,2,0,0,0,0,0,1,0,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Say 2"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,7,0,0,0,100,1,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Say 3"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,8,0,0,0,100,1,0,0,0,0,12,@NPC_IMAGE_OF_ALEXTRASZA,8,0,0,0,0,8,0,0,0,8120.65,780.068,481.87,6.14516,"Blood Queen Lana'thel (at Quel'Delar rest) - Summon Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,9,0,0,0,100,1,0,0,0,0,12,@NPC_IMAGE_OF_ANASTERIAN,8,0,0,0,0,8,0,0,0,8123.63,780.044,482.066,3.10017,"Blood Queen Lana'thel (at Quel'Delar rest) - Summon Anasterian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,10,0,0,0,100,1,500,500,0,0,45,@EMOTE_POINT,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call point talk on Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,11,0,0,0,100,1,100,100,0,0,45,@EMOTE_TALK,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote talk on Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,12,0,0,0,100,1,4000,4000,0,0,5,@EMOTE_POINT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Emote Point"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,13,0,0,0,100,1,0,0,0,0,45,@EMOTE_BOW,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote bow on Anasterian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,14,0,0,0,100,1,2000,2000,0,0,45,@EMOTE_TALK,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote talk on Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,15,0,0,0,100,1,2000,2000,0,0,45,@EMOTE_YES,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote yes on Anasterian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,16,0,0,0,100,1,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 4"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,17,0,0,0,100,1,0,0,0,0,12,@NPC_IMAGE_OF_THALORIEN,8,0,0,0,0,8,0,0,0,8125.07,773.643,482.395,1.72804,"Blood Queen Lana'thel (at Quel'Delar rest) - Summon Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,18,0,0,0,100,1,500,500,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call set facing to Thalorien on Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,19,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call set facing to Thalorien on Anasterian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,20,0,0,0,100,1,1000,1000,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Thalorien Move"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,21,0,0,0,100,1,3000,3000,0,0,45,@EMOTE_TALK,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Emote Talk on Anastarian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,22,0,0,0,100,1,1000,1000,0,0,45,@EMOTE_BOW,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Emote Bow on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,23,0,0,0,100,1,1000,1000,0,0,45,@EMOTE_POINT,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Emote point on Anastarian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,24,0,0,0,100,1,1000,1000,0,0,45,@EMOTE_KNEE,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call Emote Knee on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,25,0,0,0,100,1,1000,1000,0,0,45,@DATA_DESPAWN_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_ALEXTRASZA,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Despawn Alextrasza"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,26,0,0,0,100,1,1000,1000,0,0,45,@DATA_DESPAWN_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_ANASTERIAN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Despawn Anastarian"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,27,0,0,0,100,1,1000,1000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 5"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,28,0,0,0,100,1,3000,3000,0,0,45,@EMOTE_1H,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call emote 2h on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,29,0,0,0,100,1,4000,4000,0,0,12,@NPC_IMAGE_OF_MORLEN,8,0,0,0,0,8,0,0,0,8119.94,787.208,481.39,5.00233,"Blood Queen Lana'thel (at Quel'Delar rest) - Summon Morlen Coldgrip"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,30,0,0,0,100,1,2000,2000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 6"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,31,0,0,0,100,1,2000,2000,0,0,86,@SPELL_ICY_TOUCH_TRIGGER,0,19,@NPC_IMAGE_OF_MORLEN,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call cast of Morlen Coldgrip on Thalorien (dummy)"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,32,0,0,0,100,1,1000,1000,0,0,86,@SPELL_ICY_TOUCH_EFFECT,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call cast of Thalorien (insta self kill)"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+0,9,33,0,0,0,100,1,4000,4000,0,0,53,0,@WP_BLOOD_QUEEN_2,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Move to next event point"),
-- Blood-Queen Lana'thel 2nd action list
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Set facing to Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,1,0,0,0,100,0,2000,2000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 7"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,2,0,0,0,100,0,1000,1000,0,0,71,0,0,@ITEM_QUELDELAR,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Equip Sword"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,3,0,0,0,100,0,0,0,0,0,45,@DATA_CUSTOM_ACTION+1,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Set no weapon visible on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,4,0,0,0,100,0,7000,7000,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Set no weapon visible"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,5,0,0,0,100,0,0,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Emote Talk"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,6,0,0,0,100,0,6000,6000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 8"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,7,0,0,0,100,0,8000,8000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 9"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,8,0,0,0,100,0,8000,8000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 10"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,9,0,0,0,100,0,5000,5000,0,0,11,@SPELL_THROW_SWORD,0,0,0,0,0,19,@NPC_QUELDELAR_DUMMY,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Cast some spell on invisible dummy"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,10,0,0,0,100,0,4000,4000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Say 11"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,11,0,0,0,100,0,5000,5000,0,0,45,@DATA_CUSTOM_ACTION,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Call reset on the summoner"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,12,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION+2,0,0,0,0,0,9,@NPC_SILVER_COVENANT_SENTINEL,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Unfreeze guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,13,0,0,0,100,1,0,0,0,0,45,@DATA_CUSTOM_ACTION+2,0,0,0,0,0,9,@NPC_SUNREAVER_WAR_MAGE,0,20,0,0,0,0,"Blood Quen Lana'thel (at Quel'Delar rest) - Unfreeze guards"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,14,0,0,0,100,0,0,0,0,0,45,@DATA_DESPAWN_ACTION,0,0,0,0,0,19,@NPC_IMAGE_OF_THALORIEN,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'elar rest) - Call despawn on Thalorien"),
(@NPC_BLOOD_QUEEN_LANA_THEL*100+1,9,15,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood Queen Lana'thel (at Quel'Delar rest) - Despawn self"),
-- Silver Covenant Guards
(-202776,0,0,1,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,1,@WP_GUARD_A_1,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement on data set"),
(-202776,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set phase 1"),
(-202776,0,2,3,40,1,100,0,1,0,0,0,66,0,0,0,0,0,0,19,@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,0,0,0,"Silver Covenant Sentinel - Set facing to Lana'thel on reach point"),
(-202776,0,3,4,61,1,100,0,0,0,0,0,17,@EMOTE_2H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set attack state"),
(-202776,0,4,5,61,1,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Stop WP"),
(-202776,0,5,12,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set Phase 2"),
(-202776,0,6,0,38,0,100,0,@DATA_CUSTOM_ACTION+1,0,0,0,75,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Freeze self on Data Set"),
(-202776,0,7,8,38,0,100,0,@DATA_CUSTOM_ACTION+2,0,0,0,28,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Unfreeze self on Data Set"),
(-202776,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_SILVER_COVENANT_SENTINEL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Create timed event based on action list"),
(-202776,0,9,0,38,0,100,0,@DATA_CUSTOM_ACTION+3,0,0,0,53,0,@WP_GUARD_A_1,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement back on timed event (called from action list)"),
(-202776,0,10,11,40,0,100,0,2,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore home orientation on reach point"),
(-202776,0,11,0,61,0,100,0,0,0,0,0,17,@EMOTE_STAND,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore stand state"),
(-202776,0,12,0,61,1,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Say to Lana'thel"),
(-202775,0,0,1,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,1,@WP_GUARD_A_2,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement on data set"),
(-202775,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set phase 1"),
(-202775,0,2,3,40,1,100,0,1,0,0,0,66,0,0,0,0,0,0,19,@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,0,0,0,"Silver Covenant Sentinel - Set facing to Lana'thel on reach point"),
(-202775,0,3,4,61,1,100,0,0,0,0,0,17,@EMOTE_2H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set attack state"),
(-202775,0,4,5,61,1,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Stop WP"),
(-202775,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set Phase 2"),
(-202775,0,6,0,38,0,100,0,@DATA_CUSTOM_ACTION+1,0,0,0,75,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Freeze self on Data Set"),
(-202775,0,7,8,38,0,100,0,@DATA_CUSTOM_ACTION+2,0,0,0,28,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Unfreeze self on Data Set"),
(-202775,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_SILVER_COVENANT_SENTINEL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Create timed event based on action list"),
(-202775,0,9,0,38,0,100,0,@DATA_CUSTOM_ACTION+3,0,0,0,53,0,@WP_GUARD_A_2,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement back on timed event (called from action list)"),
(-202775,0,10,11,40,0,100,0,2,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore home orientation on reach point"),
(-202775,0,11,0,61,0,100,0,0,0,0,0,17,@EMOTE_STAND,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore stand state"),
-- Sunreaver Guards
(-202777,0,0,1,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,1,@WP_GUARD_H_1,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement on data set"),
(-202777,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set phase 1"),
(-202777,0,2,3,40,1,100,0,1,0,0,0,66,0,0,0,0,0,0,19,@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,0,0,0,"Silver Covenant Sentinel - Set facing to Lana'thel on reach point"),
(-202777,0,3,4,61,1,100,0,0,0,0,0,17,@EMOTE_2H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set attack state"),
(-202777,0,4,5,61,1,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Stop WP"),
(-202777,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set Phase 2"),
(-202777,0,6,0,38,0,100,0,@DATA_CUSTOM_ACTION+1,0,0,0,75,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Freeze self on Data Set"),
(-202777,0,7,8,38,0,100,0,@DATA_CUSTOM_ACTION+2,0,0,0,28,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Unfreeze self on Data Set"),
(-202777,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_SILVER_COVENANT_SENTINEL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Create timed event based on action list"),
(-202777,0,9,0,38,0,100,0,@DATA_CUSTOM_ACTION+3,0,0,0,53,0,@WP_GUARD_H_1,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement back on timed event (called from action list)"),
(-202777,0,10,11,40,0,100,0,2,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore home orientation on reach point"),
(-202777,0,11,0,61,0,100,0,0,0,0,0,17,@EMOTE_STAND,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore stand state"),
(-202778,0,0,1,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,1,@WP_GUARD_H_2,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement on data set"),
(-202778,0,1,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set phase 1"),
(-202778,0,2,3,40,1,100,0,1,0,0,0,66,0,0,0,0,0,0,19,@NPC_BLOOD_QUEEN_LANA_THEL,0,0,0,0,0,0,"Silver Covenant Sentinel - Set facing to Lana'thel on reach point"),
(-202778,0,3,4,61,1,100,0,0,0,0,0,17,@EMOTE_2H,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set attack state"),
(-202778,0,4,5,61,1,100,0,0,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Stop WP"),
(-202778,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Set Phase 2"),
(-202778,0,6,0,38,0,100,0,@DATA_CUSTOM_ACTION+1,0,0,0,75,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Freeze self on Data Set"),
(-202778,0,7,8,38,0,100,0,@DATA_CUSTOM_ACTION+2,0,0,0,28,@SPELL_FREEZE_GUARDS,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Unfreeze self on Data Set"),
(-202778,0,8,0,61,0,100,0,0,0,0,0,80,@NPC_SILVER_COVENANT_SENTINEL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Create timed event based on action list"),
(-202778,0,9,0,38,0,100,0,@DATA_CUSTOM_ACTION+3,0,0,0,53,0,@WP_GUARD_H_2,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - Start movement back on timed event (called from action list)"),
(-202778,0,10,11,40,0,100,0,2,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore home orientation on reach point"),
(-202778,0,11,0,61,0,100,0,0,0,0,0,17,@EMOTE_STAND,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silver Covenant Sentinel - restore stand state"),
-- Timed event for guards
(@NPC_SILVER_COVENANT_SENTINEL*100,9,0,0,0,0,100,0,1000,1000,0,0,45,@DATA_CUSTOM_ACTION+3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Delar rest - Guards timed return"),
-- Myralion Sunblaze
(@NPC_MYRALION_SUNBLAZE,0,0,1,20,0,100,0,@QUEST_RETURN_MYRALION_SUNBLAZE,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - remove gossip and qg flag on quest complete"),
(@NPC_MYRALION_SUNBLAZE,0,1,2,61,0,100,0,0,0,0,0,53,0,@WP_MYRALION,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Start WP on quest complete"),
(@NPC_MYRALION_SUNBLAZE,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Set phase 1"),
(@NPC_MYRALION_SUNBLAZE,0,3,4,40,1,100,0,1,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Stop WP on point reached"),
(@NPC_MYRALION_SUNBLAZE,0,4,0,61,1,100,0,0,0,0,0,80,@NPC_MYRALION_SUNBLAZE*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Start timed event on point reached"),
(@NPC_MYRALION_SUNBLAZE,0,6,7,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,0,@WP_MYRALION,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - WP event on data set"),
(@NPC_MYRALION_SUNBLAZE,0,7,11,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Set phase on data set"),
(@NPC_MYRALION_SUNBLAZE,0,8,9,40,0,100,0,2,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Say 3 event on home reached"),
(@NPC_MYRALION_SUNBLAZE,0,9,10,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - restore orientation event on home reached"),
(@NPC_MYRALION_SUNBLAZE,0,10,0,61,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - restore npc flags event on home reached"),
(@NPC_MYRALION_SUNBLAZE,0,11,0,61,0,100,0,0,0,0,0,43,0,28889,0,0,0,0,1,0,0,0,0,0,0,0,"Myralion Sunblaze - Mount on data set"),
-- Caladis Brightspear
(@NPC_CALADIS_BRIGHTSPEAR,0,0,1,20,0,100,0,@QUEST_RETURN_CALADIS_BRIGHTSPEAR,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - remove gossip and qg flag on quest complete"),
(@NPC_CALADIS_BRIGHTSPEAR,0,1,2,61,0,100,0,0,0,0,0,53,0,@WP_CALADIS,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Start WP on quest complete"),
(@NPC_CALADIS_BRIGHTSPEAR,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Set phase 1"),
(@NPC_CALADIS_BRIGHTSPEAR,0,3,4,40,1,100,0,1,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Stop WP on point reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,4,0,61,1,100,0,0,0,0,0,80,@NPC_MYRALION_SUNBLAZE*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Start timed event on point reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,6,7,38,0,100,0,@DATA_CUSTOM_ACTION,0,0,0,53,0,@WP_CALADIS,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - WP event on data set"),
(@NPC_CALADIS_BRIGHTSPEAR,0,7,11,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Set phase on data set"),
(@NPC_CALADIS_BRIGHTSPEAR,0,8,9,40,0,100,0,2,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Say 3 event on home reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,9,10,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - restore orientation event on home reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,10,0,61,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - restore npc flags event on home reached"),
(@NPC_CALADIS_BRIGHTSPEAR,0,11,0,61,0,100,0,0,0,0,0,43,0,28888,0,0,0,0,1,0,0,0,0,0,0,0,"Caladis Brightspear - Mount on data set"),
-- Timed event for faction heralds
(@NPC_MYRALION_SUNBLAZE*100,9,0,0,0,0,100,1,1000,1000,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'delar rest faction Herald - Dismount"),
(@NPC_MYRALION_SUNBLAZE*100,9,1,0,0,0,100,1,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'delar rest faction Herald - Say 1"),
(@NPC_MYRALION_SUNBLAZE*100,9,2,0,0,0,100,1,0,0,0,0,12,@NPC_BLOOD_QUEEN_LANA_THEL,8,0,0,0,0,8,0,0,0,8102.33,785.112,481.025,5.99244,"Quel'delar rest faction Herald - Summon Lana'thel"),
(@NPC_MYRALION_SUNBLAZE*100,9,3,0,0,0,100,1,8000,8000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'delar rest faction Herald - Say 2");
DELETE FROM `waypoints` WHERE `entry` IN (@WP_MYRALION,@WP_CALADIS,@WP_THALORIEN,@WP_MORLEN,@WP_BLOOD_QUEEN_1,@WP_BLOOD_QUEEN_2,@WP_GUARD_A_1,@WP_GUARD_A_2,@WP_GUARD_H_1,@WP_GUARD_H_2);
INSERT INTO `waypoints`(`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@WP_MYRALION,1,8121.94,776.030,482.114,"Myralion Sunblaze - WP 1"),
(@WP_MYRALION,2,8127.26,766.402,482.579,"Myralion Sunblaze - Home Position"),
(@WP_CALADIS,1,8119.73,783.416,481.623,"Caladis Brightspear - WP 1"),
(@WP_CALADIS,2,8117.69,795.523,481.184,"Caladis Brightspear - Home Position"),
(@WP_THALORIEN,1,8122.35,778.496,482.034,"Image of Thalorien Dawnseeker - WP 1"),
(@WP_MORLEN,1,8121.75,781.096,481.905,"Image of Morlen Coldgrip - WP 1"),
(@WP_MORLEN,2,8124.83,774.881,482.328,"Image of Morlen Coldgrip - WP 2"),
(@WP_BLOOD_QUEEN_1,1,8115.65,780.131,481.611,"Lana'thel Quel'delar rest - WP 1.1"),
(@WP_BLOOD_QUEEN_2,1,8119.96,775.924,482.029,"Lana'thel Quel'delar rest - WP 2.1"),
(@WP_BLOOD_QUEEN_2,2,8124.342,778.9861,482.0804,"Lana'thel Quel'delar rest - WP 2.2"),
(@WP_GUARD_A_1,1,8118.80,783.843,481.567,"Quel'Delar rest guard 2 (GUID: 202776)- WP 1"),
(@WP_GUARD_A_1,2,8123.66,793.745,481.434,"Quel'Delar rest guard 2 (GUID: 202776)- Home Position"),
(@WP_GUARD_A_2,1,8113.40,783.385,481.416,"Quel'Delar rest guard 1 (GUID: 202775)- WP 1"),
(@WP_GUARD_A_2,2,8111.31,794.347,481.059,"Quel'Delar rest guard 1 (GUID: 202775)- Home Position"),
(@WP_GUARD_H_1,1,8112.35,775.095,481.583,"Quel'Delar rest guard 1 (GUID: 202777)- WP 1"),
(@WP_GUARD_H_1,2,8120.10,765.363,482.266,"Quel'Delar rest guard 1 (GUID: 202777)- Home Position"),
(@WP_GUARD_H_2,1,8118.65,775.747,481.973,"Quel'Delar rest guard 2 (GUID: 202778)- WP 1"),
(@WP_GUARD_H_2,2,8130.01,772.465,482.629,"Quel'Delar rest guard 2 (GUID: 202778)- Home Position");
DELETE FROM `creature_text` WHERE `entry` IN (@NPC_MYRALION_SUNBLAZE,@NPC_CALADIS_BRIGHTSPEAR,@NPC_SILVER_COVENANT_SENTINEL,@NPC_BLOOD_QUEEN_LANA_THEL);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_MYRALION_SUNBLAZE,1,0,"The style of this blade and its markings hinted that it might be a dragonforged sword. At last, we will have our answer.",12,0,100,@EMOTE_TALK,0,16745,"Myralion Sunblaze - Say 1"),
(@NPC_MYRALION_SUNBLAZE,2,0,"After all these years, can it really be --",12,0,100,@EMOTE_QUESTION,0,16746,"Myralion Sunblaze - Say 2"),
(@NPC_MYRALION_SUNBLAZE,3,0,"It falls to us to see Quel'Delar restored for the Sunreavers.",12,0,100,0,0,0,"Myralion Sunblaze - Say 3"),
(@NPC_CALADIS_BRIGHTSPEAR,1,0,"I knew this was a dragonforged blade when I first laid eyes on it.",12,0,100,@EMOTE_TALK,0,16604,"Caladis Brightspear - Say 1"),
(@NPC_CALADIS_BRIGHTSPEAR,2,0,"But can it be? Is this really --",12,0,100,@EMOTE_QUESTION,0,16605,"Caladis Brightspear - Say 2"),
(@NPC_CALADIS_BRIGHTSPEAR,3,0,"I vow that the Silver Covenant will see Quel'Delar restored.",12,0,100,0,0,0,"Caladis Brightspear - Say 3"),
(@NPC_SILVER_COVENANT_SENTINEL,1,0,"You are not welcome here, minion of the Lich King!",12,0,100,0,0,0,"Silver Covenant Sentinel - Say 1"),
(@NPC_BLOOD_QUEEN_LANA_THEL,1,0,"Quel'Delar.",12,0,100,@EMOTE_TALK,0,16808,"Blood Queen Lana'thel - Say 1"),
(@NPC_BLOOD_QUEEN_LANA_THEL,2,0,"Quiet, fools. If I had wished to kill you, you'd already be dead.",12,0,100,0,0,0,"Blood Queen Lana'thel - Say 2"),
(@NPC_BLOOD_QUEEN_LANA_THEL,3,0,"As Quel'Serrar was forged by the dragons and given to the kaldorei, its twin,Quel'Delar was given to my people.",12,0,100,@EMOTE_TALK,0,16809,"Blood Queen Lana'thel - Say 3"),
(@NPC_BLOOD_QUEEN_LANA_THEL,4,0,"The king bestowed the blade upon my friend, Thalorien Dawnseeker.",12,0,100,@EMOTE_TALK,0,16800,"Blood Queen Lana'thel - Say 4"),
(@NPC_BLOOD_QUEEN_LANA_THEL,5,0,"But even Thalorien's skill and Quel'Delar's magic could not save Silvermoon from the might of the Scourge.",12,0,100,@EMOTE_TALK,0,16801,"Blood Queen Lana'thel - Say 5"),
(@NPC_BLOOD_QUEEN_LANA_THEL,6,0,"Thalorien fell before the gates of the Sunwell, buying time for others to escape.",12,0,100,@EMOTE_TALK,0,16802,"Blood Queen Lana'thel - Say 6"),
(@NPC_BLOOD_QUEEN_LANA_THEL,7,0,"After the battle, I recovered the sword from the field. I bore it to Northrend in the service of my prince, seeking to avenge our people's defeat.",12,0,100,@EMOTE_KNEE,0,16803,"Blood Queen Lana'thel - Say 7"),
(@NPC_BLOOD_QUEEN_LANA_THEL,8,0,"Arthas shattered our forces and took the most powerful of us into his service as the San'layn.",12,0,100,@EMOTE_TALK,0,16804,"Blood Queen Lana'thel - Say 8"),
(@NPC_BLOOD_QUEEN_LANA_THEL,9,0,"My memories of Thalorien went cold and so did his blade.",12,0,100,@EMOTE_TALK,0,16805,"Blood Queen Lana'thel - Say 9"),
(@NPC_BLOOD_QUEEN_LANA_THEL,10,0,"It was I who brought Quel'Delar here,to return it to its makers. In breaking the weapon, so did I break its power.",12,0,100,@EMOTE_POINT,0,16806,"Blood Queen Lana'thel - Say 10"),
(@NPC_BLOOD_QUEEN_LANA_THEL,11,0,"Quel'Delar will never serve another!",12,0,100,5,0,16807,"Blood Queen Lana'thel - Say 11");
