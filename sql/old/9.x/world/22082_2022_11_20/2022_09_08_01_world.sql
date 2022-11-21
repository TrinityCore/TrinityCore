
DELETE FROM `creature_questitem` WHERE (`Idx`=0 AND `CreatureEntry` IN (52409,52148));
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(52409, 0, 138951, 45114), -- Ragnaros
(52148, 0, 69774, 45114); -- Jin'do the Godbreaker

UPDATE `creature_questitem` SET `ItemId`=138968, `VerifiedBuild`=45161 WHERE (`CreatureEntry`=99611 AND `Idx`=0); -- Dantalionax

DELETE FROM `gameobject_template` WHERE `entry` IN (338682 /*Gossamer Thread*/, 237540 /*Gold Pile (Small)*/, 260313 /*Naughty Gears*/, 370469 /*Spectral Feed*/, 269871 /*Challenger's Cache*/, 311347 /*311347*/, 381195 /*Iron Chain*/, 357255 /*Thistledrop Frond*/, 357253 /*Abomination Head*/, 337091 /*Gormling Lure*/, 355847 /*Giant Lungcap*/, 376136 /*Fated Console*/, 311353 /*311353*/, 269852 /*Challenger's Cache*/, 311350 /*311350*/, 311351 /*311351*/, 311349 /*311349*/, 260312 /*Naughty Furnace*/, 352839 /*Theotar's Toasting Cup*/, 260300 /*Beautiful Beast Rock*/, 330214 /*Nutrient-Enriched Goo*/, 370168 /*Portal to Oribos*/, 311345 /*311345*/, 377001 /*Portal to Gorgrond*/, 260303 /*Beautiful Beast Flower*/, 377007 /*Portal to Mechagon*/, 311363 /*Tree*/, 260299 /*Beautiful Beast Rock*/, 375188 /*Camber Alcove Arrangement*/, 311358 /*Tree*/, 338614 /*Suspiciously Untouched Harp*/, 357582 /*Night Lilly*/, 311368 /*Tree*/, 377005 /*Portal to Karazhan*/, 376895 /*Challenger's Cache*/, 311346 /*311346*/, 357256 /*Thistledrop Growth*/, 376763 /*Challenger's Cache*/, 329691 /*Rustbolt Food Pellets*/, 352837 /*Theotar's Tea Tray*/, 381156 /*Iron Chain*/, 311352 /*311352*/, 330626 /*Nutrient-Enriched Brew*/, 330625 /*Traveler's Bag*/, 338613 /*Suspiciously Untouched Soulweb*/, 311348 /*311348*/, 334956 /*Sidetable*/, 260301 /*Beautiful Beast Tree*/, 311364 /*Table*/, 260311 /*Naughty Background*/, 260298 /*Beautiful Beast Background*/, 329690 /*Surprise Flowers*/, 338680 /*Shimmerdust Pile*/, 338681 /*Freshleaf*/, 376967 /*Fated Console*/, 380962 /*Chair*/, 338493 /*Suspiciously Untouched Basket*/, 352838 /*Tea Set*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(338682, 10, 15608, 'Gossamer Thread', 'questinteract', 'Inspecting', '', 1, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 311107, 0, 0, 0, 45353, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1235, 44908), -- Gossamer Thread
(237540, 5, 2614, 'Gold Pile (Small)', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Gold Pile (Small)
(260313, 5, 38497, 'Naughty Gears', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1169, 44908), -- Naughty Gears
(370469, 3, 38988, 'Spectral Feed', 'questinteract', 'Gathering', '', 1, 2160, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24982, 0, 0, 93411, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108904, 0, 0, 0, 0, 807, 44908), -- Spectral Feed
(269871, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 110, 0, 0, 0, 0, 2017, 0, 1, 0, 0, 111379, 0, 5, 107535, 0, 1180, 44908), -- Challenger's Cache
(381195, 10, 14657, 'Iron Chain', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 387369, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Iron Chain
(357255, 3, 66563, 'Thistledrop Frond', 'questinteract', 'Collecting', '', 0.5, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104521, 1, 0, 0, 0, 837, 44908), -- Thistledrop Frond
(357253, 5, 66549, 'Abomination Head', '', '', '', 1.5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Abomination Head
(337091, 10, 61460, 'Gormling Lure', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 310053, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 78372, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1236, 44908), -- Gormling Lure
(355847, 3, 64827, 'Giant Lungcap', 'questinteract', 'Collecting', '', 0.200000002980232238, 43, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 87727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104167, 1, 0, 0, 0, 837, 44908), -- Giant Lungcap
(376136, 10, 69194, 'Fated Console', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27735, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Fated Console
(269852, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 110, 0, 0, 0, 0, 1961, 0, 1, 0, 0, 111380, 0, 5, 107535, 0, 1180, 44908), -- Challenger's Cache
(260312, 5, 38496, 'Naughty Furnace', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1169, 44908), -- Naughty Furnace
(352839, 5, 62426, 'Theotar\'s Toasting Cup', '', '', '', 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 44908), -- Theotar's Toasting Cup
(260300, 5, 38487, 'Beautiful Beast Rock', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1169, 44908), -- Beautiful Beast Rock
(330214, 5, 56100, 'Nutrient-Enriched Goo', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Nutrient-Enriched Goo
(370168, 22, 68190, 'Portal to Oribos', '', '', '', 1, 344603, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 482, 44908), -- Portal to Oribos
(260303, 5, 38489, 'Beautiful Beast Flower', '', '', '', 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1169, 44908), -- Beautiful Beast Flower
(311363, 1, 10553, 'Tree', '', '', '', 0.421406000852584838, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Tree
(260299, 5, 38486, 'Beautiful Beast Rock', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1169, 44908), -- Beautiful Beast Rock
(375188, 10, 71395, 'Camber Alcove Arrangement', 'questinteract', 'Studying', '', 3, 93, 0, 0, 1, 0, 0, 0, 0, 0, 0, 364793, 0, 0, 0, 109101, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Camber Alcove Arrangement
(311358, 1, 9763, 'Tree', '', '', '', 0.976688981056213378, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Tree
(338614, 10, 59255, 'Suspiciously Untouched Harp', 'questinteract', 'Playing', '', 1, 93, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 311139, 0, 0, 0, 182871, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1235, 44908), -- Suspiciously Untouched Harp
(357582, 3, 65339, 'Night Lilly', 'questinteract', 'Collecting', '', 0.5, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104625, 1, 0, 0, 0, 837, 44908), -- Night Lilly
(311368, 1, 9765, 'Tree', '', '', '', 0.620000004768371582, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Tree
(376895, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 1754, 0, 1, 0, 0, 111375, 0, 5, 107535, 0, 1279, 44908), -- Challenger's Cache
(357256, 3, 62407, 'Thistledrop Growth', 'questinteract', 'Collecting', '', 0.5, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104522, 1, 0, 0, 0, 837, 44908), -- Thistledrop Growth
(376763, 3, 33268, 'Challenger\'s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 1754, 0, 1, 0, 0, 111376, 0, 5, 107535, 0, 1279, 44908), -- Challenger's Cache
(329691, 5, 57134, 'Rustbolt Food Pellets', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Rustbolt Food Pellets
(352837, 10, 61809, 'Theotar\'s Tea Tray', 'questinteract', '', '', 0.60000002384185791, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 329474, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 81991, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 746, 44908), -- Theotar's Tea Tray
(381156, 10, 14657, 'Iron Chain', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 387287, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Iron Chain
(330626, 5, 56101, 'Nutrient-Enriched Brew', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Nutrient-Enriched Brew
(330625, 5, 35102, 'Traveler\'s Bag', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Traveler's Bag
(338613, 10, 59254, 'Suspiciously Untouched Soulweb', 'questinteract', 'Inspecting', '', 1, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 311136, 0, 0, 0, 45353, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1235, 44908), -- Suspiciously Untouched Soulweb
(334956, 5, 58622, 'Sidetable', '', '', '', 0.400000005960464477, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Sidetable
(260301, 5, 38488, 'Beautiful Beast Tree', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1169, 44908), -- Beautiful Beast Tree
(260311, 5, 38495, 'Naughty Background', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1169, 44908), -- Naughty Background
(260298, 5, 38485, 'Beautiful Beast Background', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1169, 44908), -- Beautiful Beast Background
(329690, 5, 57133, 'Surprise Flowers', '', '', '', 0.5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Surprise Flowers
(338680, 10, 15003, 'Shimmerdust Pile', 'questinteract', 'Inspecting', '', 1, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 311058, 0, 0, 0, 45353, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1235, 44908), -- Shimmerdust Pile
(338681, 10, 59297, 'Freshleaf', 'questinteract', 'Inspecting', '', 1, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 311103, 0, 0, 0, 45353, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1235, 44908), -- Freshleaf
(376967, 10, 69194, 'Fated Console', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27735, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Fated Console
(380962, 7, 58621, 'Chair', '', '', '', 0.75, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908), -- Chair
(338493, 10, 59242, 'Suspiciously Untouched Basket', 'questinteract', 'Inspecting', '', 1, 43, 0, 0, 3000, 0, 1, 0, 0, 0, 0, 311062, 0, 0, 0, 45353, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1235, 44908), -- Suspiciously Untouched Basket
(352838, 5, 62428, 'Tea Set', '', '', '', 0.699999988079071044, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44908); -- Tea Set

DELETE FROM `gameobject_template` WHERE `entry` IN (377001 /*Portal to Gorgrond*/, 311352 /*311352*/, 311350 /*311350*/, 377005 /*Portal to Karazhan*/, 311346 /*311346*/, 377007 /*Portal to Mechagon*/, 311345 /*311345*/, 311351 /*311351*/, 311348 /*311348*/, 311347 /*311347*/, 311364 /*Table*/, 311353 /*311353*/, 311349 /*311349*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(377001, 22, 20810, 'Portal to Gorgrond', '', '', '', 1, 373516, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 783, 45161), -- Portal to Gorgrond
(311352, 1, 8519, '', '', '', '', 1.240000009536743164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- 311352
(311350, 1, 6315, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- 311350
(377005, 22, 6831, 'Portal to Karazhan', '', '', '', 1, 373515, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 783, 45161), -- Portal to Karazhan
(311346, 1, 6315, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- 311346
(377007, 22, 51955, 'Portal to Mechagon', '', '', '', 1, 373517, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 783, 45161), -- Portal to Mechagon
(311345, 1, 8395, '', '', '', '', 0.769999980926513671, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- 311345
(311351, 1, 10561, '', '', '', '', 0.889999985694885253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- 311351
(311348, 1, 8395, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- 311348
(311347, 1, 8395, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- 311347
(311364, 1, 6608, 'Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- Table
(311353, 1, 8395, '', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161), -- 311353
(311349, 1, 10250, '', '', '', '', 0.430000007152557373, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45161); -- 311349

UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=44908 WHERE `entry` IN (246709, 245855); -- Portcullis
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=203147; -- Aviana's Burial Circle
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=44908 WHERE `entry`=234633; -- Large Ammo Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39705, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208588; -- Flame Druid Staff
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=334346; -- Treasure of Purity
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=70342, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265598; -- Sealed Tome
UPDATE `gameobject_template` SET `ContentTuningId`=272, `VerifiedBuild`=44908 WHERE `entry`=239319; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry` IN (208543, 208541); -- Magmolia
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=202660; -- Lycanthoth's Altar
UPDATE `gameobject_template` SET `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=259730; -- Grand Ballroom
UPDATE `gameobject_template` SET `ContentTuningId`=713, `VerifiedBuild`=44908 WHERE `entry`=322671; -- Cogs and Springs
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39709, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208593; -- Flame Druid Idol
UPDATE `gameobject_template` SET `ContentTuningId`=2142, `VerifiedBuild`=44908 WHERE `entry`=334795; -- Eternal Cauldron
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=44908 WHERE `entry`=234635; -- Small Ammo Pile
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=70342, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265602; -- Sealed Tome
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=203066; -- Twilight Arms Crate
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=56754, `ContentTuningId`=302, `VerifiedBuild`=44908 WHERE `entry`=237462; -- Horribly Acidic Solution
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=70342, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265605; -- Sealed Tome
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=44908 WHERE `entry`=239969; -- Shadethistle
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208381; -- Pile of Ash
UPDATE `gameobject_template` SET `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=266858; -- Portal to Karazhan Entrance
UPDATE `gameobject_template` SET `name`='Pip\'s Mole Machine', `Data6`=1, `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=207327; -- Finkle's Mole Machine
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208440; -- Warden Trap
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=44908 WHERE `entry`=234671; -- Blackrock Ore
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39706, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208589; -- Flame Druid Spellbook
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28442, `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=202702; -- Stonebloom
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39507, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208544; -- Magmolia
UPDATE `gameobject_template` SET `ContentTuningId`=1253, `VerifiedBuild`=44908 WHERE `entry`=327528; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=44908 WHERE `entry`=250668; -- Alliance Banner
UPDATE `gameobject_template` SET `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=266878; -- Terrifying Stories to Tell at Night
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208474; -- Solar Core
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=95665, `ContentTuningId`=713, `VerifiedBuild`=44908 WHERE `entry`=325482; -- Energy Cell
UPDATE `gameobject_template` SET `Data30`=111377, `Data33`=107535, `ContentTuningId`=464, `VerifiedBuild`=44908 WHERE `entry`=338193; -- Challenger's Cache
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=202731; -- Lightning Channel
UPDATE `gameobject_template` SET `name`='Sinvyr Tea Set', `VerifiedBuild`=44908 WHERE `entry`=358569; -- Synvir Tea Set
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208537; -- Un'Goro Soil
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=44908 WHERE `entry`=246402; -- Worgen Tracks
UPDATE `gameobject_template` SET `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265486; -- Command Ship
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208570; -- Rappelling Rope
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=28603, `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=202846; -- Charred Staff Fragment
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=349565; -- Chest of Envious Dreams
UPDATE `gameobject_template` SET `ContentTuningId`=713, `VerifiedBuild`=44908 WHERE `entry`=322669; -- Batteries
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=204580; -- Gar'gol's Personal Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=266846; -- Door
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=355872; -- Stolen Jar
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39708, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208592; -- Flame Druid Reagent Pouch
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=209096; -- The Vow
UPDATE `gameobject_template` SET `ContentTuningId`=713, `VerifiedBuild`=44908 WHERE `entry`=332295; -- Stolen Parts
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=354646; -- Ancient Cloudfeather Egg
UPDATE `gameobject_template` SET `ContentTuningId`=292, `VerifiedBuild`=44908 WHERE `entry`=278402; -- Tiragarde Perch School
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208545; -- Ash Pile
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=202712; -- The Twilight Apocrypha
UPDATE `gameobject_template` SET `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=259928; -- Ghost Trap
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=358298; -- Forbidden Chamber Lockbox
UPDATE `gameobject_template` SET `ContentTuningId`=356, `VerifiedBuild`=44908 WHERE `entry` IN (255348, 255347); -- Gold
UPDATE `gameobject_template` SET `ContentTuningId`=816, `VerifiedBuild`=44908 WHERE `entry`=236277; -- Training Manual
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry` IN (208900, 311366); -- Portal to the Firelands
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=70342, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265604; -- Sealed Tome
UPDATE `gameobject_template` SET `ContentTuningId`=816, `VerifiedBuild`=44908 WHERE `entry` IN (236444, 236421); -- Iron Prisoner Cage
UPDATE `gameobject_template` SET `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=266848; -- POI Marker
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=353231; -- Bonebound Chest
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208426; -- Cinderweb Egg Sac - Spiderling Trap
UPDATE `gameobject_template` SET `ContentTuningId`=65, `VerifiedBuild`=44908 WHERE `entry`=234636; -- Small Ammo Barrel
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=56776, `ContentTuningId`=302, `VerifiedBuild`=44908 WHERE `entry`=237484; -- Iron Autocannon
UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=44908 WHERE `entry`=202748; -- Stormvine
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=202706; -- Twilight Cauldron
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=357584; -- Vyrtha's Dredglaive
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208552; -- Portal to Mount Hyjal
UPDATE `gameobject_template` SET `ContentTuningId`=642, `VerifiedBuild`=44908 WHERE `entry`=246660; -- Grave Marker
UPDATE `gameobject_template` SET `Data1`=0, `Data18`=679, `Data30`=39345, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=207507; -- Dark Iron Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208535; -- Dried Acorn
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=203067; -- Twilight Anvil
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39701, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208587; -- Obsidium Meteorite
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39726, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208802; -- Living Obsidium Chip
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39694, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208551; -- Lucifern
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208791; -- Small Gravestone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39488, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208423; -- Cinderweb Egg Sac
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=354853; -- Sprouting Growth
UPDATE `gameobject_template` SET `ContentTuningId`=271, `VerifiedBuild`=44908 WHERE `entry`=239324; -- Meeting Stone
UPDATE `gameobject_template` SET `ContentTuningId`=713, `VerifiedBuild`=44908 WHERE `entry`=322675; -- Volatile Liquid
UPDATE `gameobject_template` SET `Data30`=111378, `Data33`=107535, `ContentTuningId`=464, `VerifiedBuild`=44908 WHERE `entry`=338194; -- Challenger's Cache
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=356757; -- Greed's Desire
UPDATE `gameobject_template` SET `Data1`=0, `Data2`=1, `Data30`=56755, `ContentTuningId`=302, `VerifiedBuild`=44908 WHERE `entry`=237463; -- Strange Brass Compass
UPDATE `gameobject_template` SET `ContentTuningId`=271, `VerifiedBuild`=44908 WHERE `entry`=231980; -- Assault Flaps
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39495, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208442; -- Blueroot Vine
UPDATE `gameobject_template` SET `ContentTuningId`=52, `VerifiedBuild`=44908 WHERE `entry`=203169; -- Blaithe's Roost
UPDATE `gameobject_template` SET `ContentTuningId`=713, `VerifiedBuild`=44908 WHERE `entry`=322666; -- Explosives
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=353331; -- Faerie Stash
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39701, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208672; -- Obsidium Meteorite
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39706, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208590; -- Flame Druid Spellbook
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=70342, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265600; -- Sealed Tome
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39507, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208540; -- Magmolia
UPDATE `gameobject_template` SET `Data15`=0, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=266592; -- Medivh's Footlocker
UPDATE `gameobject_template` SET `Data18`=106, `VerifiedBuild`=44908 WHERE `entry`=220063; -- Forlorn Spire
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208596; -- Flame Druid Idol Trap
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=353232; -- Bleakwood Chest
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=349797; -- Abandoned Curios
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39717, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208630; -- Fire Hawk Egg
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=44908 WHERE `entry`=208778; -- Furnace Door
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=70342, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265597; -- Sealed Tome
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=70342, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265599; -- Sealed Tome
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39488, `ContentTuningId`=165, `VerifiedBuild`=44908 WHERE `entry`=208431; -- Cinderweb Egg Sac
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=349793; -- Wayfarer's Abandoned Spoils
UPDATE `gameobject_template` SET `ContentTuningId`=1039, `VerifiedBuild`=44908 WHERE `entry`=239325; -- Meeting Stone
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=70342, `ContentTuningId`=1169, `VerifiedBuild`=44908 WHERE `entry`=265603; -- Sealed Tome
UPDATE `gameobject_template` SET `ContentTuningId`=302, `VerifiedBuild`=44908 WHERE `entry`=236765; -- Deactivated Ogre Waygate
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=349795; -- Fleeing Soul's Bundle
UPDATE `gameobject_template` SET `Data32`=108, `VerifiedBuild`=44908 WHERE `entry`=349794; -- Remlate's Hidden Cache
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=44908 WHERE `entry`=277380; -- Tainted Pig Feed

UPDATE `gameobject_template` SET `ContentTuningId`=332, `VerifiedBuild`=45161 WHERE `entry` IN (244994, 241741, 244995); -- Weapon Rack
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39507, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208540; -- Magmolia
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45161 WHERE `entry`=252558; -- Hungering Orb
UPDATE `gameobject_template` SET `ContentTuningId`=332, `VerifiedBuild`=45161 WHERE `entry` IN (243215, 245650); -- Black Rook Cage
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45161 WHERE `entry`=246686; -- Barricade
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208596; -- Flame Druid Idol Trap
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry` IN (208541, 208543); -- Magmolia
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39702, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208576; -- Obsidium Meteorite
UPDATE `gameobject_template` SET `Data33`=107535, `ContentTuningId`=1172, `VerifiedBuild`=45161 WHERE `entry`=252677; -- Challenger's Cache
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45161 WHERE `entry` IN (246696, 246694, 246695); -- Supplies
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39706, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208589; -- Flame Druid Spellbook
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry` IN (311366, 208900); -- Portal to the Firelands
UPDATE `gameobject_template` SET `ContentTuningId`=682, `VerifiedBuild`=45161 WHERE `entry`=257289; -- Elven Treasure Chest
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45161 WHERE `entry`=251959; -- Ancient Elven Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39717, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208630; -- Fire Hawk Egg
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208570; -- Rappelling Rope
UPDATE `gameobject_template` SET `ContentTuningId`=332, `VerifiedBuild`=45161 WHERE `entry`=243089; -- Kur'talos Ravencrest's Sigil
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=45161 WHERE `entry`=208778; -- Furnace Door
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39507, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208544; -- Magmolia
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208552; -- Portal to Mount Hyjal
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39705, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208588; -- Flame Druid Staff
UPDATE `gameobject_template` SET `ContentTuningId`=332, `VerifiedBuild`=45161 WHERE `entry`=241586; -- Engraved Headstone
UPDATE `gameobject_template` SET `ContentTuningId`=332, `VerifiedBuild`=45161 WHERE `entry`=243807; -- Stone
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45161 WHERE `entry`=244000; -- Saris' Hammer
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45161 WHERE `entry`=287002; -- Mark of Alder
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208426; -- Cinderweb Egg Sac - Spiderling Trap
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45161 WHERE `entry`=266663; -- Duskwatch Scrying Orb
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45161 WHERE `entry`=247421; -- Powder Keg
UPDATE `gameobject_template` SET `ContentTuningId`=682, `VerifiedBuild`=45161 WHERE `entry` IN (244776, 244775); -- Dreamleaf
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39488, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208431; -- Cinderweb Egg Sac
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39495, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208442; -- Blueroot Vine
UPDATE `gameobject_template` SET `ContentTuningId`=332, `VerifiedBuild`=45161 WHERE `entry`=243636; -- Ledger of the Sea Wolf
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39708, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208592; -- Flame Druid Reagent Pouch
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208381; -- Pile of Ash
UPDATE `gameobject_template` SET `ContentTuningId`=348, `VerifiedBuild`=45161 WHERE `entry`=244001; -- Saris' Research
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39701, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208587; -- Obsidium Meteorite
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39701, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208672; -- Obsidium Meteorite
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39709, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208593; -- Flame Druid Idol
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=45161 WHERE `entry`=287001; -- Mark of Yew
UPDATE `gameobject_template` SET `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208545; -- Ash Pile
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39694, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208551; -- Lucifern
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45161 WHERE `entry`=246680; -- Banner
UPDATE `gameobject_template` SET `ContentTuningId`=683, `VerifiedBuild`=45161 WHERE `entry`=202748; -- Stormvine
UPDATE `gameobject_template` SET `ContentTuningId`=705, `VerifiedBuild`=45161 WHERE `entry`=291227; -- Small Treasure Chest
UPDATE `gameobject_template` SET `Data1`=0, `Data30`=39488, `ContentTuningId`=165, `VerifiedBuild`=45161 WHERE `entry`=208423; -- Cinderweb Egg Sac
UPDATE `gameobject_template` SET `ContentTuningId`=339, `VerifiedBuild`=45161 WHERE `entry`=252871; -- Beyond the Throne of Air
UPDATE `gameobject_template` SET `ContentTuningId`=335, `VerifiedBuild`=45161 WHERE `entry`=251190; -- Containment Field
UPDATE `gameobject_template` SET `ContentTuningId`=347, `VerifiedBuild`=45161 WHERE `entry`=246692; -- Torch
UPDATE `gameobject_template` SET `ContentTuningId`=1152, `VerifiedBuild`=45161 WHERE `entry`=253110; -- Meeting Stone

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (357255,357582,357256));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(357255, 0, 182333, 44908), -- Thistledrop Frond
(357582, 0, 182659, 44908), -- Night Lilly
(357256, 0, 182333, 44908); -- Thistledrop Growth

DELETE FROM `quest_template` WHERE `ID` IN (66650 /*-Unknown-*/, 66616 /*-Unknown-*/, 65131 /*-Unknown-*/, 66693 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(66650, 2, 0, 2426, -442, 62, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 38338624, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 7577, 0, 18446744073709551615, 2055, 8, 0, 0, 'Fate\'s Finale', 'Defeat $1oa different Fated raid bosses.', '<You are calm. The nature of this experience remains unknown, but it is no longer unfamiliar. Your now possess mastery over these ordeals with clarity as your ultimate reward.>\n\n<With clear mind and steady hand you stride forth one last time. Create your own destiny, and watch it unfold under your very feet.>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 45114), -- -Unknown-
(66616, 3, 0, 2426, 11510, 111, 0, 0, 5, 1, 0, 0, 0, 342092, 0, 0, 0, 0, 0, 0, 37290304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2465, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 12500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1623, 8, 0, 0, 'Oranomonos the Everbranching', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 45114), -- -Unknown-
(65131, 0, 0, 2060, 10413, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 8, 0, 0, 'Friend of a Friend: Rendle and Cudgelface', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 45114), -- -Unknown-
(66693, 3, 0, 837, -442, 111, 0, 0, 5, 1, 0, 0, 0, 344554, 0, 0, 0, 0, 0, 0, 36241728, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2413, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 50000, 0, 0, 0, 0, 0, 7119, 0, 18446744073709551615, 1623, 8, 0, 0, 'Tempting Fate: Castle Nathria', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 45114); -- -Unknown-

DELETE FROM `quest_objectives` WHERE `ID` IN (427707 /*427707*/, 427327 /*427327*/, 427557 /*427557*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(427707, 66650, 0, 0, 0, 190258, 5, 0, 0, 0, 'Fated raid bosses defeated', 45114), -- 427707
(427327, 66616, 0, 0, 0, 167527, 1, 1, 0, 0, '', 45114), -- 427327
(427557, 66693, 14, 0, 0, 134384, 1, 0, 0, 0, 'Fated Bosses Defeated in Castle Nathria', 45114); -- 427557

DELETE FROM `quest_reward_display_spell` WHERE (`QuestID`=65131 AND `Idx`=0);
INSERT INTO `quest_reward_display_spell` (`QuestID`, `Idx`, `SpellID`, `PlayerConditionID`, `VerifiedBuild`) VALUES
(65131, 0, 361711, 0, 45114);

UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=44908 WHERE `ID`=53253; -- Arathi Donations: Enchant Ring - Seal of Versatility
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=44908 WHERE `ID`=50581; -- Scrolls and Scales
UPDATE `quest_template` SET `ContentTuningID`=691, `VerifiedBuild`=44908 WHERE `ID`=54578; -- Branchlord Aldrus
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=44908 WHERE `ID`=41441; -- Superior Leystone Deposits
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=44908 WHERE `ID`=41438; -- Charged Leystone Deposits
UPDATE `quest_template` SET `ContentTuningID`=290, `VerifiedBuild`=45114 WHERE `ID`=53241; -- Arathi Donations: Coastal Mana Potion
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=100 WHERE `ID`=52428; -- Infusing the Heart
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500 WHERE `ID`=54391; -- Darkshore Donations: Quick Golden Beryl
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2000 WHERE `ID`=54282; -- Battle of Dazar'alor
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=45114 WHERE `ID`=52414; -- Work Order: Drums of the Maelstrom
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=700 WHERE `ID`=53172; -- Venture Co. Business Plan
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=250 WHERE `ID`=54058; -- Unintended Consequences
UPDATE `quest_template` SET `RewardCurrencyID1`=1602, `RewardCurrencyQty1`=25000 WHERE `ID`=56339; -- Tremblade Must Die
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500 WHERE `ID`=54380; -- Darkshore Donations: Gold
UPDATE `quest_template` SET `RewardCurrencyID1`=1820, `RewardCurrencyQty1`=35 WHERE `ID`=62189; -- Parasol Components
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=350 WHERE `ID`=53476; -- The Great Sea Scrolls
UPDATE `quest_template` SET `RewardCurrencyID1`=1819, `RewardCurrencyQty1`=2 WHERE `ID`=60945; -- Deep Echo Trident
UPDATE `quest_template` SET `RewardCurrencyID1`=1819, `RewardCurrencyQty1`=5 WHERE `ID`=61473; -- Sourcing Your Own Materials
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2000 WHERE `ID`=54485; -- Battle of Dazar'alor
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=400 WHERE `ID`=54172; -- The Azsharan Medallion
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=750 WHERE `ID`=56186; -- Spies to the Left and Right
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=700 WHERE `ID`=53169; -- Elemental Core
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=45114 WHERE `ID`=53253; -- Arathi Donations: Enchant Ring - Seal of Versatility
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500 WHERE `ID`=55350; -- Assault: Amathet Advance
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=700 WHERE `ID`=53182; -- Strangling Root
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=700 WHERE `ID`=53184; -- Weathered Pamphlet
UPDATE `quest_template` SET `RewardCurrencyID2`=1602, `RewardCurrencyQty2`=17500 WHERE `ID`=62285; -- Observing War
UPDATE `quest_template` SET `RewardCurrencyID1`=1602, `RewardCurrencyID2`=1792, `RewardCurrencyQty1`=17500, `RewardCurrencyQty2`=500 WHERE `ID`=62287; -- Observing Arenas
UPDATE `quest_template` SET `ContentTuningID`=290, `VerifiedBuild`=45114 WHERE `ID`=53242; -- Arathi Donations: Coastal Healing Potion
UPDATE `quest_template` SET `RewardCurrencyID1`=1819, `RewardCurrencyQty1`=5 WHERE `ID`=60498; -- Overcoming the Trial
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500 WHERE `ID`=54369; -- Darkshore Donations: Electroshock Mount Motivator
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=3000 WHERE `ID`=56356; -- The Eternal Palace: Queen's Gambit
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500 WHERE `ID`=56308; -- Assault: Aqir Unearthed
UPDATE `quest_template` SET `ContentTuningID`=347, `VerifiedBuild`=45114 WHERE `ID`=41198; -- Leystone Basilisks
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=600 WHERE `ID`=53437; -- The MOTHERLODE!!: Raw Deal
UPDATE `quest_template` SET `RewardBonusMoney`=0, `Expansion`=-2, `VerifiedBuild`=45114 WHERE `ID`=39; -- Deliver Thomas' Report
UPDATE `quest_template` SET `ContentTuningID`=691, `VerifiedBuild`=45114 WHERE `ID`=54678; -- Anything We Can Salvage
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=1500 WHERE `ID`=54438; -- Crucible of Storms: Relics of Shadow
UPDATE `quest_template` SET `ContentTuningID`=691, `VerifiedBuild`=45114 WHERE `ID`=54833; -- Scalefiend
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=45114 WHERE `ID`=51578; -- The Sea Runs Red
UPDATE `quest_template` SET `ContentTuningID`=464, `VerifiedBuild`=45114 WHERE `ID`=51223; -- Walking on Broken Glass
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=750 WHERE `ID`=56064; -- Assault: The Black Empire
UPDATE `quest_template` SET `ContentTuningID`=347, `AllowableRaces`=18446744073709551615, `VerifiedBuild`=45114 WHERE `ID`=41301; -- Starlight Rose Cluster
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=3000 WHERE `ID`=58632; -- Ny'alotha, the Waking City: The Corruptor's End

UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=55609; -- Operation: Mechagon - The Mechoriginator
UPDATE `quest_template` SET `RewardCurrencyID2`=1602, `RewardCurrencyQty2`=17500, `VerifiedBuild`=45161 WHERE `ID`=65773; -- Solo Mission
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54457; -- Supplies from Storm's Wake
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54461; -- Supplies from the Voldunai
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54451; -- Baubles from the Seekers
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54454; -- Supplies from the 7th Legion
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=53982; -- Supplies From The Unshackled
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=750, `VerifiedBuild`=45161 WHERE `ID`=57157; -- Assault: The Black Empire
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54456; -- Supplies from the Order of Embers
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=55348; -- Supplies from the Rustbolt Resistance
UPDATE `quest_template` SET `RewardCurrencyID2`=1602, `RewardCurrencyQty2`=12500, `VerifiedBuild`=45161 WHERE `ID`=62286; -- Observing Skirmishes
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54458; -- Supplies from the Proudmoore Admiralty
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54460; -- Supplies from Talanji's Expedition
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=58096; -- Supplies from the Rajani
UPDATE `quest_template` SET `RewardCurrencyID1`=1602, `RewardCurrencyID2`=1792, `RewardCurrencyQty1`=17500, `RewardCurrencyQty2`=750, `VerifiedBuild`=45161 WHERE `ID`=62288; -- Observing Teamwork
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=500, `VerifiedBuild`=45161 WHERE `ID`=57728; -- Assault: The Endless Swarm
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54455; -- Supplies from the Honorbound
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54462; -- Supplies from the Zandalari Empire
UPDATE `quest_template` SET `RewardCurrencyID2`=1602, `RewardCurrencyQty2`=17500, `VerifiedBuild`=45161 WHERE `ID`=65775; -- Soloing Strategy
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=55976; -- Supplies From the Waveblade Ankoan
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=58097; -- Supplies from the Uldum Accord
UPDATE `quest_template` SET `RewardCurrencyID1`=1553, `RewardCurrencyQty1`=2500, `VerifiedBuild`=45161 WHERE `ID`=54453; -- Supplies from Magni

UPDATE `quest_objectives` SET `Description`='Received orders from Paratrooper Jacobs', `VerifiedBuild`=45114 WHERE `ID`=336345; -- 336345
