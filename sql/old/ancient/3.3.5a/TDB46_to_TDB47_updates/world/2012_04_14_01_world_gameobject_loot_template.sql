-- Add missing gameobject_loot_templates to prevent startup errors
DELETE FROM `gameobject_loot_template` WHERE `entry` IN (3458,3459,3460,3461,15920,16841,26878,27725);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(3458,4594,100,0,0,1,1), -- Rockscale Cod on Feast Fish
(3459,3771,100,0,0,1,1), -- Wild Hog Shank On Feast Boar
(3460,4538,100,0,0,1,1), -- Snapvine Watermelon on Feast Fruit
(3461,1708,100,0,0,1,1), -- Sweet Nectar on Feast Goblet
(15920,17822,-100,0,0,1,1), -- Weird Map on weird object
(16841,18950,-100,0,0,1,1), -- Chambermaid Pillaclenchers Pillow on Pillaclencher's Ornate Pillow
(26878,45062,100,0,0,1,1), -- Dusty Journal on Dusty Journal (different ID)
(27725,49648,100,0,0,1,1); -- Borrowed Tabard on Clean Laundry (might need condition!)
