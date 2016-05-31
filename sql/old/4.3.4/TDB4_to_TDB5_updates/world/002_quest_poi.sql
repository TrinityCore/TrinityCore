DELETE FROM `quest_poi` WHERE `questid` IN (25165, 25165, 25165);
INSERT INTO `quest_poi` (`questid`, `id`, `objIndex`, `mapid`, `WorldMapAreaId`, `FloorId`, `unk3`, `unk4`) VALUES
(25165, 0, -1, 1, 4, 0, 0, 1), -- Never Trust a Big Barb and a Smile
(25165, 1, 0, 1, 4, 0, 0, 1), -- Never Trust a Big Barb and a Smile
(25165, 2, 0, 1, 4, 0, 0, 7); -- Never Trust a Big Barb and a Smile


DELETE FROM `quest_poi_points` WHERE (`questId`=25165 AND `id`=0) OR (`questId`=25165 AND `id`=1) OR (`questId`=25165 AND `id`=1) OR (`questId`=25165 AND `id`=1) OR (`questId`=25165 AND `id`=1) OR (`questId`=25165 AND `id`=1) OR (`questId`=25165 AND `id`=1) OR (`questId`=25165 AND `id`=1) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2) OR (`questId`=25165 AND `id`=2);
INSERT INTO `quest_poi_points` (`questId`, `id`, `idx`, `x`, `y`) VALUES
(25165, 0, 0, -849, -4909), -- Never Trust a Big Barb and a Smile
(25165, 1, 0, -920, -4951), -- Never Trust a Big Barb and a Smile
(25165, 1, 1, -683, -4650), -- Never Trust a Big Barb and a Smile
(25165, 1, 2, -719, -4615), -- Never Trust a Big Barb and a Smile
(25165, 1, 3, -751, -4585), -- Never Trust a Big Barb and a Smile
(25165, 1, 4, -817, -4585), -- Never Trust a Big Barb and a Smile
(25165, 1, 5, -842, -4615), -- Never Trust a Big Barb and a Smile
(25165, 1, 6, -1017, -4850), -- Never Trust a Big Barb and a Smile
(25165, 2, 0, -663, -5120), -- Never Trust a Big Barb and a Smile
(25165, 2, 1, -596, -5043), -- Never Trust a Big Barb and a Smile
(25165, 2, 2, -572, -4985), -- Never Trust a Big Barb and a Smile
(25165, 2, 3, -562, -4888), -- Never Trust a Big Barb and a Smile
(25165, 2, 4, -562, -4816), -- Never Trust a Big Barb and a Smile
(25165, 2, 5, -644, -4796), -- Never Trust a Big Barb and a Smile
(25165, 2, 6, -673, -4825), -- Never Trust a Big Barb and a Smile
(25165, 2, 7, -721, -4883), -- Never Trust a Big Barb and a Smile
(25165, 2, 8, -765, -4941), -- Never Trust a Big Barb and a Smile
(25165, 2, 9, -784, -4990), -- Never Trust a Big Barb and a Smile
(25165, 2, 10, -784, -5072), -- Never Trust a Big Barb and a Smile
(25165, 2, 11, -736, -5115); -- Never Trust a Big Barb and a Smile
