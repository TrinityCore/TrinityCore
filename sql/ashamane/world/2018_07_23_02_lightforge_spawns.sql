/*

		LightForge Drains Area Beta
		clean design for Ashamane
                go xyz 458.823 1449.61 757.573 1860 
		race 30

*/

 -- TELE LOCATION --
DELETE FROM game_tele WHERE id = 1799;
INSERT INTO game_tele (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`)VALUES
(1799, 458.823, 1449.61, 757.573, 0.4664253, 1860, 'LifghtforgeSpawn');


 -- UPDATE SPAWN LOCATION IN PLAYERCREATEINFO --
 
UPDATE playercreateinfo SET map = 1860, zone = 9359, position_x = 458.823, position_y = 1449.61, position_z = 757.573, orientation = 0.4664253 WHERE race = 30; -- Official location from sniff
 
 -- MISC --

DELETE FROM `conversation_actors` WHERE (`ConversationId`=6793 AND `ConversationActorId`=60390 AND `Idx`=0) OR (`ConversationId`=6481 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(6793, 60390, 0, 26972),
(6481, 0, 0, 26972); -- Full: 0x20313CE8807FEC4000217F0000C65E90 Creature/0 R3151/S8575 Map: 1860 Entry: 130993 Low: 13000336


DELETE FROM `conversation_actor_template` WHERE `Id`=60390;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(60390, 126306, 65199, 26972);


DELETE FROM `conversation_line_template` WHERE `Id` IN (15494, 15493, 15492, 15490, 15489, 14662, 14661, 14660, 14659, 14658);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(15494, 41047, 82, 0, 0, 26972),
(15493, 34791, 82, 0, 0, 26972),
(15492, 20704, 82, 0, 0, 26972),
(15490, 9141, 82, 0, 0, 26972),
(15489, 0, 82, 0, 0, 26972),
(14662, 47915, 0, 0, 0, 26972),
(14661, 35458, 0, 0, 0, 26972),
(14660, 25276, 0, 0, 0, 26972),
(14659, 11436, 0, 0, 8241, 26972),
(14658, 0, 0, 0, 0, 26972);


DELETE FROM `conversation_template` WHERE `Id` IN (6793, 6481);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(6793, 15489, 46121, 26972),
(6481, 14658, 51922, 26972);

DELETE FROM `npc_text` WHERE `ID` IN (33728 /*33728*/, 33495 /*33495*/, 32670 /*32670*/, 33709 /*33709*/, 33727 /*33727*/, 32623 /*32623*/, 32658 /*32658*/, 7028 /*7028*/, 9849 /*9849*/, 21709 /*21709*/, 13584 /*13584*/, 33725 /*33725*/, 33721 /*33721*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33728, 1, 1, 0, 0, 0, 0, 0, 0, 144924, 144925, 0, 0, 0, 0, 0, 0, 26972), -- 33728
(33495, 1, 0, 0, 0, 0, 0, 0, 0, 142628, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33495
(32670, 1, 0, 0, 0, 0, 0, 0, 0, 136300, 0, 0, 0, 0, 0, 0, 0, 26972), -- 32670
(33709, 1, 1, 1, 0, 0, 0, 0, 0, 144770, 144772, 144923, 0, 0, 0, 0, 0, 26972), -- 33709
(33727, 1, 0, 0, 0, 0, 0, 0, 0, 144921, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33727
(32623, 1, 0, 0, 0, 0, 0, 0, 0, 135889, 0, 0, 0, 0, 0, 0, 0, 26972), -- 32623
(32658, 1, 0, 0, 0, 0, 0, 0, 0, 136247, 0, 0, 0, 0, 0, 0, 0, 26972), -- 32658
(7028, 1, 0, 0, 0, 0, 0, 0, 0, 9701, 0, 0, 0, 0, 0, 0, 0, 26972), -- 7028
(9849, 1, 0, 0, 0, 0, 0, 0, 0, 16966, 0, 0, 0, 0, 0, 0, 0, 26972), -- 9849
(21709, 1, 0, 0, 0, 0, 0, 0, 0, 49490, 0, 0, 0, 0, 0, 0, 0, 26972), -- 21709
(13584, 1, 0, 0, 0, 0, 0, 0, 0, 30361, 0, 0, 0, 0, 0, 0, 0, 26972), -- 13584
(33725, 1, 0, 0, 0, 0, 0, 0, 0, 144908, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33725
(33721, 1, 0, 0, 0, 0, 0, 0, 0, 144864, 0, 0, 0, 0, 0, 0, 0, 26972); -- 33721

DELETE FROM `gossip_menu` WHERE (`MenuId`=22019 AND `TextId`=33728) OR (`MenuId`=21910 AND `TextId`=33495) OR (`MenuId`=21454 AND `TextId`=32670) OR (`MenuId`=22008 AND `TextId`=33709) OR (`MenuId`=22018 AND `TextId`=33727) OR (`MenuId`=21423 AND `TextId`=32623) OR (`MenuId`=21451 AND `TextId`=32658) OR (`MenuId`=8522 AND `TextId`=7028) OR (`MenuId`=21462 AND `TextId`=9849) OR (`MenuId`=15145 AND `TextId`=21709) OR (`MenuId`=9821 AND `TextId`=13584) OR (`MenuId`=22017 AND `TextId`=33725) OR (`MenuId`=22014 AND `TextId`=33721);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(22019, 33728), -- 130993
(21910, 33495), -- 130986
(21454, 32670), -- 126390
(22008, 33709), -- 130560
(22018, 33727), -- 132358
(21423, 32623), -- 132224
(21451, 32658), -- 126389
(8522, 7028), -- 126022
(21462, 9849), -- 123395
(15145, 21709), -- 96507
(9821, 13584), -- 96507
(22017, 33725), -- 132334
(22014, 33721); -- 132215

UPDATE creature_template SET gossip_menu_id = 22014 WHERE entry = 132215; 
UPDATE creature_template SET gossip_menu_id = 21910 WHERE entry = 130986; 
UPDATE creature_template SET gossip_menu_id = 22019 WHERE entry = 130993;
UPDATE creature_template SET gossip_menu_id = 21454 WHERE entry = 126390;
UPDATE creature_template SET gossip_menu_id = 22008 WHERE entry = 130560;
UPDATE creature_template SET gossip_menu_id = 22018 WHERE entry = 132358;
UPDATE creature_template SET gossip_menu_id = 21423 WHERE entry = 132224;
UPDATE creature_template SET gossip_menu_id = 21451 WHERE entry = 126389;
UPDATE creature_template SET gossip_menu_id = 22017 WHERE entry = 132334;
UPDATE creature_template SET gossip_menu_id = 21462 WHERE entry = 123395;
 

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=21910 AND `OptionIndex`=5) OR (`MenuId`=21910 AND `OptionIndex`=4) OR (`MenuId`=21910 AND `OptionIndex`=3) OR (`MenuId`=21910 AND `OptionIndex`=2) OR (`MenuId`=21910 AND `OptionIndex`=1) OR (`MenuId`=21910 AND `OptionIndex`=0) OR (`MenuId`=21423 AND `OptionIndex`=0) OR (`MenuId`=8522 AND `OptionIndex`=0) OR (`MenuId`=21462 AND `OptionIndex`=2) OR (`MenuId`=21462 AND `OptionIndex`=0) OR (`MenuId`=9821 AND `OptionIndex`=3) OR (`MenuId`=9821 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(21910, 5, 0, 'Can you teleport me back up to the bridge?', 0),
(21910, 4, 0, 'How do you like being on the Vindicaar?', 0),
(21910, 3, 0, 'Do you plan on staying with the draenei?', 0),
(21910, 2, 0, 'What do you know about becoming Lightforged?', 0),
(21910, 1, 0, 'I passed my trial!', 0),
(21910, 0, 0, 'Hello, Vigilant Quoram. We met before on Argus.', 0),
(21423, 0, 1, 'I need repairs, Durael.', 0),
(8522, 0, 3, 'Train me.', 0),
(21462, 2, 1, 'Let me browse your goods.', 0),
(21462, 0, 5, 'Make this inn your home.', 0),
(9821, 3, 0, 'I''d like to heal and revive my battle pets.', 0),
(9821, 1, 1, 'I''m looking for a lost companion.', 0);

/*  Needs Scripting?
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(130986, @GROUP_ID+0, @ID+, 'I am afraid I cannot allow that.', 12, 0, 100, 0, 0, 96050, UNKNOWN, 'Vigilant Quoram to Player'),
(130986, @GROUP_ID+1, @ID+, 'Fine.', 12, 0, 100, 0, 0, 96049, UNKNOWN, 'Vigilant Quoram to Player'),
(130986, @GROUP_ID+2, @ID+, 'For now.', 12, 0, 100, 0, 0, 96047, UNKNOWN, 'Vigilant Quoram to Player'),
(130986, @GROUP_ID+3, @ID+, 'Congratulations.', 12, 0, 100, 0, 0, 96043, UNKNOWN, 'Vigilant Quoram to Player'),
(130986, @GROUP_ID+4, @ID+, 'Why have you returned?', 12, 0, 100, 0, 0, 96042, UNKNOWN, 'Vigilant Quoram to Player'),
(130986, @GROUP_ID+5, @ID+, 'It is designed to kill you.', 12, 0, 100, 0, 0, 96044, UNKNOWN, 'Vigilant Quoram to Player'),
(131334, @GROUP_ID+0, @ID+, 'Light be with you, $n. I plan to  seek the Legion upon Azeroth to continue our eternal battle.', 12, 0, 100, 1, 0, 0, UNKNOWN, 'Vindicator Minkey to Player');
*/

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=9821 AND `OptionIndex`=3);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(9821, 3, 15145, 0);


DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=8522 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(8522, 0, 160);

DELETE FROM `quest_template` WHERE `ID` IN (11 /*11*/, 28565 /*28565*/, 50313 /*50313*/, 49772 /*49772*/, 46736 /*46736*/, 46735 /*46735*/, 46277 /*46277*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `MaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `QuestRewardID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(11, 2, -1, 20, 759, 4, 12, 0, 0, 0, 5, 1, 0, 0, 1, 90, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 1, 0, 0, 824181837, 0, 0, 'Riverpaw Gnoll Bounty', 'Bring 8 Painted Gnoll Armbands to Deputy Rainer at the Barracks.', 'Gnolls, brutish creatures with no decent business in these lands, have been seen along the borders of Elwynn Forest.  A large pack of them, many more than we can handle alone, have infested the woods south of the guard tower yonder.  Another group has infested the areas near Stone Cairn Lake to the east.$B$BThe Stormwind Army will commend whomever helps kill them.  Bring me their painted gnoll armbands as proof of your deed.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 11
(28565, 2, -1, 60, 0, 20, 11, 0, 0, 25395, 1, 1, 125, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 824181837, 0, 0, 'Hero''s Call: Wetlands!', 'Report to Mountaineer Rharen at Dun Algaz.', 'By order of his royal highness, King Anduin Wrynn, all able-bodied citizens of the Alliance are to report to Mountaineer Rharen at Dun Algaz.$B$BIn the wake of the cataclysm''s destruction, Wetlands has become overrun with wild beasts, orcish raiders, and savage gnolls! To reach the Wetlands, you must travel north from Loch Modan through the dwarven hold of Dun Algaz.$B$BFor the glory and honor of the Alliance!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 28565
(50313, 2, 20, 255, 0, 20, -437, 0, 0, 0, 0, 1, 125, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 39845896, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 543160320, 0, 6, 'Stranger in a Strange Land', 'Find the Hero''s Call board in Stormwind City.', 'Welcome to Stormwind, $r. King Anduin Wrynn invites you to explore our fair city. Say, you look like the devout sort. We have a lovely cathedral that will no doubt be of interest! \n\nAh, but that can wait. An emissary of the Lightforged is standing by to tell you of adventures that await beyond the city walls.\n\nHave a pleasant stay, $n. Oh, and please excuse the occasional mess. I fear many of our citizens lack the discipline that you Army of the Light soldiers are so famous for!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 50313
(49772, 2, 20, 255, 0, 20, -437, 0, 0, 50313, 1, 1, 125, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 39845896, 8192, 0, 0, 0, 0, 157022, 157756, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 543160320, 0, 6, 'For the Alliance', 'Meet Ambassador Moorgard at the Stormwind Embassy.', 'The Army of the Light was founded with one purpose: to defeat the Legion. Though we have achieved that goal, a new duty lies before us.\n\nAzeroth is a world beset by enemies. Use your training to battle the darkness and uphold the ideals of the Alliance.\n\nGo to Stormwind. Seek the king''s ambassador at the embassy, then set out to spread the Light''s justice across the land.\n\nPheta thones gamera, $n.', '', 'Meet Ambassador Moorgard at the Stormwind Embassy.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 26972), -- 49772
(46736, 0, -1, 255, 0, 110, 0, 143, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 100728840, 33554432, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 0, 'Contribute to Nether Disruptor', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 26972), -- 46736
(46735, 0, -1, 255, 0, 110, 0, 143, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 100728840, 33554432, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 0, 'Contribute to Command Center', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 26972), -- 46735
(46277, 0, -1, 255, 0, 110, 0, 143, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 100729096, 33554432, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 6, 'Contribute to Mage Tower', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 26972); -- 46277


DELETE FROM `quest_objectives` WHERE `ID` IN (252108 /*252108*/, 312152 /*312152*/, 289536 /*289536*/, 289535 /*289535*/, 289167 /*289167*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(252108, 11, 1, 0, 0, 782, 8, 0, 1, 0, '', 26972), -- 252108
(312152, 50313, 14, 0, 1, 65238, 1, 0, 0, 0, 'Hero''s Call Board found', 26972), -- 312152
(289536, 46736, 4, 0, -1, 1342, 100, 0, 0, 0, '', 26972), -- 289536
(289535, 46735, 4, 0, -1, 1342, 100, 0, 0, 0, '', 26972), -- 289535
(289167, 46277, 4, 0, -1, 1342, 100, 0, 0, 0, '', 26972); -- 289167


-- Creating a new SmartAI script for [Creature] ENTRY 130758 (name: Lightforged Beacon)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI', `npcflag` = 1 WHERE `entry` = 130758;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 130758);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(130758, 0, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 62, 1860, 0, 0, 0, 0, 0, 7, 0, 0, 0, 458.823, 1449.61, 757.573, 0.4664253, 'hackfix teleport from sw to lfd area');





 -- Ambassador Moorguard SAI
SET @AMBASSADOR_MOORGUARD := -1100562;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@AMBASSADOR_MOORGUARD;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@AMBASSADOR_MOORGUARD AND `event_param1`=49772);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@AMBASSADOR_MOORGUARD,0,0,0,20,0,100,0,49772,0,0,0,206,6793,0,0,0,0,0,7,0,0,0,0,0,0,0,"AMBASSADOR_MOORGUARD - On Quest 'For the Alliance' Return - conversation");

-- Captain Fareeya SAI THANKS ÐϴVΞΓϺΛΠ - 930®#4327
SET @CAPT_FAREEYA := 130993;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@CAPT_FAREEYA;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CAPT_FAREEYA AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CAPT_FAREEYA,0,0,0,19,0,100,0,49772,0,0,0,1,0,7000,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Fareeya - On Quest 'For the Horde' Taken - Say Line 0"),
(@CAPT_FAREEYA,0,1,0,52,0,100,0,0,@CAPT_FAREEYA,0,0,1,1,11000,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Fareeya - On Text 0 Over - Say Line 1"),
(@CAPT_FAREEYA,0,2,0,52,0,100,0,1,@CAPT_FAREEYA,0,0,1,2,11000,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Fareeya - On Text 1 Over - Say Line 2"),
(@CAPT_FAREEYA,0,3,0,52,0,100,0,2,@CAPT_FAREEYA,0,0,1,3,11000,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Fareeya - On Text 2 Over - Say Line 3"),
(@CAPT_FAREEYA,0,4,0,52,0,100,0,3,@CAPT_FAREEYA,0,0,1,4,11000,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Fareeya - On Text 3 Over - Say Line 4");

DELETE FROM creature_text WHERE CreatureID=@CAPT_FAREEYA;
INSERT INTO creature_text (CreatureID, GroupID, ID, Text, Type, Language, Probability, Emote, Duration, Sound, BroadcastTextId, TextRange, comment)VALUES
(@CAPT_FAREEYA, 0, 0, 'For thousands of years, the Lightforged fought demons in the Twisting Nether. The Xenedar was the only home we knew.', 12, 0, 100, 1, 0, 0, 141912, 0, ''),
(@CAPT_FAREEYA, 1, 1, 'Now, for the first time in ages, we can walk beneath a sky not befouled by the Legion''s madness... and feel the earth under our hooves again.', 12, 0, 100, 1, 0, 0, 141913, 0, ''),
(@CAPT_FAREEYA, 2, 2, 'But we must not grow complacent. One war ends, the next begins. Such is the life of a soldier.', 12, 0, 100, 1, 0, 0, 141914, 0, ''),
(@CAPT_FAREEYA, 3, 3, 'Your duty begins in Stormwind. Explore this world of Azeroth. Get to know the people and places we have sworn to defend.', 12, 0, 100, 1, 0, 0, 141915, 0, ''),
(@CAPT_FAREEYA, 4, 4, 'And always walk in the Light, $p.', 12, 0, 100, 1, 0, 0, 141916, 0, '');


DELETE FROM `quest_visual_effect` WHERE (`ID`=312152 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(312152, 0, 8537, 26972);

DELETE FROM creature_queststarter WHERE (`id` = 130993 AND `quest` = 49772) OR (`id` = 133362 AND `quest` = 50313);
INSERT INTO creature_queststarter (`id`, `quest`) VALUES
(130993, 49772),
(133362, 50313);

DELETE FROM creature_questender WHERE (`id` = 133362 AND `quest` = 49772);
INSERT INTO creature_questender (`id`, `quest`)VALUES
(133362, 49772);

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=203800 AND `Idx`=0) OR (`GameObjectEntry`=203801 AND `Idx`=0) OR (`GameObjectEntry`=203762 AND `Idx`=0) OR (`GameObjectEntry`=203751 AND `Idx`=0) OR (`GameObjectEntry`=204281 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(203800, 0, 57245, 26972), -- 203800
(203801, 0, 57246, 26972), -- 203801
(203762, 0, 57197, 26972), -- 203762
(203751, 0, 57137, 26972), -- 203751
(204281, 0, 58788, 26972); -- 204281

-- Spawn Range 1100501 to 1101000 ? --
SET @CGUID := 1100501;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+61;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 132266, 1860, 9359, 9359, 3, 0, 0, 0, 0, 470.3177, 1434.354, 757.5344, 2.293528, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132266 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+1, 130993, 1860, 9359, 9359, 3, 0, 0, 0, 0, 463.7621, 1452.3, 757.6564, 3.580927, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 130993 (Area: 9359 - Difficulty: 0)
(@CGUID+2, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 451.7274, 1440.165, 757.6559, 0.53746, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+3, 132214, 1860, 9359, 9359, 3, 0, 0, 0, 0, 456.5642, 1436.085, 741.525, 5.735341, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132214 (Area: 9359 - Difficulty: 0)
(@CGUID+4, 132225, 1860, 9359, 9359, 3, 0, 0, 0, 0, 453.6033, 1457.204, 740.973, 0.7468049, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132225 (Area: 9359 - Difficulty: 0)
(@CGUID+5, 132266, 1860, 9359, 9359, 3, 0, 0, 0, 0, 447.8212, 1466.168, 757.5344, 5.308189, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132266 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+6, 132262, 1860, 9359, 9359, 3, 0, 0, 0, 0, 464.1198, 1431.342, 757.5344, 1.83572, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132262 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+7, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 446.9705, 1450.71, 757.6559, 0.3539234, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+8, 132266, 1860, 9359, 9359, 3, 0, 0, 0, 0, 460.3264, 1469.448, 757.5344, 4.654921, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132266 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+9, 132262, 1860, 9359, 9359, 3, 0, 0, 0, 0, 453.9306, 1468.778, 757.5344, 4.978932, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132262 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+10, 132262, 1860, 9359, 9359, 3, 0, 0, 0, 0, 475.1719, 1439.33, 757.5344, 2.426835, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132262 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+11, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 419.4107, 1435.142, 772.7069, 5.016093, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 132225, 1860, 9359, 9359, 3, 0, 0, 0, 0, 487.9844, 1449.946, 742.0576, 2.175846, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132225 (Area: 9359 - Difficulty: 0)
(@CGUID+13, 132328, 1860, 9359, 9359, 3, 0, 0, 0, 0, 499.6823, 1441.557, 757.1709, 5.122677, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132328 (Area: 9359 - Difficulty: 0)
(@CGUID+14, 132262, 1860, 9359, 9359, 3, 0, 0, 0, 0, 492.2153, 1475.203, 766.0441, 4.566352, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132262 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+15, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 421.3545, 1435.727, 772.6912, 4.988676, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+16, 125524, 1860, 9359, 9359, 3, 0, 0, 0, 0, 453.9375, 1414.283, 742.0576, 4.930696, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 125524 (Area: 9359 - Difficulty: 0) (Auras: 237554 - 237554)
(@CGUID+17, 126390, 1860, 9359, 9359, 3, 0, 0, 0, 0, 496.0104, 1475.403, 742.6741, 4.389082, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126390 (Area: 9359 - Difficulty: 0) (Auras: 250840 - 250840)
(@CGUID+18, 132214, 1860, 9359, 9359, 3, 0, 0, 0, 0, 486.2413, 1451.259, 742.0576, 5.524411, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132214 (Area: 9359 - Difficulty: 0)
(@CGUID+19, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 461.2326, 1495.316, 742.0576, 3.130663, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+20, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 438.5833, 1412.306, 741.9742, 2.5448, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+21, 132266, 1860, 9359, 9359, 3, 0, 0, 0, 0, 499.4653, 1459.774, 766.043, 2.432829, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132266 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+22, 132214, 1860, 9359, 9359, 3, 0, 0, 0, 0, 458.6979, 1495.896, 742.0576, 5.855897, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132214 (Area: 9359 - Difficulty: 0)
(@CGUID+23, 132328, 1860, 9359, 9359, 3, 0, 0, 0, 0, 501.349, 1439.227, 757.1729, 1.927381, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132328 (Area: 9359 - Difficulty: 0)
(@CGUID+24, 125843, 1860, 9359, 9359, 3, 0, 0, 0, 0, 458.5538, 1435.168, 741.525, 2.386775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 125843 (Area: 9359 - Difficulty: 0)
(@CGUID+25, 132214, 1860, 9359, 9359, 3, 0, 0, 0, 0, 437.2587, 1411.191, 742.0666, 2.311964, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 132214 (Area: 9359 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+26, 125524, 1860, 9359, 9359, 3, 0, 0, 0, 0, 455.4879, 1412.189, 742.0576, 2.391975, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 125524 (Area: 9359 - Difficulty: 0) (Auras: 237554 - 237554)
(@CGUID+27, 114590, 1860, 9359, 9359, 3, 0, 0, 0, 0, 406.7153, 1417.325, 745.1935, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 114590 (Area: 9359 - Difficulty: 0)
(@CGUID+28, 132214, 1860, 9359, 9359, 3, 0, 0, 0, 0, 418.5417, 1482.031, 772.7259, 2.715962, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132214 (Area: 9359 - Difficulty: 0)
(@CGUID+29, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 426.3785, 1416.316, 742.0907, 1.02504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+30, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 415.8455, 1483.254, 772.6548, 0.05235988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+31, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 412.4757, 1445.802, 742.0907, 6.15274, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+32, 132323, 1860, 9359, 9359, 3, 0, 0, 0, 0, 402.9618, 1470.224, 773.2676, 6.024433, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132323 (Area: 9359 - Difficulty: 0)
(@CGUID+33, 125524, 1860, 9359, 9359, 3, 0, 0, 0, 0, 427.4427, 1414.569, 772.7769, 4.600402, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 125524 (Area: 9359 - Difficulty: 0) (Auras: 237554 - 237554)
(@CGUID+34, 130560, 1860, 9359, 9359, 3, 0, 0, 0, 0, 419.3576, 1478.951, 741.9806, 4.082101, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 130560 (Area: 9359 - Difficulty: 0)
(@CGUID+35, 132214, 1860, 9359, 9359, 3, 0, 0, 0, 0, 418.8559, 1484.743, 772.7311, 3.601059, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132214 (Area: 9359 - Difficulty: 0)
(@CGUID+36, 132325, 1860, 9359, 9359, 3, 0, 0, 0, 0, 406.3854, 1466.861, 742.0577, 0.8473859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132325 (Area: 9359 - Difficulty: 0)
(@CGUID+37, 126075, 1860, 9359, 9359, 3, 0, 0, 0, 0, 440.0556, 1395.688, 773.2657, 1.242475, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126075 (Area: 9359 - Difficulty: 0)
(@CGUID+38, 132334, 1860, 9359, 9359, 3, 0, 0, 0, 0, 514.0903, 1466.165, 765.8806, 5.331481, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132334 (Area: 9359 - Difficulty: 0)
(@CGUID+39, 132214, 1860, 9359, 9359, 3, 0, 0, 0, 0, 451.651, 1391.865, 772.6549, 3.804818, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 132214 (Area: 9359 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+40, 125524, 1860, 9359, 9359, 3, 0, 0, 0, 0, 427.9132, 1412.004, 772.7381, 1.935839, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 125524 (Area: 9359 - Difficulty: 0) (Auras: 237554 - 237554)
(@CGUID+41, 96507, 1860, 9359, 9359, 3, 0, 0, 0, 0, 400.4115, 1459.616, 772.8699, 5.853756, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 96507 (Area: 9359 - Difficulty: 0)
(@CGUID+42, 123395, 1860, 9359, 9359, 3, 0, 0, 0, 0, 401.2326, 1450.111, 772.7383, 5.91655, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 123395 (Area: 9359 - Difficulty: 0)
(@CGUID+43, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 449.5469, 1390.83, 772.7382, 0.457053, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+44, 126389, 1860, 9359, 9359, 3, 0, 0, 0, 0, 410.5677, 1423.108, 741.8357, 0.6931846, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126389 (Area: 9359 - Difficulty: 0)
(@CGUID+45, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 434.8802, 1507.622, 772.7382, 0.06287564, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+46, 126030, 1860, 9359, 9359, 3, 0, 0, 0, 0, 407.7396, 1488.726, 772.7383, 0.137238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126030 (Area: 9359 - Difficulty: 0) (Auras: 237554 - 237554, 240226 - 240226)
(@CGUID+47, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 421.7292, 1399.507, 772.7384, 1.936839, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0) (Auras: 260861 - 260861)
(@CGUID+48, 132224, 1860, 9359, 9359, 3, 0, 0, 0, 0, 400.0174, 1473.976, 742.0576, 2.548466, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132224 (Area: 9359 - Difficulty: 0)
(@CGUID+49, 132358, 1860, 9359, 9359, 3, 0, 0, 0, 0, 405.3837, 1481.854, 742.0577, 2.217967, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132358 (Area: 9359 - Difficulty: 0)
(@CGUID+50, 132266, 1860, 9359, 9359, 3, 0, 0, 0, 0, 387.7431, 1423.573, 769.6887, 3.993125, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132266 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+51, 132262, 1860, 9359, 9359, 3, 0, 0, 0, 0, 393.4965, 1411.476, 769.6886, 2.775591, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132262 (Area: 9359 - Difficulty: 0) (Auras: 79968 - 79968)
(@CGUID+52, 130986, 1860, 9359, 9359, 3, 0, 0, 0, 0, 441.7274, 1388.382, 742.0577, 1.234179, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 130986 (Area: 9359 - Difficulty: 0)
(@CGUID+53, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 438.3524, 1508.42, 772.7381, 2.828768, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+54, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 406.1146, 1418.431, 772.9761, 0.6309156, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+55, 132328, 1860, 9359, 9359, 3, 0, 0, 0, 0, 423.757, 1502.677, 772.6549, 3.385939, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26972), -- 132328 (Area: 9359 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+56, 114590, 1860, 9359, 9359, 3, 0, 0, 0, 0, 400.5052, 1430.264, 745.045, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 114590 (Area: 9359 - Difficulty: 0)
(@CGUID+57, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 401.2326, 1428.83, 772.9761, 0.2619283, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0)
(@CGUID+58, 126022, 1860, 9359, 9359, 3, 0, 0, 0, 0, 473.3629, 1388.507, 772.6664, 1.595955, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126022 (Area: 9359 - Difficulty: 0)
(@CGUID+59, 132215, 1860, 9359, 9359, 3, 0, 0, 0, 0, 417.5729, 1402.941, 772.7399, 5.881432, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 132215 (Area: 9359 - Difficulty: 0) (Auras: 260861 - 260861)
(@CGUID+60, 130758, 0, 1519, 9171, 1, 0, 0, 0, 0, -8163.132, 777.2292, 76.84772, 6.195094, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 130758 (Area: 9171 - Difficulty: 0)
(@CGUID+61, 133362, 0, 1519, 9171, 1, 0, 0, 0, 0, -8172.592, 801.0712, 74.05038, 3.948032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 133362 (Area: 9171 - Difficulty: 0) (Auras: 262182 - 262182)

UPDATE creature_template SET npcflag = 16777216 WHERE entry = 130758;
UPDATE creature_template SET gossip_menu_id = 21910 WHERE entry = 130986; 

SET @OGUID=20000100;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 278729, 1860, 9359, 9359, 3, 0, 0, 458.8715, 1449.936, 741.231, 3.595922, 0, 0, -0.974309, 0.2252156, 7200, 255, 1, 26972), -- 278729 (Area: 9359 - Difficulty: 0)
(@OGUID+1, 273681, 1860, 9359, 9359, 3, 0, 0, 496.1337, 1475.66, 742.4233, 5.934101, 0, 0, -0.1736574, 0.9848061, 7200, 255, 1, 26972), -- 273681 (Area: 9359 - Difficulty: 0)
(@OGUID+2, 273684, 1860, 9359, 9359, 3, 0, 0, 496.8038, 1475.247, 742.4233, 4.153275, 0, 0, -0.8747673, 0.4845432, 7200, 255, 1, 26972), -- 273684 (Area: 9359 - Difficulty: 0)
(@OGUID+3, 273682, 1860, 9359, 9359, 3, 0, 0, 490.099, 1477.743, 742.0076, 5.4582, 0, 0, -0.4008942, 0.9161244, 7200, 255, 1, 26972), -- 273682 (Area: 9359 - Difficulty: 0)
(@OGUID+4, 233662, 1860, 9359, 9359, 3, 0, 0, 488.7882, 1477.75, 742.0079, 6.024681, 0, 0, -0.1288929, 0.9916585, 7200, 255, 1, 26972), -- 233662 (Area: 9359 - Difficulty: 0)
(@OGUID+5, 278728, 1860, 9359, 9359, 3, 0, 0, 436.2135, 1439.12, 761.618, 0.4363316, 0, 0, 0.2164392, 0.9762961, 7200, 255, 1, 26972), -- 278728 (Area: 9359 - Difficulty: 0)
(@OGUID+6, 278732, 1860, 9359, 9359, 3, 0, 0, 500.3802, 1469.816, 742.4426, 0, 0, 0, 0, 1, 7200, 255, 1, 26972), -- 278732 (Area: 9359 - Difficulty: 0)
(@OGUID+7, 202862, 1860, 9359, 9359, 3, 0, 0, 478.6719, 1487.733, 742.6863, 4.719912, 0, 0, -0.704442, 0.7097615, 7200, 255, 1, 26972), -- 202862 (Area: 9359 - Difficulty: 0)
(@OGUID+8, 273683, 1860, 9359, 9359, 3, 0, 0, 497.0017, 1475.373, 743.5395, 5.823761, 0, 0, -0.2276974, 0.9737319, 7200, 255, 1, 26972), -- 273683 (Area: 9359 - Difficulty: 0)
(@OGUID+9, 273496, 1860, 9359, 9359, 3, 0, 0, 403.6795, 1465.951, 773.2155, 5.628693, 0, 0, -0.3214369, 0.946931, 7200, 255, 1, 26972), -- 273496 (Area: 9359 - Difficulty: 0)
(@OGUID+10, 276296, 1860, 9359, 9359, 3, 0, 0, 408.191, 1425.792, 743.5975, 0, 0, 0, 0, 1, 7200, 255, 1, 26972), -- 276296 (Area: 9359 - Difficulty: 0)
(@OGUID+11, 272190, 1860, 9359, 9359, 3, 0, 0, 506.2508, 1472.549, 765.8348, 0.4450628, 0, 0, 0.2206993, 0.9753419, 7200, 255, 1, 26972), -- 272190 (Area: 9359 - Difficulty: 0)
(@OGUID+12, 251228, 1860, 9359, 9359, 3, 0, 0, 419.3004, 1479.01, 741.9744, 0, 0, 0, 0, 1, 7200, 255, 1, 26972), -- 251228 (Area: 9359 - Difficulty: 0)
(@OGUID+13, 246170, 1860, 9359, 9359, 3, 0, 0, 406.4288, 1466.891, 741.9744, 0, 0, 0, 0, 1, 7200, 255, 1, 26972), -- 246170 (Area: 9359 - Difficulty: 0)
(@OGUID+14, 273289, 1860, 9359, 9359, 3, 0, 0, 399.8361, 1453.932, 772.6203, 5.122549, 0, 0, -0.5482903, 0.8362881, 7200, 255, 1, 26972), -- 273289 (Area: 9359 - Difficulty: 0)
(@OGUID+15, 273682, 1860, 9359, 9359, 3, 0, 0, 497.4531, 1475.538, 742.4233, 5.36762, 0, 0, -0.4419603, 0.8970346, 7200, 255, 1, 26972), -- 273682 (Area: 9359 - Difficulty: 0)
(@OGUID+16, 273288, 1860, 9359, 9359, 3, 0, 0, 397.9294, 1475.333, 741.9274, 4.16262, 0, 0, -0.8724937, 0.4886253, 7200, 255, 1, 26972), -- 273288 (Area: 9359 - Difficulty: 0)
(@OGUID+17, 278730, 1860, 9359, 9359, 3, 0, 0, 403.6198, 1423.67, 741.752, 0.4363316, 0, 0, 0.2164392, 0.9762961, 7200, 255, 1, 26972), -- 278730 (Area: 9359 - Difficulty: 0)
(@OGUID+18, 273287, 1860, 9359, 9359, 3, 0, 0, 394.4114, 1471.221, 741.8721, 6.257012, 0, 0, -0.01308632, 0.9999143, 7200, 255, 1, 26972), -- 273287 (Area: 9359 - Difficulty: 0)
(@OGUID+19, 271723, 0, 1519, 9171, 1, 0, 0, -8163.132, 777.2292, 76.76438, 6.195095, 0, 0, -0.04403114, 0.9990302, 120, 255, 1, 26972); -- 271723 (Area: 9171 - Difficulty: 0)


DELETE FROM gameobject_template WHERE entry = 271723;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(271723, 5, 43244, 'Lightforged Beacon', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 271723

DELETE FROM `npc_vendor` WHERE (`entry`=132224 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132224 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126075 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123395 AND `item`=152717 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123395 AND `item`=152718 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=96507 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=8953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4602 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4539 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4538 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4537 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=4536 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132323 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(132224, 6, 3857, 0, 0, 1, 0, 0, 26972), -- 3857
(132224, 5, 18567, 0, 0, 1, 0, 0, 26972), -- 18567
(132224, 4, 3466, 0, 0, 1, 0, 0, 26972), -- 3466
(132224, 3, 2880, 0, 0, 1, 0, 0, 26972), -- 2880
(132224, 2, 5956, 0, 0, 1, 0, 0, 26972), -- 5956
(132224, 1, 2901, 0, 0, 1, 0, 0, 26972), -- 2901
(126075, 6, 3857, 0, 0, 1, 0, 0, 26972), -- 3857
(126075, 5, 18567, 0, 0, 1, 0, 0, 26972), -- 18567
(126075, 4, 3466, 0, 0, 1, 0, 0, 26972), -- 3466
(126075, 3, 2880, 0, 0, 1, 0, 0, 26972), -- 2880
(126075, 2, 5956, 0, 0, 1, 0, 0, 26972), -- 5956
(126075, 1, 2901, 0, 0, 1, 0, 0, 26972), -- 2901
(123395, 2, 152717, 0, 0, 1, 0, 0, 26972), -- 152717
(123395, 1, 152718, 0, 0, 1, 0, 0, 26972), -- 152718
(96507, 1, 37460, 0, 0, 1, 0, 0, 26972), -- 37460
(132323, 12, 8953, 0, 0, 1, 0, 0, 26972), -- 8953
(132323, 11, 4602, 0, 0, 1, 0, 0, 26972), -- 4602
(132323, 10, 4539, 0, 0, 1, 0, 0, 26972), -- 4539
(132323, 9, 4538, 0, 0, 1, 0, 0, 26972), -- 4538
(132323, 8, 4537, 0, 0, 1, 0, 0, 26972), -- 4537
(132323, 7, 4536, 0, 0, 1, 0, 0, 26972), -- 4536
(132323, 6, 8766, 0, 0, 1, 0, 0, 26972), -- 8766
(132323, 5, 1645, 0, 0, 1, 0, 0, 26972), -- 1645
(132323, 4, 1708, 0, 0, 1, 0, 0, 26972), -- 1708
(132323, 3, 1205, 0, 0, 1, 0, 0, 26972), -- 1205
(132323, 2, 1179, 0, 0, 1, 0, 0, 26972), -- 1179
(132323, 1, 159, 0, 0, 1, 0, 0, 26972); -- 159

SET @PHASE_169  = 172329; -- default phase?
SET @PHASE_170  = 59073; -- alliance
SET @PHASE_171  = 59074; -- horde?
SET @PHASE_172  = 59087; -- MEH

UPDATE creature SET PhaseId = 172 WHERE guid = @CGUID+60;
UPDATE creature SET PhaseId = 172 WHERE guid = @CGUID+61;
UPDATE gameobject SET PhaseId = 172 WHERE guid = @OGUID+19;
SET @CGUID := 1100501;
SET @OGUID=20000100;
DELETE FROM spell_area WHERE (spell = @PHASE_172 AND racemask = 536870912) OR (spell = @PHASE_169 AND racemask = 536870912);
INSERT INTO spell_area (`spell`, `area`, `teamid`, `racemask`, `flags`) VALUES 
(@PHASE_172, 9171, 0, 536870912, 3),
(@PHASE_169, 9171, 0, 536870912, 3);

--  fix the dberrors ?
UPDATE creature SET spawnMask = 1 WHERE guid BETWEEN 1100225 AND 1100600;

UPDATE gameobject SET spawnMask = 1 WHERE guid BETWEEN 20000050 AND 20000118;










