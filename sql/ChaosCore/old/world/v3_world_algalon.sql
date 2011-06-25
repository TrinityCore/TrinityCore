UPDATE `creature_template` SET `equipment_id` = 28053, `RegenHealth` = 0  WHERE `entry` = 32871; 
DELETE FROM `creature_equip_template` WHERE (`entry`= 28053);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES (28053, 45985, 45985, 0);

UPDATE `creature_template` SET `ScriptName` = 'mob_algalon_asteroid_trigger' WHERE `entry` = 33104;
UPDATE `creature_template` SET `ScriptName` = 'mob_living_constellation' WHERE `entry` = 33052;
UPDATE `creature_template` SET `ScriptName` = 'mob_collapsing_star' WHERE `entry` = 32955;
UPDATE `creature_template` SET `ScriptName` = 'mob_black_hole' WHERE `entry` = 32953;
UPDATE `creature_template` SET `ScriptName` = 'mob_dark_matter' WHERE `entry` = 33089;

UPDATE `creature_template` SET `equipment_id` = 1857, `ScriptName` = 'mob_brann_algalon' WHERE `entry` = 34064;

UPDATE `gameobject_template` SET `ScriptName` = 'go_celestial_console' WHERE `entry` = 194628;
UPDATE `gameobject_template` SET `flags` = 34 WHERE `entry` = 194628;

DELETE FROM `creature` WHERE `id`=32871;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(255916, 32871, 603, 1, 1, 0, 28053, 1632.11, -303.365, 432.321, 1.57079, 300, 0, 0, 8367000, 0, 0, 0, 0, 0, 0);

DELETE FROM `gameobject` WHERE `id`=194628;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(152446, 194628, 603, 1, 1, 1646.28, -175.381, 427.257, 1.57079, 0, 0, 0.723219, 0.690619, 300, 0, 1);

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=13 AND SourceEntry IN (62304,64996,64597,62168);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
( '13','0','62304','0','18','1','33104','0','0','','Algalon Cosmic Smash Missle'), -- 10 man
( '13','0','64597','0','18','1','33104','0','0','','Algalon Cosmic Smash Missle'), -- 25 man
( '13','0','64996','0','18','1','34246','0','0','','Algalon Reorigination'), -- visual
( '13','0','62168','0','18','1','0','0','0','','Black Hole Shift'); -- Players Only


DELETE FROM `spell_script_names` WHERE `spell_id` IN(64412,62293,62295,62311,64596,64443,64584,62168,62301,64598,64487,65312);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES 
( '64412','spell_algalon_phase_punch'),
( '62295','spell_algalon_summon_asteroid_stalkers'),
( '62293','spell_algalon_summon_asteroid_stalkers'),
( '62311','spell_algalon_cosmic_smash_damage'),
( '64596','spell_algalon_cosmic_smash_damage'),
( '64443','spell_algalon_big_bang'),
( '64584','spell_algalon_big_bang'),
( '62168','spell_algalon_black_hole'),
( '62301','spell_algalon_cosmic_smash_initial'), 
( '64598','spell_algalon_cosmic_smash_initial'),
( '64487','spell_algalon_ascend_to_the_heavens');


DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN(62168);
INSERT INTO `spell_linked_spell`(`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES ( '62168','62169','2','Algalon - Black Hole Damage');

DELETE FROM `creature_text` WHERE `entry` IN(32871,34064);

insert into `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) values
('32871','0','0','Your actions are illogical. All possible results for this encounter have been calculated. The Pantheon will receive the Observer''s message regardless of outcome.','14','0','100','1','0','15386','Algalon Aggro'),
('32871','1','0','Loss of life, unavoidable.','14','0','100','0','0','15837','Algalon JustKilled1'),
('32871','1','1','I do what I must.','14','0','100','0','0','15838','Algalon JustKilled2'),
('32871','2','0','See your world through my eyes: A universe so vast as to be immeasurable - incomprehensible even to your greatest minds.','14','0','100','1','0','15390','Algalon FirstEngaged'),
('32871','3','0','The stars come to my aid.','14','0','100','0','0','15392','Algalon SummonCollapsingStars'),
('32871','4','0','I have seen worlds bathed in the Makers'' flames. Their denizens fading without so much as a whimper. Entire planetary systems born and raised in the time that it takes your mortal hearts to beat once. Yet all throughout, my own heart, devoid of emotion... of empathy. I... have... felt... NOTHING! A million, million lives wasted. Had they all held within them your tenacity? Had they all loved life as you do?','12','0','100','0','0','15393','Algalon Death1'),
('32871','6','0','Perhaps it is your imperfection that which grants you free will. That allows you to persevere against all cosmically calculated odds. You prevailed where the Titans'' own perfect creations have failed.','12','0','100','1','0','15401','Algalon Death2'),
('32871','7','0','I''ve rearranged the reply code. Your planet will be spared. I cannot be certain of my own calculations anymore.','12','0','100','1','0','15402','Algalon Death3'),
('32871','8','0','I lack the strength to transmit the signal. You must hurry. Find a place of power close to the skies.','12','0','100','1','0','15403','Algalon Death4'),
('32871','9','0','Do not worry about my fate Bronzen. If the signal is not transmitted in time re-origination will proceed regardless. Save. Your. World.','12','0','100','1','0','15404','Algalon Death5'),
('32871','10','0','You are... out of time.','14','0','100','0','0','15394','Algalon Berserk'),
('32871','11','0','Witness the fury of the cosmos!','14','0','100','0','0','15396','Algalon BigBang'),
('32871','12','0','Behold the tools of creation!','14','0','100','0','0','15397','Algalon Phaseswitch'),
('32871','13','0','Trans-location complete. Commencing planetary analysis of Azeroth.','12','0','100','0','0','15405','Algalon Summon1'),
('32871','14','0','Stand back, mortals. I am not here to fight you.','12','0','100','0','0','15406','Algalon Summon2'),
('32871','15','0','It is in the universe''s best interest to re-originate this planet should my analysis find systemic corruption. Do not interfere.','12','0','100','0','0','15407','Algalon Summon3'),
('32871','16','0','Analysis complete. There is partial corruption in the planet''s life-support systems as well as complete corruption in most of the planet''s defense mechanisms.','14','0','100','1','0','15398','Algalon Timeout'),
('32871','17','0','Begin uplink: Reply Code: ''Omega''. Planetary re-origination requested..','14','0','100','1','0','15399','Algalon Timeout2'),
('32871','18','0','Farewell, mortals. Your bravery is admirable, for such flawed creatures.','14','0','100','1','0','15400','Algalon Timeout3'),
('32871','19','0','Algalon the Observer begins to Summon Collapsing Stars!','41','0','100','0','0','0','Algalon Summon Stars'),
('32871','20','0','Algalon the Observer begins to cast Cosmic Smash','41','0','100','0','0','0','Algalon Cosmic Smash'),
('32871','21','0','Algalon the Observer begins to cast Big Bang!','41','0','100','0','0','0','Algalon Big Bang'),
('34064','0','0','We did it, lads! We got here before Algalon''s arrival. Maybe we can rig the systems to interfere with his analysis--','14','0','100','0','0','15824','Brann AlgalonSummoned01'),
('34064','1','0','I''ll head back to the archivum and see if I can jam his signal. I might be able to buy us some time while you take care of him.','14','0','100','0','0','15825','Brann AlgalonSummoned02'),
('34064','2','0','I know just the place. Will you be all right?','12','0','100','0','0','15823','Brann AlgalonDefeated');
