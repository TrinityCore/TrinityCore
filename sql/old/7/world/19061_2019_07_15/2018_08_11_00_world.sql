-- 
DELETE FROM `gossip_menu` WHERE (`MenuId`=10827 AND `TextId`=15013) OR (`MenuId`=10841 AND `TextId`=15034) OR (`MenuId`=10773 AND `TextId`=14938) OR (`MenuId`=10843 AND `TextId`=14843) OR (`MenuId`=10842 AND `TextId`=15035) OR (`MenuId`=14290 AND `TextId`=14836) OR (`MenuId`=10837 AND `TextId`=14841) OR (`MenuId`=14172 AND `TextId`=14832) OR (`MenuId`=10699 AND `TextId`=14843) OR (`MenuId`=14204 AND `TextId`=16586) OR (`MenuId`=10700 AND `TextId`=14845) OR (`MenuId`=10698 AND `TextId`=14841) OR (`MenuId`=14174 AND `TextId`=14839) OR (`MenuId`=14173 AND `TextId`=14848) OR (`MenuId`=10676 AND `TextId`=14798);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(10827, 15013, 25549), -- 36290 (Lord Godfrey)
(10841, 15034, 25549), -- 36779 (Marie Allen)
(10773, 14938, 25549), -- 36140 (Prince Liam Greymane)
(10843, 14843, 25549), -- 36630 (Loren the Fence)
(10842, 15035, 25549), -- 36717 (Gerard Walthorn)
(14290, 14836, 25549), -- 36628 (Celestine of the Harvest)
(10837, 14841, 25549), -- 36631 (Myriam Spellwaker)
(14172, 14832, 25549), -- 44455 (Sergeant Cleese)
(10699, 14843, 25549), -- 44464 (Loren the Fence)
(14204, 16586, 25549), -- 44459 (Celestine of the Harvest)
(10700, 14845, 25549), -- 44468 (Sister Almyra)
(10698, 14841, 25549), -- 44465 (Myriam Spellwaker)
(14174, 14839, 25549), -- 44461 (Huntsman Blake)
(14173, 14848, 25549), -- 44469 (Vitus Darkwalker)
(10676, 14798, 25549); -- 34913 (Prince Liam Greymane)

DELETE FROM `npc_vendor` WHERE (`entry`=36779 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=36779 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=36779 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(36779, 25, 39505, 0, 0, 1, 0, 0, 25549), -- Virtuoso Inking Set
(36779, 24, 20815, 0, 0, 1, 0, 0, 25549), -- Jeweler's Kit
(36779, 9, 85663, 0, 0, 1, 0, 0, 25549); -- Herbalist's Spade

UPDATE `spell_target_position` SET `MapID`=638, `VerifiedBuild`=25549 WHERE (`ID`=101644 AND `EffectIndex`=0);

DELETE FROM `quest_details` WHERE `ID` IN (14368, 14382, 14369);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14368, 18, 0, 0, 0, 0, 0, 0, 0, 25549), -- Save the Children!
(14382, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Two By Sea
(14369, 0, 0, 0, 0, 0, 0, 0, 0, 25549); -- Unleash the Beast

DELETE FROM `quest_details` WHERE `ID` IN (26706 /*Endgame*/, 24681 /*They Have Allies, But So Do We*/, 24680 /*Keel Harbor*/, 24679 /*Patriarch's Blessing*/, 24602 /*Laid to Rest*/, 24678 /*Knee-Deep*/, 24920 /*Slowing the Inevitable*/, 24903 /*Vengeance or Survival*/, 24902 /*The Hunt For Sylvanas*/, 24904 /*The Battle for Gilneas City*/, 24676 /*Push Them Out*/, 24675 /*Last Meal*/, 24674 /*Slaves to No One*/, 24575 /*Liberation Day*/, 24677 /*Flank the Forsaken*/, 24592 /*Betrayal at Tempest's Reach*/, 24672 /*Onwards and Upwards*/, 24673 /*Return to Stormglen*/, 24593 /*Neither Human Nor Beast*/, 24646 /*Take Back What's Ours*/, 24628 /*Preparations*/, 24627 /*At Our Doorstep*/, 24617 /*Tal'doren, the Wild Home*/, 24616 /*Losing Your Tail*/, 24578 /*The Blackwald*/, 24501 /*Queen-Sized Troubles*/, 24495 /*Pieces of the Past*/, 24484 /*Pest Control*/, 24483 /*Stormglen*/, 24472 /*Introductions Are in Order*/, 24468 /*Stranded at the Marsh*/, 24438 /*Exodus*/, 14466 /*The King's Observatory*/, 14465 /*To Greymane Manor*/, 14405 /*Escape By Sea*/, 14412 /*Washed Up*/, 14404 /*Not Quite Shipshape*/, 14401 /*Grandma's Cat*/, 14400 /*I Can't Wear This*/, 14399 /*Grandma's Lost It Alright*/, 14396 /*As the Land Shatters*/, 14386 /*Leader of the Pack*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26706, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Endgame
(24681, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- They Have Allies, But So Do We
(24680, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Keel Harbor
(24679, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Patriarch's Blessing
(24602, 1, 0, 0, 0, 0, 0, 0, 0, 25549), -- Laid to Rest
(24678, 1, 0, 0, 0, 0, 0, 0, 0, 25549), -- Knee-Deep
(24920, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Slowing the Inevitable
(24903, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Vengeance or Survival
(24902, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- The Hunt For Sylvanas
(24904, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- The Battle for Gilneas City
(24676, 1, 0, 0, 0, 0, 0, 0, 0, 25549), -- Push Them Out
(24675, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Last Meal
(24674, 1, 0, 0, 0, 0, 0, 0, 0, 25549), -- Slaves to No One
(24575, 1, 274, 0, 0, 0, 0, 0, 0, 25549), -- Liberation Day
(24677, 274, 0, 0, 0, 0, 0, 0, 0, 25549), -- Flank the Forsaken
(24592, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Betrayal at Tempest's Reach
(24672, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Onwards and Upwards
(24673, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Return to Stormglen
(24593, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Neither Human Nor Beast
(24646, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Take Back What's Ours
(24628, 1, 0, 0, 0, 0, 0, 0, 0, 25549), -- Preparations
(24627, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- At Our Doorstep
(24617, 25, 0, 0, 0, 0, 0, 0, 0, 25549), -- Tal'doren, the Wild Home
(24616, 1, 25, 0, 0, 0, 0, 0, 0, 25549), -- Losing Your Tail
(24578, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- The Blackwald
(24501, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Queen-Sized Troubles
(24495, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Pieces of the Past
(24484, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Pest Control
(24483, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Stormglen
(24472, 1, 6, 5, 0, 0, 0, 0, 0, 25549), -- Introductions Are in Order
(24468, 1, 25, 0, 0, 0, 0, 0, 0, 25549), -- Stranded at the Marsh
(24438, 1, 0, 0, 0, 0, 0, 0, 0, 25549), -- Exodus
(14466, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- The King's Observatory
(14465, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- To Greymane Manor
(14405, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Escape By Sea
(14412, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Washed Up
(14404, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Not Quite Shipshape
(14401, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Grandma's Cat
(14400, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- I Can't Wear This
(14399, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- Grandma's Lost It Alright
(14396, 0, 0, 0, 0, 0, 0, 0, 0, 25549), -- As the Land Shatters
(14386, 0, 0, 0, 0, 0, 0, 0, 0, 25549); -- Leader of the Pack

DELETE FROM `spell_target_position` WHERE (`ID`=78107 AND `EffectIndex`=0) OR (`ID`=73010 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(78107, 0, 1, 8343.86, 1165.28, 4.40044, 25549), -- Spell: Teleport to Rut'theran Efffect: 11 (SPELL_EFFECT_BIND)
(73010, 0, 654, -1795.39, 1391.93, 21.1405, 25549); -- Spell: BFGC - Teleport Location 6 Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `gossip_menu` WHERE (`MenuId`=12609 AND `TextId`=17749) OR (`MenuId`=11061 AND `TextId`=15442) OR (`MenuId`=10843 AND `TextId`=14843) OR (`MenuId`=10841 AND `TextId`=15034) OR (`MenuId`=11079 AND `TextId`=15408) OR (`MenuId`=14290 AND `TextId`=14836) OR (`MenuId`=10809 AND `TextId`=14986) OR (`MenuId`=10833 AND `TextId`=15025) OR (`MenuId`=10827 AND `TextId`=15013);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(12609, 17749, 25549), -- 36616 (Admiral Nightwind)
(11061, 15442, 25549), -- 38553 (Krennan Aranas)
(10843, 14843, 25549), -- 38796 (Loren the Fence)
(10841, 15034, 25549), -- 42853 (Karen Murray)
(11079, 15408, 25549), -- 38764 (Lord Hewell)
(14290, 14836, 25549), -- 38799 (Celestine of the Harvest)
(10809, 14986, 25549), -- 36456 (Sebastian Hayward)
(10833, 15025, 25549), -- 36452 (Gwen Armstead)
(10827, 15013, 25549); -- 36290 (Lord Godfrey)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=11061 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(11061, 1, 0, 'I wish to join the battle underway.', 38797, 25549);
