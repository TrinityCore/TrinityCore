-- delete excessive spawns
DELETE FROM `creature` WHERE `guid` IN (137758,137759);
DELETE FROM `creature_addon` WHERE `guid` IN (137758,137759);
DELETE FROM `linked_respawn` WHERE `guid` IN (137758,137759) AND `linkType`=0;

UPDATE `creature_addon` SET `auras`='70203 71465' WHERE `guid`=137753; -- Sister Svalna

DELETE FROM `creature_text` WHERE `entry` IN (37126,37129,37122,37123,37124,37125);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(37126,0,0, 'You may have once fought beside me, Crok, but now you are nothing more than a traitor. Come, your second death approaches!',1,0,0,0,0,17017, 'Sister Svalna - SAY_EVENT_START'),
(37126,1,0, 'Miserable creatures! Die!',1,0,0,0,0,17018, 'Sister Svalna - SAY_KILL_CAPTAIN'),
(37126,2,0, 'Foolish Crok. You brought my reinforcements with you. Arise, Argent Champions, and serve the Lich King in death!',1,0,0,0,0,17019, 'Sister Svanlna - SAY_RESURRECT_CAPTAINS'),
(37126,3,0, 'Come, Scourgebane. I''ll show the master which of us is truly worthy of the title of \"Champion\"!',1,0,0,0,0,17020, 'Sister Svalna - SAY_AGGRO'),
(37126,4,0, 'What a pitiful choice of an ally, Crok!',1,0,0,0,0,17021, 'Sister Svalna - SAY_KILL'),
(37126,5,0, 'What? They died so easily? No matter.',1,0,0,0,0,17022, 'Sister Svalna - SAY_CAPTAIN_DEATH'),
(37126,6,0, 'Perhaps... you were right, Crok.',1,0,0,0,0,17023, 'Sister Svalna - SAY_DEATH'),
(37126,7,0, '%s has impaled $N!',3,0,0,0,0,0, 'Sister Svalna - EMOTE_SVALNA_IMPALE'),
(37126,8,0, '%s''s Aether Shield has been shattered by $N!',3,0,0,0,0,0, 'Sister Svalna - EMOTE_SVALNA_BROKEN_SHIELD'),
(37129,0,0, 'Ready your arms, my Argent Brothers. The Vrykul will protect the Frost Queen with their lives.',1,0,0,0,0,16819, 'Crok Scourgebane - SAY_CROK_INTRO_1'),
(37129,1,0, 'Enough idle banter! Our champions have arrived - support them as we push our way through the hall!',1,0,0,0,0,16820, 'Crok Scourgebane - SAY_CROK_INTRO_3'),
(37129,2,0, 'Draw them back to us, and we''ll assist you.',1,0,0,0,0,16821, 'Crok Scourgebane - SAY_CROK_COMBAT_WP_0'),
(37129,3,0, 'Quickly, push on!',1,0,0,0,0,16823, 'Crok Scourgebane - SAY_CROK_COMBAT_WP_1'),
(37129,4,0, 'Her reinforcements will arrive shortly, we must bring her down quickly!',1,0,0,0,0,16824, 'Crok Scourgebane - SAY_CROK_FINAL_WP'),
(37129,5,0, 'I''ll draw her attacks. Return our brothers to their graves, then help me bring her down!',1,0,0,15,0,16826, 'Crok Scourgebane - SAY_CROK_COMBAT_SVALNA'),
(37129,6,0, 'I must rest for a moment',1,0,0,0,0,16826, 'Crok Scourgebane - SAY_CROK_WEAKENING_GAUNTLET'),
(37129,7,0, 'Champions, I cannot hold her back any longer!',1,0,0,0,0,16827, 'Crok Scourgebane - SAY_CROK_WEAKENING_SVALNA'),
(37129,8,0, 'Vengeance alone... was not enough!',1,0,0,0,0,16828, 'Crok Scourgebane - SAY_CROK_DEATH'),
(37122,0,0, 'Never... could reach... the top shelf...',1,0,0,0,0,16586, 'Captain Arnath - SAY_ARNATH_DEATH'),
(37122,1,0, 'You miserable fools never did manage to select a decent bat wing.',1,0,0,0,0,16587, 'Captain Arnath - SAY_ARNATH_RESURRECTED'),
(37122,2,0, 'THAT was for bringing me spoiled spider ichor!',1,0,0,0,0,16588, 'Captain Arnath - SAY_ARNATH_KILL'),
(37122,3,0, 'Don''t... let Finklestein use me... for his potions...',1,0,0,0,0,16589, 'Captain Arnath - SAY_ARNATH_SECOND_DEATH'),
(37122,4,0, 'The loss of our comrades was unpreventable. They lived and died in the service of the Argent Crusade.',1,0,0,0,0,16590, 'Captain Arnath - SAY_ARNATH_SURVIVE_TALK'),
(37122,5,0, 'Even dying here beats spending another day collecting reagents for that madman, Finklestein.',1,0,0,0,0,16585, 'Captain Arnath - SAY_ARNATH_INTRO_2'),
(37123,0,0, 'No amount of healing can save me now. Fight on, brothers...',1,0,0,0,0,16810, 'Captain Brandon - SAY_BRANDON_DEATH'),
(37123,1,0, 'What? This strength...? All of the pain is gone! You... must join me in the eternal embrace of death!',1,0,0,0,0,16811, 'Captain Brandon - SAY_BRANDON_RESURRECTED'),
(37123,2,0, 'It doesn''t hurt anymore, does it?',1,0,0,0,0,16812, 'Captain Brandon - SAY_BRANDON_KILL'),
(37123,3,0, 'I''m sorry...',1,0,0,0,0,16813, 'Captain Brandon - SAY_BRANDON_SECOND_DEATH'),
(37123,4,0, 'You have done much in this war against the Scourge. May the light embrace you.',1,0,0,0,0,16815, 'Captain Brandon - SAY_BRANDON_SURVIVE_TALK'),
(37124,0,0, 'Please... burn my remains. Let me live warm in the afterlife...',1,0,0,0,0,16844, 'Captain Grondel - SAY_GRONDEL_DEATH'),
(37124,1,0, 'No! Why was I denied a death by flame? You must all BURN!',1,0,0,0,0,16845, 'Captain Grondel - SAY_GRONDEL_RESURRECTED'),
(37124,2,0, 'Can you feel the burn?',1,0,0,0,0,16846, 'Captain Grondel - SAY_GRONDEL_KILL'),
(37124,3,0, 'What... have I done? No!',1,0,0,0,0,16847, 'Captain Grondel - SAY_GRONDEL_SECOND_DEATH'),
(37124,4,0, 'What can possibly redeem this unholy place? Thank you...',1,0,0,0,0,16849, 'Captain Grondel - SAY_GRONDEL_SURVIVE_TALK'),
(37125,0,0, 'It was... a worthy afterlife.',1,0,0,0,0,16998, 'Captain Rupert - SAY_RUPERT_DEATH'),
(37125,1,0, 'There is no escaping the Lich King''s will. Prepare for an explosive encounter!',1,0,0,0,0,16999, 'Captain Rupert - SAY_RUPERT_RESURRECTED'),
(37125,2,0, 'So that''s what happens when you stand too close to a bomb!',1,0,0,0,0,17000, 'Captain Rupert - SAY_RUPERT_KILL'),
(37125,3,0, 'What an... explosive ending!',1,0,0,0,0,17001, 'Captain Rupert - SAY_RUPERT_SECOND_DEATH'),
(37125,4,0, 'Beware the dangers that lie ahead... and do try to remain in one piece.',1,0,0,0,0,17003, 'Captain Rupert - SAY_RUPERT_SURVIVE_TALK');

DELETE FROM `script_waypoint` WHERE `entry`=37129;
INSERT INTO `script_waypoint` (`entry`,`pointid`,`location_x`,`location_y`,`location_z`,`waittime`,`point_comment`) VALUES
(37129,0,4356.90,2648.00,350.285,0, 'Crok Scourgebane - at first trash pack'),
(37129,1,4357.00,2582.17,351.101,0, 'Crok Scourgebane - at second trash pack'),
(37129,2,4357.21,2555.91,354.478,0, NULL),
(37129,3,4357.09,2547.81,354.766,0, NULL),
(37129,4,4356.88,2512.40,358.436,0, 'Crok Scourgebane - at Sister Svalna');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (70078,70053);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=50307;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,70078,0,18,1,37122,0,0, '', 'Sister Svalna - Caress of Death'),
(13,0,70078,0,18,1,37123,0,0, '', 'Sister Svalna - Caress of Death'),
(13,0,70078,0,18,1,37124,0,0, '', 'Sister Svalna - Caress of Death'),
(13,0,70078,0,18,1,37125,0,0, '', 'Sister Svalna - Caress of Death'),
(13,0,70053,0,18,1,37122,0,0, '', 'Sister Svalna - Revive Champion'),
(13,0,70053,0,18,1,37123,0,0, '', 'Sister Svalna - Revive Champion'),
(13,0,70053,0,18,1,37124,0,0, '', 'Sister Svalna - Revive Champion'),
(13,0,70053,0,18,1,37125,0,0, '', 'Sister Svalna - Revive Champion'),
(18,0,50307,0,24,1,37126,0,0, '', 'Infernal Spear- Sister Svalna target');

UPDATE `creature_template` SET `difficulty_entry_1`=38349,`minlevel`=81,`maxlevel`=81,`exp`=2,`faction_A`=2209,`faction_H`=2209,`unit_class`=2,`mindmg`=425,`maxdmg`=602,`attackpower`=670,`baseattacktime`=1500,`minrangedmg`=351,`maxrangedmg`=511,`rangedattackpower`=86,`equipment_id`=2423 WHERE `entry`=37491; -- Captain Arnath (Undead)
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81,`exp`=2,`faction_A`=2209,`faction_H`=2209,`unit_class`=2,`mindmg`=425,`maxdmg`=602,`attackpower`=670,`baseattacktime`=1500,`minrangedmg`=351,`maxrangedmg`=511,`dmg_multiplier`=13,`rangedattackpower`=86,`dynamicflags`=8,`equipment_id`=2423 WHERE `entry`=38349; -- Captain Arnath (Undead)
UPDATE `creature_template` SET `difficulty_entry_1`=38350,`minlevel`=81,`maxlevel`=81,`exp`=2,`faction_A`=2209,`faction_H`=2209,`unit_class`=2,`mindmg`=425,`maxdmg`=602,`attackpower`=670,`baseattacktime`=1500,`minrangedmg`=351,`maxrangedmg`=511,`rangedattackpower`=86,`equipment_id`=2424 WHERE `entry`=37493; -- Captain Brandon (Undead)
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81,`exp`=2,`faction_A`=2209,`faction_H`=2209,`unit_class`=2,`mindmg`=425,`maxdmg`=602,`attackpower`=670,`baseattacktime`=1500,`minrangedmg`=351,`maxrangedmg`=511,`dmg_multiplier`=13,`rangedattackpower`=86,`dynamicflags`=8,`equipment_id`=2424 WHERE `entry`=38350; -- Captain Brandon (Undead)
UPDATE `creature_template` SET `difficulty_entry_1`=38351,`minlevel`=81,`maxlevel`=81,`exp`=2,`faction_A`=2209,`faction_H`=2209,`mindmg`=464,`maxdmg`=604,`attackpower`=708,`baseattacktime`=1500,`minrangedmg`=353,`maxrangedmg`=512,`rangedattackpower`=112,`equipment_id`=2425 WHERE `entry`=37494; -- Captain Grondel (Undead)
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81,`exp`=2,`faction_A`=2209,`faction_H`=2209,`mindmg`=464,`maxdmg`=604,`attackpower`=708,`baseattacktime`=1500,`minrangedmg`=353,`maxrangedmg`=512,`dmg_multiplier`=13,`rangedattackpower`=112,`dynamicflags`=8,`equipment_id`=2425 WHERE `entry`=38351; -- Captain Grondel (Undead)
UPDATE `creature_template` SET `difficulty_entry_1`=38352,`minlevel`=81,`maxlevel`=81,`exp`=2,`faction_A`=2209,`faction_H`=2209,`mindmg`=464,`maxdmg`=604,`attackpower`=708,`baseattacktime`=1500,`minrangedmg`=353,`maxrangedmg`=512,`rangedattackpower`=112,`equipment_id`=2426 WHERE `entry`=37495; -- Captain Rupert (Undead)
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81,`exp`=2,`faction_A`=2209,`faction_H`=2209,`mindmg`=464,`maxdmg`=604,`attackpower`=708,`baseattacktime`=1500,`minrangedmg`=353,`maxrangedmg`=512,`dmg_multiplier`=13,`rangedattackpower`=112,`dynamicflags`=8,`equipment_id`=2426 WHERE `entry`=38352; -- Captain Rupert (Undead)
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`faction_A`=2209,`faction_H`=2209,`npcflag`=`npcflag`|16777216,`dynamicflags`=0,`equipment_id`=2364 WHERE `entry`=38248; -- Impaling Spear

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=38248;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(38248,71462,0,0,0,1,0,71443,2); -- Impaling Spear
