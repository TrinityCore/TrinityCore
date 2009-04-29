-- Kil'jaeden --

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 45909;
DELETE FROM `spell_script_target` WHERE `entry` IN (46589, 45839);
INSERT INTO `spell_script_target` () VALUES (46589, 1, 30598);
INSERT INTO `spell_script_target` () VALUES (46589, 1, 30614);
INSERT INTO `spell_script_target` () VALUES (45839, 1, 25653);

DELETE FROM `creature_template` WHERE entry in (30598, 30614);
INSERT INTO `creature_template` () VALUES 
(30598, 0, 4449, 0, 4449, 0, 'Spike Target', '', '', 70, 70, 1, 1, 0, 0, 0, 14, 14, 0, 1, 1, 0, 0, 0, 0, 0, 2600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 0, 0, 128, ''),
(30614, 0, 4449, 0, 4449, 0, 'Spike Target 2', '', '', 70, 70, 1, 1, 0, 0, 0, 14, 14, 0, 1, 1, 0, 0, 0, 0, 0, 2600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 0, 0, 128, '');

UPDATE `creature_template` SET `flags_extra` = 128  WHERE `entry` IN (30614, 30598, 25735);
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 73, unit_flags = 33554432, minhealth=5000000, maxhealth=5000000 WHERE entry IN (26046, 25319);
UPDATE `creature_template` SET `minlevel` = 70, `unit_flags` = 33554432 WHERE entry = 26046;
UPDATE `creature_template` SET `minlevel` =70, `maxlevel` = 70, `unit_flags` = 33554432, spell1 = 45848, spell2 = 45862, spell3 = 45860, spell4 = 45856, minhealth = 5000000, maxhealth=5000000 WHERE entry=25653;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `minhealth` = 20000, maxhealth = 20000 WHERE entry = 25502;
UPDATE `creature_template` SET `minhealth` = 12600000, maxhealth = 12600000, minmana = 2000000, maxmana = 2000000 WHERE entry = 25315;
UPDATE `creature_template` SET `minhealth` = 110000, maxhealth = 110000, minmana = 100000, maxmana = 100000 WHERE entry =25708;
UPDATE `creature_template` SET `minlevel` = 73, `maxlevel` = 73 WHERE entry = 25735;

DELETE FROM creature WHERE id IN (25319, 25588, 25608);
INSERT INTO creature (id, map, spawnMask, modelid, equipment_id, position_x, position_y, position_z, orientation, spawntimesecs, spawndist, currentwaypoint, curhealth, curmana, DeathState, MovementType) VALUES
(25319, 580, 1, 0, 0, 1701.7, 635.515, 72.2884, 4.65461, 25, 0, 0, 1, 0, 0, 0),
(25608, 580, 1, 0, 0, 1698.9, 627.877, 27.6233, 0.034907, 604800, 0, 0, 1, 0, 0, 0);

DELETE FROM gameobject WHERE id=188415;
INSERT INTO gameobject (id, map, spawnMask, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state) VALUES
(188415, 580, 1, 1653.12, 635.41, 28.0932, 0.0977725, 0, 0, 0.0488668, 0.998805, 25, 0, 1),
(188415, 580, 1, 1704.14, 583.591, 28.1696, 1.59003, 0, 0, 0.713874, 0.700274, 25, 0, 1),
(188415, 580, 1, 1745.68, 621.823, 28.0505, 2.93777, 0, 0, 0.994812, 0.101733, 25, 0, 1),
(188415, 580, 1, 1694.48, 674.29, 28.0502, 4.86985, 0, 0, 0.649302, -0.760531, 25, 0, 1);
UPDATE `gameobject_template` SET `type` = 1 WHERE `entry` = 188415;

-- M'uru --
UPDATE `creature_template` SET `modelid_A` = 23842 WHERE `entry` = 25744;
UPDATE `creature_template` SET `flags_extra` = 128 WHERE entry IN (25855, 25770);
UPDATE `creature_template` SET `spell1` = 46262, flags_extra = 128, scriptname = '' WHERE entry = 25879;

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (46242, 46228, 46228, 46262);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46242, 46247, 0, 'Black Hole Visual (Birth)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46228, 46235, 0, 'Black Hole Visual (Grown)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46228, -46247, 0, 'Black Hole Visual (Grown)');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (46262, 46265, 0, 'Void Zone Visual');

DELETE FROM `spell_script_target` WHERE `entry` IN (45976, 46177);
INSERT INTO `spell_script_target` VALUES (45976, 1, 25770);
INSERT INTO `spell_script_target` VALUES (46177, 1, 25770);

-- EAI for Berserks FROM Megamage
DELETE FROM `eventai_scripts` WHERE `creature_id` = 25798;
INSERT INTO `eventai_scripts` (`id`, `creature_id`, `event_type`, `event_flags`,`event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`, `event_chance`, `event_inverse_phase_mask`) VALUES
(2579800, 25798, 11, 0, 0*1000, 0*1000, 0*1000, 0*1000, 11, 45769, 0, 0, 20, 1, 0, 0, 21, 1, 0, 0,"Shadowsword Berserker - Sunwell Radiance", 100, 0),
(2579801, 25798, 0, 1, 10*1000, 12*1000, 10*1000, 15*1000, 11, 46160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowsword Berserker - Cast Flurry', 70, 0),
(2579802, 25798, 1, 0, 180*1000, 180*1000, 0*1000, 0*1000, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Shadowsword Berserker - 180s OOC => Evade', 100, 0);


-- Brutallus --
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 24882;

-- Felmyst --
UPDATE `creature_template` SET `modelid_H` = 22838 WHERE `entry` = 25038;

DELETE FROM `script_texts` WHERE `entry` BETWEEN '-1580109' and '-1580036';

INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `comment`) VALUES
(-1580036, 'Glory to Kil\'jaeden! Death to all who oppose!', 12477, 1, 'felmyst - YELL_BIRTH'),
(-1580037, 'I kill for the master!', 12480, 1, 'felmyst - YELL_KILL1'),
(-1580038, 'The end has come!', 12481, 1, 'felmyst - YELL_KILL2'),
(-1580039, 'Choke on your final breath!', 12478, 1, 'felmyst - YELL_BREATH'),
(-1580040, 'I am stronger than ever before!', 12479, 1, 'felmyst- YELL_TAKEOFF'),
(-1580041, 'No more hesitation! Your fates are written!', 12482, 1, 'felmyst - YELL_BERSERK'),
(-1580042, 'Kil\'jaeden... will... prevail...', 12483, 1, 'felmyst - YELL_DEATH'),
(-1580043, 'Madrigosa deserved a far better fate. You did what had to be done, but this battle is far from over.', 12439, 1, 'felmyst - YELL_KALECGOS'),

(-1580044, 'Fire to the aid of shadow!', 12489, 1, 'eredar - YELL_CANFLAGRATION'),
(-1580045, 'Sacrolash!', 12492, 1, 'eredar - YELL_SISTER_SACROLASH_DEAD'),
(-1580046, 'Fire consume.', 12490, 1, 'eredar - YELL_ALY_KILL_1'),
(-1580047, 'Ed-ir Halach!', 12491, 1, 'eredar - YELL_ALY_KILL_2'),
(-1580048, 'De-ek Anur!', 12494, 1, 'eredar - YELL_ALY_DEAD'),
(-1580049, 'Your luck has run its curse!', 12493, 1, 'eredar - YELL_BERSERK'),
(-1580050, 'Shadow to the aid of fire!', 12485, 1, 'eredar - YELL_SHADOW_NOVA'),
(-1580051, 'Alythess! Your fire burns within me!', 12488, 1, 'eredar - YELL_SISTER_ALYTHESS_DEAD'),
(-1580052, 'Shadow engulf.', 12486, 1, 'eredar - YELL_SAC_KILL_1'),
(-1580053, 'Ee-nok Kryul!', 12487, 1, 'eredar - YELL_SAC_KILL_2'),
(-1580054, 'I... fade.', 0, 1, 'eredar - YELL_SAC_DEAD'),
(-1580055, 'Time is a luxury you no longer possess!', 0, 1, 'eredar - YELL_ENRAGE'),

(-1580056, 'Misery...', 12484, 1, 'eredar - YELL_INTRO_SAC_1'),
(-1580057, 'Depravity...', 0, 1, 'eredar - YELL_INTRO_ALY_2'),
(-1580058, 'Confusion...', 0, 1, 'eredar - YELL_INTRO_SAC_3'),
(-1580059, 'Hatred...', 0, 1, 'eredar - YELL_INTRO_ALY_4'),
(-1580060, 'Mistrust...', 0, 1, 'eredar - YELL_INTRO_SAC_5'),
(-1580061, 'Chaos...', 0, 1, 'eredar - YELL_INTRO_ALY_6'),
(-1580062, 'These are the hallmarks...', 0, 1, 'eredar - YELL_INTRO_SAC_7'),
(-1580063, 'These are the pillars...', 0, 1, 'eredar - YELL_INTRO_ALY_8'),
(-1580064, 'directs Shadow Nova at $N', 0, 3, 'eredar - emote shadow nova'),
(-1580065, 'directs Conflagration at $N', 0, 3, 'eredar - emote conflagration'),

(-1580066, 'All my plans have led to this!', 12495, 1, 'KJ - SAY_KJ_OFFCOMBAT1'),
(-1580067, 'Stay on task! Do not waste tim!', 12496, 1, 'KJ - SAY_KJ_OFFCOMBAT2'),
(-1580068, 'I have waited long enough!', 12497, 1, 'KJ - SAY_KJ_OFFCOMBAT3'),
(-1580069, 'Fail me and suffer for eternity!', 12498, 1, 'KJ - SAY_KJ_OFFCOMBAT4'),
(-1580070, 'Drain the girl! Drain her power until there is nothing but a vacant shell!', 12499, 1, 'KJ - SAY_KJ_OFFCOMBAT5'),

(-1580071, 'The expendible have perished... So be it! Now I shall succeed where Sargeras could not! I will bleed this wretched world and secure my place as the true master of the Burning Legion. The end has come! Let the unraveling of this world commence!', 12500, 1, 'KJ - SAY_KJ_EMERGE'),
(-1580072, 'Another step towards destruction!', 12501, 1, 'KJ - SAY_KJ_SLAY1'),
(-1580073, 'Anak-ky\'ri!', 12502, 1, 'KJ - SAY_KJ_SLAY2'),
(-1580074, 'Who can you trust?', 12503, 1, 'KJ - SAY_KJ_REFLECTION1'),
(-1580075, 'The enemy is among you.', 12504, 1, 'KJ - SAY_KJ_REFLECTION2'),
(-1580076, 'Chaos!', 12505, 1, 'KJ - SAY_KJ_DARKNESS1'),
(-1580077, 'Destruction!', 12506, 1, 'KJ - SAY_KJ_DARKNESS2'),
(-1580078, 'Oblivion!', 12507, 1, 'KJ - SAY_KJ_DARKNESS3'),
(-1580079, 'I will not be denied! This world shall fall!', 12508, 1, 'KJ - SAY_KJ_PHASE3'),
(-1580080, 'Do not harbor false hope. You cannot win!', 12509, 1, 'KJ - SAY_KJ_PHASE4'),
(-1580081, 'Aggghh! The powers of the Sunwell... turned... against me! What have you done? WHAT HAVE YOU DONE?', 12510, 1, 'KJ - SAY_KJ_PHASE5'),

(-1580082, 'Anveena, you must awaken, this world needs you!', 12445, 1, 'KJ - SAY_KALECGOS_AWAKEN'),
(-1580083, 'I serve only the Master now.', 12511, 1, 'KJ - SAY_ANVEENA_IMPRISONED'),
(-1580084, 'You must let go! You must become what you were always meant to be! The time is now, Anveena!', 12446, 1, 'KJ - SAY_KALECGOS_LETGO'),
(-1580085, 'But I\'m... lost... I cannot find my way back!', 12512, 1, 'KJ - SAY_ANVEENA_LOST'),
(-1580086, 'Anveena, I love you! Focus on my voice, come back for me now! Only you can cleanse the Sunwell!', 12447, 1, 'KJ - SAY_KALECGOS_FOCUS'),
(-1580087, 'Kalec... Kalec?', 12513, 1, 'KJ - SAY_ANVEENA_KALEC'),
(-1580088, 'Yes, Anveena! Let fate embrace you now!', 12448, 1, 'KJ - SAY_KALECGOS_FATE'),
(-1580089, 'The nightmare is over, the spell is broken! Goodbye, Kalec, my love!', 12514, 1, 'KJ - SAY_ANVEENA_GOODBYE'),
(-1580090, 'Goodbye, Anveena, my love. Few will remember your name, yet this day you change the course of destiny. What was once corrupt is now pure. Heroes, do not let her sacrifice be in vain.', 12450, 1, 'KJ - SAY_KALECGOS_GOODBYE'),
(-1580091, 'Strike now, heroes, while he is weakened! Vanquish the Deceiver!', 12449, 1, 'KJ - SAY_KALECGOS_ENCOURAGE'),

(-1580092, 'You are not alone. The Blue Dragonflight shall help you vanquish the Deceiver.', 12438, 1, 'KJ - SAY_KALECGOS_JOIN'),
(-1580093, 'Nooooooooooooo!', 12527, 1, 'KJ - SAY_KJ_DEATH'),
(-1580094, 'begins to channel dark energy', 0, 3, 'KJ - EMOTE_KJ_DARKNESS'),

(-1580095, 'I will channel my power into the orbs, be ready!', 12440, 1, 'KJ - SAY_KALEC_ORB_READY1'),
(-1580096, 'I have empowered another orb! Use it quickly!', 12441, 1, 'KJ - SAY_KALEC_ORB_READY2'),
(-1580097, 'Another orb is ready! Make haste!', 12442, 1, 'KJ - SAY_KALEC_ORB_READY3'),
(-1580098, 'I have channeled all I can! The power is in your hands!', 12443, 1, 'KJ - SAY_KALEC_ORB_READY4'),

(-1580099, 'Mortal heroes, your victory here today was foretold long ago. My brother\'s anguished cry of defeat will echo across the universe, bringing renewed hope to all those who still stand against the Burning Crusade.', 12515, 0, 'prophet velen - SAY1'),
(-1580100, 'As the Legion\'s final defeat draws ever-nearer, stand proud in the knowledge that you have saved worlds without number from the flame. Just as this day marks an ending, so too does it herald a new beginning...', 12516, 0, 'prophet velen - SAY2'), -- van mégegy hang 12517 ami ehhez tartozik
(-1580101, 'The creature Entropius, whom you were forced to destroy, was once the noble naaru, M\'uru. In life, M\'uru channeled vast energies of LIGHT and HOPE. For a time, a misguided few sought to steal those energies...', 12518, 0, 'prophet velen - SAY3'),
(-1580102, 'Then fortunate it is, that I have reclaimed the noble naaru\'s spark from where it fell! Where faith dwells, hope is never lost, young blood elf.', 12519, 0, 'prophet velen - SAY4'),
(-1580103, 'Gaze now, mortals - upon the HEART OF M\'URU! Unblemished. Bathed by the light of Creation - just as it was at the Dawn.', 12520, 0, 'prophet velen - SAY5'),
(-1580104, 'In time, the light and hope held within - will rebirth more than this mere fount of power... Mayhap, they will rebirth the soul of a nation.', 12521, 0, 'prophet velen - SAY6'),
(-1580105, 'Salvation, young one. It waits for us all.', 12522, 0, 'prophet velen - SAY7'),
(-1580106, 'Farewell...', 12523, 0, 'prophet velen - SAY8'),

(-1580107, 'Our arrogance was unpardonable. We damned one of the most noble beings of all. We may never atone for this sin.', 12524, 0, 'lady liadrinn - SAY1'),
(-1580108, 'Can it be?', 12525, 0, 'lady liadrinn - SAY2'),
(-1580109, 'Blessed ancestors! I feel it... so much love... so much grace... there are... no words... impossible to describe...', 12525, 0, 'lady liadrinn - SAY3');

-- Kil'jaeden script --
UPDATE `creature_template` SET `ScriptName` = 'boss_kiljaeden' WHERE `entry` = 25315;
UPDATE `creature_template` SET `ScriptName` = 'boss_kalecgosKJ' WHERE `entry` = 25319;
UPDATE `creature_template` SET `ScriptName` = 'mob_kiljaeden_controller' WHERE `entry` = 25608;
UPDATE `creature_template` SET `ScriptName` = 'mob_hand_of_the_deceiver' WHERE `entry` = 25588;
UPDATE `creature_template` SET `ScriptName` = 'mob_felfire_portal' WHERE `entry` = 25603;
UPDATE `creature_template` SET `ScriptName` = 'mob_volatile_felfire_fiend' WHERE `entry` = 25598;
UPDATE `creature_template` SET `ScriptName` = 'mob_armageddon' WHERE `entry` = 25735;
UPDATE `creature_template` SET `ScriptName` = 'mob_shield_orb' WHERE `entry` = 25502;
UPDATE `creature_template` SET `ScriptName` = 'mob_sinster_reflection' WHERE `entry` = 25708;
UPDATE `gameobject_template` SET `ScriptName` = 'go_orb_of_the_blue_flight' WHERE `entry` = 188415;

-- M'uru& Entropius --
UPDATE `creature_template` SET `ScriptName` = "npc_void_sentinel" WHERE `entry` = 25772;
UPDATE `creature_template` SET `ScriptName` = "npc_dark_fiend" WHERE `entry` = 25744;
UPDATE `creature_template` SET `ScriptName` = "boss_muru" WHERE `entry` = 25741;
UPDATE `creature_template` SET `ScriptName` = "boss_entropius" WHERE `entry` = 25840;
UPDATE `creature_template` SET `ScriptName` = "npc_muru_portal" WHERE `entry` = 25770;
UPDATE `creature_template` SET `ScriptName` = "mob_eventai" WHERE `entry` = 25798;
