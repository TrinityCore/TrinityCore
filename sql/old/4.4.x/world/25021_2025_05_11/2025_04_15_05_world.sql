DELETE FROM `quest_offer_reward` WHERE `ID` IN (24766 /*The Arts of a Druid*/, 26274 /*The Arts of a Warlock*/, 24752 /*The Arts of a Mage*/, 24760 /*The Arts of a Shaman*/, 24784 /*The Arts of a Priest*/, 24772 /*The Arts of a Rogue*/, 24640 /*The Arts of a Warrior*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(24766, 5, 0, 0, 0, 0, 0, 0, 0, 'Good work, mon! Dis stuff come easy to ya.', 59185), -- The Arts of a Druid
(26274, 5, 0, 0, 0, 0, 0, 0, 0, 'Good work, mon! Dis stuff come easy to ya.', 59185), -- The Arts of a Warlock
(24752, 5, 0, 0, 0, 0, 0, 0, 0, 'Good work, mon! Dis stuff come easy to ya.', 59185), -- The Arts of a Mage
(24760, 5, 0, 0, 0, 0, 0, 0, 0, 'Good work, mon! Dis stuff come easy to ya.', 59185), -- The Arts of a Shaman
(24784, 5, 0, 0, 0, 0, 0, 0, 0, 'Good work, mon! Dis stuff come easy to ya.', 59185), -- The Arts of a Priest
(24772, 5, 0, 0, 0, 0, 0, 0, 0, 'Good work, mon! Dis stuff come easy to ya.', 59185), -- The Arts of a Rogue
(24640, 5, 0, 0, 0, 0, 0, 0, 0, 'Good work, mon! Dis stuff come easy to ya.', 59185); -- The Arts of a Warrior

UPDATE `quest_offer_reward` SET `VerifiedBuild`=59185 WHERE `ID` IN (24769, 24768, 24767, 24765, 24764, 24755, 24754, 24753, 24751, 24750, 24778, 25073, 24814, 24812, 24813, 25035, 24626, 24623, 24625, 24624, 24622, 25064, 25037);
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=59185 WHERE `ID`=26277; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=59185 WHERE `ID`=26276; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=26275; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Not bad, mon. Ya have a deep power in ya spells - you may have a talent for dis.$B$BSome rough edges ta be sure, but we\'ll get dose ironed out here and I\'ll teach ya a few new tings as we go.', `VerifiedBuild`=59185 WHERE `ID`=26273; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `RewardText`='Anotha newblood, eh?$B$BYa actually have an intense look about ya though. Fiery eyes. You might have the makings of a real $c.$B$BLets not waste anymore time \'den.', `VerifiedBuild`=59185 WHERE `ID`=26272; -- The Rise of the Darkspear
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=59185 WHERE `ID`=24763; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=59185 WHERE `ID`=24762; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=24761; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Not bad, mon. Ya have a natural flow to ya spells - you may have a talent for dis.$B$BSome rough edges ta be sure, but we\'ll get dose ironed out here and I\'ll teach ya a few new tings as we go.', `VerifiedBuild`=59185 WHERE `ID`=24759; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Not bad, mon. Ya have a natural flow to ya spells - you may have a talent for dis.$B$BSome rough edges ta be sure, but we\'ll get dose ironed out here and I\'ll teach ya a few new tings as we go.', `VerifiedBuild`=59185 WHERE `ID`=24759; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `RewardText`='Anotha newblood, eh?$B$BYa actually have a weathered look about ya though. Wise eyes. You might have the makings of a real $c.$B$BLets not waste anymore time \'den.', `VerifiedBuild`=59185 WHERE `ID`=24758; -- The Rise of the Darkspear
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=59185 WHERE `ID`=24787; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=59185 WHERE `ID`=24786; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=24785; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Not bad, mon. Ya have a natural flow to ya spells - you may have a talent for dis.$B$BSome rough edges ta be sure, but we\'ll get dose ironed out here and I\'ll teach ya a few new tings as we go.', `VerifiedBuild`=59185 WHERE `ID`=24783; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `RewardText`='Anotha newblood, eh?$B$BYa actually have a balanced look about ya though. Calm eyes. You might have the makings of a real $c.$B$BLets not waste anymore time \'den.', `VerifiedBuild`=59185 WHERE `ID`=24782; -- The Rise of the Darkspear
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=59185 WHERE `ID`=24775; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=59185 WHERE `ID`=24774; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=24773; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=24771; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `VerifiedBuild`=59185 WHERE `ID`=24770; -- The Rise of the Darkspear
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=59185 WHERE `ID`=24781; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=59185 WHERE `ID`=24780; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=24779; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='Not bad, mon. Ya have a natural flow to ya attacks - you may have a talent for dis.$B$BSome rough edges ta be sure, but we\'ll get dose ironed out here and I\'ll teach ya a few new tings as we go.', `VerifiedBuild`=59185 WHERE `ID`=24777; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `RewardText`='Anotha newblood, eh?$B$BYa actually have a wild look about ya though. Fierce eyes. You might have the makings of a real $c.$B$BLets not waste anymore time \'den.', `VerifiedBuild`=59185 WHERE `ID`=24776; -- The Rise of the Darkspear
UPDATE `quest_offer_reward` SET `Emote1`=6, `VerifiedBuild`=59185 WHERE `ID`=24643; -- More Than Expected
UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=59185 WHERE `ID`=24642; -- Proving Pit
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=24641; -- A Rough Start
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=59185 WHERE `ID`=24639; -- The Basics: Hitting Things
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `EmoteDelay2`=60, `RewardText`='Anotha newblood, eh?$B$BYa actually look ta be in shape though. Steady hands. Fierce eyes. I may be able ta turn ya into a real $c.$B$BLets not waste anymore time \'den.', `VerifiedBuild`=59185 WHERE `ID`=24607; -- The Rise of the Darkspear

DELETE FROM `quest_details` WHERE `ID` IN (24766 /*The Arts of a Druid*/, 26277 /*More Than Expected*/, 26274 /*The Arts of a Warlock*/, 26276 /*Proving Pit*/, 26275 /*A Rough Start*/, 26273 /*The Basics: Hitting Things*/, 26272 /*The Rise of the Darkspear*/, 24752 /*The Arts of a Mage*/, 24763 /*More Than Expected*/, 24760 /*The Arts of a Shaman*/, 24762 /*Proving Pit*/, 24761 /*A Rough Start*/, 24759 /*The Basics: Hitting Things*/, 24787 /*More Than Expected*/, 24784 /*The Arts of a Priest*/, 24786 /*Proving Pit*/, 24785 /*A Rough Start*/, 24783 /*The Basics: Hitting Things*/, 24782 /*The Rise of the Darkspear*/, 24775 /*More Than Expected*/, 24772 /*The Arts of a Rogue*/, 24774 /*Proving Pit*/, 24773 /*A Rough Start*/, 24771 /*The Basics: Hitting Things*/, 24770 /*The Rise of the Darkspear*/, 24643 /*More Than Expected*/, 24640 /*The Arts of a Warrior*/, 24642 /*Proving Pit*/, 24641 /*A Rough Start*/, 24639 /*The Basics: Hitting Things*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(24766, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- The Arts of a Druid
(26277, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- More Than Expected
(26274, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- The Arts of a Warlock
(26276, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- Proving Pit
(26275, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- A Rough Start
(26273, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Basics: Hitting Things
(26272, 1, 1, 1, 0, 0, 60, 60, 0, 59185), -- The Rise of the Darkspear
(24752, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- The Arts of a Mage
(24763, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- More Than Expected
(24760, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- The Arts of a Shaman
(24762, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- Proving Pit
(24761, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- A Rough Start
(24759, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Basics: Hitting Things
(24787, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- More Than Expected
(24784, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- The Arts of a Priest
(24786, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- Proving Pit
(24785, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- A Rough Start
(24783, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Basics: Hitting Things
(24782, 1, 1, 1, 0, 0, 60, 60, 0, 59185), -- The Rise of the Darkspear
(24775, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- More Than Expected
(24772, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- The Arts of a Rogue
(24774, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- Proving Pit
(24773, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- A Rough Start
(24771, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- The Basics: Hitting Things
(24770, 1, 1, 1, 0, 0, 60, 60, 0, 59185), -- The Rise of the Darkspear
(24643, 0, 0, 0, 0, 0, 0, 0, 0, 59185), -- More Than Expected
(24640, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- The Arts of a Warrior
(24642, 1, 1, 0, 0, 0, 60, 0, 0, 59185), -- Proving Pit
(24641, 1, 0, 0, 0, 0, 0, 0, 0, 59185), -- A Rough Start
(24639, 1, 0, 0, 0, 0, 0, 0, 0, 59185); -- The Basics: Hitting Things

UPDATE `quest_details` SET `VerifiedBuild`=59185 WHERE `ID` IN (24769, 24768, 24767, 24765, 24764, 24755, 24754, 24753, 24751, 24750, 24758, 24781, 24778, 24780, 24779, 24777, 24776, 25073, 24814, 24813, 24812, 25035, 24626, 24625, 24624, 24623, 24622, 25037, 25064, 24607);

DELETE FROM `quest_request_items` WHERE `ID` IN (24624 /*Mercy for the Lost*/, 24814 /*An Ancient Enemy*/, 24813 /*Territorial Fetish*/, 24812 /*No More Mercy*/, 24784 /*The Arts of a Priest*/, 24778 /*The Arts of a Hunter*/, 24772 /*The Arts of a Rogue*/, 24766 /*The Arts of a Druid*/, 24760 /*The Arts of a Shaman*/, 24754 /*Proving Pit*/, 24751 /*The Basics: Hitting Things*/, 26274 /*The Arts of a Warlock*/, 24640 /*The Arts of a Warrior*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(24624, 0, 0, 0, 0, 'Dis is very unpleasant work.', 59185), -- Mercy for the Lost
(24814, 0, 1, 0, 0, 'I did not think we\'d be afforded da opportunity to fight her again. She was foolish to be returnin\'.', 59185), -- An Ancient Enemy
(24813, 0, 1, 0, 0, 'Da naga have gotten more and more aggressive each time we meet. I suspect dey have a new leader behind dem now and dat their aims have ta do with more den just territory or revenge.', 59185), -- Territorial Fetish
(24812, 0, 1, 0, 0, 'Sometimes mercy has its place. Sometimes dat place should remain far from our minds.', 59185), -- No More Mercy
(24784, 0, 1, 0, 0, 'As ya progress in skill, dis power will become greater naturally, as will many of your others.', 59185), -- The Arts of a Priest
(24778, 0, 1, 0, 0, 'No matta how much ya learn or how good ya get, it\'s the steady hand between ya shots that will keep ya enemies hurtin\'. Don\'t forget to mix dis practice in-between da rest of tha tricks ya learn.', 59185), -- The Arts of a Hunter
(24772, 0, 1, 0, 0, 'As ya progress in skill, it will become even harder for people or tings to detect ya.', 59185), -- The Arts of a Rogue
(24766, 0, 1, 0, 0, 'Veteran druids can take on animal forms, grantin\' great speed, tough skin, or even tha ability ta fly.', 59185), -- The Arts of a Druid
(24760, 0, 1, 0, 0, 'Der are many other ways to enchant yer weapon. Ya\'ll learn more wit time.', 59185), -- The Arts of a Shaman
(24754, 0, 1, 0, 0, 'All trolls gotta prove demselves before we let them move past da training grounds.', 59185), -- Proving Pit
(24751, 0, 1, 0, 0, 'Power isn\'t da end all of defeating ya enemy, and it most certainly isn\'t tha end all of stayin\' alive. Fightin\' is about balance. Everytin\' has its time and place.', 59185), -- The Basics: Hitting Things
(26274, 0, 1, 0, 0, 'With time, ya\'ll learn ta conjure more powerful fire and shadow to tear away at ya enemies. Summon ya allies from other parts of da world. Beckon terrifying and powerful demons.$B$BAll in time.', 59185), -- The Arts of a Warlock
(24640, 0, 1, 0, 0, 'Veteran warriors can control much of da battlefield simply with da strength of deir presence. Whether it be rallyin\' other fighters beside ya to greater strength, demoralizin\' ya enemies with da fierceness of ya attacks, our intimidatin\' ya foes into runnin\' from da very sight of ya, it\'s more than just the weapon dat makes da warrior.', 59185); -- The Arts of a Warrior

UPDATE `quest_request_items` SET `VerifiedBuild`=59185 WHERE `ID` IN (24623, 24786, 24785, 24783, 24780, 24779, 24777, 24774, 24773, 24771, 24768, 24767, 24765, 24762, 24761, 24759, 24753, 26276, 26275, 26273, 25037, 24642, 24641, 24639);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=59185 WHERE `ID`=24752; -- The Arts of a Mage
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1, `VerifiedBuild`=59185 WHERE `ID`=24625; -- Consort of the Sea Witch

DELETE FROM `creature_queststarter` WHERE `id`=38245 AND `quest`=24784;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(38245, 24784, 59185); -- The Arts of a Priest offered by Tunari

UPDATE `creature_queststarter` SET `VerifiedBuild`=59185 WHERE `id`=38243 AND `quest` IN (24769,24766,24768,24767,24765) OR `id`=37951 AND `quest` IN (24764,26272,24750,24758,24782,24770,24776,24607) OR `id`=42618 AND `quest` IN (26277,26274,26276,26275,26273) OR `id`=38246 AND `quest` IN (24755,24752,24754,24753,24751) OR `id`=38242 AND `quest` IN (24763,24760,24762,24761,24759) OR `id`=38245 AND `quest` IN (24787,24786,24785,24783) OR `id`=38244 AND `quest` IN (24775,24772,24774,24773,24771) OR `id`=38247 AND `quest` IN (24781,24778,24780,24779,24777) OR `id`=38966 AND `quest` IN (25073,25064) OR `id`=38442 AND `quest` IN (24814,24813,24812) OR `id`=38440 AND `quest`=25035 OR `id`=37969 AND `quest` IN (24626,24623) OR `id`=37987 AND `quest` IN (24625,24624) OR `id`=38005 AND `quest`=24622 OR `id`=39007 AND `quest`=25037 OR `id`=38037 AND `quest` IN (24643,24640,24642,24641,24639);


UPDATE `creature_questender` SET `VerifiedBuild`=59185 WHERE `id`=38966 AND `quest` IN (24769,26277,24755,24763,24787,24775,24781,24814,24643) OR `id`=38243 AND `quest` IN (24766,24768,24767,24765,24764) OR `id`=42618 AND `quest` IN (26274,26276,26275,26273,26272) OR `id`=38246 AND `quest` IN (24752,24754,24753,24751,24750) OR `id`=38242 AND `quest` IN (24760,24762,24761,24759,24758) OR `id`=38245 AND `quest` IN (24784,24786,24785,24783,24782) OR `id`=38244 AND `quest` IN (24772,24774,24773,24771,24770) OR `id`=38247 AND `quest` IN (24778,24780,24779,24777,24776) OR `id`=3188 AND `quest`=25073 OR `id`=38442 AND `quest` IN (24812,24813,25035) OR `id`=38005 AND `quest` IN (24626,25064) OR `id`=37969 AND `quest` IN (24623,24622) OR `id`=37987 AND `quest` IN (24625,24624) OR `id`=39007 AND `quest`=25037 OR `id`=38037 AND `quest` IN (24640,24642,24641,24639,24607);
