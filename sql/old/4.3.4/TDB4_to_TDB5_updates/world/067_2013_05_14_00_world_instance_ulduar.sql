-- NPCs
SET @VOICE_OF_YOGG_SARON := 33280;
SET @YOGG_SARON := 33288;
SET @YOGG_SARON_H := 33955;
SET @SARA := 33134;
SET @SARA_H := 34332;
SET @BRAIN_OF_YOGG_SARON := 33890;
SET @BRAIN_OF_YOGG_SARON_H := 33954;
SET @OMINOUS_CLOUD := 33292;
SET @GUARDIAN_OF_YOGG_SARON := 33136;
SET @GUARDIAN_OF_YOGG_SARON_H := 33968;
SET @CORRUPTOR_TENTACLE := 33985;
SET @CORRUPTOR_TENTACLE_H := 33986;
SET @CONSTRICTOR_TENTACLE := 33983;
SET @CONSTRICTOR_TENTACLE_H := 33984;
SET @CRUSHER_TENTACLE := 33966;
SET @CRUSHER_TENTACLE_H := 33967;
SET @LAUGHING_SKULL := 33990;
SET @DEATH_RAY := 33881;
SET @DEATH_ORB := 33882;
SET @GARONA := 33436;
SET @KING_LLANE := 33437;
SET @SUIT_OF_ARMOR := 33433;
SET @THE_LICH_KING := 33441;
SET @IMMOLATED_CHAMPION := 33442;
SET @TURNED_CHAMPION := 33962;
SET @DEATHSWORN_ZEALOT := 33567;
SET @NELTHARION := 33523;
SET @ALEXSTRASZA := 33536;
SET @YSERA := 33495;
SET @MALYGOS := 33535;
SET @OBSIDIAN_CONSORT := 33720;
SET @AZURE_CONSORT := 33717;
SET @EMERALD_CONSORT := 33719;
SET @RUBY_CONSORT := 33716;
SET @YOGG_SARON_ILLUSIONS := 33552;
SET @TRIGGER := 28332; -- Generic Trigger LAB (Large AOI), maybe to start illusion events?
SET @FREYA_GOSSIP := 33241;
SET @HODIR_GOSSIP := 33213;
SET @THORIM_GOSSIP := 33242;
SET @MIMIRON_GOSSIP := 33244;
SET @FREYA_YS := 33410;
SET @HODIR_YS := 33411;
SET @MIMIRON_YS := 33412;
SET @THORIM_YS := 33413;
SET @IMMORTAL_GUARDIAN := 33988;
SET @IMMORTAL_GUARDIAN_H := 33989;
SET @MARKED_IMMORTAL_GUARDIAN := 36064;
SET @MARKED_IMMORTAL_GUARDIAN_H := 36067;
SET @SANITY_WELL := 33991;
SET @INFLUENCE_TENTACLE := 33943;
SET @INFLUENCE_TENTACLE_H := 33959;
SET @DESCEND_INTO_MADNESS := 34072;

SET @GUID := 62015;

-- GameObjects
SET @FLEE_TO_THE_SURFACE := 194625;
SET @DRAGON_SOUL := 194462;
SET @INSTANCE_PORTAL := 194338;
SET @CHAIR := 194360;

SET @GO_GUID := 17800;

DELETE FROM `creature_text` WHERE `entry` IN (@SARA,@YOGG_SARON,@VOICE_OF_YOGG_SARON,@GARONA,@KING_LLANE,@THE_LICH_KING,@IMMOLATED_CHAMPION,@NELTHARION,@YSERA,@MALYGOS,@YOGG_SARON_ILLUSIONS,@FREYA_GOSSIP,@HODIR_GOSSIP,@THORIM_GOSSIP,@MIMIRON_GOSSIP,@OMINOUS_CLOUD,@BRAIN_OF_YOGG_SARON);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SARA,0,0,'Help me! Please get them off me!',14,0,100,0,0,15771,'Sara - SAY_SARA_ULDUAR_SCREAM_1'),
(@SARA,1,0,'What do you want from me? Leave me alone!',14,0,100,0,0,15772,'Sara - SAY_SARA_ULDUAR_SCREAM_2'),
(@SARA,2,0,'The time to strike at the head of the beast will soon be upon us! Focus your anger and hatred on his minions!',14,0,100,457,0,15775,'Sara - SAY_SARA_AGGRO'),
(@SARA,3,0,'Yes! YES! Show them no mercy! Give no pause to your attacks!',14,0,100,0,0,15773,'Sara - SAY_SARA_FERVOR_HIT'),
(@SARA,4,0,'Let hatred and rage guide your blows!',14,0,100,0,0,15774,'SAY_SARA_BLESSING_HIT'),
(@SARA,5,0,'Could they have been saved?',14,0,100,0,0,15779,'Sara - SAY_SARA_KILL'),
(@SARA,5,1,'Powerless to act...',14,0,100,0,0,15778,'Sara - SAY_SARA_KILL'),
(@SARA,6,0,'I am the lucid dream.',14,0,100,457,0,15754,'Sara - SAY_SARA_TRANSFORM_1'),
(@SARA,7,0,'The monster in your nightmares.',14,0,100,457,0,0,'Sara - SAY_SARA_TRANSFORM_2'),
(@SARA,8,0,'The fiend of a thousand faces.',14,0,100,457,0,0,'Sara - SAY_SARA_TRANSFORM_3'),
(@SARA,9,0,'Cower before my true form.',14,0,100,457,0,0,'Sara - SAY_SARA_TRANSFORM_4'),
(@SARA,10,0,'Tremble, mortals, before the coming of the end!',14,0,100,0,0,15777,'Sara - SAY_SARA_DEATH_RAY'),
(@SARA,11,0,'Suffocate upon your own hate!',14,0,100,0,0,15776,'Sara - SAY_SARA_PSYCHOSIS_HIT'),
(@OMINOUS_CLOUD,0,0,'%s begins to boil upon touching $n!',16,0,100,0,0,0,'Ominous Cloud - EMOTE_OMINOUS_CLOUD_PLAYER_TOUCH'),
(@YOGG_SARON,0,0,'BOW DOWN BEFORE THE GOD OF DEATH!',14,0,100,0,0,0,'Yogg-Saron - SAY_YOGG_SARON_SPAWN'),
(@YOGG_SARON,1,0,'MADNESS WILL CONSUME YOU!',14,0,100,0,0,15756,'Yogg-Saron - SAY_YOGG_SARON_MADNESS'),
(@YOGG_SARON,2,0,'Portals open into %s''s mind!',41,0,100,0,0,0,'Yogg-Saron - EMOTE_YOGG_SARON_MADNESS'),
(@YOGG_SARON,3,0,'Look upon the true face of death and know that your end comes soon!',14,0,100,0,0,15755,'Yogg-Saron - SAY_YOGG_SARON_PHASE_3'),
(@YOGG_SARON,4,0,'Eternal suffering awaits!',14,0,100,0,0,15758,'Yogg-Saron - SAY_YOGG_SARON_DEAFENING_ROAR'),
(@YOGG_SARON,5,0,'%s opens his mouth wide!',41,0,100,0,0,0,'Yogg-Saron - EMOTE_YOGG_SARON_DEAFENING_ROAR'),
(@YOGG_SARON,6,0,'Your fate is sealed. The end of days is finally upon you and ALL who inhabit this miserable little seedling. Uulwi ifis halahs gag erh''ongg w''ssh.',14,0,100,0,0,15761,'Yogg-Saron - SAY_YOGG_SARON_DEATH'),
(@YOGG_SARON,7,0,'%s prepares to unleash Empowering Shadows!',41,0,100,0,0,0,'Yogg-Saron - EMOTE_YOGG_SARON_EMPOWERING_SHADOWS'),
(@YOGG_SARON,8,0,'%s goes berserk, extinguishing all life!',41,0,100,0,0,0,'Yogg-Saron - EMOTE_YOGG_SARON_EXTINGUISH_ALL_LIFE'),
(@VOICE_OF_YOGG_SARON,0,0,'Weak-minded fools!',15,0,100,0,0,15780,'Voice of Yogg-Saron - WHISPER_VOICE_PHASE_1_WIPE'),
(@VOICE_OF_YOGG_SARON,1,0,'Your will is no longer your own...',15,0,100,0,0,15759,'Voice of Yogg-Saron - WHISPER_VOICE_INSANE'),
(@VOICE_OF_YOGG_SARON,1,1,'Destroy them minion, your master commands it!',15,0,100,0,0,15760,'Voice of Yogg-Saron - WHISPER_VOICE_INSANE'),
(@BRAIN_OF_YOGG_SARON,0,0,'The illusion shatters and a path to the central chamber opens!',41,0,100,0,0,0,'Brain of Yogg-Saron - EMOTE_BRAIN_ILLUSION_SHATTERED'),
(@GARONA,0,0,'Bad news sire.',12,0,100,66,0,15538,'Garona'),
(@GARONA,1,0,'The clans are united under Blackhand in this assault. They will stand together until Stormwind has fallen.',12,0,100,274,0,15539,'Garona'),
(@GARONA,2,0,'Gul''dan is bringing up his warlocks by nightfall. Until then, the Blackrock clan will be trying to take the Eastern Wall.',12,0,100,1,0,15540,'Garona'),
(@GARONA,3,0,'The orc leaders agree with your assessment.',12,0,100,0,0,15541,'Garona'),
(@KING_LLANE,0,0,'We will hold until the reinforcements come. As long as men with stout hearts are manning the walls and throne Stormwind will hold.',12,0,100,274,0,15585,'King Llane'),
(@THE_LICH_KING,0,0,'Your resilience is admirable.',12,0,100,0,0,15598,'The Lich King'),
(@THE_LICH_KING,1,0,'I will break you as I broke him.',12,0,100,0,0,15599,'The Lich King'),
(@IMMOLATED_CHAMPION,0,0,'Arrrrrrgh!',14,0,100,0,0,15470,'Immolated Champion'),
(@IMMOLATED_CHAMPION,1,0,'I''m not afraid of you!',12,0,100,0,0,15471,'Immolated Champion'),
(@NELTHARION,0,0,'It is done... All have been given that which must be given. I now seal the Dragon Soul forever...',12,0,100,0,0,15631,'Neltharion'),
(@NELTHARION,1,0,'For it to be as it must, yes.',12,0,100,273,0,15632,'Neltharion'),
(@YSERA,0,0,'That terrible glow... should that be?',12,0,100,0,0,15702,'Ysera'), -- or sound 15784? they are the same
(@MALYGOS,0,0,'It is a weapon like no other. It must be like no other.',12,0,100,1,0,15610,'Malygos'),
(@YOGG_SARON_ILLUSIONS,0,0,'A thousand deaths... or one murder.',12,0,100,0,0,15762,'Yogg-Saron'), -- sound splited! 15763 - "or one murder".
(@YOGG_SARON_ILLUSIONS,1,0,'Your petty quarrels only make me stronger!',12,0,100,0,0,15764,'Yogg-Saron'),
(@YOGG_SARON_ILLUSIONS,2,0,'Yrr n''lyeth... shuul anagg!',12,0,100,0,0,15766,'Yogg-Saron'),
(@YOGG_SARON_ILLUSIONS,3,0,'He will learn... no king rules forever; only death is eternal!',12,0,100,0,0,15767,'Yogg-Saron'),
(@YOGG_SARON_ILLUSIONS,4,0,'His brood learned their lesson before too long. You will soon learn yours!',12,0,100,0,0,15765,'Yogg-Saron'),
(@FREYA_GOSSIP,0,0,'As you wish, $N.',12,0,100,0,0,0,'Freya (Observation Ring) - On Gossip Select'),
(@FREYA_GOSSIP,1,0,'Eonar, your servant calls for your blessing!',14,0,100,0,0,15535,'Freya (Observation Ring) - On Gossip Select'),
(@HODIR_GOSSIP,0,0,'As you wish, $N.',12,0,100,0,0,0,'Hodir (Observation Ring) - On Gossip Select'),
(@HODIR_GOSSIP,1,0,'The veil of winter will protect you, champions!',14,0,100,0,0,15559,'Hodir (Observation Ring) - On Gossip Select'),
(@THORIM_GOSSIP,0,0,'As you wish, $N.',12,0,100,0,0,0,'Thorim (Observation Ring) - On Gossip Select'),
(@THORIM_GOSSIP,1,0,'Golganneth, lend me your strengh! Grant my mortal allies the power of thunder!',14,0,100,0,0,15750,'Thorim (Observation Ring) - On Gossip Select'),
(@MIMIRON_GOSSIP,0,0,'As you wish, $N.',12,0,100,0,0,0,'Mimiron (Observation Ring) - On Gossip Select'),
(@MIMIRON_GOSSIP,1,0,'Combat matrix enhanced. Behold wonderous rapidity!',14,0,100,0,0,15630,'Mimiron (Observation Ring) - On Gossip Select');

DELETE FROM `npc_text` WHERE `ID` IN (14332,14333);
INSERT INTO `npc_text` (`ID`,`text0_0`,`text0_1`,`lang0`,`prob0`,`em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`,`text1_0`,`text1_1`,`lang1`,`prob1`,`em1_0`,`em1_1`,`em1_2`,`em1_3`,`em1_4`,`em1_5`,`text2_0`,`text2_1`,`lang2`,`prob2`,`em2_0`,`em2_1`,`em2_2`,`em2_3`,`em2_4`,`em2_5`,`text3_0`,`text3_1`,`lang3`,`prob3`,`em3_0`,`em3_1`,`em3_2`,`em3_3`,`em3_4`,`em3_5`,`text4_0`,`text4_1`,`lang4`,`prob4`,`em4_0`,`em4_1`,`em4_2`,`em4_3`,`em4_4`,`em4_5`,`text5_0`,`text5_1`,`lang5`,`prob5`,`em5_0`,`em5_1`,`em5_2`,`em5_3`,`em5_4`,`em5_5`,`text6_0`,`text6_1`,`lang6`,`prob6`,`em6_0`,`em6_1`,`em6_2`,`em6_3`,`em6_4`,`em6_5`,`text7_0`,`text7_1`,`lang7`,`prob7`,`em7_0`,`em7_1`,`em7_2`,`em7_3`,`em7_4`,`em7_5`,`WDBVerified`) VALUES
(14332,'Mortals, I am indebted to you for freeing me from the terrible corruption that besets this place. Though I have not yet recovered fully, I can help you battle Yogg-Saron.$B$BI can grant you and your friends the Resilience of Nature, increasing your damage and increasing healing taken from spells and effects. In addition, I can conjure Sanity Wells that will allow you to recover your Sanity when your grip on reality falters.','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,1),
(14333,'Mortals, I am indebted to you for freeing me from the terrible corruption that besets this place. Though I have not yet recovered fully, I can help you battle Yogg-Saron.$B$BI can grant you and your friends the Fury of the Storm, increasing your damage and maximum health. Should you be faced with evil so malevolent that it cannot be destroyed, I can channel all my power into a final Titanic Storm that will destroy even Immortals.','',0,1,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,'','',0,0,0,0,0,0,0,0,1);

DELETE FROM `gossip_menu` WHERE `entry` IN (10324,10333,10335,10336,10337);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(10324,14332),
(10333,14325),
(10335,14326),
(10337,14333),
(10336,14334);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (10324,10333,10335,10336,10337);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(10324,0,0,'Lend us your aid, keeper. Together we will defeat Yogg-Saron.',1,1,10333,0,0,0,''),
(10333,0,0,'Yes.',1,1,0,0,0,0,''), -- not sure if this menu_id is shared for all keepers
(10335,0,0,'Lend us your aid, keeper. Together we will defeat Yogg-Saron.',1,1,10333,0,0,0,''),
(10337,0,0,'Lend us your aid, keeper. Together we will defeat Yogg-Saron.',1,1,10333,0,0,0,''),
(10336,0,0,'Lend us your aid, keeper. Together we will defeat Yogg-Saron.',1,1,10333,0,0,0,'');

DELETE FROM `gameobject` WHERE `id` IN (@FLEE_TO_THE_SURFACE,@DRAGON_SOUL,@INSTANCE_PORTAL+0,@INSTANCE_PORTAL+1,@CHAIR+0,@CHAIR+1,@CHAIR+2,@CHAIR+3,@CHAIR+4,@CHAIR+5);
DELETE FROM `gameobject` WHERE `guid` BETWEEN @GO_GUID+0 AND @GO_GUID+11;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GO_GUID+0,@FLEE_TO_THE_SURFACE,603,3,1,1999.761,-57.29888,243.5464,0,0,0,0,1,604800,0,0),
(@GO_GUID+1,@FLEE_TO_THE_SURFACE,603,3,1,1943.855,-25.59109,243.7952,0,0,0,0,1,604800,0,0),
(@GO_GUID+2,@FLEE_TO_THE_SURFACE,603,3,1,2000.26,5.519748,243.1853,0,0,0,0,1,604800,0,0),
(@GO_GUID+3,@DRAGON_SOUL,603,3,1,2104.028,-25.21278,242.6467,0,0,0,0,1,604800,0,0),
(@GO_GUID+4,@INSTANCE_PORTAL+0,603,2,1,2178.255,-24.15329,248.345,3.141593,0,0,-1,0,604800,0,0),
(@GO_GUID+5,@INSTANCE_PORTAL+1,603,1,1,2178.255,-24.15329,248.345,3.141593,0,0,-1,0,604800,0,0),
(@GO_GUID+6,@CHAIR+0,603,3,1,1954.696,91.8725,239.6242,5.989951,0,0,-0.1460924,0.9892709,604800,0,0),
(@GO_GUID+7,@CHAIR+1,603,3,1,1961.835,65.23161,239.6471,3.686116,0,0,-0.9631653,0.2689101,604800,0,0),
(@GO_GUID+8,@CHAIR+2,603,3,1,1886.634,72.21145,239.6242,1.713894,0,0,0.755847,0.6547483,604800,0,0),
(@GO_GUID+9,@CHAIR+3,603,3,1,1944.326,106.1581,239.6471,3.686116,0,0,-0.9631653,0.2689101,604800,0,0),
(@GO_GUID+10,@CHAIR+4,603,3,1,1899.228,45.58289,239.6471,1.417184,0,0,0.6507654,0.7592788,604800,0,0),
(@GO_GUID+11,@CHAIR+5,603,3,1,1923.472,28.16412,239.6471,2.289849,0,0,0.9106789,0.413115,604800,0,0);

DELETE FROM `creature` WHERE `id` IN (@VOICE_OF_YOGG_SARON,@SARA,@BRAIN_OF_YOGG_SARON,@OMINOUS_CLOUD,@LAUGHING_SKULL,@THE_LICH_KING,@IMMOLATED_CHAMPION,@DEATHSWORN_ZEALOT,@GARONA,@KING_LLANE,@SUIT_OF_ARMOR,@NELTHARION,@MALYGOS,@ALEXSTRASZA,@YSERA,@OBSIDIAN_CONSORT,@AZURE_CONSORT,@EMERALD_CONSORT,@RUBY_CONSORT,@YOGG_SARON_ILLUSIONS,@TRIGGER,@SANITY_WELL);
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID+0 AND @GUID+7;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,@VOICE_OF_YOGG_SARON,603,3,1,0,0,1980.137,-25.74376,326.4671,0,604800,0,0,0,0,0,0,0,0),
(@GUID+1,@SARA,603,3,1,0,0,1980.43,-25.7708,329.3963,3.124139,604800,0,0,0,0,0,0,0,0),
(@GUID+2,@BRAIN_OF_YOGG_SARON,603,3,1,0,0,1981.622,-25.89063,261.6898,0.1047198,604800,0,0,0,0,0,0,0,0),
(@GUID+3,@SANITY_WELL,603,3,1,0,0,1899.941,0.330621,332.2957,0,604800,0,0,0,0,0,0,0,0),
(@GUID+4,@SANITY_WELL,603,3,1,0,0,1900.478,-51.23861,332.1303,0,604800,0,0,0,0,0,0,0,0),
(@GUID+5,@SANITY_WELL,603,3,1,0,0,1987.125,-91.27024,330.1858,0,604800,0,0,0,0,0,0,0,0),
(@GUID+6,@SANITY_WELL,603,3,1,0,0,1975.885,40.02165,331.0996,0,604800,0,0,0,0,0,0,0,0),
(@GUID+7,@SANITY_WELL,603,3,1,0,0,2042.559,-40.3667,329.2744,0,604800,0,0,0,0,0,0,0,0);
-- (@GUID+8,@TRIGGER,603,3,1,0,0,,604800,0,0,0,0,0,0,0,0), -- spawn was not found in sniffs (Icecrown vision)
-- (@GUID+9,@TRIGGER,603,3,1,0,0,1928.978,67.9108,242.4596,0,604800,0,0,0,0,0,0,0,0),
-- (@GUID+10,@TRIGGER,603,3,1,0,0,2113.323,-28.4375,242.8768,0,604800,0,0,0,0,0,0,0,0);

DELETE FROM `creature_summon_groups` WHERE `summonerId` IN (@VOICE_OF_YOGG_SARON,@BRAIN_OF_YOGG_SARON);
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(@VOICE_OF_YOGG_SARON,0,0,@OMINOUS_CLOUD,1993.538,-17.93403,324.9728,0,6,0),
(@VOICE_OF_YOGG_SARON,0,0,@OMINOUS_CLOUD,1968.158,-42.65644,324.9676,0,6,0),
(@VOICE_OF_YOGG_SARON,0,0,@OMINOUS_CLOUD,1952.901,-27.36388,325.6934,0,6,0),
(@VOICE_OF_YOGG_SARON,0,0,@OMINOUS_CLOUD,1991.673,-65.39913,328.3430,0,6,0),
(@VOICE_OF_YOGG_SARON,0,0,@OMINOUS_CLOUD,2018.573,4.088733,328.8741,0,6,0),
(@VOICE_OF_YOGG_SARON,0,0,@OMINOUS_CLOUD,2034.443,-25.29962,329.0554,0,6,0),
(@VOICE_OF_YOGG_SARON,0,1,@DESCEND_INTO_MADNESS,1964.596,-42.70562,325.0845,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,1,@DESCEND_INTO_MADNESS,1986.936,-46.21083,324.9798,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,1,@DESCEND_INTO_MADNESS,1989.495,-6.69694,325.0786,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,1,@DESCEND_INTO_MADNESS,1965.521,-8.089301,324.9476,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,2,@DESCEND_INTO_MADNESS,2000.841,-25.40006,325.192,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,2,@DESCEND_INTO_MADNESS,1960.216,-26.14138,325.0096,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,2,@DESCEND_INTO_MADNESS,1976.303,-47.82541,325.1116,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,2,@DESCEND_INTO_MADNESS,1997.688,-37.46083,325.039,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,2,@DESCEND_INTO_MADNESS,1998.07,-13.35666,325.1668,0,3,60000),
(@VOICE_OF_YOGG_SARON,0,2,@DESCEND_INTO_MADNESS,1976.992,-3.959093,325.1694,0,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@NELTHARION,2117.713,-25.27073,242.73,3.141593,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@MALYGOS,2107.963,-37.29351,242.73,2.024582,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@ALEXSTRASZA,2092.347,-25.26042,242.7301,6.265732,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@YSERA,2109.765,-14.37967,242.73,4.206244,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@OBSIDIAN_CONSORT,2146.88,-17.03125,239.8058,3.351032,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@OBSIDIAN_CONSORT,2146.24,-34.40451,239.8058,3.01942,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@AZURE_CONSORT,2113.33,-65.71007,239.8058,1.780236,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@AZURE_CONSORT,2139.83,-50.28646,239.8058,2.460914,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@EMERALD_CONSORT,2116.931,11.375,239.8058,4.415683,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@EMERALD_CONSORT,2136.641,-1.996528,239.8058,3.839724,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@RUBY_CONSORT,2069.479,-5.699653,239.8058,5.427974,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@RUBY_CONSORT,2069.298,-43.53168,239.8006,0.4712389,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@YOGG_SARON_ILLUSIONS,2109.695,-25.09549,222.3250,0,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@LAUGHING_SKULL,2134.533,18.86881,239.8042,1.850049,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@LAUGHING_SKULL,2063.156,27.95839,244.2707,5.288348,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@LAUGHING_SKULL,2070.133,-73.0108,242.5237,1.308997,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@LAUGHING_SKULL,2135.219,-41.44271,239.8027,5.846853,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@LAUGHING_SKULL,2088.254,5.053657,239.8672,0.9948376,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@LAUGHING_SKULL,2119.228,1.421441,239.8039,0,3,60000),
(@BRAIN_OF_YOGG_SARON,0,0,@LAUGHING_SKULL,2102.441,-75.04541,239.8635,1.658063,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@THE_LICH_KING,1908.557,-152.4427,240.0719,4.328416,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@IMMOLATED_CHAMPION,1903.599,-160.3576,240.1064,1.082104,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@TURNED_CHAMPION,1919.113,-160.9657,240.0659,2.700784,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1917.559,-135.7448,240.0730,4.188790,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1919.125,-140.9566,240.0730,3.979351,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1948.469,-136.2951,240.0707,3.438299,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1956.444,-138.4028,240.1078,3.368485,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1952.965,-130.5295,240.1347,3.804818,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1902.132,-111.3594,240.0698,4.852015,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1905.326,-104.7865,240.0523,4.764749,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1897.345,-106.6076,240.1444,4.939282,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@DEATHSWORN_ZEALOT,1912.129,-136.9340,240.0730,4.188790,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@YOGG_SARON_ILLUSIONS,1906.226,-155.8941,223.4727,0,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@LAUGHING_SKULL,1863.897,-100.9364,240.073,5.235988,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@LAUGHING_SKULL,1948.668,-152.4481,240.073,1.919862,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@LAUGHING_SKULL,1932.213,-93.62798,240.073,4.852015,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@LAUGHING_SKULL,1964.457,-149.5943,240.073,3.385939,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@LAUGHING_SKULL,1992.463,-131.2119,240.073,3.455752,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@LAUGHING_SKULL,1901.194,-90.4624,240.073,0.1396263,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@LAUGHING_SKULL,1923.746,-164.5339,240.073,3.455752,3,60000),
(@BRAIN_OF_YOGG_SARON,0,1,@LAUGHING_SKULL,1905.937,-133.1651,240.073,5.77704,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@GARONA,1931.064,60.5659,241.5013,2.084251,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@KING_LLANE,1928.349,66.05186,242.4596,5.113815,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@SUIT_OF_ARMOR,1956.503,72.19462,239.7495,3.281219,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@SUIT_OF_ARMOR,1951.04,49.88875,239.7495,2.495821,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@SUIT_OF_ARMOR,1931.14,38.46949,239.7495,1.710423,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@SUIT_OF_ARMOR,1908.993,44.26659,239.7495,0.9250245,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@SUIT_OF_ARMOR,1897.344,64.31419,239.7495,0.1396263,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@SUIT_OF_ARMOR,1903.393,86.60285,239.7495,5.61996,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@SUIT_OF_ARMOR,1923.342,98.01228,239.7495,4.834562,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@SUIT_OF_ARMOR,1945.442,92.17952,239.7495,4.049164,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@YOGG_SARON_ILLUSIONS,1929.160,67.75694,221.7322,0,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@LAUGHING_SKULL,1941.561,109.4812,239.7496,3.316126,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@LAUGHING_SKULL,1922.55,54.68001,241.1263,0.1919862,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@LAUGHING_SKULL,1893.146,44.24343,239.7496,0,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@LAUGHING_SKULL,1926.526,43.26215,239.7496,0.9948376,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@LAUGHING_SKULL,1904.3,73.70443,239.7496,4.276057,3,60000),
(@BRAIN_OF_YOGG_SARON,0,2,@LAUGHING_SKULL,1955.173,85.26153,239.7496,4.049164,3,60000);

-- ScriptNames
UPDATE `creature_template` SET `ScriptName`='boss_voice_of_yogg_saron' WHERE `entry`=@VOICE_OF_YOGG_SARON;
UPDATE `creature_template` SET `ScriptName`='boss_yogg_saron' WHERE `entry`=@YOGG_SARON;
UPDATE `creature_template` SET `ScriptName`='boss_sara' WHERE `entry`=@SARA;
UPDATE `creature_template` SET `ScriptName`='boss_brain_of_yogg_saron' WHERE `entry`=@BRAIN_OF_YOGG_SARON;
UPDATE `creature_template` SET `ScriptName`='npc_ominous_cloud' WHERE `entry`=@OMINOUS_CLOUD;
UPDATE `creature_template` SET `ScriptName`='npc_guardian_of_yogg_saron' WHERE `entry`=@GUARDIAN_OF_YOGG_SARON;
UPDATE `creature_template` SET `ScriptName`='npc_immortal_guardian' WHERE `entry` IN (@IMMORTAL_GUARDIAN,@MARKED_IMMORTAL_GUARDIAN);
UPDATE `creature_template` SET `ScriptName`='npc_corruptor_tentacle' WHERE `entry`=@CORRUPTOR_TENTACLE;
UPDATE `creature_template` SET `ScriptName`='npc_constrictor_tentacle' WHERE `entry`=@CONSTRICTOR_TENTACLE;
UPDATE `creature_template` SET `ScriptName`='npc_crusher_tentacle' WHERE `entry`=@CRUSHER_TENTACLE; -- should have UNIT_FLAG_PACIFIED? but it breaks tentacle's AI
UPDATE `creature_template` SET `ScriptName`='npc_descend_into_madness' WHERE `entry`=@DESCEND_INTO_MADNESS;
UPDATE `creature_template` SET `ScriptName`='npc_influence_tentacle' WHERE `entry` IN (@SUIT_OF_ARMOR,@DEATHSWORN_ZEALOT,@RUBY_CONSORT,@EMERALD_CONSORT,@OBSIDIAN_CONSORT,@AZURE_CONSORT,@INFLUENCE_TENTACLE);
UPDATE `creature_template` SET `ScriptName`='npc_observation_ring_keeper' WHERE `entry` IN (@FREYA_GOSSIP,@HODIR_GOSSIP,@THORIM_GOSSIP,@MIMIRON_GOSSIP);
UPDATE `creature_template` SET `ScriptName`='npc_yogg_saron_keeper' WHERE `entry` IN (@FREYA_YS,@HODIR_YS,@THORIM_YS,@MIMIRON_YS);
UPDATE `creature_template` SET `ScriptName`='npc_laughing_skull' WHERE `entry`=@LAUGHING_SKULL;
UPDATE `creature_template` SET `ScriptName`='npc_yogg_saron_illusions' WHERE `entry`=@YOGG_SARON_ILLUSIONS;
UPDATE `creature_template` SET `ScriptName`='npc_garona' WHERE `entry`=@GARONA;
UPDATE `creature_template` SET `ScriptName`='npc_turned_champion' WHERE `entry`=@TURNED_CHAMPION;

-- Difficulty entries
UPDATE `creature_template` SET `difficulty_entry_1`=@BRAIN_OF_YOGG_SARON_H WHERE `entry`=@BRAIN_OF_YOGG_SARON;
UPDATE `creature_template` SET `difficulty_entry_1`=@GUARDIAN_OF_YOGG_SARON_H WHERE `entry`=@GUARDIAN_OF_YOGG_SARON;
UPDATE `creature_template` SET `difficulty_entry_1`=@CORRUPTOR_TENTACLE_H WHERE `entry`=@CORRUPTOR_TENTACLE;
UPDATE `creature_template` SET `difficulty_entry_1`=@CONSTRICTOR_TENTACLE_H WHERE `entry`=@CONSTRICTOR_TENTACLE;
UPDATE `creature_template` SET `difficulty_entry_1`=@CRUSHER_TENTACLE_H WHERE `entry`=@CRUSHER_TENTACLE;
UPDATE `creature_template` SET `difficulty_entry_1`=@IMMORTAL_GUARDIAN_H WHERE `entry`=@IMMORTAL_GUARDIAN;
UPDATE `creature_template` SET `difficulty_entry_1`=@MARKED_IMMORTAL_GUARDIAN_H WHERE `entry`=@MARKED_IMMORTAL_GUARDIAN;
UPDATE `creature_template` SET `difficulty_entry_1`=@INFLUENCE_TENTACLE_H WHERE `entry`=@INFLUENCE_TENTACLE;

-- creature_template updates
UPDATE `creature_template` SET `gossip_menu_id`=10324,`npcflag`=1 WHERE `entry`=@FREYA_GOSSIP;
UPDATE `creature_template` SET `gossip_menu_id`=10335,`npcflag`=1 WHERE `entry`=@HODIR_GOSSIP;
UPDATE `creature_template` SET `gossip_menu_id`=10337,`npcflag`=1 WHERE `entry`=@THORIM_GOSSIP;
UPDATE `creature_template` SET `gossip_menu_id`=10336,`npcflag`=1 WHERE `entry`=@MIMIRON_GOSSIP;
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81,`unit_flags`=33554432 WHERE `entry`=@SANITY_WELL;
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`minlevel`=80,`maxlevel`=80,`unit_flags`=33554432 WHERE `entry` IN (@VOICE_OF_YOGG_SARON,@DEATH_ORB);
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`minlevel`=81,`maxlevel`=81,`unit_flags`=33554432 WHERE `entry` IN (@LAUGHING_SKULL,@DEATH_RAY);
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16,`minlevel`=82,`maxlevel`=82 WHERE `entry` IN (@CRUSHER_TENTACLE,@CRUSHER_TENTACLE_H);
UPDATE `creature_template` SET `exp`=2,`faction_A`=16,`faction_H`=16,`minlevel`=82,`maxlevel`=82 WHERE `entry` IN (@GUARDIAN_OF_YOGG_SARON,@GUARDIAN_OF_YOGG_SARON_H);
UPDATE `creature_template` SET `faction_A`=190,`faction_H`=190,`minlevel`=82,`maxlevel`=82 WHERE `entry` IN (@SUIT_OF_ARMOR,@DEATHSWORN_ZEALOT,@RUBY_CONSORT,@EMERALD_CONSORT,@OBSIDIAN_CONSORT,@AZURE_CONSORT,@INFLUENCE_TENTACLE,@INFLUENCE_TENTACLE_H);
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16 WHERE `entry` IN (@YOGG_SARON,@YOGG_SARON_H,@BRAIN_OF_YOGG_SARON,@BRAIN_OF_YOGG_SARON_H,@IMMORTAL_GUARDIAN,@IMMORTAL_GUARDIAN_H,@CONSTRICTOR_TENTACLE,@CONSTRICTOR_TENTACLE_H,@CORRUPTOR_TENTACLE,@CORRUPTOR_TENTACLE_H);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (@SARA,@SARA_H,@BRAIN_OF_YOGG_SARON,@BRAIN_OF_YOGG_SARON_H,@VOICE_OF_YOGG_SARON,@DEATH_ORB);
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`unit_flags`=33554688,`InhabitType`=4 WHERE `entry`=@YOGG_SARON_ILLUSIONS;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=@DESCEND_INTO_MADNESS;

-- Creature immunities
UPDATE `creature_template` SET `mechanic_immune_mask`=617299839 WHERE `entry` IN (@YOGG_SARON,@YOGG_SARON_H,@BRAIN_OF_YOGG_SARON,@BRAIN_OF_YOGG_SARON_H);
UPDATE `creature_template` SET `mechanic_immune_mask`=13312063 WHERE `entry` IN (@CRUSHER_TENTACLE,@CRUSHER_TENTACLE_H,@CONSTRICTOR_TENTACLE,@CONSTRICTOR_TENTACLE_H,@CORRUPTOR_TENTACLE,@CORRUPTOR_TENTACLE_H,@SUIT_OF_ARMOR,@DEATHSWORN_ZEALOT,@RUBY_CONSORT,@EMERALD_CONSORT,@OBSIDIAN_CONSORT,@AZURE_CONSORT,@INFLUENCE_TENTACLE,@INFLUENCE_TENTACLE_H);

UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=33 WHERE `modelid`=28951;

DELETE FROM `creature_template_addon` WHERE `entry` IN (@OMINOUS_CLOUD,@VOICE_OF_YOGG_SARON,@BRAIN_OF_YOGG_SARON,@BRAIN_OF_YOGG_SARON_H,@SARA,@SARA_H,@DEATH_ORB,@DEATHSWORN_ZEALOT);
INSERT INTO `creature_template_addon`(`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@OMINOUS_CLOUD,0,0,0,0,0,'63029'),
(@VOICE_OF_YOGG_SARON,0,0,50331648,0,0,''),
(@BRAIN_OF_YOGG_SARON,0,0,33554432,0,0,''),
(@BRAIN_OF_YOGG_SARON_H,0,0,33554432,0,0,''),
(@SARA,0,0,50331648,0,0,''),
(@SARA_H,0,0,50331648,0,0,''),
(@DEATH_ORB,0,0,50331648,0,0,''),
(@DEATHSWORN_ZEALOT,0,0,8,0,0,'');

-- DELETE FROM `spell_dbc` WHERE `Id`=63029;
-- INSERT INTO `spell_dbc` (`Id`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`AttributesEx7`,`Stances`,`StancesNot`,`Targets`,`CastingTimeIndex`,`AuraInterruptFlags`,`ProcFlags`,`ProcChance`,`ProcCharges`,`MaxLevel`,`BaseLevel`,`SpellLevel`,`DurationIndex`,`RangeIndex`,`StackAmount`,`EquippedItemClass`,`EquippedItemSubClassMask`,`EquippedItemInventoryTypeMask`,`Effect1`,`Effect2`,`Effect3`,`EffectDieSides1`,`EffectDieSides2`,`EffectDieSides3`,`EffectRealPointsPerLevel1`,`EffectRealPointsPerLevel2`,`EffectRealPointsPerLevel3`,`EffectBasePoints1`,`EffectBasePoints2`,`EffectBasePoints3`,`EffectMechanic1`,`EffectMechanic2`,`EffectMechanic3`,`EffectImplicitTargetA1`,`EffectImplicitTargetA2`,`EffectImplicitTargetA3`,`EffectImplicitTargetB1`,`EffectImplicitTargetB2`,`EffectImplicitTargetB3`,`EffectRadiusIndex1`,`EffectRadiusIndex2`,`EffectRadiusIndex3`,`EffectApplyAuraName1`,`EffectApplyAuraName2`,`EffectApplyAuraName3`,`EffectAmplitude1`,`EffectAmplitude2`,`EffectAmplitude3`,`EffectMultipleValue1`,`EffectMultipleValue2`,`EffectMultipleValue3`,`EffectMiscValue1`,`EffectMiscValue2`,`EffectMiscValue3`,`EffectMiscValueB1`,`EffectMiscValueB2`,`EffectMiscValueB3`,`EffectTriggerSpell1`,`EffectTriggerSpell2`,`EffectTriggerSpell3`,`EffectSpellClassMaskA1`,`EffectSpellClassMaskA2`,`EffectSpellClassMaskA3`,`EffectSpellClassMaskB1`,`EffectSpellClassMaskB2`,`EffectSpellClassMaskB3`,`EffectSpellClassMaskC1`,`EffectSpellClassMaskC2`,`EffectSpellClassMaskC3`,`MaxTargetLevel`,`SpellFamilyName`,`SpellFamilyFlags1`,`SpellFamilyFlags2`,`SpellFamilyFlags3`,`MaxAffectedTargets`,`DmgClass`,`PreventionType`,`DmgMultiplier1`,`DmgMultiplier2`,`DmgMultiplier3`,`AreaGroupId`,`SchoolMask`,`Comment`) VALUES
-- (63029,0x00000100,0x10000000,0,0,0,0,0,0,0,0,0,1,0,0,101,0,0,70,70,21,1,0,-1,0,0,6,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,23,0,0,1000,0,0,0,0,0,0,0,0,0,0,0,63030,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,'Ominous Cloud - SPELL_BOIL_OMINOUSLY_PERIODIC');

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (63795,62714,64468,64159,64125);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`) VALUES
(63795,63795,65301,0,0),
(62714,62714,65209,0,0),
(64468,64468,64486,0,0),
(64159,64159,64160,0,0),
(64125,64125,64126,0,0);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (62650,62670,62671,62702,63030,63050,63120,63305,63802,63830,63881,63984,64125,64174,64465,64466,64467,64132,64131,64161,63744,63745,63747,65206,64172,64059,64069,65238,63882,63993,64010,64013,64012,64148,64164,64168,64184,63795,63803,65301,64555);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(62650,'spell_yogg_saron_keeper_aura'),
(62670,'spell_yogg_saron_keeper_aura'),
(62671,'spell_yogg_saron_keeper_aura'),
(62702,'spell_yogg_saron_keeper_aura'),
(63030,'spell_yogg_saron_boil_ominously'),
(63050,'spell_yogg_saron_sanity'),
(63120,'spell_yogg_saron_insane'),
(63305,'spell_yogg_saron_grim_reprisal'),
(63802,'spell_yogg_saron_brain_link'),
(63803,'spell_yogg_saron_brain_link_damage'),
(63795,'spell_yogg_saron_psychosis'),
(65301,'spell_yogg_saron_psychosis'),
(63830,'spell_yogg_saron_malady_of_the_mind'),
(63881,'spell_yogg_saron_malady_of_the_mind'),
(63984,'spell_yogg_saron_hate_to_zero'),
(64125,'spell_yogg_saron_squeeze'),
(64174,'spell_yogg_saron_hodirs_protective_gaze'),
(64465,'spell_yogg_saron_shadow_beacon'),
(64466,'spell_yogg_saron_empowering_shadows_range_check'),
(64467,'spell_yogg_saron_empowering_shadows_missile'),
(64132,'spell_yogg_saron_constrictor_tentacle'),
(64131,'spell_yogg_saron_lunge'),
(64161,'spell_yogg_saron_empowered'),
(63744,'spell_yogg_saron_target_selectors'),
(63745,'spell_yogg_saron_target_selectors'),
(63747,'spell_yogg_saron_target_selectors'),
(65206,'spell_yogg_saron_target_selectors'),
(64172,'spell_yogg_saron_titanic_storm'),
(64059,'spell_yogg_saron_induce_madness'),
(64069,'spell_yogg_saron_match_health'),
(65238,'spell_yogg_saron_shattered_illusion'),
(63882,'spell_yogg_saron_death_ray_warning_visual'),
(63993,'spell_yogg_saron_cancel_illusion_room_aura'),
(64010,'spell_yogg_saron_nondescript'),
(64013,'spell_yogg_saron_nondescript'),
(64012,'spell_yogg_saron_revealed_tentacle'),
(64148,'spell_yogg_saron_diminsh_power'),
(64164,'spell_yogg_saron_lunatic_gaze'),
(64168,'spell_yogg_saron_lunatic_gaze'),
(64184,'spell_yogg_saron_in_the_maws_of_the_old_god'),
(64555,'spell_yogg_saron_insane_periodic');

DELETE FROM `spell_target_position` WHERE `id` IN (63989,63997,63998,63992);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(63989,603,1954.14,21.522,239.718,2.09439),
(63997,603,2043.12,-25.6981,239.721,0),
(63998,603,1949.13,-80.6744,239.99,4.18879),
(63992,603,1970.61,-25.5988,324.55,3.10346);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@DESCEND_INTO_MADNESS;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@DESCEND_INTO_MADNESS,63989,2,0),
(@DESCEND_INTO_MADNESS,63997,2,0),
(@DESCEND_INTO_MADNESS,63998,2,0);

DELETE FROM `disables` WHERE `SourceType`=4 AND `entry` IN (10187,10189,10293,10294,10388,10409,10410,10412,10414,10415,10416,10417);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10185,10187,10189,10296,10321,10322,10323,10324,10325,10326,10388,10409,10410,10412,10414,10415,10416,10417);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(10185,18,0,0,''),
(10185,12,0,0,''),
(10187,1,@SARA,0,''),
(10187,7,65157,0,''),
(10187,12,0,0,''),
(10189,1,@SARA,0,''),
(10189,7,65157,0,''),
(10189,12,1,0,''),
(10296,18,0,0,''),
(10296,12,1,0,''),
(10321,18,0,0,''),
(10321,12,1,0,''),
(10322,18,0,0,''),
(10322,12,1,0,''),
(10323,18,0,0,''),
(10323,12,1,0,''),
(10324,18,0,0,''),
(10324,12,0,0,''),
(10325,18,0,0,''),
(10325,12,0,0,''),
(10326,18,0,0,''),
(10326,12,0,0,''),
(10388,18,0,0,''),
(10388,12,0,0,''),
(10409,18,0,0,''),
(10409,12,0,0,''),
(10410,18,0,0,''),
(10410,12,0,0,''),
(10412,18,0,0,''),
(10412,12,0,0,''),
(10414,18,0,0,''),
(10414,12,1,0,''),
(10415,18,0,0,''),
(10415,12,1,0,''),
(10416,18,0,0,''),
(10416,12,1,0,''),
(10417,18,0,0,''),
(10417,12,1,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62714,65209,62978,63037,63882,63884,63886,64059,64063,64069,64172,64173,64184,65238,63744,63745,63747,64465,64466,64555,65719,65206);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=64184;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=@DESCEND_INTO_MADNESS;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,@DESCEND_INTO_MADNESS,63997,0,0,13,0,38,0,0,0,0,0,'','Required instance data for spellclick'),
(18,@DESCEND_INTO_MADNESS,63998,0,0,13,0,38,1,0,0,0,0,'','Required instance data for spellclick'),
(18,@DESCEND_INTO_MADNESS,63989,0,0,13,0,38,2,0,0,0,0,'','Required instance data for spellclick'),
(13,2,62714,0,0,31,0,3,@GUARDIAN_OF_YOGG_SARON,0,0,0,0,'','Shadow Nova'),
(13,2,65209,0,0,31,0,3,@GUARDIAN_OF_YOGG_SARON,0,0,0,0,'','Shadow Nova'),
(13,1,62978,0,0,31,0,3,@OMINOUS_CLOUD,0,0,0,0,'','Summon Guardian'),
(13,1,63037,0,0,31,0,3,@IMMOLATED_CHAMPION,0,0,0,0,'','Deathgrasp'),
(13,1,63744,0,0,31,0,3,@GUARDIAN_OF_YOGG_SARON,0,0,0,0,'','Sara''s Anger'),
(13,1,63745,0,0,31,0,4,0,0,0,0,0,'','Sara''s Blessing'),
(13,1,63747,0,0,31,0,4,0,0,0,0,0,'','Sara''s Fervor'),
(13,1,63882,0,0,31,0,3,@DEATH_ORB,0,0,0,0,'','Death Ray Warning Visual'),
(13,1,63884,0,0,1,0,63120,0,0,1,0,0,'','Death Ray damage'),
(13,1,63884,0,0,1,0,63830,1,0,1,0,0,'','Death Ray damage'),
(13,1,63884,0,0,1,0,63881,1,0,1,0,0,'','Death Ray damage'),
(13,1,63886,0,0,31,0,3,@DEATH_ORB,0,0,0,0,'','Death Ray Damage Visual'),
(13,1,64059,0,0,31,0,4,0,0,0,0,0,'','Induce Madness'),
(13,1,64059,0,0,1,0,63988,0,0,0,0,0,'','Induce Madness'),
(13,1,64063,0,0,31,0,3,@KING_LLANE,0,0,0,0,'','Assassinate'),
(13,1,64069,0,0,31,0,3,@YOGG_SARON,0,0,0,0,'','Match Health'),
(13,1,64172,0,0,31,0,3,@IMMORTAL_GUARDIAN,0,0,0,0,'','Titanic Storm'),
(13,1,64172,0,0,1,0,64162,0,0,0,0,0,'','Titanic Storm'),
(13,1,64172,0,1,31,0,3,@MARKED_IMMORTAL_GUARDIAN,0,0,0,0,'','Titanic Storm'),
(13,1,64172,0,1,1,0,64162,0,0,0,0,0,'','Titanic Storm'),
(13,1,64173,0,0,31,0,3,@SARA,0,0,0,0,'','Shattered Illusion'),
(13,1,64173,0,1,31,0,3,@YOGG_SARON,0,0,0,0,'','Shattered Illusion'),
(13,1,64173,0,2,31,0,3,@CRUSHER_TENTACLE,0,0,0,0,'','Shattered Illusion'),
(13,1,64173,0,3,31,0,3,@CONSTRICTOR_TENTACLE,0,0,0,0,'','Shattered Illusion'),
(13,1,64173,0,4,31,0,3,@CORRUPTOR_TENTACLE,0,0,0,0,'','Shattered Illusion'),
(13,1,64184,0,0,31,0,3,@YOGG_SARON,0,0,0,0,'','In the Maws of the Old God'),
(13,1,65238,0,0,31,0,3,@SARA,0,0,0,0,'','Shattered Illusion remove'),
(13,1,65238,0,1,31,0,3,@YOGG_SARON,0,0,0,0,'','Shattered Illusion remove'),
(13,1,65238,0,2,31,0,3,@CRUSHER_TENTACLE,0,0,0,0,'','Shattered Illusion remove'),
(13,1,65238,0,3,31,0,3,@CONSTRICTOR_TENTACLE,0,0,0,0,'','Shattered Illusion remove'),
(13,1,65238,0,4,31,0,3,@CORRUPTOR_TENTACLE,0,0,0,0,'','Shattered Illusion remove'),
(13,1,64465,0,0,31,0,3,@IMMORTAL_GUARDIAN,0,0,0,0,'','Shadow Beacon'),
(13,1,64465,0,0,1,0,64497,0,0,1,0,0,'','Shadow Beacon'),
(13,1,64466,0,0,31,0,3,@YOGG_SARON,0,0,0,0,'','Empowering Shadows'),
(13,1,64555,0,0,1,0,63050,0,0,1,0,0,'','Insane Periodic'),
(13,1,65719,0,0,31,0,3,@SARA,0,0,0,0,'','Shadow Nova'),
(13,1,65206,0,0,31,0,3,@CORRUPTOR_TENTACLE,0,0,0,0,'','Destabilization Matrix'),
(13,1,65206,0,1,31,0,3,@CRUSHER_TENTACLE,0,0,0,0,'','Destabilization Matrix');

-- Loot
UPDATE `creature_loot_template` SET `lootmode`=32-`lootmode` WHERE `entry` IN (@YOGG_SARON,@YOGG_SARON_H);
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100,`lootmode`=32 WHERE `entry`=@YOGG_SARON_H AND `item`=45897;
