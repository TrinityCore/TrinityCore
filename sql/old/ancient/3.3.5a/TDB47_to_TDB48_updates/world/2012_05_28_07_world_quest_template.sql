-- Correct Quest chaining and requirements up until the quest "Crusader's Pinnacle", when the Argent Base in the pinnacle phases in
UPDATE `quest_template` SET `PrevQuestId`=13036, `NextQuestId`=13044, `ExclusiveGroup`=-13008 WHERE `id`=13008; -- Scourge Tactics
UPDATE `quest_template` SET `PrevQuestId`=13036, `NextQuestId`=13044, `ExclusiveGroup`=-13008 WHERE `id`=13039; -- Defending The Vanguard
UPDATE `quest_template` SET `PrevQuestId`=13036, `NextQuestId`=13044, `ExclusiveGroup`=-13008 WHERE `id`=13040; -- Curing The Incurable
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=13045, `ExclusiveGroup`=0, `NextQuestIdChain`=13045 WHERE `id`=13044; -- If There Are Survivors
UPDATE `quest_template` SET `PrevQuestId`=13044, `NextQuestId`=13070, `ExclusiveGroup`=0, `NextQuestIdChain`=13070 WHERE `id`=13045; -- Into The Wild Green Yonder
UPDATE `quest_template` SET `Method`=0, `PrevQuestId`=13045, `NextQuestId`=13086, `ExclusiveGroup`=0, `NextQuestIdChain`=13086 WHERE `id`=13070; -- A Cold Front Approaches
UPDATE `quest_template` SET `PrevQuestId`=13070, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestidChain`=0 WHERE `id`=13086; -- The Last Line Of Defense
-- Fix restrictions for DK and all rest classes without DK
UPDATE `quest_template` SET `PrevQuestId`=13086, `RequiredClasses`=32,`NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13104; -- Once More Unto The Breach, Hero /Death Knight's Special/
UPDATE `quest_template` SET `PrevQuestId`=13086, `RequiredClasses`=1502,`NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13105; -- Once More Unto The Breach, Hero
UPDATE `quest_template` SET `PrevQuestId`=13104, `NextQuestId`=13139, `ExclusiveGroup`=-13122, `NextQuestIdChain`=0 WHERE `id`=13122; -- The Scourgestone
UPDATE `quest_template` SET `PrevQuestId`=13104, `NextQuestId`=13139, `ExclusiveGroup`=-13122, `NextQuestIdChain`=0 WHERE `id`=13118; -- The Purging of Scourgeholme
UPDATE `quest_template` SET `PrevQuestId`=13104, `NextQuestId`=13139, `ExclusiveGroup`=-13122, `NextQuestIdChain`=0 WHERE `id`=13110; -- The Restless Dead
UPDATE `quest_template` SET `PrevQuestId`=13104, `NextQuestId`=13139, `ExclusiveGroup`=-13122, `NextQuestIdChain`=0 WHERE `id`=13125; -- The Air Stands Still
UPDATE `quest_template` SET `PrevQuestId`=13104, `NextQuestId`=13139, `ExclusiveGroup`=-13122, `NextQuestIdChain`=0 WHERE `id`=13130; -- The Stone That Started a Revolution
UPDATE `quest_template` SET `PrevQuestId`=13104, `NextQuestId`=13139, `ExclusiveGroup`=-13122, `NextQuestIdChain`=0 WHERE `id`=13135; -- It Could Kill Us All
UPDATE `quest_template` SET `PrevQuestId`=0, `NextQuestId`=13141, `ExclusiveGroup`=0, `NextQuestIdChain`=13141 WHERE `id`=13139; -- Into The Cold Heart Of Northrend
UPDATE `quest_template` SET `PrevQuestId`=13139, `NextQuestId`=13157, `ExclusiveGroup`=0, `NextQuestIdChain`=13157 WHERE `id`=13141; -- The Battle For Crusader`s Pinnacle
UPDATE `quest_template` SET `PrevQuestId`=13141, `NextQuestId`=0, `ExclusiveGroup`=0, `NextQuestIdChain`=0 WHERE `id`=13135; -- The Crusader's Pinnacle
