DELETE FROM `smart_scripts` WHERE (`entryorguid`=25171 OR `entryorguid` BETWEEN -209026 AND -209019) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-209019,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35469,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Gormok the Impaler'),
(-209020,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35469,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Gormok the Impaler'),
(-209022,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35469,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Gormok the Impaler'),
(-209023,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35469,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Gormok the Impaler'),
(-209021,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35470,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Icehowl'),
(-209024,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35470,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Icehowl'),
(-209025,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35470,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Icehowl'),
(-209026,0,0,0,1,0,100,1,500,500,0,0,11,63413,0,0,0,0,0,11,35470,10,0,0,0,0,0, 'Invisible Stalker (Scale x0.5) - OOC cast Rope Beam in Icehowl');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13593,13703,13704,13705,13706,13707,13708,13709,13710,13711);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,13593,0,8,13700,0,0,0,'','Valiant Of Stormwind - Alliance Champion Marker'),
(19,0,13703,0,8,13700,0,0,0,'','Valiant Of Ironforge - Alliance Champion Marker'),
(19,0,13704,0,8,13700,0,0,0,'','Valiant Of Gnomeregan - Alliance Champion Marker'),
(19,0,13705,0,8,13700,0,0,0,'','Valiant Of The Exodar - Alliance Champion Marker'),
(19,0,13706,0,8,13700,0,0,0,'','Valiant Of Darnassus - Alliance Champion Marker'),
(19,0,13707,0,8,13701,0,0,0,'','Valiant Of Orgrimmar - Horde Champion Marker'),
(19,0,13708,0,8,13701,0,0,0,'','Valiant Of Sen''jin - Horde Champion Marker'),
(19,0,13709,0,8,13701,0,0,0,'','Valiant Of Thunder Bluff - Horde Champion Marker'),
(19,0,13710,0,8,13701,0,0,0,'','Valiant Of Undercity - Horde Champion Marker'),
(19,0,13711,0,8,13701,0,0,0,'','Valiant Of Silvermoon - Horde Champion Marker'),
(20,0,13593,0,8,13700,0,0,0,'','Valiant Of Stormwind - Alliance Champion Marker'),
(20,0,13703,0,8,13700,0,0,0,'','Valiant Of Ironforge - Alliance Champion Marker'),
(20,0,13704,0,8,13700,0,0,0,'','Valiant Of Gnomeregan - Alliance Champion Marker'),
(20,0,13705,0,8,13700,0,0,0,'','Valiant Of The Exodar - Alliance Champion Marker'),
(20,0,13706,0,8,13700,0,0,0,'','Valiant Of Darnassus - Alliance Champion Marker'),
(20,0,13707,0,8,13701,0,0,0,'','Valiant Of Orgrimmar - Horde Champion Marker'),
(20,0,13708,0,8,13701,0,0,0,'','Valiant Of Sen''jin - Horde Champion Marker'),
(20,0,13709,0,8,13701,0,0,0,'','Valiant Of Thunder Bluff - Horde Champion Marker'),
(20,0,13710,0,8,13701,0,0,0,'','Valiant Of Undercity - Horde Champion Marker'),
(20,0,13711,0,8,13701,0,0,0,'','Valiant Of Silvermoon - Horde Champion Marker');

-- Cast Armistice inside pavillions as well
DELETE FROM `spell_area` WHERE `spell`=64373 AND `area` IN (4666,4667,4674);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES
(64373,4666,0,0,0,0,0,2,1), -- Sunreaver Pavillion
(64373,4667,0,0,0,0,0,2,1), -- Silver Covenant Pavillion
(64373,4674,0,0,0,0,0,2,1); -- Argent Pavillion

UPDATE `npc_spellclick_spells` SET `quest_end`=13687 WHERE `npc_entry`=33842; -- Sunreaver Hawkstrider - !Horde Tournament Eligibility Marker
UPDATE `npc_spellclick_spells` SET `quest_end`=13686 WHERE `npc_entry`=33843; -- Quel'dorei Steed - !Alliance Tournament Eligibility Marker

-- Valiant of * quests, by Kaelima
-- Alliance
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~1 WHERE `entry`=13593; -- !Human - Valiant Of Stormwind
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~4 WHERE `entry`=13703; -- !Dwarf - Valiant Of Ironforge
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~64 WHERE `entry`=13704; -- !Gnome - Valiant Of Gnomeregan
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~1024 WHERE `entry`=13705; -- !Draenei - Valiant Of The Exodar
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~8 WHERE `entry`=13706; -- !Night Elf - Valiant Of Darnassus
-- Horde
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~2 WHERE `entry`=13707; -- !Orc - Valiant of Orgrimmar
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~128 WHERE `entry`=13708; -- !Troll - Valiant Of Sen'jin
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~32 WHERE `entry`=13709; -- !Tauren - Valiant Of Thunder Bluff
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~16 WHERE `entry`=13710; -- !Undead - Valiant Of Undercity
UPDATE `quest_template` SET `RequiredRaces`=`RequiredRaces`&~512 WHERE `entry`=13711; -- !Blood Elf - Valiant Of Silvermoon
