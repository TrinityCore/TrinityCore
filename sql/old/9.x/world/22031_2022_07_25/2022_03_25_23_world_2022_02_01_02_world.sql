-- Generic

-- Spells with random texts
DELETE FROM `spell_script_names` WHERE `spell_id` = 50287 AND `ScriptName` = 'spell_q12372_azure_on_death_force_whisper';

DELETE FROM `spell_script_names` WHERE (
`spell_id` = 50037 AND `ScriptName` = 'spell_future_you_whisper_to_controller_random' OR
`spell_id` = 50287 AND `ScriptName` = 'spell_wyrmrest_defender_whisper_to_controller_random' OR
`spell_id` = 60709 AND `ScriptName` = 'spell_past_you_whisper_to_controller_random');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50037,'spell_future_you_whisper_to_controller_random'),
(50287,'spell_wyrmrest_defender_whisper_to_controller_random'),
(60709,'spell_past_you_whisper_to_controller_random');

-- Condition for Hourglass summon spell
-- "Places the Hourglass of Eternity on the ground at the Bronze Dragonshrine. Cannot be placed within 40 yards of another hourglass."
-- It casts Hourglass of Eternity Nearby which is SPELL_EFFECT_APPLY_AREA_AURA_FRIEND with radius 40 yards
-- So in condition we simply check if player has aura
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (49890,60808);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,49890,0,0,1,0,50867,0,0,1,0,0,"","Group 0: Spell 'Hourglass of Eternity' can be used if caster does not have aura 'Hourglass of Eternity Nearby'"),
(17,0,60808,0,0,1,0,50867,0,0,1,0,0,"","Group 0: Spell 'Hourglass of Eternity' can be used if caster does not have aura 'Hourglass of Eternity Nearby'");

-- Other generic spells
DELETE FROM `spell_script_names` WHERE (
`spell_id` = 49686 AND `ScriptName` = 'spell_moti_mirror_image_script_effect' OR
`spell_id` = 50020 AND `ScriptName` = 'spell_moti_hourglass_cast_see_invis_on_master');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(49686,'spell_moti_mirror_image_script_effect'),
(50020,'spell_moti_hourglass_cast_see_invis_on_master');


-- Summoned creatures
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (27896,27897,27898,27900,32352);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27896,27897,27898,27900,32352) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27896,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assailant - On AI Initialize - Set Corpse Delay"),
(27896,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Infinite Assailant - On Spawn - Start Attack Summoner"),
(27896,0,2,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Assailant - On Evade - Despawn"),

(27897,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Destroyer - On AI Initialize - Set Corpse Delay"),
(27897,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Infinite Destroyer - On Spawn - Start Attack Summoner"),
(27897,0,2,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Destroyer - On Evade - Despawn"),

(27898,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chrono-Magus - On AI Initialize - Set Corpse Delay"),
(27898,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Infinite Chrono-Magus - On Spawn - Start Attack Summoner"),
(27898,0,2,0,0,0,50,0,0,3000,10000,20000,0,11,38085,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Chrono-Magus - In Combat - Cast 'Shadow Blast'"),
(27898,0,3,0,0,0,50,0,0,3000,10000,20000,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Chrono-Magus - In Combat - Cast 'Shadow Bolt'"),
(27898,0,4,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Chrono-Magus - On Evade - Despawn"),

(27900,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Timerender - On AI Initialize - Set Corpse Delay"),
(27900,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Infinite Timerender - On Spawn - Start Attack Summoner"),
(27900,0,2,0,0,0,100,0,5000,10000,10000,15000,0,11,51020,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Timerender - In Combat - Cast 'Time Lapse'"),
(27900,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Timerender - On Evade - Despawn"),

(32352,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Timerender - On AI Initialize - Set Corpse Delay"),
(32352,0,1,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Infinite Timerender - On Spawn - Start Attack Summoner"),
(32352,0,2,0,0,0,100,0,5000,10000,10000,15000,0,11,51020,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinite Timerender - In Combat - Cast 'Time Lapse'"),
(32352,0,3,0,7,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinite Timerender - On Evade - Despawn");


-- Mystery of the Infinite

-- Hourglass of Eternity
UPDATE `creature_template` SET `unit_flags2` = 0 WHERE `entry` = 27840;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27840 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2784000,2784001) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27840,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On AI Initialize - Set Reactstate Passive"),
(27840,0,1,0,11,0,100,0,0,0,0,0,0,80,2784000,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Spawn - Run Script"),
-- Probably handled by spells, not sure how. Maybe first spell is casted by Hourglass and spell script forces
-- Hourglass' owner to cast second spell on self (like in 50020 > 50012 or other spell scripts for similar quests),
-- then spell script of second spell fails quest and maybe does something else (... despawns Future / Past You?)
-- 4330 > 4293 (Hourglass of Eternity Dies > Hourglass of Eternity Dies - Quest Fails)
-- 60839 > 60840 (Hourglass of Eternity Dies > Hourglass of Eternity Dies - Quest Fails)
(27840,0,2,0,6,0,100,0,0,0,0,0,0,6,12470,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Death - Fail Quest 'Mystery of the Infinite'"),

(2784000,9,0,0,0,0,100,0,0,0,0,0,0,11,49942,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Mystery of the Infinite: Force Cast to Player of Summon Future You'"),
(2784000,9,1,0,0,0,100,0,0,0,0,0,0,11,50057,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Mystery of the Infinite: Hourglass of Eternity Visual/Sound Aura'"),
(2784000,9,2,0,0,0,100,0,0,0,0,0,0,11,50867,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Hourglass of Eternity Nearby'"),
(2784000,9,3,0,0,0,100,0,0,0,0,0,0,11,23235,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Battle Standard Spawn'"),
-- Those summon spells are randomized, haven't found any spell which does that, unfortunately
(2784000,9,4,0,0,0,100,0,10000,10000,0,0,0,11,49900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Assailant'"),
(2784000,9,5,0,0,0,100,0,0,0,0,0,0,11,49901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Destroyer'"),
(2784000,9,6,0,0,0,100,0,30000,30000,0,0,0,11,49900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Assailant'"),
(2784000,9,7,0,0,0,100,0,0,0,0,0,0,11,49901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Destroyer'"),
(2784000,9,8,0,0,0,100,0,30000,30000,0,0,0,11,49902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Chrono-Magus'"),
(2784000,9,9,0,0,0,100,0,0,0,0,0,0,11,49902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Chrono-Magus'"),
(2784000,9,10,0,0,0,100,0,0,0,0,0,0,11,49901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Destroyer'"),
(2784000,9,11,0,0,0,100,0,30000,30000,0,0,0,11,49902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Chrono-Magus'"),
(2784000,9,12,0,0,0,100,0,0,0,0,0,0,11,49902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Chrono-Magus'"),
(2784000,9,13,0,0,0,100,0,0,0,0,0,0,11,49900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Assailant'"),
(2784000,9,14,0,0,0,100,0,40000,40000,0,0,0,11,49905,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Timerender'"),
-- Only in this version
(2784000,9,15,0,0,0,100,0,30000,30000,0,0,0,11,50020,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Mystery of the Infinite: Hourglass cast See Invis on Master'"),
(2784000,9,16,0,0,0,100,0,0,0,0,0,0,15,12470,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Quest Credit 'Mystery of the Infinite'"),
(2784000,9,17,0,0,0,100,0,10000,10000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Despawn");

-- Future You
DELETE FROM `creature_text` WHERE `CreatureID` = 27899;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27899,0,0,"Hey there, $n, don't be alarmed. It's me... you... from the future.  I'm here to help.",15,0,100,396,0,0,27239,0,"Future You"),
(27899,1,0,"Heads up... here they come. I'll help as much as I can. Let's just keep them off of the hourglass!",15,0,100,396,0,0,27251,0,"Future You"),
(27899,2,0,"I can't believe that I used to wear that.",15,0,100,0,0,0,27301,0,"Future You"),
(27899,2,1,"Look at you fight; no wonder I turned to drinking.",15,0,100,0,0,0,27304,0,"Future You"),
(27899,2,2,"What? Am I here alone. We both have a stake in this, you know!",15,0,100,0,0,0,27305,0,"Future You"),
(27899,2,3,"No matter what, you can't die, because that would mean that I would cease to exist, right? But, I was here before when I was you. I'm so confused!",15,0,100,0,0,0,27306,0,"Future You"),
(27899,2,4,"Wow, I'd forgotten how inexperienced I used to be.",15,0,100,0,0,0,27307,0,"Future You"),
(27899,2,5,"Sorry, but Chromie said that I couldn't reveal anything about your future to you. She said that if I did, I would cease to exist.",15,0,100,0,0,0,27311,0,"Future You"),
(27899,2,6,"Wish I could remember how many of the Infinite Dragonflight were going to try to stop you. This fight was so long ago.",15,0,100,0,0,0,27312,0,"Future You"),
(27899,2,7,"Listen. I'm not supposed to tell you this, but there's going to be this party that you're invited to. Whatever you do, DO NOT DRINK THE PUNCH!",15,0,100,0,0,0,27313,0,"Future You");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27899 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2789900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27899,0,0,0,11,0,100,0,0,0,0,0,0,80,2789900,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Spawn - Run Script"),
-- Stops casting that spell in outro event
-- Do not reset, always casted each 10 sec (AI works differently currently, cast may be delayed)
(27899,0,1,0,60,0,100,256,10000,10000,10000,10000,0,11,50037,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Update - Cast 'Mystery of the Infinite: Future You's Whisper to Controller - Random' (No Reset)"),

(2789900,9,0,0,0,0,100,0,0,0,0,0,0,11,49686,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Future You - On Script - Cast 'Mystery of the Infinite: Script Effect Player Cast Mirror Image'"),
(2789900,9,1,0,0,0,100,0,0,0,0,0,0,11,49925,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Script - Cast 'Mystery of the Infinite: Future You's Mirror Class Aura'"),
-- I guess both 49951 and 60806 periodically triggers 49953. Probably 49951 and 60806 has different periodic time.
-- Something like in 36504 & 36505 or another similar spells
-- Any way currently summons for some reason usually engage with Past\Future You and not with Hourglass,
-- ignoring on-spawn attack action (but only if Past\Future You is alive), weird
(2789900,9,2,0,0,0,100,0,0,0,0,0,0,11,49951,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Script - Cast 'Mystery of the Infinite: Future You's Periodic Threat'"),
(2789900,9,3,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Future You - On Script - Set Orientation Owner"),
(2789900,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Future You - On Script - Say Line 0"),
(2789900,9,5,0,0,0,100,0,6000,6000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Future You - On Script - Set Orientation Owner"),
(2789900,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Future You - On Script - Say Line 1"),
-- This outro event is weird. Despawn Timer aura has exactly 15 sec duration but doesn't simply despawn creature but executes the second
-- part after aura fades. Maybe first part is handled in AI by OnAuraApplied and part after 15 sec in OnAuraRemoved which
-- were implemented in WotLK.
-- It looks wrong to force creature execute this script in Hourglass' script because this script actually is executed slighly before
-- Hourglass awards quest credit. Something makes Hourglass' timers grow a little after each summon, making both scripts asunchronous,
-- makes me believe they are just two completely separate scripts. Hourglass' timers looks correct and too good to break them, quite smooth
-- values a designer wants to add when creating a script. Past / Future You timers are completely different:
-- 01:50:58.538 (summon) > 01:53:48.532 (outro). We'll simply execute this part right here after 160 sec. It can be executed
-- in combat (verified)
(2789900,9,7,0,0,0,100,0,160000,160000,0,0,0,11,50014,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Script - Cast 'Mystery of the Infinite: Future You's Whisper to Controller - Nozdormu'"),
(2789900,9,8,0,0,0,100,0,0,0,0,0,0,11,50022,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Script - Cast 'Mystery of the Infinite: Future You's Despawn Timer'"),
(2789900,9,9,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,27925,0,0,0,0,0,0,0,"Future You - On Script - Set Orientation Closest Creature 'Nozdormu'"),
(2789900,9,10,0,0,0,100,0,0,0,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Script - Play Emote 25"),
(2789900,9,11,0,0,0,100,0,15000,15000,0,0,0,11,50023,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Script - Cast 'Mystery of the Infinite: Future You's Whisper to Controller - Farewell'"),
(2789900,9,12,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Future You - On Script - Despawn");


-- Mystery of the Infinite, Redux

-- Hourglass of Eternity
UPDATE `creature_template` SET `unit_flags2` = 0 WHERE `entry` = 32327;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 32327 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3232700,3232701) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32327,0,0,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On AI Initialize - Set Reactstate Passive"),
(32327,0,1,0,11,0,100,0,0,0,0,0,0,80,3232700,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Spawn - Run Script"),
-- Probably handled by spells, not sure how. Maybe first spell is casted by Hourglass and spell script forces
-- Hourglass' owner to cast second spell on self (like in 50020 > 50012 or other spell scripts for similar quests),
-- then spell script of second spell fails quest and maybe does something else (... despawns Future / Past You?)
-- 4330 > 4293 (Hourglass of Eternity Dies > Hourglass of Eternity Dies - Quest Fails)
-- 60839 > 60840 (Hourglass of Eternity Dies > Hourglass of Eternity Dies - Quest Fails)
(32327,0,2,0,6,0,100,0,0,0,0,0,0,6,13343,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Death - Fail Quest 'Mystery of the Infinite, Redux'"),

(3232700,9,0,0,0,0,100,0,0,0,0,0,0,11,60790,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'MOTI, Redux: Force Cast to Player of Summon Past You'"),
(3232700,9,1,0,0,0,100,0,0,0,0,0,0,11,50057,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Mystery of the Infinite: Hourglass of Eternity Visual/Sound Aura'"),
(3232700,9,2,0,0,0,100,0,0,0,0,0,0,11,50867,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Hourglass of Eternity Nearby'"),
(3232700,9,3,0,0,0,100,0,0,0,0,0,0,11,23235,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Battle Standard Spawn'"),
-- Those summon spells are randomized, haven't found any spell which does that, unfortunately
(3232700,9,4,0,0,0,100,0,10000,10000,0,0,0,11,49900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Assailant'"),
(3232700,9,5,0,0,0,100,0,0,0,0,0,0,11,49901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Destroyer'"),
(3232700,9,6,0,0,0,100,0,30000,30000,0,0,0,11,49900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Assailant'"),
(3232700,9,7,0,0,0,100,0,0,0,0,0,0,11,49901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Destroyer'"),
(3232700,9,8,0,0,0,100,0,30000,30000,0,0,0,11,49902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Chrono-Magus'"),
(3232700,9,9,0,0,0,100,0,0,0,0,0,0,11,49902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Chrono-Magus'"),
(3232700,9,10,0,0,0,100,0,0,0,0,0,0,11,49901,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Destroyer'"),
(3232700,9,11,0,0,0,100,0,30000,30000,0,0,0,11,49902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Chrono-Magus'"),
(3232700,9,12,0,0,0,100,0,0,0,0,0,0,11,49902,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Chrono-Magus'"),
(3232700,9,13,0,0,0,100,0,0,0,0,0,0,11,49900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Assailant'"),
(3232700,9,14,0,0,0,100,0,40000,40000,0,0,0,11,60887,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Cast 'Summon Infinite Timerender'"),
(3232700,9,15,0,0,0,100,0,30000,30000,0,0,0,15,13343,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Quest Credit 'Mystery of the Infinite, Redux'"),
(3232700,9,16,0,0,0,100,0,10000,10000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hourglass of Eternity - On Script - Despawn");

-- Past You
DELETE FROM `creature_text` WHERE `CreatureID` = 32331;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(32331,0,0,"Whoa! You're me, but from the future!  Hey, my equipment got an upgrade.  Cool!",15,0,100,25,0,0,32764,0,"Past You"),
(32331,1,0,"Here come the Infinites!  I've got to keep the hourglass safe.  Can you help?",15,0,100,6,0,0,32769,0,"Past You"),
(32331,2,0,"This equipment looks cool and all, but couldn't we have done a little better?  Are you even raiding?",15,0,100,0,0,0,32770,0,"Past You"),
(32331,2,1,"So, how does it all turn out in Icecrown?",15,0,100,0,0,0,32771,0,"Past You"),
(32331,2,2,"Chromie said that if I don't do this just right, I might wink out of existence.  If I go, then you go!",15,0,100,0,0,0,32772,0,"Past You"),
(32331,2,3,"Looks like I'm an underachiever.",15,0,100,0,0,0,32773,0,"Past You"),
(32331,2,4,"I think I'm going to turn to drinking after this.",15,0,100,0,0,0,32774,0,"Past You"),
(32331,2,5,"It might help if you could tell me how many of these guys we're going to fight.  You can remember that, right, grandpa?",15,0,100,0,0,0,32775,0,"Past You"),
(32331,2,6,"I just want you to know that if we get through this alive, I'm making sure that we turn out better than you.  No offense.",15,0,100,0,0,0,32776,0,"Past You"),
(32331,2,7,"Wait a minute!  If you're here, then that means that in the not-so-distant future I'm going to be you helping me?  Are we stuck in a time loop?!",15,0,100,0,0,0,32777,0,"Past You");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 32331 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3233100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32331,0,0,0,11,0,100,0,0,0,0,0,0,80,3233100,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Spawn - Run Script"),
-- Stops casting that spell in outro event
-- Do not reset, always casted each 10 sec (AI works differently currently, cast may be delayed)
(32331,0,1,0,60,0,100,256,10000,10000,10000,10000,0,11,60709,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Update - Cast 'MOTI, Redux: Past You's Whisper to Controller - Random' (No Reset)"),

(3233100,9,0,0,0,0,100,0,0,0,0,0,0,11,49686,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Past You - On Script - Cast 'Mystery of the Infinite: Script Effect Player Cast Mirror Image'"),
(3233100,9,1,0,0,0,100,0,0,0,0,0,0,11,49925,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Script - Cast 'Mystery of the Infinite: Future You's Mirror Class Aura'"),
-- I guess both 49951 and 60806 periodically triggers 49953. Probably 49951 and 60806 has different periodic time.
-- Something like in 36504 & 36505 or another similar spells
-- Any way currently summons for some reason usually engage with Past\Future You and not with Hourglass,
-- ignoring on-spawn attack action (but only if Past\Future You is alive), weird
(3233100,9,2,0,0,0,100,0,0,0,0,0,0,11,60806,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Script - Cast 'MOTI, Redux: Past You's Periodic Threat'"),
(3233100,9,3,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Past You - On Script - Set Orientation Owner"),
(3233100,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Past You - On Script - Say Line 0"),
(3233100,9,5,0,0,0,100,0,6000,6000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Past You - On Script - Set Orientation Owner"),
(3233100,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Past You - On Script - Say Line 1"),
-- This outro event is weird. Despawn Timer aura has exactly 15 sec duration but doesn't simply despawn creature but executes the second
-- part after aura fades. Maybe first part is handled in AI by OnAuraApplied and part after 15 sec in OnAuraRemoved which
-- were implemented in WotLK.
-- It looks wrong to force creature execute this script in Hourglass' script because this script actually is executed slighly before
-- Hourglass awards quest credit. Something makes Hourglass' timers grow a little after each summon, making both scripts asunchronous,
-- makes me believe they are just two completely separate scripts. Hourglass' timers looks correct and too good to break them, quite smooth
-- values a designer wants to add when creating a script. Past / Future You timers are completely different:
-- 01:50:58.538 (summon) > 01:53:48.532 (outro). We'll simply execute this part right here after 160 sec. It can be executed
-- in combat (verified)
(3233100,9,7,0,0,0,100,0,160000,160000,0,0,0,11,60807,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Script - Cast 'MOTI, Redux: Past You's Whisper to Controller - Nozdormu'"),
(3233100,9,8,0,0,0,100,0,0,0,0,0,0,11,60812,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Script - Cast 'MOTI, Redux: Past You's Despawn Timer'"),
(3233100,9,9,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,27925,0,0,0,0,0,0,0,"Past You - On Script - Set Orientation Closest Creature 'Nozdormu'"),
(3233100,9,10,0,0,0,100,0,0,0,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Script - Play Emote 25"),
(3233100,9,11,0,0,0,100,0,15000,15000,0,0,0,11,60811,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Script - Cast 'MOTI, Redux: Past You's Whisper to Controller - Farewell'"),
(3233100,9,12,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Past You - On Script - Despawn");
