/*
0x280000003457D30 --ascee guid
21:30:42.067 -- setting up trap
21:30:42.878 -- magma trap vehicle
-- Trap Bunny
21:30:46.092 -- spawn vents
21:30:48.900 -- move down to  -205.7569 Y: -579.0972 Z: 35.98623
21:30:48.900 -- click me
21:30:49.103 -- "aktiviert die ventile um euch zu befreien"
21:30:49.695 -- spellclick  steam vent  92399 (Steam Vent)
21:30:50.897 -- fall down
21:30:50.897 -- magma trap throw
21:31:00.990 -- vents despawn
21:30:54.937 -- nightmare slow
21:30:55.140 -- announce the nightmare elixir
21:30:55.779 -- spawn vanessa and glubtok fire bunnies  0xF130C207000044F2    48143 (Forgotten Aura)
21:30:55.779 -- glubtok spawn (with Forgotten Aura 48143) and 69676 (Cosmetic - Alpha State 50%)
21:30:55.779 -- fire bunnies activate
21:30:56.747 -- poor glubtok- when his power manifested
21:31:05.171 -- fear himself
21:31:09.788 -- nightmare auras
21:31:09.991 -- you have entered glubtoks nighmare!
21:31:10.194 -- summon real glubtok to battle
21:31:14.811 -- get back tot he ship
21:31:17.323 -- despawn vanessa
21:31:17.323 -- glubtok despawn????
21:31:41.066 -- glubtok death
21:31:43.952 -- nightmare aura  92563
21:31:44.155 -- the nightmare shifts
21:31:44.342 -- despawn fires
21:31:47.166 -- helix summoned
21:31:48.211 -- die meisten schurken -
21:31:54.217 -- but you never know
21:31:58.819 -- cancel nightmare aura
21:31:58.819 -- nightmare aura helix
21:32:02.548 -- despawn vanessa
21:32:05.044 -- helix says: ihr habt helix' apltraum betreten
21:32:05.652 -- nightmare skitterling spawns
21:32:07.462 -- nightmare spiders spawn announcement
21:32:36.634 -- helix death 
21:32:38.646 -- spiders despawn
21:32:38.740 -- announce nightmare changes
21:32:38.990 -- nightmare aura + nightmare slow
21:32:42.188 -- helix despawn


21:32:41.376 -- open foundry door + vanessa spawns
21:32:42.406 -- könnt ihr euch?
21:32:46.010 -- ein einzelner funke
21:32:49.410 -- cancel nightmare aura
21:32:49.426 -- nightmare aura foe reaper
21:32:49.816 -- real foe reaper

21:32:49.629 -- ihr habt den mechanischen
21:32:51.891 -- vanessa despawn
21:32:51.891
*/


-- Template Updates
-- Vanessa VanCleef
UPDATE `creature_template` SET `ScriptName`= 'boss_vanessa_van_cleef' WHERE `entry`= 49541;
-- Vanessa VanCleef (Intro)
UPDATE `creature_template` SET `ScriptName`= 'npc_vanessa_vanessa_van_cleef' WHERE `entry`= 49429;
-- A Note from Vanessa
UPDATE `creature_template` SET `gossip_menu_id`= 12504, `ScriptName`= 'npc_vanessa_note_from_vanessa' WHERE `entry`= 49564;
-- Magma Trap creatures
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (49454, 51624);
-- Vanessa's Trap Bunny
UPDATE `creature_template` SET `ScriptName`= 'npc_deadmines_vanessas_trap_bunny' WHERE `entry`= 49454;
-- Steam Valve
UPDATE `creature_template` SET `npcflag`= 16777216, `ScriptName`= 'npc_deadmines_steam_valve' WHERE `entry`= 49457;
-- Vanessa VanCleef Nightmare
UPDATE `creature_template` SET `ScriptName`= 'npc_deadmines_vanessa_van_cleef_nightmare' WHERE `entry`= 49671;
-- Glubtok Nightmare Fire Bunny
UPDATE `creature_template` SET `flags_extra`= 131 WHERE `entry`= 51594;
-- Collapsing Icicle
UPDATE `creature_template` SET `unit_flags`= 33587200, `flags_extra`= 131 WHERE `entry` IN (49481, 57866);
-- Glubtok Nightmare Illusion
UPDATE `creature_template` SET `ScriptName`= 'npc_deadmines_glubtok_nightmare' WHERE `entry`= 49670;
-- Helix Gearbreaker Illusion
UPDATE `creature_template` SET `unit_flags`= 33600, `ScriptName`= 'npc_deadmines_helix_nightmare' WHERE `entry`= 49674;
-- Lightning Platters
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 128 WHERE `entry` IN (49520, 49521);

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (49564, 51594, 49671, 49670, 92201);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `auras`) VALUES
(49564, 0, '92376'),
(51594, 0, '92169'),
(49671, 0, '48143'),
(49670, 0, '48143 69676');

UPDATE `creature_template_addon` SET `auras`= '94557' WHERE `entry`= 49457;

-- Remove encounter related spawns
DELETE FROM `creature` WHERE `guid` IN (376214, 376211, 376215, 376213);

-- Gossip
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=12504 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`) VALUES
(12504, 0, 0, 'Continue reading... <Note: This will alert Vanessa to your presence!>', 49641, 1, 1, 12505);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (49429, 49564, 49454, 49671, 49674);
DELETE FROM `creature_text` WHERE `CreatureID`= 45979 AND `GroupID` NOT IN (0, 1, 2, 3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
-- Vanessa VanCleef Intro
(49429, 0, 0, 'You hear a noise from above the cabin door!', 41, 0, 100, 0, 0, 0, 49476, 'Vanessa van Cleef to Player'),
(49429, 1, 0, 'I''ve been waiting a long time for this, you know.', 12, 0, 100, 1, 0, 24613, 49477, 'Vanessa van Cleef to Player'),
(49429, 2, 0, 'Biding my time, building my forces, studying the minds of my enemies.', 12, 0, 100, 1, 0, 24614, 49478, 'Vanessa van Cleef to Player'),
(49429, 3, 0, 'I was never very good at hand-to-hand combat, you know.  Not like my father.', 12, 0, 100, 1, 0, 24615, 49479, 'Vanessa van Cleef to Player'),
(49429, 4, 0, 'But I always excelled at poisons.', 12, 0, 100, 1, 0, 24616, 49480, 'Vanessa van Cleef to Player'),
(49429, 5, 0, 'Especially venoms that affect the mind.', 12, 0, 100, 1, 0, 24617, 49481, 'Vanessa van Cleef to Player'),
(49429, 6, 0, 'Vanessa injects you with the Nightmare Elixir!', 41, 0, 100, 0, 0, 0, 49483, 'Vanessa van Cleef to Player'),
-- A Note from Vanessa VanCleef
(49564, 0, 0, 'A note falls to the floor!', 41, 0, 100, 0, 0, 0, 49658, 'A Note from Vanessa to Player'),
-- Vanessa's Trap Bunny
(49454, 0, 0, 'Activate the steam valves to free yourself!', 41, 0, 100, 0, 0, 0, 49680, 'Vanessa''s Trap Bunny to Player'),
-- General Purpose Bunny JMF
(45979, 4, 0, 'The Nightmare Elixir takes hold!', 41, 0, 100, 0, 0, 0, 49705, 'General Purpose Bunny JMF to Steam Valve'),
(45979, 5, 0, 'The nightmare shifts!', 41, 0, 100, 0, 0, 0, 49707, 'General Purpose Bunny JMF to Player'),
-- Helix Gearbreaker
(49674, 0, 0, 'You have entered Helix''s nightmare!', 41, 0, 100, 0, 0, 0, 49708, 'Helix Gearbreaker to Player'),
(49674, 1, 0, 'Nightmare spiders appear in the darkness!  Kill Helix before his nightmare overwhelms you!', 41, 0, 100, 0, 0, 0, 50871, 'Helix Geabreaker to Player'),
-- Vanessa VanCleef Nightmare
(49671, 0, 0, 'Poor Glubtok.  When his powers manifested, his own ogre mound was the first to burn.', 12, 0, 100, 1, 0, 24602, 49715, 'Vanessa van Cleef to Steam Valve'),
(49671, 1, 0, 'Deep within his soul, the one thing he feared most of all was...himself.', 12, 0, 100, 1, 0, 24603, 49716, 'Vanessa van Cleef to Steam Valve'),
(49671, 2, 0, 'You have entered Glubtok''s Nightmare!', 41, 0, 100, 0, 0, 0, 49706, 'Vanessa van Cleef to Steam Valve'),
(49671, 3, 0, 'Get back to the ship!', 41, 0, 100, 0, 0, 0, 50703, 'Vanessa van Cleef to Steam Valve'),
(49671, 4, 0, 'Most rogues prefer to cloak themselves in the shadows, but not Helix.', 12, 0, 100, 1, 0, 24604, 49723, 'Vanessa van Cleef to Player'),
(49671, 5, 0, 'You never know what skitters in the darkness.', 12, 0, 100, 1, 0, 24605, 49724, 'Vanessa van Cleef to Player'),
(49671, 6, 0, 'Can you imagine the life of a machine?', 12, 0, 100, 1, 0, 24606, 49725, 'Vanessa van Cleef to Player'),
(49671, 7, 0, 'A simple spark can mean the difference between life...and death.', 12, 0, 100, 1, 0, 24607, 49726, 'Vanessa van Cleef to Player'),
(49671, 8, 0, 'You have entered the mechanical nightmare!', 41, 0, 100, 0, 0, 0, 49709, 'Vanessa van Cleef to Player');

UPDATE `creature_template` SET `npcflag`= 16777216 WHERE `entry`= 49520;

-- Vehicle Acessory
DELETE FROM `vehicle_template_accessory` WHERE `entry`= 49520;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(49520, 49521, 7, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 6, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 5, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 4, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 3, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 2, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 1, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0), -- Vanessa Lightning Platter - Vanessa Lightning Stalker
(49520, 49521, 0, 1, 'Vanessa Lightning Platter - Vanessa Lightning Stalker', 5, 0); -- Vanessa Lightning Platter - Vanessa Lightning Stalker

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_deadmines_ride_magma_vehicle',
'spell_deadmines_magma_trap_throw_to_location');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(92378, 'spell_deadmines_ride_magma_vehicle'),
(92438, 'spell_deadmines_magma_trap_throw_to_location');

-- Spellclick spells
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (49457);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
-- Steam Valve
(49457, 92399, 0, 0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (92379) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 92379, 0, 0, 31, 0, 3, 49454, 0, 0, 0, '', 'Ride Magma Vehicle - Vanessa''s Trap Bunny');

-- Creature Collapsing Icicle 49481 SAI
SET @ENTRY := 49481;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 3, 0, 28470, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Morph to model 28470 // "),
(@ENTRY, 0, 1, 2, 60, 0, 100, 1, 3200, 3200, 0, 0, 11, 92201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 3200 and 3200 ms) - Self: Cast spell Icicle (92201) on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 92202, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Icicle (92202) on Self // ");



/*
(49454, @GROUP_ID+0, @ID+, 'Aktiviert die Dampfventile, um Euch zu befreien!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Vanessa''s Trap Bunny to Player'),
(49536, @GROUP_ID+0, @ID+, 'James... bitte... Ich liebe dich...', 12, 0, 100, 0, 0, 0, UNKNOWN, 'Calissa Harrington'),
(49536, @GROUP_ID+1, @ID+, 'Calissa stirbt!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Calissa Harrington'),
(49539, @GROUP_ID+0, @ID+, 'Calissa... Es tut mir so leid...', 12, 0, 100, 0, 0, 0, UNKNOWN, 'James Harrington'),
(49541, @GROUP_ID+0, @ID+, 'Ich werde meines Vaters Schicksal nicht teilen! Eure Geschichte endet hier!', 14, 0, 100, 0, 0, 24599, UNKNOWN, 'Vanessa van Cleef to Player'),
(49541, @GROUP_ID+1, @ID+, 'Habt Ihr wirklich gedacht, ich würde allein zu diesem Kampf erscheinen?', 14, 0, 100, 0, 0, 24620, UNKNOWN, 'Vanessa van Cleef'),
(49541, @GROUP_ID+2, @ID+, 'Narren! Hahahah! Das ganze Schiff ist mit Sprengstoff gespickt! Erfreut Euch an Eurem feurigen Tod!', 14, 0, 100, 0, 0, 24621, UNKNOWN, 'Vanessa van Cleef'),
(49541, @GROUP_ID+3, @ID+, 'Vanessa hat Sprengladungen auf dem Schiff detonieren lassen! Los, schnell zu den Seilen an Steuerbord!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Vanessa van Cleef'),
(49541, @GROUP_ID+4, @ID+, 'Ha! Ihr hattet doch nicht wirklich gedacht, dass ich nur EINE Reihe Sprengstoff legen würde, oder?', 14, 0, 100, 0, 0, 24622, UNKNOWN, 'Vanessa van Cleef'),
(49541, @GROUP_ID+5, @ID+, 'Vanessa lässt weitere Sprengsätze detonieren! Los, schnell zu den Seilen an Steuerbord!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Vanessa van Cleef'),
(49541, @GROUP_ID+6, @ID+, 'GENUG! Diese Freude werde ich Euch nicht machen!', 14, 0, 100, 274, 0, 24610, UNKNOWN, 'Vanessa van Cleef'),
(49541, @GROUP_ID+7, @ID+, 'Wenn ich schon sterbe, werde ich Euch alle mitnehmen!', 14, 0, 100, 15, 0, 24611, UNKNOWN, 'Vanessa van Cleef'),
(49541, @GROUP_ID+8, @ID+, 'Vanessa zieht ein letztes Fass mit Bergbausprengstoff hervor und entzündet es! RENNT!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Vanessa van Cleef'),
(49541, @GROUP_ID+9, @ID+, 'ÜBER MEIN SCHICKSAL ENTSCHEIDE NUR ICH!', 14, 0, 100, 397, 0, 24612, UNKNOWN, 'Vanessa van Cleef'),
(49564, @GROUP_ID+0, @ID+, 'Eine Notiz fällt zu Boden!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Eine Nachricht von Vanessa to Player'),
(49671, @GROUP_ID+0, @ID+, 'Armer Glubtok. Als sich seine Kräfte manifestierten, war sein Ogerhort der erste, der brannte.', 12, 0, 100, 1, 0, 24602, UNKNOWN, 'Vanessa van Cleef to Dampfventil'),
(49671, @GROUP_ID+1, @ID+, 'In den Tiefen seiner Seele war das, was er am meisten fürchtete... er selbst.', 12, 0, 100, 1, 0, 24603, UNKNOWN, 'Vanessa van Cleef to Dampfventil'),
(49671, @GROUP_ID+2, @ID+, 'Ihr habt Glubtoks Alptraum betreten!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Vanessa van Cleef to Dampfventil'),
(49671, @GROUP_ID+3, @ID+, 'Geht zum Schiff zurück!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Vanessa van Cleef to Dampfventil'),
(49671, @GROUP_ID+4, @ID+, 'Die meisten Schurken bevorzugen die Schatten, Helix jedoch nicht.', 12, 0, 100, 1, 0, 24604, UNKNOWN, 'Vanessa van Cleef to Player'),
(49671, @GROUP_ID+5, @ID+, 'Man weiß nie, was in der Dunkelheit rumkriecht.', 12, 0, 100, 1, 0, 24605, UNKNOWN, 'Vanessa van Cleef to Player'),
(49671, @GROUP_ID+6, @ID+, 'Könnt Ihr Euch das Leben einer Maschine vorstellen?', 12, 0, 100, 1, 0, 24606, UNKNOWN, 'Vanessa van Cleef to Player'),
(49671, @GROUP_ID+7, @ID+, 'Ein einzelner Funke... kann den Unterschied zwischen Leben und Tod ausmachen.', 12, 0, 100, 1, 0, 24607, UNKNOWN, 'Vanessa van Cleef to Player'),
(49671, @GROUP_ID+8, @ID+, 'Ihr habt den mechanischen Alptraum betreten!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Vanessa van Cleef to Player'),
(49671, @GROUP_ID+9, @ID+, 'Knurrreißer war nicht immer ein blutrünstiger Wilder. Er hatte früher sogar mal eine Familie.', 12, 0, 100, 1, 0, 24608, UNKNOWN, 'Vanessa van Cleef to Player'),
(49671, @GROUP_ID+10, @ID+, 'Sein Name war James Harrington. Eine Tragödie in drei Akten.', 12, 0, 100, 1, 0, 24609, UNKNOWN, 'Vanessa van Cleef to Player'),
(49671, @GROUP_ID+11, @ID+, 'Ihr habt Knurrreißers Alptraum betreten!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Vanessa van Cleef to Player'),
(49674, @GROUP_ID+0, @ID+, 'Ihr habt Helix'' Alptraum betreten!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Helix Ritzelbrecher to Player'),
(49674, @GROUP_ID+1, @ID+, 'Alptraumspinnen erscheinen in der Finsternis! Tötet Helix, bevor sein Alptraum Euch überwältigt!', 41, 0, 100, 0, 0, 0, UNKNOWN, 'Helix Ritzelbrecher to Player');
*/