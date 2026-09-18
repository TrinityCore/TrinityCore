--
UPDATE `creature_template` SET `ScriptName` = 'npc_wild_shadow_fissure' WHERE `entry` = 18370;
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `unit_flags` = 0x02000000 WHERE `entry` = 18370;
UPDATE `creature_template` SET `minlevel` = 71, `maxlevel` = 71, `unit_flags` = 0x02000000 WHERE `entry` = 20598;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (30735,30741,32251,30745);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,30735,0,0,58,0,0,0,0,"FelOrcConvertNethekurseEvent",0,0,0,"","Group 0: Spell 'Shadow Sear' (Effect 0) targets creature 'Fel Orc Convert'"),
(13,3,30741,0,0,58,0,0,0,0,"FelOrcConvertNethekurseEvent",0,0,0,"","Group 0: Spell 'Death Coil' (Effect 0, 1) targets creature 'Fel Orc Convert'"),
(13,1,32251,0,0,58,0,0,0,0,"FelOrcConvertNethekurseEvent",0,0,0,"","Group 0: Spell 'Consumption' (Effect 0) targets creature 'Fel Orc Convert'"),
(13,1,30745,0,0,58,0,0,0,0,"FelOrcConvertNethekurseEvent",0,0,0,"","Group 0: Spell 'Target Fissures' (Effect 0) targets creature 'Fel Orc Convert'");

UPDATE `creature` SET `StringId` = 'FelOrcConvertNethekurseEvent' WHERE `guid` IN (59478,59479,59480,59481) AND `id` = 17083;

UPDATE `creature` SET `position_x` = 164.71588134765625, `position_y` = 266.263031005859375, `position_z` = -13.1121978759765625, `orientation` = 1.047197580337524414, `VerifiedBuild` = 14007 WHERE `guid` = 59478 AND `id` = 17083;
UPDATE `creature` SET `position_x` = 174.04949951171875, `position_y` = 269.132476806640625, `position_z` = -13.0549201965332031, `orientation` = 1.448623299598693847, `VerifiedBuild` = 14007 WHERE `guid` = 59479 AND `id` = 17083;
UPDATE `creature` SET `position_x` = 184.4263458251953125, `position_y` = 269.293731689453125, `position_z` = -13.0555877685546875, `orientation` = 1.727875947952270507, `VerifiedBuild` = 14007 WHERE `guid` = 59480 AND `id` = 17083;
UPDATE `creature` SET `position_x` = 194.48394775390625, `position_y` = 267.07208251953125, `position_z` = -13.1039943695068359, `orientation` = 2.181661605834960937, `VerifiedBuild` = 14007 WHERE `guid` = 59481 AND `id` = 17083;

DELETE FROM `creature_text` WHERE `CreatureID` = 17083;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17083,0,0,"We are the true Horde!",12,0,100,0,0,0,16697,0,"Fel Orc Convert"),
(17083,0,1,"For Kargath!  For Victory!",12,0,100,0,0,0,16698,0,"Fel Orc Convert"),
(17083,0,2,"Gakarah ma!",12,0,100,0,0,0,16699,0,"Fel Orc Convert"),
(17083,0,3,"The blood is our power!",12,0,100,0,0,0,16700,0,"Fel Orc Convert"),
(17083,0,4,"Lok'tar Illadari!
",12,0,100,0,0,0,16701,0,"Fel Orc Convert"),
(17083,0,5,"This world is OURS!",12,0,100,0,0,0,16702,0,"Fel Orc Convert"),
(17083,0,6,"Lok narash!",12,0,100,0,0,0,16703,0,"Fel Orc Convert"),
-- Not sure if these are grouped correctly, based on few sniffs
-- By the way, language is correct, verified, not a typo
-- Text 14143 seems to be unused, not added here
(17083,1,0,"It hurt!",14,0,100,0,0,0,14136,0,"Fel Orc Convert - Shadow Sear"),
(17083,1,1,"Augh! No more hurt!",14,0,100,0,0,0,14137,0,"Fel Orc Convert - Shadow Sear"),
(17083,1,2,"This not good tickle!",14,0,100,0,0,0,14138,0,"Fel Orc Convert - Shadow Sear"),
(17083,1,3,"Skin on fire!",14,0,100,0,0,0,14139,0,"Fel Orc Convert - Shadow Sear"),

(17083,2,0,"It hurt!",14,1,100,0,0,0,14140,0,"Fel Orc Convert - Death Coil"),
(17083,2,1,"Aahhh!",14,1,100,0,0,0,14141,0,"Fel Orc Convert - Death Coil"),
(17083,2,2,"No more scary!",14,1,100,0,0,0,14142,0,"Fel Orc Convert - Death Coil"),
(17083,2,3,"No more!",14,1,100,0,0,0,14144,0,"Fel Orc Convert - Death Coil"),

(17083,3,0,"Pain!",14,1,100,0,0,0,14149,0,"Fel Orc Convert - Target Fissures"),
(17083,3,1,"It hurts!",14,1,100,0,0,0,14150,0,"Fel Orc Convert - Target Fissures"),
(17083,3,2,"Graaagggh!!",14,1,100,0,0,0,14151,0,"Fel Orc Convert - Target Fissures"),
(17083,3,3,"No more!!",14,1,100,0,0,0,14152,0,"Fel Orc Convert - Target Fissures");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_grand_warlock_nethekurse_target_fissures';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(30745, 'spell_grand_warlock_nethekurse_target_fissures');

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4347;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4347, 'at_shattered_halls_the_sewer');

UPDATE `gameobject_template` SET `ScriptName` = 'go_grand_warlock_chamber_door' WHERE `entry` = 182539;

DELETE FROM `creature_text` WHERE `CreatureID` = 16807;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16807,0,0,"Beg for your pitiful life!",14,0,100,11,0,10259,14130,0,"nethekurse SAY_TAUNT_SHADOW_SEAR"),
(16807,1,0,"Run, coward, run!   ",14,0,100,11,0,10260,14132,0,"nethekurse SAY_TAUNT_DEATH_COIL"),
(16807,2,0,"Your pain amuses me!",14,0,100,11,0,10261,14148,0,"nethekurse SAY_TAUNT_SHADOW_FISSURE"),

(16807,3,0,"You wish to fight us all at once? This should be amusing!
",14,0,100,0,0,10262,15594,0,"nethekurse SAY_AGGRO_ALL_ALIVE"),
(16807,4,0,"Come on, show me a real fight!",14,0,100,0,0,10272,15595,0,"nethekurse SAY_AGGRO_SOME_ALIVE"),
(16807,5,0,"Thank you for saving me the trouble. Now it's my turn to have some fun!
",14,0,100,0,0,10270,15589,0,"nethekurse SAY_AGGRO_ALL_DEAD"),

(16807,6,0,"You can have that one, I no longer need him!",14,0,100,11,0,10263,15569,0,"nethekurse SAY_PEON_ENGAGED_1"),
(16807,6,1,"Yes, beat him mercilessly! His skull is as thick as an ogre's!
",14,0,100,11,0,10264,15575,0,"nethekurse SAY_PEON_ENGAGED_2"),
(16807,6,2,"Don't waste your time on that one, he's weak!",14,0,100,11,0,10265,15573,0,"nethekurse SAY_PEON_ENGAGED_3"),
(16807,6,3,"You want him? Very well, take him!",14,0,100,11,0,10266,15572,0,"nethekurse SAY_PEON_ENGAGED_4"),

(16807,7,0,"One pitiful wretch down. Go on, take another one! ",14,0,100,0,0,10267,15579,0,"nethekurse SAY_PEON_DEFEATED_1"),
(16807,7,1,"Ah, what a waste... next!",14,0,100,0,0,10268,15584,0,"nethekurse SAY_PEON_DEFEATED_2"),
(16807,7,2,"I was going to kill him anyway!",14,0,100,0,0,10269,15582,0,"nethekurse SAY_PEON_DEFEATED_3"),

(16807,8,0,"I'm already bored!",14,0,100,0,0,10271,16864,0,"nethekurse SAY_SLAY_1"),
(16807,8,1,"I had more fun torturing the peons!",14,0,100,0,0,10273,16863,0,"nethekurse SAY_SLAY_2"),
(16807,8,2,"You lose.",14,0,100,0,0,10274,16865,0,"nethekurse SAY_SLAY_3"),
(16807,8,3,"Oh, just die!",14,0,100,0,0,10275,16866,0,"nethekurse SAY_SLAY_4"),

(16807,9,0,"What... a shame.",14,0,100,0,0,10276,16862,0,"nethekurse SAY_DEATH");

UPDATE `creature` SET `MovementType` = 2 WHERE `id` = 16807;
UPDATE `creature_template_addon` SET `path_id` = 578530, `SheathState` = 1 WHERE `entry` IN (16807,20568);

DELETE FROM `waypoint_data` WHERE `id` = 578530;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `action`, `orientation`, `move_type`,  `action_chance`) VALUES
(578530,1,178.51125,287.97794,-8.183065,0,0,NULL,0,100),
(578530,2,171.82281,289.97687,-8.185595,0,0,NULL,0,100),
(578530,3,178.51125,287.97794,-8.183065,0,0,NULL,0,100),
(578530,4,184.78966,290.36990,-8.181390,0,0,NULL,0,100);
