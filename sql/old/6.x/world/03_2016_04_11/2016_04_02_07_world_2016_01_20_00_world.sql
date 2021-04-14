DELETE FROM gossip_menu_option WHERE `menu_id` IN (11013, 11014, 11015, 11016, 11017, 11018);
INSERT INTO gossip_menu_option (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES
(11013, 1, 0, 'Teleport to the Oratory of the Damned.', 37722, 1, 1, 0, 0, 0, 0, '', 0), -- Light's Hammer
(11013, 3, 0, 'Teleport to the Rampart of Skulls.',     37723, 1, 1, 0, 0, 0, 0, '', 0), -- Light's Hammer
(11013, 4, 0, 'Teleport to the Deathbringer''s Rise.',  37724, 1, 1, 0, 0, 0, 0, '', 0), -- Light's Hammer
(11013, 5, 0, 'Teleport to the Upper Spire.',           37725, 1, 1, 0, 0, 0, 0, '', 0), -- Light's Hammer
(11013, 6, 0, 'Teleport to Sindragosa''s Lair.',        37728, 1, 1, 0, 0, 0, 0, '', 0), -- Light's Hammer

(11014, 0, 0, 'Teleport to Light''s Hammer.',           37671, 1, 1, 0, 0, 0, 0, '', 0), -- Oratory of the Damned
(11014, 3, 0, 'Teleport to the Rampart of Skulls.',     37723, 1, 1, 0, 0, 0, 0, '', 0), -- Oratory of the Damned
(11014, 4, 0, 'Teleport to the Deathbringer''s Rise.',  37724, 1, 1, 0, 0, 0, 0, '', 0), -- Oratory of the Damned
(11014, 5, 0, 'Teleport to the Upper Spire.',           37725, 1, 1, 0, 0, 0, 0, '', 0), -- Oratory of the Damned
(11014, 6, 0, 'Teleport to Sindragosa''s Lair.',        37728, 1, 1, 0, 0, 0, 0, '', 0), -- Oratory of the Damned

(11015, 0, 0, 'Teleport to Light''s Hammer.',           37671, 1, 1, 0, 0, 0, 0, '', 0), -- Rampart of Skulls
(11015, 1, 0, 'Teleport to the Oratory of the Damned.', 37722, 1, 1, 0, 0, 0, 0, '', 0), -- Rampart of Skulls
(11015, 4, 0, 'Teleport to the Deathbringer''s Rise.',  37724, 1, 1, 0, 0, 0, 0, '', 0), -- Rampart of Skulls
(11015, 5, 0, 'Teleport to the Upper Spire.',           37725, 1, 1, 0, 0, 0, 0, '', 0), -- Rampart of Skulls
(11015, 6, 0, 'Teleport to Sindragosa''s Lair.',        37728, 1, 1, 0, 0, 0, 0, '', 0), -- Rampart of Skulls

(11016, 0, 0, 'Teleport to Light''s Hammer.',           37671, 1, 1, 0, 0, 0, 0, '', 0), -- Deathbringer's Rise
(11016, 1, 0, 'Teleport to the Oratory of the Damned.', 37722, 1, 1, 0, 0, 0, 0, '', 0), -- Deathbringer's Rise
(11016, 3, 0, 'Teleport to the Rampart of Skulls.',     37723, 1, 1, 0, 0, 0, 0, '', 0), -- Deathbringer's Rise
(11016, 5, 0, 'Teleport to the Upper Spire.',           37725, 1, 1, 0, 0, 0, 0, '', 0), -- Deathbringer's Rise
(11016, 6, 0, 'Teleport to Sindragosa''s Lair.',        37728, 1, 1, 0, 0, 0, 0, '', 0), -- Deathbringer's Rise

(11017, 0, 0, 'Teleport to Light''s Hammer.',           37671, 1, 1, 0, 0, 0, 0, '', 0), -- Upper Spire
(11017, 1, 0, 'Teleport to the Oratory of the Damned.', 37722, 1, 1, 0, 0, 0, 0, '', 0), -- Upper Spire
(11017, 3, 0, 'Teleport to the Rampart of Skulls.',     37723, 1, 1, 0, 0, 0, 0, '', 0), -- Upper Spire
(11017, 4, 0, 'Teleport to the Deathbringer''s Rise.',  37724, 1, 1, 0, 0, 0, 0, '', 0), -- Upper Spire
(11017, 6, 0, 'Teleport to Sindragosa''s Lair.',        37728, 1, 1, 0, 0, 0, 0, '', 0), -- Upper Spire

(11018, 0, 0, 'Teleport to Light''s Hammer.',           37671, 1, 1, 0, 0, 0, 0, '', 0), -- Sindragosa's Lair
(11018, 1, 0, 'Teleport to the Oratory of the Damned.', 37722, 1, 1, 0, 0, 0, 0, '', 0), -- Sindragosa's Lair
(11018, 3, 0, 'Teleport to the Rampart of Skulls.',     37723, 1, 1, 0, 0, 0, 0, '', 0), -- Sindragosa's Lair
(11018, 4, 0, 'Teleport to the Deathbringer''s Rise.',  37724, 1, 1, 0, 0, 0, 0, '', 0), -- Sindragosa's Lair
(11018, 5, 0, 'Teleport to the Upper Spire.',           37725, 1, 1, 0, 0, 0, 0, '', 0); -- Sindragosa's Lair

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (11013, 11014, 11015, 11016, 11017, 11018);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11013,1,0,0,13,0,0,3,2,0,0,0,'','Show option ''Teleport to the Oratory of the Damned.'' only if BossState DATA_LORD_MARROWGAR is DONE'),
(15,11013,3,0,0,13,0,1,3,2,0,0,0,'','Show option ''Teleport to the Rampart of Skulls.'' only if BossState DATA_LADY_DEATHWHISPER is DONE'),
(15,11013,4,0,0,13,0,2,3,2,0,0,0,'','Show option ''Teleport to the Deathbringer''s Rise.'' only if BossState DATA_ICECROWN_GUNSHIP_BATTLE is DONE'),
(15,11013,5,0,0,13,0,41,3,0,0,0,0,'','Show option ''Teleport to the Upper Spire.'' only if DATA_UPPERSPIRE_TELE_ACT is DONE'),
(15,11013,6,0,0,13,0,10,3,2,0,0,0,'','Show option ''Teleport to Sindragosa''s Lair.'' only if BossState DATA_VALITHRIA_DREAMWALKER is DONE'),

(15,11014,3,0,0,13,0,1,3,2,0,0,0,'','Show option ''Teleport to the Rampart of Skulls.'' only if BossState DATA_LADY_DEATHWHISPER is DONE'),
(15,11014,4,0,0,13,0,2,3,2,0,0,0,'','Show option ''Teleport to the Deathbringer''s Rise.'' only if BossState DATA_ICECROWN_GUNSHIP_BATTLE is DONE'),
(15,11014,5,0,0,13,0,41,3,0,0,0,0,'','Show option ''Teleport to the Upper Spire.'' only if DATA_UPPERSPIRE_TELE_ACT is DONE'),
(15,11014,6,0,0,13,0,10,3,2,0,0,0,'','Show option ''Teleport to Sindragosa''s Lair.'' only if BossState DATA_VALITHRIA_DREAMWALKER is DONE'),

(15,11015,1,0,0,13,0,0,3,2,0,0,0,'','Show option ''Teleport to the Oratory of the Damned.'' only if BossState DATA_LORD_MARROWGAR is DONE'),
(15,11015,4,0,0,13,0,2,3,2,0,0,0,'','Show option ''Teleport to the Deathbringer''s Rise.'' only if BossState DATA_ICECROWN_GUNSHIP_BATTLE is DONE'),
(15,11015,5,0,0,13,0,41,3,0,0,0,0,'','Show option ''Teleport to the Upper Spire.'' only if DATA_UPPERSPIRE_TELE_ACT is DONE'),
(15,11015,6,0,0,13,0,10,3,2,0,0,0,'','Show option ''Teleport to Sindragosa''s Lair.'' only if BossState DATA_VALITHRIA_DREAMWALKER is DONE'),

(15,11016,1,0,0,13,0,0,3,2,0,0,0,'','Show option ''Teleport to the Oratory of the Damned.'' only if BossState DATA_LORD_MARROWGAR is DONE'),
(15,11016,3,0,0,13,0,1,3,2,0,0,0,'','Show option ''Teleport to the Rampart of Skulls.'' only if BossState DATA_LADY_DEATHWHISPER is DONE'),
(15,11016,5,0,0,13,0,41,3,0,0,0,0,'','Show option ''Teleport to the Upper Spire.'' only if DATA_UPPERSPIRE_TELE_ACT is DONE'),
(15,11016,6,0,0,13,0,10,3,2,0,0,0,'','Show option ''Teleport to Sindragosa''s Lair.'' only if BossState DATA_VALITHRIA_DREAMWALKER is DONE'),

(15,11017,1,0,0,13,0,0,3,2,0,0,0,'','Show option ''Teleport to the Oratory of the Damned.'' only if BossState DATA_LORD_MARROWGAR is DONE'),
(15,11017,3,0,0,13,0,1,3,2,0,0,0,'','Show option ''Teleport to the Rampart of Skulls.'' only if BossState DATA_LADY_DEATHWHISPER is DONE'),
(15,11017,4,0,0,13,0,2,3,2,0,0,0,'','Show option ''Teleport to the Deathbringer''s Rise.'' only if BossState DATA_ICECROWN_GUNSHIP_BATTLE is DONE'),
(15,11017,6,0,0,13,0,10,3,2,0,0,0,'','Show option ''Teleport to Sindragosa''s Lair.'' only if BossState DATA_VALITHRIA_DREAMWALKER is DONE'),

(15,11018,1,0,0,13,0,0,3,2,0,0,0,'','Show option ''Teleport to the Oratory of the Damned.'' only if BossState DATA_LORD_MARROWGAR is DONE'),
(15,11018,3,0,0,13,0,1,3,2,0,0,0,'','Show option ''Teleport to the Rampart of Skulls.'' only if BossState DATA_LADY_DEATHWHISPER is DONE'),
(15,11018,4,0,0,13,0,2,3,2,0,0,0,'','Show option ''Teleport to the Deathbringer''s Rise.'' only if BossState DATA_ICECROWN_GUNSHIP_BATTLE is DONE'),
(15,11018,5,0,0,13,0,41,3,0,0,0,0,'','Show option ''Teleport to the Upper Spire.'' only if DATA_UPPERSPIRE_TELE_ACT is DONE');
