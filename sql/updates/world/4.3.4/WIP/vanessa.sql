/*
21:29:47.825 -- cookie dead
21:29:47.420 -- a note from vanessa spawns
21:29:52.459 -- a note falls to the ground emote


21:29:53.722 -- gossip hello
21:29:55.891 -- select menu
21:30:02.677 -- despawn note

21:29:56.655 -- vanessa spawns  0xF130C11500004444
21:29:56.655 -- sittin aura
21:29:59.276 -- ihr hört ein geräusch von oberhalb announcement
21:30:02.895 -- hierauf habe ich lange gewartet
21:30:05.095 -- remove sitting / jump to  -64.5677 Y: -820.161 Z: 41.123 // speed z = 16.31084
21:30:13.519 -- move to intro pos
21:30:13.768 -- ich habe mir zeit gelassen
21:30:23.394 -- ich war nie sehr gut, im gesegensatz...
21:30:29.212 -- facing to 1.53589
21:30:29.431 -- aber mit giften war ich immer
21:30:31.630 -- 92100 (Noxious Concoction)
21:30:34.220 -- vor allem mit giften, die den geist beeinflussen
21:30:38.853 -- 92113 (Nightmare Elixir)
21:30:38.853 -- 92120 (Vanessa's Blackout Aura)
21:30:39.087 -- announce nightmare
21:30:41.256 -- emote 392
21:30:46.092 -- despawn
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


-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (49564);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `auras`) VALUES
(49564, 0, 92376);

UPDATE `creature_template_addon` SET `auras`= '94557' WHERE `entry`= 49457;

-- Remove encounter related spawns
DELETE FROM `creature` WHERE `guid` IN (376214, 376211, 376215, 376213);

-- Gossip
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=12504 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`) VALUES
(12504, 0, 0, 'Continue reading... <Note: This will alert Vanessa to your presence!>', 49641, 1, 1, 12505);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (49429, 49564, 49454);
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
(49454, 0, 0, 'Activate the steam valves to free yourself!', 41, 0, 100, 0, 0, 0, 49680, 'Vanessa''s Trap Bunny to Player');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_deadmines_ride_magma_vehicle');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(92378, 'spell_deadmines_ride_magma_vehicle');

-- Spellclick spells
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (49457);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
-- Steam Valve
(49457, 92399, 0, 0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (92379) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 92379, 0, 0, 31, 0, 3, 49454, 0, 0, 0, '', 'Ride Magma Vehicle - Vanessa''s Trap Bunny');

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