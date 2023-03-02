UPDATE creature_template SET flags_extra = flags_extra | 1536 WHERE entry IN (71504,71529,71161,71157,71156,71155,71160,71154,71152,71158,71153,71889);
DELETE FROM personal_loot_template WHERE entry IN (71504,71529,71161,71157,71156,71155,71160,71154,71152,71158,71153,71889);
insert into `personal_loot_template` (`entry`, `type`, `chance`, `lootspellId`, `bonusspellId`, `cooldownid`, `cooldowntype`, `respawn`, `comment`) values
('71153','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71158','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71152','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71154','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71160','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71155','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71156','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71157','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71161','1','15','0','145921','71161','1','1','Klaxxi Paragons'),
('71504','1','15','0','145918','0','0','1','Siegecrafter Blackfuse'),
('71529','1','15','0','145920','0','0','1','Thok the Bloodthirsty'),
('71889','1','15','0','145919','222749','0','1','Spoils of Pandaria');
