-- Orgrimms Hammer questline
-- The Broken Front (13228)
UPDATE `quest_template` SET `PrevQuestId`=13224 WHERE `id`=13228;
-- Get To Ymirheim! (13293)
UPDATE `quest_template` SET `PrevQuestId`=13224 WHERE `id`=13293;
-- Slaves To Saronite (13302)
UPDATE `quest_template` SET `PrevQuestId`=13224 WHERE `id`=13302;
-- Mind Tricks (13308)
UPDATE `quest_template` SET `PrevQuestId`=13224 WHERE `id`=13308;
-- Blood of The Chosen (13330)
UPDATE `quest_template` SET `PrevQuestId`=13224 WHERE `id`=13330;
-- Joining the Assault (13340)
UPDATE `quest_template` SET `PrevQuestId`=13224 WHERE `id`=13340;
-- Assault by Air (13310)
UPDATE `quest_template` SET `PrevQuestId`=13340 WHERE `id`=13310;
-- Assault by Ground (13301)
UPDATE `quest_template` SET `PrevQuestId`=13340 WHERE `id`=13301;
-- Avenge Me! (13230)
UPDATE `quest_template` SET `PrevQuestId`=13228 WHERE `id`=13230;
-- Make Them Pay! (13234)
UPDATE `quest_template` SET `PrevQuestId`=13228 WHERE `id`=13234;
-- Good for Something? (13238)
UPDATE `quest_template` SET `PrevQuestId`=13228 WHERE `id`=13238;
-- Volatility - daily (13261)
UPDATE `quest_template` SET `PrevQuestId`=13239 WHERE `id`=13261;
-- Green Technology (13379)
UPDATE `quest_template` SET `PrevQuestId`=13239 WHERE `id`=13379;
-- Riding the Wavelength: The Bombardment (13406)
UPDATE `quest_template` SET `PrevQuestId`=13373 WHERE `id`=13406;
-- Total Ohmage: The Valley of Lost Hope! (13376)
UPDATE `quest_template` SET `PrevQuestId`=13373 WHERE `id`=13376;
-- Takes one to know One (13260)
UPDATE `quest_template` SET `PrevQuestId`=13228 WHERE `id`=13260;
-- That's Abominable! (13264)
UPDATE `quest_template` SET `PrevQuestId`=13237 WHERE `id`=13264;
-- Against The Giants (13277)
UPDATE `quest_template` SET `PrevQuestId`=13237 WHERE `id`=13277;
-- Neutralizing the Plague (13281)
UPDATE `quest_template` SET `PrevQuestId`=13279 WHERE `id`=13281;
-- That's Abominable! - daily (13276)
UPDATE `quest_template` SET `PrevQuestId`=13264 WHERE `id`=13276;
-- Sneak Preview (13351)
UPDATE `quest_template` SET `PrevQuestId`=13264 WHERE `id`=13351;
-- Chain of Command (13354)
UPDATE `quest_template` SET `PrevQuestId`=13351 WHERE `id`=13354;
-- Cannot Reproduce (13355)
UPDATE `quest_template` SET `PrevQuestId`=13351 WHERE `id`=13355;
-- Retest Now - daily (13357)
UPDATE `quest_template` SET `PrevQuestId`=13356 WHERE `id`=13357;
-- Drag and Drop (13352)
UPDATE `quest_template` SET `PrevQuestId`=13351 WHERE `id`=13352;
-- Drag and Drop - daily (13353)
UPDATE `quest_template` SET `PrevQuestId`=13352 WHERE `id`=13353;
-- Not A Bug (13358)
UPDATE `quest_template` SET `PrevQuestId`=13352 WHERE `id`=13358;
-- Not A Bug - daily (13365)
UPDATE `quest_template` SET `PrevQuestId`=13358 WHERE `id`=13365;
-- Need More Info (13366)
UPDATE `quest_template` SET `PrevQuestId`=13352 WHERE `id`=13366;
-- No Rest For The Wicked (13367)
UPDATE `quest_template` SET `PrevQuestId`=13366,`NextQuestId`=13312,`ExclusiveGroup`=-13306 WHERE `id`=13367;
-- No Rest for the Wicked - daily (13368)
UPDATE `quest_template` SET `PrevQuestId`=13367 WHERE `id`=13368;
-- Raise the Barricades (13306)
UPDATE `quest_template` SET `PrevQuestId`=13366,`NextQuestId`=13312,`ExclusiveGroup`=-13306 WHERE `id`=13306;
-- Blinding the Eyes in the Sky (13313)
UPDATE `quest_template` SET `PrevQuestId`=13306 WHERE `id`=13313;
-- The Ironwall Rampart (13312)
UPDATE `quest_template` SET `NextQuestId`=13329,`ExclusiveGroup`=-13307 WHERE `id`=13312;
-- Bloodspattered Banners (13307)
UPDATE `quest_template` SET `PrevQuestId`=13306,`NextQuestId`=13329,`ExclusiveGroup`=-13307 WHERE `id`=13307;
-- Shatter the Shard (13328)
UPDATE `quest_template` SET `PrevQuestId`=13329 WHERE `id`=13328;
-- The Guardians of Corp'rethar (13316)
UPDATE `quest_template` SET `PrevQuestId`=13329 WHERE `id`=13316;
