ALTER TABLE `quest_template`
  CHANGE `MinLevel` `MinLevel` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardMoney` `RewardMoney` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionValue1` `RewardFactionValue1` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionOverride1` `RewardFactionOverride1` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionValue2` `RewardFactionValue2` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionOverride2` `RewardFactionOverride2` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionValue3` `RewardFactionValue3` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionOverride3` `RewardFactionOverride3` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionValue4` `RewardFactionValue4` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionOverride4` `RewardFactionOverride4` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionValue5` `RewardFactionValue5` INT(11) NOT NULL DEFAULT '0',
  CHANGE `RewardFactionOverride5` `RewardFactionOverride5` INT(11) NOT NULL DEFAULT '0';

UPDATE `quest_template` SET `RewardFactionValue2`=-5 WHERE `Id` IN (1 /*Kanrethad's Quest*/, 189 /*Bloodscalp Ears*/, 209 /*Skullsplitter Tusks*/, 213 /*Hostile Takeover*/, 351 /*Find OOX-17/TN!*/, 485 /*Find OOX-09/HL!*/, 575 /*Supply and Demand*/, 577 /*Some Assembly Required*/, 578 /*The Stone of the Tides*/, 580 /*Whiskey Slim's Lost Grog*/, 587 /*Up to Snuff*/, 600 /*Venture Company Mining*/, 601 /*Water Elementals*/, 604 /*The Bloodsail Buccaneers*/, 605 /*Singing Blue Shards*/, 609 /*Voodoo Dues*/, 614 /*The Captain's Chest*/, 617 /*Akiris by the Bundle*/, 621 /*Zanzil's Secret*/, 628 /*Excelsior*/, 662 /*Deep Sea Salvage*/, 664 /*Drowned Sorrows*/, 669 /*Sunken Treasure*/, 705 /*Pearl Diving*/, 1182 /*Goblin Sponsorship*/, 2418 /*Power Stones*/, 8551 /*The Captain's Chest*/, 9065 /*The Pattymac Special*/, 11578 /*The ""Chow"" Quest (123)aa COPY*/, 11579 /*The ""Chow"" Quest (123)aa COPY*/, 25475 /*Find OOX-22/FE!*/, 26050 /*Goggle Boggle*/, 26055 /*Drowned Sorrows*/, 26593 /*Scaring Shaky*/, 26595 /*Kill-Collect*/, 26599 /*The Captain's Chest*/, 26613 /*Up to Snuff*/, 26614 /*Keep An Eye Out*/);
UPDATE `quest_template` SET `RewardFactionValue2`=-3 WHERE `Id` IN (201 /*Investigate the Camp*/, 210 /*Krazek's Cookery*/, 603 /*Ansirem's Key*/, 8249 /*Junkboxes Needed*/, 26052 /*Speak to Shakes*/);
UPDATE `quest_template` SET `RewardFactionValue2`=-7 WHERE `Id` IN (348 /*Stranglethorn Fever*/, 1385 /*Brutal Politics*/, 3721 /*An OOX of Your Own*/, 4621 /*Avast Ye, Admiral!*/, 9259 /*Traitor to the Bloodsail*/, 9266 /*Making Amends*/, 9267 /*Mending Old Wounds*/, 9268 /*War at Sea*/, 26597 /*Stranglethorn Fever*/, 26601 /*Mok'rash the Cleaver*/);
UPDATE `quest_template` SET `RewardFactionValue2`=-4 WHERE `Id` IN (595 /*The Bloodsail Buccaneers*/, 627 /*Favor for Krazek*/, 703 /*Barbecued Buzzard Wings*/, 26594 /*Return to MacKinley*/, 26600 /*A Giant's Feast*/, 26609 /*The Bloodsail Buccaneers*/, 26610 /*Bloodsail Treachery*/, 26617 /*An Old Sea Dog*/);
UPDATE `quest_template` SET `RewardFactionValue2`=-2 WHERE `Id` IN (606 /*Scaring Shaky*/, 1036 /*Avast Ye, Scallywag*/, 26611 /*The Baron Must Be Told*/);
UPDATE `quest_template` SET `RewardFactionValue2`=-6 WHERE `Id` IN (608 /*The Bloodsail Buccaneers*/, 611 /*The Curse of the Tides*/, 613 /*Cracking Maury's Foot*/, 623 /*Akiris by the Bundle*/, 648 /*Rescue OOX-17/TN!*/, 836 /*Rescue OOX-09/HL!*/, 2767 /*Rescue OOX-22/FE!*/, 3601 /*Kim'jael Indeed!*/, 5534 /*Kim'jael's ""Missing"" Equipment*/, 25476 /*Rescue OOX-22/FE!*/, 26051 /*Sunken Treasure*/, 26602 /*A Dish Best Served Huge*/, 26612 /*Details of the Attack*/, 26628 /*Death From Below*/);
UPDATE `quest_template` SET `RewardFactionValue3`=-2 WHERE `Id`=1180; -- Goblin Sponsorship
UPDATE `quest_template` SET `RewardFactionValue1`=-5 WHERE `Id` IN (1368 /*Gelkis Alliance*/, 30388 /*A Blue Feather for Gina*/, 30394 /*A Blue Feather for Old Hillpaw*/, 30395 /*A Marsh Lily for Old Hillpaw*/, 30396 /*A Dish for Old Hillpaw*/, 30400 /*A Blue Feather for Chee Chee*/, 30406 /*A Blue Feather for Sho*/, 30412 /*A Blue Feather for Haohan*/);
UPDATE `quest_template` SET `RewardFactionValue1`=-7 WHERE `Id`=1382; -- Strange Alliance
UPDATE `quest_template` SET `RewardMoney`=-299 WHERE `Id` IN (2945 /*Grime-Encrusted Ring*/, 2951 /*The Sparklematic 5200!*/, 2953 /*More Sparklematic Action*/, 4601 /*The Sparklematic 5200!*/, 4602 /*The Sparklematic 5200!*/, 4603 /*More Sparklematic Action*/, 4604 /*More Sparklematic Action*/);
UPDATE `quest_template` SET `RewardMoney`=-2999 WHERE `Id` IN (2948 /*Gnome Improvement*/, 2950 /*Nogg's Ring Redo*/);
UPDATE `quest_template` SET `RewardMoney`=-149999 WHERE `Id`=5538; -- Mold Rhymes With...
UPDATE `quest_template` SET `RewardMoney`=-1499999 WHERE `Id` IN (7637 /*Emphasis on Sacrifice*/, 7642 /*Collection of Goods*/);
UPDATE `quest_template` SET `RewardMoney`=-49999 WHERE `Id` IN (8763 /*The Hero of the Day*/, 8799 /*The Hero of the Day*/, 13265 /*Cloth Scavenging*/, 13268 /*Cloth Scavenging*/, 13269 /*Cloth Scavenging*/, 13270 /*Cloth Scavenging*/, 13272 /*Cloth Scavenging*/);
UPDATE `quest_template` SET `RewardMoney`=-399999 WHERE `Id`=8921; -- The Ectoplasmic Distiller
UPDATE `quest_template` SET `RewardMoney`=-749999 WHERE `Id` IN (11031 /*Archmage No More*/, 11032 /*Protector No More*/, 11033 /*Assassin No More*/, 11034 /*Restorer No More*/, 11103 /*Sage No More*/, 11104 /*Restorer No More*/, 11105 /*Champion No More*/, 11106 /*Defender No More*/);
UPDATE `quest_template` SET `RewardMoney`=-99999 WHERE `Id` IN (11548 /*Your Continued Support*/, 13846 /*Contributin' To The Cause*/);
UPDATE `quest_template` SET `RewardMoney`=-10000000 WHERE `Id`=11549; -- A Magnanimous Benefactor
UPDATE `quest_template` SET `RewardMoney`=-799999 WHERE `Id` IN (13906 /*They Grow Up So Fast*/, 29034 /*They Grow Up So Fast*/);
UPDATE `quest_template` SET `RewardMoney`=-1999999 WHERE `Id` IN (24819 /*A Change of Heart*/, 24820 /*A Change of Heart*/, 24821 /*A Change of Heart*/, 24822 /*A Change of Heart*/, 24836 /*A Change of Heart*/, 24838 /*A Change of Heart*/, 24840 /*A Change of Heart*/, 24842 /*A Change of Heart*/, 24843 /*A Change of Heart*/, 24845 /*A Change of Heart*/, 24846 /*A Change of Heart*/, 24847 /*A Change of Heart*/, 25246 /*A Change of Heart*/, 25247 /*A Change of Heart*/, 25248 /*A Change of Heart*/, 25249 /*A Change of Heart*/);
UPDATE `quest_template` SET `MinLevel`=-1 WHERE `Id` IN (27307 /*The Elements Cry Out*/, 27308 /*The Elements Cry Out*/, 27473 /*What's Shaking in Ironforge*/, 27540 /*The Wildhammer*/, 27546 /*Speak with Captain Anton*/, 27570 /*The Situation So Far*/);
UPDATE `quest_template` SET `RewardFactionValue1`=-1 WHERE `Id`=31737; -- The Cost of War
