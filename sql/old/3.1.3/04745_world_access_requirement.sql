-- BC Dungeons --
UPDATE `access_requirement` SET `heroic_level_min` = 70 WHERE `id` IN
(
    4404, -- Auchenai Crypts --
    4405, -- Mana-Tombs --
    4406, -- Sethekk Halls --
    4407, -- Shadow Labyrinth --
    4321, -- Old Hillsbrad Foothills --
    4320, -- The Black Morass --
    4365, -- The Slave Pens --
    4364, -- The Steamvault --
    4363, -- The Underbog --
    4150, -- Hellfire Ramparts --
    4152, -- The Blood Furnace --
    4151, -- The Shattered Halls --
    4887, -- Magisters' Terrace --
    4468, -- The Arcatraz --
    4467, -- The Botanica --
    4469  -- The Mechanar --
);

-- WOTLK Dungeons --
UPDATE `access_requirement` SET `heroic_level_min` = 80 WHERE `id` IN
(
    5215, -- Ahn'kahet: The Old Kingdom --
    5117, -- Azjol-Nerub --
    5150, -- The Culling of Stratholme --
    4998, -- Drak'Tharon Keep --
    5206, -- Gundrak --
    4983, -- The Nexus --
    5246, -- The Oculus --
    5209, -- The Violet Hold --
    5093, -- Halls of Lightning --
    5010, -- Halls of Stone --
    4745, -- Utgarde Keep --
    4747  -- Utgarde Pinnacle --
);

-- WOTLK Raids --
UPDATE `access_requirement` SET `heroic_level_min` = 80 WHERE `id` IN
(
    4156, -- Naxxramas --
    5290, -- The Eye of Eternity --
    5243, -- The Obsidian Sanctum --
    5379  -- Ulduar --
);
