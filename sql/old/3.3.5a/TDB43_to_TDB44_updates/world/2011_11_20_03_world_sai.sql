-- [Q] Hard to Swallow

-- Hulking Jormungar SAI
SET @ENTRY := 26293;
SET @SPELL_CORROSIVE_POISON := 50293;
SET @SPELL_GRENADE := 47305;
SET @SPELL_EXPLOSION := 47311;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,7000,11000,13000,11,@SPELL_CORROSIVE_POISON,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hulking Jormungar - In Combat - Cast Corrode Flesh"),
(@ENTRY,0,1,0,2,0,100,1,0,80,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Hulking Jormungar - At 80% HP - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hulking Jormungar - On Script - Say Line 0"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hulking Jormungar - On Script - Set Phase 1"),
(@ENTRY*100,9,2,0,0,0,100,0,5000,5000,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hulking Jormungar - On Script - Set Phase 0"),
(@ENTRY,0,2,0,8,1,100,0,@SPELL_GRENADE,0,0,0,80,@ENTRY*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"Hulking Jormungar - On Spellhit (P1) - Run Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,3000,3000,0,0,11,@SPELL_EXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hulking Jormungar - On Script - Cast Quest - Jormungar Explosion Spell Spawner"),
(@ENTRY*100+1,9,1,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hulking Jormungar - On Script - Die");

-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The Hulking Jormungar falters for a moment, opening its mouth wide.",41,0,100,0,0,0,"Hulking Jormungar");

-- Potent Explosive Charge conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@SPELL_GRENADE;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,@SPELL_GRENADE,0,18,1,@ENTRY,0,0,'',"Potent Explosive Charge only targets Hulking Jormungar"),
(13,0,@SPELL_GRENADE,0,20,80,0,0,0,'',"Potent Explosive Charge requires target to be below 80% HP");

-- Quest - Jormungar Explosion Spell Spawner triggers the meat throw spells
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=@SPELL_EXPLOSION;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(@SPELL_EXPLOSION,47925,0,"Quest - Jormungar Explosion Spell Spawner triggers Quest - Jormungar Explosion Summon Object"),
(@SPELL_EXPLOSION,47924,0,"Quest - Jormungar Explosion Spell Spawner triggers Quest - Jormungar Explosion Summon Object"),
(@SPELL_EXPLOSION,47309,0,"Quest - Jormungar Explosion Spell Spawner triggers Quest - Jormungar Explosion Summon Object");

-- Jormungar Meat SAI
SET @ENTRY := 26699;
UPDATE `creature_template` SET `AIname`='SmartAI',`unit_flags`=`unit_flags`|33554432,`flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,50,188434,120000,0,0,0,0,1,0,0,0,0,0,0,0,"Jormungar Meat - Just Summoned - Summon Jormungar Meat");

-- Give Jormungar Meat quest item loot
DELETE FROM `gameobject_loot_template` WHERE `entry`=23442;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(23442,36731,-100,1,0,1,1);
