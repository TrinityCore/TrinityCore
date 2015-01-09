UPDATE `creature_template` SET `ScriptName`='npc_gunship' WHERE `entry`=37215; -- Orgrim's Hammer
UPDATE `creature_template` SET `ScriptName`='npc_gunship' WHERE `entry`=37540; -- The Skybreaker
UPDATE `creature_template` SET `ScriptName`='npc_high_overlord_saurfang_igb' WHERE `entry`=36939; -- High Overlord Saurfang
UPDATE `creature_template` SET `ScriptName`='npc_muradin_bronzebeard_igb' WHERE `entry`=36948; -- Muradin Bronzebeard
UPDATE `creature_template` SET `ScriptName`='npc_zafod_boombox' WHERE `entry`=37184; -- Zafod Boombox
UPDATE `creature_template` SET `ScriptName`='npc_gunship_boarding_leader' WHERE `entry` IN (36961,36960); -- Skybreaker Sergeant, Kor'kron Sergeant
UPDATE `creature_template` SET `ScriptName`='npc_gunship_boarding_add' WHERE `entry` IN (36950,36957); -- Skybreaker Marine, Kor'kron Reaver
UPDATE `creature_template` SET `ScriptName`='npc_gunship_gunner' WHERE `entry` IN (36969,36968); -- Skybreaker Rifleman, Kor'kron Axethrower
UPDATE `creature_template` SET `ScriptName`='npc_gunship_rocketeer' WHERE `entry` IN (36978,36982); -- Skybreaker Mortar Soldier, Kor'kron Rocketeer
UPDATE `creature_template` SET `ScriptName`='npc_gunship_mage' WHERE `entry` IN (37116,37117); -- Skybreaker Sorcerer, Kor'kron Battle-Mage
UPDATE `creature_template` SET `ScriptName`='npc_gunship_cannon' WHERE `entry` IN (36838,36839); -- Alliance Gunship Cannon, Horde Gunship Cannon

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_jokkum_eject_all';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_the_lich_king_eject_all_passengers';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_eject_all_passengers';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_rocket_pack';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_rocket_pack_useable';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_on_gunship_deck';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_periodic_trigger_with_power_cost';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_cannon_blast';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_incinerating_blast';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_overheat';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_below_zero';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_teleport_to_enemy_ship';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_burning_pitch_selector';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_burning_pitch';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_rocket_artillery';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_rocket_artillery_explosion';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_gunship_fall_teleport';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_check_for_players';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_igb_teleport_players_on_victory';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50630,'spell_gen_eject_all_passengers'),
(63109,'spell_gen_eject_all_passengers'),
(68576,'spell_gen_eject_all_passengers'),
(68721,'spell_igb_rocket_pack'),
(70348,'spell_igb_rocket_pack_useable'),
(70120,'spell_igb_on_gunship_deck'),
(70121,'spell_igb_on_gunship_deck'),
(69470,'spell_igb_periodic_trigger_with_power_cost'),
(69487,'spell_igb_periodic_trigger_with_power_cost'),
(69399,'spell_igb_cannon_blast'),
(70172,'spell_igb_cannon_blast'),
(69402,'spell_igb_incinerating_blast'),
(70175,'spell_igb_incinerating_blast'),
(69487,'spell_igb_overheat'),
(69705,'spell_igb_below_zero'),
(70104,'spell_igb_teleport_to_enemy_ship'),
(70397,'spell_igb_burning_pitch_selector'),
(70403,'spell_igb_burning_pitch_selector'),
(71335,'spell_igb_burning_pitch'),
(71339,'spell_igb_burning_pitch'),
(69678,'spell_igb_rocket_artillery'),
(70609,'spell_igb_rocket_artillery'),
(69679,'spell_igb_rocket_artillery_explosion'),
(67335,'spell_igb_gunship_fall_teleport'),
(70331,'spell_igb_check_for_players'),
(72340,'spell_igb_teleport_players_on_victory');

UPDATE `creature_template` SET `difficulty_entry_1`=0,`difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=36838; -- Alliance Gunship Cannon
UPDATE `creature_template` SET `difficulty_entry_1`=0,`difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=36839; -- Horde Gunship Cannon
UPDATE `creature_template` SET `difficulty_entry_1`=0,`difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=36970; -- Skybreaker Deckhand
UPDATE `creature_template` SET `difficulty_entry_1`=0,`difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=36971; -- Orgrim's Hammer Crew
UPDATE `creature_template` SET `difficulty_entry_1`=38157,`difficulty_entry_2`=38639,`difficulty_entry_3`=38640 WHERE `entry`=36948; -- Muradin Bronzebeard
UPDATE `creature_template` SET `difficulty_entry_1`=38156,`difficulty_entry_2`=38637,`difficulty_entry_3`=38638 WHERE `entry`=36939; -- High Overlord Saurfang
UPDATE `creature_template` SET `difficulty_entry_1`=38128,`difficulty_entry_2`=38699,`difficulty_entry_3`=38700 WHERE `entry`=37540; -- The Skybreaker
UPDATE `creature_template` SET `difficulty_entry_1`=38129,`difficulty_entry_2`=38701,`difficulty_entry_3`=38702 WHERE `entry`=37215; -- Orgrim's Hammer
UPDATE `creature_template` SET `difficulty_entry_1`=38256,`difficulty_entry_2`=38693,`difficulty_entry_3`=38694 WHERE `entry`=37116; -- Skybreaker Sorcerer
UPDATE `creature_template` SET `difficulty_entry_1`=38408,`difficulty_entry_2`=38689,`difficulty_entry_3`=38690 WHERE `entry`=36969; -- Skybreaker Rifleman
UPDATE `creature_template` SET `difficulty_entry_1`=38407,`difficulty_entry_2`=38687,`difficulty_entry_3`=38688 WHERE `entry`=36978; -- Skybreaker Mortar Soldier
UPDATE `creature_template` SET `difficulty_entry_1`=38406,`difficulty_entry_2`=38685,`difficulty_entry_3`=38686 WHERE `entry`=36950; -- Skybreaker Marine
UPDATE `creature_template` SET `difficulty_entry_1`=38261,`difficulty_entry_2`=38691,`difficulty_entry_3`=38692 WHERE `entry`=36961; -- Skybreaker Sergeant
UPDATE `creature_template` SET `difficulty_entry_1`=38257,`difficulty_entry_2`=38677,`difficulty_entry_3`=38678 WHERE `entry`=37117; -- Kor'kron Battle-Mage
UPDATE `creature_template` SET `difficulty_entry_1`=38403,`difficulty_entry_2`=38675,`difficulty_entry_3`=38676 WHERE `entry`=36968; -- Kor'kron Axethrower
UPDATE `creature_template` SET `difficulty_entry_1`=38405,`difficulty_entry_2`=38681,`difficulty_entry_3`=38682 WHERE `entry`=36982; -- Kor'kron Rocketeer
UPDATE `creature_template` SET `difficulty_entry_1`=38404,`difficulty_entry_2`=38679,`difficulty_entry_3`=38680 WHERE `entry`=36957; -- Kor'kron Reaver
UPDATE `creature_template` SET `difficulty_entry_1`=38262,`difficulty_entry_2`=38683,`difficulty_entry_3`=38684 WHERE `entry`=36960; -- Kor'kron Sergeant

UPDATE `creature_template` SET `spell1`=0,`spell2`=0,`spell3`=0,`spell4`=0,`spell5`=0,`spell6`=0,`spell7`=0,`spell8`=0 WHERE `entry` IN (36838,36839,36970,36971,36948,38157,38639,38640,36939,38156,38638,38637,37540,38128,38699,38700,37215,38129,38701,38702,
37116,38256,38693,38694,36969,38408,38689,38690,36978,38407,38687,38688,36950,38406,38685,38686,36961,38261,38691,38692,37117,38257,38677,38678,36968,38403,38675,38676,36982,38405,38681,38682,36957,38404,38679,38680,36960,38262,38683,38684,37227,37488);

UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=0,`faction_A`=1665,`faction_H`=1665,`npcflag`=0x1000000,`speed_walk`=1,`speed_run`=1,`unit_class`=4,`unit_flags`=0x4000,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`spell1`=69399,`spell2`=70174,`VehicleId`=554,`InhabitType`=1,`mechanic_immune_mask`=650854267 WHERE `entry`=36838; -- Alliance Gunship Cannon
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=0,`faction_A`=1665,`faction_H`=1665,`npcflag`=0x1000000,`speed_walk`=1,`speed_run`=1,`unit_class`=4,`unit_flags`=0x4000,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`spell1`=70172,`spell2`=69401,`VehicleId`=555,`InhabitType`=1,`mechanic_immune_mask`=650854267 WHERE `entry`=36839; -- Horde Gunship Cannon
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=0,`faction_A`=84,`faction_H`=84,`speed_walk`=1,`speed_run`=1.14286,`unit_flags`=0x300,`unit_flags2`=0x800,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`mechanic_immune_mask`=650854267 WHERE `entry`=36970; -- Skybreaker Deckhand
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=0,`faction_A`=83,`faction_H`=83,`speed_walk`=1,`speed_run`=1.14286,`unit_flags`=0x300,`unit_flags2`=0x800,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`mechanic_immune_mask`=650854267 WHERE `entry`=36971; -- Orgrim's Hammer Crew
UPDATE `creature_template` SET `gossip_menu_id`=10875,`minlevel`=83,`maxlevel`=83,`exp`=2,`faction_A`=84,`faction_H`=84,`npcflag`=0x1,`speed_walk`=1,`speed_run`=1.71429,`unit_flags`=0x8000,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=1500,`InhabitType`=1,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36948,38157,38639,38640); -- Muradin Bronzebeard
UPDATE `creature_template` SET `gossip_menu_id`=10954,`minlevel`=83,`maxlevel`=83,`exp`=2,`faction_A`=83,`faction_H`=83,`npcflag`=0x1,`speed_walk`=1,`speed_run`=1.71429,`unit_flags`=0x8000,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=1500,`InhabitType`=1,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36939,38156,38638,38637); -- High Overlord Saurfang
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`exp`=2,`faction_A`=35,`faction_H`=35,`speed_walk`=1,`speed_run`=1.42857,`unit_flags`=0,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=4,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (37540,38128,38699,38700); -- The Skybreaker
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`exp`=2,`faction_A`=35,`faction_H`=35,`speed_walk`=1,`speed_run`=1.42857,`unit_flags`=0,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=4,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (37215,38129,38701,38702); -- Orgrim's Hammer
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81,`exp`=0,`faction_A`=35,`faction_H`=35,`npcflag`=0x1000000,`speed_walk`=1,`speed_run`=1,`unit_class`=1,`unit_flags`=0,`unit_flags2`=0x800,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry`=37227; -- Teleport Portal
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81,`exp`=0,`faction_A`=35,`faction_H`=35,`npcflag`=0,`speed_walk`=1,`speed_run`=1,`unit_class`=1,`unit_flags`=0x2000000,`unit_flags2`=0x800,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry`=37488; -- Teleport Exit
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=84,`faction_H`=84,`speed_walk`=1,`speed_run`=1.71429,`unit_class`=2,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (37116,38256,38693,38694); -- Skybreaker Sorcerer
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=84,`faction_H`=84,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=1,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36969,38408,38689,38690); -- Skybreaker Rifleman
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=84,`faction_H`=84,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=1,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36978,38407,38687,38688); -- Skybreaker Mortar Soldier
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=84,`faction_H`=84,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=1,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36950,38406,38685,38686); -- Skybreaker Marine
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=84,`faction_H`=84,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=1,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36961,38261,38691,38692); -- Skybreaker Sergeant
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=83,`faction_H`=83,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=2,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (37117,38257,38677,38678); -- Kor'kron Battle-Mage
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=83,`faction_H`=83,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=1,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36968,38403,38675,38676); -- Kor'kron Axethrower
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=83,`faction_H`=83,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=1,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36982,38405,38681,38682); -- Kor'kron Rocketeer
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=83,`faction_H`=83,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=1,`unit_flags`=0x8040,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36957,38404,38679,38680); -- Kor'kron Reaver
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`exp`=2,`faction_A`=83,`faction_H`=83,`speed_walk`=1,`speed_run`=1.42857,`unit_class`=1,`unit_flags`=0x8040,`unit_flags2`=0x800,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry` IN (36960,38262,38683,38684); -- Kor'kron Sergeant
UPDATE `creature_template` SET `npcflag`=1,`gossip_menu_id`=10885,`mechanic_immune_mask`=650854267 WHERE `entry`=37184; -- Zafod Boombox
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`faction_A`=84,`faction_H`=84,`speed_walk`=1,`speed_run`=1.14286,`unit_class`=1,`unit_flags`=0x300,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry`=37182; -- High Captain Justin Bartlett
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`faction_A`=84,`faction_H`=84,`speed_walk`=1,`speed_run`=1.14286,`unit_class`=1,`unit_flags`=0x300,`unit_flags2`=0,`dynamicflags`=0,`baseattacktime`=2000,`InhabitType`=1,`flags_extra`=0,`mechanic_immune_mask`=650854267 WHERE `entry`=37833; -- Sky-Reaver Korm Blackscar

UPDATE `gameobject_template` SET `faction`=94,`flags`=16 WHERE `entry` IN (202178,202180,202177,202179); -- Gunship Armory
UPDATE `gameobject_template` SET `faction`=94,`flags`=16 WHERE `entry` IN (201873,201874,201872,201875); -- Gunship Armory

DELETE FROM `creature_text` WHERE `entry`=36939 AND `groupid` BETWEEN 0 AND 13;
DELETE FROM `creature_text` WHERE `entry`=36948 AND `groupid` BETWEEN 0 AND 14;
DELETE FROM `creature_text` WHERE `entry` IN (37184,36838,36839);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(36939, 0,0,'Rise up, sons and daughters of the Horde! Today we battle a hated enemy of the Horde! LOK''TAR OGAR!',14,0,100,0,0,17087,'High Overlord Saurfang - SAY_SAURFANG_INTRO_1'),
(36939, 1,0,'Kor''kron, take us out!',14,0,100,0,0,17088,'High Overlord Saurfang - SAY_SAURFANG_INTRO_2'),
(36939, 2,0,'What is that? Something approaching in the distance.',14,0,100,0,0,17089,'High Overlord Saurfang - SAY_SAURFANG_INTRO_3'),
(36939, 3,0,'ALLIANCE GUNSHIP! ALL HANDS ON DECK!',14,0,100,0,0,17090,'High Overlord Saurfang - SAY_SAURFANG_INTRO_4'),
(36939, 4,0,'You answer to Saurfang now!',14,0,100,0,0,17091,'High Overlord Saurfang - SAY_SAURFANG_INTRO_5'),
(36939, 5,0,'You will know our business soon. Kor''kron, ANNIHILATE THEM!',14,0,100,0,0,17092,'High Overlord Saurfang - SAY_SAURFANG_INTRO_6'),
(36939, 6,0,'This is not your battle, dwarf. Back down or we will be forced to destroy your ship.',14,0,100,0,0,17083,'High Overlord Saurfang - SAY_SAURFANG_INTRO_A'),
(36939, 7,0,'You DARE board my ship? Your death will come swiftly.',14,0,100,0,0,17083,'High Overlord Saurfang - SAY_SAURFANG_BOARD'),
(36939, 8,0,'Reavers, Sergeants, attack!',14,0,100,0,0,17081,'High Overlord Saurfang - SAY_SAURFANG_ENTER_SKYBREAKER'),
(36939, 9,0,'Axethrowers, hurl faster!',14,0,100,0,0,17079,'High Overlord Saurfang - SAY_SAURFANG_AXETHROWERS'),
(36939,10,0,'Rocketeers, reload!',14,0,100,0,0,17080,'High Overlord Saurfang - SAY_SAURFANG_ROCKETEERS'),
(36939,11,0,'We''re taking hull damage, get a battle-mage out here to shut down those cannons!',14,0,100,0,0,17082,'High Overlord Saurfang - SAY_SAURFANG_MAGES'),
(36939,12,0,'The Alliance falter. Onward to the Lich King!',14,0,100,0,0,17084,'High Overlord Saurfang - SAY_SAURFANG_VICTORY'),
(36939,13,0,'Damage control! Put those fires out. You haven''t seen the last of the Horde!',14,0,100,0,0,17085,'High Overlord Saurfang - SAY_SAURFANG_WIPE'),
(36948, 0,0,'Fire up the engines! We got a meetin'' with destiny, lads!',14,0,100,0,0,16962,'Muradin Bronzebeard - SAY_MURADIN_INTRO_1'),
(36948, 1,0,'Hold on to yer hats!',14,0,100,0,0,16963,'Muradin Bronzebeard - SAY_MURADIN_INTRO_2'),
(36948, 2,0,'What in the world is that? Grab me spyglass, crewman!',14,0,100,0,0,16964,'Muradin Bronzebeard - SAY_MURADIN_INTRO_3'),
(36948, 3,0,'By me own beard! HORDE SAILIN'' IN FAST ''N HOT!',14,0,100,0,0,16965,'Muradin Bronzebeard - SAY_MURADIN_INTRO_4'),
(36948, 4,0,'EVASIVE ACTION! MAN THE GUNS!',14,0,100,0,0,16966,'Muradin Bronzebeard - SAY_MURADIN_INTRO_5'),
(36948, 5,0,'Cowardly dogs! Ye blindsided us!',14,0,100,0,0,16967,'Muradin Bronzebeard - SAY_MURADIN_INTRO_6'),
(36948, 6,0,'Not me battle? I dunnae who ye think ye are, mister, but I got a score to settle with Arthas and yer not gettin'' in me way! FIRE ALL GUNS! FIRE! FIRE!',14,0,100,0,0,16968,'Muradin Bronzebeard - SAY_MURADIN_INTRO_7'),
(36948, 7,0,'Move yer jalopy or we''ll blow it out of the sky, orc! The Horde''s got no business here.',14,0,100,0,0,16969,'Muradin Bronzebeard - SAY_MURADIN_INTRO_H'),
(36948, 8,0,'What''s this then?! Ye won''t be takin'' this son o'' Ironforge''s vessel without a fight!',14,0,100,0,0,16958,'Muradin Bronzebeard - SAY_MURADIN_BOARD'),
(36948, 9,0,'Marines, Sergeants, attack!',14,0,100,0,0,16956,'Muradin Bronzebeard - SAY_MURADIN_ENTER_ORGRIMMS_HAMMER'),
(36948,10,0,'Riflemen, shoot faster!',14,0,100,0,0,16954,'Muradin Bronzebeard - SAY_MURADIN_RIFLEMAN'),
(36948,11,0,'Mortar team, reload!',14,0,100,0,0,16955,'Muradin Bronzebeard - SAY_MURADIN_MORTAR'),
(36948,12,0,'We''re taking hull damage, get a sorcerer out here to shut down those cannons!',14,0,100,0,0,16957,'Muradin Bronzebeard - SAY_MURADIN_SORCERERS'),
(36948,13,0,'Don''t say I didn''t warn ya, scoundrels! Onward, brothers and sisters!',14,0,100,0,0,16959,'Muradin Bronzebeard - SAY_MURADIN_VICTORY'),
(36948,14,0,'Captain Bartlett, get us out of here! We''re taken too much damage to stay afloat!',14,0,100,0,0,16960,'Muradin Bronzebeard - SAY_MURADIN_WIPE'),
(37184,0,0,'Rocket Pack Active!',15,0,100,0,0,0,'Zafod Boombox - SAY_ZAFOD_ROCKET_PACK_ACTIVE'),
(37184,1,0,'Rocket Pack Disabled. Move closer to Zafod Boombox to re-activate.',15,0,100,0,0,0,'Zafod Boombox - SAY_ZAFOD_ROCKET_PACK_DISABLED'),
(36838,0,0,'|TInterface\\Icons\\Spell_Fire_Flameshock.blp:20|t|cFFBC0000 OVERHEAT  |r|TInterface\\Icons\\Spell_Fire_Flameshock.blp:20|t',42,0,100,0,0,0,'Alliance Gunship Cannon - SAY_OVERHEAT'),
(36839,0,0,'|TInterface\\Icons\\Spell_Fire_Flameshock.blp:20|t|cFFBC0000 OVERHEAT  |r|TInterface\\Icons\\Spell_Fire_Flameshock.blp:20|t',42,0,100,0,0,0,'Horde Gunship Cannon - SAY_OVERHEAT');

DELETE FROM `gossip_menu` WHERE `entry` IN (10875,10954,10885);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(10875,15101),
(10954,15219),
(10885,15134),
(10885,15123);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10875,10885,10954);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10875,0,0,'My companions are all accounted for, Muradin. Let''s go!',1,1,0,0,0,0,''),
(10954,0,0,'My companions are all accounted for, Saurfang. Let''s go!',1,1,0,0,0,0,''),
(10885,0,0,'Yeah, I''m sure safety is your top priority. Give me a rocket pack.',1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10885;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10885;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (72347,70104,70173,69400,69402,70175,69705,70403,70397,70383,70374,70444,67335);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(15,10885,0,0,2,49278,1,0,1,'Gossip Option - Show Option if player does not have item 49278'),
(14,10885,15134,0,2,49278,1,0,1,'Gossip Option - Show text 15134 if player does not have item 49278'),
(14,10885,15123,0,2,49278,1,0,0,'Gossip Option - Show text 15123 if player has item 49278'),
(13,1,72347,0,31,3,38569,0,0,'Lock Players and Tap Chest - target Martyr Stalker (IGB/Saurfang)'),
(13,1,70104,0,31,3,37488,0,0,'Teleport to Enemy Ship - target Teleport Exit'),
(13,2,70173,0,31,3,37540,0,0,'Cannon Blast - target The Skybreaker'),
(13,2,69400,0,31,3,37215,0,0,'Cannon Blast - target Orgrim''s Hammer'),
(13,2,69402,0,31,3,37540,0,0,'Incinerating Blast - target The Skybreaker'),
(13,2,70175,0,31,3,37215,0,0,'Incinerating Blast - target Orgrim''s Hammer'),
(13,1,69705,0,31,3,36839,0,0,'Below Zero - target Horde Gunship Cannon'),
(13,1,69705,1,31,3,36838,0,0,'Below Zero - target Alliance Gunship Cannon'),
(13,1,70403,0,31,3,37547,0,0,'Burning Pitch - target Gunship Hull'),
(13,1,70397,0,31,3,37547,0,0,'Burning Pitch - target Gunship Hull'),
(13,1,70383,0,31,3,37215,0,0,'Burning Pitch - target Orgrim''s Hammer'),
(13,1,70374,0,31,3,37540,0,0,'Burning Pitch - target The Skybreaker'),
(13,1,70444,0,31,3,37116,0,0,'Explosion - target Skybreaker Sorcerer'),
(13,1,70444,1,31,3,36969,0,0,'Explosion - target Skybreaker Rifleman'),
(13,1,70444,2,31,3,36978,0,0,'Explosion - target Skybreaker Mortar Soldier'),
(13,1,70444,3,31,3,37117,0,0,'Explosion - target Kor''kron Battle-Mage'),
(13,1,70444,4,31,3,36968,0,0,'Explosion - target Kor''kron Axethrower'),
(13,1,70444,5,31,3,36982,0,0,'Explosion - target Kor''kron Rocketeer'),
(13,1,67335,0,31,3,37540,0,0,'Gunship Fall Teleport - target The Skybreaker'),
(13,1,67335,1,31,3,37215,0,0,'Gunship Fall Teleport - target Orgrim''s Hammer');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=68645;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`Comment`) VALUES
(17,0,68645,0,1,70348,0,0,0,173,'Rocket Pack - require Rocket Pack Useable');


DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (37227,36838,36839);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(37227,70104,3,0),
(36838,70510,1,0),
(36839,70510,1,0);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (68645,73077);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(68645,68721,1,'Rocket Pack - additional aura'),
(73077,69188,2,'Rocket Pack - linked aura');

DELETE FROM `creature_template_addon` WHERE `entry` IN (36838,36839,37184,37488);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(36838,0,0x0,0x1,'69470'), -- Alliance Gunship Cannon - Heat Drain
(36839,0,0x0,0x1,'69470'), -- Horde Gunship Cannon - Heat Drain
(37184,0,0x0,0x1,'69188 70348'), -- Zafod Boombox - Rocket Pack, Rocket Pack Useable
(37488,0,0x2000000,0x1,''); -- Teleport Exit

DELETE FROM `creature` WHERE `guid` IN (201047,201030);
SET @CGUID := 1379;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+58;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@CGUID+0,37540,672,15,1,31043,0,-13.1429,-0.36969,12.8909,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+1,37547,672,15,1,0,0,-50.1652,9.71624,23.5871,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+2,37547,672,15,1,0,0,-34.2702,-26.1897,21.3748,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+3,37547,672,15,1,0,0,-41.4456,-7.6475,20.4975,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+4,37519,672,15,1,0,0,-28.275,15.5946,20.5379,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+5,37547,672,15,1,0,0,-11.6446,-19.8518,20.8843,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+6,37547,672,15,1,0,0,-19.8822,-6.57876,20.5744,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+7,36948,672,15,1,0,0,1.34481,-0.077413,20.8492,3.15905,604800,0,0,1,0,0,0,0,0),
(@CGUID+8,32780,672,15,1,0,0,1.29247,-0.006242,20.8767,3.12414,604800,0,0,1,0,0,0,0,0),
(@CGUID+9,37547,672,15,1,0,0,0.554884,-1.2329,20.5371,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+10,37547,672,15,1,0,0,19.7229,-2.19379,33.0698,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+11,37547,672,15,1,0,0,8.5994,-28.5585,24.7992,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+12,37547,672,15,1,0,0,11.4584,16.3662,20.5419,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+13,37547,672,15,1,0,0,38.9434,-33.808,25.3962,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+14,37519,672,15,1,0,0,39.4475,0.136515,25.2321,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+15,37547,673,15,1,0,0,53.1563,29.0877,44.7302,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+16,37547,673,15,1,0,0,-58.1547,0.748094,41.8766,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+17,37547,673,15,1,0,0,-39.4953,16.6872,34.3943,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+18,37547,673,15,1,0,0,-27.097,27.9929,34.3631,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+19,37547,673,15,1,0,0,-15.0316,12.0216,33.8629,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+20,37547,673,15,1,0,0,9.46182,16.1523,35.1091,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+21,37547,673,15,1,0,0,27.6276,27.103,36.8003,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+22,36939,673,15,1,0,0,36.4055,0.184604,36.7153,3.10669,604800,0,0,1,0,0,0,0,0),
(@CGUID+23,37184,673,15,1,0,0,38.5985,18.0196,36.6939,3.94444,604800,0,0,1,0,0,0,0,0),
(@CGUID+24,37833,673,15,1,0,0,60.4547,0.021568,38.7034,3.12414,604800,0,0,1,0,0,0,0,0),
(@CGUID+25,37547,673,15,1,0,0,4.7803,-29.0523,35.0963,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+26,37547,673,15,1,0,0,23.4778,-7.53715,35.8162,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+27,37547,673,15,1,0,0,-5.60755,-6.35065,34.0036,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+28,37519,673,15,1,0,0,-19.9011,-11.1976,33.4849,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+29,37519,673,15,1,0,0,22.1763,-11.4125,34.9973,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+30,36971,673,15,1,0,0,-56.4357,12.2929,34.6332,2.51327,604800,0,0,1,0,0,0,0,0),
(@CGUID+31,36971,673,15,1,0,0,30.8803,22.7656,36.3547,1.69297,604800,0,0,1,0,0,0,0,0),
(@CGUID+32,36971,673,15,1,0,0,-26.8348,13.4803,34.6954,5.3058,604800,0,0,1,0,0,0,0,0),
(@CGUID+33,36971,673,15,1,0,0,-29.3313,-23.2348,33.9633,2.80988,604800,0,0,1,0,0,0,0,0),
(@CGUID+34,36971,673,15,1,0,0,-26.1657,-13.3904,34.679,0.890118,604800,0,0,1,0,0,0,0,0),
(@CGUID+35,36971,673,15,1,0,0,60.0911,-6.35005,38.9569,2.54818,604800,0,0,1,0,0,0,0,0),
(@CGUID+36,36971,673,15,1,0,0,59.6708,6.21392,39.0067,3.735,604800,0,0,1,0,0,0,0,0),
(@CGUID+37,36971,673,15,1,0,0,30.9602,-22.9078,36.363,4.46804,604800,0,0,1,0,0,0,0,0),
(@CGUID+38,36839,673,15,1,0,0,-15.6908,31.1423,34.391,1.5708,604800,0,0,1,0,0,0,0,0),
(@CGUID+39,37215,673,15,1,31044,0,3.8386,0.183334,24.1005,0,604800,0,0,1,0,0,0,0,0),
(@CGUID+40,36839,673,15,1,0,0,18.1923,29.8694,36.3265,1.55334,604800,0,0,1,0,0,0,0,0),
(@CGUID+41,36971,673,15,1,0,0,-54.3389,-14.5897,34.4998,3.9619,604800,0,0,1,0,0,0,0,0),
(@CGUID+42,37184,672,15,1,0,0,18.8226,9.700101,20.41841,3.106686,604800,0,0,1,0,0,0,0,0), -- Zafod Boombox (A)
(@CGUID+43,37182,672,15,1,0,0,42.78902,-0.010491,25.24052,3.124139,604800,0,0,1,0,0,0,0,0), -- High Captain Justin Bartlett
(@CGUID+44,36970,672,15,1,0,0,42.80151,25.06216,31.84073,4.756748,604800,0,0,1,0,0,0,0,0), -- Skybreaker Deckhand
(@CGUID+45,36970,672,15,1,0,0,35.651,20.29211,25.11613,1.58825,604800,0,0,1,0,0,0,0,0), -- Skybreaker Deckhand
(@CGUID+46,36970,672,15,1,0,0,29.25061,-6.920386,23.37144,3.455752,604800,0,0,1,0,0,0,0,0), -- Skybreaker Deckhand
(@CGUID+47,36970,672,15,1,0,0,35.57132,-20.18365,25.1162,4.712389,604800,0,0,1,0,0,0,0,0), -- Skybreaker Deckhand
(@CGUID+48,36970,672,15,1,0,0,9.26111,-22.73216,21.84549,5.864306,604800,0,0,1,0,0,0,0,0), -- Skybreaker Deckhand
(@CGUID+49,36970,672,15,1,0,0,-36.38065,2.928953,20.5322,1.570796,604800,0,0,1,0,0,0,0,0), -- Skybreaker Deckhand
(@CGUID+50,36970,672,15,1,0,0,-36.22218,-2.960294,20.53312,4.694936,604800,0,0,1,0,0,0,0,0), -- Skybreaker Deckhand
(@CGUID+51,36970,672,15,1,0,0,-64.70975,4.575944,23.52326,2.094395,604800,0,0,1,0,0,0,0,0), -- Skybreaker Deckhand
(@CGUID+52,36948,672,15,1,0,0,13.51547,-0.160213,20.87252,3.106686,604800,0,0,1,0,0,0,0,0), -- Muradin Bronzebeard (A)
(@CGUID+53,36838,672,15,1,0,0,-6.155821,-25.23873,21.70498,4.712389,604800,0,0,1,0,0,0,0,0), -- Alliance Gunship Cannon
(@CGUID+54,36838,672,15,1,0,0,-33.6443,-24.06576,21.68014,4.712389,604800,0,0,1,0,0,0,0,0), -- Alliance Gunship Cannon
(@CGUID+55,36838,672,10,1,0,0,-24.66251,-24.52669,21.64428,4.712389,604800,0,0,1,0,0,0,0,0), -- Alliance Gunship Cannon
(@CGUID+56,36838,672,10,1,0,0,-15.35026,-24.90373,21.62014,4.712389,604800,0,0,1,0,0,0,0,0), -- Alliance Gunship Cannon
(@CGUID+57,36839,673,10,1,0,0,11.17875,30.73435,35.95937,1.553343,604800,0,0,1,0,0,0,0,0), -- Horde Gunship Cannon
(@CGUID+58,36839,673,10,1,0,0,-8.200627,31.49327,34.52401,1.553343,604800,0,0,1,0,0,0,0,0); -- Horde Gunship Cannon

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+04,@CGUID+14,@CGUID+28,@CGUID+29,200879);
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(@CGUID+04,0,0x3000000,0x1,'70120'), -- Safe Area (IGB) - On Skybreaker Deck
(@CGUID+14,0,0x3000000,0x1,'70120'), -- Safe Area (IGB) - On Skybreaker Deck
(@CGUID+28,0,0x3000000,0x1,'70121'), -- Safe Area (IGB) - On Orgrim's Hammer Deck
(@CGUID+29,0,0x3000000,0x1,'70121'), -- Safe Area (IGB) - On Orgrim's Hammer Deck
(   200879,0,0x0000000,0x1,'69942'); -- Invisible Stalker (All Phases) - Phase Normal + Dungeon Encounter 1

SET @OGUID := 12;
DELETE FROM `gameobject` WHERE `id`=202211;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+7;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID+0,202178,673,1,1,-19.87256,-14.17484,33.63771,4.71239,0,0,0,1,604800,255,1), -- Gunship Armory
(@OGUID+1,202180,673,2,1,-19.87256,-14.17484,33.63771,4.71239,0,0,0,1,604800,255,1), -- Gunship Armory
(@OGUID+2,202177,673,4,1,-19.87256,-14.17484,33.63771,4.71239,0,0,0,1,604800,255,1), -- Gunship Armory
(@OGUID+3,202179,673,8,1,-19.87256,-14.17484,33.63771,4.71239,0,0,0,1,604800,255,1), -- Gunship Armory
(@OGUID+4,201873,672,1,1,-45.44891,-0.062003,20.56404,0.2697698,0,0,0,1,604800,255,1),
(@OGUID+5,201874,672,2,1,-45.44891,-0.062003,20.56404,0.2697698,0,0,0,1,604800,255,1),
(@OGUID+6,201872,672,4,1,-45.44891,-0.062003,20.56404,0.2697698,0,0,0,1,604800,255,1),
(@OGUID+7,201875,672,8,1,-45.44891,-0.062003,20.56404,0.2697698,0,0,0,1,604800,255,1);

DELETE FROM `spell_custom_attr` WHERE `entry` IN (72347);
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(72347,4096);

UPDATE `creature_model_info` SET `bounding_radius`=0.520500,`combat_reach`=2.25000,`gender`=0 WHERE `modelid`=30508; -- Muradin Bronzebeard
UPDATE `creature_model_info` SET `bounding_radius`=0.558000,`combat_reach`=2.25000,`gender`=0 WHERE `modelid`=30416; -- High Overlord Saurfang
UPDATE `creature_model_info` SET `bounding_radius`=0.500000,`combat_reach`=1.00000,`gender`=2 WHERE `modelid`=31043; -- The Skybreaker
UPDATE `creature_model_info` SET `bounding_radius`=0.500000,`combat_reach`=1.00000,`gender`=2 WHERE `modelid`=31044; -- Orgrim's Hammer
UPDATE `creature_model_info` SET `bounding_radius`=1.250000,`combat_reach`=1.25000,`gender`=2 WHERE `modelid`=30615; -- Teleport Portal, Teleport Exit
UPDATE `creature_model_info` SET `bounding_radius`=0.364000,`combat_reach`=2.62500,`gender`=1 WHERE `modelid`=30609; -- Skybreaker Sorcerer
UPDATE `creature_model_info` SET `bounding_radius`=0.615825,`combat_reach`=3.01875,`gender`=1 WHERE `modelid`=30610; -- Skybreaker Sorcerer
UPDATE `creature_model_info` SET `bounding_radius`=0.615825,`combat_reach`=3.01875,`gender`=0 WHERE `modelid`=30611; -- Skybreaker Sorcerer
UPDATE `creature_model_info` SET `bounding_radius`=0.347000,`combat_reach`=1.50000,`gender`=0 WHERE `modelid`=30603; -- Skybreaker Rifleman
UPDATE `creature_model_info` SET `bounding_radius`=0.381700,`combat_reach`=1.65000,`gender`=0 WHERE `modelid`=30604; -- Skybreaker Rifleman
UPDATE `creature_model_info` SET `bounding_radius`=0.347000,`combat_reach`=1.50000,`gender`=1 WHERE `modelid`=30605; -- Skybreaker Rifleman
UPDATE `creature_model_info` SET `bounding_radius`=0.416400,`combat_reach`=1.80000,`gender`=0 WHERE `modelid`=30602; -- Skybreaker Mortar Soldier
UPDATE `creature_model_info` SET `bounding_radius`=0.306000,`combat_reach`=1.50000,`gender`=0 WHERE `modelid`=30598; -- Skybreaker Marine
UPDATE `creature_model_info` SET `bounding_radius`=0.306000,`combat_reach`=1.50000,`gender`=0 WHERE `modelid`=30599; -- Skybreaker Marine
UPDATE `creature_model_info` SET `bounding_radius`=1.000000,`combat_reach`=1.50000,`gender`=0 WHERE `modelid`=30600; -- Skybreaker Marine
UPDATE `creature_model_info` SET `bounding_radius`=0.208000,`combat_reach`=1.50000,`gender`=1 WHERE `modelid`=30601; -- Skybreaker Marine
UPDATE `creature_model_info` SET `bounding_radius`=0.397800,`combat_reach`=1.95000,`gender`=0 WHERE `modelid`=30606; -- Skybreaker Sergeant
UPDATE `creature_model_info` SET `bounding_radius`=0.367200,`combat_reach`=1.80000,`gender`=0 WHERE `modelid`=30607; -- Skybreaker Sergeant
UPDATE `creature_model_info` SET `bounding_radius`=0.382500,`combat_reach`=1.87500,`gender`=0 WHERE `modelid`=30608; -- Skybreaker Sergeant
UPDATE `creature_model_info` SET `bounding_radius`=0.670250,`combat_reach`=2.62500,`gender`=0 WHERE `modelid`=30741; -- Kor'kron Battle-Mage
UPDATE `creature_model_info` SET `bounding_radius`=0.670250,`combat_reach`=2.62500,`gender`=0 WHERE `modelid`=30742; -- Kor'kron Battle-Mage
UPDATE `creature_model_info` SET `bounding_radius`=0.670250,`combat_reach`=2.62500,`gender`=1 WHERE `modelid`=30743; -- Kor'kron Battle-Mage
UPDATE `creature_model_info` SET `bounding_radius`=0.670250,`combat_reach`=2.62500,`gender`=1 WHERE `modelid`=30744; -- Kor'kron Battle-Mage
UPDATE `creature_model_info` SET `bounding_radius`=0.306000,`combat_reach`=1.50000,`gender`=0 WHERE `modelid`=30739; -- Kor'kron Axethrower
UPDATE `creature_model_info` SET `bounding_radius`=0.306000,`combat_reach`=1.50000,`gender`=0 WHERE `modelid`=30740; -- Kor'kron Axethrower
UPDATE `creature_model_info` SET `bounding_radius`=0.459000,`combat_reach`=2.25000,`gender`=0 WHERE `modelid`=30748; -- Kor'kron Rocketeer
UPDATE `creature_model_info` SET `bounding_radius`=0.459000,`combat_reach`=2.25000,`gender`=1 WHERE `modelid`=30749; -- Kor'kron Rocketeer
UPDATE `creature_model_info` SET `bounding_radius`=0.372000,`combat_reach`=1.50000,`gender`=0 WHERE `modelid`=30750; -- Kor'kron Reaver
UPDATE `creature_model_info` SET `bounding_radius`=0.372000,`combat_reach`=1.50000,`gender`=0 WHERE `modelid`=30751; -- Kor'kron Reaver
UPDATE `creature_model_info` SET `bounding_radius`=0.236000,`combat_reach`=1.50000,`gender`=1 WHERE `modelid`=30752; -- Kor'kron Reaver
UPDATE `creature_model_info` SET `bounding_radius`=0.520833,`combat_reach`=2.25000,`gender`=0 WHERE `modelid`=30745; -- Kor'kron Sergeant
UPDATE `creature_model_info` SET `bounding_radius`=0.520833,`combat_reach`=2.25000,`gender`=0 WHERE `modelid`=30746; -- Kor'kron Sergeant
UPDATE `creature_model_info` SET `bounding_radius`=0.520833,`combat_reach`=2.25000,`gender`=0 WHERE `modelid`=30747; -- Kor'kron Sergeant

DELETE FROM `creature_equip_template` WHERE `entry` IN (36948,36939,37116,36969,36950,36961,37117,36968,36957,36960,36970,36971,37182,37833);
INSERT INTO `creature_equip_template` (`entry`,`id`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(36948,1,49775,49774,0), -- Muradin Bronzebeard
(36939,1,49773,0,0), -- High Overlord Saurfang
(37116,1,39746,0,0), -- Skybreaker Sorcerer
(36969,1,0,0,12523), -- Skybreaker Rifleman
(36950,1,49687,0,0), -- Skybreaker Marine
(36961,1,49637,0,0), -- Skybreaker Sergeant
(37117,1,39746,0,0), -- Kor'kron Battle-Mage
(36968,1,49691,0,49873), -- Kor'kron Axethrower
(36957,1,49689,0,0), -- Kor'kron Reaver
(36960,1,34638,0,0), -- Kor'kron Sergeant
(36970,1,1493,0,0), -- Skybreaker Deckhand
(36971,1,11019,0,0), -- Orgrim's Hammer Crew
(37182,1,42757,0,2552), -- High Captain Justin Bartlett
(37833,1,43175,0,21554); -- Sky-Reaver Korm Blackscar

DELETE FROM `spell_target_position` WHERE `id` IN (70446,71284,72340);
INSERT INTO `spell_target_position` (`id`,`effIndex`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(70446,1,631,-437.078,2390.10,191.233,1.57080),
(71284,1,631,-437.447,2032.51,191.234,4.73831),
(72340,1,631,-548.983,2211.24,539.290,0.00576);

DELETE FROM `spell_scripts` WHERE `id`=50630;

DELETE FROM `gameobject_loot_template` WHERE `entry` IN (28045,28072,28057,28090);
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(28045,1,100,1,0,-12036,2),
(28045,49426,100,1,0,2,2), -- 10N, Emblem of Frost
(28072,1,100,1,0,-34251,2),
(28072,49426,100,1,0,2,2), -- 25N, Emblem of Frost
(28072,49908,38,1,0,1,1), -- 25N, Primordial Saronite
(28072,50274,-35,1,0,1,1), -- 25N, Shadowfrost Shard
(28057,1,100,1,0,-34263,2),
(28057,49426,100,1,0,2,2), -- 10H, Emblem of Frost
(28057,49908,38,1,0,1,1), -- 10H, Primordial Saronite
(28090,1,100,1,0,-34275,2),
(28090,49426,100,1,0,2,2), -- 25H, Emblem of Frost
(28090,49908,50,1,0,1,1), -- 25H, Primordial Saronite
(28090,50274,-75,1,0,1,1); -- 25H, Shadowfrost Shard

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (12771,12777,12947,13041,13052,13079,13080,13081,13094,13109,13110,13111,13187,13198,13333,13353);
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (12771,12777,12947,13041,13052,13079,13080,13081,13094,13109,13110,13111,13187,13198,13333,13353);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(13333,12,0,0,''), -- Lich King 10-player bosses defeated
(13353,12,1,0,''), -- Lich King 25-player bosses defeated
(12771,12,0,0,''), -- Storming the Citadel (10 player)
(13041,12,2,0,''), -- Heroic: Storming the Citadel (10 player)
(12947,12,0,0,''), -- Storming the Citadel (25 player)
(13052,12,3,0,''), -- Heroic: Storming the Citadel (25 player)
(12777,12,0,0,''), -- I'm on a Boat (10 player)
(13080,12,1,0,''), -- I'm on a Boat (25 player)
(13079,12,2,0,''), -- I'm on a Boat (10 player, Heroic)
(13081,12,3,0,''), -- I'm on a Boat (25 player, Heroic)
(12777,11,0,0,'achievement_im_on_a_boat'), -- I'm on a Boat (10 player)
(13080,11,0,0,'achievement_im_on_a_boat'), -- I'm on a Boat (25 player)
(13079,11,0,0,'achievement_im_on_a_boat'), -- I'm on a Boat (10 player, Heroic)
(13081,11,0,0,'achievement_im_on_a_boat'), -- I'm on a Boat (25 player, Heroic)
(13094,12,0,0,''), -- Gunship Battle victories (Icecrown 10 player)
(13110,12,2,0,''), -- Gunship Battle victories (Heroic Icecrown 10 player)
(13109,12,1,0,''), -- Gunship Battle victories (Icecrown 25 player)
(13111,12,3,0,''), -- Gunship Battle victories (Heroic Icecrown 25 player)
(13187,12,3,0,''),
(13198,12,2,0,'');
