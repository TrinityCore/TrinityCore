-- EoE correct areatrigger_teleport coords
UPDATE `areatrigger_teleport` SET `target_position_x` = 726.68 , `target_position_y` = 1330.17, `target_position_z` = 267.23, `target_orientation` = 5.37 WHERE `id` = 5290;

-- Delete vehicle template accessory for scions and nexus lords, we'll use a hacky way to handle this
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (30234, 30248);

-- event triggered by opening focusing iris
INSERT INTO event_scripts (id, delay, command, datalong, datalong2, dataint) VALUES
(20711,0,15,61012,1,0);
-- or (20711,0,15,61012,4,28859);


-- Malygos 25men
UPDATE creature_template SET difficulty_entry_1=31734 WHERE entry=28859;
UPDATE creature_template SET flags_extra=flags_extra|1, dmg_multiplier=70 WHERE entry=31734;
UPDATE creature_template SET mechanic_immune_mask=617299803 WHERE entry IN (28859, 31734);

UPDATE `creature_model_info` SET `combat_reach`=15 WHERE `modelid`=26752; -- 20


-- vehicleIDs are in TDB 
-- Add missing vehicle id to NPC Hover Disc (ID: 30234)
UPDATE `creature_template` SET `VehicleId`=283 WHERE `entry`=30234; 
-- Add missing vehicle id to NPC Hover Disc (ID: 30248)
UPDATE `creature_template` SET `VehicleId`=223 WHERE `entry`=30248;

-- but not for 25men
UPDATE `creature_template` SET `VehicleId`=283 WHERE `entry`=31748;
UPDATE `creature_template` SET `VehicleId`=223 WHERE `entry`=31749;

-- make hover disks selectable & flyable
UPDATE `creature_template` SET unit_flags=unit_flags&~0x02000000,InhabitType=5 WHERE `entry` IN (30234,30248,31748,31749); -- 33554432,3

-- Set instance script
UPDATE instance_template SET script = 'instance_eye_of_eternity' WHERE map = 616;

-- Update flags for NPCs/Vehicles
UPDATE creature_template SET flags_extra=flags_extra|2|128 WHERE entry = 30090; -- Vortex
UPDATE creature_template SET flags_extra=flags_extra|2 WHERE entry IN (30234, 30248); -- Hover Disk (VehicleId 264)
UPDATE creature_template SET flags_extra=flags_extra|2|128, InhabitType=4 /*, faction_A = 35, faction_H = 35*/ WHERE entry = 30118; -- Portal (Malygos)
UPDATE creature_template SET flags_extra=flags_extra|2 WHERE entry = 30282; -- Arcane Overload
UPDATE creature_template SET flags_extra=flags_extra|128 WHERE entry = 30334; -- Surge of Power
UPDATE creature_template SET flags_extra=flags_extra|128 WHERE entry = 31253; -- Alextrasza (trigger)
UPDATE creature_template SET flags_extra=flags_extra|128, InhabitType=4 WHERE entry = 30592; -- Static Field

-- Set scriptnames and some misc data to bosses and GOs
UPDATE creature_template SET ScriptName = 'boss_malygos'/*, unit_flags = unit_flags & ~256*/ WHERE entry = 28859;
UPDATE creature SET MovementType = 0, spawndist = 0 WHERE id = 28859; -- Malygos, don't move
UPDATE creature_template SET ScriptName = 'mob_nexus_lord' WHERE entry = 30245; -- Nexus Lord
UPDATE creature_template SET ScriptName = 'mob_scion_of_eternity' WHERE entry = 30249; -- Scion of Eternity
UPDATE creature_template SET ScriptName = 'mob_power_spark' WHERE entry = 30084; -- Power Spark
UPDATE creature_template SET ScriptName = 'npc_arcane_overload' WHERE entry = 30282; -- Arcane Overload

-- Fix Wyrmrest drakes creature info
UPDATE creature_template SET spell1 = 56091, spell2 = 56092, spell3 = 57090, spell4 = 57143, spell5 = 57108, spell6 = 57403, VehicleId = 220/*165*/ WHERE entry IN (30161, 31752); -- 220 is from TDB

-- Delete faulty Alextrasza spawn
DELETE FROM creature WHERE guid = 132302 AND id=31253; 
DELETE FROM creature_addon WHERE guid=132302;

-- And Surge of Power
DELETE FROM creature WHERE guid = 132303 AND id=30334;
DELETE FROM creature_addon WHERE guid=132303;

-- Fix Surge of Power targeting
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 13 AND SourceEntry = 56505;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, ErrorTextId, COMMENT) VALUES
(13, 0, 56505, 0, 18, 1, 22517, 0, 0, 'Surge of Power - cast only on World Trigger (Large AOI)');

-- Fix loot for Malygos (Alexstrasza's Gift)
DELETE FROM reference_loot_template WHERE entry = 50008;
INSERT INTO reference_loot_template (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(50008, 40474, 0, 1, 1, 1, 1), -- Surge Needle Ring
(50008, 40497, 0, 1, 1, 1, 1), -- Black Ice
(50008, 40489, 0, 1, 1, 1, 1), -- Greatstaff of the Nexus
(50008, 40526, 0, 1, 1, 1, 1), -- Gown of the Spell-Weaver
(50008, 40511, 0, 1, 1, 1, 1), -- Focusing Energy Epaulets
(50008, 40475, 0, 1, 1, 1, 1), -- Barricade of Eternity
(50008, 40488, 0, 1, 1, 1, 1), -- Ice Spire Scepter
(50008, 40491, 0, 1, 1, 1, 1), -- Hailstorm
(50008, 40519, 0, 1, 1, 1, 1), -- Footsteps of Malygos
(50008, 40486, 0, 1, 1, 1, 1); -- Necklace of the Glittering Chamber

DELETE FROM reference_loot_template WHERE entry = 50009;
INSERT INTO reference_loot_template (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(50009, 40592, 0, 1, 1, 1, 1), -- Boots of Healing Energies
(50009, 40566, 0, 1, 1, 1, 1), -- Unravelling Strands of Sanity
(50009, 40194, 0, 1, 1, 1, 1), -- Blanketing Robes of Snow
(50009, 40543, 0, 1, 1, 1, 1), -- Blue Aspect Helm
(50009, 40590, 0, 1, 1, 1, 1), -- Elevated Lair Pauldrons
(50009, 40560, 0, 1, 1, 1, 1), -- Leggings of the Wanton Spellcaster
(50009, 40589, 0, 1, 1, 1, 1), -- Legplates of Sovereignty
(50009, 40555, 0, 1, 1, 1, 1), -- Mantle of Dissemination
(50009, 40591, 0, 1, 1, 1, 1), -- Melancholy Sabatons
(50009, 40594, 0, 1, 1, 1, 1), -- Spaulders of Catatonia
(50009, 40588, 0, 1, 1, 1, 1), -- Tunic of the Artifact Guardian
(50009, 40549, 0, 1, 1, 1, 1), -- Boots of the Renewed Flight
(50009, 40539, 0, 1, 1, 1, 1), -- Chestguard of the Recluse
(50009, 40541, 0, 1, 1, 1, 1), -- Frosted Adroit Handguards
(50009, 40562, 0, 1, 1, 1, 1), -- Hood of Rationality
(50009, 40561, 0, 1, 1, 1, 1), -- Leash of Heedless Magic
(50009, 40532, 0, 1, 1, 1, 1), -- Living Ice Crystals
(50009, 40531, 0, 1, 1, 1, 1), -- Mark of Norgannon
(50009, 40564, 0, 1, 1, 1, 1), -- Winter Spectacle Gloves
(50009, 40558, 0, 1, 1, 1, 1); -- Arcanic Tramplers

DELETE FROM gameobject_loot_template WHERE entry IN (26094, 26097);
INSERT INTO gameobject_loot_template (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(26094, 47241, 100, 1, 0, 2, 2), -- Emblem of Triumph x2
(26094, 	1, 100, 1, 0, -34174, 2), -- 2 items ilevel 213
(26094, 44650, 100, 1, 0, 1, 1), -- Quest item, Judgement at the Eye of Eternity
(26094, 43953, 1, 1, 0, 1, 1), -- Reins of the Blue Drake 	
-- End of 10m Malygos loot

(26097, 47241, 100, 1, 0, 2, 2), -- Emblem of Triumph x2
(26097, 	1, 100, 1, 0, -34175, 4), -- 4 items ilevel 226
(26097, 44651, 100, 1, 0, 1, 1), -- Quest item, Heroic Judgement at the Eye of Eternity
(26097, 43952, 1, 1, 0, 1, 1); -- Reins of the Azure Drake
-- End of 25m Malygos loot
-- Fix Malygos and his adds' damage
UPDATE creature_template SET mindmg = 3684, maxdmg = 4329, dmg_multiplier = 3.5, mechanic_immune_mask = 1072918979 WHERE entry = 30245; -- Nexus Lord
UPDATE creature_template SET mindmg = 3684, maxdmg = 4329, dmg_multiplier = 7,  mechanic_immune_mask = 1072918979 WHERE entry = 31750; -- Nexus Lord (1)*/
UPDATE creature_template SET mechanic_immune_mask = 1072918979 WHERE entry IN (30249, 31751); -- scion of eternity
UPDATE creature_template SET mechanic_immune_mask = 1072918979 WHERE entry IN (30245, 31750); -- scion of eternity
--
-- Fix sound entries for Malygos encounter
DELETE FROM script_texts WHERE entry BETWEEN -1616035 AND -1616000;
INSERT INTO script_texts (npc_entry, entry, content_default, sound, type, language, emote, comment) VALUES
(28859, -1616000, 'Lesser beings, intruding here! A shame that your excess courage does not compensate for your stupidity!', 14512, 1, 0, 0, 'Malygos INTRO 1'),
(28859, -1616001, 'None but the blue dragonflight are welcome here! Perhaps this is the work of Alexstrasza? Well then, she has sent you to your deaths.', 14513, 1, 0, 0, 'Malygos INTRO 2'),
(28859, -1616002, 'What could you hope to accomplish, to storm brazenly into my domain? To employ MAGIC? Against ME?', 14514, 1, 0, 0, 'Malygos INTRO 3'),
(28859, -1616003, 'I am without limits here... the rules of your cherished reality do not apply... In this realm, I am in control...', 14515, 1, 0, 0, 'Malygos INTRO 4'),
(28859, -1616004, 'I give you one chance. Pledge fealty to me, and perhaps I won\'t slaughter you for your insolence!', 14516, 1, 0, 0, 'Malygos INTRO 5'),
(28859, -1616005, 'My patience has reached its limit. I will be rid of you!', 14517, 1, 0, 0, 'Malygos AGGRO 1'),
(28859, -1616006, 'Watch helplessly as your hopes are swept away...', 14525, 1, 0, 0, 'Malygos VORTEX'),
(28859, -1616007, 'I AM UNSTOPPABLE!', 14533, 1, 0, 0, 'Malygos SPARK BUFF'),
(28859, -1616008, 'Your stupidity has finally caught up to you!', 14519, 1, 0, 0, 'Malygos SLAY 1-1'),
(28859, -1616009, 'More artifacts to confiscate...', 14520, 1, 0, 0, 'Malygos SLAY 1-2'),
(28859, -1616010, 'How very... naive...', 14521, 1, 0, 0, 'Malygos SLAY 1-3'),
(28859, -1616012, 'I had hoped to end your lives quickly, but you have proven more...resilient then I had anticipated. Nonetheless, your efforts are in vain, it is you reckless, careless mortals who are to blame for this war! I do what I must...And if it means your...extinction...THEN SO BE IT!', 14522, 1, 0, 0, 'Malygos PHASEEND 1'),
(28859, -1616013, 'Few have experienced the pain I will now inflict upon you!', 14523, 1, 0, 0, 'Malygos AGGRO 2'),
(28859, -1616014, 'YOU WILL NOT SUCCEED WHILE I DRAW BREATH!', 14518, 1, 0, 0, 'Malygos DEEP BREATH'),
(28859, -1616016, 'I will teach you IGNORANT children just how little you know of magic...', 14524, 1, 0, 0, 'Malygos ARCANE OVERLOAD'),
(28859, -1616020, 'Your energy will be put to good use!', 14526, 1, 0, 0, 'Malygos SLAY 2-1'),
(28859, -1616021, 'I AM THE SPELL-WEAVER! My power is INFINITE!', 14527, 1, 0, 0, 'Malygos SLAY 2-2'),
(28859, -1616022, 'Your spirit will linger here forever!', 14528, 1, 0, 0, 'Malygos SLAY 2-3'),
(28859, -1616017, 'ENOUGH! If you intend to reclaim Azeroth\'s magic, then you shall have it...', 14529, 1, 0, 0, 'Malygos PHASEEND 2'),
(28859, -1616018, 'Now your benefactors make their appearance...But they are too late. The powers contained here are sufficient to destroy the world ten times over! What do you think they will do to you?', 14530, 1, 0, 0, 'Malygos PHASE 3 INTRO'),
(28859, -1616019, 'SUBMIT!', 14531, 1, 0, 0, 'Malygos AGGRO 3'),
(28859, -1616026, 'The powers at work here exceed anything you could possibly imagine!', 14532, 1, 0, 0, 'Malygos STATIC FIELD'),
(28859, -1616023, 'Alexstrasza! Another of your brood falls!', 14534, 1, 0, 0, 'Malygos SLAY 3-1'),
(28859, -1616024, 'Little more then gnats!', 14535, 1, 0, 0, 'Malygos SLAY 3-2'),
(28859, -1616025, 'Your red allies will share your fate...', 14536, 1, 0, 0, 'Malygos SLAY 3-3'),
(28859, -1616027, 'Still standing? Not for long...', 14537, 1, 0, 0, 'Malygos SPELL 1'),
(28859, -1616028, 'Your cause is lost!', 14538, 1, 0, 0, 'Malygos SPELL 1'),
(28859, -1616029, 'Your fragile mind will be shattered!', 14539, 1, 0, 0, 'Malygos SPELL 1'),
(28859, -1616030, 'UNTHINKABLE! The mortals will destroy... e-everything... my sister... what have you-', 14540, 1, 0, 0, 'Malygos DEATH'),
(32295, -1616031, 'I did what I had to, brother. You gave me no alternative.', 14406, 1, 0, 0, 'Alexstrasza OUTRO 1'),
(32295, -1616032, 'And so ends the Nexus War.', 14407, 1, 0, 0, 'Alexstrasza OUTRO 2'),
(32295, -1616033, 'This resolution pains me deeply, but the destruction, the monumental loss of life had to end. Regardless of Malygos\' recent transgressions, I will mourn his loss. He was once a guardian, a protector. This day, one of the world\'s mightiest has fallen.', 14408, 1, 0, 0, 'Alexstrasza OUTRO 3'),
(32295, -1616034, 'The red dragonflight will take on the burden of mending the devastation wrought on Azeroth. Return home to your people and rest. Tomorrow will bring you new challenges, and you must be ready to face them. Life...goes on.', 14409, 1, 0, 0, 'Alexstrasza OUTRO 4'),
(28859, -1616035, 'A Power Spark forms from a nearby rift!', 0, 5, 0, 0, 'Malygos WHISPER_POWER_SPARK');

-- Fix invalid target Alexstraszas Gift
UPDATE gameobject_template SET data0 = 43, faction = 35, flags = 0 WHERE entry IN (193967, 193905);

-- Hotfixes
UPDATE creature_template SET InhabitType = 4, VehicleId = 223 WHERE entry IN (30234, 30248);
UPDATE creature_template SET spell6 = 57092, spell7 = 57403 WHERE entry IN (30161, 31752);

UPDATE `gameobject_template` SET `ScriptName` = 'go_malygos_iris' WHERE `entry` IN (193958, 193960);
