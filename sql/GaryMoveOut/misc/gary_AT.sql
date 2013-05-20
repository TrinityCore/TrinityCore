-- fix quest The Aspirant's Challenge / Die Herausforderung des Streiters
-- set quest autocomplete to normal mode
UPDATE `quest_template` SET `Method` = 2 WHERE `Id` IN (13679,13680);
-- set correct killcredit
UPDATE `quest_template` SET `RequiredNpcOrGo1` = 38595 WHERE `Id` IN (13679,13680);
-- set missing next quest for horde
UPDATE `quest_template` SET `NextQuestID` = 13696 WHERE `Id` = 13680;
-- add missing lance for the Argent Valiant
UPDATE `creature` SET `equipment_id` = 1873 WHERE `id` = 33448;

UPDATE creature_template SET ScriptName = 'npc_argent_combatant' WHERE entry IN (33448, 33707);
UPDATE creature_template SET ScriptName = 'npc_argent_squire' WHERE entry IN (33447, 33518, 33522);

-- add mount for argent champion
DELETE FROM creature_template_addon WHERE entry = 33707;
INSERT INTO creature_template_addon (entry, path_id, mount, bytes1, bytes2, emote, auras) VALUES
(33707, 0, 28919, 0, 0, 0, '');

DELETE FROM `achievement_criteria_data` WHERE criteria_id IN (9918, 10224, 10225, 10226, 10227, 9919, 9920, 10228, 9921, 9922);
INSERT INTO `achievement_criteria_data` (criteria_id, type, value1, value2, ScriptName) VALUES
(9918, 5, 64805, 0, ''), -- Darnassus
(10224, 5, 64808, 0, ''), -- Exodar
(10225, 5, 64809, 0, ''), -- Gnomeregan
(10226, 5, 64810, 0, ''), -- Ironforge
(10227, 5, 64811, 0, ''), -- Orgrimmar
(9919, 5, 64812, 0, ''), -- Sen'Jin
(9920, 5, 64813, 0, ''), -- Silvermoon
(10228, 5, 64814, 0, ''), -- Stormwind
(9921, 5, 64815, 0, ''), -- Thunder Bluff
(9922, 5, 64816, 0, ''); -- Undercity

UPDATE creature_template SET ScriptName = 'npc_argent_faction_rider', gossip_menu_id = 0, speed_walk = 1.2, dmg_multiplier = 2, unit_flags = 256, flags_extra = 0 WHERE entry IN (33562, 33559, 33558, 33564, 33561, 33382, 33383, 33384, 33306, 33285, 33739, 33738, 33747, 33743, 33740, 33746, 33748, 33744, 33745,33749);

-- Debug QuestRelation A2
DELETE FROM `creature_questrelation` WHERE `quest` IN (13828, 13672, 13679, 13684, 13685, 13689, 13688, 13690);
INSERT `creature_questrelation` (`id`, `quest`) VALUES (33625, 13828), (33625, 13672), (33625, 13679), (33625, 13684), (33625, 13685), (33625,13689), (33625, 13688), (33625, 13690);

-- Debug QuestRelation H2
DELETE FROM `creature_questrelation` WHERE `quest` IN (13691, 13693, 13694, 13695, 13696, 13829, 13680, 13678);
INSERT `creature_questrelation` (`id`, `quest`) VALUES (33542, 13691), (33542, 13693), (33542, 13694), (33542, 13695), (33542, 13696), (33542,13829), (33542, 13680), (33542, 13678);

-- Quest : A Blade Fit for A Champion
UPDATE `creature_template` SET `ScriptName` = 'npc_lake_frog' WHERE `creature_template`.`entry` =33211 LIMIT 1 ;
UPDATE `creature_template` SET `npcflag` = `npcflag` | 1, `ScriptName` = 'npc_maiden_of_ashwood_lake' WHERE `creature_template`.`entry` =33220;
-- frog speed from sniff
UPDATE creature_template SET speed_run = 1 WHERE entry = 33211;
UPDATE creature_template SET speed_walk = 1.6 WHERE entry = 33211;

-- Quest : A Worthy Weapon
SET @DrakmarGUID := 199000; -- custom, cari guid kosong
DELETE FROM `gameobject` WHERE `id` =300009;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`)VALUES 
(@DrakmarGUID,'300009','571','1','1','4601.68','-1601.91','156.659','1.0243','0','0','0.490051','0.871694','1','0','1');
DELETE FROM `creature_text` WHERE `entry`= 33273;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(33273,0,0, 'Are those winter hyacinths? For me?',12,0,100,0,0,0, 'Maiden of Drak Mar 0'),
(33273,1,0, 'I had not brought flowers here for so long.It\'s been so long since a traveler has come here bearing flowers. It\'s been so long since a traveler has come here bearing flowers.',12,0,100,0,0,0, 'Maiden of Drak Mar 1'),
(33273,2,0, 'The lake has been too lonely these past years. The travelers stopped coming and evil came to these waters.',12,0,100,0,0,0, 'Maiden of Drak Mar 2'),
(33273,3,0, 'Your gift reveals a rare kindness, traveler. I beg you, take this blade as a token of my gratitude. Long ago, another passenger who had left here, but I have little use for it...',12,0,100,0,0,0, 'Maiden of Drak Mar 3');

DELETE FROM `event_scripts` WHERE `id`=20990;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `x`, `y`, `z`, `o`) VALUES (20990, 0, 10, 33273, 42000, 4602.977, -1600.141, 156.7834, 0.7504916);
UPDATE `creature_template` SET `InhabitType`=5, `ScriptName`='npc_maiden_of_drak_mar' WHERE `entry`=33273;
DELETE FROM `creature_template_addon` WHERE `entry`=33273;
INSERT INTO `creature_template_addon` (`entry`, `emote`) VALUES (33273, 13); -- 13 = EMOTE_STATE_SIT

-- Add Scripts to NPCs
UPDATE `creature_template` SET `ScriptName`='npc_quest_givers_argent_tournament' WHERE `entry` IN (33593, 33592, 33225, 33312, 33335, 33379, 33373, 33361, 33403, 33372);
UPDATE `creature_template` SET `ScriptName`='npc_quest_givers_for_crusaders' WHERE `entry` IN (34882, 35094);
UPDATE `creature_template` SET `ScriptName`='npc_crusader_rhydalla' WHERE `entry`=33417;
UPDATE `creature_template` SET `ScriptName`='npc_eadric_the_pure' WHERE `entry`=33759;
UPDATE `creature_template` SET `ScriptName`='npc_crok_scourgebane_argent' WHERE `entry`=33762;
UPDATE `creature_template` SET `ScriptName`='quest_givers_argent_tournament' WHERE `entry` IN (33593, 33592, 33225, 33312, 33335, 33379, 33373, 33361, 33403, 33372);
UPDATE `creature_template` SET `ScriptName`='npc_justicar_mariel_trueheart' WHERE `entry`=33817;

-- Horde Premiere quete : Le tournoi d'argent
DELETE FROM `creature_questrelation` WHERE `quest`=13668;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (33817, 13668);

-- Horde ArgentTournament  Aspirant Quests
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13668;
UPDATE `quest_template` SET `PrevQuestId`=13668, `NextQuestId`=13678, `ExclusiveGroup`=-13829, `NextQuestIdChain`=0 WHERE `id` IN (13829, 13839, 13838);
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=13680 WHERE `id`=13678;
	-- Daily Aspirant Quests
UPDATE `quest_template` SET `PrevQuestId`=-13678, `NextQuestId`=0, `ExclusiveGroup`=13673, `NextQuestIdChain`=0 WHERE `id`=13673;
UPDATE `quest_template` SET `PrevQuestId`=-13678, `NextQuestId`=0, `ExclusiveGroup`=13673, `NextQuestIdChain`=0 WHERE `id`=13675;
UPDATE `quest_template` SET `PrevQuestId`=-13678, `NextQuestId`=0, `ExclusiveGroup`=13673, `NextQuestIdChain`=0 WHERE `id`=13674;
UPDATE `quest_template` SET `PrevQuestId`=-13678, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13676;
UPDATE `quest_template` SET `PrevQuestId`=-13678, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13677;
	-- End Of Aspirant Quests
UPDATE `quest_template` SET `PrevQuestId`=13678, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13680;
	-- Valiant Quests
UPDATE `quest_template` SET `PrevQuestId`=13680 WHERE `id` IN (13691, 13693, 13694, 13695, 13696);

UPDATE `quest_template` SET `RequiredRaces`=2, `NextQuestId`=13697, `NextQuestIdChain`=13697, `ExclusiveGroup`=13691 WHERE `id`=13691;
UPDATE `quest_template` SET `RequiredRaces`=128, `NextQuestId`=13719, `NextQuestIdChain`=13719, `ExclusiveGroup`=13693 WHERE `id`=13693;
UPDATE `quest_template` SET `RequiredRaces`=32, `NextQuestId`=13720, `NextQuestIdChain`=13720, `ExclusiveGroup`=13694 WHERE `id`=13694;
UPDATE `quest_template` SET `RequiredRaces`=16, `NextQuestId`=13721, `NextQuestIdChain`=13721, `ExclusiveGroup`=13695 WHERE `id`=13695;
UPDATE `quest_template` SET `RequiredRaces`=512, `NextQuestId`=13722, `NextQuestIdChain`=13722, `ExclusiveGroup`=13696 WHERE `id`=13696;

-- INFOS DEV -- Premiere Quete (Admissibilité) : 13687 Deuxieme Quete (Champion) : 13701
UPDATE `quest_template` SET `PrevQuestId`=13701 WHERE `id` IN (13707, 13708, 13709, 13710, 13711); -- TOScript into the core (check of 13687)

UPDATE `quest_template` SET `NextQuestId`=13697, `NextQuestIdChain`=13697, `ExclusiveGroup`=13691 WHERE `id`=13707;
UPDATE `quest_template` SET `NextQuestId`=13719, `NextQuestIdChain`=13719, `ExclusiveGroup`=13693 WHERE `id`=13708;
UPDATE `quest_template` SET `NextQuestId`=13720, `NextQuestIdChain`=13720, `ExclusiveGroup`=13694 WHERE `id`=13709;
UPDATE `quest_template` SET `NextQuestId`=13721, `NextQuestIdChain`=13721, `ExclusiveGroup`=13695 WHERE `id`=13710;
UPDATE `quest_template` SET `NextQuestId`=13722, `NextQuestIdChain`=13722, `ExclusiveGroup`=13696 WHERE `id`=13711;

UPDATE `quest_template` SET `PrevQuestId`=0, `ExclusiveGroup`=0 WHERE `id` IN (13697, 13719, 13720, 13721, 13722);

UPDATE `quest_template` SET `NextQuestId`=13726, `NextQuestIdChain`=13726 WHERE `id`=13697;
UPDATE `quest_template` SET `NextQuestId`=13727, `NextQuestIdChain`=13727  WHERE `id`=13719;
UPDATE `quest_template` SET `NextQuestId`=13728, `NextQuestIdChain`=13728  WHERE `id`=13720;
UPDATE `quest_template` SET `NextQuestId`=13729, `NextQuestIdChain`=13729  WHERE `id`=13721;
UPDATE `quest_template` SET `NextQuestId`=13731, `NextQuestIdChain`=13731  WHERE `id`=13722;
	-- Valiant Daily Quests A Blade Fit For A Champion, The Edge Of Winter, A Worthy Weapon
UPDATE `quest_template` SET `PrevQuestId`=-13697, `NextQuestId`=0, `ExclusiveGroup`=13762, `NextQuestIdChain`=0 WHERE `id` IN (13762, 13763, 13764);
UPDATE `quest_template` SET `PrevQuestId`=-13719, `NextQuestId`=0, `ExclusiveGroup`=13768, `NextQuestIdChain`=0 WHERE `id` IN (13768, 13769, 13770);
UPDATE `quest_template` SET `PrevQuestId`=-13720, `NextQuestId`=0, `ExclusiveGroup`=13773, `NextQuestIdChain`=0 WHERE `id` IN (13773, 13774, 13775);
UPDATE `quest_template` SET `PrevQuestId`=-13721, `NextQuestId`=0, `ExclusiveGroup`=13778, `NextQuestIdChain`=0 WHERE `id` IN (13778, 13779, 13780);
UPDATE `quest_template` SET `PrevQuestId`=-13722, `NextQuestId`=0, `ExclusiveGroup`=13783, `NextQuestIdChain`=0 WHERE `id` IN (13783, 13784, 13785);
		-- A Valiant's Field Training, The Grand Melee, At The Enemy's Gates
UPDATE `quest_template` SET `PrevQuestId`=-13697, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13765, 13767, 13856);
UPDATE `quest_template` SET `PrevQuestId`=-13719, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13771, 13772, 13857);
UPDATE `quest_template` SET `PrevQuestId`=-13720, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13776, 13777, 13858);
UPDATE `quest_template` SET `PrevQuestId`=-13721, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13781, 13782, 13860);
UPDATE `quest_template` SET `PrevQuestId`=-13722, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13786, 13787, 13859);
	-- End Of Valiant Quests
UPDATE `quest_template` SET `PrevQuestId`=13697, `NextQuestId`=13736, `ExclusiveGroup`=0, `NextQuestIdChain`=13736 WHERE `id`=13726;
UPDATE `quest_template` SET `PrevQuestId`=13719, `NextQuestId`=13737, `ExclusiveGroup`=0, `NextQuestIdChain`=13737 WHERE `id`=13727;
UPDATE `quest_template` SET `PrevQuestId`=13720, `NextQuestId`=13738, `ExclusiveGroup`=0, `NextQuestIdChain`=13738 WHERE `id`=13728;
UPDATE `quest_template` SET `PrevQuestId`=13721, `NextQuestId`=13739, `ExclusiveGroup`=0, `NextQuestIdChain`=13739 WHERE `id`=13729;
UPDATE `quest_template` SET `PrevQuestId`=13722, `NextQuestId`=13740, `ExclusiveGroup`=0, `NextQuestIdChain`=13740 WHERE `id`=13731;
	-- A Champion Rises (Final Quest of a Branch)
UPDATE `quest_template` SET `PrevQuestId`=13726, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13736;
UPDATE `quest_template` SET `PrevQuestId`=13727, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13737;
UPDATE `quest_template` SET `PrevQuestId`=13728, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13738;
UPDATE `quest_template` SET `PrevQuestId`=13729, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13739;
UPDATE `quest_template` SET `PrevQuestId`=13740, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13740;

-- Debug Quest Requirements
UPDATE `quest_template` SET `RequiredRaces`=690 WHERE `id` IN (13697, 13719, 13720, 13721, 13722);
UPDATE `quest_template` SET `RequiredRaces`=690 WHERE `id` IN (13726, 13727, 13728, 13729, 13731);
UPDATE `quest_template` SET `RequiredRaces`=690 WHERE `id` IN (13736, 13737, 13738, 13739, 13740);

-- Alliance Premiere quete : Le tournoi d'argent
DELETE FROM `creature_questrelation` WHERE `quest`=13667;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES (33817, 13667);

-- Alliance ArgentTournament Aspirant Quests
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13667;
UPDATE `quest_template` SET `PrevQuestId`=13667, `NextQuestId`=13672, `ExclusiveGroup`=-13828, `NextQuestIdChain`=0 WHERE `id` IN (13828, 13837, 13835);
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=13679 WHERE `id`=13672;
	-- Daily Aspirant Quests
UPDATE `quest_template` SET `PrevQuestId`=-13672, `NextQuestId`=0, `ExclusiveGroup`=13666, `NextQuestIdChain`=0 WHERE `id`=13666;
UPDATE `quest_template` SET `PrevQuestId`=-13672, `NextQuestId`=0, `ExclusiveGroup`=13666, `NextQuestIdChain`=0 WHERE `id`=13670;
UPDATE `quest_template` SET `PrevQuestId`=-13672, `NextQuestId`=0, `ExclusiveGroup`=13666, `NextQuestIdChain`=0 WHERE `id`=13669;
UPDATE `quest_template` SET `PrevQuestId`=-13672, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13671;
UPDATE `quest_template` SET `PrevQuestId`=-13672, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13625;
	-- End Of Aspirant Quests
UPDATE `quest_template` SET `PrevQuestId`=13672, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13679;
	-- Valiant Quests
UPDATE `quest_template` SET `PrevQuestId`=13679 WHERE `id` IN (13684, 13685, 13689, 13688, 13690);

UPDATE `quest_template` SET `RequiredRaces`=1, `NextQuestId`=13718, `NextQuestIdChain`=13718, `ExclusiveGroup`=13684 WHERE `id`=13684;
UPDATE `quest_template` SET `RequiredRaces`=4, `NextQuestId`=13714, `NextQuestIdChain`=13714, `ExclusiveGroup`=13685 WHERE `id`=13685;
UPDATE `quest_template` SET `RequiredRaces`=8, `NextQuestId`=13717, `NextQuestIdChain`=13717, `ExclusiveGroup`=13689 WHERE `id`=13689;
UPDATE `quest_template` SET `RequiredRaces`=64, `NextQuestId`=13715, `NextQuestIdChain`=13715, `ExclusiveGroup`=13688 WHERE `id`=13688;
UPDATE `quest_template` SET `RequiredRaces`=1024, `NextQuestId`=13716, `NextQuestIdChain`=13716, `ExclusiveGroup`=13690 WHERE `id`=13690;

-- INFOS DEV -- Premiere Quete (Admissibilité) : 13686 Deuxieme Quete (Champion) : 13700
UPDATE `quest_template` SET `PrevQuestId`=13700 WHERE `id` IN (13593, 13703, 13706, 13704, 13705); -- TOScript into the core (check of 13686)

UPDATE `quest_template` SET `NextQuestId`=13718, `NextQuestIdChain`=13718, `ExclusiveGroup`=13718 WHERE `id`=13593;
UPDATE `quest_template` SET `NextQuestId`=13714, `NextQuestIdChain`=13714, `ExclusiveGroup`=13714 WHERE `id`=13703;
UPDATE `quest_template` SET `NextQuestId`=13717, `NextQuestIdChain`=13717, `ExclusiveGroup`=13717 WHERE `id`=13706;
UPDATE `quest_template` SET `NextQuestId`=13715, `NextQuestIdChain`=13715, `ExclusiveGroup`=13715 WHERE `id`=13704;
UPDATE `quest_template` SET `NextQuestId`=13716, `NextQuestIdChain`=13716, `ExclusiveGroup`=13716 WHERE `id`=13705;

UPDATE `quest_template` SET `PrevQuestId`=0, `ExclusiveGroup`=0 WHERE `id` IN (13718, 13714, 13717, 13715, 13716);

UPDATE `quest_template` SET `NextQuestId`=13699, `NextQuestIdChain`=13699 WHERE `id`=13718;
UPDATE `quest_template` SET `NextQuestId`=13713, `NextQuestIdChain`=13713  WHERE `id`=13714;
UPDATE `quest_template` SET `NextQuestId`=13725, `NextQuestIdChain`=13725  WHERE `id`=13717;
UPDATE `quest_template` SET `NextQuestId`=13723, `NextQuestIdChain`=13723  WHERE `id`=13715;
UPDATE `quest_template` SET `NextQuestId`=13724, `NextQuestIdChain`=13724  WHERE `id`=13716;
	-- Valiant Daily Quests, A Blade Fit For A Champion, The Edge Of Winter, A Worthy Weapon
UPDATE `quest_template` SET `PrevQuestId`=-13718, `NextQuestId`=0, `ExclusiveGroup`=13603, `NextQuestIdChain`=0 WHERE `id` IN (13603, 13600, 13616);
UPDATE `quest_template` SET `PrevQuestId`=-13714, `NextQuestId`=0, `ExclusiveGroup`=13741, `NextQuestIdChain`=0 WHERE `id` IN (13741, 13742, 13743);
UPDATE `quest_template` SET `PrevQuestId`=-13717, `NextQuestId`=0, `ExclusiveGroup`=13757, `NextQuestIdChain`=0 WHERE `id` IN (13757, 13758, 13759);
UPDATE `quest_template` SET `PrevQuestId`=-13715, `NextQuestId`=0, `ExclusiveGroup`=13746, `NextQuestIdChain`=0 WHERE `id` IN (13746, 13747, 13748);
UPDATE `quest_template` SET `PrevQuestId`=-13716, `NextQuestId`=0, `ExclusiveGroup`=13752, `NextQuestIdChain`=0 WHERE `id` IN (13752, 13753, 13754);
		-- A Valiant's Field Training, The Grand Melee, At The Enemy's Gates
UPDATE `quest_template` SET `PrevQuestId`=-13718, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13592, 13665, 13847);
UPDATE `quest_template` SET `PrevQuestId`=-13714, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13744, 13745, 13851);
UPDATE `quest_template` SET `PrevQuestId`=-13717, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13760, 13761, 13855);
UPDATE `quest_template` SET `PrevQuestId`=-13715, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13749, 13750, 13852);
UPDATE `quest_template` SET `PrevQuestId`=-13716, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id` IN (13755, 13756, 13854);
	-- End Of Valiant Quests
UPDATE `quest_template` SET `PrevQuestId`=13718, `NextQuestId`=13702, `ExclusiveGroup`=0, `NextQuestIdChain`=13702 WHERE `id`=13699;
UPDATE `quest_template` SET `PrevQuestId`=13714, `NextQuestId`=13732, `ExclusiveGroup`=0, `NextQuestIdChain`=13732 WHERE `id`=13713;
UPDATE `quest_template` SET `PrevQuestId`=13717, `NextQuestId`=13735, `ExclusiveGroup`=0, `NextQuestIdChain`=13735 WHERE `id`=13725;
UPDATE `quest_template` SET `PrevQuestId`=13715, `NextQuestId`=13733, `ExclusiveGroup`=0, `NextQuestIdChain`=13733 WHERE `id`=13723;
UPDATE `quest_template` SET `PrevQuestId`=13716, `NextQuestId`=13734, `ExclusiveGroup`=0, `NextQuestIdChain`=13734 WHERE `id`=13724;
	-- A Champion Rises (Final Quest of a Branch)
UPDATE `quest_template` SET `PrevQuestId`=13699, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13702;
UPDATE `quest_template` SET `PrevQuestId`=13713, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13732;
UPDATE `quest_template` SET `PrevQuestId`=13725, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13735;
UPDATE `quest_template` SET `PrevQuestId`=13723, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13733;
UPDATE `quest_template` SET `PrevQuestId`=13734, `NextQuestId`=13794, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13734;

-- Debug Quest Requirements
UPDATE `quest_template` SET `RequiredRaces`=1101 WHERE `id` IN (13718, 13714, 13717, 13715, 13716);
UPDATE `quest_template` SET `RequiredRaces`=1101 WHERE `id` IN (13699, 13713, 13725, 13723, 13724);
UPDATE `quest_template` SET `RequiredRaces`=1101 WHERE `id` IN (13702, 13732, 13735, 13733, 13734);


-- Black Night chain
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=13641, `ExclusiveGroup`=13633, `NextQuestIdChain`=13641 WHERE `id` IN (13633, 13634);
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=13643 WHERE `id`=13641;
UPDATE `quest_template` SET `PrevQuestId`=13641, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=13654 WHERE `id`=13643;
UPDATE `quest_template` SET `PrevQuestId`=13643, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=13663 WHERE `id`=13654;
UPDATE `quest_template` SET `PrevQuestId`=13654, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=13664 WHERE `id`=13663;
UPDATE `quest_template` SET `PrevQuestId`=13663, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=14016 WHERE `id`=13664;
UPDATE `quest_template` SET `PrevQuestId`=13664, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=14017 WHERE `id`=14016;
UPDATE `quest_template` SET `PrevQuestId`=14016, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=14017;

-- Champion Dailies
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13794; -- Eadric the Pure Works yet, but might bug with The Scourgebane
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13795; -- The Scourgebane
UPDATE `quest_template` SET `RequiredRaces`=1101, `PrevQuestId`=13794, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13790; -- Alliance Among The Champions
UPDATE `quest_template` SET `RequiredRaces`=1101, `PrevQuestId`=13795, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13793; -- Alliance DK Among The Champions
UPDATE `quest_template` SET `RequiredRaces`=690, `PrevQuestId`=13794, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13811; -- Horde Among The Champions
UPDATE `quest_template` SET `RequiredRaces`=690, `PrevQuestId`=13795, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13814; -- Horde DK Among The Champions
UPDATE `quest_template` SET `RequiredRaces`=1101, `PrevQuestId`=13794, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13861; -- Alliance Battle Before The Citadel
UPDATE `quest_template` SET `RequiredRaces`=1101, `PrevQuestId`=13795, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13864; -- Alliance DK Battle Before The Citadel
UPDATE `quest_template` SET `RequiredRaces`=690, `PrevQuestId`=13794, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13862; -- Horde Battle Before The Citadel
UPDATE `quest_template` SET `RequiredRaces`=690, `PrevQuestId`=13795, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13863; -- Horde DK Battle Before The Citadel
UPDATE `quest_template` SET `RequiredRaces`=1101, `PrevQuestId`=13794, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13789; -- Alliance Taking Battle To The Enemy
UPDATE `quest_template` SET `RequiredRaces`=1101, `PrevQuestId`=13795, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13791; -- Alliance DK Taking Battle To The Enemy
UPDATE `quest_template` SET `RequiredRaces`=690, `PrevQuestId`=13794, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13810; -- Horde Taking Battle To The Enemy
UPDATE `quest_template` SET `RequiredRaces`=690, `PrevQuestId`=13795, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13813; -- Horde DK Taking Battle To The Enemy
UPDATE `quest_template` SET `RequiredRaces`=1101, `PrevQuestId`=13794, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13682; -- Alliance Threat From Above
UPDATE `quest_template` SET `RequiredRaces`=1101, `PrevQuestId`=13795, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13788; -- Alliance DK Threat From Above
UPDATE `quest_template` SET `RequiredRaces`=690, `PrevQuestId`=13794, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13809; -- Horde Threat From Above
UPDATE `quest_template` SET `RequiredRaces`=690, `PrevQuestId`=13795, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13812;

-- Crusader dailies, Mistcaller Yngvar, Drottinn Hrothgar, Ornolf The Scarred, Deathspeaker Kharos
UPDATE `quest_template` SET `ExclusiveGroup`=14102, `NextQuestId`=0, `NextQuestIdChain`=0 WHERE `id` IN (14102, 14101, 14104, 14105);
	-- The Fate Of The Fallen, Get Kraken!, Identifying the Remains
UPDATE `quest_template` SET `ExclusiveGroup`=14107, `NextQuestId`=0, `NextQuestIdChain`=0 WHERE `id` IN (14107, 14108, 14095);

-- Covenant Quests
UPDATE `quest_template` SET `PrevQuestId`=13700, `RequiredMinRepFaction`=1094, `RequiredMinRepValue`=42000, `NextQuestId`=0, `NextQuestIdChain`=0 WHERE `id` IN (14112, 14076, 14090, 14096, 14152, 14080, 14077, 14074);
UPDATE `quest_template` SET `PrevQuestId`=13701, `RequiredMinRepFaction`=1124, `RequiredMinRepValue`=42000, `NextQuestId`=0, `NextQuestIdChain`=0 WHERE `id` IN (14145, 14092, 14141, 14142, 14136, 14140, 14144, 14143);
	-- What Do You Feed A Yeti, Anyway? Breakfast Of Champions, Gormok Wants His Snobolds
UPDATE `quest_template` SET `ExclusiveGroup`=14112 WHERE `id` IN (14112, 14145, 14076, 14092, 14090, 14141);
	-- You've Really Done It This Time, Kul, Rescue At Sea, Stop The Agressors, The Light's Mercy, A Leg Up
UPDATE `quest_template` SET `ExclusiveGroup`=14152 WHERE `id` IN (14152, 14136, 14080, 14140, 14077, 14144, 14074, 14143);

-- Champion Marker
UPDATE `quest_template` SET `NextQuestId`=13846, `ExclusiveGroup`=13700 WHERE `id` IN (13700, 13701);

-- Contributin' To The Cause
UPDATE `quest_template` SET `RequiredMaxRepFaction`=1106, `RequiredMaxRepValue`=42000 WHERE `id`=13846;

-- Goblin Dailies Removing
DELETE FROM `creature_questrelation` WHERE `quest` IN (13820, 13681, 13627);

-- DK Quests Restrictions
UPDATE `quest_template` SET `RequiredClasses`=32 WHERE `id` IN (13795, 13791, 13813, 13788, 13812, 13793, 13814, 13864, 13863);
-- Non DK Quests Restrictions
UPDATE `quest_template` SET `RequiredClasses`=1503 WHERE `id` IN (13794, 13788, 13789, 13810, 13682, 13809, 13790, 13811, 13861, 13862);

-- ####
-- ## npc_argent_pet
-- ####
UPDATE creature_template SET npcflag = 129, gossip_menu_id = 50000, ScriptName = 'npc_argent_pet', `IconName` =  'Speak' WHERE entry = 33238;
UPDATE creature_template SET npcflag = 129, gossip_menu_id = 50001, ScriptName = 'npc_argent_pet', `IconName` =  'Speak' WHERE entry = 33239;

DELETE FROM gossip_menu WHERE entry IN (50000, 50001);
INSERT INTO gossip_menu VALUES
(50000, 14324),
(50001, 14372);

DELETE FROM spell_linked_spell WHERE spell_effect = 67401;
INSERT INTO spell_linked_spell VALUES
(-67368, 67401, 0, "Argent Squire - Bank"),
(-67377, 67401, 0, "Argent Squire - Shop"),
(-67376, 67401, 0, "Argent Squire - Mail");

DELETE FROM npc_vendor WHERE entry IN (33238, 33239);
INSERT INTO npc_vendor VALUES
-- Squire
(33238, 0, 3775, 0, 0, 0),
(33238, 0, 5237, 0, 0, 0),
(33238, 0, 5565, 0, 0, 0),
(33238, 0, 16583, 0, 0, 0),
(33238, 0, 17020, 0, 0, 0),
(33238, 0, 17030, 0, 0, 0),
(33238, 0, 17031, 0, 0, 0),
(33238, 0, 17032, 0, 0, 0),
(33238, 0, 17033, 0, 0, 0),
(33238, 0, 21177, 0, 0, 0),
(33238, 0, 37201, 0, 0, 0),
(33238, 0, 41584, 0, 0, 0),
(33238, 0, 41586, 0, 0, 0),
(33238, 0, 43231, 0, 0, 0),
(33238, 0, 43233, 0, 0, 0),
(33238, 0, 43235, 0, 0, 0),
(33238, 0, 43237, 0, 0, 0),
(33238, 0, 44605, 0, 0, 0),
(33238, 0, 44614, 0, 0, 0),
(33238, 0, 44615, 0, 0, 0),

(33238, 0, 33449, 0, 0, 0),
(33238, 0, 33451, 0, 0, 0),
(33238, 0, 33454, 0, 0, 0),
(33238, 0, 33443, 0, 0, 0),
(33238, 0, 35949, 0, 0, 0),
(33238, 0, 35952, 0, 0, 0),
(33238, 0, 35953, 0, 0, 0),
(33238, 0, 35951, 0, 0, 0),
(33238, 0, 35948, 0, 0, 0),
(33238, 0, 35950, 0, 0, 0),

-- Gruntling
(33239, 0, 3775, 0, 0, 0),
(33239, 0, 5237, 0, 0, 0),
(33239, 0, 5565, 0, 0, 0),
(33239, 0, 16583, 0, 0, 0),
(33239, 0, 17020, 0, 0, 0),
(33239, 0, 17030, 0, 0, 0),
(33239, 0, 17031, 0, 0, 0),
(33239, 0, 17032, 0, 0, 0),
(33239, 0, 17033, 0, 0, 0),
(33239, 0, 21177, 0, 0, 0),
(33239, 0, 37201, 0, 0, 0),
(33239, 0, 41584, 0, 0, 0),
(33239, 0, 41586, 0, 0, 0),
(33239, 0, 43231, 0, 0, 0),
(33239, 0, 43233, 0, 0, 0),
(33239, 0, 43235, 0, 0, 0),
(33239, 0, 43237, 0, 0, 0),
(33239, 0, 44605, 0, 0, 0),
(33239, 0, 44614, 0, 0, 0),
(33239, 0, 44615, 0, 0, 0),

(33239, 0, 33449, 0, 0, 0),
(33239, 0, 33451, 0, 0, 0),
(33239, 0, 33454, 0, 0, 0),
(33239, 0, 33443, 0, 0, 0),
(33239, 0, 35949, 0, 0, 0),
(33239, 0, 35952, 0, 0, 0),
(33239, 0, 35953, 0, 0, 0),
(33239, 0, 35951, 0, 0, 0),
(33239, 0, 35948, 0, 0, 0),
(33239, 0, 35950, 0, 0, 0);
